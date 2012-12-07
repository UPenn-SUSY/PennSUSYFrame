#include "include/TruthMatchTool.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"

// -----------------------------------------------------------------------------
CommonTools::TruthMatchTool::TruthMatchTool( SCycleBase* parent
                                           , const char* name
                                           )
                                           : ToolBase(parent, name)
                                           , m_truth_match(NULL)
                                           , m_cached(false)
{
  // do nothing
}

// -----------------------------------------------------------------------------
CommonTools::TruthMatchTool::~TruthMatchTool()
{
  if (m_truth_match) delete m_truth_match;
}

// -----------------------------------------------------------------------------
void CommonTools::TruthMatchTool::prep(
    const D3PDReader::TruthD3PDObject* truth_obj)
{
  // Don't prep this tool for data
  if (is_data()) return;

  // clear old instance of m_truth_match object
  if (m_truth_match) delete m_truth_match;

  try {
    m_truth_match = new RecoTruthMatch( 0.1,
        truth_obj->mc_channel_number(),
        truth_obj->mc_n(),
        const_cast<std::vector<int>* >(truth_obj->mc_barcode()),
        const_cast<std::vector<int>* >(truth_obj->mc_status()),
        const_cast<std::vector<int>* >(truth_obj->mc_pdgId()),
        const_cast<std::vector<std::vector<int> >* >(truth_obj->mc_parents()),
        const_cast<std::vector<std::vector<int> >* >(truth_obj->mc_children()),
        const_cast<std::vector<float>* >(truth_obj->mc_pt()),
        const_cast<std::vector<float>* >(truth_obj->mc_eta()),
        const_cast<std::vector<float>* >(truth_obj->mc_phi()),
        const_cast<std::vector<float>* >(truth_obj->mc_m()),
        0);
  }
  catch (...) {
    throw SError( SError::SkipEvent );
  }

  m_cached = false;
}

// -----------------------------------------------------------------------------
bool CommonTools::TruthMatchTool::isRealLeptonEvent( FLAVOR_CHANNEL flavor,
    const std::vector<Electron*>& el,
    const std::vector<Muon*>& mu,
    const D3PDReader::MuonTruthD3PDObject* mu_truth)
{
  // for data: pass through
  if (is_data()) return true;

  if (!m_cached) {
    bool is_prompt_1 = false;
    bool is_prompt_2 = false;

    switch (flavor) {
      case FLAVOR_EE: is_prompt_1 = isRealElectron(el.at(0));
                      is_prompt_2 = isRealElectron(el.at(1));
                      break;
      case FLAVOR_MM: is_prompt_1 = isRealMuon(mu.at(0), mu_truth);
                      is_prompt_2 = isRealMuon(mu.at(1), mu_truth);
                      break;
      case FLAVOR_EM: is_prompt_1 = isRealElectron(el.at(0));
                      is_prompt_2 = isRealMuon(mu.at(0), mu_truth);
                      break;
      default:        is_prompt_1 = false;
                      is_prompt_2 = false;
                      break;
    }

    m_is_real_lepton_event = (is_prompt_1 && is_prompt_2);
    m_cached = true;
  }
  return m_is_real_lepton_event;
}

// -----------------------------------------------------------------------------
bool CommonTools::TruthMatchTool::isRealElectron(const Electron* el)
{
  // for data: pass through
  if (is_data()) return true;

  int lep_type = m_truth_match->fakeType( el->getTlv()
                                        , el->origin()
                                        , el->type()
                                        );
  return (lep_type == RecoTruthMatch::PROMPT);
}

// -----------------------------------------------------------------------------
bool CommonTools::TruthMatchTool::isRealMuon(
    const Muon* mu, const D3PDReader::MuonTruthD3PDObject* mu_truth)
{
  // for data: pass through
  if (is_data()) return true;

  int mu_origin = 0;
  int mu_type = 0;

  // int mu_truth_index = 0;
  int mu_truth_index = matchBarcode(mu->truth_barcode(), mu_truth->barcode());

  if (mu_truth_index != -1) {
    mu_origin = mu_truth->origin()->at(mu_truth_index);
    mu_type   = mu_truth->type()->at(mu_truth_index);
  }

  int lep_type = m_truth_match->fakeType( mu->getTlv()
                                        , mu_origin
                                        , mu_type
                                        );
  return (lep_type == RecoTruthMatch::PROMPT);
}

// -----------------------------------------------------------------------------
int CommonTools::TruthMatchTool::matchBarcode(
    int barcode_to_match, const vector<int>* list_of_barcodes)
{
  size_t term = list_of_barcodes->size();
  for( size_t i = 0
     ; i != term
     ; ++i
     ) {
    if(list_of_barcodes->at(i) == barcode_to_match)
      return i;
  }

  // -1 means no match
  return -1;
}

// -----------------------------------------------------------------------------
int CommonTools::TruthMatchTool::getIndex(TLorentzVector tlv)
{

  return  m_truth_match->MatchedTruthLepton(tlv);

  //return -1;
}
