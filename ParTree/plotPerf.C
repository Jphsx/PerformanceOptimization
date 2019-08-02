/*
running Serial program with ttreereader
root -l -b -q r6_TreeProcessing.c
times:  [10.0, 9.0, 10.0, 10.0, 9.0, 10.0, 9.0, 10.0, 9.0, 10.0]
mean:  9.6 [s] stdev:  0.516397779494  [s]

running Serial program with ttreereader compiled
./compiledSerialr6
times:  [9.0, 9.0, 10.0, 9.0, 9.0, 9.0, 9.0, 9.0, 10.0, 9.0]
mean:  9.2 [s] stdev:  0.421637021356  [s]

/////// Interpreted
running  2  threads
root -l -b -q "imt101_ParTreeProcessing.c(2)"
times:  [6.0, 7.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 7.0]
mean:  6.2 [s] stdev:  0.421637021356  [s]
 
running  4  threads
root -l -b -q "imt101_ParTreeProcessing.c(4)"
times:  [11.0, 11.0, 12.0, 9.0, 11.0, 12.0, 12.0, 12.0, 11.0, 12.0]
mean:  11.3 [s] stdev:  0.948683298051  [s]
 
running  6  threads
root -l -b -q "imt101_ParTreeProcessing.c(6)"
times:  [8.0, 8.0, 8.0, 9.0, 10.0, 9.0, 11.0, 6.0, 8.0, 7.0]
mean:  8.4 [s] stdev:  1.42984070597  [s]
 
running  8  threads
root -l -b -q "imt101_ParTreeProcessing.c(8)"
times:  [9.0, 10.0, 10.0, 10.0, 9.0, 10.0, 10.0, 9.0, 9.0, 10.0]
mean:  9.6 [s] stdev:  0.516397779494  [s]
 
running  10  threads
root -l -b -q "imt101_ParTreeProcessing.c(10)"
times:  [9.0, 9.0, 9.0, 8.0, 9.0, 10.0, 9.0, 8.0, 10.0, 10.0]
mean:  9.1 [s] stdev:  0.737864787373  [s]
 
running  12  threads
root -l -b -q "imt101_ParTreeProcessing.c(12)"
times:  [10.0, 10.0, 9.0, 11.0, 12.0, 11.0, 10.0, 10.0, 10.0, 10.0]
mean:  10.3 [s] stdev:  0.823272602349  [s]
 
running  14  threads
root -l -b -q "imt101_ParTreeProcessing.c(14)"
times:  [11.0, 10.0, 10.0, 10.0, 10.0, 10.0, 9.0, 9.0, 10.0, 9.0]
mean:  9.8 [s] stdev:  0.632455532034  [s]
 
running  16  threads
root -l -b -q "imt101_ParTreeProcessing.c(16)"
times:  [10.0, 10.0, 9.0, 10.0, 10.0, 10.0, 9.0, 9.0, 9.0, 9.0]
mean:  9.5 [s] stdev:  0.527046276695  [s]
 
running  18  threads
root -l -b -q "imt101_ParTreeProcessing.c(18)"
times:  [10.0, 10.0, 11.0, 10.0, 10.0, 10.0, 9.0, 9.0, 10.0, 9.0]
mean:  9.8 [s] stdev:  0.632455532034  [s]
 
running  20  threads
root -l -b -q "imt101_ParTreeProcessing.c(20)"
times:  [10.0, 9.0, 10.0, 10.0, 10.0, 11.0, 11.0, 9.0, 8.0, 10.0]
mean:  9.8 [s] stdev:  0.918936583473  [s]

////// Compiled
running  2  threads Compiled
./compiledThreads 2
times:  [5.0, 5.0, 6.0, 6.0, 5.0, 5.0, 5.0, 5.0, 6.0, 5.0]
mean:  5.3 [s] stdev:  0.48304589154  [s]
 
running  4  threads Compiled
./compiledThreads 4
times:  [4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0]
mean:  4.0 [s] stdev:  0.0  [s]
 
running  6  threads Compiled
./compiledThreads 6
times:  [4.0, 5.0, 3.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0]
mean:  4.0 [s] stdev:  0.471404520791  [s]
 
running  8  threads Compiled
./compiledThreads 8
times:  [4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0]
mean:  4.0 [s] stdev:  0.0  [s]
 
running  10  threads Compiled
./compiledThreads 10
times:  [4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0]
mean:  4.0 [s] stdev:  0.0  [s]
 
running  12  threads Compiled
./compiledThreads 12
times:  [4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0]
mean:  4.0 [s] stdev:  0.0  [s]
 
running  14  threads Compiled
./compiledThreads 14
times:  [4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0]
mean:  4.0 [s] stdev:  0.0  [s]
 
running  16  threads Compiled
./compiledThreads 16
times:  [4.0, 5.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0]
mean:  4.1 [s] stdev:  0.316227766017  [s]
 
running  18  threads Compiled
./compiledThreads 18
times:  [4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 5.0, 4.0, 4.0, 4.0]
mean:  4.1 [s] stdev:  0.316227766017  [s]
 
running  20  threads Compiled
./compiledThreads 20
times:  [4.0, 4.0, 4.0, 4.0, 5.0, 4.0, 4.0, 4.0, 4.0, 4.0]
mean:  4.1 [s] stdev:  0.316227766017  [s]
  */

int plotPerf(){

	//Interpreted arrays
	//0 threads = serial program
	double nthreads_int []= {0, 2,4,6,8,10,12,14,16,18,20};
	double times_int [] = { 9.6, 6.2, 11.3, 8.4, 9.6, 9.1, 10.3, 9.8, 9.5, 9.8, 9.8};
	double timeserr_int [] = {0.5,0.4,0.9,1.4,0.5,0.7,0.8,0.6,0.5,0.6,0.9}; 
	double timeserrx_int [] = {0,0,0,0,0,0,0,0,0,0,0};
	int n = 11;

	double times_com [] = { 9.2, 5.3, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.1, 4.1, 4.1};
	double timeserr_com [] = {0.4, 0.5, 0, 0.5, 0,0,0,0,0.3,0.3,0.3 };

   TCanvas *c1 = new TCanvas("c1","test 1 performance",200,10,500,300);

   TGraphErrors* gr = new TGraphErrors(n,nthreads_int,times_int,timeserrx_int, timeserr_int);
  // gr->Draw("AC*");

   TGraphErrors* gr_c = new TGraphErrors(n,nthreads_int, times_com, timeserrx_int, timeserr_com);
	

	gr->SetMarkerStyle(21);
	gr->SetLineColor(2);
	gr->SetTitle("Root Interpreter");
	gr_c->SetMarkerStyle(20);
	gr_c->SetLineColor(4);
	gr_c->SetTitle("Compiled");

	

	//TGraph *gr1 = new TGraph(...
//TGraphErrors *gr2 = new TGraphErrors(...
TMultiGraph *mg = new TMultiGraph();
mg->Add(gr,"lp");
mg->Add(gr_c,"cp");

mg->SetTitle("Parallel Processing Time;nThreads;Time [s]");

mg->Draw("AC*");

 c1->BuildLegend();

return 0;

}

