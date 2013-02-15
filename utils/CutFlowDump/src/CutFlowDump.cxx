#include "CutFlowDump/include/CutFlowDump.h"

#include <iostream>
#include <iomanip>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>

#include "NtupleLooper/include/NtupleLooper.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// -----------------------------------------------------------------------------
CutFlowDump::CutFlowDump(TTree *tree) : NtupleLooper(tree)
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
          , 80, -0.5, 79.5
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
      axis->SetBinLabel(bin++, "SR 2Jets f jet feto"  );
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
  // TODO - currently pass through. handle properly with channel
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
                             && evt_desc.getTruthSignChannel() == SIGN_OS
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
  // TODO - currently pass through. handle properly with channel
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
      std::cout << "= "  << std::left  << std::setw(label_field)  << cut_name
                << " = " << std::right << std::setw(weight_field) << weight_ee
                << " = " << std::right << std::setw(weight_field) << weight_mm
                << " = " << std::right << std::setw(weight_field) << weight_em
                << " = " << std::right << std::setw(weight_field) << weight_me
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
