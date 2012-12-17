#include <math.h>
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/ElectronOutputTool.h"

// ----------------------------------------------------------------------------
CommonTools::ElectronOutputTool::ElectronOutputTool( SCycleBase* parent
                                                   , const char* name
                                                   )
                                                   : ToolBase(parent, name)
{
  DeclareProperty("do_detailed_output", c_do_detailed_output= false);
  DeclareProperty( "electron_container_name"
                 , c_electron_output_collection = "baseline"
                 );
}

// ----------------------------------------------------------------------------
CommonTools::ElectronOutputTool::~ElectronOutputTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void CommonTools::ElectronOutputTool::BeginInputData( const SInputData& )
{
  DeclareVariable(m_el_E                     , "el_E"                     );
  // DeclareVariable(m_el_E_corr                , "el_E_corr"                );
  DeclareVariable(m_el_Et                    , "el_Et"                    );
  DeclareVariable(m_el_pt                    , "el_pt"                    );
  // DeclareVariable(m_el_pt_corr               , "el_pt_corr"               );
  DeclareVariable(m_el_eta                   , "el_eta"                   );
  DeclareVariable(m_el_eta_cl                , "el_eta_cl"                );
  DeclareVariable(m_el_eta_track             , "el_eta_track"             );
  DeclareVariable(m_el_phi                   , "el_phi"                   );
  DeclareVariable(m_el_phi_cl                , "el_phi_cl"                );
  DeclareVariable(m_el_phi_track             , "el_phi_track"             );
  DeclareVariable(m_el_d0                    , "el_d0"                    );
  DeclareVariable(m_el_d0_physics            , "el_d0_physics"            );
  DeclareVariable(m_el_d0_pv                 , "el_d0_pv"                 );
  DeclareVariable(m_el_z0                    , "el_z0"                    );
  DeclareVariable(m_el_z0_pv                 , "el_z0_pv"                 );
  DeclareVariable(m_el_d0_pv_sig             , "el_d0_pv_sig"             );
  DeclareVariable(m_el_z0_pv_sig             , "el_z0_pv_sig"             );
  DeclareVariable(m_el_d0_sig                , "el_d0_sig"                );
  DeclareVariable(m_el_z0_sin_theta          , "el_z0_sin_theta"          );
  DeclareVariable(m_el_charge                , "el_charge"                );
  DeclareVariable(m_el_cf_smeared_pt         , "el_cf_smeared_pt"         );
  DeclareVariable(m_el_desc                  , "el_desc"                  );
  // DeclareVariable(m_el_mt                    , "el_mt"                    );

  DeclareVariable(m_el_etcone20              , "el_etcone20"              );
  DeclareVariable(m_el_etcone30              , "el_etcone30"              );
  DeclareVariable(m_el_etcone40              , "el_etcone40"              );
  DeclareVariable(m_el_ptcone20              , "el_ptcone20"              );
  DeclareVariable(m_el_ptcone30              , "el_ptcone30"              );
  DeclareVariable(m_el_ptcone40              , "el_ptcone40"              );
  DeclareVariable(m_el_topoetcone20          , "el_topoetcone20"          );
  DeclareVariable(m_el_topoetcone30          , "el_topoetcone30"          );
  DeclareVariable(m_el_topoetcone40          , "el_topoetcone40"          );
  DeclareVariable(m_el_topoetcone20_corrected, "el_topoetcone20_corrected");
  DeclareVariable(m_el_topoetcone30_corrected, "el_topoetcone30_corrected");
  DeclareVariable(m_el_topoetcone40_corrected, "el_topoetcone40_corrected");

  //Detailed Variables
  if(c_do_detailed_output)
  {
    DeclareVariable(m_el_raw_etcone20, "el_raw_etcone20");
    DeclareVariable(m_el_raw_etcone30, "el_raw_etcone30");
    DeclareVariable(m_el_raw_etcone40, "el_raw_etcone40");

    DeclareVariable(m_el_raw_ptcone20, "el_raw_ptcone20");
    DeclareVariable(m_el_raw_ptcone30, "el_raw_ptcone30");
    DeclareVariable(m_el_raw_ptcone40, "el_raw_ptcone40");

    DeclareVariable(m_el_raw_topoetcone20, "el_raw_topoetcone20");
    DeclareVariable(m_el_raw_topoetcone30, "el_raw_topoetcone30");
    DeclareVariable(m_el_raw_topoetcone40, "el_raw_topoetcone40");

    DeclareVariable(
        m_el_raw_topoetcone20_corrected, "el_raw_topoetcone20_corrected");
    DeclareVariable(
        m_el_raw_topoetcone30_corrected, "el_raw_topoetcone30_corrected");
    DeclareVariable(
        m_el_raw_topoetcone40_corrected, "el_raw_topoetcone40_corrected");

    DeclareVariable(m_el_OQ                  , "el_OQ"                  );
    DeclareVariable(m_el_OQ_recalc           , "el_OQRecalc"            );
    DeclareVariable(m_el_trt_ht_outlier_ratio, "el_trt_ht_outlier_ratio");
    DeclareVariable(m_el_author              , "el_author"              );
    DeclareVariable(m_el_conv_flag           , "el_convFlag"            );
    DeclareVariable(m_el_expect_b_layer      , "el_expect_b_layer_hit"  );
    DeclareVariable(m_el_weta2               , "el_weta2"               );
    DeclareVariable(m_el_wstot               , "el_wstot"               );
    DeclareVariable(m_el_reta                , "el_reta"                );
    DeclareVariable(m_el_ethad               , "el_ethad"               );
    DeclareVariable(m_el_ethad1              , "el_ethad1"              );
    DeclareVariable(m_el_num_pix_hits        , "el_num_pix_hits"        );
    DeclareVariable(m_el_num_pix_holes       , "el_num_pix_holes"       );
    DeclareVariable(m_el_num_pix_outliers    , "el_num_pix_outliers"    );
    DeclareVariable(m_el_num_sct_hits        , "el_num_sct_hits"        );
    DeclareVariable(m_el_num_sct_holes       , "el_num_sct_holes"       );
    DeclareVariable(m_el_num_sct_outliers    , "el_num_sct_outliers"    );
    DeclareVariable(m_el_num_trt_hits        , "el_num_trt_hits"        );
    DeclareVariable(m_el_num_trt_holes       , "el_num_trt_holes"       );
    DeclareVariable(m_el_num_trt_outliers    , "el_num_trt_outliers"    );
    DeclareVariable(m_el_num_trt_ht_hits     , "el_num_trt_ht_hits"     );
    DeclareVariable(m_el_num_trt_ht_outliers , "el_num_trt_ht_outliers" );
    DeclareVariable(m_el_num_bl_hits         , "el_num_bl_hits"         );
    DeclareVariable(m_el_num_bl_outliers     , "el_num_bl_outliers"     );
    DeclareVariable(m_el_fside               , "el_fside"               );
    DeclareVariable(m_el_delta_eta1          , "el_delta_eta1"          );
    DeclareVariable(m_el_delta_eta2          , "el_delta_eta2"          );
    DeclareVariable(m_el_delta_phi2          , "el_delta_phi_2"         );
    DeclareVariable(m_el_emaxs1              , "el_emaxs1"              );
    DeclareVariable(m_el_f1                  , "el_f1"                  );
    DeclareVariable(m_el_f3                  , "el_f3"                  );
  }

  DeclareVariable(m_el_truth_charge        , "el_truth_charge"        );

  DeclareVariable(m_el_tlv, "el_tlv");
}

