#include "include/MT2Tool.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"


//_____________________________________________________________________________
CommonTools::MT2Tool::MT2Tool( SCycleBase* parent
                             , const char* name
			       )
  : ToolBase(parent, name)
  
{
  // do nothing
}

//_____________________________________________________________________________
CommonTools::MT2Tool::~MT2Tool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
double CommonTools::MT2Tool::getMT2()
{
  return m_MT2;
}

//----------------------------------------------------------------------------
void CommonTools::MT2Tool::setMT2()
{
  double mt2 = 0;

  m_MT2 = mt2;

}
