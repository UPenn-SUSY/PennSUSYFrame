#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/D3PDReader.h"
// #include "PennSusyFrameCoreLooper/include/Calculators.h"

#include <vector>
#include <iostream>
#include <math.h>

// =============================================================================
static const double PI = 3.14159265359;

// =============================================================================
// = Particle
// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::Particle::Particle()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Particle::printGeneralInfo() const
{
  // std::cout << "\tmc index: " << m_mc_index
  //           << "\tpdg id: "  << m_pdgid
  //           // << "\tbarcode: "  << m_barcode
  //           << "\n"
  //           << "\t\tpt: " << m_pt
  //           << "\t\teta: " << m_eta
  //           << "\t\tphi: " << m_phi
  //           << "\t\tE: " << m_e
  //           << "\t\tm: " << m_m
  //           << "\n"
  //           << "\t\tpx: " << m_px
  //           << "\t\tpy: " << m_py
  //           << "\t\tpz: " << m_pz
  //           << "\n"
  //           << "\t\tparent index: "   << m_parent_index
  //           << "\t\tparent pdg id: "  << m_parent_pdgid
  //           << "\t\tparent barcode: " << m_parent_barcode
  //           << "\n";
}

// =============================================================================
// = Lepton
// =============================================================================
PennSusyFrame::Lepton::Lepton()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Lepton::setIsElectron(bool val)
{
  m_is_electron = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Lepton::setCharge(double val)
{
  m_charge = val;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::Lepton::isElectron() const
{
  return m_is_electron;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::Lepton::isMuon() const
{
  return !m_is_electron;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Lepton::getCharge() const
{
  return m_charge;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Lepton::print() const
{
  std::cout << "lepton (" << (m_is_electron ? "electron" : "muon") << ")"
            << "\tcharge: " << m_charge
            << "\n";
  printGeneralInfo();
}

// =============================================================================
// = Electron
// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::Electron::Electron()
{
  setIsElectron(true);
}

// -----------------------------------------------------------------------------
PennSusyFrame::Electron::Electron( const PennSusyFrame::D3PDReader* reader
                                 , int el_index
                                 , bool verbose
                                 )
{
  if (verbose) {
    std::cout << "Initializing electron\n";
  }

  setIsElectron(true);
  setElIndex(el_index);

  setCharge(reader->el_charge->at(el_index));
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setElIndex(int val)
{
  m_el_index = val;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Electron::getElIndex() const
{
  return m_el_index;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::print() const
{
  Lepton::print();
}

// =============================================================================
// = Muon
// =============================================================================
PennSusyFrame::Muon::Muon()
{
  setIsElectron(false);
}

// -----------------------------------------------------------------------------
PennSusyFrame::Muon::Muon( const PennSusyFrame::D3PDReader* reader
                         , int mu_index
                         , bool verbose
                         )
{
  if (verbose) {
    std::cout << "Initializing muon\n";
  }

  setIsElectron(false);
  setMuIndex(mu_index);

  setCharge(reader->mu_staco_charge->at(mu_index));
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setMuIndex(int val)
{
  m_mu_index = val;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Muon::getMuIndex() const
{
  return m_mu_index;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::print() const
{
  Lepton::print();
}

// =============================================================================
// = Jet
// =============================================================================
PennSusyFrame::Jet::Jet()
{
}

// -----------------------------------------------------------------------------
PennSusyFrame::Jet::Jet( const PennSusyFrame::D3PDReader* reader
                       , int jet_index
                       , bool verbose
                       )
{
  if (verbose) {
    std::cout << "Initializing jet - jet index: " << jet_index << "\n";
  }

  setJetIndex(jet_index);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setJetIndex(int val)
{
  m_jet_index = val;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Jet::getJetIndex() const
{
  return m_jet_index;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::print() const
{
  printGeneralInfo();
}

// =============================================================================
// = Met
// =============================================================================
PennSusyFrame::Met::Met()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::clear()
{
}
