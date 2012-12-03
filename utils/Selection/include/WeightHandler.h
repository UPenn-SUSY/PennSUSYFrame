#ifndef Selection_WeightHandler_h
#define Selection_WeightHandler_h

// ============================================================================
#include <sstream>

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

    std::string getWeightString();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool getDoMcEventWeight() const;
    bool getDoPileUpWeight() const;
    bool getDoLumiWeight() const;
    bool getDoTriggerWeight() const;
    bool getDoLeptonWeight() const;
    bool getDoBTagWeight() const;
    bool getDoCfWeight() const;
    bool getDoFakeWeight() const;

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
  };
}

#endif
