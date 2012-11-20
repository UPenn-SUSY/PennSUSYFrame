#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/ChargeFlipScaleFactorTool.h"

// ----------------------------------------------------------------------------
CommonTools::ChargeFlipScaleFactorTool::ChargeFlipScaleFactorTool( SCycleBase* parent
                                   , const char* name
                                   )
                                   : ToolBase(parent, name)
{
  DeclareProperty("do_charge_flip_sf", c_do_charge_flip_sf = true);
  DeclareProperty("path_to_charge_flip_map", c_path_to_flip_map = "ChargeFlip/data/chargeFlip.root");
  
  m_charge_flip =0;
  m_reco_truth_match=0;


}

// ----------------------------------------------------------------------------
CommonTools::ChargeFlipScaleFactorTool::~ChargeFlipScaleFactorTool()
{
  // do nothing


  if(m_charge_flip)  delete m_charge_flip;
  if(m_reco_truth_match) delete m_reco_truth_match;

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
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_logger << DEBUG
           << "ChargeFlipEstTool::BeginCycle()"
           << SLogger::endmsg;
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  m_logger<< DEBUG
          <<"ChargeFlipEstTool Path to map: "
          <<c_path_to_flip_map
          << SLogger::endmsg;

  m_charge_flip = new chargeFlip(c_path_to_flip_map);
  m_charge_flip->setUnits(chargeFlip::MeV);
}
// ----------------------------------------------------------------------------
void CommonTools::ChargeFlipScaleFactorTool::PrepTruth(const D3PDReader::TruthD3PDObject& mc)
{
  if(!m_truth_prepped)
    {
      
      float dR = 0.1;
      //  bool IsSherpa = false;
      int verbose_level = 0;
      
      // std::cout<<"about to stirp"<<std::endl;
      
      std::vector<int> barcode = stripConst(*(mc.mc_barcode()));
      std::vector<int>* barcode_pointer = &barcode;
      std::vector<int> status = stripConst(*(mc.mc_status()));
      std::vector<int>* status_pointer = &status;
      std::vector<int> pdgId = stripConst(*(mc.mc_pdgId()));
      std::vector<int>* pdgId_pointer = &pdgId;
      std::vector<vector<int> > parents = stripConstVector(*(mc.mc_parents()));
      std::vector<vector<int> > children = stripConstVector(*(mc.mc_children()));
      
      std::vector<float> pt = stripConst(*(mc.mc_pt()));
      std::vector<float>* pt_pointer = &pt;
      std::vector<float> eta = stripConst(*(mc.mc_eta()));
      std::vector<float>* eta_pointer = &eta;
      std::vector<float> phi = stripConst(*(mc.mc_phi()));
      std::vector<float>* phi_pointer = &phi;
      std::vector<float> m = stripConst(*(mc.mc_m()));
      std::vector<float>* m_pointer = &m;
 
      std::vector<vector<int> >* parent_pointer = &parents;
      std::vector<vector<int> >* children_pointer = &children;
      
      m_reco_truth_match = new RecoTruthMatch(dR, mc.mc_channel_number(), mc.mc_n(),
					      barcode_pointer,status_pointer,pdgId_pointer,
					      parent_pointer, children_pointer, 
					      pt_pointer, eta_pointer, phi_pointer,
					      m_pointer, verbose_level);
  
      m_truth_prepped = true;
    

    }

}

// ---------------------------------------------------------------------------
double CommonTools::ChargeFlipScaleFactorTool::getSF(FLAVOR_CHANNEL flavor_channel
						     , const std::vector<Electron*>& el
						     , const std::vector<Muon*>& mu
						     , const Met* met
						     , const D3PDReader::TruthD3PDObject& mc 
						     , int syst)
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

	m_charge_flip_sf = m_charge_flip->OS2SS(pdg_1, tlv_1_ptr, pdg_2, tlv_2_ptr, met_vector_ptr,syst);
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

	m_charge_flip_sf = m_charge_flip->OS2SS(pdg_1, tlv_1_ptr, pdg_2, tlv_2_ptr, met_vector_ptr,syst);
	double overlap_corr =  m_charge_flip->overlapFrac().first;
	m_charge_flip_sf = m_charge_flip_sf*overlap_corr;
 
      }
    
    
    m_is_cached = true;
    m_logger << VERBOSE << "b-tag sf: " << m_charge_flip_sf << SLogger::endmsg;
  }
  

  return m_charge_flip_sf;
}
std::vector<vector<int> > CommonTools::ChargeFlipScaleFactorTool::stripConstVector(const std::vector<vector<int> >& old_vector)
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

