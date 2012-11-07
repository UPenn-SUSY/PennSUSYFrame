#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "include/CutFlowDump.h"

int main(int argc, char** argv)
{
  TFile* f = new TFile(argv[1]);
  TTree* t = static_cast<TTree*>(f->Get("output"));

  CutFlowDump cfd(t);
  cfd.Loop();

  cfd.printToScreen();
  cfd.printToFile("cf.root");

  delete f;
}
