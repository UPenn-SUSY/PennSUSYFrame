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
CutFlowDump::CutFlowDump(TTree *tree) : NtupleLooper(tree)
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

      m_cutflow.at(weight_it).at(phase_it) = new TH1D( name.c_str()
          , title.c_str()
          , 110, -0.5, 109.5
          );

      TAxis* axis = m_cutflow.at(weight_it).at(phase_it)->GetXaxis();
      unsigned int bin = 1;
      axis->SetBinLabel(bin++, "ALL"              );
      axis->SetBinLabel(bin++, "MC event weight"  );
      axis->SetBinLabel(bin++, "Pile up weight"   );
      axis->SetBinLabel(bin++, "GRL"              );
      axis->SetBinLabel(bin++, "Incomplete event" );
      axis->SetBinLabel(bin++, "LAr error"        );
      axis->SetBinLabel(bin++, "Tile error"       );
      axis->SetBinLabel(bin++, "Tile hot spot"    );
      axis->SetBinLabel(bin++, "Jet cleaning"     );
      axis->SetBinLabel(bin++, "Calo problem jet" );
      axis->SetBinLabel(bin++, "Primary vertex"   );
      axis->SetBinLabel(bin++, "Bad mu veto"      );
      axis->SetBinLabel(bin++, "Cosmic mu veto"   );
      axis->SetBinLabel(bin++, "HFOR"             );
      axis->SetBinLabel(bin++, ">= 2 good lep"    );
      axis->SetBinLabel(bin++, "== 2 good lep="   );
      axis->SetBinLabel(bin++, "mll"              );
      axis->SetBinLabel(bin++, "== 2 signal lep"  );
      axis->SetBinLabel(bin++, "Flavor"           );
      axis->SetBinLabel(bin++, "Lepton SF"        );
      axis->SetBinLabel(bin++, "Trigger weight"   );
      axis->SetBinLabel(bin++, "Phase space"      );
      axis->SetBinLabel(bin++, "Trigger"          );
      axis->SetBinLabel(bin++, "Trigger matching" );
      axis->SetBinLabel(bin++, "Prompt leptons"   );
      axis->SetBinLabel(bin++, "Opposite sign"    );
      axis->SetBinLabel(bin++, "Same sign"        );
      axis->SetBinLabel(bin++, "BREAK"            );

      axis->SetBinLabel(bin++, "SR OSJVeto jet veto"    );
      axis->SetBinLabel(bin++, "SR OSJVeto b-tag weight");
      axis->SetBinLabel(bin++, "SR OSJVeto Z veto"      );
      axis->SetBinLabel(bin++, "SR OSJVeto met-rel"     );
      axis->SetBinLabel(bin++, "SR OSJVeto mt2"         );
      axis->SetBinLabel(bin++, "BREAK"                  );

      axis->SetBinLabel(bin++, "SR SSJets >= 1 L jet"  );
      axis->SetBinLabel(bin++, "SR SSJets B jet veto"  );
      axis->SetBinLabel(bin++, "SR SSJets F jet veto"  );
      axis->SetBinLabel(bin++, "SR SSJets b-tag weight");
      axis->SetBinLabel(bin++, "SR SSJets Z veto (ee)" );
      axis->SetBinLabel(bin++, "SR SSJets met-rel"     );
      axis->SetBinLabel(bin++, "SR SSJets mt"          );
      axis->SetBinLabel(bin++, "BREAK"                 );

      axis->SetBinLabel(bin++, "SR SSJetsCF CF cand"     );
      axis->SetBinLabel(bin++, "SR SSJetsCF CF weight"   );
      axis->SetBinLabel(bin++, "SR SSJetsCF >= 1 L jet"  );
      axis->SetBinLabel(bin++, "SR SSJetsCF B jet veto"  );
      axis->SetBinLabel(bin++, "SR SSJetsCF F jet veto"  );
      axis->SetBinLabel(bin++, "SR SSJetsCF b-tag weight");
      axis->SetBinLabel(bin++, "SR SSJetsCF Z veto (ee)" );
      axis->SetBinLabel(bin++, "SR SSJetsCF met-rel"     );
      axis->SetBinLabel(bin++, "SR SSJetsCF mt"          );
      axis->SetBinLabel(bin++, "BREAK"                   );

      axis->SetBinLabel(bin++, "SR 2Jets 2-light jets");
      axis->SetBinLabel(bin++, "SR 2Jets Z veto"      );
      axis->SetBinLabel(bin++, "SR 2Jets b jet veto"  );
      axis->SetBinLabel(bin++, "SR 2Jets b-tag weight");
      axis->SetBinLabel(bin++, "SR 2Jets f jet veto"  );
      axis->SetBinLabel(bin++, "SR 2Jets top tag veto");
      axis->SetBinLabel(bin++, "SR 2Jets met-rel"     );
      axis->SetBinLabel(bin++, "BREAK"                );

      axis->SetBinLabel(bin++, "SR MT2 jet veto"    );
      axis->SetBinLabel(bin++, "SR MT2 b-tag weight");
      axis->SetBinLabel(bin++, "SR MT2 Z veto"      );
      axis->SetBinLabel(bin++, "SR MT2 met-rel"     );
      axis->SetBinLabel(bin++, "SR MT2a mt2"        );
      axis->SetBinLabel(bin++, "SR MT2b mt2"        );
      axis->SetBinLabel(bin++, "BREAK"              );

      axis->SetBinLabel(bin++, "SR ZJets >= 2 L jet");
      axis->SetBinLabel(bin++, "SR ZJets Z window"  );
      axis->SetBinLabel(bin++, "SR ZJets b jet veto"  );
      axis->SetBinLabel(bin++, "SR ZJets b-tag weight");
      axis->SetBinLabel(bin++, "SR ZJets f jet veto"  );
      axis->SetBinLabel(bin++, "SR ZJets top tag veto");
      axis->SetBinLabel(bin++, "SR ZJets mjj");
      axis->SetBinLabel(bin++, "SR ZJets pt_j1");
      axis->SetBinLabel(bin++, "SR ZJets pt_j2");
      axis->SetBinLabel(bin++, "SR ZJets met-rel");
      axis->SetBinLabel(bin++, "SR ZJets mt2");
      axis->SetBinLabel(bin++, "BREAK");

      axis->SetBinLabel(bin++, "SR WW jet veto");
      axis->SetBinLabel(bin++, "SR WW pt_l1");
      axis->SetBinLabel(bin++, "SR WW pt_l2");
      axis->SetBinLabel(bin++, "SR WWa mll");
      axis->SetBinLabel(bin++, "SR WWa ptll");
      axis->SetBinLabel(bin++, "SR WWa met-rel");
      axis->SetBinLabel(bin++, "SR WWb mll");
      axis->SetBinLabel(bin++, "SR WWb ptll");
      axis->SetBinLabel(bin++, "SR WWb mt2");
      axis->SetBinLabel(bin++, "SR WWc ptll");
      axis->SetBinLabel(bin++, "SR WWc mt2");
      axis->SetBinLabel(bin++, "BREAK");

      axis->SetBinLabel(bin++, "VR SS >= 1 L jet"  );
      axis->SetBinLabel(bin++, "VR SS B jet veto"  );
      axis->SetBinLabel(bin++, "VR SS F jet veto"  );
      axis->SetBinLabel(bin++, "VR SS b-tag weight");
      axis->SetBinLabel(bin++, "VR SS Z veto (ee)" );
      axis->SetBinLabel(bin++, "VR SS met-rel"     );
      axis->SetBinLabel(bin++, "VR SS mt"          );
      axis->SetBinLabel(bin++, "BREAK"                 );

      axis->SetBinLabel(bin++, "VR SS CF cand"     );
      axis->SetBinLabel(bin++, "VR SS CF weight"   );
      axis->SetBinLabel(bin++, "VR SS >= 1 L jet"  );
      axis->SetBinLabel(bin++, "VR SS B jet veto"  );
      axis->SetBinLabel(bin++, "VR SS F jet veto"  );
      axis->SetBinLabel(bin++, "VR SS b-tag weight");
      axis->SetBinLabel(bin++, "VR SS Z veto (ee)" );
      axis->SetBinLabel(bin++, "VR SS met-rel"     );
      axis->SetBinLabel(bin++, "VR SS mt"          );
      axis->SetBinLabel(bin++, "BREAK"             );

      // axis->SetBinLabel(bin++, "CR ZX Z window");
      // axis->SetBinLabel(bin++, "CR ZXosjveto jet veto");
      // axis->SetBinLabel(bin++, "CR ZXosjveto met-rel");
      // axis->SetBinLabel(bin++, "CR ZXmt2 jet veto");
      // axis->SetBinLabel(bin++, "CR ZXmt2 met-rel");
      // axis->SetBinLabel(bin++, "CR ZXmt2a mt2");
      // axis->SetBinLabel(bin++, "CR ZXmt2b mt2");
      // axis->SetBinLabel(bin++, "CR ZX2jets >- 2 L jets");
      // axis->SetBinLabel(bin++, "CR ZX2jets b jet veto");
      // axis->SetBinLabel(bin++, "CR ZX2jets b-tag weight");
      // axis->SetBinLabel(bin++, "CR ZX2jets f jet veto");
      // axis->SetBinLabel(bin++, "CR ZX2jets top tag veto");
      // axis->SetBinLabel(bin++, "CR ZX2jets met-rel");
      // axis->SetBinLabel(bin++, "CR ZX2jets mt2");
      // axis->SetBinLabel(bin++, "CR ZXWW jet feto");
      // axis->SetBinLabel(bin++, "CR ZXWW met-rel");
      // axis->SetBinLabel(bin++, "CR ZXWW mt2");

      // axis->SetBinLabel(bin++, "CR top z veto");
      // axis->SetBinLabel(bin++, "CR top met-rel");
      // axis->SetBinLabel(bin++, "CR top num central jets");
      // axis->SetBinLabel(bin++, "CR top num b jets");

      // axis->SetBinLabel(bin++, "CR topWW pt l1");
      // axis->SetBinLabel(bin++, "CR topWW pt l2");
      // axis->SetBinLabel(bin++, "CR topWW num b jets");
      // axis->SetBinLabel(bin++, "CR topWWa ");
      // axis->SetBinLabel(bin++, "CR topWWa ");
      // axis->SetBinLabel(bin++, "CR topWWa ");
      // axis->SetBinLabel(bin++, "CR topWWb ");
      // axis->SetBinLabel(bin++, "CR topWWb ");
      // axis->SetBinLabel(bin++, "CR topWWb ");
      // axis->SetBinLabel(bin++, "CR topWWc ");
      // axis->SetBinLabel(bin++, "CR topWWc ");
      // axis->SetBinLabel(bin++, "CR topWWc ");

      // axis->SetBinLabel(bin++, "CR WW12 ");

      // axis->SetBinLabel(bin++, "CR WWabc ");

      // axis->SetBinLabel(bin++, "CR btag");

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
  if (evt_desc.getTruthPrompt())
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

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
  bin_num++;

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
  bin_num++;

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

  // srssjets cf cand
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // // SRSSJetsCF apply cf weght
  // if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_CF)
  //   weight *= m_cf_weight;
  if (pass_sr_ssjetscf)
    fillHist(phase, weight_type, bin_num, weight);
  bin_num++;

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
  bin_num++;

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
  bin_num++;

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
  bin_num++;

  // SRMT2 Z veto
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
  bin_num++;

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
  bin_num++;

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

  // srssjets cf cand
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // // VRSSCF apply cf weght
  // if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_CF)
  //   weight *= m_cf_weight;
  if (pass_vr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  bin_num++;

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
  bin_num++;

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
