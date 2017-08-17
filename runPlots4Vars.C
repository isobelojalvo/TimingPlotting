{
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/phase2/Timing/TimingPlotting/plotVarComparisonsInput.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/phase2/Timing/TimingPlotting/plot4VarComparisonsInput.C");
  

    plot4VarComparisonsInput("~/Dropbox/8_16_17/controlPlots", 
			     "tauCHIso", "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "Nominal Charged Isolation", 
			     "tauCHIsoOther", "timing-Aug14/DYJets_200PU.root","cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "All Timed Tracks", 
			     "tauCHIso3", "timing-Aug14/DYJets_200PU.root","cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "3 #sigma interval", 
			     "tauCHIso1", "timing-Aug14/DYJets_200PU.root","cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "1 #sigma interval", 
			     "Timing_MiniAOD", "tauChIsoComp_1_3_All", "#tau_{h} Charged Isolation" , 50, 0, 10, true);

    plot4VarComparisonsInput("~/Dropbox/8_16_17/controlPlots", 
			     "tauCHIso", "timing-Aug14/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "Nominal Charged Isolation", 
			     "tauCHIso6", "timing-Aug14/DYJets_200PU.root","cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "6 #sigma interval", 
			     "tauCHIso5", "timing-Aug14/DYJets_200PU.root","cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "5 #sigma interval", 
			     "tauCHIso4", "timing-Aug14/DYJets_200PU.root","cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "4 #sigma interval", 
			     "Timing_MiniAOD", "tauChIsoComp_4_5_6", "#tau_{h} Charged Isolation" , 100, 0, 100, true);


    plot4VarComparisonsInput("~/Dropbox/8_16_17/controlPlots", 
			     "nIsoTracks", "timing-Aug16/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "Nominal Charged Isolation", 
			     "tauCHIsoOther_ntracks", "timing-Aug16/DYJets_200PU.root","cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "20ps interval", 
			     "tauCHIso10_ntracks", "timing-Aug16/DYJets_200PU.root","cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "10ps interval", 
			     "tauCHIso3_ntracks", "timing-Aug16/DYJets_200PU.root","cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "3ps interval", 
			     "Timing_MiniAOD", "tauChIsoComp_3_10_20", "#tau_{h} N CH Iso Tracks" , 20, 0, 20, true);


}
