#include "Helpers/include/FileHelpers.h"

#include <iostream>
#include <string>

#include <sys/stat.h>

#include "TFile.h"

// -----------------------------------------------------------------------------
bool fileExists(const std::string& file_name)
{
  struct stat buf;
  if (stat(file_name.c_str(), &buf) != -1) {
    return true;
  }
  return false;
}

// -----------------------------------------------------------------------------
bool checkFile(const std::string& file_name, bool force_overwrite)
{
  std::cout << "out file: \n\t" << file_name << "\n";
  std::cout << "file exists: " << fileExists(file_name) << "\n";
  if (fileExists(file_name)) {
    if (!force_overwrite) {
      std::string proceed;
      unsigned int num_trials = 0;
      unsigned int max_trials = 10;
      while (!(  proceed == "y"
              || proceed == "Y"
              || proceed == "n"
              || proceed == "N"
              )
            ) {
        if (num_trials == max_trials) {
          std::cout << "Maximum number of trials exceeded. Default to 'y'\n";
          proceed = "y";
          break;
        }

        std::cout << "Output file exists. Overwrite it? (y/n) ";
        if (num_trials > 0) {
          std::cout << "[" << max_trials - num_trials << " trials remaining] ";
        }

        std::cin >> proceed;
        if (proceed == "n" || proceed == "N") {
          return false;
        }
        ++num_trials;
      }
    }

    TFile out_file(file_name.c_str(), "RECREATE");
    out_file.Close();
  }

  return true;
}
