#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "include/EventNumberDump.h"
#include "Selection/include/EventSelection.h"

#include "Parser/include/MasterConfigParser.h"
#include "Parser/include/CutConfigParser.h"
#include "Parser/include/HistConfigParser.h"

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "Making plot ntuple!\n";

  if (argc < 2) {
    std::cout << "Please enter an input config file\n";
    return 0;
  }

  std::string config_file = argv[1];
  std::cout << "config file: " << config_file << "\n";
  MasterConfigParser parser(config_file);
  parser.parse();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::string out_file_name = parser.getPTNTFile();
  TChain* chain = parser.getInputChain();
  EventNumberDump pnm(chain, out_file_name);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::string cut_config_file = parser.getSelectionFile();
  CutConfigParser cut_parser( cut_config_file
                            , parser.getGlobalWeightHandler()
                            );
  cut_parser.parse();
  std::map<std::string, Selection::EventSelection> evt_sel =
      cut_parser.getSelectionMap();

  std::map<std::string, Selection::EventSelection>::iterator sel_it =
      evt_sel.begin();
  std::map<std::string, Selection::EventSelection>::iterator sel_term =
      evt_sel.end();
  for (; sel_it != sel_term; ++sel_it) {
    std::string key = sel_it->first;
    std::cout << "key: " << key << "\n";
    pnm.addCut( key
              , evt_sel[key]
              );
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  pnm.Loop();
  // pnm.writeToFile();
}
