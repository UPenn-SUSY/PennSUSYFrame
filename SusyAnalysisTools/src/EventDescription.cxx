#include "include/EventDescription.h"

// -----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription::EventDescription()
{
  // do nothing
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

  event_desc += getIntComp(m_pass_grl              , ADD_GRL               );
  event_desc += getIntComp(m_pass_incomplete_event , ADD_INCOMPLETE_EVENT  );
  event_desc += getIntComp(m_pass_lar_error        , ADD_LAR_ERROR         );
  event_desc += getIntComp(m_pass_tile_error       , ADD_TILE_ERROR        );
  event_desc += getIntComp(m_pass_tile_hot_spot    , ADD_TILE_HOT_SPOT     );
  event_desc += getIntComp(m_pass_bad_jets         , ADD_BAD_JETS          );
  event_desc += getIntComp(m_pass_primary_vertex   , ADD_PRIMARY_VERTEX    );
  event_desc += getIntComp(m_pass_bad_muons        , ADD_BAD_MUONS         );
  event_desc += getIntComp(m_pass_cosmic_muons     , ADD_COSMIC_MUONS      );
  event_desc += getIntComp(m_pass_hfor             , ADD_HFOR              );
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

  return event_desc;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::clear()
{
  *this = 0;
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::set(const SusyAnalysisTools::EventDescription& rhs)
{
  set(rhs.toInt());
}

// -----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::set(const ull_t& rhs)
{
  m_pass_grl               = getComponent(rhs, ADD_GRL             , SIZE_BOOL);
  m_pass_incomplete_event  = getComponent(rhs, ADD_INCOMPLETE_EVENT, SIZE_BOOL);
  m_pass_lar_error         = getComponent(rhs, ADD_LAR_ERROR       , SIZE_BOOL);
  m_pass_tile_error        = getComponent(rhs, ADD_TILE_ERROR      , SIZE_BOOL);
  m_pass_tile_hot_spot     = getComponent(rhs, ADD_TILE_HOT_SPOT   , SIZE_BOOL);
  m_pass_bad_jets          = getComponent(rhs, ADD_BAD_JETS        , SIZE_BOOL);
  m_pass_primary_vertex    = getComponent(rhs, ADD_PRIMARY_VERTEX  , SIZE_BOOL);
  m_pass_bad_muons         = getComponent(rhs, ADD_BAD_MUONS       , SIZE_BOOL);
  m_pass_cosmic_muons      = getComponent(rhs, ADD_COSMIC_MUONS    , SIZE_BOOL);
  m_pass_hfor              = getComponent(rhs, ADD_HFOR            , SIZE_BOOL);
  m_pass_ge_2_good_leptons = getComponent(rhs, ADD_GE_2_GOOD_LEPTON, SIZE_BOOL);
  m_pass_2_good_leptons    = getComponent(rhs, ADD_2_GOOD_LEPTON   , SIZE_BOOL);
  m_pass_mll               = getComponent(rhs, ADD_MLL             , SIZE_BOOL);
  m_pass_2_signal_leptons  = getComponent(rhs, ADD_2_SIGNAL_LEPTON , SIZE_BOOL);
  m_pass_ee_trigger        = getComponent(rhs, ADD_TRIGGER_EE      , SIZE_BOOL);
  m_pass_mm_trigger        = getComponent(rhs, ADD_TRIGGER_MM      , SIZE_BOOL);
  m_pass_em_trigger        = getComponent(rhs, ADD_TRIGGER_EM      , SIZE_BOOL);
  m_pass_trigger_match     = getComponent(rhs, ADD_TRIGGER_MATCH   , SIZE_BOOL);
  m_truth_matched          = getComponent(rhs, ADD_TRUTH_MATCHED   , SIZE_BOOL);
  m_truth_prompt           = getComponent(rhs, ADD_TRUTH_PROMPT    , SIZE_BOOL);
  m_cf_candidate           = getComponent(rhs, ADD_TRUTH_CF_CAND   , SIZE_BOOL);

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
void SusyAnalysisTools::EventDescription::setTruthSignChannel(
    SIGN_CHANNEL truth_sign_channel)
{
  m_truth_sign_channel = truth_sign_channel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassGrl()
{
  return m_pass_grl;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassIncompleteEVent()
{
  return m_pass_incomplete_event;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassLarError()
{
  return m_pass_lar_error;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassTileError()
{
  return m_pass_tile_error;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassTileHotSpot()
{
  return m_pass_tile_hot_spot;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassBadJets()
{
  return m_pass_bad_jets;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassPrimaryVertex()
{
  return m_pass_primary_vertex;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassBadMuons()
{
  return m_pass_bad_muons;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassCosmicMuons()
{
  return m_pass_cosmic_muons;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassHFOR()
{
  return m_pass_hfor;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassGE2GoodLeptons()
{
  return m_pass_ge_2_good_leptons;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPass2GoodLeptons()
{
  return m_pass_2_good_leptons;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassMll()
{
  return m_pass_mll;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPass2SignalLeptons()
{
  return m_pass_2_signal_leptons;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassTriggerMatch()
{
  return m_pass_trigger_match;
}

// -----------------------------------------------------------------------------
FLAVOR_CHANNEL SusyAnalysisTools::EventDescription::getFlavorChannel()
{
  return m_flavor_channel;
}

// -----------------------------------------------------------------------------
PHASE_SPACE SusyAnalysisTools::EventDescription::getPhaseSpace()
{
  return m_phase_space;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::isEETrigger()
{
  return m_pass_ee_trigger;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::isMMTrigger()
{
  return m_pass_mm_trigger;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::isEMTrigger()
{
  return m_pass_em_trigger;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::isMETrigger()
{
  return m_pass_me_trigger;
}

// -----------------------------------------------------------------------------
SIGN_CHANNEL SusyAnalysisTools::EventDescription::getSignChannel()
{
  return m_sign_channel;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getTruthMatched()
{
  return m_truth_matched;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getTruthPrompt()
{
  return m_truth_prompt;
}

// -----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getCFCandidate()
{
  return m_cf_candidate;
}

// -----------------------------------------------------------------------------
SIGN_CHANNEL SusyAnalysisTools::EventDescription::getTruthSignChannel()
{
  return m_truth_sign_channel;
}

// -----------------------------------------------------------------------------
unsigned int SusyAnalysisTools::EventDescription::getComponent(
    const ull_t& rhs, unsigned int address, unsigned int size)
{
  return ( ((1 << size)-1) & (rhs >> address) );
}
