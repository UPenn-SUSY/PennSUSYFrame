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
PennSusyFrame::Particle::Particle() : m_tlv_set(false)
                                    , m_raw_tlv_set(false)
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

// -----------------------------------------------------------------------------
void PennSusyFrame::Particle::setParticleIndex(int val)
{
  m_particle_index = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Particle::setTlv(const TLorentzVector& tlv)
{
  m_tlv = tlv;
  m_tlv_set = true;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Particle::setRawTlv(const TLorentzVector& tlv)
{
  m_raw_tlv = tlv;
  m_raw_tlv_set = true;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Particle::getParticleIndex()
{
  return m_particle_index;
}

// -----------------------------------------------------------------------------
TLorentzVector* PennSusyFrame::Particle::getTlv()
{
  if (!m_tlv_set) {
    std::cout << "WARNING!!! Trying to get TLV, but it is not set!\n";
    return 0;
  }

  return &m_tlv;
}

// -----------------------------------------------------------------------------
TLorentzVector* PennSusyFrame::Particle::getRawTlv()
{
  if (!m_raw_tlv_set) {
    std::cout << "WARNING!!! Trying to get raw TLV, but it is not set!\n";
    return 0;
  }

  return &m_raw_tlv;
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
  setParticleIndex(el_index);

  setCharge(reader->el_charge->at(el_index));
  setElTlv(reader);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::print() const
{
  std::cout << "printing electron\n";
  Lepton::print();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setElTlv(const PennSusyFrame::D3PDReader* reader)
{
  TLorentzVector raw_tlv;
  raw_tlv.SetPxPyPzE( reader->el_px->at(m_particle_index)
                    , reader->el_py->at(m_particle_index)
                    , reader->el_pz->at(m_particle_index)
                    , reader->el_E->at(m_particle_index)
                    );
  setRawTlv(raw_tlv);
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
  setParticleIndex(mu_index);

  setCharge(reader->mu_staco_charge->at(mu_index));
  setMuTlv(reader);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::print() const
{
  Lepton::print();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setMuTlv(const PennSusyFrame::D3PDReader* reader)
{
  TLorentzVector raw_tlv;
  raw_tlv.SetPxPyPzE( reader->mu_staco_px->at(m_particle_index)
                    , reader->mu_staco_py->at(m_particle_index)
                    , reader->mu_staco_pz->at(m_particle_index)
                    , reader->mu_staco_E->at(m_particle_index)
                    );
  setRawTlv(raw_tlv);
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

  setParticleIndex(jet_index);
  setJetTlv(reader);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::print() const
{
  printGeneralInfo();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setJetTlv(const PennSusyFrame::D3PDReader* reader)
{
  TLorentzVector raw_tlv;
  raw_tlv.SetPtEtaPhiM( reader->jet_AntiKt4LCTopo_pt->at(m_particle_index)
                      , reader->jet_AntiKt4LCTopo_eta->at(m_particle_index)
                      , reader->jet_AntiKt4LCTopo_phi->at(m_particle_index)
                      , reader->jet_AntiKt4LCTopo_m->at(m_particle_index)
                      );
  setRawTlv(raw_tlv);
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
