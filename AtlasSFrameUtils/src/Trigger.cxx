#include <cmath>

#include "include/Trigger.h"
#include "AtlasSFrameUtils/include/CycleMacros.h"

ClassImp(Trigger)

// ----------------------------------------------------------------------------
Trigger::Trigger( const ::Long64_t& master
                , const char* prefix
                , bool /*is_data*/
                )
                : D3PDReader::TriggerD3PDObject(master, prefix)
{
  // do nothing
}
