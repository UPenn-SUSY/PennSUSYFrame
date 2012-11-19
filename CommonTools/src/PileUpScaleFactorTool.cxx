#include "include/PileUpScaleFactorTool.h"
#include "AtlasSFrameUtils/include/CycleMacros.h"


// -----------------------------------------------------------------------------
CommonTools::PileUpScaleFactorTool::PileUpScaleFactorTool(
    SCycleBase* parent,
    const char* name
    ) : ToolBase(parent, name)
{
  DeclareProperty("do_pile_up"      , c_do_pile_up_sf    = false);
  DeclareProperty("generate_mc_hist", c_generate_mc_hist = false);
  DeclareProperty("pile_up_var"     , c_pile_up_var      = "lbn");


  DeclareProperty("data_file", c_pile_up_data_file = "");
  DeclareProperty("mc_file"  , c_pile_up_mc_file   = "");

  DeclareProperty("data_hist_name", c_data_hist_name = "LumiMetaData"       );
  DeclareProperty("mc_hist_name"  , c_mc_hist_name   = "MCPileupReweighting");
}

// -----------------------------------------------------------------------------
CommonTools::PileUpScaleFactorTool::~PileUpScaleFactorTool()
{
  // do nothing
}
void CommonTools::PileUpScaleFactorTool::clear()
{
  m_is_cached = false;
  m_pileup_sf =  -999;
}
// -----------------------------------------------------------------------------
void CommonTools::PileUpScaleFactorTool::BeginInputData(const SInputData&)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // if data, do nothing
  if (!is_data()) {

    m_pile_up_reweight = new Root::TPileupReweighting("TPileupReweighting");

    int is_good = 1;

    // HACK -- Always set up a pile up tool since other tools will be using it
    // if (c_do_pile_up_sf) {
    if (true) {
      std::cout << "initializing PileUpScaleFactorTool\n";
      std::cout << "\tMC file: "   << c_pile_up_mc_file << "\n"
                << "\tData file: " << c_pile_up_data_file << "\n";

      // settings from SUSY 2-lep discussion page
      m_pile_up_reweight->SetDefaultChannel(0);

      m_pile_up_reweight->AddConfigFile(c_pile_up_mc_file);

      m_pile_up_reweight->SetDataScaleFactors(1/1.11);
      m_pile_up_reweight->AddLumiCalcFile(c_pile_up_data_file);

      // m_pile_up_reweight->SetUnrepresentedDataAction(2);

      is_good = m_pile_up_reweight->Initialize();
    }

    if (is_good != 0) {
      m_logger << FATAL
        << "Problem in Pileup initialization::isGood="
        << is_good
        << SLogger::endmsg;
    }
    else {
      AddConfigObject(m_pile_up_reweight);
    }
  }


}
// -----------------------------------------------------------------------------
void CommonTools::PileUpScaleFactorTool::EndInputData(const SInputData&)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}



// -----------------------------------------------------------------------------
double CommonTools::PileUpScaleFactorTool::getPileupScaleFactor(
    const Event* event, const D3PDReader::TruthD3PDObject* truth)
{
  if(!m_is_cached)
  {
    // float sf = 1.;
    m_pileup_sf = 1.;

    if (!is_data() && (c_do_pile_up_sf || c_generate_mc_hist)) {
      float mu = 0.;
      if (c_pile_up_var == "lbn")
        mu = event->lbn();
      else if (c_pile_up_var == "averageIntPerXing")
        mu = event->averageIntPerXing();
      else if (c_pile_up_var == "actualIntPerXing")
        mu = event->actualIntPerXing();

      m_pileup_sf = m_pile_up_reweight->GetCombinedWeight(
          event->RunNumber(),
          truth->mc_channel_number(),
          mu);
      m_logger << DEBUG
               << "mu: " << mu
               << "\trun number: " << event->RunNumber()
               << "\tchannel number: " << truth->mc_channel_number()
               << "\tpile up sf: " << m_pileup_sf
               << SLogger::endmsg;
      if (m_pileup_sf < 0.) m_pileup_sf = 0.;
    }

    m_is_cached = true;
  }

  return m_pileup_sf;
}

// ----------------------------------------------------------------------------
double CommonTools::PileUpScaleFactorTool::getIntegratedLumiFraction(
    unsigned int run_number,
    unsigned int start,
    unsigned int end)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  return m_pile_up_reweight->GetIntegratedLumiFraction( run_number
              , start
              , end
              );
}

// -----------------------------------------------------------------------------
std::vector<double>
    CommonTools::PileUpScaleFactorTool::getIntegratedLumiVector()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  return m_pile_up_reweight->getIntegratedLumiVector();
}
