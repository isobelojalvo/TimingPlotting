#include "tdrstyle.C"
#include "PlotStyles.C"
#include "plotTimeReturnTGraphAsymmErrors.C"
#include "plotTimeReturnTGraphAsymmErrors1Line.C"

void plotTiming(){
  TString isoCut = "2";
  Int_t color1 = TColor::GetColor("#283593"); //dark blue
  Int_t color2 = TColor::GetColor("#0288D1"); //medium blue

  Int_t color3 = TColor::GetColor("#00695C"); //green blue
  Int_t color4 = TColor::GetColor("#F44336"); //red

  Int_t color5 = TColor::GetColor("#FF9900"); //Mustard Yellow

  setTDRStyle();

  gStyle->SetOptStat(0);
  gROOT->ForceStyle();
  
  TCanvas *c1 = new TCanvas("c","c",800,800);
  setCanvasStyle(c1);
  c1->cd();

  TString plotName = "tauEfficiency-ZTT-200PU-iso2GeV-isoOnly-timeMatch";
  TString legLabel = "Ztautau PF Charged Isolation < 2 GeV";
  TH1F *basehist = new TH1F("basehist","",100,0,2.5);

  TChain pu200_gaus("PFChargedBased/Ntuple");  
  //pu200_gaus.Add("timing-Jan26-2/ZTT-RelVal-200.root");
  pu200_gaus.Add("timing-May13/ZTT-RelVal-200.root");

  TChain pu0_gaus("PFChargedBased/Ntuple");  
  pu0_gaus.Add("timing-Jan26-2/ZTT-RelVal-0.root");

  basehist->SetStats(false);
  TString iso200("0.050"), iso140("0.050");
  TString date = "5_3_17";


  double zs_200[4]   = {0.,0.,0.,0.};
  double vals_200[4] = {0.,0.,0.,0.};
  double erhi_200[4] = {0.,0.,0.,0.};
  double erlo_200[4] = {0.,0.,0.,0.};
  double zs_140[4]   = {0.,0.,0.,0.};
  double vals_140[4] = {0.,0.,0.,0.};
  double erhi_140[4] = {0.,0.,0.,0.};
  double erlo_140[4] = {0.,0.,0.,0.};
  double dens_200[4] = {0.,0.,0.,0.};

  double zs_time_200[4]   = {0.,0.,0.,0.};
  double vals_time_200[4] = {0.,0.,0.,0.};
  double erhi_time_200[4] = {0.,0.,0.,0.};
  double erlo_time_200[4] = {0.,0.,0.,0.};
  double zs_time_140[4]   = {0.,0.,0.,0.};
  double vals_time_140[4] = {0.,0.,0.,0.};
  double erhi_time_140[4] = {0.,0.,0.,0.};
  double erlo_time_140[4] = {0.,0.,0.,0.};

  double exl[4] = {0.,0.,0.,0.};
  double exh[4] = {0.,0.,0.,0.};

  TString numerator = "genTauPt > 30 && abs(genTauEta) < 2.1 && (dmf!=5&&dmf!=6 && dmf > -1) && (dmf == 0 || dmf == 1 || (dmf == 10 && good3ProngT4>0))  &&  tauPt> 30 && vtxIndex==0";
  TString denominator = "genTauPt > 30 && abs(genTauEta) <2.1 && vtxIndex==0 && (dmf!=5&&dmf!=6 && dmf > -1) && (dmf == 0 || dmf == 1 || (dmf == 10&& good3ProngT4>0))";

  //TString numerator = "genTauPt > 22 && abs(genTauEta) < 2.1 && (dmf!=5&&dmf!=6 && dmf > -1) && (dmf == 0 || dmf == 1 || (dmf == 10 && good3ProngT4>0))  &&  tauPt> 25 && vtxIndex==0";
  //TString denominator = "genTauPt > 22 && abs(genTauEta) <2.1 && vtxIndex==0 && (dmf!=5&&dmf!=6 && dmf > -1) && (dmf == 0 || dmf == 1 || (dmf == 10&& good3ProngT4>0))";
  TString logand = " && ";

  TString numeratorNominal = numerator + "&& PFCharged <"+isoCut;
  TGraphAsymmErrors *pu200_eff = plotTimeReturnTGraphAsymmErrors(pu200_gaus, numeratorNominal, denominator);
  //TGraphAsymmErrors *pu0_eff   = plotTimeReturnTGraphAsymmErrors(pu0_gaus, numeratorNominal,denominator);
  TGraphAsymmErrors *pu0_eff   = plotTimeReturnTGraphAsymmErrors1Line(pu0_gaus, numeratorNominal,denominator);
  //////////////////////////////////////////

  //TString numer("genTauPt > 22 && abs(genTauEta) <2.1 && dmf==10  &&  tauPt> 25 && vtxIndex==0 && PFChargedT3 <"+isoCut);
  TString numeratorT3 = numerator + "&& PFChargedT3 <"+isoCut;
  TGraphAsymmErrors *pu200_eff_timingCutT3 = plotTimeReturnTGraphAsymmErrors(pu200_gaus, numeratorT3, denominator);  

  /////////////////////////////////////////

  TString numeratorT2 = numerator + "&& PFChargedT2<"+isoCut;
  TGraphAsymmErrors *pu200_eff_timingCutT2 = plotTimeReturnTGraphAsymmErrors(pu200_gaus, numeratorT2, denominator);  

  /////////////////////////////////////////
  TString numeratorT4 = numerator + "&& PFChargedT4 <"+isoCut;
  //TString numeratorT4v0 = numerator + "&& PFChargedT4 <5";

  TGraphAsymmErrors *pu200_eff_timingCutT4 = plotTimeReturnTGraphAsymmErrors(pu200_gaus, numeratorT4, denominator);  
  TGraphAsymmErrors *pu0_eff_timingCutT4   = plotTimeReturnTGraphAsymmErrors(pu0_gaus, numeratorT4, denominator);

  /////////////////////////////////////////

  TString numeratorT6 = numerator + "&& PFChargedT6 <"+isoCut;
  //TString numeratorT6v0 = numerator + "&& PFChargedT6 <5";

  TGraphAsymmErrors *pu200_eff_timingCutT6 = plotTimeReturnTGraphAsymmErrors(pu200_gaus, numeratorT6, denominator);  
  TGraphAsymmErrors *pu0_eff_timingCutT6   = plotTimeReturnTGraphAsymmErrors(pu0_gaus, numeratorT6, denominator);

  /////////////////////////////////////////
  basehist->GetXaxis()->SetTitle("density (events / mm)");
  basehist->GetYaxis()->SetTitle("Tau Isolation Efficiency ");  
  basehist->GetYaxis()->SetRangeUser(0.0,0.8);
  basehist->GetXaxis()->SetRangeUser(0.3,2);
  basehist->Draw("");

  //setPlotStyleAsymm(                  plot , Int_t  color, Int_t fillStyle,  Int_t MarkerStyle){
  setPlotStyleAsymm(  pu200_eff_timingCutT6,       color5,            3005,                 23);
  pu200_eff_timingCutT6->Draw("P Same");

  setPlotStyleAsymm(  pu200_eff_timingCutT4,       color3,            3005,                 23);
  pu200_eff_timingCutT4->Draw("P Same");

  setPlotStyleAsymm(  pu200_eff_timingCutT2,       color2,            3005,                 23);
  pu200_eff_timingCutT2->Draw("P Same");

  //setPlotStyleAsymm(                  plot , Int_t  color, Int_t fillStyle,  Int_t MarkerStyle){
  setPlotStyleAsymm(  pu200_eff_timingCutT3,       color4,            3005,                 23);
  pu200_eff_timingCutT3->Draw("P Same");

//setPlotStyleAsymm(                  plot , Int_t  color, Int_t fillStyle,  Int_t MarkerStyle){
  setPlotStyleAsymm(             pu200_eff,       color1,            3005,                 23);
  pu200_eff->Draw("P Same");

  pu0_eff->SetFillColor(kBlue+4);
  pu0_eff->SetFillStyle(3005);
  pu0_eff->Draw("4, Same");
  //pu0_eff->SetFillColor(kBlue+4);
  //pu0_eff->SetFillStyle(3005);
  //pu0_eff->Draw("4, Same");

  TLegend *leg = new TLegend(.55, .706, .75, .92,legLabel,"nbNDC");  
  setLegendStyles(leg,legLabel, 2);

  leg->AddEntry(            pu200_eff,   "PF Charged Isolation Nominal","PL"); 
  leg->AddEntry(pu200_eff_timingCutT2,"2#sigma Interval Tracks","PL");
  leg->AddEntry(pu200_eff_timingCutT3,"3#sigma Interval Tracks","PL");
  leg->AddEntry(pu200_eff_timingCutT4,"4#sigma Interval Tracks","PL");
  leg->AddEntry(pu200_eff_timingCutT6,"6#sigma Interval Tracks","PL");
  leg->Draw();
  
  c1->SaveAs("~/Dropbox/"+date+"/TimingPlots/"+plotName+".pdf");
  c1->SaveAs("~/Dropbox/"+date+"/TimingPlots/"+plotName+".png");
}
