#!/usr/bin/env python

# ------------------------------------------------------------------------------
def generateTarBallScript(tnt_tag):
    out_script = file('grid_jobs/grid_job_%s__0.sh' % tnt_tag, 'w')
    prun_command = """prun \
  --bexec="ls" \
  --exec="ls" \
  --useRootCore \
  --outTarBall=submit_tar.%(tnt_tag)s.tar.gz \
  --rootVer=5.34.07 \
  --cmtConfig=x86_64-slc5-gcc43-opt \

""" % {'tnt_tag':tnt_tag}

    print 'prun_command: %s' % prun_command
    out_script.write(prun_command)
    out_script.close()

  # --inDS=%(in_ds)s \
  # --outDS="user.bjackson.$(out_ds_tag)s.$(tnt_tag)s/" \
  # --outputs=Tnt.root \

# ------------------------------------------------------------------------------
def generateSubmitScript( in_ds
                        , out_ds_tag
                        , tnt_tag
                        , is_data
                        , is_full_mc
                        , submit_script_number
                        ):
    out_script = file('grid_jobs/grid_job_%s__%s.sh' % (tnt_tag, submit_script_number), 'w')

    print 'is_data: %s' % is_data
    print 'is_full_mc: %s' % is_full_mc
    prun_command = """prun \
  --bexec="scripts/GridSubmit/GridBuild.sh" \
  --exec="\source SetupEnvironment.sh ; \
          echo '------------------------------------------------------------------------------------' ; \
          ./scripts/RunTntMaker.py %(is_data)s %(is_full_mc)s %%IN ; \
          echo '------------------------------------------------------------------------------------' ; \
          ls ; " \
  --useRootCore \
  --inDS=%(in_ds)s \
  --outDS="user.bjackson.$(out_ds_tag)s.$(tnt_tag)s/" \
  --inTarBall=submit_tar.%(tnt_tag)s.tar.gz \
  --rootVer=5.34.07 \
  --cmtConfig=x86_64-slc5-gcc43-opt \
  --outputs=Tnt.root \

""" % {'in_ds':in_ds, 'tnt_tag':tnt_tag, 'is_data':is_data, 'is_full_mc':is_full_mc}

    print 'prun command: %s' % prun_command

    out_script.write(prun_command)
    out_script.close()

# ==============================================================================
if __name__ == '__main__':
    tnt_tag = 'tnt_test_100'

    generateTarBallScript(tnt_tag = tnt_tag)

    ds_dict = { 'ds':'mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/'
              , 'tag':'116600.gg2ZZJimmy_AUET2CT10_ZZ4lep'
              , 'is_data':0
              , 'is_full_mc':0
              }

    generateSubmitScript( in_ds = ds_dict['ds']
                        , out_ds_tag = ds_dict['tag']
                        , tnt_tag = tnt_tag
                        , is_data = ds_dict['is_data']
                        , is_full_mc = ds_dict['is_full_mc']
                        , submit_script_number = 1
                        )
