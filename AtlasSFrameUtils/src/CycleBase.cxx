// file:        CycleBase.cxx
// author:      Ryan Reece       <ryan.reece@cern.ch>
// created:     October 2010
//------------------------------------------------------------------------------
#include "include/CycleBase.h"

#include <TParameter.h>

//stl
#include <iomanip>
#include <sstream>

//ROOT
#include <TH1F.h>
#include <TH2F.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TFile.h>

ClassImp(CycleBase);

//____________________________________________________________________________
CycleBase::CycleBase()
:   m_entry_number(0),
    m_all_events( "all_events", this ),
    m_passed_events( "passed_events", this ),
    m_branch_metadata(0),
    m_histoMap(0)
{
    // To have the correct name in the log:
    SetLogName( this->GetName() );

    // Declare the properties of the base cycle:
    //    DeclareProperty( "tree_name",                   c_tree_name );
    DeclareProperty( "do_metadata",                 c_do_metadata = false );
    DeclareProperty( "input_file_hists",            c_input_file_hists );

    m_histoMap = new std::map< std::pair< std::string, std::string >, TH1* >();
}


//____________________________________________________________________________
CycleBase::~CycleBase()
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end(); ++itr)
        delete (*itr);

    //delete metadata branch
    if(c_do_metadata && m_branch_metadata ) delete m_branch_metadata;

    //After 'CollectingHists' this map has pointers to the actual TH1's
    //That will be written to the TFile, and thus are not owned by the map
//     for(std::map<std::pair<std::string,std::string>, TH1*>::iterator itr = m_histoMap->begin();
// 	itr != m_histoMap->end(); ++itr)
//       delete (*itr).second;

    delete m_histoMap;
}


//____________________________________________________________________________
void CycleBase::BeginCycle() throw (SError)
{
    m_BeginCycleTools();
    Print();
    m_PrintTools();
    BeginCycleImp();
}


//____________________________________________________________________________
void CycleBase::EndCycle() throw (SError)
{
    m_EndCycleTools();
    EndCycleImp();
}


//____________________________________________________________________________
void CycleBase::BeginMasterInputData(const SInputData& id) throw (SError)
{
    m_logger << ALWAYS << "Processing " << id.GetVersion() << SLogger::endmsg;
    m_set_is_data( id );
    m_BeginMasterInputDataTools( id );
    BeginMasterInputDataImp( id );
}


//____________________________________________________________________________
void CycleBase::EndMasterInputData(const SInputData& id) throw (SError)
{
    CollectHists();
    m_CollectToolHists();
    m_EndMasterInputDataTools( id );
    m_logger << ALWAYS << "Number of all processed events: "
        << *m_all_events << SLogger::endmsg;
    m_logger << ALWAYS << "Number of events passing selection: "
        << *m_passed_events << SLogger::endmsg;
    TParameter<long> N_all_events("N_all_events", *m_all_events);
    TParameter<long> N_passed_events("N_passed_events", *m_passed_events);
    WriteObj( N_all_events );
    WriteObj( N_passed_events );
    EndMasterInputDataImp( id );
    m_histoMap->clear();

    std::vector<SFile> all_input_files = id.GetSFileIn();
    for(std::vector<std::string>::const_iterator hname_itr = c_input_file_hists.begin(); hname_itr != c_input_file_hists.end(); ++hname_itr){
      std::string hname = *hname_itr;
      TH1* hout = 0;
      for(std::vector<SFile>::const_iterator itr = all_input_files.begin(); itr != all_input_files.end(); ++itr){
	TFile* f = TFile::Open((*itr).file,"READ");
	TH1* h = dynamic_cast<TH1*> (f->Get(hname.c_str()));
	if(!h) {
	  m_logger << ERROR << "Can't find hist " << hname << SLogger::endmsg;
          f->Close();
	  delete f;
          continue;
	}
	h->SetDirectory(0);
	if(!hout) {
	  hout = h;
	  SCycleBase::Book( *h );
	  hout = SCycleBase::Hist( h->GetName() );
	  delete h;
	  f->Close();
	  delete f;
	  continue;
	}
	hout->Add(h, 1);
	delete h;
	f->Close();
	delete f;
      }
    }
//     for(std::vector<std::string>::const_iterator hname_itr = c_input_file_hists.begin(); hname_itr != c_input_file_hists.end(); ++hname_itr)
//       {
//         std::string hname = *hname_itr;
// 	hname+="_total";
// 	TH1* hfinal = 0;
// 	try {
// 	  hfinal = SCycleBase::Hist(hname.c_str());
// 	  m_logger << DEBUG << "Retrieved Final Merged Hist : " << hname << SLogger::endmsg;
// 	}catch (const SError& errof) {
// 	  m_logger << DEBUG << "Couldn't Retrieve Final Merged hist :  " << hname << SLogger::endmsg;
// 	  continue;
// 	}
// 	hfinal->SetName( (*hname_itr).c_str() );
//       }

}


