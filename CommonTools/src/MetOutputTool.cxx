#include <math.h>
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/MetOutputTool.h"

// ----------------------------------------------------------------------------
CommonTools::MetOutputTool::MetOutputTool( SCycleBase* parent
                                                         , const char* name
                                                         )
                                                         : ToolBase(parent, name)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


  DeclareProperty("do_detailed_output", c_do_detailed_output= false);
//   DeclareProperty("electron_container_name", c_electron_output_collection = "signal");
//   DeclareProperty("jet_container_name", c_jet_output_collection = "signal");
//   DeclareProperty("muon_container_name", c_muon_output_collection = "signal");


}
// ----------------------------------------------------------------------------
CommonTools::MetOutputTool::~MetOutputTool()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}
// ----------------------------------------------------------------------------
void CommonTools::MetOutputTool::BeginInputData( const SInputData& )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  DeclareVariable(m_met_et           , "met_et"    );
  DeclareVariable(m_met_rel_et       , "met_rel_et");
  DeclareVariable(m_met_rel_delta_phi, "met_rel_delta_phi"   );
  DeclareVariable(m_met_phi          , "met_phi"   );
  DeclareVariable(m_met_sumet        , "met_sumet" );
  DeclareVariable(m_met_vec          , "met_vec"   );

  //Detailed Variables
  if(c_do_detailed_output)
    {
      //No detailed output for now
    }

}
// ----------------------------------------------------------------------------
void CommonTools::MetOutputTool::BeginExecuteEvent( const SInputData&, Double_t )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  m_met_et            = 0;
  m_met_rel_et        = 0;
  m_met_phi           = 0;
  m_met_rel_delta_phi = 0.;
  m_met_sumet         = 0;
  m_met_vec.Set(0.,0.);

}

// ----------------------------------------------------------------------------
void CommonTools::MetOutputTool::fillOutput( Event* event
                                           , ElectronContainer& /*electrons*/
                                           , MuonContainer& /*muons*/
                                           , JetContainer& /*jets*/
                                           , Met* met
                                           , VertexContainer& /*vertices*/
                                           )
{
  m_logger << VERBOSE
           << "CommonTools::MetOutputTool::Fill"
           << SLogger::endmsg;

  // Fill met varaibles

  m_met_et = met->getMetRefFinalEt();
  m_met_rel_et = event->getMetRel();
  m_met_phi = met->getMetRefFinalPhi();
  //  m_met_rel_delta_phi = ;
  //m_met_sumet
  m_met_vec = met->getMetRefFinalVec();

  if (c_do_detailed_output) {
    //do detailed otuput -- none for now
  }
}
