//#include "TROOT.h"
//
#ifndef PARTREE
#define PARTREE

#include "TH1D.h"
#include "TH2D.h"
#include "ROOT/TThreadedObject.hxx"
//#include "ROOT/Math/GenVector/LorentzVector.h"
#include "Math/GenVector/LorentzVector.h"

#include "ROOT/TTreeProcessorMT.hxx"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include <vector>
#include "TFile.h"
#include "histset.c"
#include "myselector.C"
#include "mytreevalues.c"
#include <iostream>
//#include "mytreevalues.c"
//#include "TLorentzVector.h"
//storage for threaded objects
//std::vector<ROOT::TThreadedObject<TH1F> > th1vec{};
//std::vector<ROOT::TThreadedObject<TH2F> > th2vec{};

int main(int argc, char *argv[])
{

   //set nthreads from first input argument
   int nthreads = std::atoi (argv[1]);
   // First enable implicit multi-threading globally, so that the implicit parallelisation is on.
   // The parameter of the call specifies the number of threads to use.
   ROOT::EnableImplicitMT(nthreads);

   std::vector<std::string_view> ifilelist{};
   for(int i=2; i<argc; i++){
	ifilelist.push_back(std::string_view(argv[i]));
   }

	histset h;

   ROOT::TTreeProcessorMT tp(ifilelist,"MyNtupleMaking/PhotonConversionsTree");
   // Define the function that will process a subrange of the tree.
   // The function must receive only one parameter, a TTreeReader,
   // and it must be thread safe. To enforce the latter requirement,
   // TThreadedObject histograms will be used.
   //
 //  std::cout<<"here"<<std::endl;
   auto myFunction = [&](TTreeReader &myReader) {

  // TTreeReaderArray<vector<double>> PC_vTrack_pt(myReader, "PC_vTrack_pt");
//   TTreeReaderArray<vector<double>> PC_vTrack_eta(myReader, "PC_vTrack_eta");
//   TTreeReaderArray<vector<double>> PC_vTrack_phi(myReader, "PC_vTrack_phi");
//     TTreeReaderValue< std::vector<std::vector<double> > > PC_vTrack_pt(myReader, "PC_vTrack_pt");

	myselector s;
//	s.fReader = std::move(myReader;
	s.Init(myReader.GetTree());
//  	mytreevalues s( myReader );
	
//	double px,py,pz;
//std::cout<<"about to loop"<<std::endl;
      while (myReader.Next()) {

	s.fReader.SetEntry(myReader.GetCurrentEntry());
	h.AnalyzeEntry(s); 
	//write analysis here:
	
       // int i=0;
       // int j=0;
  //      double px,py,pz;
//	std::vector<std::vector<double> > trackspt = *PC_vTrack_pt;
	//auto& trackspt = PC_vTrack_pt;	
       // for( auto itr = s.PC_vTrack_pt.begin() ; itr != s.PC_vTrack_pt.end(); ++itr){
                // for( auto itrj = itr->begin(); itrj != itr->end(); ++itrj){
        // for( auto itr = *PC_vTrack_pt.begin() ; itr != *PC_vTrack_pt.end(); ++itr){
          //       for( auto itrj = itr->begin(); itrj != itr->end(); ++itrj){
	//	for(int i = 0; i< trackspt.size(); i++){
	//		for( int j=0; j< trackspt[i].size(); j++){
	//		std::cout<<trackspt[i][j]<<" ";
	//		}
 	//	}	
/* this loop works 	 for(int i=0; i<PC_vTrack_pt.GetSize(); i++){
		for(int j=0; j<PC_vTrack_pt[i].size(); j++){
			//std::cout<<PC_vTrack_pt[i][j]<<" ";

			h.FillTH1(h.ind_ptHist, PC_vTrack_pt[i][j]);
		}
	}
*/

/*                        px = PC_vTrack_pt[i][j] * cos( PC_vTrack_phi[i][j] );
                        py = PC_vTrack_pt[i][j] * sin( PC_vTrack_phi[i][j] );
                        pz = PC_vTrack_pt[i][j] * sinh( PC_vTrack_eta[i][j] );

                        h.FillTH1(h.ind_ptHist, PC_vTrack_pt[i][j]);
                        h.FillTH1(h.ind_pzHist, pz);

                      std::cout<<"pxpypz"<<px<<" "<<py<<" "<<pz<<std::endl;   
          //                    FillTH2(ind_pxpyHist, px,py);
               //       FillTH2(0,px,py); */
              //          j++;
            //     }
          //       i++;

        // }
	

	
      }
   };
//	std::cout<<"launch function"<<std::endl;
   // Launch the parallel processing of the tree
//	std::cout<<"here"<<std::endl;
   tp.Process(myFunction);
   // Use the TThreadedObject::Merge method to merge the thread private histograms
   // into the final result
	
  
  h.WriteHist();
	
   return 0;
}
#endif

