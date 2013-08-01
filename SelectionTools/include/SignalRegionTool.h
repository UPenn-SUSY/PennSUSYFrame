// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_SignalRegionTool_h
#define SelectionTools_SignalRegionTool_h

// =============================================================================
#include "AtlasSFrameUtils/include/ToolBase.h"

// =============================================================================
class Event;
class Met;
class ElectronContainer;
class MuonContainer;
class JetContainer;

namespace CommonTools
{
  class TopTagTool;
}
namespace SusyAnalysisTools
{
  class EventDescription;
  class SRHelper;
}

// =============================================================================
namespace SelectionTools
{
  // ===========================================================================
  class SignalRegionTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    SignalRegionTool( SCycleBase* parent
                    , const char* name = "EventCleaning"
                    );
    virtual ~SignalRegionTool();

    void BeginInputData( const SInputData& id);
    void EndInputData(   const SInputData& id);

    void processSignalRegions( Event*
                             , ElectronContainer&
                             , MuonContainer&
                             , JetContainer&
                             , Met*
                             );
    bool passSROSJVeto( SusyAnalysisTools::EventDescription*
                      , SusyAnalysisTools::SRHelper*
                      );
    bool passSRSSJets( SusyAnalysisTools::EventDescription*
                     , SusyAnalysisTools::SRHelper*
                     );
    bool passSR2Jets( SusyAnalysisTools::EventDescription*
                    , SusyAnalysisTools::SRHelper*
                    );
    bool passSRMT2a( SusyAnalysisTools::EventDescription*
                   , SusyAnalysisTools::SRHelper*
                   );
    bool passSRMT2b( SusyAnalysisTools::EventDescription*
                   , SusyAnalysisTools::SRHelper*
                   );

    bool passSRWWa( SusyAnalysisTools::EventDescription*
                  , SusyAnalysisTools::SRHelper*
                  );
    bool passSRWWb( SusyAnalysisTools::EventDescription*
                  , SusyAnalysisTools::SRHelper*
                  );
    bool passSRWWc( SusyAnalysisTools::EventDescription*
                  , SusyAnalysisTools::SRHelper*
                  );
    bool passSRZJets( SusyAnalysisTools::EventDescription*
                    , SusyAnalysisTools::SRHelper*
                    );

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passFullJetVeto(const JetContainer*);

    double c_z_window_mll_min;
    double c_z_window_mll_max;

    // SR osjveto cut values
    double c_sr_osjveto_met_rel_min;
    double c_sr_osjveto_met_rel_max;

    double c_sr_osjveto_mt2_min;
    double c_sr_osjveto_mt2_max;

    // SR ssjets cut values
    double c_sr_ssjets_mll_veto_min;
    double c_sr_ssjets_mll_veto_max;

    double c_sr_ssjets_ee_met_rel_min;
    double c_sr_ssjets_ee_met_rel_max;

    double c_sr_ssjets_mm_met_rel_min;
    double c_sr_ssjets_mm_met_rel_max;

    double c_sr_ssjets_em_met_rel_min;
    double c_sr_ssjets_em_met_rel_max;

    double c_sr_ssjets_ee_mt_min;
    double c_sr_ssjets_ee_mt_max;

    double c_sr_ssjets_mm_mt_min;
    double c_sr_ssjets_mm_mt_max;

    double c_sr_ssjets_em_mt_min;
    double c_sr_ssjets_em_mt_max;

    // SR 2jets cut values
    double c_sr_2jets_met_rel_min;
    double c_sr_2jets_met_rel_max;

    // SR mt2 cut values
    double c_sr_mt2_lep1_pt_min;
    double c_sr_mt2_lep1_pt_max;

    double c_sr_mt2_lep2_pt_min;
    double c_sr_mt2_lep2_pt_max;

    double c_sr_mt2_met_rel_min;
    double c_sr_mt2_met_rel_max;

    double c_sr_mt2a_mt2_min;
    double c_sr_mt2a_mt2_max;

