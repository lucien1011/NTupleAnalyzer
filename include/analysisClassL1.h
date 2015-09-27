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

  Double_t PHIBIN[18] = {10,30,50,70,90,110,130,150,170,190,210,230,250,270,290,310,330,350};
  std::map<std::string,int> HFPrefiringBitMap;
  std::map<std::string,int>::iterator trigbit_iter;
  std::map<std::string,TH1F*> histoMap;
  std::vector<ULong64_t> tw1;
  std::vector<ULong64_t> tw2;
  std::vector<ULong64_t> tt;
  std::vector<TString> hlt;
  std::map<std::string,int> BitMap;
  std::map<int,std::map<std::string,int> > PrescaleMap;
  Int_t Njet;
  std::vector<int> Bxjet;
  std::vector<float> Rankjet;
  std::vector<float> Etajet;
  std::vector<float> Phijet;
  std::vector<bool> Fwdjet;

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

  // float SingleJetEtaBin(float ptCut, Int_t accept_flag = 1) { 
  float SingleJetEtaBin(float ptCut,int selectedBx) {
 
    float maxPt = -10;
    float iJetMaxPt = -10;
  
    Int_t Nj = Njet ;
    for(Int_t ue=0; ue < Nj; ue++) {
      Int_t bx = Bxjet[ue];
      // std::cout << bx << std::endl;
      if(bx != selectedBx) continue;
      // Bool_t isFwdJet = Fwdjet[ue];
  
      // if(accept_flag == 1 && isFwdJet) continue;
      // if(accept_flag == 2 && !isFwdJet) continue;
  
      Float_t pt = Rankjet[ue]*4.;
      if(pt >= maxPt){
        maxPt = pt;
        iJetMaxPt = ue;
      }
    }
  
    float eta = -10.;
    int ieta = iJetMaxPt>=0 && maxPt>ptCut ? Etajet[iJetMaxPt] : -10;
    return ieta;
  };

  float SingleJetEta(float ptCut, int selectedBx) {
  
    float maxPt = -10;
    float iJetMaxPt = -10;
  
    Int_t Nj = Njet ;
    for(Int_t ue=0; ue < Nj; ue++) {
      Int_t bx = Bxjet[ue];        		
      if(bx != selectedBx) continue;
      // Bool_t isFwdJet = Fwdjet[ue];
  
      // if(accept_flag == 1 && isFwdJet) continue;
      // if(accept_flag == 2 && !isFwdJet) continue;
  
      Float_t pt = Rankjet[ue]*4.;
      if(pt >= maxPt){
        maxPt = pt;
        iJetMaxPt = ue;
      }
    }
  
    float eta = -10.;
    int ieta = iJetMaxPt>=0 && maxPt>ptCut ? Etajet[iJetMaxPt] : -10;
    if(ieta > 0) eta = convertRegionEta(ieta);
    return eta;
  };

  float SingleJetPhiBin(float ptCut,int selectedBx) {
  
    float maxPt = -10;
    float iJetMaxPt = -10;
  
    Int_t Nj = Njet ;
    for(Int_t ue=0; ue < Nj; ue++) {
      Int_t bx = Bxjet[ue];        		
      if(bx != selectedBx) continue;
  
      Float_t pt = Rankjet[ue]*4.;
      if(pt >= maxPt){
        maxPt = pt;
        iJetMaxPt = ue;
      }
    }
  
    float phi = -10.;
    int iphi = iJetMaxPt>=0 && maxPt>ptCut ? Phijet[iJetMaxPt] : -10; 
    return iphi;
  };

  float SingleJetPhi(float ptCut,int selectedBx) {
  
    float maxPt = -10;
    float iJetMaxPt = -10;
  
    Int_t Nj = Njet ;
    for(Int_t ue=0; ue < Nj; ue++) {
      Int_t bx = Bxjet[ue];        		
      if(bx != selectedBx) continue;
  
      Float_t pt = Rankjet[ue]*4.;
      if(pt >= maxPt){
        maxPt = pt;
        iJetMaxPt = ue;
      }
    }
  
    float phi = -10.;
    int iphi = iJetMaxPt>=0 && maxPt>ptCut ? Phijet[iJetMaxPt] : -10; 
    if(iphi > 0) phi = PHIBIN[iphi]/100;
    return phi;
  };


  Double_t convertRegionEta(int iEta) {
    static const double rgnEtaValues[11] = {
       0.174, // HB and inner HE bins are 0.348 wide
       0.522,
       0.870,
       1.218,
       1.566,
       1.956, // Last two HE bins are 0.432 and 0.828 wide
       2.586,
       3.250, // HF bins are 0.5 wide
       3.750,
       4.250,
       4.750
    };
    if(iEta < 11) {
      return -rgnEtaValues[-(iEta - 10)]; // 0-10 are negative eta values
    }
    else if (iEta < 22) {
      return rgnEtaValues[iEta - 11];     // 11-21 are positive eta values
    }
    return -9;
  };



};
#endif

