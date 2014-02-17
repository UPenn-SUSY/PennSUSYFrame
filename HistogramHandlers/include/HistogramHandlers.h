#ifndef PennSusyFrame_HistogramHandlers_h
#define PennSusyFrame_HistogramHandlers_h

// =============================================================================
#include <vector>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
class TFile;
class TH1F;

namespace PennSusyFrame
{
  class Event;
  class Electron;
  class Muon;
  class Jet;
}

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  // = HistogramHandler - used as parent class for other histograms
  // =============================================================================
  class HistogramHandler
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      HistogramHandler();

      virtual void Fill( const PennSusyFrame::Event&
                       , const std::vector<PennSusyFrame::Electron*>*
                       , const std::vector<PennSusyFrame::Muon*>*
                       , const std::vector<PennSusyFrame::Jet*>*
                       , float weight
                       );
      virtual void write(TFile*);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
  };

  // =============================================================================
  // = LeptonKinematicsHists
  // =============================================================================
  class LeptonKinematicsHists
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      LeptonKinematicsHists();

      virtual void Fill( const PennSusyFrame::Event&
                       , const std::vector<PennSusyFrame::Electron*>*
                       , const std::vector<PennSusyFrame::Muon*>*
                       , const std::vector<PennSusyFrame::Jet*>*
                       , float weight
                       );
      virtual void write(TFile*);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      std::vector<TH1F*> m_h_pt_all;
      std::vector<TH1F*> m_h_pt_0;
      std::vector<TH1F*> m_h_pt_1;
  };
}

#endif
