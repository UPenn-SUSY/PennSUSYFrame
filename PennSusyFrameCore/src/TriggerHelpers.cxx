#include "PennSusyFrameCore/include/TriggerHelpers.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include <vector>
#include <algorithm>
#include <set>
#include "TLorentzVector.h"

// -----------------------------------------------------------------------------
bool PennSusyFrame::matchElectronList( const std::vector<PennSusyFrame::Electron*>* electrons
                                     , const std::vector<int>* trigger_chain
                                     , const std::vector<float>* online_px
                                     , const std::vector<float>* online_py
                                     , const std::vector<float>* online_pz
                                     , const std::vector<float>* online_E
                                     , unsigned int num_to_match
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

    // set online TLV from trigger object
    TLorentzVector on_tlv;
    on_tlv.SetPxPyPzE( online_px->at(online_it)
                     , online_py->at(online_it)
                     , online_pz->at(online_it)
                     , online_E->at(online_it)
                     );

    // loop over offline obejct to look for matches
    for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
      if (  off_tlv.at(offline_it)->Pt() > pt_cut
         && off_tlv.at(offline_it)->DeltaR(on_tlv) < dr_cut
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
                                 , const std::vector<float>* online_px
                                 , const std::vector<float>* online_py
                                 , const std::vector<float>* online_pz
                                 , const std::vector<float>* online_E
                                 , double dr_cut
                                 , double pt_cut
                                 )
{
  const std::vector<PennSusyFrame::Electron*> el_vec(1, const_cast<PennSusyFrame::Electron*>(el));
  return matchElectronList( &el_vec
                          , trigger_chain
                          , online_px
                          , online_py
                          , online_pz
                          , online_E
                          , 1
                          , dr_cut
                          , pt_cut
                          );
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::matchMuonList( const std::vector<PennSusyFrame::Muon*>* muons
                                 , const std::vector<int>* trigger_chain
                                 , const std::vector<std::vector<float> >* online_pt
                                 , const std::vector<std::vector<float> >* online_eta
                                 , const std::vector<std::vector<float> >* online_phi
                                 // , const std::vector<std::vector<float> >* online_E
                                 , unsigned int num_to_match
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
  unsigned int num_online_matched = 0;
  // std::set<int> online_match;

  // loop over all online trigger objects
  size_t trig_term = trigger_chain->size();
  for (size_t trig_it = 0; trig_it != trig_term; ++trig_it) {
    // first check trigger decision of this trigger object
    //   do not match to triggers that do not fire!
    if (trigger_chain->at(trig_it) == 0) continue;

    std::set<int> online_match;

    // loop over online objects
    size_t online_term = online_pt->at(trig_it).size();
    for (size_t online_it = 0; online_it != online_term; ++online_it) {
      // get online tlv
      TLorentzVector on_tlv;
      on_tlv.SetPtEtaPhiM( std::max( static_cast<float>(1.)
                                   , online_pt->at(trig_it).at(online_it)
                                   )
                         , online_eta->at(trig_it).at(online_it)
                         , online_phi->at(trig_it).at(online_it)
                         , 0.
                         );

      // loop over offline obejct to look for matches
      for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
        if (  off_tlv.at(offline_it)->Pt() > pt_cut
           && off_tlv.at(offline_it)->DeltaR(on_tlv) < dr_cut
           ) {
          offline_match.insert(offline_it);
          online_match.insert(online_it);
        }
      }
    }

    num_online_matched += online_match.size();

    // if we have enough matches, pass the trigger matching
    if (  offline_match.size() >= num_to_match
       && num_online_matched   >= num_to_match
       ) {
      return true;
    }
  }

  // if we reach here, we did not find enough matches to pass matching cut
  return false;
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::matchMuon( const PennSusyFrame::Muon* mu
                             , const std::vector<int>* trigger_chain
                             , const std::vector<std::vector<float> >* online_pt
                             , const std::vector<std::vector<float> >* online_eta
                             , const std::vector<std::vector<float> >* online_phi
                             // , const std::vector<std::vector<float> >* online_E
                             , double dr_cut
                             , double pt_cut
                             )
{
  const std::vector<PennSusyFrame::Muon*> mu_vec(1,const_cast<PennSusyFrame::Muon*>(mu));
  return matchMuonList( &mu_vec
                      , trigger_chain
                      , online_pt
                      , online_eta
                      , online_phi
                      //,  online_E
                      , 1
                      , dr_cut
                      , pt_cut
                      );
}

// -----------------------------------------------------------------------------
std::vector<float> PennSusyFrame::getDrParticleMuonTrigger( const std::vector<PennSusyFrame::Particle*>& particles
							    , const std::vector<int>* trigger_chain
							    , const std::vector<std::vector<float> >* online_pt
							    , const std::vector<std::vector<float> >* online_eta
							    , const std::vector<std::vector<float> >* online_phi
							    )
{
  float min_dR=10.;
  std::vector<float> dR_list;
  size_t offline_term = particles.size();

  // get vector of TLV objects
  std::vector<const TLorentzVector*> off_tlv;
  // loop over all offline objects
  for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
    off_tlv.push_back(particles.at(offline_it)->getTlv());

    // loop over all online trigger objects
    size_t trig_term = trigger_chain->size();
    for (size_t trig_it = 0; trig_it != trig_term; ++trig_it) {
      // first check trigger decision of this trigger object
      //   do not match to triggers that do not fire!
      if (trigger_chain->at(trig_it) == 0) continue;

      // loop over online objects
      size_t online_term = online_pt->at(trig_it).size();
      for (size_t online_it = 0; online_it != online_term; ++online_it) {
	// get online tlv
	TLorentzVector on_tlv;
	on_tlv.SetPtEtaPhiM( std::max( static_cast<float>(1.)
				       , online_pt->at(trig_it).at(online_it)
				       )
			     , online_eta->at(trig_it).at(online_it)
			     , online_phi->at(trig_it).at(online_it)
			     , 0.
			     );

	// find dR between offline and nearest online objects
	float dR = off_tlv.at(offline_it)->DeltaR(on_tlv);
	if (dR < min_dR) min_dR = dR;

	dR_list.push_back(off_tlv.at(offline_it)->DeltaR(on_tlv));
      }
    }
    dR_list.push_back(min_dR);
  }
  return dR_list;
}
