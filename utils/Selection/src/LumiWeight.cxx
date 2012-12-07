#include "include/LumiWeight.h"


// -----------------------------------------------------------------------------
LumiWeight::LumiWeight( std::string xsec_file
                      , std::string num_evt_file
                      , unsigned int sample_num
                      , unsigned int target_lumi
                      )
                      : m_prepped(false)
                      , m_lumi_weight(1.0)
                      , m_sample_num(sample_num)
                      , m_target_lumi(target_lumi)
                      , m_xsec_file(xsec_file)
                      , m_num_evts_file(num_evt_file)
{
  readXSecFile();
  readNumEventFile();
}

// -----------------------------------------------------------------------------
void LumiWeight::readXSecFile()
{
  std::fstream file(m_xsec_file.c_str());
  bool ds_found = false;

  if (file.is_open()) {
    std::string line;
    std::vector<std::string> split_line;

    // run through file parsing each line
    while (file.good() && !ds_found) {
      // get line from file, strip comments and leading/subleading whitespace
      std::getline(file, line);
      line = ParseDriver::cleanUpLine(line);

      split_line = ParseDriver::split(line, '\t');
      if (split_line.size() < 1) continue;

      if (ParseDriver::stringToInt(split_line.at(0)) == m_sample_num) {
        ds_found = true;
        m_xsec     = ParseDriver::stringToFloat(split_line.at(2));
        m_k_factor = ParseDriver::stringToFloat(split_line.at(3));
        m_eff      = ParseDriver::stringToFloat(split_line.at(4));
      }
    }

    file.close();
  }
  else {
    std::cout << "Cross section file '" << m_xsec_file << "' is not found\n";
    throw;
  }

  if (!ds_found) {
    std::cout << "Sample number " << m_sample_num
              << " not found in cross section file\n";
    throw;
  }
}

// -----------------------------------------------------------------------------
void LumiWeight::readNumEventFile()
{
  std::fstream file(m_num_evts_file.c_str());
  bool ds_found = false;

  if (file.is_open()) {
    std::string line;
    std::vector<std::string> split_line;

    // run through file parsing each line
    while (file.good() && !ds_found) {
      // get line from file, strip comments and leading/subleading whitespace
      std::getline(file, line);
      line = ParseDriver::cleanUpLine(line);

      split_line = ParseDriver::split(line);
      if (split_line.size() < 1) continue;

      if (ParseDriver::stringToInt(split_line.at(0)) == m_sample_num) {
        ds_found = true;
        m_num_evts = ParseDriver::stringToInt(split_line.at(1));
      }
    }

    file.close();
  }
  else {
    std::cout << "num events file '" << m_num_evts_file << "' is not found\n";
    throw;
  }

  if (!ds_found) {
    std::cout << "Sample number " << m_sample_num
              << " not found in num events file\n";
    throw;
  }
}

// -----------------------------------------------------------------------------
double LumiWeight::getLumiWeight()
{
  if (!m_prepped) {
    m_prepped = true;
    m_lumi_weight = m_k_factor*m_eff*m_xsec*m_target_lumi/m_num_evts;
  }

  return m_lumi_weight;
}
