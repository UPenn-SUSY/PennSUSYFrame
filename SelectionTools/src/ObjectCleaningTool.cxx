#include "include/ObjectCleaningTool.h"

#include <iostream>
#include <vector>
#include <math.h>
#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/Tau.h"
#include "AtlasSFrameUtils/include/TauContainer.h"
#include "AtlasSFrameUtils/include/ToolBase.h"

// ----------------------------------------------------------------------------
SelectionTools::ObjectCleaningTool::ObjectCleaningTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  // DeclareProperty("signal_max_etcone_cut", c_signal_max_etcone_cut = 0.18);
  DeclareProperty("ee_cone_size", c_ee_cone_size = 0.05);
  DeclareProperty("ej_cone_size", c_ej_cone_size = 0.20);
  DeclareProperty("et_cone_size", c_et_cone_size = 0.20);
  DeclareProperty("mt_cone_size", c_mt_cone_size = 0.20);
  DeclareProperty("tj_cone_size", c_tj_cone_size = 0.20);
  DeclareProperty("je_cone_size", c_je_cone_size = 0.40);
  DeclareProperty("jm_cone_size", c_jm_cone_size = 0.40);
  DeclareProperty("em_cone_size", c_em_cone_size = 0.01);
  DeclareProperty("mm_cone_size", c_mm_cone_size = 0.05);
  DeclareProperty("min_mll"     , c_min_mll      = 12000);
}

// ----------------------------------------------------------------------------
SelectionTools::ObjectCleaningTool::~ObjectCleaningTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::fullObjectCleaning(
    ElectronContainer& electrons,
    MuonContainer& muons,
    TauContainer& taus,
    JetContainer& jets)
{
  std::vector<Electron*> good_electrons;
  std::vector<Muon*>     good_muons;
  std::vector<Tau*>      good_taus;
  std::vector<Jet*>      good_jets;
  std::vector<Jet*>      bad_jets;

  fullObjectCleaning( electrons.getElectrons(EL_BASELINE)
                    , muons.getMuons(MU_BASELINE)
                    , taus.getTaus(TAU_BASELINE)
                    , jets.getJets(JET_BASELINE_GOOD)
                    , jets.getJets(JET_BASELINE_BAD)
                    , good_electrons
                    , good_muons
                    , good_taus
                    , good_jets
                    , bad_jets
                    );

  // Set event description bits
  size_t el_term = good_electrons.size();
  for (size_t el_it = 0; el_it != el_term; ++el_it) {
    good_electrons.at(el_it)->getElectronDesc()->setPassGood(true);
  }
  size_t mu_term = good_muons.size();
  for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
    good_muons.at(mu_it)->getMuonDesc()->setPassGood(true);
  }
  size_t tau_term = good_taus.size();
  for (size_t tau_it = 0; tau_it != tau_term; ++tau_it) {
    good_taus.at(tau_it)->getTauDesc()->setPassGood(true);
  }
  size_t good_jet_term = good_jets.size();
  for (size_t jet_it = 0; jet_it != good_jet_term; ++jet_it) {
    good_jets.at(jet_it)->getJetDesc()->setPassGood(true);
  }
  size_t jet_term = bad_jets.size();
  for (size_t jet_it = 0; jet_it != jet_term; ++jet_it) {
    bad_jets.at(jet_it)->getJetDesc()->setPassBad(true);
  }

  // set collection lists
  electrons.setCollection(EL_GOOD , good_electrons);
  muons.setCollection(    MU_GOOD , good_muons    );
  taus.setCollection(     TAU_GOOD, good_taus     );
  jets.setCollection(     JET_GOOD, good_jets     );
  jets.setCollection(     JET_BAD , bad_jets      );
}

