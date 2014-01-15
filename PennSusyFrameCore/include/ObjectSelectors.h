#ifndef PennSusyFrame_ObjectSelectors
#define PennSusyFrame_ObjectSelectors

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
  // TODO move to icc
  template <class selector, class T>
    std::vector<T*> selectObjects(selector& sel, std::vector<T*> t)
    {
      std::vector<T*> selected_objects;

      size_t term = t.size();
      for (size_t it = 0; it != term; ++it) {
        if (sel.passAllCuts(t.at(it))) {
          selected_objects.push_back(t.at(it));
        }
      }

      return selected_objects;
    }

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
      // TODO move implementation of template to .icc file
      template <class T>
        bool passCut(T val, T min, T max, bool inclusive_boundaries = true)
      {
        if (min < 0 && max < 0) return true;
        if (min >= 0 && val < min) return false;
        if (max >= 0 && val > max) return false;

        if (!inclusive_boundaries) {
          if (min >= 0 && val == min) return false;
          if (max >= 0 && val == max) return false;
        }
        return true;
      }

      bool m_reversed;
  };
  
  // =============================================================================
  // = ElectronSelector
  // =============================================================================
  class ElectronSelector : public SelectorBase
  {
    public:
      ElectronSelector();

      void setPtCut(            double min = -1, double max = -1);
      void setEtaCut(           double min = -1, double max = -1);
      void setD0SignificanceCut(double min = -1, double max = -1);
      void setZ0SignThetaCut(   double min = -1, double max = -1);
      // TODO rename these functions
      void setPtIsoCut(         double min = -1, double max = -1);
      void setEtIsoCut(         double min = -1, double max = -1);

      using SelectorBase::passAllCuts;
      bool passAllCuts(const PennSusyFrame::Electron*);

    private:
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

      void setPtCut(            double min = -1, double max = -1);
      void setEtaCut(           double min = -1, double max = -1);
      void setBLayerHitsCut(    int    min = -1, int    max = -1);
      void setPixelHitsCut(     int    min = -1, int    max = -1);
      void setSctHitsCut(       int    min = -1, int    max = -1);
      void setSiHolesCut(       int    min = -1, int    max = -1);
      void setTrtEtaCut(        double min = -1, double max = -1);
      void setTrtHitsCut(       int    min = -1, int    max = -1);
      void setTrtOlFractionCut( double min = -1, double max = -1);
      void setD0SignificanceCut(double min = -1, double max = -1);
      void setZ0SignThetaCut(   double min = -1, double max = -1);
      void setD0Cut(            double min = -1, double max = -1);
      void setZ0Cut(            double min = -1, double max = -1);
      void setQOverPRatioCut(        double min = -1, double max = -1);
      // TODO rename this function
      void setPtIsoCut(         double min = -1, double max = -1);

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
  };

  // =============================================================================
  // = TauSelector
  // =============================================================================
  class TauSelector : public SelectorBase
  {
    public:
      TauSelector();

      void setPtCut(double min = -1, double max = -1);
      void setEtaCut(double min = -1, double max = -1);

      using SelectorBase::passAllCuts;
      bool passAllCuts(const PennSusyFrame::Tau*);

    private:
      double m_min_pt;
      double m_max_pt;

      double m_min_eta;
      double m_max_eta;
  };

  // =============================================================================
  // = JerSelector
  // =============================================================================
  class JetSelector : public SelectorBase
  {
    public:
      JetSelector();

      void setPtCut(double min = -1, double max = -1);
      void setEtaCut(double min = -1, double max = -1);
      void setJvfCut(double min = -1, double max = -1);
      void setJvfPtThresh(double min = -1, double max = -1);
      void setMV1Cut(double min = -1, double max = -1);
      void setIsBadJet(int val);

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

      int m_is_bad_jet;
  };

  // =============================================================================
  // = VertexSelector
  // =============================================================================
  class VertexSelector : public SelectorBase
  {
    public:
      VertexSelector();

      void setNumTracksCut(double min = -1, double max = -1);

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

      void fullObjectCleaning( const std::vector<PennSusyFrame::Electron*>&
                             , const std::vector<PennSusyFrame::Muon*>&
                             , const std::vector<PennSusyFrame::Tau*>&
                             , const std::vector<PennSusyFrame::Jet*>&
                             , const std::vector<PennSusyFrame::Jet*>&
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

// TODO move these template implementations to icc file
// -----------------------------------------------------------------------------
template <class T1, class T2>
  void PennSusyFrame::ObjectCleaning::overlapRemoveSecondList( const std::vector<T1*>& in_t1_list
                                                             , const std::vector<T2*>& in_t2_list
                                                             , std::vector<T2*>&       out_t2_list
                                                             , double                  cone_size
                                                             )
{
  // prep output electron vector
  out_t2_list.clear();
  out_t2_list.reserve(in_t1_list.size());

  // vector to flag objects to keep
  std::vector<bool> keep_object(in_t2_list.size(), true);

  // Loop over all combinations of objects, checking for overlap
  size_t t1_term = in_t1_list.size();
  size_t t2_term = in_t2_list.size();
  for (size_t it_1 = 0; it_1 != t1_term; ++it_1) {
    const TLorentzVector* tlv1 = in_t1_list.at(it_1)->getTlv();

    for (size_t it_2 = 0; it_2 != t2_term; ++it_2) {
      const TLorentzVector* tlv2 = in_t2_list.at(it_2)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, cone_size)) {
        keep_object.at(it_2) = false;
      }
    }
  }

  // add to output t2 objects flagged as "to keep"
  for (size_t it_2 = 0; it_2 != t2_term; ++it_2) {
    if (keep_object.at(it_2)) {
      out_t2_list.push_back(in_t2_list.at(it_2));
    }
  }
}

