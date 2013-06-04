#include "UpdateWeights/include/UpdateWeights.h"

#include <TTree.h>

#include "NtupleLooper/include/NtupleLooper.h"

// -----------------------------------------------------------------------------
UpdateWeights::UpdateWeights( TTree *tree
                            , double num_events
                            , std::string out_file_name
                            ) : NtupleLooper(tree, num_events)
                              , m_out_file_name(out_file_name)
{
  // do nothing
}

// -----------------------------------------------------------------------------
UpdateWeights::~UpdateWeights()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void UpdateWeights::processEvent()
{
  // do nothing
}
