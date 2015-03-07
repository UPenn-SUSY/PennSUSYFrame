from systematic import Systematic

class uncertaintyAdder:

    def __init__( self , w):
        self.w = w

        self.uncertainties = {
                '_RScales' : {
                    'Top' : {
                        'CR_TOP' : [ [1.0] , [1.0] ] , 
                        'SR_600' : [ [1.0] , [1.0] ] , 
                        'SR_400' : [ [1.0677082542910477] , [0.936585435188936] ] , 
                        'VR_Z' : [ [1.0256294964028778] , [0.9750109601052169] ] , 
                        'CR_Z' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_1' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_3' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_2' : [ [1.0] , [1.0] ] , 
                        },
                    },
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
                '_DiagramSubtr' : {
                    'ST' : {
                        'CR_TOP' : [ [1.0] , [1.0] ] , 
                        'SR_600' : [ [1.0] , [1.0] ] , 
                        'SR_400' : [ [1.0] , [1.0] ] , 
                        'VR_Z' : [ [1.1987929075049761] , [1.0] ] , 
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
                '_ISRFSR' : {
                    'Top' : {
                        'CR_TOP' : [ [1.0] , [1.0] ] , 
                        'SR_600' : [ [1.0] , [1.0] ] , 
                        'SR_400' : [ [0.977252319664771] , [1.022747680335229] ] , 
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
                        'VR_Z' : [ [1.0] , [1.0] ] , 
                        'CR_Z' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_1' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_3' : [ [1.0] , [1.0] ] , 
                        'VR_TOP_2' : [ [1.0] , [1.0] ] , 
                        },
                    },
                '_FScales' : {
                        'Top' : {
                            'CR_TOP' : [ [1.0] , [1.0] ] , 
                            'SR_600' : [ [1.1773555739296113] , [0.8493610784568175] ] , 
                            'SR_400' : [ [1.0121222004783648] , [0.9880229872710673] ] , 
                            'VR_Z' : [ [0.985788276545643] , [1.0142117234543568] ] , 
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