// ----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::fullObjectCleaning(
    const std::vector<Electron*>& input_electrons,
    const std::vector<Muon*>& input_muons,
    const std::vector<Tau*>& input_taus,
    const std::vector<Jet*>& input_jets_good,
    const std::vector<Jet*>& input_jets_bad,
    std::vector<Electron*>& output_electrons,
    std::vector<Muon*>& output_muons,
    std::vector<Tau*>& output_taus,
    std::vector<Jet*>& output_jets_good,
    std::vector<Jet*>& output_jets_bad)
{
  // do ee overlap removal
  std::vector<Electron*> el_temp_1;
  eeOverlapRemoval(input_electrons, el_temp_1);

  // do ej overlap removal
  std::vector<Jet*> jet_good_temp_1;
  std::vector<Jet*> jet_bad_temp_1;
  ejOverlapRemoval(el_temp_1, input_jets_good, jet_good_temp_1);
  ejOverlapRemoval(el_temp_1, input_jets_bad , jet_bad_temp_1 );

  // do et overlap removal
  std::vector<Tau*> tau_temp_1;
  etOverlapRemoval(el_temp_1, input_taus, tau_temp_1);

  // do mt overlap removal
  std::vector<Tau*> tau_temp_2;
  mtOverlapRemoval(input_muons, tau_temp_1, tau_temp_2);

  // do je overlap removal
  std::vector<Electron*> el_temp_2;
  std::vector<Electron*> el_temp_3;
  jeOverlapRemoval(el_temp_1, jet_good_temp_1, el_temp_2);
  jeOverlapRemoval(el_temp_2, jet_bad_temp_1 , el_temp_3);

  // do jm overlap removal
  std::vector<Muon*> mu_temp_1;
  std::vector<Muon*> mu_temp_2;
  jmOverlapRemoval(jet_good_temp_1, input_muons, mu_temp_1);
  jmOverlapRemoval(jet_bad_temp_1 , mu_temp_1  , mu_temp_2);

  // do em overlap removal
  std::vector<Electron*> el_temp_4;
  std::vector<Muon*> mu_temp_3;
  emOverlapRemoval(el_temp_3, mu_temp_2, el_temp_4, mu_temp_3);

  // do mm overlap removal
  std::vector<Muon*> mu_temp_4;
  mmOverlapRemoval(mu_temp_3, mu_temp_4);

  // do SFOS mll cut
  std::vector<Electron*> el_temp_5;
  std::vector<Muon*> mu_temp_5;
  mllOverlapRemoval(el_temp_4, mu_temp_4, el_temp_5, mu_temp_5);

  // do tj overlap removal
  std::vector<Jet*> jet_good_temp_2;
  std::vector<Jet*> jet_bad_temp_2;
  tjOverlapRemoval(tau_temp_2, jet_good_temp_1, jet_good_temp_2);
  tjOverlapRemoval(tau_temp_2, jet_bad_temp_1 , jet_bad_temp_2 );

  output_electrons = el_temp_5;
  output_jets_good = jet_good_temp_2;
  output_jets_bad  = jet_bad_temp_2;
  output_muons     = mu_temp_5;
  output_taus      = tau_temp_2;

  // std::cout << "-----------------------------\n"
  //           << "taus before OLR: " << input_taus.size() << "\n"
  //           << "taus after el OLR: " << tau_temp_1.size() << "\n"
  //           << "taus after mu OLR: " << tau_temp_2.size() << "\n"
  //           << "taus after all OLR: " << output_taus.size() << "\n"
  //           << "\n";
}

// ----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::eeOverlapRemoval(
    const std::vector<Electron*>& input_electrons,
    std::vector<Electron*>& output_electrons)
{
  // prep output electron vector
  output_electrons.clear();
  output_electrons.reserve(input_electrons.size());

  // vector to flag objects to keep
  std::vector<bool> keep_object(input_electrons.size(), true);

  // Loop over all combinations of two electrons, checking for overlap
  size_t term = input_electrons.size();
  for (size_t el_it_1 = 0; el_it_1 != term; ++el_it_1) {
    TLorentzVector tlv1 = input_electrons.at(el_it_1)->getTlv();

    for (size_t el_it_2 = 0; el_it_2 != el_it_1; ++el_it_2) {
      TLorentzVector tlv2 = input_electrons.at(el_it_2)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, c_ee_cone_size)) {
        keep_object.at(el_it_1) = false;
        keep_object.at(el_it_2) = false;
      }
    }
  }

  // add to output electrons flagged as "to keep"
  for (size_t el_it = 0; el_it != term; ++el_it) {
    if (keep_object.at(el_it)) {
      output_electrons.push_back(input_electrons.at(el_it));
    }
  }
}

