#!/bin/env python

# Run envelopes?  If false, run detailed breakdown
AllMerged = False
BigNorm = False # Big normalization region?

import ROOT
ROOT.SetSignalPolicy( ROOT.kSignalFast )
ROOT.gROOT.SetBatch(True)
ROOT.gErrorIgnoreLevel = ROOT.kError

a_long_variable_name = 0
def gimmeInt():
    global a_long_variable_name
    a_long_variable_name += 1
    return str(a_long_variable_name)

from math import sqrt

colors = [ROOT.kBlack,ROOT.kRed,ROOT.kBlue,ROOT.kGreen+2,ROOT.kMagenta,ROOT.kTeal,ROOT.kOrange,ROOT.kYellow]
c = ROOT.TCanvas('canv','',900,600)
c.SetLogy()

ttW_xsecDict = {
        'ttW': 0.1041*1.175 , 'ttWj': 0.053372*1.17 , 'ttWjI': 0.09332*1.175 , 'ttWjjI': 0.041482*1.17 ,
        'ttW_SU':    0.083065 * 1.470000 * 0.22,  'ttW_SD':    0.142750 * 0.840000 * 0.22,  'ttW_AU':    0.111250 * 1.170000 * 0.22,
        'ttW_AD':    0.099141 * 1.120000 * 0.22,  'ttW_MF':    0.103960 * 1.170000 * 0.22,  'ttW_LF':    0.103940 * 1.160000 * 0.22,
        'ttW_XU':    0.103990 * 1.170000 * 0.22,  'ttW_XD':    0.104060 * 1.160000 * 0.22,
        'ttWjE_SU':  0.042315 * 1.470000 * 0.22,  'ttWjE_SD':  0.075138 * 0.840000 * 0.22,  'ttWjE_AU':  0.051958 * 1.170000 * 0.22,
        'ttWjE_AD':  0.056702 * 1.120000 * 0.22,  'ttWjE_MF':  0.052841 * 1.170000 * 0.22,  'ttWjE_LF':  0.054088 * 1.160000 * 0.22,
        'ttWjE_XU':  0.053276 * 1.170000 * 0.22,  'ttWjE_XD':  0.053528 * 1.160000 * 0.22,
        'ttWjjI_SU': 0.032464 * 1.470000 * 0.22,  'ttWjjI_SD': 0.059412 * 0.840000 * 0.22,  'ttWjjI_AU': 0.035146 * 1.170000 * 0.22,
        'ttWjjI_AD': 0.050774 * 1.120000 * 0.22,  'ttWjjI_MF': 0.041213 * 1.170000 * 0.22,  'ttWjjI_LF': 0.041703 * 1.160000 * 0.22,
        'ttWjjI_XU': 0.041118 * 1.170000 * 0.22,  'ttWjjI_XD': 0.042272 * 1.160000 * 0.22,
        }
ttW_files = { x:ROOT.TFile.Open( 'output_hist_files/'+x+'.root' ) for x in ttW_xsecDict }

db_files = {}
db_fileList = [ 'Diboson','Nominal','bwcutoff','Py6','Sc1005','Sc0510','Sc1020','Sc2010', ]
for a in ['ww','zz','wz']: db_files[a] = [ ROOT.TFile.Open( 'output_hist_files/'+x+'_'+a+'.root' ) for x in db_fileList ]
db_files['ww'] += [ ROOT.TFile.Open( 'output_hist_files/PowPy6_ww.root' ) ]

st_fileList = ['AcerWt',
               'McAtNlo',
               'McAtNloWt',
               'PowJiWtDR',
               'PowJiWtDS',
               'PowPyWtDR',
               'PowPyWtDS',
               'PowJiWtDR',
               'PowPyWtDR',
               'AcerMore',
               'AcerLess' ]
st_files =  [ ROOT.TFile.Open( 'output_hist_files/'+x+'.root' ) for x in st_fileList ]

ttbar_fileList = ['LessPS',
                  'MorePS',
                  'facsc2',
                  'rensc2',
                  'facsc05',
                  'rensc05',
                  'PowhegJimmy',
                  'PowhegPythia']
ttbar_files = [ROOT.TFile.Open( 'output_hist_files/ttbar_'+x+'.root' ) for x in ttbar_fileList ]

alpgen_ttbar = {'AlpgenTTbarNp0':4.793*1.634 ,
                'AlpgenTTbarNp1':5.068*1.634 ,
                'AlpgenTTbarNp2':3.257*1.634 ,
                'AlpgenTTbarNp3p':2.176*1.634 ,
                'ttbar_PowhegJimmy':1}
