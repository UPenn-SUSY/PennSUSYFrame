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
  //InputContainer inp_cont = CommandParser::readInputs(argc, argv, "output");
  //InputContainer inp_cont = CommandParser::readInputs(argc, argv, "charge_flip__sample0.charge_flip_base_selection");

  InputContainer inp_cont = CommandParser::readInputs(argc, argv, "nominal");
  //  InputContainer inp_cont = CommandParser::readInputs(argc, argv, "presel");

  // check of valid tChain object

  if (inp_cont.chain == NULL) return 0;
  

  double num_events = inp_cont.num_events;

  ChargeFlipCalc cfc(inp_cont.chain, num_events);
  cfc.Loop();

  cfc.prepLikelihood();
  cfc.calcLikelihood();
  cfc.calcTruth();

  cfc.printToFile("cfNom.root");
  cfc.clearHists();


  inp_cont = CommandParser::readInputs(argc, argv, "d0sig.4.5");
  num_events = inp_cont.num_events;
  ChargeFlipCalc cfc45(inp_cont.chain, num_events);
  cfc45.Loop();

  cfc45.prepLikelihood();
  cfc45.calcLikelihood();
  cfc45.calcTruth();
  cfc45.printToFile("cf45.root");
  cfc45.clearHists();

  inp_cont = CommandParser::readInputs(argc, argv, "d0sig.4");
  num_events = inp_cont.num_events;
  ChargeFlipCalc cfc40(inp_cont.chain, num_events);
  cfc40.Loop();

  cfc40.prepLikelihood();
  cfc40.calcLikelihood();
  cfc40.calcTruth();
  cfc40.printToFile("cf40.root");
  cfc40.clearHists();

  inp_cont = CommandParser::readInputs(argc, argv, "d0sig.3.5");
  num_events = inp_cont.num_events;
  ChargeFlipCalc cfc35(inp_cont.chain, num_events);
  cfc35.Loop();

  cfc35.prepLikelihood();
  cfc35.calcLikelihood();
  cfc35.calcTruth();
  cfc35.printToFile("cf35.root");
  cfc35.clearHists();

  inp_cont = CommandParser::readInputs(argc, argv, "d0sig.3");
  num_events = inp_cont.num_events;
  ChargeFlipCalc cfc30(inp_cont.chain, num_events);
  cfc30.Loop();

  cfc30.prepLikelihood();
  cfc30.calcLikelihood();
  cfc30.calcTruth();
  cfc30.printToFile("cf30.root");
  cfc30.clearHists();

  inp_cont = CommandParser::readInputs(argc, argv, "d0sig.2.5");
  num_events = inp_cont.num_events;
  ChargeFlipCalc cfc25(inp_cont.chain, num_events);
  cfc25.Loop();

  cfc25.prepLikelihood();
  cfc25.calcLikelihood();
  cfc25.calcTruth();
  cfc25.printToFile("cf25.root");
  cfc25.clearHists();

  inp_cont = CommandParser::readInputs(argc, argv, "d0sig.2");
  num_events = inp_cont.num_events;
  ChargeFlipCalc cfc20(inp_cont.chain, num_events);
  cfc20.Loop();

  cfc20.prepLikelihood();
  cfc20.calcLikelihood();
  cfc20.calcTruth();
  cfc20.printToFile("cf20.root");
  cfc20.clearHists();


}
