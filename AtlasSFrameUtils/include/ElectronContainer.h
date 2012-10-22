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

// ============================================================================
enum ELECTRON_COLLECTIONS { EL_ALL = 0  // Green tree snake
                          , EL_BASELINE // Baseline cuts
                          , EL_GOOD     // Baseline + overlap removal
                          , EL_SIGNAL   // Signal cuts
                          , EL_N
                          };

// ============================================================================
class ElectronContainer
{
  public:
    ElectronContainer();
    ~ElectronContainer();

    void init( CommonTools::TLVTool*
             , CommonTools::IsoCorrectionTool*
             , SelectionTools::ElectronSelectionTool*
             );

    void clear();
    void prepElectrons(D3PDReader::ElectronD3PDObject*);
    void setCollection(ELECTRON_COLLECTIONS, std::vector<Electron*>);

    size_t num(ELECTRON_COLLECTIONS) const;
    const std::vector<Electron*>* getElectrons(ELECTRON_COLLECTIONS) const;

    void print(ELECTRON_COLLECTIONS, const VertexContainer&) const;

  private:
    std::vector<Electron> m_master_list;
    std::vector<std::vector<Electron*> > m_user_lists;

    CommonTools::TLVTool* m_tlv_tool;
    CommonTools::IsoCorrectionTool* m_iso_corr_tool;
    SelectionTools::ElectronSelectionTool* m_selection_tool;
};

#endif
