#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "include/NtupleLooper.h"
#include "Selection/include/LumiWeight.h"

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "Basic ntuple looper\n";

  std::cout << "input file name: " << argv[1] << "\n";

  std::vector<std::string> file_list;
  file_list.push_back(argv[1]);

  double num_events = LumiWeight::getNumEventsFromFiles(file_list);
  std::cout << "There are " << num_events << " in this file\n";

  TFile* f = new TFile(argv[1]);
  TTree* t = static_cast<TTree*>(f->Get("output"));
  // TTree* t = static_cast<TTree*>(f->Get("presel"));

  NtupleHelper::NtupleLooper ntl(t, num_events);
  ntl.Loop();

  delete f;
}
