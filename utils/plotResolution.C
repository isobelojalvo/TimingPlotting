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
//#include "tdrStyle.C"

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


int plotResolution(TString variable, TString fileName, TString outFileName, TString l1Cut, TString text, TString treePath, int bins, float low, float high){
  setTDRStyle();
  tdrStyle->SetOptStat("mr"); // To display the mean and RMS:   SetOptStat("mr");

  TFile *tauFile    = new TFile(fileName);

  if(!tauFile->IsOpen()||tauFile==0){
    std::cout<<"ERROR FILE "<< fileName<<" NOT FOUND; EXITING"<<std::endl;
    return 0;
  }

  TCanvas *Tcan= new TCanvas("Tcan","",100,20,600,600); Tcan->cd();  Tcan->SetFillColor(0);
  TPad* pad1 = new TPad("pad1","The pad",0,0,0.98,1);

  applyPadStyle(pad1);

  //gStyle->SetOptStat(0);

  TLegend *leg = new TLegend(0.25,0.75,0.55,0.99);//  Leg = new TLegend(0.74,0.65,0.99,0.95);                                                                                                                                                 

  applyLegStyle(leg);

  TTree* tauTree = (TTree*)tauFile->Get(treePath);

  //TH1F* Denom = new TH1F("Denom","Denom",bins,low,high);
  
  //tauTree->Draw(variable+">>+Denom",recoCut);

  //TBranch *recoPtBranch = 0;
  //std::vector<float> *recoPtVec;
  //tauTree->SetBranchAddress("recoPt",&recoPtVec,&recoPtBranch);
  //for(uint32_t i = 0; i<recoPtVec->size(); i++ )
  //Denom->Fill(recoPtVec->at(i));
  
  TH1F* Num = new TH1F("Num","Num",bins,low,high);
  Num->Sumw2();
  tauTree->Draw(variable+">>+Num",l1Cut);

  /*
  Double_t fitf(Double_t *x,Double_t *par);
  Double_t erf(Double_t *x, Double_t *par);
  //TF1 *func = new TF1("fit","pol3",10,30,5);
  //TF1 *f4b = new TF1("erfc(x)","erf",0,5,6);
  TF1 *fitfcn = new TF1("fitfcn",(void *)erf,5,5,10);
  //TF1 *g1    = new TF1("g1","pol4",30,65);
  TF1 *g    = new TF1("g1","pol3",0,17);
  TF1 *g0    = new TF1("g1","pol4",17,30);
  TF1 *g1    = new TF1("g1","pol4",30,75);
  TF1 *g2    = new TF1("g1","pol3",75,150);
  g->SetLineWidth(2);  g0->SetLineWidth(2);  g1->SetLineWidth(2);  g2->SetLineWidth(2);
  */

  Num->Draw();
  Num->GetXaxis()->SetTitle("#tau_{p_{T}} Resolution [GeV]");
  Num->GetYaxis()->SetTitle("Events");

  TPaveText *pt = new TPaveText(39,.4,150,.55);
  pt->AddText(text);
  //pt->AddText(text1.c_str());
  //pt->AddText(text2.c_str());
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetBorderSize(0);
  pt->SetShadowColor(0);
  pt->Draw();

  Num->SetLineColor(kBlue);  Num->SetFillColor(kBlue);
  Num->SetFillStyle(3002);
  Num->SetLineWidth(4);
  //Num->Fit(g1,"R");
  //Num->Fit(g2,"R+");
  //Num->Fit(g0,"R+");
  //Num->Fit(g,"R+");
  //Num->Sumw2();
  //Num->SetStats(0);

  Tcan->cd();
  Tcan->SaveAs(outFileName+".png");
}



