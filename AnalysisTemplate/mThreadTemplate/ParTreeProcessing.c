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
#include "histset.c"
#include "myselector.C"
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


/*	TFile *ifile = new TFile(ifilename.c_str()); 
	TDirectory * idir = (TDirectory*)ifile->Get((ifilename+":/MyNtupleMaking").c_str());
	TTree *tree;
	idir->GetObject("PhotonConversionsTree", tree);	
*/
//	std::cout<<"test print tree"<<std::endl;
//	tree->Print();		
   // Create one TThreadedObject per histogram to fill during the processing of the tree
 //  ROOT::TThreadedObject<TH1F> ptHist("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
 //  ROOT::TThreadedObject<TH1F> pzHist("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
 //  ROOT::TThreadedObject<TH2F> pxpyHist("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);

/*
	CreateThreadObject("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
	CreateThreadObject("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
	CreateThreadObject("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);
*/

 //  ROOT::TThreadedObject<TH1D> ptHist("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
 //  ROOT::TThreadedObject<TH1D> pzHist("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
 //  ROOT::TThreadedObject<TH2D> pxpyHist("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);

	histset h;
 //  BookkeepThreadObject( ptHist);
  // BookkeepThreadObject( pzHist);
  // BookkeepThreadObject( pxpyHist);

   // Create a TTreeProcessorMT: specify the file and the tree in it
//   ROOT::TTreeProcessorMT tp("tp_process_imt.root", "events");
 //   ROOT::TTreeProcessorMT tp( *tree);THIS CONSTRUCTOR DOESNT WORK :(((((
   // ROOT::TTreeProcessorMT tp(ifilename,"MyNtupleMaking/PhotonConversionsTree");
   ROOT::TTreeProcessorMT tp(ifilelist,"MyNtupleMaking/PhotonConversionsTree");
   // Define the function that will process a subrange of the tree.
   // The function must receive only one parameter, a TTreeReader,
   // and it must be thread safe. To enforce the latter requirement,
   // TThreadedObject histograms will be used.
   //
 //  std::cout<<"here"<<std::endl;
   auto myFunction = [&](TTreeReader &myReader) {
    // TTreeReaderValue<std::vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > > > tracksRV(myReader, "tracks");
//    std::cout<<"declare values"<<std::endl;
    //	TTreeReaderValue< std::vector<std::vector<double> > > tracksptRV(myReader, "PC_vTrack_pt");
//	TTreeReaderValue< std::vector<std::vector<double> > > tracksetaRV(myReader, "PC_vTrack_eta");
//	TTreeReaderValue< std::vector<std::vector<double> > > tracksphiRV(myReader, "PC_vTrack_phi");
//	myselector s = new myselector(myReader);
        myselector s;

//	TTreeReaderValue<std::vector<TLorentzVector>> tracksRV(myReader, "tracks");
      // For performance reasons, a copy of the pointer associated to this thread on the
      // stack is used
    //  auto myPtHist = ptHist.Get();
    //  auto myPzHist = pzHist.Get();
    //  auto myPxPyHist = pxpyHist.Get();
	auto myPtHist = h.ptHist->Get();
	auto myPzHist = h.pzHist->Get();
	auto myPxPyHist = h.pxpyHist->Get();

	
	double px,py,pz;
//std::cout<<"about to loop"<<std::endl;
      while (myReader.Next()) {
        // auto tracks = *tracksRV;
//	 auto trackspt = *tracksptRV;
//	 auto trackseta = *tracksetaRV;
  //	 auto tracksphi = *tracksphiRV;
	std::vector<std::vector<double> > trackspt = *(s.PC_vTrack_pt);
	std::vector<std::vector<double> > trackseta = *(s.PC_vTrack_eta);
	std::vector<std::vector<double> > tracksphi = *(s.PC_vTrack_phi);

/*         for (auto &&track : tracks) {
            myPtHist->Fill(track.Pt(), 1. / track.Pt());
            myPxPyHist->Fill(track.Px(), track.Py());
            myPzHist->Fill(track.Pz());
         }
*/
	
	for( unsigned int i=0; i<trackspt.size(); i++){
		for( unsigned int j=0; j<trackspt.at(i).size(); j++){
			px = trackspt.at(i).at(j) * cos(tracksphi.at(i).at(j));
			py = trackspt.at(i).at(j) * sin(tracksphi.at(i).at(j));
			pz = trackspt.at(i).at(j) * sinh(trackseta.at(i).at(j));
//			std::cout<<"px py pz"<<px<<" "<<py<<" "<<pz<<std::endl;
			myPtHist->Fill( trackspt.at(i).at(j), 1./ trackspt.at(i).at(j) );
			myPxPyHist->Fill(px,py);
			myPzHist->Fill(pz);
		}
	}
	
      }
   };
//	std::cout<<"launch function"<<std::endl;
   // Launch the parallel processing of the tree
   tp.Process(myFunction);
   // Use the TThreadedObject::Merge method to merge the thread private histograms
   // into the final result
	
   auto ptHistMerged = h.ptHist->Merge();
   auto pzHistMerged = h.pzHist->Merge();
   auto pxpyHistMerged = h.pxpyHist->Merge();
   


 // ptHistMerged->DrawCopy();
	TFile* outfile = new TFile("test1.root","RECREATE");
	//WriteThreadedObjects();
	TH1D* hpt = (TH1D*)ptHistMerged->Clone();
	TH1D* hpz = (TH1D*)pzHistMerged->Clone();
	TH2D* hpxpy = (TH2D*)pxpyHistMerged->Clone();
	outfile->Write();

	
   return 0;
}
