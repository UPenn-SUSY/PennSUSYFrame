#ifndef HistMaker_h
#define HistMaker_h

#include <iostream>
#include <sstream>
#include <map>
#include <vector>

#include <TROOT.h>
#include <TCut.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>

#include "HistInfo.h"

#include "NtupleLooper/include/NtupleLooper.h"

#include "Selection/include/EventSelection.h"
#include "Selection/include/WeightHandler.h"

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

    void addCut( std::string key
               , Selection::EventSelection& selecton
               , Selection::WeightHandler& weight
               );
    void addHist(const HistInfo&);

    virtual void Loop();
    virtual void processEvent();

    void writeToFile();

  // ---------------------------------------------------------------------------
  protected:
    void fillHists(std::string key);

    std::vector<std::string> m_keys;
    std::map<std::string, Selection::EventSelection> m_selection;
    std::map<std::string, Selection::WeightHandler>  m_weight;

    std::vector<HistInfo> m_hist_info;

    TFile* m_out_file;
    std::map<std::string, std::vector<TH1D*> > m_hist;

    unsigned int m_entry_num;
};

#endif
