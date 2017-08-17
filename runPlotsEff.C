{
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/phase2/Timing/TimingPlotting/plotEfficiency.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/phase2/Timing/TimingPlotting/plot3Efficiency.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/phase2/Timing/TimingPlotting/plot5Efficiency.C");

  plotEfficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		  "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "tauPt>30&&abs(genTauEta)<2.1", "genTauPt>20&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
		  "timing-Aug14/DYJets_0PU.root",   "cutBased/Ntuple", "tauPt>30&&abs(genTauEta)<2.1", "genTauPt>20&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
		  "Timing_MiniAOD", "Gen p_{T}","Efficiency Reconstruction" , 50, 0, 100);

  plotEfficiency( "genTauEta", "~/Dropbox/8_16_17/controlPlots", 
		  "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>35&&tauPt>20", "genTauPt>20", "200PU Z#rightarrow#tau#tau", 
		  "timing-Aug14/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>35&&tauPt>20", "genTauPt>20", "    0PU Z#rightarrow#tau#tau", 
		  "Timing_MiniAOD", "Gen #eta","Efficiency Reconstruction" , 50, -4, 4);

  plotEfficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		  "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso<2", "genTauPt>15&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
		  "timing-Aug14/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso<2", "genTauPt>15&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
		  "Timing_MiniAOD_chIso2", "Gen p_{T}" , "Efficiency Ch-Iso 2 GeV", 50, 0, 100);

  plotEfficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		  "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
		  "timing-Aug14/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
		  "Timing_MiniAOD_chIso2p5", "Gen p_{T}" , "Efficiency Ch-Iso 2.5 GeV", 50, 0, 100);

  plotEfficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		  "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "tauPt>15&&abs(genTauEta)<2.1&&tauCHIso3<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
		  "timing-Aug14/DYJets_0PU.root",   "cutBased/Ntuple", "tauPt>15&&abs(genTauEta)<2.1&&tauCHIso<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
		  "Timing_MiniAOD_chIso3ps2p5", "Gen p_{T}" , "Efficiency Ch-Iso, 3ps 2.5 GeV", 50, 0, 100);

  plotEfficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		  "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "tauPt>15&&abs(genTauEta)<2.1&&tauCHIso4<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
		  "timing-Aug14/DYJets_0PU.root",   "cutBased/Ntuple", "tauPt>15&&abs(genTauEta)<2.1&&tauCHIso<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
		  "Timing_MiniAOD_chIso4ps2p5", "Gen p_{T}" , "Efficiency Ch-Iso, 4ps 2.5 GeV", 50, 0, 100);

  plot3Efficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&dmf==0", "genTauPt>15&&abs(genTauEta)<2.1&&dmf==0", "1 Prong", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&dmf==1", "genTauPt>15&&abs(genTauEta)<2.1&&dmf==1", "1 Prong #pi^{0}", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&dmf==10", "genTauPt>15&&abs(genTauEta)<2.1&&dmf==10", "3 Prong", 
		   "Timing_MiniAOD-DM-200PU", "Gen p_{T}", "Efficiency Reco" , 50, 0, 100);
  
  plot3Efficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		   "timing-Aug14/DYJets_0PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&dmf==0", "genTauPt>15&&abs(genTauEta)<2.1&&dmf==0", "1 Prong", 
		   "timing-Aug14/DYJets_0PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&dmf==1", "genTauPt>15&&abs(genTauEta)<2.1&&dmf==1", "1 Prong #pi^{0}", 
		   "timing-Aug14/DYJets_0PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&dmf==10", "genTauPt>15&&abs(genTauEta)<2.1&&dmf==10", "3 Prong", 
		   "Timing_MiniAOD-DM-0PU", "Gen p_{T}", "Efficiency DMF" , 50, 0, 100);

  plot3Efficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso0<2", "genTauPt>15&&abs(genTauEta)<2.1", "1 ps Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso3<2", "genTauPt>15&&abs(genTauEta)<2.1", "3 ps Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso8<2", "genTauPt>15&&abs(genTauEta)<2.1", "8 ps Interval", 
		   "Timing_MiniAOD-Iso-200PU", "Gen p_{T}" , "Efficiency 2 GeV Ch-Iso" , 50, 0, 150);

  plot3Efficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso0<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "1 ps Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso3<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "3 ps Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso8<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "8 ps Interval", 
		   "Timing_MiniAOD-Iso-200PU", "Gen p_{T}", "Efficiency 2.5 GeV Ch-Iso" , 50, 0, 150);

  plot3Efficiency( "genTauEta", "~/Dropbox/8_16_17/controlPlots", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>20&&tauCHIso0<2.5", "genTauPt>15", "1 ps Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>20&&tauCHIso3<2.5", "genTauPt>15", "3 ps Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>20&&tauCHIso8<2.5", "genTauPt>15", "8 ps Interval", 
		   "Timing_MiniAOD-Eta-200PU", "Gen p_{T}", "Efficiency 2.5 GeV Ch-Iso" , 50, -4, 4);

  plot5Efficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		   "timing-Aug14/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso<2.5",  "genTauPt>15&&abs(genTauEta)<2.1", "0 PU", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso1<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "1 ps Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso3<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "3 ps Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso20<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "All Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "No Timing", 
		   "Timing_MiniAOD-Iso-200PU-all", "Gen p_{T}", "Efficiency 2.5 GeV Ch-Iso" , 50, 0, 150);

  plot5Efficiency( "genTauPt", "~/Dropbox/8_16_17/controlPlots", 
		   "timing-Aug14/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso<4",  "genTauPt>15&&abs(genTauEta)<2.1", "0 PU", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso1<0.9", "genTauPt>15&&abs(genTauEta)<2.1", "1 ps Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso3<1", "genTauPt>15&&abs(genTauEta)<2.1", "3 ps Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIsoOther<2.5", "genTauPt>15&&abs(genTauEta)<2.1", "All Interval", 
		   "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>15&&tauPt>30&&abs(genTauEta)<2.1&&tauCHIso<4", "genTauPt>15&&abs(genTauEta)<2.1", "No Timing", 
		   "Timing_MiniAOD-Iso-graduated-200PU-all", "Gen p_{T}", "Efficiency 2.5 GeV Ch-Iso" , 50, 0, 150);



}
