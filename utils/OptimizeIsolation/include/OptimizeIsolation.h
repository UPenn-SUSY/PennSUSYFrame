#ifndef OptimizeIsolation_h
#define OptimizeIsolation_h

// =============================================================================
#include <string>
#include <vector>
#include "NtupleLooper/include/NtupleLooper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class TH1D;
class TH2D;
class TTree;

// =============================================================================
enum ISO_STYLE { ISO_PTCONE30 = 0
               , ISO_ETCONE30
               , ISO_PTCONE20
               , ISO_ETCONE20
               , ISO_PTCONE30_CAPPED
               , ISO_ETCONE30_CAPPED
               , ISO_PTCONE20_CAPPED
               , ISO_ETCONE20_CAPPED
               , ISO_N
               };
static const std::string ISO_STYLE_STRINGS[] = { "PTCONE30"
                                               , "ETCONE30"
                                               , "PTCONE20"
                                               , "ETCONE20"
                                               , "PTCONE30_CAPPED"
                                               , "ETCONE30_CAPPED"
                                               , "PTCONE20_CAPPED"
                                               , "ETCONE20_CAPPED"
                                               , "NONE"
                                               };

// =============================================================================
class OptimizeIsolation : public NtupleHelper::NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    OptimizeIsolation(TTree *tree, double num_events);
    virtual ~OptimizeIsolation();

    virtual void processEvent();
    void printToScreen();
    void printToFile(std::string out_file_name);

  // ---------------------------------------------------------------------------
  protected:

  // ---------------------------------------------------------------------------
  private:
    std::vector<TH1D*> m_el_iso;
    std::vector<TH1D*> m_mu_iso;

    std::vector<TH1D*> m_el_iso_prompt;
    std::vector<TH1D*> m_mu_iso_prompt;

    std::vector<TH1D*> m_el_iso_fake;
    std::vector<TH1D*> m_mu_iso_fake;

    std::vector<TH2D*> m_el_iso_pt_bins;
    std::vector<TH2D*> m_mu_iso_pt_bins;

    std::vector<TH2D*> m_el_iso_pt_bins_prompt;
    std::vector<TH2D*> m_mu_iso_pt_bins_prompt;

    std::vector<TH2D*> m_el_iso_pt_bins_fake;
    std::vector<TH2D*> m_mu_iso_pt_bins_fake;

    std::vector<TH2D*> m_el_iso_eta_bins;
    std::vector<TH2D*> m_mu_iso_eta_bins;

    std::vector<TH2D*> m_el_iso_eta_bins_prompt;
    std::vector<TH2D*> m_mu_iso_eta_bins_prompt;

    std::vector<TH2D*> m_el_iso_eta_bins_fake;
    std::vector<TH2D*> m_mu_iso_eta_bins_fake;
};

#endif
