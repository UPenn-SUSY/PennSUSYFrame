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
{
  // do nothing
}

// -----------------------------------------------------------------------------
Selection::WeightHandler::WeightHandler(const Selection::WeightHandler& rhs):
    m_do_mc_event_weight(rhs.getDoMcEventWeight()),
    m_do_pile_up_weight( rhs.getDoPileUpWeight()),
    m_do_lumi_weight(    rhs.getDoLumiWeight()),
    m_do_trigger_weight( rhs.getDoTriggerWeight()),
    m_do_lepton_weight(  rhs.getDoLeptonWeight()),
    m_do_b_tag_weight(   rhs.getDoBTagWeight()),
    m_do_cf_weight(      rhs.getDoCfWeight()),
    m_do_fake_weight(    rhs.getDoFakeWeight())
{
  // do nothing
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
    // TODO include target lumi and num events
    weight_string << " * (k_factor * eff_times_cross_section)";
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

  weight_string << " ) * ";

  return weight_string.str();
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

