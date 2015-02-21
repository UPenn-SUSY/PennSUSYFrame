#include "TFile.h"
#include "TChain.h"
#include <vector>
#include <iostream>
#include "TLorentzVector.h"
#include <cmath>
#include "TH1D.h"
#include "TRandom.h"
#include "TObject.h"
#include "TCanvas.h"

// aset = "WW_emu" or "WZ_emumu" or "ZZ_eemumu"
int main(int argc, char *argv[]){

  std::cout << "Making histograms..." << std::endl;
  TH1D * h_SR_400   = new TH1D("hist_SR_400","hist_SR_400",1,-1,1);
  TH1D * h_SR_600   = new TH1D("hist_SR_600","hist_SR_600",1,-1,1);
  TH1D * h_CR_TOP   = new TH1D("hist_CR_TOP","hist_CR_TOP",1,-1,1);
  TH1D * h_CR_Z     = new TH1D("hist_CR_Z","hist_CR_Z",1,-1,1);
  TH1D * h_VR_TOP_1 = new TH1D("hist_VR_TOP_1","hist_VR_TOP_1",1,-1,1);
  TH1D * h_VR_TOP_2 = new TH1D("hist_VR_TOP_2","hist_VR_TOP_2",1,-1,1);
  TH1D * h_VR_TOP_3 = new TH1D("hist_VR_TOP_3","hist_VR_TOP_3",1,-1,1);
  TH1D * h_VR_Z     = new TH1D("hist_VR_Z","hist_VR_Z",1,-1,1);

  std::cout << "argc: " << argc << "\n";
  std::vector<TString> my_files;
  for(int a=1; a<argc; a++) {
    std::cout << "a: " << a << "\n";
    std::cout << "argv[" << a << "]: " << argv[a] << "\n";
    // Input File option
    if(!strcmp(argv[a],"--infile")) {
      //files.push_back(argv[a+1]);
      std::string argStr = argv[a+1];
      std::cout << "  argStr: << " << argStr << "\n";
      for (size_t i=0,n; i <= argStr.length(); i=n+1) {
        n = argStr.find_first_of(',',i);
        if (n == std::string::npos) n = argStr.length();
        std::string tmp = argStr.substr(i,n-i);
        std::cout << "    tmp: " << tmp << "\n";
        my_files.push_back(tmp);
      }
    }
    else {
      std::cout << "skipping\n";
    }
  }

  if (my_files.size()==0){
    std::cout << "Did not match set properly.  Exiting." << std::endl;
    return 1;
  }

  TChain ch("truth");
  for (unsigned int i=0;i<my_files.size();i++){
    std::cout << "Adding file " << my_files[i] << std::endl;
    ch.Add( my_files[i].Data() );
  }

  std:: cout << "Assigning branches..." << std::endl;
  std::vector<float> * elPt = new std::vector<float>(10), * elEta = new std::vector<float>(10), * elPhi = new std::vector<float>(10)
                   , * muPt = new std::vector<float>(10), * muEta = new std::vector<float>(10), * muPhi = new std::vector<float>(10)
                   , * jetPt = new std::vector<float>(30), *jetEta = new std::vector<float>(30), *jetPhi = new std::vector<float>(30)
                   , * jetM = new std::vector<float>(30);
  std::vector<int> * jetPartonFlavor = new std::vector<int>(30);

  float mc_event_weight=0;
  float METx=0.,METy=0.;

  ch.SetBranchStatus("*",0);
  ch.SetBranchStatus( "el_pt"  , 1 ); //&elPt );
  ch.SetBranchStatus( "el_eta" , 1 ); //&elEta );
  ch.SetBranchStatus( "el_phi" , 1 ); //&elPhi );
  ch.SetBranchStatus( "mu_pt"  , 1 ); //&muPt );
  ch.SetBranchStatus( "mu_eta" , 1 ); //&muEta );
  ch.SetBranchStatus( "mu_phi" , 1 ); //&muPhi );

  if (!my_files[0].Contains("diboson_aMCAtNLO")){
    ch.SetBranchStatus( "jet_AntiKt4TruthJets_pt"  , 1 ); //&jetPt );
    ch.SetBranchStatus( "jet_AntiKt4TruthJets_eta" , 1 ); //&jetEta );
    ch.SetBranchStatus( "jet_AntiKt4TruthJets_phi" , 1 ); //&jetPhi );
    ch.SetBranchStatus( "jet_AntiKt4TruthJets_m"   , 1 ); //&jetM );
    ch.SetBranchStatus( "jet_AntiKt4TruthJets_flavor_partonFlavor", 1 );
    ch.SetBranchAddress( "jet_AntiKt4TruthJets_pt"  , &jetPt );
    ch.SetBranchAddress( "jet_AntiKt4TruthJets_eta" , &jetEta );
    ch.SetBranchAddress( "jet_AntiKt4TruthJets_phi" , &jetPhi );
    ch.SetBranchAddress( "jet_AntiKt4TruthJets_m"   , &jetM );
    ch.SetBranchAddress( "jet_AntiKt4TruthJets_flavor_partonFlavor"   , &jetPartonFlavor );
  } else {
    ch.SetBranchStatus( "jet_antiKt4Truth_pt"  , 1 ); //&jetPt );
    ch.SetBranchStatus( "jet_antiKt4Truth_eta" , 1 ); //&jetEta );
    ch.SetBranchStatus( "jet_antiKt4Truth_phi" , 1 ); //&jetPhi );
    ch.SetBranchStatus( "jet_antiKt4Truth_m"   , 1 ); //&jetM );
    ch.SetBranchStatus( "jet_antiKt4Truth_m"   , 1 ); //&jetM );
    ch.SetBranchAddress( "jet_antiKt4Truth_pt"  , &jetPt );
    ch.SetBranchAddress( "jet_antiKt4Truth_eta" , &jetEta );
    ch.SetBranchAddress( "jet_antiKt4Truth_phi" , &jetPhi );
    ch.SetBranchAddress( "jet_antiKt4Truth_m"   , &jetM );
    ch.SetBranchAddress( "jet_antiKt4Truth_flavor_partonFlavor"   , &jetPartonFlavor );
  }

  ch.SetBranchStatus( "MET_Truth_NonInt_etx" , 1 ); //&METx );
  ch.SetBranchStatus( "MET_Truth_NonInt_ety" , 1 ); //&METy );
  ch.SetBranchStatus( "mc_event_weight" , 1 ); // mc event weight!

  ch.SetBranchAddress( "el_pt"  , &elPt );
  ch.SetBranchAddress( "el_eta" , &elEta );
  ch.SetBranchAddress( "el_phi" , &elPhi );
  ch.SetBranchAddress( "mu_pt"  , &muPt );
  ch.SetBranchAddress( "mu_eta" , &muEta );
  ch.SetBranchAddress( "mu_phi" , &muPhi );

  ch.SetBranchAddress( "MET_Truth_NonInt_etx" , &METx );
  ch.SetBranchAddress( "MET_Truth_NonInt_ety" , &METy );
  ch.SetBranchAddress( "mc_event_weight" , &mc_event_weight );

  std::cout << "Making temporary variables..." << std::endl;
  std::vector<TLorentzVector> el_list;
  std::vector<TLorentzVector> mu_list;
  std::vector<TLorentzVector> jet_list;
  el_list.resize(10);
  mu_list.resize(10);
  jet_list.resize(20);
  double m=0.;

  bool is_zz = false; //s3=="zz";

  TLorentzVector lep1, lep2, jet1, jet2;
  int lep1_flav=0, lep2_flav=0;

  long nEvents = ch.GetEntries();
  std::cout << "Beginning event loop over " << ch.GetEntries() << " events." << std::endl;
  for (long evt=0;evt<nEvents;++evt){

    ch.GetEntry(evt);
    if (evt%200000==0) std::cout << "Working on entry " << evt << std::endl;

    el_list.clear();
    mu_list.clear();
    jet_list.clear();

    lep1.SetPtEtaPhiM(0,0,0,0);
    lep2.SetPtEtaPhiM(0,0,0,0);
    jet1.SetPtEtaPhiM(0,0,0,0);
    jet2.SetPtEtaPhiM(0,0,0,0);

    int nJets40 = 0;
    int nEl40 = 0;
    int nMu40 = 0;
    // double ht=0.;
    bool found1=false;
    double bonus_METx=0. , bonus_METy=0. ;

    for (int j=elPt->size()-1;j>=0 && j<elPt->size();--j){
      if (std::fabs( (*elEta)[j] )>2.5) continue;
      if ( (*elPt)[j]<40000. ) continue;
      TLorentzVector a(0,0,0,0);
      a.SetPtEtaPhiM( (*elPt)[j] , (*elEta)[j] , (*elPhi)[j] , 0. );
      bool hadOverlap = false;
      for (unsigned int e=0;e<el_list.size();++e){
        if (el_list[e].DeltaR(a)<0.05){ // We normally do overlap removal like this anyway
          hadOverlap=true;
          break;
        }
      }
      if (hadOverlap) continue; // Already counted this guy

      el_list.push_back(a);
      nEl40++;
    }

    for (int j=muPt->size()-1;j>=0 && j<muPt->size();--j){
      if (is_zz){
        bonus_METx += (*muPt)[j]*std::cos( (*muPhi)[j] );
        bonus_METy += (*muPt)[j]*std::sin( (*muPhi)[j] );
        continue;
      }

      if (std::fabs( (*muEta)[j] )>2.5) continue;
      if ( (*muPt)[j]<10000. ) continue;
      TLorentzVector a(0,0,0,0);
      a.SetPtEtaPhiM( (*muPt)[j] , (*muEta)[j] , (*muPhi)[j] , 0. );
      bool hadOverlap = false;
      for (unsigned int e=0;e<mu_list.size();++e){
        if (mu_list[e].DeltaR(a)<0.05){ // We normally do overlap removal like this anyway
          hadOverlap=true;
          break;
        }
      }
      if (hadOverlap) continue; // Already counted this guy

      mu_list.push_back(a);
      nMu40++;
    }

    for (unsigned int j=0;j<jetPt->size();++j){
      if (std::fabs( (*jetEta)[j] )>2.5) continue;
      if ( (*jetPt)[j]<40000. ) continue;
      if ( fabs(jetPartonFlavor->at(j)) != 5) continue;

      TLorentzVector a(0,0,0,0);
      a.SetPtEtaPhiM( (*jetPt)[j] , (*jetEta)[j] , (*jetPhi)[j] , 0 );

      bool hadOverlap = false;
      for (int el_it=0; el_it<nEl40; ++el_it) { // Electron-jet overlap removal
        double theDR = a.DeltaR( el_list[el_it] );
        if ( theDR<0.2 ){
          hadOverlap = true;
          break;
        } else if ( theDR<0.4 ){
          nEl40--;
          el_list.erase( el_list.begin()+el_it );
          break; // had better only happen once!
        }
      }
      for (int mu_it=0; mu_it<nMu40; ++mu_it) { // Electron-jet overlap removal
        double theDR = a.DeltaR( mu_list[mu_it] );
        if ( theDR<0.4 ){
          nMu40--;
          mu_list.erase( mu_list.begin()+mu_it );
          break; // had better only happen once!
        }
      }
      if (hadOverlap) continue;
      jet_list.push_back(a);
      if (a.Pt()>40000.){
        nJets40++;
      }
    }

    if ((nEl40+nMu40)<2) continue;
    // if (lep1.Pt()<25.) continue; // Second lepton guaranteed above 10 GeV by def'n
    if (nJets40<2) continue;

    bool is_lep_e_0 = true;
    bool is_lep_e_1 = true;
    int lep_it_0 = -1;
    int lep_it_1 = -1;
    float lep_pt_0 = 0;
    float lep_pt_1 = 0;

    for (unsigned int el_it = 0; el_it != nEl40; ++el_it) {
      float this_lep_pt = el_list.at(el_it).Pt();
      if (this_lep_pt > lep_pt_1) {
        lep_it_1 = el_it;
        lep_pt_1 = this_lep_pt;
        is_lep_e_1 = true;
      }
      if (this_lep_pt > lep_pt_0) {
        lep_it_1 = lep_it_0;
        lep_pt_1 = lep_pt_0;
        is_lep_e_1 = is_lep_e_0;

        lep_it_0 = el_it;
        lep_pt_0 = this_lep_pt;
        is_lep_e_0 = true;
      }
    }

    for (unsigned int mu_it = 0; mu_it != nMu40; ++mu_it) {
      float this_lep_pt = mu_list.at(mu_it).Pt();
      if (this_lep_pt > lep_pt_1) {
        lep_it_1 = mu_it;
        lep_pt_1 = this_lep_pt;
        is_lep_e_1 = false;
      }
      if (this_lep_pt > lep_pt_0) {
        lep_it_1 = lep_it_0;
        lep_pt_1 = lep_pt_0;
        is_lep_e_1 = is_lep_e_0;

        lep_it_0 = mu_it;
        lep_pt_0 = this_lep_pt;
        is_lep_e_0 = false;
      }
    }

    if (is_lep_e_0) {lep1 = el_list.at(lep_it_0);}
    else            {lep1 = mu_list.at(lep_it_0);}

    if (is_lep_e_1) {lep2 = el_list.at(lep_it_1);}
    else            {lep2 = mu_list.at(lep_it_1);}

    int jet_it_0 = -1;
    int jet_it_1 = -1;
    float jet_pt_0 = 0;
    float jet_pt_1 = 0;

    for (unsigned int jet_it = 0; jet_it != nJets40; ++jet_it) {
      float this_jet_pt = jet_list.at(jet_it).Pt();
      if (this_jet_pt > jet_pt_1) {
        jet_it_1 = jet_it;
        jet_pt_1 = this_jet_pt;
      }
      if (this_jet_pt > jet_pt_0) {
        jet_it_1 = jet_it_0;
        jet_pt_1 = jet_pt_0;

        jet_it_0 = jet_it;
        jet_pt_0 = this_jet_pt;
      }
    }

    jet1 = jet_list.at(jet_it_0);
    jet2 = jet_list.at(jet_it_1);

    //bool OF = (lep1_flav+lep2_flav==24);
    m = (lep1+lep2).M();
    // if (15000.>m) continue;

    double ht = lep1.Pt() + lep2.Pt() + jet1.Pt() + jet2.Pt();
    double met = std::sqrt( METx*METx + METy*METy );
    double met_sig = met/sqrt(ht);
    if (is_zz){
      met = std::sqrt( std::pow(METx+bonus_METx,2) + std::pow(METy+bonus_METy,2) );
    }

    TLorentzVector bl_l1j1 = (lep1+jet1);
    TLorentzVector bl_l2j2 = (lep2+jet2);
    TLorentzVector bl_l1j2 = (lep1+jet2);
    TLorentzVector bl_l2j1 = (lep2+jet1);

    TLorentzVector bl_0, bl_1;
    double mbl_diff_1122 = fabs(bl_l1j1.M() - bl_l2j2.M());
    double mbl_diff_1221 = fabs(bl_l1j2.M() - bl_l2j1.M());
    if (mbl_diff_1122 < mbl_diff_1221) {
      if (bl_l1j1.M() > bl_l2j2.M()) {
        bl_0 = bl_l2j2;
        bl_1 = bl_l1j1;
      }
      else {
        bl_0 = bl_l1j1;
        bl_1 = bl_l2j2;
      }
    }
    else {
      if (bl_l1j2.M() > bl_l2j1.M()) {
        bl_0 = bl_l2j1;
        bl_1 = bl_l1j2;
      }
      else {
        bl_0 = bl_l1j2;
        bl_1 = bl_l2j1;
      }
    }

    double mbl_0 = bl_0.M();
    double mbl_1 = bl_1.M();
    double mbl_asym = (mbl_0-mbl_1)/(mbl_0+mbl_1);

    bool is_z = (  (is_lep_e_0 == is_lep_e_1)
                && (81000<m)
                && (m<101000.)
                );
    if (mbl_0 > 400000. && ht > 1100000. && mbl_asym < 2. && !is_z                ) h_SR_400 ->Fill( 0. , mc_event_weight );
    if (mbl_0 > 600000. && ht > 1100000. && mbl_asym < 2. && !is_z                ) h_SR_600 ->Fill( 0. , mc_event_weight );
    if (mbl_0 > 200000. && ht < 500000.  && mbl_asym < 2. && !is_z && met_sig > 4.) h_CR_TOP->Fill( 0. , mc_event_weight );
    if (mbl_0 > 200000. && ht < 500000.  && mbl_asym < 2. && is_z  && met_sig < 4.) h_CR_Z->Fill( 0. , mc_event_weight );
    if (mbl_0 > 200000. && ht < 500000.  && mbl_asym < 2. && !is_z && met_sig > 4.) h_VR_TOP_1->Fill( 0. , mc_event_weight );
    if (mbl_0 > 200000. && ht < 500000.  && mbl_asym > 2. && !is_z                ) h_VR_TOP_2->Fill( 0. , mc_event_weight );
    if (mbl_0 > 200000. && ht > 500000.  && mbl_asym > 2. && !is_z && met_sig > 4.) h_VR_TOP_3->Fill( 0. , mc_event_weight );
    if (mbl_0 > 200000. && ht > 500000.  && mbl_asym < 2. && is_z                 ) h_VR_Z->Fill( 0. , mc_event_weight );

  } // End of event loop

  std::cout << "Done with loop, will close file." << std::endl;

  TString of_name = "truth_histograms.root";
  TFile fOut(of_name,"RECREATE");
  fOut.cd();

  h_SR_400 ->Write("hist_SR_400", TObject::kOverwrite);
  h_SR_600 ->Write("hist_SR_600", TObject::kOverwrite);
  h_CR_TOP->Write("hist_CR_TOP",TObject::kOverwrite);
  h_CR_Z->Write("hist_CR_Z",TObject::kOverwrite);
  h_VR_TOP_1->Write("hist_VR_TOP_1",TObject::kOverwrite);
  h_VR_TOP_2->Write("hist_VR_TOP_2",TObject::kOverwrite);
  h_VR_TOP_3->Write("hist_VR_TOP_3",TObject::kOverwrite);
  h_VR_Z->Write("hist_VR_Z",TObject::kOverwrite);

  std::cout << "Done writing results, closing up and finishing up." << std::endl;
  fOut.Close();

  return 0;
}

