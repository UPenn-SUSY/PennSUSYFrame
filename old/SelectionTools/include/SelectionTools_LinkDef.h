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
#pragma link C++ class SelectionTools::ElectronSelectionTool+;
#pragma link C++ class SelectionTools::EventCleaningTool+;
#pragma link C++ class SelectionTools::EventPicker+;
#pragma link C++ class SelectionTools::GoodRunsListTool+;
#pragma link C++ class SelectionTools::JetSelectionTool+;
#pragma link C++ class SelectionTools::MuonSelectionTool+;
#pragma link C++ class SelectionTools::ObjectCleaningTool+;
#pragma link C++ class SelectionTools::TauSelectionTool+;
#pragma link C++ class SelectionTools::TriggerCutTool+;
#pragma link C++ class SelectionTools::SignalRegionTool+;
// #pragma link C++ class SelectionTools::ControlRegionTool+;
#pragma link C++ class SelectionTools::HFORTool+;

#endif // __CINT__
