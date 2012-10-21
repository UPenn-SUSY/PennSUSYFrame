// file:        Met.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     October 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Met_h
#define AtlasSFrameUtils_Met_h

#include <iostream>
#include "D3PDObjects/include/METD3PDObject.h"

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"

#include "MissingETUtility/METUtility.h"

// ============================================================================
class Met : public D3PDReader::METD3PDObject
{
public:
  // main constructor
  Met(const ::Long64_t& master, const char* prefix = "", bool is_data = true );

  void init(std::string jet_algo);
  void clear();
  void prep(Event*, ElectronContainer*, MuonContainer* , JetContainer*);

private:
  bool m_prepared;
  std::string m_jet_algo;
  METUtility m_met_utility;

  void addElectrons(ElectronContainer*);
  void addJets(JetContainer*);
  void addMet();
  void addMuons(MuonContainer*);

  ClassDef(Met, 1);
};


#endif // AtlasSFrameUtils_Met_h
