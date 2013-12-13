#include "CommonTools/include/EgammaScaleFactorTool.h"

#include <string>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "ElectronEfficiencyCorrection/TElectronEfficiencyCorrectionTool.h"
#include "PATCore/TResult.h"

// -----------------------------------------------------------------------------
CommonTools::EgammaScaleFactorTool::EgammaScaleFactorTool( SCycleBase* parent
                 , const char* name
                 )
                 : ToolBase(parent, name)
{
  DeclareProperty("do_scaling", c_do_scaling = false);
  DeclareProperty("is_af2", c_is_af2 = false);
  DeclareProperty("sf_dir"    , c_egamma_sf_dir ="" );

  // get default path for egamma SF directory.
  if (c_egamma_sf_dir == "") {
    std::string maindir = "";
    char *tmparea=getenv("ROOTCOREDIR");
    if (tmparea != NULL) {
      maindir = tmparea;
      maindir = maindir + "/";
    }
    c_egamma_sf_dir = maindir + "../ElectronEfficiencyCorrection/data/";
  }

  m_reco_file_name =
    c_egamma_sf_dir + "efficiencySF.offline.RecoTrk.2012.8TeV.rel17p2.v02.root";

  m_tight_file_name =
    c_egamma_sf_dir + "efficiencySF.offline.Tight.2012.8TeV.rel17p2.v02.root";


  //ToDo double check we want this.
  m_trigger_file_name =
    c_egamma_sf_dir +"efficiencySF.e24vhi_medium1_e60_medium1.Tight.2012.8TeV.rel17p2.v02.root";

}

// -----------------------------------------------------------------------------
void CommonTools::EgammaScaleFactorTool::BeginInputData(const SInputData&)
{
  // do nothing


  m_eg_reco_sf.addFileName(m_reco_file_name);
  m_eg_reco_sf.initialize();


  m_eg_tight_sf.addFileName(m_tight_file_name);
  m_eg_tight_sf.initialize();


  m_eg_trigger_sf.addFileName(m_trigger_file_name);
  m_eg_trigger_sf.initialize();

}


// -----------------------------------------------------------------------------
void CommonTools::EgammaScaleFactorTool::EndInputData(const SInputData&)
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::EgammaScaleFactorTool::getSF( Electron* el,
						  Event* event
						  )
{
  double sf = 1.;
  if (!is_data() && c_do_scaling) {
    float cl_et = el->getRawTlv().E()/cosh(el->cl_eta());

    float pt = el->getTlv().Pt();

    PATCore::ParticleDataType::DataType data_type = ( c_is_af2
                                                    ? PATCore::ParticleDataType::Fast
                                                    : PATCore::ParticleDataType::Full
                                                    );

    Root::TResult result_reco = m_eg_reco_sf.calculate(data_type
    							      , event->RunNumber()
    							      , el->cl_eta()
    							      , pt);
    Root::TResult result_tight = m_eg_tight_sf.calculate(data_type
    							       , event->RunNumber()
    							       , el->cl_eta()
    							       , pt);

    double result_trigger = 1.0;

    sf = result_reco * result_tight * result_trigger;



  }
  return sf;
}
// -----------------------------------------------------------------------------
double CommonTools::EgammaScaleFactorTool::getSFUncertainty( Electron* el,
							     Event * event
							     )
{
  float sfUnc = 0.;
  if (!is_data() && c_do_scaling){


    float cl_et = el->getRawTlv().E()/cosh(el->cl_eta());

    float pt = el->getTlv().Pt();

    PATCore::ParticleDataType::DataType data_type = ( c_is_af2
                                                    ? PATCore::ParticleDataType::Fast
                                                    : PATCore::ParticleDataType::Full
                                                    );


    Root::TResult result_reco = m_eg_reco_sf.calculate(data_type
    					   , event->RunNumber()
    					   , el->cl_eta()
    					   , pt);
    Root::TResult result_tight = m_eg_tight_sf.calculate(data_type
    					     , event->RunNumber()
    					     , el->cl_eta()
    					     , pt);


    sfUnc = result_reco.getTotalUncertainty() * result_tight.getTotalUncertainty()
      /* * result_trigger.getTotalUncertainty()*/;
  }
  return sfUnc;
}
