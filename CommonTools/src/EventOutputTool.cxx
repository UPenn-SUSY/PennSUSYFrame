#include "CommonTools/include/EventOutputTool.h"

#include <math.h>

#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// ----------------------------------------------------------------------------
CommonTools::EventOutputTool::EventOutputTool( SCycleBase* parent
                                                         , const char* name
                                                         )
                                                         : ToolBase(parent, name)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}
// -----------------------------------------------------------------------------
CommonTools::EventOutputTool::~EventOutputTool()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}
// -----------------------------------------------------------------------------
void CommonTools::EventOutputTool::BeginInputData( const SInputData& )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  DeclareVariable(m_lbn           , "lbn"         );
  DeclareVariable(m_run_number    , "run_number"  );
  DeclareVariable(m_event_number  , "event_number");

  DeclareVariable(m_event_desc_int, "event_desc");
  DeclareVariable(m_sr_helper_int , "sr_helper" );

  DeclareVariable(m_mc_event_weight        , "mc_event_weight"        );
  DeclareVariable(m_pileup_weight          , "pile_up_weight"         );
  DeclareVariable(m_trigger_weight         , "trigger_weight"         );
  DeclareVariable(m_lepton_weight          , "lepton_weight"          );
  DeclareVariable(m_b_tag_weight           , "b_tag_weight"           );
  DeclareVariable(m_cross_section_weight   , "cross_section_weight"   );
  DeclareVariable(m_k_factor               , "k_factor"               );
  DeclareVariable(m_eff_times_cross_section, "eff_times_cross_section");
  DeclareVariable(m_fake_weight            , "fake_weight_nom"        );
  DeclareVariable(m_fake_weight_max        , "fake_weight_max"        );
  DeclareVariable(m_fake_weight_min        , "fake_weight_min"        );
  DeclareVariable(m_charge_flip_weight     , "charge_flip_weight"     );
  DeclareVariable(m_charge_flip_weight_max , "charge_flip_weight_max" );
  DeclareVariable(m_charge_flip_weight_min , "charge_flip_weight_min" );

  DeclareVariable(m_mc_channel_number, "mc_channel_number");

  DeclareVariable(m_actual_int_per_crossing , "actual_int_per_crossing" );
  DeclareVariable(m_average_int_per_crossing, "average_int_per_crossing");

  //DeclareVariable(m_pass_top_tag_veto, "pass_top_tag_veto");

  DeclareVariable(m_ht          , "ht"          );
  DeclareVariable(m_ht_jets     , "ht_jets"     );
  DeclareVariable(m_ht_leptons  , "ht_leptons"  );
  DeclareVariable(m_mll         , "mll"         );
  DeclareVariable(m_ptll        , "ptll"        );
  DeclareVariable(m_phill       , "phill"       );
  DeclareVariable(m_etall       , "etall"       );
  DeclareVariable(m_dphill      , "dphill"      );
  DeclareVariable(m_mt          , "mt"          );
  DeclareVariable(m_mt2         , "mt2"         );
  DeclareVariable(m_meff        , "meff"        );
  DeclareVariable(m_meff_jets   , "meff_jets"   );
  DeclareVariable(m_meff_leptons, "meff_leptons");

}
// -----------------------------------------------------------------------------
void CommonTools::EventOutputTool::BeginExecuteEvent( const SInputData&, Double_t )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_run_number   = 0;
  m_event_number = 0;
  m_lbn          = 0;

  m_event_desc_int = 0;
  m_sr_helper_int = 0;

  m_mc_event_weight         = 1.;
  m_pileup_weight           = 1.;
  m_trigger_weight          = 1.;
  m_lepton_weight           = 1.;
  m_b_tag_weight            = 1.;
  m_cross_section_weight    = 1.;
  m_k_factor                = 1.;
  m_eff_times_cross_section = 1.;
  m_fake_weight             = 1.;
  m_fake_weight_max         = 1.;
  m_fake_weight_min         = 1.;
  m_charge_flip_weight      = 1.;
  m_charge_flip_weight_max  = 1.;
  m_charge_flip_weight_min  = 1.;

  m_mc_channel_number        = 0;
  m_actual_int_per_crossing  = 0;
  m_average_int_per_crossing = 0;

  m_ht           = 0.;
  m_ht_jets      = 0.;
  m_ht_leptons   = 0.;
  m_mll          = 0.;
  m_ptll         = 0.;
  m_phill        = 0.;
  m_etall        = 0.;
  m_dphill       = 0.;
  m_mt           = 0.;
  m_mt2          = 0.;
  m_meff         = 0.;
  m_meff_jets    = 0.;
  m_meff_leptons = 0.;
}

// -----------------------------------------------------------------------------
void CommonTools::EventOutputTool::fillOutput( Event* event
                                             , ElectronContainer& /*electrons*/
                                             , MuonContainer& /*muons*/
                                             , JetContainer& /*jets*/
                                             , Met* /*met*/
                                             , VertexContainer& /*vertices*/
                                             )
{
  m_logger << VERBOSE
           << "CommonTools::EventOutputTool::fillOutput"
           << SLogger::endmsg;

  m_lbn          = event->lbn();
  m_run_number   = event->RunNumber();
  m_event_number = event->EventNumber();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Fill event description as integer
  m_event_desc_int = event->getEventDesc()->toInt();
  m_sr_helper_int  = event->getSRHelper()->toInt();

  if (!is_data()) {
    m_mc_channel_number =  event->getMCChannelNum();
  }

  m_actual_int_per_crossing  = event->actualIntPerXing();
  m_average_int_per_crossing = event->averageIntPerXing();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Fill event weights
  m_mc_event_weight         = event->getMCEventWeight();
  m_pileup_weight           = event->getPileUpWeight();
  m_trigger_weight          = event->getTriggerWeight();
  m_lepton_weight           = event->getLeptonEffWeight();
  m_b_tag_weight            = event->getBTagWeight();
  m_cross_section_weight    = event->getCrossSectionWeight();
  m_k_factor                = event->getKFactor();
  m_eff_times_cross_section = event->getEffTimesXS();

  m_ht           = event->getHt();
  m_ht_jets      = event->getHtJets();
  m_ht_leptons   = event->getHtLeptons();
  m_mll          = event->getMll();
  m_ptll         = event->getPtll();
  m_phill        = event->getPhill();
  m_etall        = event->getEtall();
  m_dphill       = event->getDeltaPhill();
  m_mt           = event->getMt();
  m_mt2          = event->getMt2();
  m_meff         = event->getMeff();
  m_meff_jets    = event->getMeffJets();
  m_meff_leptons = event->getMeffLeptons();


  m_fake_weight = event->getFakeWeight();
//  m_fake_weight_min =;
//  m_fake_weight_max =;
//
  m_charge_flip_weight = event->getChargeFlipWeight();
//  m_charge_flip_weight_min =;
//  m_charge_flip_weight_max =;
}
