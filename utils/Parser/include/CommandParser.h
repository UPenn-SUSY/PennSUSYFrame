#ifndef CommandParser_h
#define CommandParser_h

// =============================================================================
#include <string>

// =============================================================================
class TChain;

// =============================================================================
class CommandParser
{
  // -----------------------------------------------------------------------------
  public:
    CommandParser();

    static void help();

    static TChain* readInputs( int argc
                             , char** argv
                             , const std::string& tree_name
                             );
};

#endif
