#ifndef EwkAnalysis_EwkChargeFlipTool_h
#define EwkAnalysis_EwkChargeFlipTool_h

// =============================================================================
#include <vector>
#include <string>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
namespace PennSusyFrame
{
  class Electron;
  class Muon;
}

class chargeFlip;

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class ChargeFlipTool
  {
    // -----------------------------------------------------------------------------
    public:
      ChargeFlipTool();
      ~ChargeFlipTool();

      void init();

      double getSF( FLAVOR_CHANNEL
                  , const std::vector<PennSusyFrame::Electron*>*
                  , const std::vector<PennSusyFrame::Muon*>*
                  );

    // -----------------------------------------------------------------------------
    private:
      // TODO make this configurable
      std::string m_charge_flip_map_file;

      chargeFlip* m_charge_flip;
  };
}

#endif