// ----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::ejOverlapRemoval(
    const std::vector<Electron*>& input_electrons,
    const std::vector<Jet*>& input_jets,
    std::vector<Jet*>& output_jets)
{
  // prep output electron vector
  output_jets.clear();
  output_jets.reserve(input_jets.size());

  // vector to flag objects to keep
  std::vector<bool> keep_object(input_jets.size(), true);

  // Loop over all combinations of jet/electron, checking for overlap
  size_t el_term = input_electrons.size();
  size_t jet_term = input_jets.size();
  for (size_t el_it = 0; el_it != el_term; ++el_it) {
    TLorentzVector tlv1 = input_electrons.at(el_it)->getTlv();

    for (size_t jet_it = 0; jet_it != jet_term; ++jet_it) {
      TLorentzVector tlv2 = input_jets.at(jet_it)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, c_ej_cone_size)) {
        keep_object.at(jet_it) = false;
      }
    }
  }

  // add to output electrons flagged as "to keep"
  for (size_t jet_it = 0; jet_it != jet_term; ++jet_it) {
    if (keep_object.at(jet_it)) {
      output_jets.push_back(input_jets.at(jet_it));
    }
  }
}

// -----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::etOverlapRemoval(
    const std::vector<Electron*>& input_electrons,
    const std::vector<Tau*>& input_taus,
    std::vector<Tau*>& output_taus)
{
  // prep output tau vector
  output_taus.clear();
  output_taus.reserve(input_taus.size());

  //vector to flag objects to keep
  std::vector<bool> keep_object(input_taus.size(), true);

  // Loop over all combinations of electron/taus, checking for overlap
  size_t el_term = input_electrons.size();
  size_t tau_term = input_taus.size();
  for (size_t el_it = 0; el_it != el_term; ++el_it) {
    TLorentzVector tlv1 = input_electrons.at(el_it)->getTlv();

    for (size_t tau_it = 0; tau_it != tau_term; ++tau_it) {
      TLorentzVector tlv2 = input_taus.at(tau_it)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, c_et_cone_size)) {
        keep_object.at(tau_it) = false;
      }
    }
  }

  // add to output taus flagged as "to keep"
  for (size_t tau_it = 0; tau_it != tau_term; ++tau_it) {
    if (keep_object.at(tau_it)) {
      output_taus.push_back(input_taus.at(tau_it));
    }
  }
}

// -----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::mtOverlapRemoval(
    const std::vector<Muon*>& input_muons,
    const std::vector<Tau*>& input_taus,
    std::vector<Tau*>& output_taus)
{
  // prep output tau vector
  output_taus.clear();
  output_taus.reserve(input_taus.size());

  //vector to flag objects to keep
  std::vector<bool> keep_object(input_taus.size(), true);

  // Loop over all combinations of muon/taus, checking for overlap
  size_t mu_term = input_muons.size();
  size_t tau_term = input_taus.size();
  for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
    TLorentzVector tlv1 = input_muons.at(mu_it)->getTlv();

    for (size_t tau_it = 0; tau_it != tau_term; ++tau_it) {
      TLorentzVector tlv2 = input_taus.at(tau_it)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, c_et_cone_size)) {
        keep_object.at(tau_it) = false;
      }
    }
  }

  // add to output taus flagged as "to keep"
  for (size_t tau_it = 0; tau_it != tau_term; ++tau_it) {
    if (keep_object.at(tau_it)) {
      output_taus.push_back(input_taus.at(tau_it));
    }
  }
}

// ----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::tjOverlapRemoval(
    const std::vector<Tau*>& input_taus,
    const std::vector<Jet*>& input_jets,
    std::vector<Jet*>& output_jets)
{
  // prep output electron vector
  output_jets.clear();
  output_jets.reserve(input_jets.size());

  // vector to flag objects to keep
  std::vector<bool> keep_object(input_jets.size(), true);

  // Loop over all combinations of jet/electron, checking for overlap
  size_t tau_term = input_taus.size();
  size_t jet_term = input_jets.size();
  for (size_t tau_it = 0; tau_it != tau_term; ++tau_it) {
    TLorentzVector tlv1 = input_taus.at(tau_it)->getTlv();

    for (size_t jet_it = 0; jet_it != jet_term; ++jet_it) {
      TLorentzVector tlv2 = input_jets.at(jet_it)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, c_tj_cone_size)) {
        keep_object.at(jet_it) = false;
      }
    }
  }

  // add to output electrons flagged as "to keep"
  for (size_t jet_it = 0; jet_it != jet_term; ++jet_it) {
    if (keep_object.at(jet_it)) {
      output_jets.push_back(input_jets.at(jet_it));
    }
  }
}

