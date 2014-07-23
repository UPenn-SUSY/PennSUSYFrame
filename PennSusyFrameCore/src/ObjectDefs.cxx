#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/D3PDReader.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "RootCore/egammaEvent/egammaEvent/egammaPIDdefs.h"
#include "RootCore/MissingETUtility/MissingETUtility/METUtility.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

#include "TVector2.h"

// =============================================================================
static const double PI = 3.14159265359;
static const double PI_OVER_2 = PI/2.;

// =============================================================================
// = PhysicsObject
// =============================================================================
void PennSusyFrame::PhysicsObject::updateWithMet(const PennSusyFrame::Met&) {}

// =============================================================================
// = Event
// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::Event::Event() : m_is_data(false)
                              , m_event_number(0)
                              , m_run_number(0)
                              , m_lumi_block(0)
                              , m_average_int_per_xing(0)
                              , m_eventshape_rhoKt4LC(0)
                              , m_flavor_channel(FLAVOR_NONE)
                              , m_sign_channel(SIGN_NONE)
                              , m_phase_channel(PHASE_NONE)
                              , m_trig_phase_channel(TRIG_NONE)
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::init() {}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::getEvent( const PennSusyFrame::D3PDReader* reader
                                   )
{
  setEventNumber(reader->EventNumber);
  setRunNumber(reader->RunNumber);
  setLumiBlock(reader->lbn);

  setAverageIntPerXing(reader->averageIntPerXing);
  setEventShapeRhoKt4LC(reader->Eventshape_rhoKt4LC);

  setCoreFlags(reader->coreFlags);
  setLarError(reader->larError);
  setTileError(reader->tileError);

  setPhaseSpace(PHASE_NONE);
  setTriggerPhase(TRIG_NONE);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::updateWithMet(const PennSusyFrame::Met& /*met*/)
{ }

// -----------------------------------------------------------------------------
void PennSusyFrame::Event::print() const
{
  std::cout << "================= Printing event info: =================\n";
  std::cout << "run number: " << m_run_number
            // << "\tlumi block: " << m_lumi_block
            << "\tevent number: " << m_event_number
            << "\n"
            << "\tFlavor channel: " << FLAVOR_CHANNEL_STRINGS[m_flavor_channel]
            << "\tSign channel: " << SIGN_CHANNEL_STRINGS[m_sign_channel]
            << "\n";
}

// =============================================================================
// = EventLevelQuantities
// =============================================================================
PennSusyFrame::EventLevelQuantities::EventLevelQuantities() : m_mll(0.)
                                                            , m_ptll(0.)
                                                            , m_mt2(0.)
                                                            , m_emma_mt(0.)
                                                            , m_dphi_ll(0.)
                                                            , m_ht_all(0.)
                                                            , m_ht_baseline(0.)
                                                            , m_ht_good(0.)
                                                            , m_ht_signal(0.)
                                                            , m_mc_event_weight(1.)
                                                            , m_pile_up_sf(1.)
                                                            , m_lepton_sf(1.)
                                                            , m_trigger_weight(1.)
                                                            , m_b_tag_sf(1.)
							    , m_cf_weight(0.)
							    , m_fake_weight(0.)  
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::EventLevelQuantities::init() {}

// -----------------------------------------------------------------------------
void PennSusyFrame::EventLevelQuantities::print() const
{
  std::cout << "================= Printing event level quantities: =================\n";
  std::cout <<std::setw(17)<<left<< "mll: " << std::setw(20)<<left<<m_mll
            <<std::setw(17)<<left<< "ptll: " << std::setw(20)<<left<<m_ptll
            <<std::setw(17)<<left<< "mt2: " << std::setw(20)<<left<<m_mt2
            << "\n"
            <<std::setw(17)<<left<< "emma mt: " << std::setw(20)<<left<<m_emma_mt
            <<std::setw(17)<<left<< "dphi_ll: " << std::setw(20)<<left<<m_dphi_ll
            <<"\n"
            <<std::setw(17)<<left<< "ht(all): " << std::setw(20)<<left<<m_ht_all
            <<std::setw(17)<<left<< "ht(baseline): " << std::setw(20)<<left<<m_ht_baseline
            <<std::setw(17)<<left<< "ht(good): " << std::setw(20)<<left<<m_ht_good
            <<std::setw(17)<<left<< "ht(signal): " << std::setw(20)<<left<<m_ht_signal
            << "\n"
            <<std::setw(17)<<left<< "mc event weight: " << std::setw(20)<<left<<m_mc_event_weight
            <<std::setw(17)<<left<< "lepton sf: " << std::setw(20)<<left<<m_lepton_sf
            <<std::setw(17)<<left<< "trigger sf: " << std::setw(20)<<left<<m_trigger_weight
            <<std::setw(17)<<left<< "b tag sf: " << std::setw(20)<<left<<m_b_tag_sf
            <<"\n";
}

// =============================================================================
// = Trigger
// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::Trigger::Trigger() : m_trig_EF_el_px(0)
                                  , m_trig_EF_el_py(0)
                                  , m_trig_EF_el_pz(0)
                                  , m_trig_EF_trigmuonef_track_CB_eta(0)
                                  , m_trig_EF_trigmuonef_track_CB_phi(0)
                                  , m_trig_EF_trigmuonef_track_CB_pt(0)
                                  , m_trig_EF_el_E(0)
                                  , m_trig_EF_el_EF_e12Tvh_loose1(0)
                                  , m_trig_EF_el_EF_e12Tvh_medium1(0)
                                  , m_trig_EF_el_EF_e24vh_medium1(0)
                                  , m_trig_EF_el_EF_e24vh_medium1_e7_medium1(0)
                                  , m_trig_EF_el_EF_e7T_medium1(0)
                                  , m_trig_EF_trigmuonef_EF_mu13(0)
                                  , m_trig_EF_trigmuonef_EF_mu18_tight(0)
                                  , m_trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS(0)
                                  , m_trig_EF_trigmuonef_EF_mu8(0)
                                  , m_trig_EF_trigmuonef_track_CB_hasCB(0)
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::Trigger::init() {}

// -----------------------------------------------------------------------------
void PennSusyFrame::Trigger::getEvent(const PennSusyFrame::D3PDReader* reader
                                     )
{
  setEF_2e12Tvh_loose1(          reader->EF_2e12Tvh_loose1);
  setEF_e24vh_medium1_e7_medium1(reader->EF_e24vh_medium1_e7_medium1);
  setEF_2mu13(                   reader->EF_2mu13);
  setEF_mu18_tight_mu8_EFFS(     reader->EF_mu18_tight_mu8_EFFS);
  setEF_e12Tvh_medium1_mu8(      reader->EF_e12Tvh_medium1_mu8);
  setEF_mu18_tight_e7_medium1(   reader->EF_mu18_tight_e7_medium1);

  setTrig_EF_el_E(                             reader->trig_EF_el_E);
  setTrig_EF_el_EF_e12Tvh_loose1(              reader->trig_EF_el_EF_e12Tvh_loose1);
  setTrig_EF_el_EF_e12Tvh_medium1(             reader->trig_EF_el_EF_e12Tvh_medium1);
  setTrig_EF_el_EF_e24vh_medium1(              reader->trig_EF_el_EF_e24vh_medium1);
  setTrig_EF_el_EF_e24vh_medium1_e7_medium1(   reader->trig_EF_el_EF_e24vh_medium1_e7_medium1);
  setTrig_EF_el_EF_e7T_medium1(                reader->trig_EF_el_EF_e7T_medium1);
  setTrig_EF_el_px(                            reader->trig_EF_el_px);
  setTrig_EF_el_py(                            reader->trig_EF_el_py);
  setTrig_EF_el_pz(                            reader->trig_EF_el_pz);
  setTrig_EF_trigmuonef_EF_mu13(               reader->trig_EF_trigmuonef_EF_mu13);
  setTrig_EF_trigmuonef_EF_mu18_tight(         reader->trig_EF_trigmuonef_EF_mu18_tight);
  setTrig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS(reader->trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS);
  setTrig_EF_trigmuonef_EF_mu8(                reader->trig_EF_trigmuonef_EF_mu8);
  setTrig_EF_trigmuonef_track_CB_eta(          reader->trig_EF_trigmuonef_track_CB_eta);
  setTrig_EF_trigmuonef_track_CB_hasCB(        reader->trig_EF_trigmuonef_track_CB_hasCB);
  setTrig_EF_trigmuonef_track_CB_phi(          reader->trig_EF_trigmuonef_track_CB_phi);
  setTrig_EF_trigmuonef_track_CB_pt (          reader->trig_EF_trigmuonef_track_CB_pt);
}

// =============================================================================
// = Particle
// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::Particle::Particle() : m_tlv_set(false)
                                    , m_raw_tlv_set(false)
                                    , m_is_signal(false)
{ }

// -----------------------------------------------------------------------------
void PennSusyFrame::Particle::printGeneralInfo() const
{
  std::cout << std::setw(17)<<left<< "pt: "  <<std::setw(20)<<left<< m_tlv.Pt()
            << std::setw(17)<<left<<"eta: " << std::setw(20)<<left<<m_tlv.Eta()
            << std::setw(17)<<left<<"phi: " << std::setw(20)<<left<<m_tlv.Phi()
            << std::setw(17)<<left<<"E: "   << std::setw(20)<<left<<m_tlv.E()
            <<"\n"
            << std::setw(17)<<left<<"raw pt: "  << std::setw(20)<<left<<m_raw_tlv.Pt()
            << std::setw(17)<<left<<"raw eta: " << std::setw(20)<<left<<m_raw_tlv.Eta()
            << std::setw(17)<<left<<"raw phi: " << std::setw(20)<<left<<m_raw_tlv.Phi()
            << std::setw(17)<<left<<"raw E: "   << std::setw(20)<<left<<m_raw_tlv.E()
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
void PennSusyFrame::Particle::setIsSignal(bool val)
{
  m_is_signal = val;
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
bool PennSusyFrame::Particle::getIsSignal() const
{
  return m_is_signal;
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
PennSusyFrame::Lepton::Lepton() {}

// -----------------------------------------------------------------------------
void PennSusyFrame::Lepton::updateIsolation(const PennSusyFrame::Event*, int) {}

// -----------------------------------------------------------------------------
void PennSusyFrame::Lepton::print() const
{
  std::cout <<std::setw(8)<<left<< "lepton " << m_particle_index << ":: ";
  if (m_is_electron)          std::cout <<std::setw(20)<<left<< "electron";
  else if (m_is_light_lepton) std::cout <<std::setw(20)<<left<< "muon";
  else                        std::cout <<std::setw(20)<<left<< "tau";
  std::cout <<std::setw(20)<<left<< "charge: " << m_charge
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
                                 , bool is_data
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

  setAuthor(  reader->el_author->at(el_index));
  setMediumPP(reader->el_mediumPP->at(el_index));
  setTightPP( reader->el_tightPP->at(el_index));
  bool pass_otx = ( !( (reader->el_OQ->at(el_index) & egammaPID::BADCLUSELECTRON)
                     > 0
                     )
                  );
  setPassOtx(pass_otx);

  setClE(  reader->el_cl_E->at(el_index));
  setClEta(reader->el_cl_eta->at(el_index));
  setClPhi(reader->el_cl_phi->at(el_index));

  setD3PDEta(reader->el_eta->at(el_index));
  setD3PDPhi(reader->el_phi->at(el_index));

  setD0(   reader->el_trackIPEstimate_d0_unbiasedpvunbiased->at(el_index));
  setSigD0(reader->el_trackIPEstimate_sigd0_unbiasedpvunbiased->at(el_index));
  setZ0(   reader->el_trackIPEstimate_z0_unbiasedpvunbiased->at(el_index));

  setRawPtIso(reader->el_ptcone30->at(el_index));
  setRawEtIso(reader->el_topoEtcone30_corrected->at(el_index));
  setPtIso(0.);
  setEtIso(0.);

  setMetStatusWord(reader->el_MET_Egamma10NoTau_statusWord->at(el_index));
  setMetWet(reader->el_MET_Egamma10NoTau_wet->at(el_index));
  setMetWpx(reader->el_MET_Egamma10NoTau_wpx->at(el_index));
  setMetWpy(reader->el_MET_Egamma10NoTau_wpy->at(el_index));

  if (!is_data) {
    setOrigin(reader->el_origin->at(el_index));
    setType(reader->el_type->at(el_index));
    setTruthBarcode(reader->el_truth_barcode->at(el_index));
    setTruthParentBarcode(reader->el_truth_motherbarcode->at(el_index));
  }

  // must set TLV last because it depends on above quantities
  setElTlv(reader, el_rescaler);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::updateIsolation( const PennSusyFrame::Event* event
                                             , int num_vertices
                                             )
{
  // pt iso correction
  // float pt_slope = 0.;
  // if (event->getIsData()) pt_slope = 0.;
  // else                    pt_slope = 0.;
  // setPtIso(m_raw_pt_iso - pt_slope*num_vertices);
  setPtIso(m_raw_pt_iso);

  // et iso correction
  float et_slope = 0.;
  if (event->getIsData()) et_slope = 20.15;
  else                    et_slope = 17.94;
  setEtIso(m_raw_et_iso - et_slope*num_vertices);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::print() const
{
  Lepton::print();
  std::cout <<std::setw(17)<<left<< "cluster E: "  << std::setw(20)<<left<<m_cl_E
	    <<std::setw(17)<<left<< "cluster eta: "<< std::setw(20)<<left<<m_cl_eta
	    <<std::setw(17)<<left<< "cluster phi: "<< std::setw(20)<<left<<m_cl_phi
            <<std::setw(17)<<left<< "raw pt iso: " << std::setw(20)<<left<<m_raw_pt_iso
            <<std::setw(17)<<left<< "raw et iso: " <<  std::setw(20)<<left<<m_raw_et_iso
            <<"\n"
            <<std::setw(17)<<left<< "pt iso: " <<  std::setw(20)<<left<<m_pt_iso
            <<std::setw(17)<<left<< "et iso: " <<  std::setw(20)<<left<<m_et_iso
            <<"\n\n";
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Electron::setElTlv( const PennSusyFrame::D3PDReader* reader
                                      , PennSusyFrame::ElectronRescalerTool* el_rescaler
                                      )
{
  int num_si_hits = reader->el_nSiHits->at(m_particle_index);
  double raw_pt  = reader->el_cl_pt->at(m_particle_index);
  double raw_eta = ( num_si_hits < 4 ? reader->el_cl_eta->at(m_particle_index)
                                     : reader->el_tracketa->at(m_particle_index)
                   );
  double raw_phi = ( num_si_hits < 4 ? reader->el_cl_phi->at(m_particle_index)
                                     : reader->el_trackphi->at(m_particle_index)
                   );
  double raw_e   = reader->el_cl_E->at(m_particle_index);
  TLorentzVector raw_tlv;
  raw_tlv.SetPtEtaPhiE( raw_pt
                      , raw_eta
                      , raw_phi
                      , raw_e
                      );
  setRawTlv(raw_tlv);

  double corrected_eta = raw_eta;
  double corrected_phi = raw_phi;
  double corrected_e  = el_rescaler->getRescaledE(this);
  double corrected_et = corrected_e/cosh(corrected_eta);
  TLorentzVector tlv;
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
                         , bool is_data
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

  float cov_q_over_p = reader->mu_staco_cov_qoverp_exPV->at(mu_index);
  float q_over_p     = reader->mu_staco_qoverp_exPV->at(mu_index);
  setQOverPRatio(sqrt(cov_q_over_p) / fabs(q_over_p));

  setExpectBLayer( reader->mu_staco_expectBLayerHit->at(mu_index));
  setNumBLayerHits(reader->mu_staco_nBLHits->at(mu_index));
  setNumPixelHits( reader->mu_staco_nPixHits->at(mu_index));
  setNumSctHits( reader->mu_staco_nSCTHits->at(mu_index)
               + reader->mu_staco_nSCTDeadSensors->at(mu_index)
               );
  setNumSiHoles( reader->mu_staco_nPixHoles->at(mu_index)
               + reader->mu_staco_nSCTHoles->at(mu_index)
               );

  int trt_hits = reader->mu_staco_nTRTHits->at(mu_index);
  int trt_ol   = reader->mu_staco_nTRTOutliers->at(mu_index);
  setNumTrtHits(trt_hits + trt_ol);
  setTrtOlFraction( m_num_trt_hits != 0 ? trt_ol/m_num_trt_hits
                                        : 0.
                  );

  setD0(    reader->mu_staco_trackIPEstimate_d0_unbiasedpvunbiased->at(mu_index));
  setSigD0( reader->mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased->at(mu_index));
  setZ0(    reader->mu_staco_trackIPEstimate_z0_unbiasedpvunbiased->at(mu_index));
  setD0exPV(reader->mu_staco_d0_exPV->at(mu_index));
  setZ0exPV(reader->mu_staco_z0_exPV->at(mu_index));

  setRawPtIso(reader->mu_staco_ptcone30_trkelstyle->at(mu_index));
  setRawEtIso(reader->mu_staco_etcone30->at(mu_index));
  setPtIso(0.);
  setEtIso(0.);

  setMsQOverP(reader->mu_staco_ms_qoverp->at(mu_index));
  setMsTheta(reader->mu_staco_ms_theta->at(mu_index));
  setMsPhi(reader->mu_staco_ms_phi->at(mu_index));

  if (!is_data) {
    setTruthBarcode(reader->mu_staco_truth_barcode->at(mu_index));
    setTruthParentBarcode(reader->mu_staco_truth_motherbarcode->at(mu_index));
  }

  setMuTlv(reader, mu_rescaler);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::updateIsolation( const PennSusyFrame::Event* /*event*/
                                         , int /*num_vertices*/
                                         )
{
  // pt iso correction
  // float pt_slope = 0.;
  // if (event->getIsData()) pt_slope = 0.;
  // else                    pt_slope = 0.;
  // setPtIso(m_raw_pt_iso - pt_slope*num_vertices);
  setPtIso(m_raw_pt_iso);

  // et iso correction
  // float et_slope = 0.;
  // if (event->getIsData()) et_slope = 0.;
  // else                    et_slope = 0.;
  // setEtIso(m_raw_et_iso - et_slope*num_vertices);
  setEtIso(m_raw_et_iso);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::print() const
{
  Lepton::print();
  std::cout <<std::setw(17)<<left<< "pt iso: "      <<std::setw(20)<<left<< getPtIso()
            <<std::setw(17)<<left<< "pt iso frac: " <<std::setw(20)<<left<< getPtIsoRatio()
            <<std::setw(17)<<left<< "et iso: "      <<std::setw(20)<<left<< getEtIso()
            <<std::setw(17)<<left<< "et iso frac: " <<std::setw(20)<<left<< getEtIsoRatio()
            <<"\n"
            <<std::setw(17)<<left<< "raw pt iso: "      <<std::setw(20)<<left<< getRawPtIso()
            <<std::setw(17)<<left<< "raw pt iso frac: " <<std::setw(20)<<left<< getRawPtIsoRatio()
            <<std::setw(17)<<left<< "raw et iso: "      <<std::setw(20)<<left<< getRawEtIso()
            <<std::setw(17)<<left<< "raw et iso frac: " <<std::setw(20)<<left<< getRawEtIsoRatio()
            << "\n"
            <<std::setw(17)<<left<< "d0: " <<std::setw(20)<<left<< getD0()
            <<std::setw(17)<<left<< "d0 sig: " <<std::setw(20)<<left<< getD0Significance()
            <<std::setw(17)<<left<< "z0: " <<std::setw(20)<<left<< getZ0()
            <<std::setw(17)<<left<< "z0sin(theta): " <<std::setw(20)<<left<< getZ0SinTheta()
            << "\n"
            <<std::setw(17)<<left<< "expect b-layer: " << std::setw(20)<<left<<getExpectBLayer()
            <<std::setw(17)<<left<< "# b-layer hits: " << std::setw(20)<<left<<getNumBLayerHits()
            <<std::setw(17)<<left<< "# pixel hits: " << std::setw(20)<<left<<getNumPixelHits()
            <<"\n"   
            <<std::setw(17)<<left<< "# sct hits: " << std::setw(20)<<left<<getNumSctHits()
            <<std::setw(17)<<left<< "# si holes: " << std::setw(20)<<left<<getNumSiHoles()
            <<"\n"
            <<std::setw(17)<<left<< "track eta: " << std::setw(20)<<left<<getTrackEta()
            <<std::setw(17)<<left<< "# TRT hits: " << std::setw(20)<<left<<getNumTrtHits()
            <<std::setw(17)<<left<< "TRT outlier frac: " << std::setw(20)<<left<<getTrtOlFraction()
            <<"\n\n";
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Muon::setMuTlv( const PennSusyFrame::D3PDReader* reader
                                  , PennSusyFrame::MuonRescalerTool* mu_rescaler
                                  )
{
  double raw_pt  = reader->mu_staco_pt->at(m_particle_index);
  double raw_eta = reader->mu_staco_eta->at(m_particle_index);
  double raw_phi = reader->mu_staco_phi->at(m_particle_index);
  double raw_m   = 105.66;
  TLorentzVector raw_tlv;
  raw_tlv.SetPtEtaPhiM(raw_pt, raw_eta, raw_phi, raw_m);
  setRawTlv(raw_tlv);

  double corrected_pt  = mu_rescaler->getSmearedPt(this);
  double corrected_eta = raw_eta;
  double corrected_phi = raw_phi;
  double corrected_m   = raw_m;
  TLorentzVector tlv;
  tlv.SetPtEtaPhiM(corrected_pt, corrected_eta, corrected_phi, corrected_m);
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
                       , bool is_data
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
  std::cout<<"\n";
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Tau::setTauTlv( const PennSusyFrame::D3PDReader* reader
                                  , PennSusyFrame::TauRescalerTool* /*tau_rescaler*/
                                  )
{
  double raw_pt  = reader->tau_pt->at(m_particle_index);
  double raw_eta = reader->tau_eta->at(m_particle_index);
  double raw_phi = reader->tau_phi->at(m_particle_index);
  double raw_m   = reader->tau_m->at(m_particle_index);;
  TLorentzVector raw_tlv;
  raw_tlv.SetPtEtaPhiM(raw_pt, raw_eta, raw_phi, raw_m);
  setRawTlv(raw_tlv);

  // TODO get rescaled tau
  double corrected_pt  = raw_pt;
  double corrected_eta = raw_eta;
  double corrected_phi = raw_phi;
  double corrected_m   = raw_m;
  TLorentzVector tlv;
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
                       , PennSusyFrame::Event* event
                       , int num_vertices_ge_2_tracks
                       , bool is_data
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
  setBchCorr(      reader->jet_AntiKt4LCTopo_BCH_CORR_JET->at(m_particle_index));

  setEmf(            reader->jet_AntiKt4LCTopo_emfrac->at(m_particle_index));
  setSumPtTrk(       reader->jet_AntiKt4LCTopo_sumPtTrk_pv0_500MeV->at(m_particle_index));

  setSamplingMax(    reader->jet_AntiKt4LCTopo_SamplingMax->at(m_particle_index));
  setFracSamplingMax(reader->jet_AntiKt4LCTopo_fracSamplingMax->at(m_particle_index));
  setHecQuality(     reader->jet_AntiKt4LCTopo_HECQuality->at(m_particle_index));
  setHecf(           reader->jet_AntiKt4LCTopo_hecf->at(m_particle_index));
  setAvgLarQf(       reader->jet_AntiKt4LCTopo_AverageLArQF->at(m_particle_index));
  setNegativeE(      reader->jet_AntiKt4LCTopo_NegativeE->at(m_particle_index));
  setLarQuality(     reader->jet_AntiKt4LCTopo_LArQuality->at(m_particle_index));

  setMetStatusWord(reader->jet_AntiKt4LCTopo_MET_Egamma10NoTau_statusWord->at(m_particle_index));
  setMetWet(reader->jet_AntiKt4LCTopo_MET_Egamma10NoTau_wet->at(m_particle_index));
  setMetWpx(reader->jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpx->at(m_particle_index));
  setMetWpy(reader->jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpy->at(m_particle_index));

  setJetTlv(reader, jet_rescaler, event, num_vertices_ge_2_tracks);

  setIsBad(isBad());

  if (!is_data) {
    setFlavorTruthLabel( reader->jet_AntiKt4LCTopo_flavor_truth_label->at(m_particle_index));
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::updateWithMet(const PennSusyFrame::Met& met)
{
  setDphiMet(met.getDPhi(this));
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::print() const
{
  std::cout << "\tjet " << m_particle_index << "\n";
  printGeneralInfo();

  std::cout << "\t\tMV1: " << m_mv1
            << "\n";

}

// -----------------------------------------------------------------------------
void PennSusyFrame::Jet::setJetTlv( const PennSusyFrame::D3PDReader* reader
                                  , PennSusyFrame::JetRescalerTool* jet_rescaler
                                  , PennSusyFrame::Event* event
                                  , int num_vertices_w_2_trks
                                  )
{
  double raw_pt  = reader->jet_AntiKt4LCTopo_pt->at(m_particle_index);
  double raw_eta = reader->jet_AntiKt4LCTopo_eta->at(m_particle_index);
  double raw_phi = reader->jet_AntiKt4LCTopo_phi->at(m_particle_index);
  double raw_m   = reader->jet_AntiKt4LCTopo_m->at(m_particle_index);
  TLorentzVector raw_tlv;
  raw_tlv.SetPtEtaPhiM(raw_pt, raw_eta, raw_phi, raw_m);
  setRawTlv(raw_tlv);

  TLorentzVector tlv = jet_rescaler->getCalibratedTlv( this
                                                     , event
                                                     , num_vertices_w_2_trks
                                                     );
  setTlv(tlv);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::Jet::isBad()
{

  double pt          = getPt();
  double chf         = (pt != 0 ? m_sum_pt_trk/pt : 0.);
  double lar_qf_frac = m_avg_lar_qf/65535.;

  // non-collision background & cosmics
  if (m_emf               < 0.05 && fabs(m_constscale_eta) >= 2)               return true;
  if (m_frac_sampling_max > 0.99 && fabs(m_constscale_eta) <  2)               return true;
  if (m_emf               < 0.05 && fabs(m_constscale_eta) <  2 && chf < 0.05) return true;

  // HEC spikes
  if (fabs(m_negative_e) > 60000) return true;
  if (  m_hecf > 0.5
     && fabs(m_hec_quality) > 0.5
     && lar_qf_frac >= 0.8
     )
    return true;

  // EM coherent noise
  if (  m_emf > 0.95
     && fabs(m_lar_quality) > 0.8
     && fabs(m_constscale_eta) < 2.8
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
  std::cout << std::setw(17)<<left<<"vertex number: "  <<std::setw(20)<<left<< m_vertex_index
            << "\n"
            << std::setw(17)<<left<<"x: " <<std::setw(20)<<left<< m_x
            << std::setw(17)<<left<<"y: " <<std::setw(20)<<left<< m_y
            << std::setw(17)<<left<<"z: " <<std::setw(20)<<left<< m_z
            << std::setw(17)<<left<<"num tracks: " <<std::setw(20)<<left<< m_num_tracks
            << "\n"
            << std::setw(17)<<left<<"E: " <<std::setw(20)<<left<< m_e
            << std::setw(17)<<left<<"m: " <<std::setw(20)<<left<< m_m
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
                             // , const PennSusyFrame::EventLevelQuantities& event_quantities
                             , const std::vector<PennSusyFrame::Electron*>* el_list
                             , const std::vector<PennSusyFrame::Muon*>* mu_list
                             , const std::vector<PennSusyFrame::Jet*>* jet_list
                             )
{
  if (!m_prepared) {

    // std::cout << "\nPreparing Met for event " << event.getEventNumber() << "\n";

    m_met_utility.setAverageIntPerXing(event.getAverageIntPerXing());
    // std::cout << "\tAverageIntPerXing: " << event.getAverageIntPerXing() << "\n";

    // std::cout << "\tadding met terms\n";
    addMet(reader);
    // std::cout << "\tadding electron terms\n";
    addElectrons(el_list);
    // std::cout << "\tadding muon terms\n";
    addMuons(mu_list);
    // std::cout << "\tadding jet terms\n";
    addJets(jet_list);

    // mark the met as preparaed
    m_prepared = true;

    // get met object from met utility
    METUtility::METObject met_util;
    met_util = m_met_utility.getMissingET( METUtil::RefFinal );

    // set met vector
    m_met_vec.Set(met_util.etx(), met_util.ety());
    m_met_et = m_met_vec.Mod();
    m_met_phi = m_met_vec.Phi();
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::constructMetSig(
    const PennSusyFrame::EventLevelQuantities& event_quantities)
{
  m_met_sig_all = calculateMetSig( m_met_et
                                 , event_quantities.getHtAll()
                                 );
  m_met_sig_baseline = calculateMetSig( m_met_et
                                      , event_quantities.getHtBaseline()
                                      );
  m_met_sig_good = calculateMetSig( m_met_et
                                  , event_quantities.getHtGood()
                                  );
  m_met_sig_signal = calculateMetSig( m_met_et
                                    , event_quantities.getHtSignal()
                                    );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::constructMetRel( const std::vector<PennSusyFrame::Electron*>* el_list
                                        , const std::vector<PennSusyFrame::Muon*>* mu_list
                                        , const std::vector<PennSusyFrame::Jet*>* jet_list
                                        )
{
  double min_dphi = 999;

  min_dphi = std::min(min_dphi, findMinDphiInList(*el_list));
  min_dphi = std::min(min_dphi, findMinDphiInList(*mu_list));
  min_dphi = std::min(min_dphi, findMinDphiInList(*jet_list));

  m_dphi_met_nearest_obj = min_dphi;

  if (min_dphi < PI_OVER_2)
    m_met_rel_et = m_met_et * sin(min_dphi);
  else
    m_met_rel_et = m_met_et;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Met::getDPhi(PennSusyFrame::Particle* p) const
{
  double this_phi = m_met_vec.Phi();
  double particle_phi = p->getPhi();
  return fabs(TVector2::Phi_mpi_pi(this_phi - particle_phi));
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::clear()
{
  m_met_et           = 0;
  m_met_phi          = 0;
  m_met_rel_et       = 0;
  m_met_sig_all      = 0;
  m_met_sig_baseline = 0;
  m_met_sig_good     = 0;
  m_met_sig_signal   = 0;
  m_dphi_met_nearest_obj = 999;

  m_met_utility.reset();
  m_prepared = false;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::addMet(const PennSusyFrame::D3PDReader* reader)
{
  // std::cout << "\t\taddMet()\n";
  // std::cout << "\t\t\tSoftTerms:"
  //           << "\n\t\t\t\tCellOut_etx: "   << reader->MET_Egamma10NoTau_CellOut_etx
  //           << "\n\t\t\t\tCellOut_ety: "   << reader->MET_Egamma10NoTau_CellOut_ety
  //           << "\n\t\t\t\tCellOut_sumet: " << reader->MET_Egamma10NoTau_CellOut_sumet
  //           << "\n";
  // std::cout << "\t\t\tRefGamma:"
  //           << "\n\t\t\t\tMET_RefGamma_etx: "   << reader->MET_Egamma10NoTau_RefGamma_etx
  //           << "\n\t\t\t\tMET_RefGamma_ety: "   << reader->MET_Egamma10NoTau_RefGamma_ety
  //           << "\n\t\t\t\tMET_RefGamma_sumet: " << reader->MET_Egamma10NoTau_RefGamma_sumet
  //           << "\n";

  m_met_utility.setMETTerm( METUtil::SoftTerms
                          , reader->MET_Egamma10NoTau_CellOut_etx
                          , reader->MET_Egamma10NoTau_CellOut_ety
                          , reader->MET_Egamma10NoTau_CellOut_sumet
                          );


  m_met_utility.setMETTerm( METUtil::RefGamma
                          , reader->MET_Egamma10NoTau_RefGamma_etx
                          , reader->MET_Egamma10NoTau_RefGamma_ety
                          , reader->MET_Egamma10NoTau_RefGamma_sumet
                          );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::addElectrons(const std::vector<PennSusyFrame::Electron*>* el_list)
{
  // std::cout << "\t\taddElectons()\n";

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

  // std::cout << "\t\t\tadding each electron\n";
  // Loop over electrons and get each of their parameters and weights
  std::vector<PennSusyFrame::Electron*>::const_iterator el_it = el_list->begin();
  std::vector<PennSusyFrame::Electron*>::const_iterator el_term = el_list->end();
  for (; el_it != el_term; ++el_it) {
    // skip electrons with wet == 0
    if ((*el_it)->getMetWet().at(0) == 0) continue;
    // std::cout << "\t\t\t\tadding electron\n";

    // fill electron kinematic vectors
    // std::cout << "\t\t\t"
    //           << "\t\tel pt: "  << (*el_it)->getPt()
    //           << "\t\tel eta: " << (*el_it)->getEta()
    //           << "\t\tel phi: " << (*el_it)->getPhi()
    //           << "\n";
    el_pt.push_back( (*el_it)->getPt() );
    el_eta.push_back((*el_it)->getD3PDEta());
    el_phi.push_back((*el_it)->getD3PDPhi());

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

    // std::cout << "\t\t\t\t\telectron status word:\n";
    // for (size_t sw_it = 0; sw_it != el_status_word.size(); ++sw_it) {
    //   std::cout << "\t\t\t\t\t\t= " << el_status_word.at(sw_it) << "\n";
    // }
    // std::cout << "\t\t\t\t\telectron wet:\n";
    // for (size_t wet_it = 0; wet_it != el_tmp_wet.size(); ++wet_it) {
    //   std::cout << "\t\t\t\t\t\t= " << el_tmp_wet.at(wet_it) << "\n";
    // }
    // std::cout << "\t\t\t\t\telectron wpx:\n";
    // for (size_t wpx_it = 0; wpx_it != el_tmp_wpx.size(); ++wpx_it) {
    //   std::cout << "\t\t\t\t\t\t= " << el_tmp_wpx.at(wpx_it) << "\n";
    // }
    // std::cout << "\t\t\t\t\telectron wpy:\n";
    // for (size_t wpy_it = 0; wpy_it != el_tmp_wpy.size(); ++wpy_it) {
    //   std::cout << "\t\t\t\t\t\t= " << el_tmp_wpy.at(wpy_it) << "\n";
    // }
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
  // std::cout << "\t\taddMuons()\n";

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

  // std::cout << "\t\t\tadding each muon\n";
  std::vector<Muon*>::const_iterator mu_it = mu_list->begin();
  std::vector<Muon*>::const_iterator mu_term = mu_list->end();
  for (; mu_it != mu_term; ++mu_it) {
    // std::cout << "\t\t\t\tadding muon\n";

    mu_pt.push_back( (*mu_it)->getPt());
    mu_eta.push_back((*mu_it)->getEta());
    mu_phi.push_back((*mu_it)->getPhi());
    mu_wet.push_back(unit_vec);
    mu_wpx.push_back(unit_vec);
    mu_wpy.push_back(unit_vec);
    mu_status_word.push_back(default_vec);

    // std::cout << "\t\t\t"
    //           << "\t\tmu pt: "        << (*mu_it)->getPt()
    //           << "\t\tmu eta: "       << (*mu_it)->getEta()
    //           << "\t\tmu phi: "       << (*mu_it)->getPhi()
    //           << "\t\tmu ms qoverp: " << (*mu_it)->getMsQOverP()
    //           << "\t\tmu ms theta: "  << (*mu_it)->getMsTheta()
    //           << "\t\tmu ms phi: "    << (*mu_it)->getMsPhi()
    //           << "\t\tmu charge: "    << (*mu_it)->getCharge()
    //           << "\n";

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
	std::cout<<"In weight fix"<<std::endl;
        wpx[cl] = wet[cl];
      }
      if (  wpy[cl] < 0.5 * wet[cl]
         || wpy[cl] > 2   * wet[cl]
         ) {
	std::cout<<"In weight fix"<<std::endl;
        wpy[cl] = wet[cl];
      }
    }
}

// -----------------------------------------------------------------------------
double PennSusyFrame::Met::calculateMetSig( double met, double ht)
{
  if (ht == 0.) return (met == 0.) ? 0. : 999999.;
  return met/sqrt(ht);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::Met::print() const
{
  std::cout << "================= Printing MET: =================\n";
  std::cout <<std::setw(17)<<left<< "MET et: "  <<setw(20)<<left<< m_met_vec.Mod()
            <<std::setw(17)<<left<< "MET phi: " <<setw(20)<<left<< m_met_vec.Phi()
            <<std::setw(17)<<left<< "MET ex: "  <<setw(20)<<left<< m_met_vec.X()
            <<std::setw(17)<<left<< "MET ey: "  <<setw(20)<<left<< m_met_vec.Y()
            <<"\n"
            <<std::setw(17)<<left<< "MET rel: " <<setw(20)<<left<< m_met_rel_et
            <<std::setw(17)<<left<< "MET sig (all): "      <<setw(20)<<left<< m_met_sig_all
            <<std::setw(20)<<left<< "MET sig (baseline): " <<setw(17)<<left<< m_met_sig_baseline
            <<std::setw(17)<<left<< "MET sig (good): "     <<setw(20)<<left<< m_met_sig_good
            <<"\n"
            <<std::setw(17)<<left<< "MET sig (signal): "   <<setw(20)<<left<< m_met_sig_signal
            <<"\n\n";
}

// =============================================================================
PennSusyFrame::MCTruth::MCTruth() : m_mc_pt(0)
                                  , m_mc_eta(0)
                                  , m_mc_phi(0)
                                  , m_mc_m(0)
                                  , m_mc_pdg_id(0)
                                  , m_mc_status(0)
                                  , m_mc_barcode(0)
                                  , m_mc_vx_barcode(0)
                                  , m_mc_parent_index(0)
                                  , m_mc_child_index(0)
                                  , m_mc_mu_origin(0)
                                  , m_mc_mu_type(0)
                                  , m_mc_charge(0)
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::MCTruth::clear()
{
  m_mc_channel_number = 0;
  m_mc_n = 0;
  m_mc_pt = 0;
  m_mc_eta = 0;
  m_mc_phi = 0;
  m_mc_m = 0;
  m_mc_pdg_id = 0;
  m_mc_status = 0;
  m_mc_barcode = 0;
  m_mc_vx_barcode = 0;
  m_mc_parent_index = 0;
  m_mc_child_index = 0;
  m_mc_parents = 0;
  m_mc_children = 0;
  m_mc_mu_origin = 0;
  m_mc_mu_type = 0;
  m_mc_charge = 0;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::MCTruth::getEvent(const PennSusyFrame::D3PDReader* reader)
{
  setChannelNumber(reader->mc_channel_number);
  setN(            reader->mc_n);
  setPt(           reader->mc_pt);
  setEta(          reader->mc_eta);
  setPhi(          reader->mc_phi);
  setM(            reader->mc_m);
  setPdgId(        reader->mc_pdgId);
  setStatus(       reader->mc_status);
  setBarcode(      reader->mc_barcode);
  setVxBarcode(    reader->mc_vx_barcode);
  setParentIndex(  reader->mc_parent_index);
  setChildIndex(   reader->mc_child_index );
  setParents(      reader->mc_parents);
  setChildren(     reader->mc_children);
  setMuOrigin(     reader->muonTruth_origin);
  setMuType(       reader->muonTruth_type);
  setCharge(       reader->mc_charge);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::MCTruth::writeFullTruthRecord(std::string out_file_name)
{
  std::ofstream fout;
  fout.open(out_file_name.c_str());

  fout << "index\tbarcode\tpdgid\tstatus\tnum_parents\tparent_index\n";
  int mc_n = getN();
  for (int mc_it = 0; mc_it != mc_n; ++mc_it) {
    fout << mc_it << "\t"
         << m_mc_barcode->at(mc_it) << "\t"
         << m_mc_pdg_id->at(mc_it) << "\t"
         << m_mc_status->at(mc_it) << "\t"
         << m_mc_parent_index->at(mc_it).size() << "\t";
    size_t num_parents = m_mc_parent_index->at(mc_it).size();
    if (num_parents > 0) {
      fout << m_mc_parent_index->at(mc_it).at(0);
      for (size_t parent_it = 1; parent_it != num_parents; ++parent_it) {
        fout << "\n\t\t\t\t\t" << m_mc_parent_index->at(mc_it).at(parent_it);
      }
    }
    fout << "\n";
  }

  fout.close();
}
