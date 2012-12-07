#ifndef LumiWeight_h
#define LumiWeight_h

#include <iostream>
#include <TH1D.h>

// =============================================================================
class LumiWeight
{
  // ---------------------------------------------------------------------------
  public:
    LumiWeight( std::string xsec_file
              , std::string num_evt_file
              , unsigned int sample_num
              , unsigned int target_lumi
              );
    void readXSecFile();
    void readNumEventFile();
    double getLumiWeight();

  // ---------------------------------------------------------------------------
  private:
    bool m_prepped;
    float m_lumi_weight;
    unsigned int m_sample_num;
    unsigned int m_target_lumi;
    unsigned int m_num_evts;
    float m_xsec;
    float m_k_factor;
    float m_eff;

    std::string m_xsec_file;
    std::string m_num_evts_file;
};

#endif
