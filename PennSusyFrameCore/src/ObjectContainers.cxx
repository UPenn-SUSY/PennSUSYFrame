#include "PennSusyFrameCore/include/ObjectContainers.h"

#include <iostream>
#include <vector>

// #include "AtlasSFrameUtils/include/ParticleElementBuilder.h"
// #include "AtlasSFrameUtils/include/Electron.h"
// #include "AtlasSFrameUtils/include/VertexContainer.h"

// #include "D3PDObjects/include/ElectronD3PDObject.h"

// #include "CommonTools/include/TLVTool.h"
// #include "CommonTools/include/IsoCorrectionTool.h"

// #include "SelectionTools/include/ElectronSelectionTool.h"

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
void PennSusyFrame::ElectronContainer::init(
    // SelectionTools::ElectronSelectionTool* electron_selection_tool,
    // CommonTools::TLVTool* tlv_tool,
    // CommonTools::IsoCorrectionTool* iso_corr_tool
    )
{
  // m_electron_selection = electron_selection_tool;
  // m_tlv_tool = tlv_tool;
  // m_iso_corr_tool = iso_corr_tool;
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
void PennSusyFrame::ElectronContainer::prepElectrons( PennSusyFrame::D3PDReader* reader
                                                    // , const VertexContainer& vertices
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

  // ParticleElementBuilder::build( m_master_list
  //                              , *electron_d3pdobject
  //                              , m_tlv_tool
  //                              , m_iso_corr_tool
  //                              );

  // size_t term = m_master_list.size();
  // for (size_t el_it = 0; el_it != term; ++el_it) {
  //   m_master_list.at(el_it).prepTlv();
  //   m_master_list.at(el_it).prepRawTlv();

  //   m_electron_selection->process(&m_master_list.at(el_it), vertices);
  //   m_user_lists.at(EL_ALL).push_back(&m_master_list.at(el_it));
  // }
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
const std::vector<PennSusyFrame::Electron*> PennSusyFrame::ElectronContainer::getElectrons(ELECTRON_COLLECTIONS el_collection) const
{
  return m_user_lists.at(el_collection);
}

// ----------------------------------------------------------------------------
void PennSusyFrame::ElectronContainer::print( ELECTRON_COLLECTIONS el_collection
                                            // , const VertexContainer& vertices
                                            ) const
{
  std::cout << "================= Printing electron collection: "
            << el_collection << " =================\n";

  // size_t term = m_user_lists.at(el_collection).size();
  size_t term = num(el_collection);
  std::cout << "Number electrons: " << term << "\n";

  for (size_t el_it = 0; el_it != term; ++el_it) {
    m_user_lists.at(el_collection).at(el_it)->print();
  }
}
