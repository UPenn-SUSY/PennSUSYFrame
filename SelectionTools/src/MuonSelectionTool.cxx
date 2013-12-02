#include "SelectionTools/include/MuonSelectionTool.h"

#include <vector>
#include <math.h>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

// -----------------------------------------------------------------------------
SelectionTools::MuonSelectionTool::MuonSelectionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  DeclareProperty("baseline_min_pt", c_baseline_min_pt = 10e3);
  DeclareProperty("baseline_max_pt", c_baseline_max_pt = -1);

  DeclareProperty("baseline_min_eta", c_baseline_min_eta = -1);
  DeclareProperty("baseline_max_eta", c_baseline_max_eta = 2.5);

  DeclareProperty( "baseline_min_b_layer_hits"
                 , c_baseline_min_b_layer_hits = 1
                 );
  DeclareProperty( "baseline_max_b_layer_hits"
                 , c_baseline_max_b_layer_hits = -1
                 );

  DeclareProperty("baseline_min_pixel_hits", c_baseline_min_pixel_hits = 1);
  DeclareProperty("baseline_max_pixel_hits", c_baseline_max_pixel_hits = -1);

  DeclareProperty("baseline_min_sct_hits", c_baseline_min_sct_hits = 5);
  DeclareProperty("baseline_max_sct_hits", c_baseline_max_sct_hits = -1);

  DeclareProperty("baseline_min_si_holes", c_baseline_min_si_holes = -1);
  DeclareProperty("baseline_max_si_holes", c_baseline_max_si_holes = 2);

  DeclareProperty("baseline_min_trt_hits", c_baseline_min_trt_hits = 6);
  DeclareProperty("baseline_max_trt_hits", c_baseline_max_trt_hits = -1);

  DeclareProperty( "baseline_min_trt_ol_fraction"
                 , c_baseline_min_trt_ol_fraction = -1
                 );
  DeclareProperty( "baseline_max_trt_ol_fraction"
                 , c_baseline_max_trt_ol_fraction = 0.9
                 );


  DeclareProperty("signal_min_eta", c_signal_min_eta = -1);
  DeclareProperty("signal_max_eta", c_signal_max_eta = 2.4);

  DeclareProperty("signal_min_d0_sig", c_signal_min_d0_sig = -1);
  DeclareProperty("signal_max_d0_sig", c_signal_max_d0_sig = 3.);

  DeclareProperty("signal_min_z0_sin_theta", c_signal_min_z0_sin_theta = -1);
  DeclareProperty("signal_max_z0_sin_theta", c_signal_max_z0_sin_theta = 1.);

  DeclareProperty("signal_min_ptcone_cut", c_signal_min_ptcone_cut = -1);
  DeclareProperty("signal_max_ptcone_cut", c_signal_max_ptcone_cut = 0.12);

  DeclareProperty("cosmic_min_d0", c_cosmic_min_d0= 0.2);
  DeclareProperty("cosmic_max_d0", c_cosmic_max_d0= -1);

  DeclareProperty("cosmic_min_z0", c_cosmic_min_z0= 1.);
  DeclareProperty("cosmic_max_z0", c_cosmic_max_z0= -1);

  DeclareProperty("bad_min_qoverp_ratio", c_bad_min_qoverp_ratio= 0.2);
  DeclareProperty("bad_max_qoverp_ratio", c_bad_max_qoverp_ratio= -1);
}

