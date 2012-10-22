#include "include/VertexContainer.h"

// ----------------------------------------------------------------------------
VertexContainer::VertexContainer()
{
  m_user_lists.resize(VERT_N);
}

// ----------------------------------------------------------------------------
VertexContainer::~VertexContainer()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void VertexContainer::init()
{
  // TODO init, or say do nothing
}

// ----------------------------------------------------------------------------
void VertexContainer::clear()
{
  for (VERTEX_COLLECTIONS vert_collection = VERT_ALL
      ; vert_collection != VERT_N
      ; vert_collection = VERTEX_COLLECTIONS(vert_collection+1)
      ) {
    m_user_lists.at(vert_collection).clear();
  }
}

// ----------------------------------------------------------------------------
void VertexContainer::prepVertices(
    D3PDReader::VertexD3PDObject* vertex_d3pdobject, bool is_data)
{
  size_t num_vert = vertex_d3pdobject->n();
  m_master_list.reserve(num_vert);

  for (size_t vert_it = 0; vert_it != num_vert; ++vert_it) {
    Vertex tmp_vert(*vertex_d3pdobject, vert_it, is_data);
    m_master_list.push_back(tmp_vert);
  }

  size_t term = m_master_list.size();
  for (size_t vert_it = 0; vert_it != term; ++vert_it) {
    m_user_lists.at(VERT_ALL).push_back(&m_master_list.at(vert_it));

    if (m_master_list.at(vert_it).isGood()) {
      m_user_lists.at(VERT_GOOD).push_back(&m_master_list.at(vert_it));
    }
    if (m_master_list.at(vert_it).twoTracks()) {
      m_user_lists.at(VERT_GT_2).push_back(&m_master_list.at(vert_it));
    }
  }
}

// ----------------------------------------------------------------------------
void VertexContainer::setCollection( VERTEX_COLLECTIONS vert_collection
                                   , std::vector<Vertex*> vertices
                                   )
{
  m_user_lists.at(vert_collection) = vertices;
}

// ----------------------------------------------------------------------------
size_t VertexContainer::num(VERTEX_COLLECTIONS vert_collection) const

{
  return m_user_lists.at(vert_collection).size();
}

// ----------------------------------------------------------------------------
const std::vector<Vertex*>* VertexContainer::getVertexs(
    VERTEX_COLLECTIONS vert_collection) const
{
  return &(m_user_lists.at(vert_collection));
}

// ----------------------------------------------------------------------------
void VertexContainer::print(VERTEX_COLLECTIONS vert_collection) const
{
  std::cout << "================= Printing vertex collection: "
            << vert_collection << " =================\n";

  size_t term = m_user_lists.at(vert_collection).size();
  for (size_t vert_it = 0; vert_it != term; ++vert_it) {
    std::cout << "Vertex: " << vert_it << "\n";
    m_user_lists.at(vert_collection).at(vert_it)->print();
  }
}
