#include "include/WeightHandler.h"
#include <iostream>

// -----------------------------------------------------------------------------
Selection::WeightHandler::WeightHandler() : m_do_mc_event_weight(false)
                                          , m_do_pile_up_weight(false)
                                          , m_do_lumi_weight(false)
                                          , m_do_trigger_weight(false)
                                          , m_do_lepton_weight(false)
                                          , m_do_b_tag_weight(false)
                                          , m_do_cf_weight(false)
                                          , m_do_fake_weight(false)
                                          , m_num_events(1.)
                                          , m_mc_channel(0)
                                          , m_target_lumi(1)
                                          , m_lumi_weight(NULL)
                                          , m_lumi_weight_prepped(false)
{
  // do nothing
}

// -----------------------------------------------------------------------------
// Selection::WeightHandler::WeightHandler(const Selection::WeightHandler& rhs)//:
Selection::WeightHandler::WeightHandler(const Selection::WeightHandler& rhs) :
  m_do_mc_event_weight( rhs.getDoMcEventWeight()),
  m_do_pile_up_weight(  rhs.getDoPileUpWeight()),
  m_do_lumi_weight(     rhs.getDoLumiWeight()),
  m_do_trigger_weight(  rhs.getDoTriggerWeight()),
  m_do_lepton_weight(   rhs.getDoLeptonWeight()),
  m_do_b_tag_weight(    rhs.getDoBTagWeight()),
  m_do_cf_weight(       rhs.getDoCfWeight()),
  m_do_fake_weight(     rhs.getDoFakeWeight()),
  m_num_events(         rhs.getNumEvents()),
  m_mc_channel(         rhs.getMcChannel()),
  m_target_lumi(        rhs.getTargetLumi()),
  m_lumi_weight(        NULL),
  m_lumi_weight_prepped(false)
{
  // do nothing
}

// -----------------------------------------------------------------------------
Selection::WeightHandler::~WeightHandler()
{
  // std::cout << "destructor\n";
  // if (m_lumi_weight != NULL) {
  //   std::cout << "deleting lumi weight: " << m_lumi_weight << "\n";
  //   delete m_lumi_weight;
  // }
}

// -----------------------------------------------------------------------------
Selection::WeightHandler&
    Selection::WeightHandler::operator=(const Selection::WeightHandler& rhs)
{
    m_do_mc_event_weight = rhs.getDoMcEventWeight();
    m_do_pile_up_weight  = rhs.getDoPileUpWeight();
    m_do_lumi_weight     = rhs.getDoLumiWeight();
    m_do_trigger_weight  = rhs.getDoTriggerWeight();
    m_do_lepton_weight   = rhs.getDoLeptonWeight();
    m_do_b_tag_weight    = rhs.getDoBTagWeight();
    m_do_cf_weight       = rhs.getDoCfWeight();
    m_do_fake_weight     = rhs.getDoFakeWeight();

    m_num_events  = rhs.getNumEvents();
    m_mc_channel  = rhs.getMcChannel();
    m_target_lumi = rhs.getTargetLumi();

    return *this;
}

