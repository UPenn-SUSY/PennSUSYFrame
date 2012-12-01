#include "include/CutConfigParser.h"

// -----------------------------------------------------------------------------
CutConfigParser::CutConfigParser(std::string file_name) :
    ParseDriver(file_name)
{
  clear();
}

// -----------------------------------------------------------------------------
CutConfigParser::~CutConfigParser()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void CutConfigParser::clear()
{
  m_in_block = false;
  m_name = "";

  m_pass_event    = 0;
  m_reverse_event = 0;
  m_pass_sr       = 0;
  m_reverse_sr    = 0;
}

// -----------------------------------------------------------------------------
void CutConfigParser::addLine(std::vector<std::string> split_line)
{
  // get key
  std::string key = split_line.at(0);
  // std::cout << "key: " << key << "\n";

  if (!m_in_block) {
    if (key.find("cut") != std::string::npos) {
      m_in_block = true;
      m_name = split_line.at(1);
    }
    else {
      std::cout << "Need to open a config block\n";
      std::cout << "Cut config blocks start with a line of the form:\n";
      std::cout << "cut: cut_name\n";
      throw("Need to open a config block");
    }
    return;
  }

  if (key.find("end") != std::string::npos) {
    std::cout << "Found end of block\n";
    configEventSelection();
    clear();
  }
  else if (key.find("pass_grl") != std::string::npos)
    m_pass_event.setPassGrl(stringToBool(split_line.at(1)));
  else if (key.find("pass_incomplete_event") != std::string::npos)
    m_pass_event.setPassIncompleteEvent(stringToBool(split_line.at(1)));
  else if (key.find("pass_lar_error") != std::string::npos)
    m_pass_event.setPassLarError(stringToBool(split_line.at(1)));
  else if (key.find("pass_tile_error") != std::string::npos)
    m_pass_event.setPassTileError(stringToBool(split_line.at(1)));
  else if (key.find("pass_tile_hot_spot") != std::string::npos)
    m_pass_event.setPassTileHotSpot(stringToBool(split_line.at(1)));
  else if (key.find("pass_bad_jets") != std::string::npos)
    m_pass_event.setPassBadJets(stringToBool(split_line.at(1)));
  else if (key.find("pass_primary_vertex") != std::string::npos)
    m_pass_event.setPassPrimaryVertex(stringToBool(split_line.at(1)));
  else if (key.find("pass_bad_muons") != std::string::npos)
    m_pass_event.setPassBadMuons(stringToBool(split_line.at(1)));
  else if (key.find("pass_cosmic_muons") != std::string::npos)
    m_pass_event.setPassCosmicMuons(stringToBool(split_line.at(1)));
  else if (key.find("pass_hfor") != std::string::npos)
    m_pass_event.setPassHFOR(stringToBool(split_line.at(1)));
  else if (key.find("pass_ge_2_good_leptons") != std::string::npos)
    m_pass_event.setPassGE2GoodLeptons(stringToBool(split_line.at(1)));
  else if (key.find("pass_2_good_leptons") != std::string::npos)
    m_pass_event.setPass2GoodLeptons(stringToBool(split_line.at(1)));
  else if (key.find("pass_mll") != std::string::npos)
    m_pass_event.setPassMll(stringToBool(split_line.at(1)));
  else if (key.find("pass_2_signal_leptons") != std::string::npos)
    m_pass_event.setPass2SignalLeptons(stringToBool(split_line.at(1)));
  else if (key.find("pass_trigger_match") != std::string::npos)
    m_pass_event.setPassTriggerMatch(stringToBool(split_line.at(1)));
  else if (key.find("pass_flavor") != std::string::npos)
    m_pass_event.setFlavorChannel(stringToFlavor(split_line.at(1)));
  else if (key.find("pass_ee_trigger") != std::string::npos)
    m_pass_event.setEETrigger(stringToBool(split_line.at(1)));
  else if (key.find("pass_mm_trigger") != std::string::npos)
    m_pass_event.setMMTrigger(stringToBool(split_line.at(1)));
  else if (key.find("pass_em_trigger") != std::string::npos)
    m_pass_event.setEMTrigger(stringToBool(split_line.at(1)));
  else if (key.find("pass_me_trigger") != std::string::npos)
    m_pass_event.setMETrigger(stringToBool(split_line.at(1)));
  else if (key.find("pass_sign") != std::string::npos)
    m_pass_event.setSignChannel(stringToSign(split_line.at(1)));
  else
    std::cout << "WARNING! The key \'" << key
              << "\' is invalid. Please check your inputs\n";
}

// -----------------------------------------------------------------------------
void CutConfigParser::configEventSelection()
{
  std::cout << "\tname   : "       << m_name    << "\n";
  std::cout << "\tpass event: "    << m_pass_event.toInt()    << "\n";
  std::cout << "\treverse event: " << m_reverse_event.toInt() << "\n";
  std::cout << "\tpass sr: "       << m_pass_sr.toInt()       << "\n";
  std::cout << "\treverse sr: "    << m_reverse_sr.toInt()    << "\n";

  Selection::EventSelection tmp_selection( m_pass_event
                                         , m_reverse_event
                                         , m_pass_sr
                                         , m_reverse_sr
                                         );
  std::cout << "adding selection " << m_name << " to vector\n";
  m_event_selection.push_back(tmp_selection);
}

// -----------------------------------------------------------------------------
FLAVOR_CHANNEL CutConfigParser::stringToFlavor(std::string to_convert)
{
  if (to_convert == "ee")   return FLAVOR_EE;
  if (to_convert == "mm")   return FLAVOR_MM;
  if (to_convert == "em")   return FLAVOR_EM;
  if (to_convert == "none") return FLAVOR_NONE;

  std::cout << "Warning: flavor channel \"" << to_convert << "\" not valid\n"
            << "\tSetting to no flavor\n";
  return FLAVOR_NONE;
}

// -----------------------------------------------------------------------------
SIGN_CHANNEL CutConfigParser::stringToSign(std::string to_convert)
{
  if (to_convert == "os")   return SIGN_OS;
  if (to_convert == "ss")   return SIGN_SS;
  if (to_convert == "none") return SIGN_NONE;

  std::cout << "Warning: sign channel \"" << to_convert << "\" not valid\n"
            << "\tSetting to no sign\n";
  return SIGN_NONE;
}
