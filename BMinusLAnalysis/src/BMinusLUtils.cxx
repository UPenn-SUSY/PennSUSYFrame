#include "BMinusLAnalysis/include/BMinusLUtils.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/Calculators.h"

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
bool PennSusyFrame::doBLPairing( const PennSusyFrame::Event& event
                               , const std::vector<PennSusyFrame::Electron*>* el_list
                               , const std::vector<PennSusyFrame::Muon*>*     mu_list
                               , const std::vector<PennSusyFrame::Jet*>*      b_jet_list
                               , PennSusyFrame::blPair& pair_0
                               , PennSusyFrame::blPair& pair_1
                               )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();
  if (fc == FLAVOR_NONE) return false;

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
                              )
{
  if (event.getIsData()) return false;

  // std::cout << "checking for same parent:\n";

  // std::cout << "\tgetting lepton parent\n";
  int lep_barcode = lep->getTruthBarcode();
  int lep_parent_index = getParentIndex(lep_barcode, mc_truth);
  int lep_parent_barcode = PennSusyFrame::getBarcodeFromIndex(lep_parent_index, mc_truth);

  // std::cout << "\tmatching b jet to b quark\n";
  int jet_b_quark_index = PennSusyFrame::matchJetToBQuark(jet, mc_truth);

  // if we fail to match the b jet to a b quark, we can give up now
  if (jet_b_quark_index < 0) return false;

  // std::cout << "\tgetting b jet parent\n";
  // std::cout << "\tgetting b jet parent - get jet barcode - b quark index: " << jet_b_quark_index << "\n";
  int jet_b_quark_barcode = mc_truth.getBarcode()->at(jet_b_quark_index);
  // std::cout << "\tgetting b jet parent - get parent index - barcode: " << jet_b_quark_barcode << "\n";
  int jet_parent_index = PennSusyFrame::getParentIndex( jet_b_quark_barcode, mc_truth);
  // std::cout << "\tgetting b jet parent - get parent barcode - jet parent index: " << jet_parent_index << "\n";
  int jet_parent_barcode = PennSusyFrame::getBarcodeFromIndex(jet_parent_index, mc_truth);
  // std::cout << "\tjet parent barcode: " << jet_parent_barcode << "\n";

  // protect from negative indices
  if (lep_parent_index < 0 || jet_parent_index < 0) return false;

  // if the two parents have the same barcode, they are the same!
  if (lep_parent_barcode == jet_parent_barcode) return true;

  // Special case to handle top -- lepton is not directly from top. There is an
  // intermediate W boson
  // std::cout << "\tgetting parent pdgids\n";
  int lep_parent_pdgid = mc_truth.getPdgId()->at(lep_parent_index);
  // std::cout << "\tlep parent pdgid: " << lep_parent_pdgid << "\n";
  int jet_parent_pdgid = mc_truth.getPdgId()->at(jet_parent_index);
  // std::cout << "\tjet parent pdgid: " << jet_parent_pdgid << "\n";

  // std::cout << "\tlepton parent barcode: " << lep_parent_barcode << "\n";
  // std::cout << "\tlepton parent index: " << lep_parent_index << "\n";
  // std::cout << "\tlepton parent pdgid: " << lep_parent_pdgid << "\n";
  // std::cout << "\n";
  // std::cout << "\tjet b quark index: " <<  jet_b_quark_index << "\n";
  // std::cout << "\tjet b quark barcode: " << jet_b_quark_barcode << "\n";
  // std::cout << "\tjet parent index: " << jet_parent_index << "\n";
  // std::cout << "\tjet parent barcode: " << jet_parent_barcode << "\n";
  // std::cout << "\tjet parent pdgid: " << jet_parent_pdgid << "\n";

  // if the parent of the lepton is a W, and the parent of the jet is a top,
  // there is still a chance these could be from the same parent (a top)
  if (fabs(lep_parent_pdgid) == 24 && fabs(jet_parent_pdgid) == 6) {
    // std::cout << "\t\tlepton parent == W && jet parent == top -- checking one step back for lepton\n";
    // find the parent of the W
    int w_parent_index   = PennSusyFrame::getParentIndex(lep_parent_barcode, mc_truth);
    int w_parent_barcode = PennSusyFrame::getBarcodeFromIndex(w_parent_index, mc_truth);
    // std::cout << "\t\tw parent index: " << w_parent_index << "\n";
    // std::cout << "\t\tw parent barcode: " << w_parent_barcode << "\n";
    if (w_parent_barcode == jet_parent_barcode) {
      // std::cout << "\tthese particles ARE from the same parent\n";
      return true;
    }
  }
  // std::cout << "\tthese particles ARE NOT from the same parent\n";

  return false;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::matchJetToBQuark( const PennSusyFrame::Jet* jet
                                   , const PennSusyFrame::MCTruth& mc_truth
                                   )
{
  float jet_phi = jet->getPhi();
  float jet_eta = jet->getEta();

  int match_index = -1;
  float dr_min = 999;

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

  return match_index;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::getParticleIndex( int barcode
                                   , const PennSusyFrame::MCTruth& mc_truth
                                   )
{
  std::vector<int>* barcode_list = mc_truth.getBarcode();
  std::vector<int>* pdgid_list = mc_truth.getPdgId();

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
                                 )
{
  // std::cout << "\t\t\t\t\tgetParentIndex(" << barcode << " )\n";

  int particle_index = getParticleIndex(barcode, mc_truth);
  if (particle_index < 0) return -1;

  std::vector<int>* pdgid_list = mc_truth.getPdgId();
  int particle_pdgid = pdgid_list->at(particle_index);

  int mother_index   = particle_index;
  int mother_pdgid   = particle_pdgid;
  // std::cout << "\t\t\t\t\t\t\tgetting mother barcode:\n";
  // std::cout << "\t\t\t\t\t\t\t\tnum parents: " << mc_truth.getParents()->at(mother_index).size() << "\n";
  // protect from particles which has no parents
  if (mc_truth.getParents()->at(mother_index).size() == 0) {
    // std::cout << "\t\t\t\t\t\t\t\tbailing!!!\n";
    return -1;
  }
  int mother_barcode = mc_truth.getParents()->at(mother_index).at(0);

  // std::cout << "\t\t\t\t\t\tparticle index: " << particle_index << "\n";
  // std::cout << "\t\t\t\t\t\tparticle pdgid: " << particle_pdgid << "\n";
  // std::cout << "\t\t\t\t\t\tmother index: " << mother_index << "\n";
  // std::cout << "\t\t\t\t\t\tmother pdgid: " << mother_pdgid << "\n";
  // std::cout << "\t\t\t\t\t\tmother barcode: " << mother_barcode << "\n";

  while (mother_pdgid == particle_pdgid && mother_index >= 0) {
    mother_index = getParticleIndex(mother_barcode, mc_truth);
    if (mother_index < 0) break;
    // std::cout << "\t\t\t\t\t\t\t---\n";
    // std::cout << "\t\t\t\t\t\t\tmother index: " << mother_index << "\n";
    // std::cout << "\t\t\t\t\t\t\tmother pdgid: " << mother_pdgid << "\n";
    // std::cout << "\t\t\t\t\t\t\tmother barcode: " << mother_barcode << "\n";
    // std::cout << "\t\t\t\t\t\t\t\tgetting next pdgid - index " << mother_index << " of " << pdgid_list->size() << "\n";

    mother_pdgid = pdgid_list->at(mother_index);

    // std::cout << "\t\t\t\t\t\t\t\tgetting next barcode - index " << mother_index << " of " << mc_truth.getParents()->size() << "\n";
    // std::cout << "\t\t\t\t\t\t\t\t\tthis parent list has " << mc_truth.getParents()->at(mother_index).size() << " entries\n";

    if (mc_truth.getParents()->at(mother_index).size() == 0) break;
    mother_barcode = mc_truth.getParents()->at(mother_index).at(0);

    // std::cout << "\t\t\t\t\t\t\t---\n";
  }
  // std::cout << "\t\t\t\t\t\t\t===\n";

  bool particle_is_b_quark_or_hadron = ( fabs(particle_pdgid) == 5 || PennSusyFrame::isBHadron(particle_pdgid) );
  bool mother_is_b_quark_or_hadron   = ( fabs(mother_pdgid  ) == 5 || PennSusyFrame::isBHadron(mother_pdgid  ) );
  if (particle_is_b_quark_or_hadron && mother_is_b_quark_or_hadron) {
    // std::cout << "\t\t\t\t\t\t\tmother index: " << mother_index << "\n";
    // std::cout << "\t\t\t\t\t\t\tmother pdgid: " << mother_pdgid << "\n";
    // std::cout << "\t\t\t\t\t\t\tmother barcode: " << mother_barcode << "\n";
    // std::cout << "\t\t\t\t\t\t\tparent and particle are b quark and b hadron -- trying again\n";
    mother_index = getParentIndex(mother_barcode, mc_truth);
    if (mother_index > 0) {
      // std::cout << "finding final mother pdgid\n";
      mother_pdgid = pdgid_list->at(mother_index);
      // std::cout << "finding final barcode\n";
      if (mc_truth.getParents()->at(mother_index).size() > 0)
        mother_barcode = mc_truth.getParents()->at(mother_index).at(0);
    }
  }

  // std::cout << "\t\t\t\t\t\t\t---\n";
  // std::cout << "\t\t\t\t\t\t\tReturning parent index\n";
  // std::cout << "\t\t\t\t\t\t\tmother index: " << mother_index << "\n";
  // std::cout << "\t\t\t\t\t\t\tmother pdgid: " << mother_pdgid << "\n";
  // std::cout << "\t\t\t\t\t\t\tmother barcode: " << mother_barcode << "\n";

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
