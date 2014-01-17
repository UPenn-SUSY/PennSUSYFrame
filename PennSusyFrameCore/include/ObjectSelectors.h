#ifndef PennSusyFrame_ObjectSelectors_h
#define PennSusyFrame_ObjectSelectors_h

// =============================================================================
#include <vector>
#include <iostream>

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/RescalerTools.h"

// =============================================================================
namespace PennSusyFrame
{
  class PhysicsObject;
  class Electron;
  class Muon;
  class Tau;
  class Jet;
  class Vertex;

  class ElectronContainer;
  class MuonContainer;
  class TauContainer;
  class JetContainer;
  class VertexContainer;
}

// ============================================================================
namespace PennSusyFrame
{
  template <class selector, class T>
    const std::vector<T*> selectObjects(selector& sel, std::vector<T*>* t);

  // =============================================================================
  // = SelectorBase
  // =============================================================================
  class SelectorBase
  {
    public:
      SelectorBase();

      virtual bool passSelection(const PennSusyFrame::PhysicsObject*);
      virtual bool passAllCuts(const PennSusyFrame::PhysicsObject*);

      void setReversedSelector(bool = true);

    protected:
      template <class T>
        bool passCut(T val, T min, T max, bool inclusive_boundaries = true);

      bool m_reversed;
  };

  // =============================================================================
  // = ElectronSelector
  // =============================================================================
  class ElectronSelector : public SelectorBase
  {
    public:
      ElectronSelector();

      // TODO move accessors to cxx file
      void setElectronQuality(ELECTRON_QUALITY_LEVEL val) { m_electron_quality = val; }
      void setPtCut(            double min = -1, double max = -1) { m_min_pt              = min; m_max_pt              = max; }
      void setEtaCut(           double min = -1, double max = -1) { m_min_eta             = min; m_max_eta             = max; }
      void setD0SignificanceCut(double min = -1, double max = -1) { m_min_d0_significance = min; m_max_d0_significance = max; }
      void setZ0SignThetaCut(   double min = -1, double max = -1) { m_min_z0_sin_theta    = min; m_max_z0_sin_theta    = max; }
      // TODO rename these functions
      void setPtIsoCut(         double min = -1, double max = -1) { m_min_ptcone = min; m_max_ptcone = max; }
      void setEtIsoCut(         double min = -1, double max = -1) { m_min_etcone = min; m_max_etcone = max; }

      using SelectorBase::passAllCuts;
      bool passAllCuts(const PennSusyFrame::Electron*);

    private:
      ELECTRON_QUALITY_LEVEL m_electron_quality;

      double m_min_pt;
      double m_max_pt;

      double m_min_eta;
      double m_max_eta;

      double m_min_d0_significance;
      double m_max_d0_significance;

      double m_min_z0_sin_theta;
      double m_max_z0_sin_theta;

      // TODO rename these variables
      double m_min_ptcone;
      double m_max_ptcone;

      double m_min_etcone;
      double m_max_etcone;
  };

  // =============================================================================
  // = MuonSelector
  // =============================================================================
  class MuonSelector : public SelectorBase
  {
    public:
      MuonSelector();

      // TODO move accessors to cxx file
      void setPtCut(            double min = -1, double max = -1) { m_min_pt              = min; m_max_pt              = max; }
      void setEtaCut(           double min = -1, double max = -1) { m_min_eta             = min; m_max_eta             = max; }
      void setBLayerHitsCut(    int    min = -1, int    max = -1) { m_min_b_layer_hits    = min; m_max_b_layer_hits    = max; }
      void setPixelHitsCut(     int    min = -1, int    max = -1) { m_min_pixel_hits      = min; m_max_pixel_hits      = max; }
      void setSctHitsCut(       int    min = -1, int    max = -1) { m_min_sct_hits        = min; m_max_sct_hits        = max; }
      void setSiHolesCut(       int    min = -1, int    max = -1) { m_min_si_holes        = min; m_max_si_holes        = max; }
      void setTrtEtaCut(        double min = -1, double max = -1) { m_min_trt_eta         = min; m_max_trt_eta         = max; }
      void setTrtHitsCut(       int    min = -1, int    max = -1) { m_min_trt_hits        = min; m_max_trt_hits        = max; }
      void setTrtOlFractionCut( double min = -1, double max = -1) { m_min_trt_ol_fraction = min; m_max_trt_ol_fraction = max; }
      void setD0SignificanceCut(double min = -1, double max = -1) { m_min_d0_significance = min; m_max_d0_significance = max; }
      void setZ0SignThetaCut(   double min = -1, double max = -1) { m_min_z0_sin_theta    = min; m_max_z0_sin_theta    = max; }
      void setD0Cut(            double min = -1, double max = -1) { m_min_d0              = min; m_max_d0              = max; }
      void setZ0Cut(            double min = -1, double max = -1) { m_min_z0              = min; m_max_z0              = max; }
      void setQOverPRatioCut(   double min = -1, double max = -1) { m_min_q_over_p_ratio  = min; m_max_q_over_p_ratio  = max; }
      // TODO rename this function
      void setPtIsoCut(         double min = -1, double max = -1) { m_min_ptcone = min; m_max_ptcone = max; }
      void setEtIsoCut(         double min = -1, double max = -1) { m_min_etcone = min; m_max_etcone = max; }

