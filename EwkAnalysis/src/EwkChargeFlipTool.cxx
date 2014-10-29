#include "EwkAnalysis/include/EwkChargeFlipTool.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include <vector>
#include <string>
#include "RootCore/ChargeFlip/ChargeFlip/chargeFlip.h"

// -----------------------------------------------------------------------------
PennSusyFrame::ChargeFlipTool::ChargeFlipTool() : m_charge_flip(0)
{
  std::string root_core_dir = getenv("ROOTCOREDIR");
  //m_charge_flip_map_file = root_core_dir + "/../ChargeFlip/data/19aug14_chargeflip_map.root";
  m_charge_flip_map_file = root_core_dir + "/../ChargeFlip/data/d0_new2d_chargeflip_map.root";
}

// -----------------------------------------------------------------------------
PennSusyFrame::ChargeFlipTool::~ChargeFlipTool()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ChargeFlipTool::init()
{
  m_charge_flip = new chargeFlip(m_charge_flip_map_file);
  m_charge_flip->setUnits(chargeFlip::MeV);
}

// -----------------------------------------------------------------------------
double PennSusyFrame::ChargeFlipTool::getSF( FLAVOR_CHANNEL flavor_channel
                                           , const std::vector<PennSusyFrame::Electron*>* el
                                           , const std::vector<PennSusyFrame::Muon*>* mu
                                           )
{
  double charge_flip_sf = 1.;

  if (flavor_channel == FLAVOR_MM) {
    charge_flip_sf = 0.;
  }
  else if (flavor_channel == FLAVOR_EE) {
    const TLorentzVector* tlv_0 = el->at(0)->getTlv();
    const TLorentzVector* tlv_1 = el->at(1)->getTlv();

    int pdg_0 = 11;
    int pdg_1 = 11;

    charge_flip_sf = m_charge_flip->OS2SS( pdg_0
                                         , const_cast<TLorentzVector*>(tlv_0)
                                         , pdg_1
                                         , const_cast<TLorentzVector*>(tlv_1)
                                         , 0 // syst
                                         );
    // correct for fake overlap
    charge_flip_sf *= m_charge_flip->overlapFrac().first;
  }
  else if (flavor_channel == FLAVOR_EM) {
    const TLorentzVector* tlv_e = el->at(0)->getTlv();
    const TLorentzVector* tlv_m = mu->at(0)->getTlv();

    int pdg_e = 11;
    int pdg_m = 13;

    charge_flip_sf = m_charge_flip->OS2SS( pdg_e
                                         , const_cast<TLorentzVector*>(tlv_e)
                                         , pdg_m
                                         , const_cast<TLorentzVector*>(tlv_m)
                                         , 0 // syst
                                         );
    charge_flip_sf *= m_charge_flip->overlapFrac().first;
  }

  return charge_flip_sf;
}
