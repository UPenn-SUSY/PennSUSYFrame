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
                        , double num_events) : NtupleHelper::NtupleLooper(tree, num_events)
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

  // apply trigger weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_TRIGGER)
    weight *= m_trigger_weight;
  fillHist(phase, weight_type, bin_num++, weight);

  // signal tau veto
  if (evt_desc.getPassTauVeto() == false) return;
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SR SS
  ++bin_num;
  weight = basic_weight;
  bool pass_sr_ss = (evt_desc.getSignChannel() == SIGN_SS);

  // SR SS truth SS
  pass_sr_ss = (pass_sr_ss && evt_desc.getTruthSignChannel() == SIGN_SS);
  if (pass_sr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SS emma mT
  pass_sr_ss = (pass_sr_ss && sr_helper.getPassSRSSEmmaMt());
  if (pass_sr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SS met-rel
  pass_sr_ss = (pass_sr_ss && sr_helper.getPassSRSSMetRel());
  if (pass_sr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // // SR SS mll veto
  // pass_sr_ss = (pass_sr_ss && sr_helper.getPassSRSSMllVeto());
  // if (pass_sr_ss)
  //   fillHist(phase, weight_type, bin_num, weight);
  // ++bin_num;

  // SR SS dphi_ll
  pass_sr_ss = (pass_sr_ss && sr_helper.getPassSRSSDphill());
  if (pass_sr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SS F jet veto
  // pass_sr_ss = (pass_sr_ss && pass_f_jet_veto);
  pass_sr_ss = (pass_sr_ss && true);
  if (pass_sr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SS B jet veto
  pass_sr_ss = (pass_sr_ss && pass_b_jet_veto);
  if (pass_sr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SS apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SS >= 1 L jet
  pass_sr_ss = (pass_sr_ss && sr_helper.getPassSRSSNumLJets());
  if (pass_sr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SS Z veto
  if (phase == PHASE_EE)
    pass_sr_ss = (pass_sr_ss && pass_z_veto);
  if (pass_sr_ss)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // SR SSCF
  ++bin_num;
  weight = basic_weight;
  bool pass_sr_sscf = (evt_desc.getSignChannel() == SIGN_OS);

  // // SR SSCF truth OS
  // pass_sr_sscf = (pass_sr_sscf && evt_desc.getTruthSignChannel() == SIGN_OS);
  // if (pass_sr_sscf)
  //   fillHist(phase, weight_type, bin_num, weight);
  // ++bin_num;

  // SR SSCF apply cf weght
  // if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_CF)
  //   weight *= m_cf_weight;
  if (pass_sr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;


  // SR SSCF emma mT
  pass_sr_sscf = (pass_sr_sscf && sr_helper.getPassSRSSEmmaMt());
  if (pass_sr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SSCF met-rel
  pass_sr_sscf = (pass_sr_sscf && sr_helper.getPassSRSSMetRel());
  if (pass_sr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // // SR SSCF mll veto
  // pass_sr_sscf = (pass_sr_sscf && sr_helper.getPassSRSSMllVeto());
  // if (pass_sr_sscf)
  //   fillHist(phase, weight_type, bin_num, weight);
  // ++bin_num;

  // SR SSCF dphi_ll
  pass_sr_sscf = (pass_sr_sscf && true);
  if (pass_sr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SSCF F jet veto
  pass_sr_sscf = (pass_sr_sscf && pass_f_jet_veto);
  if (pass_sr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SSCF B jet veto
  pass_sr_sscf = (pass_sr_sscf && pass_b_jet_veto);
  if (pass_sr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SSCF apply b-tag weight
  if (weight_type == WEIGHT_ALL || weight_type == WEIGHT_B_TAG)
    weight *= m_b_tag_weight;
  if (pass_sr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SSCF >= 1 L jet
  pass_sr_sscf = (pass_sr_sscf && !pass_l_jet_veto);
  if (pass_sr_sscf)
    fillHist(phase, weight_type, bin_num, weight);
  ++bin_num;

  // SR SSCF Z veto
  if (phase == PHASE_EE)
    pass_sr_sscf = (pass_sr_sscf && pass_z_veto);
  if (pass_sr_sscf)
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
  m_bin_list.push_back("Phase space");
  m_bin_list.push_back("Trigger");
  m_bin_list.push_back("Trigger matching");
  m_bin_list.push_back("Trigger weight");
  m_bin_list.push_back("Tau veto");
  m_bin_list.push_back("Prompt leptons");
  m_bin_list.push_back("Opposite sign");
  m_bin_list.push_back("Same sign");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("SR SS truth SS");
  m_bin_list.push_back("SR SS emma_mt");
  m_bin_list.push_back("SR SS met-rel");
  m_bin_list.push_back("SR SS dphi_ll");
  m_bin_list.push_back("SR SS F jet veto");
  m_bin_list.push_back("SR SS B jet veto");
  m_bin_list.push_back("SR SS b-tag weight");
  m_bin_list.push_back("SR SS L jets");
  m_bin_list.push_back("SR SS Z veto");
  m_bin_list.push_back("BREAK");

  m_bin_list.push_back("SR SSCF CF weight");
  m_bin_list.push_back("SR SSCF emma_mt");
  m_bin_list.push_back("SR SSCF met-rel");
  m_bin_list.push_back("SR SSCF dphi_ll");
  m_bin_list.push_back("SR SSCF F jet veto");
  m_bin_list.push_back("SR SSCF B jet veto");
  m_bin_list.push_back("SR SSCF b-tag weight");
  m_bin_list.push_back("SR SSCF L jets");
  m_bin_list.push_back("SR SSCF Z veto");
  m_bin_list.push_back("BREAK");
}
