#include "AtlasSFrameUtils/include/Trigger.h"

#include <cmath>
#include <iostream>

#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "D3PDObjects/include/TriggerD3PDObject.h"

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