alpgen_files = { x:ROOT.TFile.Open( 'output_hist_files/'+x+'.root' ) for x in alpgen_ttbar }

Z_xsecDict = { # only relative xsec matters
              'Zee_4jets':1.,'Zmm_4jets':1.,'Ztt_4jets':1.,
              'Zee_4jetsOnly':1.,'Zmm_4jetsOnly':1.,'Ztt_4jetsOnly':1.}
Z_files = { x:ROOT.TFile.Open( 'output_hist_files/'+x+'.root' ) for x in Z_xsecDict }

def half_diff( files , aset , h , normR ):
    n1 = files[aset[0]].Get('hist_'+normR).Integral(1,files[aset[0]].Get('hist_'+normR).GetNbinsX())
    n2 = files[aset[1]].Get('hist_'+normR).Integral(1,files[aset[0]].Get('hist_'+normR).GetNbinsX())

    h1 = files[aset[0]].Get('hist_'+h)
    h2 = files[aset[1]].Get('hist_'+h)

    unc = []
    for i in xrange( h1.GetNbinsX() ):
        s1 = h1.GetBinContent( i+1 )/(n1 if n1>0 else 1.)
        s2 = h2.GetBinContent( i+1 )/(n2 if n2>0 else 1.)
        if s2+s1>0 and s1>0 and s2>0 and n1>0 and n2>0: unc += [ 1+ (s2-s1)*0.5/(s2+s1) ]
        else:       unc += [1.]
    return unc

def multi_half_diff( files , aset , h , an_xsecDict , normR ):
    nhists = []
    hists = []
    the_int = -1.
    for n,ak in enumerate(aset):
        for m,b in enumerate(ak):
            if m==0:
                nhists += [ files[b].Get('hist_'+normR).Clone('temp'+gimmeInt()) ]
                nhists[n].Scale( an_xsecDict[b] )
                hists += [ files[b].Get('hist_'+h).Clone('temp'+gimmeInt()) ]
                hists[n].Scale( an_xsecDict[b] )
            else:
                nhists[n].Add( files[b].Get('hist_'+normR).Clone('temp'+gimmeInt()) , an_xsecDict[b] )
                hists[n].Add( files[b].Get('hist_'+h).Clone('temp'+gimmeInt()) , an_xsecDict[b] )

    n1 = nhists[0].Integral(1,nhists[0].GetNbinsX())
    n2 = nhists[1].Integral(1,nhists[1].GetNbinsX())

    h1 = hists[0]
    h2 = hists[1]

    unc = []
    for i in xrange( h1.GetNbinsX() ):
        s1 = h1.GetBinContent( i+1 )/(n1 if n1>0 else 1.)
        s2 = h2.GetBinContent( i+1 )/(n2 if n2>0 else 1.)
        if s2+s1>0 and s1>0 and s2>0: unc += [ 1+ (s2-s1)*0.5/(s2+s1) ]
        else:       unc += [1.]
    return unc

def full_diff( files , aset , h , normR ):
    n1 = files[aset[0]].Get('hist_'+normR).Integral(1,files[aset[0]].Get('hist_'+normR).GetNbinsX())
    n2 = files[aset[1]].Get('hist_'+normR).Integral(1,files[aset[0]].Get('hist_'+normR).GetNbinsX())

    h1 = files[aset[0]].Get('hist_'+h)
    h2 = files[aset[1]].Get('hist_'+h)

    unc = []
    for i in xrange( h1.GetNbinsX() ):
        s1 = h1.GetBinContent( i+1 )/(n1 if n1>0 else 1.)
        s2 = h2.GetBinContent( i+1 )/(n2 if n2>0 else 1.)
        if s2+s1>0 and s1>0 and s2>0: unc += [ 1+ (s2-s1)/(s2+s1) ]
        else:       unc += [1.]
    return unc

