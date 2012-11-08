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

      void setPassLJetVeto(bool);
      void setPassBJetVeto(bool);
      void setPassFJetVeto(bool);
      void setPassZVeto(bool);
      void setPassTopVeto(bool);
      void setPassSR1MetRel(bool);
      void setPassSR2MetRel(bool);
      void setPassSR32LJet(bool);
      void setPassSR3MetRel(bool);
      void setPassSR4aMetRel(bool);
      void setPassSR4bMetRel(bool);

      bool getPassLJetVeto();
      bool getPassBJetVeto();
      bool getPassFJetVeto();
      bool getPassZVeto();
      bool getPassTopVeto();
      bool getPassSR1MetRel();
      bool getPassSR2MetRel();
      bool getPassSR32LJet();
      bool getPassSR3MetRel();
      bool getPassSR4aMetRel();
      bool getPassSR4bMetRel();

    // ------------------------------------------------------------------------
    private:
      static const unsigned int SIZE_BOOL = 1;

      static const unsigned int ADD_L_JET_VETO = 0;
      static const unsigned int ADD_B_JET_VETO = 1;
      static const unsigned int ADD_F_JET_VETO = 2;
      static const unsigned int ADD_Z_VETO     = 3;
      static const unsigned int ADD_TOP_VETO   = 4;

      static const unsigned int ADD_SR1_MET_REL = 10;
      static const unsigned int ADD_SR2_MET_REL = 11;
      static const unsigned int ADD_SR3_2_L_JET = 12;
      static const unsigned int ADD_SR3_MET_REL = 13;
      static const unsigned int ADD_SR4a_MT2    = 14;
      static const unsigned int ADD_SR4b_MT2    = 15;


      bool m_pass_l_jet_veto;
      bool m_pass_b_jet_veto;
      bool m_pass_f_jet_veto;
      bool m_pass_z_veto;
      bool m_pass_top_veto;

      bool m_pass_sr1_met_rel;
      bool m_pass_sr2_met_rel;
      bool m_pass_sr3_2_l_jet;
      bool m_pass_sr3_met_rel;
      bool m_pass_sr4a_mt2;
      bool m_pass_sr4b_mt2;

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
