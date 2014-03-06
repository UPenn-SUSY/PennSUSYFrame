#ifndef HistInfo_h
#define HistInfo_h

#include <iostream>
#include <TH1.h>
#include <TH1D.h>
#include <TH2D.h>

// =============================================================================
enum HIST_TYPE {HIST_1D, HIST_2D};

// =============================================================================
class HistInfo
{
  // ---------------------------------------------------------------------------
  public:
    // HistInfo();
    HistInfo( HIST_TYPE hist_type = HIST_1D
            , std::string var_exp = ""
            , unsigned int x_num_bins = 0
            , float x_min = 0
            , float x_max = 0
            , unsigned int y_num_bins = 0
            , float y_min = 0
            , float y_max = 0
            , std::string name = "hist_name"
            , std::string title = "hist_title"
            , std::string x_axis = "x_axis"
            , std::string y_axis = "y_axis"
            , std::string z_axis = "z_axis"
            , std::string hist_cut = ""
            );
    HistInfo(const HistInfo&);

    HIST_TYPE getHistType() const;
    std::string getVarExp() const;
    unsigned int getNumXBins() const;
    float getXMin() const;
    float getXMax() const;
    unsigned int getNumYBins() const;
    float getYMin() const;
    float getYMax() const;
    std::string getName() const;
    std::string getTitle() const;
    std::string getXAxis() const;
    std::string getYAxis() const;
    std::string getZAxis() const;
    std::string getHistCut() const;

    TH1* genHist(std::string key);
    // TH1D* genHist(std::string key);

  // ---------------------------------------------------------------------------
  private:
    HIST_TYPE m_hist_type;
    std::string m_var_exp;
    unsigned int m_x_num_bins;
    float m_x_min;
    float m_x_max;
    unsigned int m_y_num_bins;
    float m_y_min;
    float m_y_max;
    std::string m_name;
    std::string m_title;
    std::string m_x_axis;
    std::string m_y_axis;
    std::string m_z_axis;
    std::string m_hist_cut;
};

#endif
