// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_TruthMatchTool_H
#define CommonTools_TruthMatchTool_H

// =============================================================================
#include <vector>
#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Electron;
class Muon;
class RecoTruthMatch;

namespace D3PDReader
{
  class MuonTruthD3PDObject;
  class TruthD3PDObject;
}

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

    int matchBarcode( int barcode_to_match
		      , const std::vector<int>* list_of_barcodes
		      );
    int getIndex(TLorentzVector tlv);

  // ---------------------------------------------------------------------------
  private:


    RecoTruthMatch* m_truth_match;

    bool m_cached;
    bool m_is_real_lepton_event;
  };

}

#endif
