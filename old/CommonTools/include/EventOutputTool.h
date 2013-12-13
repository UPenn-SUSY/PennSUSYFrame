// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_EventOutputTool_h
#define CommonTools_EventOutputTool_h

// =============================================================================
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Event;
class ElectronContainer;
class MuonContainer;
class JetContainer;
class Met;
class VertexContainer;

class SusyDiLeptonCutFlowCycle;
class SusyDiLeptonChargeFlipCycle;
// =============================================================================
namespace CommonTools
{
// =============================================================================
  class EventOutputTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    EventOutputTool(SCycleBase* parent, const char* name = "OutputTool");
    virtual ~EventOutputTool();

    virtual void BeginInputData( const SInputData& );
    virtual void BeginExecuteEvent( const SInputData&, Double_t );


    void fillOutput( Event*
                   , ElectronContainer&
                   , MuonContainer&
                   , JetContainer&
                   , Met*
                   , VertexContainer&
                   );

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    int c_output_level;
    int c_electron_output_collection;
    int c_muon_output_collection;
    int c_jet_output_collection;

    unsigned int m_run_number;
    unsigned int m_lbn;
    unsigned int m_event_number;

    ull_t m_event_desc_int;
    ull_t m_sr_helper_int;

    double m_mc_event_weight;
    double m_pileup_weight;
    double m_trigger_weight;
    double m_lepton_weight;
    double m_b_tag_weight;
    double m_cross_section_weight;
    double m_k_factor;
    double m_eff_times_cross_section;
    double m_fake_weight;
    double m_fake_weight_max;
    double m_fake_weight_min;
    double m_charge_flip_weight;
    double m_charge_flip_weight_max;
    double m_charge_flip_weight_min;

    unsigned int m_mc_channel_number;
    float m_actual_int_per_crossing;
    float m_average_int_per_crossing;

    float m_ht;
    float m_ht_jets;
    float m_ht_leptons;
    float m_mll;
    float m_ptll;
    float m_phill;
    float m_etall;
    float m_dphill;
    float m_mt;
    float m_mt2;
    float m_meff;
    float m_meff_jets;
    float m_meff_leptons;


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(EventOutputTool, 0);
  };
}

#endif
