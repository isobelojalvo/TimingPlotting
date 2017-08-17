{
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/phase2/Timing/TimingPlotting/plot2ROCCurvesTaus.C");
  float variableValuesA[15] = {0.5, 1.5, 2.0, 3.0, 4.0, 5.0, 6.0, 
			       7.0, 9.0, 12.0, 15.0, 30.0, 40.0, 65.0, 90.0};

  float variableValuesB[15] = {0.5, 0.75, 1.0, 1.5, 2.0, 2.5, 3.0, 4.0, 5.0, 6.0, 
			 7.0, 15.0, 20.0, 40.0, 80.0 };

  plot2ROCCurvesTaus("~/Dropbox/8_16_17/rocPlots",  
		     "tauPt", "tauCHIso",  variableValuesA, 
		    "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "cutBased/jetNtuple", "tauPt>20&&genTauPt>20&&abs(genTauEta)<2.1", "genTauPt>20&&abs(genTauEta)<2.1", "tauPt>20&&jetPt>18&&abs(jetEta)<2.1", "tauPt>20&&jetPt>18&&abs(jetEta)<2.1", "200PU Z#rightarrow#tau#tau", 
		     "tauPt", "tauCHIso3",  variableValuesB, 
		    "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "cutBased/jetNtuple", "tauPt>20&&genTauPt>20&&abs(genTauEta)<2.1", "genTauPt>20&&abs(genTauEta)<2.1", "tauPt>20&&jetPt>18&&abs(jetEta)<2.1", "tauPt>20&&jetPt>18&&abs(jetEta)<2.1", "200PU Z#rightarrow#tau#tau", 
		    "Timing_MiniAOD-tauCHIso-tauCHIso3", "Signal Efficiency", "Bkgd Efficiency","Reconstruction Efficiency", 50, 10, 100, 0, 100);
  

  /*
  plotROCCurvesTaus( "~/Dropbox/8_16_17/rocPlots",  "tauPt", "tauCHIso3",  variableValuesB,
		    "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "cutBased/jetNtuple", "tauPt>20&&genTauPt>20&&abs(genTauEta)<2.1", "genTauPt>20&&abs(genTauEta)<2.1", "tauPt>20&&jetPt>18&&abs(jetEta)<2.1", "jetPt>18&&abs(jetEta)<2.1", "200PU Z#rightarrow#tau#tau", 
		    "Timing_MiniAOD-tauCHIso3", "Signal Efficiency", "Bkgd Efficiency","Reconstruction Efficiency", 50, 10, 100, 0, 100);
  */
}

	 //"timing-Aug14/DYJets_0PU.root",   "cutBased/Ntuple", "tauPt>30&&abs(genTauEta)<2.1", "genTauPt>20&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
