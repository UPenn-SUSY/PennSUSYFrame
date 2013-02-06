#include "include/JetCalibTool.h"

// -----------------------------------------------------------------------------
CommonTools::JetCalibTool::JetCalibTool( SCycleBase* parent
                                       , const char* name
                                       )
                                       : ToolBase(parent, name)
                                       , m_jet_calibration(NULL)
                                       , m_jes_uncertainty(NULL)
{
  DeclareProperty("is_af2", c_is_af2 = false);
}

// -----------------------------------------------------------------------------
CommonTools::JetCalibTool::~JetCalibTool()
{
  if (m_jet_calibration)
    delete m_jet_calibration;
}

// -----------------------------------------------------------------------------
void CommonTools::JetCalibTool::BeginInputData(const SInputData&)
{
  // Configure Jet calibration
  std::string jet_algorithm = "AntiKt4LCTopo";

  std::string maindir = "";
  char *tmparea=getenv("ROOTCOREDIR");
  if (tmparea != NULL) {
    maindir = tmparea;
    maindir = maindir + "/";
  }

  std::string jes_config_file;
  std::string mc_type = "";
  if (c_is_af2){
    std::cout << "setting up JES for AF2\n";
    jes_config_file = maindir +
      "../ApplyJetCalibration/data/CalibrationConfigs/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_AFII_Jan13.config";
    mc_type = "AFII";
  } else {
    std::cout << "setting up JES for full sim\n";
    jes_config_file = maindir +
      "../ApplyJetCalibration/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_Jan13.config";
    mc_type = "MC12a";
  }

  m_jet_calibration = new JetCalibrationTool( jet_algorithm
                                            , jes_config_file
                                            , is_data()
                                            );
  m_jet_calibration->UseGeV(false);
}

// -----------------------------------------------------------------------------
void CommonTools::JetCalibTool::EndInputData(const SInputData&)
{
  // do nothing
}

// -----------------------------------------------------------------------------
TLorentzVector CommonTools::JetCalibTool::getConfiguredJet(
    Jet* jet,
    const Event* event,
    int num_vertices_w_2_trks)
{
  TLorentzVector tlv = m_jet_calibration->ApplyJetAreaOffsetEtaJES(
      jet->constscale_E(),
      jet->constscale_eta(),
      jet->constscale_phi(),
      jet->constscale_m(),
      jet->ActiveAreaPx(),
      jet->ActiveAreaPy(),
      jet->ActiveAreaPz(),
      jet->ActiveAreaE(),
      event->Eventshape_rhoKt4LC(),
      event->averageIntPerXing(),
      num_vertices_w_2_trks);

  // TLorentzVector tlv = m_jet_calibration->ApplyOffsetEtaJES(
  //     jet->constscale_E(),
  //     jet->constscale_eta(),
  //     jet->EtaOrigin(),
  //     jet->PhiOrigin(),
  //     jet->MOrigin(),
  //     mu,
  //     num_vetices_w_2_trks);

  return tlv;
}
