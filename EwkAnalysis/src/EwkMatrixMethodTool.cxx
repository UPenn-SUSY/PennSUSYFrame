#include "EwkAnalysis/include/EwkMatrixMethodTool.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include <vector>
#include <string>
//#include "RootCore/SusyMatrixMethod/SusyMatrixMethod/DiLeptonMatrixMethod.h"
//#include "RootCore/SusyMatrixMethod/SusyMatrixMethod/FakeRegions.h"

#include "RootCore/DileptonMatrixMethod/DileptonMatrixMethod/DileptonMatrixMethod.h"
#include "RootCore/DileptonMatrixMethod/DileptonMatrixMethod/Lepton.h"

// -----------------------------------------------------------------------------
PennSusyFrame::MatrixMethodTool::MatrixMethodTool() 
{
  std::string root_core_dir = getenv("ROOTCOREDIR");
  //m_fake_rate_file = root_core_dir + "/../SusyMatrixMethod/data/FinalFakeHist_Jan_02.root";
  m_fake_rate_file = root_core_dir + "/../DileptonMatrixMethod/data/FakeMatrix_Jul_25_tight_05.root";


  std::vector<std::string> region_names; 
  region_names.push_back("ssinc1j");

  m_matrix_method.configure(m_fake_rate_file
			    , region_names
			    , susy::fake::Parametrization::PT
			    , susy::fake::Parametrization::PT
			    , susy::fake::Parametrization::PT
			    , susy::fake::Parametrization::PT
			    );
  

}

// -----------------------------------------------------------------------------
PennSusyFrame::MatrixMethodTool::~MatrixMethodTool()
{
}
// -----------------------------------------------------------------------------
double PennSusyFrame::MatrixMethodTool::getSF( FLAVOR_CHANNEL flavor_channel
                                           , const std::vector<PennSusyFrame::Electron*>* el
                                           , const std::vector<PennSusyFrame::Muon*>* mu
					   , const PennSusyFrame::Met Met     
                                           )
{

  //should be passed baseline muons and electrons

  double fake_rate_sf = 0.;

  if(flavor_channel == FLAVOR_NONE) return fake_rate_sf;


  bool is_electron_0 = 0;
  bool is_electron_1 = 0;

  bool is_tight_0 = 0.;
  bool is_tight_1 = 0.;

  float pt_0 = 0.;
  float pt_1 = 0.;

  float eta_0 = 0.;
  float eta_1 = 0.;

 


  if (flavor_channel == FLAVOR_MM) {
    is_electron_0 = false;
    is_electron_1 = false;

    is_tight_0 = mu->at(0)->getIsSignal();
    is_tight_1 = mu->at(1)->getIsSignal();

    pt_0 = mu->at(0)->getPt();
    pt_1 = mu->at(1)->getPt();

    eta_0 = mu->at(0)->getEta();
    eta_1 = mu->at(1)->getEta();

  }
  else if (flavor_channel == FLAVOR_EE) {

    is_electron_0 = true;
    is_electron_1 = true;


    is_tight_0 = el->at(0)->getIsSignal();
    is_tight_1 = el->at(1)->getIsSignal();

    pt_0 = el->at(0)->getPt();
    pt_1 = el->at(1)->getPt();

    eta_0 = el->at(0)->getEta();
    eta_1 = el->at(1)->getEta();


  }
  else if (flavor_channel == FLAVOR_EM) {
    is_electron_0 = true;
    is_electron_1 = false;


    is_tight_0 = el->at(0)->getIsSignal();
    is_tight_1 = mu->at(0)->getIsSignal();

    pt_0 = el->at(0)->getPt();
    pt_1 = mu->at(0)->getPt();

    eta_0 = el->at(0)->getEta();
    eta_1 = mu->at(0)->getEta();


   
  }

  susy::fake::Lepton lepton_0(is_tight_0, is_electron_0, pt_0, eta_0);
  susy::fake::Lepton lepton_1(is_tight_1, is_electron_1, pt_1, eta_1);


fake_rate_sf = m_matrix_method.getTotalFake( lepton_0, lepton_1,
					     m_matrix_method.getIndexRegion("ssinc1j")
					     , Met.getMetRel()
					     , susy::fake::Systematic::SYS_NOM
					     );

  return fake_rate_sf;
}
