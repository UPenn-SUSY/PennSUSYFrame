#include "include/HistMaker.h"

// -----------------------------------------------------------------------------
HistMaker::HistMaker( TTree *tree
                    , std::string out_file_name
                    )
                    : NtupleLooper(tree)
                    , m_out_file(NULL)
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
void HistMaker::addHist()
{
  // TODO add histogram factories
}

// -----------------------------------------------------------------------------
void HistMaker::init()
{
  std::vector<std::string>::iterator key_it = m_keys.begin();
  std::vector<std::string>::iterator key_term = m_keys.end();
  for (; key_it != key_term; ++key_it) {
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
  }
}

// -----------------------------------------------------------------------------
void HistMaker::fillHists(std::string key)
{
  m_hist_mll[key]->Fill(m_mll/1000.);

  if (m_el_pt->size() > 0)
    m_hist_el_pt[key]->Fill(m_el_pt->at(0)/1000.);

  if (m_mu_pt->size() > 0)
    m_hist_mu_pt[key]->Fill(m_mu_pt->at(0)/1000.);
}