def multi_full_diff( files , aset , h , an_xsecDict , normR ):
    nhists = []
    hists = []
    for n,ak in enumerate(aset):
        for m,b in enumerate(ak):
            if m==0:
                nhists += [ files[b].Get('hist_'+normR).Clone('temp'+gimmeInt()) ]
                nhists[n].Scale( an_xsecDict[b] )
                hists += [ files[b].Get('hist_'+h).Clone('temp'+gimmeInt()) ]
                hists[n].Scale( an_xsecDict[b] )
            else:
                nhists[n].Add( files[b].Get('hist_'+normR).Clone('temp'+gimmeInt()) , an_xsecDict[b] )
                hists[n].Add( files[b].Get('hist_'+h).Clone('temp'+gimmeInt()) , an_xsecDict[b] )

    n1 = nhists[0].Integral(1,nhists[0].GetNbinsX())
    n2 = nhists[1].Integral(1,nhists[1].GetNbinsX())

    h1 = hists[0]
    h2 = hists[1]
    unc = []
    for i in xrange( h1.GetNbinsX() ):
        s1 = h1.GetBinContent( i+1 )/(n1 if n1>0 else 1.)
        s2 = h2.GetBinContent( i+1 )/(n2 if n2>0 else 1.)
        if s2+s1>0 and s1>0 and s2>0: unc += [ 1+ (s2-s1)/(s2+s1) ]
        else:       unc += [1.]
    return unc

class syst:
    def __init__(self):
        # Full structure: uncertainty name -> sample name -> region -> [ unc up , unc down ]
        self.systs = {}

    def check_and_add( self , syst_name , samp_name , reg_name , syst_up , syst_down ):

        if syst_name in self.systs:
            if not samp_name in self.systs[syst_name]: self.systs[syst_name][samp_name] = { reg_name : [ syst_up , syst_down ] }
            else:                                      self.systs[syst_name][samp_name][reg_name] = [ syst_up , syst_down ]
        else:
            self.systs[syst_name] = { samp_name : { reg_name : [ syst_up , syst_down ] } }

    def Print(self):
        for u in self.systs:
            print '           \''+u+'\' : {'
            for s in self.systs[u]:
                print '              \''+s+'\' : {'
                for r in self.systs[u][s]:
                    print '                 \''+r.replace('EE_','SF_')+'\' : [ '+str(self.systs[u][s][r][0])+' , '+str(self.systs[u][s][r][1])+' ] , '
                print '              },'
            print '           },'

systematics = syst()

# Systematics
for areg in ['CR_TOP', 'CR_Z', 'VR_TOP_1', 'VR_TOP_2',
             'VR_TOP_3', 'VR_Z', 'SR_400', 'SR_600']:
    norm_reg = 'NR'
    # norm_reg = 'CR_TOP'

