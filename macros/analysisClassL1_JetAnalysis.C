#include "L1Tree.h"
#include "analysisClassL1.h"
#include <algorithm>

void analysisClassL1::loop(){

  std::string MyTrigger="HLT_Any";

  L1Tree * l1Tree = getTree<L1Tree>("l1Tree");

  int n_events = l1Tree -> fChain -> GetEntries();

  l1Tree -> fChain -> SetBranchStatus("*", kFALSE);
  l1Tree -> fChain -> SetBranchStatus("lumi",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Njet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Bxjet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Rankjet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Etajet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Phijet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Fwdjet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("tw1",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("tw2",kTRUE);
  
  // TH2F * h_eta_vs_phi = makeTH2F("h_eta_vs_phi",100,-5.,5.,100,-3.14,3.14);
  TH1F * h_eta = makeTH1F("h_eta",100,-5.,5.);

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
    Njet = l1Tree -> Njet;
    Bxjet = l1Tree -> Bxjet;
    Rankjet = l1Tree -> Rankjet;
    Etajet = l1Tree -> Etajet;
    Phijet = l1Tree -> Phijet;
    Fwdjet = l1Tree -> Fwdjet;
    tw1 = l1Tree -> tw1;
    tw2 = l1Tree -> tw2;

    loadBitMap();

    bool Bx2Fired = checkTriggerBit(BitMap["L1_HTT150"],2);      

    if (not Bx2Fired) continue;

    float jetEta = SingleJetEta(128.);
    float jetPhi = SingleJetPhi(128.);
    // if ((jetEta != -10) && (jetPhi != -10)){
    //   std::cout << jetEta << " " << jetPhi << std::endl;
    // };

    // h_eta_vs_phi -> Fill(jetEta,jetPhi);
    h_eta -> Fill(jetEta);

  };
}


