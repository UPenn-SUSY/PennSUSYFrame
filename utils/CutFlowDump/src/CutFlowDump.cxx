#include "CutFlowDump/include/CutFlowDump.h"

#include <iostream>
#include <iomanip>
#include <vector>

#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2.h>
#include <TROOT.h>
#include <TStyle.h>

#include "NtupleLooper/include/NtupleLooper.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// -----------------------------------------------------------------------------
CutFlowDump::CutFlowDump( TTree *tree
                        , double num_events) : NtupleLooper(tree, num_events)
                                             , m_axis_initialized(false)
{
  initCutFlowHists();
}

// -----------------------------------------------------------------------------
CutFlowDump::~CutFlowDump()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void CutFlowDump::processEvent()
{
  for ( WEIGHTS weight_it = WEIGHT_NONE
      ; weight_it != WEIGHT_N
      ; weight_it = static_cast<WEIGHTS>(weight_it + 1)
      ) {
    for ( PHASE_SPACE phase_it = PHASE_NONE
        ; phase_it != PHASE_N
        ; phase_it = static_cast<PHASE_SPACE>(phase_it + 1)
        ) {
      checkEvent(phase_it, weight_it);
    }
  }
}

// -----------------------------------------------------------------------------
void CutFlowDump::initCutFlowHists()
{
  initBinList();
  m_cutflow.resize(WEIGHT_N);

  for ( WEIGHTS weight_it = WEIGHT_NONE
      ; weight_it != WEIGHT_N
      ; weight_it = static_cast<WEIGHTS>(weight_it + 1)
      ) {
    m_cutflow.at(weight_it).resize(PHASE_N);
    std::string name = "cutflow_" + getWeightName(weight_it) + "_";

    for ( PHASE_SPACE phase_it = PHASE_NONE
        ; phase_it != PHASE_N
        ; phase_it = static_cast<PHASE_SPACE>(phase_it + 1)
        ) {
      if (phase_it == PHASE_NONE) name = name + "none";
      else if (phase_it == PHASE_EE)   name = name + "ee";
      else if (phase_it == PHASE_MM)   name = name + "mm";
      else if (phase_it == PHASE_EM)   name = name + "em";
      else if (phase_it == PHASE_ME)   name = name + "me";
      else continue;

      std::string title = name;

      size_t num_bins = m_bin_list.size();
      std::cout << "setting histogram to: " <<  num_bins << ", " << -0.5 << ", " <<  num_bins - 0.5 << "\n";
      m_cutflow.at(weight_it).at(phase_it) = new TH1D( name.c_str()
          , title.c_str()
          // , 110, -0.5, 109.5
          , num_bins, -0.5, num_bins - 0.5
          );

      TAxis* axis = m_cutflow.at(weight_it).at(phase_it)->GetXaxis();
      for (size_t bin_it = 0; bin_it != num_bins; ++bin_it) {
        axis->SetBinLabel(bin_it+1, m_bin_list.at(bin_it).c_str());
      }
    }
  }
}

