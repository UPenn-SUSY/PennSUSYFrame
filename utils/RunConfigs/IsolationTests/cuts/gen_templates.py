#!/usr/bin/env python

import itertools

single_line = '# ------------------------------------------------------------------------------'
dashed_line = '# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -'

# ------------------------------------------------------------------------------
def genCutConfig( region_name
                , it_num
                , lepton_pt = None
                , num_jets  = None
                , jet_pt    = None
                , met_rel   = None
                , dphi_ll   = None
                , mt2       = None
                , emma_mt   = None
                , ptll      = None
                ):
    cut_name = '%s.it%s' % (region_name, it_num)
    if lepton_pt is not None:
        cut_name = '%s_leppt%s' % (cut_name, lepton_pt)
    if num_jets is not None:
        cut_name = '%s_njet%s' % (cut_name, num_jets)
    if jet_pt is not None:
        cut_name = '%s_jetpt%s' % (cut_name, jet_pt)
    if met_rel is not None:
        cut_name = '%s_metrel%s' % (cut_name, met_rel)
    if dphi_ll is not None:
        cut_name = '%s_dphill%s' % (cut_name, dphi_ll)
    if mt2 is not None:
        cut_name = '%s_mt2%s' % (cut_name, mt2)
    if emma_mt is not None:
        print 'adding emma_mt to cut name: %s' % emma_mt
        cut_name = '%s_emma_mt%s' % (cut_name, emma_mt)
    if ptll is not None:
        cut_name = '%s_ptll%s' % (cut_name, ptll)

    entry = dashed_line
    entry += """
cut: %s
    pass_grl:               1
    pass_incomplete_event:  1
    pass_lar_error:         1
    pass_tile_error:        1
    pass_tile_hot_spot:     1
    pass_tile_trip:         1
    pass_bad_jets:          1
    pass_calo_problem_jets: 1
    pass_primary_vertex:    1
    pass_bad_muons:         1
    pass_cosmic_muons:      1
    pass_hfor:              1
    pass_ge_2_good_leptons: 1
    pass_2_good_leptons:    1
    pass_mll:               1
    pass_trigger_match:     1
    pass_flavor:            mm
    pass_ee_trigger:        0
    pass_mm_trigger:        1
    pass_em_trigger:        0
    pass_me_trigger:        0

    pass_sr_ssjets:  0

    pass_l_jet_veto: 0
    pass_b_jet_veto: 1
    pass_f_jet_veto: 1
    pass_z_veto:     0
    pass_top_veto:   1

    pass_sign_channel: ss
""" % cut_name

    if lepton_pt is not None:
        entry += """
    additional_cut: mu_pt[0] > %se3
    additional_cut: mu_pt[1] > %se3
""" % (lepton_pt, lepton_pt)
    if num_jets is not None:
        entry += """
    additional_cut: light_jet_num_light_jets >= %s
""" % num_jets
    if jet_pt is not None:
        entry += """
    additional_cut: light_jet_pt[0] >= %se3
""" % jet_pt
    if met_rel is not None:
        entry += """
    additional_cut: met_rel_et > %se3
""" % met_rel
    if dphi_ll is not None:
        entry += """
    additional_cut: (1-abs(abs(mu_phi[0]-mu_phi[1])/3.14159-1)) > %s
""" % dphi_ll
    if mt2 is not None:
        entry += """
    additional_cut: mt2 < %se3
""" % mt2
    if emma_mt is not None:
        print 'adding emma_mt to additional cuts: %s' % emma_mt
        entry += """
    additional_cut: sqrt(mll*mll+ptll*ptll) < %se3
""" % emma_mt
    if ptll is not None:
        entry += """
    additional_cut: ptll < %se3
""" % ptll

    entry += """end

"""
    return entry


# ==============================================================================
if __name__ == '__main__':
    region = 'mm_sr_ss'
    out_file = '%s.cut_template.config' % region

    # lepton_pt_list = [15]
    lepton_pt_list = [10, 15]
    # jet_pt_list    = [None, 20, 25, 30]
    # jet_pt_list    = [None, 25]
    # jet_pt_list    = [None, 20, 25]
    jet_pt_list    = [None, 20]
    num_jets_list  = [0, 1, 2]
    # met_rel_list   = [None, 30, 40, 50]
    # met_rel_list   = [None, 50]
    met_rel_list   = [20, 50]
    # met_rel_list   = [None]
    # dphi_ll_list   = [None, 0.5]
    dphi_ll_list   = [None]
    # mt2_list       = [None, 20, 30]
    mt2_list       = [None, 30]
    emma_mt_list   = [None, 30]
    # ptll_list      = [None, 20]
    ptll_list      = [None]

    f = open(out_file, 'w')
    for lepton_pt in lepton_pt_list:
        for num_jets in num_jets_list:
            for jet_pt in jet_pt_list:
                if num_jets == 0 and jet_pt is not None: continue
                if num_jets != 0 and jet_pt is None: continue
                for met_rel in met_rel_list:
                    for dphi_ll in dphi_ll_list:
                        for mt2 in mt2_list:
                            for emma_mt in emma_mt_list:
                                for ptll in ptll_list:
                                    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                    # it 5, ptll
                                    f.write( genCutConfig( region_name = 'mm_sr_ss'
                                                        , it_num = 5
                                                        , lepton_pt = lepton_pt
                                                        # , num_jets  = 0 if jet_pt is None else 1
                                                        , num_jets  = num_jets
                                                        , jet_pt    = jet_pt
                                                        , met_rel   = met_rel
                                                        , dphi_ll   = dphi_ll
                                                        , mt2       = mt2
                                                        , emma_mt   = emma_mt
                                                        , ptll      = ptll
                                                        )
                                        )
