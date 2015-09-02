#include "L1Tree.h"
#include "L1ExtraTree.h"
#include "analysisClassL1.h"
#include <algorithm>

void analysisClassL1::loop(){

  std::string MyTrigger="HLT_Any";
  std::string benchMarkTrigger = "L1_SingleJet128";

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
  // char hist_name[200];
  // for (trigbit_iter = HFPrefiringBitMap.begin(); trigbit_iter != HFPrefiringBitMap.end(); trigbit_iter++){
  //     int ibit = trigbit_iter->second;
  //     std::string triggerName = trigbit_iter->first;
  //     sprintf(hist_name,"%s_%s",triggerName.c_str(),"_preFireRate");
  //     histoMap[triggerName] = makeTH1F(hist_name,5,-0.5,4.5);

  // };
  std::map<std::string,int> nBx1,nBx2;

  for (int i = 0; i < n_events; ++i){
    l1Tree -> GetEntry(i);
    if ( (i + 1) % 10000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;

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

      bool Bx1Fired = checkTriggerBit(HFPrefiringBitMap[benchMarkTrigger],1);      
      bool Bx2Fired = checkTriggerBit(ibit,2);      

      if (Bx2Fired){
        if (nBx2.find(triggerName) == nBx2.end()){
	  nBx2[triggerName] = 0;
	};
	nBx2[triggerName]++;
	if (Bx1Fired){
	  if (nBx2.find(triggerName) == nBx2.end()){
	    nBx1[triggerName] = 0;
	  };
          nBx1[triggerName]++;
	};
      };
    }
  };

  // double x[nBx2.size()],y[nBx2.size()];
  // TGraph* graph = makeTGraph();
  TH1F * graph = makeTH1F(benchMarkTrigger.c_str(),nBx2.size(),-0.5,nBx2.size()-0.5);
  for (std::map<std::string,int>::iterator it = nBx2.begin(); it != nBx2.end(); it++){
    std::string triggerName = it -> first;
    // std::cout << "Making TGraph with Trigger " << triggerName << std::endl;
    // count++;
    int nIt = std::distance(nBx2.begin(),it)+1;
    graph -> SetBinContent(nIt,(double) nBx1[triggerName]/ it -> second);
    graph -> GetXaxis() -> SetBinLabel(nIt,triggerName.c_str());
    // std::cout << nIt << std::endl;
    // graph -> SetPoint(nIt,(double)nIt,(double) nBx1[triggerName]/ it -> second);
    // graph -> GetXaxis() -> SetBinLabel(nIt+1,triggerName.c_str());
    // x[nIt] = (double) nIt;
    // y[nIt] = (double) nBx1[triggerName]/ it -> second;
    // std::cout << triggerName << " "  << y[nIt] << std::endl ;
  };
  // TGraph* graph = makeTGraph(nBx2.size(),x,y);
  // gStyle -> SetMarkerStyle(2);
  char titleName[200];
  sprintf(titleName,"Bench Mark Trigger: %s ; ; Pretrigger Rate",benchMarkTrigger.c_str());
  graph -> SetTitle(titleName);
  // graph -> UseCurrentStyle();

}