##     # Diboson uncertainties
##     if not BigNorm:
##         norm_reg = 'Z_CREM_HMxMR' if '_HM' in areg else 'Z_CREM_LMxMR'
##     for a in ['ww','wz','zz']:
##         # Get out the sample name
##         asamp = 'DibosonWW' if 'ww'==a else a.upper()
## 
##         if not AllMerged:
##             # Scale variations -- aMC@NLO samples with scale variations
##             sets = { '_RScales':[4,6] , '_FScales':[5,7] } #, '_BScales':[1,2] }
##             for aset in sets:
##                 theSystUp = half_diff( db_files[a] , sets[aset] , areg.replace('EE','EM') , norm_reg )
##                 theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
##                 #if a=='zz' and areg=='T_CREM_HMxR': print 'ZLM',areg,aset,theSystUp,theSystDown
##                 systematics.check_and_add( aset , asamp , areg , theSystUp , theSystDown )
## 
##             # PS and MC for WW - full difference and symmetrize
##             if a=='ww':
##                 sets = { '_DBPS':[1,3] , '_MC':[8,3] }
##                 for aset in sets:
##                     theSystUp = full_diff( db_files[a] , sets[aset] , areg.replace('EE','EM') , norm_reg )
##                     theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
##                     systematics.check_and_add( aset , asamp , areg , theSystUp , theSystDown )
## 
##             # PS and MC for WZ/ZZ - largest difference and symmetrize
##         else:
##             theSystUp = full_diff( db_files[a] , [0,1] , areg.replace('EE','EM') , norm_reg )
##                 for n,s in enumerate([[0,3],[1,3]]):
##                     a_diff = full_diff( db_files[a] , s , areg.replace('EE','EM') , norm_reg )
##                     for i in xrange(len(theSystUp)):
##                         theSystUp[i] = max( abs(theSystUp[i]),abs(a_diff[i]),abs(1./theSystUp[i]),abs(1./a_diff[i]) )
##                 theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
##                 systematics.check_and_add( '_DBPS' , asamp , areg , theSystUp , theSystDown )
##         else:
##             # Take the largest of the above sets and symmetrize first basic one: MC difference
## 
##             # Starting point: aMC@NLO Herwig v aMC@NLO Pythia 6
##             theSystUp = full_diff( db_files[a] , [1,3] , areg.replace('EE','EM') , norm_reg ) 
## 
##             # Check against the scale variations
##             sets = { '_RScales':[4,6] , '_FScales':[5,7] } #, '_BScales':[1,2] }
##             for aset in sets:
##                 a_diff = half_diff( db_files[a] , sets[aset] , areg.replace('EE','EM') , norm_reg )
##                 for i in xrange(len(theSystUp)):
##                     theSystUp[i] = max( abs(theSystUp[i]),abs(a_diff[i]),abs(1./theSystUp[i]),abs(1./a_diff[i]) )
##             if 'ww'==a: alist = [ [8,3] ]
##             if 'ww'!=a: alist = [ [0,1] , [0,3] ]
##             for n,s in enumerate(alist):
##                 a_diff = full_diff( db_files[a] , s , areg.replace('EE','EM') , norm_reg )
##                 for i in xrange(len(theSystUp)):
##                     theSystUp[i] = max( abs(theSystUp[i]),abs(a_diff[i]),abs(1./theSystUp[i]),abs(1./a_diff[i]) ) 
##             theSystDown = [] 
##             for t in theSystUp: 
##                 if t>1: theSystDown += [1./t] 
##                 else: theSystDown += [ 2.-t] 
##             systematics.check_and_add( '_Envelope' , asamp , areg , theSystUp , theSystDown )
## 
##     # ttW systematic uncertainties
##     if not BigNorm:
##         if 'EM' in areg:
##             norm_reg = 'T_CREM_HMxMR' if '_HM' in areg else 'T_CREM_LMxMR'
##         else:
##             norm_reg = 'T_CREE_HMxMR' if '_HM' in areg else 'T_CREE_LMxMR'
##     if not AllMerged:
##         theSystUp = multi_full_diff( ttW_files , [['ttW','ttWjI'],['ttW','ttWj','ttWjjI']] , areg , ttW_xsecDict , norm_reg )
##         theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
##         systematics.check_and_add( '_multiParton' , 'TTW' , areg , theSystUp , theSystDown )
## 
##         for a in [['SU','SD'],['AU','AD'],['MF','LF'],['XU','XD']]:
##             theSystUp = multi_half_diff( ttW_files , [['ttW_'+a[0],'ttWjE_'+a[0],'ttWjjI_'+a[0]],['ttW_'+a[1],'ttWjE_'+a[1],'ttWjjI_'+a[1]]] , areg , ttW_xsecDict , norm_reg )
##             theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
##             systematics.check_and_add( '_'+a[0] , 'TTW' , areg , theSystUp , theSystDown )
## 
##     else:
##         theSystUp = multi_full_diff( ttW_files , [['ttW','ttWjI'],['ttW','ttWj','ttWjjI']] , areg , ttW_xsecDict , norm_reg )
##         for a in [['SU','SD'],['AU','AD'],['MF','LF'],['XU','XD']]:
##             a_diff = multi_half_diff( ttW_files , [['ttW_'+a[0],'ttWjE_'+a[0],'ttWjjI_'+a[0]],['ttW_'+a[1],'ttWjE_'+a[1],'ttWjjI_'+a[1]]] , areg , ttW_xsecDict , norm_reg )
##             theSystUp[i] = max( abs(theSystUp[i]),abs(a_diff[i]),abs(1./theSystUp[i]),abs(1./a_diff[i]) )
##         theSystDown = [] 
##         for t in theSystUp: 
##             if t>1: theSystDown += [1./t] 
##             else: theSystDown += [ 2.-t] 
##         systematics.check_and_add( '_Envelope' , 'TTW' , areg , theSystUp , theSystDown )
## 
    # Single top systematic uncertainties
    norm_reg = 'CR_TOP'
    if not AllMerged:

##         # Parton shower - symmetrized
##         theSystUp = full_diff( st_files , [3,5] , areg , norm_reg )
##         theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
##         systematics.check_and_add( '_PartonShower' , 'ST' , areg , theSystUp , theSystDown )

        # DR vs DS - not symmetrized
        theSystUp = full_diff( st_files , [5,6] , areg , norm_reg )
        theSystDown = [1.]*len(theSystUp)
        systematics.check_and_add( '_DiagramSubtr' , 'ST' , areg , theSystUp , theSystDown )

