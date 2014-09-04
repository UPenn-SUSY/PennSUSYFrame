#include "PennSusyFrameCore/include/EventSelectors.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/ObjectContainers.h"

#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsList.h"
#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsListReader.h"
#include "RootCore/SUSYTools/SUSYTools/HforToolD3PD.h"
#include "RootCore/BCHCleaningTool/BCHCleaningTool/BCHCleaningToolRoot.h"
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
  m_tile_trip_file =" ${ROOTCOREDIR}/../TileTripReader/data/CompleteTripList_2011-2012.root"; 
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
// -----------------------------------------------------------------------------
Root::TTileTripReader* PennSusyFrame::TileTripTool::getTileTripReaderTool()
{
  return m_tile_trip_reader;
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
PennSusyFrame::BCHCleaningTool::BCHCleaningTool() : m_bch_tool(0)
{

}
// -----------------------------------------------------------------------------
PennSusyFrame::BCHCleaningTool::~BCHCleaningTool()
{
  if (m_bch_tool) delete m_bch_tool;
}
// -----------------------------------------------------------------------------
bool PennSusyFrame::BCHCleaningTool::passBCHCleaning(const PennSusyFrame::JetContainer& jets, int run_number, int lumi_block)
{
 
  bool pass_cleaning = true;

  //compute the cleaning;
  //Loop through the Jets and check each...if one fails, reject the event

  const std::vector<PennSusyFrame::Jet*>* jet_good = jets.getCollection(JET_GOOD);
  
  size_t n_jets = jet_good->size();
  for (size_t jet_it = 0; jet_it != n_jets; ++jet_it) {
    pass_cleaning = pass_cleaning && passBCHCleaning(jet_good->at(jet_it), run_number, lumi_block);
    if(!pass_cleaning) break;
      
  }
  
  return pass_cleaning;  
}
// -----------------------------------------------------------------------------
bool PennSusyFrame::BCHCleaningTool::passBCHCleaning(const PennSusyFrame::Jet* jet, int run_number, int lumi_block)
{
  //std::cout<<"bch_jet: "<<jet->getBchCorr()<<" bch_cell: "<<jet->getBchCorrCell()<<std::endl;

  // std::cout<<"run_number: "<<run_number<<" lumi_block: "<<lumi_block<<" eta: "<<jet->getEta()<<" phi: "<<jet->getPhi()<<" pt: "<<jet->getPt()<<std::endl;

  bool pass = !(m_bch_tool->IsBadTightBCH(run_number, lumi_block, jet->getEta(), jet->getPhi(), 
					  jet->getBchCorrCell(), jet->getEmf(), jet->getPt()));

  return pass;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BCHCleaningTool::init(const PennSusyFrame::Event& event, PennSusyFrame::TileTripTool& tile_trip)
{
  //initialize bch tool
  
  m_bch_tool = new BCHTool::BCHCleaningToolRoot();

  m_bch_file = " ${ROOTCOREDIR}/../BCHCleaningTool/share/FractionsRejectedJetsMC.root";

  Root::TTileTripReader* tile_trip_root_tool = tile_trip.getTileTripReaderTool();
 
  m_bch_tool->InitializeTool(event.getIsData(), tile_trip_root_tool, m_bch_file);

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
  // check sample dsid and skip if not sherpa Z**MassiveCBPt0 sample
  unsigned int dsid = mc_truth.getChannelNumber();
  bool is_sherpa_z_massivecb = (dsid >= 167749 && dsid <= 167757);
  if (!is_sherpa_z_massivecb) return true;

  // each massiveCB samples covers a different pt_z range
  float z_pt = findTruthLevelZPt(mc_truth)/1000.;
  if ( dsid >= 167749 && dsid <= 167757 && z_pt > 40. ) return false;

  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passSherpaDYOverlapRemoval( const PennSusyFrame::MCTruth& mc_truth
                                              , const PennSusyFrame::EventLevelQuantities& event_level_quantities
                                              )
{
  // TODO remove this function and calls to it
  return true;

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

// -----------------------------------------------------------------------------
// TODO move to calculators
float PennSusyFrame::findTruthLevelZPt(const PennSusyFrame::MCTruth& mc_truth)
{
  // only do this for sherpa Z or sherpa dy samples
  unsigned int dsid = mc_truth.getChannelNumber();
  bool is_sherpa_z_massivecb = (  ( dsid >= 167749 && dsid <= 167757)
                               || ( dsid >= 167797 && dsid <= 167805)
                               || ( dsid >= 167809 && dsid <= 167817)
                               || ( dsid >= 167821 && dsid <= 167829)
                               || ( dsid >= 167833 && dsid <= 167841)
                               || ( dsid >= 180543 && dsid <= 180551)
                               || ( dsid >= 173041 && dsid <= 173046)
                               );
  if (!is_sherpa_z_massivecb) return -1;

  // vector to hold lepton daughters of the Z
  std::vector<unsigned int> daughter_l_index;

  // loop through objects in the truth record
  unsigned int num_mc_truth_objects = mc_truth.getN();
  for (unsigned int mc_it = 0; mc_it != num_mc_truth_objects; ++mc_it) {
    // get the pdgid of this objects -- skip if not a lepton
    int this_pdgid = mc_truth.getPdgId()->at(mc_it);
    if (  fabs(this_pdgid) != 11
       && fabs(this_pdgid) != 13
       && fabs(this_pdgid) != 15
       ) {
      continue;
    }

    // get the number of parents of this object
    size_t num_parents = mc_truth.getParentIndex()->at(mc_it).size();
    if (num_parents == 0) continue;

    // look at the parents -- if the parent is a lepton, or something > 25, the
    // parent of this lepton is probably not a Z
    bool from_z = true;
    for (size_t parent_it = 0; parent_it != num_parents; ++parent_it) {
      int this_parent_index = mc_truth.getParentIndex()->at(mc_it).at(parent_it);
      int this_parent_pdgid = ( this_parent_index >= 0
                              ? mc_truth.getPdgId()->at(this_parent_index)
                              : -1
                              );
      if (  fabs(this_parent_pdgid) == 11
         || fabs(this_parent_pdgid) == 13
         || fabs(this_parent_pdgid) == 15
         || fabs(this_parent_pdgid) >  25
         ) {
        // if we found a parent that isn't a lepton or pdgid > 25, we assume we
        // found a lepton from the Z, and can stop :-)
        from_z = false;
        break;
      }
    }

    // if from the z, store the index of the lepton
    if (from_z) {
      daughter_l_index.push_back(mc_it);
    }
  }

  // if we found two daughter leptons, calculate and return the ptll
  if (daughter_l_index.size() == 2) {
    TLorentzVector tlv_0;
    TLorentzVector tlv_1;

    tlv_0.SetPtEtaPhiM( mc_truth.getPt()->at( daughter_l_index.at(0))
                      , mc_truth.getEta()->at(daughter_l_index.at(0))
                      , mc_truth.getPhi()->at(daughter_l_index.at(0))
                      , mc_truth.getM()->at(  daughter_l_index.at(0))
                      );
    tlv_1.SetPtEtaPhiM( mc_truth.getPt()->at( daughter_l_index.at(1))
                      , mc_truth.getEta()->at(daughter_l_index.at(1))
                      , mc_truth.getPhi()->at(daughter_l_index.at(1))
                      , mc_truth.getM()->at(  daughter_l_index.at(1))
                      );

    return (tlv_0 + tlv_1).Pt();
  }

  // std::cout << "num leptons from z: " << daughter_l_index.size() << "\n";
  if (daughter_l_index.size() != 2) {
    std::cout << "WARNING!!! Number of leptons from Z is not 2!!! -- dsid: " << dsid << "\n";
  }
  // std::cout << "\n\n";

  return 0;
}
