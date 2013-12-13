#include "include/JetDescription.h"

// -----------------------------------------------------------------------------
SusyAnalysisTools::JetDescription::JetDescription()
{
  // do nothing
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::JetDescription::JetDescription(
    const ull_t evt_desc_int)
{
  set(evt_desc_int);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::JetDescription::~JetDescription()
{
  // do nothing
}

// -----------------------------------------------------------------------------
ull_t SusyAnalysisTools::JetDescription::toInt() const
{
  ull_t jet_desc = 0;

  jet_desc += getIntComp(m_pass_baseline_bad, ADD_BASELINE_BAD);
  jet_desc += getIntComp(m_pass_good        , ADD_GOOD        );
  jet_desc += getIntComp(m_pass_bad         , ADD_BAD         );
  jet_desc += getIntComp(m_pass_light       , ADD_LIGHT       );
  jet_desc += getIntComp(m_pass_b           , ADD_B           );
  jet_desc += getIntComp(m_pass_forward     , ADD_FORWARD     );
  jet_desc += getIntComp(m_pass_baseline_pt , ADD_BASELINE_PT );
  jet_desc += getIntComp(m_pass_baseline_eta, ADD_BASELINE_ETA);
  jet_desc += getIntComp(m_pass_b_tag       , ADD_B_TAG       );
  jet_desc += getIntComp(m_pass_central_eta , ADD_CENTRAL_ETA );
  jet_desc += getIntComp(m_pass_jvf         , ADD_JVF         );
  jet_desc += getIntComp(m_pass_l_jet_pt    , ADD_L_PT        );
  jet_desc += getIntComp(m_pass_b_jet_pt    , ADD_B_PT        );
  jet_desc += getIntComp(m_pass_f_jet_pt    , ADD_F_PT        );
  jet_desc += getIntComp(m_pass_f_jet_eta   , ADD_F_ETA       );

  return jet_desc;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::clear()
{
  *this = 0;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::set(
    const SusyAnalysisTools::JetDescription& rhs)
{
  set(rhs.toInt());
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::set(const ull_t& rhs)
{
  m_pass_baseline_good = getComponent(rhs, ADD_BASELINE_GOOD, SIZE_BOOL);
  m_pass_baseline_bad  = getComponent(rhs, ADD_BASELINE_BAD , SIZE_BOOL);
  m_pass_good          = getComponent(rhs, ADD_GOOD         , SIZE_BOOL);
  m_pass_bad           = getComponent(rhs, ADD_BAD          , SIZE_BOOL);
  m_pass_light         = getComponent(rhs, ADD_LIGHT        , SIZE_BOOL);
  m_pass_b             = getComponent(rhs, ADD_B            , SIZE_BOOL);
  m_pass_forward       = getComponent(rhs, ADD_FORWARD      , SIZE_BOOL);
  m_pass_baseline_pt   = getComponent(rhs, ADD_BASELINE_PT  , SIZE_BOOL);
  m_pass_baseline_eta  = getComponent(rhs, ADD_BASELINE_ETA , SIZE_BOOL);
  m_pass_b_tag         = getComponent(rhs, ADD_B_TAG        , SIZE_BOOL);
  m_pass_central_eta   = getComponent(rhs, ADD_CENTRAL_ETA  , SIZE_BOOL);
  m_pass_jvf           = getComponent(rhs, ADD_JVF          , SIZE_BOOL);
  m_pass_l_jet_pt      = getComponent(rhs, ADD_L_PT         , SIZE_BOOL);
  m_pass_b_jet_pt      = getComponent(rhs, ADD_B_PT         , SIZE_BOOL);
  m_pass_f_jet_pt      = getComponent(rhs, ADD_F_PT         , SIZE_BOOL);
  m_pass_f_jet_eta     = getComponent(rhs, ADD_F_ETA        , SIZE_BOOL);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::JetDescription&
    SusyAnalysisTools::JetDescription::operator=(
        const SusyAnalysisTools::JetDescription& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::JetDescription&
    SusyAnalysisTools::JetDescription::operator=(const ull_t& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassBaselineGood(bool pass)
{
  m_pass_baseline_good = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassBaselineBad(bool pass)
{
  m_pass_baseline_bad = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassGood(bool pass)
{
  m_pass_good = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassBad(bool pass)
{
  m_pass_bad = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassLight(bool pass)
{
  m_pass_light = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassB(bool pass)
{
  m_pass_b = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassForward(bool pass)
{
  m_pass_forward = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassBaselinePt(bool pass)
{
  m_pass_baseline_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassBaselineEta(bool pass)
{
  m_pass_baseline_eta = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassBTag(bool pass)
{
  m_pass_b_tag = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassCentralEta(bool pass)
{
  m_pass_central_eta = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassJvf(bool pass)
{
  m_pass_jvf = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassLPt(bool pass)
{
  m_pass_l_jet_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassBPt(bool pass)
{
  m_pass_b_jet_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassFPt(bool pass)
{
  m_pass_f_jet_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::JetDescription::setPassFEta(bool pass)
{
  m_pass_f_jet_eta = pass;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassBaselineGood() const
{
  return m_pass_baseline_good;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassBaselineBad() const
{
  return m_pass_baseline_bad;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassGood() const
{
  return m_pass_good;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassBad() const
{
  return m_pass_bad;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassLight() const
{
  return m_pass_light;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassB() const
{
  return m_pass_b;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassForward() const
{
  return m_pass_forward;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassBaselinePt() const
{
  return m_pass_baseline_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassBaselineEta() const
{
  return m_pass_baseline_eta;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassBTag() const
{
  return m_pass_b_tag;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassCentralEta() const
{
  return m_pass_central_eta;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassJvf() const
{
  return m_pass_jvf;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassLPt() const
{
  return m_pass_l_jet_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassBPt() const
{
  return m_pass_b_jet_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassFPt() const
{
  return m_pass_f_jet_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::JetDescription::getPassFEta() const
{
  return m_pass_f_jet_eta;
}

// -----------------------------------------------------------------------------
unsigned int SusyAnalysisTools::JetDescription::getComponent(
    const ull_t& rhs, unsigned int address, unsigned int size)
{
  return ( ((1 << size)-1) & (rhs >> address) );
}
