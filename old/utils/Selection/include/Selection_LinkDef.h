// Dear emacs, this is -*- c++ -*-
// $Id$
#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;

// Add the declarations of your cycles, and any other classes for which you
// want to generate a dictionary, here. The usual format is:
//
// #pragma link C++ class MySuperClass+;

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class+protected Selection::EventSelection+;
// #pragma link C++ class Selection::MuonSelection+;
// #pragma link C++ class Selection::ElectronSelection+;
#pragma link C++ class+protected Selection::WeightHandler+;

#endif // __CINT__
