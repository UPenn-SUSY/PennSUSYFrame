#!/usr/bin/env python

import RunTntMaker

# ==============================================================================
if __name__ == '__main__':
    file_list = RunTntMaker.getFileListFromDir('/afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01267512_00/')
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01267513_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01267514_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01267515_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01267516_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01267517_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01267518_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01306755_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01306756_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01306757_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01306758_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01306759_00/
    # /afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01306760_00/

    RunTntMaker.runTntMaker( file_list = file_list
                           , is_data = False
                           , is_full_sim = True
                           )

