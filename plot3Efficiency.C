
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

void applyPadStyle(TPad* pad1){
  pad1->SetFillColor(0);
  pad1->Draw();  pad1->cd();  pad1->SetLeftMargin(0.15);  pad1->SetBottomMargin(0.13); pad1->SetRightMargin(0.05);
  //pad1->SetGrid();
  pad1->SetGrid(10,10);
}

void plot3Efficiency(TString variable, TString Date, 
		    TString fileA, TString treeA, TString numeratorA, TString denominatorA, TString textA,
		    TString fileB, TString treeB, TString numeratorB, TString denominatorB, TString textB,
		    TString fileC, TString treeC, TString numeratorC, TString denominatorC, TString textC,
		     TString outfilename, TString xaxis, TString titleText, int bins, float low, float high){
  //int bins = 20;
  //int low  = 0;
  //int high = 120;

  //TString isoCut = "2";
  //Plotting Variables
  //TString variable = "genTauPt";
  //TString GenCut= "genTauPt>22&&abs(genTauEta)<2.1&&vtxIndex==0";
  // TString RecoCut= "tauPt>25&&PFCharged<"+isoCut+"&&" + GenCut;
  //TString RecoCut1= "tauPt>25&&PFChargedT2<"+isoCut+"&&" + GenCut;
  //TString RecoCut2= "tauPt>25&&PFChargedT3<"+isoCut+"&&" + GenCut;


  //Style
  //TString xaxis = "Gen #tau p_{T} [GeV]";
  int markerstyle = 20;
  Color_t color = TColor::GetColor("#283593");//dark blue color1
  Color_t color1 = TColor::GetColor("#F44336");//red color4
  Color_t color2 = TColor::GetColor("#0288D1"); //green blue color2
  //TString outFileName = "plotEfficiency-ZTT";

  setTDRStyle();
  //tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");

  TFile *tauFileA    = new TFile(fileA);

  if(!tauFileA->IsOpen()||tauFileA==0){
    std::cout<<"ERROR FILE "<< fileA<<" NOT FOUND; EXITING"<<std::endl;
    exit(0);
  }

  TFile *tauFileB    = new TFile(fileB);

  if(!tauFileB->IsOpen()||tauFileB==0){
    std::cout<<"ERROR FILE "<< fileB<<" NOT FOUND; EXITING"<<std::endl;
    exit(0);
  }

  TFile *tauFileC    = new TFile(fileC);

  if(!tauFileC->IsOpen()||tauFileC==0){
    std::cout<<"ERROR FILE "<< fileC<<" NOT FOUND; EXITING"<<std::endl;
    exit(0);
  }

  TCanvas *Tcan= new TCanvas("Tcan","",100,20,600,600); Tcan->cd();  Tcan->SetFillColor(0);
  TPad* pad1 = new TPad("pad1","The pad",0,0,0.98,0.98);

  applyPadStyle(pad1);
  gStyle->SetOptFit(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(0);

  TTree* tauTreeA = (TTree*)tauFileA->Get(treeA);
  if(tauTreeA == 0){
    std::cout<<"ERROR Tau Tree is "<< tauTreeA<<" NOT FOUND; EXITING"<<std::endl;
    exit(0);
  }

  TTree* tauTreeB = (TTree*)tauFileB->Get(treeB);
  if(tauTreeB == 0){
    std::cout<<"ERROR Tau Tree is "<< tauTreeB<<" NOT FOUND; EXITING"<<std::endl;
    exit(0);
  }

  TTree* tauTreeC = (TTree*)tauFileC->Get(treeC);
  if(tauTreeC == 0){
    std::cout<<"ERROR Tau Tree is "<< tauTreeC<<" NOT FOUND; EXITING"<<std::endl;
    exit(0);
  }


  TH1F* DenomA;
  DenomA = new TH1F("DenomA","DenomA",bins,low,high);
  DenomA->Sumw2();
  tauTreeA->Draw(variable+">>+DenomA",denominatorA);

  TH1F* NumA;
  NumA = new TH1F("NumA","NumA",bins,low,high);
  tauTreeA->Draw(variable+">>+NumA",numeratorA);

  NumA->Divide(DenomA);

  TH1F* DenomB;
  DenomB = new TH1F("DenomB","DenomB",bins,low,high);
  DenomB->Sumw2();
  tauTreeB->Draw(variable+">>+DenomB",denominatorB);

  TH1F* NumB;
  NumB = new TH1F("NumB","NumB",bins,low,high);
  tauTreeB->Draw(variable+">>+NumB",numeratorB);
  NumB->Divide(DenomB);

  TH1F* DenomC;
  DenomC = new TH1F("DenomC","DenomC",bins,low,high);
  DenomC->Sumw2();
  tauTreeC->Draw(variable+">>+DenomC",denominatorC);

  TH1F* NumC;
  NumC = new TH1F("NumC","NumC",bins,low,high);
  tauTreeC->Draw(variable+">>+NumC",numeratorC);
  NumC->Divide(DenomC);

  NumC->SetMarkerStyle(markerstyle);
  NumC->SetMarkerColor(color1);

  NumB->SetMarkerStyle(markerstyle);
  NumB->SetMarkerColor(color2);
  ////

  gStyle->SetErrorX(0.5);

  NumA->GetXaxis()->SetTitle(xaxis);
  NumA->GetYaxis()->SetTitle("Efficiency ");
  NumA->GetYaxis()->SetTitleOffset(1.1);
  NumA->SetMarkerStyle(markerstyle);
  NumA->SetMarkerColor(color);
  NumA->Draw("P");
  NumA->Draw("P same");
  NumB->Draw("P same");
  NumC->Draw("P same");

  NumA->SetFillStyle(1001);
  NumA->SetLineWidth((short)1.5);
  NumA->SetMaximum(1.0);
  NumA->SetMinimum(0);

  TLegend *leg = new TLegend(.49, .144, .77, .345,"","nbNDC");  
  leg->SetBorderSize(0);
  leg->SetShadowColor(kWhite);
  leg->SetFillColor(kWhite);
  leg->SetTextSize(0.03);
  leg->SetHeader(titleText);
  //leg->AddEntry(pu200_eff,"PF Charged Iso All","PL"); 
  //leg->AddEntry(NumA,"Nominal PF Charged Isolation","PL");
  leg->AddEntry(NumA,textA,"PL");
  leg->AddEntry(NumB,textB,"PL");
  leg->AddEntry(NumC,textC,"PL");
  leg->Draw();


  Tcan->cd();
  Tcan->SaveAs(Date+"/"+variable+outfilename+"-eff.pdf");
  Tcan->SaveAs(Date+"/"+variable+outfilename+"-eff.png");
}
