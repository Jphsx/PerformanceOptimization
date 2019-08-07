import sys
import os
import subprocess
import math

def bash( bashCommand ):
        process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
        #process = subprocess.Popen(bashCommand.split())
        output, error = process.communicate()
        return output ,error



def mean( array ):
	return sum(array)/len(array)
def RMS( array):

	for i in range(len(array)):
		array[i] = array[i]*array[i]
#	print array
	return math.sqrt(sum(array)/len(array))
		
def stdev( array):
	avg = mean(array)
	for i in range(len(array)):
		array[i] = (avg - array[i])*(avg-array[i])
	return math.sqrt( (1./(float(len(array))-1.)) * sum(array) )

def runProcess(cmd):
	startTime = bash("date")

#print startTime
#print"run 4 threads (INTERPRETED)"
#cmd ="root -l -b -q \"imt101_ParTreeProcessing.c(4)\""
#print cmd
	os.system(cmd)

	endTime = bash("date")

#print endTime
	startTime = startTime[0].split(" ")
	endTime = endTime[0].split(" ")

	startTime.remove('')
	endTime.remove('')


	startTime = startTime[3].split(":")
	endTime = endTime[3].split(":")

	
	#convert all time to seconds

	startTime = float(startTime[0])*60.*60. + float(startTime[1])*60. + float(startTime[2])
	endTime = float(endTime[0])*60.*60. + float(endTime[1])*60. + float(endTime[2])
	deltaTime = endTime - startTime
#print deltaTime
	return deltaTime



#print "running 4 threads (INTERPRETED)"
#cmd ="root -l -b -q \"imt101_ParTreeProcessing.c(4)\"" 
#dTs = []
#for i in range(10):
#	deltaTime = runProcess(cmd)
#	dTs.append(deltaTime) 
	
#print "times: ", dTs
#print "mean: " , mean(dTs) ,"[s] stdev: " , stdev(dTs) ," [s]"



#run over a range of threads
#for nthreads in range(2,22,2):
#	print "running ",nthreads," threads"
#	cmd ="root -l -b -q \"imt101_ParTreeProcessing.c("+str(nthreads)+")\""
#	print cmd
#	dTs = []
#	for i in range(10):
#		deltaTime = runProcess(cmd)
#		dTs.append(deltaTime)

#	print "times: ", dTs
#	print "mean: " , mean(dTs) ,"[s] stdev: " , stdev(dTs) ," [s]"
#	print " "

#run over a range of threads with compiled code
#for nthreads in range(2,22,2):
#	print "running ",nthreads," threads Compiled"
#	cmd = "./compiledThreads "+str(nthreads)
#	print cmd
#	dTs = []
#	for i in range(10):
#		deltaTime = runProcess(cmd)
#		dTs.append(deltaTime)

#	print "times: ", dTs
#	print "mean: " , mean(dTs) ,"[s] stdev: " , stdev(dTs) ," [s]"
#	print " "


#run over TTreereader with 1 thread
#print "running Serial program with ttreereader"
#cmd = "root -l -b -q r6_TreeProcessing.c"
#print cmd
#dTs = []
#for i in range(10):
#	deltaTime = runProcess(cmd)
#	dTs.append(deltaTime)

#print "times: ", dTs
#print "mean: " , mean(dTs) ,"[s] stdev: " , stdev(dTs) ," [s]"
#print " "


#run over TTreerader with 1 thread COMPILED
#print "running Serial program with ttreereader compiled"
#cmd = "./compiledSerialr6"
#print cmd
#dTs = []
#for i in range(10):
#	deltaTime = runProcess(cmd)
#	dTs.append(deltaTime)
#
#print "times: ", dTs
#print "mean: " , mean(dTs) ,"[s] stdev: " , stdev(dTs) ," [s]"
#print " "


#CLUSTER LEVEL TESTS
#do nthreads test for entire file range
#for nthreads in range(2,22,2):
#	print "running", nthreads, "threads -- running over all datalist"
#	#run python file launch manager not the process directly
#	cmd = "python runmacro.py 0 "+str(nthreads)
#	dTs = []
#	for i in range(5):
#		deltaTime = runProcess(cmd)
#		dTs.append(deltaTime)
#	print "times: ", dTs
#	print "mean: ", mean(dTs), "[s] stdev: ", stdev(dTs) ," [s]"
#	print " "

#do nthreads test for entire file range with 
#for nthreads in range(2,22,2):
#	print "running", nthreads, "threads -- running over all datalist - COMPILED"
#	cmd = "python runmacro.py 0 "+str(nthreads)
#	dTs = []
#	for i in range(5):
#		deltaTime = runProcess(cmd)
#		dTs.append(deltaTime)
#	print "times: ", dTs
#	print "mean: ", mean(dTs), "[s] stdev: ", stdev(dTs), " [s]"
#	print " "

#do serial test for compiled
#cmd = "./compiledSerialr6"
#print cmd
#dTs = []
#for i in range(5):
#	deltaTime = runProcess(cmd)
#	dTs.append(deltaTime)
#print "times: ", dTs
#print "mean: ", mean(dTs) , "[s] stdev: ", stdev(dTs) ," [s]"
#print " "


#do serial test interpreted with classic approach
#cmd = "python runmacroclassic.py 0"
#print cmd
#dTs = []
#for i in range(5):
#	deltaTime = runProcess(cmd)
#	dTs.append(deltaTime)
#print "times: ", dTs
#print "mean: ", mean(dTs) , "[s] stdev: ", stdev(dTs) ," [s]"
#print " "


#do serial test compiled with classic approach
#cmd = "python runmacroclassic.py 0"
#print cmd
#dTs = []
#for i in range(5):
#	deltaTime = runProcess(cmd)
#	dTs.append(deltaTime)
#print "times: ", dTs
#print "mean: ", mean(dTs), "[s] stdev: ", stdev(dTs) ," [s]"
#print " "


#do parallel test compiled with varying datasize
for datasize in range(1,10,1):
	print "running", datasize, "datasize, multithreading compiled with 6 threads"
	cmd = "python runmacro.py "+str(datasize)+" 8"
	dTs = []
	for i in range(5):
		deltaTime = runProcess(cmd)
		dTs.append(deltaTime)
	print "times: ", dTs
	print "mean: ", mean(dTs), "[s] stdev: ", stdev(dTs) ," [s]"
	print " "

	