// -----------------------------------------------------------------------------
template <class T1>
  void PennSusyFrame::ObjectCleaning::overlapRemoveLowPt( const std::vector<T1*>& in_t1_list
                                                        , std::vector<T1*>&       out_t1_list
                                                        , double                  cone_size
                                                        )
{
  // prep output vector
  out_t1_list.clear();
  out_t1_list.reserve(in_t1_list.size());

  // vector to flag objects to keep
  std::vector<bool> keep_object(in_t1_list.size(), true);

  // Loop over all combinations of objects, checking for overlap
  size_t term = in_t1_list.size();
  for (size_t it_1 = 0; it_1 != term; ++it_1) {
    const TLorentzVector* tlv1 = in_t1_list.at(it_1)->getTlv();
    double pt1 = tlv1->Pt();

    for (size_t it_2 = 0; it_2 != it_1; ++it_2) {
      const TLorentzVector* tlv2 = in_t1_list.at(it_2)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, cone_size)) {
        if (pt1 >= tlv2->Pt())
          keep_object.at(it_2) = false;
        else
          keep_object.at(it_1) = false;
      }
    }
  }

  // add to output objects flagged as "to keep"
  for (size_t it = 0; it != term; ++it) {
    if (keep_object.at(it)) {
      out_t1_list.push_back(in_t1_list.at(it));
    }
  }
}

// -----------------------------------------------------------------------------
template <class T1, class T2>
  void PennSusyFrame::ObjectCleaning::overlapRemoveBoth( const std::vector<T1*>& in_t1_list
                                                       , const std::vector<T2*>& in_t2_list
                                                       , std::vector<T1*>&       out_t1_list
                                                       , std::vector<T2*>&       out_t2_list
                                                       , double                  cone_size
                                                       )
{
  // prep output vectors
  out_t1_list.clear();
  out_t2_list.clear();

  out_t1_list.reserve(in_t1_list.size());
  out_t2_list.reserve(in_t2_list.size());

  // vector to flag objects to keep
  std::vector<bool> keep_t1(in_t1_list.size(), true);
  std::vector<bool> keep_t2(in_t2_list.size(), true);

  // Loop over all combinations of objects, checking for overlap
  size_t t1_term = in_t1_list.size();
  size_t t2_term = in_t2_list.size();
  for (size_t it_1 = 0; it_1 != t1_term; ++it_1) {
    const TLorentzVector* tlv1 = in_t1_list.at(it_1)->getTlv();

    for (size_t it_2 = 0; it_2 != t2_term; ++it_2) {
      const TLorentzVector* tlv2 = in_t2_list.at(it_2)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, cone_size)) {
        keep_t1.at(it_1) = false;
        keep_t2.at(it_2) = false;
      }
    }
  }

  // add to output objects flagged as "to keep"
  for (size_t it_1 = 0; it_1 != t1_term; ++it_1) {
    if (keep_t1.at(it_1)) {
      out_t1_list.push_back(in_t1_list.at(it_1));
    }
  }
  for (size_t it_2 = 0; it_2 != t2_term; ++it_2) {
    if (keep_t2.at(it_2)) {
      out_t2_list.push_back(in_t2_list.at(it_2));
    }
  }
}

// -----------------------------------------------------------------------------
template <class T1>
  void PennSusyFrame::ObjectCleaning::overlapRemoveBoth( const std::vector<T1*>& in_t1_list
                                                       , std::vector<T1*>&       out_t1_list
                                                       , double                  cone_size
                                                       )
{
  // prep output vector
  out_t1_list.clear();
  out_t1_list.reserve(in_t1_list.size());

  // vector to flag objects to keep
  std::vector<bool> keep_object(in_t1_list.size(), true);

  // Loop over all combinations of objects, checking for overlap
  size_t term = in_t1_list.size();
  for (size_t it_1 = 0; it_1 != term; ++it_1) {
    const TLorentzVector* tlv1 = in_t1_list.at(it_1)->getTlv();

    for (size_t it_2 = 0; it_2 != it_1; ++it_2) {
      const TLorentzVector* tlv2 = in_t1_list.at(it_2)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, cone_size)) {
        keep_object.at(it_1) = false;
        keep_object.at(it_2) = false;
      }
    }
  }

  // add to output flagged as "to keep"
  for (size_t it = 0; it != term; ++it) {
    if (keep_object.at(it)) {
      out_t1_list.push_back(in_t1_list.at(it));
    }
  }
}

#endif
