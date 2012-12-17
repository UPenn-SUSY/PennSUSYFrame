// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_JetOutputTool_h
#define CommonTools_JetOutputTool_h

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
  class JetOutputTool : public ToolBase
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    JetOutputTool(SCycleBase* parent, const char* name = "OutputTool");
    virtual ~JetOutputTool();

    virtual void BeginInputData( const SInputData& );
    virtual void BeginExecuteEvent( const SInputData&, Double_t );

    void fillOutput( Event*
                   , ElectronContainer&
                   , MuonContainer&
                   , JetContainer&
                   , Met*
                   , VertexContainer&
                   );

  // ----------------------------------------------------------------------------
  private:

    bool c_do_detailed_output;
    std::string c_jet_output_collection;

    //Variables to always output
    unsigned int m_num_baseline_jets;
    unsigned int m_num_good_jets;
    unsigned int m_num_light_jets;
    unsigned int m_num_b_jets;
    unsigned int m_num_forward_jets;

    std::vector<float> m_jet_pt;
    std::vector<float> m_jet_eta;
    std::vector<float> m_jet_phi;
    std::vector<float> m_jet_bjet_mv1;
    std::vector<float> m_jet_dr_signal_lep;
    std::vector<float> m_jet_jvf;
    std::vector<ull_t> m_jet_desc;

    std::vector<float> m_jet_dphi_met;

    std::vector<TLorentzVector> m_jet_tlv;

    // Detailed Variables to output only if configured to

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(JetOutputTool, 0);
  };
}

#endif
