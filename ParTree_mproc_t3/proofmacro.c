
#include "TProof.h"
#include "TChain.h"


int main(int argc, char *argv[]){
//argv is the list of files to be input by a python macro

	//std::vector<std::string> ifiles{};
	TProof::Open("");
	TChain* chain = new TChain("MyNtupleMaking/PhotonConversionsTree");
	for(int i=1; i< argc; i++){
//		ifiles.push_back(argv[i]);
		chain->AddFile(argv[i]);
	}

	chain->SetProof();//set number of slaves?

	chain->Process("MySelector.C");



}
