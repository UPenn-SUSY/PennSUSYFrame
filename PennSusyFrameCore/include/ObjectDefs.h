#ifndef ObjectDefs_H
#define ObjectDefs_H

#include <vector>

#include "TLorentzVector.h"
#include "PennSusyFrameCore/include/RescalerTools.h"
#include "RootCore/MissingETUtility/MissingETUtility/METUtility.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
namespace PennSusyFrame
{
  class D3PDReader;

  class PhysicsObject;
  class Event;
  class Particle;
  class Lepton;
  class Electron;
  class Muon;
  class Jet;
  class Vertex;
  class Met;
}

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class PhysicsObject
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      // PhysicsObject();

      virtual void updateWithMet(const PennSusyFrame::Met&);
  };

  // =============================================================================
  class Event : public PhysicsObject
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Event();

      void init();
      void getEvent(const PennSusyFrame::D3PDReader*);

      virtual void updateWithMet(const PennSusyFrame::Met&);

      // TODO move accessors to cxx file
      void setIsData(bool val)              { m_is_data = val; }
      void setEventNumber(unsigned int val) { m_event_number = val; }
      void setRunNumber(unsigned int val)   { m_run_number = val; }
      void setLumiBlock(unsigned int val)   { m_lumi_block = val; }
      void setAverageIntPerXing(float val)  { m_average_int_per_xing = val; }
      void setEventShapeRhoKt4LC(float val) { m_eventshape_rhoKt4LC = val; }
      void setCoreFlags(unsigned int val)   { m_core_flags = val; }
      void setLarError(unsigned int val)    { m_lar_error = val; }
      void setTileError(unsigned int val)   { m_tile_error = val; }

      void setFlavorChannel(FLAVOR_CHANNEL val) { m_flavor_channel = val; }
      void setSignChannel(SIGN_CHANNEL val)     { m_sign_channel = val; }
      void setPhaseSpace(PHASE_SPACE val)       { m_phase_channel = val; }
      void setTriggerPhase(TRIG_PHASE val)      { m_trig_phase_channel = val; }

      void setPromptLeptons(bool val)            { m_prompt_leptons = val; }
      void setTruthSignChannel(SIGN_CHANNEL val) { m_truth_sign_channel = val; }

      // TODO move accessors to cxx file
      bool getIsData()              const { return m_is_data; }
      unsigned int getEventNumber() const { return m_event_number; }
      unsigned int getRunNumber()   const { return m_run_number; }
      unsigned int getLumiBlock()   const { return m_lumi_block; }
      float getAverageIntPerXing()  const { return m_average_int_per_xing; }
      float getEventShapeRhoKt4LC() const { return m_eventshape_rhoKt4LC; }
      unsigned int getCoreFlags()   const { return m_core_flags; }
      unsigned int getLarError()    const { return m_lar_error; }
      unsigned int getTileError()   const { return m_tile_error; }

      FLAVOR_CHANNEL getFlavorChannel() const { return m_flavor_channel; }
      SIGN_CHANNEL getSignChannel()     const { return m_sign_channel; }
      PHASE_SPACE getPhaseSpace()       const { return m_phase_channel; }
      TRIG_PHASE getTriggerPhase()      const { return m_trig_phase_channel; }

      bool getPromptLeptons()            const { return m_prompt_leptons; }
      SIGN_CHANNEL getTruthSignChannel() const { return m_truth_sign_channel; }

      void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      bool m_is_data;

      unsigned int m_event_number;
      unsigned int m_run_number;
      unsigned int m_lumi_block;

      float m_average_int_per_xing;
      float m_eventshape_rhoKt4LC;

      unsigned int m_core_flags;
      unsigned int m_lar_error;
      unsigned int m_tile_error;

      FLAVOR_CHANNEL m_flavor_channel;
      SIGN_CHANNEL m_sign_channel;
      PHASE_SPACE m_phase_channel;
      TRIG_PHASE m_trig_phase_channel;

      bool m_prompt_leptons;
      SIGN_CHANNEL m_truth_sign_channel;
  };

  // =============================================================================
  class EventLevelQuantities : public PhysicsObject
  {
    public:
      EventLevelQuantities();

      void init();

      // TODO move accessors to cxx file
      void setMll(                double val) { m_mll                   = val; }
      void setMbb(                double val) { m_mbb                   = val; }
      void setPtll(               double val) { m_ptll                  = val; }
      void setPtbb(               double val) { m_ptbb                  = val; }
      void setMt2(                double val) { m_mt2                   = val; }
      void setEmmaMt(             double val) { m_emma_mt               = val; }
      void setDphill(             double val) { m_dphi_ll               = val; }
      void setHtAll(              double val) { m_ht_all                = val; }
      void setHtBaseline(         double val) { m_ht_baseline           = val; }
      void setHtGood(             double val) { m_ht_good               = val; }
      void setHtSignal(           double val) { m_ht_signal             = val; }
      void setMcEventWeight(      double val) { m_mc_event_weight       = val; }
      void setPileUpSF(           double val) { m_pile_up_sf            = val; }
      void setLeptonSF(           double val) { m_lepton_sf             = val; }
      void setLeptonSFEgammaUp(   double val) { m_lepton_sf_egamma_up   = val; }
      void setLeptonSFEgammaDown( double val) { m_lepton_sf_egamma_down = val; }
      void setLeptonSFMuonUp(     double val) { m_lepton_sf_muon_up     = val; }
      void setLeptonSFMuonDown(   double val) { m_lepton_sf_muon_down   = val; }
      void setTriggerWeight(      double val) { m_trigger_weight        = val; }
      void setBTagSF(             double val) { m_b_tag_sf              = val; }
      void setBTagSFUp(           double val) { m_b_tag_sf_up           = val; }
      void setBTagSFDown(         double val) { m_b_tag_sf_down         = val; }
      void setCFWeight(           double val) { m_cf_weight             = val; }
      void setFakeWeight(         double val) { m_fake_weight           = val; }


      // TODO move accessors to cxx file
      double getMll()                const { return m_mll;                   }
      double getMbb()                const { return m_mbb;                   }
      double getPtll()               const { return m_ptll;                  }
      double getPtbb()               const { return m_ptbb;                  }
      double getMt2()                const { return m_mt2;                   }
      double getEmmaMt()             const { return m_emma_mt;               }
      double getDphill()             const { return m_dphi_ll;               }
      double getHtAll()              const { return m_ht_all;                }
      double getHtBaseline()         const { return m_ht_baseline;           }
      double getHtGood()             const { return m_ht_good;               }
      double getHtSignal()           const { return m_ht_signal;             }
      double getMcEventWeight()      const { return m_mc_event_weight;       }
      double getPileUpSF()           const { return m_pile_up_sf;            }
      double getLeptonSFEgammaUp()   const { return m_lepton_sf_egamma_up;   }
      double getLeptonSFEgammaDown() const { return m_lepton_sf_egamma_down; }
      double getLeptonSFMuonUp()     const { return m_lepton_sf_muon_up;     }
      double getLeptonSFMuonDown()   const { return m_lepton_sf_muon_down;   }
      double getLeptonSF()           const { return m_lepton_sf;             }
      double getTriggerWeight()      const { return m_trigger_weight;        }
      double getBTagSF()             const { return m_b_tag_sf;              }
      double getBTagSFUp()           const { return m_b_tag_sf_up;           }
      double getBTagSFDown()         const { return m_b_tag_sf_down;         }
      double getCFWeight()           const { return m_cf_weight;             }
      double getFakeWeight()         const { return m_fake_weight;           }

      void print() const;

    protected:
      double m_mll;
      double m_mbb;
      double m_ptll;
      double m_ptbb;
      double m_mt2;
      double m_emma_mt;
      double m_dphi_ll;
      double m_ht_all;
      double m_ht_baseline;
      double m_ht_good;
      double m_ht_signal;
      double m_mc_event_weight;
      double m_pile_up_sf;
      double m_lepton_sf;
      double m_lepton_sf_egamma_up;
      double m_lepton_sf_egamma_down;
      double m_lepton_sf_muon_up;
      double m_lepton_sf_muon_down;
      double m_trigger_weight;
      double m_b_tag_sf;
      double m_b_tag_sf_up;
      double m_b_tag_sf_down;
      double m_cf_weight;
      double m_fake_weight;

  };

  // =============================================================================
  class Trigger : public PhysicsObject
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Trigger();

      void init();
      void getEvent(const PennSusyFrame::D3PDReader*);

      // TODO move accessors to cxx file
      void setEF_2e12Tvh_loose1(bool val)           { m_EF_2e12Tvh_loose1           = val; }
      void setEF_e24vh_medium1_e7_medium1(bool val) { m_EF_e24vh_medium1_e7_medium1 = val; }
      void setEF_2mu13(bool val)                    { m_EF_2mu13                    = val; }
      void setEF_mu18_tight_mu8_EFFS(bool val)      { m_EF_mu18_tight_mu8_EFFS      = val; }
      void setEF_e12Tvh_medium1_mu8(bool val)       { m_EF_e12Tvh_medium1_mu8       = val; }
      void setEF_mu18_tight_e7_medium1(bool val)    { m_EF_mu18_tight_e7_medium1    = val; }

      void setTrig_EF_el_E(                             std::vector<float>* val) { m_trig_EF_el_E                                    = val; }
      void setTrig_EF_el_EF_e12Tvh_loose1(              std::vector<int>* val)   { m_trig_EF_el_EF_e12Tvh_loose1                     = val; }
      void setTrig_EF_el_EF_e12Tvh_medium1(             std::vector<int>* val)   { m_trig_EF_el_EF_e12Tvh_medium1                    = val; }
      void setTrig_EF_el_EF_e24vh_medium1(              std::vector<int>* val)   { m_trig_EF_el_EF_e24vh_medium1                     = val; }
      void setTrig_EF_el_EF_e24vh_medium1_e7_medium1(   std::vector<int>* val)   { m_trig_EF_el_EF_e24vh_medium1_e7_medium1          = val; }
      void setTrig_EF_el_EF_e7T_medium1(                std::vector<int>* val)   { m_trig_EF_el_EF_e7T_medium1                       = val; }
      void setTrig_EF_el_px(                            std::vector<float>* val) { m_trig_EF_el_px                                   = val; }
      void setTrig_EF_el_py(                            std::vector<float>* val) { m_trig_EF_el_py                                   = val; }
      void setTrig_EF_el_pz(                            std::vector<float>* val) { m_trig_EF_el_pz                                   = val; }
      void setTrig_EF_trigmuonef_EF_mu13(               std::vector<int>* val)   { m_trig_EF_trigmuonef_EF_mu13                      = val; }
      void setTrig_EF_trigmuonef_EF_mu18_tight(         std::vector<int>* val)   { m_trig_EF_trigmuonef_EF_mu18_tight                = val; }
      void setTrig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS(std::vector<int>* val)   { m_trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS       = val; }
      void setTrig_EF_trigmuonef_EF_mu8(                std::vector<int>* val)   { m_trig_EF_trigmuonef_EF_mu8                       = val; }
      void setTrig_EF_trigmuonef_track_CB_eta(          std::vector<std::vector<float> >* val) { m_trig_EF_trigmuonef_track_CB_eta   = val; }
      void setTrig_EF_trigmuonef_track_CB_hasCB(        std::vector<std::vector<int> >* val)   { m_trig_EF_trigmuonef_track_CB_hasCB = val; }
      void setTrig_EF_trigmuonef_track_CB_phi(          std::vector<std::vector<float> >* val) { m_trig_EF_trigmuonef_track_CB_phi   = val; }
      void setTrig_EF_trigmuonef_track_CB_pt (          std::vector<std::vector<float> >* val) { m_trig_EF_trigmuonef_track_CB_pt    = val; }

      // TODO move accessors to cxx file
      bool getEF_2e12Tvh_loose1()           const { return m_EF_2e12Tvh_loose1; }
      bool getEF_e24vh_medium1_e7_medium1() const { return m_EF_e24vh_medium1_e7_medium1; }
      bool getEF_2mu13()                    const { return m_EF_2mu13; }
      bool getEF_mu18_tight_mu8_EFFS()      const { return m_EF_mu18_tight_mu8_EFFS; }
      bool getEF_e12Tvh_medium1_mu8()       const { return m_EF_e12Tvh_medium1_mu8; }
      bool getEF_mu18_tight_e7_medium1()    const { return m_EF_mu18_tight_e7_medium1; }

      std::vector<float>* getTrig_EF_el_px()                                   const { return m_trig_EF_el_px; }
      std::vector<float>* getTrig_EF_el_py()                                   const { return m_trig_EF_el_py; }
      std::vector<float>* getTrig_EF_el_pz()                                   const { return m_trig_EF_el_pz; }
      std::vector<std::vector<float> >* getTrig_EF_trigmuonef_track_CB_eta()   const { return m_trig_EF_trigmuonef_track_CB_eta; }
      std::vector<std::vector<float> >* getTrig_EF_trigmuonef_track_CB_phi()   const { return m_trig_EF_trigmuonef_track_CB_phi; }
      std::vector<std::vector<float> >* getTrig_EF_trigmuonef_track_CB_pt ()   const { return m_trig_EF_trigmuonef_track_CB_pt; }
      std::vector<float>* getTrig_EF_el_E()                                    const { return m_trig_EF_el_E; }
      std::vector<int>*   getTrig_EF_el_EF_e12Tvh_loose1()                     const { return m_trig_EF_el_EF_e12Tvh_loose1; }
      std::vector<int>*   getTrig_EF_el_EF_e12Tvh_medium1()                    const { return m_trig_EF_el_EF_e12Tvh_medium1; }
      std::vector<int>*   getTrig_EF_el_EF_e24vh_medium1()                     const { return m_trig_EF_el_EF_e24vh_medium1; }
      std::vector<int>*   getTrig_EF_el_EF_e24vh_medium1_e7_medium1()          const { return m_trig_EF_el_EF_e24vh_medium1_e7_medium1; }
      std::vector<int>*   getTrig_EF_el_EF_e7T_medium1()                       const { return m_trig_EF_el_EF_e7T_medium1; }
      std::vector<int>*   getTrig_EF_trigmuonef_EF_mu13()                      const { return m_trig_EF_trigmuonef_EF_mu13; }
      std::vector<int>*   getTrig_EF_trigmuonef_EF_mu18_tight()                const { return m_trig_EF_trigmuonef_EF_mu18_tight; }
      std::vector<int>*   getTrig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS()       const { return m_trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS; }
      std::vector<int>*   getTrig_EF_trigmuonef_EF_mu8()                       const { return m_trig_EF_trigmuonef_EF_mu8; }
      std::vector<std::vector<int> >*   getTrig_EF_trigmuonef_track_CB_hasCB() const { return m_trig_EF_trigmuonef_track_CB_hasCB; }

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      bool m_EF_2e12Tvh_loose1;
      bool m_EF_e24vh_medium1_e7_medium1;
      bool m_EF_2mu13;
      bool m_EF_mu18_tight_mu8_EFFS;
      bool m_EF_e12Tvh_medium1_mu8;
      bool m_EF_mu18_tight_e7_medium1;

      std::vector<float>* m_trig_EF_el_px;
      std::vector<float>* m_trig_EF_el_py;
      std::vector<float>* m_trig_EF_el_pz;
      std::vector<std::vector<float> >* m_trig_EF_trigmuonef_track_CB_eta;
      std::vector<std::vector<float> >* m_trig_EF_trigmuonef_track_CB_phi;
      std::vector<std::vector<float> >* m_trig_EF_trigmuonef_track_CB_pt;
      std::vector<float>* m_trig_EF_el_E;
      std::vector<int>* m_trig_EF_el_EF_e12Tvh_loose1;
      std::vector<int>* m_trig_EF_el_EF_e12Tvh_medium1;
      std::vector<int>* m_trig_EF_el_EF_e24vh_medium1;
      std::vector<int>* m_trig_EF_el_EF_e24vh_medium1_e7_medium1;
      std::vector<int>* m_trig_EF_el_EF_e7T_medium1;
      std::vector<int>* m_trig_EF_trigmuonef_EF_mu13;
      std::vector<int>* m_trig_EF_trigmuonef_EF_mu18_tight;
      std::vector<int>* m_trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS;
      std::vector<int>* m_trig_EF_trigmuonef_EF_mu8;
      std::vector<std::vector<int> >* m_trig_EF_trigmuonef_track_CB_hasCB;


  // trig_EF_el_EF_e12Tvh_loose1
  // trig_EF_el_EF_e24vh_medium1
  // trig_EF_el_EF_e24vh_medium1
  // trig_EF_el_EF_e24vh_medium1_e7_medium1

  };

  // =============================================================================
  class Particle : public PhysicsObject
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Particle();

      virtual void printGeneralInfo() const;

      virtual void setParticleIndex(int val);

      virtual void setTlv(const TLorentzVector&);
      virtual void setRawTlv(const TLorentzVector&);

      void setIsSignal(bool val);

      virtual int getParticleIndex() const;

      virtual const TLorentzVector* getTlv() const;
      virtual const TLorentzVector* getRawTlv() const;

      bool getIsSignal() const;

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

      bool m_is_signal;
  };

  // =============================================================================
  class Lepton : public Particle
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      Lepton();

      // TODO move accessors to cxx file
      void setIsLightLepton(bool val) { m_is_light_lepton = val; }
      void setIsElectron(bool val) { m_is_electron = val; }
      void setCharge(double val) { m_charge = val; }
      void setTruthCharge(double val) { m_truth_charge = val; }
      void setTruthBarcode(int val) { m_truth_barcode = val; }
      void setTruthParentBarcode(int val) { m_truth_parent_barcode = val; }

      void setRawPtIso(double val) { m_raw_pt_iso = val; }
      void setRawEtIso(double val) { m_raw_et_iso = val; }
      void setPtIso(double val) { m_pt_iso = val; }
      void setEtIso(double val) { m_et_iso = val; }

      // TODO move accessors to cxx file
      bool isElectron() const { return (m_is_light_lepton && m_is_electron); }
      bool isMuon() const { return (m_is_light_lepton && !m_is_electron); }
      bool isTau() const { return !m_is_light_lepton; }
      double getCharge() const { return m_charge; }
      double getTruthCharge() const { return m_truth_charge; }
      int getTruthBarcode() const { return m_truth_barcode; }
      int getTruthParentBarcode() const { return m_truth_parent_barcode; }

      double getRawPtIso() const { return m_raw_pt_iso; }
      double getRawEtIso() const { return m_raw_et_iso; }
      double getPtIso() const { return m_pt_iso; }
      double getEtIso() const { return m_et_iso; }
      double getRawPtIsoRatio() const { return m_raw_pt_iso/(min(60.e3, getPt())); }
      double getRawEtIsoRatio() const { return m_raw_et_iso/(min(60.e3, getPt())); }
      double getPtIsoRatio() const { return m_pt_iso/(min(60.e3, getPt())); }
      double getEtIsoRatio() const { return m_et_iso/(min(60.e3, getPt())); }

      virtual void updateIsolation(const PennSusyFrame::Event*, int num_vtx);

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      bool m_is_light_lepton;
      bool m_is_electron;
      double m_charge;
      double m_truth_charge;
      int m_truth_barcode;
      int m_truth_parent_barcode;

      double m_raw_pt_iso;
      double m_raw_et_iso;
      double m_pt_iso;
      double m_et_iso;
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
              , bool is_data
              , bool verbose = false
              );

      // TODO move accessors to cxx file
      void setAuthor(int val) { m_author = val; }
      void setMediumPP(bool val) { m_medium_pp = val; }
      void setTightPP(bool val) { m_tight_pp = val; }
      void setPassOtx(bool val) { m_pass_otx = val; }
      void setClE(double val) { m_cl_E = val; }
      void setClEta(double val) { m_cl_eta = val; }
      void setClPhi(double val) { m_cl_phi = val; }
      void setD3PDEta(double val) { m_d3pd_eta = val; }
      void setD3PDPhi(double val) { m_d3pd_phi = val; }
      void setD0(double val) { m_d0 = val; }
      void setSigD0(double val) { m_sig_d0 = val; }
      void setZ0(double val) { m_z0 = val; }
      void setMetStatusWord(const std::vector<unsigned int>& val) { m_met_status_word = val; }
      void setMetWet(const std::vector<float>& val) { m_met_wet = val; }
      void setMetWpx(const std::vector<float>& val) { m_met_wpx = val; }
      void setMetWpy(const std::vector<float>& val) { m_met_wpy = val; }
      void setOrigin(int val) { m_origin = val; }
      void setType(int val) { m_type = val; }

      // TODO move accessors to cxx file
      int getAuthor() const { return m_author; }
      bool getMediumPP() const { return m_medium_pp; }
      bool getTightPP() const { return m_tight_pp; }
      bool getPassOTX() const { return m_pass_otx; }
      double getClE() const { return m_cl_E; }
      double getClEta() const { return m_cl_eta; }
      double getClPhi() const { return m_cl_phi; }
      double getD3PDEta() const { return m_d3pd_eta; }
      double getD3PDPhi() const { return m_d3pd_phi; }
      double getD0() const { return m_d0; }
      double getSigD0() const { return m_sig_d0; }
      double getD0Significance() const { return m_d0/m_sig_d0; }
      double getZ0() const { return m_z0; }
      double getZ0SinTheta() const { return m_z0*sin(m_tlv.Theta()); }
      std::vector<unsigned int> getMetStatusWord() const { return m_met_status_word; }
      std::vector<float>  getMetWet() const { return m_met_wet; }
      std::vector<float>  getMetWpx() const { return m_met_wpx; }
      std::vector<float>  getMetWpy() const { return m_met_wpy; }
      int getOrigin() const { return m_origin; }
      int getType() const { return m_type; }

      virtual void updateIsolation(const PennSusyFrame::Event*, int num_vtx);

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void setElTlv(const PennSusyFrame::D3PDReader* reader, PennSusyFrame::ElectronRescalerTool*);

      int m_author;
      bool m_medium_pp;
      bool m_tight_pp;
      bool m_pass_otx;
      double m_cl_E;
      double m_cl_eta;
      double m_cl_phi;
      double m_d3pd_eta;
      double m_d3pd_phi;
      double m_d0;
      double m_sig_d0;
      double m_z0;

      std::vector<unsigned int> m_met_status_word;
      std::vector<float> m_met_wet;
      std::vector<float> m_met_wpx;
      std::vector<float> m_met_wpy;

      int m_origin;
      int m_type;
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
          , bool is_data
          , bool verbose = false
          );

      // TODO move accessors to cxx file
      void setIsCombined(int val) { m_is_combined = val; }
      void setIsSegmentTagged(int val) { m_is_segment_tagged = val; }
      void setIdQOverP(double val) { m_id_qoverp = val; }
      void setIdTheta(double val) { m_id_theta = val; }
      void setMEQOverP(double val) { m_me_qoverp = val; }
      void setMETheta(double val) { m_me_theta = val; }
      void setTrackEta(double val) { m_track_eta = val; }
      void setQOverPRatio(double val) { m_q_over_p_ratio = val; }
      void setExpectBLayer(bool val) { m_expect_b_layer = val; }
      void setNumBLayerHits(int val) { m_num_b_layer_hits = val; }
      void setNumPixelHits(int val) { m_num_pixel_hits = val; }
      void setNumSctHits(int val) { m_num_sct_hits = val; }
      void setNumSiHoles(int val) { m_num_si_holes = val; }
      void setNumTrtHits(int val) { m_num_trt_hits = val; }
      void setTrtOlFraction(double val) { m_trt_ol_frac = val; }
      void setD0(double val) { m_d0 = val; }
      void setSigD0(double val) { m_sig_d0 = val; }
      void setZ0(double val) { m_z0 = val; }
      void setD0exPV(double val) { m_d0_exPV = val; }
      void setZ0exPV(double val) { m_z0_exPV = val; }

      void setMsQOverP(double val) { m_ms_q_over_p = val; }
      void setMsTheta(double val) { m_ms_theta = val; }
      void setMsPhi(double val) { m_ms_phi = val; }

      // void setTruthBarcode(int val) { m_truth_barcode = val; }

      // TODO move accessors to cxx file
      int getIsCombined() const { return m_is_combined; }
      int getIsSegmentTagged() const { return m_is_segment_tagged; }
      double getIdQOverP() const { return m_id_qoverp; }
      double getIdTheta() const { return m_id_theta; }
      double getMEQOverP() const { return m_me_qoverp; }
      double getMETheta() const { return m_me_theta; }
      double getTrackEta() const { return m_track_eta; }
      double getQOverPRatio() const { return m_q_over_p_ratio; }
      bool getExpectBLayer() const { return m_expect_b_layer; }
      int getNumBLayerHits() const { return m_num_b_layer_hits; }
      int getNumPixelHits() const { return m_num_pixel_hits; }
      int getNumSctHits() const { return m_num_sct_hits; }
      int getNumSiHoles() const { return m_num_si_holes; }
      int getNumTrtHits() const { return m_num_trt_hits; }
      double getTrtOlFraction() const { return m_trt_ol_frac; }
      double getD0() const { return m_d0; }
      double getSigD0() const { return m_sig_d0; }
      double getD0Significance() const { return m_d0/m_sig_d0; }
      double getZ0() const { return m_z0; }
      double getZ0SinTheta() const { return m_z0*sin(m_tlv.Theta()); }
      double getD0exPV() const { return m_d0_exPV; }
      double getZ0exPV() const { return m_z0_exPV; }

      double getMsQOverP() const { return m_ms_q_over_p; }
      double getMsTheta() const { return m_ms_theta; }
      double getMsPhi() const { return m_ms_phi; }

      // int getTruthBarcode() const { return m_truth_barcode; }

      virtual void updateIsolation(const PennSusyFrame::Event*, int num_vtx);

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

      bool m_expect_b_layer;
      int m_num_b_layer_hits;
      int m_num_pixel_hits;
      int m_num_sct_hits;
      int m_num_si_holes;
      int m_num_trt_hits;
      double m_trt_ol_frac;

      double m_d0;
      double m_sig_d0;
      double m_z0;
      double m_d0_exPV;
      double m_z0_exPV;

      double m_ms_q_over_p;
      double m_ms_theta;
      double m_ms_phi;

      // int m_truth_barcode;
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
         , bool is_data
         , bool verbose = false
         );

      // TODO move accessors to cxx file
      void setNumTracks(int val) { m_num_tracks = val; }
      void setJetBdtLoose(bool val) { m_jet_bdt_loose = val; }
      void setJetBdtMedium(bool val) { m_jet_bdt_medium = val; }
      void setJetBdtTight(bool val) { m_jet_bdt_tight = val; }
      void setEleBdtLoose(bool val) { m_ele_bdt_loose = val; }
      void setEleBdtMedium(bool val) { m_ele_bdt_medium = val; }
      void setEleBdtTight(bool val) { m_ele_bdt_tight = val; }
      void setMuVeto(bool val) { m_mu_veto = val; }

      // TODO move accessors to cxx file
      int getNumTracks() const { return m_num_tracks; }
      bool getJetBdtLoose()  const { return m_jet_bdt_loose; }
      bool getJetBdtMedium() const { return m_jet_bdt_medium; }
      bool getJetBdtTight()  const { return m_jet_bdt_tight; }
      bool getEleBdtLoose() const { return m_ele_bdt_loose; }
      bool getEleBdtMedium() const { return m_ele_bdt_medium; }
      bool getEleBdtTight() const { return m_ele_bdt_tight; }
      bool getMuVeto() const { return m_mu_veto; }

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void setTauTlv( const PennSusyFrame::D3PDReader* reader
                    , PennSusyFrame::TauRescalerTool* tau_rescaler
                    );

      int m_num_tracks;
      bool m_jet_bdt_loose;
      bool m_jet_bdt_medium;
      bool m_jet_bdt_tight;
      bool m_ele_bdt_loose;
      bool m_ele_bdt_medium;
      bool m_ele_bdt_tight;
      bool m_mu_veto;

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
         , bool is_data
         , bool verbose = false
         );

      virtual void updateWithMet(const PennSusyFrame::Met&);

      // TODO move accessors to cxx file
      void setConstScaleE(double val) { m_constscale_e = val; }
      void setConstScaleEta(double val) { m_constscale_eta = val; }
      void setConstScalePhi(double val) { m_constscale_phi = val; }
      void setConstScaleM(double val) { m_constscale_m = val; }
      void setActiveAreaPx(double val) { m_active_area_px = val; }
      void setActiveAreaPy(double val) { m_active_area_py = val; }
      void setActiveAreaPz(double val) { m_active_area_pz = val; }
      void setActiveAreaE(double val) { m_active_area_e = val; }
      void setJvf(double val) { m_jvf = val; }
      void setMv1(double val) { m_mv1 = val; }
      void setBchCorr(double val) { m_bch_corr = val; }
      void setBchCorrCell(double val) { m_bch_corr_cell = val; }
      void setDphiMet(double val) { m_dphi_met = val; }

      void setEmf(            double val) { m_emf               = val; }
      void setSumPtTrk(       double val) { m_sum_pt_trk        = val; }
      void setSamplingMax(    double val) { m_sampling_max      = val; } 
      void setFracSamplingMax(double val) { m_frac_sampling_max = val; } 
      void setHecQuality(     double val) { m_hec_quality       = val; }
      void setHecf(           double val) { m_hecf              = val; }
      void setAvgLarQf(       double val) { m_avg_lar_qf        = val; }
      void setNegativeE(      double val) { m_negative_e        = val; }
      void setLarQuality(     double val) { m_lar_quality       = val; }

      void setFlavorTruthLabel(int val) { m_flavor_truth_label = val; }

      void setIsBad(bool val) { m_is_bad = val; }
      void setMetStatusWord(const std::vector<unsigned int>& val) { m_met_status_word = val; }
      void setMetWet(const std::vector<float>& val) { m_met_wet = val; }
      void setMetWpx(const std::vector<float>& val) { m_met_wpx = val; }
      void setMetWpy(const std::vector<float>& val) { m_met_wpy = val; }

      // TODO move accessors to cxx file
      double getConstScaleE()   const { return m_constscale_e; }
      double getConstScaleEta() const { return m_constscale_eta; }
      double getConstScalePhi() const { return m_constscale_phi; }
      double getConstScaleM()   const { return m_constscale_m; }
      double getActiveAreaPx()  const { return m_active_area_px; }
      double getActiveAreaPy()  const { return m_active_area_py; }
      double getActiveAreaPz()  const { return m_active_area_pz; }
      double getActiveAreaE()   const { return m_active_area_e; }
      double getJvf()           const { return m_jvf; }
      double getMv1()           const { return m_mv1; }
      double getBchCorr()       const { return m_bch_corr; }
      double getBchCorrCell()   const { return m_bch_corr_cell; }
      double getDphiMet()       const { return m_dphi_met; }

      double getEmf()             const { return m_emf; }
      double getSumPtTrk()        const { return m_sum_pt_trk; }
      double getSamplingMax()     const { return m_sampling_max; }
      double getFracSamplingMax() const { return m_frac_sampling_max; }
      double getHecQuality()      const { return m_hec_quality; }
      double getHecf()            const { return m_hecf; }
      double getAvgLarQf()        const { return m_avg_lar_qf; }
      double getNegativeE()       const { return m_negative_e; }
      double getLarQuality()      const { return m_lar_quality; }

      int getFlavorTruthLabel() const { return m_flavor_truth_label; }

      bool getIsBad() const { return m_is_bad; }
      std::vector<unsigned int> getMetStatusWord() const { return m_met_status_word; }
      std::vector<float>  getMetWet() const { return m_met_wet; }
      std::vector<float>  getMetWpx() const { return m_met_wpx; }
      std::vector<float>  getMetWpy() const { return m_met_wpy; }

      virtual void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void setJetTlv( const PennSusyFrame::D3PDReader* reader
                    , PennSusyFrame::JetRescalerTool*
                    , PennSusyFrame::Event*
                    , int num_vertices_ge_2_tracks
                    );

      bool isBad();

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
      double m_bch_corr;
      double m_bch_corr_cell;
      double m_dphi_met;

      double m_emf;
      double m_sum_pt_trk;
      double m_sampling_max;
      double m_frac_sampling_max;
      double m_hec_quality;
      double m_hecf;
      double m_avg_lar_qf;
      double m_negative_e;
      double m_lar_quality;

      int m_flavor_truth_label;

      std::vector<unsigned int> m_met_status_word;
      std::vector<float>  m_met_wet;
      std::vector<float>  m_met_wpx;
      std::vector<float>  m_met_wpy;

      bool m_is_bad;
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

      // TODO move accessors to cxx file
      void setVertexIndex(int val) { m_vertex_index = val; }
      void setNumTracks(int val) { m_num_tracks = val; }
      void setX(double val) { m_x = val; }
      void setY(double val) { m_y = val; }
      void setZ(double val) { m_z = val; }
      void setE(double val) { m_e = val; }
      void setM(double val) { m_m = val; }

      // TODO move accessors to cxx file
      int getVertexIndex() const { return m_vertex_index; }
      int getNumTracks() const { return m_num_tracks; }
      double getX() const { return m_x; }
      double getY() const { return m_y; }
      double getZ() const { return m_z; }
      double getE() const { return m_e; }
      double getM() const { return m_m; }

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

      void init();

      void prep( const PennSusyFrame::D3PDReader*
               , const PennSusyFrame::Event&
               // , const PennSusyFrame::EventLevelQuantities&
               , const std::vector<PennSusyFrame::Electron*>*
               , const std::vector<PennSusyFrame::Muon*>*
               , const std::vector<PennSusyFrame::Jet*>*
               );
      void constructMetSig( const PennSusyFrame::EventLevelQuantities&);
      void constructMetRel( const std::vector<PennSusyFrame::Electron*>*
                          , const std::vector<PennSusyFrame::Muon*>*
                          , const std::vector<PennSusyFrame::Jet*>*
                          );

      const TVector2* getMetVec() const { return &m_met_vec; }
      double getMetEt()           const { return m_met_et; }
      double getMetPhi()          const { return m_met_phi; }
      double getMetRel()          const { return m_met_rel_et; }
      double getMetSigAll()       const { return m_met_sig_all; }
      double getMetSigBaseline()  const { return m_met_sig_baseline; }
      double getMetSigGood()      const { return m_met_sig_good; }
      double getMetSigSignal()    const { return m_met_sig_signal; }
      double getMinDPhiObj()      const { return m_dphi_met_nearest_obj; }
      double getDPhi(PennSusyFrame::Particle*) const;

      void clear();

      void print() const;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    protected:
      void addMet(const PennSusyFrame::D3PDReader*);
      void addElectrons(const std::vector<PennSusyFrame::Electron*>*);
      void addMuons(const std::vector<PennSusyFrame::Muon*>*);
      void addJets(const std::vector<PennSusyFrame::Jet*>*);
      void doWeightFix( std::vector<float>&
                      , std::vector<float>&
                      , std::vector<float>&
                      );
      double calculateMetSig(double met, double ht);
      template <class T>
        double findMinDphiInList(const std::vector<T*>&);

      bool m_prepared;

      METUtility m_met_utility;
      TVector2 m_met_vec;
      double m_met_et;
      double m_met_phi;
      double m_met_rel_et;
      double m_met_sig_all;
      double m_met_sig_baseline;
      double m_met_sig_good;
      double m_met_sig_signal;
      double m_dphi_met_nearest_obj;
  };

  // =============================================================================
  class MCTruth : public PhysicsObject
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      MCTruth();

      void clear();
      void getEvent(const PennSusyFrame::D3PDReader*);

      // TODO move accessors to cxx file
      void setChannelNumber(unsigned int val)  { m_mc_channel_number = val; }
      void setN(unsigned int val)              { m_mc_n              = val; }
      void setPt(std::vector<float>* val)      { m_mc_pt             = val; }
      void setEta(std::vector<float>* val)     { m_mc_eta            = val; }
      void setPhi(std::vector<float>* val)     { m_mc_phi            = val; }
      void setM(std::vector<float>* val)       { m_mc_m              = val; }
      void setPdgId(std::vector<int>* val)     { m_mc_pdg_id         = val; }
      void setStatus(std::vector<int>* val)    { m_mc_status         = val; }
      void setBarcode(std::vector<int>* val)   { m_mc_barcode        = val; }
      void setMuonBarcode(std::vector<int>* val) { m_muon_barcode    = val; }
      void setVxBarcode(std::vector<int>* val) { m_mc_vx_barcode     = val; }
      void setParentIndex(std::vector<std::vector<int> >* val) { m_mc_parent_index = val; }
      void setChildIndex(std::vector<std::vector<int> >* val)  { m_mc_child_index  = val; }
      void setParents(std::vector<std::vector<int> >* val)     { m_mc_parents = val;  }
      void setChildren(std::vector<std::vector<int> >* val)    { m_mc_children = val; }
      void setMuOrigin(std::vector<int>* val) { m_mc_mu_origin = val; }
      void setMuType(std::vector<int>* val)   { m_mc_mu_type = val; }
      void setCharge(std::vector<float>* val) { m_mc_charge = val; }

      bool isSherpa() const;

      // TODO move accessors to cxx file
      unsigned int getChannelNumber()  const { return m_mc_channel_number; }
      unsigned int getN()              const { return m_mc_n; }
      std::vector<float>* getPt()      const { return m_mc_pt; }
      std::vector<float>* getEta()     const { return m_mc_eta; }
      std::vector<float>* getPhi()     const { return m_mc_phi; }
      std::vector<float>* getM()       const { return m_mc_m; }
      std::vector<int>* getPdgId()     const { return m_mc_pdg_id; }
      std::vector<int>* getStatus()    const { return m_mc_status; }
      std::vector<int>* getBarcode()   const { return m_mc_barcode; }
      std::vector<int>* getMuonBarcode() const { return m_muon_barcode; }
      std::vector<int>* getVxBarcode() const { return m_mc_vx_barcode; }
      std::vector<std::vector<int> >* getParentIndex() const { return m_mc_parent_index; }
      std::vector<std::vector<int> >* getChildIndex()  const { return m_mc_child_index; }
      std::vector<std::vector<int> >* getParents()  const { return m_mc_parents; }
      std::vector<std::vector<int> >* getChildren() const { return m_mc_children; }
      std::vector<int>* getMuOrigin() const { return m_mc_mu_origin; }
      std::vector<int>* getMuType() const { return m_mc_mu_type; }
      std::vector<float>* getCharge() const { return m_mc_charge; }

      void writeFullTruthRecord(std::string out_file_name);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      unsigned int m_mc_channel_number;
      unsigned int m_mc_n;
      std::vector<float>* m_mc_pt;
      std::vector<float>* m_mc_eta;
      std::vector<float>* m_mc_phi;
      std::vector<float>* m_mc_m;
      std::vector<int>* m_mc_pdg_id;
      std::vector<int>* m_mc_status;
      std::vector<int>* m_mc_barcode;
      std::vector<int>* m_muon_barcode;
      std::vector<int>* m_mc_vx_barcode;
      std::vector<std::vector<int> >* m_mc_parent_index;
      std::vector<std::vector<int> >* m_mc_child_index;
      std::vector<std::vector<int> >* m_mc_parents;
      std::vector<std::vector<int> >* m_mc_children;
      std::vector<int>* m_mc_mu_origin;
      std::vector<int>* m_mc_mu_type;
      std::vector<float>* m_mc_charge;
  };
}

// Include the implementation:
#ifndef __CINT__
#include "ObjectDefs.icc"
#endif // __CINT__

#endif
