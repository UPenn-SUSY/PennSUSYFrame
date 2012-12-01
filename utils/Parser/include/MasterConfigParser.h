#ifndef MasterConfigParser_h
#define MasterConfigParser_h

#include <stdlib.h>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include <TChain.h>
#include <TFile.h>

#include "ParseDriver.h"

// =============================================================================
class MasterConfigParser : public ParseDriver
{
  // -----------------------------------------------------------------------------
  public:
    MasterConfigParser(std::string);
    virtual ~MasterConfigParser();

    std::string getOutFile();
    std::string getSelectionFile();
    std::string getHistInfoFile();
    TChain*     getInputChain();
    void config();

  // -----------------------------------------------------------------------------
  private:
    void clear();
    virtual void addLine(std::vector<std::string>);

    bool         m_in_file_block;
    std::string  m_cut_file_name;
    std::string  m_hist_file_name;
    std::string  m_out_file_name;
    std::vector<std::string> m_in_file_list;

};

#endif
