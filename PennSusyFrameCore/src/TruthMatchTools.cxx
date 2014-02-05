#include "PennSusyFrameCore/include/TruthMatchTools.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

#include "RootCore/LeptonTruthTools/LeptonTruthTools/RecoTruthMatch.h"

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
  return true;

  int mu_origin = 0;
  int mu_type = 0;

  int mu_truth_index = matchBarcode( mu->getTruthBarcode()
                                   , mc_truth.getBarcode()
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
