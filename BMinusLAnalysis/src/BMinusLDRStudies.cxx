#include "BMinusLAnalysis/include/BMinusLDRStudies.h"
#include "BMinusLAnalysis/include/BMinusLAnalysis.h"
#include "BMinusLAnalysis/include/BMinusLUtils.h"
#include "BMinusLAnalysis/include/BMinusLHistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <dirent.h>
#include <math.h>
#include <algorithm>

#include "PennSusyFrameCore/include/ObjectContainers.h"
#include "PennSusyFrameCore/include/Calculators.h"
#include "PennSusyFrameCore/include/D3PDReader.h"
#include "PennSusyFrameCore/include/SelectorHelpers.h"
#include "PennSusyFrameCore/include/ObjectSelectors.h"

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLDRStudies::BMinusLDRStudies(TTree* tree) : PennSusyFrame::BMinusLAnalysis(tree)
{
  m_out_hist_file_name = "BMinusLDRStudies.hists.root";
}

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLDRStudies::~BMinusLDRStudies()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLDRStudies::beginRun()
{
  m_bminusl_dr_histogram_handler.reserve(BMINUSL_DR_HIST_N);
  for (unsigned int dr_hist_level=0; dr_hist_level != BMINUSL_DR_HIST_N; ++ dr_hist_level) {
    m_bminusl_dr_histogram_handler.push_back(new PennSusyFrame::DRHists(BMINUSL_DR_HIST_LEVEL_STRINGS[dr_hist_level]));
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLDRStudies::finalizeEvent()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // replicate overlap removal to fill dR histograms
  reproduceFullObjectCleaning( m_event
                             , m_mc_truth
                             , m_object_cleaning
                             , m_electrons.getCollection(EL_BASELINE)
                             , m_muons.getCollection(MU_BASELINE)
                             , m_jets.getCollection(JET_BASELINE_GOOD)
                             , m_jets.getCollection(JET_BASELINE_BAD)
                             );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLDRStudies::finalizeRun()
{
  TFile out_hist_file(m_out_hist_file_name.c_str(), "RECREATE");

  for (unsigned int dr_hist_level=0; dr_hist_level != PennSusyFrame::BMINUSL_DR_HIST_N; ++dr_hist_level) {
    TDirectory* dr_hist_dir = out_hist_file.mkdir(PennSusyFrame::BMINUSL_DR_HIST_LEVEL_STRINGS[dr_hist_level].c_str());

    m_bminusl_dr_histogram_handler.at(dr_hist_level)->write(dr_hist_dir);
  }
  out_hist_file.Close();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLDRStudies::reproduceFullObjectCleaning( const PennSusyFrame::Event& m_event
                                                                 , const PennSusyFrame::MCTruth& m_mc_truth
                                                                 , PennSusyFrame::ObjectCleaning m_object_cleaning
                                                                 , const std::vector<PennSusyFrame::Electron*>* input_electrons
                                                                 , const std::vector<PennSusyFrame::Muon*>* input_muons
                                                                 , const std::vector<PennSusyFrame::Jet*>* input_jets_good
                                                                 , const std::vector<PennSusyFrame::Jet*>* input_jets_bad
                                                                 )
{
  // fill hist with no OR
  filldRHistHandles( PennSusyFrame::BMINUSL_NO_OR
                   , m_event
                   , m_mc_truth
                   , *input_electrons
                   , *input_muons
                   , *input_jets_good
                   );

  // do ee overlap removal
  std::vector<PennSusyFrame::Electron*> el_temp_1;
  m_object_cleaning.eeOverlapRemoval(*input_electrons, el_temp_1);
  filldRHistHandles( PennSusyFrame::BMINUSL_EE_OR
                   , m_event
                   , m_mc_truth
                   , el_temp_1
                   , *input_muons
                   , *input_jets_good
                   );

  // do ej overlap removal
  std::vector<PennSusyFrame::Jet*> jet_good_temp_1;
  std::vector<PennSusyFrame::Jet*> jet_bad_temp_1;
  m_object_cleaning.ejOverlapRemoval(el_temp_1, *input_jets_good, jet_good_temp_1);
  m_object_cleaning.ejOverlapRemoval(el_temp_1, *input_jets_bad, jet_bad_temp_1);
  filldRHistHandles( PennSusyFrame::BMINUSL_EJ_OR
                   , m_event
                   , m_mc_truth
                   , el_temp_1
                   , *input_muons
                   , jet_good_temp_1
                   );

  // do mj overlap removal
  std::vector<PennSusyFrame::Jet*> jet_good_temp_2;
  std::vector<PennSusyFrame::Jet*> jet_bad_temp_2;
  m_object_cleaning.mjOverlapRemoval(*input_muons, jet_good_temp_1, jet_good_temp_2);
  m_object_cleaning.mjOverlapRemoval(*input_muons, jet_bad_temp_1, jet_bad_temp_2);
  filldRHistHandles( PennSusyFrame::BMINUSL_MJ_OR
                   , m_event
                   , m_mc_truth
                   , el_temp_1
                   , *input_muons
                   , jet_good_temp_2
                   );

  // do je overlap removal
  std::vector<PennSusyFrame::Electron*> el_temp_2;
  std::vector<PennSusyFrame::Electron*> el_temp_3;
  m_object_cleaning.jeOverlapRemoval(jet_good_temp_2, el_temp_1, el_temp_2);
  m_object_cleaning.jeOverlapRemoval(jet_bad_temp_2 , el_temp_2, el_temp_3);
  filldRHistHandles( PennSusyFrame::BMINUSL_JE_OR
                   , m_event
                   , m_mc_truth
                   , el_temp_2
                   , *input_muons
                   , jet_good_temp_2
                   );

  // do jm overlap removal
  std::vector<PennSusyFrame::Muon*> mu_temp_1;
  std::vector<PennSusyFrame::Muon*> mu_temp_2;
  m_object_cleaning.jmOverlapRemoval(jet_good_temp_2, *input_muons, mu_temp_1);
  m_object_cleaning.jmOverlapRemoval(jet_bad_temp_2 , mu_temp_1   , mu_temp_2);
  filldRHistHandles( PennSusyFrame::BMINUSL_JM_OR
                   , m_event
                   , m_mc_truth
                   , el_temp_2
                   , mu_temp_1
                   , jet_good_temp_2
                   );

  // do em overlap removal
  std::vector<PennSusyFrame::Electron*> el_temp_4;
  std::vector<PennSusyFrame::Muon*> mu_temp_3;
  m_object_cleaning.emOverlapRemoval(el_temp_3, mu_temp_2, el_temp_4, mu_temp_3);
  filldRHistHandles( PennSusyFrame::BMINUSL_EM_OR
                   , m_event
                   , m_mc_truth
                   , el_temp_4
                   , mu_temp_3
                   , jet_good_temp_2
                   );

  // do mm overlap removal
  std::vector<PennSusyFrame::Muon*> mu_temp_4;
  m_object_cleaning.mmOverlapRemoval(mu_temp_3, mu_temp_4);
  filldRHistHandles( PennSusyFrame::BMINUSL_MM_OR
                   , m_event
                   , m_mc_truth
                   , el_temp_4
                   , mu_temp_4
                   , jet_good_temp_2
                   );
}

void PennSusyFrame::BMinusLDRStudies::filldRHistHandles( BMINUSL_DR_HIST_LEVELS hist_level
                                                , const PennSusyFrame::Event& m_event
                                                , const PennSusyFrame::MCTruth& m_mc_truth
                                                , const std::vector<PennSusyFrame::Electron*>& electrons
                                                , const std::vector<PennSusyFrame::Muon*>& muons
                                                , const std::vector<PennSusyFrame::Jet*>& jets
                                                )
{
  m_bminusl_dr_histogram_handler.at(hist_level)->FilldR( m_event
                                                       , electrons
                                                       , muons
                                                       , jets
                                                       , m_mc_truth
                                                       );
}
