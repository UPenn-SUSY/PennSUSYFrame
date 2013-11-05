#include "CommonTools/include/TriggerReweightTool.h"

#include <vector>
#include "THnSparse.h"

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"
#include "D3PDObjects/include/EventInfoD3PDObject.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

#include "DGTriggerReweight/triggerReweight2Lep.h"


// ----------------------------------------------------------------------------
CommonTools::TriggerReweightTool::TriggerReweightTool( SCycleBase* parent
                                                     , const char* name
                                                     )
                                                     : ToolBase(parent, name)
{
  DeclareProperty("do_trigger_sf"           , c_do_trigger_sf       = true);
  DeclareProperty("trigger_reweight_dir"    , c_reweight_directory  = "");
  DeclareProperty("trigger_reweight_period" , c_reweight_period     ="Moriond");

  m_trigger_weight =0;

}

// -----------------------------------------------------------------------------
CommonTools::TriggerReweightTool::~TriggerReweightTool()
{
  if (m_trigger_reweight) delete m_trigger_reweight;
}

// -----------------------------------------------------------------------------
void CommonTools::TriggerReweightTool::BeginCycle()
{
  m_logger << DEBUG
     << "TriggerReweight::BeginCycle()"
     << SLogger::endmsg;

  m_trigger_reweight = new triggerReweight2Lep();
}

// -----------------------------------------------------------------------------
void CommonTools::TriggerReweightTool::BeginInputData(const SInputData&)
{
  m_logger << DEBUG
     << "TriggerReweight::BeginInputData()"
     << SLogger::endmsg;

  //set dir for btag
  if (c_reweight_directory == "") {
    // get default path for reweight directory
    // we've put in SFrame/../data for now
    std::string maindir = "";
    char *tmparea=getenv("ROOTCOREDIR");
    if (tmparea != NULL) {
      maindir = tmparea;
      maindir = maindir + "/../DGTriggerReweight/data/";
    }
  }

  // std::cout << "reweight directory: " << c_reweight_directory << "\n";
  // std::cout << "reweight period: " << c_reweight_period << "\n";
  //new initialze method for tag 00-00-29 
  m_trigger_reweight->setDbg(1);
  m_trigger_reweight->initialize( c_reweight_directory
                                , c_reweight_period
                                , false
                                );
  m_trigger_reweight->setDbg(0);
}

// -----------------------------------------------------------------------------
void CommonTools::TriggerReweightTool::EndInputData(const SInputData&)
{
  // do nothing
}

// -----------------------------------------------------------------------------
void CommonTools::TriggerReweightTool::clear()
{
  m_is_cached = false;
}

// -----------------------------------------------------------------------------
double CommonTools::TriggerReweightTool::getTriggerWeight(
    FLAVOR_CHANNEL flavor_channel,
    const std::vector<Electron*>& el,
    const std::vector<Muon*>& mu,
    const std::vector<Jet*>& jet,
    Met* met,
    VertexContainer& vertices)
{
  // no trigger weights for data
  if (!m_is_cached)
  {
    if (is_data() || !c_do_trigger_sf) m_trigger_weight = 1.;

    else
    {
      int systematic = 0; //take nominal value for now;
      int num_vert = vertices.num(VERT_GOOD);
      int num_jets = jet.size();

      // std::cout << "get trigger weight:"
      //           << "\n\tflavor channel: " << flavor_channel
      //           << "\n\tmet: " << met->getMetRefFinalEt()
      //           << "\n\tnum vert: " << num_vert
      //           << "\n\tnum jets: " << num_jets
      //           << "\n";

      if (flavor_channel == FLAVOR_EE)
      {
        m_logger << DEBUG
          << "TriggerReweightTool::getTriggerWeight()"
          << "Flavor EE Channel "
          << SLogger::endmsg;

        double el_pt_1 = el.at(0)->getTlv().Pt();
        double el_pt_2 = el.at(1)->getTlv().Pt();

        double el_eta_1 = el.at(0)->getTlv().Eta();
        double el_eta_2 = el.at(1)->getTlv().Eta();
        // double el_eta_1 = fabs(el.at(0)->getTlv().Eta());
        // double el_eta_2 = fabs(el.at(1)->getTlv().Eta());

        // std::cout << "\tel 1 pt: " << el_pt_1 << "\tel 1 eta: " << el_eta_1 << "\n"
        //           << "\tel 2 pt: " << el_pt_2 << "\tel 2 eta: " << el_eta_2 << "\n";

        m_trigger_weight = m_trigger_reweight->triggerReweightEE(
            el_pt_1, el_eta_1, el_pt_2, el_eta_2);
            // el_pt_1, el_eta_1, el_pt_2, el_eta_2, systematic);
      }
      else if(flavor_channel == FLAVOR_MM)
      {
        m_logger << DEBUG
          << "TriggerReweightTool::getTriggerWeight()"
          << "Flavor MuMu Channel "
          << SLogger::endmsg;

        double mu_pt_1 = mu.at(0)->getTlv().Pt();
        double mu_pt_2 = mu.at(1)->getTlv().Pt();

        double mu_eta_1 = mu.at(0)->getTlv().Eta();
        double mu_eta_2 = mu.at(1)->getTlv().Eta();
        // double mu_eta_1 = fabs(mu.at(0)->getTlv().Eta());
        // double mu_eta_2 = fabs(mu.at(1)->getTlv().Eta());

        double mu_phi_1 = mu.at(0)->getTlv().Phi();
        double mu_phi_2 = mu.at(1)->getTlv().Phi();

        int mu_isComb_1 = mu.at(0)->isCombinedMuon();
        int mu_isComb_2 = mu.at(1)->isCombinedMuon();

        m_trigger_weight = m_trigger_reweight->triggerReweightMM(
            mu_pt_1, mu_eta_1, mu_phi_1, mu_isComb_1,
            mu_pt_2, mu_eta_2, mu_phi_2, mu_isComb_2,
            0, num_vert, met->getMetRefFinalEt(), 0, false);
            // systematic, num_vert, met->getMetRefFinalEt(), 0, false);
            // systematic, num_vert, met->getMetRefFinalEt(), num_jets, false);
      }
      else if(flavor_channel == FLAVOR_EM)
      {
        m_logger << DEBUG
          << "TriggerReweightTool::getTriggerWeight()"
          << "FlavorEmu Channel "
          << SLogger::endmsg;

        double el_pt = el.at(0)->getTlv().Pt();
        double mu_pt = mu.at(0)->getTlv().Pt();

        double el_eta = el.at(0)->getTlv().Eta();
        double mu_eta = mu.at(0)->getTlv().Eta();
        // double el_eta = fabs(el.at(0)->getTlv().Eta());
        // double mu_eta = fabs(mu.at(0)->getTlv().Eta());

        double mu_phi = mu.at(0)->getTlv().Phi();
        int mu_isComb = mu.at(0)->isCombinedMuon();

        m_trigger_weight = m_trigger_reweight->triggerReweightEMU(
            el_pt, el_eta,
            mu_pt, mu_eta, mu_phi,
            mu_isComb, 0, num_vert);
            // mu_isComb, systematic, num_vert);
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

  std::cout << "trigger weight: " << m_trigger_weight << "\n";
  return m_trigger_weight;
}

