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
#include <TFormula.h>
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
    Double_t errorUp = pointy+errorY;
    Double_t errorLow = pointy-errorY/2;
    //std::cout<<"error Low "<< errorLow<<" errorUp "<<errorUp<< " geterrory "<< hist->GetErrorY(i)<<" geterrorx "<< hist->GetErrorX(i)<<std::endl;
    if(errorUp>1){
      //hist->SetPointEYlow(i, errorLow);
      hist->SetPointEYhigh(i, 1-pointy);
    }
  }

}


void applyPadStyle(TPad* pad1){
  pad1->SetFillColor(0);
  pad1->Draw();  pad1->cd();  pad1->SetLeftMargin(0.2);  pad1->SetBottomMargin(0.13); pad1->SetRightMargin(0.1);
  //pad1->SetGrid(); 
  pad1->SetGrid(10,10); 
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
  return tanh(par[0]*x+par[1])+par[2]; //<===========
}

Double_t fitATan(Double_t *x,Double_t *par) {
  Double_t arg = 0;
  if (par[2]!=0) arg = (x[0]*par[3] + par[1]);
  Double_t fitval = par[0]*TMath::ATan(arg) + par[2];
  
  return fitval;
}


//added xaxis
TGraphAsymmErrors* plotEfficiencyReturnASYM(TString variable, TString fileName, TString outFileName, TString l1Cut, TString recoCut, TString xaxis, TString text, TString treePath, int bins, float low, float high, Color_t color, bool variableBin=false, int markerstyle = 20, int inputfitparam = 88){

  std::cout<<"variable "<<variable<<" filename "<<fileName<< " outFileName "<< outFileName<<" l1Cut "<< l1Cut<<" recoCut " << recoCut <<" xaxis "<< xaxis <<" text "<< text << " treePath "<< treePath<< " bins "<< bins<<" low "<< low << " high "<< high <<" color "<< color <<std::endl;

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
  gStyle->SetOptFit(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(0);

  TLegend *leg = new TLegend(0.25,0.75,0.55,0.99);//  Leg = new TLegend(0.74,0.65,0.99,0.95);                                                                                                                                                 

  applyLegStyle(leg);

  TTree* tauTree = (TTree*)tauFile->Get(treePath);
  if(tauTree == 0){
    std::cout<<"ERROR Tau Tree is "<< tauTree<<" NOT FOUND; EXITING"<<std::endl;
    return 0;
  }

  TH1F* Denom;
  float xmax = 140;
  Float_t xbins[18]= {0,12,18,22,26,27,28,29,31,32,34,38,42,52,60,76,100,140};
  if(variableBin){
    Denom = new TH1F("Denom","Denom",17,xbins);
  }
  else
    Denom = new TH1F("Denom","Denom",bins,low,high);

  Denom->Sumw2();
  tauTree->Draw(variable+">>+Denom",recoCut);
  
  TH1F* Num;
  if(variableBin){
     Num = new TH1F("Num","Num",17,xbins);
  }
  else
    Num = new TH1F("Num","Num",bins,low,high);


  tauTree->Draw(variable+">>+Num",l1Cut);

  Num->Divide(Denom);
  gStyle->SetErrorX(0.5);

  TGraphAsymmErrors* asym = new TGraphAsymmErrors(Num);

  asym->GetXaxis()->SetTitle(xaxis);
  asym->GetYaxis()->SetTitle("L1 Efficiency ");
  asym->GetYaxis()->SetTitleOffset(0.8);

  TPaveText *pt = new TPaveText(150,.05,250,0.15);
  pt->AddText(text);
  //pt->AddText(text1.c_str());
  //pt->AddText(text2.c_str());
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetBorderSize(0);
  pt->SetShadowColor(0);
  asym->SetMarkerStyle(markerstyle);
  asym->SetMarkerColor(color+2);
  asym->Draw("P");

  pt->Draw("E");

  if(color==0){
    asym->SetLineColorAlpha(color,1);  
    asym->SetMarkerColorAlpha(color,1);
    asym->SetFillColorAlpha(color,1);
    asym->SetMarkerStyle(1);
  }
  else{
    asym->SetLineColor(color);  
    asym->SetFillColor(color);
  }
  asym->SetFillStyle(1001);
  asym->SetLineWidth(1.5);
  asym->SetMaximum(1.1);
  asym->SetMinimum(0);
  setMaxErrorTo1(asym);

  /* NOW fit*/
  // par[0] * arctan( x[0]*par[3] + par[1] ) + par[2]

  TF1 *func = new TF1("fitarctan",fitATan,-3,3,4);
  func->SetParLimits(0,0.1,0.355);    //the amplitude
  func->SetParLimits(1,-40,-4);   //the x offset
  func->SetParLimits(2,0,2);    //the y offset
  func->SetParLimits(3,0.1,0.55); //the x multiplicative factor offset
  func->SetParNames ("Amplitude","x-offset","y-offset","x factor");
  func->SetParameters(500,asym->GetMean(),asym->GetRMS());

  func->SetLineWidth(2);    
  func->SetLineColor(color);
  if(markerstyle==20)
    func->SetLineStyle(1);

  if(markerstyle==26)
    func->SetLineStyle(3);

  asym->Fit("fitarctan","","",0, xmax + 10 );
  gStyle->SetOptStat(0);

  Tcan->cd();
  Tcan->SaveAs(outFileName+".pdf");

  return asym;
}



