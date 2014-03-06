#ifndef TINYTLV
#define TINYTLV

// =============================================================================
class TinyTlv
{
  public:
    TinyTlv();
    // ~TinyTlv();

    void setPxPyPzE(double, double, double, double);
    void setPtEtaPhiM(double, double, double, double);

    void calcPxPyPzE();
    void calcPtEtaPhiM();

  private:
    bool m_px_py_pz_e_set;
    double m_e;
    double m_px;
    double m_py;
    double m_pz;

    bool m_pt_eta_phi_m_set;
    double m_m;
    double m_pt;
    double m_eta;
    double m_phi;

};

#endif
