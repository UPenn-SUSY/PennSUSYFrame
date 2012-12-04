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
std::string MasterConfigParser::getOutFile()
{
  return m_out_file_name;
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
TChain* MasterConfigParser::getInputChain()
{
  TChain* chain = new TChain("output");
  size_t num_files = m_in_file_list.size();
  for (size_t it = 0; it != num_files; ++it) {
    chain->Add(m_in_file_list.at(it).c_str());
  }
  return chain;
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
Selection::WeightHandler MasterConfigParser::getGlobalWeightHandler()
{
  return m_global_weight_handler;
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
    m_cut_file_name = getValue(split_line);
  else if (key.find("hist_file") != std::string::npos)
    m_hist_file_name = getValue(split_line);
  else if (key.find("out_file") != std::string::npos)
    m_out_file_name = getValue(split_line);
  else if (key.find("mc_event_weight") != std::string::npos)
    m_global_weight_handler.setGlobalDoMcEventWeight(valueToBool(split_line));
  else if (key.find("pile_up_weight") != std::string::npos)
    m_global_weight_handler.setGlobalDoPileUpWeight(valueToBool(split_line));
  else if (key.find("lumi_weight") != std::string::npos)
    m_global_weight_handler.setGlobalDoLumiWeight(valueToBool(split_line));
  else if (key.find("trigger_weight") != std::string::npos)
    m_global_weight_handler.setGlobalDoTriggerWeight(valueToBool(split_line));
  else if (key.find("lepton_weight") != std::string::npos)
    m_global_weight_handler.setGlobalDoLeptonWeight(valueToBool(split_line));
  else if (key.find("b_tag_weight") != std::string::npos)
    m_global_weight_handler.setGlobalDoBTagWeight(valueToBool(split_line));
  else if (key.find("cf_weight") != std::string::npos)
    m_global_weight_handler.setGlobalDoCfWeight(valueToBool(split_line));
  else if (key.find("fake_weight") != std::string::npos)
    m_global_weight_handler.setGlobalDoFakeWeight(valueToBool(split_line));
  else if (key.find("num_mc") != std::string::npos)
    m_global_weight_handler.setNumMcEvents(valueToInt(split_line));
  else if (key.find("target_lumi") != std::string::npos)
    m_global_weight_handler.setTargetLumi(valueToInt(split_line));
  else if (key.find("in_files") != std::string::npos)
    m_in_file_block = true;
  else
    std::cout << "WARNING! The key \'" << key
              << "\' is invalid. Please check your inputs\n";
}
