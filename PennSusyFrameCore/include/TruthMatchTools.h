#ifndef PennSusyFrame_TruthMatchTools_h
#define PennSusyFrame_TruthMatchTools_h

// =============================================================================
namespace PennSusyFrame
{
  class Event;
  class Electron;
  class Muon;
  class MCTruth;
}

class RecoTruthMatch;

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class TruthMatchTool
  {
    // -----------------------------------------------------------------------------
    public:
      TruthMatchTool();
      ~TruthMatchTool();

      void clear();
      void prep(const PennSusyFrame::MCTruth&);

    // -----------------------------------------------------------------------------
    private:
      RecoTruthMatch* m_truth_match;
  };
}

#endif
