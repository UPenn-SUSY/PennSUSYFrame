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
                                  // , const PennSusyFrame::Trigger& trigger
                                  )
{
  return (  passEETriggerChannel(event/*, trigger*/)
         || passMMTriggerChannel(event/*, trigger*/)
         || passEMTriggerChannel(event/*, trigger*/)
         || passMETriggerChannel(event/*, trigger*/)
         );
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passEETriggerChannel( const PennSusyFrame::Event&
                                        // , const PennSusyFrame::Trigger& trigger
                                        )
{
  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passMMTriggerChannel( const PennSusyFrame::Event&
                                        // , const PennSusyFrame::Trigger& trigger
                                        )
{
  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passEMTriggerChannel( const PennSusyFrame::Event&
                                        // , const PennSusyFrame::Trigger& trigger
                                        )
{
  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passMETriggerChannel( const PennSusyFrame::Event&
                                        // , const PennSusyFrame::Trigger& trigger
                                        )
{
  return true;
}

// -----------------------------------------------------------------------------
// check trigger matching
bool PennSusyFrame::passTriggerMatching( const PennSusyFrame::Event& event
                                       // , const PennSusyFrame::Trigger& trigger
                                       , const std::vector<PennSusyFrame::Electron*>* electrons
                                       , const std::vector<PennSusyFrame::Muon*>* muons
                                       )
{
  if (event.getPhaseSpace() == PHASE_EE) return passEETriggerMatching(event, /*trigger,*/ electrons, muons);
  if (event.getPhaseSpace() == PHASE_MM) return passMMTriggerMatching(event, /*trigger,*/ electrons, muons);
  if (event.getPhaseSpace() == PHASE_EM) return passMETriggerMatching(event, /*trigger,*/ electrons, muons);
  if (event.getPhaseSpace() == PHASE_ME) return passEMTriggerMatching(event, /*trigger,*/ electrons, muons);
  return false;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passEETriggerMatching( const PennSusyFrame::Event&
                                         // , const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Electron*>*
                                         , const std::vector<PennSusyFrame::Muon*>*
                                         )
{
  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passMMTriggerMatching( const PennSusyFrame::Event&
                                         // , const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Electron*>*
                                         , const std::vector<PennSusyFrame::Muon*>*
                                         )
{
  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passEMTriggerMatching( const PennSusyFrame::Event&
                                         // , const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Electron*>*
                                         , const std::vector<PennSusyFrame::Muon*>*
                                         )
{
  return true;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::passMETriggerMatching( const PennSusyFrame::Event&
                                         // , const PennSusyFrame::Trigger& trigger
                                         , const std::vector<PennSusyFrame::Electron*>*
                                         , const std::vector<PennSusyFrame::Muon*>*
                                         )
{
  return true;
}
