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

  tau_desc += getIntComp(m_pass_baseline               , ADD_BASELINE               );
  tau_desc += getIntComp(m_pass_good                   , ADD_GOOD                   );
  tau_desc += getIntComp(m_pass_signal                 , ADD_SIGNAL                 );
  tau_desc += getIntComp(m_pass_baseline_pt            , ADD_BASELINE_PT            );
  tau_desc += getIntComp(m_pass_baseline_eta           , ADD_BASELINE_ETA           );
  tau_desc += getIntComp(m_pass_baseline_num_tracks    , ADD_BASELINE_NUM_TRACKS    );
  tau_desc += getIntComp(m_pass_baseline_charge        , ADD_BASELINE_CHARGE        );
  tau_desc += getIntComp(m_pass_baseline_jet_bdt_level , ADD_BASELINE_JET_BDT_LEVEL );
  tau_desc += getIntComp(m_pass_baseline_elebdt_level  , ADD_BASELINE_ELEBDT_LEVEL  );
  tau_desc += getIntComp(m_pass_baseline_mu_veto       , ADD_BASELINE_MU_VETO       );
  tau_desc += getIntComp(m_pass_signal_jet_bdt_level   , ADD_SIGNAL_JET_BDT_LEVEL   );
  tau_desc += getIntComp(m_pass_signal_elebdt_level    , ADD_SIGNAL_ELEBDT_LEVEL    );
  tau_desc += getIntComp(m_pass_signal_mu_veto         , ADD_SIGNAL_MU_VETO         );

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
  m_pass_good         = getComponent(rhs, ADD_GOOD        , SIZE_BOOL);
  m_pass_signal       = getComponent(rhs, ADD_SIGNAL      , SIZE_BOOL);

  m_pass_baseline_pt            = getComponent(rhs, ADD_BASELINE_PT           , SIZE_BOOL);
  m_pass_baseline_eta           = getComponent(rhs, ADD_BASELINE_ETA          , SIZE_BOOL);
  m_pass_baseline_num_tracks    = getComponent(rhs, ADD_BASELINE_NUM_TRACKS   , SIZE_BOOL);
  m_pass_baseline_charge        = getComponent(rhs, ADD_BASELINE_CHARGE       , SIZE_BOOL);
  m_pass_baseline_jet_bdt_level = getComponent(rhs, ADD_BASELINE_JET_BDT_LEVEL, SIZE_BOOL);
  m_pass_baseline_elebdt_level  = getComponent(rhs, ADD_BASELINE_ELEBDT_LEVEL , SIZE_BOOL);
  m_pass_baseline_mu_veto       = getComponent(rhs, ADD_BASELINE_MU_VETO      , SIZE_BOOL);
  m_pass_signal_jet_bdt_level   = getComponent(rhs, ADD_SIGNAL_JET_BDT_LEVEL  , SIZE_BOOL);
  m_pass_signal_elebdt_level    = getComponent(rhs, ADD_SIGNAL_ELEBDT_LEVEL   , SIZE_BOOL);
  m_pass_signal_mu_veto         = getComponent(rhs, ADD_SIGNAL_MU_VETO        , SIZE_BOOL);
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

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassGood(bool pass)
{
  m_pass_good = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassSignal(bool pass)
{
  m_pass_signal = pass;
}

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
void SusyAnalysisTools::TauDescription::setPassSignalJetBDTLevel(bool pass)
{
  m_pass_signal_jet_bdt_level = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassSignalEleBDTLevel(bool pass)
{
  m_pass_signal_elebdt_level = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::TauDescription::setPassSignalMuVeto(bool pass)
{
  m_pass_signal_mu_veto = pass;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassBaseline() const
{
  return m_pass_baseline;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassGood() const
{
  return m_pass_good;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassSignal() const
{
  return m_pass_signal;
}

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
bool SusyAnalysisTools::TauDescription::getPassSignalJetBDTLevel() const
{
  return m_pass_signal_jet_bdt_level;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassSignalEleBDTLevel() const
{
  return m_pass_signal_elebdt_level;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::TauDescription::getPassSignalMuVeto() const
{
  return m_pass_signal_mu_veto;
}

// -----------------------------------------------------------------------------
unsigned int SusyAnalysisTools::TauDescription::getComponent(
    const ull_t& rhs, unsigned int address, unsigned int size)
{
  return ( ((1 << size)-1) & (rhs >> address) );
}
