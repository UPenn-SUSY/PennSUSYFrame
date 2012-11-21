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
  m_cut_flow(NULL),
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
  m_muon_sf_tool(NULL)
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
void SusyDiLeptonCutFlowCycle::declareTools()
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


  // Output Tools
  DECLARE_TOOL(CommonTools::EventOutputTool    , "EventOutput");
  DECLARE_TOOL(CommonTools::ElectronOutputTool , "ElectronOutput");
  DECLARE_TOOL(CommonTools::MuonOutputTool     , "MuonOutput");
  DECLARE_TOOL(CommonTools::JetOutputTool      , "JetOutput");
  DECLARE_TOOL(CommonTools::MetOutputTool      , "MetOutput");
  DECLARE_TOOL(CommonTools::VertexOutputTool   , "VertexOutput");
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

  GET_TOOL(vertex_out, CommonTools::VertexOutputTool, "VertexOutput");
  m_vertex_output_tool = vertex_out;
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
  bool pass_critical_cuts = m_cut_flow->runBasicCutFlow( m_event
                                                       , m_electrons
                                                       , m_muons
                                                       , m_jets
                                                       , m_vertices
                                                       , m_trigger
                                                       , m_trigger_vec
                                                       , m_muon_truth_d3pdobject
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

  pass_critical_cuts = m_cut_flow->runAdvancedCutFlow( m_event
                                                     , m_electrons
                                                     , m_muons
                                                     , m_jets
                                                     , m_vertices
                                                     , m_trigger
                                                     , m_trigger_vec
                                                     , m_muon_truth_d3pdobject
                                                     );
  if (!pass_critical_cuts) {
    throw SError( SError::SkipEvent );
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
double SusyDiLeptonCutFlowCycle::getLeptonEffWeight()
{
  double lepton_eff = 1.;

  std::vector<Electron*> el_vec = m_electrons.getElectrons(EL_GOOD);
  size_t el_term = el_vec.size();
  for (size_t el_it = 0; el_it != el_term; ++el_it) {
    lepton_eff *= m_egamma_sf_tool->getSF(el_vec.at(el_it));
  }

  std::vector<Muon*> mu_vec = m_muons.getMuons(MU_GOOD);
  size_t mu_term = mu_vec.size();
  for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
    lepton_eff *= m_muon_sf_tool->getSF(mu_vec.at(mu_it));
  }

  return lepton_eff;
}

// -----------------------------------------------------------------------------
void SusyDiLeptonCutFlowCycle::fillEventVariables()
{
  if (!is_data()) {
    m_event->setMCEventWeight(m_truth_d3pdobject->mc_event_weight());

    m_event->setPileUpWeight(m_pileup_sf_tool->getPileupScaleFactor(
          m_event, m_truth_d3pdobject));

    m_event->setLeptonEffWeight(getLeptonEffWeight());

    m_event->setBTagWeight(m_b_tag_sf_tool->getSF(m_jets.getJets(JET_GOOD)));

    // TODO fill m_trigger_weight
    m_event->setTriggerWeight(1.);

    // TODO fill m_cross_section_weight
    m_event->setCrossSectionWeight(1.);
    m_event->setKFactor(1.);
    m_event->setEffTimesXS(1.);

    // TODO fill m_charge_flip_weight
  }
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
  m_event_output_tool->fillOutput(
      m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
  m_electron_output_tool->fillOutput(
      m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
  m_muon_output_tool->fillOutput(
      m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
  m_jet_output_tool->fillOutput(
      m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
  m_met_output_tool->fillOutput(
      m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
  m_vertex_output_tool->fillOutput(
      m_event, m_electrons, m_muons, m_jets, m_met, m_vertices);
}
