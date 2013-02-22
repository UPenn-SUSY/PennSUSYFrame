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
      void setPassSROSJVetoMetRel(bool);
      void setPassSROSJVetoMt2(bool);
      void setPassSRSSJetsMetRel(bool);
      void setPassSRSSJetsMt(bool);
      void setPassSR2JetsNumLJet(bool);
      void setPassSR2JetsMetRel(bool);
      void setPassSRMT2MetRel(bool);
      void setPassSRMT2aMt2(bool);
      void setPassSRMT2bMt2(bool);
      void setPassSRWWLep1Pt(bool);
      void setPassSRWWLep2Pt(bool);
      void setPassSRWWaMetRel(bool);
      void setPassSRWWaPtll(bool);
      void setPassSRWWaMll(bool);
      void setPassSRWWbMt2(bool);
      void setPassSRWWbPtll(bool);
      void setPassSRWWbMll(bool);
      void setPassSRWWcPtll(bool);
      void setPassSRWWcMt2(bool);
      void setPassSrZjetsNumLJets(bool);
      void setPassSrZjetsMetRel(bool);
      void setPassSrZjetsLep1Pt(bool);
      void setPassSrZjetsLep2Pt(bool);
      void setPassSrZjetsMjj(bool);
      void setPassSrZjetsMt2(bool);

      bool getPassLJetVeto();
      bool getPassBJetVeto();
      bool getPassFJetVeto();
      bool getPassZVeto();
      bool getPassTopVeto();
      bool getPassSROSJVetoMetRel();
      bool getPassSROSJVetoMt2();
      bool getPassSRSSJetsMetRel();
      bool getPassSRSSJetsMt();
      bool getPassSR2JetsNumLJet();
      bool getPassSR2JetsMetRel();
      bool getPassSRMT2MetRel();
      bool getPassSRMT2aMt2();
      bool getPassSRMT2bMt2();
      bool getPassSRWWLep1Pt();
      bool getPassSRWWLep2Pt();
      bool getPassSRWWaMetRel();
      bool getPassSRWWaPtll();
      bool getPassSRWWaMll();
      bool getPassSRWWbMt2();
      bool getPassSRWWbPtll();
      bool getPassSRWWbMll();
      bool getPassSRWWcPtll();
      bool getPassSRWWcMt2();
      bool getPassSRZjetsNumLJets();
      bool getPassSRZjetsMetRel();
      bool getPassSRZjetsLep1Pt();
      bool getPassSRZjetsLep2Pt();
      bool getPassSRZjetsMjj();
      bool getPassSRZjetsMt2();

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

      static const unsigned int ADD_SR_OSJVETO_MET_REL  = 10;
      static const unsigned int ADD_SR_OSJVETO_MT2      = 11;
      static const unsigned int ADD_SR_SSJETS_MET_REL   = 12;
      static const unsigned int ADD_SR_SSJETS_MT        = 13;
      static const unsigned int ADD_SR_2JETS_NUM_L_JET  = 14;
      static const unsigned int ADD_SR_2JETS_MET_REL    = 15;
      static const unsigned int ADD_SR_MT2_MET_REL      = 16;
      static const unsigned int ADD_SR_MT2a_MT2         = 17;
      static const unsigned int ADD_SR_MT2b_MT2         = 18;
      static const unsigned int ADD_SR_WW_LEP1_PT       = 19;
      static const unsigned int ADD_SR_WW_LEP2_PT       = 20;
      static const unsigned int ADD_SR_WWA_MET_REL      = 21;
      static const unsigned int ADD_SR_WWA_PTLL         = 22;
      static const unsigned int ADD_SR_WWA_MLL          = 23;
      static const unsigned int ADD_SR_WWB_MT2          = 24;
      static const unsigned int ADD_SR_WWB_PTLL         = 25;
      static const unsigned int ADD_SR_WWB_MLL          = 26;
      static const unsigned int ADD_SR_WWC_PTLL         = 27;
      static const unsigned int ADD_SR_WWC_MT2          = 28;
      static const unsigned int ADD_SR_ZJETS_NUM_L_JETS = 29;
      static const unsigned int ADD_SR_ZJETS_MET_REL    = 30;
      static const unsigned int ADD_SR_ZJETS_LEP1_PT    = 31;
      static const unsigned int ADD_SR_ZJETS_LEP2_PT    = 32;
      static const unsigned int ADD_SR_ZJETS_MJJ        = 33;
      static const unsigned int ADD_SR_ZJETS_MT2        = 34;

      bool m_pass_l_jet_veto;
      bool m_pass_b_jet_veto;
      bool m_pass_f_jet_veto;
      bool m_pass_z_veto;
      bool m_pass_top_veto;

      bool m_pass_sr_osjveto_met_rel;
      bool m_pass_sr_osjveto_mt2;
      bool m_pass_sr_ssjets_met_rel;
      bool m_pass_sr_ssjets_mt;
      bool m_pass_sr_2jets_num_l_jet;
      bool m_pass_sr_2jets_met_rel;
      bool m_pass_sr_mt2_met_rel;
      bool m_pass_sr_mt2a_mt2;
      bool m_pass_sr_mt2b_mt2;

      bool m_pass_sr_ww_lep1_pt;
      bool m_pass_sr_ww_lep2_pt;
      bool m_pass_sr_wwa_met_rel;
      bool m_pass_sr_wwa_ptll;
      bool m_pass_sr_wwa_mll;
      bool m_pass_sr_wwb_mt2;
      bool m_pass_sr_wwb_ptll;
      bool m_pass_sr_wwb_mll;
      bool m_pass_sr_wwc_ptll;
      bool m_pass_sr_wwc_mt2;

      bool m_pass_sr_zjets_num_l_jets;
      bool m_pass_sr_zjets_met_rel;
      bool m_pass_sr_zjets_lep1_pt;
      bool m_pass_sr_zjets_lep2_pt;
      bool m_pass_sr_zjets_mjj;
      bool m_pass_sr_zjets_mt2;

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
