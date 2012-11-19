// $Id: CycleCreators.py 173 2010-05-12 15:49:33Z krasznaa $

// Local include(s):
#include "include/SusyDiLeptonCutFlowCycle.h"
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ParticleElementBuilder.h"

ClassImp( SusyDiLeptonCutFlowCycle );

// =============================================================================
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
  m_muon_truth_d3pdobject(NULL),
  m_truth_d3pdobject(NULL),
  m_met_truth_d3pdobject(NULL),
  m_vertex_d3pdobject(NULL),
  m_electron_selection(NULL),
  m_jet_selection(NULL),
  m_muon_selection(NULL),
  m_object_cleaning(NULL),
  m_grl_tool(NULL),
  m_event_cleaning_tool(NULL),
  m_trigger_cut_tool(NULL),
  m_signal_region_tool(NULL),
  m_truth_match_tool(NULL),
  m_cross_section_sf_tool(NULL),
  m_b_tag_sf_tool(NULL),
  m_pileup_sf_tool(NULL),
  m_egamma_sf_tool(NULL),
  m_muon_sf_tool(NULL),
  m_mc_event_weight(0.),
  m_pile_up_weight(0.),
  m_lepton_weight(0.),
  m_b_tag_weight(0.),
  m_trigger_weight(0.),
  m_cross_section_weight(0.),
  m_charge_flip_weight(0.),
  m_num_el_all(0.),
  m_num_el_baseline(0.),
  m_num_el_good(0.),
  m_num_el_signal(0.),
  m_num_mu_all(0.),
  m_num_mu_baseline(0.),
  m_num_mu_good(0.),
  m_num_mu_bad(0.),
  m_num_mu_cosmic(0.),
  m_num_mu_signal(0.),
  m_num_jet_all(0.),
  m_num_jet_baseline_good(0.),
  m_num_jet_baseline_bad(0.),
  m_num_jet_good(0.),
  m_num_jet_bad(0.),
  m_num_jet_light(0.),
  m_num_jet_b(0.),
  m_num_jet_forward(0.),
  m_num_jet_central(0.),
  m_num_jet_signal(0.)
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

  // DeclareProperty("Crit_grl"              , c_crit_grl              = true );
  // DeclareProperty("Crit_incomplete_event" , c_crit_incomplete_event = true );
  // DeclareProperty("Crit_lar_error"        , c_crit_lar_error        = true );
  // DeclareProperty("Crit_tile_error"       , c_crit_tile_error       = true );
  // DeclareProperty("Crit_tile_hot_spot"    , c_crit_tile_hot_spot    = true );
  // DeclareProperty("Crit_bad_jet_veto"     , c_crit_bad_jet_veto     = true );
  // DeclareProperty("Crit_primary_vertex"   , c_crit_primary_vertex   = true );
  // DeclareProperty("Crit_bad_mu_veto"      , c_crit_bad_mu_veto      = true );
  // DeclareProperty("Crit_cosmic_mu_veto"   , c_crit_cosmic_mu_veto   = true );
  // DeclareProperty("Crit_hfor"             , c_crit_hfor             = true );
  // DeclareProperty("Crit_ge_2_lep"         , c_crit_ge_2_lep         = true );
  // DeclareProperty("Crit_2_lep"            , c_crit_2_lep            = false);
  // DeclareProperty("Crit_mll"              , c_crit_mll              = true );
  // DeclareProperty("Crit_signal_lep"       , c_crit_signal_lep       = false);
  // DeclareProperty("Crit_phase_space"      , c_crit_phase_space      = false);
  // DeclareProperty("Crit_trigger"          , c_crit_trigger          = false);
  // DeclareProperty("Crit_trigger_match"    , c_crit_trigger_match    = false);
  // DeclareProperty("Crit_prompt_leptons"   , c_crit_prompt_leptons   = false);

  DeclareProperty("Crit_grl"              , c_crit_grl              = false);
  DeclareProperty("Crit_incomplete_event" , c_crit_incomplete_event = false);
  DeclareProperty("Crit_lar_error"        , c_crit_lar_error        = false);
  DeclareProperty("Crit_tile_error"       , c_crit_tile_error       = false);
  DeclareProperty("Crit_tile_hot_spot"    , c_crit_tile_hot_spot    = false);
  DeclareProperty("Crit_bad_jet_veto"     , c_crit_bad_jet_veto     = false);
  DeclareProperty("Crit_primary_vertex"   , c_crit_primary_vertex   = false);
  DeclareProperty("Crit_bad_mu_veto"      , c_crit_bad_mu_veto      = false);
  DeclareProperty("Crit_cosmic_mu_veto"   , c_crit_cosmic_mu_veto   = false);
  DeclareProperty("Crit_hfor"             , c_crit_hfor             = false);
  DeclareProperty("Crit_ge_2_lep"         , c_crit_ge_2_lep         = false);
  DeclareProperty("Crit_2_lep"            , c_crit_2_lep            = false);
  DeclareProperty("Crit_mll"              , c_crit_mll              = false);
  DeclareProperty("Crit_signal_lep"       , c_crit_signal_lep       = false);
  DeclareProperty("Crit_phase_space"      , c_crit_phase_space      = false);
  DeclareProperty("Crit_trigger"          , c_crit_trigger          = false);
  DeclareProperty("Crit_trigger_match"    , c_crit_trigger_match    = false);
  DeclareProperty("Crit_prompt_leptons"   , c_crit_prompt_leptons   = false);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  declareTools();
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::declareTools()
{
  DECLARE_TOOL(CommonTools::EgammaEnergyRescaleTool , "EgammaEnergyRescale" );
  DECLARE_TOOL(CommonTools::MuonMomentumSmearingTool, "MuonMomentumSmearing");
  DECLARE_TOOL(CommonTools::JetCalibTool            , "JetCalibration"      );

  DECLARE_TOOL(CommonTools::IsoCorrectionTool          , "Electron_IsoCorr");
  DECLARE_TOOL(CommonTools::IsoCorrectionTool          , "Muon_IsoCorr"    );
  DECLARE_TOOL(CommonTools::TLVTool                    , "tlv"             );
  DECLARE_TOOL(CommonTools::TopTagTool                 , "Top_Tag"         );
  DECLARE_TOOL(CommonTools::TruthMatchTool             , "Truth_Match"     );
  DECLARE_TOOL(CommonTools::CrossSectionScaleFactorTool, "CrossSectionSF");
  DECLARE_TOOL(CommonTools::PileUpScaleFactorTool      , "PileUpScaleFactor");
  DECLARE_TOOL(CommonTools::EgammaScaleFactorTool      , "EgammaSF");
  DECLARE_TOOL(CommonTools::BTagScaleFactorTool        , "BTagScaleFactor");
  DECLARE_TOOL(CommonTools::MuonScaleFactorTool        , "MuonSF");

  DECLARE_TOOL(SelectionTools::ElectronSelectionTool, "Electron_Selection");
  DECLARE_TOOL(SelectionTools::JetSelectionTool     , "Jet_Selection"     );
  DECLARE_TOOL(SelectionTools::MuonSelectionTool    , "Muon_Selection"    );

  DECLARE_TOOL(SelectionTools::GoodRunsListTool  , "GRL"            );
  DECLARE_TOOL(SelectionTools::EventCleaningTool , "Event_Cleaning" );
  DECLARE_TOOL(SelectionTools::ObjectCleaningTool, "Object_Cleaning");
  DECLARE_TOOL(SelectionTools::TriggerCutTool    , "Trigger_Cut"    );

  DECLARE_TOOL(SelectionTools::SignalRegionTool, "Signal_Regions");


  //OutputTools

  DECLARE_TOOL(CommonTools::EventOutputTool    , "EventOutput");
  DECLARE_TOOL(CommonTools::ElectronOutputTool , "ElectronOutput");
  DECLARE_TOOL(CommonTools::MuonOutputTool     , "MuonOutput");
  DECLARE_TOOL(CommonTools::JetOutputTool      , "JetOutput");
  DECLARE_TOOL(CommonTools::MetOutputTool      , "MetOutput");

  // TODO populate list of tools
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::declareEventVariables()
{
  DeclareVariable(m_run_number          , "run_number"          );
  DeclareVariable(m_event_number        , "event_number"        );
  DeclareVariable(m_event_desc_int      , "event_desc"          );
  DeclareVariable(m_sr_helper_int       , "sr_helper"           );
  DeclareVariable(m_mc_event_weight     , "mc_event_weight"     );
  DeclareVariable(m_pile_up_weight      , "pile_up_weight"      );
  DeclareVariable(m_lepton_weight       , "lepton_weight"       );
  DeclareVariable(m_b_tag_weight        , "b_tag_weight"        );
  DeclareVariable(m_trigger_weight      , "trigger_weight"      );
  DeclareVariable(m_cross_section_weight, "cross_section_weight");
  DeclareVariable(m_charge_flip_weight  , "charge_flip_weight"  );

  DeclareVariable(m_num_el_all            , "num_el_all"            );
  DeclareVariable(m_num_el_baseline       , "num_el_baseline"       );
  DeclareVariable(m_num_el_good           , "num_el_good"           );
  DeclareVariable(m_num_el_signal         , "num_el_signal"         );

  DeclareVariable(m_num_mu_all            , "num_mu_all"            );
  DeclareVariable(m_num_mu_baseline       , "num_mu_baseline"       );
  DeclareVariable(m_num_mu_good           , "num_mu_good"           );
  DeclareVariable(m_num_mu_bad            , "num_mu_bad"            );
  DeclareVariable(m_num_mu_cosmic         , "num_mu_cosmic"         );
  DeclareVariable(m_num_mu_signal         , "num_mu_signal"         );

  DeclareVariable(m_num_jet_all           , "num_jet_all"           );
  DeclareVariable(m_num_jet_baseline_good , "num_jet_baseline_good" );
  DeclareVariable(m_num_jet_baseline_bad  , "num_jet_baseline_bad"  );
  DeclareVariable(m_num_jet_good          , "num_jet_good"          );
  DeclareVariable(m_num_jet_bad           , "num_jet_bad"           );
  DeclareVariable(m_num_jet_light         , "num_jet_light"         );
  DeclareVariable(m_num_jet_b             , "num_jet_b"             );
  DeclareVariable(m_num_jet_forward       , "num_jet_forward"       );
  DeclareVariable(m_num_jet_central       , "num_jet_central"       );
  DeclareVariable(m_num_jet_signal        , "num_jet_signal"        );
}

// -----------------------------------------------------------------------------
SusyDiLeptonCutFlowCycle::~SusyDiLeptonCutFlowCycle()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::BeginCycleImp() throw( SError )
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::EndCycleImp() throw( SError )
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::BeginInputDataImp( const SInputData& )
    throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonCutFlowCycle::beginInputData()"
           << SLogger::endmsg;

  // = initialize D3PD object readers =
  m_logger << DEBUG
           << "m_entry_number: "
           << m_entry_number
           << SLogger::endmsg;

  initD3PDReaders();
  declareEventVariables();
  getTools();
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::initD3PDReaders()
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
}

