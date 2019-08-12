
#include "TROOT.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include <vector>
#include "TFile.h"
#include "Math/GenVector/LorentzVector.h"
#include "TChain.h"

//int r6_TreeProcessing(){
int main(int argc, char* argv[]){

//argv multiple 
	TFile* outfile = new TFile("test0.root", "RECREATE");
	  TH1D* ptHist = new TH1D("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
	  TH1D* pzHist = new TH1D("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
	  TH2D* pxpyHist= new TH2D("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);
   // Open the file containing the tree.

  // TFile *myFile = TFile::Open("tp_process_imt.root");
  	TChain* tc = new TChain("MyNtupleMaking/PhotonConversionsTree");

	//tc->Add("/home/t3-ku/janguian/performanceOptimization/PerformanceOptimization/ParTree_t3/datalinks/*.root");

	for(int i=1; i< argc; i++){
		tc->Add(argv[i]);
	}

   // Create a TTreeReader for the tree, for instance by passing the
   // TTree's name and the TDirectory / TFile it is in.
   TTreeReader myReader( tc);
   // The branch "px" contains floats; access them as myPx.
   //TTreeReaderValue<std::vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > > > tracksRV(myReader, "tracks");
           TTreeReaderValue< std::vector<std::vector<double> > > tracksptRV(myReader, "PC_vTrack_pt");
        TTreeReaderValue< std::vector<std::vector<double> > > tracksetaRV(myReader, "PC_vTrack_eta");
        TTreeReaderValue< std::vector<std::vector<double> > > tracksphiRV(myReader, "PC_vTrack_phi");

   // The branch "py" contains floats, too; access those as myPy.
double px,py,pz;
   // Loop over all entries of the TTree or TChain.
   while (myReader.Next()) {
/*		auto tracks = *tracksRV;
		for (auto &&track : tracks) {
			ptHist->Fill(track.Pt(), 1. / track.Pt() );
			pxpyHist->Fill(track.Px(), track.Py() );
			pzHist->Fill(track.Pz());
		}
*/    
	 std::vector<std::vector<double> > trackspt = *tracksptRV;
        std::vector<std::vector<double> > trackseta = *tracksetaRV;
        std::vector<std::vector<double> > tracksphi = *tracksphiRV;			

        for( unsigned int i=0; i<trackspt.size(); i++){
                for( unsigned int j=0; j<trackspt.at(i).size(); j++){
                        px = trackspt.at(i).at(j) * cos(tracksphi.at(i).at(j));
                        py = trackspt.at(i).at(j) * sin(tracksphi.at(i).at(j));
                        pz = trackspt.at(i).at(j) * sinh(trackseta.at(i).at(j));
//                      std::cout<<"px py pz"<<px<<" "<<py<<" "<<pz<<std::endl;
                        ptHist->Fill( trackspt.at(i).at(j), 1./ trackspt.at(i).at(j) );
                        pxpyHist->Fill(px,py);
                        pzHist->Fill(pz);
                }
        }

   }
  
	outfile->Write();

	



	return 0;
}
