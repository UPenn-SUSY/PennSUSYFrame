#include "TinyTlv/include/TinyTlv.h"

#include <iostream>

// -----------------------------------------------------------------------------
TinyTlv::TinyTlv() : m_px_py_pz_e_set(0)
                   , m_e(0)
                   , m_px(0)
                   , m_py(0)
                   , m_pz(0)
                   , m_pt_eta_phi_m_set(0)
                   , m_m(0)
                   , m_pt(0)
                   , m_eta(0)
                   , m_phi(0)
{
  // do nothing
}

// -----------------------------------------------------------------------------
void TinyTlv::setPxPyPzE(double px, double py, double pz, double e)
{
  m_px = px;
  m_py = py;
  m_pz = pz;
  m_e = e;
  m_px_py_pz_e_set = true;
  m_pt_eta_phi_m_set = false;
}

// -----------------------------------------------------------------------------
void TinyTlv::setPtEtaPhiM(double pt, double eta, double phi, double m)
{
  m_pt = pt;
  m_eta = eta;
  m_phi = phi;
  m_m = m;
  m_pt_eta_phi_m_set = true;
  m_px_py_pz_e_set = false;
}

// -----------------------------------------------------------------------------
void TinyTlv::calcPxPyPzE()
{
  // if px,py,pz,e is already set, don't do anything
  if (m_px_py_pz_e_set) return;

  if (!m_pt_eta_phi_m_set) {
    std::cout << "cannot set px,py,pz,e\n";
    return;
  }

  // TODO set px,py,pz,e
  m_px_py_pz_e_set = true;
}

// -----------------------------------------------------------------------------
void TinyTlv::calcPtEtaPhiM()
{
  // if pt,eta,phi,m is already set, don't do anything
  if (m_pt_eta_phi_m_set) return;

  if (!m_px_py_pz_e_set) {
    std::cout << "cannot set pt,eta,phi,m\n";
    return;
  }

  // TODO set pt,eta,phi,m
  m_pt_eta_phi_m_set = true;
}
