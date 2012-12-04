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
void Selection::EventSelection::setPassEventWord(
    const SusyAnalysisTools::EventDescription& pass)
{
  m_pass_event_word = pass;
}

// -----------------------------------------------------------------------------
void Selection::EventSelection::setReverseEventWord(
    const SusyAnalysisTools::EventDescription& reverse)
{
  m_reverse_event_word = reverse;
}

// -----------------------------------------------------------------------------
void Selection::EventSelection::setPassSRWord(
    const SusyAnalysisTools::SRHelper& pass)
{
  m_pass_sr_word = pass;
}

// -----------------------------------------------------------------------------
void Selection::EventSelection::setReverseSRWord(
    const SusyAnalysisTools::SRHelper& reverse)
{
  m_reverse_sr_word = reverse;
}

// -----------------------------------------------------------------------------
void Selection::EventSelection::setAdditionalCutString(std::string cut_string)
{
  m_additional_cuts = cut_string;
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
SusyAnalysisTools::SRHelper* Selection::EventSelection::getPassSRWord()
{
  return &m_pass_sr_word;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::SRHelper* Selection::EventSelection::getReverseSRWord()
{
  return &m_reverse_sr_word;
}

// -----------------------------------------------------------------------------
std::string Selection::EventSelection::getAdditionalCutString()
{
  return m_additional_cuts;
}

// ----------------------------------------------------------------------------
bool Selection::EventSelection::passEvent(
    const SusyAnalysisTools::EventDescription& event_desc,
    const SusyAnalysisTools::SRHelper& sr_helper) const
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  return (  event_desc.pass(   m_pass_event_word   )
         && event_desc.reverse(m_reverse_event_word)
         && sr_helper.pass(    m_pass_sr_word      )
         && sr_helper.reverse( m_reverse_sr_word   )
         );
}

