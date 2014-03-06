/*
#include "include/ElectronSelectionDefs.h"

// ----------------------------------------------------------------------------
Selection::ElectronSelection ElectronSelectionDefs::no_cuts( unsigned int pass_el_num
                                                           , unsigned int rev_el_num
                                                           )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::ElectronSelection sel;

  sel.setElNum          (pass_el_num, rev_el_num);
  sel.setLoose          (false, false);
  sel.setMedium         (false, false);
  sel.setTight          (false, false);
  sel.setLoosePP        (false, false);
  sel.setMediumPP       (false, false);
  sel.setTightPP        (false, false);
  sel.setAbsTrackIsoCut(false, false);
  sel.setAbsCaloIsoCut (false, false);
  sel.setRelTrackIsoCut(false, false);
  sel.setRelCaloIsoCut (false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::ElectronSelection ElectronSelectionDefs::all_cuts( unsigned int pass_el_num
                                                            , unsigned int rev_el_num
                                                            )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::ElectronSelection sel;

  sel.setElNum          (pass_el_num, rev_el_num);
  sel.setLoose          (false, false);
  sel.setMedium         (false, false);
  sel.setTight          (false, false);
  sel.setLoosePP        (false, false);
  sel.setMediumPP       (true , false);
  sel.setTightPP        (true , false);
  sel.setAbsTrackIsoCut(true , false);
  sel.setAbsCaloIsoCut (true , false);
  sel.setRelTrackIsoCut(true , false);
  sel.setRelCaloIsoCut (true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::ElectronSelection ElectronSelectionDefs::Ntightpp( unsigned int pass_el_num
                                                            , unsigned int rev_el_num
                                                            )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::ElectronSelection sel = all_cuts(pass_el_num, rev_el_num);

  sel.setTightPP(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::ElectronSelection ElectronSelectionDefs::NrelTrackIso( unsigned int pass_el_num
                                                                , unsigned int rev_el_num
                                                                )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::ElectronSelection sel = all_cuts(pass_el_num, rev_el_num);

  sel.setAbsTrackIsoCut(false, false);
  sel.setAbsCaloIsoCut( false, false);
  sel.setRelTrackIsoCut(false, false);
  sel.setRelCaloIsoCut( false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::ElectronSelection ElectronSelectionDefs::Ntightpp_NrelTrackIso( unsigned int pass_el_num
                                                                         , unsigned int rev_el_num
                                                                         )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::ElectronSelection sel = all_cuts(pass_el_num, rev_el_num);

  sel.setTightPP        (false, false);
  sel.setAbsTrackIsoCut(false, false);
  sel.setAbsCaloIsoCut( false, false);
  sel.setRelTrackIsoCut(false, false);
  sel.setRelCaloIsoCut( false, false);

  return sel;
}
*/
