#ifndef PENNSUSYFRAME_H
#define PENNSUSYFRAME_H

#include <string>

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
      virtual void setAf2() {     m_is_af2 = true; }

      virtual void setStartEntry(unsigned int val) { m_start_entry = val; }
      virtual void setMaxNumEvents(int val)        { m_max_num_events = val; }

      virtual void setCrossSection(float val) { m_x_sec = val; }
      virtual void setKFactor(     float val) { m_k_factor = val; }
      virtual void setFilterEff(   float val) { m_filter_eff = val; }

      virtual void setTotalNumEntries(int val) { m_num_entries = val; }
      virtual void setNumGeneratedEvents(int val) { m_num_generated_events = val; }

      virtual void setFancyProgressBar(bool val) { m_fancy_progress_bar = val; }
      virtual void setProcessLabel(std::string val) { m_process_label = val; }

      virtual void setMV1Cut(float val) { m_mv1_cut_value = val; }

      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      virtual void prepareSelection();

      virtual void beginRun();
      virtual void processEvent();
      virtual void finalizeEvent();
      virtual void finalizeRun();

    protected:
      // find the flavor channel of this event
      // -- if exclusive_flavor_channel == true, the function will require exactly
      //    a di-lepton event
      // -- if exclusive_flavor_channel == false, the function will consider the
      //    two leading leptons
      virtual FLAVOR_CHANNEL findFlavorChannel(bool exclusive_flavor_channel = true);
      virtual SIGN_CHANNEL   findSignCannel();

      virtual void clearObjects();
      virtual void constructObjects();
      virtual void getSelectedObjects();

      virtual void configureTnt( std::string out_file_name
                               , std::string out_tree_name
                               );
      virtual void fillTnt();
      virtual void writeTnt();

      unsigned int m_start_entry;
      int m_max_num_events;
      bool m_is_data;
      bool m_is_af2;
      double m_event_weight;
      bool m_pass_event;

      float m_x_sec;
      float m_k_factor;
      float m_filter_eff;
      float m_xsec_weight;

      int m_num_entries;
      int m_num_generated_events;

      bool m_fancy_progress_bar;
      std::string m_process_label;

      float m_mv1_cut_value;

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

      std::vector<std::vector<PennSusyFrame::HistogramHandler*> > m_histogram_handlers;

    private:
  };
}

#endif
