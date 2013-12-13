#include "SelectionTools/include/HFORTool.h"

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "D3PDObjects/include/TruthD3PDObject.h"
#include "SUSYTools/HforToolD3PD.h"


#include "CommonTools/include/TruthMatchTool.h"

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
  int hfor_type = m_hforTool.getDecision( mc->mc_channel_number()
                                        , mc->mc_n()
                                        , mc->mc_pt()
                                        , mc->mc_eta()
                                        , mc->mc_phi(),mc->mc_m()
                                        , mc->mc_pdgId()
                                        , mc->mc_status()
                                        , mc->mc_vx_barcode()
                                        , mc->mc_parent_index()
                                        , mc->mc_child_index()
                                        , HforToolD3PD::DEFAULT
                                        );
  if (hfor_type == 4) return false;

  return true;


}

// -----------------------------------------------------------------------------
bool SelectionTools::HFORTool::passSherpaWWOveralpRemoval(const Event* event, const D3PDReader::TruthD3PDObject* mc)
{
  if (!is_data()) {

    unsigned int dsid = mc->mc_channel_number();
    if (  dsid == 126892
//       || dsid == 157817
//       || dsid == 157818
//       || dsid == 157819
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

// -----------------------------------------------------------------------------
bool SelectionTools::HFORTool::passZOverlapRemoval(const D3PDReader::TruthD3PDObject* mc,
                                                   CommonTools::TruthMatchTool* truth_match_tool)
{

  bool isSherpaZ = false;
  bool isZbb     = false;
  bool isZcc     = false;
  bool isZ       = false;

  unsigned int dsid = mc->mc_channel_number(); 

  if (dsid >=147770 && dsid <=147772) isSherpaZ =true;
  if (dsid >=110805 && dsid <=110816) isZcc = true;
  if (dsid >=110817 && dsid <=110828) isZbb = true;
  if (dsid >=117640 && dsid <=117675) isZ = true;

  if(isZcc || isZbb || isZ)
    {

      int ZpdgID=23;

      for (int i = 0; i<mc->mc_n(); ++i)
        { // Still looks wrong...double check
          ///if(!(mc->mc_pdgId()->at(i) == ZpdgID && mc->mc_m()->at(i) > 60000)) return false;


          // I think it should be this:

          if(mc->mc_pdgId()->at(i) == ZpdgID && mc->mc_m()->at(i) < 60000) return false;
        }
    }

  if(isSherpaZ)
    {
      double m_Z = -999;
      TLorentzVector lep1;
      TLorentzVector lep2;

      std::vector<TLorentzVector> truth_leptons;

      truth_leptons = truth_match_tool->getHSLeptonsTLV();

      if (truth_leptons.size() == 2)
        {
          lep1 = truth_leptons.at(0);


          lep2 = truth_leptons.at(1);
          m_Z = (lep1 + lep2).M();

          if (m_Z > 60000 || m_Z < 40000) return false;

        }
    } 


  return true;
}
