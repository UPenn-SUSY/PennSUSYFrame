#ifndef AtlasSFrameUtils_JetContainer
#define AtlasSFrameUtils_JetContainer

#include <iostream>
#include <vector>

#include "ParticleElementBuilder.h"
#include "Jet.h"
#include "CommonTools/include/TLVTool.h"

// ============================================================================
enum JET_COLLECTIONS { JET_ALL = 0  // Green tree snake
                     , JET_BASELINE // Baseline cuts
                     , JET_BAD      // Baseline + overlap removal
                     , JET_GOOD     // Baseline + overlap removal
                     , JET_CENTRAL  // Light central cuts
                     , JET_B        // B-jet cuts
                     , JET_FORWARD  // Forward cuts
                     , JET_N
                     };

// ============================================================================
class JetContainer
{
  public:
    JetContainer();
    ~JetContainer();

    void init(CommonTools::TLVTool*);

    void clear();
    void prepJets(D3PDReader::JetD3PDObject*);
    void setCollection(JET_COLLECTIONS, std::vector<Jet*>);

    size_t num(JET_COLLECTIONS) const;
    const std::vector<Jet*> getJets(JET_COLLECTIONS) const;

    void print(JET_COLLECTIONS) const;

  private:
    std::vector<Jet> m_master_list;
    std::vector<std::vector<Jet*> > m_user_lists;

    CommonTools::TLVTool* m_tlv_tool;
};

#endif
