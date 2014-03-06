#ifndef MakeFakeNtuple_h
#define MakeFakeNtuple_h

// =============================================================================
#include "NtupleLooper/include/NtupleLooper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

#include "SusyMatrixMethod/FakeEstNtupleMaker.h"

// =============================================================================
class TTree;

// =============================================================================
class MakeFakeNtuple : public NtupleHelper::NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    MakeFakeNtuple(TTree *tree, double num_events, std::string out_file_name);
    virtual ~MakeFakeNtuple();

    virtual void processEvent();

    void write();

  // ---------------------------------------------------------------------------
  protected:

  // ---------------------------------------------------------------------------
  private:
    std::string m_out_file_name;

    SusyMatrixMethod::FakeEstNtupleMaker m_fake_ntuple_maker;
};

#endif
