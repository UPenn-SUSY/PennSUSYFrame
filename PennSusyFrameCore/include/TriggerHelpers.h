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
  bool matchElectronList( const std::vector<const PennSusyFrame::Electron*>*
                        , const std::vector<int>* trigger_chain
                        , const PennSusyFrame::Trigger*
                        , size_t num_to_match
                        , double dr_cut
                        , double pt_cut
                        );
  bool matchElectron( const PennSusyFrame::Electron*
                    , const std::vector<int>* trigger_chain
                    , const PennSusyFrame::Trigger*
                    , double dr_cut
                    , double pt_cut
                    );
  bool matchMuonList( const std::vector<const PennSusyFrame::Muon*>*
                    , const std::vector<int>* trigger_chain
                    , const PennSusyFrame::Trigger*
                    , size_t num_to_match
                    , double dr_cut
                    , double pt_cut
                    );
  bool matchMuon( const PennSusyFrame::Muon*
                , const std::vector<int>* trigger_chain
                , const PennSusyFrame::Trigger*
                , double dr_cut
                , double pt_cut
                );
}

#endif
