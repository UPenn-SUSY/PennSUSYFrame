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
PennSusyFrame::BMinusLAnalysisLooseJets::BMinusLAnalysisLooseJets(TTree* tree) : PennSusyFrame::BMinusLAnalysis(tree)
                                                                               , m_lljj_jl_0(0)
                                                                               , m_lljj_jl_1(0)
                                                                               , m_llbj_jl_0(0)
                                                                               , m_llbj_jl_1(0)

{
}

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLAnalysisLooseJets::~BMinusLAnalysisLooseJets()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysisLooseJets::initializeEvent()
{
  m_pass_lljj_pairing = false;
  m_pass_llbj_pairing = false;

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

    // std::vector<PennSusyFrame::Jet*>

    // m_pass_llbj_pairing = PennSusyFrame::doBLPairing( m_event
    //                                                 , m_electrons.getCollection(EL_SELECTED)
    //                                                 , m_muons.getCollection(MU_SELECTED)
    //                                                 , m_llbj_jet_collection
    //                                                 , *m_llbj_jl_0
    //                                                 , *m_llbj_jl_1
    //                                                 );
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysisLooseJets::finalizeEvent()
{
  float lljj_weight = m_event_weight/m_btag_sf;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms for LLJJ_BL_PAIRING hist level
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
    }
  }
}

// -----------------------------------------------------------------------------

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
  if (m_pass_bl_pairing) {
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
