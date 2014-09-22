#include "BMinusLAnalysis/include/BMinusLTTNTMaker.h"
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
PennSusyFrame::BMinusLTTNTMaker::BMinusLTTNTMaker(TTree* tree) : PennSusyFrame::BMinusLAnalysis(tree)
                                                               , m_out_ntuple_file_name("BMinusL.ntup.root")
{
}

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLTTNTMaker::~BMinusLTTNTMaker()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLTTNTMaker::prepareTools()
{
  BMinusLAnalysis::prepareTools();

  m_object_cleaning.setEEConeSize(0.00);
  m_object_cleaning.setEJConeSize(0.00);
  // m_object_cleaning.setMJConeSize(0.20); // not done by default
  m_object_cleaning.setMJConeSize(0.00);
  m_object_cleaning.setETConeSize(0.00);
  m_object_cleaning.setMTConeSize(0.00);
  m_object_cleaning.setJEConeSize(0.00);
  m_object_cleaning.setJMConeSize(0.00);
  m_object_cleaning.setEMConeSize(0.00);
  m_object_cleaning.setMMConeSize(0.00);
  m_object_cleaning.setTJConeSize(0.00);
  m_object_cleaning.setSFOSMllMin(0.00);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLTTNTMaker::beginRun()
{
  PennSusyFrameCore::beginRun();

  // prepare selection
  prepareSelection();

  std::cout << "configuring TNT with name: " << m_out_ntuple_file_name << "\n";
  configureTnt(m_out_ntuple_file_name, "BMinusLTTNT");
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLTTNTMaker::finalizeEvent()
{
  if (  m_pass_grl
     && m_pass_incomplete_event
     && m_pass_lar_error
     && m_pass_tile_error
     && m_pass_tile_hot_spot
     && m_pass_tile_trip
     && m_pass_primary_vertex
     && m_pass_ge_2_lep
     && m_pass_ge_2_b_jet
     ) {
    fillTnt();
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLTTNTMaker::finalizeRun()
{
  std::cout << "BMinusLTTNTMaker::finalizeRun()\n";
  writeTnt();
}
