//TO DO remove the c_do_trigger_matching from the
//phase space when 2012 is settled

#include <math.h>

#include "include/TriggerCutTool.h"

// #include "include/MersenneTwister.h" // random number generator, needed for testSasa only

// ----------------------------------------------------------------------------
SelectionTools::TriggerCutTool::TriggerCutTool(
    SCycleBase* parent, const char* name) : ToolBase(parent, name)
                                          // , c_check_against_official(false)
                                          // , m_triggerReweight(NULL)
{
  DeclareProperty("do_trigger_matching", c_do_trigger_matching = false);

  // m_triggerReweight = new triggerReweight2Lep();

  // std::string directory = "./RootCore/DGTriggerReweight/data";
  // std::string periods = "A-B3"; // this is the argument that needs to be modified for more data - change to "HCP" for the fall 2012 dataset
  // m_triggerReweight->setDbg(1);
  // m_triggerReweight->initialize(directory, periods);
  // m_triggerReweight->setDbg(0);
}

// ----------------------------------------------------------------------------
SelectionTools::TriggerCutTool::~TriggerCutTool() {
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// printf("test SelectionTools::TriggerCutTool::~TriggerCutTool()\n");

  //	this->testSasa();

	// if (m_triggerReweight) {
	// 	delete m_triggerReweight;
	// 	m_triggerReweight = 0;
	// }
}

