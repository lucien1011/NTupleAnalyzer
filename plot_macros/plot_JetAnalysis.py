
import ROOT
from PlotParser import parser

def selectHist(histName,requireString):
	return requireString in histName.split("_")[1]

selectHistString = "preFireEtaPhiBin"

ROOT.gROOT.SetBatch(ROOT.kTRUE)
args = parser.parse_args()
inFileName = args.inputPath
outFileName = args.outputPath

inputFile = ROOT.TFile(inFileName,"READ")
histNames = [k.GetName() for k in inputFile.GetListOfKeys()]
hists = [ inputFile.Get(histName) for histName in histNames if selectHist(histName,selectHistString)]

c = ROOT.TCanvas()
c.Print(outFileName+"[")
for i,hist in enumerate(hists):
	hist.SetStats(0)
	hist.Draw("colz")
	c.Print(outFileName)
c.Print(outFileName+"]")
inputFile.Close()

