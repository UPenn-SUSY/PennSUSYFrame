#include "/Users/bjackson/work/PennSusyFrame.00.03.13/EwkAnalysis/include/EwkTrigger.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// -----------------------------------------------------------------------------
TRIG_PHASE PennSusyFrame::getTriggerPhase( const std::vector<PennSusyFrame::Electron*>* electrons
                                         , const std::vector<PennSusyFrame::Muon*>* muons
                                         )
{
  size_t num_el = electrons->size();
  size_t num_mu = muons->size();

  if (num_el == 2 && num_mu == 0) {
    // ee channel
    double pt_0 = electrons->at(0)->getTlv()->Pt()/1000.;
    double pt_1 = electrons->at(1)->getTlv()->Pt()/1000.;

    if (pt_1 > pt_0) {
      double pt_tmp = pt_0;
      pt_0 = pt_1; 
      pt_1 = pt_tmp;
    }

    if (pt_0 > 14. && pt_1 > 14.)              return TRIG_EE_A;
    if (pt_0 > 25. && pt_1 > 10 && pt_1 < 14.) return TRIG_EE_B;
  }
  else if (num_el == 0 && num_mu == 2) {
    // mm channel
    double pt_0 = muons->at(0)->getTlv()->Pt()/1000.;
    double pt_1 = muons->at(1)->getTlv()->Pt()/1000.;

    if (pt_1 > pt_0) {
      double pt_tmp = pt_0;
      pt_0 = pt_1; 
      pt_1 = pt_tmp;
    }

    if (pt_0 > 18 && pt_1 > 18)                           return TRIG_MM_A;
    if (pt_0 > 18 && pt_1 > 14 && pt_1 < 18)              return TRIG_MM_B;
    if (pt_0 > 18 && pt_1 > 8  && pt_1 < 14)              return TRIG_MM_C;
    if (pt_0 > 14 && pt_0 < 18 && pt_1 > 14 && pt_1 < 18) return TRIG_MM_D;
  }
  else if (num_el == 1 && num_mu == 1) {
    // em channel

    double pt_e = electrons->at(0)->getTlv()->Pt()/1000.;
    double pt_m = muons->at(0)->getTlv()->Pt()/1000.;

    if (pt_e > 14 && pt_m > 8)               return TRIG_EM_A;
    if (pt_e > 10 && pt_e < 14 && pt_m > 18) return TRIG_EM_B;
  }

  return TRIG_NONE;
}

