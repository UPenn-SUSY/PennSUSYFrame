#ifndef PennSusyFrame_SelectorsHelpers_h
#define PennSusyFrame_SelectorsHelpers_h

// ============================================================================
namespace PennSusyFrame
{
  template <class T>
    bool passCut(T val, T min, T max, bool inclusive_boundaries = true);
  template <class selector, class T>
    const std::vector<T*> selectObjects(selector& sel, std::vector<T*>* t);
  template <class selector, class T>
    const std::vector<T*> selectObjects(selector* sel, std::vector<T*>* t);
}

// Include the implementation:
#ifndef __CINT__
#include "SelectorHelpers.icc"
#endif // __CINT__

#endif
