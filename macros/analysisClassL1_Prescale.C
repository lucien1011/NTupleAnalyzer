#include "L1Tree.h"
#include "analysisClassL1.h"
#include <algorithm>

void analysisClassL1::loop(){

  // String for unprescaled trigger
  std::string uTrigger = "L1_SingleJet200";

  // String for the last prescaled trigger
  std::string pTrigger = "L1_SingleJet176";

  L1Tree * l1Tree = getTree<L1Tree>("l1Tree");

  int n_events = l1Tree -> fChain -> GetEntries();

  loadBitMap();

  l1Tree -> fChain -> SetBranchStatus("*", kFALSE);
  l1Tree -> fChain -> SetBranchStatus("tw1", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("tw2", kTRUE);

  TH1F * histo = makeTH1F("prescaled_vs_scaled",2,-0.5,1.5);

  for (int i = 0; i < n_events; ++i){
    l1Tree -> GetEntry(i);
    if ( (i + 1) % 10000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;

    tw1 = l1Tree -> tw1;
    tw2 = l1Tree -> tw2;

    bool unprescaled_fire = checkTriggerBit(BitMap[uTrigger],2);
    bool prescaled_fire = checkTriggerBit(BitMap[pTrigger],2);

    if (unprescaled_fire){
      histo -> Fill(1);
      if (prescaled_fire){
        histo -> Fill(0);
      };
    };

  };

  histo -> GetXaxis() -> SetBinLabel(1,pTrigger.c_str());
  histo -> GetXaxis() -> SetBinLabel(2,uTrigger.c_str());


};
