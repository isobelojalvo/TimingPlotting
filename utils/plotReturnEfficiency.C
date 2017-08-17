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
#include "/Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/tdrstyle.C"
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"


void setMaxErrorTo1(TGraphAsymmErrors * hist){

  for(int i = 1; i<hist->GetN(); i++){
    Double_t errorY = hist->GetErrorY(i);
    Double_t pointx, pointy;
    if(hist->GetPoint(i,pointx,pointy)<0)
      std::cout<<"error getting point "<<std::endl;
    Double_t errorUp = pointy+errorY/2;
    Double_t errorLow = pointy-errorY/2;
    std::cout<<"error Low "<< errorLow<<" errorUp "<<errorUp<< " geterrory "<< hist->GetErrorY(i)<<" geterrorx "<< hist->GetErrorX(i)<<std::endl;
    if(errorUp>1){
      hist->SetPointEYlow(i, errorLow);
      hist->SetPointEYhigh(i, 1-pointy);
    }
  }

}

Double_t fitgaus(Double_t *x,Double_t *par)
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

Double_t plotReturnEfficiency(TString fileName, TString treePath, TString recoVariable, TString numCut, TString denomCut, TString outFileName, TString xaxis, TString yaxis, TString text, int bins, float low, float high, Color_t color){
  gStyle->SetOptStat(111111);
  setTDRStyle();

  TFile *tauFile    = new TFile(fileName);
  if(!tauFile->IsOpen()||tauFile==0){
    std::cout<<"ERROR FILE "<< fileName<<" NOT FOUND; EXITING"<<std::endl;
    return 0;
  }
  TCanvas *Tcan= new TCanvas("Tcan","",100,20,600,600); Tcan->cd();  Tcan->SetFillColor(0);
  TPad* pad1 = new TPad("pad1","The pad",0,0,0.98,1);
  applyPadStyle(pad1);

  TLegend *leg = new TLegend(0.25,0.75,0.55,0.99);
  applyLegStyle(leg);
  TTree* tauTree = (TTree*)tauFile->Get(treePath);

  if(tauTree == 0){
    std::cout<<"ERROR Tau Tree is "<< tauTree<<" NOT FOUND; EXITING"<<std::endl;
    return 0;
  }
  gStyle->SetErrorX(0.25);

  TH1F* Denom;
  Denom = new TH1F("Denom","Denom",bins,low,high);
  Denom->Sumw2();
  tauTree->Draw(recoVariable+">>+Denom",denomCut,"hist");
  Denom->Draw("hist");
  Denom->GetXaxis()->SetTitle(xaxis);
  Denom->GetYaxis()->SetTitle(yaxis);
  Denom->SetMarkerStyle(20);
  Denom->SetMarkerColor(color+2);

  TH1F* Num;
  Num = new TH1F("Num","Num",bins,low,high);
  Num->Sumw2();
  tauTree->Draw(recoVariable+">>+Num",numCut+"&&"+denomCut,"hist");
  Num->Draw("hist");
  Num->GetXaxis()->SetTitle(xaxis);
  Num->GetYaxis()->SetTitle(yaxis);
  Num->SetMarkerStyle(20);
  Num->SetMarkerColor(color+2);

  TPaveText *pt = new TPaveText(2.5,Num->GetMaximum()*0.82,3.9,Num->GetMaximum()*0.95);
  pt->AddText(text);
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetBorderSize(0);
  pt->SetShadowColor(0);
  pt->SetTextColor(4);
  pt->Draw("E");

  Num->SetLineColor(color);  Num->SetFillColor(color);
  Num->SetFillStyle(3001);
  Num->SetLineWidth(2);
  Num->SetMaximum(Num->GetMaximum()*1.1);
  Num->SetMinimum(0);

  Tcan->cd();
  Tcan->SaveAs(outFileName+".png");

  float efficiency = Num->Integral()/Denom->Integral();
  std::cout<<"efficiency "<<efficiency<<std::endl;

  tauFile->Close();
  return efficiency;
}



