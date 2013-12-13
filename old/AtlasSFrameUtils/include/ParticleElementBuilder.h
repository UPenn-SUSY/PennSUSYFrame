#ifndef AtlasSFrameTools_ParticleElementBuilder_h
#define AtlasSFrameTools_ParticleElementBuilder_h

#include <vector>
#include <iostream>

#include "CommonTools/include/TLVTool.h"
#include "CommonTools/include/IsoCorrectionTool.h"

namespace ParticleElementBuilder
{

  template < class ParticleElementType, class D3PDObjectType >
    void build( std::vector<ParticleElementType>& vec
              , const D3PDObjectType& obj
              , CommonTools::TLVTool* tlv_tool
              );
  template < class ParticleElementType, class D3PDObjectType >
    void build( std::vector<ParticleElementType>& vec
              , const D3PDObjectType& obj
              , CommonTools::TLVTool* tlv_tool
              , CommonTools::IsoCorrectionTool* iso_corr_tool
              );
};

//______________________________________________________________________________
template < class ParticleElementType, class D3PDObjectType >
void ParticleElementBuilder::build( std::vector<ParticleElementType>& vec
                                  , const D3PDObjectType& obj
                                  , CommonTools::TLVTool* tlv_tool
                                  )
{
    for(int i=0; i < obj.n(); i++)
    {
        vec.push_back( ParticleElementType( obj[i]
                                          , tlv_tool
                                          , i
                                          )
                     );
    }
}

//______________________________________________________________________________
template < class ParticleElementType, class D3PDObjectType >
void ParticleElementBuilder::build( std::vector<ParticleElementType>& vec
                                  , const D3PDObjectType& obj
                                  , CommonTools::TLVTool* tlv_tool
                                  , CommonTools::IsoCorrectionTool* iso_corr_tool
                                  )
{
    for(int i=0; i < obj.n(); i++)
    {
        vec.push_back( ParticleElementType( obj[i]
                                          , tlv_tool
                                          , iso_corr_tool
                                          , i
                                          )
                     );
    }
}

#endif
