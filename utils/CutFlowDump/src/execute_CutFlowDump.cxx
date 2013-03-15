#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include <dirent.h>

#include "CutFlowDump/include/CutFlowDump.h"
// #include "NtupleLooper/include/NtupleLooper.h"
#include "Parser/include/CommandParser.h"

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "Dumping Cut flow\n";

  InputContainer inp_cont = CommandParser::readInputs(argc, argv, "output");
  // InputContainer inp_cont = CommandParser::readInputs(argc, argv, "presel");

  // check for valid TChain object
  if (inp_cont.chain == NULL) return 0;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Create the CutFlowDump object, and loop over the TChain
  CutFlowDump cfd(inp_cont.chain, inp_cont.num_events);
  cfd.Loop();

  // Dump cut flow to screen and to file
  cfd.printToScreen();
  cfd.printToFile("cf.root");

  return 0;
}
