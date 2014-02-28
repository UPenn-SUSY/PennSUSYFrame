#ifndef PennSusyFrame_TruthMatchTools_h
#define PennSusyFrame_TruthMatchTools_h

// =============================================================================
#include <vector>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
namespace PennSusyFrame
{
  class Event;
  class Electron;
  class Muon;
  class MCTruth;
}

class RecoTruthMatch;
class TLorentzVector;

// =============================================================================
namespace PennSusyFrame
{
  // ===========================================================================
  class TruthMatchTool
  {
    // -------------------------------------------------------------------------
    public:
      TruthMatchTool();
      ~TruthMatchTool();

      void clear();
      void prep(const PennSusyFrame::MCTruth&);

      int getIndex(const TLorentzVector* tlv);

      bool isRealLeptonEvent( FLAVOR_CHANNEL
                            , const std::vector<PennSusyFrame::Electron*>*
                            , const std::vector<PennSusyFrame::Muon*>*
                            , const PennSusyFrame::MCTruth&
                            );
      bool isRealElectron(const PennSusyFrame::Electron*);
      bool isRealMuon( const PennSusyFrame::Muon*
                     , const PennSusyFrame::MCTruth&
                     );

      SIGN_CHANNEL getTruthSign( FLAVOR_CHANNEL
                               , const std::vector<PennSusyFrame::Electron*>*
                               , const std::vector<PennSusyFrame::Muon*>*
                               , const PennSusyFrame::MCTruth&
                               );
      float getTruthElectronSign( const PennSusyFrame::Electron*
                                , const PennSusyFrame::MCTruth&
                                );
      float getTruthMuonSign( const PennSusyFrame::Muon*
                            , const PennSusyFrame::MCTruth&
                            );

      int getParentBarcodeElectron( const PennSusyFrame::Electron*
                                  , const PennSusyFrame::MCTruth&
                                  );
      int getParentBarcodeMuon( const PennSusyFrame::Muon*
                              , const PennSusyFrame::MCTruth&
                              );

    // -------------------------------------------------------------------------
    private:
      int matchBarcode( int barcode_to_match
                      , const std::vector<int>* list_of_barcodes
                      );

      RecoTruthMatch* m_truth_match;
  };
}

#endif
