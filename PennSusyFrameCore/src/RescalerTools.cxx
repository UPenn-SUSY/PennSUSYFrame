#include "PennSusyFrameCore/include/RescalerTools.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"

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

  // double el_eta    = p->getRawEta();
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
PennSusyFrame::MuonRescalerTool::MuonRescalerTool()
{

}

// =============================================================================
// = JetRescalerTool
// =============================================================================
PennSusyFrame::JetRescalerTool::JetRescalerTool()
{

}
