################################################################
## In principle all you have to setup is defined in this file ##
################################################################
from configManager import configMgr
from ROOT import kBlack,kWhite,kGray,kRed,kPink,kMagenta,kViolet,kBlue,kAzure,kCyan,kTeal,kGreen,kSpring,kYellow,kOrange
from systematic import Systematic
from math import sqrt
import os,sys,copy

from sample import Sample
from channel import Channel
from measurement import Measurement
from fitConfig import fitConfig

# Setup for ATLAS plotting
from ROOT import gROOT
gROOT.LoadMacro("./macros/AtlasStyle.C")
import ROOT
ROOT.SetAtlasStyle()
gROOT.SetBatch(True)

# Make things much quieter
gROOT.ProcessLine("gErrorIgnoreLevel=10001;")
#ROOT.RooMsgService.instance().setGlobalKillBelow(ROOT.RooFit.FATAL)
ROOT.Math.MinimizerOptions.SetDefaultMinimizer("Minuit2")

##########################
doExclusion = True
doDiscovery = False

verbose = False
minCutOffExp = 2
minCutOffObs = 0.5
allowSignalContamination = True  # Test will set this to false!!

if not 'skip_unc' in dir():
    skip_unc = ['CLOSEBY']
if not 'reduced_unc' in dir():
    reduced_unc = {}

# Group backgrounds
bgGroups = {'TOP':['ttbar','st'],'Zhf':['Zhf']}
crGroups = {
        # 'CR1':['CR']
           }

# define signal samples
sigSamples=["202641"]

# Colors for drawing
someColors = [kGreen-9,kAzure+1,kBlue+3,kWhite,kOrange,kRed,kYellow,kGray+1]

# Give the analysis a name
if not 'asetup' in dir():
    print 'Using default setup, 50GeV'
    asetup = '50GeV'

configMgr.analysisName = "SampleExcl"+asetup.replace('.','_')
configMgr.outputFileName = "results/%s_Output.root"%configMgr.analysisName
#configMgr.blindCR = True

# Samples to give mu parameters to (note: Top is remapped later to ttbar)
mu_samples = ['TOP']

## Use the histogram input generated already
try:
    os.mkdir('data/'+configMgr.analysisName)
except:
    pass
try:
    os.mkdir('results/'+configMgr.analysisName)
except:
    pass
setName = ''
if 'sigSamples' in dir():
    # Figure out which sample we are dealing with
    setList = open('python/SampleSignalInput.txt', 'r')
    setName = None
    for aline in setList.readlines():
        if str(sigSamples[0])==str(aline.split()[0]):
            setName = aline.split()[1]
            break
    setList.close()
    if setName is None:
        setName=sigSamples[0]

    configMgr.histCacheFile = "data/"+configMgr.analysisName+"/histCache"+str(setName)+".root"
    configMgr.outputFileName = "results/"+configMgr.analysisName+"/Output"+str(setName)+".root"
else:
    configMgr.histCacheFile = "data/"+configMgr.analysisName+"/histCache.root"
    configMgr.outputFileName = "results/"+configMgr.analysisName+"/Output.root"


if 'Test'==asetup:
    print 'Found test setup - will turn off signal contamination in the CRs'
    allowSignalContamination = False
    asetup = '50GeV'

# Setting the parameters of the hypothesis test
configMgr.nTOYs=1000
configMgr.calculatorType=2 #0 # grump grump grump # 2=asymptotic calculator, 0=frequentist calculator
configMgr.testStatType=3   # 3=one-sided profile likelihood test statistic (LHC default)
configMgr.nPoints=20       # number of values scanned of signal-strength for upper-limit determination of signal strength.
##########################

# Set observed and expected number of events in counting experiment
lumiError = 0.036           # Relative luminosity uncertainty
configMgr.weights = "1."    # Dummy weights
configMgr.inputLumi = 0.001 # Luminosity of input TTree after weighting
configMgr.outputLumi = 20.3 # Luminosity required for output histograms
configMgr.setLumiUnits("fb-1")
configMgr.fixSigXSec=True  # fix SigXSec: 0, +/-1sigma

if doDiscovery and doExclusion:
    print 'You should turn off either discovery or exclusion!'
    sys.exit(1)

# List of regions to reject
region_rej = []

inputFile = open('python/SampleBackgroundInput.txt', 'r')

regions = []
backgrounds = {} # Background format:  Name : [ [Nominal],[AfterUnc1],[AfterUnc2]...]
uncertainties = {}

# Add a line length check to ensure that we're getting the right number of items in!!