// ----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::jeOverlapRemoval(
    const std::vector<Electron*>& input_electrons,
    const std::vector<Jet*>& input_jets,
    std::vector<Electron*>& output_electrons)
{
  // prep output electron vector
  output_electrons.clear();
  output_electrons.reserve(input_electrons.size());

  // vector to flag objects to keep
  std::vector<bool> keep_object(input_electrons.size(), true);

  // Loop over all combinations of jet/electron, checking for overlap
  size_t el_term = input_electrons.size();
  size_t jet_term = input_jets.size();
  for (size_t jet_it = 0; jet_it != jet_term; ++jet_it) {
    TLorentzVector tlv1 = input_jets.at(jet_it)->getTlv();

    for (size_t el_it = 0; el_it != el_term; ++el_it) {
      TLorentzVector tlv2 = input_electrons.at(el_it)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, c_je_cone_size)) {
        keep_object.at(el_it) = false;
      }
    }
  }

  // add to output electrons flagged as "to keep"
  for (size_t el_it = 0; el_it != el_term; ++el_it) {
    if (keep_object.at(el_it)) {
      output_electrons.push_back(input_electrons.at(el_it));
    }
  }
}

// ----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::jmOverlapRemoval(
    const std::vector<Jet*>& input_jets,
    const std::vector<Muon*>& input_muons,
    std::vector<Muon*>& output_muons)
{
  // prep output electron vector
  output_muons.clear();
  output_muons.reserve(input_muons.size());

  // vector to flag objects to keep
  std::vector<bool> keep_object(input_muons.size(), true);

  // Loop over all combinations of jet/muons, checking for overlap
  size_t jet_term = input_jets.size();
  size_t mu_term = input_muons.size();
  for (size_t jet_it = 0; jet_it != jet_term; ++jet_it) {
    TLorentzVector tlv1 = input_jets.at(jet_it)->getTlv();

    for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
      TLorentzVector tlv2 = input_muons.at(mu_it)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, c_jm_cone_size)) {
        keep_object.at(mu_it) = false;
      }
    }
  }

  // add to output electrons flagged as "to keep"
  for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
    if (keep_object.at(mu_it)) {
      output_muons.push_back(input_muons.at(mu_it));
    }
  }
}

// ----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::emOverlapRemoval(
    const std::vector<Electron*>& input_electrons,
    const std::vector<Muon*>& input_muons,
    std::vector<Electron*>& output_electrons,
    std::vector<Muon*>& output_muons)
{
  // prep output vectors
  output_electrons.clear();
  output_muons.clear();

  output_electrons.reserve(input_electrons.size());
  output_muons.reserve(input_muons.size());

  // vector to flag objects to keep
  std::vector<bool> keep_el(input_electrons.size(), true);
  std::vector<bool> keep_mu(input_muons.size(), true);

  // Loop over all combinations of electrons/muons, checking for overlap
  size_t el_term = input_electrons.size();
  size_t mu_term = input_muons.size();
  for (size_t el_it = 0; el_it != el_term; ++el_it) {
    TLorentzVector tlv1 = input_electrons.at(el_it)->getTlv();

    for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
      TLorentzVector tlv2 = input_muons.at(mu_it)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, c_em_cone_size)) {
        keep_el.at(el_it) = false;
        keep_mu.at(mu_it) = false;
      }
    }
  }

  // add to output electrons/muons flagged as "to keep"
  for (size_t el_it = 0; el_it != el_term; ++el_it) {
    if (keep_el.at(el_it)) {
      output_electrons.push_back(input_electrons.at(el_it));
    }
  }
  for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
    if (keep_mu.at(mu_it)) {
      output_muons.push_back(input_muons.at(mu_it));
    }
  }
}

