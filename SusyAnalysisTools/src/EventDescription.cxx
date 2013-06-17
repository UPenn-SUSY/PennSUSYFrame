#include "SusyAnalysisTools/include/EventDescription.h"

// -----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription::EventDescription()
{
  set(0);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription::EventDescription(const ull_t evt_desc_int)
{
  set(evt_desc_int);
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription::~EventDescription()
{
  // do nothing
}

// -----------------------------------------------------------------------------
ull_t SusyAnalysisTools::EventDescription::toInt() const
{
  ull_t event_desc = 0;

  event_desc += getIntComp(m_is_data               , ADD_IS_DATA           );
  event_desc += getIntComp(m_pass_grl              , ADD_GRL               );
  event_desc += getIntComp(m_pass_incomplete_event , ADD_INCOMPLETE_EVENT  );
  event_desc += getIntComp(m_pass_lar_error        , ADD_LAR_ERROR         );
  event_desc += getIntComp(m_pass_tile_error       , ADD_TILE_ERROR        );
  event_desc += getIntComp(m_pass_tile_hot_spot    , ADD_TILE_HOT_SPOT     );
  event_desc += getIntComp(m_pass_bad_jets         , ADD_BAD_JETS          );
  event_desc += getIntComp(m_pass_calo_problem_jets, ADD_CALO_PROBLEM_JETS );
  event_desc += getIntComp(m_pass_primary_vertex   , ADD_PRIMARY_VERTEX    );
  event_desc += getIntComp(m_pass_bad_muons        , ADD_BAD_MUONS         );
  event_desc += getIntComp(m_pass_cosmic_muons     , ADD_COSMIC_MUONS      );
  event_desc += getIntComp(m_pass_hfor             , ADD_HFOR              );
  event_desc += getIntComp(m_pass_mc_overlap       , ADD_MC_OVERLAP        );
  event_desc += getIntComp(m_pass_ge_2_good_leptons, ADD_GE_2_GOOD_LEPTON  );
  event_desc += getIntComp(m_pass_2_good_leptons   , ADD_2_GOOD_LEPTON     );
  event_desc += getIntComp(m_pass_2_signal_leptons , ADD_2_SIGNAL_LEPTON   );
  event_desc += getIntComp(m_pass_mll              , ADD_MLL               );
  event_desc += getIntComp(m_flavor_channel        , ADD_FLAVOR_CHANNEL    );
  event_desc += getIntComp(m_phase_space           , ADD_PHASE_SPACE       );
  event_desc += getIntComp(m_pass_ee_trigger       , ADD_TRIGGER_EE        );
  event_desc += getIntComp(m_pass_mm_trigger       , ADD_TRIGGER_MM        );
  event_desc += getIntComp(m_pass_em_trigger       , ADD_TRIGGER_EM        );
  event_desc += getIntComp(m_pass_me_trigger       , ADD_TRIGGER_ME        );
  event_desc += getIntComp(m_pass_trigger_match    , ADD_TRIGGER_MATCH     );
  event_desc += getIntComp(m_sign_channel          , ADD_SIGN_CHANNEL      );

  event_desc += getIntComp(m_truth_sign_channel    , ADD_TRUTH_SIGN_CHANNEL);
  event_desc += getIntComp(m_truth_matched         , ADD_TRUTH_MATCHED     );
  event_desc += getIntComp(m_truth_prompt          , ADD_TRUTH_PROMPT      );
  event_desc += getIntComp(m_cf_candidate          , ADD_TRUTH_CF_CAND);

  event_desc += getIntComp(m_pass_tile_trip, ADD_TILE_TRIP);

  event_desc += getIntComp(m_pass_sr_osjveto, ADD_SR_OSJVETO);
  event_desc += getIntComp(m_pass_sr_ssjets , ADD_SR_SSJETS );
  event_desc += getIntComp(m_pass_sr_2jets  , ADD_SR_2JETS  );
  event_desc += getIntComp(m_pass_sr_mt2a   , ADD_SR_MT2a   );
  event_desc += getIntComp(m_pass_sr_mt2b   , ADD_SR_MT2b   );

  event_desc += getIntComp(m_pass_sr_wwa    , ADD_SR_WWA    );
  event_desc += getIntComp(m_pass_sr_wwb    , ADD_SR_WWB    );
  event_desc += getIntComp(m_pass_sr_wwc    , ADD_SR_WWC    );
  event_desc += getIntComp(m_pass_sr_zjets  , ADD_SR_ZJETS  );

  // event_desc += getIntComp(m_pass_cr1, ADD_CR_1);
  // event_desc += getIntComp(m_pass_cr2, ADD_CR_2);
  // event_desc += getIntComp(m_pass_cr3, ADD_CR_3);
  // event_desc += getIntComp(m_pass_cr4, ADD_CR_4);

  return event_desc;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::clear()
{
  *this = 0;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::set(
    const SusyAnalysisTools::EventDescription& rhs)
{
  set(rhs.toInt());
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::set(const ull_t& rhs)
{
  m_is_data                = getComponent(rhs, ADD_IS_DATA          , SIZE_BOOL);
  m_pass_grl               = getComponent(rhs, ADD_GRL              , SIZE_BOOL);
  m_pass_incomplete_event  = getComponent(rhs, ADD_INCOMPLETE_EVENT , SIZE_BOOL);
  m_pass_lar_error         = getComponent(rhs, ADD_LAR_ERROR        , SIZE_BOOL);
  m_pass_tile_error        = getComponent(rhs, ADD_TILE_ERROR       , SIZE_BOOL);
  m_pass_tile_hot_spot     = getComponent(rhs, ADD_TILE_HOT_SPOT    , SIZE_BOOL);
  m_pass_bad_jets          = getComponent(rhs, ADD_BAD_JETS         , SIZE_BOOL);
  m_pass_calo_problem_jets = getComponent(rhs, ADD_CALO_PROBLEM_JETS, SIZE_BOOL);
  m_pass_primary_vertex    = getComponent(rhs, ADD_PRIMARY_VERTEX   , SIZE_BOOL);
  m_pass_bad_muons         = getComponent(rhs, ADD_BAD_MUONS        , SIZE_BOOL);
  m_pass_cosmic_muons      = getComponent(rhs, ADD_COSMIC_MUONS     , SIZE_BOOL);
  m_pass_hfor              = getComponent(rhs, ADD_HFOR             , SIZE_BOOL);
  m_pass_mc_overlap        = getComponent(rhs, ADD_MC_OVERLAP       , SIZE_BOOL);
  m_pass_ge_2_good_leptons = getComponent(rhs, ADD_GE_2_GOOD_LEPTON , SIZE_BOOL);
  m_pass_2_good_leptons    = getComponent(rhs, ADD_2_GOOD_LEPTON    , SIZE_BOOL);
  m_pass_mll               = getComponent(rhs, ADD_MLL              , SIZE_BOOL);
  m_pass_2_signal_leptons  = getComponent(rhs, ADD_2_SIGNAL_LEPTON  , SIZE_BOOL);
  m_pass_ee_trigger        = getComponent(rhs, ADD_TRIGGER_EE       , SIZE_BOOL);
  m_pass_mm_trigger        = getComponent(rhs, ADD_TRIGGER_MM       , SIZE_BOOL);
  m_pass_em_trigger        = getComponent(rhs, ADD_TRIGGER_EM       , SIZE_BOOL);
  m_pass_me_trigger        = getComponent(rhs, ADD_TRIGGER_ME       , SIZE_BOOL);
  m_pass_trigger_match     = getComponent(rhs, ADD_TRIGGER_MATCH    , SIZE_BOOL);

  m_truth_matched          = getComponent(rhs, ADD_TRUTH_MATCHED    , SIZE_BOOL);
  m_truth_prompt           = getComponent(rhs, ADD_TRUTH_PROMPT     , SIZE_BOOL);
  m_cf_candidate           = getComponent(rhs, ADD_TRUTH_CF_CAND    , SIZE_BOOL);

  m_pass_tile_trip = getComponent(rhs, ADD_TILE_TRIP, SIZE_BOOL);

  m_pass_sr_osjveto = getComponent(rhs, ADD_SR_OSJVETO, SIZE_BOOL);
  m_pass_sr_ssjets  = getComponent(rhs, ADD_SR_SSJETS , SIZE_BOOL);
  m_pass_sr_2jets   = getComponent(rhs, ADD_SR_2JETS  , SIZE_BOOL);
  m_pass_sr_mt2a    = getComponent(rhs, ADD_SR_MT2a   , SIZE_BOOL);
  m_pass_sr_mt2b    = getComponent(rhs, ADD_SR_MT2b   , SIZE_BOOL);

  m_pass_sr_wwa     = getComponent(rhs, ADD_SR_WWA    , SIZE_BOOL);
  m_pass_sr_wwb     = getComponent(rhs, ADD_SR_WWB    , SIZE_BOOL);
  m_pass_sr_wwc     = getComponent(rhs, ADD_SR_WWC    , SIZE_BOOL);
  m_pass_sr_zjets   = getComponent(rhs, ADD_SR_ZJETS  , SIZE_BOOL);

  // m_pass_cr1 = getComponent(rhs, ADD_CR_1, SIZE_BOOL);
  // m_pass_cr2 = getComponent(rhs, ADD_CR_2, SIZE_BOOL);
  // m_pass_cr3 = getComponent(rhs, ADD_CR_3, SIZE_BOOL);
  // m_pass_cr4 = getComponent(rhs, ADD_CR_4, SIZE_BOOL);

  m_flavor_channel =
    static_cast<FLAVOR_CHANNEL>( getComponent( rhs
                                             , ADD_FLAVOR_CHANNEL
                                             , SIZE_FLAVOR
                                             )
                               );
  m_phase_space = static_cast<PHASE_SPACE>(
      getComponent( rhs
                  , ADD_PHASE_SPACE
                  , SIZE_PHASE
                  ) );
  m_sign_channel = static_cast<SIGN_CHANNEL>(
      getComponent( rhs
                  , ADD_SIGN_CHANNEL
                  , SIZE_SIGN
                  ) );
  m_truth_sign_channel = static_cast<SIGN_CHANNEL>(
      getComponent( rhs
                  , ADD_TRUTH_SIGN_CHANNEL
                  , SIZE_SIGN
                  ) );
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription&
    SusyAnalysisTools::EventDescription::operator=(
        const SusyAnalysisTools::EventDescription& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription&
    SusyAnalysisTools::EventDescription::operator=(const ull_t& rhs)
{
  set(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setIsData(bool is_data)
{
  m_is_data = is_data;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassGrl(bool pass_grl)
{
  m_pass_grl = pass_grl;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassIncompleteEvent(
    bool pass_incomplete_event)
{
  m_pass_incomplete_event = pass_incomplete_event;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassLarError(bool pass_lar_error)
{
  m_pass_lar_error = pass_lar_error;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassTileError(bool pass_tile_error)
{
  m_pass_tile_error = pass_tile_error;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassTileHotSpot(
    bool pass_tile_hot_spot)
{
  m_pass_tile_hot_spot = pass_tile_hot_spot;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassBadJets(bool pass_bad_jets)
{
  m_pass_bad_jets = pass_bad_jets;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassCaloProblemJets(
    bool pass_calo_problem_jets)
{
  m_pass_calo_problem_jets = pass_calo_problem_jets;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassPrimaryVertex(
    bool pass_primary_vertex)
{
  m_pass_primary_vertex = pass_primary_vertex;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassBadMuons(bool pass_bad_muons)
{
  m_pass_bad_muons = pass_bad_muons;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassCosmicMuons(
    bool pass_cosmic_muons)
{
  m_pass_cosmic_muons = pass_cosmic_muons;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassHFOR(bool pass_hfor)
{
  m_pass_hfor = pass_hfor;
}
// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassMCOverlap(bool pass_mc_overlap)
{
  m_pass_mc_overlap = pass_mc_overlap;
}
// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassGE2GoodLeptons(
    bool pass_ge_2_good_leptons)
{
  m_pass_ge_2_good_leptons = pass_ge_2_good_leptons;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPass2GoodLeptons(
    bool pass_2_good_leptons)
{
  m_pass_2_good_leptons = pass_2_good_leptons;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassMll(bool pass_mll)
{
  m_pass_mll = pass_mll;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPass2SignalLeptons(
    bool pass_2_signal_leptons)
{
  m_pass_2_signal_leptons = pass_2_signal_leptons;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassTriggerMatch(
    bool pass_trigger_match)
{
  m_pass_trigger_match = pass_trigger_match;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setFlavorChannel(
    FLAVOR_CHANNEL flavor_channel)
{
  m_flavor_channel = flavor_channel;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPhaseSpace(
    PHASE_SPACE phase_space)
{
  m_phase_space = phase_space;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPhaseSpace(TRIG_PHASE trig_phase)
{
  PHASE_SPACE phase_space = PHASE_NONE;
  switch (trig_phase) {
    case TRIG_EE_A : // treat all EE phase spaces the same
    case TRIG_EE_B : phase_space = PHASE_EE;
                     break;
    case TRIG_MM_A : // treat all MM phase spaces the same
    case TRIG_MM_B : // treat all MM phase spaces the same
    case TRIG_MM_C : // treat all MM phase spaces the same
    case TRIG_MM_D : phase_space = PHASE_MM;
                     break;
    case TRIG_EM_A : phase_space = PHASE_EM;
                     break;
    case TRIG_EM_B : phase_space = PHASE_ME;
                     break;
    default        : phase_space = PHASE_NONE;
                     break;
  };

  setPhaseSpace(phase_space);
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setEETrigger(bool pass_ee_trigger)
{
  m_pass_ee_trigger = pass_ee_trigger;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setMMTrigger(bool pass_mm_trigger)
{
  m_pass_mm_trigger = pass_mm_trigger;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setEMTrigger(bool pass_em_trigger)
{
  m_pass_em_trigger = pass_em_trigger;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setMETrigger(bool pass_me_trigger)
{
  m_pass_me_trigger = pass_me_trigger;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSignChannel(
    SIGN_CHANNEL sign_channel)
{
  m_sign_channel = sign_channel;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setTruthMatched(bool truth_matched)
{
  m_truth_matched = truth_matched;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setTruthPrompt(bool truth_prompt)
{
  m_truth_prompt = truth_prompt;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setCFCandidate(bool cf_candidate)
{
  m_cf_candidate = cf_candidate;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassTileTrip(bool pass_tile_trip)
{
  m_pass_tile_trip = pass_tile_trip;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setTruthSignChannel(
    SIGN_CHANNEL truth_sign_channel)
{
  m_truth_sign_channel = truth_sign_channel;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSROSJVeto(bool pass)
{
  m_pass_sr_osjveto = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSRSSJets(bool pass)
{
  m_pass_sr_ssjets = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSR2Jets(bool pass)
{
  m_pass_sr_2jets = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSRMT2a(bool pass)
{
  m_pass_sr_mt2a = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSRMT2b(bool pass)
{
  m_pass_sr_mt2b = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSRWWa(bool pass)
{
  m_pass_sr_wwa = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSRWWb(bool pass)
{
  m_pass_sr_wwb = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSRWWc(bool pass)
{
  m_pass_sr_wwc = pass;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSRZjets(bool pass)
{
  m_pass_sr_zjets = pass;
}

// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::EventDescription::setCR1(bool pass)
// {
//   m_pass_cr1 = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::EventDescription::setCR2(bool pass)
// {
//   m_pass_cr2 = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::EventDescription::setCR3(bool pass)
// {
//   m_pass_cr3 = pass;
// }
// 
// // -----------------------------------------------------------------------------
// void SusyAnalysisTools::EventDescription::setCR4(bool pass)
// {
//   m_pass_cr4 = pass;
// }

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getIsData() const
{
  return m_is_data;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassGrl() const
{
  return m_pass_grl;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassIncompleteEvent() const
{
  return m_pass_incomplete_event;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassLarError() const
{
  return m_pass_lar_error;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassTileError() const
{
  return m_pass_tile_error;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassTileHotSpot() const
{
  return m_pass_tile_hot_spot;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassBadJets() const
{
  return m_pass_bad_jets;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassCaloProblemJets() const
{
  return m_pass_calo_problem_jets;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassPrimaryVertex() const
{
  return m_pass_primary_vertex;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassBadMuons() const
{
  return m_pass_bad_muons;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassCosmicMuons() const
{
  return m_pass_cosmic_muons;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassHFOR() const
{
  return m_pass_hfor;
}
// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassMCOverlap() const
{
  return m_pass_mc_overlap;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassGE2GoodLeptons() const
{
  return m_pass_ge_2_good_leptons;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPass2GoodLeptons() const
{
  return m_pass_2_good_leptons;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassMll() const
{
  return m_pass_mll;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPass2SignalLeptons() const
{
  return m_pass_2_signal_leptons;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassTriggerMatch() const
{
  return m_pass_trigger_match;
}

// -----------------------------------------------------------------------------
FLAVOR_CHANNEL SusyAnalysisTools::EventDescription::getFlavorChannel() const
{
  return m_flavor_channel;
}

// -----------------------------------------------------------------------------
PHASE_SPACE SusyAnalysisTools::EventDescription::getPhaseSpace() const
{
  return m_phase_space;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::isEETrigger() const
{
  return m_pass_ee_trigger;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::isMMTrigger() const
{
  return m_pass_mm_trigger;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::isEMTrigger() const
{
  return m_pass_em_trigger;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::isMETrigger() const
{
  return m_pass_me_trigger;
}

// -----------------------------------------------------------------------------
SIGN_CHANNEL SusyAnalysisTools::EventDescription::getSignChannel() const
{
  return m_sign_channel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getTruthMatched() const
{
  return m_truth_matched;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getTruthPrompt() const
{
  return m_truth_prompt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getCFCandidate() const
{
  return m_cf_candidate;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassTileTrip() const
{
  return m_pass_tile_trip;
}

// -----------------------------------------------------------------------------
SIGN_CHANNEL SusyAnalysisTools::EventDescription::getTruthSignChannel() const
{
  return m_truth_sign_channel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassSROSJVeto() const
{
  return m_pass_sr_osjveto;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassSRSSJets() const
{
  return m_pass_sr_ssjets;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassSR2Jets() const
{
  return m_pass_sr_2jets;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassSRMT2a() const
{
  return m_pass_sr_mt2a;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassSRMT2b() const
{
  return m_pass_sr_mt2b;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassSRWWa() const
{
  return m_pass_sr_wwa;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassSRWWb() const
{
  return m_pass_sr_wwb;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassSRWWc() const
{
  return m_pass_sr_wwc;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassSRZjets() const
{
  return m_pass_sr_zjets;
}


// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::EventDescription::getPassCR1() const
// {
//   return m_pass_cr1;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::EventDescription::getPassCR2() const
// {
//   return m_pass_cr2;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::EventDescription::getPassCR3() const
// {
//   return m_pass_cr3;
// }
// 
// // -----------------------------------------------------------------------------
// bool SusyAnalysisTools::EventDescription::getPassCR4() const
// {
//   return m_pass_cr4;
// }

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::pass(
    const EventDescription& test) const
{
  // get the integer equivalent of this and test words
  ull_t this_word = toInt();
  ull_t test_word = test.toInt();

  // check the remaining bits match
  return ((this_word & test_word) == test_word);
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::reverse(
    const EventDescription& test) const
{
  // get the integer equivalent of this and test words
  ull_t this_word = toInt();
  ull_t test_word = test.toInt();

  // check the remaining bits are reversed
  return ((~this_word & test_word) == test_word);
}

// -----------------------------------------------------------------------------
unsigned int SusyAnalysisTools::EventDescription::getComponent(
    const ull_t& rhs, unsigned int address, unsigned int size)
{
  return ( ((1 << size)-1) & (rhs >> address) );
}
