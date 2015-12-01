
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
jetThresholds = [ int(k.GetName().split("_")[-1]) for k in inputFile.GetListOfKeys() if nominalBxFireHistName not in k.GetName() if "HBHE" in k.GetName()]
hbheHists = [ inputFile.Get(hbhePrefireHistName%jetThreshold).Clone("Clone_"+hbhePrefireHistName%jetThreshold) for jetThreshold in jetThresholds ]
hfHists = [ inputFile.Get(hfPrefireHistName%jetThreshold).Clone() for jetThreshold in jetThresholds ]

#____________________________________________________________________________||

hbheGraphs = []
for hbheHist in hbheHists:
	graph = hbheHist.CreateGraph()
	graph.SetName("TEff_"+hbheHist.GetName())
	hbheGraphs.append( graph )

hfGraphs = []
for hfHist in hfHists:
	graph = hfHist.CreateGraph()
	graph.SetName("TEff_"+hfHist.GetName())
	hfGraphs.append( graph )

hbheMax = max([ ROOT.TMath.MaxElement( hbheGraph.GetN() , hbheGraph.GetY() ) for hbheGraph in hbheGraphs ])
hfMax = max([ ROOT.TMath.MaxElement( hfGraph.GetN() , hfGraph.GetY() ) for hfGraph in hfGraphs ])

#____________________________________________________________________________||

c = ROOT.TCanvas()
l1 = ROOT.TLegend(0.1,0.7,0.48,0.9)
c.Print(outFileName+"[")

for i,hbheHist in enumerate(hbheGraphs):
	hbheHist.SetLineColor(i+1)
	hbheHist.GetYaxis().SetRangeUser(0.,hbheMax*1.2)
	hbheHist.SetTitle(" HBHE ; Jet pT Threshold at Nominal BX ; Prefire Probability ")
	#hbheHist.Paint("AP")
	if i == 0:
		hbheHist.Draw()
	else:
		hbheHist.Draw("same")
	c.Update()
	l1.AddEntry(hbheHist,"Leading Central Jet pT at Bx -1 > %s"%hbheHist.GetName().split("_")[-1],"l")
l1.Draw()
c.Print(outFileName)

c.Clear()
l2 = ROOT.TLegend(0.1,0.7,0.4,0.9)
for i,hfHist in enumerate(hfGraphs):
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



