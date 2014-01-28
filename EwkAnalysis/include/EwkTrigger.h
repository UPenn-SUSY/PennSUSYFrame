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
  TRIG_PHASE getPhaseSpace( const std::vector<PennSusyFrame::Electron*>*
                          , const std::vector<PennSusyFrame::Muon*>*
                          );

  // check event level trigger decision
  bool passAnyTrigger( const PennSusyFrame::Event&
                     , const PennSusyFrame::Trigger&
                     );
  bool passedEETriggerChannel( const PennSusyFrame::Event&
                             , const PennSusyFrame::Trigger&
                             );
  bool passedMMTriggerChannel( const PennSusyFrame::Event&
                             , const PennSusyFrame::Trigger&
                             );
  bool passedEMTriggerChannel( const PennSusyFrame::Event&
                             , const PennSusyFrame::Trigger&
                             );
  bool passedMETriggerChannel( const PennSusyFrame::Event&
                             , const PennSusyFrame::Trigger&
                             );

  // check trigger matching
  bool passedEETriggerMatching( const PennSusyFrame::Event&
                              , const PennSusyFrame::Trigger&
                              , const std::vector<PennSusyFrame::Electron*>*
                              , const std::vector<PennSusyFrame::Muon*>*
                              );
  bool passedMMTriggerMatching( const PennSusyFrame::Event&
                              , const PennSusyFrame::Trigger&
                              , const std::vector<PennSusyFrame::Electron*>*
                              , const std::vector<PennSusyFrame::Muon*>*
                              );
  bool passedEMTriggerMatching( const PennSusyFrame::Event&
                              , const PennSusyFrame::Trigger&
                              , const std::vector<PennSusyFrame::Electron*>*
                              , const std::vector<PennSusyFrame::Muon*>*
                              );
  bool passedMETriggerMatching( const PennSusyFrame::Event&
                              , const PennSusyFrame::Trigger&
                              , const std::vector<PennSusyFrame::Electron*>*
                              , const std::vector<PennSusyFrame::Muon*>*
                              );
}

#endif
