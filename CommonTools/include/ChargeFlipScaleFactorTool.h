#ifndef CommonTools_ChargeFlipScaleFactorTool_h
#define CommonTools_ChargeFlipScaleFactorTool_h

#include <vector>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"

#include "ChargeFlip/chargeFlip.h"
#include "LeptonTruthTools/RecoTruthMatch.h"
#include "D3PDObjects/include/TruthD3PDObject.h"
#include "D3PDObjects/include/MuonTruthD3PDObject.h"

#include "CommonTools/include/TruthMatchTool.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

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
    // void PrepTruth(const D3PDReader::TruthD3PDObject* mc);

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool c_do_charge_flip_sf;

    std::string c_path_to_flip_map;

    double m_charge_flip_sf;
    bool m_is_cached;
    bool m_truth_prepped;

    float getTruthMuonSign(const Muon*, const D3PDReader::MuonTruthD3PDObject*);
    float getTruthElectronSign(const Electron*, const D3PDReader::TruthD3PDObject*);

    //RecoTruthMatch* m_reco_truth_match;
    TruthMatchTool* m_truth_match_tool;

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



