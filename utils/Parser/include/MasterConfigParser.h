#ifndef MasterConfigParser_h
#define MasterConfigParser_h

#include <stdlib.h>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "TChain.h"
#include "TFile.h"
#include "TVectorD.h"

#include "ParseDriver.h"
#include "Selection/include/WeightHandler.h"

// =============================================================================
class MasterConfigParser : public ParseDriver
{
  // ---------------------------------------------------------------------------
  public:
    MasterConfigParser(std::string);
    virtual ~MasterConfigParser();

    std::string getPTNTFile();
    std::string getHistFile();

    std::string              getSelectionFile();
    std::string              getHistInfoFile();
    std::vector<std::string> getInputFileList();
    double                   getNumEvents();
    double                   getPTNTNumEvents();
    TChain*                  getInputChain();
    TChain*                  getInputChain(std::string tree_name);
    TChain*                  getPTNTChain(std::string tree_name);
    void config();
    Selection::WeightHandler getGlobalWeightHandler();

    int getChannelNum();

  // ---------------------------------------------------------------------------
  private:
    void clear();
    virtual void addLine(const std::vector<std::string>&);

    bool         m_in_file_block;

    std::string  m_cut_config_file_name;
    std::string  m_hist_config_file_name;

    std::string  m_ptnt_file_name;
    std::string  m_hist_file_name;

    std::string  m_in_tree_name;
    std::vector<std::string> m_in_file_list;

    Selection::WeightHandler m_global_weight_handler;

    int m_channel_num;
    int m_target_lumi;
};

#endif
