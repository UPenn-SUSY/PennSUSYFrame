//TO DO remove the c_do_trigger_matching from the
//phase space when 2012 is settled

// =============================================================================
#include "SelectionTools/include/TriggerCutTool.h"

#include <iostream>
#include <math.h>
#include <vector>

#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Trigger.h"
#include "AtlasSFrameUtils/include/TriggerVec.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

#include "TriggerMatch/TriggerMatch2Lep.h"



// -----------------------------------------------------------------------------
SelectionTools::TriggerCutTool::TriggerCutTool(
    SCycleBase* parent, const char* name) : ToolBase(parent, name)
{
  DeclareProperty("do_trigger_matching"    , c_do_trigger_matching    = false);
  DeclareProperty("check_official_matching", c_check_against_official = false);
  DeclareProperty("do_mc_trigger"          , c_do_mc_trigger          = false);
}

// -----------------------------------------------------------------------------
SelectionTools::TriggerCutTool::~TriggerCutTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedAnySingleOrDiLeptonTrigger(
    const Event* event,
    const Trigger* trig)
{
  bool pass_trigger = (  passedEETriggerChannel( event, trig)
                      || passedMMTriggerChannel( event, trig)
                      || passedEMTriggerChannel( event, trig)
                      || passedMETriggerChannel( event, trig)
                      );
  return pass_trigger;
}

