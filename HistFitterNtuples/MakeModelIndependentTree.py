import itertools
import ROOT
import array
import datetime

# ------------------------------------------------------------------------------
def fillFakeSignalTree():
    # create output file and tree
    out_file_name = 'FakeSignal.root'
    out_file = ROOT.TFile(out_file_name, 'RECREATE')
    out_tree = ROOT.TTree('fake_signal_NoSys', 'fake_signal_NoSys')

    # create variables for branches
    is_sr_400 = array.array('i', [1])
    is_sr_600 = array.array('i', [1])
    is_cr_top = array.array('i', [0])
    is_cr_z = array.array('i', [0])
    weight = array.array('f', [203000])

    # connect branches
    out_tree.Branch('is_sr_ht_1100_mbl_400' , is_sr_400, 'is_sr_ht_1100_mbl_400/I')
    out_tree.Branch('is_sr_ht_1100_mbl_600' , is_sr_600, 'is_sr_ht_1100_mbl_600/I')
    out_tree.Branch('is_cr_top_mbl_200' , is_cr_top , 'is_cr_top_mbl_200/I')
    out_tree.Branch('is_cr_z_mbl_200'   , is_cr_z   , 'is_cr_z_mbl_200/I')
    out_tree.Branch('weight'   , weight   , 'weight/F')

    out_tree.Fill()

    # write and close file
    out_file.Write()
    out_file.Close()


if __name__ == '__main__':
    # file to extract samples
    fillFakeSignalTree()

