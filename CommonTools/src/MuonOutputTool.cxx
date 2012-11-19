#include <math.h>
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/MuonOutputTool.h"

// ----------------------------------------------------------------------------
CommonTools::MuonOutputTool::MuonOutputTool( SCycleBase* parent
                                                         , const char* name
                                                         )
                                                         : ToolBase(parent, name)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


  DeclareProperty("do_detailed_output", c_do_detailed_output= false);
  DeclareProperty("electron_container_name", c_electron_output_collection = "signal");
  DeclareProperty("jet_container_name", c_jet_output_collection = "signal");
  DeclareProperty("muon_container_name", c_muon_output_collection = "signal");


}
// ----------------------------------------------------------------------------
CommonTools::MuonOutputTool::~MuonOutputTool()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}
// ----------------------------------------------------------------------------
void CommonTools::MuonOutputTool::BeginInputData( const SInputData& )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  DeclareVariable(m_mu_pt                 , "mu_pt"                 );
  DeclareVariable(m_mu_eta                , "mu_eta"                );
  DeclareVariable(m_mu_phi                , "mu_phi"                );
  DeclareVariable(m_mu_cov_d0             , "mu_cov_d0"             );
  DeclareVariable(m_mu_d0                 , "mu_d0"                 );
  DeclareVariable(m_mu_z0                 , "mu_z0"                 );
  DeclareVariable(m_mu_d0_sig             , "mu_d0_sig"             );
  DeclareVariable(m_mu_z0_sin_theta       , "mu_z0_sin_theta"       );
  DeclareVariable(m_mu_charge             , "mu_charge"             );
  DeclareVariable(m_mu_etcone20           , "mu_etcone20"           );
  DeclareVariable(m_mu_etcone30           , "mu_etcone30"           );
  DeclareVariable(m_mu_etcone40           , "mu_etcone40"           );
  DeclareVariable(m_mu_ptcone20           , "mu_ptcone20"           );
  DeclareVariable(m_mu_ptcone30           , "mu_ptcone30"           );
  DeclareVariable(m_mu_ptcone40           , "mu_ptcone40"           );

  DeclareVariable(m_mu_desc               , "mu_desc"               );


  //Detailed Variables
  if(c_do_detailed_output)
    {
      DeclareVariable(m_mu_raw_etcone20       , "mu_raw_etcone20"       );
      DeclareVariable(m_mu_raw_etcone30       , "mu_raw_etcone30"       );
      DeclareVariable(m_mu_raw_etcone40       , "mu_raw_etcone40"       );
      DeclareVariable(m_mu_raw_ptcone20       , "mu_raw_ptcone20"       );
      DeclareVariable(m_mu_raw_ptcone30       , "mu_raw_ptcone30"       );
      DeclareVariable(m_mu_raw_ptcone40       , "mu_raw_ptcone40"       );
      DeclareVariable(m_mu_b_layer_hits       , "mu_b_layer_hits"       );
      DeclareVariable(m_mu_num_pix_hits       , "mu_num_pix_hits"       );
      DeclareVariable(m_mu_num_sct_hits       , "mu_num_sct_hits"       );
      DeclareVariable(m_mu_num_trt_hits       , "mu_num_trt_hits"       );
      DeclareVariable(m_mu_expect_b_layer_hit , "mu_expect_b_layer_hit" );
      DeclareVariable(m_mu_num_pix_holes      , "mu_num_pix_holes"      );
      DeclareVariable(m_mu_num_sct_holes      , "mu_num_sct_holes"      );
      DeclareVariable(m_mu_num_trt_outliers   , "mu_num_trt_outliers"   );
      DeclareVariable(m_mu_num_trt_ht_outliers, "mu_num_trt_ht_outliers");
      DeclareVariable(m_mu_num_mdt_layers     , "mu_num_mdt_layers"     );
    }

}
// ----------------------------------------------------------------------------
void CommonTools::MuonOutputTool::BeginExecuteEvent( const SInputData&, Double_t )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  //Clear all the variables
  m_mu_pt.clear();
  m_mu_eta.clear();
  m_mu_phi.clear();
  m_mu_cov_d0.clear();
  m_mu_d0.clear();
  m_mu_z0.clear();
  m_mu_d0_sig.clear();
  m_mu_z0_sin_theta.clear();
  m_mu_charge.clear();
  m_mu_etcone20.clear();
  m_mu_etcone30.clear();
  m_mu_etcone40.clear();
  m_mu_ptcone20.clear();
  m_mu_ptcone30.clear();
  m_mu_ptcone40.clear();
  m_mu_raw_etcone20.clear();
  m_mu_raw_etcone30.clear();
  m_mu_raw_etcone40.clear();
  m_mu_raw_ptcone20.clear();
  m_mu_raw_ptcone30.clear();
  m_mu_raw_ptcone40.clear();
  m_mu_b_layer_hits.clear();
  m_mu_num_pix_hits.clear();
  m_mu_num_sct_hits.clear();
  m_mu_num_trt_hits.clear();
  m_mu_expect_b_layer_hit.clear();
  m_mu_num_pix_holes.clear();
  m_mu_num_sct_holes.clear();
  m_mu_num_trt_outliers.clear();
  m_mu_num_trt_ht_outliers.clear();
  m_mu_num_mdt_layers.clear();
  m_mu_desc.clear();


}

