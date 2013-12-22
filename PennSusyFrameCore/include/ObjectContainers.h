#ifndef PennSusyFrame_ObjectContainers
#define PennSusyFrame_ObjectContainers

// =============================================================================
#include <vector>

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
// class Electron;
// class VertexContainer;
// 
// namespace CommonTools
// {
//   class IsoCorrectionTool;
//   class TLVTool;
// }
// namespace D3PDReader
// {
//   class ElectronD3PDObject;
// }
// namespace SelectionTools
// {
//   class ElectronSelectionTool;
// }

// ============================================================================
namespace PennSusyFrame
{
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
      void prepElectrons(PennSusyFrame::D3PDReader*, const VertexContainer&);
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
}

#endif