// -----------------------------------------------------------------------------
PHASE_SPACE PennSusyFrame::getPhaseSpaceFromTriggerPhase(TRIG_PHASE trig_phase)
{
    if (  trig_phase == TRIG_EE_A
       || trig_phase == TRIG_EE_B
       )
      return PHASE_EE;

    if (  trig_phase == TRIG_MM_A
       || trig_phase == TRIG_MM_B
       || trig_phase == TRIG_MM_C
       || trig_phase == TRIG_MM_D
       )
      return PHASE_MM;

    if (trig_phase == TRIG_EM_A)
      return PHASE_EM;
    if (trig_phase == TRIG_EM_B)
      return PHASE_ME;

    return PHASE_NONE;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passAnyTrigger( const PennSusyFrame::Event& event
                                  , const PennSusyFrame::Trigger& trigger
                                  )
{
  return (  passEETriggerChannel(event, trigger)
         || passMMTriggerChannel(event, trigger)
         || passEMTriggerChannel(event, trigger)
         || passMETriggerChannel(event, trigger)
         );
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passEETriggerChannel( const PennSusyFrame::Event&
                                        , const PennSusyFrame::Trigger& trigger
                                        )
{
  bool pass_single_trigger = false;
  bool pass_double_trigger = (  trigger.getEF_2e12Tvh_loose1()
                             || trigger.getEF_e24vh_medium1_e7_medium1()
                             );
  return (pass_single_trigger || pass_double_trigger);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passMMTriggerChannel( const PennSusyFrame::Event&
                                        , const PennSusyFrame::Trigger& trigger
                                        )
{
  bool pass_single_trigger = false;
  bool pass_double_trigger = (  trigger.getEF_2mu13()
                             || trigger.getEF_mu18_tight_mu8_EFFS()
                             );
  return (pass_single_trigger || pass_double_trigger);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passEMTriggerChannel( const PennSusyFrame::Event&
                                        , const PennSusyFrame::Trigger& trigger
                                        )
{
  bool pass_trigger = trigger.getEF_e12Tvh_medium1_mu8();
  return pass_trigger;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passMETriggerChannel( const PennSusyFrame::Event&
                                        , const PennSusyFrame::Trigger& trigger
                                        )
{
  bool pass_trigger = trigger.getEF_mu18_tight_e7_medium1();
  return pass_trigger;
}

// -----------------------------------------------------------------------------
// check trigger matching
bool PennSusyFrame::passTriggerMatching( const PennSusyFrame::Event& event
                                       , const PennSusyFrame::Trigger& trigger
                                       , const std::vector<PennSusyFrame::Electron*>* electrons
                                       , const std::vector<PennSusyFrame::Muon*>* muons
                                       )
{
  if (event.getPhaseSpace() == PHASE_EE) return passEETriggerMatching(event, trigger, electrons, muons);
  if (event.getPhaseSpace() == PHASE_MM) return passMMTriggerMatching(event, trigger, electrons, muons);
  if (event.getPhaseSpace() == PHASE_EM) return passMETriggerMatching(event, trigger, electrons, muons);
  if (event.getPhaseSpace() == PHASE_ME) return passEMTriggerMatching(event, trigger, electrons, muons);
  return false;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passEETriggerMatching( const PennSusyFrame::Event& event
                                         , const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Electron*>* electrons
                                         , const std::vector<PennSusyFrame::Muon*>*
                                         )
{
  // immediately fail events failing phase space selection
  TRIG_PHASE phase = event.getTriggerPhase();
  if (  phase != TRIG_EE_A && phase != TRIG_EE_B ) return false;

  // Only do trigger matching on data. always set true for MC
  // if (!c_do_mc_trigger && !is_data()) return true;
  bool pass_trigger_match = false;

  // ee region A
  if (phase == TRIG_EE_A) {
    pass_trigger_match = PennSusyFrame::matchElectronList( electrons
                                                         , trigger.getTrig_EF_el_EF_e12Tvh_loose1()
                                                         // , trig_vec
                                                         , 2    // number matches
                                                         , 0.15 // dr for match
                                                         , 0    // min pt
                                                         );
  }
  // ee region B
  if (phase == TRIG_EE_B) {
    // require the leading lepton matches with e24vh_medium1
    bool pass_single_match = false;
    if (electrons->at(0)->getPt() > electrons->at(1)->getPt()) {
      pass_single_match = matchElectron( electrons->at(0)
                                       , trigger.getTrig_EF_el_EF_e24vh_medium1()
                                       // , trig_vec
                                       , 0.15 // dr for match
                                       , 0    // min pt
                                       );
    }
    else {
      pass_single_match = matchElectron( electrons->at(1)
                                       , trigger.getTrig_EF_el_EF_e24vh_medium1()
                                       // , trig_vec
                                       , 0.15 // dr for match
                                       , 0    // min pt
                                       );
    }

    // require both leptons match with the e24vh_medium1_e7_medium1
    bool pass_double_match = matchElectronList( electrons
                                              , trigger.getTrig_EF_el_EF_e24vh_medium1_e7_medium1()
                                              // , trig_vec
                                              , 2    // number matches
                                              , 0.15 // dr for match
                                              , 0    // min pt
                                              );

    // check the && of the single and double matches above
    pass_trigger_match = (pass_single_match && pass_double_match);
  }

  return pass_trigger_match;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passMMTriggerMatching( const PennSusyFrame::Event&
                                         , const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Electron*>*
                                         , const std::vector<PennSusyFrame::Muon*>*
                                         )
{
  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passEMTriggerMatching( const PennSusyFrame::Event&
                                         , const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Electron*>*
                                         , const std::vector<PennSusyFrame::Muon*>*
                                         )
{
  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passMETriggerMatching( const PennSusyFrame::Event&
                                         , const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Electron*>*
                                         , const std::vector<PennSusyFrame::Muon*>*
                                         )
{
  return true;
}
