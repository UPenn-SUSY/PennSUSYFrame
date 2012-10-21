#include "include/JetCalibTool.h"

// ----------------------------------------------------------------------------
CommonTools::JetCalibTool::JetCalibTool( SCycleBase* parent
                                       , const char* name
                                       )
                                       : ToolBase(parent, name)
                                       , m_jet_calibration(NULL)
{
  DeclareProperty("is_af2", c_is_af2 = false);
}

// ----------------------------------------------------------------------------
CommonTools::JetCalibTool::~JetCalibTool()
{
  if (m_jet_calibration)
    delete m_jet_calibration;
}

// ----------------------------------------------------------------------------
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
  if (c_is_af2){
    jes_config_file
      = maindir + "../ApplyJetCalibration/data/CalibrationConfigs/JES_August2012_AFII.config";
  } else {
    jes_config_file
      = maindir + "../ApplyJetCalibration/data/CalibrationConfigs/JES_March2012.config";
  }

  m_jet_calibration = new JetCalibrationTool( jet_algorithm
                                            , jes_config_file
                                            , is_data()
                                            );
}

// ----------------------------------------------------------------------------
void CommonTools::JetCalibTool::EndInputData(const SInputData&)
{
  // do nothing
}

TLorentzVector CommonTools::JetCalibTool::getConfiguredJet(
    Jet* jet,
    float mu,
    int num_vetices_w_2_trks)
{
  TLorentzVector tlv = m_jet_calibration->ApplyOffsetEtaJES( jet->constscale_E()
                                                           , jet->constscale_eta()
                                                           , jet->EtaOrigin()
                                                           , jet->PhiOrigin()
                                                           , jet->MOrigin()
                                                           , mu
                                                           , num_vetices_w_2_trks
                                                           );
  return tlv;
}
