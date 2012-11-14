#ifndef AtlasSFrameUtils_MuonContainer
#define AtlasSFrameUtils_MuonContainer

#include <iostream>
#include <vector>

#include "ParticleElementBuilder.h"
#include "Muon.h"
#include "VertexContainer.h"

#include "CommonTools/include/TLVTool.h"
#include "CommonTools/include/IsoCorrectionTool.h"

#include "SelectionTools/include/MuonSelectionTool.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
namespace SelectionTools
{
  class MuonSelectionTool;
}

// ============================================================================
class MuonContainer
{
  public:
    MuonContainer();
    ~MuonContainer();

    void init( SelectionTools::MuonSelectionTool*
             , CommonTools::TLVTool*
             , CommonTools::IsoCorrectionTool*
             );

    void clear();
    void prepMuons(D3PDReader::MuonD3PDObject*);
    void setCollection(MUON_COLLECTIONS, std::vector<Muon*>);

    size_t num(MUON_COLLECTIONS) const;
    const std::vector<Muon*> getMuons(MUON_COLLECTIONS) const;

    void print(MUON_COLLECTIONS, const VertexContainer&) const;

  private:
    std::vector<Muon> m_master_list;
    std::vector<std::vector<Muon*> > m_user_lists;

    SelectionTools::MuonSelectionTool* m_muon_selection;
    CommonTools::TLVTool* m_tlv_tool;
    CommonTools::IsoCorrectionTool* m_iso_corr_tool;
};

#endif
