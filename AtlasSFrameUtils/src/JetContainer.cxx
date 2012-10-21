#include "include/JetContainer.h"

// ----------------------------------------------------------------------------
JetContainer::JetContainer()
{
  m_user_lists.resize(JET_N);
}

// ----------------------------------------------------------------------------
JetContainer::~JetContainer()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void JetContainer::init( CommonTools::TLVTool* tlv_tool
                       )
{
  m_tlv_tool = tlv_tool;
}

// ----------------------------------------------------------------------------
void JetContainer::clear()
{
  for ( JET_COLLECTIONS jet_it = JET_ALL
      ; jet_it != JET_N
      ; jet_it = JET_COLLECTIONS(jet_it+1)
      ) {
    m_user_lists.at(jet_it).clear();
  }
  m_master_list.clear();
}

// ----------------------------------------------------------------------------
void JetContainer::prepJets(
    D3PDReader::JetD3PDObject* jet_d3pdobject)
{
  ParticleElementBuilder::build( m_master_list
                               , *jet_d3pdobject
                               , m_tlv_tool
                               );

  size_t term = m_master_list.size();
  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    // TODO configure using correct mu and # vertices
    m_master_list.at(jet_it).prepTlv(0, 0);
    m_master_list.at(jet_it).prepRawTlv();
    m_user_lists.at(JET_ALL).push_back(&m_master_list.at(jet_it));
  }
}

// ----------------------------------------------------------------------------
void JetContainer::setCollection( JET_COLLECTIONS jet_collection
                                , std::vector<Jet*> jets
                                )
{
  m_user_lists.at(jet_collection) = jets;
}

// ----------------------------------------------------------------------------
size_t JetContainer::num(JET_COLLECTIONS jet_collection) const

{
  return m_user_lists.at(jet_collection).size();
}

// ----------------------------------------------------------------------------
const std::vector<Jet*>* JetContainer::getJets(
    JET_COLLECTIONS jet_collection) const
{
  return &(m_user_lists.at(jet_collection));
}

// ----------------------------------------------------------------------------
void JetContainer::print(JET_COLLECTIONS jet_collection) const
{
  std::cout << "================= Printing jet collection: "
            << jet_collection << " =================\n";

  size_t term = m_user_lists.at(jet_collection).size();
  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    std::cout << "Jet: " << jet_it << "\n";
    m_user_lists.at(jet_collection).at(jet_it)->print();
  }
}
