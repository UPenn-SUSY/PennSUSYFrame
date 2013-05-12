#include "include/HistConfigParser.h"

// -----------------------------------------------------------------------------
HistConfigParser::HistConfigParser(std::string file_name) :
    ParseDriver(file_name)
{
  clear();
}

// -----------------------------------------------------------------------------
HistConfigParser::~HistConfigParser()
{
  // do nothing
}

// -----------------------------------------------------------------------------
std::vector<HistInfo> HistConfigParser::getHistInfoList()
{
  return m_hist_info;
}

// -----------------------------------------------------------------------------
void HistConfigParser::clear()
{
  m_in_block = false;
  m_name     = "hist";
  m_var_exp  = "1";
  m_x_bins   = 10;
  m_x_min    = 0.;
  m_x_max    = 10.;
  m_y_bins   = 10;
  m_y_min    = 0.;
  m_y_max    = 10.;
  m_title    = "";
  m_x_axis   = "x axis";
  m_y_axis   = "y axis";
  m_z_axis   = "z axis";
  m_hist_cut = "";
}

// -----------------------------------------------------------------------------
void HistConfigParser::addLine(const std::vector<std::string>& split_line)
{
  // get key
  std::string key = split_line.at(0);

  if (!m_in_block) {
    if (key.find("hist") != std::string::npos) {
      m_in_block = true;
      m_name = split_line.at(1);
    }
    else {
      std::cout << "Need to open a config block\n";
      std::cout << "Hist config blocks start with a line of the form:\n";
      std::cout << "hist: hist_name\n";
      throw("Need to open a config block");
    }
    return;
  }
  if (key.find("end") != std::string::npos) {
    configHistInfo();
    clear();
  }
  else if (key.find("type")     != std::string::npos) {
    std::string tmp_type = split_line.at(1);
    if (     tmp_type == "2D" || tmp_type == "2d") m_type = HIST_2D;
    else if (tmp_type == "1D" || tmp_type == "1d") m_type = HIST_1D;
    else                                           m_type = HIST_1D;
  }
  // else if (key.find("var")      != std::string::npos) m_var_exp  = split_line.at(1);
  else if (key.find("var")      != std::string::npos) m_var_exp  = getVarExp(split_line);
  else if (key.find("x_bins")   != std::string::npos) m_x_bins   = stringToInt(split_line.at(1));
  else if (key.find("x_min")    != std::string::npos) m_x_min    = stringToFloat(split_line.at(1));
  else if (key.find("x_max")    != std::string::npos) m_x_max    = stringToFloat(split_line.at(1));
  else if (key.find("y_bins")   != std::string::npos) m_y_bins   = stringToInt(split_line.at(1));
  else if (key.find("y_min")    != std::string::npos) m_y_min    = stringToFloat(split_line.at(1));
  else if (key.find("y_max")    != std::string::npos) m_y_max    = stringToFloat(split_line.at(1));
  else if (key.find("title")    != std::string::npos) m_title    = convertToRootLatex(split_line.at(1));
  else if (key.find("x_axis")   != std::string::npos) m_x_axis   = convertToRootLatex(split_line.at(1));
  else if (key.find("y_axis")   != std::string::npos) m_y_axis   = convertToRootLatex(split_line.at(1));
  else if (key.find("z_axis")   != std::string::npos) m_z_axis   = convertToRootLatex(split_line.at(1));
  else if (key.find("hist_cut") != std::string::npos) m_hist_cut = split_line.at(1);
  else
    std::cout << "WARNING! The key \'" << key
              << "\' is invalid. Please check your inputs\n";
}

// -----------------------------------------------------------------------------
void HistConfigParser::configHistInfo()
{
  HistInfo tmp_hist( m_type
                   , m_var_exp
                   , m_x_bins
                   , m_x_min
                   , m_x_max
                   , m_y_bins
                   , m_y_min
                   , m_y_max
                   , m_name
                   , m_title
                   , m_x_axis
                   , m_y_axis
                   , m_z_axis
                   , m_hist_cut
                   );
  m_hist_info.push_back(tmp_hist);
}