// -----------------------------------------------------------------------------
SelectionTools::MuonSelectionTool::~MuonSelectionTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SelectionTools::MuonSelectionTool::process(
    Muon* mu, const VertexContainer& vertices)
{
  SusyAnalysisTools::MuonDescription* mu_desc = mu->getMuonDesc();

  double pt  = mu->getTlv().Pt();
  double eta = fabs(mu->getTlv().Eta());

  // Check for loose of combined muons
  bool pass_combined = mu->isCombinedMuon();
  mu_desc->setPassCombined(pass_combined);

  bool pass_segment_tagged = mu->isSegmentTaggedMuon();
  mu_desc->setPassSegTag(pass_segment_tagged);

  bool pass_loose = mu->loose();
  mu_desc->setPassLoose(pass_loose);

  // Check number b-layer hits
  int num_b_layer = mu->nBLHits();
  bool pass_b_layer = true; // it looks like we are removing this cut now
  // bool pass_b_layer = (  (mu->expectBLayerHit() == false)
  //                     || passCut( num_b_layer
  //                               , c_baseline_min_b_layer_hits
  //                               , c_baseline_max_b_layer_hits
  //                               )
  //                     );
  mu_desc->setPassBLayer(pass_b_layer);

  // Check number pixel hits
  int num_pix = mu->nPixHits() + mu->nPixelDeadSensors();
  bool pass_pixel_hits = passCut( num_pix
                                , c_baseline_min_pixel_hits
                                , c_baseline_max_pixel_hits
                                );
  mu_desc->setPassPixel(pass_pixel_hits);

  // Check number SCT hits
  int num_sct = mu->nSCTHits() + mu->nSCTDeadSensors();
  bool pass_sct_hits = passCut( num_sct
                              , c_baseline_min_sct_hits
                              , c_baseline_max_sct_hits
                              );
  mu_desc->setPassSct(pass_sct_hits);

  // Check Si holes
  int num_si_holes = mu->nPixHoles() + mu->nSCTHoles();
  bool pass_si_holes = passCut( num_si_holes
                              , c_baseline_min_si_holes
                              , c_baseline_max_si_holes
                              );
  mu_desc->setPassSiHoles(pass_si_holes);

  // Check TRT hits & outlier ratio
  float track_eta = fabs(-log(tan(mu->id_theta()/2)));
  int num_trt = mu->nTRTHits() + mu->nTRTOutliers();
  float trt_ol_fraction = float(mu->nTRTOutliers())/num_trt;

  bool pass_n_trt = passCut( num_trt
                           , c_baseline_min_trt_hits
                           , c_baseline_max_trt_hits
                           );
  bool pass_trt_ol = passCut( trt_ol_fraction
                            , c_baseline_min_trt_ol_fraction
                            , c_baseline_max_trt_ol_fraction
                            );

  bool pass_trt = false;
  if (track_eta > 0.1 && track_eta < 1.9) {
    pass_trt = (pass_n_trt && pass_trt_ol);
  }
  else {
    // pass_trt = (!pass_n_trt || pass_trt_ol);
    pass_trt = true; // it looks like we are removing this check as well
  }
  mu_desc->setPassTrt(pass_trt);

  // Check for baseline pt
  bool pass_baseline_pt = passCut(pt, c_baseline_min_pt, c_baseline_max_pt);
  mu_desc->setPassBaselinePt(pass_baseline_pt);

  // Check for baseline eta
  bool pass_baseline_eta = passCut(eta, c_baseline_min_eta, c_baseline_max_eta);
  mu_desc->setPassBaselineEta(pass_baseline_eta);

  // Check for signal eta
  bool pass_signal_eta = passCut(eta, c_signal_min_eta, c_signal_max_eta);
  mu_desc->setPassSignalEta(pass_signal_eta);

  // check for signal d0 significance
  double d0_sig = fabs(mu->getD0Significance());
  bool pass_d0_sig = passCut(d0_sig, c_signal_min_d0_sig, c_signal_max_d0_sig);
  mu_desc->setPassD0Sig(pass_d0_sig);

  // check for signal z0 sin(theta)
  double z0_sin_theta = fabs(mu->getZ0SinTheta());
  bool pass_z0_sin_theta = passCut( z0_sin_theta
                                  , c_signal_min_z0_sin_theta
                                  , c_signal_max_z0_sin_theta
                                  );
  mu_desc->setPassZ0SinTheta(pass_z0_sin_theta);

  // Check for signal isolation
  // int num_good_vertices = vertices.num(VERT_GOOD);
  //double ptcone30 = mu->getIsoCorr( PTCONE
  //                                , 30
  //                                , num_good_vertices
  //                                );
  double ptcone30 = mu->ptcone30_trkelstyle();

  double ptcone_ratio = ptcone30/pt;

  bool pass_pt_iso = passCut( ptcone_ratio
                            , c_signal_min_ptcone_cut
                            , c_signal_max_ptcone_cut
                            );
  // std::cout << "checking pt iso for this muon:\n"
  //           << "\tptcone30:     " << ptcone30 << "\n"
  //           << "\tpt:           " << pt << "\n"
  //           << "\tptcone_ratio: " << ptcone_ratio << "\n"
  //           << "\tpass_pt_iso:  " << pass_pt_iso << "\n";
  mu_desc->setPassPtIso(pass_pt_iso);
}