for aline in inputFile.readlines():
    # skip blank line
    if len( aline.strip() )<2: continue

    if 'name of column' in aline.lower():
        # get regions from file header
        if 'sample' in aline.lower(): regions = [ x.strip() for x in aline.split(',')[3:] ]
        else: regions = [ x.strip() for x in aline.split(',')[2:] ]
        if verbose: print 'Found regions',regions
    elif aline.strip().startswith('#'):
        # skip comments
        continue # This was a comment...
    elif aline.strip().lower().startswith('nominal'):
        # Nominal background prediction...
        bg = aline.split(',')[1].strip()
        if bg.lower()=='data': bg='Data'
        if bg in backgrounds and len(backgrounds[0])>0:
            print 'Found second nominal prediction for background',bg,'- will replace the old one.'
        else:
            backgrounds[bg] = [ [] ]
            for a in uncertainties: backgrounds[bg] += [ [] ]
        backgrounds[bg][0] = [ float(x) for x in aline.split(',')[2:] ]
        for x in xrange(len(backgrounds[bg][0])):
            if backgrounds[bg][0][x]<0. and bg.lower()!='data':
                print 'Warning: for background',bg,'region',x,'had to set the nominal to positive from',backgrounds[bg][0][x]
                backgrounds[bg][0][x]=0.
        if verbose: print 'For background',bg,'got nominal estimates',backgrounds[bg][0]
    elif aline.strip().lower().startswith('mcstat'):
        # MC statistical uncertainty
        bg = aline.split(',')[1].strip()
        if not bg in backgrounds:
            print 'Reporting MCstat uncertainty for undiscovered sample',bg,'- if file ordering is funny, this is normal'
            backgrounds[bg] = [ [] ]
            for a in uncertainties: backgrounds[bg] += [ [] ]
        if 'MCstat' not in uncertainties:
            uncertainties['MCstat'] = len(backgrounds[bg])
            for abg in backgrounds: backgrounds[abg] += [ [] ]
        elif len( backgrounds[bg][ uncertainties['MCstat'] ] )>0:
            print 'Sample',bg,'seems to already have MC stats uncertainty.  Will overwrite it.'
        if len( backgrounds[bg][0] )<1:
            backgrounds[bg][ uncertainties['MCstat'] ] = [ float(aline.split(',')[3+i]) for i in xrange(len(aline.split(','))-3) ]
        else:
            backgrounds[bg][ uncertainties['MCstat'] ] = [ float(aline.split(',')[3+i])*backgrounds[bg][0][i] for i in xrange(len(aline.split(','))-3) ]
        if verbose: print 'For background',bg,'got MCstat uncertainty',backgrounds[bg][ uncertainties['MCstat'] ]
    elif aline.strip().lower().startswith('alpha'):
        # Systematic uncertainty
        uncname = aline.split(',')[0].strip().replace('QCD','Multijet')
        bg = aline.split(',')[1].strip()
        if not bg in backgrounds:
            print 'Reporting uncertainty',uncname,'for undiscovered sample',bg,'- if file ordering is funny, this is normal'
            backgrounds[bg] = [ [] ]
            for a in uncertainties: backgrounds[bg] += [ [] ]
        # Handle different methods of providing uncertainties
        unctype = aline.split(',')[2].strip().lower()
        if unctype in ['symrel','symabs']:
            if (uncname+'_UP') not in uncertainties:
                uncertainties[uncname+'_UP'] = len(backgrounds[bg])
                uncertainties[uncname+'_DOWN'] = len(backgrounds[bg])+1
                for abg in backgrounds: backgrounds[abg] += [ [] , [] ]
            elif len( backgrounds[bg][ uncertainties[uncname+'_UP'] ] )>0:
                print 'Sample',bg,'seems to already have uncertainty',uncname,'of type',unctype,'.  Will overwrite it.'
            if unctype=='symabs':
                backgrounds[bg][uncertainties[uncname+'_UP']]   = [ 1.+((float(aline.split(',')[3+i])/backgrounds[bg][0][i]) if backgrounds[bg][0][i]>0 else 0.) for i in xrange(len(aline.split(','))-3) ]
                backgrounds[bg][uncertainties[uncname+'_DOWN']] = [ 1.-((float(aline.split(',')[3+i])/backgrounds[bg][0][i]) if backgrounds[bg][0][i]>0 else 0.) for i in xrange(len(aline.split(','))-3) ]
            elif unctype=='symrel':
                backgrounds[bg][uncertainties[uncname+'_UP']]   = [ (1.+float(aline.split(',')[3+i])) for i in xrange(len(aline.split(','))-3) ]
                backgrounds[bg][uncertainties[uncname+'_DOWN']] = [ (1.-float(aline.split(',')[3+i])) for i in xrange(len(aline.split(','))-3) ]
            if verbose: print 'Reporting',unctype,'uncertainties on bg',bg,'with names',uncname,':',backgrounds[bg][uncertainties[uncname+'_UP']],backgrounds[bg][uncertainties[uncname+'_DOWN']]
            for x in xrange(len(backgrounds[bg][uncertainties[uncname+'_UP']])):
                if backgrounds[bg][uncertainties[uncname+'_UP']][x]<0.0001 and bg.lower()!='data':
                    print 'Warning: for background',bg,'region',x,'unc',uncname,'Up, had to set the nominal to positive from',backgrounds[bg][uncertainties[uncname+'_UP']][x]
                    backgrounds[bg][uncertainties[uncname+'_UP']][x]=0.
                if backgrounds[bg][uncertainties[uncname+'_DOWN']][x]<0.0001 and bg.lower()!='data':
                    print 'Warning: for background',bg,'region',x,'unc',uncname,'Down, had to set the nominal to positive from',backgrounds[bg][uncertainties[uncname+'_DOWN']][x]
                    backgrounds[bg][uncertainties[uncname+'_DOWN']][x]=0.
        elif unctype in ['asymrel','unsymrel','asymabs','unsymabs']:
            if uncname not in uncertainties:
                uncertainties[uncname] = len(backgrounds[bg])
                for abg in backgrounds: backgrounds[abg] += [ [] ]
            elif len( backgrounds[bg][ uncertainties[uncname] ] )>0:
                print 'Sample',bg,'seems to already have uncertainty',uncname,'of type',unctype,'.  Will overwrite it.'
            if unctype in ['asymrel','unsymrel']:
                backgrounds[bg][uncertainties[uncname]] = [ (1.+float(aline.split(',')[3+i])) for i in xrange(len(aline.split(','))-3) ]
                backgrounds[bg][uncertainties[uncname]] = [ (1.+float(aline.split(',')[3+i])) for i in xrange(len(aline.split(','))-3) ]
            elif unctype in ['asymabs','unsymabs']:
                backgrounds[bg][uncertainties[uncname]] = [ 1.+((float(aline.split(',')[3+i])/backgrounds[bg][0][i]) if backgrounds[bg][0][i]>0 else 0.) for i in xrange(len(aline.split(','))-3) ]
                #backgrounds[bg][uncertainties[uncname]] = [ float(aline.split(',')[3+i])+backgrounds[bg][0][i] for i in xrange(len(aline.split(','))-3) ]
            if verbose: print 'Reporting',unctype,'uncertainties on bg',bg,'with names',uncname,':',backgrounds[bg][uncertainties[uncname]]
            for x in xrange(len(backgrounds[bg][uncertainties[uncname]])):
                if backgrounds[bg][uncertainties[uncname]][x]<0.0001 and bg.lower()!='data':
                    print 'Warning: for background',bg,'region',x,'unc',uncname,' had to set the nominal to positive from',backgrounds[bg][uncertainties[uncname]][x]
                    backgrounds[bg][uncertainties[uncname]][x]=0.
        else:
            print 'Unknown uncertainty type:',unctype,'for background',bg,'with name',uncname
    # Bark if I could not parse the line
    else:
        print 'Did not understand this line.  Hope you didnt mean for me to!',aline.strip()

# Check that no nominal predictions are missing
for abg in backgrounds:
    if len(backgrounds[abg][0])<1:
        print 'Did not find a nominal background prediction for background',bg,'- hope you know what youre doing!!'

if len(backgrounds)>len(someColors):
    print 'Do not have enough colors!  Will repeat :-('

bglist = backgrounds.keys()

if len(regions)==0:
    print 'Going through',len(backgrounds[ bglist[0] ]),'regions'
    for i in xrange(len(backgrounds[ bglist[0] ])):
        regions += [ 'UserRegion%i'%i ]
else:
    print 'Going through',len(regions),'regions:',regions

# Group backgrounds
for agroup in bgGroups:
    # Create a holder for each systematic + nominal
    numbers = []
    for aset in xrange(len(backgrounds[ backgrounds.keys()[0] ])):
        numbers += [ [] ]
        for areg in xrange(len(regions)): numbers[-1] += [0]
    # Add together nominals, add fractional uncertainties as total numbers
    for asub in bgGroups[agroup]:
        for aset in xrange(len(backgrounds[asub])):
            if len(backgrounds[asub][aset])>0:
                for anum in xrange(len( backgrounds[asub][aset] )):
                    if aset==0:
                        numbers[aset][anum] += backgrounds[asub][aset][anum]
                    else:
                        numbers[aset][anum] += backgrounds[asub][aset][anum]*backgrounds[asub][0][anum] # Add fractional uncertainties by adding them up and dividing at the end
            else:
                for anum in xrange(len( backgrounds[asub][0] )):
                    if aset==0:
                        print 'Problem! Nominal was zero for',asub,'for combination in',agroup
                    else:
                        numbers[aset][anum] += backgrounds[asub][0][anum] # Add fractional uncertainties by adding them up and dividing at the end
    # Reset uncertainties to be fractional
    for aset in xrange(len(numbers)):
        if aset==0: continue
        for anum in xrange(len( numbers[aset] )):
            numbers[aset][anum] = numbers[aset][anum] / (numbers[0][anum] if numbers[0][anum]>0 else 1.)
    # Move the numbers into place
    backgrounds[agroup] = copy.deepcopy(numbers)
    # Remove the old ones
    for asub in bgGroups[agroup]: 
        if asub not in bgGroups:
            x = backgrounds.pop(asub)
    if verbose: print 'Regrouped backgrounds',bgGroups[agroup],'into',agroup