    double c_sr_mt2b_mt2_min;
    double c_sr_mt2b_mt2_max;

    // SR ww cut values
    double c_sr_ww_lep1_pt_min;
    double c_sr_ww_lep1_pt_max;

    double c_sr_ww_lep2_pt_min;
    double c_sr_ww_lep2_pt_max;

    double c_sr_wwa_met_rel_min;
    double c_sr_wwa_met_rel_max;

    double c_sr_wwa_mll_min;
    double c_sr_wwa_mll_max;

    double c_sr_wwa_ptll_min;
    double c_sr_wwa_ptll_max;

    double c_sr_wwb_mt2_min;
    double c_sr_wwb_mt2_max;

    double c_sr_wwb_mll_min;
    double c_sr_wwb_mll_max;

    double c_sr_wwb_ptll_min;
    double c_sr_wwb_ptll_max;

    double c_sr_wwc_mt2_min;
    double c_sr_wwc_mt2_max;

    double c_sr_wwc_ptll_min;
    double c_sr_wwc_ptll_max;

    // SR zjets cut values
    double c_sr_zjets_num_jets_min;
    double c_sr_zjets_num_jets_max;

    double c_sr_zjets_met_rel_min;
    double c_sr_zjets_met_rel_max;

    double c_sr_zjets_jet1_pt_min;
    double c_sr_zjets_jet1_pt_max;

    double c_sr_zjets_jet2_pt_min;
    double c_sr_zjets_jet2_pt_max;

    double c_sr_zjets_mjj_min;
    double c_sr_zjets_mjj_max;

    double c_sr_zjets_mt2_min;
    double c_sr_zjets_mt2_max;

    // CR zxosjveto cut values
    double c_cr_zxjveto_met_rel_min;
    double c_cr_zxjveto_met_rel_max;

    // CR zxmt2 cut values
    // Use cut values from SR mt2
    double c_cr_zxmt2_met_rel_min;
    double c_cr_zxmt2_met_rel_max;

    // CR zx2jets cut values
    double c_cr_zx2jets_met_rel_min;
    double c_cr_zx2jets_met_rel_max;

    double c_cr_zx2jets_mt2_min;
    double c_cr_zx2jets_mt2_max;

    // CR zxww cut values
    double c_cr_zxww_met_rel_min;
    double c_cr_zxww_met_rel_max;

    double c_cr_zxww_mt2_min;
    double c_cr_zxww_mt2_max;

    // CR top cut values
    double c_cr_top_met_rel_min;
    double c_cr_top_met_rel_max;

    // CR topww cut values
    // Use cut values from SR WW
    // double c_cr_topww__min;
    // double c_cr_topww__max;

    // CR ww1-2 cut values
    double c_cr_ww12_met_rel_min;
    double c_cr_ww12_met_rel_max;

    double c_cr_ww12_mt2_min;
    double c_cr_ww12_mt2_max;

    double c_cr_ww2_mll_min;
    double c_cr_ww2_mll_max;

    // CR wwa-c cut values
    // Use cut values from SR WW
    double c_cr_wwabc_dphill_min;
    double c_cr_wwabc_dphill_max;

    // CR btag cut values
    double c_cr_btag_drjettag_min;
    double c_cr_btag_drjettag_max;

    // // VR ss cut values
    // double c_vr_ss__min;
    // double c_vr_ss__max;

    // // VR ssbtag cut values
    // double c_vr_ssbtag__min;
    // double c_vr_ssbtag__max;


    // helper function to check if a cut is passed
    bool passCut(double test, double min, double max);

    // helper function to get leading/subleading lepton pt
    std::pair<float, float> getLeadingLeptonPts( const Event*
                                               , const ElectronContainer&
                                               , const MuonContainer&
                                               );

    CommonTools::TopTagTool* m_top_tag_tool;

    ClassDef(SignalRegionTool, 0);
  };
}

#endif
