#!/bin/bash
# ==============================================================================
# = Quick script to link all the relevant files to the top SusyFrame directory
# = This should be run from the grid_submit_scripts directory (i.e. where the
# = files actually live
# ==============================================================================


file_to_link=( \
  # helper scripts \
  prep_cutflow_tarball.sh \
  prep_presel_tarball.sh \
  submit_all_samples.sh \
  submit_cutflow.sh \
  submit_presel.sh \
  grid_build.sh \
  grid_run_cutflow.sh \
  grid_run_presel.sh \
  gen_job_config.py \

  # data submit scripts \
  submit_egamma_data.sh \
  submit_muon_data.sh \

  # background submit scripts \
  submit_W_plus_jet__AlpgenJimmy.sh \
  submit_higgs__PowhegPythia.sh \
  submit_higgs__Pythia.sh \
  submit_single_top__McAtNloJimmy.sh \
  submit_triboson__MadGraphPythia.sh \
  submit_ttbar__MadGraphPythia.sh \
  submit_ttbar__McAtNloJimmy.sh \
  submit_WW__Jimmy.sh \
  submit_WW__MadGraphPythia.sh \
  submit_WW__PowhegPythia8.sh \
  submit_WW__Sherpa.sh \
  submit_WZ__PowhegPythia8.sh \
  submit_Z_plus_jet_alpgen.sh \
  submit_Z_plus_jet__Sherpa.sh \
  submit_ZX__AlpgenPythia.sh \
  submit_ZX__Sherpa.sh \
  submit_ZZ__Jimmy.sh \
  submit_ZZ__PowhegPythia8.sh \
  submit_ZZ__Sherpa.sh \

  # signal submit scripts \
  submit_pmssm_signal_grids.sh \
  submit_simplified_wA_signal_grids.sh \
  submit_simplified_wC_signal_grids.sh \
  )

for ftl in ${file_to_link[@]}
do
  echo $ftl
  ln -s ${PWD}/${ftl} ${SFRAME_DIR}/..
done

