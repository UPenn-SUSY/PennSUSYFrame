#ifndef HistMaker_h
#define HistMaker_h

#include <iostream>
#include <map>
#include <vector>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>

#include "NtupleLooper/include/NtupleLooper.h"

#include "Selection/include/EventSelection.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class HistMaker : public NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    HistMaker(TTree *tree=0, std::string out_file_name = "hists.root");
    virtual ~HistMaker();

    void addCut(std::string key, Selection::EventSelection selecton);
    void addHist(/*something reasonable*/);
    void init();

    virtual void processEvent();

    void writeToFile();

  // ---------------------------------------------------------------------------
  protected:
    void fillHists(std::string key);

    std::vector<std::string> m_keys;
    std::map<std::string, Selection::EventSelection> m_selection;

    TFile* m_out_file;
    std::map<std::string, TH1D*> m_hist_mll;
    std::map<std::string, TH1D*> m_hist_el_pt;
    std::map<std::string, TH1D*> m_hist_mu_pt;
};

#endif
