// Dear emacs, this is -*- c++ -*-
#ifndef SusyDiLeptonCutFlowCycle_H
#define SusyDiLeptonCutFlowCycle_H

#include <map>

#include "AtlasSFrameUtils/include/CycleBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/Trigger.h"
#include "AtlasSFrameUtils/include/TriggerVec.h"
#include "AtlasSFrameUtils/include/Vertex.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "CommonTools/include/TLVTool.h"
#include "CommonTools/include/IsoCorrectionTool.h"
#include "CommonTools/include/EgammaEnergyRescaleTool.h"
#include "CommonTools/include/MuonMomentumSmearingTool.h"

#include "D3PDObjects/include/ElectronD3PDObject.h"
#include "D3PDObjects/include/EventInfoD3PDObject.h"
#include "D3PDObjects/include/JetD3PDObject.h"
#include "D3PDObjects/include/MCEvtD3PDObject.h"
#include "D3PDObjects/include/METD3PDObject.h"
#include "D3PDObjects/include/MuonD3PDObject.h"
#include "D3PDObjects/include/TriggerD3PDObject.h"
#include "D3PDObjects/include/TriggerVecD3PDObject.h"
#include "D3PDObjects/include/TruthD3PDObject.h"
#include "D3PDObjects/include/TruthMETD3PDObject.h"
#include "D3PDObjects/include/VertexD3PDObject.h"

#include "SelectionTools/include/GoodRunsListTool.h"
#include "SelectionTools/include/ElectronSelectionTool.h"
#include "SelectionTools/include/EventCleaningTool.h"
#include "SelectionTools/include/JetSelectionTool.h"
#include "SelectionTools/include/MuonSelectionTool.h"
#include "SelectionTools/include/ObjectCleaningTool.h"

/**
*   @short CycleBase class to run the Susy Di-lepton cut flow
*
*          CycleBase class to run the Susy Di-lepton cut flow
*
*  @author Brett Jackson
* @version $Revision: 173 $
*/
// ============================================================================
class SusyDiLeptonCutFlowCycle : public CycleBase
{
// ----------------------------------------------------------------------------
public:
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  SusyDiLeptonCutFlowCycle();
  virtual ~SusyDiLeptonCutFlowCycle();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  virtual void BeginCycleImp() throw(SError);
  virtual void EndCycleImp()   throw(SError);
  virtual void BeginInputDataImp(      const SInputData&) throw(SError);
  virtual void EndInputDataImp(        const SInputData&) throw(SError);
  virtual void BeginMasterInputDataImp(const SInputData&) throw(SError);
  virtual void EndMasterInputDataImp(  const SInputData&) throw(SError);
  virtual void BeginInputFileImp(      const SInputData&) throw(SError);
  virtual void ExecuteEventImp(        const SInputData&, Double_t) throw(SError);

  void prepEvent();
  void getObjects();

// ----------------------------------------------------------------------------
private:
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // = user configurable variables =
  // Is this egamma or muon stream
  bool c_is_egamma_stream;

  // turn on verbose print statements
  bool c_print_event_info; // turn on for debugging

  std::string c_input_tree_name;
  std::string c_output_tree_name;

  std::string c_met_prefix;
  std::string c_muon_prefix;
  std::string c_jet_prefix;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  bool m_is_ee;
  bool m_is_mm;
  bool m_is_em;
  bool m_is_me;

  bool m_pass_event;
  bool m_pass_ee;
  bool m_pass_mm;
  bool m_pass_em;
  bool m_pass_me;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  ElectronContainer m_electrons;
  Event*            m_event;
  JetContainer      m_jets;
  Met*              m_met;
  MuonContainer     m_muons;
  Trigger*          m_trigger;
  TriggerVec*       m_trigger_vec;
  VertexContainer   m_vertices;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // = D3PD readers =
  D3PDReader::ElectronD3PDObject*   m_electron_d3pdobject;
  D3PDReader::JetD3PDObject*        m_jet_d3pdobject;
  D3PDReader::MCEvtD3PDObject*      m_mcevt_d3pdobject;
  D3PDReader::METD3PDObject*        m_met_d3pdobject;
  D3PDReader::MuonD3PDObject*       m_muon_d3pdobject;
  D3PDReader::TruthD3PDObject*      m_truth_d3pdobject;
  D3PDReader::TruthMETD3PDObject*   m_met_truth_d3pdobject;
  D3PDReader::VertexD3PDObject*     m_vertex_d3pdobject;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  SelectionTools::ElectronSelectionTool* m_electron_selection;
  SelectionTools::JetSelectionTool*      m_jet_selection;
  SelectionTools::MuonSelectionTool*     m_muon_selection;
  SelectionTools::ObjectCleaningTool*    m_object_cleaning;

  SelectionTools::GoodRunsListTool* m_grl_tool;
  SelectionTools::EventCleaningTool* m_event_cleaning_tool;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  void declareTools();
  void initD3PDReaders();
  void getTools();

  void runCutFlow();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Macro adding the functions for dictionary generation
  ClassDef(SusyDiLeptonCutFlowCycle, 0);

}; // class SusyDiLeptonCutFlowCycle

// Include the implementation:
#ifndef __CINT__
#include "SusyDiLeptonCutFlowCycle.icc"
#endif // __CINT__

#endif // SusyDiLeptonCutFlowCycle_H
