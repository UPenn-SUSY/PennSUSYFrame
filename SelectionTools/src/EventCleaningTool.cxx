#include "SelectionTools/include/EventCleaningTool.h"

#include <vector>

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "CommonTools/include/MllTool.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

#include "TileTripReader/TTileTripReader.h"


// -----------------------------------------------------------------------------
SelectionTools::EventCleaningTool::EventCleaningTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
                                         , m_tile_trip_reader(NULL)
{
  DeclareProperty("total_lumi", c_total_lumi = 0);

  DeclareProperty("min_mll", c_mll_min = 20000.);
  DeclareProperty("max_mll", c_mll_max = -1);

  DeclareProperty( "tile_trip_file"
                 , c_tile_trip_file = "${ROOTCOREDIR}/../TileTripReader/data/CompleteTripList_2011-2012.root");
}

// -----------------------------------------------------------------------------
SelectionTools::EventCleaningTool::~EventCleaningTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SelectionTools::EventCleaningTool::BeginInputData(const SInputData&)
{
  if (m_tile_trip_reader != NULL) {
    delete m_tile_trip_reader;
    m_tile_trip_reader = NULL;
  }

  m_tile_trip_reader = new Root::TTileTripReader("myTripReader");
  m_tile_trip_reader->setTripFile(c_tile_trip_file.c_str());
}


// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passFCALCleaning(
    Event* event, const JetContainer& jets)
{
  return passFCALCleaning(event, jets.getJets(JET_ALL));
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passFCALCleaning(
    Event* event, const std::vector<Jet*>& jets)
{
  // first check run number and data
  // TODO: Implement MC for fraction of events if we swtich to that
  if (!checkFCALProblemRuns(event)) return true;
  bool passed_cut = true;

  size_t n_jets = jets.size();
  for (size_t jet_it=0; jet_it != n_jets && passed_cut; ++jet_it)
  {
    if (inFCALProblemArea( jets.at(jet_it)->getTlv().Pt()
                         , jets.at(jet_it)->getTlv().Eta()
                         , jets.at(jet_it)->getTlv().Phi()
                         )
       )
    {
      passed_cut = false;
      break;
    }
  }
  return passed_cut;
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passLARError(Event* event)
{
  m_logger << DEBUG
           << "SelectionTools::EventCleaningTool::passedLARError()"
           << SLogger::endmsg;

  // Only check for LAr error in data
  //   if (is_data() && event->larError()) return false;
  // Changing to new recommendation of reject LarError =2, not LarError>0
  //   per Guilliame
  if (is_data() && event->larError()==2) return false;

  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passIncompleteEvent(Event* event)
{
  m_logger << DEBUG
           << "SelectionTools::EventCleaningTool::passedIncompleteEvent()"
           << SLogger::endmsg;

  bool passed_cut = true;

  if ((event->coreFlags()&0x40000) != 0)
    {
      passed_cut = false; // This is an incomplete event remove from analysis }
      m_logger << DEBUG
               << "SelectionTools::IncompleteEventCutTool Failed"
               << SLogger::endmsg;
    }
  return passed_cut;
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passTileError(Event* event)
{
  m_logger << DEBUG
           << "SelectionTools::EventCleaningTool::passedTileError()"
           << SLogger::endmsg;

  // Changing to new recommendation of reject TileError =2, not TileError>0 per
  //   Guilliame
  if (is_data() && event->tileError()==2) return false;
  return true;

}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passTileHotSpot(
    Event* event, const JetContainer& jets)
{
  return passTileHotSpot(event, jets.getJets(JET_ALL));
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passTileHotSpot(Event* event,
              const std::vector<Jet*>& jets
              )
{
  // first check run number
  if (!checkTileHotSpotRuns(event)) return true;
  bool passed_cut = true;

  size_t n_jets = jets.size();

  for (size_t jet_it=0; jet_it != n_jets && passed_cut; ++jet_it)
    {
      if (inTileHotSpot(jets.at(jet_it)->eta(),jets.at(jet_it)->phi()))
        {
          if (  jets.at(jet_it)->fracSamplingMax()>0.6
             && jets.at(jet_it)->SamplingMax()==13
             )
            passed_cut=false;
        }
    }
  return passed_cut;
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passTileTrip(const Event* event)
{
  // check for tile trip. true: good event  false: bad event
  bool pass_tile_trip = m_tile_trip_reader->checkEvent( event->RunNumber()
                                                      , event->lbn()
                                                      , event->EventNumber()
                                                      );
  // If MC, always return true.  If data, check that the event passed tile trip
  return (!is_data() || pass_tile_trip);
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passMllCut(Event* event)
{
  double mll = event->getMll();
  return passCut(mll, c_mll_min, c_mll_max);
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passMllCut( FLAVOR_CHANNEL flavor,
    const std::vector<Electron*>& el, const std::vector<Muon*>& mu)
{
  double mll = CommonTools::MllTool::getMll(flavor, el, mu);
  return passCut(mll, c_mll_min, c_mll_max);
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::checkFCALProblemRuns(Event* event)
{
  return (  is_data()
         && (  event->RunNumber() >= 206248
            && event->RunNumber() <= 207332
            )
         );
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::inFCALProblemArea(
    float pt, float eta, float phi)
{
  // check if object is in Hot Spot

  if (pt < 20000.) return false;
  if (fabs(eta)<3.2) return false;
  if (phi < 1.6 || phi > 3.1) return false;
  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::checkTileHotSpotRuns(Event* event)
{
  return (  is_data()
         && (  event->RunNumber() >= 202660
            && event->RunNumber() <= 203027
            )
         );
}

// -----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::inTileHotSpot(float eta, float phi)
{
  // check if object is in Hot Spot

  if (eta < -0.2 || eta > 0.1) return false;
  if (phi < 2.65 || phi > 2.75) return false;

  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::EventCleaningTool::passCut( double test
                                               , double min
                                               , double max
                                               )
{
  // if no test, return true
  if (min < 0 && max < 0) return true;

  if (min >= 0 && test < min) return false;
  if (max >= 0 && test > max) return false;

  // passed test
  return true;
}
