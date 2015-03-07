import ROOT

skip_dir_list = ['TotalNumEvents', 'SumMCEventWeights', '_MINUS_', 'PARTIAL',
                 'NO_WEIGHT', 'GE_', 'ZVETO', 'PAIRING', 'ZREGION']

def get_num_events_by_channel(f_name):
    num_events_by_chanel = {}

    f = ROOT.TFile(f_name)
    key_names = [k.GetName() for k in f.GetListOfKeys()]
    for key in key_names:
        # skip dir if in skip dir list
        skip_dir = False
        for sdl in skip_dir_list:
            if sdl in key:
                skip_dir = True
        if skip_dir: continue

        dir = f.Get(key)
        hist = dir.Get('__'.join(['flavor_all__flavor_channel', key]))

        num_events_by_chanel[key.replace('BMINUSL_','')] = hist.Integral()

    f.Close()
    return num_events_by_chanel

def display_event_breakdown(event_breakdown):
    region_list = []
    totals = []
    header_drawn = False
    for channel in event_breakdown:
        if not header_drawn:
            region_list = event_breakdown[channel].keys()
            totals = [0]*len(region_list)

            print region_list
            print ' | '.join(['region'] + region_list)
            print '-'*80
            header_drawn = True

        breakdown_str = [str(event_breakdown[channel][region]) for region in region_list]
        totals = [totals[i] + event_breakdown[channel][region] for i, region in enumerate(region_list)]
        print ' | '.join([channel] + breakdown_str)
    print '-'*80
    print ' | '.join(['total'] + [str(t) for t in totals])
    print '-'*80
    for channel in event_breakdown:
        fraction_str = [str(event_breakdown[channel][region]/totals[i]) for i, region in enumerate(region_list)]
        print ' | '.join([channel] + fraction_str)


if __name__ == '__main__':
    num_events_t_channel  = get_num_events_by_channel('../../NextPlotDir.BMinusL.NOMINAL/BMinusL.NOMINAL.110101.AcerMCPythia_P2011CCTEQ6L1_singletop_tchan_l__NOMINAL.hist.root')
    num_events_s_channel  = get_num_events_by_channel('../../NextPlotDir.BMinusL.NOMINAL/BMinusL.NOMINAL.110119.PowhegPythia_P2011C_st_schan_lep__NOMINAL.hist.root')
    num_events_wt_channel = get_num_events_by_channel('../../NextPlotDir.BMinusL.NOMINAL/BMinusL.NOMINAL.110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR__NOMINAL.hist.root')

    display_event_breakdown({'t channel':num_events_t_channel,
                             's channel':num_events_s_channel,
                             'Wt channel':num_events_wt_channel})
