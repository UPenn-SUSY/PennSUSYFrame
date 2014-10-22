#ifndef PennSusyFrame_BMinusLUtils_h
#define PennSusyFrame_BMinusLUtils_h

// =============================================================================
#include <vector>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
// =============================================================================
namespace PennSusyFrame
{
  class Event;
  class Jet;
  class Lepton;
  class Electron;
  class Muon;
  class MCTruth;
}

// =============================================================================
namespace PennSusyFrame
{
  // ===========================================================================
  class blPair
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      blPair();
      blPair(PennSusyFrame::Jet*, PennSusyFrame::Lepton*);

      void calculate();

      void setJet(PennSusyFrame::Jet*    jet) { m_jet = jet; }
      void setLep(PennSusyFrame::Lepton* lep) { m_lep = lep; }
      void setSameParent(bool val)  { m_same_parent = val; }
      void setLepFromSusy(bool val) { m_lep_from_susy = val; }
      void setJetFromSusy(bool val) { m_jet_from_susy = val; }

      PennSusyFrame::Jet*    getJet()    const { return m_jet; }
      PennSusyFrame::Lepton* getLepton() const { return m_lep; }
      float getMbl()  const { return m_mbl;  }
      float getPtbl() const { return m_ptbl; }
      bool  getSameParent() const { return m_same_parent; }
      bool  getLepFromSusy() const { return m_lep_from_susy; }
      bool  getJetFromSusy() const { return m_jet_from_susy; }
      float getDphi() const;
      float getDeta() const;
      float getDr() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      PennSusyFrame::Jet*    m_jet;
      PennSusyFrame::Lepton* m_lep;

      float m_mbl;
      float m_ptbl;

      bool m_same_parent;
      bool m_lep_from_susy;
      bool m_jet_from_susy;
  };


  // ---------------------------------------------------------------------------
  bool doBLPairing( const PennSusyFrame::Event&
                  , const std::vector<PennSusyFrame::Electron*>*
                  , const std::vector<PennSusyFrame::Muon*>*
                  , const std::vector<PennSusyFrame::Jet*>*
                  , PennSusyFrame::blPair&
                  , PennSusyFrame::blPair&
                  );

  // ---------------------------------------------------------------------------
  bool doBLPairing( const std::vector<PennSusyFrame::Lepton*>*
                  , const std::vector<PennSusyFrame::Jet*>*
                  , PennSusyFrame::blPair& pair_0
                  , PennSusyFrame::blPair& pair_1
                  );

  // ---------------------------------------------------------------------------
  bool sameParent( const PennSusyFrame::Event&
                 , const PennSusyFrame::Lepton*
                 , const PennSusyFrame::Jet*
                 , const PennSusyFrame::MCTruth&
                 , bool verbose = false
                 );

  // -----------------------------------------------------------------------------
  int getLeptonParentIndex( const PennSusyFrame::Lepton*
                          , const PennSusyFrame::MCTruth&
                          );

  // -----------------------------------------------------------------------------
  int getLeptonParentPdgId( const PennSusyFrame::Lepton*
                          , const PennSusyFrame::MCTruth&
                          );

  // -----------------------------------------------------------------------------
  int getJetParentIndex( const PennSusyFrame::Jet*
                       , const PennSusyFrame::MCTruth&
                       );

  // -----------------------------------------------------------------------------
  int getJetParentIndex( const PennSusyFrame::Jet*
                       , const PennSusyFrame::MCTruth&
                       , float& return_dr_min
                       );

  // -----------------------------------------------------------------------------
  int getJetParentPdgId( const PennSusyFrame::Jet*
                       , const PennSusyFrame::MCTruth&
                       );

  // -----------------------------------------------------------------------------
  int getJetParentPdgId( const PennSusyFrame::Jet*
                       , const PennSusyFrame::MCTruth&
                       , float& return_dr_min
                       );

  // ---------------------------------------------------------------------------
  int connectTruthRecord( const PennSusyFrame::MCTruth&
                        , int broken_index
                        );

  // ---------------------------------------------------------------------------
  // match jet to b quark and return the mc index
  int matchJetToBQuark( const PennSusyFrame::Jet*
                      , const PennSusyFrame::MCTruth&
                      );
  int matchJetToBQuark( const PennSusyFrame::Jet*
                      , const PennSusyFrame::MCTruth&
                      , float& return_dr_min
                      );

  // ---------------------------------------------------------------------------
  // TODO move to truth match tools
  int getParticleIndex( int barcode
                      , const PennSusyFrame::MCTruth&
                      );

  // ---------------------------------------------------------------------------
  // TODO move to truth match tools
  int getParentIndex( int barcode
                    , const PennSusyFrame::MCTruth&
                    , bool verbose = false
                    );

  // ---------------------------------------------------------------------------
  bool isBHadron(int pdgid);

  // ---------------------------------------------------------------------------
  int getBarcodeFromIndex( int index
                         , const PennSusyFrame::MCTruth&
                         );

  // ---------------------------------------------------------------------------
  float calcMbbll( const PennSusyFrame::blPair&
                 , const PennSusyFrame::blPair&
                 );

  // ---------------------------------------------------------------------------
  float calcPtbbll( const PennSusyFrame::blPair&
                  , const PennSusyFrame::blPair&
                  );

  // ---------------------------------------------------------------------------
  FLAVOR_CHANNEL getTruthFC(const PennSusyFrame::MCTruth&);

  // ---------------------------------------------------------------------------
  double getFudgeKFactor(bool is_data, int dsid);
}

#endif
