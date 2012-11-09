#include "include/TopTagTool.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"


// -----------------------------------------------------------------------------
CommonTools::TopTagTool::TopTagTool( SCycleBase* parent
                                   , const char* name
                                   )
                                   : ToolBase(parent, name)
{
  // do nothing
}

// -----------------------------------------------------------------------------
CommonTools::TopTagTool::~TopTagTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void CommonTools::TopTagTool::init()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  DeclareProperty("pt_j_cut"  , c_pt_j_cut   = 30000. );
  DeclareProperty("m_eff_cut" , c_eff_cut    = 100000.);
  DeclareProperty("n_jet_scan", c_n_jet_scan = 3      );
}
// -----------------------------------------------------------------------------
double CommonTools::TopTagTool::mct(Jet* j1, Jet* j2)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  TLorentzVector t1 = j1->getTlv();
  TLorentzVector t2 = j2->getTlv();

  return calc_mct(t1, t2);
}

// -----------------------------------------------------------------------------
double CommonTools::TopTagTool::calc_mct( const TLorentzVector& t1
                                        , const TLorentzVector& t2
                                        )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  float mct = (t1.Mt() + t2.Mt())*(t1.Mt() + t2.Mt()) - (t1-t2).Perp2();
  mct = (mct >= 0.) ? sqrt(mct) : sqrt(-mct);

  return mct;
}


// -----------------------------------------------------------------------------
/*
 * Main method for the top-tagger algorithm described in ATL-COM-2011-XXX
 *
 * Inputs:
 *    ptjcut = cut on jets used by the tagger, (2011 analysis: 20 GeV)
 *  meffcut = effective mass cut, (2011 analysis: 100 GeV)
 *  njcut = number of jets considered (2011 analysis: 3)
 *  v1l, v2l = 4-momenta of the two leptons
 */
int CommonTools::TopTagTool::toptag( double ptjcut
                                   , double meffcut
                                   , int njetscan
                                   , TLorentzVector v1l
                                   , TLorentzVector v2l
                                   , std::vector<TLorentzVector> jets
                                   , TVector2 met
                                   )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // iopt = 0 - paper-like algorithm
  //      = 1 - consider only combinations including the most energetic jet
  int iopt = 0;

  bool itopll = toptag0j(v1l, v2l, met);
  if(!itopll) return 0;

  bool itop=false;
  int npairs = 0;
  int njet=jets.size();
  if(njet<njetscan) njetscan=njet;

  for (int i1=0; i1<njetscan-1; ++i1) {
    if(i1 == 0 || iopt == 0){
      for (int i2=i1+1; i2<njetscan; ++i2) {
        TLorentzVector v1j=jets.at(i1);
        TLorentzVector v2j=jets.at(i2);
        itop = toptag2j(ptjcut, meffcut, v1l, v2l, v1j, v2j, met, iopt);
        if(itop)npairs++;
      }
    }
  }
  return npairs;
}

// -----------------------------------------------------------------------------
bool CommonTools::TopTagTool::toptag0j( TLorentzVector v1l
                                      , TLorentzVector v2l
                                      , TVector2 met
                                      )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  static const Double_t wmass = 80400.;
  double metx = met.X();
  double mety = met.Y();

  // First mct(ll)
  //---------------
  double mctll=calc_mct(v1l,v2l);

  double pxus=v1l.Px()+v2l.Px()+metx;
  double pyus=v1l.Py()+v2l.Py()+mety;
  double rr=sqrt(pxus*pxus+pyus*pyus)/(2.*wmass);
  double fact=rr+sqrt(1+rr*rr);

  //cout << "mctll " << mctll << " cut value " << wmass*fact << std::endl;
  return mctll < wmass*fact ? true: false;
}

