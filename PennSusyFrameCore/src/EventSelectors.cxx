#include "PennSusyFrameCore/include/EventSelectors.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/ObjectContainers.h"

#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsList.h"
#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsListReader.h"
#include "RootCore/TileTripReader/TileTripReader/TTileTripReader.h"

#include <vector>

// =============================================================================
PennSusyFrame::GrlTool::GrlTool() : m_do_grl(true)
                                  , m_grl_file_name("")
{}

void PennSusyFrame::GrlTool::init(const std::string& grl_file_name, bool do_grl)
{
  m_do_grl = do_grl;
  if (!m_do_grl) return;

  m_grl_file_name = grl_file_name;
  Root::TGoodRunsListReader grl_reader(m_grl_file_name.c_str());

  if (!grl_reader.Interpret()) {
    std::cout << "ERROR!!! Good Runs List could not be interpreted: "
              << m_grl_file_name << "\n";
    // TODO throw exception
  }

  m_grl = grl_reader.GetMergedGoodRunsList();
  m_grl.SetName("GoodRunsList");
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::GrlTool::passEvent(const PennSusyFrame::Event& event)
{
  return passEvent(event.getRunNumber(), event.getLumiBlock());
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::GrlTool::passEvent(unsigned int run, unsigned int lb)
{
  if (!m_do_grl) return true;

  if(m_grl.HasRunLumiBlock(run, lb)) return true;
  return false;
}

// =============================================================================
bool PennSusyFrame::passIncompleteEvent(const PennSusyFrame::Event& event)
{
  if ((event.getCoreFlags()&0x40000) != 0) return false;
  return true;
}

// =============================================================================
bool PennSusyFrame::passLarError(const PennSusyFrame::Event& event)
{
  if (event.getLarError() == 2) return false;
  return true;
}

// =============================================================================
bool PennSusyFrame::passTileError(const PennSusyFrame::Event& event)
{
  if (event.getTileError() == 2) return false;
  return true;
}

// =============================================================================
bool PennSusyFrame::TileHotSpotTool::passTileHotSpot( const PennSusyFrame::Event& event
                                                    , const PennSusyFrame::JetContainer& jets
                                                    )
{
  return passTileHotSpot(event, jets.getCollection(JET_ALL));
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TileHotSpotTool::passTileHotSpot( const PennSusyFrame::Event& event
                                                    , const std::vector<PennSusyFrame::Jet*>* jets
                                                    )
{
  if (!inTileHotSpotRun(event)) return true;

  size_t n_jets = jets->size();

  for (size_t jet_it = 0; jet_it != n_jets; ++jet_it) {
    if (inTileHotSpot(jets->at(jet_it))) {
      if (  jets->at(jet_it)->getFracSamplingMax() > 0.6
         && jets->at(jet_it)->getSamplingMax() == 13
         ) {
        return false;
      }
    }
  }
  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TileHotSpotTool::inTileHotSpotRun(const PennSusyFrame::Event& event)
{
  return inTileHotSpotRun(event.getRunNumber());
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TileHotSpotTool::inTileHotSpotRun(int run_num)
{
  return (  run_num >= 202660
         && run_num <= 203027
         );
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TileHotSpotTool::inTileHotSpot(const PennSusyFrame::Jet* jet)
{
  return inTileHotSpot(jet->getEta(), jet->getPhi());
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TileHotSpotTool::inTileHotSpot(float eta, float phi)
{
  if (eta < -0.20 || eta > +0.10) return false;
  if (phi < +2.65 || phi > +2.75) return false;
  return true;
}

// =============================================================================
PennSusyFrame::TileTripTool::TileTripTool() : m_tile_trip_reader(0)
{
  m_tile_trip_file = "${ROOTCOREDIR}/../TileTripReader/data/CompleteTripList_2011-2012.root"; 
  m_tile_trip_reader = new Root::TTileTripReader("myTripReader");
  m_tile_trip_reader->setTripFile(m_tile_trip_file.c_str());
}

// -----------------------------------------------------------------------------
PennSusyFrame::TileTripTool::~TileTripTool()
{
  if (m_tile_trip_reader) delete m_tile_trip_reader;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TileTripTool::passTileTrip(const PennSusyFrame::Event& event)
{
  return m_tile_trip_reader->checkEvent( event.getRunNumber()
                                       , event.getLumiBlock()
                                       , event.getEventNumber()
                                       );
}
