
import ROOT
from PlotParser import parser

#____________________________________________________________________________||
#Configurables

hbhePrefireHistName = "h_previousBxFire_HBHE_%s"
hfPrefireHistName = "h_previousBxFire_HF_%s"
nominalBxFireHistName = "h_nominalBxFire"

#____________________________________________________________________________||

ROOT.gROOT.SetBatch(ROOT.kTRUE)
args = parser.parse_args()
inFileName = args.inputPath
outFileName = args.outputPath

#____________________________________________________________________________||

inputFile = ROOT.TFile(inFileName,"READ")
nomBxFireHist = inputFile.Get(nominalBxFireHistName)
jetThresholds = [ int(k.GetName().split("_")[-1]) for k in inputFile.GetListOfKeys() if nominalBxFireHistName not in k.GetName() if "HBHE" in k.GetName()]
hbheHists = [ inputFile.Get(hbhePrefireHistName%jetThreshold).Clone("Clone_"+hbhePrefireHistName%jetThreshold) for jetThreshold in jetThresholds ]
hfHists = [ inputFile.Get(hfPrefireHistName%jetThreshold).Clone() for jetThreshold in jetThresholds ]
for hbheHist in hbheHists:
	hbheHist.Divide(nomBxFireHist)
for hfHist in hfHists:
	hfHist.Divide(nomBxFireHist)
hbheMax = max([ hbheHist.GetMaximum() for hbheHist in hbheHists ])
hfMax = max([ hfHist.GetMaximum() for hfHist in hfHists ])

#____________________________________________________________________________||

c = ROOT.TCanvas()
l1 = ROOT.TLegend(0.1,0.7,0.48,0.9)
c.Print(outFileName+"[")
for i,hbheHist in enumerate(hbheHists):
	hbheHist.SetStats(0)
	hbheHist.SetLineColor(i+1)
	hbheHist.GetYaxis().SetRangeUser(0.,hbheMax*1.2)
	hbheHist.SetTitle(" HBHE ; Jet pT Threshold at Nominal BX ; Prefire Probability ")
	if i == 0:
		hbheHist.Draw()
	else:
		hbheHist.Draw("same")
	l1.AddEntry(hbheHist,"Leading Central Jet pT at Bx -1 > %s"%hbheHist.GetName().split("_")[-1],"l")
l1.Draw()
c.Print(outFileName)

l2 = ROOT.TLegend(0.1,0.7,0.4,0.9)
for i,hfHist in enumerate(hfHists):
	hfHist.SetStats(0)
	hfHist.SetLineColor(i+1)
	hfHist.GetYaxis().SetRangeUser(0.,hfMax*1.2)
	hfHist.SetTitle(" HF ; Jet pT Threshold at Nominal BX ; Prefire Probability ")
	if i == 0:
		hfHist.Draw()
	else:
		hfHist.Draw("same")
	l2.AddEntry(hfHist,"Leading Fwd pT at BX -1 > %s"%hfHist.GetName().split("_")[-1],"l")
l2.Draw()
c.Print(outFileName)
c.Print(outFileName+"]")

#____________________________________________________________________________||
inputFile.Close()

