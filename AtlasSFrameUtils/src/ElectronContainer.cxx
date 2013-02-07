#include "AtlasSFrameUtils/include/ElectronContainer.h"

#include <iostream>
#include <vector>

#include "AtlasSFrameUtils/include/ParticleElementBuilder.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "D3PDObjects/include/ElectronD3PDObject.h"

#include "CommonTools/include/TLVTool.h"
#include "CommonTools/include/IsoCorrectionTool.h"

#include "SelectionTools/include/ElectronSelectionTool.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// ----------------------------------------------------------------------------
ElectronContainer::ElectronContainer()
{
  m_user_lists.resize(EL_N);
}

// ----------------------------------------------------------------------------
ElectronContainer::~ElectronContainer()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void ElectronContainer::init(
    SelectionTools::ElectronSelectionTool* electron_selection_tool,
    CommonTools::TLVTool* tlv_tool,
    CommonTools::IsoCorrectionTool* iso_corr_tool)
{
  m_electron_selection = electron_selection_tool;
  m_tlv_tool = tlv_tool;
  m_iso_corr_tool = iso_corr_tool;
}

// ----------------------------------------------------------------------------
void ElectronContainer::clear()
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
void ElectronContainer::prepElectrons(
    D3PDReader::ElectronD3PDObject* electron_d3pdobject,
    const VertexContainer& vertices)
{
  ParticleElementBuilder::build( m_master_list
                               , *electron_d3pdobject
                               , m_tlv_tool
                               , m_iso_corr_tool
                               );

  size_t term = m_master_list.size();
  for (size_t el_it = 0; el_it != term; ++el_it) {
    m_master_list.at(el_it).prepTlv();
    m_master_list.at(el_it).prepRawTlv();

    m_electron_selection->process(&m_master_list.at(el_it), vertices);
    m_user_lists.at(EL_ALL).push_back(&m_master_list.at(el_it));
  }
}

// ----------------------------------------------------------------------------
void ElectronContainer::setCollection( ELECTRON_COLLECTIONS el_collection
                                     , std::vector<Electron*> electrons
                                     )
{
  m_user_lists.at(el_collection) = electrons;
}

// ----------------------------------------------------------------------------
size_t ElectronContainer::num(ELECTRON_COLLECTIONS el_collection) const

{
  return m_user_lists.at(el_collection).size();
}

// ----------------------------------------------------------------------------
const std::vector<Electron*> ElectronContainer::getElectrons(
    ELECTRON_COLLECTIONS el_collection) const
{
  return m_user_lists.at(el_collection);
}

// ----------------------------------------------------------------------------
void ElectronContainer::print( ELECTRON_COLLECTIONS el_collection
                             , const VertexContainer& vertices
                             ) const
{
  std::cout << "================= Printing electron collection: "
            << el_collection << " =================\n";

  size_t term = m_user_lists.at(el_collection).size();
  std::cout << "Number electrons: " << term << "\n";

  for (size_t el_it = 0; el_it != term; ++el_it) {
    std::cout << "Electron: " << el_it << "\n";
    m_user_lists.at(el_collection).at(el_it)->print(vertices);
  }
}
