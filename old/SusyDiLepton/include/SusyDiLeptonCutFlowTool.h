// Dear emacs, this is -*- c++ -*-
#ifndef SusyDiLeptonCutFlowTool_H
#define SusyDiLeptonCutFlowTool_H

// =============================================================================
#include "AtlasSFrameUtils/include/ToolBase.h"

// =============================================================================
class Event;
class ElectronContainer;
class MuonContainer;
class TauContainer;
class JetContainer;
class Met;
class VertexContainer;
class Trigger;
class TriggerVec;

namespace CommonTools
{
  class TruthMatchTool;
  class ChargeFlipScaleFactorTool;
}
namespace D3PDReader
{
  class MuonTruthD3PDObject;
  class TruthD3PDObject;
}
namespace SelectionTools
{
  class GoodRunsListTool;
  class EventCleaningTool;
  class TriggerCutTool;
  class HFORTool;
}

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
                      , TauContainer&
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
                         , TauContainer&
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
                                , TauContainer&
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
  bool c_crit_tile_trip;
  bool c_crit_bad_jet_veto;
  bool c_crit_calo_problem_jets;
  bool c_crit_primary_vertex;
  bool c_crit_bad_mu_veto;
  bool c_crit_cosmic_mu_veto;
  bool c_crit_hfor;
  bool c_crit_mc_overlap;
  bool c_crit_ge_2_lep;
  bool c_crit_2_lep;
  bool c_crit_tau_veto;
  bool c_crit_mll;
  bool c_crit_signal_lep;
  bool c_crit_phase_space;
  bool c_crit_trigger;
  bool c_crit_trigger_match;
  bool c_crit_prompt_leptons;
  bool c_crit_stream_overlap;

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
