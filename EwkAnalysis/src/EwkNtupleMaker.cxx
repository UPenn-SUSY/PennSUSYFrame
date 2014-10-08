#include "EwkAnalysis/include/EwkNtupleMaker.h"
#include "EwkAnalysis/include/EwkHistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <dirent.h>
#include <math.h>
#include <algorithm>

#include "PennSusyFrameCore/include/ObjectContainers.h"
#include "PennSusyFrameCore/include/Calculators.h"
#include "PennSusyFrameCore/include/SelectorHelpers.h"
#include "EwkAnalysis/include/EwkTrigger.h"

#include "EwkAnalysis/include/EwkCutFlowTracker.h"
#include "PennSusyFrameCore/include/D3PDReader.h"

// -----------------------------------------------------------------------------
PennSusyFrame::EwkNtupleMaker::EwkNtupleMaker(TTree* tree) : PennSusyFrame::EwkAnalysis::EwkAnalysis(tree)
                                                     , m_out_ntuple_file_name("EwkNtup.root")
                                                     , doBaselineSkim(false)

{
	
}

// -----------------------------------------------------------------------------
PennSusyFrame::EwkNtupleMaker::~EwkNtupleMaker()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::beginRun()
{
  EwkAnalysis::beginRun();
  configureOutput(m_out_ntuple_file_name, "optimize");
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::processEvent()
{
  clearVariables();

  m_event_weight = 1.;
  EwkAnalysis::processEvent();
  
  // get number of signal leptons
  int num_signal_leptons = m_electrons.num(EL_SIGNAL) + m_muons.num(MU_SIGNAL);
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 signal lepton cut
  if(!doBaselineSkim){
    bool pass_signal_lep = (num_signal_leptons == 2);
    m_pass_event = (m_pass_event && pass_signal_lep);
    if (m_crit_cut_signal_lep && !pass_signal_lep) return;
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // b jet veto
  
  // TODO validate b veto cut
  bool pass_b_veto = (m_jets.num(JET_B) == 0);
  m_pass_event = (m_pass_event && pass_b_veto);
  if (m_crit_cut_b_veto && !pass_b_veto) return;
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get charge flip weight
  // TODO move this to more sensible location
  m_event_quantities.setCFWeight(m_charge_flip_tool.getSF( m_event.getFlavorChannel()
                                                           , m_electrons.getCollection(EL_GOOD)
                                                           , m_muons.getCollection(MU_GOOD)));

  if (m_pass_event /*&& m_met.getMetRel()/1.e3 > 30*/) {
    fillNtuple( m_event_weight);
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::finalizeRun()
{
  std::cout<< "EwkNtupleMaker::finalizeRun()\n";
  m_output_file->Write();
  m_output_file->Close();
	EwkAnalysis::m_raw_cutflow_tracker.printToScreen();
	EwkAnalysis::m_cutflow_tracker.printToScreen();
}

void PennSusyFrame::EwkNtupleMaker::clearVariables()
{
  m_weight = 1.;

  m_mll = 0 ;
  m_ptll = 0 ;
  m_mt = 0;

  m_met_et  = 0 ;
  m_met_rel = 0 ;

  m_el_pt.clear();
  m_el_eta.clear();
  m_el_phi.clear();

  m_mu_pt.clear();
  m_mu_eta.clear();
  m_mu_phi.clear();

  m_lep_pt.clear();
  m_lep_eta.clear();
  m_lep_phi.clear();
  m_lep_signal.clear();

  m_jet_pt.clear();
  m_jet_eta.clear();
  m_jet_phi.clear();

  m_ljet_pt.clear();
  m_ljet_eta.clear();
  m_ljet_phi.clear();

  m_ht_signal   = 0 ;
  m_num_light_jets = 0;
  m_num_forward_jets = 0;
}

void PennSusyFrame::EwkNtupleMaker::configureOutput( std::string out_file_name
                                                               , std::string out_tree_name
                                                               )
{
  m_output_file = new TFile(out_file_name.c_str(), "RECREATE");
  m_output_tree = new TTree(out_tree_name.c_str(), out_tree_name.c_str());

  // connect branches for output
  m_output_tree->Branch( "event_number" , &m_event_number);
  m_output_tree->Branch( "run_number" , &m_run_number);
  m_output_tree->Branch( "weight" , &m_weight);
  m_output_tree->Branch( "x_sec" , &m_x_sec);
  m_output_tree->Branch( "k_factor" , &m_k_factor);
  m_output_tree->Branch( "filter_eff" , &m_filter_eff);
  m_output_tree->Branch( "cfweight" , &m_cfweight);
  m_output_tree->Branch( "isSS" , &m_isSS);
  m_output_tree->Branch( "isEE" , &m_isEE);
  m_output_tree->Branch( "isEM" , &m_isEM);
  m_output_tree->Branch( "isMM" , &m_isMM);

  m_output_tree->Branch( "n_el" , &m_num_el);
  m_output_tree->Branch( "n_mu" , &m_num_mu);

  m_output_tree->Branch( "el_pt" , &m_el_pt);
  m_output_tree->Branch( "el_eta" , &m_el_eta);
  m_output_tree->Branch( "el_phi" , &m_el_phi);

  m_output_tree->Branch( "mu_pt" , &m_mu_pt);
  m_output_tree->Branch( "mu_eta" , &m_mu_eta);
  m_output_tree->Branch( "mu_phi" , &m_mu_phi);

  m_output_tree->Branch( "lep_pt" , &m_lep_pt);
  m_output_tree->Branch( "lep_eta" , &m_lep_eta);
  m_output_tree->Branch( "lep_phi" , &m_lep_phi);
  m_output_tree->Branch( "lep_signal" , &m_lep_signal);

  m_output_tree->Branch( "jet_pt" , &m_jet_pt);
  m_output_tree->Branch( "jet_eta" , &m_jet_eta);
  m_output_tree->Branch( "jet_phi" , &m_jet_phi);

  m_output_tree->Branch( "ljet_pt" , &m_ljet_pt);
  m_output_tree->Branch( "ljet_eta" , &m_ljet_eta);
  m_output_tree->Branch( "ljet_phi" , &m_ljet_phi);

  m_output_tree->Branch( "mll"  , &m_mll);
  m_output_tree->Branch( "ptll" , &m_ptll);
  m_output_tree->Branch( "mt" , &m_mt);
  m_output_tree->Branch( "mt2" , &m_mt2);
  m_output_tree->Branch( "dphill" , &m_dphill);

  m_output_tree->Branch( "met_et"  , &m_met_et);
  m_output_tree->Branch( "met_rel" , &m_met_rel);
  m_output_tree->Branch( "met_phi" , &m_met_phi);


  m_output_tree->Branch( "ht_signal"   , &m_ht_signal);
  m_output_tree->Branch( "n_ljets" , &m_num_light_jets);
  m_output_tree->Branch( "n_fjets" , &m_num_forward_jets);
  m_output_tree->Branch( "n_jets" , &m_num_jets);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::fillNtuple( float weight)
{
  m_el_pt   = getSelectionPt ((std::vector<PennSusyFrame::Particle*>*)m_electrons.getCollection(EL_GOOD));
  m_el_signal   = getSelectionSignal ((std::vector<PennSusyFrame::Particle*>*)m_electrons.getCollection(EL_GOOD));
  m_mu_signal   = getSelectionSignal ((std::vector<PennSusyFrame::Particle*>*)m_muons.getCollection(MU_GOOD));
  m_mu_pt   = getSelectionPt ((std::vector<PennSusyFrame::Particle*>*)m_muons.getCollection(MU_GOOD));
  m_jet_pt  = getSelectionPt ((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_GOOD));
  m_ljet_pt  = getSelectionPt ((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_LIGHT));
  m_el_eta  = getSelectionEta((std::vector<PennSusyFrame::Particle*>*)m_electrons.getCollection(EL_GOOD));
  m_mu_eta  = getSelectionEta((std::vector<PennSusyFrame::Particle*>*)m_muons.getCollection(MU_GOOD));
  m_jet_eta = getSelectionEta((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_GOOD));
  m_ljet_eta = getSelectionEta((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_LIGHT));
  m_el_phi  = getSelectionPhi((std::vector<PennSusyFrame::Particle*>*)m_electrons.getCollection(EL_GOOD));
  m_mu_phi  = getSelectionPhi((std::vector<PennSusyFrame::Particle*>*)m_muons.getCollection(MU_GOOD));
  m_jet_phi = getSelectionPhi((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_GOOD));
  m_ljet_phi = getSelectionPhi((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_LIGHT));

  m_weight = weight;
  m_event_quantities.setCFWeight(m_charge_flip_tool.getSF( m_event.getFlavorChannel()
        , m_electrons.getCollection(EL_GOOD)
        , m_muons.getCollection(MU_GOOD)));
  m_cfweight = m_event_quantities.getCFWeight();
  m_event_number = m_event.getEventNumber();
  m_run_number = m_event.getRunNumber();

  m_isSS = (m_event.getSignChannel()==SIGN_SS);
  m_num_el = m_electrons.num(EL_GOOD);
  m_num_mu = m_muons.num(MU_GOOD);

  m_isEE = m_num_el == 2;
  m_isEM = m_num_el == 1 && m_num_mu == 1;
  m_isMM = m_num_mu == 2;




  if (m_isEE){
    if (m_el_pt[0] > m_el_pt[1])
      getSortLepPts(0,1,m_el_pt, m_el_eta, m_el_phi, m_el_signal);
    else 
      getSortLepPts(1,0,m_el_pt, m_el_eta, m_el_phi, m_el_signal);

  }else if (m_isMM){
    if (m_mu_pt[0] > m_mu_pt[1])
      getSortLepPts(0,1,m_mu_pt, m_mu_eta, m_mu_phi, m_mu_signal);
    else 
      getSortLepPts(1,0,m_mu_pt, m_mu_eta, m_mu_phi, m_mu_signal);

  }else if (m_isEM){
    if (m_mu_pt[0] > m_el_pt[0]){
      m_lep_pt.push_back( m_mu_pt[0]);
      m_lep_eta.push_back(m_mu_eta[0]);
      m_lep_phi.push_back(m_mu_phi[0]);
      m_lep_signal.push_back(m_mu_signal[0]);
      m_lep_pt.push_back( m_el_pt[0]);
      m_lep_eta.push_back(m_el_eta[0]);
      m_lep_phi.push_back(m_el_phi[0]);
      m_lep_signal.push_back(m_el_signal[0]);
    }else{
      m_lep_pt.push_back( m_el_pt[0]);
      m_lep_eta.push_back(m_el_eta[0]);
      m_lep_phi.push_back(m_el_phi[0]);
      m_lep_signal.push_back(m_el_signal[0]);
      m_lep_pt.push_back( m_mu_pt[0]);
      m_lep_eta.push_back(m_mu_eta[0]);
      m_lep_phi.push_back(m_mu_phi[0]);
      m_lep_signal.push_back(m_mu_signal[0]);
    }
  }

  m_mll  = m_event_quantities.getMll()/1.e3;
  m_ptll = m_event_quantities.getPtll()/1.e3;
  m_mt = m_event_quantities.getEmmaMt();
  m_mt2 = m_event_quantities.getMt2();
  m_dphill = m_event_quantities.getDphill();

  m_met_et  = m_met.getMetEt() /1.e3;
  m_met_rel = m_met.getMetRel()/1.e3;
  m_met_phi = m_met.getMetPhi();


  m_ht_signal   = m_event_quantities.getHtSignal()/1.e3;
  m_num_light_jets= m_jets.num(JET_LIGHT);
  m_num_jets= m_jets.num(JET_GOOD);
  m_num_forward_jets= m_jets.num(JET_FORWARD);

  // fill output tree
  m_output_tree->Fill();
}

void PennSusyFrame::EwkNtupleMaker::getSortLepPts( float i1
                                                 , float i2
                                                 , std::vector<float> pt
                                                 , std::vector<float> eta
                                                 , std::vector<float> phi
                                                 , std::vector<bool> signal
                                                 ){
  m_lep_pt.push_back( pt[i1]);
  m_lep_eta.push_back(eta[i1]);
  m_lep_phi.push_back(phi[i1]);
  m_lep_signal.push_back(signal[i1]);
  m_lep_pt.push_back( pt[i2]);
  m_lep_eta.push_back(eta[i2]);
  m_lep_phi.push_back(phi[i2]);
  m_lep_signal.push_back(signal[i2]);
}

std::vector<bool> PennSusyFrame::EwkNtupleMaker::getSelectionSignal(std::vector<PennSusyFrame::Particle*>* obj){
  std::vector<bool> sig;
  for (unsigned int i = 0; i < obj->size(); i++) {
    sig.push_back(obj->at(i)->getIsSignal());
  }
  return sig;
}

std::vector<float> PennSusyFrame::EwkNtupleMaker::getSelectionPt(std::vector<PennSusyFrame::Particle*>* obj){
  std::vector<float> pt;
  for (unsigned int i = 0; i < obj->size(); i++) {
    pt.push_back(obj->at(i)->getPt());
  }
  return pt;
}

std::vector<float> PennSusyFrame::EwkNtupleMaker::getSelectionEta(std::vector<PennSusyFrame::Particle*>* obj){
  std::vector<float> eta;
  for (unsigned int i = 0; i < obj->size(); i++) {
    eta.push_back(obj->at(i)->getEta());
  }
  return eta;
}

std::vector<float> PennSusyFrame::EwkNtupleMaker::getSelectionPhi(std::vector<PennSusyFrame::Particle*>* obj)
{
  std::vector<float> phi;
  for (unsigned int i = 0; i < obj->size(); i++) {
    phi.push_back(obj->at(i)->getPhi());
  }
  return phi;
}
