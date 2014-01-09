#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/D3PDReader.h"
// #include "PennSusyFrameCore/include/Calculators.h"

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
  // const TLorentzVector* raw_tlv = getRawTlv();
  std::cout << "\tpt: "  << m_tlv.Pt()
            << "\teta: " << m_tlv.Eta()
            << "\tphi: " << m_tlv.Phi()
            << "\tE: "   << m_tlv.E()
            << "\n"
            << "\traw pt: "  << m_raw_tlv.Pt()
            << "\traw eta: " << m_raw_tlv.Eta()
            << "\traw phi: " << m_raw_tlv.Phi()
            << "\traw E: "   << m_raw_tlv.E()
            << "\n";
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
int PennSusyFrame::Particle::getParticleIndex() const
{
  return m_particle_index;
}

// -----------------------------------------------------------------------------
const TLorentzVector* PennSusyFrame::Particle::getTlv() const
{
  if (!m_tlv_set) {
    std::cout << "WARNING!!! Trying to get TLV, but it is not set!\n";
    return 0;
  }

  return &m_tlv;
}

// -----------------------------------------------------------------------------
const TLorentzVector* PennSusyFrame::Particle::getRawTlv() const
{
  if (!m_raw_tlv_set) {
    std::cout << "WARNING!!! Trying to get raw TLV, but it is not set!\n";
    return 0;
  }

  return &m_raw_tlv;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Particle::getPt() const
{
  if (!m_tlv_set) {
    std::cout << "WARNING! pT requested, but not set\n";
    return 0.;
  }

  return m_tlv.Pt();
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Particle::getEta() const
{
  if (!m_tlv_set) {
    std::cout << "WARNING! eta requested, but not set\n";
    return 0.;
  }

  return m_tlv.Eta();
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Particle::getPhi() const
{
  if (!m_tlv_set) {
    std::cout << "WARNING! phi requested, but not set\n";
    return 0.;
  }

  return m_tlv.Phi();
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Particle::getE() const
{
  if (!m_tlv_set) {
    std::cout << "WARNING! E requested, but not set\n";
    return 0.;
  }

  return m_tlv.E();
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Particle::getRawPt() const
{
  if (!m_raw_tlv_set) {
    std::cout << "WARNING! Raw pT requested, but not set\n";
    return 0.;
  }

  return m_raw_tlv.Pt();
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Particle::getRawEta() const
{
  if (!m_raw_tlv_set) {
    std::cout << "WARNING! Raw eta requested, but not set\n";
    return 0.;
  }

  return m_raw_tlv.Eta();
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Particle::getRawPhi() const
{
  if (!m_raw_tlv_set) {
    std::cout << "WARNING! Raw phi requested, but not set\n";
    return 0.;
  }

  return m_raw_tlv.Phi();
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Particle::getRawE() const
{
  if (!m_raw_tlv_set) {
    std::cout << "WARNING! Raw E requested, but not set\n";
    return 0.;
  }

  return m_raw_tlv.E();
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
                                 , PennSusyFrame::ElectronRescalerTool* el_rescaler
                                 , bool verbose
                                 )
{
  if (verbose) {
    std::cout << "Initializing electron\n";
  }

  setIsElectron(true);
  setParticleIndex(el_index);

  setCharge(reader->el_charge->at(el_index));

  setClE(reader->el_cl_E->at(el_index));
  setClEta(reader->el_cl_eta->at(el_index));
  setClPhi(reader->el_cl_phi->at(el_index));

  // must set TLV last because it depends on above quantities
  setElTlv(reader, el_rescaler);
  // setElTlv(reader);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setClE(double val)
{
  m_cl_E = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setClEta(double val)
{
  m_cl_eta = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setClPhi(double val)
{
  m_cl_phi = val;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Electron::getClE() const
{
  return m_cl_E;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Electron::getClEta() const
{
  return m_cl_eta;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Electron::getClPhi() const
{
  return m_cl_phi;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::print() const
{
  std::cout << "printing electron\n";
  Lepton::print();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setElTlv( const PennSusyFrame::D3PDReader* reader
                                      , PennSusyFrame::ElectronRescalerTool* el_rescaler
                                      )
{
  TLorentzVector raw_tlv;
  raw_tlv.SetPxPyPzE( reader->el_px->at(m_particle_index)
                    , reader->el_py->at(m_particle_index)
                    , reader->el_pz->at(m_particle_index)
                    , reader->el_E->at(m_particle_index)
                    );
  setRawTlv(raw_tlv);

  TLorentzVector tlv;
  double corrected_e  = el_rescaler->getRescaledE(this);
  double corrected_eta = getRawEta();
  double corrected_phi = getRawPhi();
  double corrected_et = corrected_e/cosh(corrected_eta);
  tlv.SetPtEtaPhiE( corrected_et, corrected_eta, corrected_phi, corrected_e);
  setTlv(tlv);
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
                         , PennSusyFrame::MuonRescalerTool* mu_rescaler
                         , bool verbose
                         )
{
  if (verbose) {
    std::cout << "Initializing muon\n";
  }

  setIsElectron(false);
  setParticleIndex(mu_index);

  setCharge(reader->mu_staco_charge->at(mu_index));

  setIsCombined(reader->mu_staco_isCombinedMuon->at(mu_index));
  setIsSegmentTagged(reader->mu_staco_isSegmentTaggedMuon->at(mu_index));
  setIdQOverP(reader->mu_staco_id_qoverp_exPV->at(mu_index));
  setIdTheta( reader->mu_staco_id_theta_exPV->at(mu_index));
  setMEQOverP(reader->mu_staco_me_qoverp_exPV->at(mu_index));
  setMETheta( reader->mu_staco_me_theta_exPV->at(mu_index));

  setMuTlv(reader, mu_rescaler);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setIsCombined(int val)
{
  m_is_combined = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setIsSegmentTagged(int val)
{
  m_is_segment_tagged = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setIdQOverP(double val)
{
  m_id_qoverp = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setIdTheta(double val)
{
  m_id_theta = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setMEQOverP(double val)
{
  m_me_qoverp = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setMETheta(double val)
{
  m_me_theta = val;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Muon::getIsCombined() const
{
  return m_is_combined;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Muon::getIsSegmentTagged() const
{
  return m_is_segment_tagged;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getIdQOverP() const
{
  return m_id_qoverp;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getIdTheta() const
{
  return m_id_theta;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getMEQOverP() const
{
  return m_me_qoverp;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getMETheta() const
{
  return m_me_theta;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::print() const
{
  Lepton::print();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setMuTlv( const PennSusyFrame::D3PDReader* reader
                                  , PennSusyFrame::MuonRescalerTool* mu_rescaler
                                  )
{
  TLorentzVector raw_tlv;
  double raw_pt  = reader->mu_staco_pt->at(m_particle_index);
  double raw_eta = reader->mu_staco_eta->at(m_particle_index);
  double raw_phi = reader->mu_staco_phi->at(m_particle_index);
  double raw_m   = 105.66;
  raw_tlv.SetPtEtaPhiM( raw_pt
                      , raw_eta
                      , raw_phi
                      , raw_m
                      );
  setRawTlv(raw_tlv);

  TLorentzVector tlv;
  double corrected_pt  = mu_rescaler->getSmearedPt(this);
  double corrected_eta = raw_eta;
  double corrected_phi = raw_phi;
  double corrected_m   = raw_m;
  tlv.SetPtEtaPhiM(corrected_pt, corrected_eta, corrected_phi, corrected_m);
  setTlv(tlv);
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
                       , PennSusyFrame::JetRescalerTool* jet_rescaler
                       , bool verbose
                       )
{
  if (verbose) {
    std::cout << "Initializing jet - jet index: " << jet_index << "\n";
  }

  setParticleIndex(jet_index);
  setJetTlv(reader, jet_rescaler);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::print() const
{
  printGeneralInfo();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setJetTlv( const PennSusyFrame::D3PDReader* reader
                                  , PennSusyFrame::JetRescalerTool* jet_rescaler
                                  )
{
  TLorentzVector raw_tlv;
  double raw_pt  = reader->jet_AntiKt4LCTopo_pt->at(m_particle_index);
  double raw_eta = reader->jet_AntiKt4LCTopo_eta->at(m_particle_index);
  double raw_phi = reader->jet_AntiKt4LCTopo_phi->at(m_particle_index);
  double raw_m   = reader->jet_AntiKt4LCTopo_m->at(m_particle_index);
  raw_tlv.SetPtEtaPhiM( raw_pt
                      , raw_eta
                      , raw_phi
                      , raw_m
                      );
  setRawTlv(raw_tlv);

  TLorentzVector tlv;
  double corrected_pt  = raw_pt;
  double corrected_eta = raw_eta;
  double corrected_phi = raw_phi;
  double corrected_m   = raw_m;
  tlv.SetPtEtaPhiM(corrected_pt, corrected_eta, corrected_phi, corrected_m);
  setTlv(tlv);
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
