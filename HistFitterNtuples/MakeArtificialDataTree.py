import itertools
import ROOT
import array
import datetime

# ------------------------------------------------------------------------------
process_list = {'ttbar':1, 'ZGamma':1}
flavor_list = ['ee', 'mm', 'em']
region_list = ['cr_top', 'cr_z', 'sr']
hist_name = 'mbl_0'

hist_bins, hist_min, hist_max = 20, 0, 2000

lumi = 21.e3

rand = ROOT.TRandom3(datetime.datetime.now().microsecond)

# ------------------------------------------------------------------------------
def fillArtificialDataTree(in_file):
    # create output file and tree
    file_name_tag = '.'.join(['_'.join([k,str(v)]) for k, v in process_list.items()])
    out_file_name = '.'.join(['ArtificialData', file_name_tag, 'root'])
    out_file = ROOT.TFile(out_file_name, 'RECREATE')
    # out_tree = ROOT.TTree('ArtificialData', 'ArtificialData')
    out_tree = ROOT.TTree('data', 'data')

    # create variables for branches
    mbl_0 = array.array('d', [0])
    is_ee = array.array('i', [0])
    is_mm = array.array('i', [0])
    is_em = array.array('i', [0])
    is_sr = array.array('i', [0])
    is_cr_top = array.array('i', [0])
    is_cr_z = array.array('i', [0])

    # connect branches
    out_tree.Branch('mbl_0'     , mbl_0     , 'mbl_0/D')
    out_tree.Branch('is_ee'     , is_ee     , 'is_ee/I')
    out_tree.Branch('is_mm'     , is_mm     , 'is_mm/I')
    out_tree.Branch('is_em'     , is_em     , 'is_em/I')
    out_tree.Branch('is_sr'     , is_sr     , 'is_sr/I')
    out_tree.Branch('is_cr_top' , is_cr_top , 'is_cr_top/I')
    out_tree.Branch('is_cr_z'   , is_cr_z   , 'is_cr_z/I')

    # loop through processes and flavors
    for pl, fl in itertools.product(process_list.keys(), flavor_list):
        # get tree for this process and flavor channel
        tree_name = '_'.join([fl, pl, 'NoSys'])
        print 'process: ', pl, ' - flavor: ', fl, ' - tree: ', tree_name
        t = in_file.Get(tree_name)

        is_ee[0] = 1 if fl == 'ee' else 0
        is_mm[0] = 1 if fl == 'mm' else 0
        is_em[0] = 1 if fl == 'em' else 0

        # loop through regions
        for rl in region_list:
            is_sr[0]     = 1 if rl == 'sr'     else 0
            is_cr_top[0] = 1 if rl == 'cr_top' else 0
            is_cr_z[0]   = 1 if rl == 'cr_z'   else 0
            print 'is_sr[0]    : ' , is_sr[0]
            print 'is_cr_top[0]: ' , is_cr_top[0]
            print 'is_cr_z[0]  : ' , is_cr_z[0]

            # create and fill histogram
            this_hist_name = '_'.join([tree_name, rl, hist_name])
            print '  region: ', rl, ' - hist name: ', this_hist_name

            region_hist = ROOT.TH1F(this_hist_name,
                                    '',
                                    hist_bins,
                                    hist_min,
                                    hist_max)
            t.Draw(' >> '.join([hist_name, this_hist_name]),
                ''.join([str(lumi),
                         '*weight*is_',
                         rl,
                         '*',
                         str(process_list[pl])]))
            print '    integral: ', region_hist.Integral()
            print ''

            # find bin centers and content
            bin_centers = [region_hist.GetBinCenter(this_bin) for this_bin in
                           xrange(hist_bins + 2)]
            bin_content = [region_hist.GetBinContent(this_bin) for this_bin in
                           xrange(hist_bins + 2)]
            print bin_centers
            print bin_content
            print sum(bin_content)
            print ''

            for center, content in itertools.izip(bin_centers, bin_content):
                mbl_0[0] = center
                print center, ' - ', content

                num_events = rand.Poisson(content)
                print '  bin center: ', center, ' - exp content: ', content, ' - gen content: ', num_events
                # for i in xrange(int(content)):
                for i in xrange(num_events):
                    # print '  - filling entry ', i
                    out_tree.Fill()


            print ''

    # write and close file
    out_file.Write()
    out_file.Close()


if __name__ == '__main__':
    # file to extract samples
    bkg_file = ROOT.TFile('BackgroundHistFitterTrees.root', 'r')

    fillArtificialDataTree(bkg_file)

