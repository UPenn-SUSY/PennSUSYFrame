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
        if (sel.passSelection(t.at(it))) {
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

    protected:
      // TODO move implementation of template to .icc file
      template <class T>
        bool passCut(T val, T min, T max)
      {
        if (min < 0 && max < 0) return true;
        if (min >= 0 && val < min) return false;
        if (max >= 0 && val > max) return false;
        return true;
      }
  };
  
  // =============================================================================
  // = ElectronSelector
  // =============================================================================
  class ElectronSelector : public SelectorBase
  {
    public:
      ElectronSelector();

      void setPtCut(double min = -1, double max = -1);
      void setEtaCut(double min = -1, double max = -1);

      using SelectorBase::passSelection;
      bool passSelection(const PennSusyFrame::Electron*);

    private:
      double m_min_pt;
      double m_max_pt;

      double m_min_eta;
      double m_max_eta;
  };

  // =============================================================================
  // = MuonSelector
  // =============================================================================
  class MuonSelector : public SelectorBase
  {
    public:
      MuonSelector();

      void setPtCut(double min = -1, double max = -1);
      void setEtaCut(double min = -1, double max = -1);

      using SelectorBase::passSelection;
      bool passSelection(const PennSusyFrame::Muon*);

    private:
      double m_min_pt;
      double m_max_pt;

      double m_min_eta;
      double m_max_eta;
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

      using SelectorBase::passSelection;
      bool passSelection(const PennSusyFrame::Tau*);

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

      using SelectorBase::passSelection;
      bool passSelection(const PennSusyFrame::Jet*);

    private:
      double m_min_pt;
      double m_max_pt;

      double m_min_eta;
      double m_max_eta;
  };

  // =============================================================================
  // = VertexSelector
  // =============================================================================
  class VertexSelector : public SelectorBase
  {
    public:
      VertexSelector();

      void setNumTracksCut(double min = -1, double max = -1);

      using SelectorBase::passSelection;
      bool passSelection(const PennSusyFrame::Vertex*);

    private:
      int m_min_num_tracks;
      int m_max_num_tracks;
  };
}

#endif
