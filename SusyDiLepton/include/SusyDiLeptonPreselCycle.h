// Dear emacs, this is -*- c++ -*-
#ifndef SusyDiLeptonPreselCycle_H
#define SusyDiLeptonPreselCycle_H

// =============================================================================
#include "AtlasSFrameUtils/include/CycleBase.h"

#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

// =============================================================================
  class Event;
  class Met;
  class Trigger;
  class TriggerVec;
  class SusyDiLeptonCutFlowTool;

namespace D3PDReader
{
  class ElectronD3PDObject;
  class JetD3PDObject;
  class MCEvtD3PDObject;
  class MuonD3PDObject;
  class MuonTruthD3PDObject;
  class TruthD3PDObject;
  class TruthMETD3PDObject;
  class VertexD3PDObject;
}

namespace SelectionTools
{
  class ElectronSelectionTool;
  class JetSelectionTool;
  class MuonSelectionTool;
  class ObjectCleaningTool;
  class GoodRunsListTool;
  class EventCleaningTool;
  class TriggerCutTool;
  class SignalRegionTool;
}

// =============================================================================
/**
*   @short CycleBase class to run the Susy Di-lepton cut flow
*
*          CycleBase class to run the Susy Di-lepton cut flow
*
*  @author Brett Jackson
* @version $Revision: 173 $
*/
// =============================================================================
class SusyDiLeptonPreselCycle : public CycleBase
{
// -----------------------------------------------------------------------------
public:
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  SusyDiLeptonPreselCycle();
  virtual ~SusyDiLeptonPreselCycle();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  virtual void BeginCycleImp() throw(SError);
  virtual void EndCycleImp()   throw(SError);
  virtual void BeginInputDataImp(      const SInputData&) throw(SError);
  virtual void EndInputDataImp(        const SInputData&) throw(SError);
  virtual void BeginMasterInputDataImp(const SInputData&) throw(SError);
  virtual void EndMasterInputDataImp(  const SInputData&) throw(SError);
  virtual void BeginInputFileImp(      const SInputData&) throw(SError);
  virtual void ExecuteEventImp(
      const SInputData&, Double_t) throw(SError);

  void prepEvent();
  void getObjects();

// -----------------------------------------------------------------------------
private:
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // = user configurable variables =
  // Is this egamma or muon stream
  bool c_is_egamma_stream;

  // turn on verbose print statements
  bool c_print_event_info; // turn on for debugging
  bool c_super_verbose_info;

  std::string c_input_tree_name;
  std::string c_output_tree_name;

  std::string c_met_prefix;
  std::string c_muon_prefix;
  std::string c_muon_truth_prefix;
  std::string c_jet_prefix;

  // variables to flag cuts as "critical"
  bool c_crit_grl;
  bool c_crit_incomplete_event;
  bool c_crit_lar_error;
  bool c_crit_tile_error;
  bool c_crit_tile_hot_spot;
  bool c_crit_bad_jet_veto;
  bool c_crit_primary_vertex;
  bool c_crit_bad_mu_veto;
  bool c_crit_cosmic_mu_veto;
  bool c_crit_hfor;
  bool c_crit_ge_2_lep;
  bool c_crit_2_lep;
  bool c_crit_mll;
  bool c_crit_signal_lep;
  bool c_crit_phase_space;
  bool c_crit_trigger;
  bool c_crit_trigger_match;
  bool c_crit_prompt_leptons;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  bool m_is_ee;
  bool m_is_mm;
  bool m_is_em;
  bool m_is_me;

  bool m_pass_event;
  bool m_pass_ee;
  bool m_pass_mm;
  bool m_pass_em;
  bool m_pass_me;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  ElectronContainer m_electrons;
  Event*            m_event;
  JetContainer      m_jets;
  Met*              m_met;
  MuonContainer     m_muons;
  Trigger*          m_trigger;
  TriggerVec*       m_trigger_vec;
  VertexContainer   m_vertices;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // = D3PD readers =
  D3PDReader::ElectronD3PDObject*   m_electron_d3pdobject;
  D3PDReader::JetD3PDObject*        m_jet_d3pdobject;
  D3PDReader::MCEvtD3PDObject*      m_mcevt_d3pdobject;
  D3PDReader::MuonD3PDObject*       m_muon_d3pdobject;
  D3PDReader::MuonTruthD3PDObject*  m_muon_truth_d3pdobject;
  D3PDReader::TruthD3PDObject*      m_truth_d3pdobject;
  D3PDReader::TruthMETD3PDObject*   m_met_truth_d3pdobject;
  D3PDReader::VertexD3PDObject*     m_vertex_d3pdobject;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  SusyDiLeptonCutFlowTool* m_cut_flow;

  SelectionTools::ElectronSelectionTool* m_electron_selection;
  SelectionTools::JetSelectionTool*      m_jet_selection;
  SelectionTools::MuonSelectionTool*     m_muon_selection;
  SelectionTools::ObjectCleaningTool*    m_object_cleaning;

  SelectionTools::GoodRunsListTool*  m_grl_tool;
  SelectionTools::EventCleaningTool* m_event_cleaning_tool;
  SelectionTools::TriggerCutTool*    m_trigger_cut_tool;
  SelectionTools::SignalRegionTool*  m_signal_region_tool;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  void declareTools();

  void initD3PDReaders();
  void getTools();

  /*/
  // This function computes event variables we only want for good events
  // Call this only after you have determined the flavor channel!
  void computeGoodEventVariables();
  */

  // get the lepton eff weight for this event.
  double getLeptonEffWeight();

  void fillOutput();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Macro adding the functions for dictionary generation
  ClassDef(SusyDiLeptonPreselCycle, 0);

}; // class SusyDiLeptonPreselCycle

#endif // SusyDiLeptonPreselCycle_H
