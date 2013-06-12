#ifndef AtlasSFrameUtils_TauContainer
#define AtlasSFrameUtils_TauContainer

// =============================================================================
#include <vector>

#include "AtlasSFrameUtils/include/Tau.h"
#include "D3PDObjects/include/TauD3PDObject.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Tau;
class VertexContainer;

namespace CommonTools
{
  class TLVTool;
  class IsoCorrectionTool;
}
namespace SelectionTools
{
  class TauSelectionTool;
}

// ============================================================================
class TauContainer
{
  public:
    TauContainer();
    ~TauContainer();

    void init( SelectionTools::TauSelectionTool*
             , CommonTools::TLVTool*
             , CommonTools::IsoCorrectionTool*
             );

    void clear();
    void prepTaus(D3PDReader::TauD3PDObject*, const VertexContainer&);
    void setCollection(TAU_COLLECTIONS, std::vector<Tau*>);

    size_t num(TAU_COLLECTIONS) const;
    const std::vector<Tau*> getTaus(TAU_COLLECTIONS) const;

    void print(TAU_COLLECTIONS, const VertexContainer&) const;

  private:
    std::vector<Tau> m_master_list;
    std::vector<std::vector<Tau*> > m_user_lists;

    SelectionTools::TauSelectionTool* m_tau_selection;
    CommonTools::TLVTool* m_tlv_tool;
    CommonTools::IsoCorrectionTool* m_iso_corr_tool;
};

#endif
