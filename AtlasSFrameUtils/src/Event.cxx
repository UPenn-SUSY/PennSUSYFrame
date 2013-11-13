#include "AtlasSFrameUtils/include/Event.h"

#include <cmath>
#include <iostream>

#include "AtlasSFrameUtils/include/CycleMacros.h"

#include "D3PDObjects/include/EventInfoD3PDObject.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"

// =============================================================================
ClassImp(Event)

// -----------------------------------------------------------------------------
Event::Event( const ::Long64_t& master
            , const char* prefix
            , bool is_data
            )
            : D3PDReader::EventInfoD3PDObject(master, prefix, is_data)
            , m_pile_up_weight(1.)
            , m_lepton_eff_weight(1.)
            , m_trigger_weight(1.)
            , m_cross_section_weight(1.)
            , m_b_tag_weight(1.)
            , m_emma_mt(0.)
            , m_ht(0.)
            , m_ht_jets(0.)
            , m_ht_leptons(0.)
            , m_mll(0.)
            , m_met_et(0.)
            , m_met_phi(0.)
            , m_met_rel(0.)
            , m_mt(0.)
            , m_mt2(0.)
            , m_meff(0.)
            , m_meff_jets(0.)
            , m_meff_leptons(0.)
            , m_ptll(0.)
            , m_phill(0.)
            , m_etall(0.)
            , m_dphill(0.)
            , m_jet_sum_pt(0.)
            , m_oljet(0.)
            , m_olratio(0.)
            , m_emma_mt_cached(false)
            , m_ht_cached(false)
            , m_ht_jets_cached(false)
            , m_ht_leptons_cached(false)
            , m_mll_cached(false)
            , m_met_et_cached(false)
            , m_met_phi_cached(false)
            , m_met_rel_cached(false)
            , m_mt_cached(false)
            , m_mt2_cached(false)
            , m_meff_cached(false)
            , m_meff_jets_cached(false)
            , m_meff_leptons_cached(false)
            , m_ptll_cached(false)
            , m_phill_cached(false)
            , m_etall_cached(false)
            , m_dphill_cached(false)
            , m_jet_sum_pt_cached(false)
            , m_oljet_cached(false)
            , m_olratio_cached(false)
{
  clear();
}

// -----------------------------------------------------------------------------
void Event::clear()
{
  m_event_desc.clear();
  m_sr_helper.clear();

  m_mc_event_weight         = 1.;
  m_pile_up_weight          = 1.;
  m_lepton_eff_weight       = 1.;
  m_trigger_weight          = 1.;
  m_cross_section_weight    = 1.;
  m_b_tag_weight            = 1.;
  m_k_factor                = 1.;
  m_eff_times_cross_section = 1.;
  m_fake_weight             = 1.;
  m_charge_flip_weight      = 1.;

  m_mc_channel_num = 0;

  m_emma_mt      = 0.;
  m_ht           = 0.;
  m_ht_jets      = 0.;
  m_ht_leptons   = 0.;
  m_mll          = 0.;
  m_met_et       = 0.;
  m_met_phi      = 0.;
  m_met_rel      = 0.;
  m_mt           = 0.;
  m_mt2          = 0.;
  m_meff         = 0.;
  m_meff_jets    = 0.;
  m_meff_leptons = 0.;
  m_ptll         = 0.;
  m_phill        = 0.;
  m_etall        = 0.;
  m_dphill        = 0.;

  m_jet_sum_pt = 0.;
  m_oljet      = 0.;
  m_olratio    = 0.;

  m_emma_mt_cached      = false;
  m_ht_cached           = false;
  m_ht_jets_cached      = false;
  m_ht_leptons_cached   = false;
  m_mll_cached          = false;
  m_met_et_cached       = false;
  m_met_phi_cached      = false;
  m_met_rel_cached      = false;
  m_mt_cached           = false;
  m_mt2_cached          = false;
  m_meff_cached         = false;
  m_meff_jets_cached    = false;
  m_meff_leptons_cached = false;
  m_ptll_cached         = false;
  m_phill_cached        = false;
  m_etall_cached        = false;
  m_dphill_cached        = false;

  m_jet_sum_pt_cached = false;
  m_oljet_cached = false;
  m_olratio_cached = false;
}

// -----------------------------------------------------------------------------
double Event::getMCEventWeight() const
{
  return m_mc_event_weight;
}

// -----------------------------------------------------------------------------
double Event::getPileUpWeight() const
{
  return m_pile_up_weight;
}

// -----------------------------------------------------------------------------
double Event::getLeptonEffWeight() const
{
  return m_lepton_eff_weight;
}

// -----------------------------------------------------------------------------
double Event::getTriggerWeight() const
{
  return m_trigger_weight;
}

// -----------------------------------------------------------------------------
double Event::getCrossSectionWeight() const
{
  return m_cross_section_weight;
}

