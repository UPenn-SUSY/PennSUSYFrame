#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "include/HistMaker.h"
#include "Selection/include/EventSelection.h"
#include "Selection/include/LumiWeight.h"

#include "Parser/include/MasterConfigParser.h"
#include "Parser/include/CutConfigParser.h"
#include "Parser/include/HistConfigParser.h"

#include <sys/stat.h>

// -----------------------------------------------------------------------------
bool fileExists(const std::string& file_name)
{
  struct stat buf;
  if (stat(file_name.c_str(), &buf) != -1) {
    return true;
  }
  return false;
}

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "Making Histograms!\n";

  if (argc < 1) {
    std::cout << "Please enter an input config file\n";
    return 0;
  }

  std::string config_file = argv[1];
  std::cout << "config file: " << config_file << "\n";
  MasterConfigParser parser(config_file);
  parser.parse();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // double num_events = parser.getNumEvents();
  double num_events = parser.getPTNTNumEvents();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Open/close output file to create it
  std::string out_file_name = parser.getHistFile();
  std::cout << "out file: " << out_file_name << "\n";
  std::cout << "file exists: " << fileExists(out_file_name) << "\n";
  if (fileExists(out_file_name)) {
    std::string proceed;
    while (!(  proceed == "y"
            || proceed == "Y"
            || proceed == "n"
            || proceed == "N"
            )
          ) {
      std::cout << "Output file exists. Overwrite it? (y/n) ";
      std::cin >> proceed;
      if (proceed == "n" || proceed == "N") {
        return 0;
      }
    }

    TFile out_file(out_file_name.c_str(), "RECREATE");
    out_file.Close();
  }

  // TChain* chain = parser.getInputChain();
  // HistMaker hm(chain, out_file_name);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::string cut_config_file = parser.getSelectionFile();
  CutConfigParser cut_parser( cut_config_file
                            , parser.getGlobalWeightHandler()
                            );
  cut_parser.parse();
  std::map<std::string, Selection::EventSelection> evt_sel =
      cut_parser.getSelectionMap();
  std::map<std::string, Selection::WeightHandler> weight_handles =
      cut_parser.getWeightMap();

  // Loop over all selection criteria
  std::map<std::string, Selection::EventSelection>::iterator sel_it =
      evt_sel.begin();
  std::map<std::string, Selection::EventSelection>::iterator sel_term =
      evt_sel.end();
  for (; sel_it != sel_term; ++sel_it) {
    std::cout << sel_it->first << "\n";

    TChain* chain = parser.getPTNTChain(sel_it->first);
    HistMaker hm(chain, num_events, out_file_name);

    std::string key = sel_it->first;
    hm.addCut( key
             , evt_sel[key]
             , weight_handles[key]
             );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    std::string hist_config_file = parser.getHistInfoFile();
    HistConfigParser hist_parser(hist_config_file);
    hist_parser.parse();
    std::vector<HistInfo> hist_info = hist_parser.getHistInfoList();
    std::vector<HistInfo>::iterator hist_it = hist_info.begin();
    std::vector<HistInfo>::iterator hist_term = hist_info.end();
    for (; hist_it != hist_term; ++hist_it) {
      hm.addHist(*hist_it);
    }

    hm.Loop();
    hm.writeToFile();
  }

  // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // hm.Loop();
  // hm.writeToFile();
}
