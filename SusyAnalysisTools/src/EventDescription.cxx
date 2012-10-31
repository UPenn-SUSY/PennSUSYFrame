#include "include/EventDescription.h"

// ----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription::EventDescription()
{
  // do nothing
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription::~EventDescription()
{
  // do nothing
}

// ----------------------------------------------------------------------------
unsigned long long SusyAnalysisTools::EventDescription::toInt() const
{
  unsigned long long event_desc = 0;

  event_desc += (  static_cast<unsigned long long>(m_pass_grl)
                << ADD_GRL);
  event_desc += (  static_cast<unsigned long long>(m_pass_incomplete_event)
                << ADD_INCOMPLETE_EVENT);
  event_desc += (  static_cast<unsigned long long>(m_pass_lar_error)
                << ADD_LAR_ERROR);
  event_desc += (  static_cast<unsigned long long>(m_pass_tile_error)
                << ADD_TILE_ERROR);
  event_desc += (  static_cast<unsigned long long>(m_pass_tile_cal_hot_spot)
                << ADD_TILE_CAL_HOT_SPOT);
  event_desc += (  static_cast<unsigned long long>(m_pass_bad_jets)
                << ADD_BAD_JETS);
  event_desc += (  static_cast<unsigned long long>(m_pass_primary_vertex)
                << ADD_PRIMARY_VERTEX);
  event_desc += (  static_cast<unsigned long long>(m_pass_bad_muons)
                << ADD_BAD_MUONS);
  event_desc += (  static_cast<unsigned long long>(m_pass_cosmic_muons)
                << ADD_COSMIC_MUONS);
  event_desc += (  static_cast<unsigned long long>(m_pass_hfor)
                << ADD_HFOR);
  event_desc += (static_cast<unsigned long long>(m_pass_ge_2_good_leptons)
                << ADD_GE_2_GOOD_LEPTONS);
  event_desc += (  static_cast<unsigned long long>(m_pass_2_good_leptons)
                << ADD_2_GOOD_LEPTONS);
  event_desc += (  static_cast<unsigned long long>(m_pass_mll)
                << ADD_MLL);
  event_desc += (  static_cast<unsigned long long>(m_pass_2_signal_leptons)
                << ADD_2_SIGNAL_LEPTONS);
  event_desc += (  static_cast<unsigned long long>(m_flavor_channel)
                << ADD_FLAVOR_CHANNEL);
  event_desc += (  static_cast<unsigned long long>(m_phase_space)
                << ADD_PHASE_SPACE);
  event_desc += (  static_cast<unsigned long long>(m_trigger_channel)
                << ADD_TRIGGER_CHANNEL);
  event_desc += (  static_cast<unsigned long long>(m_pass_trigger_match)
                << ADD_TRIGGER_MATCH);
  event_desc += (  static_cast<unsigned long long>(m_sign_channel)
                << ADD_SIGN_CHANNEL);
  event_desc += (  static_cast<unsigned long long>(m_truth_sign_channel)
                << ADD_TRUTH_SIGN_CHANNEL);
  event_desc += (  static_cast<unsigned long long>(m_truth_matched)
                << ADD_TRUTH_MATCHED);
  event_desc += (  static_cast<unsigned long long>(m_truth_prompt)
                << ADD_TRUTH_PROMPT);
  event_desc += (  static_cast<unsigned long long>(m_cf_candidate)
                << ADD_TRUTH_CF_CANDIDATE);

  return event_desc;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::clear()
{
  *this = 0;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription&
    SusyAnalysisTools::EventDescription::operator=(
        const SusyAnalysisTools::EventDescription& rhs)
{
  *this = rhs.toInt();
  return *this;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription&
    SusyAnalysisTools::EventDescription::operator=(
        const unsigned long long& rhs)
{
  m_pass_grl               = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_GRL               ) );
  m_pass_incomplete_event  = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_INCOMPLETE_EVENT  ) );
  m_pass_lar_error         = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_LAR_ERROR         ) );
  m_pass_tile_error        = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_TILE_ERROR        ) );
  m_pass_tile_cal_hot_spot = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_TILE_CAL_HOT_SPOT ) );
  m_pass_bad_jets          = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_BAD_JETS          ) );
  m_pass_primary_vertex    = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_PRIMARY_VERTEX    ) );
  m_pass_bad_muons         = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_BAD_MUONS         ) );
  m_pass_cosmic_muons      = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_COSMIC_MUONS      ) );
  m_pass_hfor              = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_HFOR              ) );
  m_pass_ge_2_good_leptons = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_GE_2_GOOD_LEPTONS ) );
  m_pass_2_good_leptons    = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_2_GOOD_LEPTONS    ) );
  m_pass_mll               = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_MLL               ) );
  m_pass_2_signal_leptons  = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_2_SIGNAL_LEPTONS  ) );
  m_pass_trigger_match     = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_TRIGGER_MATCH     ) );
  m_truth_matched          = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_TRUTH_MATCHED     ) );
  m_truth_prompt           = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_TRUTH_PROMPT      ) );
  m_cf_candidate           = ( ((1 << SIZE_BOOL)-1 ) & (rhs >> ADD_TRUTH_CF_CANDIDATE) );

  m_flavor_channel =
    static_cast<FLAVOR_CHANNEL>( ((1 << SIZE_FLAVOR )-1) & (rhs >> ADD_FLAVOR_CHANNEL) );
  m_phase_space =
    static_cast<PHASE_SPACE>( ((1 << SIZE_PHASE)-1) & (rhs >> ADD_PHASE_SPACE) );
  m_trigger_channel =
    static_cast<TRIGGER_CHANNEL>( ((1 << SIZE_TRIGGER)-1) & (rhs >> ADD_TRIGGER_CHANNEL) );
  m_sign_channel =
    static_cast<SIGN_CHANNEL>( ((1 << SIZE_SIGN)-1) & (rhs >> ADD_SIGN_CHANNEL) );
  m_truth_sign_channel =
    static_cast<SIGN_CHANNEL>( ((1 << SIZE_SIGN)-1) & (rhs >> ADD_TRUTH_SIGN_CHANNEL) );

  return *this;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassGrl(bool pass_grl)
{
  m_pass_grl = pass_grl;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassIncompleteEvent(
    bool pass_incomplete_event)
{
  m_pass_incomplete_event = pass_incomplete_event;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassLarError(bool pass_lar_error)
{
  m_pass_lar_error = pass_lar_error;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassTileError(bool pass_tile_error)
{
  m_pass_tile_error = pass_tile_error;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassTileCalHotSpot(
    bool pass_tile_cal_hot_spot)
{
  m_pass_tile_cal_hot_spot = pass_tile_cal_hot_spot;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassBadJets(bool pass_bad_jets)
{
  m_pass_bad_jets = pass_bad_jets;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassPrimaryVertex(
    bool pass_primary_vertex)
{
  m_pass_primary_vertex = pass_primary_vertex;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassBadMuons(bool pass_bad_muons)
{
  m_pass_bad_muons = pass_bad_muons;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassCosmicMuons(
    bool pass_cosmic_muons)
{
  m_pass_cosmic_muons = pass_cosmic_muons;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassHFOR(bool pass_hfor)
{
  m_pass_hfor = pass_hfor;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassGE2GoodLeptons(
    bool pass_ge_2_good_leptons)
{
  m_pass_ge_2_good_leptons = pass_ge_2_good_leptons;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPass2GoodLeptons(
    bool pass_2_good_leptons)
{
  m_pass_2_good_leptons = pass_2_good_leptons;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassMll(bool pass_mll)
{
  m_pass_mll = pass_mll;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPass2SignalLeptons(
    bool pass_2_signal_leptons)
{
  m_pass_2_signal_leptons = pass_2_signal_leptons;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPassTriggerMatch(
    bool pass_trigger_match)
{
  m_pass_trigger_match = pass_trigger_match;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setFlavorChannel(
    SusyAnalysisTools::FLAVOR_CHANNEL flavor_channel)
{
  m_flavor_channel = flavor_channel;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPhaseSpace(
    SusyAnalysisTools::PHASE_SPACE phase_space)
{
  m_phase_space = phase_space;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setPhaseSpace(
    TRIG_PHASE trig_phase)
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

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setTriggerChannel(
    SusyAnalysisTools::TRIGGER_CHANNEL trigger_channel)
{
  m_trigger_channel = trigger_channel;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setSignChannel(
    SusyAnalysisTools::SIGN_CHANNEL sign_channel)
{
  m_sign_channel = sign_channel;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setTruthMatched(bool truth_matched)
{
  m_truth_matched = truth_matched;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setTruthPrompt(bool truth_prompt)
{
  m_truth_prompt = truth_prompt;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setCFCandidate(bool cf_candidate)
{
  m_cf_candidate = cf_candidate;
}

// ----------------------------------------------------------------------------
void SusyAnalysisTools::EventDescription::setTruthSignChannel(
    SusyAnalysisTools::SIGN_CHANNEL truth_sign_channel)
{
  m_truth_sign_channel = truth_sign_channel;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassGrl()
{
  return m_pass_grl;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassIncompleteEVent()
{
  return m_pass_incomplete_event;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassLarError()
{
  return m_pass_lar_error;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassTileError()
{
  return m_pass_tile_error;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassTileCalHotSpot()
{
  return m_pass_tile_cal_hot_spot;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassBadJets()
{
  return m_pass_bad_jets;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassPrimaryVertex()
{
  return m_pass_primary_vertex;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassBadMuons()
{
  return m_pass_bad_muons;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassCosmicMuons()
{
  return m_pass_cosmic_muons;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassHFOR()
{
  return m_pass_hfor;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassGE2GoodLeptons()
{
  return m_pass_ge_2_good_leptons;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPass2GoodLeptons()
{
  return m_pass_2_good_leptons;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassMll()
{
  return m_pass_mll;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPass2SignalLeptons()
{
  return m_pass_2_signal_leptons;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getPassTriggerMatch()
{
  return m_pass_trigger_match;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::FLAVOR_CHANNEL
    SusyAnalysisTools::EventDescription::getFlavorChannel()
{
  return m_flavor_channel;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::PHASE_SPACE
    SusyAnalysisTools::EventDescription::getPhaseSpace()
{
  return m_phase_space;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::TRIGGER_CHANNEL
    SusyAnalysisTools::EventDescription::getTriggerChannel()
{
  return m_trigger_channel;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::SIGN_CHANNEL
    SusyAnalysisTools::EventDescription::getSignChannel()
{
  return m_sign_channel;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getTruthMatched()
{
  return m_truth_matched;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getTruthPrompt()
{
  return m_truth_prompt;
}

// ----------------------------------------------------------------------------
bool SusyAnalysisTools::EventDescription::getCFCandidate()
{
  return m_cf_candidate;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::SIGN_CHANNEL
    SusyAnalysisTools::EventDescription::getTruthSignChannel()
{
  return m_truth_sign_channel;
}
