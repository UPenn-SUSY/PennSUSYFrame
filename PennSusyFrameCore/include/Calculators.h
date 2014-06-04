#ifndef PennSusyFrame_Calculators_h
#define PennSusyFrame_Calculators_h

#include <vector>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
namespace PennSusyFrame
{
  class Electron;
  class Muon;
  class Jet;
  class Met;
}

// =============================================================================
namespace PennSusyFrame
{
  // ---------------------------------------------------------------------------
  // mll calculator
  double getMll( FLAVOR_CHANNEL
               , const std::vector<PennSusyFrame::Electron*>*
               , const std::vector<PennSusyFrame::Muon*>*
               );
  template <class T1, class T2>
    double calcMll(const T1*, const T2*);

  template <class T> double multiObjectMass(const std::vector<T*>&);

  // ---------------------------------------------------------------------------
  // ptll calculator
  double getPtll( FLAVOR_CHANNEL
                , const std::vector<PennSusyFrame::Electron*>*
                , const std::vector<PennSusyFrame::Muon*>*
                );
  template <class T1, class T2>
    double calcPtll(const T1*, const T2*);

  template <class T> double multiObjectPt(const std::vector<T*>&);

  // ---------------------------------------------------------------------------
  // mt2 calculator
  double getMt2( FLAVOR_CHANNEL
               , const PennSusyFrame::Met*
               , const std::vector<PennSusyFrame::Electron*>*
               , const std::vector<PennSusyFrame::Muon*>*
               , double minv = 0
               );

  template <class T1, class T2>
    double calcMt2(const T1*, const T2*, const Met*, double minv = 0);

  // ---------------------------------------------------------------------------
  // dphi_ll calculator
  double getDphill( FLAVOR_CHANNEL
                  , const std::vector<PennSusyFrame::Electron*>*
                  , const std::vector<PennSusyFrame::Muon*>*
                  );
  double calcDphi(double phi_0, double phi_1);

  // ---------------------------------------------------------------------------
  // emma mt calculator
  double getEmmaMt( FLAVOR_CHANNEL
                  , const std::vector<PennSusyFrame::Electron*>*
                  , const std::vector<PennSusyFrame::Muon*>*
                  );

  // ---------------------------------------------------------------------------
  // Compute Ht variable
  double getHt( const std::vector<PennSusyFrame::Electron*>*
              , const std::vector<PennSusyFrame::Muon*>*
              , const std::vector<PennSusyFrame::Jet*>*
              );
}

// Include the implementation:
#ifndef __CINT__
#include "Calculators.icc"
#endif // __CINT__

#endif
