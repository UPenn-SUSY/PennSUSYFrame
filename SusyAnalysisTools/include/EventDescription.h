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
      EventDescription(ull_t);
      ~EventDescription();

      ull_t toInt() const;

      void clear();
      void set (const EventDescription&);
      void set (const ull_t&);
      EventDescription& operator=(const EventDescription&);
      EventDescription& operator=(const ull_t&);

      void setIsData(bool);
      void setPassGrl(bool);
      void setPassIncompleteEvent(bool);
      void setPassLarError(bool);
      void setPassTileError(bool);
      void setPassTileHotSpot(bool);
      void setPassBadJets(bool);
      void setPassCaloProblemJets(bool);
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
      void setEETrigger(bool);
      void setMMTrigger(bool);
      void setEMTrigger(bool);
      void setMETrigger(bool);
      void setSignChannel(SIGN_CHANNEL);

      void setTruthMatched(bool);
      void setTruthPrompt(bool);
      void setCFCandidate(bool);
      void setTruthSignChannel(SIGN_CHANNEL);

      void setSROSJVeto(bool);
      void setSRSSJets(bool);
      void setSR2Jets(bool);
      void setSRMT2a(bool);
      void setSRMT2b(bool);

      void setSRWWa(bool);
      void setSRWWb(bool);
      void setSRWWc(bool);
      void setSRZjets(bool);

      // void setCR1(bool);
      // void setCR2(bool);
      // void setCR3(bool);
      // void setCR4(bool);

      bool getIsData() const;
      bool getPassGrl() const;
      bool getPassIncompleteEvent() const;
      bool getPassLarError() const;
      bool getPassTileError() const;
      bool getPassTileHotSpot() const;
      bool getPassBadJets() const;
      bool getPassCaloProblemJets() const;
      bool getPassPrimaryVertex() const;
      bool getPassBadMuons() const;
      bool getPassCosmicMuons() const;
      bool getPassHFOR() const;
      bool getPassGE2GoodLeptons() const;
      bool getPass2GoodLeptons() const;
      bool getPassMll() const;
      bool getPass2SignalLeptons() const;
      bool getPassTriggerMatch() const;
      FLAVOR_CHANNEL  getFlavorChannel() const;
      PHASE_SPACE     getPhaseSpace() const;
      bool isEETrigger() const;
      bool isMMTrigger() const;
      bool isEMTrigger() const;
      bool isMETrigger() const;
      SIGN_CHANNEL    getSignChannel() const;

      bool getTruthMatched() const;
      bool getTruthPrompt() const;
      bool getCFCandidate() const;
      SIGN_CHANNEL getTruthSignChannel() const;

      bool getPassSROSJVeto() const;
      bool getPassSRSSJets() const;
      bool getPassSR2Jets() const;
      bool getPassSRMT2a() const;
      bool getPassSRMT2b() const;

      bool getPassSRWWa() const;
      bool getPassSRWWb() const;
      bool getPassSRWWc() const;
      bool getPassSRZjets() const;

      // bool getPassCR1() const;
      // bool getPassCR2() const;
      // bool getPassCR3() const;
      // bool getPassCR4() const;

      bool pass(   const EventDescription& test) const;
      bool reverse(const EventDescription& test) const;

    // -------------------------------------------------------------------------
    private:
      static const unsigned int SIZE_BOOL    = 1;
      static const unsigned int SIZE_FLAVOR  = 3;
      static const unsigned int SIZE_PHASE   = 4;
      static const unsigned int SIZE_SIGN    = 2;

      static const unsigned int ADD_IS_DATA            = 0;
      static const unsigned int ADD_GRL                = 1;
      static const unsigned int ADD_INCOMPLETE_EVENT   = 2;
      static const unsigned int ADD_LAR_ERROR          = 3;
      static const unsigned int ADD_TILE_ERROR         = 4;
      static const unsigned int ADD_TILE_HOT_SPOT      = 5;
      static const unsigned int ADD_BAD_JETS           = 6;
      static const unsigned int ADD_CALO_PROBLEM_JETS  = 7;
      static const unsigned int ADD_PRIMARY_VERTEX     = 8;
      static const unsigned int ADD_BAD_MUONS          = 9;
      static const unsigned int ADD_COSMIC_MUONS       = 10;
      static const unsigned int ADD_HFOR               = 11;
      static const unsigned int ADD_GE_2_GOOD_LEPTON   = 12;
      static const unsigned int ADD_2_GOOD_LEPTON      = 13;
      static const unsigned int ADD_2_SIGNAL_LEPTON    = 14;
      static const unsigned int ADD_MLL                = 15;
      static const unsigned int ADD_FLAVOR_CHANNEL     = 16;
      static const unsigned int ADD_PHASE_SPACE        = 19;
      static const unsigned int ADD_TRIGGER_EE         = 23;
      static const unsigned int ADD_TRIGGER_MM         = 24;
      static const unsigned int ADD_TRIGGER_EM         = 25;
      static const unsigned int ADD_TRIGGER_ME         = 26;
      static const unsigned int ADD_TRIGGER_MATCH      = 27;
      static const unsigned int ADD_SIGN_CHANNEL       = 28;
      static const unsigned int ADD_TRUTH_SIGN_CHANNEL = 30;
      static const unsigned int ADD_TRUTH_MATCHED      = 32;
      static const unsigned int ADD_TRUTH_PROMPT       = 33;
      static const unsigned int ADD_TRUTH_CF_CAND      = 34;
      static const unsigned int ADD_SR_OSJVETO         = 40;
      static const unsigned int ADD_SR_SSJETS          = 41;
      static const unsigned int ADD_SR_2JETS           = 42;
      static const unsigned int ADD_SR_MT2a            = 43;
      static const unsigned int ADD_SR_MT2b            = 44;
      static const unsigned int ADD_SR_WWA             = 45;
      static const unsigned int ADD_SR_WWB             = 46;
      static const unsigned int ADD_SR_WWC             = 47;
      static const unsigned int ADD_SR_ZJETS           = 48;
      static const unsigned int ADD_CR_ZXOSJVETO       = 50;
      static const unsigned int ADD_CR_ZXMT2A          = 51;
      static const unsigned int ADD_CR_ZXMT2B          = 52;
      static const unsigned int ADD_CR_ZX2JETS         = 53;
      static const unsigned int ADD_CR_ZXWW            = 54;
      static const unsigned int ADD_CR_TOP             = 55;
      static const unsigned int ADD_CR_TOPWWA          = 56;
      static const unsigned int ADD_CR_TOPWWB          = 57;
      static const unsigned int ADD_CR_TOPWWC          = 58;
      static const unsigned int ADD_CR_WW1             = 59;
      static const unsigned int ADD_CR_WW2             = 60;
      static const unsigned int ADD_CR_WWA             = 61;
      static const unsigned int ADD_CR_WWB             = 62;
      static const unsigned int ADD_CR_WWC             = 63;
      // static const unsigned int ADD_CR_BTAG            = 64;


      bool            m_is_data;
      bool            m_pass_grl;
      bool            m_pass_incomplete_event;
      bool            m_pass_lar_error;
      bool            m_pass_tile_error;
      bool            m_pass_tile_hot_spot;
      bool            m_pass_bad_jets;
      bool            m_pass_calo_problem_jets;
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
      bool            m_pass_ee_trigger;
      bool            m_pass_mm_trigger;
      bool            m_pass_em_trigger;
      bool            m_pass_me_trigger;
      bool            m_pass_trigger_match;
      SIGN_CHANNEL    m_sign_channel;

      SIGN_CHANNEL m_truth_sign_channel;
      bool         m_truth_matched;
      bool         m_truth_prompt;
      bool         m_cf_candidate;

      bool m_pass_sr_osjveto;
      bool m_pass_sr_ssjets;
      bool m_pass_sr_2jets;
      bool m_pass_sr_mt2a;
      bool m_pass_sr_mt2b;

      bool m_pass_sr_wwa;
      bool m_pass_sr_wwb;
      bool m_pass_sr_wwc;
      bool m_pass_sr_zjets;

      // bool m_pass_cr1;
      // bool m_pass_cr2;
      // bool m_pass_cr3;
      // bool m_pass_cr4;

      // TODO move implementation to icc file
      template <class T>
        static ull_t getIntComp( T component
                               , unsigned int address
                               )
        {
          return ( static_cast<ull_t>(component) << address );
        }

      static unsigned int getComponent( const ull_t& rhs
                                      , unsigned int address
                                      , unsigned int size
                                      );
  };

} /* end of SusyAnalysisTools */


#endif /* end of include guard: SusyAnalysisTools_EventDescription_h */
