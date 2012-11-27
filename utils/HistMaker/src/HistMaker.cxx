#include "include/HistMaker.h"

// -----------------------------------------------------------------------------
HistMaker::HistMaker(TTree *tree) : NtupleLooper(tree)
{
}

// -----------------------------------------------------------------------------
HistMaker::~HistMaker()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void HistMaker::processEvent()
{
}