// -----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isBaseline(Muon* mu)
{
  // Check if this muon passed all baseline cuts
  SusyAnalysisTools::MuonDescription* mu_desc = mu->getMuonDesc();
  bool pass_baseline = (  (  mu_desc->getPassCombined()
                          || mu_desc->getPassSegTag()
                          || mu_desc->getPassLoose()
                          )
                       && mu_desc->getPassBLayer()
                       && mu_desc->getPassPixel()
                       && mu_desc->getPassSct()
                       && mu_desc->getPassSiHoles()
                       && mu_desc->getPassTrt()
                       && mu_desc->getPassBaselinePt()
                       && mu_desc->getPassBaselineEta()
                       );
  mu_desc->setPassBaseline(pass_baseline);

  return pass_baseline;
}

// -----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isSignal(Muon* mu)
{
  // Check if this muon passed all signal cuts
  SusyAnalysisTools::MuonDescription* mu_desc = mu->getMuonDesc();
  // std::cout << "\t\tpass signal eta: "          <<  mu_desc->getPassSignalEta() << "\n"
  //              "\t\tpass signal d0 sig: "       <<  mu_desc->getPassD0Sig() << "\n"
  //              "\t\tpass signal z0 sin theta: " <<  mu_desc->getPassZ0SinTheta() << "\n"
  //              "\t\tpass signal pt iso: "       <<  mu_desc->getPassPtIso() << "\n";
  bool pass_signal = (  mu_desc->getPassSignalEta()
                     && mu_desc->getPassD0Sig()
                     && mu_desc->getPassZ0SinTheta()
                     && mu_desc->getPassPtIso()
                     );
  mu_desc->setPassSignal(pass_signal);

  return pass_signal;
}

// -----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isCosmic(Muon* mu)
{
  // check for signal d0 significance
  // float d0 = fabs(mu->trackIPEstimate_d0_unbiasedpvunbiased());
  float d0 = fabs(mu->d0_exPV());
  if (passCut(d0, c_cosmic_min_d0, c_cosmic_max_d0))
    return true;

  // check for signal z0 sin(theta)
  // float z0 = fabs(mu->trackIPEstimate_z0_unbiasedpvunbiased());
  float z0 = fabs(mu->z0_exPV());
  if (passCut(z0, c_cosmic_min_z0, c_cosmic_max_z0))
    return true;

  // Passed all cuts. This is a cosmic muon
  return false;
}

// -----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isBad(Muon* mu)
{
  // check for signal d0 significance
  float cov_qoverp = mu->cov_qoverp_exPV();
  float qoverp     = mu->qoverp_exPV();
  float ratio = sqrt(cov_qoverp)/fabs(qoverp);
  if (!passCut(ratio, c_bad_min_qoverp_ratio, c_bad_max_qoverp_ratio))
    return false;

  // Passed all cuts. This is a bad muon
  return true;
}

// -----------------------------------------------------------------------------
std::vector<Muon*> SelectionTools::MuonSelectionTool::getBaselineMuons(
    const MuonContainer& muon_container)
{
  const std::vector<Muon*> all_muons = muon_container.getMuons(MU_ALL);
  return getBaselineMuons(all_muons);
}

