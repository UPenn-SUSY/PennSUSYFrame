#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include "ChargeFlipCalc/include/ChargeFlipCalc.h"
#include "Parser/include/CommandParser.h"

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  // TChain* t = CommandParser::readInputs(argc, argv, "output");
  TChain* t = CommandParser::readInputs(argc, argv, "presel");
  //TTree* t = static_cast<TTree*>(f->Get("presel"));

  ChargeFlipCalc cfc(t);
  cfc.Loop();

  cfc.prepLikelihood();
  cfc.calcLikelihood();
  cfc.calcTruth();

  cfc.printToFile("cf.root");


}
