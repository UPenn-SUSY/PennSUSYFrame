#include "include/CutConfigParser.h"

// -----------------------------------------------------------------------------
CutConfigParser::CutConfigParser(std::string file_name) :
    ParseDriver(file_name)
{
  clear();
}

// -----------------------------------------------------------------------------
CutConfigParser::CutConfigParser( std::string file_name
                                , const Selection::WeightHandler& global_weights
                                )
                                : ParseDriver(file_name)
                                , m_global_weight_handler(global_weights)
{
  clear();
}

// -----------------------------------------------------------------------------
CutConfigParser::~CutConfigParser()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void CutConfigParser::setGlobalWeightHandler(const Selection::WeightHandler& wh)
{
  m_global_weight_handler = wh;
}

// -----------------------------------------------------------------------------
std::map<std::string, Selection::EventSelection>
    CutConfigParser::getSelectionMap()
{
  return m_event_selection;
}

// -----------------------------------------------------------------------------
std::map<std::string, Selection::WeightHandler> CutConfigParser::getWeightMap()
{
  return m_weight_handler;
}

// -----------------------------------------------------------------------------
void CutConfigParser::clear()
{
  m_in_block = false;
  m_name = "";

  m_tmp_pass_event    = 0;
  m_tmp_reverse_event = 0;
  m_tmp_pass_sr       = 0;
  m_tmp_reverse_sr    = 0;

  m_tmp_weight_handler = m_global_weight_handler;
}

// -----------------------------------------------------------------------------
void CutConfigParser::addLine(std::vector<std::string> split_line)
{
  // get key
  std::string key = split_line.at(0);

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
    configEventSelection();
    clear();
  }
  else if (key.find("pass_grl") != std::string::npos)
    m_tmp_pass_event.setPassGrl(valueToBool(split_line));
  else if (key.find("pass_incomplete_event") != std::string::npos)
    m_tmp_pass_event.setPassIncompleteEvent(valueToBool(split_line));
  else if (key.find("pass_lar_error") != std::string::npos)
    m_tmp_pass_event.setPassLarError(valueToBool(split_line));
  else if (key.find("pass_tile_error") != std::string::npos)
    m_tmp_pass_event.setPassTileError(valueToBool(split_line));
  else if (key.find("pass_tile_hot_spot") != std::string::npos)
    m_tmp_pass_event.setPassTileHotSpot(valueToBool(split_line));
  else if (key.find("pass_bad_jets") != std::string::npos)
    m_tmp_pass_event.setPassBadJets(valueToBool(split_line));
  else if (key.find("pass_primary_vertex") != std::string::npos)
    m_tmp_pass_event.setPassPrimaryVertex(valueToBool(split_line));
  else if (key.find("pass_bad_muons") != std::string::npos)
    m_tmp_pass_event.setPassBadMuons(valueToBool(split_line));
  else if (key.find("pass_cosmic_muons") != std::string::npos)
    m_tmp_pass_event.setPassCosmicMuons(valueToBool(split_line));
  else if (key.find("pass_hfor") != std::string::npos)
    m_tmp_pass_event.setPassHFOR(valueToBool(split_line));
  else if (key.find("pass_ge_2_good_leptons") != std::string::npos)
    m_tmp_pass_event.setPassGE2GoodLeptons(valueToBool(split_line));
  else if (key.find("pass_2_good_leptons") != std::string::npos)
    m_tmp_pass_event.setPass2GoodLeptons(valueToBool(split_line));
  else if (key.find("pass_mll") != std::string::npos)
    m_tmp_pass_event.setPassMll(valueToBool(split_line));
  else if (key.find("pass_2_signal_leptons") != std::string::npos)
    m_tmp_pass_event.setPass2SignalLeptons(valueToBool(split_line));
  else if (key.find("pass_trigger_match") != std::string::npos)
    m_tmp_pass_event.setPassTriggerMatch(valueToBool(split_line));
  else if (key.find("pass_flavor") != std::string::npos)
    m_tmp_pass_event.setFlavorChannel(valueToFlavor(split_line));
  else if (key.find("pass_ee_trigger") != std::string::npos)
    m_tmp_pass_event.setEETrigger(valueToBool(split_line));
  else if (key.find("pass_mm_trigger") != std::string::npos)
    m_tmp_pass_event.setMMTrigger(valueToBool(split_line));
  else if (key.find("pass_em_trigger") != std::string::npos)
    m_tmp_pass_event.setEMTrigger(valueToBool(split_line));
  else if (key.find("pass_me_trigger") != std::string::npos)
    m_tmp_pass_event.setMETrigger(valueToBool(split_line));
  else if (key.find("pass_sign") != std::string::npos)
    m_tmp_pass_event.setSignChannel(valueToSign(split_line));
  else if (key.find("mc_event_weight") != std::string::npos)
    m_tmp_weight_handler.setLocalDoMcEventWeight(valueToBool(split_line));
  else if (key.find("pile_up_weight") != std::string::npos)
    m_tmp_weight_handler.setLocalDoPileUpWeight(valueToBool(split_line));
  else if (key.find("lumi_weight") != std::string::npos)
    m_tmp_weight_handler.setLocalDoLumiWeight(valueToBool(split_line));
  else if (key.find("trigger_weight") != std::string::npos)
    m_tmp_weight_handler.setLocalDoTriggerWeight(valueToBool(split_line));
  else if (key.find("lepton_weight") != std::string::npos)
    m_tmp_weight_handler.setLocalDoLeptonWeight(valueToBool(split_line));
  else if (key.find("b_tag_weight") != std::string::npos)
    m_tmp_weight_handler.setLocalDoBTagWeight(valueToBool(split_line));
  else if (key.find("cf_weight") != std::string::npos)
    m_tmp_weight_handler.setLocalDoCfWeight(valueToBool(split_line));
  else if (key.find("fake_weight") != std::string::npos)
    m_tmp_weight_handler.setLocalDoFakeWeight(valueToBool(split_line));
  else
    std::cout << "WARNING! The key \'" << key
              << "\' is invalid. Please check your inputs\n";
}

// -----------------------------------------------------------------------------
void CutConfigParser::configEventSelection()
{
  Selection::EventSelection tmp_selection( m_tmp_pass_event
                                         , m_tmp_reverse_event
                                         , m_tmp_pass_sr
                                         , m_tmp_reverse_sr
                                         );
  m_event_selection[m_name] = tmp_selection;
  m_weight_handler[m_name]  = m_tmp_weight_handler;
}

// -----------------------------------------------------------------------------
FLAVOR_CHANNEL CutConfigParser::valueToFlavor(
    std::vector<std::string> to_convert)
{
  return stringToFlavor(to_convert.at(1));
}

// -----------------------------------------------------------------------------
SIGN_CHANNEL CutConfigParser::valueToSign(
    std::vector<std::string> to_convert)
{
  return stringToSign(to_convert.at(1));
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
