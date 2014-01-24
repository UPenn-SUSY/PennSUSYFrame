#ifndef PennSusyFrame_EventSelectors_h
#define PennSusyFrame_EventSelectors_h

#include <string>
#include <vector>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsList.h"
#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsListReader.h"

// =============================================================================
namespace PennSusyFrame
{
  class Event;
  // class Electron;
  // class Muon;
  // class Met;
}

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class GrlTool
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      GrlTool();

      void init(const std::string&, bool do_grl = true);

      bool passEvent(const PennSusyFrame::Event&);
      bool passEvent(unsigned int run, unsigned int lb);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      bool m_do_grl;
      std::string m_grl_file_name;
      Root::TGoodRunsList m_grl;
  };
}

// Include the implementation:
#ifndef __CINT__
#include "EventSelectors.icc"
#endif // __CINT__

#endif
