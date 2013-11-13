// file:        Event.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     January 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Event_h
#define AtlasSFrameUtils_Event_h

// =============================================================================
#include "D3PDObjects/include/EventInfoD3PDObject.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SusyEnums.h"
#include "SusyAnalysisTools/include/SRHelper.h"

// =============================================================================
class Event : public D3PDReader::EventInfoD3PDObject
{
public:
  // main constructor
  Event(
      const ::Long64_t& master, const char* prefix = "", bool is_data = true );

  void clear();

  double getMCEventWeight() const;
  double getPileUpWeight() const;
  double getLeptonEffWeight() const;
  double getTriggerWeight() const;
  double getBTagWeight() const;
  double getCrossSectionWeight() const;
  double getKFactor() const;
  double getEffTimesXS() const;
  double getFakeWeight() const;
  double getChargeFlipWeight() const;
  int getMCChannelNum() const;


  void setMCEventWeight(double weight);
  void setPileUpWeight(double weight);
  void setLeptonEffWeight(double weight);
  void setTriggerWeight(double weight);
  void setCrossSectionWeight(double weight);
  void setBTagWeight(double weight);
  void setKFactor(double weight);
  void setEffTimesXS(double weight);
  void setFakeWeight(double weight);
  void setChargeFlipWeight(double weight);
  void setMCChannelNum(int channel);

  void setEmmaMt(double);
  void setHt(double);
  void setHtJets(double);
  void setHtLeptons(double);
  void setMll(double);
  void setMetEt(double);
  void setMetPhi(double);
  void setMetRel(double);
  void setMt(double);
  void setMt2(double);
  void setMeff(double);
  void setMeffJets(double);
  void setMeffLeptons(double);
  void setPtll(double);
  void setPhill(double);
  void setEtall(double);
  void setDeltaPhill(double);

  void setJetSumPt(double);
  void setOLJet(double);
  void setOLRatio(double);

  double getEmmaMt() const;
  double getHt() const;
  double getHtJets() const;
  double getHtLeptons() const;
  double getMll() const;
  double getMetEt() const;
  double getMetPhi() const;
  double getMetRel() const;
  double getMt() const;
  double getMt2() const;
  double getMeff() const;
  double getMeffJets() const;
  double getMeffLeptons() const;
  double getPtll() const;
  double getPhill() const;
  double getEtall() const;
  double getDeltaPhill() const;

  double getJetSumPt() const;
  double getOLJet() const;
  double getOLRatio() const;

  void print();

  FLAVOR_CHANNEL  getFlavorChannel() const;
  SIGN_CHANNEL    getSignChannel() const;
  PHASE_SPACE     getPhaseSpace() const;

  SusyAnalysisTools::EventDescription* getEventDesc();
  SusyAnalysisTools::SRHelper* getSRHelper();

private:
  // event weights
  double m_mc_event_weight;
  double m_pile_up_weight;
  double m_lepton_eff_weight;
  double m_trigger_weight;
  double m_cross_section_weight;
  double m_b_tag_weight;
  double m_k_factor;
  double m_eff_times_cross_section;
  double m_fake_weight;
  double m_charge_flip_weight;

  int m_mc_channel_num;

  // useful event level variables
  double m_emma_mt;
  double m_ht;
  double m_ht_jets;
  double m_ht_leptons;
  double m_mll;
  double m_met_et;
  double m_met_phi;
  double m_met_rel;
  double m_mt;
  double m_mt2;
  double m_meff;
  double m_meff_jets;
  double m_meff_leptons;
  double m_ptll;
  double m_phill;
  double m_etall;
  double m_dphill;

  double m_jet_sum_pt;
  double m_oljet;
  double m_olratio;

  bool m_emma_mt_cached;
  bool m_ht_cached;
  bool m_ht_jets_cached;
  bool m_ht_leptons_cached;
  bool m_mll_cached;
  bool m_met_et_cached;
  bool m_met_phi_cached;
  bool m_met_rel_cached;
  bool m_mt_cached;
  bool m_mt2_cached;
  bool m_meff_cached;
  bool m_meff_jets_cached;
  bool m_meff_leptons_cached;
  bool m_ptll_cached;
  bool m_phill_cached;
  bool m_etall_cached;
  bool m_dphill_cached;

  bool m_jet_sum_pt_cached;
  bool m_oljet_cached;
  bool m_olratio_cached;

  // Event description
  SusyAnalysisTools::EventDescription m_event_desc;
  SusyAnalysisTools::SRHelper         m_sr_helper;

  ClassDef(Event, 1);
};

#endif // AtlasSFrameUtils_Event_h
