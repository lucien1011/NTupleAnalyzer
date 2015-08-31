#include "L1Tree.h"
#include "L1ExtraTree.h"
#include "analysisClass_HFPrefiring.h"
#include <algorithm>

void analysisClass_HFPrefiring::loop(){

  std::string MyTrigger="HLT_Any";

  L1Tree * l1Tree = getTree<L1Tree>("l1Tree");
  L1ExtraTree * l1ExtraTree = getTree<L1ExtraTree>("l1ExtraTree");

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

  l1ExtraTree -> fChain -> SetBranchStatus("*", kFALSE);
  l1ExtraTree -> fChain -> SetBranchStatus("nFwdJets", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("fwdJetEt", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("fwdJetBx", kTRUE);

  l1ExtraTree -> fChain -> SetBranchStatus("cenJetEt", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("nCenJets", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("cenJetBx", kTRUE);

  TH1F * h_preFireRate = makeTH1F("h_preFireRate",10,-4.5,5.5);
  TH1F * h_fwdJetPtBxM1 = makeTH1F("h_fwdJetPtBxM1",101,-0.5,105.5);

  for (int i = 0; i < n_events; ++i){
    l1Tree -> GetEntry(i);
    l1ExtraTree -> GetEntry(i);
    if ( (i + 1) % 1000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;

    int runNumber = l1Tree -> run ;
    int bunchNumber = l1Tree -> bx ;
    int lumiSection = l1Tree -> lumi ;
    int eventNumber = l1Tree -> event ;

    int nCenJet = l1ExtraTree -> nCenJets;
    int nFwdJet = l1ExtraTree -> nFwdJets;
    std::vector<double> fwdJetEt = l1ExtraTree -> fwdJetEt;
    std::vector<double> cenJetEt = l1ExtraTree -> cenJetEt;
    std::vector<int> fwdJetBx = l1ExtraTree -> fwdJetBx;
    std::vector<int> cenJetBx = l1ExtraTree -> cenJetBx;

    tw1 = l1Tree -> tw1;
    tw2 = l1Tree -> tw2;

    // check if the event is fired with the selected HLT
    bool accept=false;
    if (MyTrigger=="HLT_Any") {
      accept=true;
    }else{
      int ntrigs = l1Tree -> hlt.size();
      for (int itrig=0; itrig<ntrigs; itrig++){
        if (l1Tree -> hlt[itrig] == MyTrigger) accept=true;
      }
    };

    double fwdJetPtBxM1 = getJetPt(fwdJetEt,fwdJetBx,-1);
    double cenJetPtBxZero = getJetPt(cenJetEt,cenJetBx,0);

    if (cenJetPtBxZero > 50.){
      h_fwdJetPtBxM1->Fill(fwdJetPtBxM1); 
    };

    Int_t nBx=tw1.size();
    for (trigbit_iter = HFPrefiringBitMap.begin(); trigbit_iter != HFPrefiringBitMap.end(); trigbit_iter++){
      int ibit = trigbit_iter->second;
      // for(Int_t ibx=0; ibx < nBx; ibx++){

      bool Bx1Fired = checkTriggerBit(ibit,1);      
      bool Bx2Fired = checkTriggerBit(ibit,2);      

      if (Bx2Fired){
        h_preFireRate -> Fill(2);
	if (Bx1Fired){
	  h_preFireRate -> Fill(1);

	};
      };

      // }
    }// end of loop over trigger bits
  };

}

double analysisClass_HFPrefiring::getJetPt(const std::vector<double> & jetCollPt, const std::vector<int> & jetCollBx ,const int & bx){
  double jetPt = 0.;
  int nJet = jetCollPt.size();
  for (int i = 0; i != nJet; i++){
    if ((jetCollBx[i] == bx) && (jetCollPt[i] > jetPt)){
      jetPt = jetCollPt[i];
    };
  };
  return jetPt;

}

bool analysisClass_HFPrefiring::isSelectedBx(int bunchNumber){
  // std::vector<int> pretrig_Bx = {374,1268,2150,3044};
  std::vector<int> nominalBx = {375,1269,2151,3045};
  return (std::find(nominalBx.begin(),nominalBx.end(),bunchNumber) != nominalBx.end());
}


bool analysisClass_HFPrefiring::checkTriggerBit(const int & ibit,const int & ibx ){
  bool Fired(false);
  if (ibit<64){
    Fired = (tw1[ibx]>>ibit)&1;
  }else
    Fired = (tw2[ibx]>>(ibit-64))&1;

  return Fired;
};

void analysisClass_HFPrefiring::loadTrigMap(){ // these bits can change! check these are correct for the run you are using

  HFPrefiringBitMap["L1_SingleJet128"] = 20;
  // HFPrefiringBitMap["L1_SingleJet176"] = 21;
  // HFPrefiringBitMap["L1_SingleJet200"] = 22;

  // HFPrefiringBitMap["L1_HTT75"] = 8;
  // HFPrefiringBitMap["L1HTT100"] = 15;

}