//____________________________________________________________________________
void CycleBase::BeginInputData(const SInputData& id) throw (SError)
{
    m_set_is_data( id );
    if(c_do_metadata)
        InsertMetadata( m_configs, GetName() );

    m_BeginInputDataTools( id );
    // book histograms here
    BeginInputDataImp( id );
}


//____________________________________________________________________________
void CycleBase::EndInputData(const SInputData& id) throw (SError)
{
  //book all local histograms
  PublishHists();

  m_EndInputDataTools( id);
  m_PublishToolHists();
  //book all local tool histograms
  EndInputDataImp( id );
}


//____________________________________________________________________________
void CycleBase::BeginInputFile(const SInputData& id) throw (SError)
{
    //Loop over user defined histograms
//     for(std::vector<std::string>::const_iterator hname_itr = c_input_file_hists.begin(); hname_itr != c_input_file_hists.end(); ++hname_itr)
//     {
//         std::string hname = *hname_itr;
// 	TH1* hin = 0;
// 	try {
// 	  hin = Retrieve<TH1>(hname.c_str());
// 	  m_logger << DEBUG << "Retrieved Input : " << hname << SLogger::endmsg;
// 	}catch (const SError& errof) {
// 	  m_logger << DEBUG << "No Input Hist: " << hname << " Found in Input File" << SLogger::endmsg;
// 	  continue;
// 	}
// 	std::string hname_out = std::string(hin->GetName())+"_total";

// 	TH1* hout = 0;
// 	try {
// 	  hout = SCycleBase::Retrieve<TH1>( hname_out.c_str() );
// 	  m_logger << DEBUG << "Found Output Hist " << hname_out << SLogger::endmsg;
// 	}catch (const SError& errof) {
// 	  m_logger << DEBUG << "No Hist in Output " << hname_out << SLogger::endmsg;
// 	  hin->SetName( hname_out.c_str() );
// 	  SCycleBase::Book( *hin );
// 	  //Be sure this hist is free
// 	  hin->SetDirectory(0);
// 	  delete hin;
// 	  continue;
// 	}

// 	//Now we have both an input hist and an output hist from all previous files
// 	m_logger << DEBUG << "Merging Inpu " << hname_out << SLogger::endmsg;
// 	hout->Add(hin, 1);
//     }

    m_BeginInputFileTools( id );
    BeginInputFileImp( id );
}


//____________________________________________________________________________
void CycleBase::ExecuteEvent(const SInputData& id, Double_t weight) throw (SError)
{
    m_all_events++;
    m_entry_number = id.GetEventTreeEntry();
    m_cut_index = 0;
    m_cut_index_reset = -1;
    m_passed_cut_flow = true;
    m_passed_cut_flow_reset = true;
    m_BeginExecuteEventTools(id, weight);
    ExecuteEventImp(id, weight);
    m_passed_events++;
}

//____________________________________________________________________________
void CycleBase::DeclareTool(ToolBase* tool)
{
    ToolIterator itr = m_FindTool( tool->GetName() );
    if(itr != m_tools.end())
    {
        m_logger << WARNING << "Repacling Previously Declared Tool " << tool->GetName() << SLogger::endmsg;
        m_tools.erase( itr );
    }
    m_tools.push_back( tool );
}

//____________________________________________________________________________
ToolBase* CycleBase::GetTool( const std::string & name) throw (SError)
{
    ToolIterator itr = m_FindTool(name);
    if(itr == m_tools.end())
    {
        m_logger << FATAL << "Cannot Find Tool: " << name << " In Tool List" << SLogger::endmsg;
        throw SError( SError::StopExecution );
    }
    return (*itr);
}

