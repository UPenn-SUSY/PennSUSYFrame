#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "include/CrossSectionScaleFactorTool.h"

// ----------------------------------------------------------------------------
CommonTools::CrossSectionScaleFactorTool::CrossSectionScaleFactorTool( SCycleBase* parent
                                                                     , const char* name
                                                                     )
                                                                     : ToolBase(parent, name)
                                                                     , c_cross_section_file("")
                                                                     , m_cross_section_db(0)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  init();
}

// ----------------------------------------------------------------------------
CommonTools::CrossSectionScaleFactorTool::~CrossSectionScaleFactorTool()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // TODO Leaving m_cross_section_db un-deleted in order to get the code to run in proof. figure out a way to delete this without segfault in proof-lite
  // if (  !is_data()
  //    && c_cross_section_file
  //    && m_cross_section_db
  //    )
  //   delete m_pile_up_reweight;
}
// ----------------------------------------------------------------------------
void CommonTools::CrossSectionScaleFactorTool::init()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  DeclareProperty("do_cross_section"  , c_do_cross_section_sf = false);
  DeclareProperty( "cross_section_file"
                 , c_cross_section_file
                     = "${ROOTCOREDIR}/../SUSYTools/data/susy_crosssections.txt"
                 );
  DeclareProperty("data_lumi"         , c_data_lumi           = 1);
  DeclareProperty("mc_num_events"     , c_mc_num_events       = 1);

  m_logger << VERBOSE
           << "do_cross_section_sf: " << c_do_cross_section_sf
           << "\ncross_section_file: " << c_cross_section_file
           << SLogger::endmsg;
}
// ----------------------------------------------------------------------------
void CommonTools::CrossSectionScaleFactorTool::clear()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    m_sf = -999;
    m_cross_section_times_eff = -999;
    m_cross_section = -999;
    m_k_factor = -999;
    m_efficiency = -999;
    m_rel_uncertainty = -999;
    m_name = "";
    
    m_cached_sf= false;
    m_cached_cs_x_eff= false;
    m_cached_cs= false;
    m_cached_k_factor= false;
    m_cached_efficiency= false;
    m_cached_rel_uncertainty= false;
    m_cached_name= false;
}


// ----------------------------------------------------------------------------
void CommonTools::CrossSectionScaleFactorTool::BeginInputData(const SInputData&)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // if data, do nothing
  if (is_data()) return;

  // if (c_do_cross_section_sf) {
    m_cross_section_db = new SUSY::CrossSectionDB(c_cross_section_file);
  // }
}

// ----------------------------------------------------------------------------
void CommonTools::CrossSectionScaleFactorTool::EndInputData(const SInputData&)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}
float CommonTools::CrossSectionScaleFactorTool::getSF(const D3PDReader::TruthD3PDObject& truth)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (is_data() || !c_do_cross_section_sf) return 1;

  if (!m_cached_sf) 
    {

      if (!m_cached_k_factor) m_k_factor = getKFactor(truth);
      if (!m_cached_cs_x_eff) m_cross_section_times_eff = getCrossSectionTimesEff(truth);
      
      m_sf = m_k_factor*m_cross_section_times_eff*c_data_lumi/c_mc_num_events;
      m_cached_sf = true;
    }

  return m_sf;
}
// ----------------------------------------------------------------------------
float CommonTools::CrossSectionScaleFactorTool::getCrossSectionTimesEff(const D3PDReader::TruthD3PDObject& truth)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // if (is_data() || !c_do_cross_section_sf) return 1;
  if (is_data()) return 1;

  if(!m_cached_cs_x_eff) 
    {
      m_cross_section_times_eff =  m_cross_section_db->xsectTimesEff(truth.mc_channel_number());
      m_cached_cs_x_eff = true;
    }
  return m_cross_section_times_eff;
}

// ----------------------------------------------------------------------------
float CommonTools::CrossSectionScaleFactorTool::getCrossSection(const D3PDReader::TruthD3PDObject& truth)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // if (is_data() || !c_do_cross_section_sf) return 1;
  if (is_data()) return 1;

  if(!m_cached_cs) 
    {
      m_cross_section = m_cross_section_db->rawxsect(truth.mc_channel_number());
      m_cached_cs = true;
    }

  return m_cross_section;
}

// ----------------------------------------------------------------------------
float CommonTools::CrossSectionScaleFactorTool::getKFactor(const D3PDReader::TruthD3PDObject& truth)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // if (is_data() || !c_do_cross_section_sf) return 1;
  if (is_data()) return 1;

  if (!m_cached_k_factor)
    {
      m_k_factor = m_cross_section_db->kfactor(truth.mc_channel_number());
      m_cached_k_factor = true;
    }
  
  return m_k_factor;
}
// ----------------------------------------------------------------------------
float CommonTools::CrossSectionScaleFactorTool::getEfficiency(const D3PDReader::TruthD3PDObject& truth)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // if (is_data() || !c_do_cross_section_sf) return 1;
  if (is_data()) return 1;

  if(!m_cached_efficiency)
    {    
      m_efficiency = m_cross_section_db->efficiency(truth.mc_channel_number());
      m_cached_efficiency = true;
    }
  return m_efficiency;
}

// ----------------------------------------------------------------------------

float CommonTools::CrossSectionScaleFactorTool::getRelUncertainty(const D3PDReader::TruthD3PDObject& truth)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // if (is_data() || !c_do_cross_section_sf) return 1;
  if (is_data()) return 1;

  if (!m_cached_rel_uncertainty)
    {
      m_rel_uncertainty = m_cross_section_db->rel_uncertainty(truth.mc_channel_number());
      m_cached_rel_uncertainty = true;
    }
  return m_rel_uncertainty; 
}

// ----------------------------------------------------------------------------
std::string CommonTools::CrossSectionScaleFactorTool::getName(const D3PDReader::TruthD3PDObject& truth)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // if (is_data() || !c_do_cross_section_sf) return "";
  if (is_data()) return "";

  if (!m_cached_name)
    {
      m_name =  m_cross_section_db->name(truth.mc_channel_number());
      m_cached_name = true;
    }
  return m_name;
}
