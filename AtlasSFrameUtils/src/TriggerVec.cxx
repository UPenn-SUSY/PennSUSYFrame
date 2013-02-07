#include "include/TriggerVec.h"

#include <cmath>
#include <iostream>

#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "D3PDObjects/include/TriggerVecD3PDObject.h"

ClassImp(TriggerVec)

// ----------------------------------------------------------------------------
TriggerVec::TriggerVec( const ::Long64_t& master
            , const char* prefix
            , bool /*is_data*/
            )
            : D3PDReader::TriggerVecD3PDObject(master, prefix)
{
  // do nothing
}
