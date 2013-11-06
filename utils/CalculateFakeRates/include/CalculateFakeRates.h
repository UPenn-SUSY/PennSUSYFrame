#ifndef CalculateFakeRates_h
#define CalculateFakeRates_h

// =============================================================================
#include <string>
#include <vector>
#include "NtupleLooper/include/NtupleLooper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class TH1D;
class TTree;

// =============================================================================
class CalculateFakeRates : public NtupleHelper::NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    CalculateFakeRates(TTree *tree, double num_events);
    virtual ~CalculateFakeRates();

    virtual void processEvent_bak();
    virtual void processEvent();
    void printToScreen();
    void printToFile(std::string out_file_name);

  // ---------------------------------------------------------------------------
  protected:

  // ---------------------------------------------------------------------------
  private:
    std::vector<TH1D*> m_el_re;
    std::vector<TH1D*> m_el_re_numer;
    TH1D* m_el_re_denom;

    std::vector<TH1D*> m_mu_re;
    std::vector<TH1D*> m_mu_re_numer;
    TH1D* m_mu_re_denom;

    std::vector<TH1D*> m_el_fr;
    std::vector<TH1D*> m_el_fr_numer;
    TH1D* m_el_fr_denom;

    std::vector<TH1D*> m_mu_fr;
    std::vector<TH1D*> m_mu_fr_numer;
    TH1D* m_mu_fr_denom;
};

#endif
