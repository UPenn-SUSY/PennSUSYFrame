#ifndef PennSusyFrame_BMinusLTriggerScaleFactor_h
#define PennSusyFrame_BMinusLTriggerScaleFactor_h

#include <string>
#include <vector>

// =============================================================================
class LeptonTriggerSF;

namespace PennSusyFrame
{
  class Electron;
  class Muon;
}

// =============================================================================
class BMinusLTriggerScaleFactor
{
  // ---------------------------------------------------------------------------
  public:
    BMinusLTriggerScaleFactor();
    ~BMinusLTriggerScaleFactor();

    void init();

    double getSF( std::vector<PennSusyFrame::Electron*>*
                , std::vector<PennSusyFrame::Muon*>*
                );

  // ---------------------------------------------------------------------------
  private:
    std::string m_egamma_dir;
    std::string m_muon_dir;

    LeptonTriggerSF* m_lepton_trig_sf_tool;
};

#endif