// -----------------------------------------------------------------------------
bool CommonTools::TopTagTool::toptag2j( double ptjcut
                                      , double meffcut
                                      , TLorentzVector v1l
                                      , TLorentzVector v2l
                                      , TLorentzVector v1j
                                      , TLorentzVector v2j
                                      , TVector2 met
                                      , int iopt
                                      )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  static const Double_t tmass = 172500.;
  static const Double_t mljcut = 155000.;
  static const Double_t mctjcut = 137000.;
  //
  TLorentzVector vjb[2];
  double ml1j[2];
  double ml2j[2];
  //
  double metx = met.X();  double mety = met.Y();
  double ptl1=v1l.Pt(); double ptl2=v2l.Pt();
  double ptj1=v1j.Pt(); double ptj2=v2j.Pt();
  double pxus=v1l.Px()+v2l.Px()+metx;
  double pyus=v1l.Py()+v2l.Py()+mety;
  double mefftop=ptj1+ptj2+ptl1+ptl2;

  if(ptj2 < ptjcut) return false;
  if(iopt == 0 && mefftop < meffcut) return false;

  // First part:
  //-------------
  vjb[0]=v1j;
  vjb[1]=v2j;
  double mctjj=calc_mct(vjb[0],vjb[1]);
  double pxusjl=vjb[0].Px()+vjb[1].Px()+pxus;
  double pyusjl=vjb[0].Py()+vjb[1].Py()+pyus;
  double rrj=sqrt(pxusjl*pxusjl+pyusjl*pyusjl)/(2.*tmass);
  double factj=rrj+sqrt(1+rrj*rrj);

  bool imct = mctjj < mctjcut*factj ? true : false;
  if(iopt==1) return imct;
  // Second part:
  //--------------
  for(int i=0;i<2;++i) {
    ml1j[i]=(v1l+vjb[i]).M();
    ml2j[i]=(v2l+vjb[i]).M();
  }
  int ncou=0;
  int icou1[2];
  int icou2[2];
  for(int i=0;i<2;++i) {
    for(int j=0;j<2;++j) {
      if(i != j) {
        if(ml1j[i]<mljcut && ml2j[j]<mljcut) {
          icou1[ncou]=i;
          icou2[ncou]=j;
          ncou++;
        }
      }
    }
  }
  bool imjl = ncou>0 ? true : false;

  // Third part: finally mct(ql,ql) for each coupling passing the mjl cut
  //-------------exploit the dependence of mct((jl),(jl)) on the maximum
  //             mass^2 of the two jl combinations
  int ngcou=0;
  for(int i=0;i<ncou;++i) {
    int ij1=icou1[i];
    int ij2=icou2[i];
    TLorentzVector vtot1=vjb[ij1]+v1l;
    TLorentzVector vtot2=vjb[ij2]+v2l;

    double mctjl=calc_mct(vtot1,vtot2);
    double mm1=(vjb[ij1]+v1l).M();
    double mm2=(vjb[ij2]+v2l).M();
    double mmax2 = mm1>mm2 ? (mm1*mm1) : (mm2*mm2);
    double upl=mmax2/(tmass)+(tmass);
    //cout << " i " << " mctjl " << mctjl << " mmax2 " << mmax2 <<
    //" upl " << upl << endl;
    if(mctjl < upl*factj )  ngcou++;
  }

  bool imctjl = ngcou>0 ? true : false;
  //cout << " ll " << imctll << " ct " << imct << " jl " << imjl <<
  //" ctlj " << imctjl << endl;

  return imct & imjl & imctjl;
}

// -----------------------------------------------------------------------------
bool CommonTools::TopTagTool::isTopTagged(
    std::vector<TLorentzVector>& jets_vec,
    TLorentzVector& tlv_lep_1,
    TLorentzVector& tlv_lep_2,
    TVector2& met_vec)
{


  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check top tag
  int nsolutions = -1;
  nsolutions = toptag( c_pt_j_cut
                     , c_eff_cut
                     , c_n_jet_scan
                     , tlv_lep_1
                     , tlv_lep_2
                     , jets_vec
                     , met_vec
                     );

  // if nsolutions > 0, we found ttbar flag
  return (nsolutions > 0);
}
