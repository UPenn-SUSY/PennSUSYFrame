#ifndef PennSusyFrame_PennSusyFrameEnums_h
#define PennSusyFrame_PennSusyFrameEnums_h

#include <string>

// define ull_t type == unsigned long long
typedef unsigned long long ull_t;

// enum to define flavor channels
enum FLAVOR_CHANNEL { FLAVOR_NONE = 0 // no flavor
                    , FLAVOR_EE   = 1 // ee event
                    , FLAVOR_MM   = 2 // mm event
                    , FLAVOR_EM   = 4 // em event
                    , FLAVOR_N
                    };
const std::string FLAVOR_CHANNEL_STRINGS[] = { "flavor_all"  // 0
                                             , "flavor_ee"    // 1
                                             , "flavor_mm"    // 2
                                             , "flavor_error" // 3
                                             , "flavor_em"    // 4
                                             };

// enum to defint phase space
enum PHASE_SPACE { PHASE_NONE = 0 // No phase space
                 , PHASE_EE   = 1 // ee phase space
                 , PHASE_MM   = 2 // mm phase space
                 , PHASE_EM   = 4 // em phase space
                 , PHASE_ME   = 8 // me phase space
                 , PHASE_N
                 };
const std::string PHASE_CHANNEL_STRINGS[] = { "phase_none"  // 0
                                            , "phase_ee"    // 1
                                            , "phase_mm"    // 2
                                            , "phase_error" // 3
                                            , "phase_em"    // 4
                                            , "phase_error" // 5
                                            , "phase_error" // 6
                                            , "phase_error" // 7
                                            , "phase_me"    // 8
                                            };

// enum to define sign channel OS/SS
enum SIGN_CHANNEL { SIGN_NONE = 0 // no sign channel
                  , SIGN_OS   = 1 // OS event
                  , SIGN_SS   = 2 // SS event
                  , SIGN_N
                  };
const std::string SIGN_CHANNEL_STRINGS[] = { "sign_none"  // 0
                                           , "sign_os"    // 1
                                           , "sign_ss"    // 2
                                           };

// enum to define trigger pahse space -- specific to EWK analysis
enum TRIG_PHASE { TRIG_NONE = 0 // No Trigger phase
                , TRIG_EE_A     // EE region A
                , TRIG_EE_B     // EE region B
                , TRIG_MM_A     // MM region A
                , TRIG_MM_B     // MM region B
                , TRIG_MM_C     // MM region C
                , TRIG_MM_D     // MM region D
                , TRIG_EM_A     // EM region A
                , TRIG_EM_B     // EM region B
                , TRIG_N
                };
const std::string TRIG_PHASE_STRINGS[] = { "trig_none"
                                         , "trig_ee_a"
                                         , "trig_ee_b"
                                         , "trig_mm_a"
                                         , "trig_mm_b"
                                         , "trig_mm_c"
                                         , "trig_mm_d"
                                         , "trig_em_a"
                                         , "trig_em_b"
                                         };

// enum to define electron collections
enum ELECTRON_COLLECTIONS { EL_ALL = 0  // Green tree snake
                          , EL_BASELINE // Baseline cuts
                          , EL_GOOD     // Baseline + overlap removal
                          , EL_SIGNAL   // Signal cuts
                          , EL_N
                          };
const std::string ELECTRON_COLLECTIONS_STRINGS[] = { "el_all"
                                                   , "el_baseline"
                                                   , "el_good"
                                                   , "el_signal"
                                                   };

// enum to define jet collections
enum JET_COLLECTIONS { JET_ALL = 0       // Green tree snake
                     , JET_BASELINE      // Baseline cuts
                     , JET_BASELINE_GOOD // Baseline cuts
                     , JET_BASELINE_BAD  // Baseline cuts
                     , JET_CALO_PROBLEM  // Baseline cuts
                     , JET_BAD           // Baseline + overlap removal
                     , JET_GOOD          // Baseline + overlap removal
                     , JET_LIGHT         // Light central cuts
                     , JET_B             // B-jet cuts
                     , JET_FORWARD       // Forward cuts
                     , JET_ALL_SIGNAL    //Signal light+b+forward
                     , JET_ALL_CENTRAL   //Signal light+b
                     , JET_N
                     };
