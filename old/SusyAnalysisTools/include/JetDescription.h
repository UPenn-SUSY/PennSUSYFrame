// Dear emacs, this is -*- c++ -*-
#ifndef SusyAnalysisTools_JetDescription_h
#define SusyAnalysisTools_JetDescription_h

#include "SusyEnums.h"

// =============================================================================
namespace SusyAnalysisTools
{
  // ===========================================================================
  class JetDescription
  {
    // -------------------------------------------------------------------------
    public:
      JetDescription();
      JetDescription(ull_t);
      ~JetDescription();

      ull_t toInt() const;

      void clear();
      void set (const JetDescription&);
      void set (const ull_t&);
      JetDescription& operator=(const JetDescription&);
      JetDescription& operator=(const ull_t&);

      void setPassBaselineGood(bool);
      void setPassBaselineBad(bool);
      void setPassGood(bool);
      void setPassBad(bool);
      void setPassLight(bool);
      void setPassB(bool);
      void setPassForward(bool);
      void setPassBaselinePt(bool);
      void setPassBaselineEta(bool);
      void setPassBTag(bool);
      void setPassCentralEta(bool);
      void setPassJvf(bool);
      void setPassLPt(bool);
      void setPassBPt(bool);
      void setPassFPt(bool);
      void setPassFEta(bool);

      bool getPassBaselineGood() const;
      bool getPassBaselineBad() const;
      bool getPassGood() const;
      bool getPassBad() const;
      bool getPassLight() const;
      bool getPassB() const;
      bool getPassForward() const;
      bool getPassBaselinePt() const;
      bool getPassBaselineEta() const;
      bool getPassBTag() const;
      bool getPassCentralEta() const;
      bool getPassJvf() const;
      bool getPassLPt() const;
      bool getPassBPt() const;
      bool getPassFPt() const;
      bool getPassFEta() const;

    // -------------------------------------------------------------------------
    private:
      static const unsigned int SIZE_BOOL = 1;

      static const unsigned int ADD_BASELINE_GOOD = 0;
      static const unsigned int ADD_BASELINE_BAD  = 1;
      static const unsigned int ADD_GOOD          = 2;
      static const unsigned int ADD_BAD           = 3;
      static const unsigned int ADD_LIGHT         = 4;
      static const unsigned int ADD_B             = 5;
      static const unsigned int ADD_FORWARD       = 6;
      static const unsigned int ADD_BASELINE_PT   = 7;
      static const unsigned int ADD_BASELINE_ETA  = 8;
      static const unsigned int ADD_B_TAG         = 9;
      static const unsigned int ADD_CENTRAL_ETA   = 10;
      static const unsigned int ADD_JVF           = 11;
      static const unsigned int ADD_L_PT          = 12;
      static const unsigned int ADD_B_PT          = 13;
      static const unsigned int ADD_F_PT          = 14;
      static const unsigned int ADD_F_ETA         = 15;

      bool m_pass_baseline_good;
      bool m_pass_baseline_bad;
      bool m_pass_good;
      bool m_pass_bad;
      bool m_pass_light;
      bool m_pass_b;
      bool m_pass_forward;
      bool m_pass_baseline_pt;
      bool m_pass_baseline_eta;
      bool m_pass_b_tag;
      bool m_pass_central_eta;
      bool m_pass_jvf;
      bool m_pass_l_jet_pt;
      bool m_pass_b_jet_pt;
      bool m_pass_f_jet_pt;
      bool m_pass_f_jet_eta;

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


#endif /* end of include guard: SusyAnalysisTools_JetDescription_h */


