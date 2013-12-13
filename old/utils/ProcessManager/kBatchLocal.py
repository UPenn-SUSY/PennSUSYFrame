#!/usr/bin/env python

import os
from subprocess import PIPE,STDOUT
from sys import stdout
import time   # time accounting
import subprocess # subprocessing

# ------------------------------------------------------------------------------
class kBatchLocal :
    def __init__(self,maxnjobs=15) :
        self.outfiles = []
        self.errfiles = []
        self.subprocs = []
        self.maxnjobs = maxnjobs
        self.start_time = time.time()

    def addJob(self,cmd,logname) :
        # command in list form
        self.outfiles.append(open(logname+'.log','w'))
        self.errfiles.append(open(logname+'.err','w'))
        self.outfiles[-1].write('\n\n'+' '.join(cmd)+'\n\n')
        self.poll()
        #print logname
        #print cmd
        self.subprocs.append(subprocess.Popen( cmd
                                             , shell=True
                                             , stdout=self.outfiles[-1]
                                             , stderr=self.errfiles[-1])
                                             )
        return

    def poll(self) :
        for i in range(1000000) :
            njobs = 0
            for subproc in self.subprocs :
                njobs += 1 if (subproc.poll() == None) else 0
            if njobs < self.maxnjobs :
                print 'njobs:',njobs,'. Adding.'
                break
            else :
                stdout.write("\rWaiting for jobs to clear: %d (%s)" % (njobs,GetInHMS(time.time() - self.start_time)))
                stdout.flush()
                time.sleep(5)
        return

    def wait(self) :
        for i in range(1000000) :
            nleft = 0
            for subproc in self.subprocs :
                nleft += 1 if (subproc.poll() == None) else 0
            if nleft == 0 :
                break
            else :
                stdout.write("\rJobs left: %d (%s)" % (nleftft,GetInHMS(time.time() - self.start_time)))
                stdout.stdoutflush()
                time.sleep(5)
        return



# ------------------------------------------------------------------------------
def GetInHMS(seconds):
    seconds = int(seconds)
    hours = seconds / 3600
    seconds -= 3600*hours
    minutes = seconds / 60
    seconds -= 60*minutes
    return "%02d:%02d:%02d" % (hours, minutes, seconds)

