#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "MakeFakeNtuple/include/MakeFakeNtuple.h"

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
  std::cout << "Making fake ntuple!\n";

  // if (argc < 2) {
  //   std::cout << "Please enter an input config file\n";
  //   return 0;
  // }

  InputContainer input_container = CommandParser::readInputs(argc, argv, "output");
  std::string config_file = input_container.config_file;
  bool force_overwrite = input_container.force;

  // MasterConfigParser parser(config_file);
  // parser.parse();
  if (input_container.chain == NULL) return 0;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // double num_events = parser.getNumEvents();
  double num_events = input_container.chain->GetEntries();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // std::string out_file_name = parser.getPTNTFile();
  std::string out_file_name = "fake_ntuple.root";
  if (!checkFile(out_file_name, force_overwrite)) return 0;

  std::cout << "The output fake ntuple will be located here:\n\t"
            << out_file_name << "\n";

  MakeFakeNtuple mfn(input_container.chain, num_events, out_file_name);
  // TChain* chain = parser.getInputChain();
  // MakeFakeNtuple mfn(chain, num_events, out_file_name);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::cout << "Preparing to loop!\n";
  mfn.Loop();
  mfn.write();
}
