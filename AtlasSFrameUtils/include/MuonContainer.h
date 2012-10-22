#ifndef AtlasSFrameUtils_MuonContainer
#define AtlasSFrameUtils_MuonContainer

#include <iostream>
#include <vector>

#include "ParticleElementBuilder.h"
#include "Muon.h"
#include "VertexContainer.h"

#include "CommonTools/include/TLVTool.h"
#include "CommonTools/include/IsoCorrectionTool.h"

// ============================================================================
enum MUON_COLLECTIONS { MU_ALL = 0  // Green tree snake
                      , MU_BASELINE // Baseline cuts
                      , MU_GOOD     // Baseline + overlap removal
                      , MU_SIGNAL   // Signal cuts
                      , MU_BAD      // Bad muons
                      , MU_COSMIC   // Cosmic muons
                      , MU_N
                      };

// ============================================================================
class MuonContainer
{
  public:
    MuonContainer();
    ~MuonContainer();

    void init(CommonTools::TLVTool*, CommonTools::IsoCorrectionTool*);

    void clear();
    void prepMuons(D3PDReader::MuonD3PDObject*);
    void setCollection(MUON_COLLECTIONS, std::vector<Muon*>);

    size_t num(MUON_COLLECTIONS) const;
    const std::vector<Muon*>* getMuons(MUON_COLLECTIONS) const;

    void print(MUON_COLLECTIONS, const VertexContainer&) const;

  private:
    std::vector<Muon> m_master_list;
    std::vector<std::vector<Muon*> > m_user_lists;

    CommonTools::TLVTool* m_tlv_tool;
    CommonTools::IsoCorrectionTool* m_iso_corr_tool;
};

#endif
