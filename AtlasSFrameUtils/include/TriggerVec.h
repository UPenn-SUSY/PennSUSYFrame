// file:        TriggerVec.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     January 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_TriggerVec_h
#define AtlasSFrameUtils_TriggerVec_h

#include "D3PDObjects/include/TriggerVecD3PDObject.h"

// =============================================================================
class TriggerVec : public D3PDReader::TriggerVecD3PDObject
{
public:
  // main constructor
  TriggerVec(
      const ::Long64_t& master, const char* prefix = "", bool is_data = true );

private:

  ClassDef(TriggerVec, 1);
};


#endif // AtlasSFrameUtils_TriggerVec_h
