#ifndef CommonTools_ChargeFlipScaleFactorTool_h
#define CommonTools_ChargeFlipScaleFactorTool_h

#include <vector>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Jet.h"

#include "ChargeFlip/chargeFlip.h"
#include "LeptonTruthTools/RecoTruthMatch.h"
#include "D3PDObjects/include/TruthD3PDObject.h"

// =============================================================================
namespace CommonTools
{
  // ===========================================================================
  class ChargeFlipScaleFactorTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ChargeFlipScaleFactorTool(SCycleBase* parent, const char* name);
    ~ChargeFlipScaleFactorTool();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void clear();
    double getSF(int pdg_1,TLorentzVector* tlv_1, int pdg_2, TLorentzVector* tlv_2, TVector2* met_vector, const D3PDReader::TruthD3PDObject& mc, int syst);
    void BeginCycle();
    void PrepTruth(const D3PDReader::TruthD3PDObject& mc);

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool c_do_charge_flip_sf;

    std::string c_path_to_flip_map;

    double m_charge_flip_sf;
    bool m_is_cached;
    bool m_truth_prepped;


    RecoTruthMatch* m_reco_truth_match;

    chargeFlip* m_charge_flip;

    std::vector<vector<int> > stripConstVector(const std::vector<vector<int> >&);

    template<class T>
    std::vector<T> stripConst(const std::vector<T>&);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(ChargeFlipScaleFactorTool, 0);
  };
} // CommonTools

#ifndef __CINT__
#include "ChargeFlipScaleFactorTool.icc"
#endif // __CINT__



#endif // CommonTools_ChargeFlipScaleFactorTool_h



