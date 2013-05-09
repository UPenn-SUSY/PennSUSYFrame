#include "ChannelFractions/include/ChannelFractions.h"

#include <iostream>
#include <iomanip>
#include <vector>

#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2.h>
#include <TROOT.h>
#include <TStyle.h>

#include "NtupleLooper/include/NtupleLooper.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// -----------------------------------------------------------------------------
ChannelFractions::ChannelFractions( TTree *tree
                        , double num_events) : NtupleLooper(tree, num_events)
                                             , m_num_total(0.)
                                             , m_num_eee(0.)
                                             , m_num_eem(0.)
                                             , m_num_emm(0.)
                                             , m_num_mmm(0.)
                                             , m_num_ee_os(0.)
                                             , m_num_em_os(0.)
                                             , m_num_mm_os(0.)
                                             , m_num_ee_ss(0.)
                                             , m_num_em_ss(0.)
                                             , m_num_mm_ss(0.)
{
  // do nothing
}

// -----------------------------------------------------------------------------
ChannelFractions::~ChannelFractions()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void ChannelFractions::processEvent()
{
  // No matter what, we want to increment the total number of events
  ++m_num_total;
}

// -----------------------------------------------------------------------------
void ChannelFractions::printToScreen()
{
  unsigned int line_width   = 100;
  unsigned int label_field  = 30;
  unsigned int weight_field = (line_width - label_field - 4 - 4*3 )/4;
  unsigned int precision    = weight_field-2;
  if (4+label_field+4*weight_field != line_width) {
    label_field += (line_width - label_field - 4 - 4*3 )%4;
  }
  std::string break_label = "";
  std::string break_weight = "";
  for (unsigned int i = 0; i != label_field ; ++i) break_label  += "-";
  for (unsigned int i = 0; i != weight_field; ++i) break_weight += "-";

  std::string single_line;
  for (unsigned int i = 0; i != line_width; ++i) single_line += '=';
  single_line = single_line + "\n";

  std::cout << single_line;
  std::cout << "= "
            << std::left << std::setw(line_width - 3)
            << "Channel"
            << "=\n";
  std::cout << single_line;
  std::cout << "= "  << std::left  << std::setw(label_field)  << "Generated"
            << " = " << std::right << std::setw(weight_field) << "Pass met-rel"
            << " = " << std::right << std::setw(weight_field) << "Pass mT"
            << " =\n";
  std::cout << single_line;

}

// -----------------------------------------------------------------------------
void ChannelFractions::printToFile(std::string out_file_name)
{
  // do nothing
}
