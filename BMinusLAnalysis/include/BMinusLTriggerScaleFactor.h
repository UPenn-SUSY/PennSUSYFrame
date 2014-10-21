#ifndef PennSusyFrame_BMinusLTriggerScaleFactor_h
#define PennSusyFrame_BMinusLTriggerScaleFactor_h

#include <string>
#include <vector>

// =============================================================================
class LeptonTriggerSF;

namespace PennSusyFrame
{
  class Event;
  class Electron;
  class Muon;
  class PileUpScaleFactorTool;
}

// =============================================================================
class BMinusLTriggerScaleFactor
{
  // ---------------------------------------------------------------------------
  public:
    BMinusLTriggerScaleFactor();
    ~BMinusLTriggerScaleFactor();

    void init();

    double getSF( const PennSusyFrame::Event
                , PennSusyFrame::PileUpScaleFactorTool&
                , const std::vector<PennSusyFrame::Electron*>*
                , const std::vector<PennSusyFrame::Muon*>*
                );

  // ---------------------------------------------------------------------------
  private:
    std::string m_egamma_dir;
    std::string m_muon_dir;

    LeptonTriggerSF* m_lepton_trig_sf_tool;
};

#endif
