#ifndef ProgressBar_h
#define ProgressBar_h
// =============================================================================
// local includes

// =============================================================================
class ProgressBar
{
  // ---------------------------------------------------------------------------
  public:
    ProgressBar(unsigned int numEvents, unsigned int barLength = 50);

    void checkProgress(unsigned int event);
    void printProgressBar(unsigned int event);

  // ---------------------------------------------------------------------------
  private:
    const unsigned int m_numEvents;
    const unsigned int m_barLength;
    const unsigned int m_increment;
    unsigned int m_currentProgress;

    unsigned int m_startTime;

    void clearLine();
    std::string getRate(unsigned int event, float elapsed_time);
    std::string getRemainingTime(unsigned int event, float elapsed_time);
};

#endif
