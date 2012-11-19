// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_MuonOutputTool_h
#define CommonTools_MuonOutputTool_h

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
  class MuonOutputTool : public ToolBase
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    MuonOutputTool(SCycleBase* parent, const char* name = "OutputTool");
    virtual ~MuonOutputTool();

    virtual void BeginInputData( const SInputData& );
    virtual void BeginExecuteEvent( const SInputData&, Double_t );


    void fillOutput(Event*, ElectronContainer, MuonContainer, JetContainer, Met*, VertexContainer );

  // ----------------------------------------------------------------------------
  private:

    bool c_do_detailed_output;

    std::string c_muon_output_collection;

    //Variables to always output

    std::vector<double>       m_mu_pt;
    std::vector<double>       m_mu_eta;
    std::vector<double>       m_mu_phi;
    std::vector<double>       m_mu_cov_d0;
    std::vector<double>       m_mu_d0;
    std::vector<double>       m_mu_z0;
    std::vector<double>       m_mu_d0_sig;
    std::vector<double>       m_mu_z0_sin_theta;
    std::vector<int>          m_mu_charge;
    std::vector<double>       m_mu_etcone20;
    std::vector<double>       m_mu_etcone30;
    std::vector<double>       m_mu_etcone40;
    std::vector<double>       m_mu_ptcone20;
    std::vector<double>       m_mu_ptcone30;
    std::vector<double>       m_mu_ptcone40;


    std::vector<unsigned int> m_mu_desc;


    // Detailed Variables to output only if configured to 

    std::vector<int>          m_mu_b_layer_hits;
    std::vector<int>          m_mu_num_pix_hits;
    std::vector<int>          m_mu_num_sct_hits;
    std::vector<int>          m_mu_num_trt_hits;
    std::vector<int>          m_mu_expect_b_layer_hit;
    std::vector<int>          m_mu_num_pix_holes;
    std::vector<int>          m_mu_num_sct_holes;
    std::vector<int>          m_mu_num_trt_outliers;
    std::vector<int>          m_mu_num_trt_ht_outliers;
    std::vector<int>          m_mu_num_mdt_layers;

    std::vector<double>       m_mu_raw_etcone20;
    std::vector<double>       m_mu_raw_etcone30;
    std::vector<double>       m_mu_raw_etcone40;
    std::vector<double>       m_mu_raw_ptcone20;
    std::vector<double>       m_mu_raw_ptcone30;
    std::vector<double>       m_mu_raw_ptcone40;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(MuonOutputTool, 0);
  };
}

#endif
