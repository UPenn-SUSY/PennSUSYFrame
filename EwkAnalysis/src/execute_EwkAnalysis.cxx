#include <string>
#include <iostream>
#include "TFile.h"
#include "TTree.h"

#include "include/EwkAnalysis.h"

// -----------------------------------------------------------------------------
void help()
{
  std::cout << "usage:\n\t./EwkAnalysis <INPUT FILE NAME>\n\n";
}

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "Running EwkAnalysis\n";

  if (argc != 2) help();

  std::cout << "input file name: " << argv[1] << "\n";

  TFile* f = new TFile(argv[1]);
  TTree* t = static_cast<TTree*>(f->Get("susy"));

  std::cout << "initialize EwkAnalysis object\n";
  PennSusyFrame::EwkAnalysis ewka(t);
  std::cout << "about to look\n";
  ewka.Loop();
  std::cout << "Run completed!\n";

  delete f;
}
