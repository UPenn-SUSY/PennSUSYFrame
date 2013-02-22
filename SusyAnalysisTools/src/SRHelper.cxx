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

  event_desc += getIntComp(m_pass_sr_osjveto_met_rel , ADD_SR_OSJVETO_MET_REL );
  event_desc += getIntComp(m_pass_sr_osjveto_mt2     , ADD_SR_OSJVETO_MT2     );
  event_desc += getIntComp(m_pass_sr_ssjets_met_rel  , ADD_SR_SSJETS_MET_REL  );
  event_desc += getIntComp(m_pass_sr_ssjets_mt       , ADD_SR_SSJETS_MT       );
  event_desc += getIntComp(m_pass_sr_2jets_num_l_jet , ADD_SR_2JETS_NUM_L_JET );
  event_desc += getIntComp(m_pass_sr_2jets_met_rel   , ADD_SR_2JETS_MET_REL   );
  event_desc += getIntComp(m_pass_sr_mt2_met_rel     , ADD_SR_MT2_MET_REL     );
  event_desc += getIntComp(m_pass_sr_mt2a_mt2        , ADD_SR_MT2a_MT2        );
  event_desc += getIntComp(m_pass_sr_mt2b_mt2        , ADD_SR_MT2b_MT2        );

  event_desc += getIntComp(m_pass_sr_ww_lep1_pt      , ADD_SR_WW_LEP1_PT      );
  event_desc += getIntComp(m_pass_sr_ww_lep2_pt      , ADD_SR_WW_LEP2_PT      );
  event_desc += getIntComp(m_pass_sr_wwa_met_rel     , ADD_SR_WWA_MET_REL     );
  event_desc += getIntComp(m_pass_sr_wwa_ptll        , ADD_SR_WWA_PTLL        );
  event_desc += getIntComp(m_pass_sr_wwa_mll         , ADD_SR_WWA_MLL         );
  event_desc += getIntComp(m_pass_sr_wwb_mt2         , ADD_SR_WWB_MT2         );
  event_desc += getIntComp(m_pass_sr_wwb_ptll        , ADD_SR_WWB_PTLL        );
  event_desc += getIntComp(m_pass_sr_wwb_mll         , ADD_SR_WWB_MLL         );
  event_desc += getIntComp(m_pass_sr_wwc_ptll        , ADD_SR_WWC_PTLL        );
  event_desc += getIntComp(m_pass_sr_wwc_mt2         , ADD_SR_WWC_MT2         );

  event_desc += getIntComp(m_pass_sr_zjets_num_l_jets, ADD_SR_ZJETS_NUM_L_JETS);
  event_desc += getIntComp(m_pass_sr_zjets_met_rel   , ADD_SR_ZJETS_MET_REL   );
  event_desc += getIntComp(m_pass_sr_zjets_lep1_pt   , ADD_SR_ZJETS_LEP1_PT   );
  event_desc += getIntComp(m_pass_sr_zjets_lep2_pt   , ADD_SR_ZJETS_LEP2_PT   );
  event_desc += getIntComp(m_pass_sr_zjets_mjj       , ADD_SR_ZJETS_MJJ       );
  event_desc += getIntComp(m_pass_sr_zjets_mt2       , ADD_SR_ZJETS_MT2       );

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

  m_pass_sr_osjveto_met_rel = getComponent(
      rhs, ADD_SR_OSJVETO_MET_REL, SIZE_BOOL);
  m_pass_sr_osjveto_mt2 = getComponent(
      rhs, ADD_SR_OSJVETO_MT2, SIZE_BOOL);
  m_pass_sr_ssjets_met_rel = getComponent(
      rhs, ADD_SR_SSJETS_MET_REL, SIZE_BOOL);
  m_pass_sr_ssjets_mt = getComponent(
      rhs, ADD_SR_SSJETS_MT, SIZE_BOOL);
  m_pass_sr_2jets_num_l_jet = getComponent(
      rhs, ADD_SR_2JETS_NUM_L_JET, SIZE_BOOL);
  m_pass_sr_2jets_met_rel = getComponent(
      rhs, ADD_SR_2JETS_MET_REL, SIZE_BOOL);
  m_pass_sr_mt2_met_rel = getComponent(rhs, ADD_SR_MT2_MET_REL, SIZE_BOOL);
  m_pass_sr_mt2a_mt2    = getComponent(rhs, ADD_SR_MT2a_MT2   , SIZE_BOOL);
  m_pass_sr_mt2b_mt2    = getComponent(rhs, ADD_SR_MT2b_MT2   , SIZE_BOOL);

  m_pass_sr_ww_lep1_pt       = getComponent(rhs, ADD_SR_WW_LEP1_PT , SIZE_BOOL);
  m_pass_sr_ww_lep2_pt       = getComponent(rhs, ADD_SR_WW_LEP2_PT , SIZE_BOOL);
  m_pass_sr_wwa_met_rel      = getComponent(rhs, ADD_SR_WWA_MET_REL, SIZE_BOOL);
  m_pass_sr_wwa_ptll         = getComponent(rhs, ADD_SR_WWA_PTLL   , SIZE_BOOL);
  m_pass_sr_wwa_mll          = getComponent(rhs, ADD_SR_WWA_MLL    , SIZE_BOOL);
  m_pass_sr_wwb_mt2          = getComponent(rhs, ADD_SR_WWB_MT2    , SIZE_BOOL);
  m_pass_sr_wwb_ptll         = getComponent(rhs, ADD_SR_WWB_PTLL   , SIZE_BOOL);
  m_pass_sr_wwb_mll          = getComponent(rhs, ADD_SR_WWB_MLL    , SIZE_BOOL);
  m_pass_sr_wwc_ptll         = getComponent(rhs, ADD_SR_WWC_PTLL   , SIZE_BOOL);
  m_pass_sr_wwc_mt2          = getComponent(rhs, ADD_SR_WWC_MT2    , SIZE_BOOL);

  m_pass_sr_zjets_num_l_jets = getComponent(rhs, ADD_SR_ZJETS_NUM_L_JETS, SIZE_BOOL);
  m_pass_sr_zjets_met_rel    = getComponent(rhs, ADD_SR_ZJETS_MET_REL   , SIZE_BOOL);
  m_pass_sr_zjets_lep1_pt    = getComponent(rhs, ADD_SR_ZJETS_LEP1_PT   , SIZE_BOOL);
  m_pass_sr_zjets_lep2_pt    = getComponent(rhs, ADD_SR_ZJETS_LEP2_PT   , SIZE_BOOL);
  m_pass_sr_zjets_mjj        = getComponent(rhs, ADD_SR_ZJETS_MJJ       , SIZE_BOOL);
  m_pass_sr_zjets_mt2        = getComponent(rhs, ADD_SR_ZJETS_MT2       , SIZE_BOOL);
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
void SusyAnalysisTools::SRHelper::setPassSROSJVetoMetRel(bool pass)
{
  m_pass_sr_osjveto_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSROSJVetoMt2(bool pass)
{
  m_pass_sr_osjveto_mt2 = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRSSJetsMetRel(bool pass)
{
  m_pass_sr_ssjets_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRSSJetsMt(bool pass)
{
  m_pass_sr_ssjets_mt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSR2JetsNumLJet(bool pass)
{
  m_pass_sr_2jets_num_l_jet = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSR2JetsMetRel(bool pass)
{
  m_pass_sr_2jets_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRMT2MetRel(bool pass)
{
  m_pass_sr_mt2_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRMT2aMt2(bool pass)
{
  m_pass_sr_mt2a_mt2 = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRMT2bMt2(bool pass)
{
  m_pass_sr_mt2b_mt2 = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRWWLep1Pt(bool pass)
{
  m_pass_sr_ww_lep1_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRWWLep2Pt(bool pass)
{
  m_pass_sr_ww_lep2_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRWWaMetRel(bool pass)
{
  m_pass_sr_wwa_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRWWaPtll(bool pass)
{
  m_pass_sr_wwa_ptll = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRWWaMll(bool pass)
{
  m_pass_sr_wwa_mll = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRWWbMt2(bool pass)
{
  m_pass_sr_wwb_mt2 = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRWWbPtll(bool pass)
{
  m_pass_sr_wwb_ptll = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRWWbMll(bool pass)
{
  m_pass_sr_wwb_mll = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRWWcPtll(bool pass)
{
  m_pass_sr_wwc_ptll = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRWWcMt2(bool pass)
{
  m_pass_sr_wwc_mt2 = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSrZjetsNumLJets(bool pass)
{
  m_pass_sr_zjets_num_l_jets = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSrZjetsMetRel(bool pass)
{
  m_pass_sr_zjets_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSrZjetsLep1Pt(bool pass)
{
  m_pass_sr_zjets_lep1_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSrZjetsLep2Pt(bool pass)
{
  m_pass_sr_zjets_lep2_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSrZjetsMjj(bool pass)
{
  m_pass_sr_zjets_mjj = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSrZjetsMt2(bool pass)
{
  m_pass_sr_zjets_mt2 = pass;
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
bool SusyAnalysisTools::SRHelper::getPassSROSJVetoMetRel()
{
  return m_pass_sr_osjveto_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSROSJVetoMt2()
{
  return m_pass_sr_osjveto_mt2;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRSSJetsMetRel()
{
  return m_pass_sr_ssjets_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRSSJetsMt()
{
  return m_pass_sr_ssjets_mt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSR2JetsNumLJet()
{
  return m_pass_sr_2jets_num_l_jet;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSR2JetsMetRel()
{
  return m_pass_sr_2jets_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRMT2MetRel()
{
  return m_pass_sr_mt2_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRMT2aMt2()
{
  return m_pass_sr_mt2a_mt2;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRMT2bMt2()
{
  return m_pass_sr_mt2b_mt2;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRWWLep1Pt()
{
  return m_pass_sr_ww_lep1_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRWWLep2Pt()
{
  return m_pass_sr_ww_lep2_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRWWaMetRel()
{
  return m_pass_sr_wwa_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRWWaPtll()
{
  return m_pass_sr_wwa_ptll;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRWWaMll()
{
  return m_pass_sr_wwa_mll;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRWWbMt2()
{
  return m_pass_sr_wwb_mt2;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRWWbPtll()
{
  return m_pass_sr_wwb_ptll;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRWWbMll()
{
  return m_pass_sr_wwb_mll;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRWWcPtll()
{
  return m_pass_sr_wwc_ptll;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRWWcMt2()
{
  return m_pass_sr_wwc_mt2;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZjetsNumLJets()
{
  return m_pass_sr_zjets_num_l_jets;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZjetsMetRel()
{
  return m_pass_sr_zjets_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZjetsLep1Pt()
{
  return m_pass_sr_zjets_lep1_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZjetsLep2Pt()
{
  return m_pass_sr_zjets_lep2_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZjetsMjj()
{
  return m_pass_sr_zjets_mjj;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZjetsMt2()
{
  return m_pass_sr_zjets_mt2;
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
