// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_TopTagTool_H
#define CommonTools_TopTagTool_H
// ============================================================================

#include "TLorentzVector.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/JetContainer.h"

// //--- In the Loop Function:
//
// int nsolutions = -1;
// nsolutions = toptag(20000., 100000., 3, l1, l2, finaljets, met);
// if(nsolutions>0){
//   // There is a ttbar
// }



// ============================================================================
namespace CommonTools{
// ============================================================================

  class TopTagTool : public ToolBase
  {
  public:
    TopTagTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~TopTagTool();

    void init();

    double mct(Jet*,Jet*);

    //bool isTopTagged();

    bool isTopTagged( std::vector<TLorentzVector>& jet_vec
		      , TLorentzVector& lepton_1
		      , TLorentzVector& lepton_2
		      , TVector2& met_vec
		      );

    template<class T1, class T2>
    bool isTopTagged( std::vector<Jet*>&
		      , T1* lepton_1
		      , T2* lepton_2
		      , Met* met
		      );
    
    template<class T1, class T2>
    bool isTopTagged( const JetContainer& jets 
		      , T1* lepton_1
		      , T2* lepton_2
		      , Met* met_vec
		      );
    
  private:
 
    double c_pt_j_cut;
    double c_eff_cut;
    int    c_n_jet_scan;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    double calc_mct(const TLorentzVector&, const TLorentzVector&);

    int toptag( double ptjcut
              , double meffcut
              , int njetscan
              , TLorentzVector v1l
              , TLorentzVector v2l
              , std::vector<TLorentzVector> jets
              , TVector2 met
              );


    bool toptag0j(TLorentzVector v1l,TLorentzVector v2l, TVector2 met);
    bool toptag2j( double ptjcut
                 , double meffcut
                 , TLorentzVector v1l
                 , TLorentzVector v2l
                 , TLorentzVector v1j
                 , TLorentzVector v2j
                 , TVector2 met
                 , int iopt
                 );

   

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(TopTagTool, 0);

  };

}
// Include the implementation:
#ifndef __CINT__
#include "TopTagTool.icc"
#endif // __CINT__


#endif

