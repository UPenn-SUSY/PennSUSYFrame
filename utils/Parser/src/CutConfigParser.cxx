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
                                // , double num_events
                                )
                                : ParseDriver(file_name)
                                , m_global_weight_handler(global_weights)
                                                                                                // , m_num_events(num_events)
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

  m_tmp_additional_cuts = "1";

  // Reset weight handler to global weights
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

  // TODO this is ugly. clean up!
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
  else if (key.find("pass_calo_problem_jets") != std::string::npos)
    m_tmp_pass_event.setPassCaloProblemJets(valueToBool(split_line));
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
  else if (key.find("pass_prompt_leptons") != std::string::npos)
    m_tmp_pass_event.setTruthPrompt(valueToBool(split_line));
  else if (key.find("pass_sign") != std::string::npos)
    m_tmp_pass_event.setSignChannel(valueToSign(split_line));
  else if (key.find("pass_truth_sign") != std::string::npos)
    m_tmp_pass_event.setTruthSignChannel(valueToSign(split_line));
  else if (key.find("pass_cf_cand") != std::string::npos)
    m_tmp_pass_event.setCFCandidate(valueToBool(split_line));

  else if (key.find("pass_sr_osjveto") != std::string::npos)
    m_tmp_pass_event.setSROSJVeto(valueToBool(split_line));
  else if (key.find("pass_sr_ssjets") != std::string::npos)
    m_tmp_pass_event.setSRSSJets(valueToBool(split_line));
  else if (key.find("pass_sr_2jets") != std::string::npos)
    m_tmp_pass_event.setSR2Jets(valueToBool(split_line));
  else if (key.find("pass_sr_mt2a") != std::string::npos)
    m_tmp_pass_event.setSRMT2a(valueToBool(split_line));
  else if (key.find("pass_sr_mt2b") != std::string::npos)
    m_tmp_pass_event.setSRMT2b(valueToBool(split_line));

  else if (key.find("pass_l_jet_veto") != std::string::npos)
    m_tmp_pass_sr.setPassLJetVeto( valueToBool(split_line));
  else if (key.find("pass_b_jet_veto") != std::string::npos)
    m_tmp_pass_sr.setPassBJetVeto(valueToBool(split_line));
  else if (key.find("pass_f_jet_veto") != std::string::npos)
    m_tmp_pass_sr.setPassFJetVeto(valueToBool(split_line));
  else if (key.find("pass_2_l_jet") != std::string::npos)
    m_tmp_pass_sr.setPassSR2JetsNumLJet(valueToBool(split_line));
  else if (key.find("pass_z_veto") != std::string::npos)
    m_tmp_pass_sr.setPassZVeto(valueToBool(split_line));
  else if (key.find("pass_top_veto") != std::string::npos)
    m_tmp_pass_sr.setPassTopVeto(valueToBool(split_line));
  else if (key.find("pass_sr_osjveto_met") != std::string::npos)
    m_tmp_pass_sr.setPassSROSJVetoMetRel(valueToBool(split_line));
  else if (key.find("pass_sr_ssjets_met") != std::string::npos)
    m_tmp_pass_sr.setPassSRSSJetsMetRel(valueToBool(split_line));
  else if (key.find("pass_sr_2jets_met") != std::string::npos)
    m_tmp_pass_sr.setPassSR2JetsMetRel(valueToBool(split_line));
  else if (key.find("pass_sr_mt2_met") != std::string::npos)
    m_tmp_pass_sr.setPassSRMT2MetRel(valueToBool(split_line));
  else if (key.find("pass_sr_mt2a_mt2") != std::string::npos)
    m_tmp_pass_sr.setPassSRMT2aMt2(valueToBool(split_line));
  else if (key.find("pass_sr_mt2b_mt2") != std::string::npos)
    m_tmp_pass_sr.setPassSRMT2bMt2(valueToBool(split_line));

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
  else if (key.find("additional_cut") != std::string::npos) {
    m_tmp_additional_cuts += " && (";
    m_tmp_additional_cuts += getValue(split_line);
    m_tmp_additional_cuts += ")";
  }
  else
    std::cout << "WARNING! The key \'" << key
              << "\' is invalid. Please check your inputs\n";
}

// -----------------------------------------------------------------------------
void CutConfigParser::configEventSelection()
{
  // create Event selection object for this cut
  Selection::EventSelection tmp_selection( m_tmp_pass_event
                                         , m_tmp_reverse_event
                                         , m_tmp_pass_sr
                                         , m_tmp_reverse_sr
                                         );
  // Add any additional cuts to this event selection object
  tmp_selection.setAdditionalCutString(m_tmp_additional_cuts);

  // Add selection and weight handler to dictionary
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
