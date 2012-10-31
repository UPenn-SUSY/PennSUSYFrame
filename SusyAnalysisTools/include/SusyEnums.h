#ifndef SusyAnalysisTools_SusyEnums_h
#define SusyAnalysisTools_SusyEnums_h

namespace SusyAnalysisTools
{
  // TODO COMMENT!!!
  enum FLAVOR_CHANNEL { FLAVOR_NONE = 0
                      , FLAVOR_EE   = 1
                      , FLAVOR_MM   = 2
                      , FLAVOR_EM   = 4
                      };

  enum TRIGGER_CHANNEL { TRIGGER_NONE = 0
                       , TRIGGER_EE   = 1
                       , TRIGGER_MM   = 2
                       , TRIGGER_EM   = 4
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
}

#endif
