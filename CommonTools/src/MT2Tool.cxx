#include "include/MCT2Tool.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"


//_____________________________________________________________________________
CommonTools::MT2Tool::MT2Tool( SCycleBase* parent
                             , const char* name
                             )
                             : ToolBase(parent, name)
                             , m_egamma_energy_rescale(NULL)
{
  // do nothing
}

//_____________________________________________________________________________
CommonTools::MT2Tool::~MT2Tool()
{
  // do nothing
}
