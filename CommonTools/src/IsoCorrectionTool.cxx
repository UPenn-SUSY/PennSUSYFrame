#include "include/IsoCorrectionTool.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"

//_____________________________________________________________________________
CommonTools::IsoCorrectionTool::IsoCorrectionTool( SCycleBase* parent
                             , const char* name
                             )
                             : ToolBase(parent, name)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  DeclareProperty("ptcone20_p1", c_p1[PTCONE][20] = 0);
  DeclareProperty("ptcone30_p1", c_p1[PTCONE][30] = 0);
  DeclareProperty("ptcone40_p1", c_p1[PTCONE][40] = 0);

  DeclareProperty("etcone20_p1", c_p1[ETCONE][20] = 0);
  DeclareProperty("etcone30_p1", c_p1[ETCONE][30] = 0);
  DeclareProperty("etcone40_p1", c_p1[ETCONE][40] = 0);

  DeclareProperty("topoetcone20_p1", c_p1[TOPOETCONE][20] = 0);
  DeclareProperty("topoetcone30_p1", c_p1[TOPOETCONE][30] = 0);
  DeclareProperty("topoetcone40_p1", c_p1[TOPOETCONE][40] = 0);

  DeclareProperty("topoetcone_corrected20_p1", c_p1[TOPOETCONE_CORR][20] = 0);
  DeclareProperty("topoetcone_corrected30_p1", c_p1[TOPOETCONE_CORR][30] = 0);
  DeclareProperty("topoetcone_corrected40_p1", c_p1[TOPOETCONE_CORR][40] = 0);

  DeclareProperty("ptcone20_p2", c_p2[PTCONE][20] = 0);
  DeclareProperty("ptcone30_p2", c_p2[PTCONE][30] = 0);
  DeclareProperty("ptcone40_p2", c_p2[PTCONE][40] = 0);

  DeclareProperty("etcone20_p2", c_p2[ETCONE][20] = 0);
  DeclareProperty("etcone30_p2", c_p2[ETCONE][30] = 0);
  DeclareProperty("etcone40_p2", c_p2[ETCONE][40] = 0);

  DeclareProperty("topoetcone20_p2", c_p2[TOPOETCONE][20] = 0);
  DeclareProperty("topoetcone30_p2", c_p2[TOPOETCONE][30] = 0);
  DeclareProperty("topoetcone40_p2", c_p2[TOPOETCONE][40] = 0);

  DeclareProperty("topoetcone_corrected20_p2", c_p2[TOPOETCONE_CORR][20] = 0);
  DeclareProperty("topoetcone_corrected30_p2", c_p2[TOPOETCONE_CORR][30] = 0);
  DeclareProperty("topoetcone_corrected40_p2", c_p2[TOPOETCONE_CORR][40] = 0);
}

//_____________________________________________________________________________
CommonTools::IsoCorrectionTool::~IsoCorrectionTool()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::IsoCorrectionTool::getIsoCorrection( ISO_TYPE iso_type
                                                       , int cone_size
                                                       , int num_vertex
                                                       )
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (iso_type == REL_PTCONE)          iso_type = PTCONE;
  if (iso_type == REL_ETCONE)          iso_type = ETCONE;
  if (iso_type == REL_TOPOETCONE)      iso_type = TOPOETCONE;
  if (iso_type == REL_TOPOETCONE_CORR) iso_type = TOPOETCONE_CORR;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (c_p1.find(iso_type) == c_p1.end() || c_p2.find(iso_type) == c_p2.end())
    return 0;
  if (  c_p1[iso_type].find(cone_size) == c_p1[iso_type].end()
     || c_p2[iso_type].find(cone_size) == c_p2[iso_type].end()
     )
    return 0;

  double p1 = c_p1[iso_type][cone_size];
  double p2 = c_p2[iso_type][cone_size];

  double correction = 0;
  if (p1 != 0) correction += p1*num_vertex;
  if (p2 != 0) correction += p2*num_vertex*num_vertex;

  return correction;
}
