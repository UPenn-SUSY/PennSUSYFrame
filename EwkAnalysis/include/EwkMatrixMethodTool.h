#ifndef EwkAnalysis_EwkMatrixMethodTool_h
#define EwkAnalysis_EwkMatrixMethodTool_h

// =============================================================================
#include <vector>
#include <string>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "RootCore/SusyMatrixMethod/SusyMatrixMethod/DiLeptonMatrixMethod.h"


// =============================================================================
namespace PennSusyFrame
{
  class Electron;
  class Muon;
  class Met;
}

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class MatrixMethodTool
  {
    // -----------------------------------------------------------------------------
    public:
      MatrixMethodTool();
      ~MatrixMethodTool();

      void init();

      double getSF( FLAVOR_CHANNEL
                  , const std::vector<PennSusyFrame::Electron*>*
                  , const std::vector<PennSusyFrame::Muon*>*
		  , const PennSusyFrame::Met  
                  );

    // -----------------------------------------------------------------------------
    private:
      // TODO make this configurable
      std::string m_fake_rate_file;

      SusyMatrixMethod::DiLeptonMatrixMethod m_matrix_method;
  };
}

#endif
