#ifndef AtlasSFrameTools_ParticleElement_h
#define AtlasSFrameTools_ParticleElement_h

#include "TLorentzVector.h"

template <class ElementType>
class ParticleElement: public ElementType
{
public:
  // main constructor
  ParticleElement(const ElementType& p, int index = -1, bool fillTLV = true);

  // copy constructor
  ParticleElement(const ParticleElement& p);

  // assignment operator
  ParticleElement& operator=(const ParticleElement& p);

  // sort predicate
  static bool pt_cmp(const ParticleElement& p1, const ParticleElement& p2);

  TLorentzVector tlv;
  int D3PD_index;

};

//______________________________________________________________________________
template <class ElementType>
ParticleElement<ElementType>::ParticleElement(const ElementType& p, int index, bool fillTLV)
  :   ElementType(p), D3PD_index(index)
{
  if (fillTLV) tlv.SetPtEtaPhiM(p.pt(), p.eta(), p.phi(), p.m());
}

//______________________________________________________________________________
template <class ElementType>
ParticleElement<ElementType>::ParticleElement(const ParticleElement& p)
  :   ElementType(p), tlv(p.tlv), D3PD_index(p.D3PD_index)
{ }


//______________________________________________________________________________
template <class ElementType>
ParticleElement<ElementType>& ParticleElement<ElementType>::operator=(const ParticleElement& p)
{
  if(this != &p)
  {
    this->ElementType::operator=(p);
    this->tlv = p.tlv;
    this->D3PD_index = p.D3PD_index;
  }
  return *this;
}

//______________________________________________________________________________
template <class ElementType>
bool ParticleElement<ElementType>::pt_cmp(const ParticleElement& p1, const ParticleElement& p2) // sort predicate
{
  return p1.tlv.Pt() > p2.tlv.Pt();
}

#endif
