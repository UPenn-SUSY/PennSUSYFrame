#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "UpdateWeights/include/UpdateWeights.h"

#include "Helpers/include/FileHelpers.h"

#include "Selection/include/EventSelection.h"
#include "Selection/include/LumiWeight.h"

#include "Parser/include/CommandParser.h"
#include "Parser/include/MasterConfigParser.h"
#include "Parser/include/CutConfigParser.h"
#include "Parser/include/HistConfigParser.h"

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "Updating weights!\n";

  // if (argc < 2) {
  //   std::cout << "Please enter an input config file\n";
  //   return 0;
  // }

  InputContainer input_container = CommandParser::readInputs(argc, argv);
  std::string config_file = input_container.config_file;
  bool force_overwrite = input_container.force;

  MasterConfigParser parser(config_file);
  parser.parse();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  double num_events = parser.getNumEvents();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::string out_file_name = parser.getPTNTFile();
  if (!checkFile(out_file_name, force_overwrite)) return 0;

  // std::cout << "The output pTNT file will be located here:\n\t"
  //           << out_file_name << "\n";
  //
  TChain* chain = parser.getInputChain();
  UpdateWeights uw(chain, num_events, out_file_name);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::cout << "Preparing to loop!\n";
  uw.Loop();
}
