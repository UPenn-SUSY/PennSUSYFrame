#include "CommonTools/include/JetOutputTool.h"

#include <math.h>

#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "CommonTools/include/DeltaPhiTool.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// -----------------------------------------------------------------------------
CommonTools::JetOutputTool::JetOutputTool( SCycleBase* parent
                                         , const char* name
                                         )
                                         : ToolBase(parent, name)
{
  DeclareProperty("do_detailed_output", c_do_detailed_output= false);
  DeclareProperty("jet_container_name", c_jet_output_collection = "baseline");
  DeclareProperty("jet_label",          c_output_label = "jet_");
}
// -----------------------------------------------------------------------------
CommonTools::JetOutputTool::~JetOutputTool()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}
// -----------------------------------------------------------------------------
void CommonTools::JetOutputTool::BeginInputData( const SInputData& )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  DeclareVariable(m_num_baseline_jets, (c_output_label + "num_baseline_jets" ).c_str());
  DeclareVariable(m_num_good_jets    , (c_output_label + "num_good_jets"     ).c_str());
  DeclareVariable(m_num_light_jets   , (c_output_label + "num_light_jets"    ).c_str());
  DeclareVariable(m_num_b_jets       , (c_output_label + "num_b_jets"        ).c_str());
  DeclareVariable(m_num_forward_jets , (c_output_label + "num_forward_jets"  ).c_str());

  DeclareVariable(m_jet_pt           , (c_output_label + "pt"           ).c_str());
  DeclareVariable(m_jet_eta          , (c_output_label + "eta"          ).c_str());
  DeclareVariable(m_jet_phi          , (c_output_label + "phi"          ).c_str());
  DeclareVariable(m_jet_bjet_mv1     , (c_output_label + "bjet_mv1"     ).c_str());
  DeclareVariable(m_jet_dr_signal_lep, (c_output_label + "dr_signal_lep").c_str());
  DeclareVariable(m_jet_jvf          , (c_output_label + "jvf"          ).c_str());
  DeclareVariable(m_jet_desc         , (c_output_label + "desc"         ).c_str());
  DeclareVariable(m_jet_dphi_ll      , (c_output_label + "dphi_ll"      ).c_str());
  DeclareVariable(m_jet_dphi_met     , (c_output_label + "dphi_met"     ).c_str());
  DeclareVariable(m_jet_tlv          , (c_output_label + "tlv"          ).c_str());

  //Detailed Variables
  if(c_do_detailed_output)
    {
      //No detailed output for now
    }

}
// -----------------------------------------------------------------------------
void CommonTools::JetOutputTool::BeginExecuteEvent(const SInputData&, Double_t)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_num_baseline_jets = 0;
  m_num_good_jets     = 0;
  m_num_light_jets    = 0;
  m_num_b_jets        = 0;
  m_num_forward_jets  = 0;

  m_jet_pt.clear();
  m_jet_eta.clear();
  m_jet_phi.clear();
  m_jet_bjet_mv1.clear();
  m_jet_dr_signal_lep.clear();
  m_jet_jvf.clear();
  m_jet_desc.clear();
  m_jet_dphi_ll.clear();
  m_jet_dphi_met.clear();
  m_jet_tlv.clear();

}

// -----------------------------------------------------------------------------
void CommonTools::JetOutputTool::fillOutput( Event* event
                                           , ElectronContainer& electrons
                                           , MuonContainer& muons
                                           , JetContainer& jets
                                           , Met* met
                                           , VertexContainer& /*vertices*/
                                           )
{
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_logger << VERBOSE
           << "CommonTools::JetOutputTool::Fill"
           << SLogger::endmsg;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Fill jet varaibles
  std::vector<Jet*> jet_vec;

  if (  c_jet_output_collection == "signal"
     || c_jet_output_collection == "Signal"
     || c_jet_output_collection == "all_signal"
     || c_jet_output_collection == "All_Signal"
     ) {
    jet_vec = jets.getJets(JET_ALL_SIGNAL);
  }
  else if(  c_jet_output_collection == "good"
         || c_jet_output_collection == "Good"
         ) {
    jet_vec = jets.getJets(JET_GOOD);
  }
  else if(  c_jet_output_collection == "baseline"
         || c_jet_output_collection == "Baseline"
         ) {
    jet_vec = jets.getJets(JET_BASELINE);
  }
  else if(  c_jet_output_collection == "all"
         || c_jet_output_collection == "All"
         ) {
    jet_vec = jets.getJets(JET_ALL);
  }
  else if(  c_jet_output_collection == "light"
         || c_jet_output_collection == "Light"
         ) {
    jet_vec = jets.getJets(JET_LIGHT);
  }
  else if(  c_jet_output_collection == "central"
         || c_jet_output_collection == "Central"
         ) {
    jet_vec = jets.getJets(JET_ALL_CENTRAL);
  }
  else {
    m_logger << FATAL
             << "Could Not Parse Jet Output Level: "
             << c_jet_output_collection
             << SLogger::endmsg;
    throw SError(SError::StopExecution);
  }

  m_num_baseline_jets = jets.getJets(JET_BASELINE).size();
  m_num_good_jets     = jets.getJets(JET_GOOD).size();
  m_num_light_jets    = jets.getJets(JET_LIGHT).size();
  m_num_b_jets        = jets.getJets(JET_B).size();
  m_num_forward_jets  = jets.getJets(JET_FORWARD).size();

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
    m_jet_bjet_mv1.push_back(jet_vec.at(jet_it)->flavor_weight_MV1());
    // TODO when getMinDeltaR is included in a tool, move use the tool instead of cutflow member function
    // m_jet_dr_signal_lep.push_back( cutflow.getMinDeltaR( *jet_it
    // 							   , cutflow.m_el_signal
    // 							   , cutflow.m_mu_signal
    // 							   )
    //				     );
    m_jet_jvf.push_back(jet_vec.at(jet_it)->jvtxf());

    m_jet_desc.push_back(jet_vec.at(jet_it)->getJetDesc()->toInt());

    m_jet_dphi_ll.push_back(
        CommonTools::DeltaPhiTool::getDeltaPhi( event->getFlavorChannel()
                                              , electrons.getElectrons(EL_GOOD)
                                              , muons.getMuons(MU_GOOD)
                                              , jet_vec.at(jet_it)
                                              ) );
    m_jet_dphi_met.push_back(
        CommonTools::DeltaPhiTool::getDeltaPhi(jet_vec.at(jet_it), met));

    m_jet_tlv.push_back(jet_vec.at(jet_it)->getTlv());

    if (c_do_detailed_output)
    {
      //do detailed otuput -- none for now
    }
  }
}
