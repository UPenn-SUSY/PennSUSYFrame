#include <math.h>
#include "include/GoodRunsListTool.h"

// ----------------------------------------------------------------------------
SelectionTools::GoodRunsListTool::GoodRunsListTool( SCycleBase* parent
                                                  , const char* name
                                                  )
                                                  : ToolBase(parent, name)
{
  DeclareProperty("do_grl" , c_do_grl = false);
  DeclareProperty("grl_xml", c_grl_xml = "");
}

// ----------------------------------------------------------------------------
SelectionTools::GoodRunsListTool::~GoodRunsListTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void SelectionTools::GoodRunsListTool::BeginCycle()
{
  m_logger << DEBUG
           << "GoodRunsListTool::BeginCycle"
           << SLogger::endmsg;

  if (!c_do_grl) return;
  Root::TGoodRunsListReader grl(c_grl_xml);
  if (!grl.Interpret()) {
    m_logger << FATAL
             << "Good Runs List could not be interpreted: " << c_grl_xml
             << SLogger::endmsg;
    throw SError(SError::StopExecution);
  }

  m_grl = grl.GetMergedGoodRunsList();
  m_grl.SetName("GoodRunsList");
  AddConfigObject(&m_grl);
}

// ----------------------------------------------------------------------------
void SelectionTools::GoodRunsListTool::BeginInputData(const SInputData&)
{
  m_logger << DEBUG
           << "GoodRunsListTool::BeginInputData"
           << SLogger::endmsg;

  if (is_data() && !c_grl_xml.empty() && c_do_grl) {
    m_grl =
      *(static_cast<Root::TGoodRunsList*>(GetConfigObject("GoodRunsList")));
  }
}

// ----------------------------------------------------------------------------
bool SelectionTools::GoodRunsListTool::passed( const unsigned int run
                                             , const unsigned int lb
                                             )
{
  if (!c_do_grl || !is_data()) return true;

  bool has_lumi_block = m_grl.HasRunLumiBlock(run, lb);
  if (has_lumi_block) {
    m_logger << DEBUG
             << "Pass GRL " << has_lumi_block
             << " Run: " << run
             << " LB: " << lb
             << SLogger::endmsg;
    return true;
  }

  m_logger << DEBUG
           << "Fail GRL " << has_lumi_block
           << " Run: " << run
           << " LB: " << lb
           << SLogger::endmsg;
 return false;
}

// ----------------------------------------------------------------------------
bool SelectionTools::GoodRunsListTool::passed(const Event& event)
{
  return passed(event.RunNumber(), event.lbn());
}
