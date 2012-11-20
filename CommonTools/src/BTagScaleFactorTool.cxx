#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/BTagScaleFactorTool.h"

// ----------------------------------------------------------------------------
CommonTools::BTagScaleFactorTool::BTagScaleFactorTool( SCycleBase* parent
                                   , const char* name
                                   )
                                   : ToolBase(parent, name)
{
  DeclareProperty("do_b_tag_sf", c_do_b_tag_sf = true);
  DeclareProperty( "calib_file"
                 , c_calibration_file = "SUSYTools/data/BTagCalibration_JVF.env"
                 );
  DeclareProperty( "calib_folder"
                 , c_calibration_folder = "SUSYTools/data/"
                 );
}

// ----------------------------------------------------------------------------
CommonTools::BTagScaleFactorTool::~BTagScaleFactorTool()
{
  // do nothing
}
// ----------------------------------------------------------------------------
void CommonTools::BTagScaleFactorTool::clear()
{
  m_is_cached = false;
  m_b_tag_sf = -999;
}
// ---------------------------------------------------------------------------
double CommonTools::BTagScaleFactorTool::getSF(const std::vector<Jet*>& jets)
{
  if (!m_is_cached) {
    m_b_tag_sf = 1.;

    if (!is_data() && c_do_b_tag_sf) {
      std::vector<float> pt_btag;
      std::vector<float> eta_btag;
      std::vector<float> val_btag;
      std::vector<int> pdgid_btag;

      size_t jet_size = jets.size();
      for (size_t jet_it=0; jet_it != jet_size; ++jet_it) {
        TLorentzVector jet_tlv = jets.at(jet_it)->getTlv();

        if (jet_tlv.Pt() < 20000. || fabs(jet_tlv.Eta()) > 2.5) continue;

        pt_btag.push_back(jet_tlv.Pt());
        eta_btag.push_back(jet_tlv.Eta());
        val_btag.push_back(jets.at(jet_it)->flavor_weight_MV1());
        pdgid_btag.push_back(jets.at(jet_it)->flavor_truth_label());
      }

      std::pair<std::vector<float>, std::vector<float> > wgtbtag;
      wgtbtag = BTagCalib::BTagCalibrationFunction( pt_btag
                                                  , eta_btag
                                                  , val_btag
                                                  , pdgid_btag
                                                  , "MV1"
                                                  // , "0_980"
                                                  // , 0.980
                                                  , "0_122"
                                                  , 0.122
                                                  , c_calibration_file
                                                  , c_calibration_folder
                                                  );
      m_b_tag_sf = wgtbtag.first.at(0);

      m_is_cached = true;
      m_logger << VERBOSE << "b-tag sf: " << m_b_tag_sf << SLogger::endmsg;
    }
  }

  return m_b_tag_sf;
}
