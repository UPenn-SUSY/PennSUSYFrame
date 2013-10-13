#ifndef PlotNtupleMaker_h
#define PlotNtupleMaker_h

// =============================================================================
#include <map>
#include <string>
#include <vector>

#include "NtupleLooper/include/NtupleLooper.h"
#include "Selection/include/EventSelection.h"

// =============================================================================
class TFile;
class TTree;

// =============================================================================
class PlotNtupleMaker : public NtupleHelper::NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    PlotNtupleMaker( TTree* tree
                   , double events
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
