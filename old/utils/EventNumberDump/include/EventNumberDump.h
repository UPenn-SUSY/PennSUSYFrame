#ifndef EventNumberDump_h
#define EventNumberDump_h

// =============================================================================
#include <map>
#include <string>
#include <vector>
#include "NtupleLooper/include/NtupleLooper.h"
#include "Selection/include/EventSelection.h"

// =============================================================================
class TTree;
namespace Selection
{
  class EventSelection;
}

// =============================================================================
class EventNumberDump : public NtupleHelper::NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    EventNumberDump( TTree *tree
                   , double num_events
                   , std::string out_file_name = "plot_ntuple.root"
                   );
    virtual ~EventNumberDump();

    void addCut( std::string key
               , Selection::EventSelection& selecton
               );

    virtual void Loop();
    virtual void processEvent();

    // void writeToFile();
    // void writeToFile(std::string key, TTree* tree_to_write);

  // ---------------------------------------------------------------------------
  protected:
    void filterTree(std::string key);

    std::vector<std::string> m_keys;
    std::map<std::string, Selection::EventSelection> m_selection;

    TFile* m_out_file;

    unsigned int m_entry_num;
};

#endif
