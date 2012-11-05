#include "include/EgammaEnergyRescaleTool.h"

#include <math.h>

// -----------------------------------------------------------------------------
CommonTools::EgammaEnergyRescaleTool::EgammaEnergyRescaleTool(
    SCycleBase* parent, const char* name) : ToolBase(parent, name)
{
  DeclareProperty("apply_systematics", c_apply_systematics = 0);
  DeclareProperty("is_af2", c_is_af2 = false);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
  m_eRescale.Init(energy_rescale_data, "2012", "es2010");;
}

// -----------------------------------------------------------------------------
void CommonTools::EgammaEnergyRescaleTool::BeginInputData(const SInputData&)
{
  // do nothing
}


// -----------------------------------------------------------------------------
void CommonTools::EgammaEnergyRescaleTool::EndInputData(const SInputData&)
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::EgammaEnergyRescaleTool::getRescaledE(const Electron* p)
{
  const float el_E_uncorrected = p->cl_E();
  float el_E_corrected = el_E_uncorrected;

  float el_eta    = p->getEta();
  float el_cl_eta = p->cl_eta();
  float el_cl_phi = p->cl_phi();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (!is_data()) {
    // Electron energy scale uncertainty
    el_E_corrected = m_eRescale.applyEnergyCorrection(
        el_cl_eta, el_E_uncorrected,
        egRescaler::EnergyRescalerUpgrade::Electron,
        egRescaler::EnergyRescalerUpgrade::Nominal);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // Do energy smearing in MC
    int seed = static_cast<int>(1.e+5*fabs(el_cl_phi));
    if (!seed) ++seed;
    m_eRescale.SetRandomSeed(seed);

    // find smearing correction
    double smearcorr = m_eRescale.getSmearingCorrection(
        el_cl_eta, el_E_uncorrected,
        egRescaler::EnergyRescalerUpgrade::NOMINAL);
    el_E_corrected *= smearcorr;

    // Apply Atlfast specific calibration corrections (Atlfast only)
    if (c_is_af2) {
      el_E_corrected *= m_eRescale.applyAFtoG4(el_cl_eta);
    }
  }
  else {
    // Residual energy scale correction for data
    el_E_corrected = m_eRescale.applyEnergyCorrection(
        el_cl_eta, el_E_uncorrected,
        egRescaler::EnergyRescalerUpgrade::Electron,
        egRescaler::EnergyRescalerUpgrade::Nominal);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_logger << DEBUG
           << "Original energy: " << el_E_uncorrected
           << " corrected energy: "<< el_E_corrected
           << SLogger::endmsg;

  return el_E_corrected;
}

// -----------------------------------------------------------------------------
double CommonTools::EgammaEnergyRescaleTool::getRescaledEt(const Electron* p)
{
  float el_E_corrected = getRescaledE(p);
  float el_Et_corrected = el_E_corrected/cosh(p->getEta());
  return el_Et_corrected;
}
