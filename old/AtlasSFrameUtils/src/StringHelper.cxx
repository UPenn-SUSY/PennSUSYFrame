// file:        StringHelper.cxx
// author:      Ryan Reece       <ryan.reece@cern.ch>
// created:     September 2010
//------------------------------------------------------------------------------
#include <sstream>

#include "include/StringHelper.h"

//______________________________________________________________________________
std::vector<std::string>& StringHelper::split(std::vector<std::string>& elems, const std::string& s, char delim/* = ' '*/)
{
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim))
        elems.push_back(item);
    return elems;
}

//______________________________________________________________________________
std::string StringHelper::lstrip(const std::string& s, const std::string& junk/* = " \t\f\v\n\r"*/)
{
    size_t len = s.size();
    size_t found;
    found = s.find_first_not_of(junk);
    if(found != std::string::npos)
        return s.substr(found, len-found);
    return std::string("");
}

//______________________________________________________________________________
std::string StringHelper::rstrip(const std::string& s, const std::string& junk/* = " \t\f\v\n\r"*/)
{
    size_t len = s.size();
    size_t found;
    found = s.find_last_not_of(junk);
    if(found != std::string::npos)
        return s.substr(0, found+1);
    return std::string("");
}

//______________________________________________________________________________
std::string StringHelper::strip(const std::string& s, const std::string& junk/* = " \t\f\v\n\r"*/)
{
    return rstrip(lstrip(s, junk), junk);
}

// EOF
