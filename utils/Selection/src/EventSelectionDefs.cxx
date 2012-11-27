/*
#include "include/EventSelectionDefs.h"

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::no_cuts()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel;

  sel.setTrigger( SusyAnalysisTools::NO_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::NO_FLAVOR
                      , SusyAnalysisTools::NO_FLAVOR
                      );
  sel.setSignChannel( SusyAnalysisTools::NO_SIGN
                    , SusyAnalysisTools::NO_SIGN
                    );

  sel.setBadMuon      (false, false);
  sel.setCosmic       (false, false);
  sel.setSignalLeptons(false, false);
  sel.setMllCut       (false, false);
  sel.setMetCut       (false, false);
  sel.setSR1          (false, false);
  sel.setSR2          (false, false);
  sel.setSR3          (false, false);
  sel.setSR4          (false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::base_selection()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel;

  sel.setTrigger( SusyAnalysisTools::NO_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::NO_FLAVOR
                      , SusyAnalysisTools::NO_FLAVOR
                      );
  sel.setSignChannel( SusyAnalysisTools::NO_SIGN
                    , SusyAnalysisTools::NO_SIGN
                    );

  sel.setBadMuon      (true , false);
  sel.setCosmic       (true , false);
  sel.setSignalLeptons(true , false);
  // sel.setMllCut       (true , false);
  sel.setMllCut       (false, false);
  sel.setMetCut       (false, false);
  sel.setSR1          (false, false);
  sel.setSR2          (false, false);
  sel.setSR3          (false, false);
  sel.setSR4          (false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_base_selection()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = base_selection();

  sel.setSignChannel( SusyAnalysisTools::OS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_base_selection()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = base_selection();

  sel.setSignChannel( SusyAnalysisTools::SS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = base_selection();

  sel.setTrigger( SusyAnalysisTools::EE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::EMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_signal()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal();

  sel.setSignChannel( SusyAnalysisTools::OS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_signal()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal();

  sel.setSignChannel( SusyAnalysisTools::SS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = base_selection();

  sel.setTrigger( SusyAnalysisTools::EE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::EE_CHANNEL
                      , SusyAnalysisTools::NO_FLAVOR
                      );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = base_selection();

  sel.setTrigger( SusyAnalysisTools::MUMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::MUMU_CHANNEL
                      , SusyAnalysisTools::NO_FLAVOR
                      );

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = base_selection();

  sel.setTrigger( SusyAnalysisTools::EMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::EMU_CHANNEL
                      , SusyAnalysisTools::NO_FLAVOR
                      );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = base_selection();

  sel.setTrigger( SusyAnalysisTools::MUE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::EMU_CHANNEL
                      , SusyAnalysisTools::NO_FLAVOR
                      );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_elel()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setSignChannel( SusyAnalysisTools::OS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_mumu()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setSignChannel( SusyAnalysisTools::OS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_elmu()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setSignChannel( SusyAnalysisTools::OS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_muel()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setSignChannel( SusyAnalysisTools::OS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_elel()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setSignChannel( SusyAnalysisTools::SS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_mumu()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setSignChannel( SusyAnalysisTools::SS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_elmu()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setSignChannel( SusyAnalysisTools::SS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_muel()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setSignChannel( SusyAnalysisTools::SS_CHANNEL
                    , SusyAnalysisTools::NO_SIGN
                    );

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setZVeto(false, true);

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_elel_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elel();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_mumu_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_mumu();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_elmu_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elmu();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_muel_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_muel();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_elel_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_elel();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_mumu_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_mumu();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_elmu_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_elmu();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_muel_zWindow()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_muel();

  sel.setZVeto(false, true);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setSignalLeptons(false, false);

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_elel_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elel();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_mumu_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_mumu();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_elmu_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elmu();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_muel_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_muel();

  sel.setSignalLeptons(false, false);

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_elel_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_elel();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_mumu_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_mumu();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_elmu_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_elmu();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_muel_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_muel();

  sel.setSignalLeptons(false, false);

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_elel_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elel_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_mumu_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_mumu_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_elmu_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elmu_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::OS_muel_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_muel_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_elel_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_elel_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_mumu_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_mumu_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_elmu_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_elmu_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::SS_muel_zWindow_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_muel_zWindow();

  sel.setSignalLeptons(false, false);

  return sel;
}


// = Signal Regions =
// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR1()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_signal();

  sel.setSR1(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR1()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elel();

  sel.setSR1(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR1()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_mumu();

  sel.setSR1(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR1()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elmu();

  sel.setSR1(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR1()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_muel();

  sel.setSR1(true , false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR1_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_signal();

  sel.setZVeto(true, false);
  sel.setJetVeto(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR1_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elel();

  sel.setZVeto(true, false);
  sel.setJetVeto(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR1_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_mumu();

  sel.setZVeto(true, false);
  sel.setJetVeto(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR1_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elmu();

  sel.setZVeto(true, false);
  sel.setJetVeto(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR1_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_muel();

  sel.setZVeto(true, false);
  sel.setJetVeto(true, false);

  return sel;
}


// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR1_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal_SR1();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR1_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel_SR1();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR1_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu_SR1();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR1_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu_SR1();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR1_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel_SR1();

  sel.setSignalLeptons(false, false);

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR2()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal();

  sel.setTrigger( SusyAnalysisTools::EE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::EMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::NO_FLAVOR
                      , SusyAnalysisTools::NO_FLAVOR
                      );
  sel.setSignChannel( SusyAnalysisTools::NO_SIGN
                    , SusyAnalysisTools::NO_SIGN
                    );

  sel.setSR2(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR2()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setSR2(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR2()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setSR2(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR2()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setSR2(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR2()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setSR2(true , false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR2_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_signal();

  sel.setJetVeto(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR2_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_elel();

  sel.setJetVeto(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR2_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_mumu();

  sel.setJetVeto(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR2_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_elmu();

  sel.setJetVeto(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR2_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = SS_muel();

  sel.setJetVeto(true, false);

  return sel;
}


// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR2_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal_SR2();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR2_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel_SR2();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR2_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu_SR2();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR2_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu_SR2();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR2_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel_SR2();

  sel.setSignalLeptons(false, false);

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR3()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal();

  sel.setTrigger( SusyAnalysisTools::EMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::NO_FLAVOR
                      , SusyAnalysisTools::NO_FLAVOR
                      );
  sel.setSignChannel( SusyAnalysisTools::NO_SIGN
                    , SusyAnalysisTools::NO_SIGN
                    );

  sel.setSR3(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR3()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setSR3(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR3()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setSR3(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR3()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setSR3(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR3()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setSR3(true , false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR3_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_signal();

  // TODO add n jet >= 2 cut
  sel.setZVeto(true, false);
  sel.setBJetVeto(true, false);
  sel.setMCT(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR3_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elel();

  // TODO add n jet >= 2 cut
  sel.setZVeto(true, false);
  sel.setBJetVeto(true, false);
  sel.setMCT(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR3_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_mumu();

  // TODO add n jet >= 2 cut
  sel.setZVeto(true, false);
  sel.setBJetVeto(true, false);
  sel.setMCT(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR3_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elmu();

  // TODO add n jet >= 2 cut
  sel.setZVeto(true, false);
  sel.setBJetVeto(true, false);
  sel.setMCT(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR3_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_muel();

  // TODO add n jet >= 2 cut
  // sel.setZVeto(true, false);
  // sel.setJetVeto(true, false);

  return sel;
}


// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR3_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal_SR3();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR3_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel_SR3();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR3_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu_SR3();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR3_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu_SR3();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR3_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel_SR3();

  sel.setSignalLeptons(false, false);

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR4()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal();

  sel.setTrigger( SusyAnalysisTools::EMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::NO_FLAVOR
                      , SusyAnalysisTools::NO_FLAVOR
                      );
  sel.setSignChannel( SusyAnalysisTools::NO_SIGN
                    , SusyAnalysisTools::NO_SIGN
                    );

  sel.setSR4(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR4()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setSR4(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR4()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setSR4(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR4()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setSR4(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR4()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setSR4(true , false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR4_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_signal();

  sel.setZVeto(true, false);
  sel.setJetVeto(true, false);
  sel.setMT2(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR4_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elel();

  sel.setZVeto(true, false);
  sel.setJetVeto(true, false);
  sel.setMT2(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR4_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_mumu();

  sel.setZVeto(true, false);
  sel.setJetVeto(true, false);
  sel.setMT2(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR4_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_elmu();

  sel.setZVeto(true, false);
  sel.setJetVeto(true, false);
  sel.setMT2(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR4_Nmet()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = OS_muel();

  sel.setZVeto(true, false);
  sel.setJetVeto(true, false);
  sel.setMT2(true, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_SR4_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal_SR4();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_SR4_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel_SR4();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_SR4_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu_SR4();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_SR4_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu_SR4();

  sel.setSignalLeptons(false, false);

  return sel;
}

// -----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_SR4_NsigLep()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel_SR4();

  sel.setSignalLeptons(false, false);

  return sel;
}


// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_CR1()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal();

  sel.setTrigger( SusyAnalysisTools::EE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::EMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::NO_FLAVOR
                      , SusyAnalysisTools::NO_FLAVOR
                      );
  sel.setSignChannel( SusyAnalysisTools::NO_SIGN
                    , SusyAnalysisTools::NO_SIGN
                    );

  sel.setCR1(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_CR1()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setCR1(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_CR1()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setCR1(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_CR1()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setCR1(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_CR1()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setCR1(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_CR2()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal();

  sel.setTrigger( SusyAnalysisTools::EE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::EMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::NO_FLAVOR
                      , SusyAnalysisTools::NO_FLAVOR
                      );
  sel.setSignChannel( SusyAnalysisTools::NO_SIGN
                    , SusyAnalysisTools::NO_SIGN
                    );

  sel.setCR2(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_CR2()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setCR2(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_CR2()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setCR2(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_CR2()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setCR2(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_CR2()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setCR2(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_CR3()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal();

  sel.setTrigger( SusyAnalysisTools::EMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::NO_FLAVOR
                      , SusyAnalysisTools::NO_FLAVOR
                      );
  sel.setSignChannel( SusyAnalysisTools::NO_SIGN
                    , SusyAnalysisTools::NO_SIGN
                    );

  sel.setCR3(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_CR3()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setCR3(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_CR3()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setCR3(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_CR3()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setCR3(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_CR3()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setCR3(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_CR4()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal();

  sel.setTrigger( SusyAnalysisTools::EMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::NO_FLAVOR
                      , SusyAnalysisTools::NO_FLAVOR
                      );
  sel.setSignChannel( SusyAnalysisTools::NO_SIGN
                    , SusyAnalysisTools::NO_SIGN
                    );

  sel.setCR4(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_CR4()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setCR4(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_CR4()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setCR4(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_CR4()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setCR4(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_CR4()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setCR4(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::signal_CR5()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = signal();

  sel.setTrigger( SusyAnalysisTools::EMU_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setTrigger( SusyAnalysisTools::MUE_TRIGGER
                , SusyAnalysisTools::NO_TRIGGER
                );
  sel.setFlavorChannel( SusyAnalysisTools::NO_FLAVOR
                      , SusyAnalysisTools::NO_FLAVOR
                      );
  sel.setSignChannel( SusyAnalysisTools::NO_SIGN
                    , SusyAnalysisTools::NO_SIGN
                    );

  sel.setCR5(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elel_CR5()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elel();

  sel.setCR5(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::mumu_CR5()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = mumu();

  sel.setCR5(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::elmu_CR5()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = elmu();

  sel.setCR5(true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::EventSelection EventSelectionDefs::muel_CR5()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection sel = muel();

  sel.setCR5(true , false);

  return sel;
}
*/