      using SelectorBase::passAllCuts;
      bool passAllCuts(const PennSusyFrame::Muon*);

    private:
      double m_min_pt;
      double m_max_pt;

      double m_min_eta;
      double m_max_eta;

      int m_min_b_layer_hits;
      int m_max_b_layer_hits;

      int m_min_pixel_hits;
      int m_max_pixel_hits;

      int m_min_sct_hits;
      int m_max_sct_hits;

      int m_min_si_holes;
      int m_max_si_holes;

      double m_min_trt_eta;
      double m_max_trt_eta;

      int m_min_trt_hits;
      int m_max_trt_hits;

      double m_min_trt_ol_fraction;
      double m_max_trt_ol_fraction;

      double m_min_d0_significance;
      double m_max_d0_significance;

      double m_min_z0_sin_theta;
      double m_max_z0_sin_theta;

      double m_min_d0;
      double m_max_d0;

      double m_min_z0;
      double m_max_z0;

      double m_min_q_over_p_ratio;
      double m_max_q_over_p_ratio;

      // TODO rename these variables
      double m_min_ptcone;
      double m_max_ptcone;

      // TODO rename these variables
      double m_min_etcone;
      double m_max_etcone;
  };

  // =============================================================================
  // = TauSelector
  // =============================================================================
  class TauSelector : public SelectorBase
  {
    public:
      TauSelector();

      // TODO move accessors to cxx file
      void setPtCut(double min = -1, double max = -1) { m_min_pt = min; m_max_pt = max; }
      void setEtaCut(double min = -1, double max = -1) { m_min_eta = min; m_max_eta = max; }
      void setJetBdtLevel(TAU_JET_BDT_LEVEL val) { m_jet_bdt_level = val; }
      void setEleBdtLevel(TAU_ELE_BDT_LEVEL val) { m_ele_bdt_level = val; }
      void setMuVetoLevel(TAU_MU_LEVEL val) { m_mu_level = val; }

      using SelectorBase::passAllCuts;
      bool passAllCuts(const PennSusyFrame::Tau*);

    private:
      double m_min_pt;
      double m_max_pt;

      double m_min_eta;
      double m_max_eta;

      TAU_JET_BDT_LEVEL m_jet_bdt_level;
      TAU_ELE_BDT_LEVEL m_ele_bdt_level;
      TAU_MU_LEVEL m_mu_level;
  };

  // =============================================================================
  // = JerSelector
  // =============================================================================
  class JetSelector : public SelectorBase
  {
    public:
      JetSelector();

      // TODO move accessors to cxx file
      void setPtCut(      double min = -1, double max = -1) { m_min_pt            = min; m_max_pt            = max; }
      void setEtaCut(     double min = -1, double max = -1) { m_min_eta           = min; m_max_eta           = max; }
      void setJvfCut(     double min = -1, double max = -1) { m_min_jvf           = min; m_max_jvf           = max; }
      void setJvfPtThresh(double min = -1, double max = -1) { m_min_jvf_pt_thresh = min; m_max_jvf_pt_thresh = max; }
      void setMV1Cut(     double min = -1, double max = -1) { m_min_mv1           = min; m_max_mv1           = max; }
      void setBchCorrCut( double min = -1, double max = -1) { m_min_bch_corr      = min; m_max_bch_corr      = max; }
      void setDphiMet(    double min = -1, double max = -1) { m_min_dphi_met      = min; m_max_dphi_met      = max; }
      void setIsBadJet(int val) { m_is_bad_jet = val; }

      using SelectorBase::passAllCuts;
      bool passAllCuts(const PennSusyFrame::Jet*);

    private:
      double m_min_pt;
      double m_max_pt;

      double m_min_eta;
      double m_max_eta;

      double m_min_jvf;
      double m_max_jvf;

      double m_min_jvf_pt_thresh;
      double m_max_jvf_pt_thresh;

      double m_min_mv1;
      double m_max_mv1;

      double m_min_bch_corr;
      double m_max_bch_corr;

      double m_min_dphi_met;
      double m_max_dphi_met;

      int m_is_bad_jet;
  };

  // =============================================================================
  // = VertexSelector
  // =============================================================================
  class VertexSelector : public SelectorBase
  {
    public:
      VertexSelector();