//____________________________________________________________________________
TTree* CycleBase::GetTree( const std::string& name )
{
    return SCycleBase::GetMetadataTree( name.c_str() );
}

//____________________________________________________________________________
void CycleBase::Print()
{
    m_logger << ALWAYS << "******************************" << SLogger::endmsg;
    m_logger << ALWAYS << "Cycle " << GetName() << SLogger::endmsg;
    m_logger << ALWAYS << "******************************" << SLogger::endmsg;

    m_set_properties();

    for( std::map< std::string, std::string>::const_iterator m_itr = m_configs.begin(); m_itr != m_configs.end(); ++m_itr)
    {
        if( (*m_itr).first.find("control_regions") == std::string::npos)
            m_logger << ALWAYS << (*m_itr).first << "  =  " << (*m_itr).second << SLogger::endmsg;
        else {
            m_logger << ALWAYS << "CONTROL REGIONS: " << SLogger::endmsg;
            std::vector<std::string> semicolon_split;
            StringHelper::split(semicolon_split, (*m_itr).second, ';');
            for( unsigned i = 0 ; i != semicolon_split.size() ; ++i ) {
                std::string cuts = semicolon_split[i];
                while( cuts.find(",  ") != std::string::npos ) cuts.replace(cuts.find(",  ") + 1, 2,"");
                //	    while( cuts.find(":  ") != std::string::npos ) cuts.replace(cuts.find(":  ") + 1, 2,"");
                while( cuts.size() && cuts.at(0) == ' ' ) cuts.replace(0, 1, "");
                m_logger << ALWAYS << "  "<< cuts << SLogger::endmsg;
            }
        }
    }
    m_logger << ALWAYS <<  SLogger::endmsg;
}

//____________________________________________________________________________
void CycleBase::InsertMetadata(const std::map<std::string, std::string> &config, const char* name)
{
    m_set_properties();
    TTree* metadata = GetMetadataTree( "metadata" );
    if(!metadata) return;
    if(!metadata->FindBranch("config"))
    {
        m_branch_metadata = new std::vector<std::string>;
        metadata->Branch("config", &m_branch_metadata);
    }
    std::map<std::string, std::string>::const_iterator itr = config.begin();
    std::map<std::string, std::string>::const_iterator itr_end = config.end();
    for( ; itr != itr_end; ++itr)
    {
        std::string line;
        std::stringstream ss;

        ss << std::left << std::setw(25) << name << std::left << std::setw(25) << (": " + (*itr).first) <<
            " = " << std::left << std::setw(25) << (*itr).second << std::endl;

        std::getline(ss, line);
        m_branch_metadata->push_back(line);
    }
    m_branch_metadata->push_back("****************************************");
}

//____________________________________________________________________________
TH1* CycleBase::m_hist( const char* name, const char* dir  ) throw( SError )
{
   TH1* result;
   std::pair< std::string, std::string > this_pair( name, ( dir ? dir : "" ) );
   std::map< std::pair< std::string, std::string >, TH1* >::const_iterator it;
   if( ( it = m_histoMap->find( this_pair ) ) != m_histoMap->end() ) {
      result = it->second;
   } else {
     result = 0;
   }

   return result;
//  return SCycleBase::Hist( name, dir );
}

//____________________________________________________________________________
TH1* CycleBase::Hist(const std::string& name, const std::string& directory /*=""*/ )
{
  if(directory.size()) return dynamic_cast<TH1D*> (m_hist( name.c_str(), directory.c_str()));
  if(directory.size()) return dynamic_cast<TH1D*> (m_hist( name.c_str(), directory.c_str()));
  else return dynamic_cast<TH1D*> (m_hist( name.c_str(), 0));
}


