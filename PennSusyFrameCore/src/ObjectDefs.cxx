#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/D3PDReader.h"
// #include "PennSusyFrameCore/include/Calculators.h"

#include <vector>
#include <iostream>
#include <math.h>

// =============================================================================
static const double PI = 3.14159265359;

// =============================================================================
// = Event
// =============================================================================
// -----------------------------------------------------------------------------
// TODO set m_is_data properly
PennSusyFrame::Event::Event() : m_is_data(false)
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::init()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::getEvent(const PennSusyFrame::D3PDReader* reader)
{
  setEventNumber(reader->EventNumber);
  setRunNumber(reader->RunNumber);
  setLumiBlock(reader->lbn);

  setAverageIntPerXing(reader->averageIntPerXing);
  setEventShapeRhoKt4LC(reader->Eventshape_rhoKt4LC);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::setEventNumber(unsigned int val)
{
  m_event_number = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::setRunNumber(unsigned int val)
{
  m_run_number = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::setLumiBlock(unsigned int val)
{
  m_lumi_block = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::setAverageIntPerXing(float val)
{
  m_average_int_per_xing = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::setEventShapeRhoKt4LC(float val)
{
  m_eventshape_rhoKt4LC = val;
}

// -----------------------------------------------------------------------------
unsigned int PennSusyFrame::Event::getEventNumber() const
{
  return m_event_number;
}

// -----------------------------------------------------------------------------
unsigned int PennSusyFrame::Event::getRunNumber() const
{
  return m_run_number;
}

// -----------------------------------------------------------------------------
unsigned int PennSusyFrame::Event::getLumiBlock() const
{
  return m_lumi_block;
}

// -----------------------------------------------------------------------------
float PennSusyFrame::Event::getAverageIntPerXing() const
{
  return m_average_int_per_xing;
}

// -----------------------------------------------------------------------------
float PennSusyFrame::Event::getEventShapeRhoKt4LC() const
{
  return m_eventshape_rhoKt4LC;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::print() const
{
  std::cout << "================= Printing event info: =================\n";
  std::cout << "run number: " << m_run_number
            << "\tlumi block: " << m_lumi_block
            << "\tevent number: " << m_event_number
            << "\n";
}

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
void PennSusyFrame::Lepton::setIsLightLepton(bool val)
{
  m_is_light_lepton = val;
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
  return (m_is_light_lepton && m_is_electron);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::Lepton::isMuon() const
{
  return (m_is_light_lepton && !m_is_electron);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::Lepton::isTau() const
{
  return (!m_is_light_lepton);
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
  setIsLightLepton(true);
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
  setIsLightLepton(true);

  setParticleIndex(el_index);

  setCharge(reader->el_charge->at(el_index));

  setClE(reader->el_cl_E->at(el_index));
  setClEta(reader->el_cl_eta->at(el_index));
  setClPhi(reader->el_cl_phi->at(el_index));

  // TODO set variable
  setD0(reader->el_trackIPEstimate_d0_unbiasedpvunbiased->at(el_index));
  setSigD0(reader->el_trackIPEstimate_sigd0_unbiasedpvunbiased->at(el_index));
  // TODO set variable
  setZ0(reader->el_trackIPEstimate_z0_unbiasedpvunbiased->at(el_index));
  // setSinTheta(sin(m_tlv.Theta()));
  // TODO set variable
  setPtIso(0);
  // TODO set variable
  setEtIso(0);

  // must set TLV last because it depends on above quantities
  setElTlv(reader, el_rescaler);
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
void PennSusyFrame::Electron::setD0(double val)
{
  m_d0 = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setSigD0(double val)
{
  m_sig_d0 = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setZ0(double val)
{
  m_z0 = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setPtIso(double val)
{
  m_pt_iso = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setEtIso(double val)
{
  m_et_iso = val;
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
double PennSusyFrame::Electron::getD0() const
{
  return m_d0;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Electron::getSigD0() const
{
  return m_sig_d0;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Electron::getD0Significance() const
{
  return m_d0/m_sig_d0;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Electron::getZ0() const
{
  return m_z0;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Electron::getZ0SinTheta() const
{
  return m_z0*sin(m_tlv.Theta());
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Electron::getPtIso() const
{
  return m_pt_iso;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Electron::getEtIso() const
{
  return m_et_iso;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::print() const
{
  Lepton::print();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setElTlv( const PennSusyFrame::D3PDReader* reader
                                      , PennSusyFrame::ElectronRescalerTool* el_rescaler
                                      )
{
  TLorentzVector raw_tlv;
  double raw_px = reader->el_px->at(m_particle_index);
  double raw_py = reader->el_py->at(m_particle_index);
  double raw_pz = reader->el_pz->at(m_particle_index);
  double raw_e  = reader->el_E->at(m_particle_index);
  raw_tlv.SetPxPyPzE( raw_px
                    , raw_py
                    , raw_pz
                    , raw_e
                    );
  setRawTlv(raw_tlv);

  TLorentzVector tlv;
  double corrected_e  = el_rescaler->getRescaledE(this);
  double corrected_eta = getRawEta();
  double corrected_phi = getRawPhi();
  double corrected_et = corrected_e/cosh(corrected_eta);
  tlv.SetPtEtaPhiE( corrected_et
                  , corrected_eta
                  , corrected_phi
                  , corrected_e
                  );
  setTlv(tlv);
}

// =============================================================================
// = Muon
// =============================================================================
PennSusyFrame::Muon::Muon()
{
  setIsElectron(false);
  setIsLightLepton(true);
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
  setIsLightLepton(true);

  setParticleIndex(mu_index);

  setCharge(reader->mu_staco_charge->at(mu_index));

  setIsCombined(reader->mu_staco_isCombinedMuon->at(mu_index));
  setIsSegmentTagged(reader->mu_staco_isSegmentTaggedMuon->at(mu_index));
  setIdQOverP(reader->mu_staco_id_qoverp_exPV->at(mu_index));
  setIdTheta( reader->mu_staco_id_theta_exPV->at(mu_index));
  setMEQOverP(reader->mu_staco_me_qoverp_exPV->at(mu_index));
  setMETheta( reader->mu_staco_me_theta_exPV->at(mu_index));

  setNumBLayerHits(reader->mu_staco_nBLHits->at(mu_index));
  setNumPixelHits(reader->mu_staco_nPixHits->at(mu_index));
  setNumSctHits(reader->mu_staco_nSCTHits->at(mu_index));
  setNumSiHoles( reader->mu_staco_nPixHoles->at(mu_index)
               + reader->mu_staco_nSCTHoles->at(mu_index)
               );
  setD0(   reader->mu_staco_trackIPEstimate_d0_unbiasedpvunbiased->at(mu_index));
  setSigD0(reader->mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased->at(mu_index));
  setZ0(   reader->mu_staco_trackIPEstimate_z0_unbiasedpvunbiased->at(mu_index));
  // TODO fill isolations variables
  setPtIso(0);
  setEtIso(0);

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
void PennSusyFrame::Muon::setNumBLayerHits(int val)
{
  m_num_b_layer_hits = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setNumPixelHits(int val)
{
  m_num_pixel_hits = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setNumSctHits(int val)
{
  m_num_sct_hits = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setNumSiHoles(int val)
{
  m_num_si_holes = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setD0(double val)
{
  m_d0 = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setSigD0(double val)
{
  m_sig_d0 = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setZ0(double val)
{
  m_z0 = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setPtIso(double val)
{
  m_pt_iso = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setEtIso(double val)
{
  m_et_iso = val;
}

// // -----------------------------------------------------------------------------
// void PennSusyFrame::Muon::setQOverP(double val)
// {
//   m_q_over_p = val;
// }


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
int PennSusyFrame::Muon::getNumBLayerHits() const
{
  return m_num_b_layer_hits;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Muon::getNumPixelHits() const
{
  return m_num_pixel_hits;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Muon::getNumSctHits() const
{
  return m_num_sct_hits;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Muon::getNumSiHoles() const
{
  return m_num_si_holes;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getD0() const
{
  return m_d0;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getSigD0() const
{
  return m_sig_d0;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getD0Significance() const
{
  return m_d0/m_sig_d0;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getZ0() const
{
  return m_z0;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getZ0SinTheta() const
{
  return m_z0*sin(m_tlv.Theta());
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getPtIso() const
{
  return m_pt_iso;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Muon::getEtIso() const
{
  return m_et_iso;
}

// // -----------------------------------------------------------------------------
// double PennSusyFrame::Muon::getQOverP() const
// {
//   return m_q_over_p;
// }


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
  tlv.SetPtEtaPhiM( corrected_pt
                  , corrected_eta
                  , corrected_phi
                  , corrected_m
                  );
  setTlv(tlv);
}

// =============================================================================
// = Tau
// =============================================================================
PennSusyFrame::Tau::Tau()
{
  setIsElectron(false);
  setIsLightLepton(false);
}

// -----------------------------------------------------------------------------
PennSusyFrame::Tau::Tau( const PennSusyFrame::D3PDReader* reader
                       , int tau_index
                       , PennSusyFrame::TauRescalerTool* tau_rescaler
                       , bool verbose
                       )
{
  if (verbose) {
    std::cout << "Initializing tau\n";
  }

  setIsElectron(false);
  setIsLightLepton(false);

  setParticleIndex(tau_index);

  setCharge(reader->tau_charge->at(tau_index));

  setTauTlv(reader, tau_rescaler);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Tau::print() const
{
  Lepton::print();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Tau::setTauTlv( const PennSusyFrame::D3PDReader* reader
                                  , PennSusyFrame::TauRescalerTool* /*tau_rescaler*/
                                  )
{
  TLorentzVector raw_tlv;
  double raw_pt  = reader->tau_pt->at(m_particle_index);
  double raw_eta = reader->tau_eta->at(m_particle_index);
  double raw_phi = reader->tau_phi->at(m_particle_index);
  double raw_m   = reader->tau_m->at(m_particle_index);;
  raw_tlv.SetPtEtaPhiM( raw_pt
                      , raw_eta
                      , raw_phi
                      , raw_m
                      );
  setRawTlv(raw_tlv);

  // TODO get rescaled tau
  TLorentzVector tlv;
  double corrected_pt  = raw_pt;
  double corrected_eta = raw_eta;
  double corrected_phi = raw_phi;
  double corrected_m   = raw_m;
  tlv.SetPtEtaPhiM( corrected_pt
                  , corrected_eta
                  , corrected_phi
                  , corrected_m
                  );
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
                       , PennSusyFrame::Event* event
                       , int num_vertices_ge_2_tracks
                       , bool verbose
                       )
{
  if (verbose) {
    std::cout << "Initializing jet - jet index: " << jet_index << "\n";
  }

  setParticleIndex(jet_index);

  setConstScaleE(  reader->jet_AntiKt4LCTopo_constscale_E->at(m_particle_index));
  setConstScaleEta(reader->jet_AntiKt4LCTopo_constscale_eta->at(m_particle_index));
  setConstScalePhi(reader->jet_AntiKt4LCTopo_constscale_phi->at(m_particle_index));
  setConstScaleM(  reader->jet_AntiKt4LCTopo_constscale_m->at(m_particle_index));
  setActiveAreaPx( reader->jet_AntiKt4LCTopo_ActiveAreaPx->at(m_particle_index));
  setActiveAreaPy( reader->jet_AntiKt4LCTopo_ActiveAreaPy->at(m_particle_index));
  setActiveAreaPz( reader->jet_AntiKt4LCTopo_ActiveAreaPz->at(m_particle_index));
  setActiveAreaE(  reader->jet_AntiKt4LCTopo_ActiveAreaE->at(m_particle_index));

  setJetTlv(reader, jet_rescaler, event, num_vertices_ge_2_tracks);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setConstScaleE(double val)
{
  m_constscale_e = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setConstScaleEta(double val)
{
  m_constscale_eta = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setConstScalePhi(double val)
{
  m_constscale_phi = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setConstScaleM(double val)
{
  m_constscale_m = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setActiveAreaPx(double val)
{
  m_active_area_px = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setActiveAreaPy(double val)
{
  m_active_area_py = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setActiveAreaPz(double val)
{
  m_active_area_pz = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setActiveAreaE(double val)
{
  m_active_area_e = val;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Jet::getConstScaleE() const
{
  return m_constscale_e;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Jet::getConstScaleEta() const
{
  return m_constscale_eta;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Jet::getConstScalePhi() const
{
  return m_constscale_phi;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Jet::getConstScaleM() const
{
  return m_constscale_m;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Jet::getActiveAreaPx() const
{
  return m_active_area_px;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Jet::getActiveAreaPy() const
{
  return m_active_area_py;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Jet::getActiveAreaPz() const
{
  return m_active_area_pz;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Jet::getActiveAreaE() const
{
  return m_active_area_e;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::print() const
{
  printGeneralInfo();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setJetTlv( const PennSusyFrame::D3PDReader* reader
                                  , PennSusyFrame::JetRescalerTool* jet_rescaler
                                  , PennSusyFrame::Event* event
                                  , int num_vertices_w_2_trks
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

  TLorentzVector tlv = jet_rescaler->getCalibratedTlv( this
                                                     , event
                                                     , num_vertices_w_2_trks
                                                     );
  setTlv(tlv);
}

// =============================================================================
// = Vertex
// =============================================================================
PennSusyFrame::Vertex::Vertex()
{
}

PennSusyFrame::Vertex::Vertex( const PennSusyFrame::D3PDReader* reader
                             , int vertex_index
                             , bool /*verbose*/
                             )
{
  setVertexIndex(vertex_index);
  setNumTracks(reader->vx_nTracks->at(m_vertex_index));
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Vertex::setVertexIndex(int val)
{
  m_vertex_index = val;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Vertex::setNumTracks(int val)
{
  m_num_tracks = val;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Vertex::getVertexIndex() const
{
  return m_vertex_index;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::Vertex::getNumTracks() const
{
  return m_num_tracks;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Vertex::print() const
{
  std::cout << "\tvertex number: "  << m_vertex_index
            << "\n"
            << "\tnum tracks: " << m_num_tracks
            << "\n";
  ;
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
