#include "PennSusyFrameCore/include/EventSelectors.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"

#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsList.h"
#include "RootCore/GoodRunsLists/GoodRunsLists/TGoodRunsListReader.h"

#include <vector>

// =============================================================================
PennSusyFrame::GrlTool::GrlTool() : m_do_grl(true)
                                  , m_grl_file_name("")
{}

void PennSusyFrame::GrlTool::init(const std::string& grl_file_name, bool do_grl)
{
  m_do_grl = do_grl;
  if (!m_do_grl) return;

  m_grl_file_name = grl_file_name;
  Root::TGoodRunsListReader grl_reader(m_grl_file_name.c_str());

  if (!grl_reader.Interpret()) {
    std::cout << "ERROR!!! Good Runs List could not be interpreted: "
              << m_grl_file_name << "\n";
    // TODO throw exception
  }

  m_grl = grl_reader.GetMergedGoodRunsList();
  m_grl.SetName("GoodRunsList");
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::GrlTool::passEvent(const PennSusyFrame::Event& event)
{
  return passEvent(event.getRunNumber(), event.getLumiBlock());
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::GrlTool::passEvent(unsigned int run, unsigned int lb)
{
  if (!m_do_grl) return true;

  if(m_grl.HasRunLumiBlock(run, lb)) return true;
  return false;
}
