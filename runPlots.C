{
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/phase2/Timing/TimingPlotting/plotVarComparisonsInput.C");
  gROOT->ProcessLine(".L /Users/isobelojalvo/Documents/work/Analysis/phase2/Timing/TimingPlotting/plot4VarComparisonsInput.C");
  /*  
  plotVarComparisonsInput( "(genTauPt-tauPt)/genTauPt", "~/Dropbox/8_10_17/controlPlots", 
			   "timing-Aug10/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
			   "timing-Aug10/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
			   "Timing_MiniAOD", "ptResolution", "p_{T} Resolution" , 50, -1, 1);

    plotVarComparisonsInput( "(genTauEta-tauEta)", "~/Dropbox/8_10_17/controlPlots", 
			   "timing-Aug10/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
			   "timing-Aug10/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
			     "Timing_MiniAOD", "etaResolution", "#eta Resolution" , 100, -0.05, 0.05);

    plotVarComparisonsInput( "(tauEta)", "~/Dropbox/8_10_17/controlPlots", 
			     "timing-Aug10/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
			     "timing-Aug10/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
			     "Timing_MiniAOD", "eta", "#tau_{h} #eta" , 50, -2.4, 2.4);

    plotVarComparisonsInput( "(nvtx)", "~/Dropbox/8_10_17/controlPlots", 
			     "timing-Aug10/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
			     "timing-Aug10/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
			     "Timing_MiniAOD", "nVtx", "nVtx" , 50, 0, 200);

    plotVarComparisonsInput( "(tauMass)", "~/Dropbox/8_10_17/controlPlots", 
			     "timing-Aug11/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
			     "timing-Aug11/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
			     "Timing_MiniAOD", "tauMass", "tauMass" , 25, 0, 2);

    plotVarComparisonsInput( "(tauPt)", "~/Dropbox/8_10_17/controlPlots", 
			     "timing-Aug11/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
			     "timing-Aug11/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
			     "Timing_MiniAOD", "tauPt", "#tau_{h} p_{T}" , 50, 0, 100);
*/

  plotVarComparisonsInput( "nhIso", "~/Dropbox/8_16_17/controlPlots", 
			   "timing-Aug16/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
			   "timing-Aug16/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
			   "Timing_MiniAOD", "nHIso", "Neutral Hadron Iso Sum" , 50, 0, 50);

  plotVarComparisonsInput( "tauCHIso1_ntracks", "~/Dropbox/8_16_17/controlPlots", 
			   "timing-Aug16/DYJets_200PU.root", "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "200PU Z#rightarrow#tau#tau", 
			   "timing-Aug16/DYJets_0PU.root",   "cutBased/Ntuple", "genTauPt>30&&tauPt>20&&abs(genTauEta)<2.1", "    0PU Z#rightarrow#tau#tau", 
			   "Timing_MiniAOD", "n_chiso_tracks_1", "N CH Iso Tracks 1ps" , 20, 0, 20);


}