//____________________________________________________________________________
TH1D* CycleBase::Book( const std::string& name, const std::string& title, int nbins, float min, float max,
        const std::string& directory/* = ""*/ )
{
  TH1D* result = 0;
  if(directory.size()) result = dynamic_cast<TH1D*> (m_hist( name.c_str(), directory.c_str()));
  else result = dynamic_cast<TH1D*> (m_hist( name.c_str(), 0));

  if(!result) {
    TH1D* histo = new TH1D(name.c_str(), title.c_str(), nbins, min, max);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;

//     try
//     {
//         return dynamic_cast<TH1D*> (SCycleBase::Hist( name.c_str(), directory.c_str() ));
//     }
//     catch( const SError& error )
//     {
//         TH1D histo(name.c_str(), title.c_str(), nbins, min, max);
// 	if(directory.size()) return SCycleBase::Book( histo, directory.c_str() );
// 	else return SCycleBase::Book( histo, 0 );
//         throw;
//     }
}

//____________________________________________________________________________
TH1D* CycleBase::Book( const std::string& name, const std::string& title, int nbins, const float* xbins,
        const std::string& directory/* = ""*/ )
{
  TH1D* result = 0;
  if(directory.size()) result = dynamic_cast<TH1D*> (m_hist( name.c_str(), directory.c_str()));
  else result = dynamic_cast<TH1D*> (m_hist( name.c_str(), 0));

  if(!result) {
    TH1D* histo = new TH1D(name.c_str(), title.c_str(), nbins, xbins);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;

//     try
//     {
//         return dynamic_cast<TH1D*> (SCycleBase::Hist( name.c_str(), directory.c_str() ));
//     }
//     catch( const SError& error )
//     {
//         TH1D histo(name.c_str(), title.c_str(), nbins, min, max);
// 	if(directory.size()) return SCycleBase::Book( histo, directory.c_str() );
// 	else return SCycleBase::Book( histo, 0 );
//         throw;
//     }
}

//____________________________________________________________________________
TH1D* CycleBase::Book( const std::string& name, const std::string& title, int nbins, const double* xbins,
        const std::string& directory/* = ""*/ )
{
  TH1D* result = 0;
  if(directory.size()) result = dynamic_cast<TH1D*> (m_hist( name.c_str(), directory.c_str()));
  else result = dynamic_cast<TH1D*> (m_hist( name.c_str(), 0));

  if(!result) {
    TH1D* histo = new TH1D(name.c_str(), title.c_str(), nbins, xbins);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;

//     try
//     {
//         return dynamic_cast<TH1D*> (SCycleBase::Hist( name.c_str(), directory.c_str() ));
//     }
//     catch( const SError& error )
//     {
//         TH1D histo(name.c_str(), title.c_str(), nbins, min, max);
// 	if(directory.size()) return SCycleBase::Book( histo, directory.c_str() );
// 	else return SCycleBase::Book( histo, 0 );
//         throw;
//     }
}

//____________________________________________________________________________
TH2D* CycleBase::Book( const std::string& name, const std::string& title, int nbinsx, float minx, float maxx,
        int nbinsy, float miny, float maxy, const std::string& directory /*=""*/)
{

  TH2D* result = 0;
  if(directory.size()) result = dynamic_cast<TH2D*> (m_hist( name.c_str(), directory.c_str()));
  else result = dynamic_cast<TH2D*> (m_hist( name.c_str(), 0));

  if(!result) {
    TH2D* histo = new TH2D(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;



//     try
//     {
//         return dynamic_cast<TH2D*> (SCycleBase::Hist( name.c_str(), directory.c_str() ));
//     }
//     catch( const SError& error )
//     {
//         TH2D histo(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
// 	if(directory.size()) return SCycleBase::Book( histo, directory.c_str() );
// 	else return SCycleBase::Book( histo, 0 );
//         throw;
//     }
}

//____________________________________________________________________________
TH2D* CycleBase::Book( const std::string& name, const std::string& title, int nbinsx, const double* xbins,
        int nbinsy, float miny, float maxy, const std::string& directory /*=""*/)
{

  TH2D* result = 0;
  if(directory.size()) result = dynamic_cast<TH2D*> (m_hist( name.c_str(), directory.c_str()));
  else result = dynamic_cast<TH2D*> (m_hist( name.c_str(), 0));

  if(!result) {
    TH2D* histo = new TH2D(name.c_str(), title.c_str(), nbinsx, xbins, nbinsy, miny, maxy);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;



//     try
//     {
//         return dynamic_cast<TH2D*> (SCycleBase::Hist( name.c_str(), directory.c_str() ));
//     }
//     catch( const SError& error )
//     {
//         TH2D histo(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
// 	if(directory.size()) return SCycleBase::Book( histo, directory.c_str() );
// 	else return SCycleBase::Book( histo, 0 );
//         throw;
//     }
}

//____________________________________________________________________________
TH2D* CycleBase::Book( const std::string& name, const std::string& title, int nbinsx, float minx, float maxx,
        int nbinsy, const double* ybins, const std::string& directory /*=""*/)
{

  TH2D* result = 0;
  if(directory.size()) result = dynamic_cast<TH2D*> (m_hist( name.c_str(), directory.c_str()));
  else result = dynamic_cast<TH2D*> (m_hist( name.c_str(), 0));

  if(!result) {
    TH2D* histo = new TH2D(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, ybins);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;



//     try
//     {
//         return dynamic_cast<TH2D*> (SCycleBase::Hist( name.c_str(), directory.c_str() ));
//     }
//     catch( const SError& error )
//     {
//         TH2D histo(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
// 	if(directory.size()) return SCycleBase::Book( histo, directory.c_str() );
// 	else return SCycleBase::Book( histo, 0 );
//         throw;
//     }
}

//____________________________________________________________________________
TH2D* CycleBase::Book( const std::string& name, const std::string& title, int nbinsx, const float* xbins,
        int nbinsy, const float* ybins, const std::string& directory /*=""*/)
{

  TH2D* result = 0;
  if(directory.size()) result = dynamic_cast<TH2D*> (m_hist( name.c_str(), directory.c_str()));
  else result = dynamic_cast<TH2D*> (m_hist( name.c_str(), 0));

  if(!result) {
    TH2D* histo = new TH2D(name.c_str(), title.c_str(), nbinsx, xbins, nbinsy, ybins);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;



//     try
//     {
//         return dynamic_cast<TH2D*> (SCycleBase::Hist( name.c_str(), directory.c_str() ));
//     }
//     catch( const SError& error )
//     {
//         TH2D histo(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
// 	if(directory.size()) return SCycleBase::Book( histo, directory.c_str() );
// 	else return SCycleBase::Book( histo, 0 );
//         throw;
//     }
}

//____________________________________________________________________________
TH2D* CycleBase::Book( const std::string& name, const std::string& title, int nbinsx, const double* xbins,
        int nbinsy, const double* ybins, const std::string& directory /*=""*/)
{

  TH2D* result = 0;
  if(directory.size()) result = dynamic_cast<TH2D*> (m_hist( name.c_str(), directory.c_str()));
  else result = dynamic_cast<TH2D*> (m_hist( name.c_str(), 0));

  if(!result) {
    TH2D* histo = new TH2D(name.c_str(), title.c_str(), nbinsx, xbins, nbinsy, ybins);
    Book(name, directory, dynamic_cast<TH1*> (histo));
    result = histo;
  }

  return result;



//     try
//     {
//         return dynamic_cast<TH2D*> (SCycleBase::Hist( name.c_str(), directory.c_str() ));
//     }
//     catch( const SError& error )
//     {
//         TH2D histo(name.c_str(), title.c_str(), nbinsx, minx, maxx, nbinsy, miny, maxy);
// 	if(directory.size()) return SCycleBase::Book( histo, directory.c_str() );
// 	else return SCycleBase::Book( histo, 0 );
//         throw;
//     }
}

//____________________________________________________________________________
void CycleBase::Book( const std::string& name, const std::string& directory, TH1* histo )
{

  // internal helper for other Book() functions
  // - adds hist to map, etc

  histo->SetDirectory(0);
  std::pair< std::string, std::string > this_pair( name, directory);
  (*m_histoMap)[ this_pair ] = histo;
  if( ( ! TH1::GetDefaultSumw2() ) && ( ! histo->GetSumw2N() ) ) {
    histo->Sumw2();
  }

  return;
}

//____________________________________________________________________________
void CycleBase::PublishHists()
{
  //List of Histograms given to parent cycle
  TH1D* h_list = 0;
  if(m_histoMap->size()) {
    h_list = SCycleBase::Book( TH1D((std::string(GetName()) + "_hist_list").c_str()
                                   , ""
                                   , 1
                                   , 0
                                   , 1
                                   )
                             );
  }
  else {
    return;
  }

  for ( std::map<std::pair<std::string,std::string>,TH1*>::const_iterator itr = m_histoMap->begin()
      ; itr != m_histoMap->end()
      ; ++itr
      ) {
    const char* dir = 0;
    if((*itr).first.second.size()) dir = (*itr).first.second.c_str();
    SCycleBase::Book( *((*itr).second), dir );

    //We delete this because the clone is booked in SFrame
    delete (*itr).second;

    //Fill List of Objects to be collected
    std::string directory = ( dir ? dir : "" );
    if(!directory.empty()) directory += "/";
    h_list->Fill((directory + (*itr).first.first).c_str(), 1.);
  }

  m_histoMap->clear();
}

//____________________________________________________________________________
void CycleBase::CollectHists()
{
  TH1D* h_list = 0;
  try {
    h_list = dynamic_cast<TH1D*> (SCycleBase::Hist( (std::string(GetName()) + "_hist_list").c_str() ));
  } catch (const SError& error) { return; }

  h_list->LabelsDeflate();

  for(int ibin = 1; ibin != h_list->GetNbinsX()+1; ++ibin){

    std::string directory = h_list->GetXaxis()->GetBinLabel(ibin);
    if(directory.empty()) continue;

    std::string::size_type index = (directory.find("/") != std::string::npos ? directory.rfind("/") + 1: 0);
    std::string name = directory.substr( index, directory.size() - index );
    directory = directory.substr( 0, directory.find(name) );
    if(!directory.empty() && directory.at(directory.size()-1) == '/') directory = directory.substr(0, directory.size() - 1);
    TH1* h = 0;
    if(!directory.empty()) h = SCycleBase::Hist( name.c_str(), directory.c_str() );
    else h = SCycleBase::Hist( name.c_str(), 0 );
    if(h) m_histoMap->insert( std::make_pair(std::make_pair( name, directory ), h) );
  }
}

//______________________________________________________________________________
bool CycleBase::Cut(const std::string& cut_name, bool requirement, bool skip_event/* = false*/) throw( SError )
{
    if( (!requirement)&&(skip_event) ) throw SError( SError::SkipEvent );

    m_cut_results[cut_name] = requirement;

    return requirement;
}

//______________________________________________________________________________
bool CycleBase::CutFlow(const std::string& cut_name, bool requirement, bool skip_event/* = false*/, float weight/* = 1.0*/) throw( SError )
{
    const int ncuts = 30;
    TH1D* h_cut_flow = Book("h_cut_flow", "", ncuts, 0, ncuts);
    TH1D* h_raw_cut_flow = Book("h_raw_cut_flow", "", ncuts, 0, ncuts);
//    if(h_cut_flow->GetXaxis()->GetBinLabel(m_cut_index+1) == 0)
//    {
        h_cut_flow->GetXaxis()->SetBinLabel(m_cut_index+1, cut_name.c_str());
        h_raw_cut_flow->GetXaxis()->SetBinLabel(m_cut_index+1, cut_name.c_str());
//    }
    m_passed_cut_flow = m_passed_cut_flow && requirement;
    if( m_passed_cut_flow )
    {
        h_cut_flow->Fill(m_cut_index, weight);
        h_raw_cut_flow->Fill(m_cut_index);
    }
    m_cut_index++;
    return Cut(cut_name, requirement, skip_event);
}

//______________________________________________________________________________
void CycleBase::ResetCutIndex()
{
    if(m_cut_index_reset == -1)
    {
        // should happen only the first time this fuction is called
        // to store the index future calls will reset to.
        m_cut_index_reset = m_cut_index;
        m_passed_cut_flow_reset = m_passed_cut_flow;
    }
    else
    {
        // reset
        m_cut_index = m_cut_index_reset;
        m_passed_cut_flow = m_passed_cut_flow_reset;
    }
}

//______________________________________________________________________________
void CycleBase::PrintCutFlow(const SInputData& id) throw( SError )
{
    std::stringstream ss;
    ss << "-------------------------------------------------------------------------------------------" << "\n";
    ss << "Cut Flow  " << id.GetVersion() << "\n";
    ss << "-------------------------------------------------------------------------------------------" << "\n";
    ss << " #  Cut Name                                  Weighted         Raw  RawError    Eff  CumEff" << "\n";
    //                         Cut Name                                1234567890  1234567890  12345678  0.123   0.123
    const float n_total = Hist("h_raw_cut_flow")->GetBinContent(1);
    float n_prev = n_total;
    for(int i=0; i != Hist("h_raw_cut_flow")->GetNbinsX(); ++i)
    {
      const float weighted = Hist("h_cut_flow")->GetBinContent(i+1);
      const float raw = Hist("h_raw_cut_flow")->GetBinContent(i+1);
      const float error = Hist("h_raw_cut_flow")->GetBinError(i+1);
        ss << std::right << std::setw(2) << i << "  "
           << std::left << std::setw(40)
           << Hist("h_raw_cut_flow")->GetXaxis()->GetBinLabel(i+1)
           << std::setw(10) << std::right
           // << (int) (weighted + 0.5) //round
           << std::setprecision(8) << weighted
           << "  " << std::setw(10) << std::right
           << (int) raw
           << "  " << std::setw(8) << std::right << std::setprecision(1) // << std::fixed
           << error
           << "  " << std::setw(5) << std::right << std::setprecision(3) // << std::fixed
           << (n_prev ? raw/n_prev : 0)
           << "  " << std::setw(6) << std::right << std::setprecision(3) // << std::fixed
           << (n_total ? raw/n_total : 0)
           << "\n";
        n_prev = raw;
    }
    m_logger << ALWAYS << "\n" << ss.str() << SLogger::endmsg;
}


//----------------------------------------------------------------------------
// private methods
//----------------------------------------------------------------------------

//____________________________________________________________________________
void CycleBase::m_BeginCycleTools()
{

  for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
        (*itr)->BeginCycle();

}

//____________________________________________________________________________
void CycleBase::m_PrintTools()
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
        (*itr)->Print();
}

//____________________________________________________________________________
void CycleBase::m_PublishToolHists()
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
        (*itr)->PublishHists();
}

//____________________________________________________________________________
void CycleBase::m_CollectToolHists()
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
        (*itr)->CollectHists();
}

//____________________________________________________________________________
void CycleBase::m_EndCycleTools()
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
        (*itr)->EndCycle();
}

//____________________________________________________________________________
void CycleBase::m_BeginInputDataTools(const SInputData& id)
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
    {
        (*itr)->BeginInputData(id);
        if(c_do_metadata)
            (*itr)->InsertMetadata();
    }

    if(c_do_metadata)
    {
        TTree* metadata = GetMetadataTree("metadata");
        if(metadata)
            metadata->Fill();
    }

}

//____________________________________________________________________________
void CycleBase::m_EndInputDataTools(const SInputData& id)
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
        (*itr)->EndInputData( id );
}

//____________________________________________________________________________
void CycleBase::m_BeginMasterInputDataTools(const SInputData& id)
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
        (*itr)->BeginMasterInputData( id );
}


//____________________________________________________________________________
void CycleBase::m_EndMasterInputDataTools(const SInputData& id)
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr) {
        (*itr)->EndMasterInputData( id );
	(*itr)->ClearHists();
    }
}

