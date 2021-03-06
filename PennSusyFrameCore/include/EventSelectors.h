#ifndef PennSusyFrame_EventSelectors_h
#define PennSusyFrame_EventSelectors_h

#include <string>
#include <vector>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsList.h"
#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsListReader.h"
#include "RootCore/SUSYTools/SUSYTools/HforToolD3PD.h"


// =============================================================================
namespace PennSusyFrame
{
  class Event;
  class EventLevelQuantities;
  class Jet;
  class JetContainer;
  class VertexContainer;
  class MCTruth;
}

namespace Root
{
  class TTileTripReader;
}

namespace BCHTool
{
  class BCHCleaningToolRoot;
}

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class GrlTool
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      GrlTool();

      void init(const std::string&, bool do_grl = true);

      bool passEvent(const PennSusyFrame::Event&);
      bool passEvent(unsigned int run, unsigned int lb);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      bool m_do_grl;
      std::string m_grl_file_name;
      Root::TGoodRunsList m_grl;
  };

  // -----------------------------------------------------------------------------
  bool passIncompleteEvent(const PennSusyFrame::Event&);

  // -----------------------------------------------------------------------------
  bool passLarError(const PennSusyFrame::Event&);

  // -----------------------------------------------------------------------------
  bool passTileError(const PennSusyFrame::Event&);

  // =============================================================================
  class TileHotSpotTool
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      static bool passTileHotSpot(const PennSusyFrame::Event&, const PennSusyFrame::JetContainer&);
      static bool passTileHotSpot(const PennSusyFrame::Event&, const std::vector<PennSusyFrame::Jet*>*);

      static bool inTileHotSpotRun(const PennSusyFrame::Event&);
      static bool inTileHotSpotRun(int);

      static bool inTileHotSpot(const PennSusyFrame::Jet*);
      static bool inTileHotSpot(float, float);
  };

  // =============================================================================
  class TileTripTool
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      TileTripTool();
      ~TileTripTool();
      Root::TTileTripReader* getTileTripReaderTool();

      bool passTileTrip(const PennSusyFrame::Event&);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      std::string m_tile_trip_file;
      Root::TTileTripReader* m_tile_trip_reader;
  };

  // =============================================================================
  bool passPrimaryVertex(const PennSusyFrame::VertexContainer&);

  // =============================================================================
  class HFORTool
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      HFORTool();

      bool passHFOR(const PennSusyFrame::MCTruth&);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      HforToolD3PD m_hfor_tool;
  };

  // =============================================================================
  bool passSherpaWWOverlapRemoval(const PennSusyFrame::Event&, const PennSusyFrame::MCTruth&);
  bool passZOverlapRemoval(               const PennSusyFrame::MCTruth&);
  bool passSherpaZMassiveCBOverlapRemoval(const PennSusyFrame::MCTruth&, const PennSusyFrame::EventLevelQuantities&);
  bool passSherpaDYOverlapRemoval(        const PennSusyFrame::MCTruth&, const PennSusyFrame::EventLevelQuantities&);
  float findTruthLevelZPt(const PennSusyFrame::MCTruth&);

  // ===========================================================================
  class BCHCleaningTool
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      BCHCleaningTool();
      ~BCHCleaningTool();

      bool passBCHCleaning(const PennSusyFrame::JetContainer&, int, int);
      bool passBCHCleaning(const PennSusyFrame::Jet*, int, int);
      void init(const PennSusyFrame::Event&, PennSusyFrame::TileTripTool&);

      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      BCHTool::BCHCleaningToolRoot* m_bch_tool;
      std::string m_bch_file;
  };
}

// Include the implementation:
#ifndef __CINT__
#include "EventSelectors.icc"
#endif // __CINT__

#endif
