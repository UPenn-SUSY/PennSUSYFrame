#include "PennSusyFrameCore/include/RescalerTools.h"

#include <string>

#include "TLorentzVector.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "RootCore/egammaAnalysisUtils/egammaAnalysisUtils/EnergyRescalerUpgrade.h"
#include "RootCore/MuonMomentumCorrections/MuonMomentumCorrections/SmearingClass.h"
#include "RootCore/ApplyJetCalibration/ApplyJetCalibration/ApplyJetCalibration.h"
#include "RootCore/ApplyJetResolutionSmearing/ApplyJetResolutionSmearing/ApplyJetSmearing.h";
#include "RootCore/JetUncertainties/JetUncertainties/MultijetJESUncertaintyProvider.h"

// =============================================================================
// = ElectronRescalerTool
// =============================================================================
PennSusyFrame::ElectronRescalerTool::ElectronRescalerTool( bool is_data
                                                         , bool is_af2
                                                         , PennSusyFrame::SystematicStruct* syst_struct
                                                         ) : m_is_data(is_data)
                                                           , m_is_af2(is_af2)
                                                           , m_syst_struct(syst_struct)
                                                           , m_e_rescale(0)
{
  init();
}

// -----------------------------------------------------------------------------
PennSusyFrame::ElectronRescalerTool::~ElectronRescalerTool()
{
  if (m_e_rescale)
    delete m_e_rescale;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ElectronRescalerTool::init()
{
  // directory with energy rescale data
  // get default path for egamma SF directory.  This comes from SUSYTools
  std::string root_core_dir = getenv("ROOTCOREDIR");
  std::string energy_rescale_data = ( root_core_dir
                                    + "/../egammaAnalysisUtils/share/EnergyRescalerData.root"
                                    );
  std::cout << "initializing ElectronRescalerTool -- energy_rescale_data: "
            << energy_rescale_data << "\n";

  m_e_rescale = new egRescaler::EnergyRescalerUpgrade( energy_rescale_data
                                                     , "2012"
                                                     , "es2012"
                                                     );
}

// -----------------------------------------------------------------------------
double PennSusyFrame::ElectronRescalerTool::getRescaledE( const PennSusyFrame::Electron* p)
{
  const double el_E_uncorrected = p->getClE();
  double el_E_corrected = el_E_uncorrected;

  double el_cl_eta = p->getClEta();
  double el_cl_phi = p->getClPhi();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (!m_is_data && m_syst_struct) {
    if (  m_syst_struct->getSyst("do_zee_all_up")
       || m_syst_struct->getSyst("do_zee_all_down")
       || m_syst_struct->getSyst("do_r12_stat_up")
       || m_syst_struct->getSyst("do_r12_stat_down")
       || m_syst_struct->getSyst("do_ps_stat_up")
       || m_syst_struct->getSyst("do_ps_stat_down")
       || m_syst_struct->getSyst("do_low_pt_up")
       || m_syst_struct->getSyst("do_low_pt_down")
       ) {
      el_E_corrected = applyEES( el_E_corrected, el_cl_eta);
    }


    // Do energy smearing in MC
    int seed = static_cast<int>(1.e+5*fabs(el_cl_phi));
    if (!seed) ++seed;
    m_e_rescale->SetRandomSeed(seed);

    // find smearing correction
    double smearcorr = 1.;
    if (m_syst_struct->getSyst("do_eer_up")) {
      smearcorr = m_e_rescale->getSmearingCorrection( el_cl_eta
                                                    , el_E_uncorrected
                                                    , egRescaler::EnergyRescalerUpgrade::ERR_UP
                                                    );
    }
    else if (m_syst_struct->getSyst("do_eer_down")) {
      smearcorr = m_e_rescale->getSmearingCorrection( el_cl_eta
                                                    , el_E_uncorrected
                                                    , egRescaler::EnergyRescalerUpgrade::ERR_DOWN
                                                    );
    }
    else {
      smearcorr = m_e_rescale->getSmearingCorrection( el_cl_eta
                                                    , el_E_uncorrected
                                                    , egRescaler::EnergyRescalerUpgrade::NOMINAL
                                                    );
    }
    el_E_corrected *= smearcorr;

    // Apply Atlfast specific calibration corrections (Atlfast only)
    if (m_is_af2) {
      el_E_corrected *= m_e_rescale->applyAFtoG4(el_cl_eta);
    }
  }
  else {
    // Residual energy scale correction for data
    el_E_corrected = m_e_rescale->applyEnergyCorrection( el_cl_eta
                                                       , el_E_uncorrected
                                                       , egRescaler::EnergyRescalerUpgrade::Electron
                                                       , egRescaler::EnergyRescalerUpgrade::Nominal
                                                       );
  }

  return el_E_corrected;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::ElectronRescalerTool::getRescaledEt(const PennSusyFrame::Electron* p)
{
  return 0.;

  double el_E_corrected = getRescaledE(p);
  double el_Et_corrected = el_E_corrected/cosh(p->getRawEta());
  return el_Et_corrected;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::ElectronRescalerTool::applyEES(double el_e, double el_eta)
{
  double da = 0.;

  if (m_syst_struct->getSyst("do_zee_all_up")) {
    da = m_e_rescale->getAlphaUncertainty( el_eta
                                         , el_e
                                         , egRescaler::EnergyRescalerUpgrade::Electron
                                         , egRescaler::EnergyRescalerUpgrade::ZeeAllUp
                                         );
  }

  if (m_syst_struct->getSyst("do_zee_all_down")) {
    da = m_e_rescale->getAlphaUncertainty( el_eta
                                         , el_e
                                         , egRescaler::EnergyRescalerUpgrade::Electron
                                         , egRescaler::EnergyRescalerUpgrade::ZeeAllDown
                                         );
  }

  if (m_syst_struct->getSyst("do_r12_stat_up")) {
    da = m_e_rescale->getAlphaUncertainty( el_eta
                                         , el_e
                                         , egRescaler::EnergyRescalerUpgrade::Electron
                                         , egRescaler::EnergyRescalerUpgrade::R12StatUp
                                         );
  }

  if (m_syst_struct->getSyst("do_r12_stat_down")) {
    da = m_e_rescale->getAlphaUncertainty( el_eta
                                         , el_e
                                         , egRescaler::EnergyRescalerUpgrade::Electron
                                         , egRescaler::EnergyRescalerUpgrade::R12StatDown
                                         );
  }

  if (m_syst_struct->getSyst("do_ps_stat_up")) {
    da = m_e_rescale->getAlphaUncertainty( el_eta
                                         , el_e
                                         , egRescaler::EnergyRescalerUpgrade::Electron
                                         , egRescaler::EnergyRescalerUpgrade::PSStatUp
                                         );
  }

  if (m_syst_struct->getSyst("do_ps_stat_down")) {
    da = m_e_rescale->getAlphaUncertainty( el_eta
                                         , el_e
                                         , egRescaler::EnergyRescalerUpgrade::Electron
                                         , egRescaler::EnergyRescalerUpgrade::PSStatDown
                                         );
  }

  if (m_syst_struct->getSyst("do_low_pt_up")) {
    da = m_e_rescale->getAlphaUncertainty( el_eta
                                         , el_e
                                         , egRescaler::EnergyRescalerUpgrade::Electron
                                         , egRescaler::EnergyRescalerUpgrade::LowPtUp
                                         );
  }

  if (m_syst_struct->getSyst("do_low_pt_down")) {
    da = m_e_rescale->getAlphaUncertainty( el_eta
                                         , el_e
                                         , egRescaler::EnergyRescalerUpgrade::Electron
                                         , egRescaler::EnergyRescalerUpgrade::LowPtDown
                                         );
  }

  return el_e*(1+da);
}

// =============================================================================
// = MuonRescalerTool
// =============================================================================
PennSusyFrame::MuonRescalerTool::MuonRescalerTool(bool is_data
                                                 , PennSusyFrame::SystematicStruct* syst_struct
                                                 ) : m_is_data(is_data)
                                                   , m_syst_struct(syst_struct)
                                                   , m_mcp_smear(0)
                                                   , m_smearing_function("")
{
  init();
}

// -----------------------------------------------------------------------------
PennSusyFrame::MuonRescalerTool::~MuonRescalerTool()
{
  if (m_mcp_smear)
    delete m_mcp_smear;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::MuonRescalerTool::init()
{
  if (m_is_data) return;
  // get default path for muon SF directory.  This comes from SUSYTools
  std::string root_core_dir = getenv("ROOTCOREDIR");
  m_muon_momentum_dir = root_core_dir + "/../MuonMomentumCorrections/share/";
  std::cout << "Muon momentum smearing will be grabbed from: "
            << m_muon_momentum_dir << "\n";

  // create mcp smearing object
  m_mcp_smear = new MuonSmear::SmearingClass( "Data12"
                                            , "staco"
                                            , "q_pT"
					      //, "Rel17.2Repro"
					      , "Rel17.2Sum13" //updated as of susytools 3-16
                                            , m_muon_momentum_dir
                                            );

  if (!m_is_data && m_syst_struct) {
    if (m_syst_struct->getSyst("do_ms_low")) {
      m_smearing_function = "MSLOW";
    }
    if (m_syst_struct->getSyst("do_ms_up")) {
      m_smearing_function = "MSUP";
    }
    if (m_syst_struct->getSyst("do_id_low")) {
      m_smearing_function = "IDLOW";
    }
    if (m_syst_struct->getSyst("do_id_up")) {
      m_smearing_function = "IDUP";
    }
    if (m_syst_struct->getSyst("do_mu_mom_scale_low")) {
      m_smearing_function = "SCALELOW";
    }
    if (m_syst_struct->getSyst("do_mu_mom_scale_up")) {
      m_smearing_function = "SCALEUP";
    }
  }
}

// -----------------------------------------------------------------------------
double PennSusyFrame::MuonRescalerTool::getSmearedPt(const PennSusyFrame::Muon* p)
{
  double my_pt = p->getRawPt();

  // if not data, apply momentum smearing
  if (!m_is_data) {
    double mu_eta = p->getRawEta();
    double mu_phi = p->getRawPhi();

    if (m_mcp_smear) {
      // combined muon pt
      double pt_cb = my_pt;
      // id only pt
      double pt_id = ( (p->getIdQOverP() !=0) ? fabs(sin(p->getIdTheta())/p->getIdQOverP())
                                              : 0
                     );
      // MS only pt
      double pt_ms = ( (p->getMEQOverP() !=0) ? fabs(sin(p->getMETheta())/p->getMEQOverP())
                                              : 0
                     );

      // set seed based on the muon phi measurement. If seed is exactly 0, increment
      int seed = static_cast<int>(1.e+5*fabs(mu_phi));
      if (!seed) ++seed;
      m_mcp_smear->SetSeed(seed);

      // set event information for muon smearing
      if (p->getIsCombined()) {
        m_mcp_smear->Event(pt_ms, pt_id, pt_cb, mu_eta, p->getCharge(), mu_phi);
      }
      else if (p->getIsSegmentTagged()) {
        m_mcp_smear->Event(pt_id, mu_eta, "ID", p->getCharge(), mu_phi);
      }
      else {
        m_mcp_smear->Event(pt_ms, mu_eta, "MS", p->getCharge(), mu_phi);
      }

      // smear muon based on smearing function
      if (m_smearing_function == "") {
        // if combined muon
        if (p->getIsCombined()) {
          my_pt = m_mcp_smear->pTCB();
        }
        // else if segment tagged muon
        else if (p->getIsSegmentTagged()) {
          my_pt = m_mcp_smear->pTID();
        }
        // else if ms only muon
        else {
          my_pt = m_mcp_smear->pTMS();
        }
      }
      else {
        double pTMS_smeared = my_pt;
        double pTID_smeared = my_pt;
        double pTCB_smeared = my_pt;

        // Valid values for "c_smearing_function":
        //   {"MSLOW", "MSUP", "IDLOW", "IDUP","SCALELOW", "SCALEUP"}
        m_mcp_smear->PTVar( pTMS_smeared
                          , pTID_smeared
                          , pTCB_smeared
                          , m_smearing_function
                          );

        if (p->getIsCombined()) {
          my_pt = pTCB_smeared;
        }
        else if (p->getIsSegmentTagged()) {
          my_pt = pTID_smeared;
        }
        else {
          my_pt = pTMS_smeared;
        }
      }
    }
  }

  return my_pt;
}

// =============================================================================
// = JetRescalerTool
// =============================================================================
PennSusyFrame::JetRescalerTool::JetRescalerTool( bool is_data
                                               , bool is_af2
                                               , bool is_mc_12b
                                               , PennSusyFrame::SystematicStruct* syst_struct
                                               ) : m_is_data(is_data)
                                                 , m_is_af2(is_af2)
                                                 , m_is_mc12b(is_mc_12b)
                                                 , m_syst_struct(syst_struct)
                                                 , m_jet_calibration(0)
                                                 , m_jer_smearing(0)
                                                 , m_jes_tool(0)
{
  init();
}

// -----------------------------------------------------------------------------
PennSusyFrame::JetRescalerTool::~JetRescalerTool()
{
  if (m_jet_calibration)
    delete m_jet_calibration;
  if (m_jer_smearing)
    delete m_jer_smearing;
  if (m_jes_tool)
    delete m_jes_tool;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::JetRescalerTool::init()
{
  std::string jet_algorithm = "AntiKt4LCTopo";
  std::string root_core_dir = getenv("ROOTCOREDIR");

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // configure Jet calibration tool
  std::string jes_config_file;
  std::string mc_type = "";
  if (m_is_af2) {
    if(!m_is_mc12b) {
      std::cout << "setting up JES for MC12a AF2\n";
      jes_config_file = ( root_core_dir
                        + "/../ApplyJetCalibration/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_AFII_Jan13.config"
                        );
      mc_type = "AFII MC12a";
    }
    else {
      std::cout << "setting up JES for MC12b AF2\n";
      jes_config_file = ( root_core_dir
                        + "/../ApplyJetCalibration/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_MC12b_AFII_Sep23.config"
                        );
      mc_type = "AFII MC12b";
    }
  }
  else {
    if(!m_is_mc12b) {
      std::cout << "setting up JES for MC12a full sim\n";
      jes_config_file = ( root_core_dir
                        + "/../ApplyJetCalibration/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_Jan13.config"
                        );
      mc_type = "MC12a";
    }
    else {
      std::cout << "setting up JES for MC12b full sim\n";
      jes_config_file = ( root_core_dir
                        + "/../ApplyJetCalibration/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_MC12b_Sep23.config"
                        );
      mc_type = "MC12b";
    }
  }

  m_jet_calibration = new JetAnalysisCalib::JetCalibrationTool( jet_algorithm
                                                              , jes_config_file
                                                              , m_is_data
                                                              );
  m_jet_calibration->UseGeV(false);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // only configure JER and JES if we are in MC
  if (m_is_data) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // configure JER smearing tool
  std::string jer_config_file = root_core_dir + "../JetResolution/share/JERProviderPlots_2012.root";
  m_jer_smearing = new JetSmearingTool(jet_algorithm, jer_config_file);
  m_jer_smearing->init();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // configure JES tool
  //
  std::string multi_jes_file = "JES_2012/Moriond2013/MultijetJES_2012.config";
  std::string jes_file       = "JES_2012/Moriond2013/InsituJES2012_14NP.config";
  std::string jes_path       = root_core_dir + "/../JetUncertainties/share/";

  m_jes_tool = new MultijetJESUncertaintyProvider( multi_jes_file
                                                 , jes_file
                                                 , jet_algorithm
                                                 , m_is_af2 ? "AFII" : "MC12a"
                                                 , jes_path
                                                 );
}

// -----------------------------------------------------------------------------
TLorentzVector PennSusyFrame::JetRescalerTool::getCalibratedTlv( const PennSusyFrame::Jet* p
                                                               , const PennSusyFrame::Event* event
                                                               , int   num_vertices_ge_2_tracks
                                                               )
{
  TLorentzVector calibrated_tlv = m_jet_calibration->ApplyJetAreaOffsetEtaJES( p->getConstScaleE()
                                                                             , p->getConstScaleEta()
                                                                             , p->getConstScalePhi()
                                                                             , p->getConstScaleM()
                                                                             , p->getActiveAreaPx()
                                                                             , p->getActiveAreaPy()
                                                                             , p->getActiveAreaPz()
                                                                             , p->getActiveAreaE()
                                                                             , event->getEventShapeRhoKt4LC()
                                                                             , event->getAverageIntPerXing()
                                                                             , num_vertices_ge_2_tracks
                                                                             );

  if (!m_is_data && m_syst_struct != 0) {
    if (m_syst_struct->getSyst("do_jer")) {
      applyJER(calibrated_tlv);
    }
    if (  m_syst_struct->getSyst("do_jes_up")
       || m_syst_struct->getSyst("do_jes_down")
       || m_syst_struct->getSyst("do_effective_np_1_up")
       || m_syst_struct->getSyst("do_effective_np_1_down")
       || m_syst_struct->getSyst("do_effective_np_2_up")
       || m_syst_struct->getSyst("do_effective_np_2_down")
       || m_syst_struct->getSyst("do_effective_np_3_up")
       || m_syst_struct->getSyst("do_effective_np_3_down")
       || m_syst_struct->getSyst("do_effective_np_4_up")
       || m_syst_struct->getSyst("do_effective_np_4_down")
       || m_syst_struct->getSyst("do_effective_np_5_up")
       || m_syst_struct->getSyst("do_effective_np_5_down")
       || m_syst_struct->getSyst("do_effective_np_6_up")
       || m_syst_struct->getSyst("do_effective_np_6_down")
       || m_syst_struct->getSyst("do_eta_intercalibration_modelling_up")
       || m_syst_struct->getSyst("do_eta_intercalibration_modelling_down")
       || m_syst_struct->getSyst("do_eta_intercalibration_statand_method_up")
       || m_syst_struct->getSyst("do_eta_intercalibration_statand_method_down")
       || m_syst_struct->getSyst("do_single_particle_high_pt_up")
       || m_syst_struct->getSyst("do_single_particle_high_pt_down")
       || m_syst_struct->getSyst("do_relative_non_closure_pythia8_up")
       || m_syst_struct->getSyst("do_relative_non_closure_pythia8_down")
       || m_syst_struct->getSyst("do_pile_up_offset_term_mu_up")
       || m_syst_struct->getSyst("do_pile_up_offset_term_mu_down")
       || m_syst_struct->getSyst("do_pile_up_offset_term_npv_up")
       || m_syst_struct->getSyst("do_pile_up_offset_term_npv_down")
       || m_syst_struct->getSyst("do_pile_up_pt_term_up")
       || m_syst_struct->getSyst("do_pile_up_pt_term_down")
       || m_syst_struct->getSyst("do_pile_up_rho_topology_up")
       || m_syst_struct->getSyst("do_pile_up_rho_topology_down")
       || m_syst_struct->getSyst("do_closeby_up")
       || m_syst_struct->getSyst("do_closeby_down")
       || m_syst_struct->getSyst("do_flavor_comp_uncert_up")
       || m_syst_struct->getSyst("do_flavor_comp_uncert_down")
       || m_syst_struct->getSyst("do_flavor_response_uncert_up")
       || m_syst_struct->getSyst("do_flavor_response_uncert_down")
       || m_syst_struct->getSyst("do_bjes_up")
       || m_syst_struct->getSyst("do_bjes_down")
       ) {
      applyJES( calibrated_tlv
              , p->getFlavorTruthLabel()
              , num_vertices_ge_2_tracks
              , event->getAverageIntPerXing()
              );
    }
  }

  return calibrated_tlv;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::JetRescalerTool::applyJER(TLorentzVector& tlv)
{
  // don't apply JER if pT < 20 GeV
  if (tlv.Pt() < 20.e3) return;

  // use jet phi to define seed for random number
  int seed = int(fabs(tlv.Phi()*1.e5));
  if (!seed) ++seed;
  m_jer_smearing->SetSeed(seed);

  // apply jet smearing
  if (m_is_af2)
    m_jer_smearing->SmearJet_Syst_AFII(tlv);
  else
    m_jer_smearing->SmearJet_Syst(tlv);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::JetRescalerTool::applyJES( TLorentzVector& tlv
                                             , int flavor_truth_label
                                             , int num_vert_ge_2_trk
                                             , float mu
                                             )
{
  /// JES HANDLING
  double uncertainty = 0.;
  double factor = 1.;
  bool is_b_jet = (flavor_truth_label == 5);
  float f_closeby = 0;

  double old_pt  = tlv.Pt();
  double old_eta = tlv.Eta();
  double old_e   = tlv.E();

  if(m_syst_struct->getSyst("do_jes_up")) {
    uncertainty = m_jes_tool->getRelUncert( old_pt
                                          , old_eta
                                          , f_closeby
                                          , true
                                          , num_vert_ge_2_trk
                                          , mu
                                          , is_b_jet
                                          );
  }
  if(m_syst_struct->getSyst("do_jes_down")) {
    uncertainty = m_jes_tool->getRelUncert( old_pt
                                          , old_eta
                                          , f_closeby
                                          , false
                                          , num_vert_ge_2_trk
                                          , mu
                                          , is_b_jet
                                          );
    factor = -1;
  }

  // effectiveNP_1
  if (m_syst_struct->getSyst("do_effective_np_1_up")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_1"
                                                   , old_pt
                                                   , old_eta
                                                   );
  }
  if (m_syst_struct->getSyst("do_effective_np_1_down")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_1"
                                                   , old_pt
                                                   , old_eta
                                                   );
    factor = -1;
  }

  // effectiveNP_2
  if (m_syst_struct->getSyst("do_effective_np_2_up")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_2"
                                                   , old_pt
                                                   , old_eta
                                                   );
  }
  if (m_syst_struct->getSyst("do_effective_np_2_down")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_2"
                                                   , old_pt
                                                   , old_eta
                                                   );
    factor = -1;
  }

  // EffectiveNP_3
  if (m_syst_struct->getSyst("do_effective_np_3_up")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_3"
                                                   , old_pt
                                                   , old_eta
                                                   );
  }
  if (m_syst_struct->getSyst("do_effective_np_3_down")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_3"
                                                   , old_pt
                                                   , old_eta
                                                   );
    factor = -1;
  }

  // EffectiveNP_4
  if (m_syst_struct->getSyst("do_effective_np_4_up")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_4"
                                                   , old_pt
                                                   , old_eta
                                                   );
  }
  if (m_syst_struct->getSyst("do_effective_np_4_down")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_4"
                                                   , old_pt
                                                   , old_eta
                                                   );
    factor = -1;
  }

  // EffectiveNP_5
  if (m_syst_struct->getSyst("do_effective_np_5_up")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_5"
                                                   , old_pt
                                                   , old_eta
                                                   );
  }
  if (m_syst_struct->getSyst("do_effective_np_5_down")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_5"
                                                   , old_pt
                                                   , old_eta
                                                   );
    factor = -1;
  }

  // EffectiveNP_6restTerm
  if (m_syst_struct->getSyst("do_effective_np_6_up")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_6restTerm"
                                                   , old_pt
                                                   , old_eta
                                                   );
  }
  if (m_syst_struct->getSyst("do_effective_np_6_down")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EffectiveNP_6restTerm"
                                                   , old_pt
                                                   , old_eta
                                                   );
    factor = -1;
  }

  // EtaIntercalibration_Modelling
  if (m_syst_struct->getSyst("do_eta_intercalibration_modelling_up")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EtaIntercalibration_Modelling"
                                                   , old_pt
                                                   , old_eta
                                                   );
  }
  if (m_syst_struct->getSyst("do_eta_intercalibration_modelling_down")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EtaIntercalibration_Modelling"
                                                   , old_pt
                                                   , old_eta
                                                   );
    factor = -1;
  }

  // EtaIntercalibration_StatAndMethod
  if (m_syst_struct->getSyst("do_eta_intercalibration_statand_method_up")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EtaIntercalibration_StatAndMethod"
                                                   , old_pt
                                                   , old_eta
                                                   );
  }
  if (m_syst_struct->getSyst("do_eta_intercalibration_statand_method_down")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "EtaIntercalibration_StatAndMethod"
                                                   , old_pt
                                                   , old_eta
                                                   );
    factor = -1;
  }

  // SingleParticle_HighPt
  if (m_syst_struct->getSyst("do_single_particle_high_pt_up")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "SingleParticle_HighPt"
                                                   , old_pt
                                                   , old_eta
                                                   );
  }
  if (m_syst_struct->getSyst("do_single_particle_high_pt_down")) {
    uncertainty = m_jes_tool->getRelUncertComponent( "SingleParticle_HighPt"
                                                   , old_pt
                                                   , old_eta
                                                   );
    factor = -1;
  }

  // RelativeNonClosure_pythia8
  if (m_syst_struct->getSyst("do_relative_non_closure_pythia8_up")) {
    if (m_is_af2) {
      uncertainty = m_jes_tool->getRelUncertComponent( "RelativeNonClosure_AFII"
                                                     , old_pt
                                                     , old_eta
                                                     );
    }
    else {
      uncertainty = m_jes_tool->getRelUncertComponent( "RelativeNonClosure_Pythia8"
                                                     , old_pt
                                                     , old_eta
                                                     );
    }
  }
  if (m_syst_struct->getSyst("do_relative_non_closure_pythia8_down")) {
    if (m_is_af2) {
      uncertainty = m_jes_tool->getRelUncertComponent( "RelativeNonClosure_AFII"
                                                     , old_pt
                                                     , old_eta
                                                     );
    }
    else {
      uncertainty = m_jes_tool->getRelUncertComponent( "RelativeNonClosure_Pythia8"
                                                     , old_pt
                                                     , old_eta
                                                     );
    }
    factor = -1;
  }

  // pile up offset term mu
  if (m_syst_struct->getSyst("do_pile_up_offset_term_mu_up")) {
    uncertainty = m_jes_tool->getRelMuOffsetTerm(old_pt, old_eta, mu);
  }
  if (m_syst_struct->getSyst("do_pile_up_offset_term_mu_down")) {
    uncertainty = m_jes_tool->getRelMuOffsetTerm(old_pt, old_eta, mu);
    factor = -1;
  }

  // pile up offset term npv
  if (m_syst_struct->getSyst("do_pile_up_offset_term_npv_up")) {
    uncertainty = m_jes_tool->getRelNPVOffsetTerm( old_pt
                                                 , old_eta
                                                 , num_vert_ge_2_trk
                                                 );
  }
  if (m_syst_struct->getSyst("do_pile_up_offset_term_npv_down")) {
    uncertainty = m_jes_tool->getRelNPVOffsetTerm( old_pt
                                                 , old_eta
                                                 , num_vert_ge_2_trk
                                                 );
    factor = -1;
  }

  // pile up pt term
  if (m_syst_struct->getSyst("do_pile_up_pt_term_up")) {
    uncertainty = m_jes_tool->getRelPileupPtTerm( old_pt
                                                , old_eta
                                                , num_vert_ge_2_trk
                                                , mu
                                                );
  }
  if (m_syst_struct->getSyst("do_pile_up_pt_term_down")) {
    uncertainty = m_jes_tool->getRelPileupPtTerm( old_pt
                                                , old_eta
                                                , num_vert_ge_2_trk
                                                , mu
                                                );
    factor = -1;
  }

  // pile up rho topology
  if (m_syst_struct->getSyst("do_pile_up_rho_topology_up")) {
    uncertainty = m_jes_tool->getRelPileupRhoTopology( old_pt
                                                     , old_eta
                                                     );
  }
  if (m_syst_struct->getSyst("do_pile_up_rho_topology_down")) {
    uncertainty = m_jes_tool->getRelPileupRhoTopology( old_pt
                                                     , old_eta
                                                     );
    factor = -1;
  }

  // close by
  if (m_syst_struct->getSyst("do_closeby_up")) {
    uncertainty = m_jes_tool->getRelClosebyUncert(old_pt, f_closeby);
  }
  if (m_syst_struct->getSyst("do_closeby_down")) {
    uncertainty = m_jes_tool->getRelClosebyUncert(old_pt, f_closeby);
    factor = -1;
  }

  // flavor comp
  if (m_syst_struct->getSyst("do_flavor_comp_uncert_up")) {
    // only apply to non b-jets
    uncertainty = (!is_b_jet) ? m_jes_tool->getRelFlavorCompUncert(old_pt,old_eta,true)
                              : 0;
  }
  if (m_syst_struct->getSyst("do_flavor_comp_uncert_down")) {
    // only apply to non b-jets
    uncertainty = (!is_b_jet) ? m_jes_tool->getRelFlavorCompUncert(old_pt,old_eta,true)
                              : 0;
    factor = -1;
  }

  // flavor response
  if (m_syst_struct->getSyst("do_flavor_response_uncert_up")) {
    // only apply to non b-jets
    uncertainty = (!is_b_jet) ? m_jes_tool->getRelFlavorResponseUncert(old_pt,old_eta)
                              : 0;
  }
  if (m_syst_struct->getSyst("do_flavor_response_uncert_down")) {
    // only apply to non b-jets
    uncertainty = (!is_b_jet) ? m_jes_tool->getRelFlavorResponseUncert(old_pt,old_eta)
                              : 0;
    factor = -1;
  }

  // b jes
  if (m_syst_struct->getSyst("do_bjes_up")) {
    // only apply to b-jets
    uncertainty = (is_b_jet) ? m_jes_tool->getRelBJESUncert(old_pt,old_eta)
                             : 0;
  }
  if (m_syst_struct->getSyst("do_bjes_down")) {
    // only apply to b-jets
    uncertainty = (is_b_jet) ? m_jes_tool->getRelBJESUncert(old_pt,old_eta)
                             : 0;
    factor = -1;
  }

  double new_pt = old_pt*(1 + (factor*uncertainty));
  double new_e  = old_e*( 1 + (factor*uncertainty));

  tlv.SetPtEtaPhiE(new_pt, old_eta, tlv.Phi(), new_e);
}

// =============================================================================
// = TauRescalerTool
// =============================================================================
PennSusyFrame::TauRescalerTool::TauRescalerTool(bool is_data, bool is_af2) : m_is_data(is_data)
                                                                           , m_is_af2(is_af2)
{
  init();
}

// -----------------------------------------------------------------------------
PennSusyFrame::TauRescalerTool::~TauRescalerTool()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TauRescalerTool::init()
{
  // TODO initialize TauRescalerTool
}
