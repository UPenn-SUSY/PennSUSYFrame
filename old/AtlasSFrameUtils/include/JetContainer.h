#ifndef AtlasSFrameUtils_JetContainer
#define AtlasSFrameUtils_JetContainer

// =============================================================================
#include <vector>

#include "AtlasSFrameUtils/include/Jet.h"
#include "D3PDObjects/include/JetD3PDObject.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Event;
class Jet;
class VertexContainer;

namespace CommonTools
{
  class TLVTool;
}
namespace D3PDReader
{
  class JetD3PDObject;
}
namespace SelectionTools
{
  class JetSelectionTool;
}

// ============================================================================
class JetContainer
{
  public:
    JetContainer();
    ~JetContainer();

    void init( SelectionTools::JetSelectionTool*
             , CommonTools::TLVTool*
             );


    void clear();
    void prepJets( D3PDReader::JetD3PDObject*
                 , const Event*
                 , const VertexContainer&
                 );
    void setCollection(JET_COLLECTIONS, std::vector<Jet*>);
    void setCombinedCollections();

    size_t num(JET_COLLECTIONS) const;
    const std::vector<Jet*> getJets(JET_COLLECTIONS) const;

    void print(JET_COLLECTIONS) const;

  private:
    std::vector<Jet> m_master_list;
    std::vector<std::vector<Jet*> > m_user_lists;

    SelectionTools::JetSelectionTool* m_jet_selection;
    CommonTools::TLVTool* m_tlv_tool;
};

#endif
