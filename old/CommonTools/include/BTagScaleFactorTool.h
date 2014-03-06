#ifndef CommonTools_BTagScaleFactorTool_h
#define CommonTools_BTagScaleFactorTool_h

// =============================================================================
#include <string>
#include <vector>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SUSYTools//BTagCalib.h" 

// =============================================================================
class Jet;

// =============================================================================
namespace CommonTools
{
  // ===========================================================================
  class BTagScaleFactorTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    BTagScaleFactorTool(SCycleBase* parent, const char* name);
    ~BTagScaleFactorTool();
    void BeginInputData( const SInputData& id );
    void BeginCycle();
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void clear();
    double getSF(const std::vector<Jet*>&);

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool c_do_b_tag_sf;
    std::string c_calibration_file;
    std::string c_calibration_folder;

    double m_b_tag_sf;
    bool m_is_cached;

    BTagCalib *m_b_tag_calibration;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(BTagScaleFactorTool, 0);
  };
} // CommonTools

#endif // CommonTools_BTagScaleFactorTool_h



