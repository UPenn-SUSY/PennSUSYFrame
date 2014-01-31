#ifndef PennSusyFrame_TriggerHelpers_h
#define PennSusyFrame_TriggerHelpers_h

// =============================================================================
#include <vector>

// =============================================================================
namespace PennSusyFrame
{
  class Electron;
  class Muon;
  class Trigger;
}

// =============================================================================
namespace PennSusyFrame
{
  bool matchElectronList( const std::vector<PennSusyFrame::Electron*>*
                        , const std::vector<int>* trigger_chain
                        , const std::vector<float>* online_px
                        , const std::vector<float>* online_py
                        , const std::vector<float>* online_pz
                        , const std::vector<float>* online_E
                        , unsigned int num_to_match
                        , double dr_cut
                        , double pt_cut
                        );
  bool matchElectron( const PennSusyFrame::Electron*
                    , const std::vector<int>* trigger_chain
                    , const std::vector<float>* online_px
                    , const std::vector<float>* online_py
                    , const std::vector<float>* online_pz
                    , const std::vector<float>* online_E
                    , double dr_cut
                    , double pt_cut
                    );
  bool matchMuonList( const std::vector<PennSusyFrame::Muon*>*
                    , const std::vector<int>* trigger_chain
                    , const std::vector<std::vector<float> >* online_pt
                    , const std::vector<std::vector<float> >* online_eta
                    , const std::vector<std::vector<float> >* online_phi
                    , unsigned int num_to_match
                    , double dr_cut
                    , double pt_cut
                    );
  bool matchMuon( const PennSusyFrame::Muon*
                , const std::vector<int>* trigger_chain
                , const std::vector<std::vector<float> >* online_pt
                , const std::vector<std::vector<float> >* online_eta
                , const std::vector<std::vector<float> >* online_phi
                , double dr_cut
                , double pt_cut
                );
}

#endif
