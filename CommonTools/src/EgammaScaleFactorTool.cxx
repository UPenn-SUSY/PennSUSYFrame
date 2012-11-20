#include "include/EgammaScaleFactorTool.h"
// -----------------------------------------------------------------------------
CommonTools::EgammaScaleFactorTool::EgammaScaleFactorTool( SCycleBase* parent
                 , const char* name
                 )
                 : ToolBase(parent, name)
{
  DeclareProperty("do_scaling", c_do_scaling = false);
}

// -----------------------------------------------------------------------------
void CommonTools::EgammaScaleFactorTool::BeginInputData(const SInputData&)
{
  // do nothing
}


// -----------------------------------------------------------------------------
void CommonTools::EgammaScaleFactorTool::EndInputData(const SInputData&)
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::EgammaScaleFactorTool::getSF( Electron* el
                                                , int set
                                                , int rel
                                                , int mode
                                                , int range
                                                )
{
  double sf = 1.;
  if (!is_data() && c_do_scaling) {
    float cl_et = el->getRawTlv().E()/cosh(el->cl_eta());

    if (mode == 0 || mode == 1) {
      sf *= m_eg_sf.scaleFactor( el->cl_eta()
                               , cl_et
                               , set
                               , range
                               , rel
                               ).first;
    }
    if (mode == 0 || mode == 2) {
      sf *= m_eg_sf.scaleFactor( el->cl_eta()
                               , cl_et
                               , 4 /*reco+trkqual SF*/
                               , range
                               , rel
                               ).first;
    }
  }
  return sf;
}
// -----------------------------------------------------------------------------
double CommonTools::EgammaScaleFactorTool::getSFUncertainty( Electron* el
                                                           , int set
                                                           , int rel
                                                           , int mode
                                                           , int range
                                                           )
{
  float sfUnc = 0.;
  if (!is_data() && c_do_scaling){
    float cl_et = el->getTlv().E()/cosh(el->cl_eta());
    if (mode == 0 || mode == 1) {
      sfUnc = m_eg_sf.scaleFactor( el->cl_eta()
                                 , cl_et
                                 , set
                                 , range
                                 , rel
                                 ).second;
    }
    if (mode == 0 || mode == 2) {
      float sf = m_eg_sf.scaleFactor( el->cl_eta()
                                    , cl_et
                                    , 4 /*reco+trkqual SF*/
                                    , range
                                    , rel
                                    ).second;
      sfUnc = sqrt(sfUnc*sfUnc + sf*sf);
    }
  }
  return sfUnc;
}
