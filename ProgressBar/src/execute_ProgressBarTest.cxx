#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "ProgressBar/include/ProgressBar.h"

// -----------------------------------------------------------------------------
int main(int /*argc*/, char** /*argv*/)
{
  std::cout << "Testing progress bar!\n";

  const unsigned int num_test = 1e9;
  ProgressBar test_progress_bar(num_test);
  for (unsigned int it = 0; it != num_test; ++it) {
    for (unsigned int it2 = 0; it2 != 10000; ++it2) {
      // do nothing
    }
    test_progress_bar.checkProgress(it);
  }
}
