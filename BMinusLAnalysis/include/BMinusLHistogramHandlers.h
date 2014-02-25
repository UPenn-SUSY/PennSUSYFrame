#ifndef PennSusyFrame_BMinusLHistogramHandlers_h
#define PennSusyFrame_BMinusLHistogramHandlers_h

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
  // = BMinusLHists
  // =============================================================================
  class BMinusLHists : public HistogramHandler
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      BMinusLHists();
      BMinusLHists(std::string);
      virtual ~BMinusLHists();

      virtual void FillSpecial( const PennSusyFrame::Event&
                              , const std::vector<PennSusyFrame::Jet*>* b_jets
                              , const PennSusyFrame::blPair&
                              , const PennSusyFrame::blPair&
                              , float weight
                              );
      virtual void write(TDirectory*);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      std::vector<TH1F*> m_h_num_b_jet;

      std::vector<TH1F*> m_h_b_jet_pt_all;
      std::vector<TH1F*> m_h_b_jet_pt_0;
      std::vector<TH1F*> m_h_b_jet_pt_1;

      std::vector<TH1F*> m_h_mbl_all;
      std::vector<TH1F*> m_h_mbl_0;
      std::vector<TH1F*> m_h_mbl_1;

      std::vector<TH1F*> m_h_ptbl_all;
      std::vector<TH1F*> m_h_ptbl_0;
      std::vector<TH1F*> m_h_ptbl_1;

      std::vector<TH1F*> m_h_mbl_anti_pairing_all;
      std::vector<TH1F*> m_h_mbl_anti_pairing_0;
      std::vector<TH1F*> m_h_mbl_anti_pairing_1;
  };
}

#endif
