#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include "ChargeFlipCalc/include/ChargeFlipCalc.h"
#include "NtupleLooper/include/NtupleLooper.h"
#include "Parser/include/CommandParser.h"


// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  // TChain* t = CommandParser::readInputs(argc, argv, "output");
  InputContainer inp_cont = CommandParser::readInputs(argc, argv, "output");
  //  InputContainer inp_cont = CommandParser::readInputs(argc, argv, "presel");

  // check of valid tChain object

  if (inp_cont.chain == NULL) return 0;
  

  double num_events = inp_cont.num_events;

  ChargeFlipCalc cfc(inp_cont.chain, num_events);
  cfc.Loop();

  cfc.prepLikelihood();
  cfc.calcLikelihood();
  cfc.calcTruth();

  cfc.printToFile("cf.root");


}
