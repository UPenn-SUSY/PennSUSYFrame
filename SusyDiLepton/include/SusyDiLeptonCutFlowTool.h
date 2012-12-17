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
#include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/Trigger.h"
#include "AtlasSFrameUtils/include/TriggerVec.h"
#include "AtlasSFrameUtils/include/Vertex.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "CommonTools/include/SignChannel.h"
#include "CommonTools/include/MllTool.h"
#include "CommonTools/include/PtllTool.h"
#include "CommonTools/include/PhillTool.h"
#include "CommonTools/include/EtallTool.h"
#include "CommonTools/include/MTTool.h"
#include "CommonTools/include/MT2Tool.h"
#include "CommonTools/include/TopTagTool.h"
#include "CommonTools/include/TruthMatchTool.h"
#include "CommonTools/include/ChargeFlipScaleFactorTool.h"

#include "D3PDObjects/include/MuonTruthD3PDObject.h"
#include "D3PDObjects/include/TruthD3PDObject.h"

#include "SelectionTools/include/EventCleaningTool.h"
#include "SelectionTools/include/GoodRunsListTool.h"
#include "SelectionTools/include/TriggerCutTool.h"
#include "SelectionTools/include/HFORTool.h"

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
  virtual void BeginInputData(      const SInputData&) throw(SError);

  bool runBasicCutFlow( Event*
                      , ElectronContainer&
                      , MuonContainer&
                      , JetContainer&
                      , VertexContainer&
                      , const Trigger*
                      , const TriggerVec*
                      , D3PDReader::MuonTruthD3PDObject*
                      , D3PDReader::TruthD3PDObject*
                      , bool is_egamma_stream
                      );

  bool runAdvancedCutFlow( Event*
                         , ElectronContainer&
                         , MuonContainer&
                         , JetContainer&
                         , VertexContainer&
                         , const Trigger*
                         , const TriggerVec*
                         , D3PDReader::MuonTruthD3PDObject*
                         , D3PDReader::TruthD3PDObject*
                         , bool is_egamma_stream
                         );

  // This function computes event variables we only want for good events
  // Call this only after you have determined the flavor channel!
  void computeGoodEventVariables( Event*
                                , ElectronContainer&
                                , MuonContainer&
                                , JetContainer&
                                , Met*
                                );

  void setChargeFlipVariables(Event*
            , ElectronContainer&
            , MuonContainer&
            , D3PDReader::MuonTruthD3PDObject*
            , D3PDReader::TruthD3PDObject*
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
  SelectionTools::HFORTool*          m_hfor_tool;

  CommonTools::TruthMatchTool* m_truth_match_tool;
  CommonTools::ChargeFlipScaleFactorTool* m_charge_flip_sf_tool;
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  void getTools();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Macro adding the functions for dictionary generation
  ClassDef(SusyDiLeptonCutFlowTool, 0);

}; // class SusyDiLeptonCutFlowTool

#endif // SusyDiLeptonCutFlowTool_H
