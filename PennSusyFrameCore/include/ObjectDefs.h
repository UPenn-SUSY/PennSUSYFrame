#ifndef ObjectDefs_H
#define ObjectDefs_H

#include <vector>

#include "TLorentzVector.h"
#include "PennSusyFrameCore/include/RescalerTools.h"

// =============================================================================
namespace PennSusyFrame
{
  class D3PDReader;
}

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class Event
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Event();

      void init();
      void getEvent(const PennSusyFrame::D3PDReader*);

      void setEventNumber(unsigned int);
      void setRunNumber(unsigned int);
      void setLumiBlock(unsigned int);
      void setAverageIntPerXing(float);
      void setEventShapeRhoKt4LC(float);

      unsigned int getEventNumber() const;
      unsigned int getRunNumber() const;
      unsigned int getLumiBlock() const;
      float getAverageIntPerXing() const;
      float getEventShapeRhoKt4LC() const;

      void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      bool m_is_data;

      unsigned int m_event_number;
      unsigned int m_run_number;
      unsigned int m_lumi_block;

      float m_average_int_per_xing;
      float m_eventshape_rhoKt4LC;
  };

  // =============================================================================
  class Particle
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Particle();

      virtual void printGeneralInfo() const;

      virtual void setParticleIndex(int);
      virtual void setTlv(const TLorentzVector&);
      virtual void setRawTlv(const TLorentzVector&);

      virtual int getParticleIndex() const;
      virtual const TLorentzVector* getTlv() const;
      virtual const TLorentzVector* getRawTlv() const;

      virtual double getPt() const;
      virtual double getEta() const;
      virtual double getPhi() const;
      virtual double getE() const;

      virtual double getRawPt() const;
      virtual double getRawEta() const;
      virtual double getRawPhi() const;
      virtual double getRawE() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      int m_particle_index;

      bool m_tlv_set;
      bool m_raw_tlv_set;
      TLorentzVector m_tlv;
      TLorentzVector m_raw_tlv;
  };

  // =============================================================================
  class Lepton : public Particle
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Lepton();

      void setIsLightLepton(bool);
      void setIsElectron(bool);
      void setCharge(double);

      bool isElectron() const;
      bool isMuon() const;
      bool isTau() const;
      double getCharge() const;

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      bool m_is_light_lepton;
      bool m_is_electron;
      double m_charge;
  };

  // =============================================================================
  class Electron : public Lepton
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Electron();
      Electron( const PennSusyFrame::D3PDReader*
              , int el_index
              , PennSusyFrame::ElectronRescalerTool*
              , bool verbose = false
              );


      void setClE(double);
      void setClEta(double);
      void setClPhi(double);

      double getClE() const;
      double getClEta() const;
      double getClPhi() const;

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      // void setElTlv(const PennSusyFrame::D3PDReader* reader, PennSusyFrame::ElectronRescalerTool&);
      void setElTlv(const PennSusyFrame::D3PDReader* reader, PennSusyFrame::ElectronRescalerTool*);

      double m_cl_E;
      double m_cl_eta;
      double m_cl_phi;
  };

  // =============================================================================
  class Muon : public Lepton
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Muon();
      Muon( const PennSusyFrame::D3PDReader*
          , int mu_index
          , PennSusyFrame::MuonRescalerTool*
          , bool verbose = false
          );

      void setIsCombined(int);
      void setIsSegmentTagged(int);
      void setIdQOverP(double);
      void setIdTheta(double);
      void setMEQOverP(double);
      void setMETheta(double);

      int getIsCombined() const;
      int getIsSegmentTagged() const;
      double getIdQOverP() const;
      double getIdTheta() const;
      double getMEQOverP() const;
      double getMETheta() const;

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void setMuTlv( const PennSusyFrame::D3PDReader* reader
                   , PennSusyFrame::MuonRescalerTool* mu_rescaler
                   );

      int m_is_combined;
      int m_is_segment_tagged;
      double m_id_qoverp;
      double m_id_theta;
      double m_me_qoverp;
      double m_me_theta;
  };

  // =============================================================================
  class Tau : public Lepton
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Tau();
      Tau( const PennSusyFrame::D3PDReader*
         , int tau_index
         // , PennSusyFrame::TauRescalerTool*
         , bool verbose = false
         );

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void setTauTlv( const PennSusyFrame::D3PDReader* reader
                    // , PennSusyFrame::TauRescalerTool* tau_rescaler
                    );
  };

  // =============================================================================
  class Jet : public Particle
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Jet();
      Jet( const PennSusyFrame::D3PDReader*
         , int jet_index
         , PennSusyFrame::JetRescalerTool*
         , PennSusyFrame::Event*
         , bool verbose = false
         );

      void setConstScaleE(double);
      void setConstScaleEta(double);
      void setConstScalePhi(double);
      void setConstScaleM(double);
      void setActiveAreaPx(double);
      void setActiveAreaPy(double);
      void setActiveAreaPz(double);
      void setActiveAreaE(double);

      double getConstScaleE() const;
      double getConstScaleEta() const;
      double getConstScalePhi() const;
      double getConstScaleM() const;
      double getActiveAreaPx() const;
      double getActiveAreaPy() const;
      double getActiveAreaPz() const;
      double getActiveAreaE() const;

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void setJetTlv( const PennSusyFrame::D3PDReader* reader
                    , PennSusyFrame::JetRescalerTool*
                    , PennSusyFrame::Event*
                    );

      double m_constscale_e;
      double m_constscale_eta;
      double m_constscale_phi;
      double m_constscale_m;
      double m_active_area_px;
      double m_active_area_py;
      double m_active_area_pz;
      double m_active_area_e;
  };

  // =============================================================================
  class Vertex
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Vertex();
      Vertex( const PennSusyFrame::D3PDReader*
            , int vertex_index
            , bool verbose = false
            );

      void setVertexIndex(int);
      void setNumTracks(int);

      int getVertexIndex() const;
      int getNumTracks() const;

      void print() const;

      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      int m_vertex_index;
      int m_num_tracks;
  };

  // =============================================================================
  class Met
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Met();
      void clear();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
  };
}

#endif
