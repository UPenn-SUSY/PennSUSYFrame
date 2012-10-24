// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_EventCleaningTool_h
#define SelectionTools_EventCleaningTool_h

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Event.h"

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class EventCleaningTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    EventCleaningTool( SCycleBase* parent
                     , const char* name = "EventCleaning"
                     );
    virtual ~EventCleaningTool();

    bool passFCALCleaning(Event* , const JetContainer&);
    bool passFCALCleaning(Event* , const std::vector<Jet*>&);

    bool passLARError(Event*);

    bool passIncompleteEvent(Event*);

    bool passTileError(Event*);

    bool passTileHotSpot(Event*, const JetContainer&);
    bool passTileHotSpot(Event*, const std::vector<Jet*>&);

  // --------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool inFCALProblemArea(float pt, float eta, float phi);
    bool checkFCALProblemRuns(Event*);
    bool inTileHotSpot(float eta, float phi);
    bool checkTileHotSpotRuns(Event*);

    double c_total_lumi;

    ClassDef(EventCleaningTool, 0);
  };
}

#endif
