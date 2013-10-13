#include "EventNumberDump/include/EventNumberDump.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

#include <TROOT.h>
#include <TCut.h>
#include <TChain.h>
#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

#include "NtupleLooper/include/NtupleLooper.h"

#include "Selection/include/EventSelection.h"
// #include "Selection/include/WeightHandler.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// -----------------------------------------------------------------------------
EventNumberDump::EventNumberDump( TTree *tree
                                , double num_events
                                , std::string out_file_name
                                )
                                : NtupleHelper::NtupleLooper(tree, num_events)
                                , m_out_file(NULL)
                                , m_entry_num(0)
{
  // m_out_file = new TFile(out_file_name.c_str(), "recreate");
}

// -----------------------------------------------------------------------------
EventNumberDump::~EventNumberDump()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void EventNumberDump::addCut( std::string key
                            , Selection::EventSelection& selecton
                            )
{
  std::cout << "adding cut: " << key << "\n";

  m_keys.push_back(key);
  m_selection[key] = selecton;
}

// -----------------------------------------------------------------------------
void EventNumberDump::Loop()
{
  std::vector<std::string>::iterator key_it = m_keys.begin();
  std::vector<std::string>::iterator key_term = m_keys.end();
  for (; key_it != key_term; ++key_it) {
    filterTree(*key_it);
  }
}

// -----------------------------------------------------------------------------
void EventNumberDump::processEvent()
{
  // do nothing
}

// // -----------------------------------------------------------------------------
// void EventNumberDump::writeToFile()
// {
//   // loop though cut directories
//   std::vector<std::string>::iterator key_it = m_keys.begin();
//   std::vector<std::string>::iterator key_term = m_keys.end();
//   for (; key_it != key_term; ++key_it) {
//     m_out_file->cd();
//     // TDirectory* d = m_out_file->GetDirectory((*key_it).c_str());
//     // if (d == NULL) d = m_out_file->mkdir((*key_it).c_str());
//     //
//     // d->cd();
//   }
// }
// 
// // -----------------------------------------------------------------------------
// void EventNumberDump::writeToFile(std::string key, TTree* tree_to_write)
// {
//   m_out_file->cd();
//   tree_to_write->Write(key.c_str());
// }

// -----------------------------------------------------------------------------
void EventNumberDump::filterTree(std::string key)
{
  // get the selection cuts for this event
  ull_t pass_event = m_selection[key].getPassEventWord()->toInt();
  ull_t pass_sr    = m_selection[key].getPassSRWord()->toInt();

  std::stringstream ss_pass_event;
  ss_pass_event << "((event_desc & " << pass_event
                << ") == " << pass_event << ") ";
  TCut cut_pass_event = ss_pass_event.str().c_str();

  std::stringstream ss_pass_sr;
  ss_pass_sr << "((sr_helper & " << pass_sr
             << ") == " << pass_sr << ") ";
  TCut cut_pass_sr = ss_pass_sr.str().c_str();

  TCut additional_cuts = m_selection[key].getAdditionalCutString().c_str();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  TCut full_selection = (  cut_pass_event
                        && cut_pass_sr
                        && additional_cuts
                        );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Copy fChain into temp tree with selection applied
  TTree* tmp_tree = fChain->CopyTree(full_selection);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Loop over tmp_tree and print the run and event numbers
  UInt_t run_number   = 0;
  UInt_t event_number = 0;

  tmp_tree->SetBranchAddress("run_number"  , &run_number);
  tmp_tree->SetBranchAddress("event_number", &event_number);

  std::string f_name_event_list = "event_list.";
  f_name_event_list += key;
  f_name_event_list += ".dat";

  std::ofstream f_event_list;
  f_event_list.open(f_name_event_list.c_str());

  ull_t num_entries = tmp_tree->GetEntries();
  for (ull_t entry = 0; entry != num_entries; ++entry) {
    tmp_tree->GetEntry(entry);
    f_event_list << run_number << "\t" << event_number << "\n";
  }
  f_event_list.close();
}
