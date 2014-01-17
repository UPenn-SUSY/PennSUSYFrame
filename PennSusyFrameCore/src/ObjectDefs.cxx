#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/D3PDReader.h"
// #include "PennSusyFrameCore/include/Calculators.h"
#include "RootCore/egammaEvent/egammaEvent/egammaPIDdefs.h"
#include "RootCore/MissingETUtility/MissingETUtility/METUtility.h"

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

  setMetStatusWord(reader->el_MET_Egamma10NoTau_statusWord->at(el_index));
  setMetWet(reader->el_MET_Egamma10NoTau_wet->at(el_index));
  setMetWpx(reader->el_MET_Egamma10NoTau_wpx->at(el_index));
  setMetWpy(reader->el_MET_Egamma10NoTau_wpy->at(el_index));

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

  setMsQOverP(reader->mu_staco_ms_qoverp->at(mu_index));
  setMsTheta(reader->mu_staco_ms_theta->at(mu_index));
  setMsPhi(reader->mu_staco_ms_phi->at(mu_index));

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

  setMetStatusWord(reader->jet_AntiKt4LCTopo_MET_Egamma10NoTau_statusWord->at(m_particle_index));
  setMetWet(reader->jet_AntiKt4LCTopo_MET_Egamma10NoTau_wet->at(m_particle_index));
  setMetWpx(reader->jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpx->at(m_particle_index));
  setMetWpy(reader->jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpy->at(m_particle_index));

  setJetTlv(reader, jet_rescaler, event, num_vertices_ge_2_tracks);

  setIsBad(isBad(reader));
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::updateWithMet(const PennSusyFrame::Met&)
{
  // TODO update jet object with met -- need to store dphi(jet,met)
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
PennSusyFrame::Met::Met() : m_prepared(false)
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::init()
{
  m_met_utility.defineMissingET( true  // doRefEle
                               , true  // doRefGamma
                               , false // doRefTau
                               , true  // doRefJet
                               , false // doRefMuon
                               , true  // doMuonTotal
                               , true  // doSoftTerms
                               );
  m_met_utility.setIsMuid(false);

  // configure the met utility
  // m_met_utility.configMissingET(m_is_2012, m_is_stvf);
  m_met_utility.configMissingET( true  // is_2012
                               , false // is_stvf
                               );
  m_met_utility.setJetPUcode(MissingETTags::DEFAULT);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::prep( const PennSusyFrame::D3PDReader* reader
                             , const Event& event 
                             , const std::vector<PennSusyFrame::Electron*>* el_list
                             , const std::vector<PennSusyFrame::Muon*>* mu_list
                             , const std::vector<PennSusyFrame::Jet*>* jet_list
                             )
{
  if (!m_prepared) {

    m_met_utility.setAverageIntPerXing(event.getAverageIntPerXing());

    addMet(reader);
    addElectrons(el_list);
    addMuons(mu_list);
    addJets(jet_list);

    // mark the met as preparaed
    m_prepared = true;
  }

  // get met object from met utility
  METUtility::METObject met_util;
  met_util = m_met_utility.getMissingET( METUtil::RefFinal );

  // set met vector
  m_met_vec.Set(met_util.etx(), met_util.ety());
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::clear()
{
  m_met_utility.reset();
  m_prepared = false;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::addMet(const PennSusyFrame::D3PDReader* reader)
{
  m_met_utility.setMETTerm( METUtil::SoftTerms
                          , reader->MET_CellOut_etx
                          , reader->MET_CellOut_ety
                          , reader->MET_CellOut_sumet
                          );


  m_met_utility.setMETTerm( METUtil::RefGamma
                          , reader->MET_RefGamma_etx
                          , reader->MET_RefGamma_ety
                          , reader->MET_RefGamma_sumet
                          );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::addElectrons(const std::vector<PennSusyFrame::Electron*>* el_list)
{
  // initialize container vectors for electron parameters
  int n_el = el_list->size();
  std::vector<float> el_pt;
  std::vector<float> el_eta;
  std::vector<float> el_phi;

  std::vector<std::vector<float> > el_wet;
  std::vector<std::vector<float> > el_wpx;
  std::vector<std::vector<float> > el_wpy;
  std::vector<std::vector<unsigned int> > el_status_word;

  // reserve their size for a little optimization
  el_pt.reserve(n_el);
  el_eta.reserve(n_el);
  el_phi.reserve(n_el);

  el_wet.reserve(n_el);
  el_wpx.reserve(n_el);
  el_wpy.reserve(n_el);
  el_status_word.reserve(n_el);

  // Loop over electrons and get each of their parameters and weights
  std::vector<PennSusyFrame::Electron*>::const_iterator el_it = el_list->begin();
  std::vector<PennSusyFrame::Electron*>::const_iterator el_term = el_list->end();
  for (; el_it != el_term; ++el_it) {
    // skip electrons with wet == 0
    if ((*el_it)->getMetWet().at(0) == 0) continue;

    // fill electron kinematic vectors
    el_pt.push_back( (*el_it)->getPt() );
    el_eta.push_back((*el_it)->getEta());
    el_phi.push_back((*el_it)->getPhi());

    // get MET status word for this electron
    el_status_word.push_back((*el_it)->getMetStatusWord());

    // get MET weights for this electron - apply weight fix
    std::vector<float> el_tmp_wet;
    std::vector<float> el_tmp_wpx;
    std::vector<float> el_tmp_wpy;
    el_tmp_wet = (*el_it)->getMetWet();
    el_tmp_wpx = (*el_it)->getMetWpx();
    el_tmp_wpy = (*el_it)->getMetWpy();

    doWeightFix(el_tmp_wet, el_tmp_wpx, el_tmp_wpy);

    // add corrected weights to weight vectors
    el_wet.push_back(el_tmp_wet);
    el_wpx.push_back(el_tmp_wpx);
    el_wpy.push_back(el_tmp_wpy);
  }

  m_met_utility.setElectronParameters( &el_pt
                                     , &el_eta
                                     , &el_phi
                                     , &el_wet
                                     , &el_wpx
                                     , &el_wpy
                                     , &el_status_word
                                     );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::addMuons(const std::vector<PennSusyFrame::Muon*>* mu_list)
{
  // initialize container vectors for muon parameters
  int n_mu = mu_list->size();
  std::vector<float> mu_pt;
  std::vector<float> mu_eta;
  std::vector<float> mu_phi;
  std::vector<std::vector<float> > mu_wet;
  std::vector<std::vector<float> > mu_wpx;
  std::vector<std::vector<float> > mu_wpy;
  std::vector<std::vector<unsigned int> > mu_status_word;
  std::vector<float> mu_ms_qoverp;
  std::vector<float> mu_ms_theta;
  std::vector<float> mu_ms_phi;
  std::vector<float> mu_charge;

  // reserve their size for a little optimization
  mu_pt.reserve(n_mu);
  mu_eta.reserve(n_mu);
  mu_phi.reserve(n_mu);
  mu_wet.reserve(n_mu);
  mu_wpx.reserve(n_mu);
  mu_wpy.reserve(n_mu);
  mu_status_word.reserve(n_mu);
  mu_ms_qoverp.reserve(n_mu);
  mu_ms_theta.reserve(n_mu);
  mu_ms_phi.reserve(n_mu);
  mu_charge.reserve(n_mu);

  std::vector<float> unit_vec(1., 1);
  std::vector<unsigned int> default_vec(MissingETTags::DEFAULT, 1);

  std::vector<Muon*>::const_iterator mu_it = mu_list->begin();
  std::vector<Muon*>::const_iterator mu_term = mu_list->end();
  for (; mu_it != mu_term; ++mu_it) {
    mu_pt.push_back( (*mu_it)->getPt());
    mu_eta.push_back((*mu_it)->getEta());
    mu_phi.push_back((*mu_it)->getPhi());
    mu_wet.push_back(unit_vec);
    mu_wpx.push_back(unit_vec);
    mu_wpy.push_back(unit_vec);
    mu_status_word.push_back(default_vec);

    mu_ms_qoverp.push_back((*mu_it)->getMsQOverP());
    mu_ms_theta.push_back((*mu_it)->getMsTheta());
    mu_ms_phi.push_back((*mu_it)->getMsPhi());
    mu_charge.push_back((*mu_it)->getCharge());
  }

  m_met_utility.setMuonParameters( &mu_pt
                                 , &mu_eta
                                 , &mu_phi
                                 , &mu_wet
                                 , &mu_wpx
                                 , &mu_wpy
                                 , &mu_status_word
                                 );
  m_met_utility.setExtraMuonParameters( &mu_ms_qoverp
                                      , &mu_ms_theta
                                      , &mu_ms_phi
                                      , &mu_charge
                                      );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::addJets(const std::vector<PennSusyFrame::Jet*>* jet_list)
{
  // initialize container vectors for electron parameters
  int n_jets = jet_list->size();
  std::vector<float> jet_pt;
  std::vector<float> jet_eta;
  std::vector<float> jet_phi;
  std::vector<float> jet_E;
  std::vector<float> jet_orig_pt;

  std::vector<std::vector<float> > jet_wet;
  std::vector<std::vector<float> > jet_wpx;
  std::vector<std::vector<float> > jet_wpy;
  std::vector<std::vector<unsigned int> > jet_status_word;

  // reserve their size for a little optimization
  jet_pt.reserve(n_jets);
  jet_eta.reserve(n_jets);
  jet_phi.reserve(n_jets);
  jet_E.reserve(n_jets);
  jet_orig_pt.reserve(n_jets);

  jet_wet.reserve(n_jets);
  jet_wpx.reserve(n_jets);
  jet_wpy.reserve(n_jets);
  jet_status_word.reserve(n_jets);

  // Loop over jets and get their parameters and weights
  std::vector<Jet*>::const_iterator jet_it = jet_list->begin();
  std::vector<Jet*>::const_iterator jet_term = jet_list->end();
  for (; jet_it != jet_term; ++jet_it) {
    // fill jet kinematic vectors
    jet_pt.push_back( (*jet_it)->getPt());
    jet_eta.push_back((*jet_it)->getRawEta());
    jet_phi.push_back((*jet_it)->getRawPhi());
    jet_E.push_back(  (*jet_it)->getE());

    // get MET status word for this jet
    jet_status_word.push_back((*jet_it)->getMetStatusWord());

    // get MET weights for this jet - apply weight fix
    std::vector<float> jet_tmp_wet;
    std::vector<float> jet_tmp_wpx;
    std::vector<float> jet_tmp_wpy;
    jet_tmp_wet = (*jet_it)->getMetWet();
    jet_tmp_wpx = (*jet_it)->getMetWpx();
    jet_tmp_wpy = (*jet_it)->getMetWpy();

    doWeightFix(jet_tmp_wet, jet_tmp_wpx, jet_tmp_wpy);

    jet_wet.push_back(jet_tmp_wet);
    jet_wpx.push_back(jet_tmp_wpx);
    jet_wpy.push_back(jet_tmp_wpy);
  }

  m_met_utility.setJetParameters( &jet_pt
                                , &jet_eta
                                , &jet_phi
                                , &jet_E
                                , &jet_wet
                                , &jet_wpx
                                , &jet_wpy
                                , &jet_status_word
                                );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::doWeightFix( std::vector<float>& wet
                                    , std::vector<float>& wpx
                                    , std::vector<float>& wpy
                                    )
{
    // temp fix for too large and too small electron weights
    unsigned int num_weights = wet.size();
    for (unsigned int cl = 0; cl < num_weights; ++cl) {
      if (  wpx[cl] < 0.5 * wet[cl]
         || wpx[cl] > 2   * wet[cl]
         ) {
        wpx[cl] = wet[cl];
      }
      if (  wpy[cl] < 0.5 * wet[cl]
         || wpy[cl] > 2   * wet[cl]
         ) {
        wpy[cl] = wet[cl];
      }
    }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::print() const
{
  std::cout << "MET\n"
            << "\n"
            << "\tMET et: "  << m_met_vec.Mod()
            << "\tMET phi: " << m_met_vec.Phi()
            << "\tMET ex: "  << m_met_vec.X()
            << "\tMET ey: "  << m_met_vec.Y()
            << "\n";
}
