#ifndef ProgressBar_h
#define ProgressBar_h
// =============================================================================
// local includes
#include <string>

// =============================================================================
class ProgressBar
{
  // ---------------------------------------------------------------------------
  public:
    ProgressBar(unsigned int numEvents, unsigned int barLength = 50, bool fancy_draw = true);

    void setProcessLabel(std::string);
    void checkProgress(unsigned int event);
    void printProgressBar(unsigned int event);

  // ---------------------------------------------------------------------------
  private:
    const unsigned int m_numEvents;
    const unsigned int m_barLength;
    const unsigned int m_increment;
    unsigned int m_currentProgress;

    std::string m_process_label;
    bool m_fancy_draw;

    unsigned int m_startTime;

    void clearLine();
    std::string getRate(unsigned int event, float elapsed_time);
    std::string getRemainingTime(unsigned int event, float elapsed_time);
};

#endif
