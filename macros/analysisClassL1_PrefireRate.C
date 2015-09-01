#include "L1Tree.h"
#include "L1ExtraTree.h"
#include "analysisClassL1.h"
#include <algorithm>

void analysisClassL1::loop(){

  std::string MyTrigger="HLT_Any";

  L1Tree * l1Tree = getTree<L1Tree>("l1Tree");

  int n_events = l1Tree -> fChain -> GetEntries();

  loadTrigMap();

  l1Tree -> fChain -> SetBranchStatus("*", kFALSE);
  l1Tree -> fChain -> SetBranchStatus("run", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("lumi", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("event", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("bx", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("hlt", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("tw1", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("tw2", kTRUE);

  // Define Histograms
  char hist_name[200];
  for (trigbit_iter = HFPrefiringBitMap.begin(); trigbit_iter != HFPrefiringBitMap.end(); trigbit_iter++){
      int ibit = trigbit_iter->second;
      std::string triggerName = trigbit_iter->first;
      sprintf(hist_name,"%s_%s",triggerName.c_str(),"_preFireRate");
      histoMap[triggerName] = makeTH1F(hist_name,5,-0.5,4.5);

  };
  int nBx1 = 0;
  int nBx2 = 0;

  for (int i = 0; i < n_events; ++i){
    l1Tree -> GetEntry(i);
    if ( (i + 1) % 1000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;

    int runNumber = l1Tree -> run ;
    int bunchNumber = l1Tree -> bx ;
    int lumiSection = l1Tree -> lumi ;
    int eventNumber = l1Tree -> event ;

    tw1 = l1Tree -> tw1;
    tw2 = l1Tree -> tw2;

    // check if the event is fired with the selected HLT
    bool accept = checkHLT(MyTrigger);
    if (not accept) continue;

    Int_t nBx=tw1.size();
    for (trigbit_iter = HFPrefiringBitMap.begin(); trigbit_iter != HFPrefiringBitMap.end(); trigbit_iter++){
      int ibit = trigbit_iter->second;
      std::string triggerName = trigbit_iter->first;

      bool Bx1Fired = checkTriggerBit(HFPrefiringBitMap["L1_SingleJet128"],1);      
      bool Bx2Fired = checkTriggerBit(ibit,2);      

      if (Bx2Fired){
        histoMap[triggerName] -> Fill(2);
	nBx2++
	if (Bx1Fired){
	  histoMap[triggerName] -> Fill(1);
	  nBx1++;
	};
      };
    }
  };
  std::cout << "Prefire Rate: " << nBx1/nBx2 << std::endl;

}
