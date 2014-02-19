#ifndef PennSusyFrame_BMinusLCalculators_h
#define PennSusyFrame_BMinusLCalculators_h

// =============================================================================
namespace PennSusyFrame
{
  class Jet;
  class Lepton;
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

      PennSusyFrame::Jet*    getJet()    { return m_jet;    }
      PennSusyFrame::Lepton* getLepton() { return m_lep; }

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      PennSusyFrame::Jet*    m_jet;
      PennSusyFrame::Lepton* m_lep;
  };

}

#endif
