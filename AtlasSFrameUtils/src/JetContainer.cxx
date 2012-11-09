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
void JetContainer::prepJets( D3PDReader::JetD3PDObject* jet_d3pdobject
                           , const Event* event
                           , const VertexContainer& vertices
                           )
{
  ParticleElementBuilder::build( m_master_list
                               , *jet_d3pdobject
                               , m_tlv_tool
                               );

  size_t term = m_master_list.size();
  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    float mu = event->averageIntPerXing();
    int num_vertices_w_2_trks = vertices.num(VERT_GT_2);

    m_master_list.at(jet_it).prepTlv(mu, num_vertices_w_2_trks);
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

// -----------------------------------------------------------------------------
void JetContainer::setCombinedCollections()
{
  std::vector<Jet*> l_jet = getJets(JET_LIGHT);
  std::vector<Jet*> b_jet = getJets(JET_B);
  std::vector<Jet*> f_jet = getJets(JET_FORWARD);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::vector<Jet*> all_central;
  all_central.reserve(l_jet.size() + b_jet.size() );
  all_central.insert(all_central.end(), l_jet.begin(), l_jet.end());
  all_central.insert(all_central.end(), b_jet.begin(), b_jet.end());
  setCollection(JET_ALL_CENTRAL, all_central);
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::vector<Jet*> all_signal;
  all_signal.reserve( l_jet.size() + b_jet.size() + f_jet.size());
  all_signal.insert(all_signal.end(), l_jet.begin(), l_jet.end());
  all_signal.insert(all_signal.end(), b_jet.begin(), b_jet.end());
  all_signal.insert(all_signal.end(), f_jet.begin(), f_jet.end());
  setCollection(JET_ALL_SIGNAL, all_signal);
}


// ----------------------------------------------------------------------------
size_t JetContainer::num(JET_COLLECTIONS jet_collection) const

{
  return m_user_lists.at(jet_collection).size();
}

// ----------------------------------------------------------------------------
const std::vector<Jet*> JetContainer::getJets(
    JET_COLLECTIONS jet_collection) const
{
  return m_user_lists.at(jet_collection);
}

// ----------------------------------------------------------------------------
void JetContainer::print(JET_COLLECTIONS jet_collection) const
{
  std::cout << "================= Printing jet collection: "
            << jet_collection << " =================\n";

  size_t term = m_user_lists.at(jet_collection).size();
  std::cout << "Number Jets: " << term << "\n";

  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    std::cout << "Jet: " << jet_it << "\n";
    m_user_lists.at(jet_collection).at(jet_it)->print();
  }
}
