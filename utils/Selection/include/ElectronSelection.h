/*
#ifndef Selection_ElectronSelection_h
#define Selection_ElectronSelection_h
// ============================================================================
#include "ObjectDefs/include/SusyDataTypes.h"
#include "ObjectDefs/include/Electron.h"

// ============================================================================
namespace Selection
{
  // ============================================================================
  class ElectronSelection
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ElectronSelection();
    ElectronSelection( SusyAnalysisTools::electron_description pass_word
                     , SusyAnalysisTools::electron_description reverse_word
                     );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passElectron(Electron&) const;

    bool passD0SigCut(Electron&) const;
    bool passZ0SinThetaCut(Electron&) const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void enable();
    void disable();
    void setElNum(unsigned int pass, unsigned int reverse);
    void setLoose(          bool pass, bool reverse);
    void setMedium(         bool pass, bool reverse);
    void setTight(          bool pass, bool reverse);
    void setLoosePP(        bool pass, bool reverse);
    void setMediumPP(       bool pass, bool reverse);
    void setTightPP(        bool pass, bool reverse);
    void setAbsTrackIsoCut(bool pass, bool reverse);
    void setAbsCaloIsoCut( bool pass, bool reverse);
    void setRelTrackIsoCut(bool pass, bool reverse);
    void setRelCaloIsoCut( bool pass, bool reverse);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void setD0SigCutValue(double min = -999, double max = -999);
    void setZ0SinThetaCutValue(double min = -999, double max = -999);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    SusyAnalysisTools::electron_description getPassDesc() const { return m_pass_cut_word; }
    SusyAnalysisTools::electron_description getReverseDesc() const { return m_reverse_cut_word; }
  // ----------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool m_enabled;

    SusyAnalysisTools::electron_description m_pass_cut_word;
    SusyAnalysisTools::electron_description m_reverse_cut_word;

    double m_d0sig_cut_min;
    double m_d0sig_cut_max;

    double m_z0sintheta_cut_min;
    double m_z0sintheta_cut_max;
  };
}

#endif
*/
