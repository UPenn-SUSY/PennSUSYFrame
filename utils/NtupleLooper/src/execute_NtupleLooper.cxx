#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "include/NtupleLooper.h"

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "Basic ntuple looper\n";

  std::cout << "input file name: " << argv[1] << "\n";

  TFile* f = new TFile(argv[1]);
  TTree* t = static_cast<TTree*>(f->Get("output"));

  NtupleLooper ntl(t);
  ntl.Loop();

  delete f;
}
