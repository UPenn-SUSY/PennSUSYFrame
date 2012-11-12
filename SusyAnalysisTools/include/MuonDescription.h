// Dear emacs, this is -*- c++ -*-
#ifndef SusyAnalysisTools_MuonDescription_h
#define SusyAnalysisTools_MuonDescription_h

#include "SusyEnums.h"

// =============================================================================
namespace SusyAnalysisTools
{
  // ===========================================================================
  class MuonDescription
  {
    // -------------------------------------------------------------------------
    public:
      MuonDescription();
      MuonDescription(ull_t);
      ~MuonDescription();

      ull_t toInt() const;

      void clear();
      void set (const MuonDescription&);
      void set (const ull_t&);
      MuonDescription& operator=(const MuonDescription&);
      MuonDescription& operator=(const ull_t&);

      void setPassBaseline(bool);
      void setPassGood(bool);
      void setPassSignal(bool);
      void setPassBad(bool);
      void setPassCosmic(bool);
      void setPassLoose(bool);
      void setPassSegTag(bool);
      void setPassCombined(bool);
      void setPassBLayer(bool);
      void setPassPixel(bool);
      void setPassSct(bool);
      void setPassTrt(bool);
      void setPassSiHoles(bool);
      void setPassBaselinePt(bool);
      void setPassBaselineEta(bool);
      void setPassD0Sig(bool);
      void setPassZ0SinTheta(bool);
      void setPassPtIso(bool);

      bool getPassBaseline() const;
      bool getPassGood() const;
      bool getPassSignal() const;
      bool getPassBad() const;
      bool getPassCosmic() const;
      bool getPassLoose() const;
      bool getPassSegTag() const;
      bool getPassCombined() const;
      bool getPassBLayer() const;
      bool getPassPixel() const;
      bool getPassSct() const;
      bool getPassTrt() const;
      bool getPassSiHoles() const;
      bool getPassBaselinePt() const;
      bool getPassBaselineEta() const;
      bool getPassD0Sig() const;
      bool getPassZ0SinTheta() const;
      bool getPassPtIso() const;

    // -------------------------------------------------------------------------
    private:
      static const unsigned int SIZE_BOOL = 1;

      static const unsigned int ADD_BASELINE     = 0;
      static const unsigned int ADD_GOOD         = 1;
      static const unsigned int ADD_SIGNAL       = 2;
      static const unsigned int ADD_BAD          = 3;
      static const unsigned int ADD_COSMIC       = 4;
      static const unsigned int ADD_LOOSE        = 5;
      static const unsigned int ADD_SEG_TAG      = 6;
      static const unsigned int ADD_COMBINED     = 7;
      static const unsigned int ADD_B_LAYER      = 8;
      static const unsigned int ADD_PIXEL        = 9;
      static const unsigned int ADD_SCT          = 10;
      static const unsigned int ADD_TRT          = 11;
      static const unsigned int ADD_SI_HOLES     = 12;
      static const unsigned int ADD_BASELINE_PT  = 13;
      static const unsigned int ADD_BASELINE_ETA = 14;
      static const unsigned int ADD_D0_SIG       = 15;
      static const unsigned int ADD_Z0_SIN_THETA = 16;
      static const unsigned int ADD_PT_ISO       = 17;

      bool m_pass_baseline;
      bool m_pass_good;
      bool m_pass_signal;
      bool m_pass_bad;
      bool m_pass_cosmic;
      bool m_pass_loose;
      bool m_pass_seg_tag;
      bool m_pass_combined;
      bool m_pass_b_layer;
      bool m_pass_pixel;
      bool m_pass_sct;
      bool m_pass_trt;
      bool m_pass_si_holes;
      bool m_pass_baseline_pt;
      bool m_pass_baseline_eta;
      bool m_pass_d0_sig;
      bool m_pass_z0_sin_theta;
      bool m_pass_pt_iso;

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


#endif /* end of include guard: SusyAnalysisTools_MuonDescription_h */


