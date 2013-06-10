#include "AtlasSFrameUtils/include/Met.h"

#include <cmath>
#include <iostream>

#include "AtlasSFrameUtils/include/CycleMacros.h"

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"

#include "D3PDObjects/include/METD3PDObject.h"

#include "MissingETUtility/METUtility.h"

// =============================================================================
ClassImp(Met)

// ----------------------------------------------------------------------------
Met::Met( const ::Long64_t& master
        , const char* prefix
        , bool is_data
        )
        : D3PDReader::METD3PDObject(master, prefix, is_data)
{
  // do nothing
}

// ----------------------------------------------------------------------------
void Met::init()
{

  // Set the jet algorithm option
  m_met_utility.defineMissingET( true  // doRefEle
                               , true  // doRefGamma
                               , false // doRefTau
                               , true  // doRefJet
                               , false // doRefMuon
                               , true  // doMuonTotal
                               , true  // doSoftTerms
                               );
  m_met_utility.setIsMuid(false);

  bool m_is_2012 = true;
  bool m_is_stvf = false;

  // configure the met utility
  m_met_utility.configMissingET(m_is_2012, m_is_stvf);
  m_met_utility.setJetPUcode(MissingETTags::DEFAULT);
}

// ----------------------------------------------------------------------------
void Met::clear()
{
  m_prepared = false;

  m_met_utility.reset();
  // do other things to clear met tool
}

// ----------------------------------------------------------------------------
void Met::prep( Event* event
              , ElectronContainer* electrons
              , MuonContainer* muons
              , JetContainer* jets
              )
{
  if (!m_prepared) {
    m_met_utility.setAverageIntPerXing(event->averageIntPerXing());
    // m_met_utility.setJetPUcode(MissingETTags::DEFAULT);

    addMet();
    addJets(jets);
    addElectrons(electrons);
    addMuons(muons);
  }
  METUtility::METObject met_util = m_met_utility.getMissingET( METUtil::RefFinal );
  m_met_vec.Set(met_util.etx(), met_util.ety());

  m_prepared = true;
}

