#include "PennSusyFrameCore/include/ScaleFactorTools.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "RootCore/PileupReweighting/PileupReweighting/TPileupReweighting.h"

// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::PileUpScaleFactorTool::PileUpScaleFactorTool() : m_pile_up_reweight(0)
{
  // set data and mc histogram names
  m_data_hist_name = "LumiMetaData";
  m_mc_hist_name   = "MCPileupReweighting";

  // set data and mc pile up files
  char *tmparea=getenv("ROOTCOREDIR");
  std::string maindir = tmparea;
  m_pile_up_data_file = maindir + "/../MultiLep/data/ilumicalc_histograms_EF_2e12Tvh_loose1_200842-215643_grl_v61.root";
  m_pile_up_mc_file   = maindir + "/../PileupReweighting/share/mc12a_defaults.prw.root";

  std::cout << "initializing PileUpScaleFactorTool\n"
            << "\tMC file: "   << m_pile_up_mc_file   << "\n"
            << "\tData file: " << m_pile_up_data_file << "\n";

  // set up pile up reweight tool
  m_pile_up_reweight = new Root::TPileupReweighting("TPileupReweighting");
  m_pile_up_reweight->SetDefaultChannel(0);
  m_pile_up_reweight->AddConfigFile(m_pile_up_mc_file);

  m_pile_up_reweight->SetDataScaleFactors(1/1.09);
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

// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::EgammaScaleFactorTool::EgammaScaleFactorTool() : m_is_af2(false)
{
  // get directory for SF files
  std::string maindir = "";
  char *tmparea=getenv("ROOTCOREDIR");
  maindir = tmparea;
  maindir = maindir + "/";
  m_egamma_sf_dir = maindir + "../ElectronEfficiencyCorrection/data/";

  // initialize reco sf
  m_reco_file_name = m_egamma_sf_dir + "efficiencySF.offline.RecoTrk.2012.8TeV.rel17p2.v04.root";
  std::cout << "Adding file to Egamma reco sf tool: " << m_reco_file_name << "\n";
  m_eg_reco_sf.addFileName(m_reco_file_name);
  m_eg_reco_sf.initialize();

  // initialize tight sf
  m_tight_file_name = m_egamma_sf_dir + "efficiencySF.offline.Tight.2012.8TeV.rel17p2.v04.root";
  std::cout << "Adding file to Egamma tight sf tool: " << m_tight_file_name << "\n";
  m_eg_tight_sf.addFileName(m_tight_file_name);
  m_eg_tight_sf.initialize();
}

// -----------------------------------------------------------------------------
double PennSusyFrame::EgammaScaleFactorTool::getSF( const PennSusyFrame::Event& event
                                                  , const PennSusyFrame::Electron* el
                                                  )
{
  float cl_eta = el->getClEta();
  float pt = el->getPt();

  PATCore::ParticleDataType::DataType data_type = ( m_is_af2
                                                  ? PATCore::ParticleDataType::Fast
                                                  : PATCore::ParticleDataType::Full
                                                  );


  Root::TResult result_reco = m_eg_reco_sf.calculate( data_type
  					                                        , event.getRunNumber()
  					                                        , cl_eta
  					                                        , pt
                                                    );
  Root::TResult result_tight = m_eg_tight_sf.calculate( data_type
  					                                          , event.getRunNumber()
  					                                          , cl_eta
  					                                          , pt
                                                      );

  return ( result_reco.getScaleFactor()
         * result_tight.getScaleFactor()
         );
}

// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::MuonScaleFactorTool::MuonScaleFactorTool() : m_muon_sf(0)
{
  // get default path for muon SF directory. This comes from SUSYTools
  std::string maindir = "";
  char *tmparea=getenv("ROOTCOREDIR");
  if (tmparea != NULL) {
    maindir = tmparea;
    maindir = maindir + "/";
  }
  m_muon_sf_dir = maindir + "../MuonEfficiencyCorrections/share/";

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
  if (m_muon_sf) delete m_muon_sf;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::MuonScaleFactorTool::getSF(const PennSusyFrame::Muon* mu)
{
  return m_muon_sf->scaleFactor(mu->getCharge(), *mu->getTlv());
}
