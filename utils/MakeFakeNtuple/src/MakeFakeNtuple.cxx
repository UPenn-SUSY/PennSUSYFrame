#include "MakeFakeNtuple/include/MakeFakeNtuple.h"

#include <TTree.h>

#include "NtupleLooper/include/NtupleLooper.h"
#include "TLorentzVector.h"
#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/ElectronDescription.h"
#include "SusyAnalysisTools/include/MuonDescription.h"

// -----------------------------------------------------------------------------
MakeFakeNtuple::MakeFakeNtuple( TTree *tree
                            , double num_events
                            , std::string out_file_name
                            ) : NtupleLooper(tree, num_events)
                              , m_out_file_name(out_file_name)
{
  std::string rate_file_name = "${ROOTCOREDIR}/../SusyMatrixMethod/data/pass6_Apr2_2013.root";
  m_fake_ntuple_maker.configure( rate_file_name
                               , SusyMatrixMethod::PT
                               , m_out_file_name
                               );
  // do nothing
}

// -----------------------------------------------------------------------------
MakeFakeNtuple::~MakeFakeNtuple()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void MakeFakeNtuple::processEvent()
{

  size_t num_el  = m_el_desc->size();
  size_t num_mu  = m_mu_desc->size();
  size_t num_jet = m_jet_desc->size();
  if (num_el + num_mu == 2) {
    m_fake_ntuple_maker.clean();

    SusyAnalysisTools::EventDescription event_desc(m_event_desc);
    SusyAnalysisTools::SRHelper         sr_helper(m_sr_helper);

    SusyMatrixMethod::SIGN_CHANNEL sign_channel = SusyMatrixMethod::NO_SIGN;
    if (event_desc.getSignChannel() == SIGN_OS) {
      sign_channel = SusyMatrixMethod::OS_CHANNEL;
    }
    else if (event_desc.getSignChannel() == SIGN_SS) {
      sign_channel = SusyMatrixMethod::SS_CHANNEL;
    }

    if (sign_channel != SusyMatrixMethod::SS_CHANNEL)
      return;

    if (  event_desc.isEETrigger() == false
       && event_desc.isMMTrigger() == false
       && event_desc.isEMTrigger() == false
       && event_desc.isMETrigger() == false
       )
      return;

    if (!event_desc.getPassTriggerMatch())
      return;

    // std::cout << "trigger channel: "
    //           << "\n\tee: " << event_desc.isEETrigger()
    //           << "\n\tmm: " << event_desc.isMMTrigger()
    //           << "\n\tem: " << event_desc.isEMTrigger()
    //           << "\n\tme: " << event_desc.isMETrigger()
    //           << "\n\tmatch: " << event_desc.getPassTriggerMatch()
    //           << "\n";

    if (event_desc.getPassTriggerMatch() == false)
      std::cout << "WARNING!!! no trigger match\n";

    m_fake_ntuple_maker.setSRFlags( false
                                  , true
                                  , false
                                  , false
                                  , false
                                  , false
                                  , false
                                  , false
                                  , false
                                  , false
                                  );

    m_fake_ntuple_maker.setEventProperties( m_run_number
                                          , m_event_number
                                          , sign_channel
                                          , m_met_et
                                          , m_met_phi
                                          , m_met_rel_et
                                          , m_mll
                                          , m_mt2
                                          , m_ptll
                                          , sr_helper.getPassTopVeto()
                                          , m_vtx_n
                                          );

    std::vector<bool>  lep_is_electron;
    std::vector<bool>  lep_is_tight;
    std::vector<float> lep_pt;
    std::vector<float> lep_eta;
    std::vector<float> lep_phi;
    std::vector<float> lep_energy;
    std::vector<float> jet_pt;
    std::vector<float> jet_energy;
    std::vector<float> jet_eta;
    std::vector<float> jet_phi;
    std::vector<float> jet_b_tag_weight;
    std::vector<float> jet_jvf;

    lep_is_electron.reserve(num_el+num_mu);
    lep_is_tight.reserve(num_el+num_mu);
    lep_pt.reserve(num_el+num_mu);
    lep_eta.reserve(num_el+num_mu);
    lep_phi.reserve(num_el+num_mu);
    lep_energy.reserve(num_el+num_mu);
    jet_pt.reserve(num_jet);
    jet_energy.reserve(num_jet);
    jet_eta.reserve(num_jet);
    jet_phi.reserve(num_jet);
    jet_b_tag_weight.reserve(num_jet);
    jet_jvf.reserve(num_jet);

    for (size_t el_it = 0; el_it != num_el; ++el_it) {
      SusyAnalysisTools::ElectronDescription el_desc(m_el_desc->at(el_it));

      lep_is_electron.push_back(true);
      lep_is_tight.push_back(el_desc.getPassSignal());
      lep_pt.push_back(m_el_pt->at(el_it));
      lep_eta.push_back(m_el_eta->at(el_it));
      lep_phi.push_back(m_el_phi->at(el_it));
      lep_energy.push_back(m_el_E->at(el_it));
    }

    for (size_t mu_it = 0; mu_it != num_mu; ++mu_it) {
      SusyAnalysisTools::MuonDescription mu_desc(m_mu_desc->at(mu_it));

      lep_is_electron.push_back(false);
      lep_is_tight.push_back(mu_desc.getPassSignal());
      lep_pt.push_back(m_mu_pt->at(mu_it));
      lep_eta.push_back(m_mu_eta->at(mu_it));
      lep_phi.push_back(m_mu_phi->at(mu_it));
      // TODO fill with muon energy
      // lep_energy.push_back(m_mu_E->at(mu_it));
      lep_energy.push_back(0.);
    }

    for (size_t jet_it = 0; jet_it != num_jet; ++jet_it) {
      jet_pt.push_back(m_jet_pt->at(jet_it));
      // TODO fill with jet energy
      // jet_energy.push_back(m_jet_E->at(jet_it));
      jet_energy.push_back(0.);
      jet_eta.push_back(m_jet_eta->at(jet_it));
      jet_phi.push_back(m_jet_phi->at(jet_it));
      jet_b_tag_weight.push_back(m_jet_bjet_mv1->at(jet_it));
      jet_jvf.push_back(m_jet_jvf->at(jet_it));
    }

    m_fake_ntuple_maker.setJets( jet_pt
                               , jet_energy
                               , jet_eta
                               , jet_phi
                               , jet_b_tag_weight
                               , jet_jvf
                               );
    m_fake_ntuple_maker.setLeptons( lep_is_electron
                                  , lep_is_tight
                                  , lep_pt
                                  , lep_eta
                                  , lep_phi
                                  , lep_energy
                                  , m_met_rel_et
                                  );
  m_fake_ntuple_maker.fill();
  }
}

// -----------------------------------------------------------------------------
void MakeFakeNtuple::write()
{
  m_fake_ntuple_maker.write();
}
