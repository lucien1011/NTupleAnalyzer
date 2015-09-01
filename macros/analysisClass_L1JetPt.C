#include "L1Tree.h"
#include "L1ExtraTree.h"
#include "analysisClassL1.h"
#include <algorithm>

std::vector<double> getJetsWithBx(const int bx,const std::vector<double> jetEt, const std::vector<int> jetBx ){
  std::vector<double> tempVec;
  for (int i=0;i != jetBx.size();i++){
    if (jetBx[i] == bx){
      tempVec.push_back(jetEt[i]);
    };
  };
  return tempVec;
};

double getMaximum(const std::vector<double> jetEt){
  auto it = std::max_element(jetEt.begin(),jetEt.end());
  if (jetEt.size() != 0){
    return *it;
  }else{
    return 0.;
  };
};


void analysisClassL1::loop(){

  std::string MyTrigger="HLT_Any";

  L1Tree * l1Tree = getTree<L1Tree>("l1Tree");
  L1ExtraTree * l1ExtraTree = getTree<L1ExtraTree>("l1ExtraTree");

  int n_events = l1Tree -> fChain -> GetEntries();

  l1Tree -> fChain -> SetBranchStatus("*", kFALSE);
  l1Tree -> fChain -> SetBranchStatus("bx", kFALSE);

  l1ExtraTree -> fChain -> SetBranchStatus("*", kFALSE);
  l1ExtraTree -> fChain -> SetBranchStatus("nFwdJets", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("fwdJetEt", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("fwdJetBx", kTRUE);

  l1ExtraTree -> fChain -> SetBranchStatus("nCenJets", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("cenJetEt", kTRUE); 
  l1ExtraTree -> fChain -> SetBranchStatus("cenJetBx", kTRUE);

  TH1F * bxM1JetPt = makeTH1F("bxM1JetPt",250,-0.5,249.5);

  for (int i = 0; i < n_events; ++i){
    l1Tree -> GetEntry(i);
    l1ExtraTree -> GetEntry(i);
    if ( (i + 1) % 1000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;

    bool accept = checkHLT(MyTrigger);
    if (not accept) continue;

    int nCenJet = l1ExtraTree -> nCenJets;
    std::vector<double> cenJetEt = l1ExtraTree -> cenJetEt;
    std::vector<int> cenJetBx = l1ExtraTree -> cenJetBx; 

    int nFwdJet = l1ExtraTree -> nFwdJets;
    std::vector<double> fwdJetEt = l1ExtraTree -> fwdJetEt;
    std::vector<int> fwdJetBx = l1ExtraTree -> fwdJetBx;

    int bunchNumber = l1Tree -> bx ;

    double leadingFwdJetPt = getMaximum(getJetsWithBx(0,fwdJetEt,fwdJetBx));
    double leadingCenJetPt = getMaximum(getJetsWithBx(0,cenJetEt,cenJetBx));

    if ((leadingFwdJetPt > 20.) || (leadingCenJetPt > 20.)){
      std::vector<double> bxM1FwdJetEt = getJetsWithBx(-1,fwdJetEt,fwdJetBx);
      for (int i=0; i != bxM1FwdJetEt.size(); i++){
        bxM1JetPt -> Fill(bxM1FwdJetEt[i]);
      };
      
    };


  };

}
