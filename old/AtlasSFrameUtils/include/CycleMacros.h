// file:        CycleMacros.h
// author:      Ryan Reece       <ryan.reece@cern.ch>
// created:     January 2011
//------------------------------------------------------------------------------


#ifndef AtlasSFrameUtils_CycleMacros_h
#define AtlasSFrameUtils_CycleMacros_h

#define DECLARE_TOOL(ToolType, ToolName) DeclareTool(new ToolType(this, ToolName) )
#define GET_TOOL(var, ToolType, ToolName) ToolType* var = dynamic_cast<ToolType*>( GetTool(ToolName) )

enum SYST { NOMINAL
          , MET_SCALE_ST_UP
          , MET_SCALE_ST_DOWN
          , MET_RES_ST
          };

#endif // AtlasSFrameUtils_CycleMacros_h
