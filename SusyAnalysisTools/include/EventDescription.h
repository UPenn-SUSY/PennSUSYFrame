// Dear emacs, this is -*- c++ -*-
#ifndef SusyAnalysisTools_EventDescription_h
#define SusyAnalysisTools_EventDescription_h

#include "SusyEnums.h"

// ============================================================================
namespace SusyAnalysisTools
{
  // ==========================================================================
  class EventDescription
  {
    // ------------------------------------------------------------------------
    public:
      EventDescription();
      ~EventDescription();

      unsigned long long toInt() const;

      void clear();
      EventDescription& operator=(const EventDescription&);
      EventDescription& operator=(const unsigned long long&);

      void setPassGrl(bool);
      void setPassIncompleteEvent(bool);
      void setPassLarError(bool);
      void setPassTileError(bool);
      void setPassTileCalHotSpot(bool);
      void setPassBadJets(bool);
      void setPassPrimaryVertex(bool);
      void setPassBadMuons(bool);
      void setPassCosmicMuons(bool);
      void setPassHFOR(bool);
      void setPassGE2GoodLeptons(bool);
      void setPass2GoodLeptons(bool);
      void setPassMll(bool);
      void setPass2SignalLeptons(bool);
      void setPassTriggerMatch(bool);
      void setFlavorChannel(FLAVOR_CHANNEL);
      void setPhaseSpace(PHASE_SPACE);
      void setPhaseSpace(TRIG_PHASE);
      void setTriggerChannel(TRIGGER_CHANNEL);
      void setSignChannel(SIGN_CHANNEL);

      void setTruthMatched(bool);
      void setTruthPrompt(bool);
      void setCFCandidate(bool);
      void setTruthSignChannel(SIGN_CHANNEL);

      bool getPassGrl();
      bool getPassIncompleteEVent();
      bool getPassLarError();
      bool getPassTileError();
      bool getPassTileCalHotSpot();
      bool getPassBadJets();
      bool getPassPrimaryVertex();
      bool getPassBadMuons();
      bool getPassCosmicMuons();
      bool getPassHFOR();
      bool getPassGE2GoodLeptons();
      bool getPass2GoodLeptons();
      bool getPassMll();
      bool getPass2SignalLeptons();
      bool getPassTriggerMatch();
      FLAVOR_CHANNEL  getFlavorChannel();
      PHASE_SPACE     getPhaseSpace();
      TRIGGER_CHANNEL getTriggerChannel();
      SIGN_CHANNEL    getSignChannel();

      bool getTruthMatched();
      bool getTruthPrompt();
      bool getCFCandidate();
      SIGN_CHANNEL getTruthSignChannel();

    // ------------------------------------------------------------------------
    private:
      static const unsigned long long SIZE_BOOL    = 1;
      static const unsigned long long SIZE_FLAVOR  = 3;
      static const unsigned long long SIZE_TRIGGER = 3;
      static const unsigned long long SIZE_PHASE   = 4;
      static const unsigned long long SIZE_SIGN    = 2;

      static const unsigned long long ADD_GRL                = 0;
      static const unsigned long long ADD_INCOMPLETE_EVENT   = 1;
      static const unsigned long long ADD_LAR_ERROR          = 2;
      static const unsigned long long ADD_TILE_ERROR         = 3;
      static const unsigned long long ADD_TILE_CAL_HOT_SPOT  = 4;
      static const unsigned long long ADD_BAD_JETS           = 5;
      static const unsigned long long ADD_PRIMARY_VERTEX     = 6;
      static const unsigned long long ADD_BAD_MUONS          = 7;
      static const unsigned long long ADD_COSMIC_MUONS       = 8;
      static const unsigned long long ADD_HFOR               = 9;
      static const unsigned long long ADD_GE_2_GOOD_LEPTONS  = 10;
      static const unsigned long long ADD_2_GOOD_LEPTONS     = 11;
      static const unsigned long long ADD_MLL                = 12;
      static const unsigned long long ADD_2_SIGNAL_LEPTONS   = 13;
      static const unsigned long long ADD_FLAVOR_CHANNEL     = 14;
      static const unsigned long long ADD_PHASE_SPACE        = 17;
      static const unsigned long long ADD_TRIGGER_CHANNEL    = 21;
      static const unsigned long long ADD_TRIGGER_MATCH      = 24;
      static const unsigned long long ADD_SIGN_CHANNEL       = 25;
      static const unsigned long long ADD_TRUTH_SIGN_CHANNEL = 30;
      static const unsigned long long ADD_TRUTH_MATCHED      = 32;
      static const unsigned long long ADD_TRUTH_PROMPT       = 33;
      static const unsigned long long ADD_TRUTH_CF_CANDIDATE = 34;

      bool            m_pass_grl;
      bool            m_pass_incomplete_event;
      bool            m_pass_lar_error;
      bool            m_pass_tile_error;
      bool            m_pass_tile_cal_hot_spot;
      bool            m_pass_bad_jets;
      bool            m_pass_primary_vertex;
      bool            m_pass_bad_muons;
      bool            m_pass_cosmic_muons;
      bool            m_pass_hfor;
      bool            m_pass_ge_2_good_leptons;
      bool            m_pass_2_good_leptons;
      bool            m_pass_mll;
      bool            m_pass_2_signal_leptons;
      FLAVOR_CHANNEL  m_flavor_channel;
      PHASE_SPACE     m_phase_space;
      TRIGGER_CHANNEL m_trigger_channel;
      bool            m_pass_trigger_match;
      SIGN_CHANNEL    m_sign_channel;

      SIGN_CHANNEL m_truth_sign_channel;
      bool         m_truth_matched;
      bool         m_truth_prompt;
      bool         m_cf_candidate;
  };

} /* end of SusyAnalysisTools */


#endif /* end of include guard: SusyAnalysisTools_EventDescription_h */
