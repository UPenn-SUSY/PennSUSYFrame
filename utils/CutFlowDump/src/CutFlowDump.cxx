#include <iostream>
#include <iomanip>
#include "include/CutFlowDump.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

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
          , 50, -0.5, 49.5
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

      axis->SetBinLabel(bin++, "SR1 jet veto"    );
      axis->SetBinLabel(bin++, "SR1 b-tag weight");
      axis->SetBinLabel(bin++, "SR1 Z veto"      );
      axis->SetBinLabel(bin++, "SR1 met-rel"     );

      axis->SetBinLabel(bin++, "SR2 jet veto"    );
      axis->SetBinLabel(bin++, "SR2 b-tag weight");
      axis->SetBinLabel(bin++, "SR2 Z veto"      );
      axis->SetBinLabel(bin++, "SR2 met-rel"     );

      axis->SetBinLabel(bin++, "SR3 SF"          );
      axis->SetBinLabel(bin++, "SR3 2-light jets");
      axis->SetBinLabel(bin++, "SR3 Z veto"      );
      axis->SetBinLabel(bin++, "SR3 b jet veto"  );
      axis->SetBinLabel(bin++, "SR3 b-tag weight");
      axis->SetBinLabel(bin++, "SR3 f jet feto"  );
      axis->SetBinLabel(bin++, "SR3 top tag veto");
      axis->SetBinLabel(bin++, "SR3 met-rel"     );

      axis->SetBinLabel(bin++, "SR4 jet veto"    );
      axis->SetBinLabel(bin++, "SR4 b-tag weight");
      axis->SetBinLabel(bin++, "SR4 Z veto"      );
      axis->SetBinLabel(bin++, "SR4 met-rel"     );
      axis->SetBinLabel(bin++, "SR4a mt2"        );
      axis->SetBinLabel(bin++, "SR4b mt2"        );
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
  if (evt_desc.getPassIncompleteEVent() == false) return;
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
  // SR1
  weight = basic_weight;
  bool pass_sr1 = (evt_desc.getSignChannel() == SIGN_OS);

  // SR1 jet veto
  pass_sr1 = (pass_sr1 && pass_total_jet_veto);
  if (pass_sr1)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR1 apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr1)
    fillHist(phase, weight_type, bin_num, weight);
  bin_num++;

  // SR1 Z veto
  pass_sr1 = (pass_sr1 && pass_z_veto);
  if (pass_sr1)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR1 met-rel
  pass_sr1 = (pass_sr1 && sr_helper.getPassSR1MetRel());
  if (pass_sr1)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SR2
  weight = basic_weight;
  bool pass_sr2 = (evt_desc.getSignChannel() == SIGN_SS);

  // SR2 jet veto
  pass_sr2 = (pass_sr2 && pass_total_jet_veto);
  if (pass_sr2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR2 apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr2)
    fillHist(phase, weight_type, bin_num, weight);
  bin_num++;

  // SR2 Z veto
  pass_sr2 = (pass_sr2 && pass_z_veto);
  if (pass_sr2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR2 met-rel
  pass_sr2 = (pass_sr2 && sr_helper.getPassSR2MetRel());
  if (pass_sr2)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SR3
  weight = basic_weight;
  bool pass_sr3 = (evt_desc.getSignChannel() == SIGN_OS);

  // SR3 same flavor
  bool is_sf = (  evt_desc.getFlavorChannel() == FLAVOR_EE
               || evt_desc.getFlavorChannel() == FLAVOR_MM
               || true
               );
  pass_sr3 = (pass_sr3 && is_sf);
  if (pass_sr3)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR3 2 light jets
  pass_sr3 = (pass_sr3 && sr_helper.getPassSR32LJet());
  if (pass_sr3)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR3 Z veto
  pass_sr3 = (pass_sr3 && pass_z_veto);
  if (pass_sr3)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR3 b jet veto
  pass_sr3 = (pass_sr3 && pass_b_jet_veto);
  if (pass_sr3)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR3 apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr3)
    fillHist(phase, weight_type, bin_num, weight);
  bin_num++;

  // SR3 forward jet veto
  pass_sr3 = (pass_sr3 && pass_f_jet_veto);
  if (pass_sr3)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR3 top tag veto
  pass_sr3 = (pass_sr3 && sr_helper.getPassTopVeto());
  if (pass_sr3)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR3 met-rel
  pass_sr3 = (pass_sr3 && sr_helper.getPassSR3MetRel());
  if (pass_sr3)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SR4
  weight = basic_weight;
  bool pass_sr4 = (evt_desc.getSignChannel() == SIGN_OS);

  // SR4 jet veto
  pass_sr4 = (pass_sr4 && pass_total_jet_veto);
  if (pass_sr4)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR4 apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr4)
    fillHist(phase, weight_type, bin_num, weight);
  bin_num++;

  // SR4 Z veto
  pass_sr4 = (pass_sr4 && pass_z_veto);
  if (pass_sr4)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR4 met-rel
  pass_sr4 = (pass_sr4 && sr_helper.getPassSR4MetRel());
  if (pass_sr4)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR4a MT2 cut
  pass_sr4 = (pass_sr4 && sr_helper.getPassSR4aMt2());
  if (pass_sr4)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR4b MT2 cut
  pass_sr4 = (pass_sr4 && sr_helper.getPassSR4bMt2());
  if (pass_sr4)
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
  unsigned int line_width   = 80;
  unsigned int label_field  = 20;
  unsigned int weight_field = (line_width - label_field - 4 - 4*3 )/4;

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

    std::cout << "= "  << std::left  << std::setw(label_field)  << cut_name
              << " = " << std::right << std::setw(weight_field) << weight_ee
              << " = " << std::right << std::setw(weight_field) << weight_mm
              << " = " << std::right << std::setw(weight_field) << weight_em
              << " = " << std::right << std::setw(weight_field) << weight_me
              << " =\n";
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
