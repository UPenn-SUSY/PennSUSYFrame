#include "BMinusLAnalysis/include/BMinusLUtils.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/Calculators.h"

// -----------------------------------------------------------------------------
PennSusyFrame::blPair::blPair()
{ }

// -----------------------------------------------------------------------------
PennSusyFrame::blPair::blPair( PennSusyFrame::Jet* jet, PennSusyFrame::Lepton* lep)
{
  m_jet = jet;
  m_lep = lep;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::blPair::calculate()
{
  m_mbl = calcMll(m_lep, m_jet);
  m_ptbl = calcPtll(m_lep, m_jet);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::doBLPairing( const PennSusyFrame::Event& event
                               , const std::vector<PennSusyFrame::Electron*>* el_list
                               , const std::vector<PennSusyFrame::Muon*>*     mu_list
                               , const std::vector<PennSusyFrame::Jet*>*      b_jet_list
                               , PennSusyFrame::blPair& pair_0
                               , PennSusyFrame::blPair& pair_1
                               )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();
  if (fc == FLAVOR_NONE) return false;

  std::vector<PennSusyFrame::Lepton*> lep_list;
  lep_list.reserve(2);
  if (fc == FLAVOR_EE) {
    lep_list.push_back(el_list->at(0));
    lep_list.push_back(el_list->at(1));
  }
  else if (fc == FLAVOR_MM) {
    lep_list.push_back(mu_list->at(0));
    lep_list.push_back(mu_list->at(1));
  }
  else if (fc == FLAVOR_EM) {
    lep_list.push_back(el_list->at(0));
    lep_list.push_back(mu_list->at(0));
  }

  return doBLPairing(&lep_list, b_jet_list, pair_0, pair_1);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::doBLPairing( const std::vector<PennSusyFrame::Lepton*>* lep_list
                               , const std::vector<PennSusyFrame::Jet*>*    jet_list
                               , PennSusyFrame::blPair& pair_0
                               , PennSusyFrame::blPair& pair_1
                               )
{
  if (lep_list->size() < 2 || jet_list->size() < 2) return false;

  // first calculate the mbl values for the 00 11 pairings
  float mbl_00 = calcMll(lep_list->at(0), jet_list->at(0));
  float mbl_11 = calcMll(lep_list->at(1), jet_list->at(1));
  float mbl_ratio_00_11 = ( (mbl_00 > mbl_11) ? (mbl_00/mbl_11)
                                              : (mbl_11/mbl_00)
                          );

  // first calculate the mbl values for the 01 01 pairings
  float mbl_01 = calcMll(lep_list->at(0), jet_list->at(1));
  float mbl_10 = calcMll(lep_list->at(1), jet_list->at(0));
  float mbl_ratio_01_01 = ( (mbl_01 > mbl_10) ? (mbl_01/mbl_10)
                                              : (mbl_10/mbl_01)
                          );


  if (mbl_ratio_00_11 <= mbl_ratio_01_01) {
    if (mbl_00 >= mbl_11) {
      pair_0.setLep(lep_list->at(0));
      pair_0.setJet(jet_list->at(0));

      pair_1.setLep(lep_list->at(1));
      pair_1.setJet(jet_list->at(1));
    }
    else {
      pair_0.setLep(lep_list->at(1));
      pair_0.setJet(jet_list->at(1));

      pair_1.setLep(lep_list->at(0));
      pair_1.setJet(jet_list->at(0));
    }
  }
  else {
    if (mbl_01 >= mbl_10) {
      pair_0.setLep(lep_list->at(0));
      pair_0.setJet(jet_list->at(1));

      pair_1.setLep(lep_list->at(1));
      pair_1.setJet(jet_list->at(0));
    }
    else {
      pair_0.setLep(lep_list->at(1));
      pair_0.setJet(jet_list->at(0));

      pair_1.setLep(lep_list->at(0));
      pair_1.setJet(jet_list->at(1));
    }
  }

  pair_0.calculate();
  pair_1.calculate();

  return true;
}

