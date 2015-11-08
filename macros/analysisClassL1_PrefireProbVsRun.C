#include "L1Tree.h"
#include "L1ExtraTree.h"
#include "analysisClassL1.h"
#include <algorithm>

double binoError(double selected, double all){
  return sqrt(selected*(1-selected/all))/all ; 
};

void analysisClassL1::loop(){

//__________________________________________________________________||
//Configurables

  std::string HLT_Trigger = "HLT_Any";
  // std::vector<std::string> preFireTrigger = {"L1_HTT075","L1_HTT100","L1_HTT125","L1_HTT150","L1_HTT175","L1_HTT200"};
  double preFireThreshold = 120.;
  double nominalFireThreshold = 150.;

//__________________________________________________________________||
//Constant
  const std::vector<int> hfEtaBin = {0,1,2,3,18,19,20,21};

//__________________________________________________________________||
//Get Trees

  L1Tree * l1Tree = getTree<L1Tree>("l1Tree");
  L1ExtraTree * l1ExtraTree = getTree<L1ExtraTree>("l1ExtraTree");

//__________________________________________________________________||
//Number of Events

  int n_events = l1Tree -> fChain -> GetEntries();

//__________________________________________________________________||
//Turn on necessary branches

  l1Tree -> fChain -> SetBranchStatus("*", kFALSE);
  l1Tree -> fChain -> SetBranchStatus("run", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("lumi", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("bx", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Njet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Bxjet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Rankjet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Etajet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Phijet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Fwdjet",kTRUE);

//__________________________________________________________________||
//Necessary varibles
  std::map<int,double> preFireCount;
  std::map<int,double> nominalCount;

//__________________________________________________________________||
//Event loop

  for (int i = 0; i < n_events; ++i){
    l1Tree -> GetEntry(i);
    l1ExtraTree -> GetEntry(i);

    if ( (i + 1) % 10000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;
    
    if ((l1ExtraTree -> cenJetEt.size() == 0) && (l1ExtraTree -> fwdJetEt.size() == 0) ) continue;

    int bunchNumber = l1Tree -> bx;
    int runNumber = l1Tree -> run;
    
    if (bunchNumber != 39) continue;

    if (preFireCount.find(runNumber) == preFireCount.end()){
      preFireCount[runNumber] = 0.;
    };

    if (nominalCount.find(runNumber) == nominalCount.end()){
      nominalCount[runNumber] = 0.;
    };

    Njet = l1Tree -> Njet;
    Bxjet = l1Tree -> Bxjet;
    Rankjet = l1Tree -> Rankjet;
    Etajet = l1Tree -> Etajet;
    Phijet = l1Tree -> Phijet;
    Fwdjet = l1Tree -> Fwdjet;

    int jetEtaBin = SingleJetEtaBin(nominalFireThreshold,0);
    if (jetEtaBin != -10){
      nominalCount[runNumber]++;
      int jetEtaBin_BxM1 = SingleJetEtaBin(preFireThreshold,-1);
      if (jetEtaBin_BxM1 != -10){
        preFireCount[runNumber]++;
      };
    };	       
  };

//__________________________________________________________________||
//Wrap up result

  char histName[100];
  char titleName[100];
  sprintf(histName,"PrefireProb_Run_%.0f_%0.f",nominalFireThreshold,preFireThreshold);
  sprintf(titleName," Nominal BX Threshold: %.0f, Previous BX Threshold: %.0f ; Run Number ; Prefire Probablilty ",nominalFireThreshold,preFireThreshold);
  int nBin = nominalCount.size();
  TH1F* result = makeTH1F(histName,nBin,-0.5,nBin-0.5);
  result -> SetTitle(titleName);
  int iBin = 1;
  char binLabel[100];
  for (std::map<int,double>::iterator it = nominalCount.begin(); it != nominalCount.end(); it++){
    double select = preFireCount[it -> first];
    double all = it -> second;
    result -> SetBinContent(iBin, select/all);
    result -> SetBinError(iBin, binoError(select,all) );
    sprintf(binLabel,"%d",it -> first);
    result -> GetXaxis() -> SetBinLabel(iBin , binLabel);
    iBin++;
  };


//__________________________________________________________________||

}
