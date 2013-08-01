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
  event_desc += getIntComp(m_pass_sr_ssjets_mll_veto , ADD_SR_SSJETS_MLL_VETO );
  event_desc += getIntComp(m_pass_sr_ssjets_met_rel  , ADD_SR_SSJETS_MET_REL  );
  event_desc += getIntComp(m_pass_sr_ssjets_mt       , ADD_SR_SSJETS_MT       );
  event_desc += getIntComp(m_pass_sr_2jets_num_l_jet , ADD_SR_2JETS_NUM_L_JET );
  event_desc += getIntComp(m_pass_sr_2jets_met_rel   , ADD_SR_2JETS_MET_REL   );
  event_desc += getIntComp(m_pass_sr_mt2_lep1_pt     , ADD_SR_MT2_LEP1_PT     );
  event_desc += getIntComp(m_pass_sr_mt2_lep2_pt     , ADD_SR_MT2_LEP2_PT     );
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
  event_desc += getIntComp(m_pass_sr_zjets_jet1_pt   , ADD_SR_ZJETS_LEP1_PT   );
  event_desc += getIntComp(m_pass_sr_zjets_jet2_pt   , ADD_SR_ZJETS_LEP2_PT   );
  event_desc += getIntComp(m_pass_sr_zjets_mjj       , ADD_SR_ZJETS_MJJ       );
  event_desc += getIntComp(m_pass_sr_zjets_mt2       , ADD_SR_ZJETS_MT2       );

  event_desc += getIntComp(m_pass_cr_zxjveto_met_rel , ADD_CR_ZXJVETO_MET_REL);
  event_desc += getIntComp(m_pass_cr_zxmt2_met_rel   , ADD_CR_ZXMT2_MET_REL);
  event_desc += getIntComp(m_pass_cr_zx2jets_met_rel , ADD_CR_ZX2JETS_MET_REL);
  event_desc += getIntComp(m_pass_cr_zx2jets_mt2     , ADD_CR_ZX2JETS_MT2);
  event_desc += getIntComp(m_pass_cr_zxww_met_rel    , ADD_CR_ZXWW_MET_REL);
  event_desc += getIntComp(m_pass_cr_zxww_mt2        , ADD_CR_ZXWW_MT2);
  event_desc += getIntComp(m_pass_cr_top_met_rel     , ADD_CR_TOP_MET_REL);
  event_desc += getIntComp(m_pass_cr_ww12_met_rel    , ADD_CR_WW12_MET_REL);
  event_desc += getIntComp(m_pass_cr_ww12_mt2        , ADD_CR_WW12_MT2);
  event_desc += getIntComp(m_pass_cr_ww2_mll         , ADD_CR_WW2_MLL);
  event_desc += getIntComp(m_pass_cr_wwabc_dphill    , ADD_CR_WWABC_DPHILL);
  event_desc += getIntComp(m_pass_cr_btag_drjettag   , ADD_CR_BTAG_DRJETTAG);

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

  m_pass_sr_ssjets_mll_veto = getComponent(
      rhs, ADD_SR_SSJETS_MLL_VETO, SIZE_BOOL);
  m_pass_sr_ssjets_met_rel = getComponent(
      rhs, ADD_SR_SSJETS_MET_REL, SIZE_BOOL);
  m_pass_sr_ssjets_mt = getComponent(
      rhs, ADD_SR_SSJETS_MT, SIZE_BOOL);

  m_pass_sr_2jets_num_l_jet = getComponent(
      rhs, ADD_SR_2JETS_NUM_L_JET, SIZE_BOOL);
  m_pass_sr_2jets_met_rel = getComponent(
      rhs, ADD_SR_2JETS_MET_REL, SIZE_BOOL);

  m_pass_sr_mt2_lep1_pt = getComponent(rhs, ADD_SR_MT2_LEP1_PT, SIZE_BOOL);
  m_pass_sr_mt2_lep2_pt = getComponent(rhs, ADD_SR_MT2_LEP2_PT, SIZE_BOOL);
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
  m_pass_sr_zjets_jet1_pt    = getComponent(rhs, ADD_SR_ZJETS_LEP1_PT   , SIZE_BOOL);
  m_pass_sr_zjets_jet2_pt    = getComponent(rhs, ADD_SR_ZJETS_LEP2_PT   , SIZE_BOOL);
  m_pass_sr_zjets_mjj        = getComponent(rhs, ADD_SR_ZJETS_MJJ       , SIZE_BOOL);
  m_pass_sr_zjets_mt2        = getComponent(rhs, ADD_SR_ZJETS_MT2       , SIZE_BOOL);

  m_pass_cr_zxjveto_met_rel = getComponent(rhs, ADD_CR_ZXJVETO_MET_REL, SIZE_BOOL);

  m_pass_cr_zxmt2_met_rel   = getComponent(rhs, ADD_CR_ZXMT2_MET_REL  , SIZE_BOOL);

  m_pass_cr_zx2jets_met_rel = getComponent(rhs, ADD_CR_ZX2JETS_MET_REL, SIZE_BOOL);
  m_pass_cr_zx2jets_mt2     = getComponent(rhs, ADD_CR_ZX2JETS_MT2    , SIZE_BOOL);

  m_pass_cr_zxww_met_rel    = getComponent(rhs, ADD_CR_ZXWW_MET_REL   , SIZE_BOOL);
  m_pass_cr_zxww_mt2        = getComponent(rhs, ADD_CR_ZXWW_MT2       , SIZE_BOOL);

  m_pass_cr_top_met_rel     = getComponent(rhs, ADD_CR_TOP_MET_REL    , SIZE_BOOL);

  m_pass_cr_ww12_met_rel    = getComponent(rhs, ADD_CR_WW12_MET_REL   , SIZE_BOOL);
  m_pass_cr_ww12_mt2        = getComponent(rhs, ADD_CR_WW12_MT2       , SIZE_BOOL);
  m_pass_cr_ww2_mll         = getComponent(rhs, ADD_CR_WW2_MLL        , SIZE_BOOL);

  m_pass_cr_wwabc_dphill    = getComponent(rhs, ADD_CR_WWABC_DPHILL   , SIZE_BOOL);

  m_pass_cr_btag_drjettag   = getComponent(rhs, ADD_CR_BTAG_DRJETTAG  , SIZE_BOOL);
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
void SusyAnalysisTools::SRHelper::setPassSRSSJetsMllVeto(bool pass)
{
  m_pass_sr_ssjets_mll_veto = pass;
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
void SusyAnalysisTools::SRHelper::setPassSRMT2Lep1Pt(bool pass)
{
  m_pass_sr_mt2_lep1_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRMT2Lep2Pt(bool pass)
{
  m_pass_sr_mt2_lep2_pt = pass;
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
void SusyAnalysisTools::SRHelper::setPassSRZJetsNumLJets(bool pass)
{
  m_pass_sr_zjets_num_l_jets = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRZJetsMetRel(bool pass)
{
  m_pass_sr_zjets_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRZJetsJet1Pt(bool pass)
{
  m_pass_sr_zjets_jet1_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRZJetsJet2Pt(bool pass)
{
  m_pass_sr_zjets_jet2_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRZJetsMjj(bool pass)
{
  m_pass_sr_zjets_mjj = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassSRZJetsMt2(bool pass)
{
  m_pass_sr_zjets_mt2 = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRZXJVetoMetRel(bool pass)
{
  m_pass_cr_zxjveto_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRZXMt2MetRel(bool pass)
{
  m_pass_cr_zxmt2_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRZX2JetsMetRel(bool pass)
{
  m_pass_cr_zx2jets_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRZX2JetsMt2(bool pass)
{
  m_pass_cr_zx2jets_mt2 = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRZXWWMetRel(bool pass)
{
  m_pass_cr_zxww_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRZXWWMt2(bool pass)
{
  m_pass_cr_zxww_mt2 = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRTopMetRel(bool pass)
{
  m_pass_cr_top_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRWW12MetRel(bool pass)
{
  m_pass_cr_ww12_met_rel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRWW12Mt2(bool pass)
{
  m_pass_cr_ww12_mt2 = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRWW2Mll(bool pass)
{
  m_pass_cr_ww2_mll = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRWWabcDPhill(bool pass)
{
  m_pass_cr_wwabc_dphill = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::SRHelper::setPassCRBtagDRJetTag(bool pass)
{
  m_pass_cr_btag_drjettag = pass;
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
bool SusyAnalysisTools::SRHelper::getPassSRSSJetsMllVeto()
{
  return m_pass_sr_ssjets_mll_veto;
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
bool SusyAnalysisTools::SRHelper::getPassSRMT2Lep1Pt()
{
  return m_pass_sr_mt2_lep1_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRMT2Lep2Pt()
{
  return m_pass_sr_mt2_lep2_pt;
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
bool SusyAnalysisTools::SRHelper::getPassSRZJetsNumLJets()
{
  return m_pass_sr_zjets_num_l_jets;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZJetsMetRel()
{
  return m_pass_sr_zjets_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZJetsJet1Pt()
{
  return m_pass_sr_zjets_jet1_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZJetsJet2Pt()
{
  return m_pass_sr_zjets_jet2_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZJetsMjj()
{
  return m_pass_sr_zjets_mjj;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassSRZJetsMt2()
{
  return m_pass_sr_zjets_mt2;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRZXJVetoMetRel()
{
  return m_pass_cr_zxjveto_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRZXMt2MetRel()
{
  return m_pass_cr_zxmt2_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRZX2JetsMetRel()
{
  return m_pass_cr_zx2jets_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRZX2JetsMt2()
{
  return m_pass_cr_zx2jets_mt2;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRZXWWMetRel()
{
  return m_pass_cr_zxww_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRZXWWMt2()
{
  return m_pass_cr_zxww_mt2;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRTopMetRel()
{
  return m_pass_cr_top_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRWW12MetRel()
{
  return m_pass_cr_ww12_met_rel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRWW12Mt2()
{
  return m_pass_cr_ww12_mt2;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRWW2Mll()
{
  return m_pass_cr_ww2_mll;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRWWabcDPhill()
{
  return m_pass_cr_wwabc_dphill;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::SRHelper::getPassCRBtagDRJetTag()
{
  return m_pass_cr_btag_drjettag;
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
