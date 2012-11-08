// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_TruthMatchTool_H
#define CommonTools_TruthMatchTool_H
// =============================================================================

#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"

#include "D3PDObjects/include/TruthD3PDObject.h"
#include "D3PDObjects/include/MuonTruthD3PDObject.h"

#include "LeptonTruthTools/RecoTruthMatch.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
namespace CommonTools {
  // ===========================================================================
  class TruthMatchTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    TruthMatchTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~TruthMatchTool();

    void prep(const D3PDReader::TruthD3PDObject*);

    // TODO rewrite to handle MuonTruth objects rather than D3PD reader
    bool isRealLeptonEvent( FLAVOR_CHANNEL
                          , const std::vector<Electron*>&
                          , const std::vector<Muon*>&
                          , const D3PDReader::MuonTruthD3PDObject*
                          );
    bool isRealElectron(const Electron*);
    bool isRealMuon(const Muon*, const D3PDReader::MuonTruthD3PDObject*);

  // ---------------------------------------------------------------------------
  private:
    int matchBarcode( int barcode_to_match
                    , const vector<int>* list_of_barcodes
                    );

    RecoTruthMatch* m_truth_match;

    bool m_cached;
    bool m_is_real_lepton_event;
  };

}

#endif
