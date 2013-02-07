#ifndef CommonTools_ChargeFlipScaleFactorTool_h
#define CommonTools_ChargeFlipScaleFactorTool_h

// =============================================================================
#include <vector>
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "CommonTools/include/TruthMatchTool.h"
#include "SusyAnalysisTools/include/SusyEnums.h"
#include "ChargeFlip/chargeFlip.h"

// =============================================================================
class Electron;
class Muon;
class Met;

namespace CommonTools
{
  class TruthMatchTool;
}
namespace D3PDReader
{
  class TruthD3PDObject;
  class MuonTruthD3PDObject;
}

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
    double getSF(FLAVOR_CHANNEL flavor_channel
		 , const std::vector<Electron*>& el
		 , const std::vector<Muon*>& mu
		 , const Met* met
		 , int syst);

    SIGN_CHANNEL getTruthSign( FLAVOR_CHANNEL flavor_channel
			     , const std::vector<Electron*>& el
			     , const std::vector<Muon*>& mu
			     , const D3PDReader::TruthD3PDObject* mc
			     , const D3PDReader::MuonTruthD3PDObject* mu_truth
			     , TruthMatchTool* truth_match_tool );

    void BeginCycle();

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool c_do_charge_flip_sf;

    std::string c_path_to_flip_map;

    double m_charge_flip_sf;
    bool m_is_cached;
    bool m_truth_prepped;

    float getTruthMuonSign(const Muon*, const D3PDReader::MuonTruthD3PDObject*);
    float getTruthElectronSign(Electron*, const D3PDReader::TruthD3PDObject*);

    TruthMatchTool* m_truth_match_tool;

    chargeFlip* m_charge_flip;

    std::vector<std::vector<int> > stripConstVector(const std::vector<std::vector<int> >&);

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



