#include "PennSusyFrameCore/include/ScaleFactorTools.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "RootCore/PileupReweighting/PileupReweighting/TPileupReweighting.h"
#include "RootCore/SUSYTools/SUSYTools/BTagCalib.h"
#include "RootCore/DGTriggerReweight/DGTriggerReweight/triggerReweight2Lep.h"

// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::PileUpScaleFactorTool::PileUpScaleFactorTool() : m_pile_up_reweight(0)
{
  // set data and mc histogram names
  m_data_hist_name = "LumiMetaData";
  m_mc_hist_name   = "MCPileupReweighting";

  // set data and mc pile up files
  // std::string maindir = getenv("ROOTCOREDIR");
  // m_pile_up_data_file = maindir + "/../MultiLep/data/ilumicalc_histograms_EF_2e12Tvh_loose1_200842-215643_grl_v61.root";
  // m_pile_up_mc_file   = maindir + "/../PileupReweighting/share/mc12ab_defaults.prw.root";
  std::string maindir = getenv("BASE_WORK_DIR");

  //This is the full year pile up file
  m_pile_up_data_file = maindir + "/RootCore/MultiLep/data/ilumicalc_histograms_EF_2e12Tvh_loose1_200842-215643_grl_v61.root";

  //This is the 13 fb-1 file
  // m_pile_up_data_file = maindir + "/RootCore/MultiLep/data/ilumicalc_histograms_EF_2e12Tvh_loose1_200841-210308.root";


  // MC pile up file
  m_pile_up_mc_file   = maindir + "/RootCore/PileupReweighting/share/mc12ab_defaults.prw.root";

  std::cout << "initializing PileUpScaleFactorTool\n"
            << "\tMC file: "   << m_pile_up_mc_file   << "\n"
            << "\tData file: " << m_pile_up_data_file << "\n";

  // set up pile up reweight tool
  m_pile_up_reweight = new Root::TPileupReweighting("TPileupReweighting");
  m_pile_up_reweight->SetDefaultChannel(0);
  m_pile_up_reweight->AddConfigFile(m_pile_up_mc_file);

  m_pile_up_reweight->SetDataScaleFactors(1/1.11);
  m_pile_up_reweight->AddLumiCalcFile(m_pile_up_data_file);

  int is_good = m_pile_up_reweight->Initialize();
  if (is_good != 0) {
    std::cout << "FATAL: Problem in PileUp initialization::isGood = "
              << is_good << "\n";
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::PileUpScaleFactorTool::~PileUpScaleFactorTool()
{
  if (m_pile_up_reweight)
    delete m_pile_up_reweight;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::PileUpScaleFactorTool::getPileupScaleFactor( const PennSusyFrame::Event& event
                                                                 , const PennSusyFrame::MCTruth& mc_truth
                                                                 )
{
  float pile_up_sf = m_pile_up_reweight->GetCombinedWeight( event.getRunNumber()
                                                          , mc_truth.getChannelNumber()
                                                          , event.getAverageIntPerXing()
                                                          );
  if (pile_up_sf < 0.) pile_up_sf = 0.;
  return pile_up_sf;
}
// -----------------------------------------------------------------------------
int PennSusyFrame::PileUpScaleFactorTool::getRandomRunNumber(int run_number, double mu)
{
  return m_pile_up_reweight->GetRandomRunNumber(run_number, mu);
}
// -----------------------------------------------------------------------------
int PennSusyFrame::PileUpScaleFactorTool::getRandomLumiBlockNumber(int run_number)
{
  return m_pile_up_reweight->GetRandomLumiBlockNumber(run_number);
}
void PennSusyFrame::PileUpScaleFactorTool::setRandomSeed(int seed)
{
  m_pile_up_reweight->SetRandomSeed(seed);
}
// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::EgammaScaleFactorTool::EgammaScaleFactorTool() : m_is_af2(false)
                                                              , m_is_tightpp(true)
{
  // get directory for SF files
  std::string maindir = getenv("ROOTCOREDIR");
  m_egamma_sf_dir = maindir + "/../ElectronEfficiencyCorrection/data/";
}

void PennSusyFrame::EgammaScaleFactorTool::init()
{
  // initialize reco sf
  m_reco_file_name = m_egamma_sf_dir + "efficiencySF.offline.RecoTrk.2012.8TeV.rel17p2.GEO20.v08.root";
  //TODO make sure these are the right files

  std::cout << "Adding file to Egamma reco sf tool: " << m_reco_file_name << "\n";
  m_eg_reco_sf.addFileName(m_reco_file_name);
  m_eg_reco_sf.initialize();

  // initialize sf tight++ or medium++
  m_tight_file_name  = m_egamma_sf_dir + "efficiencySF.offline.Tight.2012.8TeV.rel17p2.v04.root";
  m_medium_file_name = m_egamma_sf_dir + "efficiencySF.offline.Medium.2012.8TeV.rel17p2.v04.root";

  std::string the_file_name = ( m_is_tightpp ? m_tight_file_name : m_medium_file_name );
  std::cout << "Adding file to Egamma id sf tool: " << the_file_name << "\n";
  m_eg_id_sf.addFileName(the_file_name);
  m_eg_id_sf.initialize();

  m_data_type = ( m_is_af2
                ? PATCore::ParticleDataType::Fast
                : PATCore::ParticleDataType::Full
                );
}

// -----------------------------------------------------------------------------
double PennSusyFrame::EgammaScaleFactorTool::getSF( const PennSusyFrame::Event& event
                                                  , const PennSusyFrame::Electron* el
                                                  )
{
  float cl_eta = el->getClEta();
  float pt = el->getPt();

  // PATCore::ParticleDataType::DataType data_type = ( m_is_af2
  //                                                 ? PATCore::ParticleDataType::Fast
  //                                                 : PATCore::ParticleDataType::Full
  //                                                 );


  Root::TResult result_reco = m_eg_reco_sf.calculate( m_data_type
  					                                        , event.getRunNumber()
  					                                        , cl_eta
  					                                        , pt
                                                    );
  Root::TResult result_id = m_eg_id_sf.calculate( m_data_type
  					                                    , event.getRunNumber()
  					                                    , cl_eta
  					                                    , pt
                                                );

  return ( result_reco.getScaleFactor()
         * result_id.getScaleFactor()
         );
}

// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::MuonScaleFactorTool::MuonScaleFactorTool() : m_muon_sf(0)
{
  // get default path for muon SF directory. This comes from SUSYTools
  std::string maindir = getenv("ROOTCOREDIR");
  m_muon_sf_dir = maindir + "/../MuonEfficiencyCorrections/share/";

  std::cout << "Muon efficiency corrections will be grabbed from: "
            << m_muon_sf_dir << "\n";

  m_muon_type = "STACO_CB_plus_ST";
  m_file_name = m_muon_type + "_2012_SF.txt.gz";

  m_configuration = Analysis::AnalysisMuonConfigurableScaleFactors::AverageOverPeriods;

  // set unit
  m_unit = "MeV";

  m_muon_sf = new Analysis::AnalysisMuonConfigurableScaleFactors( m_muon_sf_dir
                                                                , m_file_name
                                                                , m_unit
                                                                , m_configuration
                                                                );
  m_muon_sf->Initialise();
}

// -----------------------------------------------------------------------------
PennSusyFrame::MuonScaleFactorTool::~MuonScaleFactorTool()
{
  if (m_muon_sf)
    delete m_muon_sf;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::MuonScaleFactorTool::getSF(const PennSusyFrame::Muon* mu)
{
  return m_muon_sf->scaleFactor(mu->getCharge(), *mu->getTlv());
}

// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::TriggerWeightTool::TriggerWeightTool() : m_trigger_reweight(0)
{
  std::string root_core_dir = getenv("ROOTCOREDIR");
  m_reweight_directory = root_core_dir + "/../DGTriggerReweight/data/";
  m_reweight_period = "Moriond";

  m_trigger_reweight = new triggerReweight2Lep();
  m_trigger_reweight->setDbg(1);
  m_trigger_reweight->initialize( m_reweight_directory
                                , m_reweight_period
                                , false // use reweight utils
                                );
  m_trigger_reweight->setDbg(0);
}

// -----------------------------------------------------------------------------
PennSusyFrame::TriggerWeightTool::~TriggerWeightTool()
{
  if (m_trigger_reweight)
    delete m_trigger_reweight;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::TriggerWeightTool::getWeight( FLAVOR_CHANNEL flavor_channel
                                                  , const std::vector<PennSusyFrame::Electron*>* el
                                                  , const std::vector<PennSusyFrame::Muon*>* mu
                                                  , const std::vector<PennSusyFrame::Jet*>* // jet
                                                  , const PennSusyFrame::Met& met
                                                  , const std::vector<PennSusyFrame::Vertex*>* vertices
    )
{
  double trigger_weight = 1.;

  size_t num_vert = vertices->size();
  // size_t num_jets = jet->size();

  if (flavor_channel == FLAVOR_EE) {
    double el_pt_0 = el->at(0)->getPt();
    double el_pt_1 = el->at(1)->getPt();

    double el_eta_0 = el->at(0)->getEta();
    double el_eta_1 = el->at(1)->getEta();

    trigger_weight = m_trigger_reweight->triggerReweightEE( el_pt_0, el_eta_0
                                                          , el_pt_1, el_eta_1
                                                          );
  }
  else if (flavor_channel == FLAVOR_MM) {
    double mu_pt_0 = mu->at(0)->getPt();
    double mu_pt_1 = mu->at(1)->getPt();

    double mu_eta_0 = mu->at(0)->getEta();
    double mu_eta_1 = mu->at(1)->getEta();

    double mu_phi_0 = mu->at(0)->getPhi();
    double mu_phi_1 = mu->at(1)->getPhi();

    int mu_is_comb_0 = mu->at(0)->getIsCombined();
    int mu_is_comb_1 = mu->at(1)->getIsCombined();

    trigger_weight = m_trigger_reweight->triggerReweightMM( mu_pt_0, mu_eta_0, mu_phi_0, mu_is_comb_0
                                                          , mu_pt_1, mu_eta_1, mu_phi_1, mu_is_comb_1
                                                          , num_vert
                                                          , met.getMetEt()
                                                          , 0
                                                          , false
                                                          );
  }
  else if (flavor_channel == FLAVOR_EM) {
    double el_pt = el->at(0)->getPt();
    double mu_pt = mu->at(0)->getPt();

    double el_eta = el->at(0)->getEta();
    double mu_eta = mu->at(0)->getEta();

    double mu_phi = mu->at(0)->getPhi();
    int mu_isComb = mu->at(0)->getIsCombined();

    trigger_weight = m_trigger_reweight->triggerReweightEMU( el_pt, el_eta
                                                           , mu_pt, mu_eta, mu_phi, mu_isComb
                                                           , 0, num_vert
                                                           );
  }

  return trigger_weight;
}

// =============================================================================
PennSusyFrame::BTagScaleFactorTool::BTagScaleFactorTool() : m_b_tag_calibration(0)
{
  std::string root_core_dir = getenv("ROOTCOREDIR");
  std::string base_work_dir = getenv("BASE_WORK_DIR");
  m_calibration_file   = base_work_dir + "/data/BTagCalibration.env";
  m_calibration_folder = root_core_dir + "/../SUSYTools/data/";
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BTagScaleFactorTool::init(float mv1_cut_value)
{
  std::cout << "Init b tag scale factor tool\n";

  if (m_b_tag_calibration != 0)  {
    delete m_b_tag_calibration;
    m_b_tag_calibration = 0;
  }

  std::string cut_string = "";
  float cut_value = 0;
  if      (fabs(mv1_cut_value - 0.0617) < 0.01) { cut_string = "0_0617"; cut_value  = 0.0617; }
  else if (fabs(mv1_cut_value - 0.1340) < 0.01) { cut_string = "0_1340"; cut_value  = 0.1340; }
  else if (fabs(mv1_cut_value - 0.3511) < 0.01) { cut_string = "0_3511"; cut_value  = 0.3511; }
  else if (fabs(mv1_cut_value - 0.6073) < 0.01) { cut_string = "0_6073"; cut_value  = 0.6073; }
  else if (fabs(mv1_cut_value - 0.7892) < 0.01) { cut_string = "0_7892"; cut_value  = 0.7892; }
  else if (fabs(mv1_cut_value - 0.9370) < 0.01) { cut_string = "0_9370"; cut_value  = 0.9370; }
  else if (fabs(mv1_cut_value - 0.9827) < 0.01) { cut_string = "0_9827"; cut_value  = 0.9827; }
  else                                          { cut_string = "0_3511"; cut_value  = 0.3511; }

  std::cout << "\tcut value: " << cut_value << " -- cut string: " << cut_string << "\n";

  m_b_tag_calibration = new BTagCalib( "MV1"
                                     , m_calibration_file
                                     , m_calibration_folder
                                     , cut_string
                                     , false  // use_jvf
                                     , cut_value
                                     );

  // m_b_tag_calibration = new BTagCalib( "MV1" , m_calibration_file , m_calibration_folder , cut_string , false  , cut_value);

  // BTagCalibTool       = new BTagCalib( "MV1" , m_calibration_file , m_calibration_folder , "0_7892"   , useJVF , 0.7892   )
}

// -----------------------------------------------------------------------------
PennSusyFrame::BTagScaleFactorTool::~BTagScaleFactorTool()
{
  if (m_b_tag_calibration)
    delete m_b_tag_calibration;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::BTagScaleFactorTool::getSF(const std::vector<PennSusyFrame::Jet*>* jets)
{
  // vectors to hold jet info for valid jets
  std::vector<float> pt_btag;
  std::vector<float> eta_btag;
  std::vector<float> val_btag;
  std::vector<int>   pdgid_btag;

  size_t jet_term = jets->size();
  for (size_t jet_it = 0; jet_it != jet_term; ++jet_it) {
    float jet_pt = jets->at(jet_it)->getPt();
    float jet_eta = jets->at(jet_it)->getEta();

    // remove jets out of range for b-tagging
    if (jet_pt < 20.e3 || fabs(jet_eta) > 2.4) continue;

    pt_btag.push_back(jet_pt);
    eta_btag.push_back(jet_eta);
    val_btag.push_back(jets->at(jet_it)->getMv1());
    pdgid_btag.push_back(jets->at(jet_it)->getFlavorTruthLabel());
  }

  // calculate b tag weight
  std::pair<std::vector<float>, std::vector<float> > b_tag_weight;
  b_tag_weight = m_b_tag_calibration->BTagCalibrationFunction( pt_btag
                                                             , eta_btag
                                                             , val_btag
                                                             , pdgid_btag
                                                             );
  return b_tag_weight.first.at(0);
}
