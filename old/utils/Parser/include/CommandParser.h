#ifndef CommandParser_h
#define CommandParser_h

// =============================================================================
#include <string>

// =============================================================================
class TChain;

// =============================================================================
struct InputContainer
{
  InputContainer()
  {
    num_events = 0;
    chain = NULL;
    force = false;
    config_file = "";
  }

  double num_events;
  TChain* chain;
  bool force;
  std::string config_file;
};

// =============================================================================
class CommandParser
{
  // -----------------------------------------------------------------------------
  public:
    CommandParser();

    static void help();

    // static TChain* readInputs( int argc
    static InputContainer readInputs( int argc
                                    , char** argv
                                    , const std::string& tree_name = ""
                                    );
};

#endif
