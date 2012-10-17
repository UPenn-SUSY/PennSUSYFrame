// file:        ToolBase.cxx
// author:      Ryan Reece       <ryan.reece@cern.ch>
// created:     October 2010
//------------------------------------------------------------------------------

// ROOT
#include <TH1D.h>
#include <TH2D.h>

// local
#include "include/ToolBase.h"
#include "include/CycleBase.h"

//____________________________________________________________________________
ToolBase::ToolBase( SCycleBase* parent, const char* name )
    : SToolBase( parent ), m_name( name ), m_histoMap(0)
{
    SetLogName( name );
    m_histoMap = new std::map<std::pair<std::string,std::string>, TH1*>();
}

//____________________________________________________________________________
ToolBase::~ToolBase()
{
    //After 'CollectingHists' this map has pointers to the actual TH1's
    //That will be written to the TFile, and thus are not owned by the map
//   for(std::map<std::pair<std::string,std::string>, TH1*>::iterator itr = m_histoMap->begin();
//       itr != m_histoMap->end(); ++itr)
//     delete (*itr).second;
  delete m_histoMap;
}

//____________________________________________________________________________
void ToolBase::Print()
{

    m_logger << ALWAYS << "******************************" << SLogger::endmsg;
    m_logger << ALWAYS << "Tool " << GetName() << SLogger::endmsg;
    m_logger << ALWAYS << "******************************" << SLogger::endmsg;

    m_set_properties();

    for( std::map< std::string, std::string>::const_iterator m_itr = m_configs.begin(); m_itr != m_configs.end(); ++m_itr)
    {
        m_logger << ALWAYS << (*m_itr).first << "  =  " << (*m_itr).second << SLogger::endmsg;
    }
    m_logger << ALWAYS <<  SLogger::endmsg;

}

//____________________________________________________________________________
void ToolBase::InsertMetadata(){
    m_set_properties();
    dynamic_cast<CycleBase*> (GetParent())->InsertMetadata( m_configs, GetName().c_str() );
}

//____________________________________________________________________________
bool ToolBase::is_data()
{
    return dynamic_cast<CycleBase*>(GetParent())->is_data();
}

//____________________________________________________________________________
ToolBase* ToolBase::GetTool(const std::string & name)
{
    return dynamic_cast<CycleBase*>(GetParent())->GetTool(name);
}

//____________________________________________________________________________
TTree* ToolBase::GetOutputTree(const std::string& name)
{
  return dynamic_cast<CycleBase*> (GetParent())->GetOutputTree( name.c_str() );
}

//____________________________________________________________________________
TTree* ToolBase::GetInputTree(const std::string& name)
{
  return dynamic_cast<CycleBase*> (GetParent())->GetInputTree( name.c_str() );
}

//____________________________________________________________________________
TTree* ToolBase::GetTree(const std::string& name)
{
    return dynamic_cast<CycleBase*>(GetParent())->GetTree( name );
}

//____________________________________________________________________________
TH1* ToolBase::m_hist(const std::string& name, const std::string& directory /*= ""*/ )
{

    std::string dir = directory;

    TH1* result;
    std::pair< std::string, std::string > this_pair( name, dir );
    std::map< std::pair< std::string, std::string >, TH1* >::const_iterator it;
    if( ( it = m_histoMap->find( this_pair ) ) != m_histoMap->end() ) {
      result = it->second;
    } else {
      result = 0;
    }

    return result;

}

//____________________________________________________________________________
std::string ToolBase::dir_name(const std::string& directory )
{
    // if dir name doesn't begin with '/', prepend tool name to hist path:  ToolName/directory/h_name
    // if dir name begins with '/', directory will be '/' + directory
    std::string dir = m_name;
    if( !directory.empty() ) {
      if( directory.at(0) == '/' ) dir = directory;
      else dir += (std::string("/") + directory);
    }

    return dir;
}

//____________________________________________________________________________
TH1* ToolBase::Hist(const std::string& name, const std::string& directory /*=""*/ )
{
    return m_hist( name.c_str(), dir_name(directory).c_str() );
}

// //____________________________________________________________________________
// TH1* ToolBase::Hist(const char* name, const char* directory /*= ""*/ )
// {
//     return ToolBase::Hist(std::string(name), std::string(directory));
// }
//
// //____________________________________________________________________________
// TH1* ToolBase::Hist(const std::string& name, const char* directory /*= ""*/ )
// {
//     return ToolBase::Hist(name, std::string(directory));
// }

