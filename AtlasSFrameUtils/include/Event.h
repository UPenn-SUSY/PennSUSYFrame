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

  double getMCEventWeight();
  double getPileUpWeight();
  double getLeptonEffWeight();
  double getTriggerWeight();
  double getBTagWeight();
  double getCrossSectionWeight();
  double getKFactor();
  double getEffTimesXS();
  double getFakeWeight();
  double getChargeFlipWeight();
  int getMCChannelNum();


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

  void setMll(double);
  void setMetEt(double);
  void setMetPhi(double);
  void setMetRel(double);
  void setMt(double);
  void setMt2(double);
  void setMeff(double);
  void setPtll(double);
  void setPhill(double);
  void setEtall(double);

  double getMll();
  double getMetEt();
  double getMetPhi();
  double getMetRel();
  double getMt();
  double getMt2();
  double getMeff();
  double getPtll();
  double getPhill();
  double getEtall();

  void print();

  FLAVOR_CHANNEL  getFlavorChannel();
  SIGN_CHANNEL    getSignChannel();
  PHASE_SPACE     getPhaseSpace();

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
  double m_mll;
  double m_met_et;
  double m_met_phi;
  double m_met_rel;
  double m_mt;
  double m_mt2;
  double m_meff;
  double m_ptll;
  double m_phill;
  double m_etall;

  bool m_mll_cached;
  bool m_met_et_cached;
  bool m_met_phi_cached;
  bool m_met_rel_cached;
  bool m_mt_cached;
  bool m_mt2_cached;
  bool m_meff_cached;
  bool m_ptll_cached;
  bool m_phill_cached;
  bool m_etall_cached;

  // Event description
  SusyAnalysisTools::EventDescription m_event_desc;
  SusyAnalysisTools::SRHelper         m_sr_helper;

  ClassDef(Event, 1);
};

#endif // AtlasSFrameUtils_Event_h
