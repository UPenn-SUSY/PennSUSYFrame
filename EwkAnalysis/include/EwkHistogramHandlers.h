#ifndef PennSusyFrame_EwkHistogramHandlers_h
#define PennSusyFrame_EwkHistogramHandlers_h

// =============================================================================
#include <vector>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "HistogramHandlers/include/HistogramHandlers.h"

// =============================================================================
class TFile;
class TDirectory;
class TH1F;

namespace PennSusyFrame
{
  class Event;
  class Electron;
  class Muon;
  class Jet;
  class Met;

  class blPair;
}

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  // = EwkHists
  // =============================================================================
  class EwkHists : public HistogramHandler
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      EwkHists(std::string name_tag="");
      virtual ~EwkHists();

      virtual void FillSpecial( const PennSusyFrame::Event&
                              , const std::vector<PennSusyFrame::Jet*>* jets
                              , float weight
                              );      
      void FillBDT( const PennSusyFrame::Event& event
                    , float bdt_score
                    , float weight);
      void FillIsr(const PennSusyFrame::Event& event
		   , const PennSusyFrame::EventLevelQuantities& event_level_quantities
		   , const std::vector<PennSusyFrame::Electron*>*
		   , const std::vector<PennSusyFrame::Muon*>*
		   , const std::vector<PennSusyFrame::Jet*>*
		   , const PennSusyFrame::Met&
		   , float weight
		   );

      virtual void write(TDirectory*);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      std::vector<TH1F*> m_h_num_b_jet;

      std::vector<TH1F*> m_h_b_jet_pt_all;
      std::vector<TH1F*> m_h_b_jet_pt_0;
      std::vector<TH1F*> m_h_b_jet_pt_1;

      std::vector<TH1F*> m_h_jet_sum_pt;

      std::vector<TH1F*> m_h_mbl_all;
      std::vector<TH1F*> m_h_mbl_0;
      std::vector<TH1F*> m_h_mbl_1;

      std::vector<TH1F*> m_h_bdt_score;

      std::vector<TH1F*> m_h_mtr1;
      std::vector<TH1F*> m_h_mtr2;

      std::vector<TH1F*> m_h_ratio_met_jet;
      std::vector<TH1F*> m_h_ratio_lep_jet;
      std::vector<TH1F*> m_h_dphi_met_jet;
  };
}

#endif
