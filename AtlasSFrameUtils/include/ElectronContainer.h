#ifndef AtlasSFrameUtils_ElectronContainer
#define AtlasSFrameUtils_ElectronContainer

#include <iostream>
#include <vector>

#include "ParticleElementBuilder.h"
#include "Electron.h"
#include "VertexContainer.h"

#include "CommonTools/include/TLVTool.h"
#include "CommonTools/include/IsoCorrectionTool.h"

#include "SelectionTools/include/ElectronSelectionTool.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
namespace SelectionTools
{
  class ElectronSelectionTool;
}

// ============================================================================
class ElectronContainer
{
  public:
    ElectronContainer();
    ~ElectronContainer();

    void init( SelectionTools::ElectronSelectionTool*
             , CommonTools::TLVTool*
             , CommonTools::IsoCorrectionTool*
             );

    void clear();
    void prepElectrons(D3PDReader::ElectronD3PDObject*, const VertexContainer&);
    void setCollection(ELECTRON_COLLECTIONS, std::vector<Electron*>);

    size_t num(ELECTRON_COLLECTIONS) const;
    const std::vector<Electron*> getElectrons(ELECTRON_COLLECTIONS) const;

    void print(ELECTRON_COLLECTIONS, const VertexContainer&) const;

  private:
    std::vector<Electron> m_master_list;
    std::vector<std::vector<Electron*> > m_user_lists;

    SelectionTools::ElectronSelectionTool* m_electron_selection;
    CommonTools::TLVTool* m_tlv_tool;
    CommonTools::IsoCorrectionTool* m_iso_corr_tool;
};

#endif