      // TODO move accessors to cxx file
      void setNumTracksCut(double min = -1, double max = -1) { m_min_num_tracks = min; m_max_num_tracks = max; }

      using SelectorBase::passAllCuts;
      bool passAllCuts(const PennSusyFrame::Vertex*);

    private:
      int m_min_num_tracks;
      int m_max_num_tracks;
  };

  // =============================================================================
  // = Object cleaning
  // =============================================================================
  class ObjectCleaning
  {
    public:
      ObjectCleaning();

      void fullObjectCleaning( PennSusyFrame::ElectronContainer&
                             , PennSusyFrame::MuonContainer&
                             , PennSusyFrame::TauContainer&
                             , PennSusyFrame::JetContainer&
                             );

      void fullObjectCleaning( const std::vector<PennSusyFrame::Electron*>*
                             , const std::vector<PennSusyFrame::Muon*>*
                             , const std::vector<PennSusyFrame::Tau*>*
                             , const std::vector<PennSusyFrame::Jet*>*
                             , const std::vector<PennSusyFrame::Jet*>*
                             , std::vector<PennSusyFrame::Electron*>&
                             , std::vector<PennSusyFrame::Muon*>&
                             , std::vector<PennSusyFrame::Tau*>&
                             , std::vector<PennSusyFrame::Jet*>&
                             , std::vector<PennSusyFrame::Jet*>&
                             );

      void eeOverlapRemoval( const std::vector<PennSusyFrame::Electron*>&
                           , std::vector<PennSusyFrame::Electron*>&
                           );
      void ejOverlapRemoval( const std::vector<PennSusyFrame::Electron*>&
                           , const std::vector<PennSusyFrame::Jet*>&
                           , std::vector<PennSusyFrame::Jet*>&
                           );
      void etOverlapRemoval( const std::vector<PennSusyFrame::Electron*>&
                           , const std::vector<PennSusyFrame::Tau*>&
                           , std::vector<PennSusyFrame::Tau*>&
                           );
      void mtOverlapRemoval( const std::vector<PennSusyFrame::Muon*>&
                           , const std::vector<PennSusyFrame::Tau*>&
                           , std::vector<PennSusyFrame::Tau*>&
                           );
      void tjOverlapRemoval( const std::vector<PennSusyFrame::Tau*>&
                           , const std::vector<PennSusyFrame::Jet*>&
                           , std::vector<PennSusyFrame::Jet*>&
                           );
      void jeOverlapRemoval( const std::vector<PennSusyFrame::Jet*>&
                           , const std::vector<PennSusyFrame::Electron*>&
                           , std::vector<PennSusyFrame::Electron*>&
                           );
      void jmOverlapRemoval( const std::vector<PennSusyFrame::Jet*>&
                           , const std::vector<PennSusyFrame::Muon*>&
                           , std::vector<PennSusyFrame::Muon*>&
                           );
      void emOverlapRemoval( const std::vector<PennSusyFrame::Electron*>&
                           , const std::vector<PennSusyFrame::Muon*>&
                           , std::vector<PennSusyFrame::Electron*>&
                           , std::vector<PennSusyFrame::Muon*>&
                           );
      void mmOverlapRemoval( const std::vector<PennSusyFrame::Muon*>&
                           , std::vector<PennSusyFrame::Muon*>&
                           );

      void sfosMllOverlapRemoval( const std::vector<PennSusyFrame::Electron*>&
                                , const std::vector<PennSusyFrame::Muon*>&
                                , std::vector<PennSusyFrame::Electron*>&
                                , std::vector<PennSusyFrame::Muon*>&
                                );

      static bool overlap( const TLorentzVector*
                         , const TLorentzVector*
                         , double thresh
                         );

    private:
      double m_ee_cone_size;
      double m_ej_cone_size;
      double m_et_cone_size;
      double m_mt_cone_size;
      double m_je_cone_size;
      double m_jm_cone_size;
      double m_em_cone_size;
      double m_mm_cone_size;
      double m_tj_cone_size;
      double m_sfos_mll_min;


      template <class T1, class T2>
        void overlapRemoveSecondList( const std::vector<T1*>&
                                    , const std::vector<T2*>&
                                    , std::vector<T2*>&
                                    , double
                                    );
      template <class T1>
        void overlapRemoveLowPt( const std::vector<T1*>&
                               , std::vector<T1*>&
                               , double
                               );
      template <class T1, class T2>
        void overlapRemoveBoth( const std::vector<T1*>&
                              , const std::vector<T2*>&
                              , std::vector<T1*>&
                              , std::vector<T2*>&
                              , double
                              );
      template <class T1>
        void overlapRemoveBoth( const std::vector<T1*>&
                              , std::vector<T1*>&
                              , double
                              );

  };
  
}

// Include the implementation:
#ifndef __CINT__
#include "ObjectSelectors.icc"
#endif // __CINT__

#endif
