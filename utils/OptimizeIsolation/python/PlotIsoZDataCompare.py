#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
import rootlogon
import metaroot

import Helpers


def makeIsoPlots(file_handles, out_file_name, do_el, do_mu):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    if do_el:
        Helpers.plotIso(file_handles, out_file, 'el', '_PTCONE30'       , 0.  , 1., x_title = 'ptcone30/p_{T}'        )
        Helpers.plotIso(file_handles, out_file, 'el', '_ETCONE30'       , -0.5, 1., x_title = 'etcone30/p_{T}'        )
        Helpers.plotIso(file_handles, out_file, 'el', '_PTCONE20'       , 0.  , 1., x_title = 'ptcone20/p_{T}'        )
        Helpers.plotIso(file_handles, out_file, 'el', '_ETCONE20'       , -0.5, 1., x_title = 'etcone20/p_{T}'        )
        Helpers.plotIso(file_handles, out_file, 'el', '_PTCONE30_CAPPED', 0.  , 1., x_title = 'ptcone30/min(p_{T},60)')
        Helpers.plotIso(file_handles, out_file, 'el', '_ETCONE30_CAPPED', -0.5, 1., x_title = 'etcone30/min(p_{T},60)')
        Helpers.plotIso(file_handles, out_file, 'el', '_PTCONE20_CAPPED', 0.  , 1., x_title = 'ptcone20/min(p_{T},60)')
        Helpers.plotIso(file_handles, out_file, 'el', '_ETCONE20_CAPPED', -0.5, 1., x_title = 'etcone20/min(p_{T},60)')

    if do_mu:
        Helpers.plotIso(file_handles, out_file, 'mu', '_PTCONE30'       , 0.  , 1., x_title = 'ptcone30/p_{T}'        )
        Helpers.plotIso(file_handles, out_file, 'mu', '_ETCONE30'       , -0.5, 1., x_title = 'etcone30/p_{T}'        )
        Helpers.plotIso(file_handles, out_file, 'mu', '_PTCONE20'       , 0.  , 1., x_title = 'ptcone20/p_{T}'        )
        Helpers.plotIso(file_handles, out_file, 'mu', '_ETCONE20'       , -0.5, 1., x_title = 'etcone20/p_{T}'        )
        Helpers.plotIso(file_handles, out_file, 'mu', '_PTCONE30_CAPPED', 0.  , 1., x_title = 'ptcone30/min(p_{T},60)')
        Helpers.plotIso(file_handles, out_file, 'mu', '_ETCONE30_CAPPED', -0.5, 1., x_title = 'etcone30/min(p_{T},60)')
        Helpers.plotIso(file_handles, out_file, 'mu', '_PTCONE20_CAPPED', 0.  , 1., x_title = 'ptcone20/min(p_{T},60)')
        Helpers.plotIso(file_handles, out_file, 'mu', '_ETCONE20_CAPPED', -0.5, 1., x_title = 'etcone20/min(p_{T},60)')

    out_file.Close()

# ==============================================================================
if __name__ == '__main__':
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    file_handles = []

    # add Zee
    this_color=ROOT.kBlue
    file_handle_zee = Helpers.FileHandle( [ {'file_name':'iso.117650.ZeeNp0.root', 'weight':718.89*1.18*1./99999}
                                          , {'file_name':'iso.117651.ZeeNp1.root', 'weight':175.60*1.18*1./100000}
                                          , {'file_name':'iso.117652.ZeeNp2.root', 'weight':58.846*1.18*1./99999}
                                          , {'file_name':'iso.117653.ZeeNp3.root', 'weight':15.560*1.18*1./99999}
                                          , {'file_name':'iso.117654.ZeeNp4.root', 'weight':3.9322*1.18*1./30000 }
                                          , {'file_name':'iso.117655.ZeeNp5.root', 'weight':1.1994*1.18*1./10000 }
                                          ]
                                        , 'Z #rightarrow ee'
                                        , this_color
                                        )
    file_handles.append(file_handle_zee)

    # add egamma data
    this_color = ROOT.kBlack
    file_handles.append(Helpers.FileHandle( [{'file_name':'iso.data_subset.egamma.root', 'weight':1.}]
                                          , 'egamma data'
                                          , this_color
                                          )
                       )

    makeIsoPlots(file_handles, 'iso.electron.canv.root', True, False)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    file_handles = []

    # add Zmumu
    this_color=ROOT.kBlue
    file_handle_zmm = Helpers.FileHandle( [ {'file_name':'iso.117660.ZmumuNp0.root', 'weight':718.91*1.18*1./100000}
                                          , {'file_name':'iso.117661.ZmumuNp1.root', 'weight':175.81*1.18*1./100000}
                                          , {'file_name':'iso.117662.ZmumuNp2.root', 'weight':58.805*1.18*1./100000}
                                          , {'file_name':'iso.117663.ZmumuNp3.root', 'weight':15.589*1.18*1./100000}
                                          , {'file_name':'iso.117664.ZmumuNp4.root', 'weight':3.9072*1.18*1./30000 }
                                          , {'file_name':'iso.117665.ZmumuNp5.root', 'weight':1.1933*1.18*1./10000 }
                                          ]
                                        , 'Z #rightarrow #mu#mu'
                                        , this_color
                                        )
    file_handles.append(file_handle_zmm)

    # add muon data
    this_color = ROOT.kBlack
    file_handles.append(Helpers.FileHandle( [{'file_name':'iso.data_subset.muon.root', 'weight':1.}]
                                          , 'muon data'
                                          , this_color
                                          )
                       )

    makeIsoPlots(file_handles, 'iso.muon.canv.root', False, True)