// ----------------------------------------------------------------------------
void CommonTools::MuonOutputTool::fillOutput(Event* event, ElectronContainer electrons, MuonContainer muons, JetContainer jets, Met*, VertexContainer vertices)
{
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_logger << VERBOSE
           << "CommonTools::MuonOutputTool::Fill"
           << SLogger::endmsg;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Fill muon varaibles

  std::vector<Muon*> mu_vec = muons.getMuons(MU_SIGNAL);

  size_t num_mu = mu_vec.size();

  int num_good_vtx = vertices.num(VERT_GOOD);
 
  // before storing muons to ntuple, we want to check the pt-ordering
//   std::sort( cutflow.m_mu_signal.begin()
//            , cutflow.m_mu_signal.end()
//            , MuonHandle::gt
//            );

  for (size_t mu_it=0; mu_it != num_mu; ++mu_it) 
    {
      TLorentzVector mu_tlv =  mu_vec.at(mu_it)->getTlv();
          
      m_mu_pt.push_back(mu_tlv.Pt());
      m_mu_eta.push_back(mu_tlv.Eta());
      m_mu_phi.push_back(mu_tlv.Phi());
      m_mu_cov_d0.push_back(mu_vec.at(mu_it)->cov_d0_exPV());
      m_mu_d0.push_back(mu_vec.at(mu_it)->d0_exPV());
      m_mu_z0.push_back(mu_vec.at(mu_it)->z0_exPV());
      m_mu_d0_sig.push_back(mu_vec.at(mu_it)->getD0Significance());
      m_mu_z0_sin_theta.push_back(mu_vec.at(mu_it)->getZ0SinTheta());
      m_mu_charge.push_back(static_cast<int>(mu_vec.at(mu_it)->charge()));

      m_mu_etcone20.push_back(mu_vec.at(mu_it)->getIsoCorr(ETCONE, 20, num_good_vtx));
      m_mu_etcone30.push_back(mu_vec.at(mu_it)->getIsoCorr(ETCONE, 30, num_good_vtx));
      m_mu_etcone40.push_back(mu_vec.at(mu_it)->getIsoCorr(ETCONE, 40, num_good_vtx));
      m_mu_ptcone20.push_back(mu_vec.at(mu_it)->getIsoCorr(PTCONE, 20, num_good_vtx));
      m_mu_ptcone30.push_back(mu_vec.at(mu_it)->getIsoCorr(PTCONE, 30, num_good_vtx));
      m_mu_ptcone40.push_back(mu_vec.at(mu_it)->getIsoCorr(PTCONE, 40, num_good_vtx));


      m_mu_desc.push_back(mu_vec.at(mu_it)->getMuonDesc()->toInt());
      if (c_do_detailed_output)
	{

	  m_mu_raw_etcone20.push_back(mu_vec.at(mu_it)->etcone20());
	  m_mu_raw_etcone30.push_back(mu_vec.at(mu_it)->etcone30());
	  m_mu_raw_etcone40.push_back(mu_vec.at(mu_it)->etcone40());
	  m_mu_raw_ptcone20.push_back(mu_vec.at(mu_it)->ptcone20());
	  m_mu_raw_ptcone30.push_back(mu_vec.at(mu_it)->ptcone30());
	  m_mu_raw_ptcone40.push_back(mu_vec.at(mu_it)->ptcone40());

	  m_mu_b_layer_hits.push_back(mu_vec.at(mu_it)->nBLHits());
	  m_mu_num_pix_hits.push_back(mu_vec.at(mu_it)->nPixHits());
	  m_mu_num_sct_hits.push_back(mu_vec.at(mu_it)->nSCTHits());
	  m_mu_num_trt_hits.push_back(mu_vec.at(mu_it)->nTRTHits());
	  m_mu_expect_b_layer_hit.push_back(mu_vec.at(mu_it)->expectBLayerHit());
	  m_mu_num_pix_holes.push_back(mu_vec.at(mu_it)->nPixHoles());
	  m_mu_num_sct_holes.push_back(mu_vec.at(mu_it)->nSCTHoles());
	  m_mu_num_trt_outliers.push_back(mu_vec.at(mu_it)->nTRTOutliers());
	  m_mu_num_trt_ht_outliers.push_back(mu_vec.at(mu_it)->nTRTHighTOutliers());
	  m_mu_num_mdt_layers.push_back(mu_vec.at(mu_it)->getNMuonStations());

	}

    }
}
