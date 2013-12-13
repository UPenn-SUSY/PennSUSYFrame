#ifndef UpdateWeights_h
#define UpdateWeights_h

// =============================================================================
#include "NtupleLooper/include/NtupleLooper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class TTree;

// =============================================================================
class UpdateWeights : public NtupleHelper::NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    UpdateWeights(TTree *tree, double num_events, std::string out_file_name);
    virtual ~UpdateWeights();

    virtual void processEvent();

  // ---------------------------------------------------------------------------
  protected:

  // ---------------------------------------------------------------------------
  private:
    std::string m_out_file_name;
};

#endif
