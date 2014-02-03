#include "PennSusyFrameCore/include/ScaleFactorTools.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"

// =============================================================================
// -----------------------------------------------------------------------------
// TODO set m_is_af2 correctly
PennSusyFrame::EgammaScaleFactorTool::EgammaScaleFactorTool() : m_is_af2(false)
{
  // get directory for SF files
  std::string maindir = "";
  char *tmparea=getenv("ROOTCOREDIR");
  maindir = tmparea;
  maindir = maindir + "/";
  m_egamma_sf_dir = maindir + "../ElectronEfficiencyCorrection/data/";

  // initialize reco sf
  m_reco_file_name = m_egamma_sf_dir + "efficiencySF.offline.RecoTrk.2012.8TeV.rel17p2.v02.root";
  m_eg_reco_sf.addFileName(m_reco_file_name);
  m_eg_reco_sf.initialize();

  // initialize tight sf
  m_tight_file_name = m_egamma_sf_dir + "efficiencySF.offline.Tight.2012.8TeV.rel17p2.v02.root";
  m_eg_tight_sf.addFileName(m_tight_file_name);
  m_eg_tight_sf.initialize();

  // // initialize trigger sf
  // m_trigger_file_name = m_egamma_sf_dir +"efficiencySF.e24vhi_medium1_e60_medium1.Tight.2012.8TeV.rel17p2.v02.root";
  // m_eg_trigger_sf.addFileName(m_trigger_file_name);
  // m_eg_trigger_sf.initialize();
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


  return ( result_reco.getTotalUncertainty()
         * result_tight.getTotalUncertainty()
         // * result_trigger.getTotalUncertainty()
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
