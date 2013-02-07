#ifndef Selection_EventSelection_h
#define Selection_EventSelection_h

// ============================================================================
#include <string>

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"

// ============================================================================
namespace Selection
{
  // ============================================================================
  class EventSelection
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
    void setPassEventWord(   const SusyAnalysisTools::EventDescription&);
    void setReverseEventWord(const SusyAnalysisTools::EventDescription&);

    void setPassSRWord(   const SusyAnalysisTools::SRHelper&);
    void setReverseSRWord(const SusyAnalysisTools::SRHelper&);

    void setAdditionalCutString(std::string);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    SusyAnalysisTools::EventDescription* getPassEventWord();
    SusyAnalysisTools::EventDescription* getReverseEventWord();

    SusyAnalysisTools::SRHelper* getPassSRWord();
    SusyAnalysisTools::SRHelper* getReverseSRWord();

    std::string getAdditionalCutString();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passEvent( const SusyAnalysisTools::EventDescription&
                  , const SusyAnalysisTools::SRHelper&
                  ) const;

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    SusyAnalysisTools::EventDescription m_pass_event_word;
    SusyAnalysisTools::EventDescription m_reverse_event_word;

    SusyAnalysisTools::SRHelper m_pass_sr_word;
    SusyAnalysisTools::SRHelper m_reverse_sr_word;

    std::string m_additional_cuts;
  };
}

#endif
