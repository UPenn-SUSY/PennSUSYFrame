#ifndef PennSusyFrame_BMinusLUtils_h
#define PennSusyFrame_BMinusLUtils_h

// =============================================================================
#include <vector>

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
      void setSameParent(bool val) { m_same_parent = val; }

      PennSusyFrame::Jet*    getJet()    const { return m_jet; }
      PennSusyFrame::Lepton* getLepton() const { return m_lep; }
      float getMbl()  const { return m_mbl;  }
      float getPtbl() const { return m_ptbl; }
      bool  getSameParent() const { return m_same_parent; }
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

  // ---------------------------------------------------------------------------
  // match jet to b quark and return the mc index
  int matchJetToBQuark( const PennSusyFrame::Jet*
                      , const PennSusyFrame::MCTruth&
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
}

#endif
