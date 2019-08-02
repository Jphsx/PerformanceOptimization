//#include "TROOT.h"
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
//#include "TLorentzVector.h"
//storage for threaded objects
//std::vector<ROOT::TThreadedObject<TH1F> > th1vec{};
//std::vector<ROOT::TThreadedObject<TH2F> > th2vec{};
/*
void CreateThreadObject(std::string varname, std::string title, int nbins, double xlow, double xup){
	ROOT::TThreadedObject<TH1D> threadHist(varname.c_str(), title.c_str(), nbins, xlow, xup);
	th1vec.push_back( threadHist );
}
void CreateThreadObject(std::string varname, std::string title, int nbinsx, double xlow, double xup, int nbinsy, double ylow, double yup){
	ROOT::TThreadedObject<TH2D> threadHist(varname.c_str(), title.c_str(), nbinsx, xlow, xup , nbinsy, xlow, xup);
	th2vec.push_back( threadHist );
}
*/
/*void BookkeepThreadObject( ROOT::TThreadedObject<TH1F> threadHist ){
	th1vec.push_back( threadHist);
}
void BookkeepThreadObject( ROOT::TThreadedObject<TH2F> threadHist) {
	th2vec.push_back( threadHist);
}
void WriteThreadedObjects( ){


	for(unsigned int i =0; i< th1vec.size(); i++){
		TH1D  *h1D = (TH1D*)( th1vec.at(i).Merge()->Clone());
	}
	for(unsigned int i =0; i< th2vec.size(); i++){
		TH2D *h2d = (TH2D*)( th2vec.at(i).Merge()->Clone());
	}
}*/

//int imt101_ParTreeProcessing(int nthreads)
int main(int argc, char *argv[])
{
	int nthreads = std::atoi (argv[1]);
   // First enable implicit multi-threading globally, so that the implicit parallelisation is on.
   // The parameter of the call specifies the number of threads to use.
   //int nthreads = 4;
   ROOT::EnableImplicitMT(nthreads);


		
   // Create one TThreadedObject per histogram to fill during the processing of the tree
 //  ROOT::TThreadedObject<TH1F> ptHist("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
 //  ROOT::TThreadedObject<TH1F> pzHist("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
 //  ROOT::TThreadedObject<TH2F> pxpyHist("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);

/*
	CreateThreadObject("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
	CreateThreadObject("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
	CreateThreadObject("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);
*/

   ROOT::TThreadedObject<TH1D> ptHist("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
   ROOT::TThreadedObject<TH1D> pzHist("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
   ROOT::TThreadedObject<TH2D> pxpyHist("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);
 //  BookkeepThreadObject( ptHist);
  // BookkeepThreadObject( pzHist);
  // BookkeepThreadObject( pxpyHist);

   // Create a TTreeProcessorMT: specify the file and the tree in it
   ROOT::TTreeProcessorMT tp("tp_process_imt.root", "events");
   // Define the function that will process a subrange of the tree.
   // The function must receive only one parameter, a TTreeReader,
   // and it must be thread safe. To enforce the latter requirement,
   // TThreadedObject histograms will be used.
   auto myFunction = [&](TTreeReader &myReader) {
     TTreeReaderValue<std::vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > > > tracksRV(myReader, "tracks");
//	TTreeReaderValue<std::vector<TLorentzVector>> tracksRV(myReader, "tracks");
      // For performance reasons, a copy of the pointer associated to this thread on the
      // stack is used
      auto myPtHist = ptHist.Get();
      auto myPzHist = pzHist.Get();
      auto myPxPyHist = pxpyHist.Get();
	

      while (myReader.Next()) {
         auto tracks = *tracksRV;
         for (auto &&track : tracks) {
            myPtHist->Fill(track.Pt(), 1. / track.Pt());
            myPxPyHist->Fill(track.Px(), track.Py());
            myPzHist->Fill(track.Pz());
         }
      }
   };
   // Launch the parallel processing of the tree
   tp.Process(myFunction);
   // Use the TThreadedObject::Merge method to merge the thread private histograms
   // into the final result
	
   auto ptHistMerged = ptHist.Merge();
   auto pzHistMerged = pzHist.Merge();
   auto pxpyHistMerged = pxpyHist.Merge();
   


 // ptHistMerged->DrawCopy();
	TFile* outfile = new TFile("test1.root","RECREATE");
	//WriteThreadedObjects();
	TH1D* hpt = (TH1D*)ptHistMerged->Clone();
	TH1D* hpz = (TH1D*)pzHistMerged->Clone();
	TH2D* hpxpy = (TH2D*)pxpyHistMerged->Clone();
	outfile->Write();

	
   return 0;
}
