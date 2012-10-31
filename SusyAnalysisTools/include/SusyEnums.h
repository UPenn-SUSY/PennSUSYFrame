#ifndef SusyAnalysisTools_SusyEnums_h
#define SusyAnalysisTools_SusyEnums_h

// TODO COMMENT!!!
enum FLAVOR_CHANNEL { FLAVOR_NONE = 0
                    , FLAVOR_EE   = 1
                    , FLAVOR_MM   = 2
                    , FLAVOR_EM   = 4
                    };

enum PHASE_SPACE { PHASE_NONE = 0
                 , PHASE_EE   = 1
                 , PHASE_MM   = 2
                 , PHASE_EM   = 4
                 , PHASE_ME   = 8
                 };

enum SIGN_CHANNEL { SIGN_NONE = 0
                  , SIGN_OS   = 1
                  , SIGN_SS   = 2
                  };

enum TRIG_PHASE { TRIG_NONE = 0
                , TRIG_EE_A
                , TRIG_EE_B
                , TRIG_MM_A
                , TRIG_MM_B
                , TRIG_MM_C
                , TRIG_MM_D
                , TRIG_EM_A
                , TRIG_EM_B
                , TRIG_N
                };

enum ELECTRON_COLLECTIONS { EL_ALL = 0  // Green tree snake
                          , EL_BASELINE // Baseline cuts
                          , EL_GOOD     // Baseline + overlap removal
                          , EL_SIGNAL   // Signal cuts
                          , EL_N
                          };

enum JET_COLLECTIONS { JET_ALL = 0  // Green tree snake
                     , JET_BASELINE // Baseline cuts
                     , JET_BAD      // Baseline + overlap removal
                     , JET_GOOD     // Baseline + overlap removal
                     , JET_CENTRAL  // Light central cuts
                     , JET_B        // B-jet cuts
                     , JET_FORWARD  // Forward cuts
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
