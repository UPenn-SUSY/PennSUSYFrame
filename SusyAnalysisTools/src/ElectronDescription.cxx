#include "SusyAnalysisTools/include/ElectronDescription.h"

// -----------------------------------------------------------------------------
SusyAnalysisTools::ElectronDescription::ElectronDescription()
{
  // do nothing
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::ElectronDescription::ElectronDescription(
    const ull_t evt_desc_int)
{
  set(evt_desc_int);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::ElectronDescription::~ElectronDescription()
{
  // do nothing
}

// -----------------------------------------------------------------------------
ull_t SusyAnalysisTools::ElectronDescription::toInt() const
{
  ull_t el_desc = 0;

  el_desc += getIntComp(m_pass_baseline         , ADD_BASELINE        );
  el_desc += getIntComp(m_pass_good             , ADD_GOOD            );
  el_desc += getIntComp(m_pass_signal           , ADD_SIGNAL          );
  el_desc += getIntComp(m_pass_cluster_seed     , ADD_CLUSTER_SEED    );
  el_desc += getIntComp(m_pass_otx              , ADD_OTX             );
  el_desc += getIntComp(m_pass_medium_pp        , ADD_MEDIUM_PP       );
  el_desc += getIntComp(m_pass_baseline_pt      , ADD_BASELINE_PT     );
  el_desc += getIntComp(m_pass_baseline_eta     , ADD_BASELINE_ETA    );
  el_desc += getIntComp(m_pass_tight_pp         , ADD_TIGHT_PP        );
  el_desc += getIntComp(m_pass_d0_sig           , ADD_D0_SIG          );
  el_desc += getIntComp(m_pass_z0_sin_theta     , ADD_Z0_SIN_THETA    );
  el_desc += getIntComp(m_pass_pt_iso           , ADD_PT_ISO          );
  el_desc += getIntComp(m_pass_calo_iso         , ADD_CALO_ISO        );
  el_desc += getIntComp(m_pass_likelihood_medium, ADD_LIKELIHOOD_MED  );
  el_desc += getIntComp(m_pass_likelihood_tight , ADD_LIKELIHOOD_TIGHT);

  return el_desc;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::clear()
{
  *this = 0;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::set(
    const SusyAnalysisTools::ElectronDescription& rhs)
{
  set(rhs.toInt());
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::set(const ull_t& rhs)
{
  m_pass_baseline          = getComponent(rhs, ADD_BASELINE         ,SIZE_BOOL);
  m_pass_good              = getComponent(rhs, ADD_GOOD             ,SIZE_BOOL);
  m_pass_signal            = getComponent(rhs, ADD_SIGNAL           ,SIZE_BOOL);
  m_pass_cluster_seed      = getComponent(rhs, ADD_CLUSTER_SEED     ,SIZE_BOOL);
  m_pass_otx               = getComponent(rhs, ADD_OTX              ,SIZE_BOOL);
  m_pass_medium_pp         = getComponent(rhs, ADD_MEDIUM_PP        ,SIZE_BOOL);
  m_pass_baseline_pt       = getComponent(rhs, ADD_BASELINE_PT      ,SIZE_BOOL);
  m_pass_baseline_eta      = getComponent(rhs, ADD_BASELINE_ETA     ,SIZE_BOOL);
  m_pass_tight_pp          = getComponent(rhs, ADD_TIGHT_PP         ,SIZE_BOOL);
  m_pass_d0_sig            = getComponent(rhs, ADD_D0_SIG           ,SIZE_BOOL);
  m_pass_z0_sin_theta      = getComponent(rhs, ADD_Z0_SIN_THETA     ,SIZE_BOOL);
  m_pass_pt_iso            = getComponent(rhs, ADD_PT_ISO           ,SIZE_BOOL);
  m_pass_calo_iso          = getComponent(rhs, ADD_CALO_ISO         ,SIZE_BOOL);
  m_pass_likelihood_medium = getComponent(rhs, ADD_LIKELIHOOD_MED   ,SIZE_BOOL);
  m_pass_likelihood_tight  = getComponent(rhs, ADD_LIKELIHOOD_TIGHT ,SIZE_BOOL);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::ElectronDescription&
    SusyAnalysisTools::ElectronDescription::operator=(
        const SusyAnalysisTools::ElectronDescription& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::ElectronDescription&
    SusyAnalysisTools::ElectronDescription::operator=(const ull_t& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassBaseline(bool pass)
{
  m_pass_baseline = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassGood(bool pass)
{
  m_pass_good = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassSignal(bool pass)
{
  m_pass_signal = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassClusterSeed(bool pass)
{
  m_pass_cluster_seed = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassOtx(bool pass)
{
  m_pass_otx = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassMediumPP(bool pass)
{
  m_pass_medium_pp = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassBaselinePt(bool pass)
{
  m_pass_baseline_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassBaselineEta(bool pass)
{
  m_pass_baseline_eta = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassTightPP(bool pass)
{
  m_pass_tight_pp = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassD0Sig(bool pass)
{
  m_pass_d0_sig = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassZ0SinTheta(bool pass)
{
  m_pass_z0_sin_theta = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassPtIso(bool pass)
{
  m_pass_pt_iso = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassCaloIso(bool pass)
{
  m_pass_calo_iso = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassLikelihoodMedium(bool pass)
{
  m_pass_likelihood_medium = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::ElectronDescription::setPassLikelihoodTight(bool pass)
{
  m_pass_likelihood_tight = pass;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassBaseline() const
{
  return m_pass_baseline;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassGood() const
{
  return m_pass_good;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassSignal() const
{
  return m_pass_signal;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassClusterSeed() const
{
  return m_pass_cluster_seed;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassOtx() const
{
  return m_pass_otx;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassMediumPP() const
{
  return m_pass_medium_pp;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassBaselinePt() const
{
  return m_pass_baseline_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassBaselineEta() const
{
  return m_pass_baseline_eta;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassTightPP() const
{
  return m_pass_tight_pp;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassD0Sig() const
{
  return m_pass_d0_sig;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassZ0SinTheta() const
{
  return m_pass_z0_sin_theta;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassPtIso() const
{
  return m_pass_pt_iso;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassCaloIso() const
{
  return m_pass_calo_iso;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassLikelihoodMedium() const
{
  return m_pass_likelihood_medium;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::ElectronDescription::getPassLikelihoodTight() const
{
  return m_pass_likelihood_tight;
}

// -----------------------------------------------------------------------------
unsigned int SusyAnalysisTools::ElectronDescription::getComponent(
    const ull_t& rhs, unsigned int address, unsigned int size)
{
  return ( ((1 << size)-1) & (rhs >> address) );
}
