// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_TriggerCutTool_h
#define SelectionTools_TriggerCutTool_h

#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Trigger.h"
#include "AtlasSFrameUtils/include/TriggerVec.h"

// #include "TriggerMatch/TriggerMatch2Lep.h"
// #include "DGTriggerReweight/triggerReweight2Lep.h"

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class TriggerCutTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    TriggerCutTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~TriggerCutTool();

    // // weights for simulation

	  // double EEweight(std::vector<Electron>&);
	  // double MuMuweight(std::vector<Muon>&);
	  // double EMuweight(std::vector<Electron>&, std::vector<Muon>&);

    // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // bool passedAnySingleOrDiLeptonTrigger( const Event&
    //                                      , const Trigger&
    //                                      );

    // Trigger channel - event level check for trigger
    bool passedEETriggerChannel( const Event*
                               , const Trigger*
                               );
    bool passedMuMuTriggerChannel( const Event*
                                 , const Trigger*
                                 );
    bool passedEMuTriggerChannel( const Event*
                                , const Trigger*
                                );
    bool passedMuETriggerChannel( const Event*
                                , const Trigger*
                                );

    // // Trigger matching
    // bool passedEETriggerMatching( Event&
    //                             , TriggerVecD3PDObject&
    //                             , std::vector<Electron>&
    //                             );
    // bool passedMuMuTriggerMatching( Event&
    //                               , TriggerVecD3PDObject&
    //                               , std::vector<Muon>&
    //                               );
    // bool passedEMuTriggerMatching( Event&
    //                              , TriggerVecD3PDObject&
    //                              , std::vector<Electron>&
    //                              , std::vector<Muon>&
    //                              );
    // bool passedMuETriggerMatching( Event&
    //                              , TriggerVecD3PDObject&
    //                              , std::vector<Electron>&
    //                              , std::vector<Muon>&
    //                              );

    // // the following functions are wrappers to call the official trigger
    // // match pachage
    // bool passedEETriggerMatch_anders(
    //     Event& event,
    //     TriggerVecD3PDObject& trig_vec,
    //     std::vector<Electron>& el,
    //     bool debug=false);
    // bool passedMuMuTriggerMatch_anders(
    //     Event& event,
    //     TriggerVecD3PDObject& trig_vec,
    //     std::vector<Muon>& mu,
    //     bool debug=false);
    // bool passedEMuTriggerMatch_anders(
    //     Event& event,
    //     TriggerVecD3PDObject& trig_vec,
    //     std::vector<Electron>& el,
    //     std::vector<Muon>& mu,
    //     bool debug=false);
    // bool passedMuETriggerMatch_anders(
    //     Event& event,
    //     TriggerVecD3PDObject& trig_vec,
    //     std::vector<Electron>& el,
    //     std::vector<Muon>& mu,
    //     bool debug=false);

  // --------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool c_do_trigger_matching;
    // bool c_check_against_official;

	  // void testSasa();
	  // triggerReweight2Lep *m_triggerReweight;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // 2012 trigger selection criteria
    bool passedEETrigger2012( const Event*
                            , const Trigger*
                            );
    bool passedMuMuTrigger2012( const Event*
                              , const Trigger*
                              );
    bool passedEMuTrigger2012( const Event*
                             , const Trigger*
                             );
    bool passedMuETrigger2012( const Event*
                             , const Trigger*
                             );

    // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // // 2012 trigger selection criteria
    // bool passedEETriggerMatching2012(
    //     Event&,
    //     TriggerVecD3PDObject&,
    //     std::vector<Electron>&);
    // bool passedMuMuTriggerMatching2012(
    //     Event&,
    //     TriggerVecD3PDObject&,
    //     std::vector<Muon>&);
    // bool passedEMuTriggerMatching2012(
    //     Event&,
    //     TriggerVecD3PDObject&,
    //     std::vector<Electron>&,
    //     std::vector<Muon>&);
    // bool passedMuETriggerMatching2012(
    //     Event&,
    //     TriggerVecD3PDObject&,
    //     std::vector<Electron>&,
    //     std::vector<Muon>&);


    // bool passedElectronTriggerMatch(
    //     std::vector<Electron>&,
    //     std::vector<int>& trigger_chain,
    //     TriggerVecD3PDObject&,
    //     size_t num_to_match,
    //     double dr_cut,
    //     double pt_cut);

    // bool passedElectronTriggerMatch(
    //     Electron&,
    //     std::vector<int>& trigger_chain,
    //     TriggerVecD3PDObject&,
    //     double dr_cut,
    //     double pt_cut);

    // bool passedMuonTriggerMatch(
    //     std::vector<Muon>&,
    //     std::vector<int>& trigger_chain,
    //     TriggerVecD3PDObject&,
    //     size_t num_to_match,
    //     double dr_cut,
    //     double pt_cut);

    // bool passedMuonTriggerMatch(
    //     Muon&,
    //     std::vector<int>& trigger_chain,
    //     TriggerVecD3PDObject&,
    //     double dr_cut,
    //     double pt_cut);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(TriggerCutTool, 0);
  };
}

#endif
