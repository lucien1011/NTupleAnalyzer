#ifndef analysisClassL1_h
#define analysisClassL1_h

#include "analysisClass.h"

class analysisClassL1 : public analysisClass {
 
 public:
  analysisClassL1 (std::string inputList, std::string treeList, std::string out_file): 
  analysisClass(inputList, treeList, out_file) {};

  ~analysisClassL1(){};
  void loop();

private :

  std::map<std::string,int> HFPrefiringBitMap;
  std::map<std::string,int>::iterator trigbit_iter;
  std::map<std::string,TH1F*> histoMap;
  std::vector<ULong64_t> tw1;
  std::vector<ULong64_t> tw2;
  std::vector<TString> hlt;

  bool checkTriggerBit(const int & ibit,const int & ibx ){
    bool Fired(false);
    if (ibit<64){
      Fired = (tw1[ibx]>>ibit)&1;
    }else
      Fired = (tw2[ibx]>>(ibit-64))&1;
  
    return Fired;
  };
  
  void loadTrigMap(){ 
    // HFPrefiringBitMap["L1_SingleJet36"] = 23;
    // HFPrefiringBitMap["L1_SingleJet52"] = 17;
    // HFPrefiringBitMap["L1_SingleJet68"] = 18;
    // HFPrefiringBitMap["L1_SingleJet92"] = 19;
    HFPrefiringBitMap["L1_SingleJet128"] = 20;
    HFPrefiringBitMap["L1_SingleJet176"] = 21;
    HFPrefiringBitMap["L1_SingleJet200"] = 22;
  
    HFPrefiringBitMap["L1_HTT75"] = 8;
    HFPrefiringBitMap["L1HTT100"] = 15;
  
  };

  bool checkHLT(const std::string MyTrigger){
    bool accept=false;
    if (MyTrigger=="HLT_Any") {
      accept=true;
    }else{
      int ntrigs = hlt.size();
      for (int itrig=0; itrig<ntrigs; itrig++){
        if (hlt[itrig] == MyTrigger) accept=true;
      }
    };
   return accept; 
  };

// bool analysisClassL1::isSelectedBx(int bunchNumber){
//   std::vector<int> nominalBx = {375,1269,2151,3045};
//   return (std::find(nominalBx.begin(),nominalBx.end(),bunchNumber) != nominalBx.end());
// }

};
#endif

