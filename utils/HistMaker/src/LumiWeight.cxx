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

  while (file.isOpen() {

      }


  fin.close();
}

// -----------------------------------------------------------------------------
void LumiWeight::readNumEventFile()
{

}

// -----------------------------------------------------------------------------
double LumiWeight::getLumiWeight()
{
  if (!m_prepped)
    m_lumi_weight = m_k_factor*m_eff*m_xsec*m_target_lumi/m_num_evts;
  return m_lumi_weight;
}
