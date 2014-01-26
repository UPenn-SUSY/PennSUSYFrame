#include "BMinusLAnalysis/include/BMinusLAnalysis.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <dirent.h>
#include <math.h>
#include <algorithm>

#include "PennSusyFrameCore/include/ObjectContainers.h"
#include "PennSusyFrameCore/include/Calculators.h"

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLAnalysis::BMinusLAnalysis(TTree* tree) : PennSusyFrame::PennSusyFrameCore(tree)
{}

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLAnalysis::~BMinusLAnalysis()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::processEvent()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::finalizeEvent()
{
}
