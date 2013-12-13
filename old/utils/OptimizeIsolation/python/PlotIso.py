#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
import rootlogon
import metaroot

import Helpers

# ==============================================================================
if __name__ == '__main__':
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ROOT.gROOT.SetBatch()

    # fh = []
    file_handles = []
    this_color = 1

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add ttbar
    this_color = ROOT.kBlue
    file_handles.append(Helpers.FileHandle( [{'file_name':'iso.105200.ttbar.root', 'weight':1.}]
                                          , 'ttbar'
                                          , this_color
                                          )
                       )
    this_color += 1

    # # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # # add Zee
    # this_color=ROOT.kCyan
    # file_handle_zee = Helpers.FileHandle( [ {'file_name':'iso.117650.ZeeNp0.root', 'weight':718.89*1.18*1./149998}
    #                                       , {'file_name':'iso.117651.ZeeNp1.root', 'weight':175.60*1.18*1./150000}
    #                                       , {'file_name':'iso.117652.ZeeNp2.root', 'weight':58.846*1.18*1./144999}
    #                                       , {'file_name':'iso.117653.ZeeNp3.root', 'weight':15.560*1.18*1./109999}
    #                                       , {'file_name':'iso.117654.ZeeNp4.root', 'weight':3.9322*1.18*1./30000 }
    #                                       , {'file_name':'iso.117655.ZeeNp5.root', 'weight':1.1994*1.18*1./10000 }
    #                                       ]
    #                                     , 'Z #rightarrow ee'
    #                                     , this_color
    #                                     )
    # file_handles.append(file_handle_zee)

    # # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # # add Zmumu
    # this_color=ROOT.kGreen
    # file_handle_zmm = Helpers.FileHandle( [ {'file_name':'iso.117660.ZmumuNp0.root', 'weight':718.91*1.18*1./150000}
    #                                       , {'file_name':'iso.117661.ZmumuNp1.root', 'weight':175.81*1.18*1./150000}
    #                                       , {'file_name':'iso.117662.ZmumuNp2.root', 'weight':58.805*1.18*1./144998}
    #                                       , {'file_name':'iso.117663.ZmumuNp3.root', 'weight':15.589*1.18*1./110000}
    #                                       , {'file_name':'iso.117664.ZmumuNp4.root', 'weight':3.9072*1.18*1./30000 }
    #                                       , {'file_name':'iso.117665.ZmumuNp5.root', 'weight':1.1933*1.18*1./10000 }
    #                                       ]
    #                                     , 'Z #rightarrow #mu#mu'
    #                                     , this_color
    #                                     )
    # file_handles.append(file_handle_zmm)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add signal
    # rates.127994.signal.root
    # rates.127995.signal.root
    # rates.127996.signal.root
    this_color = ROOT.kRed
    file_handles.append(Helpers.FileHandle( [{'file_name':'iso.127995.signal.root', 'weight':1.}]
                                          , 'signal 127995'
                                          , this_color
                                          )
                       )
    this_color += 1

    # iso.small_data.egamma.root
    # iso.small_data.muon.root

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = ROOT.TFile('iso.canv.root', 'RECREATE')

    Helpers.plotIso(file_handles, out_file, 'el', '_PTCONE30'       , 0.  , 1., x_title = 'ptcone30/p_{T}'        )
    Helpers.plotIso(file_handles, out_file, 'el', '_ETCONE30'       , -0.5, 1., x_title = 'etcone30/p_{T}'        )
    Helpers.plotIso(file_handles, out_file, 'el', '_PTCONE20'       , 0.  , 1., x_title = 'ptcone20/p_{T}'        )
    Helpers.plotIso(file_handles, out_file, 'el', '_ETCONE20'       , -0.5, 1., x_title = 'etcone20/p_{T}'        )
    Helpers.plotIso(file_handles, out_file, 'el', '_PTCONE30_CAPPED', 0.  , 1., x_title = 'ptcone30/min(p_{T},60)')
    Helpers.plotIso(file_handles, out_file, 'el', '_ETCONE30_CAPPED', -0.5, 1., x_title = 'etcone30/min(p_{T},60)')
    Helpers.plotIso(file_handles, out_file, 'el', '_PTCONE20_CAPPED', 0.  , 1., x_title = 'ptcone20/min(p_{T},60)')
    Helpers.plotIso(file_handles, out_file, 'el', '_ETCONE20_CAPPED', -0.5, 1., x_title = 'etcone20/min(p_{T},60)')

    Helpers.plotIso(file_handles, out_file, 'mu', '_PTCONE30'       , 0.  , 1., x_title = 'ptcone30/p_{T}'        )
    Helpers.plotIso(file_handles, out_file, 'mu', '_ETCONE30'       , -0.5, 1., x_title = 'etcone30/p_{T}'        )
    Helpers.plotIso(file_handles, out_file, 'mu', '_PTCONE20'       , 0.  , 1., x_title = 'ptcone20/p_{T}'        )
    Helpers.plotIso(file_handles, out_file, 'mu', '_ETCONE20'       , -0.5, 1., x_title = 'etcone20/p_{T}'        )
    Helpers.plotIso(file_handles, out_file, 'mu', '_PTCONE30_CAPPED', 0.  , 1., x_title = 'ptcone30/min(p_{T},60)')
    Helpers.plotIso(file_handles, out_file, 'mu', '_ETCONE30_CAPPED', -0.5, 1., x_title = 'etcone30/min(p_{T},60)')
    Helpers.plotIso(file_handles, out_file, 'mu', '_PTCONE20_CAPPED', 0.  , 1., x_title = 'ptcone20/min(p_{T},60)')
    Helpers.plotIso(file_handles, out_file, 'mu', '_ETCONE20_CAPPED', -0.5, 1., x_title = 'etcone20/min(p_{T},60)')

    out_file.Close()

