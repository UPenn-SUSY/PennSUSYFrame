#include "ChannelFractions/include/ChannelFractions.h"

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
ChannelFractions::ChannelFractions( TTree *tree
                        , double num_events) : NtupleHelper::NtupleLooper(tree, num_events)
                                             , m_num_total(0.)
                                             , m_num_eee(0.)
                                             , m_num_eem(0.)
                                             , m_num_emm(0.)
                                             , m_num_mmm(0.)
                                             , m_num_ee_os(0.)
                                             , m_num_em_os(0.)
                                             , m_num_mm_os(0.)
                                             , m_num_ee_ss(0.)
                                             , m_num_em_ss(0.)
                                             , m_num_mm_ss(0.)
{
  // do nothing
}

// -----------------------------------------------------------------------------
ChannelFractions::~ChannelFractions()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void ChannelFractions::processEvent()
{
  SusyAnalysisTools::EventDescription evt_desc  = m_event_desc;
  double weight = 1.;

  // No matter what, we want to increment the total number of events
  ++m_num_total;


  // apply mc event weight
  weight *= m_mc_event_weight;

  // GRL
  if (evt_desc.getPassGrl() == false) return;

  // incomplete event
  if (evt_desc.getPassIncompleteEvent() == false) return;

  // lar error
  if (evt_desc.getPassLarError() == false) return;

  // tile error
  if (evt_desc.getPassTileError() == false) return;

  // tile hot spot
  if (evt_desc.getPassTileHotSpot() == false) return;

  // tile trip
  if (evt_desc.getPassTileTrip() == false) return;

  // bad jets
  if (evt_desc.getPassBadJets() == false) return;

  // calo problem jets
  if (evt_desc.getPassCaloProblemJets() == false) return;

  // primary vertex
  if (evt_desc.getPassPrimaryVertex() == false) return;

  // bad muons
  if (evt_desc.getPassBadMuons() == false) return;

  // cosmic muons
  if (evt_desc.getPassCosmicMuons() == false) return;

  // HFOR
  if (evt_desc.getPassHFOR() == false) return;

  // >= 2 good leptons
  if (evt_desc.getPassGE2GoodLeptons() == false) return;

  // == 2 good leptons
  if (evt_desc.getPass2GoodLeptons() == false) return;

  // mll
  if (evt_desc.getPassMll() == false) return;

  // 2 signal leptons
  if (evt_desc.getPass2SignalLeptons() == false) return;

  // // flavor selection
  // bool pass_flavor = false;
  // if (phase == PHASE_EE && evt_desc.getFlavorChannel() == FLAVOR_EE)
  //   pass_flavor = true;
  // if (phase == PHASE_MM && evt_desc.getFlavorChannel() == FLAVOR_MM)
  //   pass_flavor = true;
  // if (phase == PHASE_EM && evt_desc.getFlavorChannel() == FLAVOR_EM)
  //   pass_flavor = true;
  // if (phase == PHASE_ME && evt_desc.getFlavorChannel() == FLAVOR_EM)
  //   pass_flavor = true;
  //
  // if (pass_flavor == false) return;
  // fillHist(phase, weight_type, bin_num++, weight);

  // // apply lepton weight
  // weight *= m_lepton_weight;

  // // apply trigger weight
  // weight *= m_trigger_weight;

  // // phase space selection
  // if (evt_desc.getPhaseSpace() != phase) return;
  // fillHist(phase, weight_type, bin_num++, weight);

  // // Trigger
  // bool pass_trigger = false;
  // if (phase == PHASE_EE && evt_desc.isEETrigger()) pass_trigger = true;
  // if (phase == PHASE_MM && evt_desc.isMMTrigger()) pass_trigger = true;
  // if (phase == PHASE_EM && evt_desc.isEMTrigger()) pass_trigger = true;
  // if (phase == PHASE_ME && evt_desc.isMETrigger()) pass_trigger = true;
  // if (pass_trigger == false) return;
  // fillHist(phase, weight_type, bin_num++, weight);

  // // Trigger matching
  // if (evt_desc.getPassTriggerMatch() == false) return;

  // // Flag prompt lepton events
  // if (evt_desc.getTruthPrompt())
  //   fillHist(phase, weight_type, bin_num, weight);
  // ++bin_num;

  // // Flag OS events
  // if (evt_desc.getSignChannel() == SIGN_OS)
  //   fillHist(phase, weight_type, bin_num, weight);

  // // Flag SS events
  // if (evt_desc.getSignChannel() == SIGN_SS)
  //   fillHist(phase, weight_type, bin_num, weight);
}

// -----------------------------------------------------------------------------
void ChannelFractions::printToScreen()
{
  unsigned int line_width   = 100;
  unsigned int label_field  = 30;
  unsigned int weight_field = (line_width - label_field - 4 - 2*3 )/2;
  unsigned int precision    = weight_field-2;
  if (4+label_field+2*weight_field != line_width) {
    label_field += (line_width - label_field - 4 - 2*3 )%2;
  }
  std::string break_label = "";
  std::string break_weight = "";
  for (unsigned int i = 0; i != label_field ; ++i) break_label  += "-";
  for (unsigned int i = 0; i != weight_field; ++i) break_weight += "-";

  std::string single_line;
  for (unsigned int i = 0; i != line_width; ++i) single_line += '=';
  single_line = single_line + "\n";

  std::cout << '\n' << single_line;
  std::cout << "= "   << std::left  << std::setw(label_field)  << "Channel"
            << " = "  << std::right << std::setw(weight_field) << "Generated"
            << " = "  << std::right << std::setw(weight_field) << "Fraction"
            << " =\n";
  std::cout << single_line;
  printLine("Total", m_num_total, label_field, weight_field, precision);
  printLine("eee", m_num_eee, label_field, weight_field, precision);
  printLine("eem", m_num_eem, label_field, weight_field, precision);
  printLine("emm", m_num_emm, label_field, weight_field, precision);
  printLine("mmm", m_num_mmm, label_field, weight_field, precision);
  printLine("ee - SS", m_num_ee_ss, label_field, weight_field, precision);
  printLine("em - SS", m_num_em_ss, label_field, weight_field, precision);
  printLine("mm - SS", m_num_mm_ss, label_field, weight_field, precision);
  printLine("ee - OS", m_num_ee_os, label_field, weight_field, precision);
  printLine("em - OS", m_num_em_os, label_field, weight_field, precision);
  printLine("mm - OS", m_num_mm_os, label_field, weight_field, precision);
  std::cout << single_line;

}

// -----------------------------------------------------------------------------
void ChannelFractions::printToFile(std::string out_file_name)
{
  // do nothing
}

// -----------------------------------------------------------------------------
double ChannelFractions::getFraction(double numerator)
{
  if (m_num_total == 0) return -1.;
  return numerator/m_num_total;
}

// -----------------------------------------------------------------------------
void ChannelFractions::printLine( std::string channel
                                , double num_entries
                                , unsigned int label_field
                                , unsigned int weight_field
                                , unsigned int precision
                                )
{
  std::cout << "= "  << std::left  << std::setw(label_field)   << channel
            << " = "  << std::right << std::setw(weight_field) << num_entries
            << " = "  << std::right << std::setw(weight_field) 
            << std::setprecision(precision) << getFraction(m_num_total)
            << " =\n";
}
