#include "L1Tree.h"
#include "L1ExtraTree.h"
#include "analysisClassL1.h"
#include <algorithm>

void analysisClassL1::loop(){

//__________________________________________________________________||
//Configurables

  std::string HLT_Trigger = "HLT_Any";
  std::vector<double> preFireTrigger = {30., 60., 90.,120.,150.,180.,210.,240.};
  // std::vector<std::string> preFireTrigger = {"L1_HTT075","L1_HTT100","L1_HTT125","L1_HTT150","L1_HTT175","L1_HTT200"};
  double lowPtThreshold = 45.;
  double highPtThreshold = 305.;
  int nThresholds = 26;

//__________________________________________________________________||
//Constant
  std::vector<int> hfEtaBin = {0,1,2,3,18,19,20,21};

//__________________________________________________________________||
//Get Trees

  L1Tree * l1Tree = getTree<L1Tree>("l1Tree");
  L1ExtraTree * l1ExtraTree = getTree<L1ExtraTree>("l1ExtraTree");

//__________________________________________________________________||
//Number of Events

  int n_events = l1Tree -> fChain -> GetEntries();

//__________________________________________________________________||
//Loading Trigger Map

//__________________________________________________________________||
//Turn on necessary branches
  l1Tree -> fChain -> SetBranchStatus("*", kFALSE);
  l1Tree -> fChain -> SetBranchStatus("lumi", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("bx", kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Njet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Bxjet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Rankjet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Etajet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Phijet",kTRUE);
  l1Tree -> fChain -> SetBranchStatus("Fwdjet",kTRUE);
//__________________________________________________________________||
//Histograms
  char histName[100];
  std::map<double,TEfficiency*> h_previousBxFire_HF;
  std::map<double,TEfficiency*> h_previousBxFire_HBHE;
  for (std::vector<double>::iterator it = preFireTrigger.begin(); it != preFireTrigger.end(); it++){
    sprintf(histName,"h_previousBxFire_HF_%.0f",*it);
    h_previousBxFire_HF[*it] =  makeTEff(histName,nThresholds,lowPtThreshold,highPtThreshold);
    sprintf(histName,"h_previousBxFire_HBHE_%.0f",*it);
    h_previousBxFire_HBHE[*it] =  makeTEff(histName,nThresholds,lowPtThreshold,highPtThreshold);
  }; 
  // TH1F* h_previousBxFire_HF = makeTH1F("h_previousBxFire_HF",nThresholds,lowPtThreshold,highPtThreshold);
  // TH1F* h_previousBxFire_HBHE = makeTH1F("h_previousBxFire_HBHE",nThresholds,lowPtThreshold,highPtThreshold);
  TH1F* h_nominalBxFire = makeTH1F("h_nominalBxFire",nThresholds,lowPtThreshold,highPtThreshold);
  int nBins = h_nominalBxFire -> GetNbinsX(); 

//__________________________________________________________________||
//Event loop
  for (int i = 0; i < n_events; ++i){
    l1Tree -> GetEntry(i);
    l1ExtraTree -> GetEntry(i);

    if ( (i + 1) % 10000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;
    
    if ((l1ExtraTree -> cenJetEt.size() == 0) && (l1ExtraTree -> fwdJetEt.size() == 0) ) continue;

    int bunchNumber = l1Tree -> bx;
    
    // if (bunchNumber != 39) continue;

    Njet = l1Tree -> Njet;
    Bxjet = l1Tree -> Bxjet;
    Rankjet = l1Tree -> Rankjet;
    Etajet = l1Tree -> Etajet;
    Phijet = l1Tree -> Phijet;
    Fwdjet = l1Tree -> Fwdjet;

    for (int iBin = 0; iBin != nBins; iBin++){
      double ptThreshold = h_nominalBxFire -> GetBinCenter( iBin );
      int jetEtaBin = SingleJetEtaBin(ptThreshold,0);
      if (jetEtaBin != -10){
        h_nominalBxFire -> Fill( ptThreshold );
	for (std::vector<double>::iterator it = preFireTrigger.begin(); it != preFireTrigger.end(); it++){
          int jetEtaBin_BxM1 = SingleJetEtaBin(*it,-1);
          if (jetEtaBin_BxM1 == -10) {
	    h_previousBxFire_HF[*it] -> Fill( false , ptThreshold );
            h_previousBxFire_HBHE[*it] -> Fill( false, ptThreshold ); 
	  } else {
	    if (std::find(hfEtaBin.begin(),hfEtaBin.end(),jetEtaBin_BxM1) != hfEtaBin.end()){
              h_previousBxFire_HF[*it] -> Fill( true , ptThreshold ); 
            } else {
              h_previousBxFire_HBHE[*it] -> Fill( true , ptThreshold ); 
	    };
	  };
	};	
      };
    };       
  };
//__________________________________________________________________||
//Wrap up result

//__________________________________________________________________||

}