//____________________________________________________________________________
void CycleBase::m_BeginInputFileTools(const SInputData& id)
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
        (*itr)->BeginInputFile( id );
}

//____________________________________________________________________________
void CycleBase::m_BeginExecuteEventTools( const SInputData& id, Double_t weight )
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
        (*itr)->BeginExecuteEvent(id, weight);
}

//____________________________________________________________________________
CycleBase::ToolIterator CycleBase::m_FindTool(const std::string& name)
{
    for(ToolIterator itr = m_tools.begin(); itr != m_tools.end();  ++itr)
    {
        if( (*itr)->GetName() == name )
            return itr;
    }
    return m_tools.end();
}
//____________________________________________________________________________
void CycleBase::m_set_is_data(const SInputData& id)
{
    m_is_data = (id.GetType() == "data");
}

//____________________________________________________________________________
void CycleBase::m_set_properties()
{
    SCycleConfig::property_type properties = this->GetConfig().GetProperties();
    for( SCycleConfig::property_type::const_iterator itr = properties.begin(); itr != properties.end(); ++itr)
    {
        std::map< std::string, std::string >::iterator m_itr = m_configs.find( (*itr).first );
        if( m_itr == m_configs.end() ) continue;
        (*m_itr).second = (*itr).second;
    }
}


// EOF
