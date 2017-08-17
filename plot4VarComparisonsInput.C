
int plot4VarComparisonsInput(TString Date, 
			     TString variableA, TString fileA, TString treeA, TString numeratorA, TString textA, 
			     TString variableB, TString fileB, TString treeB, TString numeratorB, TString textB, 
			     TString variableC, TString fileC, TString treeC, TString numeratorC, TString textC, 
			     TString variableD, TString fileD, TString treeD, TString numeratorD, TString textD, 
			     TString opt, TString fileLabel, TString xaxis, int bin, float min, float max, bool log){

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


  TH1F* eff_pt20v1  = plotReturnTH1F(variableA, fileA, Date+"/"+variableA+"-A", numeratorA, xaxis,"Events", "p_{T} > 20GeV", treeA, bin, min, max, 0         , false);
  TH1F* eff_pt20v1_2= plotReturnTH1F(variableA, fileA,Date+"/"+variableA+"-A", numeratorA,  xaxis,"Events", "p_{T} > 20GeV", treeA, bin, min, max, kRed+2  , false);

  //TString optB = "Dynamic Strips 200PU H#rightarrow#tau#tau";
  //file = "MiniAOD_effi_93x_HtoTauTau_Org.root";
  TH1F* eff_pt20v2  = plotReturnTH1F(variableB, fileB, Date+"/"+variableB+"-B", numeratorB,  xaxis,"Events", "p_{T} > 20GeV", treeB, bin, min, max, kBlue  , false);

  //TString optC = "Fixed Strips (Yurii) 200PU Z#rightarrow#tau#tau";
  //file = "MiniAOD_effi_80x_200PU_DYtoLL.root";
  TH1F* eff_pt20v3  = plotReturnTH1F(variableC, fileC,Date+"/"+variableC+"-C", numeratorC,  xaxis,"Events", "p_{T} > 20GeV", treeC, bin, min, max, kOrange + 1  , false);

  TH1F* eff_pt20v4  = plotReturnTH1F(variableD, fileD,Date+"/"+variableD+"-D", numeratorD,  xaxis,"Events", "p_{T} > 20GeV", treeD, bin, min, max, kGreen + 2  , false);

  Tcan2->cd();
  pad1->cd();

  pad1->SetGrid(15,15); 
  eff_pt20v1->Scale(1/eff_pt20v1->Integral());
  eff_pt20v1_2->Scale(1/eff_pt20v1_2->Integral());

  eff_pt20v2->Scale(1/eff_pt20v2->Integral());
  eff_pt20v3->Scale(1/eff_pt20v3->Integral());
  eff_pt20v4->Scale(1/eff_pt20v4->Integral());

  eff_pt20v1->SetMarkerColor(0);
  eff_pt20v1->SetLineColor(0);
  eff_pt20v1_2->SetMarkerColor(0);
  eff_pt20v1_2->SetFillStyle(1001);
  eff_pt20v1_2->SetFillColor(kOrange-2);
  eff_pt20v1_2->SetLineColor(kOrange+1);
  eff_pt20v1_2->SetLineWidth(2);

  eff_pt20v2->SetMarkerColor(0);
  eff_pt20v2->SetFillStyle(1001);
  eff_pt20v2->SetFillColorAlpha(kBlue,0.25);
  eff_pt20v2->SetLineWidth(2);
  eff_pt20v2->SetLineColor(kBlue);

  eff_pt20v3->SetMarkerColor(0);
  eff_pt20v3->SetFillStyle(1001);
  eff_pt20v3->SetFillColorAlpha(kRed,0.25);
  eff_pt20v3->SetLineWidth(2);
  eff_pt20v3->SetLineColor(kRed + 1);

  eff_pt20v4->SetMarkerColor(0);
  eff_pt20v4->SetFillStyle(1001);
  eff_pt20v4->SetFillColorAlpha(kGreen,0.25);
  eff_pt20v4->SetLineWidth(2);
  eff_pt20v4->SetLineColor(kGreen + 2);

  eff_pt20v1->Draw();
  //eff_pt20v1->Draw();

  if(log)
    gPad->SetLogy();
  else
    eff_pt20v1->SetMinimum(0);

  eff_pt20v1_2->Draw("same hist");
  eff_pt20v2->Draw("same hist");
  eff_pt20v3->Draw("same hist");
  eff_pt20v4->Draw("same hist");

  if( eff_pt20v1->GetMaximum() > eff_pt20v2->GetMaximum() && 
      eff_pt20v1->GetMaximum() > eff_pt20v3->GetMaximum() &&
      eff_pt20v1->GetMaximum() > eff_pt20v4->GetMaximum() 
      )
    eff_pt20v1->SetMaximum( 1.5*eff_pt20v1->GetMaximum());
  else if( eff_pt20v2->GetMaximum() > eff_pt20v1->GetMaximum() && 
	   eff_pt20v2->GetMaximum() > eff_pt20v3->GetMaximum() &&
	   eff_pt20v2->GetMaximum() > eff_pt20v4->GetMaximum() )
    eff_pt20v1->SetMaximum( 1.5*eff_pt20v2->GetMaximum());
  else if( eff_pt20v3->GetMaximum() > eff_pt20v1->GetMaximum() && 
	   eff_pt20v3->GetMaximum() > eff_pt20v2->GetMaximum() &&
	   eff_pt20v3->GetMaximum() > eff_pt20v4->GetMaximum() )
    eff_pt20v1->SetMaximum( 1.5*eff_pt20v3->GetMaximum());
  else 
    eff_pt20v1->SetMaximum( 1.5*eff_pt20v4->GetMaximum());

  leg->SetHeader(opt);
  leg->AddEntry(eff_pt20v1_2,textA,"f");
  leg->AddEntry(eff_pt20v2,textB+" ","f");
  leg->AddEntry(eff_pt20v3,textC+" ","f");
  leg->AddEntry(eff_pt20v4,textD+" ","f");
  leg->Draw();

  Tcan2->SaveAs(Date+"/"+fileLabel+".png");
  Tcan2->SaveAs(Date+"/"+fileLabel+".pdf");
  //root [13] Ntuple->Draw("(genTauPt-tauPt)/genTauPt>>htemp(75,-.5,.5)","tauPt>40&&dmf==1&&genTauPt>40")
}
