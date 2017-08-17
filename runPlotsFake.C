{
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/phase2/Timing/TimingPlotting/plot3Efficiency.C");
  plot3Efficiency( "tauPt", "~/Dropbox/8_10_17/controlPlots", 
		   "timing-Aug11-1/DYJets_200PU.root", "cutBased/jetNtuple", "tauPt>20&&tauCHIso1<0.9&&(dmf==0||dmf==1||dmf==10)&&jetPt>18", "jetPt>18", "1 ps Interval", 
		   "timing-Aug11-1/DYJets_200PU.root", "cutBased/jetNtuple", "tauPt>20&&tauCHIso3<1&&(dmf==0||dmf==1||dmf==10)&&jetPt>18", "jetPt>18", "3 ps Interval", 
		   "timing-Aug11-1/DYJets_200PU.root", "cutBased/jetNtuple", "tauPt>20&&tauCHIso<4&&(dmf==0||dmf==1||dmf==10)&&jetPt>18", "jetPt>18", "8 ps Interval", 
		   "Fakes-Timing_MiniAOD-Iso-200PU", "Gen p_{T}", "Efficiency 2.5 GeV Ch-Iso" , 50, 0, 150);
}
