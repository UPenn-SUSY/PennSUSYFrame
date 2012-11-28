#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "include/HistMaker.h"
#include "Selection/include/EventSelection.h"

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  TFile* f = new TFile(argv[1]);
  TTree* t = static_cast<TTree*>(f->Get("output"));

  HistMaker hm(t, "test_hists.root");

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection ee_sig_lep;
  ee_sig_lep.getPassEventWord()->setPassGrl(true);
  ee_sig_lep.getPassEventWord()->setPassIncompleteEvent(true);
  ee_sig_lep.getPassEventWord()->setPassLarError(true);
  ee_sig_lep.getPassEventWord()->setPassTileError(true);
  ee_sig_lep.getPassEventWord()->setPassTileHotSpot(true);
  ee_sig_lep.getPassEventWord()->setPassBadJets(true);
  ee_sig_lep.getPassEventWord()->setPassPrimaryVertex(true);
  ee_sig_lep.getPassEventWord()->setPassBadMuons(true);
  ee_sig_lep.getPassEventWord()->setPassCosmicMuons(true);
  ee_sig_lep.getPassEventWord()->setPassHFOR(true);
  ee_sig_lep.getPassEventWord()->setPassGE2GoodLeptons(true);
  ee_sig_lep.getPassEventWord()->setPass2GoodLeptons(true);
  ee_sig_lep.getPassEventWord()->setPassMll(true);
  ee_sig_lep.getPassEventWord()->setPass2SignalLeptons(true);
  ee_sig_lep.getPassEventWord()->setPassTriggerMatch(true);
  ee_sig_lep.getPassEventWord()->setFlavorChannel(FLAVOR_EE);
  ee_sig_lep.getPassEventWord()->setEETrigger(true);

  hm.addCut("ee_signal", ee_sig_lep);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection mm_sig_lep;
  mm_sig_lep.getPassEventWord()->setPassGrl(true);
  mm_sig_lep.getPassEventWord()->setPassIncompleteEvent(true);
  mm_sig_lep.getPassEventWord()->setPassLarError(true);
  mm_sig_lep.getPassEventWord()->setPassTileError(true);
  mm_sig_lep.getPassEventWord()->setPassTileHotSpot(true);
  mm_sig_lep.getPassEventWord()->setPassBadJets(true);
  mm_sig_lep.getPassEventWord()->setPassPrimaryVertex(true);
  mm_sig_lep.getPassEventWord()->setPassBadMuons(true);
  mm_sig_lep.getPassEventWord()->setPassCosmicMuons(true);
  mm_sig_lep.getPassEventWord()->setPassHFOR(true);
  mm_sig_lep.getPassEventWord()->setPassGE2GoodLeptons(true);
  mm_sig_lep.getPassEventWord()->setPass2GoodLeptons(true);
  mm_sig_lep.getPassEventWord()->setPassMll(true);
  mm_sig_lep.getPassEventWord()->setPass2SignalLeptons(true);
  mm_sig_lep.getPassEventWord()->setPassTriggerMatch(true);
  mm_sig_lep.getPassEventWord()->setFlavorChannel(FLAVOR_MM);
  mm_sig_lep.getPassEventWord()->setMMTrigger(true);

  hm.addCut("mm_signal", mm_sig_lep);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection em_sig_lep;
  em_sig_lep.getPassEventWord()->setPassGrl(true);
  em_sig_lep.getPassEventWord()->setPassIncompleteEvent(true);
  em_sig_lep.getPassEventWord()->setPassLarError(true);
  em_sig_lep.getPassEventWord()->setPassTileError(true);
  em_sig_lep.getPassEventWord()->setPassTileHotSpot(true);
  em_sig_lep.getPassEventWord()->setPassBadJets(true);
  em_sig_lep.getPassEventWord()->setPassPrimaryVertex(true);
  em_sig_lep.getPassEventWord()->setPassBadMuons(true);
  em_sig_lep.getPassEventWord()->setPassCosmicMuons(true);
  em_sig_lep.getPassEventWord()->setPassHFOR(true);
  em_sig_lep.getPassEventWord()->setPassGE2GoodLeptons(true);
  em_sig_lep.getPassEventWord()->setPass2GoodLeptons(true);
  em_sig_lep.getPassEventWord()->setPassMll(true);
  em_sig_lep.getPassEventWord()->setPass2SignalLeptons(true);
  em_sig_lep.getPassEventWord()->setPassTriggerMatch(true);
  em_sig_lep.getPassEventWord()->setFlavorChannel(FLAVOR_EM);
  em_sig_lep.getPassEventWord()->setEMTrigger(true);

  hm.addCut("em_signal", em_sig_lep);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  hm.init();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  hm.Loop();
  hm.writeToFile();

  delete f;
}
