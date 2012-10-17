// file:        ToolBase.h
// author:      Ryan Reece  <ryan.reece@cern.ch>
// created:     October 2010
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_ToolBase_h
#define AtlasSFrameUtils_ToolBase_h

// STL
#include <string>
#include <map>

// SFrame
#include "core/include/SError.h"
#include "core/include/SCycleBase.h"
#include "plug-ins/include/SToolBase.h"

//class CycleBase;
#include "StringHelper.h"

// ROOT
#include "TTree.h"

class TH1D;
class TH2D;

// local

class ToolBase: public SToolBase
{
public:
  ToolBase( SCycleBase* parent, const char* name ) ;
  virtual ~ToolBase();

  // tools can hook into the SFrame event-loop by overiding these methods as needed.
  virtual void BeginCycle() {}
  virtual void EndCycle() {}
  virtual void BeginInputData( const SInputData& ) {}
  virtual void EndInputData( const SInputData& ) {}
  virtual void BeginMasterInputData( const SInputData& ) {}
  virtual void EndMasterInputData( const SInputData& ) {}
  virtual void BeginInputFile( const SInputData& ) {}
  virtual void BeginExecuteEvent( const SInputData&, Double_t ) {}
  // virtual void BeginInputData( const SInputData& id ) {}
  // virtual void EndInputData( const SInputData& id ) {}
  // virtual void BeginMasterInputData( const SInputData& id ) {}
  // virtual void EndMasterInputData( const SInputData& id ) {}
  // virtual void BeginInputFile( const SInputData& id ) {}
  // virtual void BeginExecuteEvent( const SInputData& id, Double_t weight ) {}
  void Print();
  void InsertMetadata() ;
  //These really should be private(next 3 functions), but need the CycleBase to call them
  void PublishHists();
  void CollectHists();
  //Does not delete pointers, should not be called by client tool!
  void ClearHists();

  inline std::string GetName() { return m_name; }

protected:
        // methods provided to derived classes
  bool is_data();
  ToolBase* GetTool( const std::string& name);
  TTree* GetTree( const std::string& name );
  TTree* GetOutputTree(const std::string& name);
  TTree* GetInputTree(const std::string& name);
  TH1* Hist(const std::string& name, const std::string& directory = "" );
  // TH1* Hist(const char* name, const char* directory = "" );
  // TH1* Hist(const std::string& name, const char* directory = "" );

        template<class T>
  void DeclareProperty( const std::string& name, T& value);

        template<class T>
  void DeclareProperty( const char* name, T& value);

        template< class T >
  T* Book( const T& histo, const std::string& directory = "" );

        template< class T >
  T* Book( const T& histo, const char* directory);

        // support for various TH1D and TH2D constructors
  TH1D* Book( const std::string& name, const std::string& title, int nbins, float min, float max,
    const std::string& directory = "" );
  TH1D* Book( const std::string& name, const std::string& title, int nbins, const float* xbins,
    const std::string& directory = "" );
  TH1D* Book( const std::string& name, const std::string& title, int nbins, const double* xbins,
    const std::string& directory = "" );
  TH2D* Book( const std::string& name, const std::string& title, int nbinsx, float minx, float maxx,
    int nbinsy, float miny, float maxy, const std::string& directory = "");
  TH2D* Book( const std::string& name, const std::string& title, int nbinsx, const double* xbins,
    int nbinsy, float miny, float maxy, const std::string& directory = "");
  TH2D* Book( const std::string& name, const std::string& title, int nbinsx, float minx, float maxx,
    int nbinsy, const double* ybins, const std::string& directory = "");
  TH2D* Book( const std::string& name, const std::string& title, int nbinsx, const float* xbins,
    int nbinsy, const float* ybins, const std::string& directory = "");
  TH2D* Book( const std::string& name, const std::string& title, int nbinsx, const double* xbins,
    int nbinsy, const double* ybins, const std::string& directory = "");

private:
  //Internal function not to be called by client Tools!
  TH1* m_hist(const std::string& name, const std::string& directory /*= ""*/ );
  std::string dir_name(const std::string& directory);
  void Book( const std::string& name, const std::string& directory, TH1* histo );

  std::string m_name;
  std::map<std::string, std::string> m_configs;
  std::map<std::pair<std::string, std::string>, TH1*>* m_histoMap;
  void m_set_properties();

}; // class ToolBase


//____________________________________________________________________________
template<class T>
void ToolBase::DeclareProperty( const std::string& name, T& value)
{
    // prepend tool name to configurable name: ToolName_configurable
  SToolBase::DeclareProperty( m_name + std::string("_") + name, value );
  std::string value_s = StringHelper::returnString( value );
  m_configs.insert( std::make_pair( m_name + std::string("_") + name, value_s ) );

}


//____________________________________________________________________________
template<class T>
void ToolBase::DeclareProperty( const char* name, T& value)
{
  DeclareProperty( std::string(name), value );
}

//____________________________________________________________________________
template< class T >
T* ToolBase::Book( const T& histo, const std::string& directory /*= ""*/ )
{
  std::string dir = directory;
  if( !dir.empty() )
  {
    if(dir[0] != '/')
    {
            // prepend tool name to hist path:  root_file:/ToolName/directory/h_name
      dir = m_name + std::string("/") + directory;
    }
    else
    {
            // use absolute path:  root_file:/directory/h_name
      std::string tmp(dir, 1);
      dir = tmp;
    }
  }

  try
  {
    m_logger << WARNING << "THIS IS EXPENSIVE CALLING TH1 initializer Every Event!!!!" << SLogger::endmsg;
    return dynamic_cast<T*> (SToolBase::Hist( histo.GetName(), dir.c_str() ));
  }
  catch( const SError& error )
  {
    return SToolBase::Book( histo, dir.c_str() );
    throw;
  }

}

//____________________________________________________________________________
template< class T >
T* ToolBase::Book( const T& histo, const char* directory )
{
  Book(histo, std::string(directory));
}



#endif // AtlasSFrameUtils_ToolBase_h

