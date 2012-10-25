// file:        Trigger.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     January 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Trigger_h
#define AtlasSFrameUtils_Trigger_h

#include <iostream>
#include "D3PDObjects/include/TriggerD3PDObject.h"

// ============================================================================
class Trigger : public D3PDReader::TriggerD3PDObject
{
public:
  // main constructor
  Trigger(
      const ::Long64_t& master, const char* prefix = "", bool is_data = true );

private:
  ClassDef(Trigger, 1);
};


#endif // AtlasSFrameUtils_Trigger_h
