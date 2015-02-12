if [[ ! -d YieldTable ]] ; then
  mkdir YieldTable
fi

## YieldsTable.py \
##   -c CR_top_all_mbl_0,CR_Z_all_mbl_0,VR_top_1_all_mbl_0,VR_top_2_all_mbl_0,VR_top_3_all_mbl_0,VR_Z_all_mbl_0 \
##   -s ttbar,ZGamma,SingleTop,Other \
##   -w results/SampleExcl_bre_50_brm_50_brt_0_sr_ht_1100_mbl_400/BkgOnly_combined_NormalMeasurement_model_afterFit.root \
##   -o YieldTable/MyYieldTable.CR_VR.tex
## 
## YieldsTable.py \
##   -c CR_top_all_mbl_0,CR_top_ee_mbl_0,CR_top_mm_mbl_0,CR_top_em_mbl_0,CR_Z_all_mbl_0,CR_Z_ee_mbl_0,CR_Z_mm_mbl_0 \
##   -s ttbar,ZGamma,SingleTop,Other \
##   -w results/SampleExcl_bre_50_brm_50_brt_0_sr_ht_1100_mbl_400/BkgOnly_combined_NormalMeasurement_model_afterFit.root \
##   -o YieldTable/MyYieldTable.CR_detail.tex
## 
#


YieldsTable.py \
##   -c VR_top_1_all_mbl_0,VR_top_2_all_mbl_0,VR_top_3_all_mbl_0,VR_top_1_ee_mbl_0,VR_top_2_ee_mbl_0,VR_top_3_ee_mbl_0,VR_top_1_mm_mbl_0,VR_top_2_mm_mbl_0,VR_top_3_mm_mbl_0,VR_top_1_em_mbl_0,VR_top_2_em_mbl_0,VR_top_3_em_mbl_0,VR_Z_all_mbl_0,VR_Z_ee_mbl_0,VR_Z_mm_mbl_0\
##   -s ttbar,ZGamma,SingleTop,Other \
##   -w results/SampleExcl_bre_50_brm_50_brt_0_sr_ht_1100_mbl_400/BkgOnly_combined_NormalMeasurement_model_afterFit.root \
##   -o YieldTable/MyYieldTable.VR_detail.tex

YieldsTable.py \
  -c CR_top_all_mbl_0,CR_Z_all_mbl_0,VR_top_1_all_mbl_0,VR_top_2_all_mbl_0,VR_top_3_all_mbl_0,VR_Z_all_mbl_0,SR_ht_1100_mbl_400_all_mbl_0,SR_ht_1100_mbl_600_all_mbl_0 \
  -s ttbar,ZGamma,SingleTop,Other \
  -w results/SampleBkg_bre_50_brm_50_brt_0/BkgOnly_combined_NormalMeasurement_model_afterFit.root \
  -o YieldTable/MyYieldTable.CR_VR_SR.tex

YieldsTable.py \
  -c CR_top_all_mbl_0,CR_top_ee_mbl_0,CR_top_mm_mbl_0,CR_top_em_mbl_0,CR_Z_all_mbl_0,CR_Z_ee_mbl_0,CR_Z_mm_mbl_0 \
  -s ttbar,ZGamma,SingleTop,Other \
  -w results/SampleBkg_bre_50_brm_50_brt_0/BkgOnly_combined_NormalMeasurement_model_afterFit.root \
  -o YieldTable/MyYieldTable.CR_detail.tex

YieldsTable.py \
  -c VR_top_1_all_mbl_0,VR_top_1_ee_mbl_0,VR_top_1_mm_mbl_0,VR_top_1_em_mbl_0,VR_top_2_all_mbl_0,VR_top_2_ee_mbl_0,VR_top_2_mm_mbl_0,VR_top_2_em_mbl_0,VR_top_3_all_mbl_0,VR_top_3_ee_mbl_0,VR_top_3_mm_mbl_0,VR_top_3_em_mbl_0,VR_Z_all_mbl_0,VR_Z_ee_mbl_0,VR_Z_mm_mbl_0 \
  -s ttbar,ZGamma,SingleTop,Other \
  -w results/SampleBkg_bre_50_brm_50_brt_0/BkgOnly_combined_NormalMeasurement_model_afterFit.root \
  -o YieldTable/MyYieldTable.VR_detail.tex

YieldsTable.py \
  -c SR_ht_1100_mbl_400_all_mbl_0,SR_ht_1100_mbl_400_ee_mbl_0,SR_ht_1100_mbl_400_mm_mbl_0,SR_ht_1100_mbl_400_em_mbl_0,SR_ht_1100_mbl_600_all_mbl_0,SR_ht_1100_mbl_600_ee_mbl_0,SR_ht_1100_mbl_600_mm_mbl_0,SR_ht_1100_mbl_600_em_mbl_0 \
  -s ttbar,ZGamma,SingleTop,Other \
  -w results/SampleBkg_bre_50_brm_50_brt_0/BkgOnly_combined_NormalMeasurement_model_afterFit.root \
  -o YieldTable/MyYieldTable.SR_detail.tex

