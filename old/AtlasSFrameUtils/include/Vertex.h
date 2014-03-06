// file:        Vertex.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     October 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Vertex_h
#define AtlasSFrameUtils_Vertex_h

#include <iostream>
#include <vector>
#include "ParticleElement.h"

#include "D3PDObjects/include/VertexD3PDObject.h"

// ============================================================================
namespace CommonTools
{
  class TLVTool;
}

// ============================================================================
class Vertex : public D3PDReader::VertexD3PDObjectElement
{
public:
  Vertex( const D3PDReader::VertexD3PDObject& p
        , int index = -1
        , bool is_data = true
        );

  bool isGood();
  bool twoTracks();

  void print();

  static bool eq(const Vertex& el1, const Vertex& el2);
  static bool lt(const Vertex& el1, const Vertex& el2);
  static bool gt(const Vertex& el1, const Vertex& el2);

  bool operator==(const Vertex& rhs) const;
  bool operator<( const Vertex& rhs) const;
  bool operator>( const Vertex& rhs) const;

private:

  ClassDef(Vertex, 1);
};

#endif // AtlasSFrameUtils_Vertex_h
