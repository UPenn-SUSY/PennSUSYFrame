#include "include/HistMaker.h"

// -----------------------------------------------------------------------------
HistMaker::HistMaker( TTree *tree
                    , std::string out_file_name
                    )
                    : NtupleLooper(tree)
                    , m_out_file(NULL)
                    , m_entry_num(0)
{
  m_out_file = new TFile(out_file_name.c_str(), "create");
}

// -----------------------------------------------------------------------------
HistMaker::~HistMaker()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void HistMaker::addCut(std::string key, Selection::EventSelection selecton)
{
  m_keys.push_back(key);
  m_selection[key] = selecton;
}

// -----------------------------------------------------------------------------
void HistMaker::addHist(const HistInfo& hist_info)
{
  m_hist_info.push_back(hist_info);
}

// -----------------------------------------------------------------------------
void HistMaker::init()
{
  std::vector<std::string>::iterator key_it = m_keys.begin();
  std::vector<std::string>::iterator key_term = m_keys.end();
  for (; key_it != key_term; ++key_it) {
    // std::vector<HistInfo>::iterator hist_it = m_hist_info.begin();
    // std::vector<HistInfo>::iterator hist_term = m_hist_info.end();
    // for (; hist_it != hist_term; ++hist_it) {
    //   TH1D* tmp_hist = (*hist_it)->genHist(*key_it);
    //   m_hist[*key_it].push_back(tmp_hist);
    // }

    m_hist_mll[*key_it] = new TH1D( ("mll__" + *key_it).c_str()
                                  , "m_ll; m_ll [GeV] ; Entries"
                                  , 50, 0, 500
                                  );
    m_hist_el_pt[*key_it] = new TH1D( ("el_pt__" + *key_it).c_str()
                                    , "el_pt; p_{T}^{e} [GeV] ; Entries"
                                    , 50, 0, 500
                                    );
    m_hist_mu_pt[*key_it] = new TH1D( ("mu_pt__" + *key_it).c_str()
                                    , "mu_pt; p_{T}^{#mu} [GeV] ; Entries"
                                    , 50, 0, 500
                                    );
  }
}

// -----------------------------------------------------------------------------
void HistMaker::Loop()
{
  std::vector<std::string>::iterator key_it = m_keys.begin();
  std::vector<std::string>::iterator key_term = m_keys.end();
  for (; key_it != key_term; ++key_it) {
    fillHists(*key_it);
  }
}

// -----------------------------------------------------------------------------
void HistMaker::processEvent()
{
  std::vector<std::string>::iterator key_it = m_keys.begin();
  std::vector<std::string>::iterator key_term = m_keys.end();
  for (; key_it != key_term; ++key_it) {
    if (m_selection[*key_it].passEvent(m_event_desc, m_sr_helper))
      fillHists(*key_it);
  }
}

// -----------------------------------------------------------------------------
void HistMaker::writeToFile()
{
  std::vector<std::string>::iterator key_it = m_keys.begin();
  std::vector<std::string>::iterator key_term = m_keys.end();
  for (; key_it != key_term; ++key_it) {
    m_out_file->cd();
    TDirectory* d = m_out_file->GetDirectory((*key_it).c_str());
    if (d == NULL) d = m_out_file->mkdir((*key_it).c_str());

    d->cd();

    m_hist_mll[*key_it]->Write();
    m_hist_el_pt[*key_it]->Write();
    m_hist_mu_pt[*key_it]->Write();


    std::vector<TH1D*>::iterator hist_it = m_hist[*key_it].begin();
    std::vector<TH1D*>::iterator hist_term = m_hist[*key_it].end();
    for (; hist_it != hist_term; ++hist_it) {
      (*hist_it)->Write();
    }
  }
}

// -----------------------------------------------------------------------------
void HistMaker::fillHists(std::string key)
{
  // get the selection cuts for this event
  ull_t pass_event = m_selection[key].getPassEventWord()->toInt();
  ull_t pass_sr    = m_selection[key].getPassSRWord()->toInt();

  std::stringstream ss_pass_event;
  ss_pass_event << "((event_desc & " << pass_event 
                << ") == " << pass_event << ") ";
  TCut cut_pass_event = ss_pass_event.str().c_str();

  std::stringstream ss_pass_sr;
  ss_pass_sr << "((sr_helper & " << pass_sr 
             << ") == " << pass_sr << ") ";
  TCut cut_pass_sr = ss_pass_sr.str().c_str();

  TCut full_selection = cut_pass_event && cut_pass_sr;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::map<std::string, std::string> vars_to_plot;
  vars_to_plot["mll"] = "mll/1000.";
  vars_to_plot["el_pt"] = "el_pt[0]/1000.";
  vars_to_plot["mu_pt"] = "mu_pt[0]/1000.";

  std::map<std::string, std::string>::iterator var_it = vars_to_plot.begin();
  std::map<std::string, std::string>::iterator var_term = vars_to_plot.end();
  for (; var_it != var_term; ++var_it) {
    std::string var_exp = ( var_it->second + " >> "
                          + var_it->first + "__" + key
                          );
    std::cout << "var_exp: " << var_exp << "\n";
    fChain->Draw(var_exp.c_str(), full_selection, "goff");
  }



  std::cout << "=================================\n";
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::vector<HistInfo>::iterator hist_it = m_hist_info.begin();
  std::vector<HistInfo>::iterator hist_term = m_hist_info.end();
  for (; hist_it != hist_term; ++hist_it) {
    TH1D * tmp_hist = hist_it->genHist(key);

    std::string var_exp = ( hist_it->getVarExp() + " >> "
                          + hist_it->getName() + "__" + key
                          );
    std::cout << "var_exp: " << var_exp << "\n";
    fChain->Draw(var_exp.c_str(), full_selection, "goff");

    m_hist[key].push_back(tmp_hist);
  }
  std::cout << "---------------------------------\n";
}