const std::string JET_COLLECTIONS_STRINGS[] = { "jet_all"
                                              , "jet_baseline"
                                              , "jet_baseline_good"
                                              , "jet_baseline_bad"
                                              , "jet_calo_problem"
                                              , "jet_bad"
                                              , "jet_good"
                                              , "jet_light"
                                              , "jet_b"
                                              , "jet_forward"
                                              , "jet_all_signal"
                                              , "jet_all_central"
                                              };

// enum to define muon collections
enum MUON_COLLECTIONS { MU_ALL = 0  // Green tree snake
                      , MU_BASELINE // Baseline cuts
                      , MU_GOOD     // Baseline + overlap removal
                      , MU_SIGNAL   // Signal cuts
                      , MU_BAD      // Bad muons
                      , MU_COSMIC   // Cosmic muons
                      , MU_N
                      };
const std::string MUON_COLLECTIONS_STRINGS[] = { "mu_all"
                                               , "mu_baseline"
                                               , "mu_good"
                                               , "mu_signal"
                                               , "mu_bad"
                                               , "mu_cosmic"
                                               };

// enum to define tau collections
enum TAU_COLLECTIONS { TAU_ALL = 0
                     , TAU_BASELINE
                     , TAU_GOOD
                     , TAU_SIGNAL
                     , TAU_N
                     };
const std::string TAU_COLLECTIONS_STRINGS[] = { "tau_all"
                                              , "tau_baseline"
                                              , "tau_good"
                                              , "tau_signal"
                                              };

// enum to define vertex collections
enum VERTEX_COLLECTIONS { VERTEX_ALL = 0  // Green tree snake
                        , VERTEX_GOOD     // Vertices flagged as good
                        , VERTEX_GT_2     // Vertices with more than two tracks
                        , VERTEX_N
                        };
const std::string VERTEX_COLLECTIONS_STRINGS[] = { "vertex_all"
                                                 , "vertex_good"
                                                 , "vertex_gt_2"
                                                 };

// enum ISO_TYPE { PTCONE = 0
//               , ETCONE
//               , TOPOETCONE
//               , TOPOETCONE_CORR
//               , REL_PTCONE
//               , REL_ETCONE
//               , REL_TOPOETCONE
//               , REL_TOPOETCONE_CORR
//               };

// enum to define electron quality level
enum ELECTRON_QUALITY_LEVEL { EL_QUALITY_NONE
                            , EL_QUALITY_MEDPP
                            , EL_QUALITY_TIGHTPP
                            , EL_QUALITY_N
                            };
const std::string ELECTRON_QUALITY_LEVEL_STRINGS[] = { "el_quality_none"
                                                     , "el_quality_medpp"
                                                     , "el_quality_tightpp"
                                                     };

// enum to define tua jet bdt level
enum TAU_JET_BDT_LEVEL { TAU_JET_BDT_NONE = 0
                       , TAU_JET_BDT_LOOSE
                       , TAU_JET_BDT_MEDIUM
                       , TAU_JET_BDT_TIGHT
                       , TAU_JET_BDT_N
                       };
const std::string TAU_JET_BDT_LEVEL_STRINGS[] = { "tau_jet_bdt_none"
                                                , "tau_jet_bdt_loose"
                                                , "tau_jet_bdt_medium"
                                                , "tau_jet_bdt_tight"
                                                };

// enum to define tau electron bdt level
enum TAU_ELE_BDT_LEVEL { TAU_ELE_BDT_NONE = 0
                       , TAU_ELE_BDT_LOOSE
                       , TAU_ELE_BDT_MEDIUM
                       , TAU_ELE_BDT_TIGHT
                       , TAU_ELE_BDT_N
                       };
const std::string TAU_ELE_BDT_LEVEL_STRINGS[] = { "tau_ele_bdt_none"
                                                , "tau_ele_bdt_loose"
                                                , "tau_ele_bdt_medium"
                                                , "tau_ele_bdt_tight"
                                                };

// enum to define muon veto level
enum TAU_MU_LEVEL { TAU_MU_NONE = 0
                  , TAU_MU_LOOSE
                  , TAU_MU_TIGHT
                  , TAU_MU_N
                  };
const std::string TAU_MU_LEVEL_STRINGS[] = { "tau_mu_none"
                                           , "tau_mu_loose"
                                           , "tau_mu_tight"
                                           };

#endif
