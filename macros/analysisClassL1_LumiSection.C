#include "L1Tree.h"
#include "analysisClassL1.h"
#include <algorithm>

void analysisClassL1::loop(){

  int maxLumiSection = 1693;  

  L1Tree * l1Tree = getTree<L1Tree>("l1Tree");

  int n_events = l1Tree -> fChain -> GetEntries();

  l1Tree -> fChain -> SetBranchStatus("*", kFALSE);
  l1Tree -> fChain -> SetBranchStatus("lumi", kTRUE);

  TH1F * h_lumi = makeTH1F("h_lumi",maxLumiSection,0.5,maxLumiSection+0.5);

  for (int i = 0; i < n_events; ++i){
    l1Tree -> GetEntry(i);
    if ( (i + 1) % 10000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;
    
    int lumiSection = l1Tree -> lumi;

    h_lumi -> Fill(lumiSection);

  };
};
