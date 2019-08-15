


main: histset.o myselector.o ParTreeProcessing.c
	g++ -o compiledthreads -pthread ParTreeProcessing.c `root-config --cflags --libs`

histset.o: histset.c
	g++ -c -pthread histset.c `root-config --cflags --libs`

myselector.o: myselector.C myselector.h
	g++ -c -pthread myselector.C `root-config --cflags --libs` 

#mytreevalues.o: mytreevalues.c
#	g++ -c -pthread mytreevalues.c `root-config --cflags --libs`

clean:
	rm *.o
