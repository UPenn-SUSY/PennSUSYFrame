// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_TLVTool_H
#define CommonTools_TLVTool_H
// ============================================================================
#include "TLorentzVector.h"
#include "AtlasSFrameUtils/include/ToolBase.h"

// ============================================================================
// Forward declares
class Event;
class Electron;
class Muon;
class Jet;

namespace CommonTools{
  class EgammaEnergyRescaleTool;
  class MuonMomentumSmearingTool;
  class JetCalibTool;
}

// ============================================================================
namespace CommonTools{
// ============================================================================
  /**
  * Helper class to take two objects and compute the invariant mass of the
  * pair system
  */
  class TLVTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    TLVTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~TLVTool();

    void init( CommonTools::EgammaEnergyRescaleTool*
             , CommonTools::MuonMomentumSmearingTool*
             , CommonTools::JetCalibTool*
             );

    const TLorentzVector tlv(const Electron*);
    const TLorentzVector tlv(const Muon*);
    const TLorentzVector tlv( Jet*
                            , const Event* event
                            , int num_vetices_w_2_trks
                            );

    const TLorentzVector rawTlv(const Electron*);
    const TLorentzVector rawTlv(const Muon*);
    const TLorentzVector rawTlv(const Jet*);

  // --------------------------------------------------------------------------
  private:
    CommonTools::EgammaEnergyRescaleTool* m_egamma_energy_rescale;
    CommonTools::MuonMomentumSmearingTool* m_muon_smearing;
    CommonTools::JetCalibTool* m_jet_calib;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(TLVTool, 0);
  };
}

#endif
