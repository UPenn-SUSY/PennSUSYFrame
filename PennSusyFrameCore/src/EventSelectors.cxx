#include "PennSusyFrameCore/include/EventSelectors.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/ObjectContainers.h"

#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsList.h"
#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsListReader.h"
#include "RootCore/TileTripReader/TileTripReader/TTileTripReader.h"
#include "RootCore/SUSYTools/SUSYTools/HforToolD3PD.h"

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
  Root::TGoodRunsListReader grl_reader;
  grl_reader.AddXMLFile(m_grl_file_name);

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

// =============================================================================
bool PennSusyFrame::passPrimaryVertex(const PennSusyFrame::VertexContainer& vertices)
{
  // This is a bit of a hack

  // if there are no good vertices, we can stop here - fails the primary vertex cut
  size_t num_good_vertices = vertices.num(VERTEX_GOOD);
  if (num_good_vertices == 0) return false;

  // find the first vertex, and get all the good vertices in the event
  const PennSusyFrame::Vertex* first_vertex = vertices.getCollection(VERTEX_ALL)->at(0);
  const std::vector<PennSusyFrame::Vertex*>* good_vertices = vertices.getCollection(VERTEX_GOOD);

  // loop through all good vertices - if any of the good vertices match with the first vertex, the event passes the cut
  // Can probably shorten this to just check the first vertex in the good vertex list, but leave this way for now for safety
  for ( size_t good_vertex_it = 0
      ; good_vertex_it != num_good_vertices
      ; ++good_vertex_it
      ) {
    if (good_vertices->at(0) == first_vertex) return true;
  }

  // no first vertex was not good -- event fails cut
  return false;
}

// =============================================================================
PennSusyFrame::HFORTool::HFORTool()
{
  m_hfor_tool.setVerbosity(HforToolD3PD::ERROR);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::HFORTool::passHFOR(const PennSusyFrame::MCTruth& mc_truth)
{
  // get hfor_type from m_hfor_tool
  int hfor_type = m_hfor_tool.getDecision( mc_truth.getChannelNumber()
                                         , mc_truth.getN()
                                         , mc_truth.getPt()
                                         , mc_truth.getEta()
                                         , mc_truth.getPhi()
                                         , mc_truth.getM()
                                         , mc_truth.getPdgId()
                                         , mc_truth.getStatus()
                                         , mc_truth.getVxBarcode()
                                         , mc_truth.getParentIndex()
                                         , mc_truth.getChildIndex()
                                         , HforToolD3PD::DEFAULT
                                         );

  // fails HFOR cut if hfor_type == 4
  return (hfor_type != 4);
}

// =============================================================================
bool PennSusyFrame::passSherpaWWOverlapRemoval( const PennSusyFrame::Event&
                                              , const PennSusyFrame::MCTruth& mc_truth
                                              )
{
  unsigned int dsid = mc_truth.getChannelNumber();
  if (dsid == 126892) {
    int num_truth_objects = mc_truth.getN();
    for (int obj_itr = 0; obj_itr != num_truth_objects; ++obj_itr) {
      if (  abs(mc_truth.getPdgId()->at(obj_itr)) == 5
         && mc_truth.getStatus()->at(obj_itr) == 3
         ) {
        return false;
      }
    }
  }

  return true;
}

// =============================================================================
bool PennSusyFrame::passZOverlapRemoval(const PennSusyFrame::MCTruth& mc_truth)
{
  bool isSherpaZ = false;
  bool isZbb     = false;
  bool isZcc     = false;
  bool isZ       = false;

  unsigned int dsid = mc_truth.getChannelNumber();

  if (dsid >=147770 && dsid <=147772) isSherpaZ = true;
  if (dsid >=110805 && dsid <=110816) isZcc     = true;
  if (dsid >=110817 && dsid <=110828) isZbb     = true;
  if (dsid >=117640 && dsid <=117675) isZ       = true;

  if(isZcc || isZbb || isZ) {
    int ZpdgID=23;

    int term = mc_truth.getN();
    for (int i = 0; i < term; ++i) {
      if (  mc_truth.getPdgId()->at(i) == ZpdgID
         && mc_truth.getM()->at(i) < 60000
         )
        return false;
    }
  }

  if(isSherpaZ) {
    // TODO get tlv objects for truth leptons using truth matching tool
    // std::vector<TLorentzVector> truth_leptons = truth_match_tool->getHSLeptonsTLV();

    // if (truth_leptons.size() == 2) {
    //   double m_Z = (truth_leptons.at(0) + truth_leptons.at(1)).M();
    //   if (m_Z > 60000 || m_Z < 40000) return false;
    // }
  }

  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passSherpaZMassiveCBOverlapRemoval( const PennSusyFrame::MCTruth& mc_truth
                                                      , const PennSusyFrame::EventLevelQuantities& event_level_quantities
                                                      )
{
  unsigned int dsid = mc_truth.getChannelNumber();
  bool is_sherpa_z_massivecb = (  ( dsid >= 167749 && dsid <= 167757)
                               || ( dsid >= 167797 && dsid <= 167805)
                               || ( dsid >= 167809 && dsid <= 167817)
                               || ( dsid >= 167821 && dsid <= 167829)
                               || ( dsid >= 167833 && dsid <= 167841)
                               || ( dsid >= 180543 && dsid <= 180551)
                               );
  if (!is_sherpa_z_massivecb) return true;

  // massiveCB samples cover m_Z > 40 GeV
  if (event_level_quantities.getMll() < 40000) return false;

  // each massiveCB samples covers a different pt_z range
  float z_pt = event_level_quantities.getPtll()/1000.;
  if ( (dsid >= 167749 && dsid <= 167757) && (false       || z_pt > 40. ) ) return false;
  if ( (dsid >= 167797 && dsid <= 167805) && (z_pt < 70.  || z_pt > 140.) ) return false;
  if ( (dsid >= 167809 && dsid <= 167817) && (z_pt < 140. || z_pt > 280.) ) return false;
  if ( (dsid >= 167821 && dsid <= 167829) && (z_pt < 280. || z_pt > 500.) ) return false;
  if ( (dsid >= 167833 && dsid <= 167841) && (z_pt < 500. || false      ) ) return false;
  if ( (dsid >= 180543 && dsid <= 180551) && (z_pt < 40.  || z_pt > 70. ) ) return false;

  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passSherpaDYOverlapRemoval( const PennSusyFrame::MCTruth& mc_truth
                                              , const PennSusyFrame::EventLevelQuantities& event_level_quantities
                                              )
{
  unsigned int dsid = mc_truth.getChannelNumber();
  bool is_sherpa_dy = ( dsid >= 173041 && dsid <= 173046 );
  if (!is_sherpa_dy) return true;

  // sherpa dy samples each cover an m_Z range
  float m_z = event_level_quantities.getMll()/1000.;

  if (  ( (dsid == 173041) || (dsid == 173043) || (dsid == 173045) )
      && ( (m_z < 8.) || (m_z > 15.) )
      ) {
    return false;
  }
  if (  ( (dsid == 173042) || (dsid == 173044) || (dsid == 173046) )
     && ( (m_z < 15.) || (m_z > 40.) )
     ) {
    return false;
  }

  return true;
}
