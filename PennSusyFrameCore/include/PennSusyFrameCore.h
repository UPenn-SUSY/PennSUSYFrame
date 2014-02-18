#ifndef PENNSUSYFRAME_H
#define PENNSUSYFRAME_H

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "PennSusyFrameCore/include/ObjectContainers.h"
#include "PennSusyFrameCore/include/ObjectSelectors.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ScaleFactorTools.h"
#include "PennSusyFrameCore/include/TruthMatchTools.h"
#include "HistogramHandlers/include/HistogramHandlers.h"

// =============================================================================
class TBranch;

namespace PennSusyFrame
{
  class D3PDReader;
}

// =============================================================================
namespace PennSusyFrame
{
  // ===========================================================================
  class PennSusyFrameCore
  {
    public :
      PennSusyFrameCore(TTree *tree=0);
      virtual ~PennSusyFrameCore();
      virtual Int_t    GetEntry(Long64_t entry);
      virtual Long64_t LoadTree(Long64_t entry);
      virtual void     Init(TTree *tree);
      virtual void     Loop();
      virtual Bool_t   Notify();

      virtual void prepareTools();

      // TODO move accessor to cxx file
      virtual void setIsData() { m_is_data = true; }
      virtual void setIsMC()   { m_is_data = false; }

      virtual void setFullSim() { m_is_af2 = false; }
      virtual void setAf2() { m_is_af2 = true; }

      virtual void prepareSelection();

      virtual void beginRun();
      virtual void processEvent();
      virtual void finalizeEvent();
      virtual void finalizeRun();

    protected:
      virtual FLAVOR_CHANNEL findFlavorChannel();
      virtual SIGN_CHANNEL   findSignCannel();

      virtual void clearObjects();
      virtual void constructObjects();

      virtual void configureTnt( std::string out_file_name
                               , std::string out_tree_name
                               );
      virtual void fillTnt();
      virtual void writeTnt();

      bool m_is_data;
      bool m_is_af2;
      double m_event_weight;
      bool m_pass_event;

      TTree* m_tree;
      PennSusyFrame::D3PDReader* m_d3pd_reader;

      PennSusyFrame::Event                m_event;
      PennSusyFrame::EventLevelQuantities m_event_quantities;
      PennSusyFrame::Trigger              m_trigger;
      PennSusyFrame::Met                  m_met;
      PennSusyFrame::VertexContainer      m_vertices;
      PennSusyFrame::ElectronContainer    m_electrons;
      PennSusyFrame::MuonContainer        m_muons;
      PennSusyFrame::TauContainer         m_taus;
      PennSusyFrame::JetContainer         m_jets;

      PennSusyFrame::MCTruth m_mc_truth;

      std::vector<PennSusyFrame::VertexSelector>   m_vertex_selectors;
      std::vector<PennSusyFrame::ElectronSelector> m_electron_selectors;
      std::vector<PennSusyFrame::MuonSelector>     m_muon_selectors;
      std::vector<PennSusyFrame::TauSelector>      m_tau_selectors;
      std::vector<PennSusyFrame::JetSelector>      m_jet_selectors;

      PennSusyFrame::ObjectCleaning m_object_cleaning;

      PennSusyFrame::PileUpScaleFactorTool m_pile_up_sf_tool;
      PennSusyFrame::EgammaScaleFactorTool m_egamma_sf_tool;
      PennSusyFrame::MuonScaleFactorTool   m_muon_sf_tool;
      PennSusyFrame::TriggerWeightTool     m_trigger_weight_tool;
      PennSusyFrame::BTagScaleFactorTool   m_b_tag_sf_tool;

      PennSusyFrame::TruthMatchTool        m_truth_match_tool;

      std::vector<PennSusyFrame::HistogramHandler*> m_histogram_handlers;

    private:
  };
}

#endif
