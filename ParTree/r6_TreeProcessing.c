
#include "TROOT.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include <vector>
#include "TFile.h"
#include "Math/GenVector/LorentzVector.h"


//int r6_TreeProcessing(){
int main(){
	TFile* outfile = new TFile("test0.root", "RECREATE");
	  TH1D* ptHist = new TH1D("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
	  TH1D* pzHist = new TH1D("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
	  TH2D* pxpyHist= new TH2D("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);
   // Open the file containing the tree.
   TFile *myFile = TFile::Open("tp_process_imt.root");
   // Create a TTreeReader for the tree, for instance by passing the
   // TTree's name and the TDirectory / TFile it is in.
   TTreeReader myReader("events", myFile);
   // The branch "px" contains floats; access them as myPx.
   TTreeReaderValue<std::vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > > > tracksRV(myReader, "tracks");
   // The branch "py" contains floats, too; access those as myPy.

   // Loop over all entries of the TTree or TChain.
   while (myReader.Next()) {
		auto tracks = *tracksRV;
		for (auto &&track : tracks) {
			ptHist->Fill(track.Pt(), 1. / track.Pt() );
			pxpyHist->Fill(track.Px(), track.Py() );
			pzHist->Fill(track.Pz());
		}
     

   }
  
	outfile->Write();

	



	return 0;
}