// ----------------------------------------------------------------------------
void CommonTools::ElectronOutputTool::BeginExecuteEvent(
    const SInputData&, Double_t )
{
  m_el_E.clear();
  // m_el_E_corr.clear();
  m_el_Et.clear();
  m_el_pt.clear();
  // m_el_pt_corr.clear();
  m_el_eta.clear();
  m_el_eta_cl.clear();
  m_el_eta_track.clear();
  m_el_phi.clear();
  m_el_phi_cl.clear();
  m_el_phi_track.clear();
  m_el_etcone20.clear();
  m_el_etcone30.clear();
  m_el_etcone40.clear();
  m_el_ptcone20.clear();
  m_el_ptcone30.clear();
  m_el_ptcone40.clear();
  m_el_topoetcone20.clear();
  m_el_topoetcone30.clear();
  m_el_topoetcone40.clear();
  m_el_topoetcone20_corrected.clear();
  m_el_topoetcone30_corrected.clear();
  m_el_topoetcone40_corrected.clear();
  m_el_raw_etcone20.clear();
  m_el_raw_etcone30.clear();
  m_el_raw_etcone40.clear();
  m_el_raw_ptcone20.clear();
  m_el_raw_ptcone30.clear();
  m_el_raw_ptcone40.clear();
  m_el_raw_topoetcone20.clear();
  m_el_raw_topoetcone30.clear();
  m_el_raw_topoetcone40.clear();
  m_el_raw_topoetcone20_corrected.clear();
  m_el_raw_topoetcone30_corrected.clear();
  m_el_raw_topoetcone40_corrected.clear();
  m_el_d0.clear();
  m_el_d0_physics.clear();
  m_el_d0_pv.clear();
  m_el_z0.clear();
  m_el_z0_pv.clear();
  m_el_d0_pv_sig.clear();
  m_el_z0_pv_sig.clear();
  m_el_d0_sig.clear();
  m_el_z0_sin_theta.clear();
  m_el_charge.clear();
  m_el_OQ.clear();
  m_el_OQ_recalc.clear();
  m_el_trt_ht_outlier_ratio.clear();
  m_el_author.clear();
  m_el_conv_flag.clear();
  m_el_expect_b_layer.clear();
  m_el_weta2.clear();
  m_el_wstot.clear();
  m_el_reta.clear();
  m_el_ethad.clear();
  m_el_ethad1.clear();
  m_el_num_pix_hits.clear();
  m_el_num_pix_holes.clear();
  m_el_num_pix_outliers.clear();
  m_el_num_sct_hits.clear();
  m_el_num_sct_holes.clear();
  m_el_num_sct_outliers.clear();
  m_el_num_trt_hits.clear();
  m_el_num_trt_holes.clear();
  m_el_num_trt_outliers.clear();
  m_el_num_trt_ht_hits.clear();
  m_el_num_trt_ht_outliers.clear();
  m_el_num_bl_hits.clear();
  m_el_num_bl_outliers.clear();
  m_el_fside.clear();
  m_el_delta_eta1.clear();
  m_el_delta_eta2.clear();
  m_el_delta_phi2.clear();
  m_el_emaxs1.clear();
  m_el_f1.clear();
  m_el_f3.clear();
  m_el_cf_smeared_pt.clear();
  m_el_desc.clear();
  // m_el_mt.clear();

  m_el_truth_charge.clear();

  m_el_tlv.clear();
}

