
{
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

  TLegend *leg = new TLegend(0.6,0.55,0.9,0.87);//  Leg = new TLegend(0.74,0.65,0.99,0.95);                                                                                                                                                 
  applyLegStyle(leg);

  //withIsolation

  TString file;
  TString tree = "cutBased/Ntuple";
  TString Date = "~/Dropbox/8_10_17/controlPlots";

  TString l1Cut = "genTauPt>60&&abs(genTauEta)<2.1";
  TString optA = "Fixed Strips 200PU H#rightarrow#tau#tau";
  file = "MiniAOD_effi_93x_HtoTauTau.root";

  TString var = "(genTauPt-tauPt)/genTauPt";
  TString fileLabel = "ptResolution_genPT60";
  TString xaxis = "p_{T} Resolution";
  TString opt = "1 prong #pi^{0}";
  int bin =70;
  float min = -2;
  float max = 2;

  TH1F* eff_pt20v1  = plotReturnTH1F(var, file,Date+"/"+optA, l1Cut+"&&(dmf==1)", xaxis,"Events", "p_{T} > 20GeV", tree, bin, min, max, 0         , false);
  TH1F* eff_pt20v1_2= plotReturnTH1F(var, file,Date+"/"+optA, l1Cut+"&&(dmf==1)",  xaxis,"Events", "p_{T} > 20GeV", tree, bin, min, max, kRed   , false);

  TString optB = "Dynamic Strips 200PU H#rightarrow#tau#tau";
  file = "MiniAOD_effi_93x_HtoTauTau_Org.root";
  TH1F* eff_pt20v2  = plotReturnTH1F(var, file,Date+"/dynamic_strip"+optB, l1Cut+"&&dmf==1",  xaxis,"Events", "p_{T} > 20GeV", tree, bin, min, max, kOrange  , false);

  TString optC = "Fixed Strips (Yurii) 200PU Z#rightarrow#tau#tau";
  file = "MiniAOD_effi_80x_200PU_DYtoLL.root";
  TH1F* eff_pt20v3  = plotReturnTH1F(var, file,Date+"/"+optC, l1Cut+"&&dmf==1",  xaxis,"Events", "p_{T} > 20GeV", tree, bin, min, max, kBlue  , false);

  Tcan2->cd();
  pad1->cd();

  pad1->SetGrid(5,5); 
  eff_pt20v1->Scale(1/eff_pt20v1->Integral());
  eff_pt20v1_2->Scale(1/eff_pt20v1_2->Integral());

  eff_pt20v2->Scale(1/eff_pt20v2->Integral());
  eff_pt20v3->Scale(1/eff_pt20v3->Integral());

  eff_pt20v1->Draw();
  eff_pt20v1->SetMinimum(0);
  eff_pt20v1_2->Draw("same hist");
  eff_pt20v2->Draw("same hist");
  eff_pt20v3->Draw("same hist");
  //eff_pt20v1_2->Draw("same hist");
  eff_pt20v1->SetMaximum(0.5);

  leg->SetHeader(opt);
  leg->AddEntry(eff_pt20v1_2,optA,"f");
  leg->AddEntry(eff_pt20v2,optB+" ","f");
  leg->AddEntry(eff_pt20v3,optC+" ","f");
  leg->Draw();

  Tcan2->SaveAs(Date+"/"+fileLabel+".png");
  //root [13] Ntuple->Draw("(genTauPt-tauPt)/genTauPt>>htemp(75,-.5,.5)","tauPt>40&&dmf==1&&genTauPt>40")
}
