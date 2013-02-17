#include <iostream>
#include <sstream>

#include "include/ProgressBar.h"
// =============================================================================

// -----------------------------------------------------------------------------
ProgressBar::ProgressBar( int numEvents
                        , int barLength
                        )
                        : m_numEvents(numEvents)
                        , m_barLength(barLength)
                        , m_increment((numEvents/barLength)+1)
                        , m_currentProgress(0)
{
  // do nothing
}

// -----------------------------------------------------------------------------
void ProgressBar::checkProgress(int event)
{
  if (event%m_increment == 0) {
    ++m_currentProgress;
    printProgressBar(event);
  }
  if (event%10000 == 0 || event == m_numEvents-1) {
    printProgressBar(event);
  }
}

// -----------------------------------------------------------------------------
void ProgressBar::printProgressBar(int event)
{
  std::stringstream bar;
  bar << "\r<";
  for (int i = 0; i < m_barLength; ++i) {
    if (i <= m_currentProgress) bar << '=';
    else bar << '-';
  }
  bar << "> -- "
      << event << " of " << m_numEvents
      << " (" << (100*event)/m_numEvents << "%)";
  // if (event == m_numEvents) bar << '\n';
  if (event == m_numEvents-1) bar << '\n';

  std::cout << bar.str();
  std::cout.flush();
}
