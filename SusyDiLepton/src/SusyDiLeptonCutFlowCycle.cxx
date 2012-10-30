// $Id: CycleCreators.py 173 2010-05-12 15:49:33Z krasznaa $

// Local include(s):
#include "include/SusyDiLeptonCutFlowCycle.h"
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ParticleElementBuilder.h"

ClassImp( SusyDiLeptonCutFlowCycle );

// ============================================================================
SusyDiLeptonCutFlowCycle::SusyDiLeptonCutFlowCycle() :
  CycleBase(),
  m_event(NULL),
  m_met(NULL),
  m_trigger(NULL),
  m_trigger_vec(NULL),
  m_electron_d3pdobject(NULL),
  m_jet_d3pdobject(NULL),
  m_mcevt_d3pdobject(NULL),
  m_muon_d3pdobject(NULL),
  m_truth_d3pdobject(NULL),
  m_met_truth_d3pdobject(NULL),
  m_vertex_d3pdobject(NULL),
  m_electron_selection(NULL),
  m_jet_selection(NULL),
  m_muon_selection(NULL),
  m_object_cleaning(NULL),
  m_grl_tool(NULL),
  m_event_cleaning_tool(NULL),
  m_trigger_cut_tool(NULL)
{
  // = declare user defined properties =
  DeclareProperty("input_tree_name" , c_input_tree_name="presel");
  DeclareProperty("output_tree_name", c_output_tree_name="output");

  DeclareProperty("is_egamma_stream", c_is_egamma_stream=false);
  DeclareProperty("print_event_info", c_print_event_info=false);

  DeclareProperty("Met_prefix" , c_met_prefix="MET_Egamma10NoTau"    );
  DeclareProperty("Muon_prefix", c_muon_prefix="mu_staco_"           );
  DeclareProperty("Jet_prefix" , c_jet_prefix="jet_AntiKt4LCTopo_");

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  declareTools();
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::declareTools()
{
  DECLARE_TOOL(CommonTools::EgammaEnergyRescaleTool , "EgammaEnergyRescale" );
  DECLARE_TOOL(CommonTools::MuonMomentumSmearingTool, "MuonMomentumSmearing");
  DECLARE_TOOL(CommonTools::JetCalibTool            , "JetCalibration"      );

  DECLARE_TOOL(CommonTools::IsoCorrectionTool       , "Electron_IsoCorr"    );
  DECLARE_TOOL(CommonTools::IsoCorrectionTool       , "Muon_IsoCorr"        );
  DECLARE_TOOL(CommonTools::TLVTool                 , "tlv"                 );

  DECLARE_TOOL(SelectionTools::ElectronSelectionTool, "Electron_Selection");
  DECLARE_TOOL(SelectionTools::JetSelectionTool     , "Jet_Selection"     );
  DECLARE_TOOL(SelectionTools::MuonSelectionTool    , "Muon_Selection"    );

  DECLARE_TOOL(SelectionTools::GoodRunsListTool  , "GRL"            );
  DECLARE_TOOL(SelectionTools::EventCleaningTool , "Event_Cleaning" );
  DECLARE_TOOL(SelectionTools::ObjectCleaningTool, "Object_Cleaning");
  DECLARE_TOOL(SelectionTools::TriggerCutTool    , "Trigger_Cut"    );

  // TODO populate list of tools
}

// ----------------------------------------------------------------------------
SusyDiLeptonCutFlowCycle::~SusyDiLeptonCutFlowCycle()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::BeginCycleImp() throw( SError )
{
  // do nothing
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::EndCycleImp() throw( SError )
{
  // do nothing
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::BeginInputDataImp( const SInputData& ) throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonCutFlowCycle::eginInputData()"
           << SLogger::endmsg;

  // = initialize D3PD object readers =
  m_logger << DEBUG
           << "m_entry_number: "
           << m_entry_number
           << SLogger::endmsg;

  initD3PDReaders();
  getTools();
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::initD3PDReaders()
{
  m_event = new Event(m_entry_number, "", is_data());
  m_trigger = new Trigger(m_entry_number, "");
  m_trigger_vec = new TriggerVec(m_entry_number, "");
  m_met = new Met(m_entry_number, c_met_prefix.c_str(), is_data());

  m_vertex_d3pdobject =
      new D3PDReader::VertexD3PDObject(m_entry_number
                                      , "vx_"
                                      , is_data()
                                      );
  m_electron_d3pdobject =
      new D3PDReader::ElectronD3PDObject(m_entry_number
                                        , "el_"
                                        , is_data()
                                        );
  m_jet_d3pdobject =
      new D3PDReader::JetD3PDObject(m_entry_number
                                   , c_jet_prefix.c_str()
                                   , is_data()
                                   );
  m_muon_d3pdobject =
      new D3PDReader::MuonD3PDObject(m_entry_number
                                    , c_muon_prefix.c_str()
                                    , is_data()
                                    );

  // Some of these readers are only initialized for MC
  if (!is_data()) {
    m_mcevt_d3pdobject
        = new D3PDReader::MCEvtD3PDObject(m_entry_number);
    m_truth_d3pdobject
        = new D3PDReader::TruthD3PDObject(m_entry_number);
    m_met_truth_d3pdobject
        = new D3PDReader::TruthMETD3PDObject(m_entry_number);
  }
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::getTools()
{
  // Get helper tools required by containers
  GET_TOOL( egamma_energy_rescale
          , CommonTools::EgammaEnergyRescaleTool
          , "EgammaEnergyRescale"
          );
  GET_TOOL( muon_smearing
          , CommonTools::MuonMomentumSmearingTool
          , "MuonMomentumSmearing"
          );
  GET_TOOL( jet_calib
          , CommonTools::JetCalibTool
          , "JetCalibration"
          );

  // Initialize vertices
  m_vertices.init();

  // TLV tool
  GET_TOOL(tlv_tool, CommonTools::TLVTool, "tlv");
  tlv_tool->init(egamma_energy_rescale, muon_smearing, jet_calib);

  // Isolation correction tools
  GET_TOOL(el_iso_corr_tool, CommonTools::IsoCorrectionTool, "Electron_IsoCorr");
  GET_TOOL(mu_iso_corr_tool, CommonTools::IsoCorrectionTool, "Muon_IsoCorr"    );

  // Electron selection
  GET_TOOL( electron_selection
          , SelectionTools::ElectronSelectionTool
          , "Electron_Selection"
          );
  m_electron_selection = electron_selection;
  m_electrons.init(tlv_tool, el_iso_corr_tool);

  // Jet selection
  GET_TOOL( jet_selection
          , SelectionTools::JetSelectionTool
          , "Jet_Selection"
          );
  m_jet_selection = jet_selection;
  m_jets.init(tlv_tool);

  // Muon selection
  GET_TOOL( muon_selection
          , SelectionTools::MuonSelectionTool
          , "Muon_Selection"
          );
  m_muon_selection = muon_selection;
  m_muons.init(tlv_tool, mu_iso_corr_tool);

  // Object cleaning for overlap removal, etc.
  GET_TOOL( object_cleaning
          , SelectionTools::ObjectCleaningTool
          , "Object_Cleaning"
          );
  m_object_cleaning = object_cleaning;

  // GRL
  GET_TOOL( grl_tool
          , SelectionTools::GoodRunsListTool
          , "GRL"
          );
  m_grl_tool = grl_tool;

  // Event cleaning tool
  GET_TOOL( event_cleaning
          , SelectionTools::EventCleaningTool
          , "Event_Cleaning"
          );
  m_event_cleaning_tool = event_cleaning;

  GET_TOOL( trigger_cut
          , SelectionTools::TriggerCutTool
          , "Trigger_Cut"
          );
  m_trigger_cut_tool = trigger_cut;
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::EndInputDataImp( const SInputData& ) throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonCutFlowCycle::EndInputData()"
           << SLogger::endmsg;

  // = clean up pointers =
  delete m_event;
  delete m_trigger;
  delete m_trigger_vec;
  delete m_met;
  delete m_vertex_d3pdobject;
  delete m_electron_d3pdobject;
  delete m_jet_d3pdobject;
  delete m_muon_d3pdobject;

  if (!is_data()) {
    delete m_mcevt_d3pdobject;
    delete m_truth_d3pdobject;
    delete m_met_truth_d3pdobject;
  }
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::BeginMasterInputDataImp( const SInputData& ) throw( SError )
{
  // do nothing
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::EndMasterInputDataImp( const SInputData& /*id*/ ) throw( SError )
{
  m_logger << DEBUG
           << "EndMasterInputDataImp()"
           << SLogger::endmsg;

  // do nothing
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::BeginInputFileImp( const SInputData& ) throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonCutFlowCycle::BeginInputFile()"
           << SLogger::endmsg;

  // = get input trees from the d3pd objects =
  m_event->ReadFrom(                 GetInputTree(c_input_tree_name.c_str()));
  m_trigger->ReadFrom(               GetInputTree(c_input_tree_name.c_str()));
  m_trigger_vec->ReadFrom(           GetInputTree(c_input_tree_name.c_str()));
  m_met->ReadFrom(                   GetInputTree(c_input_tree_name.c_str()));
  m_vertex_d3pdobject->ReadFrom(     GetInputTree(c_input_tree_name.c_str()));
  m_electron_d3pdobject->ReadFrom(   GetInputTree(c_input_tree_name.c_str()));
  m_jet_d3pdobject->ReadFrom(        GetInputTree(c_input_tree_name.c_str()));
  m_muon_d3pdobject->ReadFrom(       GetInputTree(c_input_tree_name.c_str()));

  if (!is_data()){
    m_mcevt_d3pdobject->ReadFrom(    GetInputTree(c_input_tree_name.c_str()));
    m_truth_d3pdobject->ReadFrom(    GetInputTree(c_input_tree_name.c_str()));
    m_met_truth_d3pdobject->ReadFrom(GetInputTree(c_input_tree_name.c_str()));
  }
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::ExecuteEventImp( const SInputData&, Double_t ) throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonCutFlowCycle::ExecuteEvent()"
           << "\n\trun number = "   << m_event->RunNumber()
           << " -- event number = " << m_event->EventNumber()
           << SLogger::endmsg;

  // = Prep event by zeroing out old vent stuff
  prepEvent();

  getObjects();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::cout << "run number: " << m_event->RunNumber()
            << "\t--\tevent number: " << m_event->EventNumber()
            << "\n";

  runCutFlow();

  //
  // m_vertices.print(VERT_ALL);
  // m_electrons.print(EL_ALL, m_vertices);
  // m_muons.print(MU_ALL, m_vertices);
  // m_jets.print(JET_ALL);
  // m_electrons.print(EL_BASELINE, m_vertices);
  // m_vertices.print(VERT_GOOD);
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::runCutFlow()
{
  // Check GRL
  // TODO Check GRL
  if (m_grl_tool->passed(*m_event)) {
    // TODO flag event as failed GRL
    // TODO reject event if critical cut
  }

  // Check LAr error
  if (m_event_cleaning_tool->passLARError(m_event) == false) {
    // TODO flag event as failed LAr error
    // TODO reject event if critical cut
  }

  // Check Tile Error
  if (m_event_cleaning_tool->passTileError(m_event) == false) {
    // TODO flag event as failed tile error
    // TODO reject event if critical cut
  }

  // Check Tile hot spot
  if (m_event_cleaning_tool->passTileHotSpot(m_event, m_jets) == false) {
    // TODO flag event as failed tile hot spot
    // TODO reject event if critical cut
  }

  // Check jet cleaning
  if (m_jets.num(JET_BAD) > 0) {
    // TODO flag event as failing bad jet veto
    // TODO reject event if critical cut
  }

  // Check primary vertex
  if (m_vertices.firstGood(VERT_ALL) == false) {
    // TODO flag event as failing good vertex
    // TODO reject event if critical cut
  }

  // Check for bad muons
  if (m_muons.getMuons(MU_BAD).size() > 0) {
    // TODO flag event as failing bad mu veto
    // TODO reject event if critical cut
  }

  // Check for cosmic muons
  if (m_muons.getMuons(MU_COSMIC).size() > 0) {
    // TODO flag event as failing cosmic mu veto
    // TODO reject event if critical cut
  }

  // Check TTC veto
  // TODO Check TTC veto
  if (m_event_cleaning_tool->passIncompleteEvent(m_event) == false) {
    // TODO flag event as failed incomplete event
    // TODO reject event if critical cut
  }

  // Check for FCal region
  // TODO Check for FCal region
  if (m_event_cleaning_tool->passFCALCleaning(m_event, m_jets) == false) {
    // TODO flag event as failed FCAL cleaning
    // TODO reject event if critical cut
  }

  // Check for At least two leptons
  // TODO check for at least two leptons
  size_t num_good_leptons = m_electrons.num(EL_GOOD) + m_muons.num(MU_GOOD);
  if (num_good_leptons < 2) {
    // TODO flag event as failed >= 2 leptons
    // TODO reject event if critical cut
  }

  // Check for exactly two leptons
  // TODO check for exactly two leptons
  if (num_good_leptons != 2) {
    // TODO flag event as failed == 2 leptons
    // TODO reject event if critical cut
  }

  // Check for signal leptons
  // TODO check for signal leptons
  size_t num_signal_leptons = m_electrons.num(EL_SIGNAL) + m_muons.num(MU_SIGNAL);
  if (num_signal_leptons != 2) {
    // TODO flag event as failed == 2 signal leptons
    // TODO reject event if critical cut
  }

  // Check flavor channel for this event
  // TODO check flavor channel

  // Check for valid pt phase space
  // TODO check for pt phase space
  m_trigger_cut_tool->passedEEPhaseSpace( m_electrons.getElectrons(EL_GOOD)
                                        , m_muons.getMuons(MU_GOOD)
                                        );
  m_trigger_cut_tool->passedMMPhaseSpace( m_electrons.getElectrons(EL_GOOD)
                                        , m_muons.getMuons(MU_GOOD)
                                        );
  m_trigger_cut_tool->passedEMPhaseSpace( m_electrons.getElectrons(EL_GOOD)
                                        , m_muons.getMuons(MU_GOOD)
                                        );
  m_trigger_cut_tool->passedMEPhaseSpace( m_electrons.getElectrons(EL_GOOD)
                                        , m_muons.getMuons(MU_GOOD)
                                        );

  // Check trigger for this event
  // TODO check event level trigger
  m_trigger_cut_tool->passedEETriggerChannel( m_event
                                            , m_trigger
                                            );
  m_trigger_cut_tool->passedMMTriggerChannel( m_event
                                            , m_trigger
                                            );
  m_trigger_cut_tool->passedEMTriggerChannel( m_event
                                            , m_trigger
                                            );
  m_trigger_cut_tool->passedMETriggerChannel( m_event
                                            , m_trigger
                                            );

  // Check trigger matching
  // TODO check trigger matching
  m_trigger_cut_tool->passedEETriggerMatching( m_event
                                             , m_trigger_vec
                                             , m_electrons.getElectrons(EL_GOOD)
                                             , m_muons.getMuons(MU_GOOD)
                                             );
  m_trigger_cut_tool->passedMMTriggerMatching( m_event
                                             , m_trigger_vec
                                             , m_electrons.getElectrons(EL_GOOD)
                                             , m_muons.getMuons(MU_GOOD)
                                             );
  m_trigger_cut_tool->passedEMTriggerMatching( m_event
                                             , m_trigger_vec
                                             , m_electrons.getElectrons(EL_GOOD)
                                             , m_muons.getMuons(MU_GOOD)
                                             );
  m_trigger_cut_tool->passedMETriggerMatching( m_event
                                             , m_trigger_vec
                                             , m_electrons.getElectrons(EL_GOOD)
                                             , m_muons.getMuons(MU_GOOD)
                                             );

  // Check sign channel for this event
  // TODO check sign channel for this event
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::prepEvent()
{
  // set default values for constants, bools, and weights
  m_is_ee = false;
  m_is_mm = false;
  m_is_em = false;
  m_is_me = false;

  m_pass_event = true;
  m_pass_ee    = true;
  m_pass_mm    = true;
  m_pass_em    = true;
  m_pass_me    = true;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_electrons.clear();
  m_jets.clear();
  m_muons.clear();
  m_met->clear();
  m_vertices.clear();
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::getObjects()
{
  m_vertices.prepVertices(m_vertex_d3pdobject, is_data());

  m_electrons.prepElectrons(m_electron_d3pdobject);
  m_muons.prepMuons(m_muon_d3pdobject);
  m_jets.prepJets(m_jet_d3pdobject, m_event, m_vertices);

  // Get baseline objects
  m_electrons.setCollection( EL_BASELINE,
      m_electron_selection->getBaselineElectrons(m_electrons));

  m_muons.setCollection( MU_BASELINE,
      m_muon_selection->getBaselineMuons(m_muons));

  m_jets.setCollection( JET_BASELINE,
      m_jet_selection->getBaselineJets(m_jets));

  // Get bad/veto objects
  m_muons.setCollection( MU_BAD,
      m_muon_selection->getBadMuons(m_muons));

  m_muons.setCollection( MU_COSMIC,
      m_muon_selection->getCosmicMuons(m_muons));

  m_jets.setCollection( JET_BAD,
      m_jet_selection->getBadJets(m_jets));

  // do overlap removal to get good objects
  m_object_cleaning->SelectionTools::ObjectCleaningTool::fullObjectCleaning(
      m_electrons, m_muons, m_jets);

  // Get signal objects
  m_electrons.setCollection( EL_SIGNAL,
      m_electron_selection->getSignalElectrons(m_electrons));

  m_muons.setCollection( MU_SIGNAL,
      m_muon_selection->getSignalMuons(m_muons, m_vertices));

  m_jets.setCollection( JET_CENTRAL,
      m_jet_selection->getLJets(m_jets));

  m_jets.setCollection( JET_B,
      m_jet_selection->getBJets(m_jets));

  m_jets.setCollection( JET_FORWARD,
      m_jet_selection->getFJets(m_jets));

  // Prep met for this event
  m_met->prep(m_event, &m_electrons, &m_muons, &m_jets);
}
