#include <vector>

void plotROCCurvesTaus( TString Date, TString variableA, TString variableScanA, float variableValuesA[15],
		       TString fileA, TString treeSignalA, TString treeBkgdA, TString numeratorSignalA, TString denominatorSignalA, TString numeratorBkgdA, TString denominatorBkgdA, TString textA,
		       TString outFileName, TString xaxis, TString yaxis, TString titleText, int bins, float xlow, float xhigh, float ylow, float yhigh){


  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/tdrstyle.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/plotRateScaleReturnTH1F.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/plotRateScaleReturnTH1FOred.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/plotEfficiencyReturnASYM.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/plotResolution.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/plotTProfile.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/tauSeedStudy/getNEntries.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/createLuts/fToS.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/ROCCurve/returnRatePT.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/Level1/ROCCurve/plotReturnEfficiency.C");          
   
  setTDRStyle();
  //The dummy file is required to create the workspace
  TFile   *tauFile  = new TFile("dummy");
  TCanvas *Tcan2    = new TCanvas("Tcan2","",100,20,800,600); Tcan2->cd();  Tcan2->SetFillColor(0);

  TPad* pad1        = new TPad("pad1","The pad",0,0,0.98,1);
  applyPadStyle(pad1);

  TLegend *leg = new TLegend(0.47,0.8,0.655,0.9188);//  Leg = new TLegend(0.74,0.65,0.99,0.95);
  applyLegStyle(leg);

  TString denomCut;
  TString xaxis;
  TString yaxis;
  TString text = "";
  Color_t color;

  Double_t signal[100], bkgd[100];
  //Double_t variableValues[15] =  { 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 48, 50, 55, 60};

  vector<TPaveText*>  variableValuesText; 

  color = kOrange-3;
  xaxis = "p_{T} [GeV]";
  color = kRed;
  

  for(int i = 0; i < 14; i++){
    //input variable values as strings for text
    float variableValue  = variableValuesA[i];
    std::ostringstream strs;
    strs << variableValue;
    std::string text1 = strs.str();
    variableValue = variableValuesA[i];
    //finish creating string values

    //create numeratorCut
    TString numeratorCut    = variableScanA + "<" + fToS(variableValue);

    //Get Signal Efficiency
    TString tempOutNameSig  = Date+"/sigVar-"  + fToS(variableValue) + outFileName;
    signal[i]  = plotReturnEfficiency(fileA, treeSignalA, variableA, numeratorCut +"&&"+numeratorSignalA, denominatorSignalA, tempOutNameSig,  xaxis, yaxis, text, bins, xlow, xhigh, color);

    //Get Background Efficiency
    TString tempOutNameBkgd = Date+"/bkgdVar-" + fToS(variableValue) + outFileName;
    bkgd[i]    = plotReturnEfficiency(fileA, treeBkgdA,   variableA, numeratorCut +"&&"+numeratorBkgdA , denominatorBkgdA, tempOutNameBkgd, xaxis, yaxis, text, bins, xlow, xhigh, color);

    std::cout<<"Numerator Selection "+variableA+": "<<variableValue <<" signal: "<<signal[i]<<" fake: "<<bkgd[i]<<std::endl;

    //Create Text Per Marker
    TPaveText *tempText = new TPaveText( signal[i]-0.015, bkgd[i]+1, signal[i]+ 0.005, bkgd[i]+0.3);
    tempText->AddText(text1.c_str());
    tempText->SetFillColor(0);
    tempText->SetLineColor(0);
    tempText->SetShadowColor(0);
    tempText->SetTextColor(color);
    variableValuesText.push_back(tempText);
  }

  TGraph* rocA = new TGraph(14,signal,bkgd);
  rocA->SetLineColor(color);
  rocA->SetMarkerColor(color);
  rocA->SetMarkerStyle(4);

  //Tcan2->cd();
  pad1->cd();
  pad1->SetGrid(0,0); 
  rocA->Draw();
  rocA->GetXaxis()->SetTitle("Signal Efficiency");
  rocA->GetYaxis()->SetTitle("Background Efficiency");
  rocA->GetYaxis()->SetTitleOffset(0.85);

  rocA->SetMaximum(1);
  rocA->SetMinimum(0);

  //pad1->SetLogy();
  //rocS3Iso->Draw("lpsame");
  rocA->Draw("lpsame");
  //rocS1Iso->Draw("lpsame");

  /*  
  gr->Draw("psame");
  gr->SetLineColor(kGreen+1);
  gr->SetMarkerColor(kGreen+1);
  gr->SetMarkerStyle(21);
  gr->SetMarkerSize(1.5);

  gr2->Draw("psame");
  gr2->SetLineColor(kBlue);
  gr2->SetMarkerColor(kBlue);
  gr2->SetMarkerStyle(21);
  gr2->SetMarkerSize(1.5);
  */
  /*
  TPaveText *info1 = new TPaveText(0.188,0.733,0.45,0.762,"NDC");
  info1->AddText("#bf{Run I}");
  info1->SetFillColor(kGreen+1);
  info1->SetTextColor(kGreen+1);
  info1->SetFillStyle(0);
  info1->SetBorderSize(0);
  info1->SetShadowColor(0);
  info1->SetTextSize(0.05);
  info1->Draw("E");
*/
  /*
  TPaveText *info3 = new TPaveText(0.518,0.3333,0.638,0.4333,"NDC");
  info3->AddText("#bf{#splitline{Stage-2}{Actual Rate}}");
  info3->SetFillColor(kBlue);
  info3->SetTextColor(kBlue);
  info3->SetFillStyle(0);
  info3->SetBorderSize(0);
  info3->SetShadowColor(0);
  info3->SetTextSize(0.05);
  info3->Draw("E");
  */
  /* //opt1
  TPaveText *info = new TPaveText(0.688,0.2833,0.818,0.3933,"NDC");
  info->AddText("2015 Data");
  info->SetFillColor(kMagenta);
  info->SetTextColor(kMagenta);
  info->SetFillStyle(0);
  info->SetBorderSize(0);
  info->SetShadowColor(0);
  info->Draw("E");
  */
  /*
  TPaveText *info2 = new TPaveText(0.328,0.2433,0.498,0.4033,"NDC");
  info2->AddText("#bf{ChargedIsolation}");
  info2->SetFillColor(kMagenta);
  info2->SetTextColor(kMagenta);
  info2->SetFillStyle(0);
  info2->SetBorderSize(0);
  info2->SetShadowColor(0);
  info2->SetTextSize(0.05);
  info2->Draw("E");
  */
  rocA->SetLineColor(kBlack);
  //rocS3Iso->SetLineColor(kBlack);

  leg->SetHeader(titleText);
  //leg->AddEntry(rocS1Iso,"#bf{2015 Data}","p");
  //leg->AddEntry(rocS3Iso,"#bf{Stage-3a}","p");
  leg->AddEntry(rocA,variableA,"p");

  leg->SetFillColor(kWhite);
  leg->SetFillStyle(1001);  
  leg->SetMargin(0.15);
  leg->SetTextSize(0.035);

  leg->Draw();

  rocA->GetXaxis()->SetRangeUser(0,1.0);

  std::cout<<"variableValuesText.size() "<<variableValuesText.size()<<std::endl;
  for(unsigned int j = 0; i < variableValuesText.size(); j++){

    variableValuesText.at(j)->Draw();
    variableValuesText.at(j)->SetFillColorAlpha(kWhite, 0.01);
    variableValuesText.at(j)->SetLineColorAlpha(kWhite, 0.001);
    variableValuesText.at(j)->SetBorderSize(0);
    
  }

  //TPaveText *ptext = new TPaveText(4,1000,40,1.05,"NDC");
  TPaveText *ptext = new TPaveText(0.18,0.947, 0.46,1.0,"NDC");
  ptext->AddText("CMS #bf{#it{Preliminary}}");
  ptext->SetFillColor(0);
  ptext->SetFillStyle(0);
  ptext->SetBorderSize(0);
  ptext->SetShadowColor(0);
  ptext->Draw("E");

  TPaveText *info4 = new TPaveText(0.23,0.83,0.47,0.98,"NDC");
  info4->AddText("#bf{ZeroBias, Run 259721}");
  info4->SetFillColor(0);
  info4->SetFillStyle(0);
  info4->SetBorderSize(0);
  info4->SetShadowColor(0);
  //info4->Draw("E");

  TPaveText *info5 = new TPaveText(0.235,0.8,0.345,0.9,"NDC");
  info5->AddText("#bf{Z(#tau#tau), MC}");
  info5->SetFillColor(0);
  info5->SetFillStyle(0);
  info5->SetBorderSize(0);
  info5->SetShadowColor(0);
  info5->Draw("E");


  Tcan2->SaveAs(Date+"/ROC_Curve"+variableA+"-"+outFileName+".png");
  Tcan2->SaveAs(Date+"/ROC_Curve"+variableA+"-"+outFileName+".pdf");

}
