#include "include/LumiWeight.h"

/*
// -----------------------------------------------------------------------------
LumiWeight::LumiWeight()
                  : m_var_exp("")
                  , m_x_num_bins(0)
                  , m_x_min(0)
                  , m_x_max(0)
                  , m_name("")
                  , m_title("")
                  , m_x_axis("")
                  , m_y_axis("")
{
  // do nothing
}

// -----------------------------------------------------------------------------
LumiWeight::LumiWeight( std::string var_exp
                  , unsigned int x_num_bins
                  , float x_min
                  , float x_max
                  , std::string name
                  , std::string title
                  , std::string x_axis
                  , std::string y_axis
                  )
                  : m_var_exp(var_exp)
                  , m_x_num_bins(x_num_bins)
                  , m_x_min(x_min)
                  , m_x_max(x_max)
                  , m_name(name)
                  , m_title(title)
                  , m_x_axis(x_axis)
                  , m_y_axis(y_axis)
{
  // do nothing
}

// -----------------------------------------------------------------------------
LumiWeight::LumiWeight(const LumiWeight& rhs) : m_var_exp(rhs.getVarExp())
                                        , m_x_num_bins(rhs.getNumXBins())
                                        , m_x_min(rhs.getXMin())
                                        , m_x_max(rhs.getXMax())
                                        , m_name(rhs.getName())
                                        , m_title(rhs.getTitle())
                                        , m_x_axis(rhs.getXAxis())
                                        , m_y_axis(rhs.getYAxis())
{
  // do nothing
}


// -----------------------------------------------------------------------------
std::string LumiWeight::getVarExp() const
{
  return m_var_exp;
}

// -----------------------------------------------------------------------------
float LumiWeight::getNumXBins() const
{
  return m_x_num_bins;
}

// -----------------------------------------------------------------------------
unsigned int LumiWeight::getXMin() const
{
  return m_x_min;
}

// -----------------------------------------------------------------------------
unsigned int LumiWeight::getXMax() const
{
  return m_x_max;
}

// -----------------------------------------------------------------------------
std::string LumiWeight::getName() const
{
  return m_name;
}

// -----------------------------------------------------------------------------
std::string LumiWeight::getTitle() const
{
  return m_title;
}

// -----------------------------------------------------------------------------
std::string LumiWeight::getXAxis() const
{
  return m_x_axis;
}

// -----------------------------------------------------------------------------
std::string LumiWeight::getYAxis() const
{
  return m_y_axis;
}

// -----------------------------------------------------------------------------
TH1D* LumiWeight::genHist(std::string key)
{
  TH1D* tmp = new TH1D( (m_name + "__" + key).c_str()
                 , (m_title + ";" + m_x_axis + ";" + m_y_axis).c_str()
                 , m_x_num_bins
                 , m_x_min
                 , m_x_max
                 );

  return tmp;
}
*/
