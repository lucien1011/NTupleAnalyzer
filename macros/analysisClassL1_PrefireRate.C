#include "L1Tree.h"
#include "L1ExtraTree.h"
#include "analysisClassL1.h"
#include <algorithm>

double binoError(double selected, double all){
  return sqrt(selected*(1-selected/all))/all ; 
};


void analysisClassL1::loop(){

  std::string MyTrigger="HLT_Any";
  // std::vector<std::string> preFireTrigger = {"L1_SingleJet092","L1_SingleJet128","L1_SingleJet176","L1_SingleJet200","L1_SingleJet240"};
  std::vector<std::string> preFireTrigger = {"L1_HTT075","L1_HTT100","L1_HTT125","L1_HTT150","L1_HTT175","L1_HTT200"};

  L1Tree * l1Tree = getTree<L1Tree>("l1Tree");

  int n_events = l1Tree -> fChain -> GetEntries();

  // loadSingleJetTrigMap();
  loadHTTTrigMap();
  loadBitMap();
  loadPrescaleMap();

  l1Tree -> fChain -> SetBranchStatus("*", kFALSE);
  l1Tree -> fChain -> SetBranchStatus("tw1", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("tw2", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("lumi",kTRUE);

  std::map<std::string,std::map<std::string,int>> nBx1,nBx2;

  for (int i = 0; i < n_events; ++i){
    l1Tree -> GetEntry(i);
    if ( (i + 1) % 10000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;
    int lumi = l1Tree -> lumi;
    if (lumi < 126) continue;
    int prescaleIndex;
    if (lumi < 317){
      prescaleIndex = 6;
    }else{
      prescaleIndex = 7;
    };

    tw1 = l1Tree -> tw1;
    tw2 = l1Tree -> tw2;

    for (int iTrig = 0; iTrig != preFireTrigger.size(); iTrig++){
      Int_t nBx=tw1.size();
      if (nBx1.find(preFireTrigger[iTrig]) == nBx1.end()){
        nBx1[preFireTrigger[iTrig]] = std::map<std::string,int>();
      };
      if (nBx2.find(preFireTrigger[iTrig]) == nBx2.end()){
        nBx2[preFireTrigger[iTrig]] = std::map<std::string,int>();
      };

      for (trigbit_iter = HFPrefiringBitMap.begin(); trigbit_iter != HFPrefiringBitMap.end(); trigbit_iter++){
        int ibit = trigbit_iter->second;
        std::string triggerName = trigbit_iter->first;
        
        bool Bx1Fired = checkTriggerBit(BitMap[preFireTrigger[iTrig]],1);      
        bool Bx2Fired = checkTriggerBit(ibit,2);      
  
        if (Bx2Fired){
          if (nBx2[preFireTrigger[iTrig]].find(triggerName) == nBx2[preFireTrigger[iTrig]].end()){
  	    nBx2[preFireTrigger[iTrig]][triggerName] = 0;
  	  };
  	  nBx2[preFireTrigger[iTrig]][triggerName] += PrescaleMap[prescaleIndex][triggerName];
  	  if (Bx1Fired){
  	    if (nBx2[preFireTrigger[iTrig]].find(triggerName) == nBx2[preFireTrigger[iTrig]].end()){
  	      nBx1[preFireTrigger[iTrig]][triggerName] = 0;
  	    };
            nBx1[preFireTrigger[iTrig]][triggerName]  += PrescaleMap[prescaleIndex][preFireTrigger[iTrig]]; 
  	  };
        };
      };
    };
  };

  std::map<std::string,TH1F*> graphs;
  for (int iTrig = 0; iTrig != preFireTrigger.size(); iTrig++){
    graphs[preFireTrigger[iTrig]] = makeTH1F(preFireTrigger[iTrig].c_str(),nBx2[preFireTrigger[iTrig]].size(),-0.5,nBx2[preFireTrigger[iTrig]].size()-0.5);
    for (std::map<std::string,int>::iterator it = nBx2[preFireTrigger[iTrig]].begin(); it != nBx2[preFireTrigger[iTrig]].end(); it++){
      std::string triggerName = it -> first;
      int nIt = std::distance(nBx2[preFireTrigger[iTrig]].begin(),it)+1;
      if (it -> second != 0){
        graphs[preFireTrigger[iTrig]] -> SetBinContent(nIt,(double) nBx1[preFireTrigger[iTrig]][triggerName]/ it -> second);
        graphs[preFireTrigger[iTrig]] -> SetBinError(nIt,binoError( nBx1[preFireTrigger[iTrig]][triggerName], it -> second) );
        graphs[preFireTrigger[iTrig]] -> GetXaxis() -> SetBinLabel(nIt,triggerName.c_str());
      };
    };
    char titleName[200];
    sprintf(titleName," ; Trigger at Nominal BX  ; Pretrigger Rate");
    graphs[preFireTrigger[iTrig]] -> SetTitle(titleName);
  };

}