# A couple of illegal / pain in the a$$ names
if 'QCD' in backgrounds:
    print 'Renaming QCD as Multijets - QCD is not an allowed name!!'
    backgrounds['Multijets'] = backgrounds.pop('QCD')
if 'Top' in backgrounds:
    print 'Renaming Top as ttbar to avoid overlap with SingleTop'
    backgrounds['ttbar'] = backgrounds.pop('Top')

bglist = backgrounds.keys()
print 'Regrouped backgrounds:',bglist

bkt = configMgr.addFitConfig("BkgOnlyFit")
bkt.statErrThreshold=0.05 # From the Higgs guys

meas=bkt.addMeasurement(name="NormalMeasurement",lumi=1.0,lumiErr=0.028)
meas.addParamSetting("Lumi",True,1)
if not doDiscovery:
    meas.addPOI("mu_SIG")
else:
    meas.addPOI('mu_theVRcut')

# Combine CRs and SRs according to groupings
for agrp in crGroups:
    regCount = 0
    for areg in crGroups[agrp]:
        if areg in regions:
            regCount += 1
    if regCount==0:
        print 'Skipping grouping of region',agrp,'from',crGroups[agrp],'as it does not appear in',regions
        continue

    lead_idx = 0
    for i,areg in enumerate( sorted(crGroups[agrp], key=lambda a: regions.index(a) ) ):
        region_rej += [ areg ]
        if i==0:
            lead_idx = regions.index(areg)
    # Loop through all the backgrounds and uncertainties
    for abg in backgrounds:
        for anunc in xrange(len(backgrounds[abg])):
            # Go through all the regions with non-zero length
            if len( backgrounds[abg][anunc] )<1: continue # Empty uncertainty set

            # Two passes.  First change everything that needs to be into an event yield
            for i,areg in enumerate( sorted( [ regions.index(a) for a in crGroups[agrp] ] ) ):
                # Region 0 is untouched - turn it into an event yield if necessary!
                if i==0:
                    if anunc!=0:
                        backgrounds[abg][anunc][areg]=backgrounds[abg][anunc][areg]*backgrounds[abg][0][areg]
                else: # Add the region to region zero (as an event yield if necessary
                    if anunc!=0:
                        backgrounds[abg][anunc][areg]=backgrounds[abg][anunc][areg]*backgrounds[abg][0][areg]

    for abg in backgrounds:
        for anunc in xrange(len(backgrounds[abg])):
            if len( backgrounds[abg][anunc] )<1: continue # Empty uncertainty set
            # Second add things up
            for i,areg in enumerate( sorted( [ regions.index(a) for a in crGroups[agrp] ] ) ):
                # Region 0 is untouched... 
                if i==0: continue
                else: # Add the region to region zero (as an event yield if necessary
                    if anunc == 0:
                        backgrounds[abg][anunc][lead_idx] += backgrounds[abg][anunc][areg]
                    else:
                        backgrounds[abg][anunc][lead_idx] += backgrounds[abg][anunc][areg]
            # Third, normalize if necessary
            if anunc != 0: 
                backgrounds[abg][anunc][lead_idx] /= ( backgrounds[abg][0][lead_idx] if backgrounds[abg][0][lead_idx]>0 else 1.)
            #print 'ZLM2',anunc,(uncertainties.keys()[anunc-1] if anunc>0 else 'Nominal'),abg,backgrounds[abg][anunc]
    for i,areg in enumerate( sorted(crGroups[agrp], key=lambda a: regions.index(a) ) ):
        regions[ lead_idx ] = agrp
        break

if len(crGroups)>0:
    print 'Will skip regions',region_rej,'after combining into regions according to',crGroups

# Preliminary numbers
numbers = []
for aset in xrange(len(backgrounds[ backgrounds.keys()[0] ])):
    numbers += [ [] ]
    for areg in xrange(len(regions)):
        numbers[-1] += [0]

for abg in backgrounds:
    if 'data' in abg.lower(): continue
    for areg in xrange(len(regions)):
        numbers[0][areg] += backgrounds[abg][0][areg]

# Recalculate numbers
numbers = []
for aset in xrange(len(backgrounds[ backgrounds.keys()[0] ])):
    numbers += [ [] ]
    for areg in xrange(len(regions)):
        numbers[-1] += [0]

for abg in backgrounds:
    if 'data' in abg.lower(): continue
    for areg in xrange(len(regions)):
        numbers[0][areg] += backgrounds[abg][0][areg]

# Make sure we have some data
if not 'Data' in backgrounds:
    print 'Did not find any data.  Will fake it.'
    theData = []
    for aset in numbers:
        theData += [ [] ]
        for i in xrange(len(aset)):
            theData[-1] += [ int( aset[i] ) ]
    backgrounds['Data']=theData
    bglist += ['Data']

for areg in xrange(len(regions)):
    if numbers[0][areg]==0 or (numbers[0][areg]<minCutOffExp and 'CR' in regions[areg]) or (backgrounds['Data'][0][areg]<minCutOffObs and minCutOffObs>0):
        print numbers[0][areg],'entries in region',regions[areg],'and',backgrounds['Data'][0][areg],'obs with cuts of',minCutOffExp,'and',minCutOffObs,'- will remove from fit'
        region_rej += [ regions[areg] ]

print 'Sorted configuration...'
for a in sorted(bglist):
    print '   ',a,backgrounds[a]

# Sort out which regions are constraint regions and which are signal regions!  For now this is hacky...
constraints = []
validations = []
for areg in xrange(len(regions)):
    if regions[areg] in region_rej: continue # No stats!!
    if 'UserRegion' in regions[areg]:
        print 'Warning: for region',regions[areg],'I dont know if this is control or signal.  Treating it as control'
        constraints += [ regions[areg] ]
    elif 'CR' not in regions[areg]:
        if verbose: print 'Adding region',regions[areg],'as a validation region'
        validations += [ regions[areg] ]
    else:
        if verbose: print 'Adding region',regions[areg],'as a control region'
        constraints += [ regions[areg] ]

if len(constraints)>0:
    configMgr.cutsDict['theCRcut'] = '1.'
    constraintReg = [ bkt.addChannel( 'theCR' , ['theCRcut'] , len(constraints) , 0.5 , len(constraints)+0.5 ) ]
    #constraintReg[0].showLumi = True
    constraintReg[0].titleX = 'Control Region'
    constraintReg[0].titleY = 'Number of Events'
    constraintReg[0].logY = True
    constraintReg[0].minY = 0.5
    constraintReg[0].maxY = 300.
    bkt.setBkgConstrainChannels(constraintReg)

