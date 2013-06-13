#include "include/TauDescription.h"

// -----------------------------------------------------------------------------
SusyAnalysisTools::TauDescription::TauDescription()
{
  // do nothing
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::TauDescription::TauDescription(
    const ull_t evt_desc_int)
{
  set(evt_desc_int);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::TauDescription::~TauDescription()
{
  // do nothing
}

// -----------------------------------------------------------------------------
ull_t SusyAnalysisTools::TauDescription::toInt() const
{
  ull_t tau_desc = 0;

  tau_desc += getIntComp(m_pass_baseline, ADD_BASELINE);

  tau_desc += getIntComp(m_pass_baseline    , ADD_BASELINE    );
  // tau_desc += getIntComp(m_pass_good        , ADD_GOOD        );
  // tau_desc += getIntComp(m_pass_signal      , ADD_SIGNAL      );
  // tau_desc += getIntComp(m_pass_bad         , ADD_BAD         );
  // tau_desc += getIntComp(m_pass_cosmic      , ADD_COSMIC      );
  // tau_desc += getIntComp(m_pass_loose       , ADD_LOOSE       );
  // tau_desc += getIntComp(m_pass_seg_tag     , ADD_SEG_TAG     );
  // tau_desc += getIntComp(m_pass_combined    , ADD_COMBINED    );
  // tau_desc += getIntComp(m_pass_b_layer     , ADD_B_LAYER     );
  // tau_desc += getIntComp(m_pass_pixel       , ADD_PIXEL       );
  // tau_desc += getIntComp(m_pass_sct         , ADD_SCT         );
  // tau_desc += getIntComp(m_pass_trt         , ADD_TRT         );
  // tau_desc += getIntComp(m_pass_si_holes    , ADD_SI_HOLES    );
  // tau_desc += getIntComp(m_pass_baseline_pt , ADD_BASELINE_PT );
  // tau_desc += getIntComp(m_pass_baseline_eta, ADD_BASELINE_ETA);
  // tau_desc += getIntComp(m_pass_d0_sig      , ADD_D0_SIG      );
  // tau_desc += getIntComp(m_pass_z0_sin_theta, ADD_Z0_SIN_THETA);
  // tau_desc += getIntComp(m_pass_pt_iso      , ADD_PT_ISO      );

  return tau_desc;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::clear()
{
  *this = 0;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::set(
    const SusyAnalysisTools::TauDescription& rhs)
{
  set(rhs.toInt());
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::set(const ull_t& rhs)
{
  m_pass_baseline     = getComponent(rhs, ADD_BASELINE    , SIZE_BOOL);
  // m_pass_good         = getComponent(rhs, ADD_GOOD        , SIZE_BOOL);
  // m_pass_signal       = getComponent(rhs, ADD_SIGNAL      , SIZE_BOOL);
  // m_pass_bad          = getComponent(rhs, ADD_BAD         , SIZE_BOOL);
  // m_pass_cosmic       = getComponent(rhs, ADD_COSMIC      , SIZE_BOOL);
  // m_pass_loose        = getComponent(rhs, ADD_LOOSE       , SIZE_BOOL);
  // m_pass_seg_tag      = getComponent(rhs, ADD_SEG_TAG     , SIZE_BOOL);
  // m_pass_combined     = getComponent(rhs, ADD_COMBINED    , SIZE_BOOL);
  // m_pass_b_layer      = getComponent(rhs, ADD_B_LAYER     , SIZE_BOOL);
  // m_pass_pixel        = getComponent(rhs, ADD_PIXEL       , SIZE_BOOL);
  // m_pass_sct          = getComponent(rhs, ADD_SCT         , SIZE_BOOL);
  // m_pass_trt          = getComponent(rhs, ADD_TRT         , SIZE_BOOL);
  // m_pass_si_holes     = getComponent(rhs, ADD_SI_HOLES    , SIZE_BOOL);
  // m_pass_baseline_pt  = getComponent(rhs, ADD_BASELINE_PT , SIZE_BOOL);
  // m_pass_baseline_eta = getComponent(rhs, ADD_BASELINE_ETA, SIZE_BOOL);
  // m_pass_d0_sig       = getComponent(rhs, ADD_D0_SIG      , SIZE_BOOL);
  // m_pass_z0_sin_theta = getComponent(rhs, ADD_Z0_SIN_THETA, SIZE_BOOL);
  // m_pass_pt_iso       = getComponent(rhs, ADD_PT_ISO      , SIZE_BOOL);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::TauDescription&
    SusyAnalysisTools::TauDescription::operator=(
        const SusyAnalysisTools::TauDescription& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::TauDescription&
    SusyAnalysisTools::TauDescription::operator=(const ull_t& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassBaseline(bool pass)
{
  m_pass_baseline = pass;
}

// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassGood(bool pass)
// {
//   m_pass_good = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassSignal(bool pass)
// {
//   m_pass_signal = pass;
// }

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassBaselinePt(bool pass)
{
  m_pass_baseline_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassBaselineEta(bool pass)
{
  m_pass_baseline_eta = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassBaselineNumTracks(bool pass)
{
  m_pass_baseline_num_tracks = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassBaselineCharge(bool pass)
{
  m_pass_baseline_charge = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassBaselineJetBDTLevel(bool pass)
{
  m_pass_baseline_jet_bdt_level = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassBaselineEleBDTLevel(bool pass)
{
  m_pass_baseline_elebdt_level = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassBaselineMuVeto(bool pass)
{
  m_pass_baseline_mu_veto = pass;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassBaseline() const
{
  return m_pass_baseline;
}

// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassGood() const
// {
//   return m_pass_good;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassSignal() const
// {
//   return m_pass_signal;
// }

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassBaselinePt() const
{
  return m_pass_baseline_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassBaselineEta() const
{
  return m_pass_baseline_eta;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassBaselineNumTracks() const
{
  return m_pass_baseline_num_tracks;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassBaselineCharge() const
{
  return m_pass_baseline_charge;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassBaselineJetBDTLevel() const
{
  return m_pass_baseline_jet_bdt_level;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassBaselineEleBDTLevel() const
{
  return m_pass_baseline_elebdt_level;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassBaselineMuVeto() const
{
  return m_pass_baseline_mu_veto;
}

// -----------------------------------------------------------------------------
unsigned int SusyAnalysisTools::TauDescription::getComponent(
    const ull_t& rhs, unsigned int address, unsigned int size)
{
  return ( ((1 << size)-1) & (rhs >> address) );
}
