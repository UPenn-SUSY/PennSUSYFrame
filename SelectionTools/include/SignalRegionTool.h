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
    bool passSRSS( SusyAnalysisTools::EventDescription*
                 , SusyAnalysisTools::SRHelper*
                 );

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passFullJetVeto(const JetContainer*);

    double c_z_window_mll_min;
    double c_z_window_mll_max;

    // SR SS cut values
    double c_sr_ss_mll_veto_min;
    double c_sr_ss_mll_veto_max;

    double c_sr_ss_ee_met_rel_min;
    double c_sr_ss_ee_met_rel_max;

    double c_sr_ss_mm_met_rel_min;
    double c_sr_ss_mm_met_rel_max;

    double c_sr_ss_em_met_rel_min;
    double c_sr_ss_em_met_rel_max;

    double c_sr_ss_ee_emma_mt_min;
    double c_sr_ss_ee_emma_mt_max;

    double c_sr_ss_mm_emma_mt_min;
    double c_sr_ss_mm_emma_mt_max;

    double c_sr_ss_em_emma_mt_min;
    double c_sr_ss_em_emma_mt_max;

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
