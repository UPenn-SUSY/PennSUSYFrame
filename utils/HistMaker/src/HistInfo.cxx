#include "include/HistInfo.h"

// // -----------------------------------------------------------------------------
// HistInfo::HistInfo()
//                   : m_hist_type(HIST_1D)
//                   , m_var_exp("")
//                   , m_x_num_bins(0)
//                   , m_x_min(0)
//                   , m_x_max(0)
//                   , m_y_num_bins(0)
//                   , m_y_min(0)
//                   , m_y_max(0)
//                   , m_name("")
//                   , m_title("")
//                   , m_x_axis("")
//                   , m_y_axis("")
//                   , m_hist_cut("")
// {
//   // do nothing
// }

// -----------------------------------------------------------------------------
HistInfo::HistInfo( HIST_TYPE hist_type
                  , std::string var_exp
                  , unsigned int x_num_bins
                  , float x_min
                  , float x_max
                  , unsigned int y_num_bins
                  , float y_min
                  , float y_max
                  , std::string name
                  , std::string title
                  , std::string x_axis
                  , std::string y_axis
                  , std::string z_axis
                  , std::string hist_cut
                  )
                  : m_hist_type(hist_type)
                  , m_var_exp(var_exp)
                  , m_x_num_bins(x_num_bins)
                  , m_x_min(x_min)
                  , m_x_max(x_max)
                  , m_y_num_bins(y_num_bins)
                  , m_y_min(y_min)
                  , m_y_max(y_max)
                  , m_name(name)
                  , m_title(title)
                  , m_x_axis(x_axis)
                  , m_y_axis(y_axis)
                  , m_z_axis(z_axis)
                  , m_hist_cut(hist_cut)
{
  // do nothing
  std::cout << "m_hist_type  - " << m_hist_type  << "\n";
  std::cout << "m_var_exp    - " << m_var_exp    << "\n";
  std::cout << "m_x_num_bins - " << m_x_num_bins << "\n";
  std::cout << "m_x_min      - " << m_x_min      << "\n";
  std::cout << "m_x_max      - " << m_x_max      << "\n";
  std::cout << "m_y_num_bins - " << m_y_num_bins << "\n";
  std::cout << "m_y_min      - " << m_y_min      << "\n";
  std::cout << "m_y_max      - " << m_y_max      << "\n";
  std::cout << "m_name       - " << m_name       << "\n";
  std::cout << "m_title      - " << m_title      << "\n";
  std::cout << "m_x_axis     - " << m_x_axis     << "\n";
  std::cout << "m_y_axis     - " << m_y_axis     << "\n";
  std::cout << "m_z_axis     - " << m_z_axis     << "\n";
  std::cout << "m_hist_cut   - " << m_hist_cut   << "\n";
}

// -----------------------------------------------------------------------------
HistInfo::HistInfo(const HistInfo& rhs) : m_hist_type(rhs.getHistType())
                                        , m_var_exp(rhs.getVarExp())
                                        , m_x_num_bins(rhs.getNumXBins())
                                        , m_x_min(rhs.getXMin())
                                        , m_x_max(rhs.getXMax())
                                        , m_y_num_bins(rhs.getNumYBins())
                                        , m_y_min(rhs.getYMin())
                                        , m_y_max(rhs.getYMax())
                                        , m_name(rhs.getName())
                                        , m_title(rhs.getTitle())
                                        , m_x_axis(rhs.getXAxis())
                                        , m_y_axis(rhs.getYAxis())
                                        , m_z_axis(rhs.getZAxis())
                                        , m_hist_cut(rhs.getHistCut())
{
  // do nothing
}

// -----------------------------------------------------------------------------
HIST_TYPE HistInfo::getHistType() const
{
  return m_hist_type;
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
unsigned int HistInfo::getNumYBins() const
{
  return m_y_num_bins;
}

// -----------------------------------------------------------------------------
float HistInfo::getYMin() const
{
  return m_y_min;
}

// -----------------------------------------------------------------------------
float HistInfo::getYMax() const
{
  return m_y_max;
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
std::string HistInfo::getZAxis() const
{
  return m_z_axis;
}

// -----------------------------------------------------------------------------
std::string HistInfo::getHistCut() const
{
  return m_hist_cut;
}

// -----------------------------------------------------------------------------
TH1* HistInfo::genHist(std::string key)
{
  TH1* tmp = NULL;

  if (m_hist_type == HIST_1D) {
    tmp = new TH1D( (m_name + "__" + key).c_str()
            , (m_title + ";" + m_x_axis + ";" + m_y_axis).c_str()
            , m_x_num_bins
            , m_x_min
            , m_x_max
            );
  }
  else if (m_hist_type == HIST_2D) {
    tmp = new TH2D( (m_name + "__" + key).c_str()
            , (m_title + ";" + m_x_axis + ";" + m_y_axis + ";" + m_z_axis).c_str()
            , m_x_num_bins
            , m_x_min
            , m_x_max
            , m_y_num_bins
            , m_y_min
            , m_y_max
            );
  }

  return tmp;
}
