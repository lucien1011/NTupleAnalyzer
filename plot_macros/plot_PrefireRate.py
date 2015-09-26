
import argparse
import ROOT

parser = argparse.ArgumentParser(description='Make an input list')

parser.add_argument('-i', metavar="inputPath", dest='inputPath',action="store" , required=True, help='Input file path',type=str)
parser.add_argument('-o', metavar="output", dest='outputPath',action="store" , required=True, help='Output file path',type=str)

args = parser.parse_args()

inFileName = args.inputPath
outFileName = args.outputPath

inputFile = ROOT.TFile(inFileName,"READ")
histNames = [k.GetName() for k in inputFile.GetListOfKeys()]
hists = [ inputFile.Get(histName) for histName in histNames]
maximum = max([hist.GetMaximum() for hist in hists])

c = ROOT.TCanvas()
l = ROOT.TLegend(0.1,0.7,0.48,0.9)
for i,hist in enumerate(hists):
	hist.SetStats(0)
	hist.SetTitle(histName)
	hist.SetLineColor(i+1)
	hist.GetYaxis().SetRangeUser(0,maximum*1.1)
	hist.Draw("same")
	l.AddEntry(hist,hist.GetName().replace("_"," "),"l")
l.Draw()
c.SaveAs(outFileName)
inputFile.Close()

