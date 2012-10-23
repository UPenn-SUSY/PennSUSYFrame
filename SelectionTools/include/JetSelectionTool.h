// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_JetSelectionTool_h
#define SelectionTools_JetSelectionTool_h

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class JetSelectionTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    JetSelectionTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~JetSelectionTool();

    bool isBaseline(Jet*);
    bool isLJet(Jet*);
    bool isBJet(Jet*);
    bool isFJet(Jet*);
    bool isBadJet(Jet*);

    // std::vector<Jet*> getBaselineJets(const JetContainer&);
    // std::vector<Jet*> getBaselineJets(
    //     std::vector<Jet*> all_jets);

    // std::vector<Jet*> getLJets(const JetContainer&);
    // std::vector<Jet*> getLJets(
    //     std::vector<Jet*> good_jets);

    // std::vector<Jet*> getBJets(const JetContainer&);
    // std::vector<Jet*> getBJets(
    //     std::vector<Jet*> good_jets);

    // std::vector<Jet*> getFJets(const JetContainer&);
    // std::vector<Jet*> getFJets(
    //     std::vector<Jet*> good_jets);

    // std::vector<Jet*> getBadJets(const JetContainer&);
    // std::vector<Jet*> getBadJets(
    //     std::vector<Jet*> good_jets);

  // --------------------------------------------------------------------------
  private:
    // = user configurables =
    // baseline cut values
    double c_baseline_min_pt;
    double c_baseline_max_pt;

    double c_baseline_min_eta;
    double c_baseline_max_eta;

    // light-central jet cut values
    double c_light_min_pt;
    double c_light_max_pt;

    double c_light_min_eta;
    double c_light_max_eta;

    double c_light_min_jvf;
    double c_light_max_jvf;

    double c_light_min_mv1;
    double c_light_max_mv1;

    // central b jet cut values
    double c_b_min_pt;
    double c_b_max_pt;

    double c_b_min_eta;
    double c_b_max_eta;

    double c_b_min_mv1;
    double c_b_max_mv1;

    // forward jet cut values
    double c_forward_min_pt;
    double c_forward_max_pt;

    double c_forward_min_eta;
    double c_forward_max_eta;

    bool passCut(double test, double min, double max);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(JetSelectionTool, 0);
  };
}

#endif
