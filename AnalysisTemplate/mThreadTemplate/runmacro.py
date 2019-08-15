import sys
import os
import subprocess

#input file list
idatalist = open("data.list", "r")
#idatalist = open("datasmall.list", "r")
#idatalist = open("bigdata.list", "r")

idatafiles = [f.rstrip() for f in idatalist if ".root" in f ]
print(idatafiles)

numFiles = int(sys.argv[1]) 
ifile = 1

nthreads = sys.argv[2]

if (numFiles == 0 ):
	numFiles = len(idatafiles)
print( "from runmacro numFiles == ", numFiles," nthreads == ",nthreads)
cmd = "./compiledthreads "+str(nthreads)+" "
 
for f in idatafiles:
	if (ifile <= numFiles):
		pathsplit = f.split("/")
		namesplit = pathsplit[-1].split(".")
		tag = namesplit[0]
	
		cmd = cmd + "\""+f+"\" "
	ifile = ifile + 1

print cmd
os.system(cmd)	
