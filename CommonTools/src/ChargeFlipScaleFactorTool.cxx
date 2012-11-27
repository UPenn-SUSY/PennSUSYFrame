#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/ChargeFlipScaleFactorTool.h"

// ----------------------------------------------------------------------------
CommonTools::ChargeFlipScaleFactorTool::ChargeFlipScaleFactorTool(
    SCycleBase* parent, const char* name) : ToolBase(parent, name)
{
  DeclareProperty("do_charge_flip_sf", c_do_charge_flip_sf = true);
  DeclareProperty("path_to_charge_flip_map", c_path_to_flip_map = 
		  "ChargeFlip/data/chargeFlip.root");

  m_charge_flip =0;
  //m_reco_truth_match=0;
}

// ----------------------------------------------------------------------------
CommonTools::ChargeFlipScaleFactorTool::~ChargeFlipScaleFactorTool()
{
  if(m_charge_flip)  delete m_charge_flip;
  // if(m_reco_truth_match) delete m_reco_truth_match;
}

// ----------------------------------------------------------------------------
void CommonTools::ChargeFlipScaleFactorTool::clear()
{
  m_is_cached = false;
  m_charge_flip_sf = -999;
  
}

// ----------------------------------------------------------------------------
void CommonTools::ChargeFlipScaleFactorTool::BeginCycle()
{
  m_logger << DEBUG
    << "ChargeFlipEstTool::BeginCycle()"
    << SLogger::endmsg;

  m_logger<< DEBUG
    <<"ChargeFlipEstTool Path to map: "
    <<c_path_to_flip_map
    << SLogger::endmsg;

  m_charge_flip = new chargeFlip(c_path_to_flip_map);
  m_charge_flip->setUnits(chargeFlip::MeV);
}

SIGN_CHANNEL CommonTools::ChargeFlipScaleFactorTool::getTruthSign(
    FLAVOR_CHANNEL flavor_channel,
    const std::vector<Electron*>& el,
    const std::vector<Muon*>& mu,
    const D3PDReader::TruthD3PDObject* mc,
    const D3PDReader::MuonTruthD3PDObject* mu_truth,
    TruthMatchTool* truth_match_tool)
{
  //if(!m_truth_prepped) PrepTruth(mc);

  m_logger << DEBUG
           << "ChargeFlipScaleFactorTool::getTruthSign()"
           << SLogger::endmsg;


  SIGN_CHANNEL truth_sign_channel = SIGN_NONE;

  m_truth_match_tool = truth_match_tool;

  float charge_0 = 0;
  float charge_1 = 0;

  switch (flavor_channel) 
    {
    case FLAVOR_EE: 
      charge_0 = getTruthElectronSign(el.at(0), mc);
      charge_1 = getTruthElectronSign(el.at(1), mc);
      break;
    case FLAVOR_MM: 
      charge_0 = getTruthMuonSign(mu.at(0), mu_truth);
      charge_1 = getTruthMuonSign(mu.at(1), mu_truth);
      break;
    case FLAVOR_EM: 
      charge_0 = getTruthElectronSign(el.at(0), mc);
      charge_1 = getTruthMuonSign(mu.at(0), mu_truth);
      break;
    default:       
      charge_0 = 0;
      charge_1 = 0;
    }
  if (charge_0*charge_1 == 0)       truth_sign_channel = SIGN_NONE;
  else if (charge_0*charge_1 == 1)  truth_sign_channel = SIGN_SS;
  else if (charge_0*charge_1 == -1) truth_sign_channel = SIGN_OS;
  else                              truth_sign_channel = SIGN_NONE;
      
  return truth_sign_channel;
  
}


// ---------------------------------------------------------------------------
double CommonTools::ChargeFlipScaleFactorTool::getSF(
    FLAVOR_CHANNEL flavor_channel,
    const std::vector<Electron*>& el,
    const std::vector<Muon*>& mu,
    const Met* met,
    int syst)
{
  if (!m_is_cached) {
    m_charge_flip_sf = 1.;


    TVector2 met_vector = met->getMetRefFinalVec();
    TVector2* met_vector_ptr = &met_vector;

    if(flavor_channel == FLAVOR_MM)
    {
      m_charge_flip_sf = 0;
    }
    else if(flavor_channel == FLAVOR_EE)
    {
      TLorentzVector tlv_1 = el.at(0)->getTlv();
      TLorentzVector tlv_2 = el.at(1)->getTlv();
      TLorentzVector* tlv_1_ptr = &tlv_1;
      TLorentzVector* tlv_2_ptr = &tlv_2;

      int pdg_1=11;
      int pdg_2=11;

      m_charge_flip_sf = m_charge_flip->OS2SS(
          pdg_1, tlv_1_ptr, pdg_2, tlv_2_ptr, met_vector_ptr,syst);
      double overlap_corr =  m_charge_flip->overlapFrac().first;
      m_charge_flip_sf = m_charge_flip_sf*overlap_corr;
    }
    else if(flavor_channel == FLAVOR_EM)
    {
      TLorentzVector tlv_1 = el.at(0)->getTlv();
      TLorentzVector tlv_2 = mu.at(0)->getTlv();
      TLorentzVector* tlv_1_ptr = &tlv_1;
      TLorentzVector* tlv_2_ptr = &tlv_2;

      int pdg_1=11;
      int pdg_2=13;

      m_charge_flip_sf = m_charge_flip->OS2SS(pdg_1
					      , tlv_1_ptr
					      , pdg_2
					      , tlv_2_ptr
					      , met_vector_ptr
					      ,syst);
      
      double overlap_corr =  m_charge_flip->overlapFrac().first;
      m_charge_flip_sf = m_charge_flip_sf*overlap_corr;
    }


    m_is_cached = true;
    m_logger << VERBOSE << "b-tag sf: " << m_charge_flip_sf << SLogger::endmsg;
  }
  return m_charge_flip_sf;
}

// -----------------------------------------------------------------------------
std::vector<vector<int> > CommonTools::ChargeFlipScaleFactorTool::stripConstVector(
     const std::vector<vector<int> >& old_vector)
{
  size_t length = old_vector.size();
  std::vector<vector<int> > new_vector;
  //new_vector.reserve(length);
  for (unsigned int i = 0; i != length; ++i) {
    std::vector<int> tmp_vector;
    size_t internal_length = old_vector.at(i).size();
    //tmp_vector.reserve(internal_length);
    for(unsigned int j = 0; j < internal_length; ++j) {
      tmp_vector.push_back(old_vector.at(i).at(j));
    }
    new_vector.push_back(tmp_vector);
  }
  std::vector< vector<int> >* pointer = &new_vector;

  return new_vector;
}
// -----------------------------------------------------------------------------
float CommonTools::ChargeFlipScaleFactorTool::getTruthMuonSign(
     const Muon* mu,
     const D3PDReader::MuonTruthD3PDObject* mu_truth
     )
{
  int barcode = m_truth_match_tool->matchBarcode(
       mu->truth_barcode(),mu_truth->barcode());
  
  if(barcode < 0) return 0;
  
  return  mu_truth->charge()->at(barcode);
  
      
}
// -----------------------------------------------------------------------------
float CommonTools::ChargeFlipScaleFactorTool::getTruthElectronSign(
     const Electron* el,
     const D3PDReader::TruthD3PDObject* mc
     )
{

  TLorentzVector tlv = el->getTlv();

  int index =  m_truth_match_tool->getIndex(tlv);

  if(index < 0) return 0;
  
  return mc->mc_charge()->at(index);
      
}
