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

#include "CommonTools/include/MllTool.h"

// =============================================================================
namespace SelectionTools
{
  // ===========================================================================
  class EventCleaningTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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

    bool passMllCut( FLAVOR_CHANNEL
                   , const std::vector<Electron*>&
                   , const std::vector<Muon*>&
                   );

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool inFCALProblemArea(float pt, float eta, float phi);
    bool checkFCALProblemRuns(Event*);
    bool inTileHotSpot(float eta, float phi);
    bool checkTileHotSpotRuns(Event*);

    double c_total_lumi;

    double c_mll_min;
    double c_mll_max;

    bool passCut(double test, double min, double max);

    ClassDef(EventCleaningTool, 0);
  };
}

#endif
