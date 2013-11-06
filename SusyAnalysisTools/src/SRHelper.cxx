#include "include/SRHelper.h"

// -----------------------------------------------------------------------------
SusyAnalysisTools::SRHelper::SRHelper()
{
  // do nothing
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::SRHelper::SRHelper(const ull_t evt_desc_int)
{
  set(evt_desc_int);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::SRHelper::~SRHelper()
{
  // do nothing
}

// -----------------------------------------------------------------------------
ull_t SusyAnalysisTools::SRHelper::toInt() const
{
  ull_t event_desc = 0;

  event_desc += getIntComp(m_pass_l_jet_veto, ADD_L_JET_VETO);
  event_desc += getIntComp(m_pass_b_jet_veto, ADD_B_JET_VETO);
  event_desc += getIntComp(m_pass_f_jet_veto, ADD_F_JET_VETO);
  event_desc += getIntComp(m_pass_z_veto    , ADD_Z_VETO    );
  event_desc += getIntComp(m_pass_top_veto  , ADD_TOP_VETO  );

  event_desc += getIntComp(m_pass_sr_ss_mll_veto, ADD_SR_SS_MLL_VETO);
  event_desc += getIntComp(m_pass_sr_ss_emma_mt , ADD_SR_SS_EMMA_MT );
  event_desc += getIntComp(m_pass_sr_ss_met_rel , ADD_SR_SS_MET_REL );
  event_desc += getIntComp(m_pass_sr_ss_dphi_ll , ADD_SR_SS_DPHI_LL );

  return event_desc;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::clear()
{
  *this = 0;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::set(const SusyAnalysisTools::SRHelper& rhs)
{
  set(rhs.toInt());
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::set(const ull_t& rhs)
{
  m_pass_l_jet_veto = getComponent(rhs, ADD_L_JET_VETO, SIZE_BOOL);
  m_pass_b_jet_veto = getComponent(rhs, ADD_B_JET_VETO, SIZE_BOOL);
  m_pass_f_jet_veto = getComponent(rhs, ADD_F_JET_VETO, SIZE_BOOL);
  m_pass_z_veto     = getComponent(rhs, ADD_Z_VETO    , SIZE_BOOL);
  m_pass_top_veto   = getComponent(rhs, ADD_TOP_VETO  , SIZE_BOOL);

  m_pass_sr_ss_mll_veto = getComponent(rhs,  ADD_SR_SS_MLL_VETO, SIZE_BOOL);
  m_pass_sr_ss_emma_mt  = getComponent(rhs,  ADD_SR_SS_EMMA_MT , SIZE_BOOL);
  m_pass_sr_ss_met_rel  = getComponent(rhs,  ADD_SR_SS_MET_REL , SIZE_BOOL);
  m_pass_sr_ss_dphi_ll  = getComponent(rhs,  ADD_SR_SS_DPHI_LL , SIZE_BOOL);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::SRHelper&
    SusyAnalysisTools::SRHelper::operator=(
        const SusyAnalysisTools::SRHelper& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::SRHelper&
    SusyAnalysisTools::SRHelper::operator=(const ull_t& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassLJetVeto(bool pass)
{
  m_pass_l_jet_veto = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassBJetVeto(bool pass)
{
  m_pass_b_jet_veto = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassFJetVeto(bool pass)
{
  m_pass_f_jet_veto = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassZVeto(bool pass)
{
  m_pass_z_veto = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassTopVeto(bool pass)
{
  m_pass_top_veto = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRSSMllVeto(bool pass)
{
  m_pass_sr_ss_mll_veto = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRSSEmmaMt(bool pass)
{
  m_pass_sr_ss_emma_mt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRSSMetRel(bool pass)
{
  m_pass_sr_ss_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRSSDphill(bool pass)
{
  m_pass_sr_ss_dphi_ll = pass;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassLJetVeto()
{
  return m_pass_l_jet_veto;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassBJetVeto()
{
  return m_pass_b_jet_veto;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassFJetVeto()
{
  return m_pass_f_jet_veto;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassZVeto()
{
  return m_pass_z_veto;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassTopVeto()
{
  return m_pass_top_veto;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRSSMllVeto()
{
  return m_pass_sr_ss_mll_veto;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRSSEmmaMt()
{
  return m_pass_sr_ss_emma_mt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRSSMetRel()
{
  return m_pass_sr_ss_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRSSDphill()
{
  return m_pass_sr_ss_dphi_ll;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::pass(const SRHelper& test) const
{
  ull_t this_word = toInt();
  ull_t test_word = test.toInt();

  return ((this_word & test_word) == test_word);
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::reverse(const SRHelper& test) const
{
  ull_t this_word = toInt();
  ull_t test_word = test.toInt();

  return ((~this_word & test_word) == test_word);
}

// -----------------------------------------------------------------------------
unsigned int SusyAnalysisTools::SRHelper::getComponent(
    const ull_t& rhs, unsigned int address, unsigned int size)
{
  return ( ((1 << size)-1) & (rhs >> address) );
}
