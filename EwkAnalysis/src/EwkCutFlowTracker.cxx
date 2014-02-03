#include "EwkAnalysis/include/EwkCutFlowTracker.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
#include <iostream>
#include <iomanip>
#include <vector>
#include "TH1D.h"

// =============================================================================
// -----------------------------------------------------------------------------
EwkCutFlowTracker::EwkCutFlowTracker()
{
  initCutFlowHists();
}

// -----------------------------------------------------------------------------
EwkCutFlowTracker::~EwkCutFlowTracker()
{}

// -----------------------------------------------------------------------------
void EwkCutFlowTracker::fillHist(int channel, int bin, float weight)
{
  m_cutflow.at(channel)->Fill(bin, weight);
}

// -----------------------------------------------------------------------------
void EwkCutFlowTracker::printToScreen()
{
  // set line widths etc.
  m_line_width   = 100;
  m_label_field  = 30;
  m_weight_field = (m_line_width - m_label_field - 5 - 5*3)/5;
  m_precision    = m_weight_field - 2;
  if (5+m_label_field+5*m_weight_field != m_line_width) {
    m_label_field += (m_line_width - m_label_field - 5 - 5*3 )%5;
  }
  m_break_label = "";
  m_break_weight = "";
  for (unsigned int i = 0; i != m_label_field ; ++i) m_break_label  += "-";
  for (unsigned int i = 0; i != m_weight_field; ++i) m_break_weight += "-";

  m_single_line = "";
  for (unsigned int i = 0; i != m_line_width; ++i) m_single_line += '=';
  m_single_line = m_single_line + "\n";

  // print header
  // std::cout << m_single_line;
  // std::cout << "= "
  //           << std::left << std::setw(m_line_width - 3)
  //           << getWeightName(m_weight_type)
  //           << "=\n";
  std::cout << "\n" << m_single_line;
  std::cout << "= "  << std::left  << std::setw(m_label_field)  << "Cut"
            << " = " << std::right << std::setw(m_weight_field) << "ALL"
            << " = " << std::right << std::setw(m_weight_field) << "EE"
            << " = " << std::right << std::setw(m_weight_field) << "MM"
            << " = " << std::right << std::setw(m_weight_field) << "EM"
            << " = " << std::right << std::setw(m_weight_field) << "ME"
            << " =\n";
  std::cout << m_single_line << "\n";

  for (unsigned int cut_it = 0; cut_it != EWK_CUT_N; ++cut_it) {
    printLine(cut_it);
  }
  std::cout << m_single_line;
}

// -----------------------------------------------------------------------------
void EwkCutFlowTracker::printLine(int cut_it)
{
  std::string cut_name = EWK_CUT_STRINGS[cut_it];
  // std::cout << "cut it: " << cut_it << " - cut name: " << cut_name << "\n";

  double weight_none = m_cutflow.at(PHASE_NONE)->GetBinContent(cut_it+1);
  double weight_ee   = m_cutflow.at(PHASE_EE  )->GetBinContent(cut_it+1);
  double weight_mm   = m_cutflow.at(PHASE_MM  )->GetBinContent(cut_it+1);
  double weight_em   = m_cutflow.at(PHASE_EM  )->GetBinContent(cut_it+1);
  double weight_me   = m_cutflow.at(PHASE_ME  )->GetBinContent(cut_it+1);

  if (cut_name == "BREAK") {
    std::cout << "= "  << std::left  << std::setw(m_label_field)  << m_break_label
              << " = " << std::right << std::setw(m_weight_field) << m_break_weight
              << " = " << std::right << std::setw(m_weight_field) << m_break_weight
              << " = " << std::right << std::setw(m_weight_field) << m_break_weight
              << " = " << std::right << std::setw(m_weight_field) << m_break_weight
              << " = " << std::right << std::setw(m_weight_field) << m_break_weight
              // << " = " << std::right << std::setw(m_weight_field)
              // << std::setprecision(precision) << weight_ee
              // << " = " << std::right << std::setw(m_weight_field)
              // << std::setprecision(precision) << weight_mm
              // << " = " << std::right << std::setw(m_weight_field)
              // << std::setprecision(precision) << weight_em
              // << " = " << std::right << std::setw(m_weight_field)
              // << std::setprecision(precision) << weight_me
              << " =\n";
  }
  else {
    std::cout << "= "  << std::left  << std::setw(m_label_field)
              << std::setprecision(m_precision) << cut_name
              << " = " << std::right << std::setw(m_weight_field)
              << std::setprecision(m_precision) << weight_none
              << " = " << std::right << std::setw(m_weight_field)
              << std::setprecision(m_precision) << weight_ee
              << " = " << std::right << std::setw(m_weight_field)
              << std::setprecision(m_precision) << weight_mm
              << " = " << std::right << std::setw(m_weight_field)
              << std::setprecision(m_precision) << weight_em
              << " = " << std::right << std::setw(m_weight_field)
              << std::setprecision(m_precision) << weight_me
              << " =\n";
  }

}

// -----------------------------------------------------------------------------
void EwkCutFlowTracker::initBinList()
{
  m_bin_list.clear();

  for (int cut_it = 0; cut_it != EWK_CUT_N; ++cut_it) {
    m_bin_list.push_back(EWK_CUT_STRINGS[cut_it]);
  }
}

// -----------------------------------------------------------------------------
void EwkCutFlowTracker::initCutFlowHists()
{
  initBinList();

  m_cutflow.resize(PHASE_N);

  std::string name = "cutflow";

  size_t num_bins = m_bin_list.size();
  std::cout << "setting cutflow histogram to: "
            << num_bins << ", " << -0.5 << " , " << num_bins - 0.5 << "\n";

  std::string name_base = "cutflow_";
  for (size_t channel_it = 0; channel_it != PHASE_N; ++channel_it) {
    std::string this_name = name_base;
    if (     channel_it == static_cast<size_t>(PHASE_NONE)) this_name += "none";
    else if (channel_it == static_cast<size_t>(PHASE_EE  )) this_name += "ee";
    else if (channel_it == static_cast<size_t>(PHASE_MM  )) this_name += "mm";
    else if (channel_it == static_cast<size_t>(PHASE_EM  )) this_name += "em";
    else if (channel_it == static_cast<size_t>(PHASE_ME  )) this_name += "me";
    else continue;

    std::cout << "channel it: " << channel_it << " this_name: " << this_name << "\n";

    m_cutflow.at(channel_it) = new TH1D( this_name.c_str()
                                       , this_name.c_str()
                                       , EWK_CUT_N
                                       , -0.5
                                       , EWK_CUT_N - 0.5
                                       );
    initCutFlowAxis(m_cutflow.at(channel_it));
  }
}
