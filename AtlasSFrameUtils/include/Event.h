// file:        Event.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     January 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Event_h
#define AtlasSFrameUtils_Event_h

#include <iostream>

#include "D3PDObjects/include/EventInfoD3PDObject.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"

// ============================================================================
class Event : public D3PDReader::EventInfoD3PDObject
{
public:
  // main constructor
  Event(
      const ::Long64_t& master, const char* prefix = "", bool is_data = true );

  void clear();

  double getPileUpWeight();
  double getLeptonEffWeight();
  double getTriggerWeight();
  double getCrossSectionWeight();
  double getBTagWeight();

  void setPileUpWeight(double weight);
  void setLeptonEffWeight(double weight);
  void setTriggerWeight(double weight);
  void setCrossSectionWeight(double weight);
  void setBTagWeight(double weight);

  void setMll(double mll);
  double getMll();

  FLAVOR_CHANNEL  getFlavorChannel();
  SIGN_CHANNEL    getSignChannel();
  PHASE_SPACE     getPhaseSpace();

  SusyAnalysisTools::EventDescription* getEventDesc();
  SusyAnalysisTools::SRHelper* getSRHelper();

private:
  // event weights
  double m_pile_up_weight;
  double m_lepton_eff_weight;
  double m_trigger_weight;
  double m_cross_section_weight;
  double m_b_tag_weight;

  // useful event level variables
  double m_mll;

  // Event description
  SusyAnalysisTools::EventDescription m_event_desc;
  SusyAnalysisTools::SRHelper         m_sr_helper;

  ClassDef(Event, 1);

};

#endif // AtlasSFrameUtils_Event_h
