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

numFiles = int(sys.argv[1]) 
ifile = 1

#nthreads = sys.argv[2]


if (numFiles == 0 ):
	numFiles = len(idatafiles)
print( "from runmacro numFiles == ", numFiles)
#cmd = "./compiledThreads "+str(nthreads)
for f in idatafiles:
	if (ifile <= numFiles):
		pathsplit = f.split("/")
		namesplit = pathsplit[-1].split(".")
		tag = namesplit[0]
	
		#cmd ="root -l -b -q \"imt101_ParTreeProcessing.c("+str(nthreads)+", \\\""+f+"\\\")\""
		#cmd = "root -l -b -q \"classic_TreeProcessing.c(\\\""+f+"\\\",\\\"./classicFiles/"+tag+".root\\\")\"" 
		cmd = "./compiledClassic \""+f+"\" \""+tag+".root\""
		#cmd = "./compiledThreads "+str(nthreads)+" \""+f+"\""
		#cmd = cmd + "\""+f+"\" "
		print cmd 
		os.system(cmd)
	ifile = ifile + 1


PathToInput = "./classicFiles/"
OutputName = "combinedClassic.root"
PathToOutput = "./"
cmd = "ls "+PathToInput
LS = bash(cmd)
LS = LS[0].split('\n')
LS = [f for f in LS if ".root" in f]
cmd = "hadd -f "+PathToOutput+OutputName
for f in LS:
        cmd = cmd + " "+PathToInput+f.rstrip()

print cmd
os.system(cmd)


