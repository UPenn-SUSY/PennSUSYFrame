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

    lepton_pt_list = [10, 12.5, 15]
    jet_pt_list    = [20, 25, 30]
    met_rel_list   = [None, 20, 30, 40, 50]
    dphi_ll_list   = [None, 0.5, 0.6, 0.7]
    mt2_list       = [None, 15, 20, 30]
    ptll_list      = [None, 20, 40, 60]

    f = open(out_file, 'w')
    for lepton_pt in lepton_pt_list:
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # # it 0, baseline
        # f.write( genCutConfig( region_name = 'mm_sr_ss'
        #                      , it_num = 0
        #                      , lepton_pt = lepton_pt
        #                      , num_jets  = None
        #                      , jet_pt    = None
        #                      , met_rel   = None
        #                      , dphi_ll   = None
        #                      , mt2       = None
        #                      , ptll      = None
        #                      )
        #        )

        for jet_pt in jet_pt_list:
            # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            # # it 1, num jets
            # f.write( genCutConfig( region_name = 'mm_sr_ss'
            #                      , it_num = 1
            #                      , lepton_pt = lepton_pt
            #                      , num_jets  = 1
            #                      , jet_pt    = jet_pt
            #                      , met_rel   = None
            #                      , dphi_ll   = None
            #                      , mt2       = None
            #                      , ptll      = None
            #                      )
            #        )


            for met_rel in met_rel_list:
                # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                # it 2, met_rel
                # f.write( genCutConfig( region_name = 'mm_sr_ss'
                #                      , it_num = 2
                #                      , lepton_pt = lepton_pt
                #                      , num_jets  = 1
                #                      , jet_pt    = jet_pt
                #                      , met_rel   = met_rel
                #                      , dphi_ll   = None
                #                      , mt2       = None
                #                      , ptll      = None
                #                      )
                #        )


                for dphi_ll in dphi_ll_list:
                    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                    # it 3, dphi_ll
                    # f.write( genCutConfig( region_name = 'mm_sr_ss'
                    #                      , it_num = 3
                    #                      , lepton_pt = lepton_pt
                    #                      , num_jets  = 1
                    #                      , jet_pt    = jet_pt
                    #                      , met_rel   = met_rel
                    #                      , dphi_ll   = dphi_ll
                    #                      , mt2       = None
                    #                      , ptll      = None
                    #                      )
                    #        )

                    for mt2 in mt2_list:
                        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                        # it 4, mt2
                        # f.write( genCutConfig( region_name = 'mm_sr_ss'
                        #                     , it_num = 4
                        #                     , lepton_pt = lepton_pt
                        #                     , num_jets  = 1
                        #                     , jet_pt    = jet_pt
                        #                     , met_rel   = met_rel
                        #                     , dphi_ll   = dphi_ll
                        #                     , mt2       = mt2
                        #                     , ptll      = None
                        #                     )
                        #     )

                        for ptll in ptll_list:
                            # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                            # it 5, ptll
                            f.write( genCutConfig( region_name = 'mm_sr_ss'
                                                , it_num = 5
                                                , lepton_pt = lepton_pt
                                                , num_jets  = 1
                                                , jet_pt    = jet_pt
                                                , met_rel   = met_rel
                                                , dphi_ll   = dphi_ll
                                                , mt2       = mt2
                                                , ptll      = ptll
                                                )
                                )


    # f.write( genCutConfig( region_name = 'test'
    #                   , it_num = 0
    #                   , lepton_pt = None
    #                   , num_jets  = None
    #                   , jet_pt    = None
    #                   , met_rel   = None
    #                   , dphi_ll   = None
    #                   , mt2       = None
    #                   , ptll      = None
    #                   )

    # print genCutConfig( region_name = 'test'
    #                   , it_num = 1
    #                   , lepton_pt = 15
    #                   , num_jets  = None
    #                   , jet_pt    = None
    #                   , met_rel   = None
    #                   , dphi_ll   = None
    #                   , mt2       = None
    #                   , ptll      = None
    #                   )

    # print genCutConfig( region_name = 'test'
    #                   , it_num = 2
    #                   , lepton_pt = 15
    #                   , num_jets  = 1
    #                   , jet_pt    = None
    #                   , met_rel   = None
    #                   , dphi_ll   = None
    #                   , mt2       = None
    #                   , ptll      = None
    #                   )

    # print genCutConfig( region_name = 'test'
    #                   , it_num = 3
    #                   , lepton_pt = 15
    #                   , num_jets  = 1
    #                   , jet_pt    = 25
    #                   , met_rel   = None
    #                   , dphi_ll   = None
    #                   , mt2       = None
    #                   , ptll      = None
    #                   )






