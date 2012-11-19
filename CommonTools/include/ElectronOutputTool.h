/// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_ElectronOutputTool_h
#define CommonTools_ElectronOutputTool_h

#include "AtlasSFrameUtils/include/ToolBase.h"

#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// ============================================================================
// Forward declare SusyDiLeptonCutFlowCycle
class SusyDiLeptonCutFlowCycle;
class SusyDiLeptonChargeFlipCycle;
// ============================================================================
namespace CommonTools
{
// ============================================================================
  class ElectronOutputTool : public ToolBase
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ElectronOutputTool(SCycleBase* parent, const char* name = "OutputTool");
    virtual ~ElectronOutputTool();

    virtual void BeginInputData( const SInputData& );
    virtual void BeginExecuteEvent( const SInputData&, Double_t );


    void fillOutput(Event*, ElectronContainer, MuonContainer, JetContainer, Met*, VertexContainer );

  // ----------------------------------------------------------------------------
  private:

    bool c_do_detailed_output;
    std::string c_electron_output_collection;
    std::string c_muon_output_collection;
    std::string c_jet_output_collection;


    //Variables to always output
    std::vector<double>          m_el_E;
    std::vector<double>          m_el_Et;
    std::vector<double>          m_el_pt;
    std::vector<double>          m_el_eta;
    std::vector<double>          m_el_eta_cl;
    std::vector<double>          m_el_eta_track;
    std::vector<double>          m_el_phi;
    std::vector<double>          m_el_phi_cl;
    std::vector<double>          m_el_phi_track;
    std::vector<double>          m_el_d0;
    std::vector<double>          m_el_d0_physics;
    std::vector<double>          m_el_d0_pv;
    std::vector<double>          m_el_z0;
    std::vector<double>          m_el_z0_pv;
    std::vector<double>          m_el_d0_pv_sig;
    std::vector<double>          m_el_z0_pv_sig;
    std::vector<double>          m_el_d0_sig;
    std::vector<double>          m_el_z0_sin_theta;
    std::vector<int>             m_el_charge;
    std::vector<double>          m_el_cf_smeared_pt;   
    std::vector<unsigned int>    m_el_desc;

   
    // Detailed Variables to output only if configured to 

    std::vector<unsigned int> m_el_OQ;
    std::vector<unsigned int> m_el_OQ_recalc;
    std::vector<double>       m_el_trt_ht_outlier_ratio;
    std::vector<int>          m_el_author;
    std::vector<int>          m_el_conv_flag;
    std::vector<int>          m_el_expect_b_layer;
    std::vector<double>       m_el_weta2;
    std::vector<double>       m_el_wstot;
    std::vector<double>       m_el_reta;
    std::vector<double>       m_el_ethad;
    std::vector<double>       m_el_ethad1;
    std::vector<int>          m_el_num_pix_hits;
    std::vector<int>          m_el_num_pix_holes;
    std::vector<int>          m_el_num_pix_outliers;
    std::vector<int>          m_el_num_sct_hits;
    std::vector<int>          m_el_num_sct_holes;
    std::vector<int>          m_el_num_sct_outliers;
    std::vector<int>          m_el_num_trt_hits;
    std::vector<int>          m_el_num_trt_holes;
    std::vector<int>          m_el_num_trt_outliers;
    std::vector<int>          m_el_num_trt_ht_hits;
    std::vector<int>          m_el_num_trt_ht_outliers;
    std::vector<int>          m_el_num_bl_hits;
    std::vector<int>          m_el_num_bl_outliers;
    std::vector<double>       m_el_fside;
    std::vector<double>       m_el_delta_eta1;
    std::vector<double>       m_el_delta_eta2;
    std::vector<double>       m_el_delta_phi2;
    std::vector<double>       m_el_emaxs1;
    std::vector<double>       m_el_f1;
    std::vector<double>       m_el_f3;


    std::vector<double> m_el_etcone20;
    std::vector<double> m_el_etcone30;
    std::vector<double> m_el_etcone40;
    std::vector<double> m_el_ptcone20;
    std::vector<double> m_el_ptcone30;
    std::vector<double> m_el_ptcone40;
    std::vector<double> m_el_topoetcone20;
    std::vector<double> m_el_topoetcone30;
    std::vector<double> m_el_topoetcone40;
    std::vector<double> m_el_topoetcone20_corrected;
    std::vector<double> m_el_topoetcone30_corrected;
    std::vector<double> m_el_topoetcone40_corrected;
    std::vector<double> m_el_raw_etcone20;
    std::vector<double> m_el_raw_etcone30;
    std::vector<double> m_el_raw_etcone40;
    std::vector<double> m_el_raw_ptcone20;
    std::vector<double> m_el_raw_ptcone30;
    std::vector<double> m_el_raw_ptcone40;
    std::vector<double> m_el_raw_topoetcone20;
    std::vector<double> m_el_raw_topoetcone30;
    std::vector<double> m_el_raw_topoetcone40;
    std::vector<double> m_el_raw_topoetcone20_corrected;
    std::vector<double> m_el_raw_topoetcone30_corrected;
    std::vector<double> m_el_raw_topoetcone40_corrected;


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(ElectronOutputTool, 0);
  };
}

#endif