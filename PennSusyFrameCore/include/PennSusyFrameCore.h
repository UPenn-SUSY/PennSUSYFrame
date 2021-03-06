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
  struct SystematicStruct;
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
      virtual void setIsData(bool val = true) { m_is_data = val; }
      virtual void setIsMC(  bool val = true) { m_is_data = !val; }

      virtual void setIsEgammaStream(bool val = true) { m_is_egamma_stream = val; }
      virtual void setIsMuonStream(  bool val = true) { m_is_egamma_stream = !val; }

      virtual void setIsBlind(   bool val = true) { m_is_blind = val; }
      virtual void setIsNotBlind(bool val = true) { m_is_blind = !val; }

      virtual void setFullSim() { m_is_af2 = false; }
      virtual void setAf2() {     m_is_af2 = true; }

      virtual void setIsMC12a() { m_is_mc12b = false; }
      virtual void setIsMC12b() { m_is_mc12b = true; }

      virtual void setStartEntry(unsigned int val) { m_start_entry = val; }
      virtual void setMaxNumEvents(int val)        { m_max_num_events = val; }

      virtual void setCrossSection(float val) { m_x_sec = val; }
      virtual void setKFactor(     float val) { m_k_factor = val; }
      virtual void setFilterEff(   float val) { m_filter_eff = val; }

      virtual void setTotalNumEntries(   int   val) { m_num_entries          = val; }
      virtual void setNumGeneratedEvents(int   val) { m_num_generated_events = val; }
      virtual void setSumMCEventWeights( float val) { m_sum_mc_event_weights = val; }

      virtual void setFancyProgressBar(bool val) { m_fancy_progress_bar = val; }
      virtual void setProcessLabel(std::string val) { m_process_label = val; }

      virtual void setMV1Cut(float val) { m_mv1_cut_value = val; }

      SystematicStruct * getSystematicStruct() { return &m_syst_struct; }

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
      bool m_is_egamma_stream;
      bool m_is_blind;
      bool m_is_af2;
      bool m_is_mc12b;
      double m_event_weight;
      bool m_pass_event;

      float m_x_sec;
      float m_k_factor;
      float m_filter_eff;
      float m_xsec_weight;

      int   m_num_entries;
      int   m_num_generated_events;
      float m_sum_mc_event_weights;

      bool m_fancy_progress_bar;
      std::string m_process_label;

      float m_mv1_cut_value;

      // struct to determine the systematics for this run
      SystematicStruct m_syst_struct;

      // boolians to turn on systematic shifts
      // bool m_do_jer;
      // bool m_do_jes_up;
      // bool m_do_jes_down;

      // bool m_do_effectivenp_1Up;
      // bool m_do_effectivenp_1Down;
      // bool m_do_effectivenp_2Up;
      // bool m_do_effectivenp_2Down;
      // bool m_do_effectivenp_3Up;
      // bool m_do_effectivenp_3Down;
      // bool m_do_effectivenp_4Up;
      // bool m_do_effectivenp_4Down;
      // bool m_do_effectivenp_5Up;
      // bool m_do_effectivenp_5Down;
      // bool m_do_effectivenp_6Up;
      // bool m_do_effectivenp_6Down;
      // bool m_do_etaintercalibration_modellingUp;
      // bool m_do_etaintercalibration_modellingDown;
      // bool m_do_etaintercalibration_statandmethodUp;
      // bool m_do_etaintercalibration_statandmethodDown;
      // bool m_do_singleparticle_highptUp;
      // bool m_do_singleparticle_highptDown;
      // bool m_do_relativenonclosure_pythia8Up;
      // bool m_do_relativenonclosure_pythia8Down;
      // bool m_do_pileupoffsettermmuup;
      // bool m_do_pileupoffsettermmudown;
      // bool m_do_pileupoffsettermnpvup;
      // bool m_do_pileupoffsettermnpvdown;
      // bool m_do_pileuppttermup;
      // bool m_do_pileuppttermdown;
      // bool m_do_pileuprhotopologyup;
      // bool m_do_pileuprhotopologydown;
      // bool m_do_closebyup;
      // bool m_do_closebydown;
      // bool m_do_flavorcompuncertup;
      // bool m_do_flavorcompuncertdown;
      // bool m_do_flavorresponseuncertup;
      // bool m_do_flavorresponseuncertdown;
      // bool m_do_bjesup;
      // bool m_do_bjesdown;

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
