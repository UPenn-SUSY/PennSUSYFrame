#include "include/MuonMomentumSmearingTool.h"

// ----------------------------------------------------------------------------
CommonTools::MuonMomentumSmearingTool::MuonMomentumSmearingTool(
    SCycleBase* parent,
    const char* name): ToolBase(parent, name),
                       m_mcp_smear(NULL)
{
  init();
}

// ----------------------------------------------------------------------------
CommonTools::MuonMomentumSmearingTool::~MuonMomentumSmearingTool()
{
  if (m_mcp_smear)
    delete m_mcp_smear;
}

// ----------------------------------------------------------------------------
void CommonTools::MuonMomentumSmearingTool::init()
{
  DeclareProperty("smearing_function", c_smearing_function = "");
}

// ----------------------------------------------------------------------------
void CommonTools::MuonMomentumSmearingTool::BeginInputData(const SInputData&)
{
  // do nothing for data
  if (is_data()) return;

  // clean up old m_mcp_smear if it exists
  if (m_mcp_smear)
    delete m_mcp_smear;

  // Muon momentum scale corrections
  if (m_muon_momentum_dir == "") {
    // get default path for muon SF directory.  This comes from SUSYTools
    std::string maindir = "";
    char *tmparea=getenv("ROOTCOREDIR");
    if (tmparea != NULL) {
      maindir = tmparea;
      maindir = maindir + "/";
    }
    // Default path
    m_muon_momentum_dir = maindir + "/../MuonMomentumCorrections/share/";
  }

  std::cout << "Muon momentum smearing will be grabbed from: "
            << m_muon_momentum_dir << "\n";

  // create mcp smearing object
  m_mcp_smear = new MuonSmear::SmearingClass( "Data12"
                                            , "staco"
                                            , "q_pT"
                                            , "Rel17.2"
                                            , m_muon_momentum_dir
                                            );
  m_mcp_smear->UseScale(1);
  m_mcp_smear->UseImprovedCombine();
}


// ----------------------------------------------------------------------------
void CommonTools::MuonMomentumSmearingTool::EndInputData(const SInputData&)
{
  // do nothing
}

// ----------------------------------------------------------------------------
double CommonTools::MuonMomentumSmearingTool::getSmearedPt(const Muon* mu)
{
  double my_pt = mu->pt();

  // if not data, apply momentum smearing
  if (!is_data()) {
    if (m_mcp_smear) {
      float pt_cb = mu->pt();
      float pt_id = (mu->id_qoverp_exPV() !=0) ? fabs(sin(mu->id_theta_exPV())/mu->id_qoverp_exPV()) : 0;
      float pt_ms = (mu->me_qoverp_exPV() !=0) ? fabs(sin(mu->me_theta_exPV())/mu->me_qoverp_exPV()) : 0;

      // m_mcp_smear.SetSeed(EventNumber+iMu*1000000);
      int seed = static_cast<int>(1.e+5*fabs(mu->phi()));
      if (!seed) ++seed;
      m_mcp_smear->SetSeed(seed);
      m_mcp_smear->Event(pt_ms, pt_id, pt_cb, mu->eta());

      if (c_smearing_function == "") {
        if (mu->isCombinedMuon())
          my_pt = m_mcp_smear->pTCB();
        else if (mu->isSegmentTaggedMuon())
          my_pt = m_mcp_smear->pTID();
        else
          my_pt = m_mcp_smear->pTMS();
      }
      else {
        double pTMS_smeared = 0.;
        double pTID_smeared = 0.;
        double pTCB_smeared = 0.;

        // Valid values for "c_smearing_function":
        //   {"MSLOW", "MSUP", "IDLOW", "IDUP"}
        m_mcp_smear->PTVar( pTMS_smeared
                          , pTID_smeared
                          , pTCB_smeared
                          , c_smearing_function
                          );

        if (mu->isCombinedMuon())
          my_pt = pTCB_smeared;
        else if (mu->isSegmentTaggedMuon())
          my_pt = pTID_smeared;
        else
          my_pt = pTMS_smeared;
      }
    }
  }

  return my_pt;
}
