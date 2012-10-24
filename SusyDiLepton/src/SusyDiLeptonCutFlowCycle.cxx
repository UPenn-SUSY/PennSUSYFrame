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
  m_electron_d3pdobject(NULL),
  m_jet_d3pdobject(NULL),
  m_mcevt_d3pdobject(NULL),
  m_muon_d3pdobject(NULL),
  m_trigger_d3pdobject(NULL),
  m_trigger_vec_d3pdobject(NULL),
  m_truth_d3pdobject(NULL),
  m_met_truth_d3pdobject(NULL),
  m_vertex_d3pdobject(NULL),
  m_electron_selection(NULL),
  m_jet_selection(NULL),
  m_muon_selection(NULL),
  m_grl_tool(NULL)
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

  DECLARE_TOOL(SelectionTools::GoodRunsListTool  , "GRL");
  DECLARE_TOOL(SelectionTools::ObjectCleaningTool, "Object_Cleaning");

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
  m_trigger_d3pdobject =
      new D3PDReader::TriggerD3PDObject(m_entry_number
                                       , ""
                                       );
  m_trigger_vec_d3pdobject =
      new D3PDReader::TriggerVecD3PDObject(m_entry_number
                                          , ""
                                          );
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

  // GRL
  GET_TOOL( grl_tool
          , SelectionTools::GoodRunsListTool
          , "GRL"
          );
  m_grl_tool = grl_tool;

  // Object cleaning for overlap removal, etc.
  GET_TOOL( object_cleaning
          , SelectionTools::ObjectCleaningTool
          , "Object_Cleaning"
          );
  m_object_cleaning = object_cleaning;
}

// ----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::EndInputDataImp( const SInputData& ) throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonCutFlowCycle::EndInputData()"
           << SLogger::endmsg;

  // = clean up pointers =
  delete m_event;
  delete m_trigger_d3pdobject;
  delete m_trigger_vec_d3pdobject;
  delete m_met;
  // delete m_met_d3pdobject;
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
  m_trigger_d3pdobject->ReadFrom(    GetInputTree(c_input_tree_name.c_str()));
  m_trigger_vec_d3pdobject->ReadFrom(GetInputTree(c_input_tree_name.c_str()));
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
  // TODO Check LAr error

  // Check Tile Error
  // TODO Check Tile Error

  // Check Tile hot spot
  // TODO Check Tile hot spot

  // Check jet cleaning
  // TODO Check jet cleaning
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

  // Check for FCal region
  // TODO Check for FCal region
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
