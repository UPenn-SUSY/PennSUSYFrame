#include "SelectionTools/include/SherpaWWOverlapRemovalTool.h"

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "D3PDObjects/include/TruthD3PDObject.h"

// -----------------------------------------------------------------------------
SelectionTools::SherpaWWOverlapRemovalTool::SherpaWWOverlapRemovalTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  // do nothing
}

// -----------------------------------------------------------------------------
SelectionTools::SherpaWWOverlapRemovalTool::~SherpaWWOverlapRemovalTool()
{
  //do nothing
}

// -----------------------------------------------------------------------------
bool SelectionTools::SherpaWWOverlapRemovalTool::passOveralpRemoval(const Event* event, const D3PDReader::TruthD3PDObject* mc)
{
  if (!is_data()) {
    unsigned int dsid = event->RunNumber();
    if (  dsid == 126892
       || dsid == 157817
       || dsid == 157818
       || dsid == 157819
       ) {
      Int_t num_truth_objects = mc->mc_n();
      for(Int_t obj_itr = 0; obj_itr != num_truth_objects; ++obj_itr) {
        if(  abs(mc->mc_pdgId()->at(obj_itr)) == 5
          && mc->mc_status()->at(obj_itr) == 3
          ) {
          return false;
        }
      }
    }
  }

  return true;
}
