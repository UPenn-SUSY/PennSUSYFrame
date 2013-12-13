#ifndef Selection_WeightHandler_h
#define Selection_WeightHandler_h

// ============================================================================
#include <sstream>

#include "LumiWeight.h"

// ============================================================================
namespace Selection
{
  // ============================================================================
  class WeightHandler
  {
  // ----------------------------------------------------------------------------
  public:
    WeightHandler();
    WeightHandler(const WeightHandler&);
    ~WeightHandler();

    WeightHandler& operator=(const WeightHandler&);

    std::string getWeightString();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void setGlobalDoMcEventWeight(bool);
    void setGlobalDoPileUpWeight(bool);
    void setGlobalDoLumiWeight(bool);
    void setGlobalDoTriggerWeight(bool);
    void setGlobalDoLeptonWeight(bool);
    void setGlobalDoBTagWeight(bool);
    void setGlobalDoCfWeight(bool);
    void setGlobalDoFakeWeight(bool);

    void setLocalDoMcEventWeight(bool);
    void setLocalDoPileUpWeight(bool);
    void setLocalDoLumiWeight(bool);
    void setLocalDoTriggerWeight(bool);
    void setLocalDoLeptonWeight(bool);
    void setLocalDoBTagWeight(bool);
    void setLocalDoCfWeight(bool);
    void setLocalDoFakeWeight(bool);

    void setNumEvents(double);
    void setMcChannel(int);
    void setTargetLumi(int);
    void setModeledInFile(double);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool getDoMcEventWeight() const;
    bool getDoPileUpWeight() const;
    bool getDoLumiWeight() const;
    bool getDoTriggerWeight() const;
    bool getDoLeptonWeight() const;
    bool getDoBTagWeight() const;
    bool getDoCfWeight() const;
    bool getDoFakeWeight() const;

    double getNumEvents() const;
    int getMcChannel() const;
    int getTargetLumi() const;
    double getModeledInFile() const;

  // ---------------------------------------------------------------------------
  private:
    bool m_do_mc_event_weight;
    bool m_do_pile_up_weight;
    bool m_do_lumi_weight;
    bool m_do_trigger_weight;
    bool m_do_lepton_weight;
    bool m_do_b_tag_weight;
    bool m_do_cf_weight;
    bool m_do_fake_weight;

    double m_num_events;
    int m_mc_channel;
    int m_target_lumi;
    int m_modeled_in_file;

    LumiWeight* m_lumi_weight;
    bool m_lumi_weight_prepped;
  };
}

#endif
