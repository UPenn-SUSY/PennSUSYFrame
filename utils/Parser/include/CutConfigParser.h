#ifndef CutConfigParser_h
#define CutConfigParser_h

#include <stdlib.h>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "ParseDriver.h"

#include "Selection/include/EventSelection.h"
#include "Selection/include/WeightHandler.h"
#include "SusyAnalysisTools/include/EventDescription.h"

// =============================================================================
class CutConfigParser : public ParseDriver
{
  // -----------------------------------------------------------------------------
  public:
    CutConfigParser(std::string);
    CutConfigParser(std::string, const Selection::WeightHandler&);
    virtual ~CutConfigParser();

    void setGlobalWeightHandler(const Selection::WeightHandler&);

    std::map<std::string, Selection::EventSelection> getSelectionMap();
    std::map<std::string, Selection::WeightHandler>  getWeightMap();

  // -----------------------------------------------------------------------------
  private:
    void clear();
    virtual void addLine(std::vector<std::string>);
    void configEventSelection();

    FLAVOR_CHANNEL valueToFlavor(std::vector<std::string>);
    SIGN_CHANNEL   valueToSign(std::vector<std::string>);

    FLAVOR_CHANNEL stringToFlavor(std::string);
    SIGN_CHANNEL   stringToSign(std::string);

    bool m_in_block;
    std::string m_name;
    SusyAnalysisTools::EventDescription m_tmp_pass_event;
    SusyAnalysisTools::EventDescription m_tmp_reverse_event;
    SusyAnalysisTools::SRHelper m_tmp_pass_sr;
    SusyAnalysisTools::SRHelper m_tmp_reverse_sr;

    Selection::WeightHandler m_global_weight_handler;
    Selection::WeightHandler m_tmp_weight_handler;

    std::map<std::string, Selection::EventSelection> m_event_selection;
    std::map<std::string, Selection::WeightHandler>  m_weight_handler;
};

#endif
