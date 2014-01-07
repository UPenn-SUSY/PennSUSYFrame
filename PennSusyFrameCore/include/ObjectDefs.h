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

      void setIsElectron(bool);
      void setCharge(double);

      bool isElectron() const;
      bool isMuon() const;
      double getCharge() const;

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
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
              // , PennSusyFrame::ElectronRescalerTool&
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
      void setElTlv(const PennSusyFrame::D3PDReader* reader);

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
          , bool verbose = false
          );

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void setMuTlv(const PennSusyFrame::D3PDReader* reader);
  };

  // =============================================================================
  class Jet : public Particle
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Jet();
      Jet( const PennSusyFrame::D3PDReader*
         , int jet_index
         , bool verbose = false
         );

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void setJetTlv(const PennSusyFrame::D3PDReader* reader);
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
