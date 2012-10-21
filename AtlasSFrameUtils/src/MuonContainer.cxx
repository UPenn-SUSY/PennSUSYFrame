#include "include/MuonContainer.h"

// ----------------------------------------------------------------------------
MuonContainer::MuonContainer()
{
  m_user_lists.resize(MU_N);
}

// ----------------------------------------------------------------------------
MuonContainer::~MuonContainer()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void MuonContainer::init( CommonTools::TLVTool* tlv_tool
                        , CommonTools::IsoCorrectionTool* iso_corr_tool
                        )
{
  m_tlv_tool = tlv_tool;
  m_iso_corr_tool = iso_corr_tool;
}

// ----------------------------------------------------------------------------
void MuonContainer::clear()
{
  for ( MUON_COLLECTIONS mu_it = MU_ALL
      ; mu_it != MU_N
      ; mu_it = MUON_COLLECTIONS(mu_it+1)
      ) {
    m_user_lists.at(mu_it).clear();
  }
  m_master_list.clear();
}

// ----------------------------------------------------------------------------
void MuonContainer::prepMuons(
    D3PDReader::MuonD3PDObject* muon_d3pdobject)
{
  ParticleElementBuilder::build( m_master_list
                               , *muon_d3pdobject
                               , m_tlv_tool
                               , m_iso_corr_tool
                               );

  size_t term = m_master_list.size();
  for (size_t mu_it = 0; mu_it != term; ++mu_it) {
    m_master_list.at(mu_it).prepTlv();
    m_master_list.at(mu_it).prepRawTlv();
    m_user_lists.at(MU_ALL).push_back(&m_master_list.at(mu_it));
  }
}

// ----------------------------------------------------------------------------
void MuonContainer::setCollection( MUON_COLLECTIONS el_collection
                                 , std::vector<Muon*> muons
                                 )
{
  m_user_lists.at(el_collection) = muons;
}

// ----------------------------------------------------------------------------
size_t MuonContainer::num(MUON_COLLECTIONS mu_collection) const

{
  return m_user_lists.at(mu_collection).size();
}

// ----------------------------------------------------------------------------
const std::vector<Muon*>* MuonContainer::getMuons(
    MUON_COLLECTIONS mu_collection) const
{
  return &(m_user_lists.at(mu_collection));
}

// ----------------------------------------------------------------------------
void MuonContainer::print(MUON_COLLECTIONS mu_collection) const
{
  std::cout << "================= Printing muon collection: "
            << mu_collection << " =================\n";

  size_t term = m_user_lists.at(mu_collection).size();
  for (size_t mu_it = 0; mu_it != term; ++mu_it) {
    std::cout << "Muon: " << mu_it << "\n";
    m_user_lists.at(mu_collection).at(mu_it)->print();
  }
}
