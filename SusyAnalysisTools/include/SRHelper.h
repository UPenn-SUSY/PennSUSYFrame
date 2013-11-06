// Dear emacs, this is -*- c++ -*-
#ifndef SusyAnalysisTools_SRHelper_h
#define SusyAnalysisTools_SRHelper_h

#include "SusyEnums.h"

// ============================================================================
namespace SusyAnalysisTools
{
  // ==========================================================================
  class SRHelper
  {
    // ------------------------------------------------------------------------
    public:
      SRHelper();
      SRHelper(ull_t);
      ~SRHelper();

      ull_t toInt() const;

      void clear();
      void set (const SRHelper&);
      void set (const ull_t&);
      SRHelper& operator=(const SRHelper&);
      SRHelper& operator=(const ull_t&);

      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      // setter methods
      void setPassLJetVeto(bool);
      void setPassBJetVeto(bool);
      void setPassFJetVeto(bool);
      void setPassZVeto(bool);
      void setPassTopVeto(bool);

      void setPassSRSSMllVeto(bool);
      void setPassSRSSEmmaMt(bool);
      void setPassSRSSMetRel(bool);
      void setPassSRSSDphill(bool);

      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      // getter methods
      bool getPassLJetVeto();
      bool getPassBJetVeto();
      bool getPassFJetVeto();
      bool getPassZVeto();
      bool getPassTopVeto();

      bool getPassSRSSMllVeto();
      bool getPassSRSSEmmaMt();
      bool getPassSRSSMetRel();
      bool getPassSRSSDphill();

      bool pass(   const SRHelper&) const;
      bool reverse(const SRHelper&) const;

    // ------------------------------------------------------------------------
    private:
      static const unsigned int SIZE_BOOL = 1;

      static const unsigned int ADD_L_JET_VETO = 0;
      static const unsigned int ADD_B_JET_VETO = 1;
      static const unsigned int ADD_F_JET_VETO = 2;
      static const unsigned int ADD_GE_L_JET   = 3;
      static const unsigned int ADD_Z_VETO     = 4;
      static const unsigned int ADD_TOP_VETO   = 5;

      static const unsigned int ADD_SR_SS_MLL_VETO  = 10;
      static const unsigned int ADD_SR_SS_EMMA_MT   = 11;
      static const unsigned int ADD_SR_SS_MET_REL   = 12;
      static const unsigned int ADD_SR_SS_DPHI_LL   = 13;

      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      bool m_pass_l_jet_veto;
      bool m_pass_b_jet_veto;
      bool m_pass_f_jet_veto;
      bool m_pass_z_veto;
      bool m_pass_top_veto;

      bool m_pass_sr_ss_mll_veto;
      bool m_pass_sr_ss_emma_mt;
      bool m_pass_sr_ss_met_rel;
      bool m_pass_sr_ss_dphi_ll;

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


#endif /* end of include guard: SusyAnalysisTools_SRHelper_h */
