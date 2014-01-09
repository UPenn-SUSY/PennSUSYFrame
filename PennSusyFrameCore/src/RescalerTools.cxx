#include "PennSusyFrameCore/include/RescalerTools.h"

#include <string>

#include "TLorentzVector.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "RootCore/egammaAnalysisUtils/egammaAnalysisUtils/EnergyRescalerUpgrade.h"
#include "RootCore/MuonMomentumCorrections/MuonMomentumCorrections/SmearingClass.h"
#include "RootCore/ApplyJetCalibration/ApplyJetCalibration/ApplyJetCalibration.h"

// =============================================================================
// = ElectronRescalerTool
// =============================================================================
// TODO set m_is_af2 correctly
// TODO set m_is_data correctly
// TODO set m_systematics correctly
PennSusyFrame::ElectronRescalerTool::ElectronRescalerTool() : m_is_data(false)
                                                            , m_is_af2(false)
                                                            , m_systematics(0)
{
  std::cout << "ElectronRescalerTool::ElectronRescalerTool()\n";
  // directory with energy rescale data
  // get default path for muon SF directory.  This comes from SUSYTools
  std::string maindir = "";
  char *tmparea=getenv("ROOTCOREDIR");
  if (tmparea != NULL) {
    maindir = tmparea;
    maindir = maindir + "/";
  }
  std::string energy_rescale_data =
      maindir + "/../egammaAnalysisUtils/share/EnergyRescalerData.root";
  std::cout << "initializing ElectronRescalerTool -- energy_rescale_data: " << energy_rescale_data << "\n";

  // m_e_rescale = new egRescaler::EnergyRescalerUpgrade();
  // m_e_rescale->Init(energy_rescale_data, "2012", "es2012");;
  m_e_rescale = new egRescaler::EnergyRescalerUpgrade(energy_rescale_data, "2012", "es2012");
  std::cout << "end ElectronRescalerTool::ElectronRescalerTool()\n";
}

