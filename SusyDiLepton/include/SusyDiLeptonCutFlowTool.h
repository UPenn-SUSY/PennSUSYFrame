// Dear emacs, this is -*- c++ -*-
#ifndef SusyDiLeptonCutFlowTool_H
#define SusyDiLeptonCutFlowTool_H

#include <map>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
// #include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/Trigger.h"
#include "AtlasSFrameUtils/include/TriggerVec.h"
#include "AtlasSFrameUtils/include/Vertex.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "CommonTools/include/SignChannel.h"
#include "CommonTools/include/MllTool.h"
#include "CommonTools/include/PtllTool.h"
#include "CommonTools/include/MT2Tool.h"
#include "CommonTools/include/TopTagTool.h"
#include "CommonTools/include/TruthMatchTool.h"
// 
#include "D3PDObjects/include/MuonTruthD3PDObject.h"

#include "SelectionTools/include/EventCleaningTool.h"
#include "SelectionTools/include/GoodRunsListTool.h"
#include "SelectionTools/include/TriggerCutTool.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class SusyDiLeptonCutFlowTool : public ToolBase
{
// -----------------------------------------------------------------------------
public:
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  SusyDiLeptonCutFlowTool(SCycleBase* parent, const char* name = "OutputTool");
  virtual ~SusyDiLeptonCutFlowTool();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // virtual void BeginCycleImp() throw(SError);
  // virtual void EndCycleImp()   throw(SError);
  virtual void BeginInputData(      const SInputData&) throw(SError);
  // virtual void EndInputDataImp(        const SInputData&) throw(SError);
  // virtual void BeginMasterInputDataImp(const SInputData&) throw(SError);
  // virtual void EndMasterInputDataImp(  const SInputData&) throw(SError);
  // virtual void BeginInputFileImp(      const SInputData&) throw(SError);

  bool runBasicCutFlow( Event*
                      , ElectronContainer&
                      , MuonContainer&
                      , JetContainer&
                      , VertexContainer&
                      , const Trigger*
                      , const TriggerVec*
                      , D3PDReader::MuonTruthD3PDObject*
                      );

  bool runAdvancedCutFlow( Event*
                         , ElectronContainer&
                         , MuonContainer&
                         , JetContainer&
                         , VertexContainer&
                         , const Trigger*
                         , const TriggerVec*
                         , D3PDReader::MuonTruthD3PDObject*
                         );

  // This function computes event variables we only want for good events
  // Call this only after you have determined the flavor channel!
  void computeGoodEventVariables( Event*
                                , ElectronContainer&
                                , MuonContainer&
                                , JetContainer&
                                , Met*
                                );

// -----------------------------------------------------------------------------
private:
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // = user configurable variables =
  // turn on verbose print statements
  bool c_super_verbose_info;

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
  SelectionTools::GoodRunsListTool*  m_grl_tool;
  SelectionTools::EventCleaningTool* m_event_cleaning_tool;
  SelectionTools::TriggerCutTool*    m_trigger_cut_tool;

  CommonTools::TruthMatchTool* m_truth_match_tool;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  void getTools();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Macro adding the functions for dictionary generation
  ClassDef(SusyDiLeptonCutFlowTool, 0);

}; // class SusyDiLeptonCutFlowTool

#endif // SusyDiLeptonCutFlowTool_H
