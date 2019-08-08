//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug  1 14:58:46 2019 by ROOT version 6.14/06
// from TTree events/Fake events
// found on file: tp_process_imt.root
//////////////////////////////////////////////////////////

#ifndef testtree_h
#define testtree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "Math/GenVector/PxPyPzE4D.h"

class testtree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxtracks = 563;

   // Declaration of leaf types
   Int_t           tracks_;
   Double_t        tracks_fCoordinates_fX[kMaxtracks];   //[tracks_]
   Double_t        tracks_fCoordinates_fY[kMaxtracks];   //[tracks_]
   Double_t        tracks_fCoordinates_fZ[kMaxtracks];   //[tracks_]
   Double_t        tracks_fCoordinates_fT[kMaxtracks];   //[tracks_]
   Int_t           evtNum;

   // List of branches
   TBranch        *b_tracks_;   //!
   TBranch        *b_tracks_fCoordinates_fX;   //!
   TBranch        *b_tracks_fCoordinates_fY;   //!
   TBranch        *b_tracks_fCoordinates_fZ;   //!
   TBranch        *b_tracks_fCoordinates_fT;   //!
   TBranch        *b_evtNum;   //!

   testtree(TTree *tree=0);
   virtual ~testtree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef testtree_cxx
testtree::testtree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("tp_process_imt.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("tp_process_imt.root");
      }
      f->GetObject("events",tree);

   }
   Init(tree);
}

testtree::~testtree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t testtree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t testtree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void testtree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("tracks", &tracks_, &b_tracks_);
   fChain->SetBranchAddress("tracks.fCoordinates.fX", tracks_fCoordinates_fX, &b_tracks_fCoordinates_fX);
   fChain->SetBranchAddress("tracks.fCoordinates.fY", tracks_fCoordinates_fY, &b_tracks_fCoordinates_fY);
   fChain->SetBranchAddress("tracks.fCoordinates.fZ", tracks_fCoordinates_fZ, &b_tracks_fCoordinates_fZ);
   fChain->SetBranchAddress("tracks.fCoordinates.fT", tracks_fCoordinates_fT, &b_tracks_fCoordinates_fT);
   fChain->SetBranchAddress("evtNum", &evtNum, &b_evtNum);
   Notify();
}

Bool_t testtree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void testtree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t testtree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef testtree_cxx
