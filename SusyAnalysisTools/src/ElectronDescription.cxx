#include "include/ElectronDescription.h"

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

  el_desc += getIntComp(m_pass_baseline,     ADD_BASELINE    );
  el_desc += getIntComp(m_pass_good,         ADD_GOOD        );
  el_desc += getIntComp(m_pass_signal,       ADD_SIGNAL      );
  el_desc += getIntComp(m_pass_cluster_seed, ADD_CLUSTER_SEED);
  el_desc += getIntComp(m_pass_otx,          ADD_OTX         );
  el_desc += getIntComp(m_pass_medium_pp,    ADD_MEDIUM_PP   );
  el_desc += getIntComp(m_pass_baseline_pt,  ADD_BASELINE_PT );
  el_desc += getIntComp(m_pass_baseline_eta, ADD_BASELINE_ETA);
  el_desc += getIntComp(m_pass_tight_pp,     ADD_TIGHT_PP    );
  el_desc += getIntComp(m_pass_d0_sig,       ADD_D0_SIG      );
  el_desc += getIntComp(m_pass_z0_sin_theta, ADD_Z0_SIN_THETA);
  el_desc += getIntComp(m_pass_pt_iso,       ADD_PT_ISO      );
  el_desc += getIntComp(m_pass_calo_iso,     ADD_CALO_ISO    );

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
  m_pass_baseline     = getComponent(rhs, ADD_BASELINE,     SIZE_BOOL);
  m_pass_good         = getComponent(rhs, ADD_GOOD,         SIZE_BOOL);
  m_pass_signal       = getComponent(rhs, ADD_SIGNAL,       SIZE_BOOL);
  m_pass_cluster_seed = getComponent(rhs, ADD_CLUSTER_SEED, SIZE_BOOL);
  m_pass_otx          = getComponent(rhs, ADD_OTX,          SIZE_BOOL);
  m_pass_medium_pp    = getComponent(rhs, ADD_MEDIUM_PP,    SIZE_BOOL);
  m_pass_baseline_pt  = getComponent(rhs, ADD_BASELINE_PT,  SIZE_BOOL);
  m_pass_baseline_eta = getComponent(rhs, ADD_BASELINE_ETA, SIZE_BOOL);
  m_pass_tight_pp     = getComponent(rhs, ADD_TIGHT_PP,     SIZE_BOOL);
  m_pass_d0_sig       = getComponent(rhs, ADD_D0_SIG,       SIZE_BOOL);
  m_pass_z0_sin_theta = getComponent(rhs, ADD_Z0_SIN_THETA, SIZE_BOOL);
  m_pass_pt_iso       = getComponent(rhs, ADD_PT_ISO,       SIZE_BOOL);
  m_pass_calo_iso     = getComponent(rhs, ADD_CALO_ISO,     SIZE_BOOL);
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
bool SusyAnalysisTools::ElectronDescription::getPassBaseline() const
{
  return m_pass_baseline;
}

// -----------------------------------------------------------------------------
unsigned int SusyAnalysisTools::ElectronDescription::getComponent(
    const ull_t& rhs, unsigned int address, unsigned int size)
{
  return ( ((1 << size)-1) & (rhs >> address) );
}
