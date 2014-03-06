#include "Parser/include/CommandParser.h"

#include <dirent.h>
#include <iostream>
#include <string>

#include <TROOT.h>
#include <TChain.h>

#include "Selection/include/LumiWeight.h"

// -----------------------------------------------------------------------------
CommandParser::CommandParser()
{
  // do nothing
}

// -----------------------------------------------------------------------------
InputContainer CommandParser::readInputs( int argc
                                        , char** argv
                                        , const std::string& tree_name
                                        )
{
  InputContainer input_container;

  if (argc == 1) {
    help();
    return input_container;
  }

  std::vector<std::string> file_names;

  for (int in_it = 1; in_it < argc; ++in_it) {
    // std::cout << "This option: " << argv[in_it] << "\n";
    if (std::string(argv[in_it]) == "--file") {
      file_names.push_back(argv[in_it+1]);

      // increment an extra time because we already got the next input
      ++in_it;
    }
    else if (std::string(argv[in_it]) == "--dir") {
      std::string dir_name = argv[in_it+1];
      DIR *dir;
      struct dirent *ent;
      if ((dir = opendir(dir_name.c_str())) != NULL) {

        while ((ent = readdir(dir)) != NULL) {
          if (  std::string(ent->d_name) != "."
            && std::string(ent->d_name) != ".."
            )
            file_names.push_back(dir_name + std::string(ent->d_name));

        }
        closedir(dir);
      }
      else {
        std::cout << "Cannot open directory: " << dir_name << "\n";
      }

      // increment an extra time because we already got the next input
      ++in_it;
    }
    else if (std::string(argv[in_it]) == "--force") {
      input_container.force = true;
    }
    else if (std::string(argv[in_it]) == "--config") {
      input_container.config_file = std::string(argv[in_it+1]);

      // increment an extra time because we already got the next input
      ++in_it;
    }
    else {
      std::cout << "invalid option: " << argv[in_it] << "\n";
      help();
    }
  }

  if (file_names.size() > 0) {
    input_container.num_events = LumiWeight::getNumEventsFromFiles(file_names);
    // TChain* t = new TChain(tree_name.c_str());
    // TChain* t = new TChain(tree_name.c_str());
    input_container.chain = new TChain(tree_name.c_str());

    size_t num_files = file_names.size();
    for (size_t file_itr = 0; file_itr != num_files; ++file_itr) {
      input_container.chain->AddFile(file_names.at(file_itr).c_str());
      std::cout << "Adding file: " << file_names.at(file_itr) << "\n";
    }
  }

  return input_container;
}

// -----------------------------------------------------------------------------
void CommandParser::help()
{
  std::cout << "Please give a valid option:\n"
            << "\t--file FILE_NAME: Single file input\n"
            << "\t--dir  DIR_NAME:  Input all files in directory\n"
            << "\t--config CONFIG_FILE\n"
            << "\t--force\n";
}
