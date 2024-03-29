/*
running 2 threads -- running over all datalist - COMPILED
times:  [41.0, 15.0, 16.0, 14.0, 14.0]
mean:  20.0 [s] stdev:  11.7686022959  [s]
 
running 4 threads -- running over all datalist - COMPILED
times:  [9.0, 9.0, 8.0, 9.0, 9.0]
mean:  8.8 [s] stdev:  0.4472135955  [s]
 
running 6 threads -- running over all datalist - COMPILED
times:  [7.0, 7.0, 8.0, 7.0, 7.0]
mean:  7.2 [s] stdev:  0.4472135955  [s]
 
running 8 threads -- running over all datalist - COMPILED
times:  [6.0, 7.0, 8.0, 7.0, 7.0]
mean:  7.0 [s] stdev:  0.707106781187  [s]
 
running 10 threads -- running over all datalist - COMPILED
times:  [6.0, 7.0, 7.0, 8.0, 7.0]
mean:  7.0 [s] stdev:  0.707106781187  [s]
 
running 12 threads -- running over all datalist - COMPILED
times:  [7.0, 8.0, 8.0, 23.0, 9.0]
mean:  11.0 [s] stdev:  6.74536878162  [s]
 
running 14 threads -- running over all datalist - COMPILED
times:  [9.0, 8.0, 8.0, 9.0, 8.0]
mean:  8.4 [s] stdev:  0.547722557505  [s]
 
running 16 threads -- running over all datalist - COMPILED
times:  [10.0, 8.0, 10.0, 9.0, 10.0]
mean:  9.4 [s] stdev:  0.894427191  [s]
 
running 18 threads -- running over all datalist - COMPILED
times:  [11.0, 10.0, 10.0, 24.0, 16.0]
mean:  14.2 [s] stdev:  6.0166435826  [s]
 
running 20 threads -- running over all datalist - COMPILED
times:  [16.0, 12.0, 15.0, 11.0, 11.0]
mean:  13.0 [s] stdev:  2.34520787991  [s]

Serial MODE
./compiledSerialr6
times:  [30.0, 24.0, 36.0, 24.0, 25.0]
mean:  27.8 [s] stdev:  5.21536192416  [s]


Classic serial Interpeted:


*/

int plotPerf(){

	//Interpreted arrays
	//0 threads = serial program
	double nthreads_int []= {0, 2,4,6,8,10,12,14,16,18,20};
//	double times_int [] = { 9.6, 6.2, 11.3, 8.4, 9.6, 9.1, 10.3, 9.8, 9.5, 9.8, 9.8};
//	double timeserr_int [] = {0.5,0.4,0.9,1.4,0.5,0.7,0.8,0.6,0.5,0.6,0.9}; 
	double timeserrx_int [] = {0,0,0,0,0,0,0,0,0,0,0};
	int n = 11;

	double times_com [] = { 27.8, 15.2, 18.2, 7.6, 6.8, 7.2, 9.8, 8.2, 9.0, 10.2, 11.2};
	double timeserr_com [] = { 5.2, 1.1, 15.9, 0.5, 0.4, 0.4, 2.5, 0.8, 0.0, 1.1, 0.8 };

	//n trials
	double rn = sqrt(5);
	for(int i=0; i<n; i++){
		timeserr_com[i] = timeserr_com[i]/rn;
	}

	double nthreads_classic [] = {0};
	double timeserrx_classic [] = {0};
	double times_classic_int = {265.4 };
	double timeserr_classic_int = {20.6 };
	int n_classic = 1;
	double times_classic_com = { };
	double timeserr_classic_com = { };

   TCanvas *c1 = new TCanvas("c1","test 1 performance",200,10,500,300);

  // TGraphErrors* gr = new TGraphErrors(n,nthreads_int,times_int,timeserrx_int, timeserr_int);
  // gr->Draw("AC*");

   TGraphErrors* gr_c = new TGraphErrors(n,nthreads_int, times_com, timeserrx_int, timeserr_com);
//  TGraphErrors* gr_classic_int = new TGraphErrors(n_classic, nthreads_classic, times_classic_int, timeserrx_classic, timeserr_classic_int);
//  TGraphErrors* gr_classic_com = new TGraphErrors(n_classic, nthreads_classic, times_classic_com, timeserrx_classic, timeserr_classic_com);

	

//	gr->SetMarkerStyle(21);
//	gr->SetLineColor(2);
//	gr->SetTitle("Root Interpreter");
	gr_c->SetMarkerStyle(20);
	gr_c->SetLineColor(4);
	gr_c->SetTitle("Compiled");

	

	//TGraph *gr1 = new TGraph(...
//TGraphErrors *gr2 = new TGraphErrors(...
TMultiGraph *mg = new TMultiGraph();
//mg->Add(gr,"lp");
mg->Add(gr_c,"cp");

mg->SetTitle("Parallel Processing Time;nThreads;Time [s]");

mg->Draw("AC*");

 c1->BuildLegend();



  double ntracks [] = { 1547322., 950444., 602330., 347156., 1958272., 2968340., 1299172., 832024., 3685896. };
  double ntracksum [9];
  double ntrackserr [] = { 0,0,0,0,0,0,0,0,0};
	int nfiles = 9;

	//accumulate the tracks
	ntracksum[0] = ntracks[0];
	double accum = 0.;
	for(int i=1; i<9; i++){
		for(int j=0; j<=i; j++){
			accum = accum + ntracks[j];
		}
		ntracksum[i] = accum;
		accum = 0.;
	}

	double times_size_par [] = {3, 3, 3.6, 4.2, 4.4, 5.0, 5.6, 5.8, 9.6 };	
	double timeserr_size_par [] = { 0.7, 0, 0.5, 1.1, 0.5, 1, 0.5, 0.4, 3.6};


	double times_size_ser [] = {4.4, 6.0, 10.4, 7.8, 12.0, 15.0, 22.8, 17.4, 28.2};
	double timeserr_size_ser [] = {0.5, 0, 7.6, 0.4, 2.3, 0 , 13.5, 0.9, 8.3};

	
   for(int i=0; i<9; i++){
		timeserr_size_par[i] = timeserr_size_par[i]/rn;
		timeserr_size_ser[i] = timeserr_size_ser[i]/rn;
	}

	TGraphErrors* g_size_par = new TGraphErrors(nfiles, ntracksum, times_size_par, ntrackserr, timeserr_size_par);
	TGraphErrors* g_size_ser = new TGraphErrors(nfiles, ntracksum, times_size_ser, ntrackserr, timeserr_size_ser);


	g_size_par->SetMarkerStyle(21);
	g_size_par->SetLineColor(2);
	g_size_par->SetTitle("Compiled Parallel");
	g_size_ser->SetMarkerStyle(20);
	g_size_ser->SetLineColor(4);
	g_size_ser->SetTitle("Compiled Serial");


  TMultiGraph *mg2 = new TMultiGraph();
	mg2->Add(g_size_par,"lp");
	mg2->Add(g_size_ser,"cp");
	mg2->SetTitle("Processing Time With Varying Data Sizes;nTracks;Time[s]");
	

	

   TCanvas *c2 = new TCanvas("c2","test 3 performance",200,10,500,300);

	mg2->Draw("AC*");
	c2->BuildLegend();
return 0;

}

