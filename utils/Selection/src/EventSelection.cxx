#include "include/EventSelection.h"
#include <iostream>

// -----------------------------------------------------------------------------
Selection::EventSelection::EventSelection() : m_pass_event_word(0)
                                            , m_reverse_event_word(0)
                                            , m_pass_sr_word(0)
                                            , m_reverse_sr_word(0)
{
  // do nothing
}

// -----------------------------------------------------------------------------
Selection::EventSelection::EventSelection(
    SusyAnalysisTools::EventDescription pass_event_word,
    SusyAnalysisTools::EventDescription reverse_event_word) :
        m_pass_event_word(pass_event_word),
        m_reverse_event_word(reverse_event_word),
        m_pass_sr_word(0),
        m_reverse_sr_word(0)
{
  // do nothing
}

// -----------------------------------------------------------------------------
Selection::EventSelection::EventSelection(
    SusyAnalysisTools::EventDescription pass_event_word,
    SusyAnalysisTools::EventDescription reverse_event_word,
    SusyAnalysisTools::SRHelper         pass_sr_word,
    SusyAnalysisTools::SRHelper         reverse_sr_word) :
        m_pass_event_word(pass_event_word),
        m_reverse_event_word(reverse_event_word),
        m_pass_sr_word(pass_sr_word),
        m_reverse_sr_word(reverse_sr_word)
{
  // do nothing
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription*
    Selection::EventSelection::getPassEventWord()
{
  return &m_pass_event_word;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::EventDescription*
    Selection::EventSelection::getReverseEventWord()
{
  return &m_reverse_event_word;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::SRHelper*
    Selection::EventSelection::getPassSRWord()
{
  return &m_pass_sr_word;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::SRHelper*
    Selection::EventSelection::getReverseSRWord()
{
  return &m_reverse_sr_word;
}

// ----------------------------------------------------------------------------
bool Selection::EventSelection::passEvent(
    const SusyAnalysisTools::EventDescription& event_desc,
    const SusyAnalysisTools::SRHelper& sr_helper) const
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  return (  event_desc.pass(   m_pass_event_word      )
         && event_desc.reverse(m_reverse_event_word   )
         && sr_helper.pass(    m_pass_sr_word   )
         && sr_helper.reverse( m_reverse_sr_word)
      );
}

// // -----------------------------------------------------------------------------
// bool Selection::EventSelection::passMllCut(Event& event) const
// {
//   double mll = event.mll();
//   if ( m_mll_cut_min > -999 && mll < m_mll_cut_min ) return false;
//   if ( m_mll_cut_max > -999 && mll > m_mll_cut_max ) return false;
//   return true;
// }
//
// // -----------------------------------------------------------------------------
// bool Selection::EventSelection::passMetCut(MET& met) const
// {
//   double met_et = met.getMetVar(m_met_collection, m_met_var);
//   if ( m_met_cut_min > -999 && met_et < m_met_cut_min ) return false;
//   if ( m_met_cut_max > -999 && met_et > m_met_cut_max ) return false;
//   return true;
// }
//
// // -----------------------------------------------------------------------------
// bool Selection::EventSelection::passMt2Cut(Event& event) const
// {
//   double mt2 = event.mt2();
//   if ( m_mt2_cut_min > -999 && mt2 < m_mt2_cut_min ) return false;
//   if ( m_mt2_cut_max > -999 && mt2 > m_mt2_cut_max ) return false;
//   return true;
// }
//
// // -----------------------------------------------------------------------------
// bool Selection::EventSelection::passJetPtCut(std::vector<Jet>& jets) const
// {
//   // if no cut defined, short circuit to save time looping
//   if (m_jet_pt_cut_min == -999 && m_jet_pt_cut_max == -999) return true;
//
//   size_t num_jets = jets.size();
//   for (size_t jet_it = 0; jet_it != num_jets; ++jet_it) {
//     if (m_jet_pt_cut_min > -999 && jets.at(jet_it).pt() < m_jet_pt_cut_min)
//       return false;
//     if (m_jet_pt_cut_max > -999 && jets.at(jet_it).pt() > m_jet_pt_cut_max)
//       return false;
//   }
//   return true;
// }
//
// // -----------------------------------------------------------------------------
// void Selection::EventSelection::setMllCutValue(double min, double max)
// {
//   m_mll_cut_min = min;
//   m_mll_cut_max = max;
// }
//
// // -----------------------------------------------------------------------------
// void Selection::EventSelection::setMetCutValue(double min, double max,
//     MET::MET_VAR met_var, MET::MET_COLLECTION met_collection)
// {
//   m_met_cut_min = min;
//   m_met_cut_max = max;
//   m_met_var = met_var;
//   m_met_collection = met_collection;
// }
//
// // -----------------------------------------------------------------------------
// void Selection::EventSelection::setMt2CutValue(double min, double max)
// {
//   m_mt2_cut_min = min;
//   m_mt2_cut_max = max;
// }
//
// // -----------------------------------------------------------------------------
// void Selection::EventSelection::setJetPtCutValue(double min, double max)
// {
//   m_jet_pt_cut_min = min;
//   m_jet_pt_cut_max = max;
// }
