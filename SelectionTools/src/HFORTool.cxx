#include "include/HFORTool.h"

// -----------------------------------------------------------------------------
SelectionTools::HFORTool::HFORTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  DeclareProperty("do_hfor", c_do_hfor = true);

  m_hforTool.setVerbosity(HforToolD3PD::ERROR);
}
// -----------------------------------------------------------------------------
SelectionTools::HFORTool::~HFORTool()
{
  //do nothing
}
// -----------------------------------------------------------------------------
bool SelectionTools::HFORTool::passHFOR(const D3PDReader::TruthD3PDObject* mc)
{
  
  if (!c_do_hfor || is_data()) return true;
  int hfor_type = m_hforTool.getDecision(mc->mc_channel_number(), mc->mc_n(), mc->mc_pt(), mc->mc_eta(), mc->mc_phi(),mc->mc_m(), mc->mc_pdgId(), mc->mc_status(), mc->mc_vx_barcode(), mc->mc_parent_index(), mc->mc_child_index(), HforToolD3PD::DEFAULT);
  
  if (hfor_type == 4) return false;

  return true;

 
}
