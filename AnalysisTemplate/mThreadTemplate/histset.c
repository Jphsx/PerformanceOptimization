#ifndef HISTS
#define HISTS


#include "TH1D.h"
#include "TH2D.h"
#include "ROOT/TThreadedObject.hxx"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
class histset{
	
	public:
	  // ROOT::TThreadedObject<TH1D> ptHist("ptHist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
  	  // ROOT::TThreadedObject<TH1D> pzHist("pzHist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
   	  // ROOT::TThreadedObject<TH2D> pxpyHist("pxpyHist", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);
		ROOT::TThreadedObject<TH1D> *ptHist;
		ROOT::TThreadedObject<TH1D> *pzHist;
		ROOT::TThreadedObject<TH2D> *pxpyHist;

	   histset();	
	   void init();  
	
};

histset::histset(){
	init();
}
void histset::init(){
	  ptHist = new ROOT::TThreadedObject<TH1D>("ptHist", "p_{T} Distribution;p_{T};dN/p_{T}dp_{T}", 100, 0, 5);
          pzHist = new ROOT::TThreadedObject<TH1D>("pzHist", "p_{Z} Distribution;p_{Z};dN/dp_{Z}", 100, 0, 5);
          pxpyHist = new ROOT::TThreadedObject<TH2D>("pxpyHist", "p_{X} vs p_{Y} Distribution;p_{X};p_{Y}", 100, -5., 5., 100, -5., 5.);

}
#endif