// -----------------------------------------------------------------------------
void Met::doWeightFix( std::vector<float>& wet
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

// ----------------------------------------------------------------------------
void Met::addMet()
{
  m_met_utility.setMETTerm( METUtil::SoftTerms
                          , CellOut_etx()
                          , CellOut_ety()
                          , CellOut_sumet()
                          );


  m_met_utility.setMETTerm( METUtil::RefGamma
                          , RefGamma_etx()
                          , RefGamma_ety()
                          , RefGamma_sumet()
                          );
}

// ----------------------------------------------------------------------------
void Met::addElectrons(ElectronContainer* electron_container)
{
  const std::vector<Electron*> el = electron_container->getElectrons(EL_ALL);

  // initialize container vectors for electron parameters
  int n_el = el.size();
  std::vector<float> el_pt;
  std::vector<float> el_eta;
  std::vector<float> el_phi;

  std::vector<std::vector<float> > el_wet;
  std::vector<std::vector<float> > el_wpx;
  std::vector<std::vector<float> > el_wpy;
  std::vector<std::vector<unsigned int> > el_statusWord;

  // reserve their size for a little optimization
  el_pt.reserve(n_el);
  el_eta.reserve(n_el);
  el_phi.reserve(n_el);

  el_wet.reserve(n_el);
  el_wpx.reserve(n_el);
  el_wpy.reserve(n_el);
  el_statusWord.reserve(n_el);

  // Loop over electrons and get each of their parameters and weights
  std::vector<Electron*>::const_iterator el_it = el.begin();
  std::vector<Electron*>::const_iterator el_term = el.end();
  for (; el_it != el_term; ++el_it) {
    // skip electrons with wet == 0
    if ((*el_it)->MET_Egamma10NoTau_wet().at(0) == 0) continue;

    TLorentzVector el_tlv = (*el_it)->getTlv();
    el_pt.push_back( el_tlv.Pt() );
    el_eta.push_back(el_tlv.Eta());
    el_phi.push_back(el_tlv.Phi());

    std::vector<float> el_tmp_wet;
    std::vector<float> el_tmp_wpx;
    std::vector<float> el_tmp_wpy;
    if (m_is_stvf) {
      // el_statusWord.push_back((*el_it)->MET_Egamma10NoTau_STVF_statusWord());
      // el_tmp_wet = (*el_it)->MET_Egamma10NoTau_STVF_wet();
      // el_tmp_wpx = (*el_it)->MET_Egamma10NoTau_STVF_wpx();
      // el_tmp_wpy = (*el_it)->MET_Egamma10NoTau_STVF_wpy();
    }
    else {
      el_statusWord.push_back((*el_it)->MET_Egamma10NoTau_statusWord());
      el_tmp_wet = (*el_it)->MET_Egamma10NoTau_wet();
      el_tmp_wpx = (*el_it)->MET_Egamma10NoTau_wpx();
      el_tmp_wpy = (*el_it)->MET_Egamma10NoTau_wpy();
    }

    doWeightFix(el_tmp_wet, el_tmp_wpx, el_tmp_wpy);

    // // temp fix for too large and too small electron weights
    // unsigned int num_weights = el_tmp_wet.size();
    // for (unsigned int cl = 0; cl < num_weights; ++cl) {
    //   if (  el_tmp_wpx[cl] < 0.5 * el_tmp_wet[cl]
    //      || el_tmp_wpx[cl] > 2   * el_tmp_wet[cl]
    //      ) {
    //     el_tmp_wpx[cl] = el_tmp_wet[cl];
    //   }
    //   if (  el_tmp_wpy[cl] < 0.5 * el_tmp_wet[cl]
    //      || el_tmp_wpy[cl] > 2   * el_tmp_wet[cl]
    //      ) {
    //     el_tmp_wpy[cl] = el_tmp_wet[cl];
    //   }
    // }

    el_wet.push_back(el_tmp_wet);
    el_wpx.push_back(el_tmp_wpx);
    el_wpy.push_back(el_tmp_wpy);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_met_utility.setElectronParameters( &el_pt
                                     , &el_eta
                                     , &el_phi
                                     , &el_wet
                                     , &el_wpx
                                     , &el_wpy
                                     , &el_statusWord
                                     );
}

// ----------------------------------------------------------------------------
void Met::addJets(JetContainer* jet_container)
{

  const std::vector<Jet*> jets = jet_container->getJets(JET_ALL);

  // initialize container vectors for electron parameters
  int n_jets = jets.size();
  std::vector<float> jet_pt;
  std::vector<float> jet_eta;
  std::vector<float> jet_phi;
  std::vector<float> jet_E;
  std::vector<float> jet_orig_pt;

  std::vector<std::vector<float> > jet_wet;
  std::vector<std::vector<float> > jet_wpx;
  std::vector<std::vector<float> > jet_wpy;
  std::vector<std::vector<unsigned int> > jet_statusWord;

  // reserve their size for a little optimization
  jet_pt.reserve(n_jets);
  jet_eta.reserve(n_jets);
  jet_phi.reserve(n_jets);
  jet_E.reserve(n_jets);
  jet_orig_pt.reserve(n_jets);

  jet_wet.reserve(n_jets);
  jet_wpx.reserve(n_jets);
  jet_wpy.reserve(n_jets);
  jet_statusWord.reserve(n_jets);

  // Loop over jets and get their parameters and weights
  std::vector<Jet*>::const_iterator jet_it = jets.begin();
  std::vector<Jet*>::const_iterator jet_term = jets.end();
  for (; jet_it != jet_term; ++jet_it) {
    TLorentzVector jet_tlv     = (*jet_it)->getTlv();
    TLorentzVector jet_raw_tlv = (*jet_it)->getRawTlv();

    jet_pt.push_back( jet_tlv.Pt());
    jet_eta.push_back(jet_tlv.Eta());
    jet_phi.push_back(jet_tlv.Phi());
    jet_E.push_back(  jet_tlv.E());
    // jet_orig_pt.push_back(jet_raw_tlv.Pt());

    std::vector<float> jet_tmp_wet;
    std::vector<float> jet_tmp_wpx;
    std::vector<float> jet_tmp_wpy;
    if (m_is_stvf) {
      // jet_statusWord.push_back((*jet_it)->MET_Egamma10NoTau_STVF_statusWord());
      // jet_tmp_wet = (*jet_it)->MET_Egamma10NoTau_STVF_wet();
      // jet_tmp_wpx = (*jet_it)->MET_Egamma10NoTau_STVF_wpx();
      // jet_tmp_wpy = (*jet_it)->MET_Egamma10NoTau_STVF_wpy();
    }
    else {
      jet_statusWord.push_back((*jet_it)->MET_Egamma10NoTau_statusWord());
      jet_tmp_wet = (*jet_it)->MET_Egamma10NoTau_wet();
      jet_tmp_wpx = (*jet_it)->MET_Egamma10NoTau_wpx();
      jet_tmp_wpy = (*jet_it)->MET_Egamma10NoTau_wpy();
    }

    doWeightFix(jet_tmp_wet, jet_tmp_wpx, jet_tmp_wpy);

    // // temp fix for too large and too small jet weights
    // unsigned int num_weights = jet_tmp_wet.size();
    // for (unsigned int j = 0; j < num_weights; ++j) {
    //   if (  jet_tmp_wpx[j] < 0.5 * jet_tmp_wet[j]
    //      || jet_tmp_wpx[j] > 2   * jet_tmp_wet[j]
    //      ) {
    //     jet_tmp_wpx[j] = jet_tmp_wet[j];
    //   }
    //   if (  jet_tmp_wpy[j] < 0.5 * jet_tmp_wet[j]
    //      || jet_tmp_wpy[j] > 2   * jet_tmp_wet[j]
    //      ) {
    //     jet_tmp_wpy[j] = jet_tmp_wet[j];
    //   }
    // }

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
                                , &jet_statusWord
                                );

  // m_met_utility.setOriJetParameters(&jet_orig_pt);
}

// ----------------------------------------------------------------------------
void Met::addMuons(MuonContainer* muon_container)
{
  // const std::vector<Muon*> muons = muon_container->getMuons(MU_GOOD);
  const std::vector<Muon*> muons = muon_container->getMuons(MU_BASELINE);

  // initialize container vectors for muon parameters
  int n_mu = muons.size();
  std::vector<float> mu_pt;
  std::vector<float> mu_eta;
  std::vector<float> mu_phi;
  std::vector<std::vector<float> > mu_wet;
  std::vector<std::vector<float> > mu_wpx;
  std::vector<std::vector<float> > mu_wpy;
  std::vector<std::vector<unsigned int> > mu_statusWord;
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
  mu_statusWord.reserve(n_mu);
  mu_ms_qoverp.reserve(n_mu);
  mu_ms_theta.reserve(n_mu);
  mu_ms_phi.reserve(n_mu);
  mu_charge.reserve(n_mu);

  std::vector<float> unit_vec(1., 1);
  std::vector<unsigned int> def_vec(MissingETTags::DEFAULT, 1);

  std::vector<Muon*>::const_iterator mu_it = muons.begin();
  std::vector<Muon*>::const_iterator mu_term = muons.end();
  for (; mu_it != mu_term; ++mu_it) {
    TLorentzVector mu_tlv = (*mu_it)->getTlv();

    mu_pt.push_back( mu_tlv.Pt());
    mu_eta.push_back(mu_tlv.Eta());
    mu_phi.push_back(mu_tlv.Phi());
    mu_wet.push_back(unit_vec);
    mu_wpx.push_back(unit_vec);
    mu_wpy.push_back(unit_vec);
    mu_statusWord.push_back(def_vec);

    mu_ms_qoverp.push_back((*mu_it)->ms_qoverp());
    mu_ms_theta.push_back((*mu_it)->ms_theta());
    mu_ms_phi.push_back((*mu_it)->ms_phi());
    mu_charge.push_back((*mu_it)->charge());
  }

  m_met_utility.setMuonParameters( &mu_pt
                                 , &mu_eta
                                 , &mu_phi
                                 , &mu_wet
                                 , &mu_wpx
                                 , &mu_wpy
                                 , &mu_statusWord
                                 );
  m_met_utility.setExtraMuonParameters( &mu_ms_qoverp
                                      , &mu_ms_theta
                                      , &mu_ms_phi
                                      , &mu_charge
                                      );
}
// ----------------------------------------------------------------------------
TVector2 Met::getMetRefFinalVec() const
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (!m_prepared) {
    std::cout << "WARNING!!! "
             << "Met not prepared for event! Setting default value:"
             << "\n\tetx: 0\n\tety: 0\n";
    return TVector2(0,0);
  }

  return m_met_vec;
}

// ----------------------------------------------------------------------------
double Met::getMetRefFinalEt() const
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (!m_prepared) {
    std::cout << "WARNING!!! "
             << "Met not prepared for event! Setting default value:"
             << "\n\tet: -999\n";
    return -999;
  }
  return m_met_vec.Mod();
}

