#!/bin/bash

DATA_MC=mc
STREAM=egamma
VERSION_FLAG=presel.51

ds_list=( ##"Z_plus_jet.107650.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0"
          "Z_plus_jet.107651.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1"
          ##"Z_plus_jet.107652.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2"
          "Z_plus_jet.107653.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3"
          "Z_plus_jet.107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4"
          "Z_plus_jet.107655.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5"
        )

for sample in ${ds_list[@]}
do 
  echo '---------------------------------------'
  echo $sample
  ./gen_job_configs.sh --${DATA_MC} --${STREAM} --sample-name $sample --version ${VERSION_FLAG}
done

##
##
##ds_list=( "Z_plus_jet.128975.Sherpa_CT10_ZeeHeavyJets"
##          "Z_plus_jet.128976.Sherpa_CT10_ZmumuHeavyJets"
##          "Z_plus_jet.128977.Sherpa_CT10_ZtautauHeavyJets"
##          "Z_plus_jet.146820.Sherpa_CT10_ZeeLightJets"
##          "Z_plus_jet.146821.Sherpa_CT10_ZmumuLightJets"
##          "Z_plus_jet.146822.Sherpa_CT10_ZtautauLightJets"
##        )
##
##for sample in ${ds_list[@]}
##do 
##  echo '---------------------------------------'
##  echo $sample
##  ./gen_job_configs.sh --${DATA_MC} --${STREAM} --af2 --sample-name $sample
##done
