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

  event_desc += getIntComp(m_pass_sr1_met_rel, ADD_SR1_MET_REL);
  event_desc += getIntComp(m_pass_sr2_met_rel, ADD_SR2_MET_REL);
  event_desc += getIntComp(m_pass_sr3_2_l_jet, ADD_SR3_2_L_JET);
  event_desc += getIntComp(m_pass_sr3_met_rel, ADD_SR3_MET_REL);
  event_desc += getIntComp(m_pass_sr4_met_rel, ADD_SR4_MET_REL);
  event_desc += getIntComp(m_pass_sr4a_mt2   , ADD_SR4a_MT2   );
  event_desc += getIntComp(m_pass_sr4b_mt2   , ADD_SR4b_MT2   );

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

  m_pass_sr1_met_rel = getComponent(rhs, ADD_SR1_MET_REL, SIZE_BOOL);
  m_pass_sr2_met_rel = getComponent(rhs, ADD_SR2_MET_REL, SIZE_BOOL);
  m_pass_sr3_2_l_jet = getComponent(rhs, ADD_SR3_2_L_JET, SIZE_BOOL);
  m_pass_sr3_met_rel = getComponent(rhs, ADD_SR3_MET_REL, SIZE_BOOL);
  m_pass_sr4_met_rel = getComponent(rhs, ADD_SR4_MET_REL, SIZE_BOOL);
  m_pass_sr4a_mt2    = getComponent(rhs, ADD_SR4a_MT2   , SIZE_BOOL);
  m_pass_sr4b_mt2    = getComponent(rhs, ADD_SR4b_MT2   , SIZE_BOOL);
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
void SusyAnalysisTools::SRHelper::setPassSR1MetRel(bool pass)
{
  m_pass_sr1_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSR2MetRel(bool pass)
{
  m_pass_sr2_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSR32LJet(bool pass)
{
  m_pass_sr3_2_l_jet = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSR3MetRel(bool pass)
{
  m_pass_sr3_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSR4MetRel(bool pass)
{
  m_pass_sr4_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSR4aMt2(bool pass)
{
  m_pass_sr4a_mt2 = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSR4bMt2(bool pass)
{
  m_pass_sr4b_mt2 = pass;
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
bool SusyAnalysisTools::SRHelper::getPassSR1MetRel()
{
  return m_pass_sr1_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSR2MetRel()
{
  return m_pass_sr2_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSR32LJet()
{
  return m_pass_sr3_2_l_jet;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSR3MetRel()
{
  return m_pass_sr3_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSR4MetRel()
{
  return m_pass_sr4_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSR4aMt2()
{
  return m_pass_sr4a_mt2;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSR4bMt2()
{
  return m_pass_sr4b_mt2;
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
