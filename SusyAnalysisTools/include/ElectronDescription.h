// Dear emacs, this is -*- c++ -*-
#ifndef SusyAnalysisTools_ElectronDescription_h
#define SusyAnalysisTools_ElectronDescription_h

#include "SusyEnums.h"

// =============================================================================
namespace SusyAnalysisTools
{
  // ===========================================================================
  class ElectronDescription
  {
    // -------------------------------------------------------------------------
    public:
      ElectronDescription();
      ElectronDescription(ull_t);
      ~ElectronDescription();

      ull_t toInt() const;

      void clear();
      void set (const ElectronDescription&);
      void set (const ull_t&);
      ElectronDescription& operator=(const ElectronDescription&);
      ElectronDescription& operator=(const ull_t&);

      void setPassBaseline(bool);
      void setPassGood(bool);
      void setPassSignal(bool);
      void setPassClusterSeed(bool);
      void setPassOtx(bool);
      void setPassMediumPp(bool);
      void setPassBaselinePt(bool);
      void setPassBaselineEta(bool);
      void setPassTightPp(bool);
      void setPassD0Sig(bool);
      void setPassZ0SinTheta(bool);
      void setPassPtIso(bool);
      void setPassCaloIso(bool);

      bool getPassBaseline() const;
      bool getPassGood() const;
      bool getPassSignal() const;
      bool getPassClusterSeed() const;
      bool getPassOtx() const;
      bool getPassMediumPp() const;
      bool getPassBaselinePt() const;
      bool getPassBaselineEta() const;
      bool getPassTightPp() const;
      bool getPassD0Sig() const;
      bool getPassZ0SinTheta() const;
      bool getPassPtIso() const;
      bool getPassCaloIso() const;

    // -------------------------------------------------------------------------
    private:
      static const unsigned int SIZE_BOOL = 1;

      static const unsigned int ADD_BASELINE     = 0;
      static const unsigned int ADD_GOOD         = 1;
      static const unsigned int ADD_SIGNAL       = 2;
      static const unsigned int ADD_CLUSTER_SEED = 3;
      static const unsigned int ADD_OTX          = 4;
      static const unsigned int ADD_MEDIUM_PP    = 5;
      static const unsigned int ADD_BASELINE_PT  = 6;
      static const unsigned int ADD_BASELINE_ETA = 7;
      static const unsigned int ADD_TIGHT_PP     = 8;
      static const unsigned int ADD_D0_SIG       = 9;
      static const unsigned int ADD_Z0_SIN_THETA = 10;
      static const unsigned int ADD_PT_ISO       = 11;
      static const unsigned int ADD_CALO_ISO     = 12;

      bool m_pass_baseline;
      bool m_pass_good;
      bool m_pass_signal;
      bool m_pass_cluster_seed;
      bool m_pass_otx;
      bool m_pass_medium_pp;
      bool m_pass_baseline_pt;
      bool m_pass_baseline_eta;
      bool m_pass_tight_pp;
      bool m_pass_d0_sig;
      bool m_pass_z0_sin_theta;
      bool m_pass_pt_iso;
      bool m_pass_calo_iso;

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


#endif /* end of include guard: SusyAnalysisTools_ElectronDescription_h */

