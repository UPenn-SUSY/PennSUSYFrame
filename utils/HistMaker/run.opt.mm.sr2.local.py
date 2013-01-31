#!/usr/bin/env python

import sys
import os.path
import optparse
import time

sys.path.append( '../ProcessManager' )
from kBatchLocal import kBatchLocal

# ------------------------------------------------------------------------------
ds_list = [ "fake.Muon.periodA..config"
          , "fake.Muon.periodB..config"
          , "fake.Muon.periodC..config"
          , "fake.Muon.periodD..config"
          , "fake.Muon.periodE..config"
          , "nominal.data.Muon.periodA..config"
          , "nominal.data.Muon.periodB..config"
          , "nominal.data.Muon.periodC..config"
          , "nominal.data.Muon.periodD..config"
          , "nominal.data.Muon.periodE..config"
          , "nominal.mc.diboson.126892.Sherpa_CT10_llnunu_WW.config"
          , "nominal.mc.diboson.126893.Sherpa_CT10_lllnu_WZ.config"
          , "nominal.mc.diboson.126894.Sherpa_CT10_llll_ZZ.config"
          , "nominal.mc.diboson.126895.Sherpa_CT10_llnunu_ZZ.config"
          , "nominal.mc.signal.144871.simplifiedModel_wA_slep_noWcascade_5.config"
          , "nominal.mc.signal.144873.simplifiedModel_wA_slep_noWcascade_7.config"
          , "nominal.mc.signal.144874.simplifiedModel_wA_slep_noWcascade_8.config"
          , "nominal.mc.signal.144876.simplifiedModel_wA_slep_noWcascade_10.config"
          , "nominal.mc.signal.144877.simplifiedModel_wA_slep_noWcascade_11.config"
          , "nominal.mc.signal.144879.simplifiedModel_wA_slep_noWcascade_13.config"
          , "nominal.mc.signal.144880.simplifiedModel_wA_slep_noWcascade_14.config"
          , "nominal.mc.signal.144881.simplifiedModel_wA_slep_noWcascade_15.config"
          , "nominal.mc.signal.144883.simplifiedModel_wA_slep_noWcascade_17.config"
          , "nominal.mc.signal.144884.simplifiedModel_wA_slep_noWcascade_18.config"
          , "nominal.mc.signal.144885.simplifiedModel_wA_slep_noWcascade_19.config"
          , "nominal.mc.signal.144886.simplifiedModel_wA_slep_noWcascade_20.config"
          , "nominal.mc.signal.144888.simplifiedModel_wA_slep_noWcascade_22.config"
          , "nominal.mc.signal.144889.simplifiedModel_wA_slep_noWcascade_23.config"
          , "nominal.mc.signal.144890.simplifiedModel_wA_slep_noWcascade_24.config"
          , "nominal.mc.signal.144891.simplifiedModel_wA_slep_noWcascade_25.config"
          , "nominal.mc.signal.144892.simplifiedModel_wA_slep_noWcascade_26.config"
          , "nominal.mc.signal.144894.simplifiedModel_wA_slep_noWcascade_28.config"
          , "nominal.mc.signal.144895.simplifiedModel_wA_slep_noWcascade_29.config"
          , "nominal.mc.signal.144896.simplifiedModel_wA_slep_noWcascade_30.config"
          , "nominal.mc.signal.157461.simplifiedModel_wA_slep_noWcascade_32.config"
          , "nominal.mc.signal.157464.simplifiedModel_wA_slep_noWcascade_35.config"
          , "nominal.mc.signal.157467.simplifiedModel_wA_slep_noWcascade_38.config"
          , "nominal.mc.signal.157954.simplifiedModel_wA_slep_noWcascade_39.config"
          , "nominal.mc.signal.157955.simplifiedModel_wA_slep_noWcascade_40.config"
          , "nominal.mc.signal.157956.simplifiedModel_wA_slep_noWcascade_41.config"
          , "nominal.mc.signal.157957.simplifiedModel_wA_slep_noWcascade_42.config"
          , "nominal.mc.signal.157958.simplifiedModel_wA_slep_noWcascade_43.config"
          , "nominal.mc.signal.157959.simplifiedModel_wA_slep_noWcascade_44.config"
          , "nominal.mc.signal.157960.simplifiedModel_wA_slep_noWcascade_45.config"
          , "nominal.mc.signal.157961.simplifiedModel_wA_slep_noWcascade_46.config"
          , "nominal.mc.signal.157962.simplifiedModel_wA_slep_noWcascade_47.config"
          , "nominal.mc.signal.157963.simplifiedModel_wA_slep_noWcascade_48.config"
          , "nominal.mc.signal.157964.simplifiedModel_wA_slep_noWcascade_49.config"
          , "nominal.mc.signal.157965.simplifiedModel_wA_slep_noWcascade_50.config"
          , "nominal.mc.signal.157966.simplifiedModel_wA_slep_noWcascade_51.config"
          , "nominal.mc.signal.157967.simplifiedModel_wA_slep_noWcascade_52.config"
          , "nominal.mc.signal.157968.simplifiedModel_wA_slep_noWcascade_53.config"
          # , "nominal.mc.signal.144902.simplifiedModel_wC_slep_noWcascade_5.config"
          # , "nominal.mc.signal.144904.simplifiedModel_wC_slep_noWcascade_7.config"
          # , "nominal.mc.signal.144905.simplifiedModel_wC_slep_noWcascade_8.config"
          # , "nominal.mc.signal.144907.simplifiedModel_wC_slep_noWcascade_10.config"
          # , "nominal.mc.signal.144908.simplifiedModel_wC_slep_noWcascade_11.config"
          # , "nominal.mc.signal.144910.simplifiedModel_wC_slep_noWcascade_13.config"
          # , "nominal.mc.signal.144911.simplifiedModel_wC_slep_noWcascade_14.config"
          # , "nominal.mc.signal.144912.simplifiedModel_wC_slep_noWcascade_15.config"
          # , "nominal.mc.signal.144914.simplifiedModel_wC_slep_noWcascade_17.config"
          # , "nominal.mc.signal.144915.simplifiedModel_wC_slep_noWcascade_18.config"
          # , "nominal.mc.signal.144916.simplifiedModel_wC_slep_noWcascade_19.config"
          # , "nominal.mc.signal.144917.simplifiedModel_wC_slep_noWcascade_20.config"
          # , "nominal.mc.signal.144919.simplifiedModel_wC_slep_noWcascade_22.config"
          # , "nominal.mc.signal.144920.simplifiedModel_wC_slep_noWcascade_23.config"
          # , "nominal.mc.signal.144921.simplifiedModel_wC_slep_noWcascade_24.config"
          # , "nominal.mc.signal.144922.simplifiedModel_wC_slep_noWcascade_25.config"
          # , "nominal.mc.signal.144923.simplifiedModel_wC_slep_noWcascade_26.config"
          # , "nominal.mc.signal.144925.simplifiedModel_wC_slep_noWcascade_28.config"
          # , "nominal.mc.signal.144926.simplifiedModel_wC_slep_noWcascade_29.config"
          # , "nominal.mc.signal.144927.simplifiedModel_wC_slep_noWcascade_30.config"
          # , "nominal.mc.signal.157969.simplifiedModel_wC_slep_noWcascade_32.config"
          # , "nominal.mc.signal.157970.simplifiedModel_wC_slep_noWcascade_33.config"
          # , "nominal.mc.signal.157971.simplifiedModel_wC_slep_noWcascade_34.config"
          # , "nominal.mc.signal.157972.simplifiedModel_wC_slep_noWcascade_35.config"
          # , "nominal.mc.signal.157973.simplifiedModel_wC_slep_noWcascade_36.config"
          # , "nominal.mc.signal.157974.simplifiedModel_wC_slep_noWcascade_37.config"
          # , "nominal.mc.signal.157975.simplifiedModel_wC_slep_noWcascade_38.config"
          # , "nominal.mc.signal.157976.simplifiedModel_wC_slep_noWcascade_39.config"
          # , "nominal.mc.signal.157977.simplifiedModel_wC_slep_noWcascade_40.config"
          # , "nominal.mc.signal.157978.simplifiedModel_wC_slep_noWcascade_41.config"
          # , "nominal.mc.signal.157979.simplifiedModel_wC_slep_noWcascade_42.config"
          # , "nominal.mc.signal.157980.simplifiedModel_wC_slep_noWcascade_43.config"
          # , "nominal.mc.signal.157981.simplifiedModel_wC_slep_noWcascade_44.config"
          # , "nominal.mc.signal.157982.simplifiedModel_wC_slep_noWcascade_45.config"
          # , "nominal.mc.signal.157983.simplifiedModel_wC_slep_noWcascade_46.config"
          # , "nominal.mc.signal.157984.simplifiedModel_wC_slep_noWcascade_47.config"
          # , "nominal.mc.signal.157985.simplifiedModel_wC_slep_noWcascade_48.config"
          # , "nominal.mc.signal.157986.simplifiedModel_wC_slep_noWcascade_49.config"
          ]

# ------------------------------------------------------------------------------
def main():
    k_batch = kBatchLocal(6)
    for ds in ds_list:
        cmd = './HistMaker ../RunConfigs/OptimizationHistograms/2013_01_22/mm.sr2/%s' % ds
        k_batch.addJob(cmd, ds)

# ==============================================================================
if __name__ == '__main__':
    main()