if len(validations)>0:
    configMgr.cutsDict['theVRcut'] = '1.'

    if doDiscovery:
        validationReg = [ bkt.addChannel( 'cuts'  , ['theVRcut'] , len(validations) , 0.5 , len(validations)+0.5 ) ]
    else:
        validationReg = [ bkt.addChannel( 'theVR' , ['theVRcut'] , len(validations) , 0.5 , len(validations)+0.5 ) ]
    #validationReg[0].showLumi = True
    validationReg[0].titleX = 'Signal Region'
    validationReg[0].titleY = 'Number of Events'
    validationReg[0].logY = True
    validationReg[0].minY = 0.5
    validationReg[0].maxY = 200.
    bkt.setValidationChannels(validationReg)

# Have added all the channels... Now let's add the histograms :-)
# Construct samples from the background number lists
samples = []
for i in xrange(len(bglist)):
    bg = bglist[i]
    abg = backgrounds[ bg ]
    if bg.lower()=='data':
        print 'Now adding data...'
        asamp = Sample( bg , kBlack )
        asamp.setData()
    else:
        asamp = Sample( bg , someColors[i%(len(someColors))] )
        asamp.setStatConfig(True)
        # Add a norm factor if requested
        if bg in mu_samples:
            # TODO set this norm factor to something applicable to us
            asamp.setNormFactor('mu_'+bg,1.,0.,5.)
            if 'Top'==bg and 'GeV' not in asetup and 'Test' not in asetup:
                asamp.setNormRegions([('theCR','theCRcut')])
        else:
            asamp.setNormByTheory()
    # Two histograms: one for control regions, one for signal regions.
    CRvals = []
    CRstat = []
    VRvals = []
    VRstat = []
    for areg in xrange(len(regions)):
        if regions[areg] in constraints:
            CRvals += [ abg[0][areg] ]
            if 'MCstat' in uncertainties and bg.lower() != 'data' and len(abg[ uncertainties['MCstat'] ]) > 0:
                CRstat += [ abg[ uncertainties['MCstat'] ][areg] ]
            else:
                CRstat += [0.]
        elif regions[areg] in validations:
            VRvals += [ abg[0][areg] ]
            if 'MCstat' in uncertainties and bg.lower() != 'data' and len(abg[ uncertainties['MCstat'] ]) > 0:
                VRstat += [ abg[ uncertainties['MCstat'] ][areg] ]
            else:
                VRstat += [0.]

    # Build standard histograms
    if len(constraints)>0:
        asamp.buildHisto( CRvals , 'theCRcut' , 'theCR' )
    if len(validations)>0:
        if doDiscovery: asamp.buildHisto( VRvals , 'theVRcut' , 'cuts' )
        else:           asamp.buildHisto( VRvals , 'theVRcut' , 'theVR' )

    if len(CRstat)>0:
        if len(constraints)>0:
            asamp.buildStatErrors( CRstat , 'theCRcut' , 'theCR' )
        if len(validations)>0:
            if doDiscovery:
                asamp.buildStatErrors( VRstat , 'theVRcut' , 'cuts' )
            else:
                asamp.buildStatErrors( VRstat , 'theVRcut' , 'theVR' )
        if verbose: print 'Built region',regions[areg],'with statistical uncertainties for bg',bg
    elif bglist[i].lower()!='data':
        if verbose: print 'Built region',regions[areg],'without statistical uncertainties for bg',bg
    else:
        if verbose: print 'Built region',regions[areg],'for data'

    # Add sample to the list
    samples += [ asamp ]

bkt.addSamples(samples)

# Finally, take care of systematics - this is the tricky bit
unc_name_list = []
for abg in backgrounds:
    # No systematics on data
    if abg.lower()=='data': continue

    used_systs=[]

    for asyst in uncertainties:
        if asyst in used_systs: continue
        # is this high or low?
        if asyst.lower().endswith('up'):
            upper = asyst
            lower = asyst[:-2]+'down'
            for as2 in uncertainties:
                if lower.lower()==as2.lower():
                    lower=as2
                    break
        elif asyst.lower().endswith('down'):
            lower = asyst
            upper = asyst[:-4]+'up'
            for as2 in uncertainties:
                if upper.lower()==as2.lower():
                    upper=as2
                    break
        elif asyst.lower()!='mcstat':
            print 'Did not understand uncertainty name:',asyst
        else: continue
        if verbose: print 'Building uncertainty for names',upper,lower,'sample',abg
        baseUncName=upper[:-2].replace('alpha_','')
        if baseUncName[-1]=='_':
            baseUncName=upper[:-3].replace('alpha_','')

        if baseUncName not in unc_name_list:
            unc_name_list += [ baseUncName ]
        if baseUncName in skip_unc: continue

        modifier=1.0
        if baseUncName in reduced_unc:
            modifier=reduced_unc[baseUncName] #0.5

        # Two histograms: one for control regions, one for signal regions.
        CRupper = []
        CRlower = []
        VRupper = []
        VRlower = []

        useThis = False
        for areg in xrange(len(regions)):
            if len(backgrounds[abg][uncertainties[lower] ])>0 and abs(1.-backgrounds[abg][uncertainties[lower] ][ areg ])>0.001:
                useThis=True
            if len(backgrounds[abg][uncertainties[upper] ])>0 and abs(1.-backgrounds[abg][uncertainties[upper] ][ areg ])>0.001:
                useThis=True
        if not useThis: 
            print 'Skipping uncertainty',lower,'and',upper,'on sample',abg
            used_systs += [ upper , lower ]
            continue

        for areg in xrange(len(regions)):
            if regions[areg] in constraints:
                if len(backgrounds[abg][uncertainties[lower] ])>0:
                    CRlower += [ 1.-modifier*(1.-backgrounds[abg][uncertainties[lower] ][ areg ]) ]
                if len(backgrounds[abg][uncertainties[upper] ])>0:
                    CRupper += [ 1.+modifier*(backgrounds[abg][uncertainties[upper] ][ areg ]-1.) ]
            elif regions[areg] in validations:
                if len(backgrounds[abg][uncertainties[lower] ])>0:
                    VRlower += [ 1.-modifier*(1.-backgrounds[abg][uncertainties[lower] ][ areg ]) ]
                if len(backgrounds[abg][uncertainties[upper] ])>0:
                    VRupper += [ 1.+modifier*(backgrounds[abg][uncertainties[upper] ][ areg ]-1.) ]

        if len(CRupper)+len(VRupper)>0 and len(CRlower)+len(VRlower)>0:

            if baseUncName in ['JES','CLOSEBY'] and 'GeV' not in asetup and 'Test' not in asetup: # or (asetup=='50GeV' and baseUncName=='SCALEST'):
                if len(constraints)>0:
                    constraintReg[0].getSample(abg).addSystematic( Systematic( baseUncName,configMgr.weights, CRupper , CRlower , 'user' , 'overallNormHistoSys') ) #'userHistoSys') )
                if len(validations)>0:
                    validationReg[0].getSample(abg).addSystematic( Systematic( baseUncName,configMgr.weights, VRupper , VRlower , 'user' , 'overallNormHistoSys') ) #'userHistoSys') )
            elif baseUncName in ['STtheoryInterference']:
                if len(constraints)>0:
                    constraintReg[0].getSample(abg).addSystematic( Systematic( baseUncName,configMgr.weights, CRlower , CRlower , 'user' , 'histoSysOneSide') )
                if len(validations)>0:
                    validationReg[0].getSample(abg).addSystematic( Systematic( baseUncName,configMgr.weights, VRlower , VRlower , 'user' , 'histoSysOneSide') )
            elif baseUncName in ['JER']:
                if len(constraints)>0:
                    constraintReg[0].getSample(abg).addSystematic( Systematic( baseUncName,configMgr.weights, CRlower , CRlower , 'user' , 'histoSysOneSideSym') )
                if len(validations)>0:
                    validationReg[0].getSample(abg).addSystematic( Systematic( baseUncName,configMgr.weights, VRlower , VRlower , 'user' , 'histoSysOneSideSym') )
            else:
                if len(constraints)>0:
                    constraintReg[0].getSample(abg).addSystematic( Systematic( baseUncName,configMgr.weights, CRupper , CRlower , 'user' , 'userHistoSys') )
                if len(validations)>0:
                    validationReg[0].getSample(abg).addSystematic( Systematic( baseUncName,configMgr.weights, VRupper , VRlower , 'user' , 'userHistoSys') )

            used_systs += [ upper , lower ]
        elif len(CRupper)+len(VRupper)>0:
            print 'Upper uncertainty only on',upper,lower,abg,regions[areg]
        elif len(CRlower)+len(VRlower)>0:
            print 'Lower uncertainty only on',upper,lower,abg,regions[areg]

