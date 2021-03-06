#ifndef PennSusyFrame_ObjectContainers
#define PennSusyFrame_ObjectContainers

// =============================================================================
#include <vector>

#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/RescalerTools.h"

// ============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  // = VertexContainer
  // =============================================================================
  class VertexContainer
  {
    public:
      VertexContainer();

      void init();

      void clear();
      void prep(PennSusyFrame::D3PDReader*);
      void setCollection(VERTEX_COLLECTIONS, std::vector<PennSusyFrame::Vertex*>);

      size_t num(VERTEX_COLLECTIONS) const;
      const std::vector<PennSusyFrame::Vertex*>* getCollection(VERTEX_COLLECTIONS) const;

      void print(VERTEX_COLLECTIONS) const;

    private:
      std::vector<PennSusyFrame::Vertex> m_master_list;
      std::vector<std::vector<PennSusyFrame::Vertex*> > m_user_lists;
  };

  // =============================================================================
  // = ElectronContainer
  // =============================================================================
  class ElectronContainer
  {
    public:
      ElectronContainer();
      ~ElectronContainer();

      void init( bool is_data
               , bool is_af2
               , PennSusyFrame::SystematicStruct* syst_struct
               );
      void updateWithMet(const PennSusyFrame::Met&);
      void updateIsolation(const PennSusyFrame::Event*, int num_vtx);

      void clear();
      void prep(PennSusyFrame::D3PDReader*);
      void setCollection(ELECTRON_COLLECTIONS, std::vector<PennSusyFrame::Electron*>);

      size_t num(ELECTRON_COLLECTIONS) const;
      const std::vector<PennSusyFrame::Electron*>* getCollection(ELECTRON_COLLECTIONS) const;

      void print(ELECTRON_COLLECTIONS) const;

    private:
      std::vector<PennSusyFrame::Electron> m_master_list;
      std::vector<std::vector<PennSusyFrame::Electron*> > m_user_lists;

      bool m_is_data;
      PennSusyFrame::ElectronRescalerTool* m_el_rescaler;
  };

  // =============================================================================
  // = MuonContainer
  // =============================================================================
  class MuonContainer
  {
    public:
      MuonContainer();
      ~MuonContainer();

      void init(bool is_data
               , PennSusyFrame::SystematicStruct* syst_struct = 0
               );
      void updateWithMet(const PennSusyFrame::Met&);
      void updateIsolation(const PennSusyFrame::Event*, int num_vtx);

      void clear();
      void prep(PennSusyFrame::D3PDReader*);
      void setCollection(MUON_COLLECTIONS, std::vector<PennSusyFrame::Muon*>);

      size_t num(MUON_COLLECTIONS) const;
      const std::vector<PennSusyFrame::Muon*>* getCollection(MUON_COLLECTIONS) const;

      void print(MUON_COLLECTIONS) const;

    private:
      std::vector<PennSusyFrame::Muon> m_master_list;
      std::vector<std::vector<PennSusyFrame::Muon*> > m_user_lists;

      bool m_is_data;
      PennSusyFrame::MuonRescalerTool* m_mu_rescaler;
  };

  // =============================================================================
  // = TauContainer
  // =============================================================================
  class TauContainer
  {
    public:
      TauContainer();
      ~TauContainer();

      void init(bool is_data, bool is_af2);
      void updateWithMet(const PennSusyFrame::Met&);

      void clear();
      void prep(PennSusyFrame::D3PDReader*);
      void setCollection(TAU_COLLECTIONS, std::vector<PennSusyFrame::Tau*>);

      size_t num(TAU_COLLECTIONS) const;
      const std::vector<PennSusyFrame::Tau*>* getCollection(TAU_COLLECTIONS) const;

      void print(TAU_COLLECTIONS) const;

    private:
      std::vector<PennSusyFrame::Tau> m_master_list;
      std::vector<std::vector<PennSusyFrame::Tau*> > m_user_lists;

      bool m_is_data;
      PennSusyFrame::TauRescalerTool* m_tau_rescaler;
  };

  // =============================================================================
  // = JerContainer
  // =============================================================================
  class JetContainer
  {
    public:
      JetContainer();
      ~JetContainer();

      void init( bool is_data
               , bool is_af2
               , bool is_mc12b
               , PennSusyFrame::SystematicStruct* syst_struct = 0
               );
      void updateWithMet(const PennSusyFrame::Met&);

      void clear();
      void prep(PennSusyFrame::D3PDReader*, PennSusyFrame::Event*, PennSusyFrame::VertexContainer*);
      void setCollection(JET_COLLECTIONS, std::vector<PennSusyFrame::Jet*>);

      size_t num(JET_COLLECTIONS) const;
      const std::vector<PennSusyFrame::Jet*>* getCollection(JET_COLLECTIONS) const;

      void print(JET_COLLECTIONS) const;

    private:
      std::vector<PennSusyFrame::Jet> m_master_list;
      std::vector<std::vector<PennSusyFrame::Jet*> > m_user_lists;

      bool m_is_data;
      PennSusyFrame::JetRescalerTool* m_jet_rescaler;
  };
}

#endif
