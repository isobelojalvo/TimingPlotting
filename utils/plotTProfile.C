#include "TMathBase.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1.h"
#include "TF1.h"
#include <math.h>
#include <TEfficiency.h>
#include <TMath.h>
#include <iostream>
#include <string>

#include <iostream>
#include <cmath>
#include "TLegend.h"
#include "TPad.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2.h"
#include "TF1.h"
#include "THStack.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "TTree.h"
#include "TPaveText.h"
#include "tdrstyle.C"
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"


using namespace std;


Double_t erf( Double_t *x, Double_t *par){   //<===========
  return par[0]*sqrt(x[0]); //<===========
}

Double_t fitf(Double_t *x,Double_t *par)
{
  Double_t arg = 0;
  if (par[2] != 0) arg = (x[0] - par[1])/par[2];
  Double_t fitval = par[0]*TMath::Exp(-0.5*arg*arg);
  return fitval;
}


void applyPadStyle(TPad* pad1){
  pad1->SetFillColor(0);
  pad1->Draw();  pad1->cd();  pad1->SetLeftMargin(0.2);  pad1->SetBottomMargin(0.13); pad1->SetRightMargin(0.1);
  pad1->SetGrid(); 
}
void applyLegStyle(TLegend *leg){
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetHeader("");
  leg->SetShadowColor(0);
}

using namespace std;


Double_t erf( Double_t *x, Double_t *par){   //<===========
  return par[0]*sqrt(x[0]); //<===========
}

Double_t fitf(Double_t *x,Double_t *par)
{
  Double_t arg = 0;
  if (par[2] != 0) arg = (x[0] - par[1])/par[2];
  Double_t fitval = par[0]*TMath::Exp(-0.5*arg*arg);
  return fitval;
}


int plotTProfile(TString variable, TString fileName, TString outFileName, TString l1Cut, TString xaxis, TString yaxis, TString text, TString treePath, int bins, float low, float high){
  setTDRStyle();
  TFile *tauFile  = new TFile(fileName);
  
  if(!tauFile->IsOpen()||tauFile==0){
    std::cout<<"ERROR FILE "<< fileName<<" NOT FOUND; EXITING"<<std::endl;
    return 0;
  }

  TTree* tauTreePre;
  tauTreePre = (TTree*) tauFile->Get(treePath);
  Long64_t nentries = tauTreePre->GetEntries(); 
  gROOT->cd();
  TTree* tauTree = tauTreePre->CopyTree(l1Cut,"",nentries); 
  tauTree->SetDirectory(0); //required to remove memory resident errors

  TCanvas *Tcan= new TCanvas("Tcan","",100,20,600,600); Tcan->cd();  Tcan->SetFillColor(0);
  TPad* pad1 = new TPad("pad1","The pad",0,0,0.98,1);
  applyPadStyle(pad1);
  TLegend *leg = new TLegend(0.25,0.75,0.55,0.99);//  Leg = new TLegend(0.74,0.65,0.99,0.95); 
  applyLegStyle(leg);

  //Draw recopt/l1pt 
  Double_t recoPt; Double_t isoCandsEt_, jetEt_, ecal, hcal, rawEcal, rawHcal; 
  Double_t l1Pt; Double_t tauEtaEcalEnt_;
  Int_t decayMode_;

  tauTree->SetBranchAddress("recoPt",&recoPt);
  tauTree->SetBranchAddress("jetEt",&jetEt_);
  tauTree->SetBranchAddress("decayMode",&decayMode_);
  tauTree->SetBranchAddress("isoCandsEt",&isoCandsEt_);
  tauTree->SetBranchAddress(variable,&l1Pt);
  tauTree->SetBranchAddress("tauEtaEcalEnt",&tauEtaEcalEnt_);
  tauTree->SetBranchAddress("ecal",&ecal);
  tauTree->SetBranchAddress("hcal",&hcal);
  tauTree->SetBranchAddress("rawEcal",&rawEcal);
  tauTree->SetBranchAddress("rawHcal",&rawHcal);
  
  TProfile *hprof  = new TProfile("hprof","Profile of pz versus px",bins,low,high,0,5);
  TString yAxis = yaxis;
  TString xAxis = xaxis;
  Double_t px, py, pz;
  for ( Int_t i=0; i<tauTree->GetEntries(); i++) {
    tauTree->GetEntry(i);
    //float ptEcal_ = ecal_ / TMath::CosH( tauEtaEcalEnt_ );
    //float ptHcal_ = hcal_ / TMath::CosH( tauEtaEcalEnt_ );
    //px = (tauEtaEcalEnt_);
    px = (l1Pt);
    pz = recoPt/l1Pt;
    //if(recoPt > 12 && l1Pt>8 && isoCandsEt_<2 && decayMode_==10){    
      hprof->Fill(px,pz,1);
      //}
  }
  std::cout<<"Y max "<< hprof->GetYmax()<<std ::endl;
  hprof->SetMaximum(2.5);
  hprof->Draw();
  hprof->GetXaxis()->SetTitle(xAxis);
  hprof->GetYaxis()->SetTitle(yAxis);
  //tauEt->Sumw2();
  

  TPaveText *pt = new TPaveText(30,1.5,42,2);
  pt->AddText(text);
  //pt->AddText(text1.c_str());
  //pt->AddText(text2.c_str());
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetBorderSize(0);
  pt->SetShadowColor(0);
  pt->Draw();

  //Num->SetLineColor(kBlue);  Num->SetFillColor(kBlue);
  //Num->SetFillStyle(3002);
  //Num->SetLineWidth(4);
  //Num->Fit(g1,"R");
  //Num->Fit(g2,"R+");
  //Num->Fit(g0,"R+");
  //Num->Fit(g,"R+");
  //Num->Sumw2();
  //Num->SetStats(0);

  Tcan->cd();
  Tcan->SaveAs(outFileName+".png");
}



