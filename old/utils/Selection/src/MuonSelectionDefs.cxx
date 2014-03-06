/*
#include "include/MuonSelectionDefs.h"

// ----------------------------------------------------------------------------
Selection::MuonSelection MuonSelectionDefs::no_cuts( unsigned int pass_mu_num
                                                   , unsigned int rev_mu_num
                                                   )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::MuonSelection sel;

  sel.setMuNum(pass_mu_num, rev_mu_num);
  sel.setCombined       (false, false);
  sel.setTag            (false, false);
  sel.setLoose          (false, false);
  sel.setZ0Cut         (false, false);
  sel.setD0Cut         (false, false);
  sel.setAbsTrackIsoCut(false, false);
  sel.setAbsCaloIsoCut (false, false);
  sel.setRelTrackIsoCut(false, false);
  sel.setRelCaloIsoCut (false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::MuonSelection MuonSelectionDefs::all_cuts( unsigned int pass_mu_num
                                                    , unsigned int rev_mu_num
                                                    )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::MuonSelection sel;

  sel.setMuNum(pass_mu_num, rev_mu_num);
  sel.setCombined       (true , false);
  sel.setTag            (true , false);
  sel.setLoose          (true , false);
  sel.setZ0Cut         (true , false);
  sel.setD0Cut         (true , false);
  sel.setAbsTrackIsoCut(true , false);
  sel.setAbsCaloIsoCut (true , false);
  sel.setRelTrackIsoCut(true , false);
  sel.setRelCaloIsoCut (true , false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::MuonSelection MuonSelectionDefs::Nd0( unsigned int pass_mu_num
                                               , unsigned int rev_mu_num
                                               )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::MuonSelection sel = all_cuts(pass_mu_num, rev_mu_num);

  sel.setD0Cut(false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::MuonSelection MuonSelectionDefs::NabsTrackIso( unsigned int pass_mu_num
                                                        , unsigned int rev_mu_num
                                                        )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::MuonSelection sel = all_cuts(pass_mu_num, rev_mu_num);

  sel.setAbsTrackIsoCut(false, false);
  sel.setAbsCaloIsoCut (false, false);
  sel.setRelTrackIsoCut(false, false);
  sel.setRelCaloIsoCut (false, false);

  return sel;
}

// ----------------------------------------------------------------------------
Selection::MuonSelection MuonSelectionDefs::Nd0_NabsTrackIso( unsigned int pass_mu_num
                                                      		   , unsigned int rev_mu_num
                                                      		   )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  Selection::MuonSelection sel = all_cuts(pass_mu_num, rev_mu_num);

  sel.setD0Cut         (false, false);
  sel.setAbsTrackIsoCut(false, false);
  sel.setAbsCaloIsoCut (false, false);
  sel.setRelTrackIsoCut(false, false);
  sel.setRelCaloIsoCut (false, false);

  return sel;
}
*/