# cut: mm_sr_ss.it0_l10_j25
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 10e3
#     additional_cut: mu_pt[1] > 10e3
# 
#     additional_cut: light_jet_pt[0] >= 25e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l10_j30
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 10e3
#     additional_cut: mu_pt[1] > 10e3
# 
#     additional_cut: light_jet_pt[0] >= 30e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l10_j35
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 10e3
#     additional_cut: mu_pt[1] > 10e3
# 
#     additional_cut: light_jet_pt[0] >= 35e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l10_j40
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 10e3
#     additional_cut: mu_pt[1] > 10e3
# 
#     additional_cut: light_jet_pt[0] >= 40e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l10_j45
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 10e3
#     additional_cut: mu_pt[1] > 10e3
# 
#     additional_cut: light_jet_pt[0] >= 45e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l10_j50
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 10e3
#     additional_cut: mu_pt[1] > 10e3
# 
#     additional_cut: light_jet_pt[0] >= 50e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it0_l11_j20
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 11e3
#     additional_cut: mu_pt[1] > 11e3
# 
#     additional_cut: light_jet_pt[0] >= 20e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l11_j25
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 11e3
#     additional_cut: mu_pt[1] > 11e3
# 
#     additional_cut: light_jet_pt[0] >= 25e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l11_j30
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 11e3
#     additional_cut: mu_pt[1] > 11e3
# 
#     additional_cut: light_jet_pt[0] >= 30e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l11_j35
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 11e3
#     additional_cut: mu_pt[1] > 11e3
# 
#     additional_cut: light_jet_pt[0] >= 35e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l11_j40
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 11e3
#     additional_cut: mu_pt[1] > 11e3
# 
#     additional_cut: light_jet_pt[0] >= 40e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l11_j45
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 11e3
#     additional_cut: mu_pt[1] > 11e3
# 
#     additional_cut: light_jet_pt[0] >= 45e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l11_j50
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 11e3
#     additional_cut: mu_pt[1] > 11e3
# 
#     additional_cut: light_jet_pt[0] >= 50e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it0_l12_j20
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 12e3
#     additional_cut: mu_pt[1] > 12e3
# 
#     additional_cut: light_jet_pt[0] >= 20e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l12_j25
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 12e3
#     additional_cut: mu_pt[1] > 12e3
# 
#     additional_cut: light_jet_pt[0] >= 25e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l12_j30
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 12e3
#     additional_cut: mu_pt[1] > 12e3
# 
#     additional_cut: light_jet_pt[0] >= 30e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l12_j35
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 12e3
#     additional_cut: mu_pt[1] > 12e3
# 
#     additional_cut: light_jet_pt[0] >= 35e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l12_j40
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 12e3
#     additional_cut: mu_pt[1] > 12e3
# 
#     additional_cut: light_jet_pt[0] >= 40e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l12_j45
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 12e3
#     additional_cut: mu_pt[1] > 12e3
# 
#     additional_cut: light_jet_pt[0] >= 45e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it0_l12_j50
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   1
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 12e3
#     additional_cut: mu_pt[1] > 12e3
# 
#     additional_cut: light_jet_pt[0] >= 50e3
# 
#     # additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     # additional_cut: ptll < 20e3
# end
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it1
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     # additional_cut: met_rel_et > 40e3
#     additional_cut: light_jet_num_light_jets >= 1
# end
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it2a
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 40e3
#     additional_cut: light_jet_num_light_jets >= 1
# end
# 
# cut: mm_sr_ss.it2b
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 30e3
#     additional_cut: light_jet_num_light_jets >= 1
# end
# 
# cut: mm_sr_ss.it2c
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 20e3
#     additional_cut: light_jet_num_light_jets >= 1
# end
# 
# cut: mm_sr_ss.it2d
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 50e3
#     additional_cut: light_jet_num_light_jets >= 1
# end
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it3a
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 40e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
# end
# 
# cut: mm_sr_ss.it3b
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 30e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
# end
# 
# cut: mm_sr_ss.it3c
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 20e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
# end
# 
# cut: mm_sr_ss.it3d
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 50e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
# end
# 
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it4a
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 40e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
# end
# 
# cut: mm_sr_ss.it4b
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 30e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
# end
# 
# cut: mm_sr_ss.it4c
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 20e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
# end
# 
# cut: mm_sr_ss.it4d
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 50e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
# end
# 
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it5a
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 40e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it5b
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 30e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it5c
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 20e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it5d
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 50e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it6a
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 40e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it6b
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 30e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it6c
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 20e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it6d
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 50e3
#     # additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it7
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     # additional_cut: met_rel_et > 50e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it8a
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 40e3
#     additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it8b
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 30e3
#     additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it8c
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 20e3
#     additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it8d
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 50e3
#     additional_cut: light_jet_num_light_jets >= 1
#     # additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# 
# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# cut: mm_sr_ss.it9a
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 40e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it9b
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 30e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it9c
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 20e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# cut: mm_sr_ss.it9d
#     pass_grl:               1
#     pass_incomplete_event:  1
#     pass_lar_error:         1
#     pass_tile_error:        1
#     pass_tile_hot_spot:     1
#     pass_tile_trip:         1
#     pass_bad_jets:          1
#     pass_calo_problem_jets: 1
#     pass_primary_vertex:    1
#     pass_bad_muons:         1
#     pass_cosmic_muons:      1
#     pass_hfor:              1
#     pass_ge_2_good_leptons: 1
#     pass_2_good_leptons:    1
#     pass_mll:               1
#     pass_trigger_match:     1
#     pass_flavor:            mm
#     pass_ee_trigger:        0
#     pass_mm_trigger:        1
#     pass_em_trigger:        0
#     pass_me_trigger:        0
# 
#     pass_sr_ssjets:  0
# 
#     pass_l_jet_veto: 0
#     pass_b_jet_veto: 1
#     pass_f_jet_veto: 1
#     pass_z_veto:     0
#     pass_top_veto:   0
# 
#     pass_sign_channel: ss
# 
#     additional_cut: mu_pt[0] > 15e3
#     additional_cut: mu_pt[1] > 15e3
# 
#     additional_cut: met_rel_et > 50e3
#     additional_cut: light_jet_num_light_jets >= 1
#     additional_cut: abs(mu_phi[0]-mu_phi[1])/3.14159 > 0.5
#     # additional_cut: mt2 < 30e3
#     additional_cut: ptll < 20e3
# end
# 
# 