// ----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::mmOverlapRemoval(
    const std::vector<Muon*>& input_muons,
    std::vector<Muon*>& output_muons)
{
  // prep output muon vector
  output_muons.clear();
  output_muons.reserve(input_muons.size());

  // vector to flag objects to keep
  std::vector<bool> keep_object(input_muons.size(), true);

  // Loop over all combinations of two muons, checking for overlap
  size_t term = input_muons.size();
  for (size_t mu_it_1 = 0; mu_it_1 != term; ++mu_it_1) {
    TLorentzVector tlv1 = input_muons.at(mu_it_1)->getTlv();

    for (size_t mu_it_2 = 0; mu_it_2 != mu_it_1; ++mu_it_2) {
      TLorentzVector tlv2 = input_muons.at(mu_it_2)->getTlv();

      // if overlap, flag for removal
      if (overlap(tlv1, tlv2, c_mm_cone_size)) {
        keep_object.at(mu_it_1) = false;
        keep_object.at(mu_it_2) = false;
      }
    }
  }

  // add to output muons flagged as "to keep"
  for (size_t mu_it = 0; mu_it != term; ++mu_it) {
    if (keep_object.at(mu_it)) {
      output_muons.push_back(input_muons.at(mu_it));
    }
  }
}

// ----------------------------------------------------------------------------
void SelectionTools::ObjectCleaningTool::mllOverlapRemoval(
    const std::vector<Electron*>& input_electrons,
    const std::vector<Muon*>& input_muons,
    std::vector<Electron*>& output_electrons,
    std::vector<Muon*>& output_muons)
{
  // prep output vectors
  output_electrons.clear();
  output_muons.clear();

  output_electrons.reserve(input_electrons.size());
  output_muons.reserve(input_electrons.size());

  std::vector<bool> keep_el(input_electrons.size(), true);
  std::vector<bool> keep_mu(input_muons.size(), true);

  // Loop over electron combinations, checking for SFOS pairs
  size_t el_term = input_electrons.size();
  for (size_t el_it_1 = 0; el_it_1 != el_term; ++el_it_1) {
    float charge_1 = input_electrons.at(el_it_1)->charge();
    TLorentzVector tlv1 = input_electrons.at(el_it_1)->getTlv();
    for (size_t el_it_2 = 0; el_it_2 != el_it_1; ++el_it_2) {
      float charge_2 = input_electrons.at(el_it_2)->charge();
      if (charge_1 * charge_2 < 0) {
        TLorentzVector tlv2 = input_electrons.at(el_it_2)->getTlv();
        if ((tlv1+tlv2).Mag() < c_min_mll) {
          keep_el.at(el_it_1) = false;
          keep_el.at(el_it_2) = false;
        }
      }
    }
  }

  // Loop over muon combinations, checking for SFOS pairs
  size_t mu_term = input_muons.size();
  for (size_t mu_it_1 = 0; mu_it_1 != mu_term; ++mu_it_1) {
    float charge_1 = input_muons.at(mu_it_1)->charge();
    TLorentzVector tlv1 = input_muons.at(mu_it_1)->getTlv();
    for (size_t mu_it_2 = 0; mu_it_2 != mu_it_1; ++mu_it_2) {
      float charge_2 = input_muons.at(mu_it_2)->charge();
      if (charge_1 * charge_2 < 0) {
        TLorentzVector tlv2 = input_muons.at(mu_it_2)->getTlv();
        if ((tlv1+tlv2).Mag() < c_min_mll) {
          keep_mu.at(mu_it_1) = false;
          keep_mu.at(mu_it_2) = false;
        }
      }
    }
  }

  // add to output electrons flagged as "to keep"
  for (size_t el_it = 0; el_it != el_term; ++el_it) {
    if (keep_el.at(el_it)) {
      output_electrons.push_back(input_electrons.at(el_it));
    }
  }
  // add to output muons flagged as "to keep"
  for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
    if (keep_mu.at(mu_it)) {
      output_muons.push_back(input_muons.at(mu_it));
    }
  }
}

// ----------------------------------------------------------------------------
bool SelectionTools::ObjectCleaningTool::overlap( TLorentzVector& tlv1
                                                , TLorentzVector& tlv2
                                                , double dr_max
                                                )
{
  double dr = tlv1.DeltaR(tlv2);
  return (dr < dr_max);
}
