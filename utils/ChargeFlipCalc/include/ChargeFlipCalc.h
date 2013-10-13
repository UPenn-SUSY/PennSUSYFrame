#ifndef ChargeFlipCalc_h
#define ChargeFlipCalc_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TH1.h>
#include "TMinuit.h"

#include "NtupleLooper/include/NtupleLooper.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/ElectronDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.


// =============================================================================
class ChargeFlipCalc : public NtupleHelper::NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    ChargeFlipCalc(TTree *tree, double num_events);
    virtual ~ChargeFlipCalc();
    // virtual void     Init(TTree *tree);

    virtual void processEvent();
    void prepLikelihood();

    void calcLikelihood();
    void calcTruth();

    void printToFile(std::string out_file_name);

    void clearHists();

    TH1F* m_h_lklh_rate;
  // ---------------------------------------------------------------------------
  private:

    void initChargeFlipHists();
    void fillTruthHists();
    bool passTruthSelection();
    void fillLikelihoodHists();
    bool passLikelihoodSelection();
    float GetChargeFlipWeightFromMap(float, float,float, float);

    TH2* m_h_map;

    TH2F* m_h_flipped;
    TH2F* m_h_total;
	  
    TH1F* m_h_flipped_pt_only;
    TH1F* m_h_total_pt_only;
	  
    TH1F* m_h_flipped_eta_only;
    TH1F* m_h_total_eta_only;

    TH1F* m_h_mll;
    TH1F* m_h_mll_ss;

    TH2F* m_h_n_events; 
    TH2F* m_h_n_ss;


    TH1F* m_h_truth_rate_eta_only;
    TH2F* m_h_truth_rate;

    static double lkh_events[5][5];
    static double lkh_ss[5][5];

    static double logLikelihood(double eff_array[], 
				int num_total, 
				int num_ss, 
				int lead_eta_bin, 
				int sublead_eta_bin
				);


    static void flipLikelihood(Int_t &npar, 
			       Double_t *gin, 
			       Double_t &f, 
			       Double_t *par, 
			       Int_t iflag);

    

};

#endif
