#include <string>
#include <iostream>
#include "TFile.h"
#include "TTree.h"

#include "include/PennSusyFrameCore.h"

// -----------------------------------------------------------------------------
void help()
{
  std::cout << "usage:\n\t./TruthNtupleLooper <INPUT FILE NAME>\n\n";
}

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "testing basic truth ntuple looper\n";

  if (argc != 2) help();

  std::cout << "input file name: " << argv[1] << "\n";

  TFile* f = new TFile(argv[1]);
  TTree* t = static_cast<TTree*>(f->Get("truth"));

  std::cout << "retrieved tree from file. constructing PennSusyFrameCore object\n";
  PennSusyFrame::PennSusyFrameCore tnl(t);
  std::cout << "Preparing to loop over events!\n";
  tnl.Loop();
  std::cout << "done!\n";

  delete f;
}
