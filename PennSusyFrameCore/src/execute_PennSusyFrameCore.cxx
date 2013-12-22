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
  std::cout << "testing PennSusyFrameCore\n";

  if (argc != 2) help();

  std::cout << "input file name: " << argv[1] << "\n";

  TFile* f = new TFile(argv[1]);
  TTree* t = static_cast<TTree*>(f->Get("susy"));

  std::cout << "initialize PennSusyFrameCore object\n";
  PennSusyFrame::PennSusyFrameCore tnl(t);
  std::cout << "about to look\n";
  tnl.Loop();
  std::cout << "Run completed!\n";

  delete f;
}
