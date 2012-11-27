#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "include/HistMaker.h"

int main(int argc, char** argv)
{
  TFile* f = new TFile(argv[1]);
  TTree* t = static_cast<TTree*>(f->Get("output"));

  HistMaker hm(t);
  hm.Loop();

  delete f;
}