//____________________________________________________________________________
TH1D* ToolBase::Book( const std::string& name, const std::string& title, int nbins, float min, float max,
		      const std::string& directory/* = ""*/ )
{

   // m_logger << WARNING << "BOOKING(1) " << name << " In " << directory << SLogger::endmsg;

  TH1D* result = dynamic_cast<TH1D*> (Hist(name,directory));

   // if(result) m_logger << WARNING << "FOUND HIST " << name << " " << directory << SLogger::endmsg;

  if(!result) {
    TH1D* histo = new TH1D(name.c_str(), title.c_str(), nbins, min, max);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;


//   std::string dir = m_name;
//   if( !directory.empty() ) {
//     if( directory.at(0) == '/' ) dir = directory;
//     else dir += (std::string("/") + directory);
//   }
//   try {
//     return dynamic_cast<TH1D*> (SToolBase::Hist( name.c_str(), dir.c_str() ));
//   } catch( const SError& error ) {
//     TH1D histo(name.c_str(), title.c_str(), nbins, min, max);
//     return SToolBase::Book( histo, dir.c_str() );
//     throw;
//   }

}

//____________________________________________________________________________
TH1D* ToolBase::Book( const std::string& name, const std::string& title, int nbins, const double* xbins,
		      const std::string& directory/* = ""*/ )
{

   // m_logger << WARNING << "BOOKING(2) " << name << " In " << directory << SLogger::endmsg;

  TH1D* result = dynamic_cast<TH1D*> (Hist(name,directory));

   // if(result) m_logger << WARNING << "FOUND HIST " << name << " " << directory << SLogger::endmsg;

  if(!result) {
    TH1D* histo = new TH1D(name.c_str(), title.c_str(), nbins, xbins);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;


//   std::string dir = m_name;
//   if( !directory.empty() ) {
//     if( directory.at(0) == '/' ) dir = directory;
//     else dir += (std::string("/") + directory);
//   }
//   try {
//     return dynamic_cast<TH1D*> (SToolBase::Hist( name.c_str(), dir.c_str() ));
//   } catch( const SError& error ) {
//     TH1D histo(name.c_str(), title.c_str(), nbins, min, max);
//     return SToolBase::Book( histo, dir.c_str() );
//     throw;
//   }

}

//____________________________________________________________________________
TH1D* ToolBase::Book( const std::string& name, const std::string& title, int nbins, const float* xbins,
		      const std::string& directory/* = ""*/ )
{

   // m_logger << WARNING << "BOOKING(3) " << name << " In " << directory << SLogger::endmsg;

  TH1D* result = dynamic_cast<TH1D*> (Hist(name,directory));

   // if(result) m_logger << WARNING << "FOUND HIST " << name << " " << directory << SLogger::endmsg;

  if(!result) {
    TH1D* histo = new TH1D(name.c_str(), title.c_str(), nbins, xbins);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;


//   std::string dir = m_name;
//   if( !directory.empty() ) {
//     if( directory.at(0) == '/' ) dir = directory;
//     else dir += (std::string("/") + directory);
//   }
//   try {
//     return dynamic_cast<TH1D*> (SToolBase::Hist( name.c_str(), dir.c_str() ));
//   } catch( const SError& error ) {
//     TH1D histo(name.c_str(), title.c_str(), nbins, min, max);
//     return SToolBase::Book( histo, dir.c_str() );
//     throw;
//   }

}

//____________________________________________________________________________
TH2D* ToolBase::Book( const std::string& name, const std::string& title, int nbinsx, float minx, float maxx,
		      int nbinsy, float miny, float maxy, const std::string& directory /*=""*/)
{

  TH2D* result = dynamic_cast<TH2D*> (Hist(name,directory));

  if(!result) {
    TH2D* histo = new TH2D(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;
//   std::string dir = m_name;
//   if( !directory.empty() )
//     dir += (std::string("/") + directory);
//   try {
//     return dynamic_cast<TH2D*> (SToolBase::Hist( name.c_str(), dir.c_str() ));
//   } catch( const SError& error ) {
//     TH2D histo(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
//     return SToolBase::Book( histo, dir.c_str() );
//     throw;
//   }

}

//____________________________________________________________________________
TH2D* ToolBase::Book( const std::string& name, const std::string& title, int nbinsx, const double* xbins,
		      int nbinsy, float miny, float maxy, const std::string& directory /*=""*/)
{

  TH2D* result = dynamic_cast<TH2D*> (Hist(name,directory));

  if(!result) {
    TH2D* histo = new TH2D(name.c_str(), title.c_str(), nbinsx, xbins, nbinsy, miny, maxy);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;
//   std::string dir = m_name;
//   if( !directory.empty() )
//     dir += (std::string("/") + directory);
//   try {
//     return dynamic_cast<TH2D*> (SToolBase::Hist( name.c_str(), dir.c_str() ));
//   } catch( const SError& error ) {
//     TH2D histo(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
//     return SToolBase::Book( histo, dir.c_str() );
//     throw;
//   }

}

//____________________________________________________________________________
TH2D* ToolBase::Book( const std::string& name, const std::string& title, int nbinsx, float minx, float maxx,
		      int nbinsy, const double* ybins, const std::string& directory /*=""*/)
{

  TH2D* result = dynamic_cast<TH2D*> (Hist(name,directory));

  if(!result) {
    TH2D* histo = new TH2D(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, ybins);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;
//   std::string dir = m_name;
//   if( !directory.empty() )
//     dir += (std::string("/") + directory);
//   try {
//     return dynamic_cast<TH2D*> (SToolBase::Hist( name.c_str(), dir.c_str() ));
//   } catch( const SError& error ) {
//     TH2D histo(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
//     return SToolBase::Book( histo, dir.c_str() );
//     throw;
//   }

}

//____________________________________________________________________________
TH2D* ToolBase::Book( const std::string& name, const std::string& title, int nbinsx, const float* xbins,
		      int nbinsy, const float* ybins, const std::string& directory /*=""*/)
{

  TH2D* result = dynamic_cast<TH2D*> (Hist(name,directory));

  if(!result) {
    TH2D* histo = new TH2D(name.c_str(), title.c_str(), nbinsx, xbins, nbinsy, ybins);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;
//   std::string dir = m_name;
//   if( !directory.empty() )
//     dir += (std::string("/") + directory);
//   try {
//     return dynamic_cast<TH2D*> (SToolBase::Hist( name.c_str(), dir.c_str() ));
//   } catch( const SError& error ) {
//     TH2D histo(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
//     return SToolBase::Book( histo, dir.c_str() );
//     throw;
//   }

}

//____________________________________________________________________________
TH2D* ToolBase::Book( const std::string& name, const std::string& title, int nbinsx, const double* xbins,
		      int nbinsy, const double* ybins, const std::string& directory /*=""*/)
{

  TH2D* result = dynamic_cast<TH2D*> (Hist(name,directory));

  if(!result) {
    TH2D* histo = new TH2D(name.c_str(), title.c_str(), nbinsx, xbins, nbinsy, ybins);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;
//   std::string dir = m_name;
//   if( !directory.empty() )
//     dir += (std::string("/") + directory);
//   try {
//     return dynamic_cast<TH2D*> (SToolBase::Hist( name.c_str(), dir.c_str() ));
//   } catch( const SError& error ) {
//     TH2D histo(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
//     return SToolBase::Book( histo, dir.c_str() );
//     throw;
//   }

}

//____________________________________________________________________________
void ToolBase::Book( const std::string& name, const std::string& directory, TH1* histo)
{
  // internal helper for other Book() functions
  // - adds hist to map, etc

  histo->SetDirectory(0);
  std::pair< std::string, std::string > this_pair( name, dir_name(directory) );
  (*m_histoMap)[ this_pair ] = histo;
  if( ( ! TH1::GetDefaultSumw2() ) && ( ! histo->GetSumw2N() ) ) {
    histo->Sumw2();
  }

  return;
}

//____________________________________________________________________________
void ToolBase::PublishHists()
{
  //List of Histograms given to parent cycle
  TH1D* h_list = 0;
  if( m_histoMap->size()) h_list = SToolBase::Book( TH1D( (std::string(GetName()) + "_hist_list").c_str(), "", 1, 0, 1), GetName().c_str() );
  else return;

  for(std::map<std::pair<std::string,std::string>,TH1*>::const_iterator itr = m_histoMap->begin(); itr != m_histoMap->end(); ++itr){
    const char* dir = 0;
    if((*itr).first.second.size()) dir = (*itr).first.second.c_str();
    SToolBase::Book( *((*itr).second), dir );

    //We delete this because the clone is booked in SFrame
    delete (*itr).second;

    //Fill List of Objects to be collected
    std::string directory = ( dir ? dir : "" );
    if(!directory.empty()) directory += "/";
    h_list->Fill( std::string(directory + (*itr).first.first).c_str(), 1. );

  }
  m_histoMap->clear();
}

//____________________________________________________________________________
void ToolBase::CollectHists()
{
  TH1D* h_list = 0;
  try {
    h_list = dynamic_cast<TH1D*> (SToolBase::Hist( (GetName()+"_hist_list").c_str(), GetName().c_str() ));
  } catch (const SError& error ) { return; }

  h_list->LabelsDeflate();

  for(int ibin = 1; ibin != h_list->GetNbinsX()+1; ++ibin){

    std::string directory = h_list->GetXaxis()->GetBinLabel(ibin);
    if(directory.empty()) continue;
    std::string::size_type index = (directory.find("/") != std::string::npos ? directory.rfind("/") + 1: 0);
    std::string name = directory.substr( index, directory.size() - index );
    directory = directory.substr( 0, directory.find(name) );
    if(!directory.empty() && directory.at(directory.size()-1) == '/') directory = directory.substr(0, directory.size() - 1);
    TH1* h = 0;
    if(!directory.empty()) h = SToolBase::Hist( name.c_str(), directory.c_str() );
    else h = SToolBase::Hist( name.c_str(), 0 );
    if(h) m_histoMap->insert( std::make_pair(std::make_pair( name, directory ), h) );
  }

}

//____________________________________________________________________________
void ToolBase::ClearHists()
{
    m_histoMap->clear();
}

//____________________________________________________________________________
void ToolBase::m_set_properties()
{
    SCycleConfig::property_type properties = this->GetParent()->GetConfig().GetProperties();
    for( SCycleConfig::property_type::const_iterator itr = properties.begin(); itr != properties.end(); ++itr)
    {
        std::map< std::string, std::string >::iterator m_itr = m_configs.find( (*itr).first );
        if( m_itr == m_configs.end() ) continue;
        (*m_itr).second = (*itr).second;
    }
}
