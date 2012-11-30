#include "include/ParseDriver.h"

// -----------------------------------------------------------------------------
ParseDriver::ParseDriver(std::string file_name) : m_file_name(file_name)
{
  // do nothing
}

// -----------------------------------------------------------------------------
bool ParseDriver::stringToBool(std::string to_convert) {
  if (to_convert == "1" || to_convert == "true")
    return true;
  else if (to_convert == "0" || to_convert == "false")
    return false;

  // if we get here, we have a malformed input string
  std::cout << "ERROR! The string \'" << to_convert << "\' could not be converted.  Check your inputs\n";
  return false;
}

// -----------------------------------------------------------------------------
int ParseDriver::stringToInt(std::string to_convert) {
  return atoi(to_convert.c_str());
  // return std::atoi(to_convert.c_str());
}

// -----------------------------------------------------------------------------
float ParseDriver::stringToFloat(std::string to_convert) {
  return atof(to_convert.c_str());
  // return std::atof(to_convert.c_str());
}

// -----------------------------------------------------------------------------
std::string ParseDriver::cleanUpLine(std::string line)
{
  line = stripComments(line);
  line = stripLeadingWhiteSpace(line);
  line = stripTrailingWhiteSpace(line);
  return line;
}

// -----------------------------------------------------------------------------
std::string ParseDriver::stripLeadingWhiteSpace(std::string line)
{
  std::string new_line = line;
  size_t found = 0;
  while (found < 1) {
    found = new_line.find(' ');
    if (found == 0)
      new_line = new_line.substr(found+1, std::string::npos);
  }
  return new_line;
}

// -----------------------------------------------------------------------------
std::string ParseDriver::stripTrailingWhiteSpace(std::string line)
{
  std::string new_line = line;
  size_t current_length = new_line.size();
  size_t found = current_length;
  while (found >= current_length-1 && found != std::string::npos) {
    found = new_line.rfind(' ');
    if (found == current_length-1) {
      new_line = new_line.substr(0, found);
      current_length = new_line.size();
    }
  }
  return new_line;
}

// -----------------------------------------------------------------------------
std::string ParseDriver::stripComments(std::string line)
{
  size_t found = line.find('#');
  if (found != std::string::npos)
    line = line.substr(0, found);
  return line;
}

// -----------------------------------------------------------------------------
std::vector<std::string> ParseDriver::split( std::string line
                                           , char split_char
                                           )
{
  std::vector<std::string> split_string;

  // find eol either real end of line, or beginning of comment
  size_t eol = line.find('#');
  if (eol == std::string::npos)
    eol = line.size();

  // search line for split_char
  size_t old_found = 0;
  size_t found = 0;
  while (found < eol) {
    found = std::min(eol, line.find(split_char, found+1));

    std::string substr = line.substr(old_found, found-old_found);
    split_string.push_back(substr);
    old_found = found+1;
  }

  // Remove any unwanted whitespace that got picked up while splitting
  size_t term = split_string.size();
  for (size_t it = 0; it != term; ++it) {
    split_string.at(it) = stripLeadingWhiteSpace(split_string.at(it));
    split_string.at(it) = stripTrailingWhiteSpace(split_string.at(it));
  }

  return split_string;
}

// -----------------------------------------------------------------------------
void ParseDriver::parse()
{
  std::cout << "parse()\n";
  std::fstream file;
  file.open(m_file_name.c_str());

  if (file.is_open()) {
    std::string line;
    std::vector<std::string> split_line;

    // run through file parsing each line
    while (file.good()) {
      // get line from file, strip comments and leading/subleading whitespace
      std::getline(file, line);
      line = cleanUpLine(line);
      // std::cout << "=====================================\n";
      // std::cout << line << "\n";

      split_line = split(line);
      if (split_line.size() < 1) continue;

      addLine(split_line);
    }
    file.close();
  }
}

// -----------------------------------------------------------------------------
void ParseDriver::addLine(std::vector<std::string> split_line)
{
  // std::cout << "-------------------------------------\n";
  size_t num_elements = split_line.size();
  for (size_t it = 0; it != num_elements; ++it) {
    std::cout << "\t" << split_line.at(it) << "\n";
  }
}
