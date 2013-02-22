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

    // helper function to check if a cut is passed
    bool passCut(double test, double min, double max);

    CommonTools::TopTagTool* m_top_tag_tool;

    ClassDef(SignalRegionTool, 0);
  };
}

#endif
