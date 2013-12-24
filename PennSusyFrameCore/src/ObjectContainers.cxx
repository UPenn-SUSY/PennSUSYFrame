#include "PennSusyFrameCore/include/ObjectContainers.h"

#include <iostream>
#include <vector>

#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/D3PDReader.h"

// ----------------------------------------------------------------------------
PennSusyFrame::ElectronContainer::ElectronContainer()
{
  m_user_lists.resize(EL_N);
}

// ----------------------------------------------------------------------------
PennSusyFrame::ElectronContainer::~ElectronContainer()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void PennSusyFrame::ElectronContainer::init()
{
}

// ----------------------------------------------------------------------------
void PennSusyFrame::ElectronContainer::clear()
{
  for ( ELECTRON_COLLECTIONS el_it = EL_ALL
      ; el_it != EL_N
      ; el_it = ELECTRON_COLLECTIONS(el_it+1)
      ) {
    m_user_lists.at(el_it).clear();
  }
  m_master_list.clear();
}

// ----------------------------------------------------------------------------
void PennSusyFrame::ElectronContainer::prep( PennSusyFrame::D3PDReader* reader
                                           )
{
  size_t num_el = reader->el_n;
  m_master_list.reserve(num_el);
  for (size_t el_it = 0; el_it != num_el; ++el_it) {
    PennSusyFrame::Electron tmp(reader, el_it);
    m_master_list.push_back(tmp);
  }

  m_user_lists.at(EL_ALL).reserve(num_el);
  for (size_t el_it = 0; el_it != num_el; ++el_it) {
    m_user_lists.at(EL_ALL).push_back(&m_master_list.at(el_it));
  }
}

// ----------------------------------------------------------------------------
void PennSusyFrame::ElectronContainer::setCollection( ELECTRON_COLLECTIONS el_collection
                                                    , std::vector<PennSusyFrame::Electron*> electrons
                                                    )
{
  m_user_lists.at(el_collection) = electrons;
}

// ----------------------------------------------------------------------------
size_t PennSusyFrame::ElectronContainer::num(ELECTRON_COLLECTIONS el_collection) const

{
  return m_user_lists.at(el_collection).size();
}

// ----------------------------------------------------------------------------
const std::vector<PennSusyFrame::Electron*> PennSusyFrame::ElectronContainer::getCollection(ELECTRON_COLLECTIONS el_collection) const
{
  return m_user_lists.at(el_collection);
}

// ----------------------------------------------------------------------------
void PennSusyFrame::ElectronContainer::print( ELECTRON_COLLECTIONS el_collection
                                            ) const
{
  std::cout << "================= Printing electron collection: "
            << el_collection << " =================\n";

  size_t term = num(el_collection);
  std::cout << "Number electrons: " << term << "\n";

  for (size_t el_it = 0; el_it != term; ++el_it) {
    m_user_lists.at(el_collection).at(el_it)->print();
  }
}

// ----------------------------------------------------------------------------
PennSusyFrame::MuonContainer::MuonContainer()
{
  m_user_lists.resize(MU_N);
}

// ----------------------------------------------------------------------------
PennSusyFrame::MuonContainer::~MuonContainer()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void PennSusyFrame::MuonContainer::init()
{
}

// ----------------------------------------------------------------------------
void PennSusyFrame::MuonContainer::clear()
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
void PennSusyFrame::MuonContainer::prep( PennSusyFrame::D3PDReader* reader
                                       )
{
  size_t num_mu = reader->mu_staco_n;
  m_master_list.reserve(num_mu);
  for (size_t mu_it = 0; mu_it != num_mu; ++mu_it) {
    PennSusyFrame::Muon tmp(reader, mu_it);
    m_master_list.push_back(tmp);
  }

  m_user_lists.at(MU_ALL).reserve(num_mu);
  for (size_t mu_it = 0; mu_it != num_mu; ++mu_it) {
    m_user_lists.at(MU_ALL).push_back(&m_master_list.at(mu_it));
  }
}

// ----------------------------------------------------------------------------
void PennSusyFrame::MuonContainer::setCollection( MUON_COLLECTIONS mu_collection
                                                , std::vector<PennSusyFrame::Muon*> muons
                                                )
{
  m_user_lists.at(mu_collection) = muons;
}

// ----------------------------------------------------------------------------
size_t PennSusyFrame::MuonContainer::num(MUON_COLLECTIONS mu_collection) const

{
  return m_user_lists.at(mu_collection).size();
}

// ----------------------------------------------------------------------------
const std::vector<PennSusyFrame::Muon*> PennSusyFrame::MuonContainer::getCollection(MUON_COLLECTIONS mu_collection) const
{
  return m_user_lists.at(mu_collection);
}

// ----------------------------------------------------------------------------
void PennSusyFrame::MuonContainer::print( MUON_COLLECTIONS mu_collection
                                        ) const
{
  std::cout << "================= Printing muon collection: "
            << mu_collection << " =================\n";

  size_t term = num(mu_collection);
  std::cout << "Number muons: " << term << "\n";

  for (size_t mu_it = 0; mu_it != term; ++mu_it) {
    m_user_lists.at(mu_collection).at(mu_it)->print();
  }
}

// ----------------------------------------------------------------------------
PennSusyFrame::JetContainer::JetContainer()
{
  m_user_lists.resize(JET_N);
}

// ----------------------------------------------------------------------------
PennSusyFrame::JetContainer::~JetContainer()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void PennSusyFrame::JetContainer::init()
{
}

// ----------------------------------------------------------------------------
void PennSusyFrame::JetContainer::clear()
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
void PennSusyFrame::JetContainer::prep( PennSusyFrame::D3PDReader* reader
                                      )
{
  size_t num_mu = reader->jet_AntiKt4LCTopo_n;
  m_master_list.reserve(num_mu);
  for (size_t jet_it = 0; jet_it != num_mu; ++jet_it) {
    PennSusyFrame::Jet tmp(reader, jet_it);
    m_master_list.push_back(tmp);
  }

  m_user_lists.at(JET_ALL).reserve(num_mu);
  for (size_t jet_it = 0; jet_it != num_mu; ++jet_it) {
    m_user_lists.at(JET_ALL).push_back(&m_master_list.at(jet_it));
  }
}

// ----------------------------------------------------------------------------
void PennSusyFrame::JetContainer::setCollection( JET_COLLECTIONS jet_collection
                                               , std::vector<PennSusyFrame::Jet*> muons
                                               )
{
  m_user_lists.at(jet_collection) = muons;
}

// ----------------------------------------------------------------------------
size_t PennSusyFrame::JetContainer::num(JET_COLLECTIONS jet_collection) const

{
  return m_user_lists.at(jet_collection).size();
}

// ----------------------------------------------------------------------------
const std::vector<PennSusyFrame::Jet*> PennSusyFrame::JetContainer::getCollection(JET_COLLECTIONS jet_collection) const
{
  return m_user_lists.at(jet_collection);
}

// ----------------------------------------------------------------------------
void PennSusyFrame::JetContainer::print( JET_COLLECTIONS jet_collection
                                       ) const
{
  std::cout << "================= Printing muon collection: "
            << jet_collection << " =================\n";

  size_t term = num(jet_collection);
  std::cout << "Number muons: " << term << "\n";

  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    m_user_lists.at(jet_collection).at(jet_it)->print();
  }
}
