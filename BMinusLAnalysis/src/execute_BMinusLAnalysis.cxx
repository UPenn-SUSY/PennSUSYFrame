#include <string>
#include <iostream>
#include "TFile.h"
#include "TTree.h"

#include "include/BMinusLAnalysis.h"

// -----------------------------------------------------------------------------
void help()
{
  std::cout << "usage:\n\t./BMinusLAnalysis <INPUT FILE NAME>\n\n";
}

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "Running BMinusLAnalysis\n";

  if (argc != 2) help();

  std::cout << "input file name: " << argv[1] << "\n";

  TFile* f = new TFile(argv[1]);
  TTree* t = static_cast<TTree*>(f->Get("susy"));

  std::cout << "initialize BMinusLAnalysis object\n";
  PennSusyFrame::BMinusLAnalysis bmla(t);
  std::cout << "about to look\n";
  bmla.Loop();
  std::cout << "Run completed!\n";

  delete f;
}
