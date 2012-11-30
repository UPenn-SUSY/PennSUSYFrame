#include "include/CutConfigParser.h"

// -----------------------------------------------------------------------------
CutConfigParser::CutConfigParser(std::string file_name) :
    ParseDriver(file_name)
{
  clear();
}

// -----------------------------------------------------------------------------
void CutConfigParser::clear()
{
  m_in_block = false;
  m_name = "";
  m_pass_event = 0;
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
      throw("Need to open a config block");
    }
  }
  else {
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

    // else if (key.find("var") != std::string::npos)
    //   m_var_exp = split_line.at(1);
    // else if (key.find("x_bins") != std::string::npos)
    //   m_x_bins = stringToInt(split_line.at(1));
    // else if (key.find("x_min") != std::string::npos)
    //   m_x_min = stringToFloat(split_line.at(1));
    // else if (key.find("x_max") != std::string::npos)
    //   m_x_max = stringToFloat(split_line.at(1));
    // else if (key.find("title") != std::string::npos)
    //   m_title = split_line.at(1);
    // else if (key.find("x_axis") != std::string::npos)
    //   m_x_axis = split_line.at(1);
    // else if (key.find("y_axis") != std::string::npos)
    //   m_y_axis = split_line.at(1);
  }
}

// -----------------------------------------------------------------------------
void CutConfigParser::configEventSelection()
{
  std::cout << "\tname   : "  << m_name    << "\n";
  std::cout << "\tpass event: " << m_pass_event.toInt() << "\n";
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
