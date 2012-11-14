#include <math.h>
#include "include/MuonSelectionTool.h"

// -----------------------------------------------------------------------------
SelectionTools::MuonSelectionTool::MuonSelectionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  DeclareProperty("baseline_min_pt", c_baseline_min_pt = 10e3);
  DeclareProperty("baseline_max_pt", c_baseline_max_pt = -1);

  DeclareProperty("baseline_min_eta", c_baseline_min_eta = -1);
  DeclareProperty("baseline_max_eta", c_baseline_max_eta = 2.4);

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
void SelectionTools::MuonSelectionTool::process(Muon* mu)
{

}

// -----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isBaseline(Muon* mu)
{
  // Check for loose of combined muons
  if (!mu->isCombinedMuon() && !mu->isSegmentTaggedMuon() && !mu->loose())
    return false;

  // Check number b-layer hits
  int num_b_layer = mu->nBLHits();
  if (mu->expectBLayerHit()) {
    if (!passCut( num_b_layer
                , c_baseline_min_b_layer_hits
                , c_baseline_max_b_layer_hits
                )
       )
      return false;
  }

  // Check number pixel hits
  int num_pix = mu->nPixHits() + mu->nPixelDeadSensors();
  if (!passCut(num_pix, c_baseline_min_pixel_hits, c_baseline_max_pixel_hits))
    return false;

  // Check number SCT hits
  int num_sct = mu->nSCTHits() + mu->nSCTDeadSensors();
  if (!passCut(num_sct, c_baseline_min_sct_hits, c_baseline_max_sct_hits))
    return false;

  // Check Si holes
  int num_si_holes = mu->nPixHoles() + mu->nSCTHoles();
  if (!passCut(num_si_holes, c_baseline_min_si_holes, c_baseline_max_si_holes))
    return false;

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

  // std::cout << "\tpt: " << mu->getTlv().Pt() << "\n";
  // std::cout << "\ttrack_eta: " << track_eta << "\n";
  // std::cout << "\tnum_trt: " << num_trt << "\n";
  // std::cout << "\ttrt_ol_fraction: " << trt_ol_fraction << "\n";
  // std::cout << "\tpass_n_trt: " << pass_n_trt << "\n";
  // std::cout << "\tpass_trt_ol: " << pass_trt_ol << "\n";

  if (track_eta > 0.1 && track_eta < 1.9) {
    if (!pass_n_trt || !pass_trt_ol) return false;
  }
  else {
    if (!pass_n_trt && !pass_trt_ol) return false;
  }

  // Check for baseline pt
  double pt = mu->getTlv().Pt();
  if (!passCut(pt, c_baseline_min_pt, c_baseline_max_pt))
    return false;

  // Check for baseline eta
  double eta = fabs(mu->getTlv().Eta());
  if (!passCut(eta, c_baseline_min_eta, c_baseline_max_eta))
    return false;

  // Passed all cuts. This is a baseline muon
  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isSignal(
    Muon* mu, const VertexContainer& vertices)
{
  // check for signal d0 significance
  double d0_sig = fabs(mu->getD0Significance());
  if (!passCut(d0_sig, c_signal_min_d0_sig, c_signal_max_d0_sig))
    return false;

  // check for signal z0 sin(theta)
  double z0_sin_theta = fabs(mu->getZ0SinTheta());
  if (!passCut( z0_sin_theta
              , c_signal_min_z0_sin_theta
              , c_signal_max_z0_sin_theta
              ) )
    return false;

  // Check for signal isolation
  int num_good_vertices = vertices.num(VERT_GOOD);
  double ptcone30 = mu->getIsoCorr( PTCONE
                                  , 30
                                  , num_good_vertices
                                  );
  double pt = mu->getTlv().Pt();
  double ptcone_ratio = ptcone30/pt;

  if (!passCut(ptcone_ratio, c_signal_min_ptcone_cut, c_signal_max_ptcone_cut))
      return false;

  // Passed all cuts. This is a cosmic muon
  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isCosmic(Muon* mu)
{
  // check for signal d0 significance
  float d0 = fabs(mu->d0_exPV());
  if (passCut(d0, c_cosmic_min_d0, c_cosmic_max_d0))
    return true;

  // check for signal z0 sin(theta)
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
  const std::vector<Muon*> all_muons =
    muon_container.getMuons(MU_ALL);
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
    const MuonContainer& muon_container, const VertexContainer& vertices)
{
  const std::vector<Muon*> good_muons =
    muon_container.getMuons(MU_GOOD);
  return getSignalMuons(good_muons, vertices);
}

// -----------------------------------------------------------------------------
std::vector<Muon*> SelectionTools::MuonSelectionTool::getSignalMuons(
    const std::vector<Muon*>& good_muons, const VertexContainer& vertices)
{
  size_t term = good_muons.size();

  std::vector<Muon*> signal_muons;
  signal_muons.reserve(term);

  for (size_t mu_it = 0; mu_it != term; ++mu_it) {
    if (isSignal(good_muons.at(mu_it), vertices)) {
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
