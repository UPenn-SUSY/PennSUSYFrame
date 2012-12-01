#ifndef HistConfigParser_h
#define HistConfigParser_h

#include <stdlib.h>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "ParseDriver.h"
#include "HistMaker/include/HistInfo.h"

// =============================================================================
class HistConfigParser : public ParseDriver
{
  // -----------------------------------------------------------------------------
  public:
    HistConfigParser(std::string);
    virtual ~HistConfigParser();

  // -----------------------------------------------------------------------------
  private:
    void clear();
    virtual void addLine(std::vector<std::string>);
    void configHistInfo();

    bool         m_in_block;
    std::string  m_name;
    std::string  m_var_exp;
    unsigned int m_x_bins;
    float        m_x_min;
    float        m_x_max;
    std::string  m_title;
    std::string  m_x_axis;
    std::string  m_y_axis;

    std::vector<HistInfo> m_hist_info;
};

#endif
