#define testselector_cxx
// The class definition in testselector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("testselector.C")
// root> T->Process("testselector.C","some options")
// root> T->Process("testselector.C+")
//


#include "testselector.h"
#include <TH2.h>
#include <TStyle.h>

void testselector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
  outfile = new TFile("testmproc.root", "RECREATE");
   TString option = GetOption();
}

void testselector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
	ptHist = new TH1D("pt_dist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
	pzHist = new TH1D("pz_dist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
	pxpyHist= new TH2D("px_py", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);

		
	GetOutputList()->Add(ptHist);
	GetOutputList()->Add(pzHist);
	GetOutputList()->Add(pxpyHist);

}

Bool_t testselector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);



//  auto pt = PC_vTrack_pt.begin();
//  auto phi = PC_vTrack_phi.begin();
//  auto eta = PC_vTrack_eta.begin();

	double px,py,pz;
 //  for( pt ;  pt != PC_vTrack_pt.end() ; ++pt){
 int i=0;
 int j=0;
for( auto itr = PC_vTrack_pt.begin(); itr != PC_vTrack_pt.end(); ++itr){ 
	for( auto itrj = itr->begin(); itrj != itr->end(); ++itrj){	
//	px = *pt * cos(*phi);
  //	py = *pt * sin(*phi);
    //    pz = *pt * sinh(*eta);
	px = PC_vTrack_pt[i][j] * cos( PC_vTrack_phi[i][j] );
	py = PC_vTrack_pt[i][j] * sin( PC_vTrack_phi[i][j] );
	pz = PC_vTrack_pt[i][j] * sinh( PC_vTrack_eta[i][j] );
		
		ptHist->Fill(PC_vTrack_pt[i][j]);
		pzHist->Fill(pz);
		pxpyHist->Fill(px,py);
			j++;
	//	++eta;
	//	++phi;
		}
		i++;
	}

 
 		




   return kTRUE;
}

void testselector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void testselector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   //
   	//TFile* outtest = new TFile("test2mproc.root","RECREATE");
	//	ptHist->Draw();
	outfile->WriteObject(ptHist,"pt_dist");
		outfile->WriteObject(pzHist,"pz_dist");
		outfile->WriteObject(pxpyHist,"px_py");
	//	outfile->Write("px_py");

		//outfile->Write(ptHist);
}
