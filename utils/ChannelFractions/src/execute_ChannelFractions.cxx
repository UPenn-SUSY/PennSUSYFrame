#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include <dirent.h>

#include "ChannelFractions/include/ChannelFractions.h"
#include "Parser/include/CommandParser.h"

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "Getting fractional channel contributions\n";

  InputContainer inp_cont = CommandParser::readInputs(argc, argv, "output");

  // check for valid TChain object
  if (inp_cont.chain == NULL) return 0;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Create the ChannelFractions object, and loop over the TChain
  ChannelFractions cf(inp_cont.chain, inp_cont.num_events);
  cf.Loop();

  // Dump cut flow to screen and to file
  cf.printToScreen();
  cf.printToFile("cf.root");

  return 0;
}
