g++ -o compiledThreads imt101_ParTreeProcessing.c -pthread `root-config --cflags --libs`

g++ -o compiledSerialr6 r6_TreeProcessing.c `root-config --cflags --libs`

g++ -o compiledClassic classic_TreeProcessing.c `root-config --cflags --libs` 
