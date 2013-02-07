#ifndef AtlasSFrameUtils_VertexContainer
#define AtlasSFrameUtils_VertexContainer

#include <iostream>
#include <vector>

#include "Vertex.h"

#include "D3PDObjects/include/VertexD3PDObject.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// ============================================================================
class VertexContainer
{
  public:
    VertexContainer();
    ~VertexContainer();

    void init();

    void clear();
    void prepVertices(D3PDReader::VertexD3PDObject*, bool is_data);
    void setCollection(VERTEX_COLLECTIONS, std::vector<Vertex*>);

    size_t num(VERTEX_COLLECTIONS) const;
    const std::vector<Vertex*>* getVertexs(VERTEX_COLLECTIONS) const;
    bool firstGood(VERTEX_COLLECTIONS) const;

    void print(VERTEX_COLLECTIONS) const;

  private:
    std::vector<Vertex> m_master_list;
    std::vector<std::vector<Vertex*> > m_user_lists;
};

#endif
