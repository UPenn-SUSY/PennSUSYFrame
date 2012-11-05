// file:        CycleBase.h
// author:      Ryan Reece       <ryan.reece@cern.ch>
// created:     October 2010
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_CycleBase_h
#define AtlasSFrameUtils_CycleBase_h

// STL
#include <string>
#include <list>
#include <map>

// SFrame
#include "core/include/SError.h"
#include "core/include/SCycleBase.h"
#include "plug-ins/include/SSummedVar.h"

// ROOT
#include "TTree.h"

// local
#include "ToolBase.h"
#include "StringHelper.h"


class CycleBase: public SCycleBase
{

  friend class ToolBase;
    public:

        CycleBase();
        virtual ~CycleBase();

        // SFrame event-loop functions, called by the framework, not the user.
        void BeginCycle() throw (SError);
        void EndCycle() throw (SError);
        void BeginMasterInputData(const SInputData& id) throw (SError);
        void EndMasterInputData(const SInputData& id) throw (SError);
        void BeginInputData(const SInputData& id) throw (SError);
        void EndInputData(const SInputData& id) throw (SError);
        void BeginInputFile(const SInputData& id) throw (SError);
        void ExecuteEvent(const SInputData& id, Double_t weight) throw (SError);

        // additional public methods
        inline bool is_data() const { return m_is_data; }

        //helper storing configuration
        void InsertMetadata( const std::map<std::string
                           , std::string> &config
                           , const char* name
                           );


    protected:

        // derived cycles should implement these as needed.
        virtual void BeginCycleImp() throw (SError) {}
        virtual void EndCycleImp() throw (SError) {}
        virtual void BeginInputDataImp(const SInputData&) throw (SError) {}
        virtual void EndInputDataImp(const SInputData&) throw (SError) {}
        virtual void BeginMasterInputDataImp(const SInputData&) throw (SError) {}
        virtual void EndMasterInputDataImp(const SInputData&) throw (SError) {}
        virtual void BeginInputFileImp(const SInputData&) throw (SError) {}
        virtual void ExecuteEventImp(const SInputData&, Double_t) throw (SError) {}
        // virtual void BeginInputDataImp(const SInputData& id) throw (SError) {}
        // virtual void EndInputDataImp(const SInputData& id) throw (SError) {}
        // virtual void BeginMasterInputDataImp(const SInputData& id) throw (SError) {}
        // virtual void EndMasterInputDataImp(const SInputData& id) throw (SError) {}
        // virtual void BeginInputFileImp(const SInputData& id) throw (SError) {}
        // virtual void ExecuteEventImp(const SInputData& id, Double_t weight) throw (SError) {}

        // methods provided to derived classes
        template<class T>
        void DeclareProperty( const std::string& name, T& value );

        template<class T>
        void DeclareProperty( const char* name, T& value);

        void        DeclareTool( ToolBase* tool );
        ToolBase*   GetTool( const std::string& name ) throw (SError);
        TTree*      GetTree( const std::string& name );
        void        Print();

        TH1* Hist(const std::string& name, const std::string& directory = "" );

        // support for various TH1D and TH2D constructors
        TH1D* Book( const std::string& name, const std::string& title,
            int nbins, float min, float max,
            const std::string& directory = "" );
        TH1D* Book( const std::string& name, const std::string& title,
            int nbins, const float* xbins,
            const std::string& directory = "" );
        TH1D* Book( const std::string& name, const std::string& title,
            int nbins, const double* xbins,
            const std::string& directory = "" );
        TH2D* Book( const std::string& name, const std::string& title,
            int nbinsx, float minx, float maxx, int nbinsy, float miny,
            float maxy, const std::string& directory = "");
        TH2D* Book( const std::string& name, const std::string& title,
            int nbinsx, const double* xbins, int nbinsy, float miny, float maxy,
            const std::string& directory = "");
        TH2D* Book( const std::string& name, const std::string& title,
            int nbinsx, float minx, float maxx, int nbinsy, const double* ybins,
            const std::string& directory = "");
        TH2D* Book( const std::string& name, const std::string& title,
            int nbinsx, const float* xbins,
            int nbinsy, const float* ybins, const std::string& directory = "");
        TH2D* Book( const std::string& name, const std::string& title,
            int nbinsx, const double* xbins,
            int nbinsy, const double* ybins, const std::string& directory = "");


        bool Cut(const std::string& cut_name, bool requirement,
            bool skip_event = false) throw( SError );
        bool CutFlow(const std::string& cut_name, bool requirement,
            bool skip_event = false, float weight = 1.0) throw( SError );
        void ResetCutIndex();
        void PrintCutFlow(const SInputData& id) throw( SError );

        std::map<std::string, bool> m_cut_results;
        Long64_t m_entry_number;

    private:

  /// Function searching for 1-dimensional histograms in the output file
  /// Don't want client cycles calling this
  TH1* m_hist( const char* name, const char* dir = 0 ) throw (SError);
  void PublishHists();
  void CollectHists();
  void Book( const std::string& name, const std::string& directory, TH1* histo );

        // SFrame event-loop functions over tools
        void m_BeginCycleTools();
  void m_PrintTools();
        void m_PublishToolHists();
        void m_EndCycleTools();
        void m_BeginInputDataTools( const SInputData& id );
        void m_EndInputDataTools( const SInputData& id );
        void m_BeginMasterInputDataTools( const SInputData& id );
  void m_CollectToolHists();
        void m_EndMasterInputDataTools( const SInputData& id );
        void m_BeginInputFileTools( const SInputData& id );
        void m_BeginExecuteEventTools( const SInputData& id, Double_t weight );

        // tool iterators typedef
        typedef std::list<ToolBase* >::iterator ToolIterator;

        // helper private methods
        ToolIterator m_FindTool(const std::string& name);
        void m_set_is_data(const SInputData& id);
        void m_set_properties();

        // private data
        std::list<ToolBase*> m_tools;   // tools belonging to this cycle
      std::map<std::string, std::string> m_configs;
        bool m_is_data;
        SSummedVar<long> m_all_events;
        SSummedVar<long> m_passed_events;
        std::vector<std::string>* m_branch_metadata;

#ifndef __MAKECINT__
  std::map< std::pair< std::string, std::string >, TH1* >* m_histoMap;
#endif // __MAKECINT__

  //configurables
  //add histograms from input files in output file
  std::vector<std::string> c_input_file_hists;
      bool c_do_metadata;

        int m_cut_index;
        int m_cut_index_reset;
        bool m_passed_cut_flow;
        bool m_passed_cut_flow_reset;

  ClassDef( CycleBase, 0 );
}; // class CycleBase


//____________________________________________________________________________
template<class T>
void CycleBase::DeclareProperty( const std::string& name, T& value)
{
    // prepend tool name to configurable name: ToolName_configurable
    SCycleBase::DeclareProperty( name, value );
    std::string value_s = StringHelper::returnString( value );
    m_configs.insert( std::make_pair( name, value_s ) );

}


//____________________________________________________________________________
template<class T>
void CycleBase::DeclareProperty( const char* name, T& value)
{
    DeclareProperty( std::string(name), value );
}

#endif // AtlasSFrameUtils_CycleBase_h
