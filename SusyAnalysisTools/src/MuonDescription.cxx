#include "include/MuonDescription.h"

// -----------------------------------------------------------------------------
SusyAnalysisTools::MuonDescription::MuonDescription()
{
  // do nothing
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::MuonDescription::MuonDescription(
    const ull_t evt_desc_int)
{
  set(evt_desc_int);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::MuonDescription::~MuonDescription()
{
  // do nothing
}

// -----------------------------------------------------------------------------
ull_t SusyAnalysisTools::MuonDescription::toInt() const
{
  ull_t mu_desc = 0;

  mu_desc += getIntComp(m_pass_baseline, ADD_BASELINE);

  mu_desc += getIntComp(m_pass_baseline    , ADD_BASELINE    );
  mu_desc += getIntComp(m_pass_good        , ADD_GOOD        );
  mu_desc += getIntComp(m_pass_signal      , ADD_SIGNAL      );
  mu_desc += getIntComp(m_pass_bad         , ADD_BAD         );
  mu_desc += getIntComp(m_pass_cosmic      , ADD_COSMIC      );
  mu_desc += getIntComp(m_pass_loose       , ADD_LOOSE       );
  mu_desc += getIntComp(m_pass_seg_tag     , ADD_SEG_TAG     );
  mu_desc += getIntComp(m_pass_combined    , ADD_COMBINED    );
  mu_desc += getIntComp(m_pass_b_layer     , ADD_B_LAYER     );
  mu_desc += getIntComp(m_pass_pixel       , ADD_PIXEL       );
  mu_desc += getIntComp(m_pass_sct         , ADD_SCT         );
  mu_desc += getIntComp(m_pass_trt         , ADD_TRT         );
  mu_desc += getIntComp(m_pass_si_holes    , ADD_SI_HOLES    );
  mu_desc += getIntComp(m_pass_baseline_pt , ADD_BASELINE_PT );
  mu_desc += getIntComp(m_pass_baseline_eta, ADD_BASELINE_ETA);
  mu_desc += getIntComp(m_pass_d0_sig      , ADD_D0_SIG      );
  mu_desc += getIntComp(m_pass_z0_sin_theta, ADD_Z0_SIN_THETA);
  mu_desc += getIntComp(m_pass_pt_iso      , ADD_PT_ISO      );

  return mu_desc;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::clear()
{
  *this = 0;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::set(
    const SusyAnalysisTools::MuonDescription& rhs)
{
  set(rhs.toInt());
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::set(const ull_t& rhs)
{
  m_pass_baseline     = getComponent(rhs, ADD_BASELINE    , SIZE_BOOL);
  m_pass_good         = getComponent(rhs, ADD_GOOD        , SIZE_BOOL);
  m_pass_signal       = getComponent(rhs, ADD_SIGNAL      , SIZE_BOOL);
  m_pass_bad          = getComponent(rhs, ADD_BAD         , SIZE_BOOL);
  m_pass_cosmic       = getComponent(rhs, ADD_COSMIC      , SIZE_BOOL);
  m_pass_loose        = getComponent(rhs, ADD_LOOSE       , SIZE_BOOL);
  m_pass_seg_tag      = getComponent(rhs, ADD_SEG_TAG     , SIZE_BOOL);
  m_pass_combined     = getComponent(rhs, ADD_COMBINED    , SIZE_BOOL);
  m_pass_b_layer      = getComponent(rhs, ADD_B_LAYER     , SIZE_BOOL);
  m_pass_pixel        = getComponent(rhs, ADD_PIXEL       , SIZE_BOOL);
  m_pass_sct          = getComponent(rhs, ADD_SCT         , SIZE_BOOL);
  m_pass_trt          = getComponent(rhs, ADD_TRT         , SIZE_BOOL);
  m_pass_si_holes     = getComponent(rhs, ADD_SI_HOLES    , SIZE_BOOL);
  m_pass_baseline_pt  = getComponent(rhs, ADD_BASELINE_PT , SIZE_BOOL);
  m_pass_baseline_eta = getComponent(rhs, ADD_BASELINE_ETA, SIZE_BOOL);
  m_pass_d0_sig       = getComponent(rhs, ADD_D0_SIG      , SIZE_BOOL);
  m_pass_z0_sin_theta = getComponent(rhs, ADD_Z0_SIN_THETA, SIZE_BOOL);
  m_pass_pt_iso       = getComponent(rhs, ADD_PT_ISO      , SIZE_BOOL);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::MuonDescription&
    SusyAnalysisTools::MuonDescription::operator=(
        const SusyAnalysisTools::MuonDescription& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::MuonDescription&
    SusyAnalysisTools::MuonDescription::operator=(const ull_t& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassBaseline(bool pass)
{
  m_pass_baseline = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassGood(bool pass)
{
  m_pass_good = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassSignal(bool pass)
{
  m_pass_signal = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassBad(bool pass)
{
  m_pass_bad = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassCosmic(bool pass)
{
  m_pass_cosmic = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassLoose(bool pass)
{
  m_pass_loose = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassSegTag(bool pass)
{
  m_pass_seg_tag = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassCombined(bool pass)
{
  m_pass_combined = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassBLayer(bool pass)
{
  m_pass_b_layer = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassPixel(bool pass)
{
  m_pass_pixel = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassSct(bool pass)
{
  m_pass_sct = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassTrt(bool pass)
{
  m_pass_trt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassSiHoles(bool pass)
{
  m_pass_si_holes = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassBaselinePt(bool pass)
{
  m_pass_baseline_pt = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassBaselineEta(bool pass)
{
  m_pass_baseline_eta = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassSignalEta(bool pass)
{
  m_pass_signal_eta = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassD0Sig(bool pass)
{
  m_pass_d0_sig = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassZ0SinTheta(bool pass)
{
  m_pass_z0_sin_theta = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::MuonDescription::setPassPtIso(bool pass)
{
  m_pass_pt_iso = pass;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassBaseline() const
{
  return m_pass_baseline;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassGood() const
{
  return m_pass_good;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassSignal() const
{
  return m_pass_signal;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassBad() const
{
  return m_pass_bad;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassCosmic() const
{
  return m_pass_cosmic;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassLoose() const
{
  return m_pass_loose;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassSegTag() const
{
  return m_pass_seg_tag;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassCombined() const
{
  return m_pass_combined;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassBLayer() const
{
  return m_pass_b_layer;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassPixel() const
{
  return m_pass_pixel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassSct() const
{
  return m_pass_sct;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassTrt() const
{
  return m_pass_trt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassSiHoles() const
{
  return m_pass_si_holes;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassBaselinePt() const
{
  return m_pass_baseline_pt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassBaselineEta() const
{
  return m_pass_baseline_eta;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassSignalEta() const
{
  return m_pass_signal_eta;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassD0Sig() const
{
  return m_pass_d0_sig;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassZ0SinTheta() const
{
  return m_pass_z0_sin_theta;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::MuonDescription::getPassPtIso() const
{
  return m_pass_pt_iso;
}

// -----------------------------------------------------------------------------
unsigned int SusyAnalysisTools::MuonDescription::getComponent(
    const ull_t& rhs, unsigned int address, unsigned int size)
{
  return ( ((1 << size)-1) & (rhs >> address) );
}
