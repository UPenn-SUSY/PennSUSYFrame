#include <math.h>
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/VertexOutputTool.h"

// ----------------------------------------------------------------------------
CommonTools::VertexOutputTool::VertexOutputTool( SCycleBase* parent
                                                         , const char* name
                                                         )
                                                         : ToolBase(parent, name)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


  DeclareProperty("do_detailed_output", c_do_detailed_output= false);
  DeclareProperty("vertex_container_name", c_vertex_output_collection = "good");


}
// ----------------------------------------------------------------------------
CommonTools::VertexOutputTool::~VertexOutputTool()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}
// ----------------------------------------------------------------------------
void CommonTools::VertexOutputTool::BeginInputData( const SInputData& )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  DeclareVariable(m_vtx_n       , "vtx_n"       );
  DeclareVariable(m_vtx_x       , "vtx_x"       );
  DeclareVariable(m_vtx_y       , "vtx_y"       );
  DeclareVariable(m_vtx_z       , "vtx_z"       );
  DeclareVariable(m_vtx_n_tracks, "vtx_n_tracks");
  DeclareVariable(m_vtx_sum_pt  , "vtx_sum_pt"  );


  //Detailed Variables
  if(c_do_detailed_output)
    {
      //No detailed output for now
    }

}
// ----------------------------------------------------------------------------
void CommonTools::VertexOutputTool::BeginExecuteEvent( const SInputData&, Double_t )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_vtx_n = 0;
  m_vtx_x.clear();
  m_vtx_y.clear();
  m_vtx_z.clear();
  m_vtx_n_tracks.clear();
  m_vtx_sum_pt.clear();

}

// ----------------------------------------------------------------------------
void CommonTools::VertexOutputTool::fillOutput( Event* /*event*/
                                              , ElectronContainer& /*electrons*/
                                              , MuonContainer& /*muons*/
                                              , JetContainer& /*jets*/
                                              , Met* /*met*/
                                              , VertexContainer& vertices
                                              )
{
  m_logger << VERBOSE
           << "CommonTools::VertexOutputTool::Fill"
           << SLogger::endmsg;

  // Fill vertex varaibles

  const std::vector<Vertex*> *vertex_vec;

  if(  c_vertex_output_collection == "good"
    || c_vertex_output_collection == "Good"
    || c_vertex_output_collection == "signal"
    || c_vertex_output_collection == "Signal"
    ) {
    vertex_vec = vertices.getVertexs(VERT_GOOD);
  }
  else if(  c_vertex_output_collection == "all"
         || c_vertex_output_collection =="All"
         ) {
    vertex_vec = vertices.getVertexs(VERT_ALL);
  }
  else {
    m_logger << FATAL
             << "Could Not Parse Electron Output Level: "
             << c_vertex_output_collection
             << SLogger::endmsg;
    throw SError(SError::StopExecution);
  }

  m_vtx_n = vertex_vec->size();
  for (unsigned int vtx_it = 0; vtx_it != m_vtx_n; ++vtx_it) {
    m_vtx_x.push_back(vertex_vec->at(vtx_it)->x());
    m_vtx_y.push_back(vertex_vec->at(vtx_it)->y());
    m_vtx_z.push_back(vertex_vec->at(vtx_it)->z());
    m_vtx_n_tracks.push_back(vertex_vec->at(vtx_it)->nTracks());
    m_vtx_sum_pt.push_back(vertex_vec->at(vtx_it)->sumPt());
  }

  if (c_do_detailed_output)
  {
    //do detailed otuput -- none for now
  }
}
