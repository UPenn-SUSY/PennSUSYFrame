// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_ObjectCleaningTool_h
#define SelectionTools_ObjectCleaningTool_h

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/ToolBase.h"

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

    void eeOverlapRemoval( const std::vector<Electron*>& input_electrons
                         , std::vector<Electron*>& output_electrons
                         );
    void ejOverlapRemoval( const std::vector<Electron*>& input_electrons
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
