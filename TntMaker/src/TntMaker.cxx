#include "TntMaker/include/TntMaker.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <dirent.h>
#include <math.h>
#include <algorithm>

#include "PennSusyFrameCore/include/ObjectContainers.h"
#include "PennSusyFrameCore/include/Calculators.h"
#include "PennSusyFrameCore/include/SelectorHelpers.h"

// -----------------------------------------------------------------------------
PennSusyFrame::TntMaker::TntMaker(TTree* tree) : PennSusyFrame::PennSusyFrameCore(tree)
                                               , m_out_tnt_file_name("Tnt.root")
                                               , m_crit_cut_incomplete_event(false)
                                               , m_crit_cut_lar_error(false)
                                               , m_crit_cut_tile_error(false)
                                               , m_crit_cut_tile_hot_spot(false)
                                               , m_crit_cut_tile_trip(false)
                                               , m_crit_cut_bad_jet_veto(false)
                                               , m_crit_cut_calo_problem_jet(false)
                                               , m_crit_cut_primary_vertex(false)
                                               , m_crit_cut_bad_mu_veto(false)
                                               , m_crit_cut_cosmic_mu_veto(false)
                                               , m_crit_cut_hfor(false)
                                               , m_crit_cut_mc_overlap(false)
                                               , m_crit_cut_ge_2_lep(false)
                                               , m_crit_cut_2_lep(false)
                                               , m_crit_cut_mll_sfos(false)
{ }

// -----------------------------------------------------------------------------
PennSusyFrame::TntMaker::~TntMaker()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::TntMaker::prepareTools()
{
  PennSusyFrameCore::prepareTools();

  // Turn off all overlap removal
  m_object_cleaning.setEEConeSize(0.0);
  m_object_cleaning.setEJConeSize(0.0);
  m_object_cleaning.setMJConeSize(0.0);
  m_object_cleaning.setETConeSize(0.0);
  m_object_cleaning.setMTConeSize(0.0);
  m_object_cleaning.setJEConeSize(0.0);
  m_object_cleaning.setJMConeSize(0.0);
  m_object_cleaning.setEMConeSize(0.0);
  m_object_cleaning.setMMConeSize(0.0);
  m_object_cleaning.setTJConeSize(0.0);
  m_object_cleaning.setSFOSMllMin(0.0);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TntMaker::beginRun()
{
  configureTnt(m_out_tnt_file_name, "TNT");
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TntMaker::processEvent()
{
  // increment the mc event weight counter
  m_sum_mc_event_weights += m_event_quantities.getMcEventWeight();

  // // -----------------------------------------------------------------------------
  // m_event.setTriggerPhase( PennSusyFrame::getTriggerPhase( m_electrons.getCollection(EL_GOOD)
  //                                                        , m_muons.getCollection(MU_GOOD)
  //                                                        )
  //                        );
  // m_event.setPhaseSpace(PennSusyFrame::getPhaseSpaceFromTriggerPhase(m_event.getTriggerPhase()));

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // incomplete event cut
  // TODO validate incomplete event cut
  bool pass_incomplete_event = PennSusyFrame::passIncompleteEvent(m_event);
  if (m_crit_cut_incomplete_event && !pass_incomplete_event) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // LAr error cut
  // TODO validate LAr error cut
  bool pass_lar_error = PennSusyFrame::passLarError(m_event);
  if (m_crit_cut_lar_error && !pass_lar_error) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile error cut
  // TODO validate tile error cut
  bool pass_tile_error = PennSusyFrame::passTileError(m_event);
  if (m_crit_cut_tile_error && !pass_tile_error) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile hot spot cut
  // TODO validate tile hot spot cut
  bool pass_tile_hot_spot = PennSusyFrame::TileHotSpotTool::passTileHotSpot(m_event, m_jets);
  if (m_crit_cut_tile_hot_spot && !pass_tile_hot_spot) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile trip cut
  // TODO validate tile trip cut
  bool pass_tile_trip = m_tile_trip_tool.passTileTrip(m_event);
  if (m_crit_cut_tile_trip && !pass_tile_trip) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad jet veto
  bool pass_bad_jet_veto = (m_jets.num(JET_BAD) == 0);
  if (m_crit_cut_bad_jet_veto && !pass_bad_jet_veto) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calo problem jet cut
  bool pass_calo_problem_jet = (m_jets.num(JET_CALO_PROBLEM) == 0);
  if (m_crit_cut_calo_problem_jet && !pass_calo_problem_jet) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // primary vertex cut
  bool pass_primary_vertex = PennSusyFrame::passPrimaryVertex(m_vertices);
  if (m_crit_cut_primary_vertex && !pass_primary_vertex) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad muon cut
  bool pass_bad_mu_veto = (m_muons.num(MU_BAD) == 0);
  if (m_crit_cut_bad_mu_veto && !pass_bad_mu_veto) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // cosmic muon veto
  bool pass_cosmic_mu_veto = (m_muons.num(MU_COSMIC) == 0);
  if (m_crit_cut_cosmic_mu_veto && !pass_cosmic_mu_veto) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // HFOR cut
  // TODO validate HFOR cut
  bool pass_hfor = m_hfor_tool.passHFOR(m_mc_truth);
  if (m_crit_cut_hfor && !pass_hfor) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // mc overlap cut
  // TODO validate mc overlap cut
  bool pass_mc_overlap = (  PennSusyFrame::passSherpaWWOverlapRemoval(m_event, m_mc_truth)
                         && PennSusyFrame::passZOverlapRemoval(m_mc_truth)
                         );
  if (m_crit_cut_mc_overlap && !pass_mc_overlap) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of good leptons
  int num_good_leptons = m_electrons.num(EL_GOOD) + m_muons.num(MU_GOOD);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // >= 2 baseline leptons cut
  bool pass_ge_2_lep = (num_good_leptons >= 2);
  if (m_crit_cut_ge_2_lep && !pass_ge_2_lep) {
    m_pass_event = false;
    return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 baseline leptons cut
  bool pass_2_lep = (num_good_leptons == 2);
  if (m_crit_cut_2_lep && !pass_2_lep) {
    m_pass_event = false;
    return;
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TntMaker::finalizeEvent()
{
  if (m_pass_event) {
    fillTnt();
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TntMaker::finalizeRun()
{
  writeTnt();
}
