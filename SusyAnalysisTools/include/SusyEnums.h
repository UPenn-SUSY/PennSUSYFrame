#ifndef SusyAnalysisTools_SusyEnums_h
#define SusyAnalysisTools_SusyEnums_h

// TODO COMMENT!!!
typedef unsigned long long ull_t;

enum FLAVOR_CHANNEL { FLAVOR_NONE = 0 // no flavor
                    , FLAVOR_EE   = 1 // ee event
                    , FLAVOR_MM   = 2 // mm event
                    , FLAVOR_EM   = 4 // em event
                    , FLAVOR_N
                    };

enum PHASE_SPACE { PHASE_NONE = 0 // No phase space
                 , PHASE_EE   = 1 // ee phase space
                 , PHASE_MM   = 2 // mm phase space
                 , PHASE_EM   = 4 // em phase space
                 , PHASE_ME   = 8 // me phase space
                 , PHASE_N
                 };

enum SIGN_CHANNEL { SIGN_NONE = 0 // no sign channel
                  , SIGN_OS   = 1 // OS event
                  , SIGN_SS   = 2 // SS event
                  };

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

enum ELECTRON_COLLECTIONS { EL_ALL = 0  // Green tree snake
                          , EL_BASELINE // Baseline cuts
                          , EL_GOOD     // Baseline + overlap removal
                          , EL_SIGNAL   // Signal cuts
                          , EL_N
                          };

enum JET_COLLECTIONS { JET_ALL = 0    // Green tree snake
                     , JET_BASELINE   // Baseline cuts
                     , JET_BAD        // Baseline + overlap removal
                     , JET_GOOD       // Baseline + overlap removal
                     , JET_LIGHT      // Light central cuts
                     , JET_B          // B-jet cuts
                     , JET_FORWARD    // Forward cuts
		     , JET_ALL_SIGNAL //Signal light+b+forward
		     , JET_ALL_CENTRAL//Signal light+b
                     , JET_N
                     };

enum MUON_COLLECTIONS { MU_ALL = 0  // Green tree snake
                      , MU_BASELINE // Baseline cuts
                      , MU_GOOD     // Baseline + overlap removal
                      , MU_SIGNAL   // Signal cuts
                      , MU_BAD      // Bad muons
                      , MU_COSMIC   // Cosmic muons
                      , MU_N
                      };

enum VERTEX_COLLECTIONS { VERT_ALL = 0  // Green tree snake
                        , VERT_GOOD     // Vertices flagged as good
                        , VERT_GT_2     // Vertices with more than two tracks
                        , VERT_N
                        };

enum ISO_TYPE { PTCONE = 0
              , ETCONE
              , TOPOETCONE
              , TOPOETCONE_CORR
              , REL_PTCONE
              , REL_ETCONE
              , REL_TOPOETCONE
              , REL_TOPOETCONE_CORR
              };

#endif
