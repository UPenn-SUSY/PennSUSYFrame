#ifndef AtlasSFrameUtils_JetContainer
#define AtlasSFrameUtils_JetContainer

#include <iostream>
#include <vector>

#include "ParticleElementBuilder.h"
#include "Event.h"
#include "Jet.h"
#include "VertexContainer.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

#include "CommonTools/include/TLVTool.h"

// ============================================================================
class JetContainer
{
  public:
    JetContainer();
    ~JetContainer();

    void init(CommonTools::TLVTool*);

    void clear();
    void prepJets( D3PDReader::JetD3PDObject*
                 , const Event*
                 , const VertexContainer&
                 );
    void setCollection(JET_COLLECTIONS, std::vector<Jet*>);

    size_t num(JET_COLLECTIONS) const;
    const std::vector<Jet*> getJets(JET_COLLECTIONS) const;

    void print(JET_COLLECTIONS) const;

  private:
    std::vector<Jet> m_master_list;
    std::vector<std::vector<Jet*> > m_user_lists;

    CommonTools::TLVTool* m_tlv_tool;
};

#endif
