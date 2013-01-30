#ifndef PlotNtupleMaker_h
#define PlotNtupleMaker_h

#include <iostream>
#include <sstream>
#include <map>
#include <vector>

#include <TROOT.h>
#include <TCut.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>

#include "NtupleLooper/include/NtupleLooper.h"

#include "Selection/include/EventSelection.h"
#include "Selection/include/WeightHandler.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class PlotNtupleMaker : public NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    PlotNtupleMaker( TTree *tree=0
                   , std::string out_file_name = "plot_ntuple.root"
                   );
    virtual ~PlotNtupleMaker();

    void addCut( std::string key
               , Selection::EventSelection& selecton
               );

    virtual void Loop();
    virtual void processEvent();

    void writeToFile();
    void writeToFile(std::string key, TTree* tree_to_write);

  // ---------------------------------------------------------------------------
  protected:
    void filterTree(std::string key);

    std::vector<std::string> m_keys;
    std::map<std::string, Selection::EventSelection> m_selection;

    TFile* m_out_file;

    unsigned int m_entry_num;
};

#endif
