// file:        Event.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     January 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Event_h
#define AtlasSFrameUtils_Event_h

#include <iostream>
#include "D3PDObjects/include/EventInfoD3PDObject.h"

// ============================================================================
class Event : public D3PDReader::EventInfoD3PDObject
{
public:
  // main constructor
  Event(const ::Long64_t& master, const char* prefix = "", bool is_data = true );

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

private:
  // event weights
  double m_pile_up_weight;
  double m_lepton_eff_weight;
  double m_trigger_weight;
  double m_cross_section_weight;
  double m_b_tag_weight;

  ClassDef(Event, 1);

};


#endif // AtlasSFrameUtils_Event_h
