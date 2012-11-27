/*
#ifndef Selection_EventSelectionDefs_h
#define Selection_EventSelectionDefs_h

// ============================================================================
#include "EventSelection.h"

// ============================================================================
namespace EventSelectionDefs
{
  Selection::EventSelection no_cuts();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection base_selection();
  Selection::EventSelection OS_base_selection();
  Selection::EventSelection SS_base_selection();

  Selection::EventSelection signal();
  Selection::EventSelection OS_signal();
  Selection::EventSelection SS_signal();

  Selection::EventSelection elel();
  Selection::EventSelection mumu();
  Selection::EventSelection elmu();
  Selection::EventSelection muel();

  Selection::EventSelection OS_elel();
  Selection::EventSelection OS_mumu();
  Selection::EventSelection OS_elmu();
  Selection::EventSelection OS_muel();

  Selection::EventSelection SS_elel();
  Selection::EventSelection SS_mumu();
  Selection::EventSelection SS_elmu();
  Selection::EventSelection SS_muel();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection elel_zWindow();
  Selection::EventSelection mumu_zWindow();
  Selection::EventSelection elmu_zWindow();
  Selection::EventSelection muel_zWindow();

  Selection::EventSelection OS_elel_zWindow();
  Selection::EventSelection OS_mumu_zWindow();
  Selection::EventSelection OS_elmu_zWindow();
  Selection::EventSelection OS_muel_zWindow();

  Selection::EventSelection SS_elel_zWindow();
  Selection::EventSelection SS_mumu_zWindow();
  Selection::EventSelection SS_elmu_zWindow();
  Selection::EventSelection SS_muel_zWindow();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection elel_NsigLep();
  Selection::EventSelection mumu_NsigLep();
  Selection::EventSelection elmu_NsigLep();
  Selection::EventSelection muel_NsigLep();

  Selection::EventSelection OS_elel_NsigLep();
  Selection::EventSelection OS_mumu_NsigLep();
  Selection::EventSelection OS_elmu_NsigLep();
  Selection::EventSelection OS_muel_NsigLep();

  Selection::EventSelection SS_elel_NsigLep();
  Selection::EventSelection SS_mumu_NsigLep();
  Selection::EventSelection SS_elmu_NsigLep();
  Selection::EventSelection SS_muel_NsigLep();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection elel_zWindow_NsigLep();
  Selection::EventSelection mumu_zWindow_NsigLep();
  Selection::EventSelection elmu_zWindow_NsigLep();
  Selection::EventSelection muel_zWindow_NsigLep();

  Selection::EventSelection OS_elel_zWindow_NsigLep();
  Selection::EventSelection OS_mumu_zWindow_NsigLep();
  Selection::EventSelection OS_elmu_zWindow_NsigLep();
  Selection::EventSelection OS_muel_zWindow_NsigLep();

  Selection::EventSelection SS_elel_zWindow_NsigLep();
  Selection::EventSelection SS_mumu_zWindow_NsigLep();
  Selection::EventSelection SS_elmu_zWindow_NsigLep();
  Selection::EventSelection SS_muel_zWindow_NsigLep();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection signal_SR1();
  Selection::EventSelection elel_SR1();
  Selection::EventSelection mumu_SR1();
  Selection::EventSelection elmu_SR1();
  Selection::EventSelection muel_SR1();

  Selection::EventSelection signal_SR2();
  Selection::EventSelection elel_SR2();
  Selection::EventSelection mumu_SR2();
  Selection::EventSelection elmu_SR2();
  Selection::EventSelection muel_SR2();

  Selection::EventSelection signal_SR3();
  Selection::EventSelection elel_SR3();
  Selection::EventSelection mumu_SR3();
  Selection::EventSelection elmu_SR3();
  Selection::EventSelection muel_SR3();

  Selection::EventSelection signal_SR4();
  Selection::EventSelection elel_SR4();
  Selection::EventSelection mumu_SR4();
  Selection::EventSelection elmu_SR4();
  Selection::EventSelection muel_SR4();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection signal_SR1_Nmet();
  Selection::EventSelection elel_SR1_Nmet();
  Selection::EventSelection mumu_SR1_Nmet();
  Selection::EventSelection elmu_SR1_Nmet();
  Selection::EventSelection muel_SR1_Nmet();

  Selection::EventSelection signal_SR2_Nmet();
  Selection::EventSelection elel_SR2_Nmet();
  Selection::EventSelection mumu_SR2_Nmet();
  Selection::EventSelection elmu_SR2_Nmet();
  Selection::EventSelection muel_SR2_Nmet();

  Selection::EventSelection signal_SR3_Nmet();
  Selection::EventSelection elel_SR3_Nmet();
  Selection::EventSelection mumu_SR3_Nmet();
  Selection::EventSelection elmu_SR3_Nmet();
  Selection::EventSelection muel_SR3_Nmet();

  Selection::EventSelection signal_SR4_Nmet();
  Selection::EventSelection elel_SR4_Nmet();
  Selection::EventSelection mumu_SR4_Nmet();
  Selection::EventSelection elmu_SR4_Nmet();
  Selection::EventSelection muel_SR4_Nmet();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection signal_SR1_NsigLep();
  Selection::EventSelection elel_SR1_NsigLep();
  Selection::EventSelection mumu_SR1_NsigLep();
  Selection::EventSelection elmu_SR1_NsigLep();
  Selection::EventSelection muel_SR1_NsigLep();

  Selection::EventSelection signal_SR2_NsigLep();
  Selection::EventSelection elel_SR2_NsigLep();
  Selection::EventSelection mumu_SR2_NsigLep();
  Selection::EventSelection elmu_SR2_NsigLep();
  Selection::EventSelection muel_SR2_NsigLep();

  Selection::EventSelection signal_SR3_NsigLep();
  Selection::EventSelection elel_SR3_NsigLep();
  Selection::EventSelection mumu_SR3_NsigLep();
  Selection::EventSelection elmu_SR3_NsigLep();
  Selection::EventSelection muel_SR3_NsigLep();

  Selection::EventSelection signal_SR4_NsigLep();
  Selection::EventSelection elel_SR4_NsigLep();
  Selection::EventSelection mumu_SR4_NsigLep();
  Selection::EventSelection elmu_SR4_NsigLep();
  Selection::EventSelection muel_SR4_NsigLep();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::EventSelection signal_CR1();
  Selection::EventSelection elel_CR1();
  Selection::EventSelection mumu_CR1();
  Selection::EventSelection elmu_CR1();
  Selection::EventSelection muel_CR1();

  Selection::EventSelection signal_CR2();
  Selection::EventSelection elel_CR2();
  Selection::EventSelection mumu_CR2();
  Selection::EventSelection elmu_CR2();
  Selection::EventSelection muel_CR2();

  Selection::EventSelection signal_CR3();
  Selection::EventSelection elel_CR3();
  Selection::EventSelection mumu_CR3();
  Selection::EventSelection elmu_CR3();
  Selection::EventSelection muel_CR3();

  Selection::EventSelection signal_CR4();
  Selection::EventSelection elel_CR4();
  Selection::EventSelection mumu_CR4();
  Selection::EventSelection elmu_CR4();
  Selection::EventSelection muel_CR4();

  Selection::EventSelection signal_CR5();
  Selection::EventSelection elel_CR5();
  Selection::EventSelection mumu_CR5();
  Selection::EventSelection elmu_CR5();
  Selection::EventSelection muel_CR5();
}

#endif
*/
