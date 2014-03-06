#ifndef ChannelFractions_h
#define ChannelFractions_h

// =============================================================================
#include <string>
#include <vector>
#include "NtupleLooper/include/NtupleLooper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class TH1D;

// =============================================================================
class TTree;

// =============================================================================
class ChannelFractions : public NtupleHelper::NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    ChannelFractions(TTree *tree, double num_events);
    virtual ~ChannelFractions();

    virtual void processEvent();

    void printToScreen();
    void printToFile(std::string out_file_name);

  // ---------------------------------------------------------------------------
  protected:
    double m_num_total;
    double m_num_eee;
    double m_num_eem;
    double m_num_emm;
    double m_num_mmm;
    double m_num_ee_os;
    double m_num_em_os;
    double m_num_mm_os;
    double m_num_ee_ss;
    double m_num_em_ss;
    double m_num_mm_ss;

  // ---------------------------------------------------------------------------
  private:
    double getFraction(double);
    void printLine( std::string channel
                  , double num_entries
                  , unsigned int label_field
                  , unsigned int weight_field
                  , unsigned int precision
                  );
};

#endif
