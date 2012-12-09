#include <iostream>

#include "include/ParseDriver.h"
#include "include/HistConfigParser.h"
#include "include/CutConfigParser.h"
#include "include/MasterConfigParser.h"

int main()
{
  std::cout << "Testing parser\n";

  std::string test_file_name = "test.config";
  MasterConfigParser parser(test_file_name);
  parser.parse();
  parser.config();

  std::string test_cut_file_name = parser.getSelectionFile();
  CutConfigParser cut_parser( test_cut_file_name
                            , parser.getGlobalWeightHandler()
                            );
  cut_parser.parse();

  std::string test_hist_file_name =
      parser.getHistInfoFile();
  HistConfigParser hist_parser(test_hist_file_name);
  hist_parser.parse();
}
