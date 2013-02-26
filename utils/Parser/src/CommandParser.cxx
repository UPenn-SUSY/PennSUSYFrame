#include "Parser/include/CommandParser.h"

#include <dirent.h>
#include <iostream>
#include <string>

#include <TROOT.h>
#include <TChain.h>

// -----------------------------------------------------------------------------
CommandParser::CommandParser()
{
  // do nothing
}

// // -----------------------------------------------------------------------------
TChain* CommandParser::readInputs( int argc
                                 , char** argv
                                 , const std::string& tree_name
                                 )
{
  if (argc == 1) {
    help();
    return NULL;
  }

  // TChain* t = new TChain(tree_name.c_str());
  TChain* t = NULL;

  // If loading a single file
  if (std::string(argv[1]) == "--file") {
    t = new TChain(tree_name.c_str());
    std::string file_name = argv[2];
    t->AddFile(file_name.c_str());

    std::cout << "Adding file: " << file_name << "\n";
  }
  // If loading a full directory
  else if (std::string(argv[1]) == "--dir") {
    t = new TChain(tree_name.c_str());
    std::string dir_name = argv[2];

    DIR *dir;
    struct dirent *ent;
    // if ((dir = opendir ("c:\\src\\")) != NULL) {
    if ((dir = opendir (dir_name.c_str())) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
        std::string file_name = std::string(ent->d_name);

        // Only add root files. Not log files etc
        if (file_name.find(".root") == std::string::npos) continue;

        // If this is a good file, add it to the TChain
        std::string full_file_name = dir_name + "/" + file_name;
        std::cout << "Adding file: " << file_name << '\n';

        t->AddFile(full_file_name.c_str());
      }
      closedir (dir);
    }
    else {
      std::cout << "Cannot open directory: " << dir_name << "\n";
      // perror ("");
      return NULL;
    }
  }
  else {
    help();
  }

  return t;
}

// -----------------------------------------------------------------------------
void CommandParser::help()
{
  std::cout << "Please give a valid option:\n"
            << "\t--file FILE_NAME: Single file input\n"
            << "\t--dir  DIR_NAME:  Input all files in directory\n";
}
