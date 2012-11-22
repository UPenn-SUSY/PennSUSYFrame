#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/TriggerReweightTool.h"

// ----------------------------------------------------------------------------
CommonTools::TriggerReweightTool::TriggerReweightTool( SCycleBase* parent
                                                     , const char* name
                                                     )
                                                     : ToolBase(parent, name)
                                                    
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  DeclareProperty("do_trigger_sf"           , c_do_trigger_sf       = true);
  DeclareProperty("trigger_reweight_dir"    , c_reweight_directory  = "/exports/project/data_d07_3/ehines/SusyFrame/Susy2.0/RootCore/DGTriggerReweight/data/");
  DeclareProperty("trigger_reweight_period" , c_reweight_period     ="HCP");

  m_trigger_weight =0;

}

// ----------------------------------------------------------------------------
CommonTools::TriggerReweightTool::~TriggerReweightTool()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  if (m_trigger_reweight) delete m_trigger_reweight;
}
// ----------------------------------------------------------------------------
void CommonTools::TriggerReweightTool::BeginCycle()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_logger << DEBUG
	   << "TriggerReweight::BeginCycle()"
	   << SLogger::endmsg;
  
  m_trigger_reweight = new triggerReweight2Lep();
  m_trigger_reweight->initialize(c_reweight_directory,c_reweight_period);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

}


// ----------------------------------------------------------------------------
void CommonTools::TriggerReweightTool::BeginInputData(const SInputData&)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // if data, or no trigger sf, do nothing
  //if (is_data() || !c_do_trigger_sf) return;
 
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  m_logger << DEBUG
	   << "TriggerReweight::BeginInputData()"
	   << SLogger::endmsg;


}

// ----------------------------------------------------------------------------
void CommonTools::TriggerReweightTool::EndInputData(const SInputData&)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}
// ----------------------------------------------------------------------------
void CommonTools::TriggerReweightTool::clear()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  m_is_cached = false;
}

// ----------------------------------------------------------------------------
double CommonTools::TriggerReweightTool::getTriggerWeight(FLAVOR_CHANNEL flavor_channel
							  , const std::vector<Electron*>& el
							  , const std::vector<Muon*>& mu
							  , VertexContainer& vertices
							  )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  // no trigger weights for data
  if (!m_is_cached)
    {
      if (is_data() || !c_do_trigger_sf) m_trigger_weight = 1.;
      
      else
	{
	  int systematic = 0; //take nominal value for now;

	  int num_vert = vertices.num(VERT_GOOD);

	  if (flavor_channel == FLAVOR_EE)
	    {

	      m_logger << DEBUG
		       << "TriggerReweightTool::getTriggerWeight()"
		       << "Flavor EE Channel "
		       << SLogger::endmsg;

	      double el_pt_1 = el.at(0)->getTlv().Pt();
	      double el_pt_2 = el.at(1)->getTlv().Pt();

	      double el_eta_1 = fabs(el.at(0)->getTlv().Eta());
	      double el_eta_2 = fabs(el.at(1)->getTlv().Eta());

	      m_trigger_weight = m_trigger_reweight->triggerReweightEE(el_pt_1,el_eta_1,el_pt_2,el_eta_2, systematic);
	    }
	  else if(flavor_channel == FLAVOR_MM)
	    {
	      m_logger << DEBUG
		       << "TriggerReweightTool::getTriggerWeight()"
		       << "Flavor MuMu Channel "
		       << SLogger::endmsg;



	      double mu_pt_1 = mu.at(0)->getTlv().Pt();
	      double mu_pt_2 = mu.at(1)->getTlv().Pt();
	      
	      double mu_eta_1 = fabs(mu.at(0)->getTlv().Eta());
	      double mu_eta_2 = fabs(mu.at(1)->getTlv().Eta());

	      double mu_phi_1 = mu.at(0)->getTlv().Phi();
	      double mu_phi_2 = mu.at(1)->getTlv().Phi();
	      
	      int mu_isComb_1 = mu.at(0)->isCombinedMuon();
	      int mu_isComb_2 = mu.at(1)->isCombinedMuon();
	      
	      m_trigger_weight = m_trigger_reweight->triggerReweightMM(mu_pt_1,mu_eta_1,mu_phi_1,mu_isComb_1,mu_pt_2,mu_eta_2,mu_phi_2, mu_isComb_2, systematic, num_vert);
	    }
	  else if(flavor_channel == FLAVOR_EM)
	    {

	      m_logger << DEBUG
		       << "TriggerReweightTool::getTriggerWeight()"
		       << "FlavorEmu Channel "
		       << SLogger::endmsg;
	      

	      double el_pt = el.at(0)->getTlv().Pt();
	      double mu_pt = mu.at(0)->getTlv().Pt();
	      
	      double el_eta = fabs(el.at(0)->getTlv().Eta());
	      double mu_eta = fabs(mu.at(0)->getTlv().Eta());

	      double mu_phi = mu.at(0)->getTlv().Phi();
	      int mu_isComb = mu.at(0)->isCombinedMuon();

	      m_trigger_weight = m_trigger_reweight->triggerReweightEMU(el_pt, el_eta, mu_pt, mu_eta, mu_phi, mu_isComb, systematic, num_vert);

	    }
	  else
	    {  
	      m_logger << DEBUG
		       << "TriggerReweightTool::getTriggerWeight()"
		       << "Flavor Channel not Recognized"
		       << SLogger::endmsg;

	      m_trigger_weight = 1.;
	    }

	}
    
      m_is_cached = true;
    }

  return m_trigger_weight;
  
}

