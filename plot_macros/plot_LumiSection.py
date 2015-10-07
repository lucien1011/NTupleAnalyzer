
import ROOT
from PlotParser import parser

ROOT.gROOT.SetBatch(ROOT.kTRUE)

args = parser.parse_args()

inFileName = args.inputPath
outFileName = args.outputPath

inputFile = ROOT.TFile(inFileName,"READ")

c = ROOT.TCanvas()
hist = inputFile.Get("h_lumi")
hist.SetStats(0)
hist.SetTitle(" ; LumiSection ; Number of Event")
hist.Draw()

c.SaveAs(outFileName)
