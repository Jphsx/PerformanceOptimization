import sys
import os
import subprocess

def bash( bashCommand ):
        process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
        #process = subprocess.Popen(bashCommand.split())
        output, error = process.communicate()
        return output ,error




#input file list
idatalist = open("data.list", "r")
#idatalist = open("datasmall.list", "r")


idatafiles = [f.rstrip() for f in idatalist if ".root" in f ]
print(idatafiles)


cmd = "./compiledproofmacro "
for ifile in idatafiles:
	cmd = cmd + idatafiles + " "


print cmd
os.system(cmd)
	
	
