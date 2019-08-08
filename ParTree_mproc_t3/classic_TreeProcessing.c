
#include "testtree.C"
#include <iostream>
void LoopTree(PCtree& t){



}
int classic_TreeProcessing.c(){


	testtree* t = new testtree("tp_process_imt.root");
	






void runmacro(std::string ifile, std::string ofile){


std::cout<<"using file: "<<ifile<<std::endl;

PCtree* t = new PCtree(ifile,"events");


//init histograms in separate hist macro
TFile* outfile = new TFile("test0classic.root", "RECREATE");
	  TH1D* ptHist = new TH1D("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
	  TH1D* pzHist = new TH1D("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
	  TH2D* pxpyHist= new TH2D("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);


   if (t.fChain == 0) return;

   Long64_t nentries = t.fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = t.LoadTree(jentry);
      if (ientry < 0) break;
      nb = t.fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

        hs->Fill();

   }

//loop here, for every entry pass the tree to the histogramming macro
LoopTree(*t,hs);
hs->ofile->Write();
}


}
