if [[ ! -d YieldTable ]] ; then
  mkdir YieldTable
fi

YieldsTable.py \
  -c CR_top_all_mbl_0,CR_Z_all_mbl_0,VR_3_all_mbl_0,VR_5_all_mbl_0 \
  -s ttbar,ZGamma,SingleTop,ttV,Diboson,Higgs \
  -w results/SampleExcl/BkgOnly_combined_NormalMeasurement_model_afterFit.root \
  -o YieldTable/MyYieldTable.CR_VR.tex

YieldsTable.py \
  -c CR_top_all_mbl_0,CR_top_ee_mbl_0,CR_top_mm_mbl_0,CR_top_em_mbl_0,CR_Z_all_mbl_0,CR_Z_ee_mbl_0,CR_Z_mm_mbl_0 \
  -s ttbar,ZGamma,SingleTop,ttV,Diboson,Higgs \
  -w results/SampleExcl/BkgOnly_combined_NormalMeasurement_model_afterFit.root \
  -o YieldTable/MyYieldTable.CR_detail.tex

YieldsTable.py \
  -c VR_3_all_mbl_0,VR_3_ee_mbl_0,VR_3_mm_mbl_0,VR_3_em_mbl_0,VR_5_all_mbl_0,VR_5_ee_mbl_0,VR_5_mm_mbl_0 \
  -s ttbar,ZGamma,SingleTop,ttV,Diboson,Higgs \
  -w results/SampleExcl/BkgOnly_combined_NormalMeasurement_model_afterFit.root \
  -o YieldTable/MyYieldTable.VR_detail.tex


# SR_ee
# SR_mm
# SR_em
