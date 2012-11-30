#ifndef CutConfigParser_h
#define CutConfigParser_h

#include <stdlib.h>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "ParseDriver.h"

#include "SusyAnalysisTools/include/EventDescription.h"

// =============================================================================
class CutConfigParser : public ParseDriver
{
  // -----------------------------------------------------------------------------
  public:
    CutConfigParser(std::string);

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
};

#endif
