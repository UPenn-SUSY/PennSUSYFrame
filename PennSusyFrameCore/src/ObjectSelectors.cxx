#include "PennSusyFrameCore/include/ObjectSelectors.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/ObjectContainers.h"

#include <iostream>

// =============================================================================
// = SelectorBase
// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::SelectorBase::SelectorBase() : m_reversed(false)
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::SelectorBase::setReversedSelector(bool val)
{
  m_reversed = val;
}

bool PennSusyFrame::SelectorBase::passSelection(const PennSusyFrame::PhysicsObject* p)
{
  bool pass_all_cuts = passAllCuts(p);

  if (m_reversed) return !pass_all_cuts;
  return pass_all_cuts;
}

bool PennSusyFrame::SelectorBase::passAllCuts(const PennSusyFrame::PhysicsObject*)
{
  std::cout << "calling default selector :-(\n";
  return false;
}

// =============================================================================
// = ElectronSelector
// =============================================================================
// ----------------------------------------------------------------------------
PennSusyFrame::ElectronSelector::ElectronSelector() : m_electron_quality(EL_QUALITY_NONE)
                                                    , m_min_pt(-1)
                                                    , m_max_pt(-1)
                                                    , m_min_eta(-1)
                                                    , m_max_eta(-1)
                                                    , m_min_d0_significance(-1)
                                                    , m_max_d0_significance(-1)
                                                    , m_min_z0_sin_theta(-1)
                                                    , m_max_z0_sin_theta(-1)
                                                    , m_min_ptcone(-1)
                                                    , m_max_ptcone(-1)
                                                    , m_min_etcone(-1)
                                                    , m_max_etcone(-1)
{
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::ElectronSelector::passAllCuts(const PennSusyFrame::Electron* p)
{
  // check electron author
  // TODO do we want this hard coded? do we ever want electrons with author != 1 || 3?
  if (p->getAuthor() != 1 && p->getAuthor() != 3) return false;

  // check electron OTX cut
  // TODO do we want this hard coded? do we ever want electrons that fail the OTX cut?
  if (!p->getPassOTX()) return false;

  // check electron quality
  if (m_electron_quality == EL_QUALITY_MEDPP   && !p->getMediumPP()) return false;
  if (m_electron_quality == EL_QUALITY_TIGHTPP && !p->getTightPP() ) return false;

  // check electron pt
  if (!passCut(p->getPt(), m_min_pt, m_max_pt)) return false;

  // check electron eta
  if (!passCut(p->getEta(), m_min_eta, m_max_eta)) return false;

  // check electron d0 significance
  if (!passCut(p->getD0Significance(), m_min_d0_significance, m_max_d0_significance)) return false;

  // check electron z0*sin(theta)
  if (!passCut(p->getZ0SinTheta(), m_min_z0_sin_theta, m_max_z0_sin_theta)) return false;

  // check electron pt isolation
  if (!passCut(p->getPtIsoRatio(), m_min_ptcone, m_max_ptcone)) return false;

  // check electron et isolation
  if (!passCut(p->getEtIsoRatio(), m_min_etcone, m_max_etcone)) return false;

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
                                            , m_min_b_layer_hits(-1)
                                            , m_max_b_layer_hits(-1)
                                            , m_min_pixel_hits(-1)
                                            , m_max_pixel_hits(-1)
                                            , m_min_sct_hits(-1)
                                            , m_max_sct_hits(-1)
                                            , m_min_si_holes(-1)
                                            , m_max_si_holes(-1)
                                            , m_min_trt_eta(-1)
                                            , m_max_trt_eta(-1)
                                            , m_min_trt_hits(-1)
                                            , m_max_trt_hits(-1)
                                            , m_min_trt_ol_fraction(-1)
                                            , m_max_trt_ol_fraction(-1)
                                            , m_min_d0_significance(-1)
                                            , m_max_d0_significance(-1)
                                            , m_min_z0_sin_theta(-1)
                                            , m_max_z0_sin_theta(-1)
                                            , m_min_d0(-1)
                                            , m_max_d0(-1)
                                            , m_min_z0(-1)
                                            , m_max_z0(-1)
                                            , m_min_q_over_p_ratio(-1)
                                            , m_max_q_over_p_ratio(-1)
                                            , m_min_ptcone(-1)
                                            , m_max_ptcone(-1)
                                            , m_min_etcone(-1)
                                            , m_max_etcone(-1)
{
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::MuonSelector::passAllCuts(const PennSusyFrame::Muon* p)
{
  // check muon pt
  if (!passCut(p->getPt(), m_min_pt, m_max_pt)) return false;

  // check muon eta
  if (!passCut(p->getEta(), m_min_eta, m_max_eta)) return false;

  // check muon num b layer hits
  if (!passCut(p->getNumBLayerHits(), m_min_b_layer_hits, m_max_b_layer_hits)) return false;

  // check muon num pixel hits
  if (!passCut(p->getNumPixelHits(), m_min_pixel_hits, m_max_pixel_hits)) return false;

  // check muon num sct hits
  if (!passCut(p->getNumSctHits(), m_min_sct_hits, m_max_sct_hits)) return false;

  // check muon si holes
  if (!passCut(p->getNumSiHoles(), m_min_si_holes, m_max_si_holes)) return false;

  // check muon track eta
  if (  passCut(p->getTrackEta(), m_min_trt_eta, m_max_trt_eta)
     && (  !passCut(p->getNumTrtHits(), m_min_trt_hits, m_max_trt_hits)
        || !passCut(p->getTrtOlFraction(), m_min_trt_ol_fraction, m_max_trt_ol_fraction)
       )
     )
    return false;

  // check muon d0 significance
  if (!passCut(p->getD0Significance(), m_min_d0_significance, m_max_d0_significance)) return false;

  // check muon z0*sin(theta)
  if (!passCut(p->getZ0SinTheta(), m_min_z0_sin_theta, m_max_z0_sin_theta)) return false;

  // check muon d0
  if (!passCut(p->getD0(), m_min_d0, m_max_d0)) return false;

  // check muon z0
  if (!passCut(p->getZ0(), m_min_z0, m_max_z0)) return false;

  // check muon q/p ratio
  if (!passCut(p->getQOverPRatio(), m_min_q_over_p_ratio, m_max_q_over_p_ratio)) return false;

  // check muon pt isolation
  if (!passCut(p->getPtIsoRatio(), m_min_ptcone, m_max_ptcone)) return false;

  // check muon et isolation
  if (!passCut(p->getEtIsoRatio(), m_min_etcone, m_max_etcone)) return false;

  // this muon passes all cuts
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
                                          , m_jet_bdt_level(TAU_JET_BDT_NONE)
                                          , m_ele_bdt_level(TAU_ELE_BDT_NONE)
                                          , m_mu_level(TAU_MU_NONE)
{
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TauSelector::passAllCuts(const PennSusyFrame::Tau* p)
{
  // check num tacks
  if (p->getNumTracks() != 1 && p->getNumTracks() != 3) return false;

  // check tau charge
  if (fabs(p->getCharge())) return false;

  // check tau pt
  if (!passCut(p->getPt(), m_min_pt, m_max_pt)) return false;

  // check tau eta
  if (!passCut(p->getEta(), m_min_eta, m_max_eta)) return false;

  // check jet BDT level
  if (m_jet_bdt_level == TAU_JET_BDT_LOOSE  && p->getJetBdtLoose()  == false)  return false;
  if (m_jet_bdt_level == TAU_JET_BDT_MEDIUM && p->getJetBdtMedium() == false)  return false;
  if (m_jet_bdt_level == TAU_JET_BDT_TIGHT  && p->getJetBdtTight()  == false)  return false;

  // check ele BDT level
  if (p->getNumTracks() == 1) {
    if (  m_ele_bdt_level == TAU_ELE_BDT_LOOSE  && p->getEleBdtLoose()  == true) return false;
    if (  m_ele_bdt_level == TAU_ELE_BDT_MEDIUM && p->getEleBdtMedium() == true) return false;
    if (  m_ele_bdt_level == TAU_ELE_BDT_TIGHT  && p->getEleBdtTight()  == true) return false;
  }

  // check jet BDT level
  if (m_mu_level == TAU_MU_TIGHT && p->getMuVeto() == true) return false;

  // this tau passes all cuts
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
                                          , m_min_jvf(-1)
                                          , m_max_jvf(-1)
                                          , m_min_jvf_pt_thresh(-1)
                                          , m_max_jvf_pt_thresh(-1)
                                          , m_min_mv1(-1)
                                          , m_max_mv1(-1)
                                          , m_min_bch_corr(-1)
                                          , m_max_bch_corr(-1)
                                          , m_min_dphi_met(-1)
                                          , m_max_dphi_met(-1)
                                          , m_is_bad_jet(-1)
{
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::JetSelector::passAllCuts(const PennSusyFrame::Jet* p)
{
  // check jet pt
  if (!passCut(p->getPt(), m_min_pt, m_max_pt)) return false;

  // check jet eta
  if (!passCut(fabs(p->getEta()), m_min_eta, m_max_eta)) return false;

  // check jet jvf - only make jvf cut if the jet fails the jvf pt threshold
  // jet jvf is NOT an incsive cut
  if (  !passCut(fabs(p->getJvf()), m_min_jvf, m_max_jvf, false)
     && !passCut(p->getPt(), m_min_jvf_pt_thresh, m_max_jvf_pt_thresh)
     ) return false;

  // check jet mv1 flavor weight
  if (!passCut(p->getMv1(), m_min_mv1, m_max_mv1)) return false;
  if (m_is_bad_jet == 0 || m_is_bad_jet == 1) {
    if (m_is_bad_jet == 0 && p->getIsBad() == true ) return false;
    if (m_is_bad_jet == 1 && p->getIsBad() == false) return false;
  }

  // check bch_corr
  if (!passCut(p->getBchCorr(), m_min_bch_corr, m_max_bch_corr)) return false;

  // check dphi(met,jet)
  if (!passCut(p->getDphiMet(), m_min_dphi_met, m_max_dphi_met)) return false;

  // this jet passes all cuts
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
bool PennSusyFrame::VertexSelector::passAllCuts(const PennSusyFrame::Vertex* p)
{
  // check number of tracks for this vertex
  if ( !passCut( p->getNumTracks()
               , m_min_num_tracks
               , m_max_num_tracks
               )
     ) return false;

  return true;
}

// =============================================================================
// = Object cleaning
// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::ObjectCleaning::ObjectCleaning()
{
  // TODO properly set cone sizes and mll threshold
  m_ee_cone_size = 0.05;
  m_ej_cone_size = 0.20;
  m_et_cone_size = 0.20;
  m_mt_cone_size = 0.20;
  m_je_cone_size = 0.40;
  m_jm_cone_size = 0.40;
  m_em_cone_size = 0.01;
  m_mm_cone_size = 0.05;
  m_tj_cone_size = 0.20;
  m_sfos_mll_min = 12.e3;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::fullObjectCleaning( PennSusyFrame::ElectronContainer& electrons
                                                      , PennSusyFrame::MuonContainer& muons
                                                      , PennSusyFrame::TauContainer& taus
                                                      , PennSusyFrame::JetContainer& jets
                                                      )
{
  // placeholders for objects passing object cleaning
  std::vector<PennSusyFrame::Electron*> good_electrons;
  std::vector<PennSusyFrame::Muon*>     good_muons;
  std::vector<PennSusyFrame::Tau*>      good_taus;
  std::vector<PennSusyFrame::Jet*>      good_jets;
  std::vector<PennSusyFrame::Jet*>      bad_jets;

  // do object cleaning
  fullObjectCleaning( electrons.getCollection(EL_BASELINE)
                    , muons.getCollection(MU_BASELINE)
                    , taus.getCollection(TAU_BASELINE)
                    , jets.getCollection(JET_BASELINE_GOOD)
                    , jets.getCollection(JET_BASELINE_BAD)
                    , good_electrons
                    , good_muons
                    , good_taus
                    , good_jets
                    , bad_jets
                    );

  // TODO update object desc for objects passing object cleaning

  // set collection lists
  electrons.setCollection(EL_GOOD , good_electrons);
  muons.setCollection(    MU_GOOD , good_muons    );
  taus.setCollection(     TAU_GOOD, good_taus     );
  jets.setCollection(     JET_GOOD, good_jets     );
  jets.setCollection(     JET_BAD , bad_jets      );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::fullObjectCleaning( const std::vector<PennSusyFrame::Electron*>* input_electrons
                                                      , const std::vector<PennSusyFrame::Muon*>* input_muons
                                                      , const std::vector<PennSusyFrame::Tau*>* input_taus
                                                      , const std::vector<PennSusyFrame::Jet*>* input_jets_good
                                                      , const std::vector<PennSusyFrame::Jet*>* input_jets_bad
                                                      , std::vector<PennSusyFrame::Electron*>& output_electrons
                                                      , std::vector<PennSusyFrame::Muon*>& output_muons
                                                      , std::vector<PennSusyFrame::Tau*>& output_taus
                                                      , std::vector<PennSusyFrame::Jet*>& output_jets_good
                                                      , std::vector<PennSusyFrame::Jet*>& output_jets_bad
                                                      )
{
  // do ee overlap removal
  std::vector<PennSusyFrame::Electron*> el_temp_1;
  eeOverlapRemoval(*input_electrons, el_temp_1);

  // do ej overlap removal
  std::vector<PennSusyFrame::Jet*> jet_good_temp_1;
  std::vector<PennSusyFrame::Jet*> jet_bad_temp_1;
  ejOverlapRemoval(el_temp_1, *input_jets_good, jet_good_temp_1);
  ejOverlapRemoval(el_temp_1, *input_jets_bad , jet_bad_temp_1 );

  // do et overlap removal
  std::vector<PennSusyFrame::Tau*> tau_temp_1;
  etOverlapRemoval(el_temp_1, *input_taus, tau_temp_1);

  // do mt overlap removal
  std::vector<PennSusyFrame::Tau*> tau_temp_2;
  mtOverlapRemoval(*input_muons, tau_temp_1, tau_temp_2);

  // do je overlap removal
  std::vector<PennSusyFrame::Electron*> el_temp_2;
  std::vector<PennSusyFrame::Electron*> el_temp_3;
  jeOverlapRemoval(jet_good_temp_1, el_temp_1, el_temp_2);
  jeOverlapRemoval(jet_bad_temp_1 , el_temp_2, el_temp_3);

  // do jm overlap removal
  std::vector<PennSusyFrame::Muon*> mu_temp_1;
  std::vector<PennSusyFrame::Muon*> mu_temp_2;
  jmOverlapRemoval(jet_good_temp_1, *input_muons, mu_temp_1);
  jmOverlapRemoval(jet_bad_temp_1 , mu_temp_1   , mu_temp_2);

  // do em overlap removal
  std::vector<PennSusyFrame::Electron*> el_temp_4;
  std::vector<PennSusyFrame::Muon*> mu_temp_3;
  emOverlapRemoval(el_temp_3, mu_temp_2, el_temp_4, mu_temp_3);

  // do mm overlap removal
  std::vector<PennSusyFrame::Muon*> mu_temp_4;
  mmOverlapRemoval(mu_temp_3, mu_temp_4);

  // do SFOS mll cut
  std::vector<PennSusyFrame::Electron*> el_temp_5;
  std::vector<PennSusyFrame::Muon*> mu_temp_5;
  sfosMllOverlapRemoval(el_temp_4, mu_temp_4, el_temp_5, mu_temp_5);

  // do tj overlap removal
  std::vector<PennSusyFrame::Jet*> jet_good_temp_2;
  std::vector<PennSusyFrame::Jet*> jet_bad_temp_2;
  tjOverlapRemoval(tau_temp_2, jet_good_temp_1, jet_good_temp_2);
  tjOverlapRemoval(tau_temp_2, jet_bad_temp_1 , jet_bad_temp_2 );

  // set output vectors to the final temp objects
  output_electrons = el_temp_5;
  output_jets_good = jet_good_temp_2;
  output_jets_bad  = jet_bad_temp_2;
  output_muons     = mu_temp_5;
  output_taus      = tau_temp_2;

  // std::cout << "-----------------------------\n"
  //           << "taus before OLR: " << input_taus.size() << "\n"
  //           << "taus after el OLR: " << tau_temp_1.size() << "\n"
  //           << "taus after mu OLR: " << tau_temp_2.size() << "\n"
  //           << "taus after all OLR: " << output_taus.size() << "\n"
  //           << "\n";

}


// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::eeOverlapRemoval( const std::vector<PennSusyFrame::Electron*>& input_electrons
                                                    , std::vector<PennSusyFrame::Electron*>&       output_electrons
                                                    )
{
  overlapRemoveLowPt( input_electrons
                    , output_electrons
                    , m_ee_cone_size
                    );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::ejOverlapRemoval( const std::vector<PennSusyFrame::Electron*>& electrons
                                                    , const std::vector<PennSusyFrame::Jet*>&      input_jets
                                                    , std::vector<PennSusyFrame::Jet*>&            output_jets
                                                    )
{
  overlapRemoveSecondList( electrons
                         , input_jets
                         , output_jets
                         , m_ej_cone_size
                         );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::etOverlapRemoval( const std::vector<PennSusyFrame::Electron*>& electrons
                                                    , const std::vector<PennSusyFrame::Tau*>&      input_taus
                                                    , std::vector<PennSusyFrame::Tau*>&            output_taus
                                                    )
{
  overlapRemoveSecondList( electrons
                         , input_taus
                         , output_taus
                         , m_et_cone_size
                         );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::mtOverlapRemoval( const std::vector<PennSusyFrame::Muon*>& muons
                                                    , const std::vector<PennSusyFrame::Tau*>&  input_taus
                                                    , std::vector<PennSusyFrame::Tau*>&        output_taus
                                                    )
{
  overlapRemoveSecondList( muons
                         , input_taus
                         , output_taus
                         , m_mt_cone_size
                         );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::tjOverlapRemoval( const std::vector<PennSusyFrame::Tau*>& taus
                                                    , const std::vector<PennSusyFrame::Jet*>& input_jets
                                                    , std::vector<PennSusyFrame::Jet*>&       output_jets
                                                    )
{
  overlapRemoveSecondList( taus
                         , input_jets
                         , output_jets
                         , m_tj_cone_size
                         );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::jeOverlapRemoval( const std::vector<PennSusyFrame::Jet*>&      jets
                                                    , const std::vector<PennSusyFrame::Electron*>& inputs_electrons
                                                    , std::vector<PennSusyFrame::Electron*>&       output_electrons
                                                    )
{
  overlapRemoveSecondList( jets
                         , inputs_electrons
                         , output_electrons
                         , m_je_cone_size
                         );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::jmOverlapRemoval( const std::vector<PennSusyFrame::Jet*>&  jets
                                                    , const std::vector<PennSusyFrame::Muon*>& input_muons
                                                    , std::vector<PennSusyFrame::Muon*>&       output_muon
                                                    )
{
  overlapRemoveSecondList( jets
                         , input_muons
                         , output_muon
                         , m_jm_cone_size
                         );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::emOverlapRemoval( const std::vector<PennSusyFrame::Electron*>& input_electrons
                                                    , const std::vector<PennSusyFrame::Muon*>&     input_muons
                                                    , std::vector<PennSusyFrame::Electron*>&       output_electrons
                                                    , std::vector<PennSusyFrame::Muon*>&           output_muons
                                                    )
{
  overlapRemoveBoth( input_electrons
                   , input_muons
                   , output_electrons
                   , output_muons
                   , m_em_cone_size
                   );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::mmOverlapRemoval( const std::vector<PennSusyFrame::Muon*>& input_muons
                                                    , std::vector<PennSusyFrame::Muon*>&       output_muons
                                                    )
{
  overlapRemoveBoth( input_muons
                   , output_muons
                   , m_mm_cone_size
                   );
}


// -----------------------------------------------------------------------------
void PennSusyFrame::ObjectCleaning::sfosMllOverlapRemoval( const std::vector<PennSusyFrame::Electron*>& input_electrons
                                                         , const std::vector<PennSusyFrame::Muon*>&     input_muons
                                                         , std::vector<PennSusyFrame::Electron*>&       output_electrons
                                                         , std::vector<PennSusyFrame::Muon*>&           output_muons
                                                         )
{
  // prep output vectors
  output_electrons.clear();
  output_muons.clear();

  output_electrons.reserve(input_electrons.size());
  output_muons.reserve(input_electrons.size());

  std::vector<bool> keep_el(input_electrons.size(), true);
  std::vector<bool> keep_mu(input_muons.size(), true);

  // Loop over electron combinations, checking for SFOS pairs
  size_t el_term = input_electrons.size();
  for (size_t el_it_1 = 0; el_it_1 != el_term; ++el_it_1) {
    float charge_1 = input_electrons.at(el_it_1)->getCharge();
    const TLorentzVector* tlv1 = input_electrons.at(el_it_1)->getTlv();
    for (size_t el_it_2 = 0; el_it_2 != el_it_1; ++el_it_2) {
      float charge_2 = input_electrons.at(el_it_2)->getCharge();
      if (charge_1 * charge_2 < 0) {
        const TLorentzVector* tlv2 = input_electrons.at(el_it_2)->getTlv();
        if (((*tlv1)+(*tlv2)).Mag() < m_sfos_mll_min) {
          keep_el.at(el_it_1) = false;
          keep_el.at(el_it_2) = false;
        }
      }
    }
  }

  // Loop over muon combinations, checking for SFOS pairs
  size_t mu_term = input_muons.size();
  for (size_t mu_it_1 = 0; mu_it_1 != mu_term; ++mu_it_1) {
    float charge_1 = input_muons.at(mu_it_1)->getCharge();
    const TLorentzVector* tlv1 = input_muons.at(mu_it_1)->getTlv();
    for (size_t mu_it_2 = 0; mu_it_2 != mu_it_1; ++mu_it_2) {
      float charge_2 = input_muons.at(mu_it_2)->getCharge();
      if (charge_1 * charge_2 < 0) {
        const TLorentzVector* tlv2 = input_muons.at(mu_it_2)->getTlv();
        if (((*tlv1)+(*tlv2)).Mag() < m_sfos_mll_min) {
          keep_mu.at(mu_it_1) = false;
          keep_mu.at(mu_it_2) = false;
        }
      }
    }
  }

  // add to output electrons flagged as "to keep"
  for (size_t el_it = 0; el_it != el_term; ++el_it) {
    if (keep_el.at(el_it)) {
      output_electrons.push_back(input_electrons.at(el_it));
    }
  }
  // add to output muons flagged as "to keep"
  for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
    if (keep_mu.at(mu_it)) {
      output_muons.push_back(input_muons.at(mu_it));
    }
  }
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::ObjectCleaning::overlap( const TLorentzVector* tlv1
                                           , const TLorentzVector* tlv2
                                           , double thresh
                                           )
{
  double dr = tlv1->DeltaR(*tlv2);
  return (dr < thresh);
}
