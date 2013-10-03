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
    TH1D* m_el_re_EWK;
    TH1D* m_el_re_STRONG;
    TH1D* m_el_re_numer_EWK;
    TH1D* m_el_re_numer_STRONG;
    TH1D* m_el_re_denom;

    TH1D* m_mu_re_EWK;
    TH1D* m_mu_re_STRONG;
    TH1D* m_mu_re_numer_EWK;
    TH1D* m_mu_re_numer_STRONG;
    TH1D* m_mu_re_denom;

    TH1D* m_el_fr_EWK;
    TH1D* m_el_fr_STRONG;
    TH1D* m_el_fr_numer_EWK;
    TH1D* m_el_fr_numer_STRONG;
    TH1D* m_el_fr_denom;

    TH1D* m_mu_fr_EWK;
    TH1D* m_mu_fr_STRONG;
    TH1D* m_mu_fr_numer_EWK;
    TH1D* m_mu_fr_numer_STRONG;
    TH1D* m_mu_fr_denom;
};

#endif