PennSusyFrame::ElectronRescalerTool::~ElectronRescalerTool()
{
  delete m_e_rescale;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::ElectronRescalerTool::getRescaledE( const PennSusyFrame::Electron* p)
{
  const double el_E_uncorrected = p->getClE();
  double el_E_corrected = el_E_uncorrected;

  double el_cl_eta = p->getClEta();
  double el_cl_phi = p->getClPhi();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (!m_is_data) {
    // // Electron energy scale uncertainty
    // el_E_corrected = m_e_rescale->applyEnergyCorrection( el_cl_eta
    //                                                    , el_E_uncorrected
    //                                                    , egRescaler::EnergyRescalerUpgrade::Electron
    //                                                    , egRescaler::EnergyRescalerUpgrade::Nominal
    //                                                    );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // Do energy smearing in MC
    int seed = static_cast<int>(1.e+5*fabs(el_cl_phi));
    if (!seed) ++seed;
    m_e_rescale->SetRandomSeed(seed);

    // find smearing correction
    double smearcorr = m_e_rescale->getSmearingCorrection( el_cl_eta
                                                         , el_E_uncorrected
                                                         , egRescaler::EnergyRescalerUpgrade::NOMINAL
                                                         );
    el_E_corrected *= smearcorr;

    // Apply Atlfast specific calibration corrections (Atlfast only)
    if (m_is_af2) {
      el_E_corrected *= m_e_rescale->applyAFtoG4(el_cl_eta);
    }
  }
  else {
    // Residual energy scale correction for data
    el_E_corrected = m_e_rescale->applyEnergyCorrection( el_cl_eta
                                                       , el_E_uncorrected
                                                       , egRescaler::EnergyRescalerUpgrade::Electron
                                                       , egRescaler::EnergyRescalerUpgrade::Nominal
                                                       );
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // std::cout << "Original energy: " << el_E_uncorrected
  //           << " corrected energy: "<< el_E_corrected
  //           << SLogger::endmsg;

  return el_E_corrected;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::ElectronRescalerTool::getRescaledEt(const PennSusyFrame::Electron* p)
{
  return 0.;

  double el_E_corrected = getRescaledE(p);
  double el_Et_corrected = el_E_corrected/cosh(p->getRawEta());
  return el_Et_corrected;
}

// =============================================================================
// = MuonRescalerTool
// =============================================================================
// TODO set m_is_data correctly
PennSusyFrame::MuonRescalerTool::MuonRescalerTool() : m_is_data(false)
                                                    , m_smearing_function("")
{
  if (m_is_data) return;

  // get default path for muon SF directory.  This comes from SUSYTools
  std::string maindir = "";
  char *tmparea=getenv("ROOTCOREDIR");
  if (tmparea != NULL) {
    maindir = tmparea;
    maindir = maindir + "/";
  }
  // Default path
  m_muon_momentum_dir = maindir + "/../MuonMomentumCorrections/share/";

  std::cout << "Muon momentum smearing will be grabbed from: "
            << m_muon_momentum_dir << "\n";

  // create mcp smearing object
  m_mcp_smear = new MuonSmear::SmearingClass( "Data12"
                                            , "staco"
                                            , "q_pT"
                                            , "Rel17.2Repro"
                                            , m_muon_momentum_dir
                                            );
}

// -----------------------------------------------------------------------------
PennSusyFrame::MuonRescalerTool::~MuonRescalerTool()
{
  if (m_mcp_smear)
    delete m_mcp_smear;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::MuonRescalerTool::getSmearedPt(const PennSusyFrame::Muon* p)
{
  double my_pt = p->getRawPt();

  // if not data, apply momentum smearing
  if (!m_is_data) {
    double mu_eta = p->getRawEta();
    double mu_phi = p->getRawPhi();

    if (m_mcp_smear) {
      // combined muon pt
      double pt_cb = my_pt;
      // id only pt
      double pt_id = ( (p->getIdQOverP() !=0) ? fabs(sin(p->getIdTheta())/p->getIdQOverP())
                                              : 0
                     );
      // MS only pt
      double pt_ms = ( (p->getMEQOverP() !=0) ? fabs(sin(p->getMETheta())/p->getMEQOverP())
                                              : 0
                     );

      // set seed based on the muon phi measurement. If seed is exactly 0, increment
      int seed = static_cast<int>(1.e+5*fabs(mu_phi));
      if (!seed) ++seed;
      m_mcp_smear->SetSeed(seed);

      // smear muon based on smearing function
      if (m_smearing_function == "") {
        // if combined muon
        if (p->getIsCombined()) {
          m_mcp_smear->Event(pt_ms, pt_id, pt_cb, mu_eta, p->getCharge());
          my_pt = m_mcp_smear->pTCB();
        }
        // else if segment tagged muon
        else if (p->getIsSegmentTagged()) {
          m_mcp_smear->Event(pt_id, mu_eta, "ID", p->getCharge());
          my_pt = m_mcp_smear->pTID();
        }
        // else if ms only muon
        else {
          m_mcp_smear->Event(pt_ms, mu_eta, "MS", p->getCharge());
          my_pt = m_mcp_smear->pTMS();
        }
      }
      else {
        double pTMS_smeared = 0.;
        double pTID_smeared = 0.;
        double pTCB_smeared = 0.;

        // Valid values for "c_smearing_function":
        //   {"MSLOW", "MSUP", "IDLOW", "IDUP","SCALELOW", "SCALEUP"}
        m_mcp_smear->PTVar( pTMS_smeared
                          , pTID_smeared
                          , pTCB_smeared
                          , m_smearing_function
                          );

        if (p->getIsCombined())
          my_pt = pTCB_smeared;
        else if (p->getIsSegmentTagged())
          my_pt = pTID_smeared;
        else
          my_pt = pTMS_smeared;
      }
    }
  }

  return my_pt;
}

// =============================================================================
// = JetRescalerTool
// =============================================================================
PennSusyFrame::JetRescalerTool::JetRescalerTool() : m_is_data(false)
                                                  , m_is_af2(false)
{
  std::string jet_algorithm = "AntiKt4LCTopo";

  std::string maindir = "";
  char *tmparea=getenv("ROOTCOREDIR");
  if (tmparea != NULL) {
    maindir = tmparea;
    maindir = maindir + "/";
  }

  std::string jes_config_file;
  std::string mc_type = "";
  if (m_is_af2) {
    std::cout << "setting up JES for AF2\n";
    jes_config_file = maindir +
      "../ApplyJetCalibration/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_AFII_Jan13.config";
    mc_type = "AFII";
  } else {
    std::cout << "setting up JES for full sim\n";
    jes_config_file = maindir +
      "../ApplyJetCalibration/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_Jan13.config";
    mc_type = "MC12a";
  }

  m_jet_calibration = new JetCalibrationTool( jet_algorithm
                                            , jes_config_file
                                            , m_is_data
                                            );
  m_jet_calibration->UseGeV(false);
}

// -----------------------------------------------------------------------------
PennSusyFrame::JetRescalerTool::~JetRescalerTool()
{
  delete m_jet_calibration;
}

// -----------------------------------------------------------------------------
// TODO get proper calibratd jet tlv
TLorentzVector PennSusyFrame::JetRescalerTool::getCalibratedTlv(const PennSusyFrame::Jet* p)
{
  return *(p->getRawTlv());
}