print 'Added uncertainties:', unc_name_list
print 'From list',asyst

print bkt

################### Discovery fits (MSUGRA grid) ##################
if doDiscovery:
    discovery = configMgr.addFitConfigClone(bkt,"Discovery")
    signalregions= [ bkt.getChannel('cuts',['theVRcut']) ]
    iPop = bkt.validationChannels.index('theVRcut_cuts')
    discovery.validationChannels.pop(iPop)
    signalregions[-1].useOverflowBin=True
    signalregions[-1].addDiscoverySamples(['theVRcut'],[1.],[0.],[100.],[kMagenta])
    discovery.setSignalChannels( signalregions )
    #meas.addPOI('mu_theVRcut')

################### Exclusion fits (MSUGRA grid) ##################
print 'about do to exclusion'
print dir()
if doExclusion and 'sigSamples' in dir():
    print 'doing exclusion!'
    print 'sig samples: %s' % sigSamples
    for sig in sigSamples:
        print 'sig: %s' % sig
        # New top level cfg
        myTopLvl = configMgr.addFitConfigClone(bkt,"Sig_%s"%sig)

        # # Figure out which sample we are dealing with
        # setList = open('/afs/cern.ch/atlas/project/cern/susy2/SPyRoot/susy12a_razor_p1328/HistFitter/data/MJ_datasets.txt','r')
        # setName = None
        # for aline in setList.readlines():
        #     if str(sig)==str(aline.split()[0]):
        #         setName = aline.split()[1]
        #         break
        # if setName is None:
        #     print 'ERROR: Could not decode sample',sig
        #     continue

        # print 'Decoded name',setName,'from number',sig

        # # XSec and uncertainty
        # xsec = 0.
        # xunc = 0.
        # if 'Gtt_' in setName:
        #     xsf = ROOT.TFile.Open('/afs/cern.ch/atlas/groups/susy/SignalCrossSectionsUncert/GluinoMediatedAndSbottom/8TeV/susy_Gtt_8TeV.root')
        #     xst = xsf.Get('SignalUncertainties')
        #     for a in xrange(xst.GetEntries()):
        #         blah = xst.GetEntry(a)
        #         if xst.G==int(setName.split('Gtt_G')[1].split('_')[0]):
        #             xsec = xst.crossSection
        #             xunc = xst.crossSection * xst.Tot_error
        #             break
        #     xsf.Close()
        # elif 'RPVg_' in setName:
        #     xsf = ROOT.TFile.Open('/afs/cern.ch/atlas/groups/susy/SignalCrossSectionsUncert/SimplModels/SignalUncertainties-SM_GG_direct_mc12.root')
        #     xst = xsf.Get('SignalUncertainties')
        #     xsec=-1.
        #     lowx = 0.
        #     lowm = 0.
        #     lowu = 0.
        #     hix = 0.
        #     him = 100000.
        #     hiu = 0.
        #     for a in xrange(xst.GetEntries()):
        #         blah = xst.GetEntry(a)
        #         if xst.mgluino==int(setName.split('_')[1]):
        #             xsec = xst.crossSection
        #             xunc = xst.crossSection * xst.Tot_error
        #             break
        #         if xst.mgluino>lowm and xst.mgluino<int(setName.split('_')[1]):
        #             lowm=xst.mgluino
        #             lowx=xst.crossSection
        #             lowu=xst.crossSection * xst.Tot_error
        #         if xst.mgluino<him and xst.mgluino>int(setName.split('_')[1]):
        #             him=xst.mgluino
        #             hix=xst.crossSection
        #             hiu=xst.crossSection * xst.Tot_error
        #     xsf.Close()
        #     if xsec<0.:
        #         xsec = (hix-lowx)/(him-lowm)*(int(setName.split('_')[1])-lowm)+lowx
        #         xunc = (hiu-lowu)/(him-lowm)*(int(setName.split('_')[1])-lowm)+lowu
        #         print 'ZLM Using linear interpolation for xsec uncertainty...'
        # elif 'GttOnShell_' in setName:
        #     xsf = ROOT.TFile.Open('/afs/cern.ch/atlas/groups/susy/SignalCrossSectionsUncert/GluinoMediatedAndSbottom/8TeV/susy_GluinoStop_8TeV.root')
        #     xst = xsf.Get('SignalUncertainties')
        #     for a in xrange(xst.GetEntries()):
        #         blah = xst.GetEntry(a)
        #         if xst.G==int(setName.split('GttOnShell_G')[1].split('_')[0]): # and xst.T==int(setName.split('_T')[1].split('_')[0]):
        #             xsec = xst.crossSection
        #             xunc = xst.crossSection * xst.Tot_error
        #             break
        #     xsf.Close()
        # elif 'GG_onestepCC' in setName:
        #     if int(setName.split('_')[3])<=1200: xsf = ROOT.TFile.Open('/afs/cern.ch/atlas/groups/susy/SignalCrossSectionsUncert/SimplModels/SignalUncertainties-SM_GG_onestep_mc12.root')
        #     else:                                xsf = ROOT.TFile.Open('/afs/cern.ch/atlas/groups/susy/SignalCrossSectionsUncert/SimplModels/SignalUncertainties-SM_GG_onestep_extension_mc12.root')
        #     xst = xsf.Get('SignalUncertainties')
        #     for a in xrange(xst.GetEntries()):
        #         blah = xst.GetEntry(a)
        #         if xst.mgluino==int(setName.split('_')[3]):
        #             xsec = xst.crossSection
        #             xunc = xst.crossSection * xst.Tot_error
        #             break
        #     xsf.Close()
        # elif 'SMGG2WWZZ' in setName: # needs checking
        #     xsf = ROOT.TFile.Open('/afs/cern.ch/atlas/groups/susy/SignalCrossSectionsUncert/SimplModels/SignalUncertainties-SM_GG_twostep_WWZZ_mc12.root')
        #     xst = xsf.Get('SignalUncertainties')
        #     for a in xrange(xst.GetEntries()):
        #         blah = xst.GetEntry(a)
        #         if xst.mgluino==int(setName.split('_')[1]):
        #             xsec = xst.crossSection
        #             xunc = xst.crossSection * xst.Tot_error 
        #             break
        #     xsf.Close()

        # if xsec>0: xunc = xunc/xsec
        # print 'For signal sample',setName,'found xsec',xsec,'and unc',xunc

        # # Not the best to be copy-pasting so much code, but this seems like a better move when I'm tired.
        # # Get out the nominal and uncertainties for the signal

        # if asetup=='50GeV' or 'Test' in asetup:
        #     filelist = [ 'bjetStream_SRnumbers/GttOnShell_50GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/Gtt_50GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/MSUGRA_50GeV_newLumi_stat.txt',

        #                  'bjetStream_SRnumbers/OneStepL60_50GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/OneStepX12_50GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/TwoStep_50GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/Sgluon_50GeV_newLumi_AFII.txt',

        #                  #'bjetStream_SRnumbers/OneStepL60_50GeV_newLumi_stat.txt',
        #                  #'bjetStream_SRnumbers/OneStepX12_50GeV_newLumi_stat.txt',
        #                  #'bjetStream_SRnumbers/RPVUDD_50GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/RPVUDDExt_50GeV_newLumi.txt',
        #                  'bjetStream_SRnumbers/bRPV_50GeV_newLumi_stat.txt',

        #                  'bjetStream_SRnumbers/RhadqqFull_50GeV_newLumi_noOverlap.txt',
        #                  'bjetStream_SRnumbers/RhadttFull_50GeV_newLumi_s1978_noOverlap.txt',
        #                ]
        # elif asetup=='80GeV':
        #     filelist = [ 'bjetStream_SRnumbers/GttOnShell_80GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/Gtt_80GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/MSUGRA_80GeV_newLumi_stat.txt',

        #                  'bjetStream_SRnumbers/OneStepL60_80GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/OneStepX12_80GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/TwoStep_80GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/Sgluon_80GeV_newLumi_AFII.txt',

        #                  #'bjetStream_SRnumbers/OneStepL60_80GeV_newLumi_stat.txt',
        #                  #'bjetStream_SRnumbers/OneStepX12_80GeV_newLumi_stat.txt',
        #                  #'bjetStream_SRnumbers/RPVUDD_80GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/RPVUDDExt_80GeV_newLumi.txt',
        #                  'bjetStream_SRnumbers/bRPV_80GeV_newLumi_stat.txt',

        #                  'bjetStream_SRnumbers/RhadqqFull_80GeV_newLumi_noOverlap.txt',
        #                  'bjetStream_SRnumbers/RhadttFull_80GeV_newLumi_s1978_noOverlap.txt',
        #                ]
        # elif 'MJ' in asetup:
        #     filelist = [ 'MultiJet_MJ2/'+asetup+'.Gtt.txt',
        #                  'MultiJet_MJ2/'+asetup+'.GttOnShell.txt',
        #                  'MultiJet_MJ2/'+asetup+'.MSUGRA.txt',
        #                  'MultiJet_MJ2/'+asetup+'.RPVUDD_StopGluino.txt',
        #                  'MultiJet_MJ2/'+asetup+'.bRPV_mSUGRA.txt',
        #                  'MultiJet_MJ2/'+asetup+'.GG2WWZZ.txt',
        #                  'MultiJet_MJ2/'+asetup+'.sglsgl_2ttbar.txt',
        #                  'MultiJet_MJ2/'+asetup+'.GGoneStepLSP60.txt',
        #                  'MultiJet_MJ2/'+asetup+'.GGoneStepX12.txt', ]
        # elif asetup=='50GeVJES':
        #     filelist = [ 'bjetStream_SRnumbers/Gtt_50GeV_newLumi_JEScomponents.txt' ] #
        # elif asetup=='80GeVJES':
        #     filelist = [ 'bjetStream_SRnumbers/Gtt_80GeV_newLumi_JEScomponents.txt' ] #
        # elif '50' in asetup:
        #     filelist = [ 'bjetStream_SRnumbers/GttOnShell_50GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/Gtt_50GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/MSUGRA_50GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/Sgluon_50GeV_newLumi_AFII.txt',

        #                  'bjetStream_SRnumbers/OneStepL60_50GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/OneStepX12_50GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/TwoStep_50GeV_newLumi_AFII.txt',

        #                  #'bjetStream_SRnumbers/OneStepL60_50GeV_newLumi_stat.txt',
        #                  #'bjetStream_SRnumbers/OneStepX12_50GeV_newLumi_stat.txt',
        #                  #'bjetStream_SRnumbers/RPVUDD_50GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/RPVUDDExt_50GeV_newLumi.txt',
        #                  'bjetStream_SRnumbers/bRPV_50GeV_newLumi_stat.txt',]
        # elif '80' in asetup:
        #     filelist = [ 'bjetStream_SRnumbers/GttOnShell_80GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/Gtt_80GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/MSUGRA_80GeV_newLumi_stat.txt',

        #                  'bjetStream_SRnumbers/OneStepL60_80GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/OneStepX12_80GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/TwoStep_80GeV_newLumi_AFII.txt',
        #                  'bjetStream_SRnumbers/Sgluon_80GeV_newLumi_AFII.txt',

        #                  #'bjetStream_SRnumbers/OneStepL60_80GeV_newLumi_stat.txt',
        #                  #'bjetStream_SRnumbers/OneStepX12_80GeV_newLumi_stat.txt',
        #                  #'bjetStream_SRnumbers/RPVUDD_80GeV_newLumi_stat.txt',
        #                  'bjetStream_SRnumbers/RPVUDDExt_80GeV_newLumi.txt',
        #                  'bjetStream_SRnumbers/bRPV_80GeV_newLumi_stat.txt',]

        # sigNumbers = [ ]
        # xunc_as_hist=False

        # for afile in filelist:
        #     moreInput = open('/afs/cern.ch/atlas/project/cern/susy2/SPyRoot/susy12a_razor_p1328/HistFitter/input_root_files/'+afile,'r')
        #     for aline in moreInput.readlines():
        #         if len( aline.strip() )<2:
        #             continue # ~blank line 
        #         elif aline.strip().startswith('#'):
        #             continue # This was a comment...
        #         elif aline.split(',')<2 or aline.split(',')[1].strip()!=sig:
        #             continue # Malformed line or not the signal sample we want
        #         elif aline.strip().lower().startswith('nominal'):
        #             # Nominal background prediction...
        #             if len(sigNumbers)<1:
        #                 sigNumbers = [ [] ]
        #                 for a in uncertainties: sigNumbers += [ [] ]
        #             elif len(sigNumbers[0])>0:
        #                 print 'Found a second nominal signal prediction... troubling!!'
        #             #if 'MultiJet_MJ2' in afile and ('MSUGRA' in afile or 'bRPV_MSUGRA' in afile or 'RPVUDD' in afile): # Buggy x-secs from Hernan
        #             #    sigNumbers[0] = [ float(x)*1000. for x in aline.split(',')[2:] ]
        #             #else:
        #             sigNumbers[0] = [ float(x) for x in aline.split(',')[2:] ]
        #             if verbose: print 'For signal got nominal estimates',sigNumbers[0]
        #         elif aline.strip().lower().startswith('mcstat'):
        #             # MC statistical uncertainty
        #             if len(sigNumbers)<1:
        #                 print 'Reporting MCstat uncertainty for undiscovered signal - if file ordering is funny, this is normal'
        #                 sigNumbers = [ [] ]
        #                 for a in uncertainties: sigNumbers += [ [] ]
        #             if 'MCstat' not in uncertainties:
        #                 uncertainties['MCstat'] = len(sigNumbers)
        #                 sigNumbers += [ [] ]
        #             elif len( sigNumbers[ uncertainties['MCstat'] ] )>0:
        #                 print 'Signal seems to already have MC stats uncertainty.  Will overwrite it.'
        #             if len( sigNumbers[0] )<1:
        #                 sigNumbers[ uncertainties['MCstat'] ] = [ float(aline.split(',')[3+i]) for i in xrange(len(aline.split(','))-3) ]
        #             else:
        #                 sigNumbers[ uncertainties['MCstat'] ] = [ float(aline.split(',')[3+i])*sigNumbers[0][i] for i in xrange(len(aline.split(','))-3) ]
        #             #if verbose: 
        #             print 'For signal got MCstat uncertainty',sigNumbers[ uncertainties['MCstat'] ]
        #         elif aline.strip().lower().startswith('alpha'):
        #             # Systematic uncertainty
        #             if aline.strip().split()[0].lower().startswith('alpha_theory'): xunc_as_hist=True
        #             uncname = aline.split(',')[0].strip().replace('QCD','Multijet')
        #             if len(sigNumbers)<1:
        #                 print 'Reporting uncertainty for undiscovered signal - if file ordering is funny, this is normal'
        #                 sigNumbers = [ [] ]
        #                 for a in uncertainties: sigNumbers += [ [] ]
        #             # Handle different methods of providing uncertainties
        #             unctype = aline.split(',')[2].strip().lower()
        #             if unctype in ['symrel','symabs']:
        #                 if (uncname+'_UP') not in uncertainties:
        #                     uncertainties[uncname+'_UP'] = len(sigNumbers)
        #                     uncertainties[uncname+'_DOWN'] = len(sigNumbers)+1
        #                     sigNumbers += [ [] , [] ]
        #                 elif len( sigNumbers[ uncertainties[uncname+'_UP'] ] )>0:
        #                     print 'Signal seems to already have uncertainty',uncname,'of type',unctype,'.  Will overwrite it.'
        #                 if unctype=='symabs':
        #                     sigNumbers[uncertainties[uncname+'_UP']]   = [ 1.+((float(aline.split(',')[3+i])/sigNumbers[0][i]) if sigNumbers[0][i]>0 else 0.) for i in xrange(len(aline.split(','))-3) ]
        #                     sigNumbers[uncertainties[uncname+'_DOWN']] = [ 1.-((float(aline.split(',')[3+i])/sigNumbers[0][i]) if sigNumbers[0][i]>0 else 0.) for i in xrange(len(aline.split(','))-3) ]
        #                 elif unctype=='symrel':
        #                     sigNumbers[uncertainties[uncname+'_UP']]   = [ (1.+float(aline.split(',')[3+i])) for i in xrange(len(aline.split(','))-3) ]
        #                     sigNumbers[uncertainties[uncname+'_DOWN']] = [ (1.-float(aline.split(',')[3+i])) for i in xrange(len(aline.split(','))-3) ]
        #                 if verbose: print 'Reporting',unctype,'uncertainties on signal with names',uncname,':',sigNumbers[uncertainties[uncname+'_UP']],sigNumbers[uncertainties[uncname+'_DOWN']]
        #             elif unctype in ['asymrel','unsymrel','asymabs','unsymabs']:
        #                 if uncname not in uncertainties:
        #                     uncertainties[uncname] = len(sigNumbers)
        #                     sigNumbers += [ [] ]
        #                 elif len( sigNumbers[ uncertainties[uncname] ] )>0:
        #                     print 'Signal seems to already have uncertainty',uncname,'of type',unctype,'.  Will overwrite it.'
        #                 if unctype in ['asymrel','unsymrel']:
        #                     sigNumbers[uncertainties[uncname]] = [ (1.+float(aline.split(',')[3+i])) for i in xrange(len(aline.split(','))-3) ]
        #                     sigNumbers[uncertainties[uncname]] = [ (1.+float(aline.split(',')[3+i])) for i in xrange(len(aline.split(','))-3) ]
        #                 elif unctype in ['asymabs','unsymabs']:
        #                     sigNumbers[uncertainties[uncname]] = [ 1.+((float(aline.split(',')[3+i])/sigNumbers[0][i]) if sigNumbers[0][i]>0 else 0.) for i in xrange(len(aline.split(','))-3) ]
        #                 if verbose: print 'Reporting',unctype,'uncertainties on signal with names',uncname,':',sigNumbers[uncertainties[uncname]]
        #             else:
        #                 print 'Unknown uncertainty type:',unctype,'for signal with name',uncname
        #         # Bark if I could not parse the line
        #         else:
        #             print 'Did not understand this line.  Hope you didnt mean for me to!',aline.strip()
        #     moreInput.close()
        #     if len(sigNumbers)>1: break # Caught the right file

        # # Create signal sample
        # sigSample = Sample(setName,kPink)
        # sigSample.setNormByTheory()
        # sigSample.setStatConfig(True)
        # sigSample.setNormFactor('mu_SIG',1.,0.,5.)

        # # Global theory uncertainty
        # #print 'Hello:',xunc_as_hist
        # if not xunc_as_hist: sigSample.addSystematic( Systematic('SigXSec','1.',1+xunc,1-xunc,'user','userOverallSys') )

        # # Build two histograms: one for control regions, one for signal regions.
        # CRvals = []
        # CRstat = []
        # VRvals = []
        # VRstat = []
        # for areg in xrange(len(regions)):
        #     if regions[areg] in constraints:
        #         if allowSignalContamination: CRvals += [ sigNumbers[0][areg] ]
        #         else:                        CRvals += [ 0 ]
        #         if 'MCstat' in uncertainties and len(sigNumbers[ uncertainties['MCstat'] ])>0:
        #             if allowSignalContamination: CRstat += [ sigNumbers[ uncertainties['MCstat'] ][areg] ]
        #             else:                        CRstat += [ 0 ]
        #         else:
        #             CRstat += [0.]
        #     elif regions[areg] in validations:
        #         VRvals += [ sigNumbers[0][areg] ]
        #         if 'MCstat' in uncertainties and len(sigNumbers[ uncertainties['MCstat'] ])>0:
        #             VRstat += [ sigNumbers[ uncertainties['MCstat'] ][areg] ]
        #         else:
        #             VRstat += [0.] 

        # # Build standard histograms
        # if len(constraints)>0:
        #     sigSample.buildHisto( CRvals , 'theCRcut' , 'theCR' )
        # if len(validations)>0:
        #     sigSample.buildHisto( VRvals , 'theVRcut' , 'theVR' )
        # 
        # if len(CRstat)>0:
        #     if len(constraints)>0:
        #         sigSample.buildStatErrors( CRstat , 'theCRcut' , 'theCR' )
        #     if len(validations)>0:
        #         sigSample.buildStatErrors( VRstat , 'theVRcut' , 'theVR' )
        #     #if verbose: 
        #     print 'Built regions with statistical uncertainties for signal',CRstat,VRstat
        # else:
        #     if verbose: print 'Built regions without statistical uncertainties for signal'

        # # Add sample to the configs
        # myTopLvl.addSamples(sigSample)
        # myTopLvl.setSignalSample(sigSample)

        # # Now add systematics channel-by-channel...
        # # this is the tricky bit
        # unc_name_list = []
        # used_systs=[]
        # if len(constraints)>0:
        #     constraintReg = [ myTopLvl.getChannel('theCR',['theCRcut']) ]
        # if len(validations)>0:
        #     validationReg = [ myTopLvl.getChannel('theVR',['theVRcut']) ]
    
        # for asyst in uncertainties:
        #     if asyst in used_systs: continue
        #     # is this high or low?
        #     if asyst.lower().endswith('up'):
        #         upper = asyst
        #         lower = asyst[:-2]+'down'
        #         for as2 in uncertainties:
        #             if lower.lower()==as2.lower():
        #                 lower=as2
        #                 break
        #     elif asyst.lower().endswith('down'):
        #         lower = asyst
        #         upper = asyst[:-4]+'up'
        #         for as2 in uncertainties:
        #             if upper.lower()==as2.lower():
        #                 upper=as2
        #                 break
        #     elif asyst.lower()!='mcstat':
        #         print 'Did not understand uncertainty name:',asyst
        #     else: continue
        #     if verbose: print 'Building uncertainty for names',upper,lower,'signal'
        #     baseUncName=upper[:-2].replace('alpha_','')
        #     if baseUncName[-1]=='_': baseUncName=upper[:-3].replace('alpha_','')
    
        #     if baseUncName not in unc_name_list: unc_name_list += [ baseUncName ]
        #     if baseUncName in skip_unc: continue

        #     modifier=1.0
        #     if baseUncName in reduced_unc: modifier=reduced_unc[baseUncName] #0.5

        #     useThis = False
        #     for areg in xrange(len(regions)):
        #         if len(sigNumbers[uncertainties[lower] ])>0 and abs(1.-sigNumbers[uncertainties[lower] ][ areg ])>0.0001: useThis=True
        #         if len(sigNumbers[uncertainties[upper] ])>0 and abs(1.-sigNumbers[uncertainties[upper] ][ areg ])>0.0001: useThis=True
        #     if not useThis: continue
 
        #     if baseUncName.lower()=='theory':
        #         used_systs += [ upper , lower ]
        #         baseUncName = 'SigXSec'
        #         if 'sglsgl_2ttbar' in setName:
        #             baseUncName = 'PartonShower'
        #             print 'Found parton shower theory uncertainty for sglsgl model' #Skipping theory uncertainty for sglsgl'
        #             #continue

        #     # Two histograms: one for control regions, one for signal regions.
        #     CRupper = []
        #     CRlower = []
        #     VRupper = []
        #     VRlower = []
        #     for areg in xrange(len(regions)):
        #         if regions[areg] in constraints:
        #             if len(sigNumbers[uncertainties[lower] ])>0:
        #                 CRlower += [ 1.-modifier*(1.-sigNumbers[uncertainties[lower] ][ areg ]) ]
        #             if len(sigNumbers[uncertainties[upper] ])>0:
        #                 CRupper += [ 1.+modifier*(sigNumbers[uncertainties[upper] ][ areg ]-1.) ]
        #         elif regions[areg] in validations:
        #             if len(sigNumbers[uncertainties[lower] ])>0:
        #                 VRlower += [ 1.-modifier*(1.-sigNumbers[uncertainties[lower] ][ areg ]) ]
        #             if len(sigNumbers[uncertainties[upper] ])>0:
        #                 VRupper += [ 1.+modifier*(sigNumbers[uncertainties[upper] ][ areg ]-1.) ]
    
        #     if len(CRupper)+len(VRupper)>0 and len(CRlower)+len(VRlower)>0:
        #         if baseUncName in ['JES','CLOSEBY'] and 'GeV' not in asetup:
        #             if len(constraints)>0:
        #                 constraintReg[0].getSample(setName).addSystematic( Systematic( baseUncName,configMgr.weights, CRupper , CRlower , 'user' , 'overallNormHistoSys') )
        #             if len(validations)>0:
        #                 validationReg[0].getSample(setName).addSystematic( Systematic( baseUncName,configMgr.weights, VRupper , VRlower , 'user' , 'overallNormHistoSys') )
        #         elif baseUncName in []:
        #             if len(constraints)>0:
        #                 constraintReg[0].getSample(setName).addSystematic( Systematic( baseUncName,configMgr.weights, CRlower , CRlower , 'user' , 'histoSysOneSide') )
        #             if len(validations)>0:
        #                 validationReg[0].getSample(setName).addSystematic( Systematic( baseUncName,configMgr.weights, VRlower , VRlower , 'user' , 'histoSysOneSide') )
        #         elif baseUncName in ['JER']:
        #             if len(constraints)>0:
        #                 constraintReg[0].getSample(setName).addSystematic( Systematic( baseUncName,configMgr.weights, CRlower , CRlower , 'user' , 'histoSysOneSideSym') )
        #             if len(validations)>0:
        #                 validationReg[0].getSample(setName).addSystematic( Systematic( baseUncName,configMgr.weights, VRlower , VRlower , 'user' , 'histoSysOneSideSym') )
        #         else:
        #             if len(constraints)>0:
        #                 constraintReg[0].getSample(setName).addSystematic( Systematic( baseUncName,configMgr.weights, CRupper , CRlower , 'user' , 'userHistoSys') )
        #             if len(validations)>0:
        #                 validationReg[0].getSample(setName).addSystematic( Systematic( baseUncName,configMgr.weights, VRupper , VRlower , 'user' , 'userHistoSys') )

        #         used_systs += [ upper , lower ]
        #     elif len(CRupper)+len(VRupper)>0: print 'Upper uncertainty only on',upper,lower,abg,regions[areg]
        #     elif len(CRlower)+len(VRlower)>0: print 'Lower uncertainty only on',upper,lower,abg,regions[areg]
        # print 'Added signal uncertainties:', unc_name_list

        # # Move validation region to signal region
        # if len(validations)>0:
        #     iPop = myTopLvl.validationChannels.index('theVRcut_theVR')
        #     myTopLvl.validationChannels.pop(iPop)
        #     print 'Got SR',validationReg,'and popped',iPop
        #     for sr in validationReg:
        #         sr.useOverflowBin=True
        #     myTopLvl.setSignalChannels(validationReg)
        # else:
        #     print 'WARNING: No signal regions will be used (they were all turned off for some reason)'

print 'done with my shit'