// ----------------------------------------------------------------------------
void CommonTools::ElectronOutputTool::fillOutput( Event* /*event*/
                                                , ElectronContainer& electrons
                                                , MuonContainer& /*muons*/
                                                , JetContainer& /*jets*/
                                                , Met* /*met*/
                                                , VertexContainer& vertices
                                                )
{
  m_logger << VERBOSE
           << "CommonTools::ElectronOutputTool::Fill"
           << SLogger::endmsg;

  // Fill electron varaibles

  std::vector<Electron*> el_vec;

  if (  c_electron_output_collection == "signal"
     || c_electron_output_collection == "Signal"
     ) {
    el_vec = electrons.getElectrons(EL_SIGNAL);
  }
  else if(  c_electron_output_collection == "good"
         || c_electron_output_collection == "Good"
         ) {
    el_vec =  electrons.getElectrons(EL_GOOD);
  }
  else if(  c_electron_output_collection == "baseline"
         || c_electron_output_collection == "Baseline"
         ) {
    el_vec =  electrons.getElectrons(EL_BASELINE);
  }
  else if(  c_electron_output_collection == "all"
         || c_electron_output_collection == "All"
         ) {
    el_vec =  electrons.getElectrons(EL_ALL);
  }
  else {
    m_logger << FATAL
             << "Could Not Parse Electron Output Level: "
             << c_electron_output_collection
             << SLogger::endmsg;
    throw SError(SError::StopExecution);
  }

  size_t num_el = el_vec.size();

  int num_good_vtx = vertices.num(VERT_GOOD);

  // before storing electrons to ntuple, we want to check the pt-ordering
  //   std::sort( cutflow.m_el_signal.begin()
  //            , cutflow.m_el_signal.end()
  //            , ElectronHandle::gt
  //            );

  for (size_t el_it=0; el_it != num_el; ++el_it) {
    TLorentzVector el_tlv =  el_vec.at(el_it)->getTlv();

    m_el_E.push_back(el_tlv.E());
    // m_el_E_corr.push_back(el_tlv.E());
    m_el_Et.push_back(el_tlv.Et());
    m_el_pt.push_back(el_tlv.Pt());
    // m_el_pt_corr.push_back(el_tlv.Pt());
    m_el_eta.push_back(el_tlv.Eta());
    m_el_eta_cl.push_back(el_vec.at(el_it)->cl_eta());

    m_el_eta_track.push_back(el_vec.at(el_it)->tracketa());
    m_el_phi.push_back(el_tlv.Phi());
    m_el_phi_cl.push_back(el_vec.at(el_it)->cl_phi());
    m_el_phi_track.push_back(el_vec.at(el_it)->trackphi());

    // fill electron description bit pattern
    m_el_desc.push_back(el_vec.at(el_it)->getElectronDesc()->toInt());
    m_el_d0.push_back(el_vec.at(el_it)->trackd0());
    m_el_d0_physics.push_back(el_vec.at(el_it)->trackd0_physics());
    m_el_d0_pv.push_back(el_vec.at(el_it)->trackd0pv());
    m_el_z0.push_back(el_vec.at(el_it)->trackz0());
    m_el_z0_pv.push_back(el_vec.at(el_it)->trackz0pv());
    m_el_d0_pv_sig.push_back(el_vec.at(el_it)->tracksigd0pv());
    m_el_z0_pv_sig.push_back(el_vec.at(el_it)->tracksigz0pv());
    m_el_d0_sig.push_back(el_vec.at(el_it)->getD0Significance());
    m_el_z0_sin_theta.push_back(el_vec.at(el_it)->getZ0SinTheta());
    m_el_charge.push_back(static_cast<int>(el_vec.at(el_it)->charge()));

    // TODO:  cf smeared pt -- for now indentical to regular pt
    m_el_cf_smeared_pt.push_back(el_tlv.Pt());

    m_el_etcone20.push_back(el_vec.at(el_it)->getIsoCorr(ETCONE, 20, num_good_vtx));
    m_el_etcone30.push_back(el_vec.at(el_it)->getIsoCorr(ETCONE, 30, num_good_vtx));
    m_el_etcone40.push_back(el_vec.at(el_it)->getIsoCorr(ETCONE, 40, num_good_vtx));
    m_el_ptcone20.push_back(el_vec.at(el_it)->getIsoCorr(PTCONE, 20, num_good_vtx));
    m_el_ptcone30.push_back(el_vec.at(el_it)->getIsoCorr(PTCONE, 30, num_good_vtx));
    m_el_ptcone40.push_back(el_vec.at(el_it)->getIsoCorr(PTCONE, 40, num_good_vtx));
    m_el_topoetcone20.push_back(el_vec.at(el_it)->getIsoCorr(TOPOETCONE, 20, num_good_vtx));
    m_el_topoetcone30.push_back(el_vec.at(el_it)->getIsoCorr(TOPOETCONE, 30, num_good_vtx));
    m_el_topoetcone40.push_back(el_vec.at(el_it)->getIsoCorr(TOPOETCONE, 40, num_good_vtx));
    m_el_topoetcone20_corrected.push_back(el_vec.at(el_it)->getIsoCorr(TOPOETCONE_CORR, 20, num_good_vtx));
    m_el_topoetcone30_corrected.push_back(el_vec.at(el_it)->getIsoCorr(TOPOETCONE_CORR, 30, num_good_vtx));
    m_el_topoetcone40_corrected.push_back(el_vec.at(el_it)->getIsoCorr(TOPOETCONE_CORR, 40, num_good_vtx));

    m_el_truth_charge.push_back(el_vec.at(el_it)->getTruthCharge());

    m_el_tlv.push_back(el_vec.at(el_it)->getTlv());

    if (c_do_detailed_output) {
      m_el_raw_etcone20.push_back(el_vec.at(el_it)->Etcone20());
      m_el_raw_etcone30.push_back(el_vec.at(el_it)->Etcone30());
      m_el_raw_etcone40.push_back(el_vec.at(el_it)->Etcone40());
      m_el_raw_ptcone20.push_back(el_vec.at(el_it)->ptcone20());
      m_el_raw_ptcone30.push_back(el_vec.at(el_it)->ptcone30());
      m_el_raw_etcone20.push_back(el_vec.at(el_it)->Etcone20());
      m_el_raw_etcone30.push_back(el_vec.at(el_it)->Etcone30());
      m_el_raw_etcone40.push_back(el_vec.at(el_it)->Etcone40());
      m_el_raw_ptcone20.push_back(el_vec.at(el_it)->ptcone20());
      m_el_raw_ptcone30.push_back(el_vec.at(el_it)->ptcone30());
      m_el_raw_ptcone40.push_back(el_vec.at(el_it)->ptcone40());
      m_el_raw_topoetcone20.push_back(el_vec.at(el_it)->topoEtcone20());
      m_el_raw_topoetcone30.push_back(el_vec.at(el_it)->topoEtcone30());
      m_el_raw_topoetcone40.push_back(el_vec.at(el_it)->topoEtcone40());
      m_el_raw_topoetcone20_corrected.push_back(el_vec.at(el_it)->topoEtcone20_corrected());
      m_el_raw_topoetcone30_corrected.push_back(el_vec.at(el_it)->topoEtcone30_corrected());
      m_el_raw_topoetcone40_corrected.push_back(el_vec.at(el_it)->topoEtcone40_corrected());

      m_el_OQ.push_back(el_vec.at(el_it)->OQ());
      m_el_OQ_recalc.push_back(0);
      m_el_trt_ht_outlier_ratio.push_back(el_vec.at(el_it)->TRTHighTOutliersRatio());
      m_el_author.push_back(el_vec.at(el_it)->author());
      m_el_conv_flag.push_back(el_vec.at(el_it)->convFlag());
      m_el_expect_b_layer.push_back(el_vec.at(el_it)->expectBLayerHit());
      m_el_weta2.push_back(el_vec.at(el_it)->weta2());
      m_el_wstot.push_back(el_vec.at(el_it)->wstot());
      m_el_reta.push_back(el_vec.at(el_it)->reta());
      m_el_ethad.push_back(el_vec.at(el_it)->Ethad());
      m_el_ethad1.push_back(el_vec.at(el_it)->Ethad1());
      m_el_num_pix_hits.push_back(el_vec.at(el_it)->nPixHits());
      m_el_num_pix_holes.push_back(el_vec.at(el_it)->nPixHoles());
      m_el_num_pix_outliers.push_back(el_vec.at(el_it)->nPixelOutliers());
      m_el_num_sct_hits.push_back(el_vec.at(el_it)->nSCTHits());
      m_el_num_sct_holes.push_back(el_vec.at(el_it)->nSCTHoles());
      m_el_num_sct_outliers.push_back(el_vec.at(el_it)->nSCTOutliers());
      m_el_num_trt_hits.push_back(el_vec.at(el_it)->nTRTHits());
      m_el_num_trt_holes.push_back(el_vec.at(el_it)->nTRTHoles());
      m_el_num_trt_outliers.push_back(el_vec.at(el_it)->nTRTOutliers());
      m_el_num_trt_ht_hits.push_back(el_vec.at(el_it)->nTRTHighTHits());
      m_el_num_trt_ht_outliers.push_back(el_vec.at(el_it)->nTRTHighTOutliers());
      m_el_num_bl_hits.push_back(el_vec.at(el_it)->nBLHits());
      m_el_num_bl_outliers.push_back(el_vec.at(el_it)->nBLayerOutliers());
      m_el_fside.push_back(el_vec.at(el_it)->fside());
      m_el_delta_eta1.push_back(el_vec.at(el_it)->deltaeta1());
      m_el_delta_eta2.push_back(el_vec.at(el_it)->deltaeta2());
      m_el_delta_phi2.push_back(el_vec.at(el_it)->deltaphi2());
      m_el_emaxs1.push_back(el_vec.at(el_it)->emaxs1());
      m_el_f1.push_back(el_vec.at(el_it)->f1());
      m_el_f3.push_back(el_vec.at(el_it)->f3());
    }
  }
}