##         # MC generator - MC@NLO+Jimmy vs Powheg+Jimmy symmetrized
##         theSystUp = full_diff( st_files , [2,7] , areg , norm_reg )
##         theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
##         systematics.check_and_add( '_Generator' , 'ST' , areg , theSystUp , theSystDown )

        # ISR/FSR - half sym
        theSystUp = half_diff( st_files , [9,10] , areg , norm_reg )
        theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
        systematics.check_and_add( '_ISRFSR' , 'ST' , areg , theSystUp , theSystDown )

    else:

        # ISR/FSR - half sym
        theSystUp = half_diff( st_files , [9,10] , areg , norm_reg )

##         # Parton shower and MC generator
##         for n,s in enumerate( [ [3,5],[2,7] ] ):
##             a_diff = full_diff( st_files , s , areg , norm_reg )
##             theSystUp[i] = max( abs(theSystUp[i]),abs(a_diff[i]),abs(1./theSystUp[i]),abs(1./a_diff[i]) )
##             #theSystUp = [ max( abs(theSystUp[i]),abs(a_diff[i]),abs(1./theSystUp[i]),abs(1./a_diff[i]) ) for i in xrange(len(theSystUp)) ]

        theSystDown = []
        for t in theSystUp:
            if t>1: theSystDown += [1./t]
            else: theSystDown += [ 2.-t]

        # DR vs DS - not symmetrized
        a_diff = full_diff( st_files , [5,6] , areg , norm_reg )
        for n,x in enumerate(a_diff):
            if x>1:
                if theSystUp[n]>1: theSystUp[n] = max( theSystUp[n] , x )
                else:              theSystDown[n] = max( theSystDown[n] , x )
            else:
                if theSystUp[n]<1: theSystUp[n] = min( theSystUp[n] , x )
                else:              theSystDown[n] = min( theSystDown[n] , x )

        systematics.check_and_add( '_Envelope' , 'ST' , areg , theSystUp , theSystDown )

    # ttbar systematic uncertainties
    norm_reg = 'CR_TOP'
    if not AllMerged:
        # ISR/FSR , renormalization scale , factorization scale - half sym
        theSystUp = half_diff( ttbar_files , [0,1] , areg , norm_reg )
        theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
        systematics.check_and_add( '_ISRFSR' , 'Top' , areg , theSystUp , theSystDown )

        theSystUp = half_diff( ttbar_files , [3,5] , areg , norm_reg )
        theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
        systematics.check_and_add( '_RScales' , 'Top' , areg , theSystUp , theSystDown )

        theSystUp = half_diff( ttbar_files , [2,4] , areg , norm_reg )
        theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
        systematics.check_and_add( '_FScales' , 'Top' , areg , theSystUp , theSystDown )

    else:
        # ISR/FSR - half sym
        theSystUp = half_diff( ttbar_files , [0,1] , areg , norm_reg )
        # Scale variations
        for n,s in enumerate( [ [2,4],[3,5] ] ):
            a_diff = full_diff( ttbar_files , s , areg , norm_reg )
            for  i in xrange(len(theSystUp)):
                theSystUp[i] = max(abs(theSystUp[i]),
                                   abs(a_diff[i]),
                                   abs(1./theSystUp[i]),
                                   abs(1./a_diff[i]))

        theSystDown = []
        for t in theSystUp:
            if t>1: theSystDown += [1./t]
            else: theSystDown += [ 2.-t]

        systematics.check_and_add( '_Envelope' , 'Top' , areg , theSystUp , theSystDown )

    theSystUp = full_diff( ttbar_files , [6,7] , areg , norm_reg )
    theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
    systematics.check_and_add( '_PartonShower' , 'Top' , areg , theSystUp , theSystDown )

    # theSystUp = multi_full_diff( alpgen_files , [['AlpgenTTbarNp0','AlpgenTTbarNp1','AlpgenTTbarNp2','AlpgenTTbarNp3p'],['ttbar_PowhegJimmy']] , areg , alpgen_ttbar , norm_reg )
    # theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
    # systematics.check_and_add( '_multiParton' , 'Top' , areg , theSystUp , theSystDown )

    # Z systematics
    #if not BigNorm: For Z and ttbar we always do it this way
    norm_reg = 'CR_Z'
    theSystUp = multi_full_diff( Z_files , [['Zee_4jets','Zmm_4jets'],
                                            ['Zee_4jetsOnly','Zmm_4jetsOnly']],
                                            areg , Z_xsecDict , norm_reg )
    theSystDown = [ ((1./t) if t>1. else (2.-t)) for t in theSystUp ]
    systematics.check_and_add( '_multiParton' , 'ZX' , areg , theSystUp , theSystDown )

systematics.Print()

