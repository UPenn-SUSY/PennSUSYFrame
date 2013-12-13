#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "HistMaker/include/HistMaker.h"

#include "Helpers/include/FileHelpers.h"

#include "Selection/include/EventSelection.h"
#include "Selection/include/LumiWeight.h"
#include "Selection/include/WeightHandler.h"

#include "Parser/include/CommandParser.h"
#include "Parser/include/MasterConfigParser.h"
#include "Parser/include/CutConfigParser.h"
#include "Parser/include/HistConfigParser.h"

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "Making Histograms!\n";

  // if (argc != 2) {
  //   std::cout << "Please enter an input config file\n";
  //   return 0;
  // }

  InputContainer input_container = CommandParser::readInputs(argc, argv);
  std::string config_file = input_container.config_file;
  bool force_overwrite = input_container.force;

  MasterConfigParser parser(config_file);
  parser.parse();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  double num_events = parser.getPTNTNumEvents();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Open/close output file to create it
  std::string out_file_name = parser.getHistFile();
  if (!checkFile(out_file_name, force_overwrite)) return 0;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::string cut_config_file = parser.getSelectionFile();
  Selection::WeightHandler global_weight_handle = parser.getGlobalWeightHandler();
  CutConfigParser cut_parser( cut_config_file
                            , global_weight_handle
                            );
  cut_parser.parse();
  std::map<std::string, Selection::EventSelection> evt_sel =
      cut_parser.getSelectionMap();
  std::map<std::string, Selection::WeightHandler> weight_handles =
      cut_parser.getWeightMap();

  // Loop over all selection criteria
  std::cout << "Looping through selection criteria\n";
  std::map<std::string, Selection::EventSelection>::iterator sel_it =
      evt_sel.begin();
  std::map<std::string, Selection::EventSelection>::iterator sel_term =
      evt_sel.end();
  for (; sel_it != sel_term; ++sel_it) {
    std::cout << "Cut: " << sel_it->first << "\n";

    TChain* chain = parser.getPTNTChain(sel_it->first);
    HistMaker hm(chain, num_events, out_file_name);

    std::string key = sel_it->first;
    hm.addCut( key
             , evt_sel[key]
             , weight_handles[key]
             );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    std::string hist_config_file = parser.getHistInfoFile();
    HistConfigParser hist_parser(hist_config_file);
    hist_parser.parse();
    std::vector<HistInfo> hist_info = hist_parser.getHistInfoList();
    std::vector<HistInfo>::iterator hist_it = hist_info.begin();
    std::vector<HistInfo>::iterator hist_term = hist_info.end();
    for (; hist_it != hist_term; ++hist_it) {
      hm.addHist(*hist_it);
    }

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    hm.Loop();
    hm.writeToFile();
  }

  // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // hm.Loop();
  // hm.writeToFile();
}
