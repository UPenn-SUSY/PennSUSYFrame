#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "include/ChargeFlipCalc.h"

int main(int argc, char** argv)
{
  TFile* f = new TFile(argv[1]);
  TTree* t = static_cast<TTree*>(f->Get("output"));

  ChargeFlipCalc cfc(t);
  cfc.Loop();

  cfc.prepLikelihood();
  cfc.calcLikelihood();

  cfc.printToFile("cf.root");

  delete f;
}
