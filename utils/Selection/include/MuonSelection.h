/*
#ifndef Selection_MuonSelection_h
#define Selection_MuonSelection_h
// ============================================================================
#include "ObjectDefs/include/SusyDataTypes.h"
#include "ObjectDefs/include/Muon.h"

// ============================================================================
namespace Selection
{
  // ============================================================================
  class MuonSelection
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    MuonSelection();
    MuonSelection( SusyAnalysisTools::muon_description pass_word
                 , SusyAnalysisTools::muon_description reverse_word
                 );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passMuon(Muon&) const;

    bool passD0Cut(Muon&) const;
    bool passD0SigCut(Muon&) const;
    bool passZ0Cut(Muon&) const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void enable();
    void disable();
    void setMuNum(unsigned int  pass, unsigned int reverse);
    void setCombined(       bool pass, bool reverse);
    void setTag(            bool pass, bool reverse);
    void setLoose(          bool pass, bool reverse);
    void setZ0Cut(         bool pass, bool reverse);
    void setD0Cut(         bool pass, bool reverse);
    void setAbsTrackIsoCut(bool pass, bool reverse);
    void setAbsCaloIsoCut( bool pass, bool reverse);
    void setRelTrackIsoCut(bool pass, bool reverse);
    void setRelCaloIsoCut( bool pass, bool reverse);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void setD0CutValue(double min = -999, double max = -999);
    void setD0SigCutValue(double min = -999, double max = -999);
    void setZ0CutValue(double min = -999, double max = -999);

// ----------------------------------------------------------------------------
  private:
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool m_enabled;

    SusyAnalysisTools::muon_description m_pass_cut_word;
    SusyAnalysisTools::muon_description m_reverse_cut_word;

    double m_d0_cut_min;
    double m_d0_cut_max;

    double m_d0sig_cut_min;
    double m_d0sig_cut_max;

    double m_z0_cut_min;
    double m_z0_cut_max;
  };
}

#endif
*/
