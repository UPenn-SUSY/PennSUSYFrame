// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_TriggerCutTool_h
#define SelectionTools_TriggerCutTool_h

// =============================================================================
#include <vector>
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Event;
class Electron;
class Muon;
class Jet;
class Trigger;
class TriggerVec;

// =============================================================================
namespace SelectionTools
{
  // ===========================================================================
  class TriggerCutTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    TriggerCutTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~TriggerCutTool();

    // // weights for simulation

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passedAnySingleOrDiLeptonTrigger( const Event*
                                         , const Trigger*
                                         );

    // Phase space channel
    TRIG_PHASE getPhaseSpace( const std::vector<Electron*>&
                            , const std::vector<Muon*>&
                            );
    bool passedEEPhaseSpace( const std::vector<Electron*>&
                           , const std::vector<Muon*>&
                           );
    bool passedMMPhaseSpace( const std::vector<Electron*>&
                           , const std::vector<Muon*>&
                           );
    bool passedEMPhaseSpace( const std::vector<Electron*>&
                           , const std::vector<Muon*>&
                           );
    bool passedMEPhaseSpace( const std::vector<Electron*>&
                           , const std::vector<Muon*>&
                           );

    // Trigger channel - event level check for trigger
    bool passedEETriggerChannel( const Event*
                               , const Trigger*
                               );
    bool passedMMTriggerChannel( const Event*
                               , const Trigger*
                               );
    bool passedEMTriggerChannel( const Event*
                               , const Trigger*
                               );
    bool passedMETriggerChannel( const Event*
                               , const Trigger*
                               );

    // Trigger matching
    bool passedEETriggerMatching( const Event*
                                , const TriggerVec*
                                , const std::vector<Electron*>&
                                , const std::vector<Muon*>&
                                );
    bool passedMMTriggerMatching( const Event*
                                , const TriggerVec*
                                , const std::vector<Electron*>&
                                , const std::vector<Muon*>&
                                );
    bool passedEMTriggerMatching( const Event*
                                , const TriggerVec*
                                , const std::vector<Electron*>&
                                , const std::vector<Muon*>&
                                );
    bool passedMETriggerMatching( const Event*
                                , const TriggerVec*
                                , const std::vector<Electron*>&
                                , const std::vector<Muon*>&
                                );

  // ---------------------------------------------------------------------------
  private:
    bool c_do_trigger_matching;
    bool c_check_against_official;
    bool c_do_mc_trigger;

    // void testSasa();
    // triggerReweight2Lep *m_triggerReweight;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // 2012 trigger selection criteria
    bool passedEETrigger2012( const Event*
                            , const Trigger*
                            );
    bool passedMMTrigger2012( const Event*
                            , const Trigger*
                            );
    bool passedEMTrigger2012( const Event*
                            , const Trigger*
                            );
    bool passedMETrigger2012( const Event*
                            , const Trigger*
                            );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // 2012 trigger selection criteria
    bool passedEETriggerMatching2012( const Event*
                                    , const TriggerVec*
                                    , const std::vector<Electron*>&
                                    , const std::vector<Muon*>&
                                    );
    bool passedMMTriggerMatching2012( const Event*
                                    , const TriggerVec*
                                    , const std::vector<Electron*>&
                                    , const std::vector<Muon*>&
                                    );
    bool passedEMTriggerMatching2012( const Event*
                                    , const TriggerVec*
                                    , const std::vector<Electron*>&
                                    , const std::vector<Muon*>&
                                    );
    bool passedMETriggerMatching2012( const Event*
                                    , const TriggerVec*
                                    , const std::vector<Electron*>&
                                    , const std::vector<Muon*>&
                                    );


    bool matchElectronList( const std::vector<Electron*>&
                          , const std::vector<int>* trigger_chain
                          , const TriggerVec*
                          , size_t num_to_match
                          , double dr_cut
                          , double pt_cut
                          );

    bool matchElectron( Electron*
                      , const std::vector<int>* trigger_chain
                      , const TriggerVec*
                      , double dr_cut
                      , double pt_cut
                      );

    bool matchMuonList( const std::vector<Muon*>&
                      , const std::vector<int>* trigger_chain
                      , const TriggerVec*
                      , size_t num_to_match
                      , double dr_cut
                      , double pt_cut
                      );

    bool matchMuon( Muon*
                  , const std::vector<int>* trigger_chain
                  , const TriggerVec*
                  , double dr_cut
                  , double pt_cut
                  );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // the following functions are wrappers to call the official trigger
    // match pachage
    bool passedEETriggerMatch_anders( const Event* event
                                    , const TriggerVec* trig_vec
                                    , const std::vector<Electron*>& electrons
                                    , const std::vector<Muon*>& muons
                                    , bool debug=false
                                    );
    bool passedMMTriggerMatch_anders( const Event* event
                                    , const TriggerVec* trig_vec
                                    , const std::vector<Electron*>& electrons
                                    , const std::vector<Muon*>& muons
                                    , bool debug=false
                                    );
    bool passedEMTriggerMatch_anders( const Event* event
                                    , const TriggerVec* trig_vec
                                    , const std::vector<Electron*>& electrons
                                    , const std::vector<Muon*>& muons
                                    , bool debug=false
                                    );
    bool passedMETriggerMatch_anders( const Event* event
                                    , const TriggerVec* trig_vec
                                    , const std::vector<Electron*>& electrons
                                    , const std::vector<Muon*>& muons
                                    , bool debug=false
                                    );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(TriggerCutTool, 0);
  };
}

#endif
