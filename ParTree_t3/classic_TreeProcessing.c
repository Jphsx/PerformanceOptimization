
#include "testtree.C"
#include <iostream>

//int classic_TreeProcessing(std::string ifilename, std::string ofilename){
//int main(std::string ifilename, std::string ofilename){
int main(int argc, char* argv[]){

	std::string ifilename( argv[1] );
	std::string ofilename( argv[2] );
	testtree* t = new testtree(ifilename.c_str());
	
	TFile *outfile = new TFile(ofilename.c_str(), "RECREATE");
	
	  TH1D* ptHist = new TH1D("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
	  TH1D* pzHist = new TH1D("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
	  TH2D* pxpyHist= new TH2D("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);


   if (t->fChain == 0) return 0;

Long64_t nentries = t->fChain->GetEntriesFast();

Long64_t nbytes = 0, nb = 0;
for (Long64_t jentry=0; jentry<nentries;jentry++) {
   Long64_t ientry = t->LoadTree(jentry);
   if (ientry < 0) break;
   nb = t->fChain->GetEntry(jentry);   nbytes += nb;
   // if (Cut(ientry) < 0) continue;
	double px,py,pz;

	        std::vector<std::vector<double> > trackspt = *(t->PC_vTrack_pt);
        std::vector<std::vector<double> > trackseta = *(t->PC_vTrack_eta);
        std::vector<std::vector<double> > tracksphi = *(t->PC_vTrack_phi);

     for(unsigned int i=0; i<trackspt.size(); i++){
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

//loop here, for every entry pass the tree to the histogramming macro
outfile->Write();
return 0;
}


