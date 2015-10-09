#include "L1Tree.h"
#include "L1ExtraTree.h"
#include "analysisClassL1.h"
#include <algorithm>

void analysisClassL1::loop(){

  std::string HLTTrigger="HLT_Any";

  std::string preFireTrigger = "L1_SingleJet128";
  std::string nominalTrigger = "L1_SingleJet176";

  L1Tree * l1Tree = getTree<L1Tree>("l1Tree");

  int n_events = l1Tree -> fChain -> GetEntries();

  // loadSingleJetTrigMap();
  loadBitMap();

  l1Tree -> fChain -> SetBranchStatus("*", kFALSE);
  l1Tree -> fChain -> SetBranchStatus("run", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("lumi", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("event", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("tw1", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("tw2", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("tt" , kTRUE);
  // l1Tree -> fChain -> SetBranchStatus("hlt", kTRUE);

  FILE * f;
  f = fopen("output/ExpressPhysics_NoiseFilter_254833/ExpressPhysics254833_EventList.txt","w");

  for (int i = 0; i < n_events; ++i){
   
    l1Tree -> GetEntry(i);
    if ( (i + 1) % 1000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;

    // hlt = l1Tree -> hlt;
    // bool accept = checkHLT(HLTTrigger);
    // if (not accept) continue;

    int runNumber = l1Tree -> run ;
    int lumiSection = l1Tree -> lumi ;
    int eventNumber = l1Tree -> event ;

    if (lumiSection < 126) continue;

    tw1 = l1Tree -> tw1;
    tw2 = l1Tree -> tw2;

    bool Bx1Fired = checkTriggerBit(BitMap[preFireTrigger],1);      
    bool Bx2Fired = checkTriggerBit(BitMap[nominalTrigger],2);
    bool ttbit0 = (tt[2]>>0)&1;

    if (Bx1Fired && Bx2Fired && ttbit0){
      fprintf(f,"%d %d %d",runNumber,lumiSection,eventNumber);
    };
  };

  fclose(f);

}
