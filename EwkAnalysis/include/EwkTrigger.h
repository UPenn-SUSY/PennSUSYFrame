#ifndef PennSusyFrame_EwkTrigger_h
#define PennSusyFrame_EwkTrigger_h

#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/TriggerHelpers.h"

// =============================================================================
namespace PennSusyFrame
{
  class Event;
  class Trigger;
}

// =============================================================================
namespace PennSusyFrame
{
  // check trigger phase space
  TRIG_PHASE getTriggerPhase( const std::vector<PennSusyFrame::Electron*>*
                            , const std::vector<PennSusyFrame::Muon*>*
                            );
  PHASE_SPACE getPhaseSpaceFromTriggerPhase(TRIG_PHASE);

  // check event level trigger decision
  bool passAnyTrigger( const PennSusyFrame::Event&
                     , const PennSusyFrame::Trigger&
                     );
  bool passEETriggerChannel( const PennSusyFrame::Event&
                           , const PennSusyFrame::Trigger&
                           );
  bool passMMTriggerChannel( const PennSusyFrame::Event&
                           , const PennSusyFrame::Trigger&
                           );
  bool passEMTriggerChannel( const PennSusyFrame::Event&
                           , const PennSusyFrame::Trigger&
                           );
  bool passMETriggerChannel( const PennSusyFrame::Event&
                           , const PennSusyFrame::Trigger&
                           );

  // check trigger matching
  bool passTriggerMatching( const PennSusyFrame::Event&
                          , const PennSusyFrame::Trigger&
                          , const std::vector<PennSusyFrame::Electron*>*
                          , const std::vector<PennSusyFrame::Muon*>*
                          );

  bool passEETriggerMatching( const PennSusyFrame::Event&
                            , const PennSusyFrame::Trigger&
                            , const std::vector<PennSusyFrame::Electron*>*
                            );
  bool passMMTriggerMatching( const PennSusyFrame::Event&
                            , const PennSusyFrame::Trigger&
                            , const std::vector<PennSusyFrame::Muon*>*
                            );
  bool passEMTriggerMatching( const PennSusyFrame::Event&
                            , const PennSusyFrame::Trigger&
                            , const std::vector<PennSusyFrame::Electron*>*
                            , const std::vector<PennSusyFrame::Muon*>*
                            );
  bool passMETriggerMatching( const PennSusyFrame::Event&
                            , const PennSusyFrame::Trigger&
                            , const std::vector<PennSusyFrame::Electron*>*
                            , const std::vector<PennSusyFrame::Muon*>*
                            );
}

#endif