// -----------------------------------------------------------------------------
void CutFlowDump::checkEvent(PHASE_SPACE phase, WEIGHTS weight_type)
{
  if (  phase != PHASE_EE
     && phase != PHASE_MM
     && phase != PHASE_EM
     && phase != PHASE_ME
     ) {
    return;
  }

  SusyAnalysisTools::EventDescription evt_desc  = m_event_desc;
  SusyAnalysisTools::SRHelper         sr_helper = m_sr_helper;
  unsigned int bin_num = 0;

  double weight = 1.;

  // All events
  fillHist(phase, weight_type, bin_num++, weight);

  // apply mc event weight
  if (weight_type != WEIGHT_NONE)
    weight *= m_mc_event_weight;
  fillHist(phase, weight_type, bin_num++, weight);

  // apply pile up weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_PILE_UP)
    weight *= m_pile_up_weight;
  fillHist(phase, weight_type, bin_num++, weight);

  // GRL
  if (evt_desc.getPassGrl() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // incomplete event
  if (evt_desc.getPassIncompleteEvent() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // lar error
  if (evt_desc.getPassLarError() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // tile error
  if (evt_desc.getPassTileError() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // tile hot spot
  if (evt_desc.getPassTileHotSpot() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // tile trip
  if (evt_desc.getPassTileTrip() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // bad jets
  if (evt_desc.getPassBadJets() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // calo problem jets
  if (evt_desc.getPassCaloProblemJets() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // primary vertex
  if (evt_desc.getPassPrimaryVertex() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // bad muons
  if (evt_desc.getPassBadMuons() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // cosmic muons
  if (evt_desc.getPassCosmicMuons() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // HFOR
  if (evt_desc.getPassHFOR() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // MC overlap
  if (evt_desc.getPassMCOverlap() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // >= 2 good leptons
  if (evt_desc.getPassGE2GoodLeptons() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // == 2 good leptons
  if (evt_desc.getPass2GoodLeptons() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // mll
  if (evt_desc.getPassMll() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // 2 signal leptons
  if (evt_desc.getPass2SignalLeptons() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // flavor selection
  bool pass_flavor = false;
  if (phase == PHASE_EE && evt_desc.getFlavorChannel() == FLAVOR_EE)
    pass_flavor = true;
  if (phase == PHASE_MM && evt_desc.getFlavorChannel() == FLAVOR_MM)
    pass_flavor = true;
  if (phase == PHASE_EM && evt_desc.getFlavorChannel() == FLAVOR_EM)
    pass_flavor = true;
  if (phase == PHASE_ME && evt_desc.getFlavorChannel() == FLAVOR_EM)
    pass_flavor = true;

  if (pass_flavor == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // apply lepton weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_LEPTON)
    weight *= m_lepton_weight;
  fillHist(phase, weight_type, bin_num++, weight);

  // apply trigger weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_TRIGGER)
    weight *= m_trigger_weight;
  fillHist(phase, weight_type, bin_num++, weight);

  // phase space selection
  if (evt_desc.getPhaseSpace() != phase) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // signal tau veto
  if (evt_desc.getPassTauVeto() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // Trigger
  bool pass_trigger = false;
  if (phase == PHASE_EE && evt_desc.isEETrigger()) pass_trigger = true;
  if (phase == PHASE_MM && evt_desc.isMMTrigger()) pass_trigger = true;
  if (phase == PHASE_EM && evt_desc.isEMTrigger()) pass_trigger = true;
  if (phase == PHASE_ME && evt_desc.isMETrigger()) pass_trigger = true;
  if (pass_trigger == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // Trigger matching
  if (evt_desc.getPassTriggerMatch() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);

  // Flag prompt lepton events
  if (evt_desc.getTruthPrompt() == false) return;
  fillHist(phase, weight_type, bin_num++, weight);
  // if (evt_desc.getTruthPrompt())
  //   fillHist(phase, weight_type, bin_num, weight);
  // ++bin_num;

  // Flag OS events
  if (evt_desc.getSignChannel() == SIGN_OS)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // Flag SS events
  if (evt_desc.getSignChannel() == SIGN_SS)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SR helpers
  bool pass_z_veto = sr_helper.getPassZVeto();
  bool pass_l_jet_veto = sr_helper.getPassLJetVeto();
  bool pass_b_jet_veto = sr_helper.getPassBJetVeto();
  bool pass_f_jet_veto = sr_helper.getPassFJetVeto();
  bool pass_total_jet_veto = (  pass_l_jet_veto
                             && pass_b_jet_veto
                             && pass_f_jet_veto
                             );

  // Store weight at this point so we can apply the b-tag weight at the
  // appropriate time for each SR
  double basic_weight = weight;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SROSJVeto
  ++bin_num;
  weight = basic_weight;
  bool pass_sr_osjveto = (evt_desc.getSignChannel() == SIGN_OS);

  // SROSJVeto jet veto
  pass_sr_osjveto = (pass_sr_osjveto && pass_total_jet_veto);
  if (pass_sr_osjveto)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SROSJVeto apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr_osjveto)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SROSJVeto Z veto
  pass_sr_osjveto = (pass_sr_osjveto && pass_z_veto);
  if (pass_sr_osjveto)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SROSJVeto met-rel
  pass_sr_osjveto = (pass_sr_osjveto && sr_helper.getPassSROSJVetoMetRel());
  if (pass_sr_osjveto)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SROSJVeto mt2
  pass_sr_osjveto = (pass_sr_osjveto && sr_helper.getPassSROSJVetoMt2());
  if (pass_sr_osjveto)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SRSSJets
  ++bin_num;
  weight = basic_weight;
  bool pass_sr_ssjets = (evt_desc.getSignChannel() == SIGN_SS);

  // SRSSJets mll veto
  pass_sr_ssjets = (pass_sr_ssjets && sr_helper.getPassSRSSJetsMllVeto());
  if (pass_sr_ssjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJets >= 1 L jet
  pass_sr_ssjets = (pass_sr_ssjets && !pass_l_jet_veto);
  if (pass_sr_ssjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJets B jet veto
  pass_sr_ssjets = (pass_sr_ssjets && pass_b_jet_veto);
  if (pass_sr_ssjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJets F jet veto
  pass_sr_ssjets = (pass_sr_ssjets && pass_f_jet_veto);
  if (pass_sr_ssjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJets apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr_ssjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJets Z veto
  if (phase == PHASE_EE)
    pass_sr_ssjets = (pass_sr_ssjets && pass_z_veto);
  if (pass_sr_ssjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJets met-rel
  pass_sr_ssjets = (pass_sr_ssjets && sr_helper.getPassSRSSJetsMetRel());
  if (pass_sr_ssjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJets mt
  pass_sr_ssjets = (pass_sr_ssjets && sr_helper.getPassSRSSJetsMt());
  if (pass_sr_ssjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SRSSJetsCF
  ++bin_num;
  weight = basic_weight;
  bool pass_sr_ssjetscf = (  (  evt_desc.getSignChannel()      == SIGN_OS
                             // && evt_desc.getTruthSignChannel() == SIGN_OS
                             )
                          || (  evt_desc.getSignChannel()      == SIGN_SS
                             && evt_desc.getTruthSignChannel() == SIGN_SS
                             )
                          );

  // SRSSJets mll veto
  pass_sr_ssjetscf = (pass_sr_ssjetscf && sr_helper.getPassSRSSJetsMllVeto());
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // srssjets cf cand
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // // SRSSJetsCF apply cf weght
  // if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_CF)
  //   weight *= m_cf_weight;
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // srssjets >= 1 l jet
  pass_sr_ssjetscf = (pass_sr_ssjetscf && !pass_l_jet_veto);
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJetsCF B jet veto
  pass_sr_ssjetscf = (pass_sr_ssjetscf && pass_b_jet_veto);
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJetsCF F jet veto
  pass_sr_ssjetscf = (pass_sr_ssjetscf && pass_f_jet_veto);
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJetsCF apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJetsCF Z veto
  if (phase == PHASE_EE)
    pass_sr_ssjetscf = (pass_sr_ssjetscf && pass_z_veto);
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJetsCF met-rel
  pass_sr_ssjetscf = (pass_sr_ssjetscf && sr_helper.getPassSRSSJetsMetRel());
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRSSJetsCF mt
  pass_sr_ssjetscf = (pass_sr_ssjetscf && sr_helper.getPassSRSSJetsMt());
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SR2Jets
  ++bin_num;
  weight = basic_weight;
  bool pass_sr_2jets = (evt_desc.getSignChannel() == SIGN_OS);

  // SR2Jets 2 light jets
  pass_sr_2jets = (pass_sr_2jets && sr_helper.getPassSR2JetsNumLJet());
  if (pass_sr_2jets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR2Jets Z veto
  pass_sr_2jets = (pass_sr_2jets && pass_z_veto);
  if (pass_sr_2jets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR2Jets b jet veto
  pass_sr_2jets = (pass_sr_2jets && pass_b_jet_veto);
  if (pass_sr_2jets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR2Jets apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr_2jets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR2Jets forward jet veto
  pass_sr_2jets = (pass_sr_2jets && pass_f_jet_veto);
  if (pass_sr_2jets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR2Jets top tag veto
  pass_sr_2jets = (pass_sr_2jets && sr_helper.getPassTopVeto());
  if (pass_sr_2jets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR2Jets met-rel
  pass_sr_2jets = (pass_sr_2jets && sr_helper.getPassSR2JetsMetRel());
  if (pass_sr_2jets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SRMT2
  ++bin_num;
  weight = basic_weight;
  bool pass_sr_mt2 = (evt_desc.getSignChannel() == SIGN_OS);

  // SRMT2 jet veto
  pass_sr_mt2 = (pass_sr_mt2 && pass_total_jet_veto);
  if (pass_sr_mt2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRMT2 apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr_mt2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR MT2 pt_l1
  pass_sr_mt2 = (pass_sr_mt2 && sr_helper.getPassSRMT2Lep1Pt());
  if (pass_sr_mt2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR MT2 pt_l2
  pass_sr_mt2 = (pass_sr_mt2 && sr_helper.getPassSRMT2Lep2Pt());
  if (pass_sr_mt2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;


  // SRMT2 Z veto
  if (phase == PHASE_EE || phase == PHASE_MM)
    pass_sr_mt2 = (pass_sr_mt2 && pass_z_veto);
  if (pass_sr_mt2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRMT2 met-rel
  pass_sr_mt2 = (pass_sr_mt2 && sr_helper.getPassSRMT2MetRel());
  if (pass_sr_mt2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRMT2a MT2 cut
  pass_sr_mt2 = (pass_sr_mt2 && sr_helper.getPassSRMT2aMt2());
  if (pass_sr_mt2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRMT2b MT2 cut
  pass_sr_mt2 = (pass_sr_mt2 && sr_helper.getPassSRMT2bMt2());
  if (pass_sr_mt2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SR ZJets
  ++bin_num;
  weight = basic_weight;
  bool pass_sr_zjets = (evt_desc.getSignChannel() == SIGN_OS);

  // SR ZJets >= 2 l jets
  pass_sr_zjets = (pass_sr_zjets && sr_helper.getPassSRZJetsNumLJets());
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR ZJets in Z window
  pass_sr_zjets = (pass_sr_zjets && !pass_z_veto);
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR ZJets b jet veto
  pass_sr_zjets = (pass_sr_zjets && pass_b_jet_veto);
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRZJets apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRZJets forward jet veto
  pass_sr_zjets = (pass_sr_zjets && pass_f_jet_veto);
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRZJets top tag veto
  pass_sr_zjets = (pass_sr_zjets && sr_helper.getPassTopVeto());
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR ZJets mjj
  pass_sr_zjets = (pass_sr_zjets && sr_helper.getPassSRZJetsMjj());
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR ZJets pt_j1
  pass_sr_zjets = (pass_sr_zjets && sr_helper.getPassSRZJetsJet1Pt());
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR ZJets pt_j2
  pass_sr_zjets = (pass_sr_zjets && sr_helper.getPassSRZJetsJet2Pt());
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRZJets met-rel
  pass_sr_zjets = (pass_sr_zjets && sr_helper.getPassSRZJetsMetRel());
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR ZJets mt2
  pass_sr_zjets = (pass_sr_zjets && sr_helper.getPassSRZJetsMt2());
  if (pass_sr_zjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SR WW
  ++bin_num;
  weight = basic_weight;
  bool pass_sr_ww = (evt_desc.getSignChannel() == SIGN_OS);

  // SR WW jet veto
  pass_sr_ww = (pass_sr_ww && pass_total_jet_veto);
  if (pass_sr_ww)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SRWW apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr_ww)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WW pt_l1
  pass_sr_ww = (pass_sr_ww && sr_helper.getPassSRWWLep1Pt());
  if (pass_sr_ww)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WW pt_l2
  pass_sr_ww = (pass_sr_ww && sr_helper.getPassSRWWLep2Pt());
  if (pass_sr_ww)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WW Z veto
  if (phase == PHASE_EE || phase == PHASE_MM)
    pass_sr_ww = (pass_sr_ww && pass_z_veto);
  if (pass_sr_ww)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WWa mll
  bool pass_sr_wwa = pass_sr_ww;
  pass_sr_wwa = (pass_sr_wwa && sr_helper.getPassSRWWaMll());
  if (pass_sr_wwa)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WWa ptll
  pass_sr_wwa = (pass_sr_wwa && sr_helper.getPassSRWWaPtll());
  if (pass_sr_wwa)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WWa met-rel
  pass_sr_wwa = (pass_sr_wwa && sr_helper.getPassSRWWaMetRel());
  if (pass_sr_wwa)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WWb mll
  bool pass_sr_wwb = pass_sr_ww;
  pass_sr_wwb = (pass_sr_wwb && sr_helper.getPassSRWWbMll());
  if (pass_sr_wwb)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WWb ptll
  pass_sr_wwb = (pass_sr_wwb && sr_helper.getPassSRWWbPtll());
  if (pass_sr_wwb)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WWb mt2
  pass_sr_wwb = (pass_sr_wwb && sr_helper.getPassSRWWbMt2());
  if (pass_sr_wwb)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WWc ptll
  bool pass_sr_wwc = pass_sr_ww;
  pass_sr_wwc = (pass_sr_wwc && sr_helper.getPassSRWWcPtll());
  if (pass_sr_wwc)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR WWc mt2
  pass_sr_wwc = (pass_sr_wwc && sr_helper.getPassSRWWcMt2());
  if (pass_sr_wwc)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // VRSS
  ++bin_num;
  weight = basic_weight;
  bool pass_vr_ss = (evt_desc.getSignChannel() == SIGN_SS);

  // VRSSCF mll veto
  pass_vr_ss = (pass_vr_ss && sr_helper.getPassSRSSJetsMllVeto());
  if (pass_sr_ssjets)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSS >= 1 L jet
  pass_vr_ss = (pass_vr_ss && !pass_l_jet_veto);
  if (pass_vr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSS B jet veto
  pass_vr_ss = (pass_vr_ss && pass_b_jet_veto);
  if (pass_vr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSS F jet veto
  pass_vr_ss = (pass_vr_ss && pass_f_jet_veto);
  if (pass_vr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSS apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_vr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSS Z veto
  if (phase == PHASE_EE)
    pass_vr_ss = (pass_vr_ss && pass_z_veto);
  if (pass_vr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSS met-rel
  pass_vr_ss = (pass_vr_ss && sr_helper.getPassSRSSJetsMetRel());
  if (pass_vr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSS mt
  pass_vr_ss = (pass_vr_ss && sr_helper.getPassSRSSJetsMt() == false);
  if (pass_vr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // VRSSCF
  ++bin_num;
  weight = basic_weight;
  bool pass_vr_sscf = (  (  evt_desc.getSignChannel()      == SIGN_OS
                         // && evt_desc.getTruthSignChannel() == SIGN_OS
                         )
                      || (  evt_desc.getSignChannel()      == SIGN_SS
                         && evt_desc.getTruthSignChannel() == SIGN_SS
                         )
                      );

  // VRSSCF mll veto
  pass_vr_sscf = (pass_vr_sscf && sr_helper.getPassSRSSJetsMllVeto());
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // srssjets cf cand
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // // VRSSCF apply cf weght
  // if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_CF)
  //   weight *= m_cf_weight;
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // srssjets >= 1 l jet
  pass_vr_sscf = (pass_vr_sscf && !pass_l_jet_veto);
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSSCF B jet veto
  pass_vr_sscf = (pass_vr_sscf && pass_b_jet_veto);
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSSCF F jet veto
  pass_vr_sscf = (pass_vr_sscf && pass_f_jet_veto);
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSSCF apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSSCF Z veto
  if (phase == PHASE_EE)
    pass_vr_sscf = (pass_vr_sscf && pass_z_veto);
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSSCF met-rel
  pass_vr_sscf = (pass_vr_sscf && sr_helper.getPassSRSSJetsMetRel());
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // VRSSCF mt
  pass_vr_sscf = (pass_vr_sscf && sr_helper.getPassSRSSJetsMt() == false);
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  
}

// -----------------------------------------------------------------------------
void CutFlowDump::fillHist( PHASE_SPACE phase
                          , WEIGHTS weight_type
                          , unsigned int cut_bin
                          , double weight
                          )
{
  m_cutflow.at(weight_type).at(phase)->Fill(cut_bin, weight);
}

// -----------------------------------------------------------------------------
void CutFlowDump::printToScreen()
{
  for ( WEIGHTS weight_it = WEIGHT_NONE
      ; weight_it != WEIGHT_N
      ; weight_it = static_cast<WEIGHTS>(weight_it + 1)
      ) {
    printToScreen(weight_it);
  }
}

// -----------------------------------------------------------------------------
void CutFlowDump::printToScreen(WEIGHTS weight_type)
{
  unsigned int line_width   = 100;
  unsigned int label_field  = 30;
  unsigned int weight_field = (line_width - label_field - 4 - 4*3 )/4;
  unsigned int precision    = weight_field-2;
  if (4+label_field+4*weight_field != line_width) {
    label_field += (line_width - label_field - 4 - 4*3 )%4;
  }
  std::string break_label = "";
  std::string break_weight = "";
  for (unsigned int i = 0; i != label_field ; ++i) break_label  += "-";
  for (unsigned int i = 0; i != weight_field; ++i) break_weight += "-";

  std::string single_line;
  for (unsigned int i = 0; i != line_width; ++i) single_line += '=';
  single_line = single_line + "\n";

  std::cout << single_line;
  std::cout << "= "
            << std::left << std::setw(line_width - 3)
            << getWeightName(weight_type)
            << "=\n";
  std::cout << single_line;
  std::cout << "= "  << std::left  << std::setw(label_field)  << "Cut"
            << " = " << std::right << std::setw(weight_field) << "EE"
            << " = " << std::right << std::setw(weight_field) << "MM"
            << " = " << std::right << std::setw(weight_field) << "EM"
            << " = " << std::right << std::setw(weight_field) << "ME"
            << " =\n";
  std::cout << single_line;

  TH1D* cutflow_ee = m_cutflow.at(weight_type).at(PHASE_EE);
  TH1D* cutflow_mm = m_cutflow.at(weight_type).at(PHASE_MM);
  TH1D* cutflow_em = m_cutflow.at(weight_type).at(PHASE_EM);
  TH1D* cutflow_me = m_cutflow.at(weight_type).at(PHASE_ME);

  unsigned int num_cuts = cutflow_ee->GetXaxis()->GetNbins();

  for (unsigned int bin_it = 0; bin_it != num_cuts; ++bin_it) {
    std::string cut_name = cutflow_ee->GetXaxis()->GetBinLabel(bin_it+1);

    double weight_ee = cutflow_ee->GetBinContent(bin_it + 1);
    double weight_mm = cutflow_mm->GetBinContent(bin_it + 1);
    double weight_em = cutflow_em->GetBinContent(bin_it + 1);
    double weight_me = cutflow_me->GetBinContent(bin_it + 1);

    if (cut_name == "BREAK") {
      std::cout << "= "  << std::left  << std::setw(label_field)  << break_label
                << " = " << std::right << std::setw(weight_field) << break_weight
                << " = " << std::right << std::setw(weight_field) << break_weight
                << " = " << std::right << std::setw(weight_field) << break_weight
                << " = " << std::right << std::setw(weight_field) << break_weight
                // << " = " << std::right << std::setw(weight_field)
                // << std::setprecision(precision) << weight_ee
                // << " = " << std::right << std::setw(weight_field)
                // << std::setprecision(precision) << weight_mm
                // << " = " << std::right << std::setw(weight_field)
                // << std::setprecision(precision) << weight_em
                // << " = " << std::right << std::setw(weight_field)
                // << std::setprecision(precision) << weight_me
                << " =\n";
    }
    else {
      std::cout << "= "  << std::left  << std::setw(label_field)
                << std::setprecision(precision) << cut_name
                << " = " << std::right << std::setw(weight_field)
                << std::setprecision(precision) << weight_ee
                << " = " << std::right << std::setw(weight_field)
                << std::setprecision(precision) << weight_mm
                << " = " << std::right << std::setw(weight_field)
                << std::setprecision(precision) << weight_em
                << " = " << std::right << std::setw(weight_field)
                << std::setprecision(precision) << weight_me
                << " =\n";
    }
  }
  std::cout << single_line;
  std::cout << "\n";
}

// -----------------------------------------------------------------------------
void CutFlowDump::printToFile(std::string out_file_name)
{
   std::cout << "Writing cut flow histograms to file: "
             << out_file_name << "\n";

   TFile* f = new TFile(out_file_name.c_str(), "RECREATE");

   m_cutflow.at(WEIGHT_NONE).at(PHASE_NONE)->Write();
   m_cutflow.at(WEIGHT_NONE).at(PHASE_EE)->Write();
   m_cutflow.at(WEIGHT_NONE).at(PHASE_MM)->Write();
   m_cutflow.at(WEIGHT_NONE).at(PHASE_EM)->Write();
   m_cutflow.at(WEIGHT_NONE).at(PHASE_ME)->Write();

   f->Write();
   f->Close();
   delete f;
}

// -----------------------------------------------------------------------------
std::string getWeightName(WEIGHTS weight_type)
{
  std::string weight_name = "";
  switch (weight_type) {
    case WEIGHT_NONE    : weight_name = "Raw";
                          break;
    case WEIGHT_MC_EVENT: weight_name = "MC_event";
                          break;
    case WEIGHT_PILE_UP : weight_name = "Pile_up";
                          break;
    case WEIGHT_LEPTON  : weight_name = "Lepton";
                          break;
    case WEIGHT_B_TAG   : weight_name = "B-tag";
                          break;
    case WEIGHT_TRIGGER: weight_name = "Trigger";
                         break;
    case WEIGHT_ALL    : weight_name = "All";
                         break;
    default            : break;
  }

  return weight_name;
}

// -----------------------------------------------------------------------------
void CutFlowDump::initBinList()
{
  m_bin_list.clear();

  m_bin_list.push_back("ALL");
  m_bin_list.push_back("MC event weight");
  m_bin_list.push_back("Pile up weight");
  m_bin_list.push_back("GRL");
  m_bin_list.push_back("Incomplete event");
  m_bin_list.push_back("LAr error");
  m_bin_list.push_back("Tile error");
  m_bin_list.push_back("Tile hot spot");
  m_bin_list.push_back("Tile trip");
  m_bin_list.push_back("Jet cleaning");
  m_bin_list.push_back("Calo problem jet");
  m_bin_list.push_back("Primary vertex");
  m_bin_list.push_back("Bad mu veto");
  m_bin_list.push_back("Cosmic mu veto");
  m_bin_list.push_back("HFOR");
  m_bin_list.push_back("MC Overlap");
  m_bin_list.push_back(">= 2 good lep");
  m_bin_list.push_back("== 2 good lep=");
  m_bin_list.push_back("mll");
  m_bin_list.push_back("== 2 signal lep");
  m_bin_list.push_back("Flavor");
  m_bin_list.push_back("Lepton SF");
  m_bin_list.push_back("Trigger weight");
  m_bin_list.push_back("Phase space");
  m_bin_list.push_back("Tau veto");
  m_bin_list.push_back("Trigger");
  m_bin_list.push_back("Trigger matching");
  m_bin_list.push_back("Prompt leptons");
  m_bin_list.push_back("Opposite sign");
  m_bin_list.push_back("Same sign");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("SR OSJVeto jet veto");
  m_bin_list.push_back("SR OSJVeto b-tag weight");
  m_bin_list.push_back("SR OSJVeto Z veto");
  m_bin_list.push_back("SR OSJVeto met-rel");
  m_bin_list.push_back("SR OSJVeto mt2");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("SR SSJets mll veto");
  m_bin_list.push_back("SR SSJets >= 1 L jet");
  m_bin_list.push_back("SR SSJets B jet veto");
  m_bin_list.push_back("SR SSJets F jet veto");
  m_bin_list.push_back("SR SSJets b-tag weight");
  m_bin_list.push_back("SR SSJets Z veto (ee)");
  m_bin_list.push_back("SR SSJets met-rel");
  m_bin_list.push_back("SR SSJets mt");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("SR SSJetsCF mll veto");
  m_bin_list.push_back("SR SSJetsCF CF cand");
  m_bin_list.push_back("SR SSJetsCF CF weight");
  m_bin_list.push_back("SR SSJetsCF >= 1 L jet");
  m_bin_list.push_back("SR SSJetsCF B jet veto");
  m_bin_list.push_back("SR SSJetsCF F jet veto");
  m_bin_list.push_back("SR SSJetsCF b-tag weight");
  m_bin_list.push_back("SR SSJetsCF Z veto (ee)");
  m_bin_list.push_back("SR SSJetsCF met-rel");
  m_bin_list.push_back("SR SSJetsCF mt");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("SR 2Jets 2-light jets");
  m_bin_list.push_back("SR 2Jets Z veto");
  m_bin_list.push_back("SR 2Jets b jet veto");
  m_bin_list.push_back("SR 2Jets b-tag weight");
  m_bin_list.push_back("SR 2Jets f jet veto");
  m_bin_list.push_back("SR 2Jets top tag veto");
  m_bin_list.push_back("SR 2Jets met-rel");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("SR MT2 jet veto");
  m_bin_list.push_back("SR MT2 b-tag weight");
  m_bin_list.push_back("SR MT2 pt_l1");
  m_bin_list.push_back("SR MT2 pt_l2");
  m_bin_list.push_back("SR MT2 Z veto");
  m_bin_list.push_back("SR MT2 met-rel");
  m_bin_list.push_back("SR MT2a mt2");
  m_bin_list.push_back("SR MT2b mt2");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("SR ZJets >= 2 L jet");
  m_bin_list.push_back("SR ZJets Z window");
  m_bin_list.push_back("SR ZJets b jet veto");
  m_bin_list.push_back("SR ZJets b-tag weight");
  m_bin_list.push_back("SR ZJets f jet veto");
  m_bin_list.push_back("SR ZJets top tag veto");
  m_bin_list.push_back("SR ZJets mjj");
  m_bin_list.push_back("SR ZJets pt_j1");
  m_bin_list.push_back("SR ZJets pt_j2");
  m_bin_list.push_back("SR ZJets met-rel");
  m_bin_list.push_back("SR ZJets mt2");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("SR WW jet veto");
  m_bin_list.push_back("SR WW b-tag weight");
  m_bin_list.push_back("SR WW pt_l1");
  m_bin_list.push_back("SR WW pt_l2");
  m_bin_list.push_back("SR WW Z veto");
  m_bin_list.push_back("SR WWa mll");
  m_bin_list.push_back("SR WWa ptll");
  m_bin_list.push_back("SR WWa met-rel");
  m_bin_list.push_back("SR WWb mll");
  m_bin_list.push_back("SR WWb ptll");
  m_bin_list.push_back("SR WWb mt2");
  m_bin_list.push_back("SR WWc ptll");
  m_bin_list.push_back("SR WWc mt2");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("VR SS mll veto");
  m_bin_list.push_back("VR SS >= 1 L jet");
  m_bin_list.push_back("VR SS B jet veto");
  m_bin_list.push_back("VR SS F jet veto");
  m_bin_list.push_back("VR SS b-tag weight");
  m_bin_list.push_back("VR SS Z veto (ee)");
  m_bin_list.push_back("VR SS met-rel");
  m_bin_list.push_back("VR SS mt");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("VR SS CF mll veto");
  m_bin_list.push_back("VR SS CF cand");
  m_bin_list.push_back("VR SS CF weight");
  m_bin_list.push_back("VR SS CF >= 1 L jet");
  m_bin_list.push_back("VR SS CF B jet veto");
  m_bin_list.push_back("VR SS CF F jet veto");
  m_bin_list.push_back("VR SS CF b-tag weight");
  m_bin_list.push_back("VR SS CF Z veto (ee)");
  m_bin_list.push_back("VR SS CF met-rel");
  m_bin_list.push_back("VR SS CF mt");
  m_bin_list.push_back("BREAK");

  // m_bin_list.push_back("CR ZX Z window");
  // m_bin_list.push_back("CR ZXosjveto jet veto");
  // m_bin_list.push_back("CR ZXosjveto met-rel");
  // m_bin_list.push_back("CR ZXmt2 jet veto");
  // m_bin_list.push_back("CR ZXmt2 met-rel");
  // m_bin_list.push_back("CR ZXmt2a mt2");
  // m_bin_list.push_back("CR ZXmt2b mt2");
  // m_bin_list.push_back("CR ZX2jets >- 2 L jets");
  // m_bin_list.push_back("CR ZX2jets b jet veto");
  // m_bin_list.push_back("CR ZX2jets b-tag weight");
  // m_bin_list.push_back("CR ZX2jets f jet veto");
  // m_bin_list.push_back("CR ZX2jets top tag veto");
  // m_bin_list.push_back("CR ZX2jets met-rel");
  // m_bin_list.push_back("CR ZX2jets mt2");
  // m_bin_list.push_back("CR ZXWW jet feto");
  // m_bin_list.push_back("CR ZXWW met-rel");
  // m_bin_list.push_back("CR ZXWW mt2");

  // m_bin_list.push_back("CR top z veto");
  // m_bin_list.push_back("CR top met-rel");
  // m_bin_list.push_back("CR top num central jets");
  // m_bin_list.push_back("CR top num b jets");

  // m_bin_list.push_back("CR topWW pt l1");
  // m_bin_list.push_back("CR topWW pt l2");
  // m_bin_list.push_back("CR topWW num b jets");
  // m_bin_list.push_back("CR topWWa ");
  // m_bin_list.push_back("CR topWWa ");
  // m_bin_list.push_back("CR topWWa ");
  // m_bin_list.push_back("CR topWWb ");
  // m_bin_list.push_back("CR topWWb ");
  // m_bin_list.push_back("CR topWWb ");
  // m_bin_list.push_back("CR topWWc ");
  // m_bin_list.push_back("CR topWWc ");
  // m_bin_list.push_back("CR topWWc ");

  // m_bin_list.push_back("CR WW12 ");

  // m_bin_list.push_back("CR WWabc ");

  // m_bin_list.push_back("CR btag");
}
