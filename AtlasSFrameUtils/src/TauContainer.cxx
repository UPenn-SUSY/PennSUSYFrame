#include "AtlasSFrameUtils/include/TauContainer.h"

#include <iostream>
#include <vector>

#include "AtlasSFrameUtils/include/ParticleElementBuilder.h"
#include "AtlasSFrameUtils/include/Tau.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "CommonTools/include/TLVTool.h"
// #include "CommonTools/include/IsoCorrectionTool.h"

#include "SelectionTools/include/TauSelectionTool.h"

#include "SusyAnalysisTools/include/SusyEnums.h"


// ----------------------------------------------------------------------------
TauContainer::TauContainer()
{
  m_user_lists.resize(TAU_N);
}

// ----------------------------------------------------------------------------
TauContainer::~TauContainer()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void TauContainer::init( SelectionTools::TauSelectionTool* tau_selection_tool
                        , CommonTools::TLVTool* tlv_tool
                        // , CommonTools::IsoCorrectionTool* iso_corr_tool
                        )
{
  m_tau_selection = tau_selection_tool;
  m_tlv_tool = tlv_tool;
  // m_iso_corr_tool = iso_corr_tool;
}

// ----------------------------------------------------------------------------
void TauContainer::clear()
{
  for ( TAU_COLLECTIONS tau_it = TAU_ALL
      ; tau_it != TAU_N
      ; tau_it = TAU_COLLECTIONS(tau_it+1)
      ) {
    m_user_lists.at(tau_it).clear();
  }
  m_master_list.clear();
}

// ----------------------------------------------------------------------------
void TauContainer::prepTaus(
    D3PDReader::TauD3PDObject* tau_d3pdobject,
    const VertexContainer& vertices)
{
  ParticleElementBuilder::build( m_master_list
                               , *tau_d3pdobject
                               , m_tlv_tool
                               // , m_iso_corr_tool
                               );

  size_t term = m_master_list.size();
  for (size_t tau_it = 0; tau_it != term; ++tau_it) {
    m_master_list.at(tau_it).prepTlv();
    m_master_list.at(tau_it).prepRawTlv();

    m_tau_selection->process(&m_master_list.at(tau_it), vertices);
    m_user_lists.at(TAU_ALL).push_back(&m_master_list.at(tau_it));
  }
}

// ----------------------------------------------------------------------------
void TauContainer::setCollection( TAU_COLLECTIONS el_collection
                                 , std::vector<Tau*> taus
                                 )
{
  m_user_lists.at(el_collection) = taus;
}

// ----------------------------------------------------------------------------
size_t TauContainer::num(TAU_COLLECTIONS tau_collection) const

{
  return m_user_lists.at(tau_collection).size();
}

// ----------------------------------------------------------------------------
const std::vector<Tau*> TauContainer::getTaus(
    TAU_COLLECTIONS tau_collection) const
{
  return m_user_lists.at(tau_collection);
}

// ----------------------------------------------------------------------------
void TauContainer::print( TAU_COLLECTIONS tau_collection
                         , const VertexContainer& vertices
                         ) const
{
  std::cout << "================= Printing tau collection: "
            << tau_collection << " =================\n";

  size_t term = m_user_lists.at(tau_collection).size();
  std::cout << "Number taus: " << term << "\n";

  for (size_t tau_it = 0; tau_it != term; ++tau_it) {
    std::cout << "Tau: " << tau_it << "\n";
    m_user_lists.at(tau_collection).at(tau_it)->print(vertices);
  }
}
