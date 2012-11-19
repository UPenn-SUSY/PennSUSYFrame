#include <math.h>
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/JetOutputTool.h"

// ----------------------------------------------------------------------------
CommonTools::JetOutputTool::JetOutputTool( SCycleBase* parent
                                                         , const char* name
                                                         )
                                                         : ToolBase(parent, name)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


  DeclareProperty("do_detailed_output", c_do_detailed_output= false);
  DeclareProperty("jet_container_name", c_jet_output_collection = "signal");

}
// ----------------------------------------------------------------------------
CommonTools::JetOutputTool::~JetOutputTool()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}
// ----------------------------------------------------------------------------
void CommonTools::JetOutputTool::BeginInputData( const SInputData& )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


  DeclareVariable(m_jet_pt           , "jet_pt"           );
  DeclareVariable(m_jet_eta          , "jet_eta"          );
  DeclareVariable(m_jet_phi          , "jet_phi"          );
  //DeclareVariable(m_jet_bjet_combnn  , "jet_bjet_combnn"  );
  DeclareVariable(m_jet_bjet_mv1     , "jet_bjet_mv1"     );
  DeclareVariable(m_jet_dr_signal_lep, "jet_dr_signal_lep");
  DeclareVariable(m_jet_jvf          , "jet_jvf"          );
  DeclareVariable(m_jet_desc         , "jet_desc"         );


  //Detailed Variables
  if(c_do_detailed_output)
    {
      //No detailed output for now      
    }

}
// ----------------------------------------------------------------------------
void CommonTools::JetOutputTool::BeginExecuteEvent( const SInputData&, Double_t )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  m_jet_pt.clear();
  m_jet_eta.clear();
  m_jet_phi.clear();
  // m_jet_bjet_combnn.clear();
  m_jet_bjet_mv1.clear();
  m_jet_dr_signal_lep.clear();
  m_jet_jvf.clear();
  m_jet_desc.clear();

}

// ----------------------------------------------------------------------------
void CommonTools::JetOutputTool::fillOutput(Event* event, ElectronContainer electrons, MuonContainer muons, JetContainer jets, Met*, VertexContainer vertices)
{
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_logger << VERBOSE
           << "CommonTools::JetOutputTool::Fill"
           << SLogger::endmsg;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Fill jet varaibles

  std::vector<Jet*> jet_vec; 

  if (c_jet_output_collection == "signal" || c_jet_output_collection == "Signal"
      || c_jet_output_collection =="all_signal" || c_jet_output_collection == "All_Signal")
    {
      jet_vec = jets.getJets(JET_ALL_SIGNAL);
    }
  else if(c_jet_output_collection == "good" || c_jet_output_collection == "Good")
    {
      jet_vec =  jets.getJets(JET_GOOD);
    }
  else if(c_jet_output_collection == "baseline" || c_jet_output_collection == "Baseline")
    {
      jet_vec =  jets.getJets(JET_BASELINE);
    }
  else if(c_jet_output_collection == "all" || c_jet_output_collection == "All")
    {
      jet_vec =  jets.getJets(JET_ALL);
    }
  else if(c_jet_output_collection == "light" || c_jet_output_collection == "Light")
    {
      jet_vec =  jets.getJets(JET_LIGHT);
    }
  else if(c_jet_output_collection == "central" || c_jet_output_collection == "Central")
    {
      jet_vec =  jets.getJets(JET_ALL_CENTRAL);
    }
  else
    {
      m_logger << FATAL
	       << "Could Not Parse Jet Output Level: " << c_jet_output_collection
	       << SLogger::endmsg;
      throw SError(SError::StopExecution);
    }


  size_t num_jet = jet_vec.size();
 
  // before storing jets to ntuple, we want to check the pt-ordering
//   std::sort( cutflow.m_jet_signal.begin()
//            , cutflow.m_jet_signal.end()
//            , JetHandle::gt
//            );


  for (size_t jet_it=0; jet_it != num_jet; ++jet_it) 
    {
      TLorentzVector jet_tlv =  jet_vec.at(jet_it)->getTlv();
      
      m_jet_pt.push_back(jet_tlv.Pt());
      m_jet_eta.push_back(jet_tlv.Eta());
      m_jet_phi.push_back(jet_tlv.Phi());
      //      m_jet_bjet_combnn.push_back(jet_vec.at(jet_it)->flavor_weight_JetFitterCOMBNN());
      m_jet_bjet_mv1.push_back(jet_vec.at(jet_it)->flavor_weight_MV1());
      // TODO when getMinDeltaR is included in a tool, move use the tool instead of cutflow member function
      // m_jet_dr_signal_lep.push_back( cutflow.getMinDeltaR( *jet_it
// 							   , cutflow.m_el_signal
// 							   , cutflow.m_mu_signal
// 							   )
//				     );
      m_jet_jvf.push_back(jet_vec.at(jet_it)->jvtxf());
    
      m_jet_desc.push_back(jet_vec.at(jet_it)->getJetDesc()->toInt());
 
      if (c_do_detailed_output)
	{

	  //do detailed otuput -- none for now
	}

    }
}

