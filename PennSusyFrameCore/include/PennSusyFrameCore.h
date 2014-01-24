#ifndef PENNSUSYFRAME_H
#define PENNSUSYFRAME_H

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "PennSusyFrameCore/include/ObjectContainers.h"
#include "PennSusyFrameCore/include/ObjectSelectors.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
class TBranch;

namespace PennSusyFrame
{
  class D3PDReader;
}

// =============================================================================
namespace PennSusyFrame
{
  // ===========================================================================
  class PennSusyFrameCore
  {
    public :
      PennSusyFrameCore(TTree *tree=0);
      virtual ~PennSusyFrameCore();
      virtual Int_t    GetEntry(Long64_t entry);
      virtual Long64_t LoadTree(Long64_t entry);
      virtual void     Init(TTree *tree);
      virtual void     Loop();
      virtual Bool_t   Notify();

      virtual void prepareSelection();

      virtual void clearObjects();
      virtual void constructObjects();
      virtual void processEvent();

    protected:
      virtual FLAVOR_CHANNEL findFlavorChannel();
      virtual SIGN_CHANNEL   findSignCannel();

      PennSusyFrame::D3PDReader* m_d3pd_reader;

      PennSusyFrame::Event                m_event;
      PennSusyFrame::EventLevelQuantities m_event_quantities;
      PennSusyFrame::Met                  m_met;
      PennSusyFrame::VertexContainer      m_vertices;
      PennSusyFrame::ElectronContainer    m_electrons;
      PennSusyFrame::MuonContainer        m_muons;
      PennSusyFrame::TauContainer         m_taus;
      PennSusyFrame::JetContainer         m_jets;

      std::vector<PennSusyFrame::VertexSelector>   m_vertex_selectors;
      std::vector<PennSusyFrame::ElectronSelector> m_electron_selectors;
      std::vector<PennSusyFrame::MuonSelector>     m_muon_selectors;
      std::vector<PennSusyFrame::TauSelector>      m_tau_selectors;
      std::vector<PennSusyFrame::JetSelector>      m_jet_selectors;

      PennSusyFrame::ObjectCleaning m_object_cleaning;

    private:
  };
}

#endif
