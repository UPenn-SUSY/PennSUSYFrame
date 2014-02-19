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

      void  setJet(PennSusyFrame::Jet*    jet) { m_jet = jet; }
      void  setLep(PennSusyFrame::Lepton* lep) { m_lep = lep; }

      PennSusyFrame::Jet*    getJet()    const { return m_jet; }
      PennSusyFrame::Lepton* getLepton() const { return m_lep; }
      float getMbl()  const { return m_mbl;  }
      float getPtbl() const { return m_ptbl; }

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      PennSusyFrame::Jet*    m_jet;
      PennSusyFrame::Lepton* m_lep;

      float m_mbl;
      float m_ptbl;
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
}

#endif
