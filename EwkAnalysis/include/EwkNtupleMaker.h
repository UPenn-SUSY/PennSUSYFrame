#ifndef EWKNTUPLEMAKER_H
#define EWKNTUPLEMAKER_H
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"
#include "PennSusyFrameCore/include/EventSelectors.h"
#include "HistogramHandlers/include/HistogramHandlers.h"
#include "EwkAnalysis/include/EwkHistogramHandlers.h"
#include "EwkAnalysis/include/EwkCutFlowTracker.h"
#include "EwkAnalysis/include/EwkChargeFlipTool.h"
#include "EwkAnalysis/include/EwkMatrixMethodTool.h"
#include "EwkAnalysis/include/EwkAnalysis.h"
// =============================================================================
namespace PennSusyFrame
{
  // ===========================================================================
  class EwkNtupleMaker : public EwkAnalysis
  {
  public :
    EwkNtupleMaker(TTree *tree=0);
    virtual ~EwkNtupleMaker();
    void beginRun();
    void processEvent();
    void configureOutput( std::string out_file_name
                          , std::string out_tree_name
                          );
    void clearVariables();
    void finalizeRun();
    void setOutNtupleFileName(std::string val) { m_out_ntuple_file_name = val; }
    std::string m_out_ntuple_file_name;
    std::vector<float> getSelectionPt (std::vector<PennSusyFrame::Particle*>* obj);
    std::vector<float> getSelectionPhi(std::vector<PennSusyFrame::Particle*>* obj);
    std::vector<float> getSelectionEta(std::vector<PennSusyFrame::Particle*>* obj);
    std::vector<bool> getSelectionSignal(std::vector<PennSusyFrame::Particle*>* obj);
    void getSortLepPts(float i1, float i2, std::vector<float> pt, std::vector<float> eta, std::vector<float> phi, std::vector<bool> signal);
    void fillNtuple(float weight);
    void setOutNtupFileName(std::string val) { m_out_ntuple_file_name = val; }
  private:
    bool doBaselineSkim;
    int m_num_light_jets;
    int m_num_forward_jets;
    int m_num_jets;
    int m_num_el;
    int m_num_mu;
    TFile* m_output_file;
    TTree* m_output_tree;
    int m_event_number;
    int m_run_number;
    bool m_isSS;
    bool m_isEE;
    bool m_isEM;
    bool m_isMM;
    float m_weight;
    float m_cfweight;
    float m_mll;
    float m_ptll;
    float m_mt;
    float m_mt2;
    float m_dphill;
    std::vector<float> m_el_pt;
    std::vector<float> m_el_eta;
    std::vector<float> m_el_phi;
    std::vector<bool> m_el_signal;
    std::vector<float> m_mu_pt;
    std::vector<float> m_mu_eta;
    std::vector<float> m_mu_phi;
    std::vector<bool> m_mu_signal;
    std::vector<float> m_lep_pt;
    std::vector<float> m_lep_eta;
    std::vector<float> m_lep_phi;
    std::vector<bool> m_lep_signal;
    std::vector<float> m_jet_pt;
    std::vector<float> m_jet_eta;
    std::vector<float> m_jet_phi;
    std::vector<float> m_ljet_pt;	
    std::vector<float> m_ljet_eta;
    std::vector<float> m_ljet_phi;
    float m_met_et;
    float m_met_rel;
    float m_met_phi;
    float m_ht_signal;

  };
}
#endif
