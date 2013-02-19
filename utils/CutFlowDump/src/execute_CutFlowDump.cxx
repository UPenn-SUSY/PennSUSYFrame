#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include <dirent.h>

#include "include/CutFlowDump.h"

int main(int argc, char** argv)
{
  std::cout << "Dumping Cut flow\n";

  TFile* f(NULL);
  // TChain* = new TChain("output");
  TChain* t = new TChain("presel");

  if (std::string(argv[1]) == "--file") {
    std::string file_name = argv[2];
    t->AddFile(file_name.c_str());
  }
  else if (std::string(argv[1]) == "--dir") {
    std::string dir_name = argv[2];

    DIR *dir;
    struct dirent *ent;
    // if ((dir = opendir ("c:\\src\\")) != NULL) {
    if ((dir = opendir (dir_name.c_str())) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
        std::string file_name = std::string(ent->d_name);

        // Only add root files. Not log files etc
        if (file_name.find(".root") == std::string::npos)
          continue;

        std::string full_file_name = dir_name + "/" + file_name;
        // std::cout << "Adding file: " << ent->d_name << '\n';;
        std::cout << "Adding file: " << file_name << '\n';;
        // printf ("%s\n", ent->d_name);

        t->AddFile(full_file_name.c_str());
      }
      closedir (dir);
    }
    else {
      /* could not open directory */
      perror ("");
      // return EXIT_FAILURE;
      return 0;
    }
  }

  // TTree* t = static_cast<TTree*>(f->Get("output"));
  // TTree* t = static_cast<TTree*>(f->Get("presel"));

  CutFlowDump cfd(t);
  cfd.Loop();

  cfd.printToScreen();
  cfd.printToFile("cf.root");

  delete f;
}
