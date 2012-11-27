#ifndef Selection_EventSelection_h
#define Selection_EventSelection_h

// ============================================================================
#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
// #include "SusyAnalysisTools/include/Event.h"
// #include "SusyAnalysisTools/include/MET.h"
// #include "SusyAnalysisTools/include/Jet.h"

// ============================================================================
namespace Selection
{
  // ============================================================================
  class EventSelection : public SusyAnalysisTools::EventDescription
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    EventSelection();
    EventSelection( SusyAnalysisTools::EventDescription pass_event_word
                  , SusyAnalysisTools::EventDescription reverse_event_word
                  );
    EventSelection( SusyAnalysisTools::EventDescription pass_event_word
                  , SusyAnalysisTools::EventDescription reverse_event_word
                  , SusyAnalysisTools::SRHelper         pass_sr_word
                  , SusyAnalysisTools::SRHelper         reverse_sr_word
                  );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    SusyAnalysisTools::EventDescription* getPassEventWord();
    SusyAnalysisTools::EventDescription* getReverseEventWord();

    SusyAnalysisTools::SRHelper* getPassSRWord();
    SusyAnalysisTools::SRHelper* getReverseSRWord();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passEvent( const SusyAnalysisTools::EventDescription&
                  , const SusyAnalysisTools::SRHelper&
                  ) const;

    // bool passMllCut(Event& ) const;
    // bool passMetCut(MET& ) const;
    // bool passMt2Cut(Event& ) const;
    // bool passJetPtCut(std::vector<Jet>& ) const;

    // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // void setMllCutValue(double min = -999, double max = -999);
    // void setMetCutValue(double min = -999, double max = -999,
    //     MET::MET_VAR = MET::REL_ET, MET::MET_COLLECTION = MET::PHYSICS);
    // void setMt2CutValue(double min = -999, double max = -999);
    // void setJetPtCutValue(double min = -999, double max = -999);

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    SusyAnalysisTools::EventDescription m_pass_event_word;
    SusyAnalysisTools::EventDescription m_reverse_event_word;

    SusyAnalysisTools::SRHelper m_pass_sr_word;
    SusyAnalysisTools::SRHelper m_reverse_sr_word;

    // double m_mll_cut_min;
    // double m_mll_cut_max;

    // MET::MET_COLLECTION m_met_collection;
    // MET::MET_VAR m_met_var;
    // double m_met_cut_min;
    // double m_met_cut_max;

    // double m_met_rel_cut_min;
    // double m_met_rel_cut_max;

    // double m_mt2_cut_min;
    // double m_mt2_cut_max;

    // double m_jet_pt_cut_min;
    // double m_jet_pt_cut_max;
  };
}

#endif
