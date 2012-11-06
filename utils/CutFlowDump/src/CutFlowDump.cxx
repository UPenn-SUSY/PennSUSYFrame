#include <iostream>
#include "include/CutFlowDump.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

CutFlowDump::CutFlowDump(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("SusyDiLeptonCutFlowCycle.MC.egamma.2012_10_15.1.ttbar_small_cutflow_challenge.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("SusyDiLeptonCutFlowCycle.MC.egamma.2012_10_15.1.ttbar_small_cutflow_challenge.root");
      }
      f->GetObject("output",tree);

   }
   Init(tree);

   initCutFlowHists();
}

CutFlowDump::~CutFlowDump()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CutFlowDump::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CutFlowDump::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void CutFlowDump::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run_number"  , &m_run_number  , &b_run_number);
   fChain->SetBranchAddress("event_number", &m_event_number, &b_event_number);
   fChain->SetBranchAddress("event_desc"  , &m_event_desc  , &b_event_desc);
   Notify();
}

Bool_t CutFlowDump::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CutFlowDump::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}

Int_t CutFlowDump::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
void CutFlowDump::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      for ( PHASE_SPACE phase_it = PHASE_NONE
          ; phase_it != PHASE_N
          ; phase_it = static_cast<PHASE_SPACE>(phase_it + 1)
          ) {
        checkEvent(phase_it);
      }
   }
}

// -----------------------------------------------------------------------------
void CutFlowDump::initCutFlowHists()
{
  m_cutflow.resize(PHASE_N);

  for ( PHASE_SPACE phase_it = PHASE_NONE
      ; phase_it != PHASE_N
      ; phase_it = static_cast<PHASE_SPACE>(phase_it + 1)
      ) {
    std::string name = "cutflow_";
    if (phase_it == PHASE_NONE) name = name + "none";
    else if (phase_it == PHASE_EE)   name = name + "ee";
    else if (phase_it == PHASE_MM)   name = name + "mm";
    else if (phase_it == PHASE_EM)   name = name + "em";
    else if (phase_it == PHASE_ME)   name = name + "me";
    else continue;

    std::string title = name;

    m_cutflow.at(phase_it) = new TH1D( name.c_str()
                                     , title.c_str()
                                     , 40, -0.5, 39.5
                                     );

    unsigned int bin = 1;
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "ALL"              );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "GRL"              );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Incomplete event" );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "LAr error"        );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Tile error"       );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Tile hot spot"    );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Jet cleaning"     );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Primary vertex"   );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Bad mu veto"      );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Cosmic mu veto"   );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "HFOR"             );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, ">= 2 good lep"    );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "== 2 good lep="   );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "mll"              );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "== 2 signal lep"  );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Flavor"           );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Phase space"      );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Trigger"          );
    m_cutflow.at(phase_it)->GetXaxis()->SetBinLabel(bin++, "Trigger matching" );
  }
}

// -----------------------------------------------------------------------------
void CutFlowDump::checkEvent(PHASE_SPACE phase)
{
  if (  phase != PHASE_EE
     && phase != PHASE_MM
     && phase != PHASE_EM
     && phase != PHASE_ME
     ) {
    return;
  }

  SusyAnalysisTools::EventDescription evt_desc = m_event_desc;
  unsigned int bin_num = 0;

  // All events
  fillHist(phase, bin_num++);

  // GRL
  if (evt_desc.getPassGrl() == false) return;
  fillHist(phase, bin_num++);

  // incomplete event
  if (evt_desc.getPassIncompleteEVent() == false) return;
  fillHist(phase, bin_num++);

  // lar error
  if (evt_desc.getPassLarError() == false) return;
  fillHist(phase, bin_num++);

  // tile error
  if (evt_desc.getPassTileError() == false) return;
  fillHist(phase, bin_num++);

  // tile hot spot
  if (evt_desc.getPassTileHotSpot() == false) return;
  fillHist(phase, bin_num++);

  // bad jets
  if (evt_desc.getPassBadJets() == false) return;
  fillHist(phase, bin_num++);

  // primary vertex
  if (evt_desc.getPassPrimaryVertex() == false) return;
  fillHist(phase, bin_num++);

  // bad muons
  if (evt_desc.getPassBadMuons() == false) return;
  fillHist(phase, bin_num++);

  // cosmic muons
  if (evt_desc.getPassCosmicMuons() == false) return;
  fillHist(phase, bin_num++);

  // HFOR
  if (evt_desc.getPassHFOR() == false) return;
  fillHist(phase, bin_num++);

  // >= 2 good leptons
  if (evt_desc.getPassGE2GoodLeptons() == false) return;
  fillHist(phase, bin_num++);

  // == 2 good leptons
  if (evt_desc.getPass2GoodLeptons() == false) return;
  fillHist(phase, bin_num++);

  // mll
  if (evt_desc.getPassMll() == false) return;
  fillHist(phase, bin_num++);

  // 2 signal leptons
  if (evt_desc.getPass2SignalLeptons() == false) return;
  fillHist(phase, bin_num++);

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
  fillHist(phase, bin_num++);

  // phase space selection
  if (evt_desc.getPhaseSpace() != phase) return;
  fillHist(phase, bin_num++);

  // Trigger
  bool pass_trigger = false;
  if (phase == PHASE_EE && evt_desc.isEETrigger()) pass_trigger = true;
  if (phase == PHASE_MM && evt_desc.isMMTrigger()) pass_trigger = true;
  if (phase == PHASE_EM && evt_desc.isEMTrigger()) pass_trigger = true;
  if (phase == PHASE_ME && evt_desc.isMETrigger()) pass_trigger = true;
  if (pass_trigger == false) return;
  fillHist(phase, bin_num++);

  // Trigger matching
  if (evt_desc.getPassTriggerMatch() == false) return;
  fillHist(phase, bin_num++);

  // FLAVOR_CHANNEL  getFlavorChannel()
  // PHASE_SPACE     getPhaseSpace()
  // SIGN_CHANNEL    getSignChannel()

}

// -----------------------------------------------------------------------------
void CutFlowDump::fillHist( PHASE_SPACE phase
                          , unsigned int cut_bin
                          , double weight
                          )
{
  m_cutflow.at(phase)->Fill(cut_bin, weight);
}

// -----------------------------------------------------------------------------
void CutFlowDump::printToFile(std::string out_file_name)
{
   std::cout << "Writing cut flow histograms to file: "
             << out_file_name << "\n";

   TFile* f = new TFile(out_file_name.c_str(), "RECREATE");

   m_cutflow.at(PHASE_NONE)->Write();
   m_cutflow.at(PHASE_EE)->Write();
   m_cutflow.at(PHASE_MM)->Write();
   m_cutflow.at(PHASE_EM)->Write();
   m_cutflow.at(PHASE_ME)->Write();

   f->Write();
   f->Close();
   delete f;
}