/*
void SelectionTools::TriggerCutTool::testSasa(){

	static int count = 0;
	if (count>0) return;
	count++;

	MTRand rand;

	FILE *f = fopen("test_trigger.txt", "w");
	int count_nan = 0;
	for (int i=0; i<100000; i++) {

		double pt1 = 10. + 20. * rand.rand();
		double pt2 = 10. + 20. * rand.rand(); // electrons
		//		double pt1 = pt2 - 1.;
		//		while (pt1<pt2) { pt1 = 10. + 20. * rand.rand(); }
		pt1 *= 1000.;
		pt2 *= 1000.;
		double eta1 = 2.4 * 2 * (rand.rand()-0.5);
		double eta2 = 2.4 * 2 * (rand.rand()-0.5);
		double phi1 = 3.1415 * 2. * (rand.rand()-0.5);
		double phi2 = 3.1415 * 2. * (rand.rand()-0.5);

		//		double more_info[100]; for (int j=0; j<100; j++) more_info[j] = 0.;
		//		m_triggerReweight->testTriggerWeights(pt1, eta1, phi1, pt2, eta2, phi2, 1, 0, more_info);

		double ee_official_weight(-999.), mumu_official_weight(-999.);
		if (pt1>=pt2) {
			ee_official_weight = m_triggerReweight->triggerReweightEE(pt1, eta1, pt2, eta2);
			mumu_official_weight = m_triggerReweight->triggerReweightMM(pt1, eta1, phi1, 1, pt2, eta2, phi2, 1 );
		}
		double emu_official_weight  = m_triggerReweight->triggerReweightEMU(pt1, eta1, pt2, eta2, phi2, 1 );

		if (i<20) printf("test ee asym %lf %lf %lf %lf %lf %lf %lf \n", pt1, eta1, pt2, eta2, ee_official_weight, mumu_official_weight, emu_official_weight );
		fprintf(f, "%lf %lf %lf %lf %lf %lf %lf \n", pt1, eta1, pt2, eta2, ee_official_weight, mumu_official_weight, emu_official_weight );

	}
	fclose(f);

	printf("test sasa m_triggerReweight\n");
	return;
}

double SelectionTools::TriggerCutTool::EEweight(std::vector<Electron>& el){

  if (el.size() < 2) return 0.;

  // triggerReweightEE code orders electrons by pT in ant case
    TLorentzVector tlv1 = el[0].getTlv();
  TLorentzVector tlv2 = el[1].getTlv();

  double weight = m_triggerReweight->triggerReweightEE(tlv1.Pt(), tlv1.Eta(), tlv2.Pt(), tlv2.Eta());

  return weight;
}

double SelectionTools::TriggerCutTool::MuMuweight(std::vector<Muon>& mu){

  if (mu.size() < 2) return 0.;

  // triggerReweightMM code does not order muons by pT, have to do it by hand

  int leading_pt_muon_index = ( mu[0].getTlv().Pt() >= mu[1].getTlv().Pt() ) ? 0 : 1 ;

  TLorentzVector tlv1 = mu[leading_pt_muon_index].getTlv();
  TLorentzVector tlv2 = mu[1-leading_pt_muon_index].getTlv();

  double weight = m_triggerReweight->triggerReweightMM(tlv1.Pt(), tlv1.Eta(), tlv1.Phi(), mu[leading_pt_muon_index].isCombinedMuon(), tlv2.Pt(), tlv2.Eta(), tlv2.Phi(), mu[1-leading_pt_muon_index].isCombinedMuon());

  return weight;
}
double SelectionTools::TriggerCutTool::EMuweight(std::vector<Electron>& el, std::vector<Muon>& mu) {

  if (el.size()==0 || mu.size()==0) return 0.;

  TLorentzVector tlv1 = el[0].getTlv();
  TLorentzVector tlv2 = mu[0].getTlv();

  double weight = m_triggerReweight->triggerReweightEMU(tlv1.Pt(), tlv1.Eta(), tlv2.Pt(), tlv2.Eta(), tlv2.Phi(), mu[0].isCombinedMuon() ); ;

  return weight;
}
*/

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedAnySingleOrDiLeptonTrigger(
    const Event* event,
    const Trigger* trig)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  bool pass_trigger = (  passedEETriggerChannel(  event, trig)
                      || passedMuMuTriggerChannel(event, trig)
                      || passedEMuTriggerChannel( event, trig)
                      || passedMuETriggerChannel( event, trig)
                      );
  return pass_trigger;
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEEPhaseSpace(
    const ElectronContainer& electrons,
    const MuonContainer& /*muons*/)
{
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuMuPhaseSpace(
    const ElectronContainer& /*electrons*/,
    const MuonContainer& muons)
{
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEMuPhaseSpace(
    const ElectronContainer& electrons,
    const MuonContainer& muons)
{
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuEPhaseSpace(
    const ElectronContainer& electrons,
    const MuonContainer& muons)
{
  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEETriggerChannel(
    const Event* event,
    const Trigger* trig)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  return passedEETrigger2012(event, trig);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuMuTriggerChannel(
    const Event* event,
    const Trigger* trig)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  return passedMuMuTrigger2012(event, trig);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEMuTriggerChannel(
    const Event* event,
    const Trigger* trig)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  return passedEMuTrigger2012(event, trig);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuETriggerChannel(
    const Event* event,
    const Trigger* trig)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  return passedMuETrigger2012(event, trig);
}


/*
// =============================================================================
// - trigger matching
// =============================================================================
// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEETriggerMatching(
    Event& event,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Electron>& el)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // std::cout << "passedEETriggerMatching\n";
  // TODO make user configurable trigger cut
  bool my_code = passedEETriggerMatching2012(event, trig_vec, el);

  if (c_check_against_official) {
    bool official_code = passedEETriggerMatch_anders(event, trig_vec, el);

    if (my_code != official_code) {
      printf("passedEETriggerMatching TEST FAILED (sasa), I, official: %d %d, lepton size: %d\n", my_code?1:0, official_code?1:0, (int) el.size());
      if (el.size() > 1) {
        TLorentzVector tlv1 = el[0].getTlv();
        TLorentzVector tlv2 = el[1].getTlv();
        printf("pTs: %lf %lf\n", tlv1.Pt(), tlv2.Pt() );
      }
      // If conflict, call trigger match again with debug turned on
      passedEETriggerMatch_anders(event, trig_vec, el, true);
    }
    // else {
    //   printf("passedEETriggerMatching TEST PASSED (sasa), I, official: %d %d, lepton size: %ld\n", my_code?1:0, official_code?1:0, el.size());
    // }
  }

  return my_code;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuMuTriggerMatching(
    Event& event,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Muon>& mu)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // std::cout << "passedMuMuTriggerMatching\n";
  // TODO make user configurable trigger cut
  bool my_code = passedMuMuTriggerMatching2012(event, trig_vec, mu);

//  double test_mc_weight = this->MuMuweight( mu );
//  printf("test sasa muon MC weight: %lf\n", test_mc_weight);

  if (c_check_against_official) {
    bool official_code = passedMuMuTriggerMatch_anders(event, trig_vec, mu);

    if (my_code != official_code) {
      printf("passedMuMuTriggerMatching TEST FAILED (sasa), I, official: %d %d, lepton size: %d\n", my_code?1:0, official_code?1:0, (int) mu.size() );
      if (mu.size() > 1) {
        TLorentzVector tlv1 = mu[0].getTlv();
        TLorentzVector tlv2 = mu[1].getTlv();
        printf("pTs: %lf %lf\n", tlv1.Pt(), tlv2.Pt() );
      }
      // If conflict, call trigger match again with debug turned on
      passedMuMuTriggerMatch_anders(event, trig_vec, mu, true);
    }
    // else {
    //   printf("passedMuMuTriggerMatching TEST PASSED (sasa), I, official: %d %d, lepton size: %ld\n", my_code?1:0, official_code?1:0, mu.size());
    // }
  }

  return my_code;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEMuTriggerMatching(
    Event& event,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Electron>& el,
    std::vector<Muon>& mu)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // std::cout << "passedEMuTriggerMatching\n";
  // TODO make user configurable trigger cut
  bool my_code = passedEMuTriggerMatching2012(event, trig_vec, el, mu);

  if (c_check_against_official) {
    bool official_code = passedEMuTriggerMatch_anders(event, trig_vec, el, mu);

    if (my_code != official_code) {
      printf("passedEMuTriggerMatching TEST FAILED (sasa), I, official: %d %d, lepton size: %d %d\n", my_code?1:0, official_code?1:0, (int) el.size(), (int) mu.size() );
      if (el.size() > 0 && mu.size() > 0) {
        TLorentzVector el_tlv = el[0].getTlv();
        TLorentzVector mu_tlv = mu[0].getTlv();
        printf("pTs: %lf %lf\n", el_tlv.Pt(), mu_tlv.Pt() );
      }
      // If conflict, call trigger match again with debug turned on
      passedEMuTriggerMatch_anders(event, trig_vec, el, mu, true);
    }
    // else {
    //   printf("passedEMuTriggerMatching TEST PASSED (sasa), I, official: %d %d, lepton size: %ld %ld\n", my_code?1:0, official_code?1:0, el.size(), mu.size() );
    // }
  }

  return my_code;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuETriggerMatching(
    Event& event,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Electron>& el,
    std::vector<Muon>& mu)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // std::cout << "passedMuETriggerMatching\n";
  // TODO make user configurable trigger cut
  bool my_code = passedMuETriggerMatching2012(event, trig_vec, el, mu);

  if (c_check_against_official) {
    bool official_code = passedMuETriggerMatch_anders(event, trig_vec, el, mu);

    if (my_code != official_code) {
      printf("passedMuETriggerMatching TEST FAILED (sasa), I, official: %d %d, lepton size: %d %d\n", my_code?1:0, official_code?1:0, (int) el.size(), (int) mu.size() );
      if (el.size() > 0 && mu.size() > 0) {
        TLorentzVector el_tlv = el[0].getTlv();
        TLorentzVector mu_tlv = mu[0].getTlv();
        printf("pTs: %lf %lf\n", el_tlv.Pt(), mu_tlv.Pt() );
      }
      // If conflict, call trigger match again with debug turned on
      passedMuETriggerMatch_anders(event, trig_vec, el, mu, true);
    }
  }

  return my_code;
}



// -----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEETriggerMatch_anders(
    Event& event,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Electron>& el,
    bool / *debug* /)
{
  if (el.size()<2) return false;

  if (!is_data()) return true;

  TLorentzVector l1 = el[0].getTlv();
  TLorentzVector l2 = el[1].getTlv();

  // TODO do correct kinematic cuts for ee events
  // if ( l1.Pt()<14000. || l2.Pt()<8000. ) return false; // region B kinematic cuts

  TriggerMatch2Lep *triggerMatchTool = new TriggerMatch2Lep();

  int run = event.RunNumber();

  unsigned int electron_trigger_object_size = trig_vec.trig_EF_el_px()->size();
  std::vector<float> *trig_EF_el_px = trig_vec.trig_EF_el_px();
  std::vector<float> *trig_EF_el_py = trig_vec.trig_EF_el_py();
  std::vector<float> *trig_EF_el_pz = trig_vec.trig_EF_el_pz();
  std::vector<float> *trig_EF_el_E  = trig_vec.trig_EF_el_E();

  std::vector<int> *trig_EF_el_EF_e12Tvh_loose1 = trig_vec.trig_EF_el_EF_e12Tvh_loose1();
  std::vector<int> *trig_EF_el_EF_e24vh_medium1 = trig_vec.trig_EF_el_EF_e24vh_medium1();
  std::vector<int> *trig_EF_el_EF_e24vh_medium1_e7_medium1 = trig_vec.trig_EF_el_EF_e24vh_medium1_e7_medium1();

  bool pass_ee_trigger = triggerMatchTool->getElecTriggerMatch(
      l1, l2, run, electron_trigger_object_size,
      trig_EF_el_px, trig_EF_el_py, trig_EF_el_pz, trig_EF_el_E,
      trig_EF_el_EF_e12Tvh_loose1,
      trig_EF_el_EF_e24vh_medium1,
      trig_EF_el_EF_e24vh_medium1_e7_medium1);

  delete triggerMatchTool;
  return pass_ee_trigger;
}

bool SelectionTools::TriggerCutTool::passedMuMuTriggerMatch_anders(
    Event& event,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Muon>& mu,
    bool / *debug* /)
{
  if (mu.size()<2) return false;

  if (!is_data()) return true;

  TLorentzVector l1 = mu[0].getTlv();
  TLorentzVector l2 = mu[1].getTlv();

  // TODO do correct kinematic cuts for mumu events
  // if ( l1.Pt()<14000. || l2.Pt()<8000. ) return false; // region B kinematic cuts

  TriggerMatch2Lep *triggerMatchTool = new TriggerMatch2Lep();

  int run = event.RunNumber();

  std::vector<int> *trig_EF_el_EF_e12Tvh_medium1 =
      trig_vec.trig_EF_el_EF_e12Tvh_medium1();

  unsigned int muon_trigger_object_size =
      trig_vec.trig_EF_trigmuonef_track_CB_eta()->size();
  std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_eta =
      trig_vec.trig_EF_trigmuonef_track_CB_eta();
  std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_phi =
      trig_vec.trig_EF_trigmuonef_track_CB_phi();
  std::vector<std::vector<int> >   *trig_EF_trigmuonef_track_CB_hasCB =
      trig_vec.trig_EF_trigmuonef_track_CB_hasCB();

  std::vector<int> *trig_EF_trigmuonef_EF_mu18_tight =
      trig_vec.trig_EF_trigmuonef_EF_mu18_tight();
  std::vector<int> *trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS =
      trig_vec.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS();
   std::vector<int> *trig_EF_trigmuonef_EF_mu13 =
      trig_vec.trig_EF_trigmuonef_EF_mu13();

  bool pass_mumu_trigger = triggerMatchTool->getMuonTriggerMatch(
      l1, l2, run, muon_trigger_object_size,
      trig_EF_trigmuonef_track_CB_eta,
      trig_EF_trigmuonef_track_CB_phi,
      trig_EF_trigmuonef_track_CB_hasCB,
      trig_EF_trigmuonef_EF_mu18_tight,
      trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS,
      trig_EF_trigmuonef_EF_mu13);

  delete triggerMatchTool;
  return pass_mumu_trigger;
}

bool SelectionTools::TriggerCutTool::passedEMuTriggerMatch_anders(
    Event& event,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Electron>& el,
    std::vector<Muon>& mu,
    bool / *debug* /)
{
  if (el.size()<1 || mu.size()<1) return false;

  if (!is_data()) return true;

  TLorentzVector l1 = el[0].getTlv();
  TLorentzVector l2 = mu[0].getTlv();

  TriggerMatch2Lep *triggerMatchTool = new TriggerMatch2Lep();

  int run = event.RunNumber();

  unsigned int electron_trigger_object_size = trig_vec.trig_EF_el_px()->size();
  std::vector<float> *trig_EF_el_px = trig_vec.trig_EF_el_px();
  std::vector<float> *trig_EF_el_py = trig_vec.trig_EF_el_py();
  std::vector<float> *trig_EF_el_pz = trig_vec.trig_EF_el_pz();
  std::vector<float> *trig_EF_el_E  = trig_vec.trig_EF_el_E();

  std::vector<int> *trig_EF_el_EF_e12Tvh_medium1 = trig_vec.trig_EF_el_EF_e12Tvh_medium1();

  unsigned int muon_trigger_object_size =
      trig_vec.trig_EF_trigmuonef_track_CB_eta()->size();
  std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_eta =
      trig_vec.trig_EF_trigmuonef_track_CB_eta();
  std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_phi =
      trig_vec.trig_EF_trigmuonef_track_CB_phi();
  std::vector<std::vector<int> >   *trig_EF_trigmuonef_track_CB_hasCB =
      trig_vec.trig_EF_trigmuonef_track_CB_hasCB();

  std::vector<int> *trig_EF_trigmuonef_EF_mu8 =
      trig_vec.trig_EF_trigmuonef_EF_mu8();

  bool pass_emu_trigger = triggerMatchTool->getEmuTriggerMatch(
      l1, l2, run,
      electron_trigger_object_size,
      trig_EF_el_px, trig_EF_el_py, trig_EF_el_pz, trig_EF_el_E,
      muon_trigger_object_size,
      trig_EF_trigmuonef_track_CB_eta, trig_EF_trigmuonef_track_CB_phi,
      trig_EF_trigmuonef_track_CB_hasCB,
      trig_EF_el_EF_e12Tvh_medium1, trig_EF_trigmuonef_EF_mu8);

  delete triggerMatchTool;
  return pass_emu_trigger;
}

bool SelectionTools::TriggerCutTool::passedMuETriggerMatch_anders(
    Event& event,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Electron>& el,
    std::vector<Muon>& mu,
    bool / *debug* /)
{
  // static int count(0); count++; if (count<10) { printf("test sasa passedMuETriggerMatch calling the officieal code\n");  }

  if (el.size()<1 || mu.size()<1) return false;

  if (!is_data()) return true;

  TLorentzVector l1 = el[0].getTlv();
  TLorentzVector l2 = mu[0].getTlv();

  // if ( l1.Pt()<10000. || l1.Pt()>=14000. || l2.Pt()<18000. ) return false; // region B kinematic cuts

  TriggerMatch2Lep *triggerMatchTool = new TriggerMatch2Lep();

  int run = event.RunNumber();

  unsigned int electron_trigger_object_size = trig_vec.trig_EF_el_px()->size();
  std::vector<float> *trig_EF_el_px = trig_vec.trig_EF_el_px();
  std::vector<float> *trig_EF_el_py = trig_vec.trig_EF_el_py();
  std::vector<float> *trig_EF_el_pz = trig_vec.trig_EF_el_pz();
  std::vector<float> *trig_EF_el_E  = trig_vec.trig_EF_el_E();

  std::vector<int> *trig_EF_el_EF_e7T_medium1 =
      trig_vec.trig_EF_el_EF_e7T_medium1();
  std::vector<int> *trig_EF_el_EF_e12Tvh_medium1 =
      trig_vec.trig_EF_el_EF_e12Tvh_medium1();
  std::vector<int> *trig_EF_el_EF_e12Tvh_loose1 =
      trig_vec.trig_EF_el_EF_e12Tvh_loose1();
  std::vector<int> *trig_EF_el_EF_e24vh_medium1_e7_medium1 =
      trig_vec.trig_EF_el_EF_e24vh_medium1_e7_medium1();
  std::vector<int> *trig_EF_el_EF_e24vh_medium1 =
      trig_vec.trig_EF_el_EF_e24vh_medium1();

  unsigned int muon_trigger_object_size =
      trig_vec.trig_EF_trigmuonef_track_CB_eta()->size();
  std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_eta =
      trig_vec.trig_EF_trigmuonef_track_CB_eta();
  std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_phi =
      trig_vec.trig_EF_trigmuonef_track_CB_phi();
  std::vector<std::vector<int> >   *trig_EF_trigmuonef_track_CB_hasCB =
      trig_vec.trig_EF_trigmuonef_track_CB_hasCB();

  std::vector<int> *trig_EF_trigmuonef_EF_mu8 =
      trig_vec.trig_EF_trigmuonef_EF_mu8();
  std::vector<int> *trig_EF_trigmuonef_EF_mu13 =
      trig_vec.trig_EF_trigmuonef_EF_mu13();
  std::vector<int> *trig_EF_trigmuonef_EF_mu18_tight =
      trig_vec.trig_EF_trigmuonef_EF_mu18_tight();
  std::vector<int> *trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS =
      trig_vec.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS();

  bool pass_mue_trigger = triggerMatchTool->getMueTriggerMatch(
      l1, l2, run,
      electron_trigger_object_size,
      trig_EF_el_px, trig_EF_el_py, trig_EF_el_pz, trig_EF_el_E,
      muon_trigger_object_size,
      trig_EF_trigmuonef_track_CB_eta, trig_EF_trigmuonef_track_CB_phi,
      trig_EF_trigmuonef_track_CB_hasCB,
      trig_EF_el_EF_e7T_medium1, trig_EF_trigmuonef_EF_mu18_tight);

  bool pass_emu_trigger = triggerMatchTool->getEmuTriggerMatch(
      l1, l2, run,
      electron_trigger_object_size,
      trig_EF_el_px, trig_EF_el_py, trig_EF_el_pz, trig_EF_el_E,
      muon_trigger_object_size,
      trig_EF_trigmuonef_track_CB_eta, trig_EF_trigmuonef_track_CB_phi,
      trig_EF_trigmuonef_track_CB_hasCB,
      trig_EF_el_EF_e12Tvh_medium1, trig_EF_trigmuonef_EF_mu8);

  // if (pass_emu_trigger) { printf("pass_mue_trigger override, before %d\n", pass_mue_trigger?1:0); pass_mue_trigger = false;  }

  delete triggerMatchTool;
  return pass_mue_trigger;
}
*/





// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEETrigger2012(
    const Event* /*event*/,
    const Trigger* trig)
{
  if (!is_data()) return true;

  bool pass_single_trigger = false;
  bool pass_double_trigger = (  trig->EF_2e12Tvh_loose1()
                             || trig->EF_e24vh_medium1_e7_medium1()
                             );
  return (pass_single_trigger || pass_double_trigger);
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuMuTrigger2012(
    const Event* /*event*/,
    const Trigger* trig)
{
  if (!is_data()) return true;

  // this->testSasa();

  bool pass_single_trigger = false;
  bool pass_double_trigger = (  trig->EF_2mu13()
                             || trig->EF_mu18_tight_mu8_EFFS()
                             );
  return (pass_single_trigger || pass_double_trigger);
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEMuTrigger2012(
    const Event* /*event*/,
    const Trigger* trig)
{
  if (!is_data()) return true;

  bool pass_trigger = trig->EF_e12Tvh_medium1_mu8();
  return pass_trigger;
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuETrigger2012(
    const Event* /*event*/,
    const Trigger* trig)
{
  if (!is_data()) return true;

  bool pass_trigger = trig->EF_mu18_tight_e7_medium1();
  return pass_trigger;
}



/*
// 2012 trigger selection criteria
// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEETriggerMatching2012(
    Event& / *event* /,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Electron>& el)
{
  // immediately fail events with more/less than two electrons
  // if (el.size() != 2) return false;
  if (el.size() < 2) return false;

  if (!is_data()) return true;

  double pt0 = el.at(0).getTlv().Pt();
  double pt1 = el.at(1).getTlv().Pt();

  double pt_lead    = std::max(pt0, pt1);
  double pt_sublead = std::min(pt0, pt1);

  bool pass_trigger_match = false;

  if (  pt_lead    > 14000
     && pt_sublead > 14000
     ) {
    // region A (pt_lead > 14 GeV && pt_sublead > 14 GeV)

    // require both electrons match with EF_e12Tvh_loose1
    pass_trigger_match = passedElectronTriggerMatch(
        el, (*trig_vec.trig_EF_el_EF_e12Tvh_loose1()), trig_vec, 2, 0.15, 0);
  }
  else if (  pt_lead    > 25000
          && pt_sublead > 10000
          && pt_sublead < 14000
          ) {
    // region B (pt_lead > 25 GeV && 10 < pt_sublead < 14 GeV)

    // require the leading lepton matches with e24vh_medium1
    bool pass_single_match = false;
    if (pt0 >= pt1) {
      pass_single_match = passedElectronTriggerMatch(
          el[0], (*trig_vec.trig_EF_el_EF_e24vh_medium1()), trig_vec, 0.15, 0);
    }
    else {
      pass_single_match = passedElectronTriggerMatch(
          el[1], (*trig_vec.trig_EF_el_EF_e24vh_medium1()), trig_vec, 0.15, 0);
    }

    // require both leptons match with the e24vh_medium1_e7_medium1
    bool pass_double_match = passedElectronTriggerMatch(
        el, (*trig_vec.trig_EF_el_EF_e24vh_medium1_e7_medium1()),
        trig_vec, 2, 0.15, 0);

    // check the && of the single and double matches above
    pass_trigger_match = (pass_single_match && pass_double_match);
  }

  return pass_trigger_match;
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuMuTriggerMatching2012(
    Event& / *event* /,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Muon>& mu)
{
  // immediately fail events with more/less than two muons
  // if (mu.size() != 2) return false;
  if (mu.size() < 2) return false;

  if (!is_data()) return true;

  double pt0 = mu.at(0).getTlv().Pt();
  double pt1 = mu.at(1).getTlv().Pt();

  double pt_lead    = std::max(pt0, pt1);
  double pt_sublead = std::min(pt0, pt1);

  bool pass_trigger_match = false;

  if (  pt_lead    > 18000
     && pt_sublead > 18000
     ) {
    // region A (pt_lead > 18 GeV && pt_sublead > 18 GeV)

      // require at least one muon matches with ef_mu18_tight
      bool pass_single_match = passedMuonTriggerMatch(
          mu, (*trig_vec.trig_EF_trigmuonef_EF_mu18_tight()), trig_vec, 1, 0.15, 0);

      // require both muons match with ef_mu18_tight_mu8_effs
      bool pass_double_match = passedMuonTriggerMatch(
          mu, (*trig_vec.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS()), trig_vec,
          2, 0.15, 0);

      // check the && of the single and double match above
      pass_trigger_match = (pass_single_match && pass_double_match);
  }
  else if (  pt_lead    > 18000
          && pt_sublead < 18000
          && pt_sublead > 14000
          )
  {
    // region B (pt_lead > 18 GeV && 14 < pt_sublead < 18 GeV)

    // require leading muon matches with EF_mu18_tight
    bool pass_leading_match = false;
    if (pt0 >= pt1) {
      // std::cout << "\tleading match(0):\n";
      pass_leading_match = passedMuonTriggerMatch(
          mu.at(0), (*trig_vec.trig_EF_trigmuonef_EF_mu18_tight()),
          trig_vec, 0.15, 0);
    }
    else {
      // std::cout << "\tleading match(1):\n";
      pass_leading_match = passedMuonTriggerMatch(
          mu.at(1), (*trig_vec.trig_EF_trigmuonef_EF_mu18_tight()),
          trig_vec, 0.15, 0);
    }

    // require both muons match with EF_mu18_tight_mu8_EFFS
    // std::cout << "\tdouble match 1:\n";
    bool pass_double_match_1 = passedMuonTriggerMatch(
        mu, (*trig_vec.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS()), trig_vec,
        2, 0.15, 0);

    // require both muons match with EF_mu18_tight_mu8_EFFS
    // std::cout << "\tdouble match 2:\n";
    bool pass_double_match_2 = passedMuonTriggerMatch(
        mu, (*trig_vec.trig_EF_trigmuonef_EF_mu13()), trig_vec,
        2, 0.15, 0);

    // std::cout << "\tleading_match: " << pass_leading_match << "\t-\tdouble_match_1: " << pass_double_match_1  << "\t-\tdouble_match_2: " << pass_double_match_2 << "\n";
    // check (leading_match && double_match_1) || double_match_2
    // to get the decision
    pass_trigger_match = (  (pass_leading_match && pass_double_match_1)
                         || pass_double_match_2
                         );
  }
  else if (  pt_lead    > 18000
          && pt_sublead > 8000
          && pt_sublead < 14000
          )
  {
    // region C (pt_lead > 18 GeV && 8 < pt_sublead < 14 GeV)
    // std::cout << "region C\n";

    // require leading muon matches with EF_mu18_tight
    bool pass_single_match = false;
    if (pt0 >= pt1) {
      pass_single_match = passedMuonTriggerMatch(
          mu.at(0), (*trig_vec.trig_EF_trigmuonef_EF_mu18_tight()),
          trig_vec, 0.15, 0);
    }
    else {
      pass_single_match = passedMuonTriggerMatch(
          mu.at(1), (*trig_vec.trig_EF_trigmuonef_EF_mu18_tight()),
          trig_vec, 0.15, 0);
    }

    // require both muons match with EF_mu18_tight_mu8_EFFS
    bool pass_double_match = passedMuonTriggerMatch(
        mu, (*trig_vec.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS()), trig_vec,
        2, 0.15, 0);

    // std::cout << "\tsingle_match: " << pass_single_match << "\t-\tdouble_match: " << pass_double_match << "\n";
    // check the && of the single and double match above
    pass_trigger_match = (pass_single_match && pass_double_match);
  }
  else if (  pt_lead    > 14000
          && pt_lead    < 18000
          && pt_sublead > 14000
          && pt_sublead < 18000
          )
  {
    // region D (14 < pt_lead < 18 GeV && 14 < pt_sublead < 18 GeV)

    // require both muons match with EF_mu13
    pass_trigger_match = passedMuonTriggerMatch(
        mu, (*trig_vec.trig_EF_trigmuonef_EF_mu13()), trig_vec,
        2, 0.15, 0);
  }

  // std::cout << "MuMu Trigger match: " << pass_trigger_match << "\n";

  return pass_trigger_match;
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedEMuTriggerMatching2012(
    Event& / *event* /,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Electron>& el,
    std::vector<Muon>& mu)
{
  // immediately fail events with more/less than two OF leptons
  if (el.size() < 1 || mu.size() < 1) return false;

  double pt_el = el.at(0).getTlv().Pt();
  double pt_mu = mu.at(0).getTlv().Pt();

  bool pass_trigger_match = false;

  if (  pt_el > 14000
     && pt_mu >  8000
     ) {
    // region A (pt_e > 14 GeV && pt_mu > 8 GeV)

    if (is_data()) {
      // check electron matches with EF_e12Tvh_medium1
      bool pass_electron_match = passedElectronTriggerMatch(
          el.at(0), (*trig_vec.trig_EF_el_EF_e12Tvh_medium1()), trig_vec, 0.15, 0);

      // check muon matches with EF_mu8
      bool pass_muon_match = passedMuonTriggerMatch(
          mu.at(0), (*trig_vec.trig_EF_trigmuonef_EF_mu8()), trig_vec, 0.15, 0);

      // require the && of the electron and muon match above
      pass_trigger_match = (pass_electron_match && pass_muon_match);
    }
    else {
      // for MC, we just want to check the phase space
      pass_trigger_match = true;
    }
  }

  return pass_trigger_match;
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuETriggerMatching2012(
    Event& / *event* /,
    TriggerVecD3PDObject& trig_vec,
    std::vector<Electron>& el,
    std::vector<Muon>& mu)
{
  // immediately fail events with more/less than two OF leptons
  if (el.size() < 1 || mu.size() < 1) return false;

  double pt_el = el.at(0).getTlv().Pt();
  double pt_mu = mu.at(0).getTlv().Pt();

  bool pass_trigger_match = false;

  if (  pt_el > 10000
     && pt_el < 14000
     && pt_mu > 18000
     ) {
    // region B (10 < pt_e < 14 GeV && pt_mu > 18 GeV)

    if (is_data()) {
      // check electron matches with EF_e7T_medium1
      bool pass_electron_match = passedElectronTriggerMatch(
          el.at(0), (*trig_vec.trig_EF_el_EF_e7T_medium1()), trig_vec, 0.15, 0);

      // check muon matches with EF_mu18_tight
      bool pass_muon_match = passedMuonTriggerMatch(
          mu.at(0), (*trig_vec.trig_EF_trigmuonef_EF_mu18_tight()), trig_vec, 0.15, 0);

      // require the && of the electron and muon match above
      pass_trigger_match = (pass_electron_match && pass_muon_match);
    }
    else {
      // for MC, we just want to check the phase space
      pass_trigger_match = true;
    }
  }

  return pass_trigger_match;
}


// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedElectronTriggerMatch(
    std::vector<Electron>& el,
    std::vector<int>& trigger_chain,
    TriggerVecD3PDObject& trig_vec,
    size_t num_to_match,
    double dr_cut,
    double pt_cut)
{
  // if we have fewer offline objects than num_to_match, we automatically fail
  if (el.size() < num_to_match)
    return false;

  // get vector of TLV objects
  std::vector<TLorentzVector> off_tlv;
  size_t offline_term = el.size();
  for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
    off_tlv.push_back(el.at(offline_it).getTlv());
  }

  // sets to keep track of matches - want to avoid double counting matches
  std::set<int> offline_match;
  std::set<int> online_match;

  // loop over all online trigger objects
  size_t trig_term = trigger_chain.size();
  for (size_t trig_it = 0; trig_it != trig_term; ++trig_it) {
    // First check the trigger decision for this trigger object
    // do not match triggers that don't fire
    if (trigger_chain.at(trig_it) == 0) continue;

    TLorentzVector on_tlv;
    on_tlv.SetPxPyPzE( trig_vec[trig_it].trig_EF_el_px()
                     , trig_vec[trig_it].trig_EF_el_py()
                     , trig_vec[trig_it].trig_EF_el_pz()
                     , trig_vec[trig_it].trig_EF_el_E()
                     );

    // loop over offline objects to look for matches
    for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
      if (  off_tlv[offline_it].DeltaR(on_tlv) < dr_cut
         && off_tlv[offline_it].Pt() > pt_cut
         )
      {
        offline_match.insert(offline_it);
        online_match.insert(trig_it);

        if (  offline_match.size() >= num_to_match
           && online_match.size() >= num_to_match
           )
          return true;
      }
    }
  }

  return false;
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedElectronTriggerMatch(
    Electron& el,
    std::vector<int>& trigger_chain,
    TriggerVecD3PDObject& trig_vec,
    double dr_cut,
    double pt_cut)
{
  std::vector<Electron> el_vec(1, el);
  return passedElectronTriggerMatch( el_vec
                                   , trigger_chain
                                   , trig_vec
                                   , 1
                                   , dr_cut
                                   , pt_cut
                                   );
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuonTriggerMatch(
    std::vector<Muon>& mu,
    std::vector<int>& trigger_chain,
    TriggerVecD3PDObject& trig_vec,
    size_t num_to_match,
    double dr_cut,
    double pt_cut)
{
  // if we have fewer offline objects than num_to_match, we automatically fail
  if (mu.size() < num_to_match)
    return false;

  // get vector of TLV objects
  std::vector<TLorentzVector> off_tlv;
  size_t offline_term = mu.size();
  for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
    off_tlv.push_back(mu.at(offline_it).getTlv());
  }

  // sets to keep track of matches - want to avoid double counting matches
  std::set<int> offline_match;
  // std::set<int> online_match;
  unsigned int num_online_matched = 0;

  // loop over all online trigger objects
  size_t trig_term = trigger_chain.size();
  for (size_t trig_it = 0; trig_it != trig_term; ++trig_it) {
    // First check the trigger decision for this trigger object
    // do not match triggers that don't fire
    // std::cout << "\t\ttrigger chain.at(" << trig_it << "): " << trigger_chain.at(trig_it) << "\n";
    if (trigger_chain.at(trig_it) == 0) continue;

    std::set<int> online_match;

    size_t online_term =
        trig_vec[trig_it].trig_EF_trigmuonef_track_CB_pt().size();
    for (size_t online_it = 0; online_it != online_term; ++online_it) {
      TLorentzVector on_tlv;
      on_tlv.SetPtEtaPhiM(
          std::max( 1.
                  , static_cast<double>(
                        trig_vec[trig_it].trig_EF_trigmuonef_track_CB_pt().at(online_it))
                  ),
          trig_vec[trig_it].trig_EF_trigmuonef_track_CB_eta().at(online_it),
          trig_vec[trig_it].trig_EF_trigmuonef_track_CB_phi().at(online_it),
          0);

      // loop over offline objects to look for matches
      for (size_t offline_it = 0; offline_it != offline_term; ++offline_it) {
        if (  off_tlv[offline_it].DeltaR(on_tlv) < dr_cut
           && off_tlv[offline_it].Pt() > pt_cut
           )
        {
          // std::cout << "found offline muon matching trigger object - off: " << offline_it << " - on: " << online_it << "\n";
          offline_match.insert(offline_it);
          // online_match.insert(trig_it);
          online_match.insert(online_it);

        }
      }
    }

    num_online_matched += online_match.size();

    if (  offline_match.size() >= num_to_match
       // && online_match.size()  >= num_to_match
       && num_online_matched   >= num_to_match
       ) {
      // std::cout << "fully matched for this trigger"
      //           << "\n\toffline matches: " << offline_match.size()
      //           << "\n\tonline matches: "  << online_match.size()
      //           << "\n";
      return true;
    }
  }

  return false;
}

// ----------------------------------------------------------------------------
bool SelectionTools::TriggerCutTool::passedMuonTriggerMatch(
    Muon& mu,
    std::vector<int>& trigger_chain,
    TriggerVecD3PDObject& trig_vec,
    double dr_cut,
    double pt_cut)
{
  std::vector<Muon> mu_vec(1, mu);
  return passedMuonTriggerMatch( mu_vec
                               , trigger_chain
                               , trig_vec
                               , 1
                               , dr_cut
                               , pt_cut
                               );
}
*/
