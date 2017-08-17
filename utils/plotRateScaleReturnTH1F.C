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

Float_t xbins[16]= {0,10,16,20,24,28,32,36,44,52,60,76,100,140,200,280};
//added xaxis
TH1F* plotRateScaleReturnTH1F(TString variable, TString fileName, TString outFileName, TString l1Cut, TString xaxis, TString text, TString treePath, int bins, float low, float high, Color_t color, float scaledRate, bool variableBin=false, int linestyle=1, TString yaxis = "Rate"){

  setTDRStyle();
  //tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");

  TFile *tauFile    = new TFile(fileName);

  if(!tauFile->IsOpen()||tauFile==0){
    std::cout<<"ERROR FILE "<< fileName<<" NOT FOUND; EXITING"<<std::endl;
    return 0;
  }

  TCanvas *Tcan= new TCanvas("Tcan","",100,20,600,600); Tcan->cd();  Tcan->SetFillColor(0);

  TPad* pad1 = new TPad("pad1","The pad",0,0,0.98,1);
  applyPadStyle(pad1);
  gPad->SetLogy();
  gStyle->SetOptStat(0);

  TLegend *leg = new TLegend(0.25,0.75,0.55,0.99);// 
  applyLegStyle(leg);
  TH1F* histo = (TH1F*)tauFile->Get(treePath + variable);
  if(histo == 0){
    std::cout<<"ERROR Tau histo is "<< histo <<" NOT FOUND; EXITING"<<std::endl;
    return 0;
  }
  //histo->Rebin(bins);
  
  TH1F* rateHisto = new TH1F("rateHisto","rateHisto",bins,low,high);
  Double_t Sum = 0;

  for(int i = bins; i > 0; i-- ){
    Sum += histo->GetBinContent(i);
    rateHisto->SetBinContent(i, Sum);
  }

  pad1->cd();
  rateHisto->Draw("L");

  gStyle->SetErrorX(0.25);
  rateHisto->Draw();
  rateHisto->GetXaxis()->SetTitle(xaxis);
  rateHisto->GetYaxis()->SetTitle(yaxis);

  TPaveText *pt = new TPaveText(150,.05,250,0.15);
  pt->AddText(text);
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetBorderSize(0);
  pt->SetShadowColor(0);
  rateHisto->SetMarkerStyle(20);
  rateHisto->SetMarkerColor(color+2);
  pt->Draw("E");

  rateHisto->SetLineColor(color);  rateHisto->SetFillColor(0);
  rateHisto->SetFillStyle(0);
  rateHisto->SetLineWidth(2);
  rateHisto->SetLineStyle(linestyle);
  //rateHisto->Fit(g1,"R");
  //rateHisto->Fit(g2,"R+");
  //rateHisto->Fit(g0,"R+");
  //rateHisto->Fit(g,"R+");
  //rateHisto->Sumw2();
  //rateHisto->SetStats(0);
  rateHisto->SetMaximum(10000000);
  rateHisto->SetMinimum(10);
  //setMaxErrorTo1(Num);

  rateHisto->Scale(scaledRate);
  gStyle->SetOptStat(0);
  //
  Tcan->cd();
  Tcan->SaveAs(outFileName+".png");

  return rateHisto;
}