// ----------------------------------------------------------------------------
double Met::getMetRefFinalPhi() const
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (!m_prepared) {
    std::cout << "WARNING!!! "
             << "Met not prepared for event! Setting default value:"
             << "\n\tphi: -999\n";
    return -999;
  }
  return TVector2::Phi_mpi_pi(m_met_vec.Phi());
}

// -----------------------------------------------------------------------------
double Met::getMetRel( const Met* met
                     , const std::vector<Electron*>& el
                     , const std::vector<Muon*>& mu
                     , const std::vector<Jet*>& jet
                     )
{
  float min_dphi = 9999;

  float dphi_el  = getMinPhi(met, el);
  float dphi_mu  = getMinPhi(met, mu);
  float dphi_jet = getMinPhi(met, jet);

  if (dphi_el  < min_dphi) min_dphi = dphi_el;
  if (dphi_mu  < min_dphi) min_dphi = dphi_mu;
  if (dphi_jet < min_dphi) min_dphi = dphi_jet;

  double met_rel = met->getMetRefFinalEt();
  if (min_dphi < 3.14159/2) {
    met_rel *= sin(min_dphi);
  }

  return met_rel;
}

// -----------------------------------------------------------------------------
void Met::print( const std::vector<Electron*>& el
               , const std::vector<Muon*>& mu
               , const std::vector<Jet*>& jet
               )
{
  std::cout << "MET:\n"
            << "\tmet et: "  << getMetRefFinalEt()
            << "\tmet phi: " << getMetRefFinalPhi()
            << "\tmet-rel: " << getMetRel(this, el, mu, jet)
            << "\n";
}
