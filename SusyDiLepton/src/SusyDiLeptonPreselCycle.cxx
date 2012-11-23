// $Id: CycleCreators.py 173 2010-05-12 15:49:33Z krasznaa $

// Local include(s):
#include "include/SusyDiLeptonPreselCycle.h"
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ParticleElementBuilder.h"

ClassImp( SusyDiLeptonPreselCycle );

// =============================================================================
SusyDiLeptonPreselCycle::SusyDiLeptonPreselCycle() :
  CycleBase(),
  m_event(NULL),
  m_met(NULL),
  m_trigger(NULL),
  m_trigger_vec(NULL),
  m_electron_d3pdobject(NULL),
  m_jet_d3pdobject(NULL),
  m_mcevt_d3pdobject(NULL),
  m_muon_d3pdobject(NULL),
  m_muon_truth_d3pdobject(NULL),
  m_truth_d3pdobject(NULL),
  m_met_truth_d3pdobject(NULL),
  m_vertex_d3pdobject(NULL),
  m_cut_flow(NULL),
  m_electron_selection(NULL),
  m_jet_selection(NULL),
  m_muon_selection(NULL),
  m_object_cleaning(NULL),
  m_grl_tool(NULL),
  m_event_cleaning_tool(NULL),
  m_trigger_cut_tool(NULL),
  m_signal_region_tool(NULL)
  // m_truth_match_tool(NULL),
{
  // = declare user defined properties =
  DeclareProperty("input_tree_name" , c_input_tree_name="presel");
  DeclareProperty("output_tree_name", c_output_tree_name="output");

  DeclareProperty("is_egamma_stream"  , c_is_egamma_stream   = false);
  DeclareProperty("print_event_info"  , c_print_event_info   = false);
  DeclareProperty("super_verbose_info", c_super_verbose_info = false);

  DeclareProperty("Met_prefix"      , c_met_prefix="MET_Egamma10NoTau" );
  DeclareProperty("Muon_prefix"     , c_muon_prefix="mu_staco_"        );
  DeclareProperty("MuonTruth_prefix", c_muon_truth_prefix="muonTruth_" );
  DeclareProperty("Jet_prefix"      , c_jet_prefix="jet_AntiKt4LCTopo_");

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  declareTools();
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::declareTools()
{
  DECLARE_TOOL(SusyDiLeptonCutFlowTool, "CutFlow");

  DECLARE_TOOL(CommonTools::EgammaEnergyRescaleTool , "EgammaEnergyRescale" );
  DECLARE_TOOL(CommonTools::MuonMomentumSmearingTool, "MuonMomentumSmearing");
  DECLARE_TOOL(CommonTools::JetCalibTool            , "JetCalibration"      );

  DECLARE_TOOL(CommonTools::IsoCorrectionTool          , "Electron_IsoCorr");
  DECLARE_TOOL(CommonTools::IsoCorrectionTool          , "Muon_IsoCorr"    );
  DECLARE_TOOL(CommonTools::TLVTool                    , "tlv"             );
  DECLARE_TOOL(CommonTools::TopTagTool                 , "Top_Tag"         );
  DECLARE_TOOL(CommonTools::TruthMatchTool             , "Truth_Match"     );

  DECLARE_TOOL(SelectionTools::ElectronSelectionTool, "Electron_Selection");
  DECLARE_TOOL(SelectionTools::JetSelectionTool     , "Jet_Selection"     );
  DECLARE_TOOL(SelectionTools::MuonSelectionTool    , "Muon_Selection"    );

  DECLARE_TOOL(SelectionTools::GoodRunsListTool  , "GRL"            );
  DECLARE_TOOL(SelectionTools::EventCleaningTool , "Event_Cleaning" );
  DECLARE_TOOL(SelectionTools::ObjectCleaningTool, "Object_Cleaning");
  DECLARE_TOOL(SelectionTools::TriggerCutTool    , "Trigger_Cut"    );
  DECLARE_TOOL(SelectionTools::HFORTool          , "HFOR"           );

  DECLARE_TOOL(SelectionTools::SignalRegionTool, "Signal_Regions");

  // Output Tools
}

// -----------------------------------------------------------------------------
SusyDiLeptonPreselCycle::~SusyDiLeptonPreselCycle()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::BeginCycleImp() throw( SError )
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::EndCycleImp() throw( SError )
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::BeginInputDataImp( const SInputData& )
    throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonPreselCycle::beginInputData()"
           << SLogger::endmsg;

  // = initialize D3PD object readers =
  m_logger << DEBUG
           << "m_entry_number: "
           << m_entry_number
           << SLogger::endmsg;

  initD3PDReaders();
  getTools();
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::initD3PDReaders()
{
  m_event = new Event(m_entry_number, "", is_data());
  m_trigger = new Trigger(m_entry_number, "");
  m_trigger_vec = new TriggerVec(m_entry_number, "");
  m_met = new Met(m_entry_number, c_met_prefix.c_str(), is_data());

  m_vertex_d3pdobject =
      new D3PDReader::VertexD3PDObject( m_entry_number
                                      , "vx_"
                                      , is_data()
                                      );
  m_electron_d3pdobject =
      new D3PDReader::ElectronD3PDObject( m_entry_number
                                        , "el_"
                                        , is_data()
                                        );
  m_jet_d3pdobject =
      new D3PDReader::JetD3PDObject( m_entry_number
                                   , c_jet_prefix.c_str()
                                   , is_data()
                                   );
  m_muon_d3pdobject =
      new D3PDReader::MuonD3PDObject( m_entry_number
                                    , c_muon_prefix.c_str()
                                    , is_data()
                                    );

  // Some of these readers are only initialized for MC
  if (!is_data()) {
    m_muon_truth_d3pdobject =
        new D3PDReader::MuonTruthD3PDObject( m_entry_number
                                           , c_muon_truth_prefix.c_str()
                                           );

    m_mcevt_d3pdobject
        = new D3PDReader::MCEvtD3PDObject(m_entry_number);
    m_truth_d3pdobject
        = new D3PDReader::TruthD3PDObject(m_entry_number);
    m_met_truth_d3pdobject
        = new D3PDReader::TruthMETD3PDObject(m_entry_number);
  }

  m_event->SetActive(              kTRUE, ".*");
  m_met->SetActive(                kTRUE, ".*");
  m_trigger->SetActive(            kTRUE, ".*");
  m_trigger_vec->SetActive(        kTRUE, ".*");
  m_vertex_d3pdobject->SetActive(  kTRUE, ".*");
  m_electron_d3pdobject->SetActive(kTRUE, ".*");
  m_jet_d3pdobject->SetActive(     kTRUE, ".*");
  m_muon_d3pdobject->SetActive(    kTRUE, ".*");

  if (!is_data()) {
    m_mcevt_d3pdobject->SetActive(     kTRUE, ".*");
    m_muon_truth_d3pdobject->SetActive(kTRUE, ".*");
    m_truth_d3pdobject->SetActive(     kTRUE, ".*");
    m_met_truth_d3pdobject->SetActive( kTRUE, ".*");
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_event->WriteTo(              GetOutputTree(c_output_tree_name.c_str()));
  m_met->WriteTo(                GetOutputTree(c_output_tree_name.c_str()));
  m_trigger->WriteTo(            GetOutputTree(c_output_tree_name.c_str()));
  m_trigger_vec->WriteTo(        GetOutputTree(c_output_tree_name.c_str()));
  m_vertex_d3pdobject->WriteTo(  GetOutputTree(c_output_tree_name.c_str()));
  m_electron_d3pdobject->WriteTo(GetOutputTree(c_output_tree_name.c_str()));
  m_jet_d3pdobject->WriteTo(     GetOutputTree(c_output_tree_name.c_str()));
  m_muon_d3pdobject->WriteTo(    GetOutputTree(c_output_tree_name.c_str()));

  if (!is_data()) {
    m_mcevt_d3pdobject->WriteTo(     GetOutputTree(c_output_tree_name.c_str()));
    m_muon_truth_d3pdobject->WriteTo(GetOutputTree(c_output_tree_name.c_str()));
    m_truth_d3pdobject->WriteTo(     GetOutputTree(c_output_tree_name.c_str()));
    m_met_truth_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()));
  }
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::getTools()
{
  GET_TOOL( cut_flow_tool
          , SusyDiLeptonCutFlowTool
          , "CutFlow"
          );
  m_cut_flow = cut_flow_tool;

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
  GET_TOOL(
      el_iso_corr_tool, CommonTools::IsoCorrectionTool, "Electron_IsoCorr");
  GET_TOOL(
      mu_iso_corr_tool, CommonTools::IsoCorrectionTool, "Muon_IsoCorr"    );

  // Electron selection
  GET_TOOL( electron_selection
          , SelectionTools::ElectronSelectionTool
          , "Electron_Selection"
          );
  m_electron_selection = electron_selection;
  m_electrons.init(electron_selection, tlv_tool, el_iso_corr_tool);

  // Jet selection
  GET_TOOL( jet_selection
          , SelectionTools::JetSelectionTool
          , "Jet_Selection"
          );
  m_jet_selection = jet_selection;
  m_jets.init(jet_selection, tlv_tool);

  // Muon selection
  GET_TOOL( muon_selection
          , SelectionTools::MuonSelectionTool
          , "Muon_Selection"
          );
  m_muon_selection = muon_selection;
  m_muons.init(muon_selection, tlv_tool, mu_iso_corr_tool);

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

  GET_TOOL( signal_region_tool
          , SelectionTools::SignalRegionTool
          , "Signal_Regions"
          );
  m_signal_region_tool = signal_region_tool;

  // GET_TOOL( truth_match_tool
  //         , CommonTools::TruthMatchTool
  //         , "Truth_Match"
  //         );
  // m_truth_match_tool = truth_match_tool;
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::EndInputDataImp( const SInputData& )
    throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonPreselCycle::EndInputData()"
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
  delete m_muon_truth_d3pdobject;

  if (!is_data()) {
    delete m_mcevt_d3pdobject;
    delete m_truth_d3pdobject;
    delete m_met_truth_d3pdobject;
  }
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::BeginMasterInputDataImp( const SInputData& )
    throw( SError )
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::EndMasterInputDataImp( const SInputData& /*id*/ )
    throw( SError )
{
  m_logger << DEBUG
           << "EndMasterInputDataImp()"
           << SLogger::endmsg;

  // do nothing
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::BeginInputFileImp( const SInputData& )
    throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonPreselCycle::BeginInputFile()"
           << SLogger::endmsg;

  // = get input trees from the d3pd objects =
  m_event->ReadFrom(              GetInputTree(c_input_tree_name.c_str()));
  m_trigger->ReadFrom(            GetInputTree(c_input_tree_name.c_str()));
  m_trigger_vec->ReadFrom(        GetInputTree(c_input_tree_name.c_str()));
  m_met->ReadFrom(                GetInputTree(c_input_tree_name.c_str()));
  m_vertex_d3pdobject->ReadFrom(  GetInputTree(c_input_tree_name.c_str()));
  m_electron_d3pdobject->ReadFrom(GetInputTree(c_input_tree_name.c_str()));
  m_jet_d3pdobject->ReadFrom(     GetInputTree(c_input_tree_name.c_str()));
  m_muon_d3pdobject->ReadFrom(    GetInputTree(c_input_tree_name.c_str()));

  if (!is_data()){
    m_mcevt_d3pdobject->ReadFrom(     GetInputTree(c_input_tree_name.c_str()));
    m_muon_truth_d3pdobject->ReadFrom(GetInputTree(c_input_tree_name.c_str()));
    m_truth_d3pdobject->ReadFrom(     GetInputTree(c_input_tree_name.c_str()));
    m_met_truth_d3pdobject->ReadFrom( GetInputTree(c_input_tree_name.c_str()));
  }
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::ExecuteEventImp( const SInputData&, Double_t )
    throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonPreselCycle::ExecuteEvent()"
           << "\n\trun number = "   << m_event->RunNumber()
           << " -- event number = " << m_event->EventNumber()
           << SLogger::endmsg;

  // = Prep event by zeroing out old vent stuff
  prepEvent();
  getObjects();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  bool pass_critical_cuts = m_cut_flow->runBasicCutFlow( m_event
                                                       , m_electrons
                                                       , m_muons
                                                       , m_jets
                                                       , m_vertices
                                                       , m_trigger
                                                       , m_trigger_vec
                                                       , m_muon_truth_d3pdobject
						       , m_truth_d3pdobject
                                                       );
  if (!pass_critical_cuts) {
    throw SError( SError::SkipEvent );
  }

  m_cut_flow->computeGoodEventVariables( m_event
                                       , m_electrons
                                       , m_muons
                                       , m_jets
                                       , m_met
                                       );

  // pass_critical_cuts = m_cut_flow->runAdvancedCutFlow( m_event
  //                                                    , m_electrons
  //                                                    , m_muons
  //                                                    , m_jets
  //                                                    , m_vertices
  //                                                    , m_trigger
  //                                                    , m_trigger_vec
  //                                                    , m_muon_truth_d3pdobject
  //                                                    , m_truth_d3pdobject
  //                                                    );
  // if (!pass_critical_cuts) {
  //   throw SError( SError::SkipEvent );
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  fillOutput();
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::prepEvent()
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
  m_event->clear();

  m_electrons.clear();
  m_jets.clear();
  m_muons.clear();
  m_met->clear();
  m_vertices.clear();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // m_truth_match_tool->prep(m_truth_d3pdobject);
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::getObjects()
{
  m_vertices.prepVertices(m_vertex_d3pdobject, is_data());

  m_electrons.prepElectrons(m_electron_d3pdobject, m_vertices);
  m_muons.prepMuons(m_muon_d3pdobject, m_vertices);
  m_jets.prepJets(m_jet_d3pdobject, m_event, m_vertices);

  // Get baseline objects
  m_electrons.setCollection( EL_BASELINE,
      m_electron_selection->getBaselineElectrons(m_electrons));

  m_muons.setCollection( MU_BASELINE,
      m_muon_selection->getBaselineMuons(m_muons));

  m_jets.setCollection( JET_BASELINE_GOOD,
      m_jet_selection->getBaselineGoodJets(m_jets));

  m_jets.setCollection( JET_BASELINE_BAD,
      m_jet_selection->getBaselineBadJets(m_jets));

  // Get bad/veto objects
  m_muons.setCollection( MU_BAD,
      m_muon_selection->getBadMuons(m_muons));

  // do overlap removal to get good objects
  m_object_cleaning->SelectionTools::ObjectCleaningTool::fullObjectCleaning(
      m_electrons, m_muons, m_jets);

  // get cosmic muons
  m_muons.setCollection( MU_COSMIC,
      m_muon_selection->getCosmicMuons(m_muons));

  // Get signal objects
  m_electrons.setCollection( EL_SIGNAL,
      m_electron_selection->getSignalElectrons(m_electrons));

  m_muons.setCollection( MU_SIGNAL,
      m_muon_selection->getSignalMuons(m_muons));

  m_jets.setCollection( JET_LIGHT,
      m_jet_selection->getLJets(m_jets));

  m_jets.setCollection( JET_B,
      m_jet_selection->getBJets(m_jets));

  m_jets.setCollection( JET_FORWARD,
      m_jet_selection->getFJets(m_jets));

  // Set "coimbined colelctions like JET_ALL_SIGNAL and JET_ALL_CENTRAL
  m_jets.setCombinedCollections();
}

// -----------------------------------------------------------------------------
void SusyDiLeptonPreselCycle::fillOutput()
{
  m_event->ReadAllActive();
  m_met->ReadAllActive();
  m_trigger->ReadAllActive();
  m_trigger_vec->ReadAllActive();
  m_vertex_d3pdobject->ReadAllActive();
  m_electron_d3pdobject->ReadAllActive();
  m_jet_d3pdobject->ReadAllActive();
  m_muon_d3pdobject->ReadAllActive();

  if (!is_data()) {
    m_mcevt_d3pdobject->ReadAllActive();
    m_muon_truth_d3pdobject->ReadAllActive();
    m_truth_d3pdobject->ReadAllActive();
    m_met_truth_d3pdobject->ReadAllActive();
  }
}