// -----------------------------------------------------------------------------
std::string Selection::WeightHandler::getWeightString()
{
  std::stringstream weight_string;
  weight_string << "(1.";

  if( m_do_mc_event_weight ) {
    weight_string << " * mc_event_weight";
  }
  if( m_do_pile_up_weight ) {
    weight_string << " * pile_up_weight";
  }
  if( m_do_lumi_weight ) {
    // if (m_lumi_weight == NULL) {
    if (m_lumi_weight_prepped == false) {
      std::cout << "Preparing LumiWeight object"
                << "\n\tmc_channel: " << m_mc_channel
                << "\n\ttarget_lumi: " << m_target_lumi
                << "\n";
      // TODO make files configurable
      m_lumi_weight = NULL;
      m_lumi_weight = new LumiWeight( "data/cross_sections.txt"
                                    , m_mc_channel
                                    , m_target_lumi
                                    , m_num_events
                                    );
      m_lumi_weight_prepped = true;
    }
    weight_string << " * ( " << m_lumi_weight->getLumiWeight() << ")";
  }
  if( m_do_trigger_weight ) {
    weight_string << " * trigger_weight";
  }
  if( m_do_lepton_weight ) {
    weight_string << " * lepton_weight";
  }
  if( m_do_b_tag_weight ) {
    weight_string << " * b_tag_weight";
  }
  if( m_do_cf_weight ) {
    weight_string << " * charge_flip_weight";
  }
  if( m_do_fake_weight ) {
    weight_string << " * fake_weight_nom";
  }

  weight_string << " ) ";

  return weight_string.str();
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setGlobalDoMcEventWeight(bool do_weight)
{
  m_do_mc_event_weight = do_weight;
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setGlobalDoPileUpWeight(bool do_weight)
{
  m_do_pile_up_weight = do_weight;
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setGlobalDoLumiWeight(bool do_weight)
{
  m_do_lumi_weight = do_weight;
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setGlobalDoTriggerWeight(bool do_weight)
{
  m_do_trigger_weight = do_weight;
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setGlobalDoLeptonWeight(bool do_weight)
{
  m_do_lepton_weight = do_weight;
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setGlobalDoBTagWeight(bool do_weight)
{
  m_do_b_tag_weight = do_weight;
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setGlobalDoCfWeight(bool do_weight)
{
  m_do_cf_weight = do_weight;
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setGlobalDoFakeWeight(bool do_weight)
{
  m_do_fake_weight = do_weight;
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setLocalDoMcEventWeight(bool do_weight)
{
  m_do_mc_event_weight = (m_do_mc_event_weight && do_weight);
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setLocalDoPileUpWeight(bool do_weight)
{
  m_do_pile_up_weight = (m_do_pile_up_weight && do_weight);
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setLocalDoLumiWeight(bool do_weight)
{
  m_do_lumi_weight = (m_do_lumi_weight && do_weight);
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setLocalDoTriggerWeight(bool do_weight)
{
  m_do_trigger_weight = (m_do_trigger_weight && do_weight);
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setLocalDoLeptonWeight(bool do_weight)
{
  m_do_lepton_weight = (m_do_lepton_weight && do_weight);
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setLocalDoBTagWeight(bool do_weight)
{
  m_do_b_tag_weight = (m_do_b_tag_weight && do_weight);
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setLocalDoCfWeight(bool do_weight)
{
  m_do_cf_weight = (m_do_cf_weight && do_weight);
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setLocalDoFakeWeight(bool do_weight)
{
  m_do_fake_weight = (m_do_fake_weight && do_weight);
}

// // -----------------------------------------------------------------------------
// void Selection::WeightHandler::setNumMcEvents(int num_mc_evt)
// {
//   m_num_mc_events = num_mc_evt;
// }

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setNumEvents(double num_events)
{
  m_num_events = num_events;
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setMcChannel(int mc_channel)
{
  m_mc_channel = mc_channel;
}

// -----------------------------------------------------------------------------
void Selection::WeightHandler::setTargetLumi(int target_lumi)
{
  m_target_lumi = target_lumi;
}

// -----------------------------------------------------------------------------
bool Selection::WeightHandler::getDoMcEventWeight() const
{
  return m_do_mc_event_weight;
}

// -----------------------------------------------------------------------------
bool Selection::WeightHandler::getDoPileUpWeight() const
{
  return m_do_pile_up_weight;
}

// -----------------------------------------------------------------------------
bool Selection::WeightHandler::getDoLumiWeight() const
{
  return m_do_lumi_weight;
}

// -----------------------------------------------------------------------------
bool Selection::WeightHandler::getDoTriggerWeight() const
{
  return m_do_trigger_weight;
}

// -----------------------------------------------------------------------------
bool Selection::WeightHandler::getDoLeptonWeight() const
{
  return m_do_lepton_weight;
}

// -----------------------------------------------------------------------------
bool Selection::WeightHandler::getDoBTagWeight() const
{
  return m_do_b_tag_weight;
}

// -----------------------------------------------------------------------------
bool Selection::WeightHandler::getDoCfWeight() const
{
  return m_do_cf_weight;
}

// -----------------------------------------------------------------------------
bool Selection::WeightHandler::getDoFakeWeight() const
{
  return m_do_fake_weight;
}

//// -----------------------------------------------------------------------------
//int Selection::WeightHandler::getNumMCEvents() const
//{
//  return m_num_mc_events;
//}

// -----------------------------------------------------------------------------
double Selection::WeightHandler::getNumEvents() const
{
  return m_num_events;
}

// -----------------------------------------------------------------------------
int Selection::WeightHandler::getMcChannel() const
{
  return m_mc_channel;
}

// -----------------------------------------------------------------------------
int Selection::WeightHandler::getTargetLumi() const
{
  return m_target_lumi;
}
