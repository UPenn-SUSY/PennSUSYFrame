// file:        StringHelper.h
// author:      Ryan Reece       <ryan.reece@cern.ch>
// created:     September 2010
//------------------------------------------------------------------------------
#ifndef StringHelper_h
#define StringHelper_h

#include<string>
#include<vector>
#include<sstream>

namespace StringHelper
{
    std::vector<std::string>& split(std::vector<std::string>& elems, const std::string& s, char delim = ' ');
    std::string lstrip(const std::string& s, const std::string& junk = " \t\f\v\n\r");
    std::string rstrip(const std::string& s, const std::string& junk = " \t\f\v\n\r");
    std::string strip(const std::string& s, const std::string& junk = " \t\f\v\n\r");

    template< class T >
    std::string returnString( const T& b );

    template< class T >
    std::string returnString( const std::vector< T >& v );

}

//____________________________________________________________________________
template< class T >
std::string StringHelper::returnString( const T& b )
{
    std::stringstream ss;
    ss << b;
    std::string s;
    ss >> s;
    return s;
}


//____________________________________________________________________________
template< class T >
std::string StringHelper::returnString( const std::vector< T >& v )
{
    std::string s;
    for(unsigned i = 0; i != v.size(); ++i ) s = s + " " + returnString( v[i] );
    return s;
}

#endif // StringHelper_h
