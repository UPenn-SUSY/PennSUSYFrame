#include "PennSusyFrameCore/include/TruthMatchTools.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "RootCore/LeptonTruthTools/LeptonTruthTools/RecoTruthMatch.h"
#include "TLorentzVector.h"

// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::TruthMatchTool::TruthMatchTool() : m_truth_match(0)
{

}

// -----------------------------------------------------------------------------
PennSusyFrame::TruthMatchTool::~TruthMatchTool()
{
  clear();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TruthMatchTool::clear()
{
  if (m_truth_match) {
    delete m_truth_match;
    m_truth_match = 0;
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TruthMatchTool::prep(const PennSusyFrame::MCTruth& mc_truth)
{
  clear();

  m_truth_match = new RecoTruthMatch( 0.1
                                    , mc_truth.getChannelNumber()
                                    , mc_truth.getN()
                                    , mc_truth.getBarcode()
                                    , mc_truth.getStatus()
                                    , mc_truth.getPdgId()
                                    , mc_truth.getParents()
                                    , mc_truth.getChildren()
                                    , mc_truth.getPt()
                                    , mc_truth.getEta()
                                    , mc_truth.getPhi()
                                    , mc_truth.getM()
                                    , 0
                                    );
}

// -----------------------------------------------------------------------------
int PennSusyFrame::TruthMatchTool::getIndex(const TLorentzVector* tlv)
{
  return m_truth_match->MatchedTruthLepton(*tlv);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TruthMatchTool::isRealLeptonEvent( FLAVOR_CHANNEL flavor_channel
                                                     , const std::vector<PennSusyFrame::Electron*>* el
                                                     , const std::vector<PennSusyFrame::Muon*>* mu
                                                     , const PennSusyFrame::MCTruth& mc_truth
                                                     )
{
  // bail out if we have no flavor channel
  if (flavor_channel == FLAVOR_NONE) return false;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check for prompt lepton event
  std::vector<bool> is_prompt;

  size_t num_el = el->size();
  for (size_t el_it = 0; el_it != num_el; ++el_it) {
    is_prompt.push_back(isRealElectron(el->at(el_it)));
  }

  size_t num_mu = mu->size();
  for (size_t mu_it = 0; mu_it != num_mu; ++mu_it) {
    is_prompt.push_back(isRealMuon(mu->at(mu_it), mc_truth));
  }

  return (is_prompt.at(0) && is_prompt.at(1));
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TruthMatchTool::isRealElectron(const PennSusyFrame::Electron* el)
{
  int lep_type = m_truth_match->fakeType( *(el->getTlv())
                                        , el->getOrigin()
                                        , el->getType()
                                        );

  bool is_real_lep = (lep_type == RecoTruthMatch::PROMPT);
  return is_real_lep;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::TruthMatchTool::isRealMuon( const PennSusyFrame::Muon* mu
                                              , const PennSusyFrame::MCTruth& mc_truth
                                              )
{

  int mu_origin = 0;
  int mu_type = 0;
  int mu_truth_index = matchBarcode( mu->getTruthBarcode()
                                   , mc_truth.getMuonBarcode()
                                   );
  if (mu_truth_index != -1) {
    mu_origin = mc_truth.getMuOrigin()->at(mu_truth_index);
    mu_type   = mc_truth.getMuType()->at(mu_truth_index);
  }

  int lep_type = m_truth_match->fakeType( *(mu->getTlv())
                                        , mu_origin
                                        , mu_type
                                        );
  bool is_real_lep = (lep_type == RecoTruthMatch::PROMPT);

  return is_real_lep;
}
//TODO:::::double check this is the right muon truth
// -----------------------------------------------------------------------------
SIGN_CHANNEL PennSusyFrame::TruthMatchTool::getTruthSign( FLAVOR_CHANNEL flavor_channel
                                                        , const std::vector<PennSusyFrame::Electron*>* el
                                                        , const std::vector<PennSusyFrame::Muon*>* mu
                                                        , const PennSusyFrame::MCTruth& mc_truth
                                                        )
{
  if (flavor_channel == FLAVOR_NONE)
    return SIGN_NONE;

  float charge_0 = 0.;
  float charge_1 = 0.;

  if (flavor_channel == FLAVOR_EE) {
    charge_0 = getTruthElectronSign(el->at(0), mc_truth);
    charge_1 = getTruthElectronSign(el->at(1), mc_truth);
  }
  else if (flavor_channel == FLAVOR_MM) {
    charge_0 = getTruthMuonSign(mu->at(0), mc_truth);
    charge_1 = getTruthMuonSign(mu->at(1), mc_truth);
  }
  else if (flavor_channel == FLAVOR_EM) {
    charge_0 = getTruthElectronSign(el->at(0), mc_truth);
    charge_1 = getTruthMuonSign(    mu->at(0), mc_truth);
  }

  float charge_product = charge_0*charge_1;
  if (charge_product > 0) return SIGN_SS;
  if (charge_product < 0) return SIGN_OS;
  return SIGN_NONE;
}

// -----------------------------------------------------------------------------
float PennSusyFrame::TruthMatchTool::getTruthElectronSign( const PennSusyFrame::Electron* el
                                                         , const PennSusyFrame::MCTruth& mc_truth
                                                         )
{
  int index = getIndex(el->getTlv());
  if (index < 0) return 0;

  return mc_truth.getCharge()->at(index);
}

// -----------------------------------------------------------------------------
float PennSusyFrame::TruthMatchTool::getTruthMuonSign( const PennSusyFrame::Muon* mu
                                                     , const PennSusyFrame::MCTruth& mc_truth
                                                     )
{
  int index = matchBarcode( mu->getTruthBarcode()
                          , mc_truth.getBarcode()
                          );
  if (index < 0) return 0;

  return mc_truth.getCharge()->at(index);
}

// -----------------------------------------------------------------------------
int PennSusyFrame::TruthMatchTool::getParentBarcodeElectron( const PennSusyFrame::Electron* el
                                                           , const PennSusyFrame::MCTruth& mc_truth
                                                           )
{
  return -1;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::TruthMatchTool::getParentBarcodeMuon( const PennSusyFrame::Muon* mu
                                                       , const PennSusyFrame::MCTruth& mc_truth
                                                       )
{
  int mu_index = matchBarcode( mu->getTruthBarcode()
                             , mc_truth.getBarcode()
                             );
  int parent_index = mc_truth.getParentIndex()->at(mu_index).at(0);
  int parent_barcode = mc_truth.getBarcode()->at(parent_index);
  return parent_barcode;
}

// -----------------------------------------------------------------------------
int PennSusyFrame::TruthMatchTool::matchBarcode( int barcode_to_match
                                               , const std::vector<int>* list_of_barcodes
                                               )
{
  size_t term = list_of_barcodes->size();
  for (size_t i = 0; i != term; ++i) {
    if(list_of_barcodes->at(i) == barcode_to_match)
      return i;
  }

  // -1 means no match
  return -1;
}
