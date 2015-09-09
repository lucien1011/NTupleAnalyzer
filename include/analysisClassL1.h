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
  std::map<std::string,int> BitMap;
  std::map<int,std::map<std::string,int> > PrescaleMap;

  bool checkTriggerBit(const int & ibit,const int & ibx ){
    bool Fired(false);
    if (ibit<64){
      Fired = (tw1[ibx]>>ibit)&1;
    }else
      Fired = (tw2[ibx]>>(ibit-64))&1;
  
    return Fired;
  };

  void loadPrescaleMap(){
    PrescaleMap[6] = std::map<std::string,int>();
    PrescaleMap[6]["L1_SingleJet092"] = 20000;
    PrescaleMap[6]["L1_SingleJet052"] = 1400;
    PrescaleMap[6]["L1_SingleJet068"] = 2500;
    PrescaleMap[6]["L1_SingleJet092"] = 100;
    PrescaleMap[6]["L1_SingleJet128"] = 1;
    PrescaleMap[6]["L1_SingleJet176"] = 1;
    PrescaleMap[6]["L1_SingleJet200"] = 1;
    PrescaleMap[6]["L1_HTT075"] = 1;
    PrescaleMap[6]["L1_HTT100"] = 1;
    PrescaleMap[6]["L1_HTT125"] = 1;
    PrescaleMap[6]["L1_HTT150"] = 1;
    PrescaleMap[6]["L1_HTT175"] = 1;
    PrescaleMap[6]["L1_HTT200"] = 1; 

    PrescaleMap[7] = std::map<std::string,int>();
    PrescaleMap[7]["L1_SingleJet092"] = 5000;
    PrescaleMap[7]["L1_SingleJet052"] = 1000;
    PrescaleMap[7]["L1_SingleJet068"] = 1000;
    PrescaleMap[7]["L1_SingleJet092"] = 100;
    PrescaleMap[7]["L1_SingleJet128"] = 1;
    PrescaleMap[7]["L1_SingleJet176"] = 1;
    PrescaleMap[7]["L1_SingleJet200"] = 1;
    PrescaleMap[7]["L1_HTT075"] = 1;
    PrescaleMap[7]["L1_HTT100"] = 1;
    PrescaleMap[7]["L1_HTT125"] = 1;
    PrescaleMap[7]["L1_HTT150"] = 1;
    PrescaleMap[7]["L1_HTT175"] = 1;
    PrescaleMap[7]["L1_HTT200"] = 1; 



  };
  
  void loadSingleJetTrigMap(){ 
    HFPrefiringBitMap["L1_SingleJet036"] = 23;
    HFPrefiringBitMap["L1_SingleJet052"] = 17;
    HFPrefiringBitMap["L1_SingleJet068"] = 18;
    HFPrefiringBitMap["L1_SingleJet092"] = 19;
    HFPrefiringBitMap["L1_SingleJet128"] = 20;
    HFPrefiringBitMap["L1_SingleJet176"] = 21;
    HFPrefiringBitMap["L1_SingleJet200"] = 22;
    HFPrefiringBitMap["L1_SingleJet240"] = 39;
  };

  void loadBitMap(){
    BitMap["L1_SingleJet036"] = 23;
    BitMap["L1_SingleJet052"] = 17;
    BitMap["L1_SingleJet068"] = 18;
    BitMap["L1_SingleJet092"] = 19;
    BitMap["L1_SingleJet128"] = 20;
    BitMap["L1_SingleJet176"] = 21;
    BitMap["L1_SingleJet200"] = 22;
    BitMap["L1_SingleJet240"] = 39;
    BitMap["L1_HTT075"] = 8;
    BitMap["L1_HTT100"] = 15;
    BitMap["L1_HTT125"] = 70;
    BitMap["L1_HTT150"] = 71;
    BitMap["L1_HTT175"] = 72;
    BitMap["L1_HTT200"] = 73; 
  };

  void loadHTTTrigMap(){
    HFPrefiringBitMap["L1_HTT075"] = 8;
    HFPrefiringBitMap["L1_HTT100"] = 15;
    HFPrefiringBitMap["L1_HTT125"] = 70;
    HFPrefiringBitMap["L1_HTT150"] = 71;
    HFPrefiringBitMap["L1_HTT175"] = 72;
    HFPrefiringBitMap["L1_HTT200"] = 73; 
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

