#include "BMinusLAnalysis/include/BMinusLTrigger.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// -----------------------------------------------------------------------------
bool PennSusyFrame::passBMinusLTrigger( const PennSusyFrame::Event& event
                                      , const PennSusyFrame::Trigger& trigger
                                      )
{
  FLAVOR_CHANNEL flavor_channel = event.getFlavorChannel();

  // ee flavor channel
  if (flavor_channel == FLAVOR_EE && trigger.getEF_e24vhi_medium1()) return true;
  if (flavor_channel == FLAVOR_EE && trigger.getEF_e60_medium1())    return true;

  // mumu flavor channel
  if (flavor_channel == FLAVOR_MM && trigger.getEF_mu24i_tight())    return true;
  if (flavor_channel == FLAVOR_MM && trigger.getEF_mu36_tight())     return true;

  // emu flavor channel
  if (flavor_channel == FLAVOR_EM && trigger.getEF_e24vhi_medium1()) return true;
  if (flavor_channel == FLAVOR_EM && trigger.getEF_mu24i_tight())    return true;
  if (flavor_channel == FLAVOR_EM && trigger.getEF_mu36_tight())     return true;

  return false;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passBMinusLTriggerMatch( const PennSusyFrame::Event& event
                                           , const PennSusyFrame::Trigger& trigger
                                           , const std::vector<PennSusyFrame::Electron*>* electrons
                                           , const std::vector<PennSusyFrame::Muon*>* muons
                                           )
{
  FLAVOR_CHANNEL flavor_channel = event.getFlavorChannel();

  if (flavor_channel == FLAVOR_EE) return passEETriggerMatching( trigger
                                                               , electrons
                                                               );
  if (flavor_channel == FLAVOR_MM) return passMMTriggerMatching( trigger
                                                               , muons
                                                               );
  if (flavor_channel == FLAVOR_EM) return passEMTriggerMatching( trigger
                                                               , electrons
                                                               , muons
                                                               );
  return false;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passEETriggerMatching( const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Electron*>* electrons
                                         )
{
  bool pass_trigger_match = false;
  if (trigger.getEF_e24vhi_medium1()) {
    pass_trigger_match = (  pass_trigger_match
                         || PennSusyFrame::matchElectronList( electrons
                                                            , trigger.getTrig_EF_el_EF_e24vhi_medium1()
                                                            , trigger.getTrig_EF_el_px()
                                                            , trigger.getTrig_EF_el_py()
                                                            , trigger.getTrig_EF_el_pz()
                                                            , trigger.getTrig_EF_el_E()
                                                            , 1    // number matches
                                                            , 0.15 // dr for match
                                                            , 0    // min pt
                                                            )
                         );
  }
  if (trigger.getEF_e60_medium1()) {
    pass_trigger_match = (  pass_trigger_match
                         || PennSusyFrame::matchElectronList( electrons
                                                            , trigger.getTrig_EF_el_EF_e60_medium1()
                                                            , trigger.getTrig_EF_el_px()
                                                            , trigger.getTrig_EF_el_py()
                                                            , trigger.getTrig_EF_el_pz()
                                                            , trigger.getTrig_EF_el_E()
                                                            , 1    // number matches
                                                            , 0.15 // dr for match
                                                            , 0    // min pt
                                                            )
                         );
  }

  return pass_trigger_match;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passMMTriggerMatching( const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Muon*>* muons
                                         )
{
  bool pass_trigger_match = false;

  if (trigger.getTrig_EF_trigmuonef_EF_mu24i_tight()) {
    pass_trigger_match = (  pass_trigger_match
                         || matchMuonList( muons
                                         , trigger.getTrig_EF_trigmuonef_EF_mu24i_tight()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_pt()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_eta()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_phi()
                                         , 1
                                         , 0.15
                                         , 0
                                         )
                         );
  }
  if (trigger.getTrig_EF_trigmuonef_EF_mu36_tight()) {
    pass_trigger_match = (  pass_trigger_match
                         || matchMuonList( muons
                                         , trigger.getTrig_EF_trigmuonef_EF_mu36_tight()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_pt()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_eta()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_phi()
                                         , 1
                                         , 0.15
                                         , 0
                                         )
                         );
  }

  return pass_trigger_match;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passEMTriggerMatching( const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Electron*>* electrons
                                         , const std::vector<PennSusyFrame::Muon*>* muons
                                         )
{
  bool pass_trigger_match = false;

  if (trigger.getEF_e24vhi_medium1()) {
    pass_trigger_match = (  pass_trigger_match
                         || PennSusyFrame::matchElectronList( electrons
                                                            , trigger.getTrig_EF_el_EF_e24vhi_medium1()
                                                            , trigger.getTrig_EF_el_px()
                                                            , trigger.getTrig_EF_el_py()
                                                            , trigger.getTrig_EF_el_pz()
                                                            , trigger.getTrig_EF_el_E()
                                                            , 1    // number matches
                                                            , 0.15 // dr for match
                                                            , 0    // min pt
                                                            )
                         );
  }
  if (trigger.getEF_e60_medium1()) {
    pass_trigger_match = (  pass_trigger_match
                         || PennSusyFrame::matchElectronList( electrons
                                                            , trigger.getTrig_EF_el_EF_e60_medium1()
                                                            , trigger.getTrig_EF_el_px()
                                                            , trigger.getTrig_EF_el_py()
                                                            , trigger.getTrig_EF_el_pz()
                                                            , trigger.getTrig_EF_el_E()
                                                            , 1    // number matches
                                                            , 0.15 // dr for match
                                                            , 0    // min pt
                                                            )
                         );
  }
  if (trigger.getTrig_EF_trigmuonef_EF_mu24i_tight()) {
    pass_trigger_match = (  pass_trigger_match
                         || matchMuonList( muons
                                         , trigger.getTrig_EF_trigmuonef_EF_mu24i_tight()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_pt()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_eta()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_phi()
                                         , 1
                                         , 0.15
                                         , 0
                                         )
                         );
  }
  if (trigger.getTrig_EF_trigmuonef_EF_mu36_tight()) {
    pass_trigger_match = (  pass_trigger_match
                         || matchMuonList( muons
                                         , trigger.getTrig_EF_trigmuonef_EF_mu36_tight()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_pt()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_eta()
                                         , trigger.getTrig_EF_trigmuonef_track_CB_phi()
                                         , 1
                                         , 0.15
                                         , 0
                                         )
                         );
  }

  return pass_trigger_match;
}
