// file:        Met.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     October 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Met_h
#define AtlasSFrameUtils_Met_h

// =============================================================================
#include <vector>

#include "TLorentzVector.h"

#include "D3PDObjects/include/METD3PDObject.h"
#include "MissingETUtility/METUtility.h"

// =============================================================================
class Electron;
class Event;
class Muon;
class Jet;

class ElectronContainer;
class MuonContainer;
class JetContainer;

// =============================================================================
class Met : public D3PDReader::METD3PDObject
{
public:
  // main constructor
  Met(const ::Long64_t& master, const char* prefix = "", bool is_data = true );

  void init(std::string jet_algo);
  void clear();
  void prep(Event*, ElectronContainer*, MuonContainer* , JetContainer*);


  TVector2 getMetRefFinalVec() const;
  double   getMetRefFinalEt()  const;
  double   getMetRefFinalPhi() const;

  static double getMetRel( const Met*
                         , const std::vector<Electron*>&
                         , const std::vector<Muon*>&
                         , const std::vector<Jet*>&
                         );

  void print( const std::vector<Electron*>&
            , const std::vector<Muon*>&
            , const std::vector<Jet*>&
            );

private:
  bool m_prepared;
  std::string m_jet_algo;
  METUtility m_met_utility;

  void addElectrons(ElectronContainer*);
  void addJets(JetContainer*);
  void addMet();
  void addMuons(MuonContainer*);

  template <class T>
    static double getMinPhi(const Met*, const std::vector<T*>&);

  TVector2 m_met_vec;

  ClassDef(Met, 1);
};

// Include the implementation:
#ifndef __CINT__
#include "Met.icc"
#endif // __CINT__

#endif // AtlasSFrameUtils_Met_h
