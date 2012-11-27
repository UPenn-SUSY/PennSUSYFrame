/*
// Dear emacs, this is -*- c++ -*-
#include "include/MuonSelection.h"
#include <iostream>
#include <math.h>

// ----------------------------------------------------------------------------
Selection::MuonSelection::MuonSelection() : m_enabled(false)
                                          , m_pass_cut_word(0)
                                          , m_reverse_cut_word(0)
                                          , m_d0_cut_min(-999)
                                          , m_d0_cut_max(-999)
                                          , m_d0sig_cut_min(-999)
                                          , m_d0sig_cut_max(-999)
                                          , m_z0_cut_min(-999)
                                          , m_z0_cut_max(-999)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}

// ----------------------------------------------------------------------------
Selection::MuonSelection::MuonSelection( SusyAnalysisTools::muon_description pass_word
                                       , SusyAnalysisTools::muon_description reverse_word
                                       )
                                       : m_enabled(true)
                                       , m_pass_cut_word(pass_word)
                                       , m_reverse_cut_word(reverse_word)
                                       , m_d0_cut_min(-999)
                                       , m_d0_cut_max(-999)
                                       , m_d0sig_cut_min(-999)
                                       , m_d0sig_cut_max(-999)
                                       , m_z0_cut_min(-999)
                                       , m_z0_cut_max(-999)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}

// -----------------------------------------------------------------------------
void Selection::MuonSelection::enable()
{
  m_enabled = true;
}

// -----------------------------------------------------------------------------
void Selection::MuonSelection::disable()
{
  m_enabled = false;
}

// ----------------------------------------------------------------------------
void Selection::MuonSelection::setMuNum(unsigned int  pass, unsigned int reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_mu_num(pass);
  m_reverse_cut_word.set_mu_num(reverse);
}

// ----------------------------------------------------------------------------
void Selection::MuonSelection::setCombined(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_combined(pass);
  m_reverse_cut_word.set_combined(reverse);
}

// ----------------------------------------------------------------------------
void Selection::MuonSelection::setTag(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_tag(pass);
  m_reverse_cut_word.set_tag(reverse);
}

// ----------------------------------------------------------------------------
void Selection::MuonSelection::setLoose(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_loose(pass);
  m_reverse_cut_word.set_loose(reverse);
}

// ----------------------------------------------------------------------------
void Selection::MuonSelection::setZ0Cut(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_z0_cut(pass);
  m_reverse_cut_word.set_z0_cut(reverse);
}

// ----------------------------------------------------------------------------
void Selection::MuonSelection::setD0Cut(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_d0_cut(pass);
  m_reverse_cut_word.set_d0_cut(reverse);
}

// ----------------------------------------------------------------------------
void Selection::MuonSelection::setAbsTrackIsoCut(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_abs_track_iso_cut(pass);
  m_reverse_cut_word.set_abs_track_iso_cut(reverse);
}

// ----------------------------------------------------------------------------
void Selection::MuonSelection::setAbsCaloIsoCut(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_abs_calo_iso_cut(pass);
  m_reverse_cut_word.set_abs_calo_iso_cut(reverse);
}

// ----------------------------------------------------------------------------
void Selection::MuonSelection::setRelTrackIsoCut(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_rel_track_iso_cut(pass);
  m_reverse_cut_word.set_rel_track_iso_cut(reverse);
}

// ----------------------------------------------------------------------------
void Selection::MuonSelection::setRelCaloIsoCut(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_rel_calo_iso_cut(pass);
  m_reverse_cut_word.set_rel_calo_iso_cut(reverse);
}


// ----------------------------------------------------------------------------
bool Selection::MuonSelection::passMuon(Muon& muon) const
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  return (  m_enabled
         && muon.desc().pass(m_pass_cut_word)
         && muon.desc().reverse(m_reverse_cut_word)
         && passD0Cut(muon)
         && passD0SigCut(muon)
         && passZ0Cut(muon)
         );
}

// -----------------------------------------------------------------------------
bool Selection::MuonSelection::passD0Cut(Muon& muon) const
{
  double d0 = muon.d0();
  if ( m_d0_cut_min > -999 && d0 < m_d0_cut_min ) return false;
  if ( m_d0_cut_max > -999 && d0 > m_d0_cut_max ) return false;
  return true;
}

// -----------------------------------------------------------------------------
bool Selection::MuonSelection::passD0SigCut(Muon& muon) const
{
  double d0sig = fabs(muon.d0()/sqrt(muon.cov_d0()));
  if ( m_d0sig_cut_min > -999 && d0sig < m_d0sig_cut_min ) return false;
  if ( m_d0sig_cut_max > -999 && d0sig > m_d0sig_cut_max ) return false;
  return true;
}

// -----------------------------------------------------------------------------
bool Selection::MuonSelection::passZ0Cut(Muon& muon) const
{
  double z0 = muon.z0();
  if ( m_z0_cut_min > -999 && z0 < m_z0_cut_min ) return false;
  if ( m_z0_cut_max > -999 && z0 > m_z0_cut_max ) return false;
  return true;
}

// -----------------------------------------------------------------------------
void Selection::MuonSelection::setD0CutValue(double min, double max)
{
  m_d0_cut_min = min;
  m_d0_cut_max = max;
}

// -----------------------------------------------------------------------------
void Selection::MuonSelection::setD0SigCutValue(double min, double max)
{
  m_d0sig_cut_min = min;
  m_d0sig_cut_max = max;
}

// -----------------------------------------------------------------------------
void Selection::MuonSelection::setZ0CutValue(double min, double max)
{
  m_z0_cut_min = min;
  m_z0_cut_max = max;
}
*/
