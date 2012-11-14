#ifndef AtlasSFrameUtils_JetContainer
#define AtlasSFrameUtils_JetContainer

#include <iostream>
#include <vector>

#include "ParticleElementBuilder.h"
#include "Event.h"
#include "Jet.h"
#include "VertexContainer.h"

#include "CommonTools/include/TLVTool.h"

#include "SelectionTools/include/JetSelectionTool.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
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
