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
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassBad(bool pass)
// {
//   m_pass_bad = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassCosmic(bool pass)
// {
//   m_pass_cosmic = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassLoose(bool pass)
// {
//   m_pass_loose = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassSegTag(bool pass)
// {
//   m_pass_seg_tag = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassCombined(bool pass)
// {
//   m_pass_combined = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassBLayer(bool pass)
// {
//   m_pass_b_layer = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassPixel(bool pass)
// {
//   m_pass_pixel = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassSct(bool pass)
// {
//   m_pass_sct = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassTrt(bool pass)
// {
//   m_pass_trt = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassSiHoles(bool pass)
// {
//   m_pass_si_holes = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassBaselinePt(bool pass)
// {
//   m_pass_baseline_pt = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassBaselineEta(bool pass)
// {
//   m_pass_baseline_eta = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassD0Sig(bool pass)
// {
//   m_pass_d0_sig = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassZ0SinTheta(bool pass)
// {
//   m_pass_z0_sin_theta = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::TauDescription::setPassPtIso(bool pass)
// {
//   m_pass_pt_iso = pass;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassBaseline() const
// {
//   return m_pass_baseline;
// }
// 
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
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassBad() const
// {
//   return m_pass_bad;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassCosmic() const
// {
//   return m_pass_cosmic;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassLoose() const
// {
//   return m_pass_loose;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassSegTag() const
// {
//   return m_pass_seg_tag;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassCombined() const
// {
//   return m_pass_combined;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassBLayer() const
// {
//   return m_pass_b_layer;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassPixel() const
// {
//   return m_pass_pixel;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassSct() const
// {
//   return m_pass_sct;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassTrt() const
// {
//   return m_pass_trt;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassSiHoles() const
// {
//   return m_pass_si_holes;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassBaselinePt() const
// {
//   return m_pass_baseline_pt;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassBaselineEta() const
// {
//   return m_pass_baseline_eta;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassD0Sig() const
// {
//   return m_pass_d0_sig;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassZ0SinTheta() const
// {
//   return m_pass_z0_sin_theta;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::TauDescription::getPassPtIso() const
// {
//   return m_pass_pt_iso;
// }

// -----------------------------------------------------------------------------
unsigned int SusyAnalysisTools::TauDescription::getComponent(
    const ull_t& rhs, unsigned int address, unsigned int size)
{
  return ( ((1 << size)-1) & (rhs >> address) );
}
