#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/D3PDReader.h"
// #include "PennSusyFrameCore/include/Calculators.h"
#include "RootCore/egammaEvent/egammaEvent/egammaPIDdefs.h"

#include <vector>
#include <iostream>
#include <math.h>

// =============================================================================
static const double PI = 3.14159265359;

// =============================================================================
// = PhysicsObject
// =============================================================================
void PennSusyFrame::PhysicsObject::updateWithMet(const PennSusyFrame::Met&) {}

// =============================================================================
// = Event
// =============================================================================
// -----------------------------------------------------------------------------
// TODO set m_is_data properly
PennSusyFrame::Event::Event() : m_is_data(false) {}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::init() {}

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
{ }

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

// // -----------------------------------------------------------------------------
// void PennSusyFrame::Particle::setParticleIndex(int val)
// {
//   m_particle_index = val;
// }

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

  setAuthor(reader->el_author->at(el_index));
  setMediumPP(reader->el_mediumPP->at(el_index));
  setTightPP(reader->el_tightPP->at(el_index));
  bool pass_otx = ( !( (reader->el_OQ->at(el_index) & egammaPID::BADCLUSELECTRON)
                     > 0
                     )
                  );
  setPassOtx(pass_otx);

  setClE(reader->el_cl_E->at(el_index));
  setClEta(reader->el_cl_eta->at(el_index));
  setClPhi(reader->el_cl_phi->at(el_index));

  setD0(reader->el_trackIPEstimate_d0_unbiasedpvunbiased->at(el_index));
  setSigD0(reader->el_trackIPEstimate_sigd0_unbiasedpvunbiased->at(el_index));
  setZ0(reader->el_trackIPEstimate_z0_unbiasedpvunbiased->at(el_index));
  // TODO set variable
  setPtIso(0);
  // TODO set variable
  setEtIso(0);

  // must set TLV last because it depends on above quantities
  setElTlv(reader, el_rescaler);
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
  setTrackEta(-log(tan(m_id_theta/2)));

  setQOverPRatio( reader->mu_staco_cov_qoverp_exPV->at(mu_index)
                / reader->mu_staco_qoverp_exPV->at(mu_index)
                );

  setNumBLayerHits(reader->mu_staco_nBLHits->at(mu_index));
  setNumPixelHits(reader->mu_staco_nPixHits->at(mu_index));
  setNumSctHits(reader->mu_staco_nSCTHits->at(mu_index));
  setNumSiHoles( reader->mu_staco_nPixHoles->at(mu_index)
               + reader->mu_staco_nSCTHoles->at(mu_index)
               );

  int trt_hits = reader->mu_staco_nTRTHits->at(mu_index);
  int trt_ol   = reader->mu_staco_nTRTOutliers->at(mu_index);
  setNumTrtHits(trt_hits + trt_ol);
  setTrtOlFraction( m_num_trt_hits != 0 ? trt_ol/m_num_trt_hits
                                        : 0.
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
  setNumTracks(reader->tau_numTrack->at(tau_index));

  setJetBdtLoose( reader->tau_JetBDTSigLoose->at( tau_index));
  setJetBdtMedium(reader->tau_JetBDTSigMedium->at(tau_index));
  setJetBdtTight (reader->tau_JetBDTSigTight->at( tau_index));

  setEleBdtLoose( reader->tau_EleBDTLoose->at( tau_index));
  setEleBdtMedium(reader->tau_EleBDTMedium->at(tau_index));
  setEleBdtTight( reader->tau_EleBDTTight->at( tau_index));

  setMuVeto(reader->tau_muonVeto->at(tau_index));

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
  setJvf(          reader->jet_AntiKt4LCTopo_jvtxf->at(m_particle_index));
  setMv1(          reader->jet_AntiKt4LCTopo_flavor_weight_MV1->at(m_particle_index));

  setJetTlv(reader, jet_rescaler, event, num_vertices_ge_2_tracks);

  setIsBad(isBad(reader));
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

// -----------------------------------------------------------------------------
bool PennSusyFrame::Jet::isBad(const PennSusyFrame::D3PDReader* reader)
{
  double emf         = reader->jet_AntiKt4LCTopo_emfrac->at(m_particle_index);
  double eta         = m_constscale_eta;
  double sum_pt_trk  = reader->jet_AntiKt4LCTopo_sumPtTrk_pv0_500MeV->at(m_particle_index);
  double pt          = getPt();
  double chf         = (pt != 0 ? sum_pt_trk/pt : 0.);
  double fmax        = reader->jet_AntiKt4LCTopo_fracSamplingMax->at(m_particle_index);
  double hec_quality = reader->jet_AntiKt4LCTopo_HECQuality->at(m_particle_index);
  double hecf        = reader->jet_AntiKt4LCTopo_hecf->at(m_particle_index);
  double avg_lar_qf  = reader->jet_AntiKt4LCTopo_AverageLArQF->at(m_particle_index);
  double lar_qf_frac = avg_lar_qf/65535.;
  double negative_e  = reader->jet_AntiKt4LCTopo_NegativeE->at(m_particle_index);
  double lar_quality = reader->jet_AntiKt4LCTopo_LArQuality->at(m_particle_index);


  // non-collision background & cosmics
  if (emf  < 0.05 && fabs(eta) >= 2)               return true;
  if (fmax > 0.99 && fabs(eta) <  2)               return true;
  if (emf  < 0.05 && fabs(eta) <  2 && chf < 0.05) return true;

  // HEC spikes
  if (fabs(negative_e) > 60000) return true;
  if (  hecf > 0.5
     && fabs(hec_quality) > 0.5
     && lar_qf_frac >= 0.8
     )
    return true;

  // EM coherent noise
  if (  emf > 0.95
     && fabs(lar_quality) > 0.8
     && fabs(eta) < 2.8
     && lar_qf_frac >= 0.8
     )
    return true;

  // do not flag this as a bad jet
  return false;
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
  setX(reader->vx_x->at(m_vertex_index));
  setY(reader->vx_y->at(m_vertex_index));
  setZ(reader->vx_z->at(m_vertex_index));
  setE(reader->vx_E->at(m_vertex_index));
  setM(reader->vx_m->at(m_vertex_index));
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Vertex::print() const
{
  std::cout << "\tvertex number: "  << m_vertex_index
            << "\n"
            << "\tx: " << m_x
            << "\ty: " << m_y
            << "\tz: " << m_z
            << "\tnum tracks: " << m_num_tracks
            << "\n"
            << "\tE: " << m_e
            << "\tm: " << m_m
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
