#include "PennSusyFrameCore/include/ObjectSelectors.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"

#include <iostream>

// =============================================================================
// = SelectorBase
// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::SelectorBase::SelectorBase()
{
}

bool PennSusyFrame::SelectorBase::passSelection(const PennSusyFrame::PhysicsObject*)
{
  std::cout << "calling default selector :-(\n";
  return false;
}

// =============================================================================
// = ElectronSelector
// =============================================================================
// ----------------------------------------------------------------------------
PennSusyFrame::ElectronSelector::ElectronSelector() : m_min_pt(-1)
                                                    , m_max_pt(-1)
                                                    , m_min_eta(-1)
                                                    , m_max_eta(-1)
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ElectronSelector::setPtCut(double min, double max)
{
  m_min_pt = min;
  m_max_pt = max;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ElectronSelector::setEtaCut(double min, double max)
{
  m_min_eta = min;
  m_max_eta = max;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::ElectronSelector::passSelection(const PennSusyFrame::Electron* p)
{
  if (!passCut(p->getPt(), m_min_pt, m_max_pt)) return false;
  if (!passCut(p->getEta(), m_min_eta, m_max_eta)) return false;

  return true;
}

// =============================================================================
// = MuonSelector
// =============================================================================
// ----------------------------------------------------------------------------
PennSusyFrame::MuonSelector::MuonSelector() : m_min_pt(-1)
                                            , m_max_pt(-1)
                                            , m_min_eta(-1)
                                            , m_max_eta(-1)
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::MuonSelector::setPtCut(double min, double max)
{
  m_min_pt = min;
  m_max_pt = max;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::MuonSelector::setEtaCut(double min, double max)
{
  m_min_eta = min;
  m_max_eta = max;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::MuonSelector::passSelection(const PennSusyFrame::Muon* p)
{
  if (!passCut(p->getPt(), m_min_pt, m_max_pt)) return false;
  if (!passCut(p->getEta(), m_min_eta, m_max_eta)) return false;

  return true;
}

// =============================================================================
// = TauSelector
// =============================================================================
// ----------------------------------------------------------------------------
PennSusyFrame::TauSelector::TauSelector() : m_min_pt(-1)
                                          , m_max_pt(-1)
                                          , m_min_eta(-1)
                                          , m_max_eta(-1)
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TauSelector::setPtCut(double min, double max)
{
  m_min_pt = min;
  m_max_pt = max;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TauSelector::setEtaCut(double min, double max)
{
  m_min_eta = min;
  m_max_eta = max;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TauSelector::passSelection(const PennSusyFrame::Tau* p)
{
  if (!passCut(p->getPt(), m_min_pt, m_max_pt)) return false;
  if (!passCut(p->getEta(), m_min_eta, m_max_eta)) return false;

  return true;
}

// =============================================================================
// = JetSelector
// =============================================================================
// ----------------------------------------------------------------------------
PennSusyFrame::JetSelector::JetSelector() : m_min_pt(-1)
                                          , m_max_pt(-1)
                                          , m_min_eta(-1)
                                          , m_max_eta(-1)
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::JetSelector::setPtCut(double min, double max)
{
  m_min_pt = min;
  m_max_pt = max;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::JetSelector::setEtaCut(double min, double max)
{
  m_min_eta = min;
  m_max_eta = max;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::JetSelector::passSelection(const PennSusyFrame::Jet* p)
{
  if (!passCut(p->getPt(), m_min_pt, m_max_pt)) return false;
  if (!passCut(p->getEta(), m_min_eta, m_max_eta)) return false;

  return true;
}

// =============================================================================
// = VertexSelector
// =============================================================================
// ----------------------------------------------------------------------------
PennSusyFrame::VertexSelector::VertexSelector() : m_min_num_tracks(-1)
                                                , m_max_num_tracks(-1)
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::VertexSelector::setNumTracksCut(double min, double max)
{
  m_min_num_tracks = min;
  m_max_num_tracks = max;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::VertexSelector::passSelection(const PennSusyFrame::Vertex* p)
{
  if ( !passCut( p->getNumTracks()
               , m_min_num_tracks
               , m_max_num_tracks
               )
     ) return false;

  return true;
}
