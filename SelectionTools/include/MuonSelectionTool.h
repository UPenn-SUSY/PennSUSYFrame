// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_MuonSelectionTool_h
#define SelectionTools_MuonSelectionTool_h

// =============================================================================
#include <vector>
#include "AtlasSFrameUtils/include/ToolBase.h"

// =============================================================================
class Muon;
class MuonContainer;
class VertexContainer;

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class MuonSelectionTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    MuonSelectionTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~MuonSelectionTool();

    void process(Muon*, const VertexContainer&);
    bool isBaseline(Muon*);
    bool isSignal(Muon*);
    bool isCosmic(Muon*);
    bool isBad(Muon*);

    std::vector<Muon*> getBaselineMuons(const MuonContainer&);
    std::vector<Muon*> getBaselineMuons(
        const std::vector<Muon*>& all_muons);

    std::vector<Muon*> getSignalMuons( const MuonContainer&);
    std::vector<Muon*> getSignalMuons( const std::vector<Muon*>& good_muons);

    std::vector<Muon*> getCosmicMuons(const MuonContainer&);
    std::vector<Muon*> getCosmicMuons(
        const std::vector<Muon*>& all_muons);

    std::vector<Muon*> getBadMuons(const MuonContainer&);
    std::vector<Muon*> getBadMuons(
        const std::vector<Muon*>& all_muons);

  // --------------------------------------------------------------------------
  private:
    // = user configurables =
    // baseline cut values
    double c_baseline_min_pt;
    double c_baseline_max_pt;

    double c_baseline_min_eta;
    double c_baseline_max_eta;

    int c_baseline_min_b_layer_hits;
    int c_baseline_max_b_layer_hits;

    int c_baseline_min_pixel_hits;
    int c_baseline_max_pixel_hits;

    int c_baseline_min_sct_hits;
    int c_baseline_max_sct_hits;

    int c_baseline_min_si_holes;
    int c_baseline_max_si_holes;

    int c_baseline_min_trt_hits;
    int c_baseline_max_trt_hits;

    double c_baseline_min_trt_ol_fraction;
    double c_baseline_max_trt_ol_fraction;

    // signal cut values
    double c_signal_min_d0_sig;
    double c_signal_max_d0_sig;

    double c_signal_min_z0_sin_theta;
    double c_signal_max_z0_sin_theta;

    double c_signal_min_ptcone_cut;
    double c_signal_max_ptcone_cut;

    // cosmic muon cut values
    double c_cosmic_min_d0;
    double c_cosmic_max_d0;

    double c_cosmic_min_z0;
    double c_cosmic_max_z0;

    // bad muon cut values
    double c_bad_min_qoverp_ratio;
    double c_bad_max_qoverp_ratio;

    bool passCut(double test, double min, double max);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(MuonSelectionTool, 0);
  };
}

#endif
