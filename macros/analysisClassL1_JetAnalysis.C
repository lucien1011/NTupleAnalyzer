#include "L1Tree.h"
#include "analysisClassL1.h"
#include <algorithm>

void analysisClassL1::loop(){

  std::string MyTrigger="HLT_Any";

  std::vector<std::string> triggerList =  {"L1_SingleJet092","L1_SingleJet128","L1_SingleJet176","L1_SingleJet200","L1_SingleJet240"};
  std::vector<std::string> preTriggerList =  {"L1_SingleJet092","L1_SingleJet128","L1_SingleJet176","L1_SingleJet200","L1_SingleJet240"};

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
  
  std::map<std::string,TH1F*> etaHistList;
  std::map<std::string,TH1F*> l1BitHistList;
  std::map<std::string,std::map<std::string,TH1F*>> preFireEtaHistList;
  char histName[100];
  for (std::vector<std::string>::iterator it = triggerList.begin(); it != triggerList.end(); it++){
    sprintf(histName,"h_etaBin_%s",it->c_str());
    etaHistList[*it] = makeTH1F(histName,22,-0.5,21.5);
    sprintf(histName,"h_l1Bit_%s",it->c_str());
    l1BitHistList[*it] = makeTH1F(histName,2,-0.5,1.5);
    preFireEtaHistList[*it] = std::map<std::string,TH1F*>();
    for (std::vector<std::string>::iterator it2 = preTriggerList.begin(); it2 != preTriggerList.end(); it2++){
      sprintf(histName,"%s_%s",it->c_str(),it2->c_str());
      preFireEtaHistList[*it][*it2] = makeTH1F(histName,22,-0.5,21.5);
    };
  };

  loadPrescaleMap();
  loadBitMap();

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

    for (std::vector<std::string>::iterator it = triggerList.begin(); it != triggerList.end(); it++){
      bool Bx2Fired = checkTriggerBit(BitMap[*it],2);
      float ptThreshold = (float)std::stoi(it -> substr(12)); 
      int jetEtaBin = SingleJetEtaBin(ptThreshold,0);
      if (Bx2Fired){
        l1BitHistList[*it] -> Fill(1,PrescaleMap[prescaleIndex][*it]);
      };

      if (jetEtaBin != -10){
        etaHistList[*it] -> Fill(jetEtaBin,PrescaleMap[prescaleIndex][*it]);
        for (std::vector<std::string>::iterator it2 = preTriggerList.begin(); it2 != preTriggerList.end(); it2++){
	  float ptThreshold_BxM1 = (float)std::stoi(it2 -> substr(12));
	  int jetEtaBin_BxM1 = SingleJetEtaBin(ptThreshold_BxM1,-1);
          if (jetEtaBin_BxM1 != -10){
            preFireEtaHistList[*it][*it2] -> Fill(jetEtaBin_BxM1,PrescaleMap[prescaleIndex][*it2]);
	  };
	};
      };
    };
  };

  char titleName[100];
  for (std::map<std::string,TH1F*>::iterator itr = etaHistList.begin(); itr != etaHistList.end(); ++itr){
    sprintf(titleName,"%s, SingleJet:%4.0f, L1Bit:%4.0f ; Eta Bin ( 0 - 21 ); Number of Event",itr->first.c_str(),itr -> second -> Integral(),l1BitHistList[itr->first]->Integral());
    itr -> second -> SetTitle(titleName);
    for (std::vector<std::string>::iterator it2 = preTriggerList.begin(); it2 != preTriggerList.end(); it2++){
      sprintf(titleName,"Bx2: %s, Bx1: %s, Prefire Rate: %4.3f ; Eta Bin ( 0 - 21 ); Number of Event",itr->first.c_str(),it2->c_str(),preFireEtaHistList[itr->first][*it2]->Integral()/itr->second->Integral());
      preFireEtaHistList[itr->first][*it2] -> SetTitle(titleName);


    };
  };
}


