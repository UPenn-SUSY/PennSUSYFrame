#ifndef LumiWeight_h
#define LumiWeight_h

#include <iostream>
#include <TH1D.h>

#include "Parser/include/ParseDriver.h"

// =============================================================================
class LumiWeight
{
  // ---------------------------------------------------------------------------
  public:
    LumiWeight( std::string xsec_file
              , unsigned int sample_num
              , unsigned int target_lumi
              , double num_events
              , double modeled_in_file = -999
              );
    void readXSecFile();
    double getLumiWeight();

    static double getNumEventsFromFiles(
        const std::vector<std::string>& tnt_file_list);

  // ---------------------------------------------------------------------------
  private:
    bool m_prepped;
    float m_lumi_weight;
    int m_sample_num;
    int m_target_lumi;
    double m_num_evts;
    double m_modeled_in_file;
    float m_xsec;
    float m_k_factor;
    float m_eff;

    std::string m_xsec_file;
    // std::string m_num_evts_file;
};

#endif
