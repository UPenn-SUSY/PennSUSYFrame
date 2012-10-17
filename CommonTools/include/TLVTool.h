// Dear emacs, this is -*- c++ -*-
#ifndef TLVTool_H
#define TLVTool_H
// ============================================================================
#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/Jet.h"

//#include "CommonTools/include/EgammaEnergyRescaleTool.h"
//#include "CommonTools/include/JetCalibTool.h"
//#include "CommonTools/include/JetSmearingTool.h"
//#include "CommonTools/include/MuonMomentumSmearingTool.h"

// ============================================================================
class Electron;
class Muon;
class Jet;

// ============================================================================
namespace CommonTools{
// ============================================================================
  /**
  * Helper class to take two objects and compute the invariant mass of the
    pair system
  */
  class TLVTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    TLVTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~TLVTool();

    const TLorentzVector tlv(const Electron&);
    const TLorentzVector tlv(const Muon&);
    const TLorentzVector tlv( Jet&
                            , float mu
                            , int num_vetices_w_2_trks
                            );

    const TLorentzVector rawTlv(const Electron&);
    const TLorentzVector rawTlv(const Muon&);
    const TLorentzVector rawTlv(const Jet&);

  // --------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(TLVTool, 0);
  };
}

#endif
