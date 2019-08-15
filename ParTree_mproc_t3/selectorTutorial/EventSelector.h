//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug  8 20:25:17 2019 by ROOT version 6.14/06
// from TTree EventTree/Tutorial tree
// found on file: eventdata.root
//////////////////////////////////////////////////////////

#ifndef EventSelector_h
#define EventSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

using namespace std;
// Headers needed by this particular selector


class EventSelector : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain



   TH1F *hfPosX =  new TH1F("hPosX", "Position in X", 20, -5, 5);
   // Readers to access the data (delete the ones you do not need).
   TTreeReaderArray<Double_t> fParticles_fPosX = {fReader, "fParticles.fPosX"};
   TTreeReaderArray<Double_t> fParticles_fPosY = {fReader, "fParticles.fPosY"};
   TTreeReaderArray<Double_t> fParticles_fPosZ = {fReader, "fParticles.fPosZ"};
   TTreeReaderArray<Double_t> fParticles_fMomentum = {fReader, "fParticles.fMomentum"};
   TTreeReaderArray<Double_t> fParticles_fMomentumPhi = {fReader, "fParticles.fMomentumPhi"};
   TTreeReaderArray<Double_t> fParticles_fMomentumEta = {fReader, "fParticles.fMomentumEta"};
   TTreeReaderValue<Int_t> fEventSize = {fReader, "fEventSize"};

	Int_t       fNumberOfEvents; // Total number of events

   EventSelector(TTree * = 0): fNumberOfEvents(0),hfPosX(0) {

	//hfPosX = new TH1F("hPosX", "Position in X", 20, -5, 5);	
   }

  // EventSelector(TTree * /*tree*/ =0) { }
   virtual ~EventSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(EventSelector,0);

};

#endif

#ifdef EventSelector_cxx
void EventSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);

 // hfPosX = new TH1F("hPosX", "Position in X", 20, -5, 5);
//   tree->SetBranchAddress("fParticles.fPosX", fParticlesPosX, &fParticlesPosXBranch);
//   tree->SetBranchAddress("fParticles.fMomentum", fParticlesMomentum, &fParticlesMomentumBranch);
  // hfPosX = new TH1F("hPosX", "Position in X", 20, -5, 5);
}

Bool_t EventSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef EventSelector_cxx
