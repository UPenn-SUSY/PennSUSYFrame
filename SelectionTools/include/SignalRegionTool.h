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

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passFullJetVeto(const JetContainer*);

    double c_z_window_mll_min;
    double c_z_window_mll_max;

    double c_sr_osjveto_met_rel_min;
    double c_sr_osjveto_met_rel_max;

    double c_sr_ssjets_met_rel_min;
    double c_sr_ssjets_met_rel_max;

    double c_sr_2jets_met_rel_min;
    double c_sr_2jets_met_rel_max;

    double c_sr_mt2_met_rel_min;
    double c_sr_mt2_met_rel_max;

    double c_sr_mt2a_mt2_min;
    double c_sr_mt2a_mt2_max;

    double c_sr_mt2b_mt2_min;
    double c_sr_mt2b_mt2_max;

    bool passCut(double test, double min, double max);

    CommonTools::TopTagTool* m_top_tag_tool;

    ClassDef(SignalRegionTool, 0);
  };
}

#endif
