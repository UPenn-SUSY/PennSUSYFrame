# Class to return theory uncertainties to a channel

from systematic import Systematic

class uncertaintyAdder:

    def __init__( self , w):
        self.w = w

        self.uncertainties = {
                '_PartonShower' : {
                    'Top' : {
                        'CR_TOP' : [ [1.0] , [1.0] ] , 
                        'SR_600' : [ [1.0] , [1.0] ] , 
                        'SR_400' : [ [1.0] , [1.0] ] , 
                        'VR_Z' : [ [0.8826048576492873] , [1.1173951423507127] ] , 
                        'CR_Z' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_1' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_3' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_2' : [ [1.0] , [1.0] ] , 
                        },
                    },
                '_multiParton' : {
                    'ZX' : {
                        'CR_TOP' : [ [0.8625950679234464] , [1.1374049320765536] ] , 
                        'SR_600' : [ [1.0] , [1.0] ] , 
                        'SR_400' : [ [1.0] , [1.0] ] , 
                        'VR_Z' : [ [0.8656300847891922] , [1.1343699152108078] ] , 
                        'CR_Z' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_1' : [ [0.8625950679234464] , [1.1374049320765536] ] , 
                        'VR_TOP_3' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_2' : [ [1.0] , [1.0] ] , 
                        },
                    },
                '_Envelope' : {
                    'Top' : {
                        'CR_TOP' : [ [1.0] , [1.0] ] , 
                        'SR_600' : [ [1.3547111478592229] , [0.7381647383504936] ] , 
                        'SR_400' : [ [1.1354165085820953] , [0.8807340675791274] ] , 
                        'VR_Z' : [ [1.068729936620298] , [0.9356900800985828] ] , 
                        'CR_Z' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_1' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_3' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_2' : [ [1.0] , [1.0] ] , 
                        },
                    'ST' : {
                        'CR_TOP' : [ [1.0] , [1.0] ] , 
                        'SR_600' : [ [1.0] , [1.0] ] , 
                        'SR_400' : [ [1.0] , [1.0] ] , 
                        'VR_Z' : [ [1.0] , [1.1987929075049761] ] , 
                        'CR_Z' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_1' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_3' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_2' : [ [1.0] , [1.0] ] , 
                        },
                    },
                }

    def getUncertainties( self , reg):
        # List of systematics to add
        syst_list = {}

        # This is poor array index ordering, but it's only in setup, so it won't kill us
        for aU in self.uncertainties: # Uncertainties
            for aS in self.uncertainties[aU]: # Samples
                for aRV in self.uncertainties[aU][aS]: # region x variable
                    if reg!=aRV.split('x')[0]: continue
                    if aS not in syst_list:
                        syst_list[aS] = [Systematic( aS+aU,
                                         self.w,
                                         self.uncertainties[aU][aS][aRV][0],
                                         self.uncertainties[aU][aS][aRV][1],
                                         'user',
                                         'userHistoSys')]
                    else:
                        syst_list[aS] += [Systematic(aS+aU,
                                          self.w,
                                          self.uncertainties[aU][aS][aRV][0],
                                          self.uncertainties[aU][aS][aRV][1],
                                          'user',
                                          'userHistoSys')]
        # All done!
        return syst_list

