#include "include/HistInfo.h"

// -----------------------------------------------------------------------------
HistInfo::HistInfo()
                  : m_var_exp("")
                  , m_x_num_bins(0)
                  , m_x_min(0)
                  , m_x_max(0)
                  , m_name("")
                  , m_title("")
                  , m_x_axis("")
                  , m_y_axis("")
                  , m_hist_cut("")
{
  // do nothing
}

// -----------------------------------------------------------------------------
HistInfo::HistInfo( std::string var_exp
                  , unsigned int x_num_bins
                  , float x_min
                  , float x_max
                  , std::string name
                  , std::string title
                  , std::string x_axis
                  , std::string y_axis
                  , std::string hist_cut
                  )
                  : m_var_exp(var_exp)
                  , m_x_num_bins(x_num_bins)
                  , m_x_min(x_min)
                  , m_x_max(x_max)
                  , m_name(name)
                  , m_title(title)
                  , m_x_axis(x_axis)
                  , m_y_axis(y_axis)
                  , m_hist_cut(hist_cut)
{
  // do nothing
  std::cout << "m_var_exp    - " << m_var_exp    << "\n";
  std::cout << "m_x_num_bins - " << m_x_num_bins << "\n";
  std::cout << "m_x_min      - " << m_x_min      << "\n";
  std::cout << "m_x_max      - " << m_x_max      << "\n";
  std::cout << "m_name       - " << m_name       << "\n";
  std::cout << "m_title      - " << m_title      << "\n";
  std::cout << "m_x_axis     - " << m_x_axis     << "\n";
  std::cout << "m_y_axis     - " << m_y_axis     << "\n";
  std::cout << "m_hist_cut   - " << m_hist_cut   << "\n";
}

// -----------------------------------------------------------------------------
HistInfo::HistInfo(const HistInfo& rhs) : m_var_exp(rhs.getVarExp())
                                        , m_x_num_bins(rhs.getNumXBins())
                                        , m_x_min(rhs.getXMin())
                                        , m_x_max(rhs.getXMax())
                                        , m_name(rhs.getName())
                                        , m_title(rhs.getTitle())
                                        , m_x_axis(rhs.getXAxis())
                                        , m_y_axis(rhs.getYAxis())
                                        , m_hist_cut(rhs.getHistCut())
{
  // do nothing
}


// -----------------------------------------------------------------------------
std::string HistInfo::getVarExp() const
{
  return m_var_exp;
}

// -----------------------------------------------------------------------------
unsigned int HistInfo::getNumXBins() const
{
  return m_x_num_bins;
}

// -----------------------------------------------------------------------------
float HistInfo::getXMin() const
{
  return m_x_min;
}

// -----------------------------------------------------------------------------
float HistInfo::getXMax() const
{
  return m_x_max;
}

// -----------------------------------------------------------------------------
std::string HistInfo::getName() const
{
  return m_name;
}

// -----------------------------------------------------------------------------
std::string HistInfo::getTitle() const
{
  return m_title;
}

// -----------------------------------------------------------------------------
std::string HistInfo::getXAxis() const
{
  return m_x_axis;
}

// -----------------------------------------------------------------------------
std::string HistInfo::getYAxis() const
{
  return m_y_axis;
}

// -----------------------------------------------------------------------------
std::string HistInfo::getHistCut() const
{
  return m_hist_cut;
}

// -----------------------------------------------------------------------------
TH1D* HistInfo::genHist(std::string key)
{
  TH1D* tmp = new TH1D( (m_name + "__" + key).c_str()
                 , (m_title + ";" + m_x_axis + ";" + m_y_axis).c_str()
                 , m_x_num_bins
                 , m_x_min
                 , m_x_max
                 );

  return tmp;
}
