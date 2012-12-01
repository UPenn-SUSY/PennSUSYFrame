#include "include/MasterConfigParser.h"

// -----------------------------------------------------------------------------
MasterConfigParser::MasterConfigParser(std::string file_name) :
    ParseDriver(file_name)
{
  clear();
}

// -----------------------------------------------------------------------------
MasterConfigParser::~MasterConfigParser()
{
  // do nothing
}

// -----------------------------------------------------------------------------
std::string MasterConfigParser::getSelectionFile()
{
  return m_cut_file_name;
}

// -----------------------------------------------------------------------------
std::string MasterConfigParser::getHistInfoFile()
{
  return m_hist_file_name;
}

// -----------------------------------------------------------------------------
void MasterConfigParser::config()
{
  std::cout << "\tcut_file : "  << m_cut_file_name    << "\n";
  std::cout << "\thist_file: "  << m_hist_file_name << "\n";

  std::cout << "\tin files:\n";
  size_t term = m_in_file_list.size();
  for (size_t it = 0; it != term; ++it)
    std::cout << "\t\t" << m_in_file_list.at(it) << "\n";
}

// -----------------------------------------------------------------------------
void MasterConfigParser::clear()
{
  m_in_file_block = false;
  m_cut_file_name = "";
  m_hist_file_name = "";
  m_in_file_list.clear();
}

// -----------------------------------------------------------------------------
void MasterConfigParser::addLine(std::vector<std::string> split_line)
{
  // get key
  std::string key = split_line.at(0);

  // in file list block
  if (m_in_file_block) {
    if (key == "end")
      m_in_file_block = false;
    else
      m_in_file_list.push_back(key);
    return;
  }

  if (key.find("cut_file") != std::string::npos)
    m_cut_file_name = split_line.at(1);
  else if (key.find("hist_file") != std::string::npos)
    m_hist_file_name = split_line.at(1);
  else if (key.find("in_files") != std::string::npos)
    m_in_file_block = true;
  else
    std::cout << "WARNING! The key \'" << key
              << "\' is invalid. Please check your inputs\n";
}
