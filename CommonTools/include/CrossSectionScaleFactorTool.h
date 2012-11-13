#ifndef CommonTools_CrossSectionScaleFactorTool_h
#define CommonTools_CrossSectionScaleFactorTool_h

#include <vector>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "D3PDObjects/include/EventInfoD3PDObject.h"
#include "D3PDObjects/include/TruthD3PDObject.h"
#include "SUSYTools/SUSYCrossSection.h"

// ============================================================================
namespace CommonTools
{
  // ============================================================================
  class CrossSectionScaleFactorTool : public ToolBase 
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    CrossSectionScaleFactorTool(SCycleBase* parent, const char* name);
    ~CrossSectionScaleFactorTool();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void init();
    void clear();
    
    void BeginInputData(const SInputData& id);
    void EndInputData(  const SInputData& id);
    
    float getSF(                  const D3PDReader::TruthD3PDObject&);
    float getCrossSectionTimesEff(const D3PDReader::TruthD3PDObject&);
    float getCrossSection(        const D3PDReader::TruthD3PDObject&);
    float getKFactor(             const D3PDReader::TruthD3PDObject&);
    float getEfficiency(          const D3PDReader::TruthD3PDObject&);
    float getRelUncertainty(      const D3PDReader::TruthD3PDObject&);
    std::string getName(          const D3PDReader::TruthD3PDObject&);
    
  // ----------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // user configurables 
    bool c_do_cross_section_sf;
    std::string c_cross_section_file;


    float m_sf;
    float m_cross_section_times_eff;
    float m_cross_section;
    float m_k_factor;
    float m_efficiency;
    float m_rel_uncertainty;
    std::string m_name;
    
    bool m_cached_sf;
    bool m_cached_cs_x_eff;
    bool m_cached_cs;
    bool m_cached_k_factor;
    bool m_cached_efficiency;
    bool m_cached_rel_uncertainty;
    bool m_cached_name;


    double c_data_lumi;
    int c_mc_num_events;
    
    SUSY::CrossSectionDB* m_cross_section_db;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(CrossSectionScaleFactorTool, 0);
  };
} // CommonTools 

#endif // CommonTools_CrossSectionScaleFactorTool_h
