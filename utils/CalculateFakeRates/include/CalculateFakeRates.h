#ifndef CalculateFakeRates_h
#define CalculateFakeRates_h

// =============================================================================
#include <string>
#include <vector>
#include "NtupleLooper/include/NtupleLooper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class TH1;
class TH1D;
class TH2D;
class TTree;

// =============================================================================
class CalculateFakeRates : public NtupleHelper::NtupleLooper
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
    // TH1* computeFactorHistogram(TH1* numer, TH1* denom, std::string name);
    template <class T>
      T * computeFactorHistogram(T* numer, T* denom, std::string name);
    // TH1D * computeFactorHistogram(TH1D* numer, TH1D* denom, std::string name);
    // TH2D * computeFactorHistogram(TH2D* numer, TH2D* denom, std::string name);

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

    std::vector<TH2D*> m_el_re_eta_bins;
    std::vector<TH2D*> m_el_re_eta_bins_numer;
    TH2D* m_el_re_eta_bins_denom;

    std::vector<TH2D*> m_mu_re_eta_bins;
    std::vector<TH2D*> m_mu_re_eta_bins_numer;
    TH2D* m_mu_re_eta_bins_denom;

    std::vector<TH2D*> m_el_fr_eta_bins;
    std::vector<TH2D*> m_el_fr_eta_bins_numer;
    TH2D* m_el_fr_eta_bins_denom;

    std::vector<TH2D*> m_mu_fr_eta_bins;
    std::vector<TH2D*> m_mu_fr_eta_bins_numer;
    TH2D* m_mu_fr_eta_bins_denom;
};

// -----------------------------------------------------------------------------
template <class T>
  T* CalculateFakeRates::computeFactorHistogram( T* numer
                                               , T* denom
                                               , std::string name
                                               )
{
    T * h_rate = static_cast<T*>(numer->Clone(name.c_str()));
    h_rate->Sumw2();
    h_rate->Divide(m_el_re_denom);
    return h_rate;
}

#endif
