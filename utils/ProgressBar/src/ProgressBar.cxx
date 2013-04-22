#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>

#include "include/ProgressBar.h"
// =============================================================================

// -----------------------------------------------------------------------------
ProgressBar::ProgressBar( unsigned int numEvents
                        , unsigned int barLength
                        )
                        : m_numEvents(numEvents)
                        , m_barLength(barLength)
                        , m_increment((numEvents/barLength)+1)
                        , m_currentProgress(0)
                        // , m_startTime(0)
                        , m_startTime(clock())
{
  // do nothing
}

// -----------------------------------------------------------------------------
void ProgressBar::checkProgress(unsigned int event)
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
void ProgressBar::printProgressBar(unsigned int event)
{
  float elapsed_time = static_cast<float>(clock()-m_startTime)/CLOCKS_PER_SEC;
  // float rate = event/elapsed_time;
  // float remaining_time =  (m_numEvents-event)/elapsed_time;
  std::string rate           = getRate(         event, elapsed_time);
  std::string remaining_time = getRemainingTime(event, elapsed_time);

  // clearLine();
  std::stringstream bar;
  bar << "\r<";
  for (unsigned int i = 0; i < m_barLength; ++i) {
    if (i <= m_currentProgress) bar << '=';
    else bar << ' ';
  }
  bar << "> -- "
      << event << " of " << m_numEvents
      << " ("
      << static_cast<unsigned int>(100*(static_cast<float>(event)/m_numEvents))
      // << "%) [" << rate << " Hz - " << remaining_time << " s remaining]";
      << "%) [" << rate << " - " << remaining_time << " remaining]";

  // // Add whitespace to the end of the line to make sure previous text is gone
  // for (int it = 0; it != 30; ++it) {
  //   bar << " ";
  // }
  // Add new line for last line
  if (event == m_numEvents-1) bar << '\n';

  // Print to screen
  clearLine();
  std::cout << bar.str();
  std::cout.flush();
}

// -----------------------------------------------------------------------------
void ProgressBar::clearLine()
{
  std::cout << "\r";
  for (int it = 0; it != 150; ++it) {
    std::cout << " ";
  }
  std::cout.flush();
}

// -----------------------------------------------------------------------------
std::string ProgressBar::getRate(unsigned int event, float elapsed_time)
{
  if (event == 0) return "--";

  float rate = event/elapsed_time;
  int unit = 0;

  while (rate >= 1.e3 && unit < 3) {
    rate /= 1.e3;
    ++unit;
  }

  std::stringstream rate_str;
  rate_str << std::setprecision(5) << rate << " ";
  switch (unit) {
    case 0: rate_str << "Hz";
            break;
    case 1: rate_str << "kHz";
            break;
    case 2: rate_str << "MHz";
            break;
    case 3: rate_str << "GHz";
            break;
  }

  return rate_str.str();
}

// -----------------------------------------------------------------------------
std::string ProgressBar:: getRemainingTime(unsigned int event, float elapsed_time)
{
  if (event == 0)
    return "--";

  float remaining_time = (static_cast<float>(m_numEvents)/(event) - 1);
  remaining_time *= elapsed_time;
  int unit = 0;

  while (remaining_time > 60 && unit < 2) {
    remaining_time /= 60;
    ++unit;
  }

  std::stringstream remaining_time_str;
  remaining_time_str << std::setprecision(4) << remaining_time << " ";
  switch (unit) {
    case 0: remaining_time_str << "sec";
            break;
    case 1: remaining_time_str << "min";
            break;
    case 2: remaining_time_str << "hour";
            break;
  }

  return remaining_time_str.str();
}
