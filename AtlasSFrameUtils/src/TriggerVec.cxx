#include <cmath>

#include "include/TriggerVec.h"
#include "AtlasSFrameUtils/include/CycleMacros.h"

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
