#include <cmath>

#include "include/Event.h"
#include "AtlasSFrameUtils/include/CycleMacros.h"

ClassImp(Event)

// ----------------------------------------------------------------------------
Event::Event( const ::Long64_t& master
            , const char* prefix
            , bool is_data
            )
            : D3PDReader::EventInfoD3PDObject(master, prefix, is_data)
            , m_pile_up_weight(1.)
            , m_lepton_eff_weight(1.)
            , m_trigger_weight(1.)
            , m_cross_section_weight(1.)
            , m_b_tag_weight(1.)
{
  // do nothing
}

// ----------------------------------------------------------------------------
void Event::clear()
{
  m_event_desc.clear();

  m_pile_up_weight       = 0.;
  m_lepton_eff_weight    = 0.;
  m_trigger_weight       = 0.;
  m_cross_section_weight = 0.;
  m_b_tag_weight         = 0.;
}

// ----------------------------------------------------------------------------
double Event::getPileUpWeight()
{
  return m_pile_up_weight;
}

// ----------------------------------------------------------------------------
double Event::getLeptonEffWeight()
{
  return m_lepton_eff_weight;
}

// ----------------------------------------------------------------------------
double Event::getTriggerWeight()
{
  return m_trigger_weight;
}

// ----------------------------------------------------------------------------
double Event::getCrossSectionWeight()
{
  return m_cross_section_weight;
}

// ----------------------------------------------------------------------------
double Event::getBTagWeight()
{
  return m_b_tag_weight;
}

// ----------------------------------------------------------------------------
void Event::setPileUpWeight(double weight)
{
  m_pile_up_weight = weight;
}

// ----------------------------------------------------------------------------
void Event::setLeptonEffWeight(double weight)
{
  m_lepton_eff_weight = weight;
}

// ----------------------------------------------------------------------------
void Event::setTriggerWeight(double weight)
{
  m_trigger_weight = weight;
}

// ----------------------------------------------------------------------------
void Event::setCrossSectionWeight(double weight)
{
  m_cross_section_weight = weight;
}

// ----------------------------------------------------------------------------
void Event::setBTagWeight(double weight)
{
  m_b_tag_weight = weight;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription* Event::getEventDesc()
{
  return &m_event_desc;
}
