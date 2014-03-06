/*
// Dear emacs, this is -*- c++ -*-
#include "include/ElectronSelection.h"
#include <iostream>
#include <math.h>

// ----------------------------------------------------------------------------
Selection::ElectronSelection::ElectronSelection(): m_enabled(false)
                                                 , m_pass_cut_word(0)
                                                 , m_reverse_cut_word(0)
                                                 , m_d0sig_cut_min(-999)
                                                 , m_d0sig_cut_max(-999)
                                                 , m_z0sintheta_cut_min(-999)
                                                 , m_z0sintheta_cut_max(-999)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}

// ----------------------------------------------------------------------------
Selection::ElectronSelection::ElectronSelection( SusyAnalysisTools::electron_description pass_word
                                               , SusyAnalysisTools::electron_description reverse_word
                                               )
                                               : m_enabled(true)
                                               , m_pass_cut_word(pass_word)
                                               , m_reverse_cut_word(reverse_word)
                                               , m_d0sig_cut_min(-999)
                                               , m_d0sig_cut_max(-999)
                                               , m_z0sintheta_cut_min(-999)
                                               , m_z0sintheta_cut_max(-999)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}
// -----------------------------------------------------------------------------
void Selection::ElectronSelection::enable()
{
  m_enabled = true;
}

// -----------------------------------------------------------------------------
void Selection::ElectronSelection::disable()
{
  m_enabled = false;
}


// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setElNum(unsigned int pass, unsigned int reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_el_num(pass);
  m_reverse_cut_word.set_el_num(reverse);
}

// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setLoose(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_loose(pass);
  m_reverse_cut_word.set_loose(reverse);
}

// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setMedium(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_medium(pass);
  m_reverse_cut_word.set_medium(reverse);
}

// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setTight(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_tight(pass);
  m_reverse_cut_word.set_tight(reverse);
}

// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setLoosePP(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_loosepp(pass);
  m_reverse_cut_word.set_loosepp(reverse);
}

// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setMediumPP(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_mediumpp(pass);
  m_reverse_cut_word.set_mediumpp(reverse);
}

// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setTightPP(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_tightpp(pass);
  m_reverse_cut_word.set_tightpp(reverse);
}

// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setAbsTrackIsoCut(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_abs_track_iso_cut(pass);
  m_reverse_cut_word.set_abs_track_iso_cut(reverse);
}

// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setAbsCaloIsoCut(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_abs_calo_iso_cut(pass);
  m_reverse_cut_word.set_abs_calo_iso_cut(reverse);
}

// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setRelTrackIsoCut(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_rel_track_iso_cut(pass);
  m_reverse_cut_word.set_rel_track_iso_cut(reverse);
}

// ----------------------------------------------------------------------------
void Selection::ElectronSelection::setRelCaloIsoCut(bool pass, bool reverse)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_pass_cut_word.set_rel_calo_iso_cut(pass);
  m_reverse_cut_word.set_rel_calo_iso_cut(reverse);
}

// ----------------------------------------------------------------------------
bool Selection::ElectronSelection::passElectron(Electron& electron) const
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  return (  m_enabled
         && electron.desc().pass(m_pass_cut_word)
         && electron.desc().reverse(m_reverse_cut_word)
         && passD0SigCut(electron)
         );
}

// -----------------------------------------------------------------------------
bool Selection::ElectronSelection::passD0SigCut(Electron& electron) const
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  double d0sig = fabs(electron.d0()/electron.d0_sig());
  if ( m_d0sig_cut_min > -999 && d0sig < m_d0sig_cut_min ) return false;
  if ( m_d0sig_cut_max > -999 && d0sig > m_d0sig_cut_max ) return false;
  return true;
}

// -----------------------------------------------------------------------------
bool Selection::ElectronSelection::passZ0SinThetaCut(Electron& electron) const
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  double theta = 2*atan(exp(-electron.eta()));
  double z0_sin_theta = fabs(electron.z0() * sin(theta));
  if ( m_z0sintheta_cut_min > -999 && z0_sin_theta < m_z0sintheta_cut_min) return false;
  if ( m_z0sintheta_cut_max > -999 && z0_sin_theta > m_z0sintheta_cut_max) return false;
  return true;
}

// -----------------------------------------------------------------------------
void Selection::ElectronSelection::setD0SigCutValue(double min, double max)
{
  m_d0sig_cut_min = min;
  m_d0sig_cut_max = max;
}

// -----------------------------------------------------------------------------
void Selection::ElectronSelection::setZ0SinThetaCutValue(double min, double max)
{
  m_z0sintheta_cut_min = min;
  m_z0sintheta_cut_max = max;
}
*/