// -----------------------------------------------------------------------------
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

  GET_TOOL( truth_match_tool
          , CommonTools::TruthMatchTool
          , "Truth_Match"
          );
  m_truth_match_tool = truth_match_tool;


  //SF Tools
  GET_TOOL( cross_section_sf
	        , CommonTools::CrossSectionScaleFactorTool
	        , "CrossSectionSF"
	        );
  m_cross_section_sf_tool = cross_section_sf;


  GET_TOOL(b_tag_sf, CommonTools::BTagScaleFactorTool, "BTagScaleFactor");
  m_b_tag_sf_tool = b_tag_sf;

  GET_TOOL(pile_up_sf, CommonTools::PileUpScaleFactorTool, "PileUpScaleFactor");
  m_pileup_sf_tool = pile_up_sf;

  GET_TOOL(egamma_sf, CommonTools::EgammaScaleFactorTool, "EgammaSF");
  m_egamma_sf_tool = egamma_sf;

  GET_TOOL(muon_sf, CommonTools::MuonScaleFactorTool, "MuonSF");
  m_muon_sf_tool = muon_sf;


  GET_TOOL(event_out, CommonTools::EventOutputTool, "EventOutput");
  m_event_output_tool = event_out;

  GET_TOOL(electron_out, CommonTools::ElectronOutputTool, "ElectronOutput");
  m_electron_output_tool = electron_out;

  GET_TOOL(muon_out, CommonTools::MuonOutputTool, "MuonOutput");
  m_muon_output_tool = muon_out;

  GET_TOOL(jet_out, CommonTools::JetOutputTool, "JetOutput");
  m_jet_output_tool = jet_out;

  GET_TOOL(met_out, CommonTools::MetOutputTool, "MetOutput");
  m_met_output_tool = met_out;
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::EndInputDataImp( const SInputData& )
    throw( SError )
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
  delete m_muon_truth_d3pdobject;

  if (!is_data()) {
    delete m_mcevt_d3pdobject;
    delete m_truth_d3pdobject;
    delete m_met_truth_d3pdobject;
  }
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::BeginMasterInputDataImp( const SInputData& )
    throw( SError )
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::EndMasterInputDataImp( const SInputData& /*id*/ )
    throw( SError )
{
  m_logger << DEBUG
           << "EndMasterInputDataImp()"
           << SLogger::endmsg;

  // do nothing
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::BeginInputFileImp( const SInputData& )
    throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonCutFlowCycle::BeginInputFile()"
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
void SusyDiLeptonCutFlowCycle::ExecuteEventImp( const SInputData&, Double_t )
    throw( SError )
{
  m_logger << DEBUG
           << "SusyDiLeptonCutFlowCycle::ExecuteEvent()"
           << "\n\trun number = "   << m_event->RunNumber()
           << " -- event number = " << m_event->EventNumber()
           << SLogger::endmsg;

  // = Prep event by zeroing out old vent stuff
  prepEvent();
  getObjects();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  bool pass_critical_cuts = runCutFlow();
  if (!pass_critical_cuts) {
    throw SError( SError::SkipEvent );
  }

  checkSignalRegions();

  fillEventVariables();

  fillOutput();

  // m_vertices.print(VERT_ALL);
  // m_electrons.print(EL_ALL, m_vertices);
  // m_muons.print(MU_ALL, m_vertices);
  // m_jets.print(JET_ALL);
  // m_electrons.print(EL_BASELINE, m_vertices);
  // m_vertices.print(VERT_GOOD);
}

// -----------------------------------------------------------------------------
bool SusyDiLeptonCutFlowCycle::runCutFlow()
{
  // if (! (  m_event->EventNumber() == 10342648
  //       || m_event->EventNumber() == 13978696
  //       || m_event->EventNumber() == 14498571
  //       || m_event->EventNumber() == 311085
  //       || m_event->EventNumber() == 560097
  //       || m_event->EventNumber() == 63860
  //       )
  //    )
  //   return false;
//   if (! (  m_event->EventNumber() == 10342648
//         || m_event->EventNumber() == 13978696
//         || m_event->EventNumber() == 14498571
//         || m_event->EventNumber() == 311085
//         || m_event->EventNumber() == 560097
//         || m_event->EventNumber() == 63860
//         )
//      )
//     return false;


//   std::cout << "============================================================\n";
//   std::cout << "= event: " << m_event->EventNumber() << "\n";
//   std::cout << "============================================================\n";

//   m_electrons.print(EL_BASELINE  , m_vertices) ;
//   m_muons.print(MU_BASELINE      , m_vertices) ;
//   m_jets.print(JET_BASELINE_GOOD) ;
//   m_jets.print(JET_BASELINE_BAD ) ;

//   std::cout << "\n";
//   std::cout << "After OL removal\n";
//   m_electrons.print(EL_GOOD, m_vertices ) ;
//   m_muons.print(MU_GOOD    , m_vertices ) ;
//   m_jets.print(JET_GOOD) ;
//   m_jets.print(JET_BAD ) ;

//   std::cout << "\n";
//   std::cout << "Any cosmics?\n";
//   m_muons.print(MU_COSMIC, m_vertices);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check GRL
  bool pass_grl = m_grl_tool->passed(*m_event);
  m_event->getEventDesc()->setPassGrl(pass_grl);
  if (c_crit_grl && pass_grl == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed GRL --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check TTC veto
  bool pass_incomplete_event =
      m_event_cleaning_tool->passIncompleteEvent(m_event);
  m_event->getEventDesc()->setPassIncompleteEvent(pass_incomplete_event);
  if (c_crit_incomplete_event && pass_incomplete_event == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed incomplete event --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check LAr error
  bool pass_lar_error = m_event_cleaning_tool->passLARError(m_event);
  m_event->getEventDesc()->setPassLarError(pass_lar_error);
  if (c_crit_lar_error && pass_lar_error == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed LAr error --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check Tile Error
  bool pass_tile_error = m_event_cleaning_tool->passTileError(m_event);
  m_event->getEventDesc()->setPassTileError(pass_tile_error);
  if (c_crit_tile_error && pass_tile_error == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed tile error --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check Tile hot spot
  bool pass_tile_hot_spot = m_event_cleaning_tool->passTileHotSpot( m_event
                                                                  , m_jets
                                                                  );
  m_event->getEventDesc()->setPassTileHotSpot(pass_tile_hot_spot);
  if (c_crit_tile_hot_spot && pass_tile_hot_spot == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed tile hot spot --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check jet cleaning
  bool pass_jet_cleaning = (m_jets.num(JET_BAD) == 0);
  m_event->getEventDesc()->setPassBadJets(pass_jet_cleaning);
  if (c_crit_bad_jet_veto && pass_jet_cleaning == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed jet cleaning --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check primary vertex
  bool pass_good_vertex = m_vertices.firstGood(VERT_ALL);
  m_event->getEventDesc()->setPassPrimaryVertex(pass_good_vertex);
  if (c_crit_primary_vertex && pass_good_vertex == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed primary vertex --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check for bad muons
  bool pass_bad_muon_veto = (m_muons.getMuons(MU_BAD).size() == 0);
  m_event->getEventDesc()->setPassBadMuons(pass_bad_muon_veto);
  if (c_crit_bad_mu_veto && pass_bad_muon_veto == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed bad muon veto --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check for cosmic muons
  bool pass_cosmic_muon_veto = (m_muons.num(MU_COSMIC) == 0);
  m_event->getEventDesc()->setPassCosmicMuons(pass_cosmic_muon_veto);
  if (c_crit_cosmic_mu_veto && pass_cosmic_muon_veto == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed cosmic muon veto --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check HFOR
  // TODO do proper HFOR cut
  bool pass_hfor = true;
  m_event->getEventDesc()->setPassHFOR(pass_hfor);
  if (c_crit_hfor && pass_hfor == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed HFOR -- "
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check for At least two leptons
  size_t num_good_el = m_electrons.num(EL_GOOD);
  size_t num_good_mu = m_muons.num(MU_GOOD);
  size_t num_good_leptons = num_good_el + num_good_mu;

  bool pass_ge_2_good_leptons = (num_good_leptons >= 2);
  m_event->getEventDesc()->setPassGE2GoodLeptons(pass_ge_2_good_leptons);
  if (c_crit_ge_2_lep && pass_ge_2_good_leptons == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed >= 2 leptons --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check for exactly two leptons
  bool pass_2_good_leptons = (num_good_leptons == 2);
  m_event->getEventDesc()->setPass2GoodLeptons(pass_2_good_leptons);
  if (c_crit_2_lep && pass_2_good_leptons == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed == 2 leptons --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check flavor channel for this event
  FLAVOR_CHANNEL flavor_channel = FLAVOR_NONE;
  if (num_good_el == 2 && num_good_mu == 0) {
    flavor_channel = FLAVOR_EE;
  }
  if (num_good_el == 0 && num_good_mu == 2) {
    flavor_channel = FLAVOR_MM;
  }
  if (num_good_el == 1 && num_good_mu == 1) {
    flavor_channel = FLAVOR_EM;
  }
  m_event->getEventDesc()->setFlavorChannel(flavor_channel);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // compute/cache event variables we only want for "good events"
  computeGoodEventVariables();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check mll of di-lepton pair
  bool pass_mll = m_event_cleaning_tool->passMllCut(m_event);
  m_event->getEventDesc()->setPassMll(pass_mll);
  if (c_crit_mll && pass_mll == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed mll --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check for signal leptons
  size_t num_signal_leptons = ( m_electrons.num(EL_SIGNAL)
                              + m_muons.num(MU_SIGNAL)
                              );
  bool pass_2_signal_leptons = (num_signal_leptons == 2);
  m_event->getEventDesc()->setPass2SignalLeptons(pass_2_signal_leptons);
  if (c_crit_signal_lep && pass_2_signal_leptons == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed == 2 signal leptons --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check sign channel for this event
  SIGN_CHANNEL sign_channel = CommonTools::SignChannel::getSignChannel(
      m_event->getFlavorChannel(),
      m_electrons.getElectrons(EL_GOOD),
      m_muons.getMuons(MU_GOOD));
  m_event->getEventDesc()->setSignChannel(sign_channel);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check for real leptons
  bool pass_real_leptons = m_truth_match_tool->isRealLeptonEvent(
      m_event->getFlavorChannel(),
      m_electrons.getElectrons(EL_GOOD),
      m_muons.getMuons(MU_GOOD),
      m_muon_truth_d3pdobject);
  m_event->getEventDesc()->setTruthPrompt(pass_real_leptons);
  if (c_crit_prompt_leptons && pass_real_leptons == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed prompt leptons --"
                << " Run: " << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check for valid pt phase space
  TRIG_PHASE trigger_phase_space =
      m_trigger_cut_tool->getPhaseSpace( m_electrons.getElectrons(EL_GOOD)
                                       , m_muons.getMuons(MU_GOOD)
                                       );
  m_event->getEventDesc()->setPhaseSpace(trigger_phase_space);
  if (  c_crit_phase_space
     && m_event->getEventDesc()->getPhaseSpace() == PHASE_NONE
     ) {
    if (c_super_verbose_info) {
      std::cout << "Failed phase space --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check trigger for this event
  bool pass_ee_trigger = m_trigger_cut_tool->passedEETriggerChannel(
      m_event, m_trigger);
  m_event->getEventDesc()->setEETrigger(pass_ee_trigger);

  bool pass_mm_trigger = m_trigger_cut_tool->passedMMTriggerChannel(
      m_event, m_trigger);
  m_event->getEventDesc()->setMMTrigger(pass_mm_trigger);

  bool pass_em_trigger = m_trigger_cut_tool->passedEMTriggerChannel(
      m_event, m_trigger);
  m_event->getEventDesc()->setEMTrigger(pass_em_trigger);

  bool pass_me_trigger = m_trigger_cut_tool->passedMETriggerChannel(
      m_event, m_trigger);
  m_event->getEventDesc()->setMETrigger(pass_me_trigger);

  if (  c_crit_trigger
     && pass_ee_trigger == false
     && pass_mm_trigger == false
     && pass_em_trigger == false
     && pass_me_trigger == false
     ) {
    if (c_super_verbose_info) {
      std::cout << "Failed trigger --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check trigger matching
  bool pass_trigger_match = false;

  switch (m_event->getPhaseSpace()) {
    case PHASE_EE: pass_trigger_match =
                      m_trigger_cut_tool->passedEETriggerMatching(
                          m_event, m_trigger_vec,
                          m_electrons.getElectrons(EL_GOOD),
                          m_muons.getMuons(MU_GOOD));
                   break;
    case PHASE_MM: pass_trigger_match =
                      m_trigger_cut_tool->passedMMTriggerMatching(
                          m_event, m_trigger_vec,
                          m_electrons.getElectrons(EL_GOOD),
                          m_muons.getMuons(MU_GOOD));
                   break;
    case PHASE_EM: pass_trigger_match =
                      m_trigger_cut_tool->passedEMTriggerMatching(
                          m_event, m_trigger_vec,
                          m_electrons.getElectrons(EL_GOOD),
                          m_muons.getMuons(MU_GOOD));
                   break;
    case PHASE_ME: pass_trigger_match =
                      m_trigger_cut_tool->passedMETriggerMatching(
                          m_event, m_trigger_vec,
                          m_electrons.getElectrons(EL_GOOD),
                          m_muons.getMuons(MU_GOOD));
                   break;
    default:       pass_trigger_match = false;
  };
  m_event->getEventDesc()->setPassTriggerMatch(pass_trigger_match);
  if (c_crit_trigger_match && pass_trigger_match == false) {
    if (c_super_verbose_info) {
      std::cout << "Failed trigger match --"
                << " Run: "   << m_event->RunNumber()
                << " Event: " << m_event->EventNumber()
                << std::endl;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Reached the end of the cut flow. Return true to signify this event did
  // not fail any critical cuts
  return true;
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::checkSignalRegions()
{
  m_signal_region_tool->processSignalRegions( m_event
                                            , m_electrons
                                            , m_muons
                                            , m_jets
                                            , m_met
                                            );
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::computeGoodEventVariables()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // compute mll
  m_event->setMll(CommonTools::MllTool::getMll(
        m_event->getFlavorChannel(),
        m_electrons.getElectrons(EL_GOOD),
        m_muons.getMuons(MU_GOOD)
        ) );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // compute met and met-rel
  m_met->prep(m_event, &m_electrons, &m_muons, &m_jets);
  m_event->setMetRel(Met::getMetRel( m_met
                                   , m_electrons.getElectrons(EL_GOOD)
                                   , m_muons.getMuons(MU_GOOD)
                                   , m_jets.getJets(JET_ALL_CENTRAL)
                                   )
                    );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // compute mt2
  m_event->setMt2(CommonTools::MT2Tool::getMt2( m_event->getFlavorChannel(),
        m_met,
        m_electrons.getElectrons(EL_GOOD),
        m_muons.getMuons(MU_GOOD)));
  
  // compute ptll
  m_event->setPtll(CommonTools::PtllTool::getPtll(m_event->getFlavorChannel(),
						  m_electrons.getElectrons(EL_GOOD),
						  m_muons.getMuons(MU_GOOD)));

}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::clearEventVariables()
{
  m_run_number     = 0;
  m_event_number   = 0;
  m_event_desc_int = 0.;
  m_sr_helper_int  = 0.;

  m_mc_event_weight      = 1.;
  m_pile_up_weight       = 1.;
  m_lepton_weight        = 1.;
  m_b_tag_weight         = 1.;
  m_trigger_weight       = 1.;
  m_cross_section_weight = 1.;
  m_charge_flip_weight   = 1.;

  m_num_el_all = 0.;
  m_num_el_baseline = 0.;
  m_num_el_good = 0.;
  m_num_el_signal = 0.;

  m_num_mu_all = 0.;
  m_num_mu_baseline = 0.;
  m_num_mu_good = 0.;
  m_num_mu_bad = 0.;
  m_num_mu_cosmic = 0.;
  m_num_mu_signal = 0.;

  m_num_jet_all = 0.;
  m_num_jet_baseline_good = 0.;
  m_num_jet_baseline_bad = 0.;
  m_num_jet_good = 0.;
  m_num_jet_bad = 0.;
  m_num_jet_light = 0.;
  m_num_jet_b = 0.;
  m_num_jet_forward = 0.;
  m_num_jet_central = 0.;
  m_num_jet_signal = 0.;
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::fillEventVariables()
{
  m_run_number     = m_event->RunNumber();
  m_event_number   = m_event->EventNumber();
  m_event_desc_int = m_event->getEventDesc()->toInt();
  m_sr_helper_int  = m_event->getSRHelper()->toInt();

  if (!is_data()) {
    m_mc_event_weight = m_truth_d3pdobject->mc_event_weight();
    // TODO fill m_pile_up_weight
    m_pile_up_weight       = 1.;
    // TODO fill m_lepton_weight
    m_lepton_weight        = 1.;
    // TODO fill m_b_tag_weight
    m_b_tag_weight         = 1.;
    // TODO fill m_trigger_weight
    m_trigger_weight       = 1.;
    // TODO fill m_cross_section_weight
    m_cross_section_weight = 1.;
    // TODO fill m_charge_flip_weight
    m_charge_flip_weight   = 1.;
  }


  m_num_el_all            = m_electrons.num(EL_ALL);
  m_num_el_baseline       = m_electrons.num(EL_BASELINE);
  m_num_el_good           = m_electrons.num(EL_GOOD);
  m_num_el_signal         = m_electrons.num(EL_SIGNAL);

  m_num_mu_all            = m_muons.num(MU_ALL);
  m_num_mu_baseline       = m_muons.num(MU_BASELINE);
  m_num_mu_good           = m_muons.num(MU_GOOD);
  m_num_mu_bad            = m_muons.num(MU_BAD);
  m_num_mu_cosmic         = m_muons.num(MU_COSMIC);
  m_num_mu_signal         = m_muons.num(MU_SIGNAL);

  m_num_jet_all           = m_jets.num(JET_ALL);
  m_num_jet_baseline_good = m_jets.num(JET_BASELINE_GOOD);
  m_num_jet_baseline_bad  = m_jets.num(JET_BASELINE_BAD);
  m_num_jet_good          = m_jets.num(JET_GOOD);
  m_num_jet_bad           = m_jets.num(JET_BAD);
  m_num_jet_light         = m_jets.num(JET_LIGHT);
  m_num_jet_b             = m_jets.num(JET_B);
  m_num_jet_forward       = m_jets.num(JET_FORWARD);
  m_num_jet_central       = m_jets.num(JET_ALL_CENTRAL);
  m_num_jet_signal        = m_jets.num(JET_ALL_SIGNAL);
}

// -----------------------------------------------------------------------------
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
  m_event->clear();

  m_electrons.clear();
  m_jets.clear();
  m_muons.clear();
  m_met->clear();
  m_vertices.clear();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  clearEventVariables();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_truth_match_tool->prep(m_truth_d3pdobject);

  m_cross_section_sf_tool->clear();
  m_b_tag_sf_tool->clear();
  m_pileup_sf_tool->clear();

}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::getObjects()
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

  // m_jets.setCollection( JET_BASELINE,
  //     m_jet_selection->getBaselineJets(m_jets));

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
void SusyDiLeptonCutFlowCycle::fillOutput()
{

  m_event_output_tool->fillOutput(m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
  m_electron_output_tool->fillOutput(m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
  m_muon_output_tool->fillOutput(m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
  m_jet_output_tool->fillOutput(m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
 m_met_output_tool->fillOutput(m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
}