// -----------------------------------------------------------------------------
double Event::getBTagWeight() const
{
  return m_b_tag_weight;
}

// -----------------------------------------------------------------------------
double Event::getKFactor() const
{
  return m_k_factor;
}

// -----------------------------------------------------------------------------
double Event::getEffTimesXS() const
{
  return m_eff_times_cross_section;
}
// -----------------------------------------------------------------------------
double Event::getFakeWeight() const
{
  return m_fake_weight;
}
// -----------------------------------------------------------------------------
double Event::getChargeFlipWeight() const
{
  return m_charge_flip_weight;
}
// -----------------------------------------------------------------------------
int Event::getMCChannelNum() const
{
  return m_mc_channel_num;
}

// -----------------------------------------------------------------------------
void Event::setMCEventWeight(double weight)
{
  m_mc_event_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setPileUpWeight(double weight)
{
  m_pile_up_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setLeptonEffWeight(double weight)
{
  m_lepton_eff_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setTriggerWeight(double weight)
{
  m_trigger_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setCrossSectionWeight(double weight)
{
  m_cross_section_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setBTagWeight(double weight)
{
  m_b_tag_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setKFactor(double weight)
{
  m_k_factor = weight;
}

// -----------------------------------------------------------------------------
void Event::setEffTimesXS(double weight)
{
  m_eff_times_cross_section = weight;
}
// -----------------------------------------------------------------------------
void Event::setFakeWeight(double weight)
{
  m_fake_weight = weight;
}
// -----------------------------------------------------------------------------
void Event::setChargeFlipWeight(double weight)
{
  m_charge_flip_weight = weight;
}
// -----------------------------------------------------------------------------
void Event::setMCChannelNum(int channel)
{
  m_mc_channel_num = channel;
}

// -----------------------------------------------------------------------------
void Event::setHt(double ht)
{
  m_ht = ht;
  m_ht_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setHtJets(double ht)
{
  m_ht_jets = ht;
  m_ht_jets_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setHtLeptons(double ht)
{
  m_ht_leptons = ht;
  m_ht_leptons_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMll(double mll)
{
  m_mll = mll;
  m_mll_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setEmmaMt(double emma_mt)
{
  m_emma_mt = emma_mt;
  m_emma_mt_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMt(double mt)
{
  m_mt = mt;
  m_mt_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMt2(double mt2)
{
  m_mt2 = mt2;
  m_mt2_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMeff(double meff)
{
  m_meff = meff;
  m_meff_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMeffJets(double meff)
{
  m_meff_jets = meff;
  m_meff_jets_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMeffLeptons(double meff)
{
  m_meff_leptons = meff;
  m_meff_leptons_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setPtll(double ptll)
{
  m_ptll = ptll;
  m_ptll_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setPhill(double phill)
{
  m_phill = phill;
  m_phill_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setEtall(double etall)
{
  m_etall = etall;
  m_etall_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setDeltaPhill(double dphill)
{
  m_dphill = dphill;
  m_dphill_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMetEt(double met_et)
{
  m_met_et = met_et;
  m_met_et_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMetPhi(double met_phi)
{
  m_met_phi = met_phi;
  m_met_phi_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMetRel(double met_rel)
{
  m_met_rel = met_rel;
  m_met_rel_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setJetSumPt(double jet_sum_pt)
{
  m_jet_sum_pt = jet_sum_pt;
  m_jet_sum_pt_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setOLJet(double oljet)
{
  m_oljet = oljet;
  m_oljet_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setOLRatio(double olratio)
{
  m_olratio = olratio;
  m_olratio_cached = true;
}

// -----------------------------------------------------------------------------
double Event::getHt() const
{
  if (!m_ht_cached)
    std::cout << "WARNING! Asking for ht, but not yet cached!\n";
  return m_ht;
}

// -----------------------------------------------------------------------------
double Event::getHtJets() const
{
  if (!m_ht_jets_cached)
    std::cout << "WARNING! Asking for ht_jets, but not yet cached!\n";
  return m_ht_jets;
}

// -----------------------------------------------------------------------------
double Event::getHtLeptons() const
{
  if (!m_ht_leptons_cached)
    std::cout << "WARNING! Asking for ht_leptons, but not yet cached!\n";
  return m_ht_leptons;
}

// -----------------------------------------------------------------------------
double Event::getMll() const
{
  if (!m_mll_cached)
    std::cout << "WARNING! Asking for mll, but not yet cached!\n";
  return m_mll;
}

// -----------------------------------------------------------------------------
double Event::getMetEt() const
{
  if (!m_met_et_cached)
    std::cout << "WARNING! Asking for met_et, but not yet cached!\n";
  return m_met_et;
}

// -----------------------------------------------------------------------------
double Event::getMetPhi() const
{
  if (!m_met_phi_cached)
    std::cout << "WARNING! Asking for met_phi, but not yet cached!\n";
  return m_met_phi;
}

// -----------------------------------------------------------------------------
double Event::getMetRel() const
{
  if (!m_met_rel_cached)
    std::cout << "WARNING! Asking for met_rel, but not yet cached!\n";
  return m_met_rel;
}

// -----------------------------------------------------------------------------
double Event::getEmmaMt() const
{
  if (!m_emma_mt_cached)
    std::cout << "WARNING! Asking for emma_mt, but not yet cached!\n";
  return m_emma_mt;
}

// -----------------------------------------------------------------------------
double Event::getMt() const
{
  if (!m_mt_cached)
    std::cout << "WARNING! Asking for mt, but not yet cached!\n";
  return m_mt;
}

// -----------------------------------------------------------------------------
double Event::getMt2() const
{
  if (!m_mt2_cached)
    std::cout << "WARNING! Asking for mt2, but not yet cached!\n";
  return m_mt2;
}

// -----------------------------------------------------------------------------
double Event::getMeff() const
{
  if (!m_meff_cached)
    std::cout << "WARNING! Asking for meff, but not yet cached!\n";
  return m_meff;
}

// -----------------------------------------------------------------------------
double Event::getMeffJets() const
{
  if (!m_meff_jets_cached)
    std::cout << "WARNING! Asking for meff_jets, but not yet cached!\n";
  return m_meff_jets;
}

// -----------------------------------------------------------------------------
double Event::getMeffLeptons() const
{
  if (!m_meff_leptons_cached)
    std::cout << "WARNING! Asking for meff_leptons, but not yet cached!\n";
  return m_meff_leptons;
}

// -----------------------------------------------------------------------------
double Event::getPtll() const
{
  if (!m_ptll_cached)
    std::cout << "WARNING! Asking for pt_ll, but not yet cached!\n";
  return m_ptll;
}

// -----------------------------------------------------------------------------
double Event::getPhill() const
{
  if (!m_phill_cached)
    std::cout << "WARNING! Asking for phi_ll, but not yet cached!\n";
  return m_phill;
}

// -----------------------------------------------------------------------------
double Event::getEtall() const
{
  if (!m_etall_cached)
    std::cout << "WARNING! Asking for eta_ll, but not yet cached!\n";
  return m_etall;
}

// -----------------------------------------------------------------------------
double Event::getDeltaPhill() const
{
  if (!m_dphill_cached)
    std::cout << "WARNING! Asking for dphi_ll, but not yet cached!\n";
  return m_dphill;
}

// -----------------------------------------------------------------------------
double Event::getJetSumPt() const
{
  if (!m_jet_sum_pt_cached)
    std::cout << "WARNING! Asking for jet_sum_pt, but not yet cached!\n";
  return m_jet_sum_pt;
}

// -----------------------------------------------------------------------------
double Event::getOLJet() const
{
  if (!m_oljet_cached)
    std::cout << "WARNING! Asking for oljet, but not yet cached!\n";
  return m_oljet;
}

// -----------------------------------------------------------------------------
double Event::getOLRatio() const
{
  if (!m_olratio_cached)
    std::cout << "WARNING! Asking for olratio, but not yet cached!\n";
  return m_olratio;
}


// ----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription* Event::getEventDesc()
{
  return &m_event_desc;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::SRHelper* Event::getSRHelper()
{
  return &m_sr_helper;
}

// ----------------------------------------------------------------------------
FLAVOR_CHANNEL Event::getFlavorChannel() const
{
  return m_event_desc.getFlavorChannel();
}

// ----------------------------------------------------------------------------
SIGN_CHANNEL Event::getSignChannel() const
{
  return m_event_desc.getSignChannel();
}

// ----------------------------------------------------------------------------
PHASE_SPACE Event::getPhaseSpace() const
{
  return m_event_desc.getPhaseSpace();
}

// -----------------------------------------------------------------------------
void Event::print()
{
  std::cout << "Event:\n"
            << "\tmll: "    << m_mll
            << "\tptll: "   << m_ptll
            << "\tphill: "  << m_phill
            << "\tetall: "  << m_etall
            << "\tdphill: " << m_dphill
            << "\n"
            << "\tmet_et: "  << m_met_et
            << "\tmet_phi: " << m_met_phi
            << "\tmet_rel: " << m_met_rel
            << "\n"
            << "\temma_mt: "      << m_emma_mt
            << "\tmt: "           << m_mt
            << "\tmt2: "          << m_mt2
            << "\tmeff: "         << m_meff
            << "\tmeff_jets: "    << m_meff_jets
            << "\tmeff_leptons: " << m_meff_leptons
            << "\n"
            << "\tht: "         << m_ht
            << "\tht_jets: "    << m_ht_jets
            << "\tht_leptons: " << m_ht_leptons
            << "\n";
}