// -----------------------------------------------------------------------------
TRIG_PHASE SelectionTools::TriggerCutTool::getPhaseSpace(
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  size_t num_el = electrons.size();
  size_t num_mu = muons.size();

  if (num_el == 2 && num_mu == 0) {
    // ee channel
    double pt_0 = electrons.at(0)->getTlv().Pt()/1000.;
    double pt_1 = electrons.at(1)->getTlv().Pt()/1000.;

    if (pt_1 > pt_0) {
      double pt_tmp = pt_0;
      pt_0 = pt_1;
      pt_1 = pt_tmp;
    }

    if (pt_0 > 14. && pt_1 > 14.) {
      return TRIG_EE_A;
    }
    if (pt_0 > 25. && pt_1 > 10 && pt_1 < 14.) {
      return TRIG_EE_B;
    }
  }
  else if (num_el == 0 && num_mu == 2) {
    // mm channel
    double pt_0 = muons.at(0)->getTlv().Pt()/1000.;
    double pt_1 = muons.at(1)->getTlv().Pt()/1000.;

    if (pt_1 > pt_0) {
      double pt_tmp = pt_0;
      pt_0 = pt_1;
      pt_1 = pt_tmp;
    }

    if (pt_0 > 18 && pt_1 > 18)                           return TRIG_MM_A;
    if (pt_0 > 18 && pt_1 > 14 && pt_1 < 18)              return TRIG_MM_B;
    if (pt_0 > 18 && pt_1 > 8  && pt_1 < 14)              return TRIG_MM_C;
    if (pt_0 > 14 && pt_0 < 18 && pt_1 > 14 && pt_1 < 18) return TRIG_MM_D;
  }
  else if (num_el == 1 && num_mu == 1) {
    // em channel
    double pt_e = electrons.at(0)->getTlv().Pt()/1000.;
    double pt_m = muons.at(0)->getTlv().Pt()/1000.;

    if (pt_e > 14 && pt_m > 8)               return TRIG_EM_A;
    if (pt_e > 10 && pt_e < 14 && pt_m > 18) return TRIG_EM_B;
  }

  return TRIG_NONE;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEEPhaseSpace(
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  TRIG_PHASE phase = getPhaseSpace(electrons, muons);
  return (  phase == TRIG_EE_A
         || phase == TRIG_EE_B
         );
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMMPhaseSpace(
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  TRIG_PHASE phase = getPhaseSpace(electrons, muons);
  return (  phase == TRIG_MM_A
         || phase == TRIG_MM_B
         || phase == TRIG_MM_C
         || phase == TRIG_MM_D
         );
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEMPhaseSpace(
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  TRIG_PHASE phase = getPhaseSpace(electrons, muons);
  return (phase == TRIG_EM_A);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMEPhaseSpace(
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  TRIG_PHASE phase = getPhaseSpace(electrons, muons);
  return (phase == TRIG_EM_B);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEETriggerChannel(
    const Event* event,
    const Trigger* trig)
{
  return passedEETrigger2012(event, trig);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMMTriggerChannel(
    const Event* event,
    const Trigger* trig)
{
  return passedMMTrigger2012(event, trig);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEMTriggerChannel(
    const Event* event,
    const Trigger* trig)
{
  return passedEMTrigger2012(event, trig);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMETriggerChannel(
    const Event* event,
    const Trigger* trig)
{
  return passedMETrigger2012(event, trig);
}


// =============================================================================
// - trigger matching
// =============================================================================
// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEETriggerMatching(
    const Event* event,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  bool pass_trigger_match =
      passedEETriggerMatching2012(event, trig_vec, electrons, muons);

  // TODO make user configurable trigger cut
  if (c_check_against_official) {
    bool official_code = passedEETriggerMatch_anders( event
                                                    , trig_vec
                                                    , electrons
                                                    , muons
                                                    );

    if (pass_trigger_match != official_code) {
      std::cout << "passedEETriggerMatching TEST FAILED -- "
                << " our code: " << pass_trigger_match
                << " official: " << official_code
                << " num_electrons: " << electrons.size()
                << " num_muons: " << muons.size()
                << "\n";

      // if (el.size() > 1) {
      //   TLorentzVector tlv1 = el[0].getTlv();
      //   TLorentzVector tlv2 = el[1].getTlv();
      //   printf("pTs: %lf %lf\n", tlv1.Pt(), tlv2.Pt() );
      // }
      // // If conflict, call trigger match again with debug turned on
      // passedEETriggerMatch_anders(event, trig_vec, el, true);
    }
    else {
      std::cout << "passedEETriggerMatching TEST PASSED -- "
                << "\n";
    }
  }

  return pass_trigger_match;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMMTriggerMatching(
    const Event* event,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  bool pass_trigger_match =
      passedMMTriggerMatching2012(event, trig_vec, electrons, muons);

  // TODO make user configurable trigger cut
  if (c_check_against_official) {
    bool official_code = passedMMTriggerMatch_anders( event
                                                    , trig_vec
                                                    , electrons
                                                    , muons
                                                    );

    if (pass_trigger_match != official_code) {
      std::cout << "passedMMTriggerMatching TEST FAILED -- "
                << " our code: " << pass_trigger_match
                << " official: " << official_code
                << " num_electrons: " << electrons.size()
                << " num_muons: " << muons.size()
                << "\n";

      // if (mu.size() > 1) {
      //   TLorentzVector tlv1 = mu[0].getTlv();
      //   TLorentzVector tlv2 = mu[1].getTlv();
      //   printf("pTs: %lf %lf\n", tlv1.Pt(), tlv2.Pt() );
      // }
      // // If conflict, call trigger match again with debug turned on
      // passedMMTriggerMatch_anders(event, trig_vec, mu, true);
    }
    else {
      std::cout << "passedMMTriggerMatching TEST PASSED -- "
                << "\n";
    }
  }

  return pass_trigger_match;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEMTriggerMatching(
    const Event* event,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  bool pass_trigger_match =
      passedEMTriggerMatching2012(event, trig_vec, electrons, muons);

  // TODO make user configurable trigger cut
  if (c_check_against_official) {
    bool official_code = passedEMTriggerMatch_anders( event
                                                    , trig_vec
                                                    , electrons
                                                    , muons
                                                    );

    if (pass_trigger_match != official_code) {
      std::cout << "passedEMTriggerMatching TEST FAILED -- "
                << " our code: " << pass_trigger_match
                << " official: " << official_code
                << " num_electrons: " << electrons.size()
                << " num_muons: " << muons.size()
                << "\n";
      // if (el.size() > 0 && mu.size() > 0) {
      //   TLorentzVector el_tlv = el[0].getTlv();
      //   TLorentzVector mu_tlv = mu[0].getTlv();
      //   printf("pTs: %lf %lf\n", el_tlv.Pt(), mu_tlv.Pt() );
      // }
      // // If conflict, call trigger match again with debug turned on
      // passedEMTriggerMatch_anders(event, trig_vec, el, mu, true);
    }
    else {
      std::cout << "passedMETriggerMatching TEST PASSED -- "
                << "\n";
    }
  }

  return pass_trigger_match;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMETriggerMatching(
    const Event* event,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  bool pass_trigger_match =
    passedMETriggerMatching2012(event, trig_vec, electrons, muons);

  // TODO make user configurable trigger cut
  if (c_check_against_official) {
    bool official_code = passedMETriggerMatch_anders( event
                                                    , trig_vec
                                                    , electrons
                                                    , muons
                                                    );

    if (pass_trigger_match != official_code) {
      std::cout << "passedMETriggerMatching TEST FAILED -- "
                << " our code: "      << pass_trigger_match
                << " official: "      << official_code
                << " num_electrons: " << electrons.size()
                << " num_muons: "     << muons.size()
                << "\n";
      // if (el.size() > 0 && mu.size() > 0) {
      //   TLorentzVector el_tlv = el[0].getTlv();
      //   TLorentzVector mu_tlv = mu[0].getTlv();
      //   printf("pTs: %lf %lf\n", el_tlv.Pt(), mu_tlv.Pt() );
      // }
      // // If conflict, call trigger match again with debug turned on
      // passedMETriggerMatch_anders(event, trig_vec, el, mu, true);
    }
    else {
      std::cout << "passedEMTriggerMatching TEST PASSED -- "
                << "\n";
    }
  }

  return pass_trigger_match;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEETrigger2012(
    const Event* /*event*/,
    const Trigger* trig)
{
  if (!c_do_mc_trigger && !is_data()) return true;

  bool pass_single_trigger = false;
  bool pass_double_trigger = (  trig->EF_2e12Tvh_loose1()
                             || trig->EF_e24vh_medium1_e7_medium1()
                             );
  return (pass_single_trigger || pass_double_trigger);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMMTrigger2012(
    const Event* /*event*/,
    const Trigger* trig)
{
  if (!c_do_mc_trigger && !is_data()) return true;

  // this->testSasa();

  bool pass_single_trigger = false;
  bool pass_double_trigger = (  trig->EF_2mu13()
                             || trig->EF_mu18_tight_mu8_EFFS()
                             );
  return (pass_single_trigger || pass_double_trigger);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEMTrigger2012(
    const Event* /*event*/,
    const Trigger* trig)
{
  if (!c_do_mc_trigger && !is_data()) return true;

  bool pass_trigger = trig->EF_e12Tvh_medium1_mu8();
  return pass_trigger;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMETrigger2012(
    const Event* /*event*/,
    const Trigger* trig)
{
  if (!c_do_mc_trigger && !is_data()) return true;

  bool pass_trigger = trig->EF_mu18_tight_e7_medium1();
  return pass_trigger;
}


// 2012 trigger selection criteria
// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEETriggerMatching2012(
    const Event* /*event*/,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  // immediately fail events failing phase space selection
  TRIG_PHASE phase = getPhaseSpace(electrons, muons);
  if (  phase != TRIG_EE_A && phase != TRIG_EE_B ) return false;
  // if (electrons.size() < 2) return false;

  // Only do trigger matching on data. always set true for MC
  if (!c_do_mc_trigger && !is_data()) return true;
  bool pass_trigger_match = false;

  // ee region A
  if (phase == TRIG_EE_A) {
    pass_trigger_match = matchElectronList(
        electrons, trig_vec->trig_EF_el_EF_e12Tvh_loose1(), trig_vec,
        2, 0.15, 0);
  }
  // ee region B
  if (phase == TRIG_EE_B) {
    // require the leading lepton matches with e24vh_medium1
    bool pass_single_match = false;
    if (*electrons.at(0) > *electrons.at(1)) {
      pass_single_match = matchElectron(
          electrons.at(0), trig_vec->trig_EF_el_EF_e24vh_medium1(),
          trig_vec, 0.15, 0);
    }
    else {
      pass_single_match = matchElectron(
          electrons.at(1), trig_vec->trig_EF_el_EF_e24vh_medium1(),
          trig_vec, 0.15, 0);
    }

    // require both leptons match with the e24vh_medium1_e7_medium1
    bool pass_double_match = matchElectronList(
        electrons, trig_vec->trig_EF_el_EF_e24vh_medium1_e7_medium1(),
        trig_vec, 2, 0.15, 0);

    // check the && of the single and double matches above
    pass_trigger_match = (pass_single_match && pass_double_match);
  }

  return pass_trigger_match;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMMTriggerMatching2012(
    const Event* /*event*/,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  // immediately fail events failing phase space selection
  TRIG_PHASE phase = getPhaseSpace(electrons, muons);
  if (  phase != TRIG_MM_A
     && phase != TRIG_MM_B
     && phase != TRIG_MM_C
     && phase != TRIG_MM_D
     )
    return false;
  // if (muons.size() < 2) return false;

  // Only do trigger matching on data. always set true for MC
  if (!c_do_mc_trigger && !is_data()) return true;
  bool pass_trigger_match = false;



  // double pt0 = muons.at(0)->getTlv().Pt();
  // double pt1 = muons.at(1)->getTlv().Pt();

  // double pt_lead    = std::max(pt0, pt1);
  // double pt_sublead = std::min(pt0, pt1);


  // mm region A
  if (phase == TRIG_MM_A) {
      // require at least one muon matches with ef_mu18_tight
      bool pass_single_match = matchMuonList(
          muons, trig_vec->trig_EF_trigmuonef_EF_mu18_tight(),
          trig_vec, 1, 0.15, 0);

      // require both muons match with ef_mu18_tight_mu8_effs
      bool pass_double_match = matchMuonList(
          muons, trig_vec->trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS(),
          trig_vec, 2, 0.15, 0);

      // check the && of the single and double match above
      pass_trigger_match = (pass_single_match && pass_double_match);
  }

  if (phase == TRIG_MM_B) {
    // require leading muon matches with EF_mu18_tight
    Muon* leading = muons.at(0);
    if (*muons.at(1) > *leading)
      leading = muons.at(1);

    bool pass_leading_match = matchMuon(
        leading, trig_vec->trig_EF_trigmuonef_EF_mu18_tight(),
        trig_vec, 0.15, 0);

    // require both muons match with EF_mu18_tight_mu8_EFFS
    bool pass_double_match_1 = matchMuonList(
        muons, trig_vec->trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS(),
        trig_vec, 2, 0.15, 0);

    // require both muons match with EF_mu18_tight_mu8_EFFS
    bool pass_double_match_2 = matchMuonList(
        muons, trig_vec->trig_EF_trigmuonef_EF_mu13(),
        trig_vec, 2, 0.15, 0);

    // check (leading_match && double_match_1) || double_match_2
    // to get the decision
    pass_trigger_match = (  (pass_leading_match && pass_double_match_1)
                         || pass_double_match_2
                         );
  }
  if (phase == TRIG_MM_C) {
    // require leading muon matches with EF_mu18_tight
    Muon* leading = muons.at(0);
    if (*muons.at(1) > *leading)
      leading = muons.at(1);

    bool pass_single_match = matchMuon(
        leading, trig_vec->trig_EF_trigmuonef_EF_mu18_tight(),
        trig_vec, 0.15, 0);

    // require both muons match with EF_mu18_tight_mu8_EFFS
    bool pass_double_match = matchMuonList(
        muons, trig_vec->trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS(),
        trig_vec, 2, 0.15, 0);

    // check the && of the single and double match above
    pass_trigger_match = (pass_single_match && pass_double_match);
  }
  if (phase == TRIG_MM_D) {
    // require both muons match with EF_mu13
    pass_trigger_match = matchMuonList(
        muons, trig_vec->trig_EF_trigmuonef_EF_mu13(),
        trig_vec, 2, 0.15, 0);
  }

  return pass_trigger_match;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEMTriggerMatching2012(
    const Event* /*event*/,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  // immediately fail events failing phase space selection
  TRIG_PHASE phase = getPhaseSpace(electrons, muons);
  if (phase != TRIG_EM_A) {
    return false;
  }
  // if (electrons.size() < 1 || muons.size() < 1) return false;

  // Only do trigger matching on data. always set true for MC
  if (!c_do_mc_trigger && !is_data()) return true;
  bool pass_trigger_match = false;

  // em region A
  if (phase == TRIG_EM_A) {
    bool pass_electron_match = matchElectronList(
        electrons, trig_vec->trig_EF_el_EF_e12Tvh_medium1(),
        trig_vec, 1, 0.15, 0);
    bool pass_muon_match = matchMuonList(
        muons, trig_vec->trig_EF_trigmuonef_EF_mu8(),
        trig_vec, 1, 0.15, 0);

    pass_trigger_match = (pass_electron_match && pass_muon_match);
  }

  return pass_trigger_match;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMETriggerMatching2012(
    const Event* /*event*/,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons)
{
  // immediately fail events failing phase space selection
  TRIG_PHASE phase = getPhaseSpace(electrons, muons);
  if (phase != TRIG_EM_B) {
    return false;
  }
  // if (electrons.size() < 1 || muons.size() < 1) return false;

  // Only do trigger matching on data. always set true for MC
  if (!c_do_mc_trigger && !is_data()) return true;
  bool pass_trigger_match = false;

  // em region B
  if (phase == TRIG_EM_B) {
    bool pass_electron_match = matchElectronList(
        electrons, trig_vec->trig_EF_el_EF_e7T_medium1(),
        trig_vec, 1, 0.15, 0);
    bool pass_muon_match = matchMuonList(
        muons, trig_vec->trig_EF_trigmuonef_EF_mu18_tight(),
        trig_vec, 1, 0.15, 0);

    pass_trigger_match = (pass_electron_match && pass_muon_match);
  }

  return pass_trigger_match;
}


// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::matchElectronList(
    const std::vector<Electron*>& el,
    const std::vector<int>* trigger_chain,
    const TriggerVec* trig_vec,
    size_t num_to_match,
    double dr_cut,
    double pt_cut)
{
  // if we have fewer offline objects than num_to_match, we automatically fail
  if (el.size() < num_to_match)
    return false;

  // get vector of TLV objects
  std::vector<TLorentzVector> off_tlv;
  size_t offline_term = el.size();
  for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
    off_tlv.push_back(el.at(offline_it)->getTlv());
  }

  // sets to keep track of matches - want to avoid double counting matches
  std::set<int> offline_match;
  std::set<int> online_match;

  // loop over all online trigger objects
  size_t trig_term = trigger_chain->size();
  for (size_t trig_it = 0; trig_it != trig_term; ++trig_it) {
    // First check the trigger decision for this trigger object
    // do not match triggers that don't fire
    if (trigger_chain->at(trig_it) == 0) continue;

    TLorentzVector on_tlv;
    on_tlv.SetPxPyPzE( (*trig_vec)[trig_it].trig_EF_el_px()
                     , (*trig_vec)[trig_it].trig_EF_el_py()
                     , (*trig_vec)[trig_it].trig_EF_el_pz()
                     , (*trig_vec)[trig_it].trig_EF_el_E()
                     );

    // loop over offline objects to look for matches
    for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
      if (  off_tlv[offline_it].DeltaR(on_tlv) < dr_cut
         && off_tlv[offline_it].Pt() > pt_cut
         )
      {
        offline_match.insert(offline_it);
        online_match.insert(trig_it);

        if (  offline_match.size() >= num_to_match
           && online_match.size() >= num_to_match
           )
          return true;
      }
    }
  }

  return false;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::matchElectron(
    Electron* el,
    const std::vector<int>* trigger_chain,
    const TriggerVec* trig_vec,
    double dr_cut,
    double pt_cut)
{
  const std::vector<Electron*> el_vec(1, el);
  return matchElectronList( el_vec
                          , trigger_chain
                          , trig_vec
                          , 1
                          , dr_cut
                          , pt_cut
                          );
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::matchMuonList(
    const std::vector<Muon*>& mu,
    const std::vector<int>* trigger_chain,
    const TriggerVec* trig_vec,
    size_t num_to_match,
    double dr_cut,
    double pt_cut)
{
  // if we have fewer offline objects than num_to_match, we automatically fail
  if (mu.size() < num_to_match)
    return false;

  // get vector of TLV objects
  std::vector<TLorentzVector> off_tlv;
  size_t offline_term = mu.size();
  for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
    off_tlv.push_back(mu.at(offline_it)->getTlv());
  }

  // sets to keep track of matches - want to avoid double counting matches
  std::set<int> offline_match;
  unsigned int num_online_matched = 0;

  // loop over all online trigger objects
  size_t trig_term = trigger_chain->size();
  for (size_t trig_it = 0; trig_it != trig_term; ++trig_it) {
    // First check the trigger decision for this trigger object
    // do not match triggers that don't fire
    if (trigger_chain->at(trig_it) == 0) continue;

    std::set<int> online_match;

    size_t online_term =
        (*trig_vec)[trig_it].trig_EF_trigmuonef_track_CB_pt().size();
    for (size_t online_it = 0; online_it != online_term; ++online_it) {
      TLorentzVector on_tlv;
      on_tlv.SetPtEtaPhiM(
          std::max( 1.
                  , static_cast<double>(
                        (*trig_vec)[trig_it].trig_EF_trigmuonef_track_CB_pt().at(online_it))
                  ),
          (*trig_vec)[trig_it].trig_EF_trigmuonef_track_CB_eta().at(online_it),
          (*trig_vec)[trig_it].trig_EF_trigmuonef_track_CB_phi().at(online_it),
          0);

      // loop over offline objects to look for matches
      for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
        if (  off_tlv[offline_it].DeltaR(on_tlv) < dr_cut
           && off_tlv[offline_it].Pt() > pt_cut
           )
        {
          offline_match.insert(offline_it);
          online_match.insert(online_it);

        }
      }
    }

    num_online_matched += online_match.size();

    if (  offline_match.size() >= num_to_match
       && num_online_matched   >= num_to_match
       ) {
      return true;
    }
  }

  return false;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::matchMuon(
    Muon* mu,
    const std::vector<int>* trigger_chain,
    const TriggerVec* trig_vec,
    double dr_cut,
    double pt_cut)
{
  const std::vector<Muon*> mu_vec(1, mu);
  return matchMuonList( mu_vec
                      , trigger_chain
                      , trig_vec
                      , 1
                      , dr_cut
                      , pt_cut
                      );
}



// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEETriggerMatch_anders(
    const Event* event,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& /*muons*/,
    bool /*debug*/)
{
  if (electrons.size()<2) return false;
  if (!c_do_mc_trigger && !is_data()) return true;

  TLorentzVector l1 = electrons.at(0)->getTlv();
  TLorentzVector l2 = electrons.at(1)->getTlv();

  TriggerMatch2Lep *triggerMatchTool = new TriggerMatch2Lep();

  int run = event->RunNumber();

  size_t electron_trigger_object_size = trig_vec->trig_EF_el_px()->size();
  std::vector<float>* trig_EF_el_px =
      const_cast<std::vector<float>*>(trig_vec->trig_EF_el_px());
  std::vector<float>* trig_EF_el_py =
      const_cast<std::vector<float>*>(trig_vec->trig_EF_el_py());
  std::vector<float>* trig_EF_el_pz =
      const_cast<std::vector<float>*>(trig_vec->trig_EF_el_pz());
  std::vector<float>* trig_EF_el_E =
      const_cast<std::vector<float>*>(trig_vec->trig_EF_el_E());

  std::vector<int>* trig_EF_el_EF_e12Tvh_loose1 =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_el_EF_e12Tvh_loose1());
  std::vector<int>* trig_EF_el_EF_e24vh_medium1 =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_el_EF_e24vh_medium1());
  std::vector<int>* trig_EF_el_EF_e24vh_medium1_e7_medium1 =
      const_cast<std::vector<int>*>(
          trig_vec->trig_EF_el_EF_e24vh_medium1_e7_medium1());

  bool pass_ee_trigger = triggerMatchTool->getElecTriggerMatch(
      l1, l2, run, electron_trigger_object_size,
      trig_EF_el_px, trig_EF_el_py, trig_EF_el_pz, trig_EF_el_E,
      trig_EF_el_EF_e12Tvh_loose1,
      trig_EF_el_EF_e24vh_medium1,
      trig_EF_el_EF_e24vh_medium1_e7_medium1);

  delete triggerMatchTool;
  return pass_ee_trigger;
}

bool SelectionTools::TriggerCutTool::passedMMTriggerMatch_anders(
    const Event* event,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& /*electrons*/,
    const std::vector<Muon*>& muons,
    bool /*debug*/)
{
  if (muons.size()<2) return false;
  if (!c_do_mc_trigger && !is_data()) return true;

  TLorentzVector l1 = muons.at(0)->getTlv();
  TLorentzVector l2 = muons.at(1)->getTlv();

  TriggerMatch2Lep *triggerMatchTool = new TriggerMatch2Lep();

  int run = event->RunNumber();

  std::vector<int>* trig_EF_el_EF_e12Tvh_medium1 =
      const_cast<std::vector<int>* >(trig_vec->trig_EF_el_EF_e12Tvh_medium1());

  size_t muon_trigger_object_size =
      trig_vec->trig_EF_trigmuonef_track_CB_eta()->size();
  std::vector<std::vector<float> >* trig_EF_trigmuonef_track_CB_eta =
      const_cast<std::vector<std::vector<float> >*>(
          trig_vec->trig_EF_trigmuonef_track_CB_eta());
  std::vector<std::vector<float> >* trig_EF_trigmuonef_track_CB_phi =
      const_cast<std::vector<std::vector<float> >*>(
          trig_vec->trig_EF_trigmuonef_track_CB_phi());
  std::vector<std::vector<int> >* trig_EF_trigmuonef_track_CB_hasCB =
      const_cast<std::vector<std::vector<int> >*>(
          trig_vec->trig_EF_trigmuonef_track_CB_hasCB());

  std::vector<int> *trig_EF_trigmuonef_EF_mu18_tight =
      const_cast<std::vector<int>*>(
          trig_vec->trig_EF_trigmuonef_EF_mu18_tight());
  std::vector<int> *trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS =
      const_cast<std::vector<int>*>(
          trig_vec->trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS());
  std::vector<int> *trig_EF_trigmuonef_EF_mu13 =
      const_cast<std::vector<int>*>(
          trig_vec->trig_EF_trigmuonef_EF_mu13());

  bool pass_mumu_trigger = triggerMatchTool->getMuonTriggerMatch(
      l1, l2, run, muon_trigger_object_size,
      trig_EF_trigmuonef_track_CB_eta,
      trig_EF_trigmuonef_track_CB_phi,
      trig_EF_trigmuonef_track_CB_hasCB,
      trig_EF_trigmuonef_EF_mu18_tight,
      trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS,
      trig_EF_trigmuonef_EF_mu13);

  delete triggerMatchTool;
  return pass_mumu_trigger;
}

bool SelectionTools::TriggerCutTool::passedEMTriggerMatch_anders(
    const Event* event,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons,
    bool /*debug*/)
{
  if (electrons.size()<1 || muons.size()<1) return false;
  if (!c_do_mc_trigger && !is_data()) return true;

  TLorentzVector l1 = electrons.at(0)->getTlv();
  TLorentzVector l2 = muons.at(0)->getTlv();

  TriggerMatch2Lep *triggerMatchTool = new TriggerMatch2Lep();

  int run = event->RunNumber();

  unsigned int electron_trigger_object_size = trig_vec->trig_EF_el_px()->size();
  std::vector<float>* trig_EF_el_px = const_cast<std::vector<float>*>(trig_vec->trig_EF_el_px());
  std::vector<float>* trig_EF_el_py = const_cast<std::vector<float>*>(trig_vec->trig_EF_el_py());
  std::vector<float>* trig_EF_el_pz = const_cast<std::vector<float>*>(trig_vec->trig_EF_el_pz());
  std::vector<float>* trig_EF_el_E  = const_cast<std::vector<float>*>(trig_vec->trig_EF_el_E());

  std::vector<int>* trig_EF_el_EF_e12Tvh_medium1 = const_cast<std::vector<int>*>(trig_vec->trig_EF_el_EF_e12Tvh_medium1());

  unsigned int muon_trigger_object_size =
      trig_vec->trig_EF_trigmuonef_track_CB_eta()->size();
  std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_eta =
      const_cast<std::vector<std::vector<float> >*>(trig_vec->trig_EF_trigmuonef_track_CB_eta());
  std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_phi =
      const_cast<std::vector<std::vector<float> >*>(trig_vec->trig_EF_trigmuonef_track_CB_phi());
  std::vector<std::vector<int> >   *trig_EF_trigmuonef_track_CB_hasCB =
      const_cast<std::vector<std::vector<int> >*>(trig_vec->trig_EF_trigmuonef_track_CB_hasCB());

  std::vector<int> *trig_EF_trigmuonef_EF_mu8 =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_trigmuonef_EF_mu8());

  bool pass_emu_trigger = triggerMatchTool->getEmuTriggerMatch( l1
                                                              , l2
                                                              , run
                                                              , electron_trigger_object_size
                                                              , trig_EF_el_px
                                                              , trig_EF_el_py
                                                              , trig_EF_el_pz
                                                              , trig_EF_el_E
                                                              , muon_trigger_object_size
                                                              , trig_EF_trigmuonef_track_CB_eta
                                                              , trig_EF_trigmuonef_track_CB_phi
                                                              , trig_EF_trigmuonef_track_CB_hasCB
                                                              , trig_EF_el_EF_e12Tvh_medium1
                                                              , trig_EF_trigmuonef_EF_mu8
                                                              );

  delete triggerMatchTool;
  return pass_emu_trigger;
}

bool SelectionTools::TriggerCutTool::passedMETriggerMatch_anders(
    const Event* event,
    const TriggerVec* trig_vec,
    const std::vector<Electron*>& electrons,
    const std::vector<Muon*>& muons,
    bool /*debug*/)
{
  // static int count(0); count++; if (count<10) { printf("test sasa passedMETriggerMatch calling the officieal code\n");  }

  if (electrons.size()<1 || muons.size()<1) return false;
  if (!c_do_mc_trigger && !is_data()) return true;

  TLorentzVector l1 = electrons.at(0)->getTlv();
  TLorentzVector l2 = muons.at(0)->getTlv();

  TriggerMatch2Lep *triggerMatchTool = new TriggerMatch2Lep();

  int run = event->RunNumber();

  size_t electron_trigger_object_size = trig_vec->trig_EF_el_px()->size();
  std::vector<float>* trig_EF_el_px = const_cast<std::vector<float>*>(trig_vec->trig_EF_el_px());
  std::vector<float>* trig_EF_el_py = const_cast<std::vector<float>*>(trig_vec->trig_EF_el_py());
  std::vector<float>* trig_EF_el_pz = const_cast<std::vector<float>*>(trig_vec->trig_EF_el_pz());
  std::vector<float>* trig_EF_el_E  = const_cast<std::vector<float>*>(trig_vec->trig_EF_el_E());

  std::vector<int> *trig_EF_el_EF_e7T_medium1 =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_el_EF_e7T_medium1());
  std::vector<int> *trig_EF_el_EF_e12Tvh_medium1 =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_el_EF_e12Tvh_medium1());
  std::vector<int> *trig_EF_el_EF_e12Tvh_loose1 =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_el_EF_e12Tvh_loose1());
  std::vector<int> *trig_EF_el_EF_e24vh_medium1_e7_medium1 =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_el_EF_e24vh_medium1_e7_medium1());
  std::vector<int> *trig_EF_el_EF_e24vh_medium1 =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_el_EF_e24vh_medium1());

  size_t muon_trigger_object_size =
      trig_vec->trig_EF_trigmuonef_track_CB_eta()->size();
  std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_eta =
      const_cast<std::vector<std::vector<float> >* >(trig_vec->trig_EF_trigmuonef_track_CB_eta());
  std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_phi =
      const_cast<std::vector<std::vector<float> >* >(trig_vec->trig_EF_trigmuonef_track_CB_phi());
  std::vector<std::vector<int> >   *trig_EF_trigmuonef_track_CB_hasCB =
      const_cast<std::vector<std::vector<int> >* >(trig_vec->trig_EF_trigmuonef_track_CB_hasCB());

  std::vector<int> *trig_EF_trigmuonef_EF_mu8 =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_trigmuonef_EF_mu8());
  std::vector<int> *trig_EF_trigmuonef_EF_mu13 =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_trigmuonef_EF_mu13());
  std::vector<int> *trig_EF_trigmuonef_EF_mu18_tight =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_trigmuonef_EF_mu18_tight());
  std::vector<int> *trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS =
      const_cast<std::vector<int>*>(trig_vec->trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS());

  bool pass_mue_trigger = triggerMatchTool->getMueTriggerMatch( l1
                                                              , l2
                                                              , run
                                                              , electron_trigger_object_size
                                                              , trig_EF_el_px
                                                              , trig_EF_el_py
                                                              , trig_EF_el_pz
                                                              , trig_EF_el_E
                                                              , muon_trigger_object_size
                                                              , trig_EF_trigmuonef_track_CB_eta
                                                              , trig_EF_trigmuonef_track_CB_phi
                                                              , trig_EF_trigmuonef_track_CB_hasCB
                                                              , trig_EF_el_EF_e7T_medium1
                                                              , trig_EF_trigmuonef_EF_mu18_tight
                                                              );

  // bool pass_emu_trigger = triggerMatchTool->getEmuTriggerMatch( l1
  //                                                             , l2
  //                                                             , run
  //                                                             , electron_trigger_object_size
  //                                                             , trig_EF_el_px
  //                                                             , trig_EF_el_py
  //                                                             , trig_EF_el_pz
  //                                                             , trig_EF_el_E
  //                                                             , muon_trigger_object_size
  //                                                             , trig_EF_trigmuonef_track_CB_eta
  //                                                             , trig_EF_trigmuonef_track_CB_phi
  //                                                             , trig_EF_trigmuonef_track_CB_hasCB
  //                                                             , trig_EF_el_EF_e12Tvh_medium1
  //                                                             , trig_EF_trigmuonef_EF_mu8
  //                                                             );

  delete triggerMatchTool;
  return pass_mue_trigger;
}
