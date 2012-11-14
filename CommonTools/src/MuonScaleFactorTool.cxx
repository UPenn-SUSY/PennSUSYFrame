#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/MuonScaleFactorTool.h"

// ----------------------------------------------------------------------------
CommonTools::MuonScaleFactorTool::MuonScaleFactorTool( SCycleBase* parent
                                                                 , const char* name
                                                                 )
                                                                 : ToolBase(parent, name)
                                                                 , m_muon_sf(NULL)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  DeclareProperty("do_scaling", c_do_scaling = false             );
  DeclareProperty("sf_dir"    , c_muon_sf_dir  = ""              );
  DeclareProperty("muon_type" , c_muon_type  = "STACO_CB_plus_ST");
  DeclareProperty("unit"      , c_unit = "MeV"                   );

  // get default path for muon SF directory.  This comes from SUSYTools
  if (c_muon_sf_dir == "") {
    std::string maindir = "";
    char *tmparea=getenv("ROOTCOREDIR");
    if (tmparea != NULL) {
      maindir = tmparea;
      maindir = maindir + "/";
    }
    c_muon_sf_dir = maindir + "../MuonEfficiencyCorrections/share/";
  }

  std::cout << "Muon efficiency corrections will be grabbed from: "
            << c_muon_sf_dir << "\n";

  if (c_muon_type == "") {
    c_muon_type = "STACO_CB_plus_ST";
  }
  m_file_name = c_muon_type + "_2012_SF.txt";

  m_configuration = Analysis::AnalysisMuonConfigurableScaleFactors::AverageOverRuns;
}
// ----------------------------------------------------------------------------
CommonTools::MuonScaleFactorTool::~MuonScaleFactorTool()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (m_muon_sf)
    delete m_muon_sf;
}

// ----------------------------------------------------------------------------
void CommonTools::MuonScaleFactorTool::BeginInputData(const SInputData&)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (!is_data() && c_do_scaling) {
    // Get muon SF values from pile up tool
    GET_TOOL(pile_up_tool, CommonTools::PileUpScaleFactorTool, "PileUpScaleFactor");

    m_muon_sf_int_lum.clear();
    m_muon_sf_int_lum = pile_up_tool->getIntegratedLumiVector();

    // clean up old m_muon_sf if exists
    if (m_muon_sf)
      delete m_muon_sf;

    // m_muon_sf = new Analysis::AnalysisMuonEfficiencyScaleFactors( c_muon_type
    //    c_muon_type, m_muon_sf_int_lum, c_unit, c_muon_sf_dir);
    m_muon_sf = new Analysis::AnalysisMuonConfigurableScaleFactors(
        c_muon_sf_dir, m_file_name, c_unit, m_configuration);
    m_muon_sf->Initialise();
  }
}
// ----------------------------------------------------------------------------
void CommonTools::MuonScaleFactorTool::EndInputData(const SInputData&)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}

// ----------------------------------------------------------------------------
double CommonTools::MuonScaleFactorTool::getSF(Muon* mu)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  float sf = 1;
  if (!is_data() && c_do_scaling) {
    if (!m_muon_sf) {
      m_logger << ERROR
               << "No scale factor class initialized! Setting SF to 1"
               << SLogger::endmsg;
      return 1;
    }
    TLorentzVector mu_tlv = mu->getTlv();

    sf = m_muon_sf->scaleFactor(mu->charge(), mu_tlv);
  }

  return sf;
}

// ----------------------------------------------------------------------------
double CommonTools::MuonScaleFactorTool::getSFUncertainty(Muon* mu)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  float sf_unc = 0;

  if (!is_data() && c_do_scaling) {
    if (!m_muon_sf) {
      m_logger << ERROR
               << "No scale factor class initialized! Setting SF uncertainty to 0"
               << SLogger::endmsg;
      return 0;
    }
    TLorentzVector mu_tlv = mu->getTlv();

    sf_unc = m_muon_sf->scaleFactorUncertainty(mu->charge(), mu_tlv);
  }

  return sf_unc;
}
