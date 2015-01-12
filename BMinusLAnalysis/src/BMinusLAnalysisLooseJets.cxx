#include "BMinusLAnalysis/include/BMinusLAnalysisLooseJets.h"
#include "BMinusLAnalysis/include/BMinusLUtils.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

#include "TFile.h"
#include "TTree.h"

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

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLAnalysisLooseJets::BMinusLAnalysisLooseJets(TTree* tree) :
  PennSusyFrame::BMinusLAnalysis(tree),
  m_lljj_jl_0(0),
  m_lljj_jl_1(0),
  m_llbj_jl_0(0),
  m_llbj_jl_1(0)

{
}

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLAnalysisLooseJets::~BMinusLAnalysisLooseJets()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysisLooseJets::beginRun()
{
  PennSusyFrameCore::beginRun();

  // prepare selection
  prepareSelection();

  m_histogram_handlers.resize(BMINUSL_LOOSE_HIST_N);
  m_bminusl_histogram_handler.reserve(BMINUSL_LOOSE_HIST_N);

  for ( unsigned int hist_level = 0
      ; hist_level != BMINUSL_LOOSE_HIST_N
      ; ++hist_level) {
    std::cout << "creating histograms with hist level: "
              << hist_level
              << " -- "
              << PennSusyFrame::BMINUSL_LOOSE_HIST_LEVEL_STRINGS[hist_level]
              << "\n";
    m_histogram_handlers.at(hist_level).push_back(
        new PennSusyFrame::HistogramHandler(
          PennSusyFrame::BMINUSL_LOOSE_HIST_LEVEL_STRINGS[hist_level]));
    m_histogram_handlers.at(hist_level).push_back(
        new PennSusyFrame::EventLevelHists(
          PennSusyFrame::BMINUSL_LOOSE_HIST_LEVEL_STRINGS[hist_level]));
    m_histogram_handlers.at(hist_level).push_back(
        new PennSusyFrame::LeptonKinematicsHists(
          PennSusyFrame::BMINUSL_LOOSE_HIST_LEVEL_STRINGS[hist_level]));
    m_histogram_handlers.at(hist_level).push_back(
        new PennSusyFrame::JetKinematicsHists(
          PennSusyFrame::BMINUSL_LOOSE_HIST_LEVEL_STRINGS[hist_level]));
    m_histogram_handlers.at(hist_level).push_back(
        new PennSusyFrame::MetHists(
          PennSusyFrame::BMINUSL_LOOSE_HIST_LEVEL_STRINGS[hist_level]));

    m_bminusl_histogram_handler.push_back(
        new PennSusyFrame::BMinusLHists(
          PennSusyFrame::BMINUSL_LOOSE_HIST_LEVEL_STRINGS[hist_level]));
    m_weight_histogram_handler.push_back(
        new PennSusyFrame::WeightHists(
          PennSusyFrame::BMINUSL_LOOSE_HIST_LEVEL_STRINGS[hist_level]));
    m_parent_histogram_handler.push_back(
        new PennSusyFrame::ParentHists(
          PennSusyFrame::BMINUSL_LOOSE_HIST_LEVEL_STRINGS[hist_level]));
  }
}


// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysisLooseJets::initializeEvent()
{
  BMinusLAnalysis::initializeEvent();

  m_pass_lljj_pairing = false;
  m_pass_llbj_pairing = false;

  m_lljj_ht_signal = 0.;
  m_llbj_ht_signal = 0.;

  m_llbj_jet_collection.clear();

  if (m_lljj_jl_0 != 0) {
    delete m_lljj_jl_0;
    m_lljj_jl_0 = 0;
  }
  if (m_lljj_jl_1 != 0) {
    delete m_lljj_jl_1;
    m_lljj_jl_1 = 0;
  }

  if (m_llbj_jl_0 != 0) {
    delete m_llbj_jl_0;
    m_llbj_jl_0 = 0;
  }
  if (m_llbj_jl_1 != 0) {
    delete m_llbj_jl_1;
    m_llbj_jl_1 = 0;
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysisLooseJets::processEvent()
{
  BMinusLAnalysis::processEvent();

  m_lljj_jl_0 = new PennSusyFrame::blPair();
  m_lljj_jl_1 = new PennSusyFrame::blPair();

  size_t num_lep = m_electrons.num(EL_SELECTED) + m_muons.num(MU_SELECTED);
  size_t num_jets = m_jets.num(JET_GOOD);
  size_t num_b_jets = m_jets.num(JET_B);

  if (num_lep >= 2 && num_jets >= 2) {
    m_pass_lljj_pairing = PennSusyFrame::doBLPairing( m_event
                                                    , m_electrons.getCollection(EL_SELECTED)
                                                    , m_muons.getCollection(MU_SELECTED)
                                                    , m_jets.getCollection(JET_GOOD)
                                                    , *m_lljj_jl_0
                                                    , *m_lljj_jl_1
                                                    );
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (num_lep >= 2 && num_jets >= 2 && num_b_jets >= 1) {
    m_llbj_jl_0 = new PennSusyFrame::blPair();
    m_llbj_jl_1 = new PennSusyFrame::blPair();

    // for the llbb selection, first add the first b-jet
    m_llbj_jet_collection.push_back(m_jets.getCollection(JET_B)->at(0));
    for (size_t jet_it = 0; jet_it < num_jets && m_llbj_jet_collection.size() < 2 ; ++jet_it) {
      if (m_jets.getCollection(JET_GOOD)->at(jet_it) != m_llbj_jet_collection.at(0)) {
        m_llbj_jet_collection.push_back(m_jets.getCollection(JET_GOOD)->at(jet_it));
      }
    }

    m_pass_llbj_pairing = PennSusyFrame::doBLPairing( m_event
                                                    , m_electrons.getCollection(EL_SELECTED)
                                                    , m_muons.getCollection(MU_SELECTED)
                                                    , &m_llbj_jet_collection
                                                    , *m_llbj_jl_0
                                                    , *m_llbj_jl_1
                                                    );
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysisLooseJets::finalizeEvent()
{
  float lljj_weight = m_event_weight/m_btag_sf;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms for LLJJ and LLBJ BL_PAIRING hist level
  if (  m_pass_grl
     && m_pass_incomplete_event
     && m_pass_lar_error
     && m_pass_tile_error
     && m_pass_tile_hot_spot
     && m_pass_tile_trip
     && m_pass_bad_jet_veto
     && m_pass_calo_problem_jet
     && m_pass_primary_vertex
     && m_pass_bad_mu_veto
     && m_pass_cosmic_mu_veto
     && m_pass_hfor
     && m_pass_mc_overlap
     && m_pass_ge_2_lep
     && m_pass_signal_lep
     && m_pass_os
     && m_pass_trigger
     && m_pass_phase
     ) {
    if( m_pass_lljj_pairing ) {
      fillHistHandles( PennSusyFrame::BMINUSL_LLJJ_HIST_BL_PAIRING
                     , m_electrons.getCollection(EL_SELECTED)
                     , m_muons.getCollection(MU_SELECTED)
                     , m_jets.getCollection(JET_GOOD)
                     , m_lljj_jl_0
                     , m_lljj_jl_1
                     , lljj_weight
                     );

      m_lljj_ht_signal = ( m_lljj_jl_0->getLepton()->getPt()
                         + m_lljj_jl_0->getJet()->getPt()
                         + m_lljj_jl_1->getLepton()->getPt()
                         + m_lljj_jl_1->getJet()->getPt()
                         );
    }
    if( m_pass_llbj_pairing ) {
      fillHistHandles( PennSusyFrame::BMINUSL_LLBJ_HIST_BL_PAIRING
                     , m_electrons.getCollection(EL_SELECTED)
                     , m_muons.getCollection(MU_SELECTED)
                     , &m_llbj_jet_collection
                     , m_llbj_jl_0
                     , m_llbj_jl_1
                     , m_event_weight
                     );

      m_llbj_ht_signal = ( m_lljj_jl_0->getLepton()->getPt()
                         + m_lljj_jl_0->getJet()->getPt()
                         + m_lljj_jl_1->getLepton()->getPt()
                         + m_lljj_jl_1->getJet()->getPt()
                         );
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms for LLJJ and LLBJ ZVETO hist level
  if (  m_pass_grl
     && m_pass_incomplete_event
     && m_pass_lar_error
     && m_pass_tile_error
     && m_pass_tile_hot_spot
     && m_pass_tile_trip
     && m_pass_bad_jet_veto
     && m_pass_calo_problem_jet
     && m_pass_primary_vertex
     && m_pass_bad_mu_veto
     && m_pass_cosmic_mu_veto
     && m_pass_hfor
     && m_pass_mc_overlap
     && m_pass_ge_2_lep
     && m_pass_signal_lep
     && m_pass_os
     && m_pass_trigger
     && m_pass_phase
     && m_pass_z_veto
     ) {
    if( m_pass_lljj_pairing ) {
      fillHistHandles( PennSusyFrame::BMINUSL_LLJJ_HIST_Z_VETO
                     , m_electrons.getCollection(EL_SELECTED)
                     , m_muons.getCollection(MU_SELECTED)
                     , m_jets.getCollection(JET_GOOD)
                     , m_lljj_jl_0
                     , m_lljj_jl_1
                     , lljj_weight
                     );
    }
    if( m_pass_llbj_pairing ) {
      fillHistHandles( PennSusyFrame::BMINUSL_LLBJ_HIST_Z_VETO
                     , m_electrons.getCollection(EL_SELECTED)
                     , m_muons.getCollection(MU_SELECTED)
                     , &m_llbj_jet_collection
                     , m_llbj_jl_0
                     , m_llbj_jl_1
                     , m_event_weight
                     );
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms in signal regions
  // first, do a baseline cut
  if (  m_pass_grl
     && m_pass_incomplete_event
     && m_pass_lar_error
     && m_pass_tile_error
     && m_pass_tile_hot_spot
     && m_pass_tile_trip
     && m_pass_bad_jet_veto
     && m_pass_calo_problem_jet
     && m_pass_primary_vertex
     && m_pass_bad_mu_veto
     && m_pass_cosmic_mu_veto
     && m_pass_hfor
     && m_pass_mc_overlap
     && m_pass_ge_2_lep
     && m_pass_signal_lep
     && m_pass_os
     && m_pass_trigger
     && m_pass_phase
     ) {
    if( m_pass_lljj_pairing ) {
      double lljj_mbl_asym = (m_lljj_jl_0->getMbl() - m_lljj_jl_1->getMbl()) / (m_lljj_jl_0->getMbl() + m_lljj_jl_1->getMbl());
      double lljj_ht       = m_lljj_ht_signal / 1.e3;
      double lljj_met_sig  = m_met.getMetEt()/sqrt(lljj_ht)/1.e3;

      bool lljj_ht_ge_1100   = (lljj_ht       >= 1100.0 );
      bool lljj_ht_ge_500    = (lljj_ht       >= 500.0  );
      bool lljj_mbl_le_2     = (lljj_mbl_asym <= 0.20   );
      bool lljj_met_sig_ge_4 = (lljj_met_sig  >= 4.     );

      // -------------------------------------------------------------------------
      // - Fill histograms for SR (don't fill for data if we are blind!)
      // -------------------------------------------------------------------------
      if ( !m_is_data || !m_is_blind ) {
        // signal region cuts
        if (m_pass_z_veto && lljj_mbl_le_2) {
          if (lljj_ht_ge_1100) {
            fillHistHandles( PennSusyFrame::BMINUSL_LLJJ_HIST_SR_1
                           , m_electrons.getCollection(EL_SELECTED)
                           , m_muons.getCollection(MU_SELECTED)
                           , m_jets.getCollection(JET_GOOD)
                           , m_lljj_jl_0
                           , m_lljj_jl_1
                           , lljj_weight
                           );
          }
          else if (lljj_ht_ge_500) {
            fillHistHandles( PennSusyFrame::BMINUSL_LLJJ_HIST_SR_2
                           , m_electrons.getCollection(EL_SELECTED)
                           , m_muons.getCollection(MU_SELECTED)
                           , m_jets.getCollection(JET_GOOD)
                           , m_lljj_jl_0
                           , m_lljj_jl_1
                           , lljj_weight
                           );
          }
        }
      }

      // -------------------------------------------------------------------------
      // - Fill histograms for CR and VR
      // -------------------------------------------------------------------------
      // CR top region cuts
      if (m_pass_z_veto && !lljj_ht_ge_500 && lljj_mbl_le_2 && lljj_met_sig_ge_4) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLJJ_HIST_CR_TOP
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , m_jets.getCollection(JET_GOOD)
                       , m_lljj_jl_0
                       , m_lljj_jl_1
                       , lljj_weight
                       );
      }

      // CR Z region cuts
      if (!m_pass_z_veto && !lljj_ht_ge_500 && lljj_mbl_le_2 && !lljj_met_sig_ge_4) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLJJ_HIST_CR_Z
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , m_jets.getCollection(JET_GOOD)
                       , m_lljj_jl_0
                       , m_lljj_jl_1
                       , lljj_weight
                       );
      }


      // VR TOP 1 region cuts
      if (m_pass_z_veto && lljj_ht_ge_500 && !lljj_mbl_le_2 && !lljj_met_sig_ge_4) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLJJ_HIST_VR_TOP_1
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , m_jets.getCollection(JET_GOOD)
                       , m_lljj_jl_0
                       , m_lljj_jl_1
                       , lljj_weight
                       );
      }

      // VR TOP 2 region cuts
      if (m_pass_z_veto && lljj_ht_ge_500 && !lljj_mbl_le_2) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLJJ_HIST_VR_TOP_2
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , m_jets.getCollection(JET_GOOD)
                       , m_lljj_jl_0
                       , m_lljj_jl_1
                       , lljj_weight
                       );
      }

      // VR TOP 3 region cuts
      if (m_pass_z_veto && !lljj_ht_ge_500 && lljj_met_sig_ge_4 && !lljj_mbl_le_2) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLJJ_HIST_VR_TOP_3
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , m_jets.getCollection(JET_GOOD)
                       , m_lljj_jl_0
                       , m_lljj_jl_1
                       , lljj_weight
                       );
      }

      // VR Z region cuts
      if (!m_pass_z_veto && lljj_ht_ge_500 && lljj_mbl_le_2) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLJJ_HIST_VR_Z
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , m_jets.getCollection(JET_GOOD)
                       , m_lljj_jl_0
                       , m_lljj_jl_1
                       , lljj_weight
                       );
      }
    }

    if( m_pass_llbj_pairing ) {
      double llbj_mbl_asym = (m_llbj_jl_0->getMbl() - m_llbj_jl_1->getMbl()) / (m_llbj_jl_0->getMbl() + m_llbj_jl_1->getMbl());
      double llbj_ht       = m_llbj_ht_signal / 1.e3;
      double llbj_met_sig  = m_met.getMetEt()/sqrt(llbj_ht)/1.e3;

      bool llbj_ht_ge_1100   = (llbj_ht       >= 1100.0 );
      bool llbj_ht_ge_500    = (llbj_ht       >= 500.0  );
      bool llbj_mbl_le_2     = (llbj_mbl_asym <= 0.20   );
      bool llbj_met_sig_ge_4 = (llbj_met_sig  >= 4.     );


      // -------------------------------------------------------------------------
      // - Fill histograms for SR (don't fill for data if we are blind!)
      // -------------------------------------------------------------------------
      if ( !m_is_data || !m_is_blind ) {
        // signal region cuts
        if (m_pass_z_veto && llbj_mbl_le_2) {
          if (llbj_ht_ge_1100) {
            fillHistHandles( PennSusyFrame::BMINUSL_LLBJ_HIST_SR_1
                           , m_electrons.getCollection(EL_SELECTED)
                           , m_muons.getCollection(MU_SELECTED)
                           , &m_llbj_jet_collection
                           , m_llbj_jl_0
                           , m_llbj_jl_1
                           , m_event_weight
                           );
          }
          else if (llbj_ht_ge_500) {
            fillHistHandles( PennSusyFrame::BMINUSL_LLBJ_HIST_SR_2
                           , m_electrons.getCollection(EL_SELECTED)
                           , m_muons.getCollection(MU_SELECTED)
                           , &m_llbj_jet_collection
                           , m_llbj_jl_0
                           , m_llbj_jl_1
                           , m_event_weight
                           );
          }
        }
      }

      // -------------------------------------------------------------------------
      // - Fill histograms for CR and VR
      // -------------------------------------------------------------------------
      // CR top region cuts
      if (m_pass_z_veto && !llbj_ht_ge_500 && llbj_mbl_le_2 && llbj_met_sig_ge_4) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLBJ_HIST_CR_TOP
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , &m_llbj_jet_collection
                       , m_llbj_jl_0
                       , m_llbj_jl_1
                       , m_event_weight
                       );
      }

      // CR Z region cuts
      if (!m_pass_z_veto && !llbj_ht_ge_500 && llbj_mbl_le_2 && !llbj_met_sig_ge_4) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLBJ_HIST_CR_Z
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , &m_llbj_jet_collection
                       , m_llbj_jl_0
                       , m_llbj_jl_1
                       , m_event_weight
                       );
      }

      // VR TOP 1 region cuts
      if (m_pass_z_veto && !llbj_ht_ge_500 && llbj_mbl_le_2 && !llbj_met_sig_ge_4) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLBJ_HIST_VR_TOP_1
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , &m_llbj_jet_collection
                       , m_llbj_jl_0
                       , m_llbj_jl_1
                       , m_event_weight
                       );
      }

      // VR TOP 2 region cuts
      if (m_pass_z_veto && !llbj_ht_ge_500 && !llbj_mbl_le_2) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLBJ_HIST_VR_TOP_2
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , &m_llbj_jet_collection
                       , m_llbj_jl_0
                       , m_llbj_jl_1
                       , m_event_weight
                       );
      }

      // VR TOP 3 region cuts
      if (m_pass_z_veto && llbj_ht_ge_500 && llbj_met_sig_ge_4 && !llbj_mbl_le_2) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLBJ_HIST_VR_TOP_3
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , &m_llbj_jet_collection
                       , m_llbj_jl_0
                       , m_llbj_jl_1
                       , m_event_weight
                       );
      }

      // VR Z region cuts
      if (!m_pass_z_veto && llbj_ht_ge_500 && llbj_mbl_le_2) {
        fillHistHandles( PennSusyFrame::BMINUSL_LLBJ_HIST_VR_Z
                       , m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , &m_llbj_jet_collection
                       , m_llbj_jl_0
                       , m_llbj_jl_1
                       , m_event_weight
                       );
      }
    }
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysisLooseJets::fillHistHandles( PennSusyFrame::BMINUSL_LOOSE_HIST_LEVELS hist_level
                                                             , const std::vector<PennSusyFrame::Electron*>* electron_list
                                                             , const std::vector<PennSusyFrame::Muon*>* muon_list
                                                             , const std::vector<PennSusyFrame::Jet*>* jet_list
                                                             , const PennSusyFrame::blPair* bl_0
                                                             , const PennSusyFrame::blPair* bl_1
                                                             , float weight
                                                             )
{
  // if this is data, don't fill for wrong phase space + data stream combination
  //   (egamma = ee+em , muon = mm+me)
  if (m_is_data) {
    if (  m_is_egamma_stream
       && (  m_event.getPhaseSpace() == PHASE_MM
          || m_event.getPhaseSpace() == PHASE_ME
          )
       ) {
      return;
    }
    if (  !m_is_egamma_stream
       && (  m_event.getPhaseSpace() == PHASE_EE
          || m_event.getPhaseSpace() == PHASE_EM
         )
       ) {
      return;
    }
  }

  // loop through basic histogram handlers to fill
  size_t num_hists = m_histogram_handlers.at(hist_level).size();
  for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
    m_histogram_handlers.at(hist_level).at(hist_it)->Fill( m_event
                                                         , m_event_quantities
                                                         , electron_list
                                                         , muon_list
                                                         , jet_list
                                                         , m_met
                                                         , weight
                                                         );
  }

  // fill b-l histograms
  // if (m_pass_bl_pairing) {
  if (bl_0 != 0 && bl_1 != 0) {
    m_bminusl_histogram_handler.at(hist_level)->FillSpecial( m_event
                                                           , m_jets.getCollection(JET_B)
                                                           , *bl_0
                                                           , *bl_1
                                                           , m_mc_truth
                                                           , weight
                                                           );
    m_weight_histogram_handler.at(hist_level)->FillSpecial( m_event
                                                          , m_event_quantities
                                                          , m_xsec_weight
                                                          , m_ttbar_pt_weight
                                                          );
    if (!m_is_data) {
      m_parent_histogram_handler.at(hist_level)->FillSpecial( m_event
                                                            , *bl_0
                                                            , *bl_1
                                                            , m_mc_truth
                                                            , weight
                                                            );
    }
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysisLooseJets::finalizeRun()
{
  std::cout << "BMinusLAnalysisLooseJets::finalizeRun()\n";
  std::cout << "creating output histogram file\n";
  TFile out_hist_file(m_out_hist_file_name.c_str(), "RECREATE");

  m_d3pd_reader->writeNumEvents();

  std::cout << "about to write histograms to file\n";
  for ( unsigned int hist_level = 0
      ; hist_level != BMINUSL_LOOSE_HIST_N
      ; ++hist_level
      ) {
    TDirectory* hist_dir_cut_level = out_hist_file.mkdir(PennSusyFrame::BMINUSL_LOOSE_HIST_LEVEL_STRINGS[hist_level].c_str());

    size_t num_hists = m_histogram_handlers.at(hist_level).size();
    for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
      m_histogram_handlers.at(hist_level).at(hist_it)->write(hist_dir_cut_level);
    }

    m_bminusl_histogram_handler.at(hist_level)->write(hist_dir_cut_level);
    m_weight_histogram_handler.at( hist_level)->write(hist_dir_cut_level);
    m_parent_histogram_handler.at( hist_level)->write(hist_dir_cut_level);
    if (m_do_detailed_bl_hists) {
      m_bminusl_detailed_histogram_handler.at(hist_level)->write(hist_dir_cut_level);
    }
  }

  out_hist_file.Close();
  std::cout << "file is closed!\n";

  m_raw_cutflow_tracker.printToScreen();
  m_cutflow_tracker.printToScreen();
}
