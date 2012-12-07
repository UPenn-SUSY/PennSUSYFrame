#include <cmath>

#include "include/Event.h"
#include "AtlasSFrameUtils/include/CycleMacros.h"

ClassImp(Event)

// -----------------------------------------------------------------------------
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
            , m_mll(0.)
            , m_met_rel(0.)
            , m_mll_cached(false)
            , m_met_rel_cached(false)
{
  clear();
}

// -----------------------------------------------------------------------------
void Event::clear()
{
  m_event_desc.clear();
  m_sr_helper.clear();

  m_mc_event_weight         = 1.;
  m_pile_up_weight          = 1.;
  m_lepton_eff_weight       = 1.;
  m_trigger_weight          = 1.;
  m_cross_section_weight    = 1.;
  m_b_tag_weight            = 1.;
  m_k_factor                = 1.;
  m_eff_times_cross_section = 1.;
  m_fake_weight             = 1.;
  m_charge_flip_weight      = 1.;

  m_mc_channel_num = 0;

  m_mll     = 0.;
  m_met_rel = 0.;

  m_mll_cached     = false;
  m_met_rel_cached = false;
}

// -----------------------------------------------------------------------------
double Event::getMCEventWeight()
{
  return m_mc_event_weight;
}

// -----------------------------------------------------------------------------
double Event::getPileUpWeight()
{
  return m_pile_up_weight;
}

// -----------------------------------------------------------------------------
double Event::getLeptonEffWeight()
{
  return m_lepton_eff_weight;
}

// -----------------------------------------------------------------------------
double Event::getTriggerWeight()
{
  return m_trigger_weight;
}

// -----------------------------------------------------------------------------
double Event::getCrossSectionWeight()
{
  return m_cross_section_weight;
}

// -----------------------------------------------------------------------------
double Event::getBTagWeight()
{
  return m_b_tag_weight;
}

// -----------------------------------------------------------------------------
double Event::getKFactor()
{
  return m_k_factor;
}

// -----------------------------------------------------------------------------
double Event::getEffTimesXS()
{
  return m_eff_times_cross_section;
}
// -----------------------------------------------------------------------------
double Event::getFakeWeight()
{
  return m_fake_weight;
}
// -----------------------------------------------------------------------------
double Event::getChargeFlipWeight()
{
  return m_charge_flip_weight;
}
// -----------------------------------------------------------------------------
int Event::getMCChannelNum()
{
  return m_mc_channel_num;
}

// -----------------------------------------------------------------------------
void Event::setMCEventWeight(double weight)
{
  m_mc_event_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setPileUpWeight(double weight)
{
  m_pile_up_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setLeptonEffWeight(double weight)
{
  m_lepton_eff_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setTriggerWeight(double weight)
{
  m_trigger_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setCrossSectionWeight(double weight)
{
  m_cross_section_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setBTagWeight(double weight)
{
  m_b_tag_weight = weight;
}

// -----------------------------------------------------------------------------
void Event::setKFactor(double weight)
{
  m_k_factor = weight;
}

// -----------------------------------------------------------------------------
void Event::setEffTimesXS(double weight)
{
  m_eff_times_cross_section = weight;
}
// -----------------------------------------------------------------------------
void Event::setFakeWeight(double weight)
{
  m_fake_weight = weight;
}
// -----------------------------------------------------------------------------
void Event::setChargeFlipWeight(double weight)
{
  m_charge_flip_weight = weight;
}
// -----------------------------------------------------------------------------
void Event::setMCChannelNum(int channel)
{
  m_mc_channel_num = channel;
}

// -----------------------------------------------------------------------------
void Event::setMll(double mll)
{
  m_mll = mll;
  m_mll_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMt2(double mt2)
{
  m_mt2 = mt2;
  m_mt2_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setPtll(double ptll)
{
  m_ptll = ptll;
  m_ptll_cached = true;
}

// -----------------------------------------------------------------------------
void Event::setMetRel(double met_rel)
{
  m_met_rel = met_rel;
  m_met_rel_cached = true;
}

// -----------------------------------------------------------------------------
double Event::getMll()
{
  if (!m_mll_cached)
    std::cout << "WARNING! Asking for mll, but not yet cached!\n";
  return m_mll;
}

// -----------------------------------------------------------------------------
double Event::getMetRel()
{
  if (!m_met_rel_cached)
    std::cout << "WARNING! Asking for met_rel, but not yet cached!\n";
  return m_met_rel;
}

// -----------------------------------------------------------------------------
double Event::getMt2()
{
  if (!m_mt2_cached)
    std::cout << "WARNING! Asking for mt2, but not yet cached!\n";
  return m_mt2;
}
// -----------------------------------------------------------------------------
double Event::getPtll()
{
  if (!m_ptll_cached)
    std::cout << "WARNING! Asking for pt_ll, but not yet cached!\n";
  return m_ptll;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription* Event::getEventDesc()
{
  return &m_event_desc;
}

// ----------------------------------------------------------------------------
SusyAnalysisTools::SRHelper* Event::getSRHelper()
{
  return &m_sr_helper;
}

// ----------------------------------------------------------------------------
FLAVOR_CHANNEL Event::getFlavorChannel()
{
  return m_event_desc.getFlavorChannel();
}

// ----------------------------------------------------------------------------
SIGN_CHANNEL Event::getSignChannel()
{
  return m_event_desc.getSignChannel();
}

// ----------------------------------------------------------------------------
PHASE_SPACE Event::getPhaseSpace()
{
  return m_event_desc.getPhaseSpace();
}
