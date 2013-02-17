#ifndef ProgressBar_h
#define ProgressBar_h
// =============================================================================
// local includes

// =============================================================================
class ProgressBar
{
  // ---------------------------------------------------------------------------
  public:
    ProgressBar(int numEvents, int barLength = 50);

    void checkProgress(int event);
    void printProgressBar(int event);

  // ---------------------------------------------------------------------------
  private:
    const int m_numEvents;
    const int m_barLength;
    const int m_increment;
    int m_currentProgress;
};

#endif
