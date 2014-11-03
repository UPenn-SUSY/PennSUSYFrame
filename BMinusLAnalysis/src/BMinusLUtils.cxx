#include "BMinusLAnalysis/include/BMinusLUtils.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/Calculators.h"

#include <iostream>

// -----------------------------------------------------------------------------
PennSusyFrame::blPair::blPair() : m_jet(0)
                                , m_lep(0)
                                , m_mbl(0)
                                , m_ptbl(0)
                                , m_same_parent(false)
{ }

// -----------------------------------------------------------------------------
PennSusyFrame::blPair::blPair( PennSusyFrame::Jet* jet, PennSusyFrame::Lepton* lep) : m_mbl(0)
                                                                                    , m_ptbl(0)
                                                                                    , m_same_parent(false) // default value
{
  m_jet = jet;
  m_lep = lep;

  calculate();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::blPair::calculate()
{
  m_mbl  = calcMll(m_lep, m_jet);
  m_ptbl = calcPtll(m_lep, m_jet);
}

// -----------------------------------------------------------------------------
float PennSusyFrame::blPair::getDphi() const
{
  return PennSusyFrame::calcDphi(m_jet->getPhi(), m_lep->getPhi());
}

// -----------------------------------------------------------------------------
float PennSusyFrame::blPair::getDeta() const
{
  return fabs( m_jet->getEta() - m_lep->getEta() );
}

// -----------------------------------------------------------------------------
float PennSusyFrame::blPair::getDr() const
{
  return sqrt( pow(getDphi(), 2) + pow(getDeta(), 2) );
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::doBLPairing( const PennSusyFrame::Event& event
                               , const std::vector<PennSusyFrame::Electron*>* el_list
                               , const std::vector<PennSusyFrame::Muon*>*     mu_list
                               , const std::vector<PennSusyFrame::Jet*>*      b_jet_list
                               , PennSusyFrame::blPair& pair_0
                               , PennSusyFrame::blPair& pair_1
                               )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();
  // if (fc == FLAVOR_NONE) return false;

  std::vector<PennSusyFrame::Lepton*> lep_list;
  lep_list.reserve(2);
  if (fc == FLAVOR_EE) {
    lep_list.push_back(el_list->at(0));
    lep_list.push_back(el_list->at(1));
  }
  else if (fc == FLAVOR_MM) {
    lep_list.push_back(mu_list->at(0));
    lep_list.push_back(mu_list->at(1));
  }
  else if (fc == FLAVOR_EM) {
    lep_list.push_back(el_list->at(0));
    lep_list.push_back(mu_list->at(0));
  }
  else if (fc == FLAVOR_NONE) {
    size_t num_el = el_list->size();
    size_t num_mu = mu_list->size();

    if ((num_el + num_mu) < 2) return false;

    size_t next_el = 0;
    size_t next_mu = 0;
    size_t num_leps_stored = 0;

    float el_pt = -1;
    float mu_pt = -1;
    size_t num_it = 0;
    while (  num_leps_stored < 2
          && next_el < num_el
          && next_mu < num_mu
          && num_it < 10
          ) {
      // get the next electron and muon pt values
      el_pt = ((next_el < num_el) ? el_list->at(next_el)->getPt() : -1);
      mu_pt = ((next_mu < num_mu) ? mu_list->at(next_mu)->getPt() : -1);

      if (el_pt >= mu_pt) {
        // if next electron is harder than next muon, add that to lepton list
        lep_list.push_back(el_list->at(next_el));
        ++next_el;
      }
      else {
        // if muon is harder than electron, add that to lepton list
        lep_list.push_back(mu_list->at(next_mu));
        ++next_mu;
      }
      ++num_leps_stored;
    }
    if (num_leps_stored < 2) return false;
  }

  return doBLPairing(&lep_list, b_jet_list, pair_0, pair_1);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::doBLPairing( const std::vector<PennSusyFrame::Lepton*>* lep_list
                               , const std::vector<PennSusyFrame::Jet*>*    jet_list
                               , PennSusyFrame::blPair& pair_0
                               , PennSusyFrame::blPair& pair_1
                               )
{
  if (lep_list->size() < 2 || jet_list->size() < 2) return false;

  // first calculate the mbl values for the 00 11 pairings
  float mbl_00 = calcMll(lep_list->at(0), jet_list->at(0));
  float mbl_11 = calcMll(lep_list->at(1), jet_list->at(1));
  float mbl_ratio_00_11 = ( (mbl_00 > mbl_11) ? (mbl_00/mbl_11)
                                              : (mbl_11/mbl_00)
                          );

  // first calculate the mbl values for the 01 01 pairings
  float mbl_01 = calcMll(lep_list->at(0), jet_list->at(1));
  float mbl_10 = calcMll(lep_list->at(1), jet_list->at(0));
  float mbl_ratio_01_01 = ( (mbl_01 > mbl_10) ? (mbl_01/mbl_10)
                                              : (mbl_10/mbl_01)
                          );

  if (mbl_ratio_00_11 <= mbl_ratio_01_01) {
    if (mbl_00 >= mbl_11) {
      pair_0.setLep(lep_list->at(0));
      pair_0.setJet(jet_list->at(0));

      pair_1.setLep(lep_list->at(1));
      pair_1.setJet(jet_list->at(1));
    }
    else {
      pair_0.setLep(lep_list->at(1));
      pair_0.setJet(jet_list->at(1));

      pair_1.setLep(lep_list->at(0));
      pair_1.setJet(jet_list->at(0));
    }
  }
  else {
    if (mbl_01 >= mbl_10) {
      pair_0.setLep(lep_list->at(0));
      pair_0.setJet(jet_list->at(1));

      pair_1.setLep(lep_list->at(1));
      pair_1.setJet(jet_list->at(0));
    }
    else {
      pair_0.setLep(lep_list->at(1));
      pair_0.setJet(jet_list->at(0));

      pair_1.setLep(lep_list->at(0));
      pair_1.setJet(jet_list->at(1));
    }
  }

  pair_0.calculate();
  pair_1.calculate();

  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::sameParent( const PennSusyFrame::Event& event
                              , const PennSusyFrame::Lepton* lep
                              , const PennSusyFrame::Jet* jet
                              , const PennSusyFrame::MCTruth& mc_truth
                              , bool verbose
                              )
{
  if (event.getIsData()) return false;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  int lep_parent_index = getLeptonParentIndex(lep, mc_truth);
  if (lep_parent_index < 0) return false;
  int lep_parent_barcode = PennSusyFrame::getBarcodeFromIndex(lep_parent_index, mc_truth);
  int lep_parent_pdgid = mc_truth.getPdgId()->at(lep_parent_index);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  int jet_parent_index = getJetParentIndex( jet, mc_truth);
  if (jet_parent_index < 0) return false;

  int jet_parent_barcode = PennSusyFrame::getBarcodeFromIndex(jet_parent_index, mc_truth);

  // // if the two parents have the same barcode, they are the same!
  if (lep_parent_barcode == jet_parent_barcode) return true;

  // Special case to handle top -- lepton is not directly from top. There is an
  // intermediate W boson
  if (verbose) {
    std::cout << "\tgetting b jet parent pdgid\n";
  }
  int jet_parent_pdgid = mc_truth.getPdgId()->at(jet_parent_index);

  if (verbose) {
    std::cout << "\tjet parent pdgid: "      << jet_parent_pdgid    << "\n";
    std::cout << "\n";
    // std::cout << "\tjet b quark index: "     << jet_b_quark_index   << "\n";
    // std::cout << "\tjet b quark barcode: "   << jet_b_quark_barcode << "\n";
    std::cout << "\n";
    std::cout << "\tjet parent index: "      << jet_parent_index    << "\n";
    std::cout << "\tjet parent barcode: "    << jet_parent_barcode  << "\n";
    std::cout << "\tjet parent pdgid: "      << jet_parent_pdgid    << "\n";
    std::cout << "\n";
    std::cout << "\tlepton parent index: "   << lep_parent_index    << "\n";
    std::cout << "\tlepton parent barcode: " << lep_parent_barcode  << "\n";
    std::cout << "\tlepton parent pdgid: "   << lep_parent_pdgid    << "\n";
    std::cout << "\n";
  }

  // if the parent of the lepton is a W, and the parent of the jet is a top,
  // there is still a chance these could be from the same parent (a top)
  if (fabs(lep_parent_pdgid) == 24 && fabs(jet_parent_pdgid) == 6) {
    if (verbose) {
      std::cout << "\t\tlepton parent == W && jet parent == top"
                << " -- checking one step back for lepton\n";
    }

    // find the parent of the W
    int w_parent_index   = PennSusyFrame::getParentIndex(lep_parent_barcode, mc_truth);
    int w_parent_barcode = PennSusyFrame::getBarcodeFromIndex(w_parent_index, mc_truth);

    if (verbose) {
      std::cout << "\t\tw parent index: " << w_parent_index << "\n";
      std::cout << "\t\tw parent barcode: " << w_parent_barcode << "\n";
    }
    if (w_parent_barcode == jet_parent_barcode) {
      if (verbose) {
        std::cout << "\tthese particles ARE from the same parent\n";
      }
      return true;
    }
  }

  if (verbose) {
    std::cout << "\tthese particles ARE NOT from the same parent\n";
  }

  return false;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::getLeptonParentIndex( const PennSusyFrame::Lepton* lep
                                       , const PennSusyFrame::MCTruth& mc_truth
                                       )
{
  // if (verbose) {
  // std::cout << "\tgetting lepton parent\n";
  // }
  int lep_barcode        = lep->getTruthBarcode();
  int lep_parent_index   = getParentIndex(lep_barcode, mc_truth);
  int lep_parent_barcode = PennSusyFrame::getBarcodeFromIndex(lep_parent_index, mc_truth);

  // if (verbose) {
  // std::cout << "\tlepton barcode: " << lep_barcode << "\n";
  // std::cout << "\tlepton parent index: " << lep_parent_index << "\n";
  // std::cout << "\tlepton parent barcode: " << lep_parent_barcode << "\n";
  // if (lep_parent_index >= 0)
  //   std::cout << "\tlepton parent pdgid: " << mc_truth.getPdgId()->at(lep_parent_index) << "\n";
  // std::cout << "\n";
  // }

  // protect from negative indices
  if (lep_parent_index < 0) return -1;

  // if the parent of the lepton is a tau, we should step back one level to see
  // the parent of the tau
  int lep_parent_pdgid = mc_truth.getPdgId()->at(lep_parent_index);
  if (fabs(lep_parent_pdgid) == 15) {
    // if (verbose) {
    // std::cout << "\t\tlepton parent == tau"
    //           << " -- checking one step back for lepton"
    //           << "\n";
    // }
    // find the parent of the tau
    int tau_parent_index   = PennSusyFrame::getParentIndex(lep_parent_barcode, mc_truth);
    int tau_parent_barcode = PennSusyFrame::getBarcodeFromIndex(tau_parent_index, mc_truth);

    lep_parent_index   = tau_parent_index;
    lep_parent_barcode = tau_parent_barcode;
  // protect from negative indices
  if (lep_parent_index < 0) return -1;
    lep_parent_pdgid   = mc_truth.getPdgId()->at(lep_parent_index);

    // if (verbose) {
    // std::cout << "\tlep parent pdgid: " << lep_parent_pdgid << "\n";
    // }

    // protect from negative indices
    // if (lep_parent_index < 0) return -1;
  }
  return lep_parent_index;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::getLeptonParentPdgId( const PennSusyFrame::Lepton* lep
                                       , const PennSusyFrame::MCTruth& mc_truth
                                       )
{
  int index = getLeptonParentIndex(lep, mc_truth);
  if (index < 0) return 0;
  return mc_truth.getPdgId()->at(index);
}

// -----------------------------------------------------------------------------
int PennSusyFrame::getJetParentIndex( const PennSusyFrame::Jet* jet
                                    , const PennSusyFrame::MCTruth& mc_truth
                                    )
{
  float dummy_dr_min = 0;
  return getJetParentIndex(jet, mc_truth, dummy_dr_min);
}

// -----------------------------------------------------------------------------
int PennSusyFrame::getJetParentIndex( const PennSusyFrame::Jet* jet
                                    , const PennSusyFrame::MCTruth& mc_truth
                                    , float& return_dr_min
                                    )
{
  // if (verbose) {
  // std::cout << "\tmatching b jet to b quark\n";
  // }
  int jet_b_quark_index = PennSusyFrame::matchJetToBQuark(jet, mc_truth, return_dr_min);

  // protect from negative indices
  if (jet_b_quark_index < 0) return -1;

  // if (verbose) {
  // std::cout << "\tgetting b jet parent\n";
  // std::cout << "\tgetting b jet parent - get jet barcode - b quark index: "
  //           << jet_b_quark_index
  //           << "\n";
  // }
  int jet_b_quark_barcode = mc_truth.getBarcode()->at(jet_b_quark_index);
  int jet_parent_index = PennSusyFrame::getParentIndex( jet_b_quark_barcode, mc_truth);
  // int jet_parent_barcode = PennSusyFrame::getBarcodeFromIndex(jet_parent_index, mc_truth);
  // if (verbose) {
  // std::cout << "\tgetting b jet parent - get parent index - barcode: " << jet_b_quark_barcode << "\n";
  // std::cout << "\tgetting b jet parent - get parent barcode - jet parent index: " << jet_parent_index << "\n";
  // std::cout << "\n";
  // std::cout << "\tjet parent barcode: " << jet_parent_barcode << "\n";
  // }

  // protect from negative indices
  if (jet_parent_index < 0) return -1;

  return jet_parent_index;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::getJetParentPdgId( const PennSusyFrame::Jet* jet
                                    , const PennSusyFrame::MCTruth& mc_truth
                                    )
{
  float dummy_dr_min = 0;
  return getJetParentPdgId(jet, mc_truth, dummy_dr_min);
}

// -----------------------------------------------------------------------------
int PennSusyFrame::getJetParentPdgId( const PennSusyFrame::Jet* jet
                                    , const PennSusyFrame::MCTruth& mc_truth
                                    , float& return_dr_min
                                    )
{
  int index = getJetParentIndex(jet, mc_truth, return_dr_min);
  if (index < 0) return -1;
  return mc_truth.getPdgId()->at(index);
}

// ---------------------------------------------------------------------------
int PennSusyFrame::connectTruthRecord( const PennSusyFrame::MCTruth& mc_truth
                                     , int broken_index
                                     )
{
  if (broken_index <= 0) return broken_index;

  int broken_pdgid = mc_truth.getPdgId()->at(broken_index);
  float broken_phi = mc_truth.getPhi()->at(broken_index);
  float broken_eta = mc_truth.getEta()->at(broken_index);

  // std::cout << "\t\tbroken it: " << broken_index
  //           << " - pdgid: " << broken_pdgid
  //           << " - phi: " << broken_phi
  //           << " - eta: " << broken_eta
  //           << "\n";

  int found_missing_link = -1;
  for ( size_t mc_it = 0
      ; mc_it != broken_index && found_missing_link < 0
      ; ++mc_it
      ) {
    int this_pdgid = mc_truth.getPdgId()->at(mc_it);
    if (this_pdgid != broken_pdgid) continue;
    float this_phi = mc_truth.getPhi()->at(mc_it);
    float this_eta = mc_truth.getEta()->at(mc_it);
    float dphi  = PennSusyFrame::calcDphi(this_phi, broken_phi);
    float deta  = (this_eta - broken_eta);
    float dr2 = dphi*dphi + deta*deta;

    // std::cout << "\t\tmc it: " << mc_it
    //           << " - pdgid: " << this_pdgid
    //           << " - phi: "   << this_phi
    //           << " - eta: "   << this_eta
    //           << " - dphi: "    << dphi
    //           << " - deta: "    << deta
    //           << " - dr2: "    << dr2
    //           << "\n";

    // if (  fabs(this_phi - broken_phi) < 0.1
    //    && fabs(this_eta - broken_eta) < 0.1
    if (dr2 < 0.16) {
      found_missing_link = mc_it;
    }
  }
  // if (found_missing_link == -1) {
  //   std::cout << "\tfailed to connect link\n";
  // }
  return found_missing_link;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::matchJetToBQuark( const PennSusyFrame::Jet* jet
                                   , const PennSusyFrame::MCTruth& mc_truth
                                   )
{
  float dummy_dr_min = 0;
  return matchJetToBQuark(jet, mc_truth, dummy_dr_min);
}

// -----------------------------------------------------------------------------
int PennSusyFrame::matchJetToBQuark( const PennSusyFrame::Jet* jet
                                   , const PennSusyFrame::MCTruth& mc_truth
                                   , float& return_dr_min
                                   )
{
  float jet_phi = jet->getPhi();
  float jet_eta = jet->getEta();

  int match_index = -1;
  //float dr_min = 999;
  // we want to ensure b jet is at least reasonably close to b quark
  // float dr_min = 0.30;
  float dr_min = 0.40;

  std::vector<float>* mc_eta    =  mc_truth.getEta();
  std::vector<float>* mc_phi    =  mc_truth.getPhi();
  std::vector<int>*   mc_pdgid  =  mc_truth.getPdgId();
  std::vector<int>*   mc_status =  mc_truth.getStatus();

  unsigned int mc_n = mc_truth.getN();
  for (unsigned int mc_it = 0; mc_it != mc_n; ++mc_it) {
    // only pair to b quarks
    if (fabs(mc_pdgid->at(mc_it)) != 5) continue;
    // only consider b quarks with status code 1-3
    if (mc_status->at(mc_it) > 3) continue;

    float dphi = PennSusyFrame::calcDphi(jet_phi, mc_phi->at(mc_it));
    float deta = (jet_eta - mc_eta->at(mc_it));
    float dr = std::sqrt( dphi*dphi + deta*deta );

    if (dr < dr_min) {
      dr_min = dr;
      match_index = mc_it;
    }
  }

  if (match_index != -1) return_dr_min = dr_min;
  else                   return_dr_min = -1;

  return match_index;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::getParticleIndex( int barcode
                                   , const PennSusyFrame::MCTruth& mc_truth
                                   )
{
  std::vector<int>* barcode_list = mc_truth.getBarcode();

  unsigned int mc_n = mc_truth.getN();
  for (unsigned int mc_it = 0; mc_it != mc_n; ++mc_it) {
    if (  barcode_list->at(mc_it) == barcode
       )
      return mc_it;
  }
  return -1;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::getParentIndex( int barcode
                                 , const PennSusyFrame::MCTruth& mc_truth
                                 , bool verbose
                                 )
{
  if (verbose) {
    std::cout << "\t\t\t\t\tgetParentIndex(" << barcode << " )\n";
  }

  int particle_index = getParticleIndex(barcode, mc_truth);
  if (particle_index < 0) return -1;

  std::vector<int>* pdgid_list = mc_truth.getPdgId();
  int particle_pdgid = pdgid_list->at(particle_index);

  int mother_index   = particle_index;
  int mother_pdgid   = particle_pdgid;
  if (verbose) {
    std::cout << "\t\t\t\t\t\t\tgetting mother barcode:\n";
    std::cout << "\t\t\t\t\t\t\t\tnum parents: "
              << mc_truth.getParents()->at(mother_index).size()
              << "\n";
  }

  // protect from particles which has no parents
  if (mc_truth.getParents()->at(mother_index).size() == 0) {
    if (verbose) {
      std::cout << "\t\t\t\t\t\t\t\tbailing!!!\n";
    }
    return -1;
  }
  int mother_barcode = mc_truth.getParents()->at(mother_index).at(0);

  if (verbose) {
    std::cout << "\t\t\t\t\t\tparticle index: " << particle_index << "\n"
              << "\t\t\t\t\t\tparticle pdgid: " << particle_pdgid << "\n"
              << "\t\t\t\t\t\tmother index: " << mother_index << "\n"
              << "\t\t\t\t\t\tmother pdgid: " << mother_pdgid << "\n"
              << "\t\t\t\t\t\tmother barcode: " << mother_barcode << "\n";
  }

  // place to store the next mother index while we validate it
  int next_mother_index = mother_index;
  while (mother_pdgid == particle_pdgid && mother_index >= 0) {
    // get the next mother index
    next_mother_index = getParticleIndex(mother_barcode, mc_truth);
    // if we reach a mother index <=0, check for a broken truth record
    if (next_mother_index <= 0) {
      // std::cout << "truth record broken -- need to connect truth record using dr matching\n";
      next_mother_index = connectTruthRecord(mc_truth, mother_index);
    }
    // move next mother index to mother_index
    mother_index = next_mother_index;

    if (mother_index < 0) break;
    if (verbose) {
      std::cout << "\t\t\t\t\t\t\t---\n"
                << "\t\t\t\t\t\t\tmother index: " << mother_index << "\n"
                << "\t\t\t\t\t\t\tmother pdgid: " << mother_pdgid << "\n"
                << "\t\t\t\t\t\t\tmother barcode: " << mother_barcode << "\n"
                << "\t\t\t\t\t\t\t\tgetting next pdgid - index "
                << mother_index << " of " << pdgid_list->size() << "\n";
    }

    mother_pdgid = pdgid_list->at(mother_index);

    if (verbose) {
      std::cout << "\t\t\t\t\t\t\t\tgetting next barcode - index "
                << mother_index << " of " << mc_truth.getParents()->size()
                << "\n"
                << "\t\t\t\t\t\t\t\t\tthis parent list has "
                << mc_truth.getParents()->at(mother_index).size()
                << " entries\n";
    }

    if (mc_truth.getParents()->at(mother_index).size() == 0) break;
    mother_barcode = mc_truth.getParents()->at(mother_index).at(0);

    if (verbose) {
      std::cout << "\t\t\t\t\t\t\t---\n";
    }
  }
  if (verbose) {
    std::cout << "\t\t\t\t\t\t\t===\n";
  }

  bool particle_is_b_quark_or_hadron = ( fabs(particle_pdgid) == 5 || PennSusyFrame::isBHadron(particle_pdgid) );
  bool mother_is_b_quark_or_hadron   = ( fabs(mother_pdgid  ) == 5 || PennSusyFrame::isBHadron(mother_pdgid  ) );
  if (particle_is_b_quark_or_hadron && mother_is_b_quark_or_hadron) {
    if (verbose) {
      std::cout << "\t\t\t\t\t\t\tmother index: " << mother_index << "\n"
                << "\t\t\t\t\t\t\tmother pdgid: " << mother_pdgid << "\n"
                << "\t\t\t\t\t\t\tmother barcode: " << mother_barcode << "\n"
                << "\t\t\t\t\t\t\tparent and particle are b quark and b hadron"
                << " -- trying again\n";
    }
    mother_index = getParentIndex(mother_barcode, mc_truth);
    if (mother_index > 0) {
      if (verbose) std::cout << "finding final mother pdgid\n";
      mother_pdgid = pdgid_list->at(mother_index);
      if (verbose) std::cout << "finding final barcode\n";
      if (mc_truth.getParents()->at(mother_index).size() > 0)
        mother_barcode = mc_truth.getParents()->at(mother_index).at(0);
    }
  }

  if (verbose) {
    std::cout << "\t\t\t\t\t\t\t---\n"
              << "\t\t\t\t\t\t\tReturning parent index\n"
              << "\t\t\t\t\t\t\tmother index: " << mother_index << "\n"
              << "\t\t\t\t\t\t\tmother pdgid: " << mother_pdgid << "\n"
              << "\t\t\t\t\t\t\tmother barcode: " << mother_barcode << "\n";
  }

  return mother_index;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::isBHadron(int pdgid)
{
  // look for b mesons
  if (  fabs(pdgid) >= 500  && fabs(pdgid) < 600  ) return true;
  // look for b baryons
  if (  fabs(pdgid) >= 5000 && fabs(pdgid) < 6000 ) return true;
  // look for excited b mesons
  int pdgid_mod_1k = int(fabs(pdgid)) % 1000;
  if (  pdgid_mod_1k >= 500  && pdgid_mod_1k < 600  ) return true;
  return false;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::getBarcodeFromIndex( int index
                                      , const PennSusyFrame::MCTruth& mc_truth
                                      )
{
  if (index < 0) return -1;
  return mc_truth.getBarcode()->at(index);
}

// ---------------------------------------------------------------------------
float PennSusyFrame::calcMbbll( const PennSusyFrame::blPair& bl_0
                              , const PennSusyFrame::blPair& bl_1
                              )
{
  return ( *(bl_0.getJet()->getTlv())
         + *(bl_0.getLepton()->getTlv())
         + *(bl_1.getJet()->getTlv())
         + *(bl_1.getLepton()->getTlv())
         ).Mag();
}

// ---------------------------------------------------------------------------
float PennSusyFrame::calcPtbbll( const PennSusyFrame::blPair& bl_0
                               , const PennSusyFrame::blPair& bl_1
                               )
{
  return ( *(bl_0.getJet()->getTlv())
         + *(bl_0.getLepton()->getTlv())
         + *(bl_1.getJet()->getTlv())
         + *(bl_1.getLepton()->getTlv())
         ).Pt();
}

// ---------------------------------------------------------------------------
FLAVOR_CHANNEL PennSusyFrame::getTruthFC(const PennSusyFrame::MCTruth& mc_truth)
{
  std::vector<int> daughter_l_index;

  unsigned int num_mc_truth_objects = mc_truth.getN();
  for (unsigned int mc_it = 0; mc_it != num_mc_truth_objects; mc_it ++) {
    // get the pdgid of objects ... only care about leptons
    int this_pdgid = mc_truth.getPdgId()->at(mc_it);
    if (  fabs(this_pdgid) != 11
       && fabs(this_pdgid) != 13
       && fabs(this_pdgid) != 15
       ) {
      continue ;
    }
    // get number of parents of this particle...
    size_t num_parents = mc_truth.getParentIndex()->at(mc_it).size();
    if (num_parents == 0 ) continue;
    // look at the parents...
    for (size_t parent_it = 0; parent_it != num_parents ; parent_it++) {
      int this_parent_index = mc_truth.getParentIndex()->at(mc_it).at(parent_it);
      int this_parent_pdgid = ( this_parent_index >= 0
                              ? mc_truth.getPdgId()->at(this_parent_index)
                              : -1
                              );
      if (fabs(this_parent_pdgid) > 1.e6) {
        // then it's a stop parent-- store lep pdgid
        daughter_l_index.push_back(fabs(this_pdgid));
      }
    }
  }
  // find flavor channel this corresponds to
  if (daughter_l_index.size() == 2 ) {
    if (  daughter_l_index.at(0) == 11
       && daughter_l_index.at(1) == 11
       ) {
      return FLAVOR_EE;
    }
    else if (  daughter_l_index.at(0) == 13
            && daughter_l_index.at(1) == 13
            ) {
      return FLAVOR_MM;
    }
    else if (  (daughter_l_index.at(0) == 11 && daughter_l_index.at(1) == 13)
            || (daughter_l_index.at(0) == 13 && daughter_l_index.at(1) == 11)
            ) {
      return FLAVOR_EM;
    }
    else { //taus?
      std::cout << "WARNING!! Taus! \n" ;
      return FLAVOR_NONE;
    }
  }
  else if (daughter_l_index.size() < 2) {
    std::cout << "WARNING!! Less than 2 leptons with stop parent!! \n" ;
    return FLAVOR_NONE;
  }
  else {
    std::cout << "WARNING!! More than 2 leptons with stop parent!! \n" ;
    return FLAVOR_NONE;
  }
}

// -----------------------------------------------------------------------------
double PennSusyFrame::getFudgeKFactor(bool is_data, int dsid)
{
  if (is_data) return 1.;

  if (  (dsid >= 167749 && dsid <= 167757)
     || (dsid >= 167797 && dsid <= 167805)
     || (dsid >= 167809 && dsid <= 167817)
     || (dsid >= 167821 && dsid <= 167829)
     || (dsid >= 167833 && dsid <= 167841)
     || (dsid >= 180543 && dsid <= 180551)
     ) {
    return 1.3086;
  }
  return 1.;
}

