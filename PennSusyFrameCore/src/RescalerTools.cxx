#include "PennSusyFrameCore/include/RescalerTools.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"

// =============================================================================
// = ElectronRescalerTool
// =============================================================================
PennSusyFrame::ElectronRescalerTool::ElectronRescalerTool() : m_is_af2(false)
                                                            , m_systematics(0)
{
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
  m_e_rescale.Init(energy_rescale_data, "2012", "es2012");;
}

// -----------------------------------------------------------------------------
double getRescaledE( const PennSusyFrame::Electron* p)
{

  return p->getTlv()->Pt();
}

// -----------------------------------------------------------------------------
double getRescaledEt(const PennSusyFrame::Electron* p)
{
  float el_E_corrected = getRescaledE(p);
  // float el_Et_corrected = el_E_corrected/cosh(p->getEta());
  float el_Et_corrected = el_E_corrected/cosh(p->getTlv()->Eta());
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
