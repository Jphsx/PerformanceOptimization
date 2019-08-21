#ifndef HISTS
#define HISTS


#include "TH1D.h"
#include "TH2D.h"
#include "ROOT/TThreadedObject.hxx"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "myselector.C"
#include "mytreevalues.c"
class histset{
	
	public:
	  // ROOT::TThreadedObject<TH1D> ptHist("ptHist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
  	  // ROOT::TThreadedObject<TH1D> pzHist("pzHist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
   	  // ROOT::TThreadedObject<TH2D> pxpyHist("pxpyHist", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);
	//	ROOT::TThreadedObject<TH1D> *ptHist;
	//	ROOT::TThreadedObject<TH1D> *pzHist;
		
	//	ROOT::TThreadedObject<TH2D> *pxpyHist;

	   histset();	
	   void init(); 

	   void AnalyzeEntry(myselector& s); 
	 //  void AnalyzeEntry(mytreevalues& s);

	   //bookeeping enumeration: (if we do this we dont need to worry about hist ptr copies and merging)
	   enum th1d_index{ind_ptHist, ind_pzHist, numTH1Hist};
	   enum th2d_index{ind_pxpyHist, numTH2Hist};


	   // make a big vector and load enumerated histograms onto the vector
	 std::vector<ROOT::TThreadedObject<TH1D>* >  TH1Manager{};
	 std::vector<ROOT::TThreadedObject<TH2D>* >  TH2Manager{};


	  //locate the histogram and perform ptr copying 
	  void FillTH1(int index, double x);
	  void FillTH2(int index, double x, double y);
	
	  void WriteHist(); 
};

histset::histset(){

	 std::vector<ROOT::TThreadedObject<TH1D>*>  Manager1(numTH1Hist);
	TH1Manager=Manager1;

	 std::vector<ROOT::TThreadedObject<TH2D>*>  Manager2(numTH2Hist);
	TH2Manager=Manager2;

	init();

	std::cout<<"num th2 "<< numTH2Hist<<std::endl;
}
void histset::init(){
	 // ptHist = new ROOT::TThreadedObject<TH1D>("ptHist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
         // pzHist = new ROOT::TThreadedObject<TH1D>("pzHist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
         // pxpyHist = new ROOT::TThreadedObject<TH2D>("pxpyHist", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);

//init TH1D
	TH1Manager.at(ind_ptHist) = new ROOT::TThreadedObject<TH1D>("ptHist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
	//TH1Manager.at(ind_pzHist) = new ROOT::TThreadedObject<TH1D>("pzHist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);

// init TH2D
        std::cout<<"init th2"<<std::endl;
	TH2Manager.at(ind_pxpyHist) = new ROOT::TThreadedObject<TH2D>("pxpyHist", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);


}
void histset::FillTH1(int index, double x){
	auto myhist = TH1Manager.at(index)->Get();
	myhist->Fill(x);
}
void histset::FillTH2(int index, double x, double y){
	std::cout<<"entered fill"<<std::endl;
	auto myhist = TH2Manager.at(index)->Get();
	myhist->Fill(x,y);
}
void histset::WriteHist(){

	TFile* outfile = new TFile("testset.root","RECREATE");

	for(int i=0; i<numTH1Hist-1; i++){
		auto histmerged = TH1Manager.at(i)->Merge();
		TH1D* h = (TH1D*) histmerged->Clone();
		outfile->WriteObject(h, h->GetName() );
	}
	

}
void histset::AnalyzeEntry(myselector& s){
//void histset::AnalyzeEntry(mytreevalues& s){
   //	int i=0;
    //    int j=0;
        double px,py,pz;
	//always make a local copy, if its a value dereference
	//have to auto& or myreader will try to register copy of the readerarray ptr
	auto& PC_vTrack_pt = s.PC_vTrack_pt;
	
	for(int i=0; i<PC_vTrack_pt.GetSize(); i++){
                for(int j=0; j<PC_vTrack_pt[i].size(); j++){
                        std::cout<<PC_vTrack_pt[i][j]<<" ";

                        FillTH1(ind_ptHist, PC_vTrack_pt[i][j]);
                }
        }

		
	
       // for( auto itr = s.PC_vTrack_pt.begin() ; itr != s.PC_vTrack_pt.end(); ++itr){
       		// for( auto itrj = itr->begin(); itrj != itr->end(); ++itrj){
       	// for( auto itr = s.PC_vTrack_pt->begin() ; itr != s.PC_vTrack_pt->end(); ++itr){
       	//	 for( auto itrj = itr->begin(); itrj != itr->end(); ++itrj){
//	for(int i	
//
  //          		px = (*(s.PC_vTrack_pt))[i][j] * cos( (*(s.PC_vTrack_phi))[i][j] );
    //        		py = (*(s.PC_vTrack_pt))[i][j] * sin( (*(s.PC_vTrack_phi))[i][j] );
      //      		pz = (*(s.PC_vTrack_pt))[i][j] * sinh( (*(s.PC_vTrack_eta))[i][j] );

        //        	FillTH1(ind_ptHist, (*(s.PC_vTrack_pt))[i][j]);
            //    	FillTH1(ind_pzHist, pz);
			
	//		std::cout<<"pxpypz"<<px<<" "<<py<<" "<<pz<<std::endl;	
          //     		FillTH2(ind_pxpyHist, px,py);
               // 	FillTH2(0,px,py);
          //              j++;
            //     }
              //   i++;
       	// }
	

}
#endif
