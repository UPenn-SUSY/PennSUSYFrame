#include "PennSusyFrameCore/include/TriggerHelpers.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include <vector>
#include <set>
#include "TLorentzVector.h"

// -----------------------------------------------------------------------------
bool PennSusyFrame::matchElectronList( const std::vector<PennSusyFrame::Electron*>* electrons
                                     , const std::vector<int>* trigger_chain
                                     // , const PennSusyFrame::Trigger* // trigger
                                     , size_t num_to_match
                                     , double dr_cut
                                     , double pt_cut
                                     )
{
  // if there are fewer offline objects than num_to_match, automatically fail trigger matching
  size_t offline_term = electrons->size();
  if (offline_term < num_to_match)
    return false;

  // get vector of TLV objects
  std::vector<const TLorentzVector*> off_tlv;
  for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
    off_tlv.push_back(electrons->at(offline_it)->getTlv());
  }

  // sets to keep track of matches - want to aovid double counting matches
  std::set<int> offline_match;
  std::set<int> online_match;

  // loop over all online trigger objects
  size_t online_term = trigger_chain->size();
  for (size_t online_it = 0; online_it != online_term; ++online_it) {
    // first check trigger decision of this trigger object
    //   do not match to triggers that do not fire!
    if (trigger_chain->at(online_it) == 0) continue;

    TLorentzVector on_tlv;
    // TODO set online TLV from trigger object

    // loop over offline obejct to look for matches
    for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
      if (  off_tlv.at(offline_it)->Pt() > pt_cut
         // && off_tlv.at(offline_it)->DeltaR(on_tlv) < dr_cut
         )
      {
        offline_match.insert(offline_it);
        online_match.insert(online_it);

        if (  offline_match.size() >= num_to_match
           && online_match.size() >= num_to_match
           )
          return true;
      }
    }
  }

  // if we reach here, we did not find enough matches to pass matching cut
  return false;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::matchElectron( const PennSusyFrame::Electron* el
                                 , const std::vector<int>* trigger_chain
                                 // , const PennSusyFrame::Trigger* trigger
                                 , double dr_cut
                                 , double pt_cut
                                 )
{
  const std::vector<PennSusyFrame::Electron*> el_vec(1, const_cast<PennSusyFrame::Electron*>(el));
  return matchElectronList( &el_vec
                          , trigger_chain
                          // , trigger
                          , 1
                          , dr_cut
                          , pt_cut
                          );
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::matchMuonList( const std::vector<PennSusyFrame::Muon*>* muons
                                 , const std::vector<int>* trigger_chain
                                 // , const PennSusyFrame::Trigger* // trigger
                                 , size_t num_to_match
                                 , double dr_cut
                                 , double pt_cut
                                 )
{
  // if there are fewer offline objects than num_to_match, automatically fail trigger matching
  size_t offline_term = muons->size();
  if (offline_term < num_to_match)
    return false;

  // get vector of TLV objects
  std::vector<const TLorentzVector*> off_tlv;
  for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
    off_tlv.push_back(muons->at(offline_it)->getTlv());
  }

  // sets to keep track of matches - want to aovid double counting matches
  std::set<int> offline_match;
  std::set<int> online_match;

  // loop over all online trigger objects
  size_t online_term = trigger_chain->size();
  for (size_t online_it = 0; online_it != online_term; ++online_it) {
    // first check trigger decision of this trigger object
    //   do not match to triggers that do not fire!
    if (trigger_chain->at(online_it) == 0) continue;

    TLorentzVector on_tlv;
    // TODO set online TLV from trigger object

    // loop over offline obejct to look for matches
    for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
      if (  off_tlv.at(offline_it)->Pt() > pt_cut
         // && off_tlv.at(offline_it)->DeltaR(on_tlv) < dr_cut
         )
      {
        offline_match.insert(offline_it);
        online_match.insert(online_it);

        if (  offline_match.size() >= num_to_match
           && online_match.size() >= num_to_match
           )
          return true;
      }
    }
  }

  // if we reach here, we did not find enough matches to pass matching cut
  return false;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::matchMuon( const PennSusyFrame::Muon* mu
                             , const std::vector<int>* trigger_chain
                             // , const PennSusyFrame::Trigger* trigger
                             , double dr_cut
                             , double pt_cut
                             )
{
  const std::vector<PennSusyFrame::Muon*> mu_vec(1,const_cast<PennSusyFrame::Muon*>(mu));
  return matchMuonList( &mu_vec
                      , trigger_chain
                      // , trigger
                      , 1
                      , dr_cut
                      , pt_cut
                      );
}