// -----------------------------------------------------------------------------
std::vector<Muon*> SelectionTools::MuonSelectionTool::getBaselineMuons(
    const std::vector<Muon*>& all_muons)
{
  size_t term = all_muons.size();

  std::vector<Muon*> baseline_muons;
  baseline_muons.reserve(term);

  for (size_t mu_it = 0; mu_it != term; ++mu_it) {
    if (  isBaseline(all_muons.at(mu_it))
       && !isBad(all_muons.at(mu_it))
       ) {
      baseline_muons.push_back(all_muons.at(mu_it));
    }
  }

  return baseline_muons;
}

// -----------------------------------------------------------------------------
std::vector<Muon*> SelectionTools::MuonSelectionTool::getSignalMuons(
    const MuonContainer& muon_container)
{
  const std::vector<Muon*> good_muons =
    muon_container.getMuons(MU_GOOD);
  return getSignalMuons(good_muons);
}

// -----------------------------------------------------------------------------
std::vector<Muon*> SelectionTools::MuonSelectionTool::getSignalMuons(
    const std::vector<Muon*>& good_muons)
{
  // std::cout << "Finding signal muons\n";
  size_t term = good_muons.size();

  std::vector<Muon*> signal_muons;
  signal_muons.reserve(term);

  for (size_t mu_it = 0; mu_it != term; ++mu_it) {
    // std::cout << "\tmuon it: " << mu_it << "\n";
    if (isSignal(good_muons.at(mu_it))) {
      signal_muons.push_back(good_muons.at(mu_it));
    }
  }

  return signal_muons;
}

// -----------------------------------------------------------------------------
std::vector<Muon*> SelectionTools::MuonSelectionTool::getCosmicMuons(
    const MuonContainer& muon_container)
{
  const std::vector<Muon*> good_muons =
    muon_container.getMuons(MU_GOOD);
  return getCosmicMuons(good_muons);
}

// -----------------------------------------------------------------------------
std::vector<Muon*> SelectionTools::MuonSelectionTool::getCosmicMuons(
    const std::vector<Muon*>& good_muons)
{
  size_t term = good_muons.size();

  std::vector<Muon*> cosmic_muons;
  cosmic_muons.reserve(term);

  for (size_t mu_it = 0; mu_it != term; ++mu_it) {
    if (isCosmic(good_muons.at(mu_it))) {
      good_muons.at(mu_it)->getMuonDesc()->setPassCosmic(true);
      cosmic_muons.push_back(good_muons.at(mu_it));
    }
  }

  return cosmic_muons;
}

// -----------------------------------------------------------------------------
std::vector<Muon*> SelectionTools::MuonSelectionTool::getBadMuons(
    const MuonContainer& muon_container)
{
  const std::vector<Muon*> all_muons =
    muon_container.getMuons(MU_ALL);
  return getBadMuons(all_muons);
}

// -----------------------------------------------------------------------------
std::vector<Muon*> SelectionTools::MuonSelectionTool::getBadMuons(
    const std::vector<Muon*>& all_muons)
{
  size_t term = all_muons.size();

  std::vector<Muon*> bad_muons;
  bad_muons.reserve(term);

  for (size_t mu_it = 0; mu_it != term; ++mu_it) {
    if (  isBaseline(all_muons.at(mu_it))
       && isBad(all_muons.at(mu_it))
       ) {
      all_muons.at(mu_it)->getMuonDesc()->setPassBad(true);
      bad_muons.push_back(all_muons.at(mu_it));
    }
  }

  return bad_muons;
}

// -----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::passCut( double test
                                               , double min
                                               , double max
                                               )
{
  // if no test, return true
  if (min < 0 && max < 0) return true;

  if (min >= 0 && test < min) return false;
  if (max >= 0 && test > max) return false;

  // passed test
  return true;
}
