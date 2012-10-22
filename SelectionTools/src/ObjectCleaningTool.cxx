#include <math.h>
#include "include/ObjectCleaningTool.h"

// ----------------------------------------------------------------------------
SelectionTools::ObjectCleaningTool::ObjectCleaningTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  // DeclareProperty("signal_max_etcone_cut", c_signal_max_etcone_cut = 0.18);
  DeclareProperty("ee_cone_size", c_ee_cone_size = 0.10);
  DeclareProperty("ej_cone_size", c_ej_cone_size = 0.20);
  DeclareProperty("je_cone_size", c_je_cone_size = 0.40);
  DeclareProperty("jm_cone_size", c_jm_cone_size = 0.40);
  DeclareProperty("em_cone_size", c_em_cone_size = 0.10);
  DeclareProperty("mm_cone_size", c_mm_cone_size = 0.05);
  DeclareProperty("min_mll"     , c_min_mll      = 12e3);
}

// ----------------------------------------------------------------------------
SelectionTools::ObjectCleaningTool::~ObjectCleaningTool()
{
  // do nothing
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
        if ((tlv1+tlv2).Mag() > c_min_mll) {
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
        if ((tlv1+tlv2).Mag() > c_min_mll) {
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

