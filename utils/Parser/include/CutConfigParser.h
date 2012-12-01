#ifndef CutConfigParser_h
#define CutConfigParser_h

#include <stdlib.h>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "ParseDriver.h"

#include "Selection/include/EventSelection.h"
#include "SusyAnalysisTools/include/EventDescription.h"

// =============================================================================
class CutConfigParser : public ParseDriver
{
  // -----------------------------------------------------------------------------
  public:
    CutConfigParser(std::string);
    virtual ~CutConfigParser();

    std::map<std::string, Selection::EventSelection> getSelectionMap();

  // -----------------------------------------------------------------------------
  private:
    void clear();
    virtual void addLine(std::vector<std::string>);
    void configEventSelection();

    FLAVOR_CHANNEL stringToFlavor(std::string);
    SIGN_CHANNEL   stringToSign(std::string);

    bool m_in_block;
    std::string m_name;
    SusyAnalysisTools::EventDescription m_pass_event;
    SusyAnalysisTools::EventDescription m_reverse_event;
    SusyAnalysisTools::SRHelper m_pass_sr;
    SusyAnalysisTools::SRHelper m_reverse_sr;

    std::map<std::string, Selection::EventSelection> m_event_selection;
};

#endif
