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
  class PhysicsObject
  {
    // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // public:
    //   PhysicsObject();
  };

  // =============================================================================
  class Event : public PhysicsObject
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
  class Particle : public PhysicsObject
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
      void setD0(double);
      void setSigD0(double);
      void setZ0(double);
      // TODO rename these functions to give access to all iso variables - raw and corrected
      void setPtIso(double);
      void setEtIso(double);


      double getClE() const;
      double getClEta() const;
      double getClPhi() const;
      double getD0() const;
      double getSigD0() const;
      double getD0Significance() const;
      double getZ0() const;
      double getZ0SinTheta() const;
      // TODO rename these functions to give access to all iso variables - raw and corrected
      double getPtIso() const;
      double getEtIso() const;

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      // void setElTlv(const PennSusyFrame::D3PDReader* reader, PennSusyFrame::ElectronRescalerTool&);
      void setElTlv(const PennSusyFrame::D3PDReader* reader, PennSusyFrame::ElectronRescalerTool*);

      double m_cl_E;
      double m_cl_eta;
      double m_cl_phi;
      double m_d0;
      double m_sig_d0;
      double m_z0;
      double m_pt_iso;
      double m_et_iso;
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
      void setTrackEta(double);
      void setQOverPRatio(double);
      void setNumBLayerHits(int);
      void setNumPixelHits(int);
      void setNumSctHits(int);
      void setNumSiHoles(int);
      void setNumTrtHits(int);
      void setTrtOlFraction(double);
      void setD0(double);
      void setSigD0(double);
      void setZ0(double);
      void setPtIso(double);
      void setEtIso(double);

      int getIsCombined() const;
      int getIsSegmentTagged() const;
      double getIdQOverP() const;
      double getIdTheta() const;
      double getMEQOverP() const;
      double getMETheta() const;
      double getTrackEta() const;
      double getQOverPRatio() const;
      int getNumBLayerHits() const;
      int getNumPixelHits() const;
      int getNumSctHits() const;
      int getNumSiHoles() const;
      int getNumTrtHits() const;
      double getTrtOlFraction() const;
      double getD0() const;
      double getSigD0() const;
      double getD0Significance() const;
      double getZ0() const;
      double getZ0SinTheta() const;
      double getPtIso() const;
      double getEtIso() const;

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
      double m_track_eta;
      double m_me_qoverp;
      double m_me_theta;
      double m_q_over_p_ratio;

      int m_num_b_layer_hits;
      int m_num_pixel_hits;
      int m_num_sct_hits;
      int m_num_si_holes;
      int m_num_trt_hits;
      double m_trt_ol_frac;

      double m_d0;
      double m_sig_d0;
      double m_z0;
      double m_pt_iso;
      double m_et_iso;

  };

  // =============================================================================
  class Tau : public Lepton
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Tau();
      Tau( const PennSusyFrame::D3PDReader*
         , int tau_index
         , PennSusyFrame::TauRescalerTool*
         , bool verbose = false
         );

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void setTauTlv( const PennSusyFrame::D3PDReader* reader
                    , PennSusyFrame::TauRescalerTool* tau_rescaler
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
         , int num_vertices_ge_2_tracks
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
      void setJvf(double);
      void setMv1(double);

      double getConstScaleE() const;
      double getConstScaleEta() const;
      double getConstScalePhi() const;
      double getConstScaleM() const;
      double getActiveAreaPx() const;
      double getActiveAreaPy() const;
      double getActiveAreaPz() const;
      double getActiveAreaE() const;
      double getJvf() const;
      double getMv1() const;

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void setJetTlv( const PennSusyFrame::D3PDReader* reader
                    , PennSusyFrame::JetRescalerTool*
                    , PennSusyFrame::Event*
                    , int num_vertices_ge_2_tracks
                    );

      double m_constscale_e;
      double m_constscale_eta;
      double m_constscale_phi;
      double m_constscale_m;
      double m_active_area_px;
      double m_active_area_py;
      double m_active_area_pz;
      double m_active_area_e;
      double m_jvf;
      double m_mv1;
  };

  // =============================================================================
  class Vertex : public PhysicsObject
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
      void setX(double);
      void setY(double);
      void setZ(double);
      void setE(double);
      void setM(double);

      int getVertexIndex() const;
      int getNumTracks() const;
      double getX() const;
      double getY() const;
      double getZ() const;
      double getE() const;
      double getM() const;

      void print() const;

      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      int m_vertex_index;
      int m_num_tracks;
      double m_x;
      double m_y;
      double m_z;
      double m_e;
      double m_m;
  };

  // =============================================================================
  class Met : public PhysicsObject
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
