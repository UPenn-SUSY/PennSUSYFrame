// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_SignalRegionTool_h
#define SelectionTools_SignalRegionTool_h

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/Met.h"

#include "CommonTools/include/MllTool.h"

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

    void processSignalRegions( Event*
                             , ElectronContainer&
                             , MuonContainer&
                             , JetContainer&
                             , Met*
                             );
    bool passSR1( SusyAnalysisTools::EventDescription*
                , SusyAnalysisTools::SRHelper*
                );
    bool passSR2( SusyAnalysisTools::EventDescription*
                , SusyAnalysisTools::SRHelper*
                );
    bool passSR3( SusyAnalysisTools::EventDescription*
                , SusyAnalysisTools::SRHelper*
                );
    bool passSR4a( SusyAnalysisTools::EventDescription*
                 , SusyAnalysisTools::SRHelper*
                 );
    bool passSR4b( SusyAnalysisTools::EventDescription*
                 , SusyAnalysisTools::SRHelper*
                 );

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passFullJetVeto(const JetContainer*);

    double c_z_window_mll_min;
    double c_z_window_mll_max;

    double c_sr1_met_rel_min;
    double c_sr1_met_rel_max;

    double c_sr2_met_rel_min;
    double c_sr2_met_rel_max;

    double c_sr3_met_rel_min;
    double c_sr3_met_rel_max;

    double c_sr4_met_rel_min;
    double c_sr4_met_rel_max;

    double c_sr4a_mt2_min;
    double c_sr4a_mt2_max;

    double c_sr4b_mt2_min;
    double c_sr4b_mt2_max;

    bool passCut(double test, double min, double max);

    ClassDef(SignalRegionTool, 0);
  };
}

#endif
