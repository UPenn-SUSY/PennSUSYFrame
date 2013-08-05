#!/bin/bash
# ==============================================================================
# = Quick script to link all the relevant files to the top SusyFrame directory
# = This should be run from the grid_submit_scripts directory (i.e. where the
# = files actually live
# ==============================================================================


file_to_link=( \
  gen_job_config.py  \
  grid_build.sh  \
  grid_run_cutflow.sh  \
  grid_run_presel.sh  \
  prep_cutflow_tarball.sh  \
  prep_presel_tarball.sh  \

  submit_all_samples.sh  \
  submit_cutflow.sh  \
  submit_presel.sh  \

  submit_W_plus_jet.sh \
  submit_Z_plus_jet.sh \
  submit_Z_plus_jet_alpgen.sh \
  submit_diboson.sh  \
  submit_drell_yan.sh  \
  submit_egamma_data.sh  \
  submit_muon_data.sh  \
  submit_pmssm_signal_grids.sh  \
  submit_simplified_wA_signal_grids.sh \
  submit_simplified_wC_signal_grids.sh \
  submit_single_top_AcerMCPythia.sh
  submit_single_top_McAtNloJimmy.sh
  submit_ttbar_MadGraphPythia.sh
  submit_ttbar_McAtNloJimmy.sh
  submit_ttbar_PowhegPythia.sh
  )

for ftl in ${file_to_link[@]}
do
  echo $ftl
  ln -s ${PWD}/${ftl} ${SFRAME_DIR}/..
done
