
int plot3VarComparisonsInput(TString variable,  TString Date, TString fileA, TString treeA, TString numeratorA, TString textA, TString fileB, TString treeB, TString numeratorB, TString textB, TString fileC, TString treeC, TString numeratorC, TString textC,  TString opt, TString fileLabel, TString xaxis, int bin, float min, float max){

  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/tdrstyle.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/plotReturnTH1F.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/plotResolution.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/plotTProfile.C");
  //gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/DrawOverflow.C");
  
  setTDRStyle();
  TFile *tauFile    = new TFile("dummy");
  TCanvas *Tcan2= new TCanvas("Tcan2","",100,20,800,600); Tcan2->cd();  Tcan2->SetFillColor(0);
  TPad* pad1 = new TPad("pad1","The pad",0,0,0.98,1);
  applyPadStyle(pad1);
  //l1NtupleProducer/EfficiencyTree

  TLegend *leg = new TLegend(0.6,0.75,0.9,0.92);//  Leg = new TLegend(0.74,0.65,0.99,0.95);                                                                                                                                                 
  applyLegStyle(leg);

  //withIsolation

  //TString file;
  //TString tree = "cutBased/Ntuple";
  //TString Date = "~/Dropbox/8_10_17/controlPlots";

  //TString numerator = "genTauPt>60&&abs(genTauEta)<2.1";
  //TString optA = "Fixed Strips 200PU H#rightarrow#tau#tau";
  //file = "MiniAOD_effi_93x_HtoTauTau.root";

  //TString var = "(genTauPt-tauPt)/genTauPt";
  //TString fileLabel = "ptResolution_genPT60";
  //TString xaxis = "p_{T} Resolution";
  //TString opt = "1 prong #pi^{0}";
  //int bin =70;
  //float min = -2;
  //float max = 2;

  TH1F* eff_pt20v1  = plotReturnTH1F(variable, fileA, Date+"/"+variable+"-A", numeratorA, xaxis,"Events", "p_{T} > 20GeV", treeA, bin, min, max, 0         , false);
  TH1F* eff_pt20v1_2= plotReturnTH1F(variable, fileA,Date+"/"+variable+"-A", numeratorA,  xaxis,"Events", "p_{T} > 20GeV", treeA, bin, min, max, kRed+2  , false);

  //TString optB = "Dynamic Strips 200PU H#rightarrow#tau#tau";
  //file = "MiniAOD_effi_93x_HtoTauTau_Org.root";
  TH1F* eff_pt20v2  = plotReturnTH1F(variable, fileB, Date+"/"+variable+"-B", numeratorB,  xaxis,"Events", "p_{T} > 20GeV", treeB, bin, min, max, kBlue  , false);

  //TString optC = "Fixed Strips (Yurii) 200PU Z#rightarrow#tau#tau";
  //file = "MiniAOD_effi_80x_200PU_DYtoLL.root";
  TH1F* eff_pt20v3  = plotReturnTH1F(variable, fileC,Date+"/"+variable+"-C", numeratorC,  xaxis,"Events", "p_{T} > 20GeV", treeC, bin, min, max, kOrange + 1  , false);

  Tcan2->cd();
  pad1->cd();

  pad1->SetGrid(15,15); 
  eff_pt20v1->Scale(1/eff_pt20v1->Integral());
  eff_pt20v1_2->Scale(1/eff_pt20v1_2->Integral());

  eff_pt20v2->Scale(1/eff_pt20v2->Integral());
  eff_pt20v3->Scale(1/eff_pt20v3->Integral());

  eff_pt20v1->SetMarkerColor(0);
  eff_pt20v1->SetLineColor(0);
  eff_pt20v1_2->SetMarkerColor(0);
  eff_pt20v1_2->SetFillStyle(1001);
  eff_pt20v1_2->SetFillColor(kOrange-2);
  eff_pt20v1_2->SetLineColor(kOrange+1);
  eff_pt20v1_2->SetLineWidth(2);

  eff_pt20v2->SetMarkerColor(0);
  eff_pt20v2->SetFillStyle(1001);
  eff_pt20v2->SetFillColorAlpha(kBlue,0.35);
  eff_pt20v2->SetLineWidth(2);
  eff_pt20v2->SetLineColor(kBlue);

  eff_pt20v3->SetMarkerColor(0);
  eff_pt20v3->SetFillStyle(1001);
  eff_pt20v3->SetFillColorAlpha(kOrange,0.35);
  eff_pt20v3->SetLineWidth(2);
  eff_pt20v3->SetLineColor(kOrange + 1);

  eff_pt20v1->Draw();
  eff_pt20v1->SetMinimum(0);
  eff_pt20v1_2->Draw("same hist");
  eff_pt20v2->Draw("same hist");
  eff_pt20v3->Draw("same hist");
  //eff_pt20v3->Draw("same hist");
  //eff_pt20v1_2->Draw("same hist");

  if( eff_pt20v1->GetMaximum() > eff_pt20v2->GetMaximum() && eff_pt20v1->GetMaximum() > eff_pt20v3->GetMaximum() )
    eff_pt20v1->SetMaximum( 1.5*eff_pt20v1->GetMaximum());
  else if( eff_pt20v2->GetMaximum() > eff_pt20v1->GetMaximum() && eff_pt20v2->GetMaximum() > eff_pt20v3->GetMaximum() )
    eff_pt20v1->SetMaximum( 1.5*eff_pt20v2->GetMaximum());
  else
    eff_pt20v1->SetMaximum( 1.5*eff_pt20v3->GetMaximum());

  leg->SetHeader(opt);
  leg->AddEntry(eff_pt20v1_2,textA,"f");
  leg->AddEntry(eff_pt20v2,textB+" ","f");
  leg->AddEntry(eff_pt20v3,textC+" ","f");
  leg->Draw();

  Tcan2->SaveAs(Date+"/"+fileLabel+".png");
  Tcan2->SaveAs(Date+"/"+fileLabel+".pdf");

}
