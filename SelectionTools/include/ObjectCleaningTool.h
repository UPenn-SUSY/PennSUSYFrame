// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_ObjectCleaningTool_h
#define SelectionTools_ObjectCleaningTool_h

// =============================================================================
#include <vector>
#include "AtlasSFrameUtils/include/ToolBase.h"

// =============================================================================
class TLorentzVector;
class Electron;
class Muon;
class Jet;
class Tau;
class ElectronContainer;
class MuonContainer;
class JetContainer;
class TauContainer;

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class ObjectCleaningTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    ObjectCleaningTool( SCycleBase* parent
                      , const char* name = "ObjectCleaning"
                      );
    virtual ~ObjectCleaningTool();

    void fullObjectCleaning( ElectronContainer& electrons
                           , MuonContainer&     muons
                           , TauContainer&      taus
                           , JetContainer&      jets
                           );
    void fullObjectCleaning( const std::vector<Electron*>& input_electrons
                           , const std::vector<Muon*>&     input_muons
                           , const std::vector<Tau*>&      input_taus
                           , const std::vector<Jet*>&      input_jets_good
                           , const std::vector<Jet*>&      input_jets_bad
                           , std::vector<Electron*>&       output_electrons
                           , std::vector<Muon*>&           output_muons
                           , std::vector<Tau*>&            output_taus
                           , std::vector<Jet*>&            output_jets_good
                           , std::vector<Jet*>&            output_jets_bad
                           );

    void eeOverlapRemoval( const std::vector<Electron*>& input_electrons
                         , std::vector<Electron*>& output_electrons
                         );
    void ejOverlapRemoval( const std::vector<Electron*>& input_electrons
                         , const std::vector<Jet*>& input_jets
                         , std::vector<Jet*>& output_jets
                         );
    void etOverlapRemoval( const std::vector<Electron*>& input_electrons
                         , const std::vector<Tau*>& input_taus
                         , std::vector<Tau*>& output_taus
                         );
    void mtOverlapRemoval( const std::vector<Muon*>& input_muons
                         , const std::vector<Tau*>& input_taus
                         , std::vector<Tau*>& output_taus
                         );
    void tjOverlapRemoval( const std::vector<Tau*>& input_taus
                         , const std::vector<Jet*>& input_jets
                         , std::vector<Jet*>& output_jets
                         );
    void jeOverlapRemoval( const std::vector<Electron*>& input_electrons
                         , const std::vector<Jet*>& input_jets
                         , std::vector<Electron*>& output_electrons
                         );
    void jmOverlapRemoval( const std::vector<Jet*>& input_jets
                         , const std::vector<Muon*>& input_muons
                         , std::vector<Muon*>& output_muon
                         );
    void emOverlapRemoval( const std::vector<Electron*>& input_electrons
                         , const std::vector<Muon*>& input_muons
                         , std::vector<Electron*>& output_electrons
                         , std::vector<Muon*>& output_muon
                         );
    void mmOverlapRemoval( const std::vector<Muon*>& input_muons
                         , std::vector<Muon*>& output_muon
                         );

    void mllOverlapRemoval( const std::vector<Electron*>& input_electrons
                          , const std::vector<Muon*>& input_muons
                          , std::vector<Electron*>& output_electrons
                          , std::vector<Muon*>& output_muon
                          );

    static bool overlap( TLorentzVector& tlv1
                       , TLorentzVector& tlv2
                       , double dr_max
                       );

  // --------------------------------------------------------------------------
  private:
    // = user configurables =
    double c_ee_cone_size;
    double c_ej_cone_size;
    double c_et_cone_size;
    double c_mt_cone_size;
    double c_tj_cone_size;
    double c_je_cone_size;
    double c_jm_cone_size;
    double c_em_cone_size;
    double c_mm_cone_size;
    double c_min_mll;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(ObjectCleaningTool, 0);
  };
}

#endif
