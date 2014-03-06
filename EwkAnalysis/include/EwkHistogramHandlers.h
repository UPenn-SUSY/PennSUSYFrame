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
  };
}

#endif
