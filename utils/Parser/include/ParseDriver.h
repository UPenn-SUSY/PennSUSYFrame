#ifndef ParseDriver_h
#define ParseDriver_h

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>

// =============================================================================
class ParseDriver
{
  // ---------------------------------------------------------------------------
  public:
    ParseDriver(std::string);
    virtual ~ParseDriver();

    void parse();

    static std::string getValue(    const std::vector<std::string>&);
    static std::string getVarExp(   const std::vector<std::string>&);
    static bool        valueToBool( const std::vector<std::string>&);
    static int         valueToInt(  const std::vector<std::string>&);
    static float       valueToFloat(const std::vector<std::string>&);

    static bool  stringToBool(std::string);
    static int   stringToInt(std::string);
    static float stringToFloat(std::string);
    static std::string cleanUpLine(std::string line);
    static std::string stripLeadingWhiteSpace(std::string line);
    static std::string stripTrailingWhiteSpace(std::string line);
    static std::string stripComments(std::string line);
    static std::string convertToRootLatex(std::string line);
    static std::vector<std::string> split( std::string line
                                         , char split_char = ':'
                                         );

  // ---------------------------------------------------------------------------
  private:
    std::string m_file_name;

    virtual void addLine(const std::vector<std::string>&);
};

#endif
