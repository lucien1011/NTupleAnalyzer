#include "CustomTree.h"
#include "analysisClass_L1Trigger.h"
#include <algorithm>

void analysisClass_L1Trigger::loop(){

  std::string MyTrigger="HLT_Any";

  CustomTree * tuple_tree = getTree<CustomTree>("tuple_tree");
  int n_events = tuple_tree -> fChain -> GetEntries();
  //std::cout << "n events = " << n_events << std::endl;

  loadTrigMap();

  tuple_tree -> fChain -> SetBranchStatus("*", kFALSE);
  tuple_tree -> fChain -> SetBranchStatus("run", kTRUE);
  tuple_tree -> fChain -> SetBranchStatus("lumi", kTRUE);
  tuple_tree -> fChain -> SetBranchStatus("event", kTRUE);
  tuple_tree -> fChain -> SetBranchStatus("bx", kTRUE);
  tuple_tree -> fChain -> SetBranchStatus("hlt", kTRUE);
  tuple_tree -> fChain -> SetBranchStatus("tw1", kTRUE);
  tuple_tree -> fChain -> SetBranchStatus("tw2", kTRUE);


  for (int i = 0; i < n_events; ++i){
    tuple_tree -> GetEntry(i);
    if ( (i + 1) % 1000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;

    int runNumber = tuple_tree -> run ;
    int bunchNumber = tuple_tree -> bx ;
    int lumiSection = tuple_tree -> lumi ;
    int eventNumber = tuple_tree -> event ;

    tw1 = tuple_tree -> tw1;
    tw2 = tuple_tree -> tw2;

    // check if the event is fired with the selected HLT
    bool accept=false;
    if (MyTrigger=="HLT_Any") {
      accept=true;
    }else{
      int ntrigs = tuple_tree -> hlt.size();
      for (int itrig=0; itrig<ntrigs; itrig++){
        if (tuple_tree -> hlt[itrig] == MyTrigger) accept=true;
      }
    };


    Int_t nBx=tw1.size();
    // std::cout << "Number of Bunch Number: " << nBx << std::endl;
    for (trigbit_iter = L1TriggerBitMap.begin(); trigbit_iter != L1TriggerBitMap.end(); trigbit_iter++){
      int ibit = trigbit_iter->second;
      for(Int_t ibx=0; ibx < nBx; ibx++){
      // for (std::vector<Int_t>::iterator it = pretrig_Bx.begin(); it != pretrig_Bx.end(); ++it){
        bool Fired = checkTriggerBit(ibit,ibx);
        if (Fired and isSelectedBx(bunchNumber)) {
	  if (preTrigEvent.find(eventNumber) == preTrigEvent.end()){
	     preTrigEvent[eventNumber] = std::vector<std::string>{};
	   };
	  if (eventLumiMap.find(eventNumber) == eventLumiMap.end()){
	    eventLumiMap[eventNumber] = lumiSection;
	  };
	  preTrigEvent[eventNumber].push_back(trigbit_iter -> first);
        }
      }
    }// end of loop over trigger bits
  };

  std::cout << "Number of event with pre-triggering: " << preTrigEvent.size() << std::endl;

  FILE * f;
  f = fopen("preTrigEventList.txt","w");
  std::map<int,std::vector<std::string>>::iterator itr;
  for (itr = preTrigEvent.begin(); itr != preTrigEvent.end(); itr++){
    fprintf(f,"%d %d \n", eventLumiMap[itr -> first], itr -> first);
  };
  fclose(f);


}

bool analysisClass_L1Trigger::isSelectedBx(int bunchNumber){
  std::vector<int> pretrig_Bx = {374,1268,2150,3044};
  return (std::find(pretrig_Bx.begin(),pretrig_Bx.end(),bunchNumber) != pretrig_Bx.end());
}


bool analysisClass_L1Trigger::checkTriggerBit(const int & ibit,const int & ibx ){
  bool Fired(false);
  if (ibit<64){
    Fired = (tw1[ibx]>>ibit)&1;
  }else
    Fired = (tw2[ibx]>>(ibit-64))&1;

  return Fired;
};

void analysisClass_L1Trigger::loadTrigMap(){ // these bits can change! check these are correct for the run you are using

  L1TriggerBitMap["L1_SingleJet128"] = 20;
  L1TriggerBitMap["L1_SingleJet176"] = 21;
  L1TriggerBitMap["L1_SingleJet200"] = 22;

  L1TriggerBitMap["L1_HTT75"] = 8;
  L1TriggerBitMap["L1HTT100"] = 15;

}
