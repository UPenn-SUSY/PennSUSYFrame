#include <cmath>

#include "include/Vertex.h"
#include "AtlasSFrameUtils/include/CycleMacros.h"

ClassImp(Vertex)

// ----------------------------------------------------------------------------
  Vertex::Vertex( const D3PDReader::VertexD3PDObject& p
                , int index
                , bool is_data
                )
                : D3PDReader::VertexD3PDObjectElement(index,p,is_data)
{
  // do nothing
}

// ----------------------------------------------------------------------------
bool Vertex::isGood()
{
  return (nTracks() >= 5);
}

// ----------------------------------------------------------------------------
bool Vertex::twoTracks()
{
  return (nTracks() >= 2);
}

// ----------------------------------------------------------------------------
void Vertex::print()
{
  std::cout << "\tx: " << x()
            << "\ty: " << y()
            << "\tz: " << z()
            << "\tnum tracks: " << nTracks()
            << "\tE: " << E()
            << "\tm: " << m()
            << "\n";
}

// -----------------------------------------------------------------------------
bool Vertex::eq(const Vertex& v1, const Vertex& v2)
{
  return (v1 == v2);
}

// -----------------------------------------------------------------------------
bool Vertex::lt(const Vertex& v1, const Vertex& v2)
{
  return (v1 < v2);
}

// -----------------------------------------------------------------------------
bool Vertex::gt(const Vertex& v1, const Vertex& v2)
{
  return (v1 > v2);
}

// -----------------------------------------------------------------------------
bool Vertex::operator==(const Vertex& rhs) const
{
  return (m() == rhs.m());
}

// -----------------------------------------------------------------------------
bool Vertex::operator<(const Vertex& rhs) const
{
  return (m() < rhs.m());
}

// -----------------------------------------------------------------------------
bool Vertex::operator>(const Vertex& rhs) const
{
  return (m() > rhs.m());
}
