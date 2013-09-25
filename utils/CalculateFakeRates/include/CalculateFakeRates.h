#ifndef CalculateFakeRates_h
#define CalculateFakeRates_h

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
class CalculateFakeRates : public NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    CalculateFakeRates(TTree *tree, double num_events);
    virtual ~CalculateFakeRates();

    virtual void processEvent();

    void printToScreen();
    void printToFile(std::string out_file_name);

  // ---------------------------------------------------------------------------
  protected:

  // ---------------------------------------------------------------------------
  private:
    TH1D* m_el_re;
    TH1D* m_el_re_numer;
    TH1D* m_el_re_denom;

    TH1D* m_mu_re;
    TH1D* m_mu_re_numer;
    TH1D* m_mu_re_denom;

    TH1D* m_el_fr;
    TH1D* m_el_fr_numer;
    TH1D* m_el_fr_denom;

    TH1D* m_mu_fr;
    TH1D* m_mu_fr_numer;
    TH1D* m_mu_fr_denom;
};

#endif
