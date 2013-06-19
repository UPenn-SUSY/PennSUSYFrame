// Dear emacs, this is -*- c++ -*-
#ifndef SusyAnalysisTools_TauDescription_h
#define SusyAnalysisTools_TauDescription_h

#include "SusyEnums.h"

// =============================================================================
namespace SusyAnalysisTools
{
  // ===========================================================================
  class TauDescription
  {
    // -------------------------------------------------------------------------
    public:
      TauDescription();
      TauDescription(ull_t);
      ~TauDescription();

      ull_t toInt() const;

      void clear();
      void set(const TauDescription&);
      void set(const ull_t&);
      TauDescription& operator=(const TauDescription&);
      TauDescription& operator=(const ull_t&);

      void setPassBaseline(bool);
      void setPassGood(bool);
      void setPassSignal(bool);
      void setPassBaselinePt(bool);
      void setPassBaselineEta(bool);
      void setPassBaselineNumTracks(bool);
      void setPassBaselineCharge(bool);
      void setPassBaselineJetBDTLevel(bool);
      void setPassBaselineEleBDTLevel(bool);
      void setPassBaselineMuVeto(bool);

      bool getPassBaseline() const;
      bool getPassGood() const;
      bool getPassSignal() const;
      bool getPassBaselinePt() const;
      bool getPassBaselineEta() const;
      bool getPassBaselineNumTracks() const;
      bool getPassBaselineCharge() const;
      bool getPassBaselineJetBDTLevel() const;
      bool getPassBaselineEleBDTLevel() const;
      bool getPassBaselineMuVeto() const;

    // -------------------------------------------------------------------------
    private:
      static const unsigned int SIZE_BOOL = 1;

      static const unsigned int ADD_BASELINE               = 0;
      static const unsigned int ADD_GOOD                = 1;
      static const unsigned int ADD_SIGNAL              = 2;
      static const unsigned int ADD_BASELINE_PT            = 5;
      static const unsigned int ADD_BASELINE_ETA           = 6;
      static const unsigned int ADD_BASELINE_NUM_TRACKS    = 7;
      static const unsigned int ADD_BASELINE_CHARGE        = 8;
      static const unsigned int ADD_BASELINE_JET_BDT_LEVEL = 9;
      static const unsigned int ADD_BASELINE_ELEBDT_LEVEL  = 10;
      static const unsigned int ADD_BASELINE_MU_VETO       = 11;

      bool m_pass_baseline;
      bool m_pass_good;
      bool m_pass_signal;
      bool m_pass_baseline_pt;
      bool m_pass_baseline_eta;
      bool m_pass_baseline_num_tracks;
      bool m_pass_baseline_charge;
      bool m_pass_baseline_jet_bdt_level;
      bool m_pass_baseline_elebdt_level;
      bool m_pass_baseline_mu_veto;

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


#endif /* end of include guard: SusyAnalysisTools_TauDescription_h */


