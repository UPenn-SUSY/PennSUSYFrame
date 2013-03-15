#include "include/MasterConfigParser.h"
#include "Selection/include/LumiWeight.h"

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
std::string MasterConfigParser::getPTNTFile()
{
  return m_ptnt_file_name;
}

// -----------------------------------------------------------------------------
std::string MasterConfigParser::getHistFile()
{
  return m_hist_file_name;
}

// -----------------------------------------------------------------------------
std::string MasterConfigParser::getSelectionFile()
{
  return m_cut_config_file_name;
}

// -----------------------------------------------------------------------------
std::string MasterConfigParser::getHistInfoFile()
{
  return m_hist_config_file_name;
}

// -----------------------------------------------------------------------------
std::vector<std::string> MasterConfigParser::getInputFileList()
{
  return m_in_file_list;
}

// -----------------------------------------------------------------------------
double MasterConfigParser::getNumEvents()
{
  return LumiWeight::getNumEventsFromFiles(m_in_file_list);
}

// -----------------------------------------------------------------------------
double MasterConfigParser::getPTNTNumEvents()
{
  return LumiWeight::getNumEventsFromFiles(m_in_file_list);

  // size_t num_files = m_in_file_list.size();
  // double num_events = 0.;

  // for (size_t file_itr = 0; file_itr != num_files; ++file_itr) {
  //   TFile* f = new TFile(m_in_file_list.at(file_itr).c_str());
  //   TVectorD* var = dynamic_cast<TVectorD*>(f->Get("num_events"));
  //   num_events += (*var)[0];
  // }
  // return num_events;
}

// -----------------------------------------------------------------------------
TChain* MasterConfigParser::getInputChain()
{
  return getInputChain(m_in_tree_name);
  // // TChain* chain = new TChain("output");
  // TChain* chain = new TChain(m_in_tree_name.c_str());
  // size_t num_files = m_in_file_list.size();
  // for (size_t it = 0; it != num_files; ++it) {
  //   chain->Add(m_in_file_list.at(it).c_str());
  // }
  // return chain;
}

// -----------------------------------------------------------------------------
TChain* MasterConfigParser::getInputChain(std::string tree_name)
{
  // TChain* chain = new TChain("output");
  TChain* chain = new TChain(tree_name.c_str());
  size_t num_files = m_in_file_list.size();
  for (size_t it = 0; it != num_files; ++it) {
    chain->Add(m_in_file_list.at(it).c_str());
  }
  return chain;
}

// -----------------------------------------------------------------------------
TChain* MasterConfigParser::getPTNTChain(std::string tree_name)
{
  // TChain* chain = new TChain("output");
  TChain* chain = new TChain(tree_name.c_str());
  chain->Add(m_ptnt_file_name.c_str());
  // size_t num_files = m_in_file_list.size();
  // for (size_t it = 0; it != num_files; ++it) {
  //   chain->Add(m_in_file_list.at(it).c_str());
  // }
  return chain;
}

// -----------------------------------------------------------------------------
void MasterConfigParser::config()
{
  std::cout << "\tcut_file : "  << m_cut_config_file_name  << "\n";
  std::cout << "\thist_file: "  << m_hist_config_file_name << "\n";

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
int MasterConfigParser::getChannelNum()
{
  return m_channel_num;
}

// -----------------------------------------------------------------------------
void MasterConfigParser::clear()
{
  m_in_file_block = false;
  m_cut_config_file_name = "";
  m_hist_config_file_name = "";

  m_ptnt_file_name = "";
  m_hist_file_name = "";

  m_in_tree_name = "output";
  m_in_file_list.clear();

  m_channel_num = 0;
  m_target_lumi = 1;
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

  // TODO this is ugly. clean up
  if (key.find("cut_config") != std::string::npos)
    m_cut_config_file_name = getValue(split_line);
  else if (key.find("hist_config") != std::string::npos)
    m_hist_config_file_name = getValue(split_line);

  else if (key.find("ptnt_file") != std::string::npos)
    m_ptnt_file_name = getValue(split_line);
  else if (key.find("hist_file") != std::string::npos)
    m_hist_file_name = getValue(split_line);

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
  else if (key.find("mc_channel") != std::string::npos)
    m_global_weight_handler.setMcChannel(valueToInt(split_line));
  else if (key.find("target_lumi") != std::string::npos)
    m_global_weight_handler.setTargetLumi(valueToInt(split_line));

  else if (key.find("in_tree") != std::string::npos)
    m_in_tree_name = getValue(split_line);

  else if (key.find("in_files") != std::string::npos)
    m_in_file_block = true;
  else if (key.find("channel_num") != std::string::npos)
    m_channel_num = valueToInt(split_line);
  else
    std::cout << "WARNING! The key \'" << key
              << "\' is invalid. Please check your inputs\n";
}
