#!/usr/bin/env python
"""
Find the latest GRL in the GRLs directory.
"""

import sys
import os.path
import subprocess
import optparse
import time

# ----------------------------------------------------------------------------
def find_latest_grl(grl_tag = 'All_Good'):
  # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  path = os.environ['SFRAME_DIR']
  path = path[0:path.find('/SFrame')]
  path = '%s/data/' % path

  file_list = os.listdir(path)

  susy_grls = []
  for fname in sorted(file_list):
    if not fname.find(grl_tag) == -1:
      susy_grls.append(fname)

  return '%s%s' % (path, susy_grls[-1])

# ----------------------------------------------------------------------------
def main():
  # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  print find_latest_grl()

# ============================================================================
if __name__ == "__main__":
  sys.exit( main() )
