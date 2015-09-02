#include "L1Tree.h"
#include "L1ExtraTree.h"
#include "analysisClassL1.h"
#include <algorithm>

std::vector<double> getJetsWithBx(int bx, std::vector<double> jetEt, std::vector<int> jetBx ){
  std::vector<double> tempVec; 
  for (int i=0;i != jetBx.size();i++){
    if (jetBx[i] == bx){
      tempVec.push_back(jetEt[i]);
    };
  };
  return tempVec;
};

double getMaximum(std::vector<double> jetEt){
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
  // l1Tree -> fChain -> SetBranchStatus("bx", kTRUE);
  // l1Tree -> fChain -> SetBranchStatus("event",kTRUE);

  l1ExtraTree -> fChain -> SetBranchStatus("*", kFALSE);
  l1ExtraTree -> fChain -> SetBranchStatus("nFwdJets", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("fwdJetEt", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("fwdJetBx", kTRUE);

  l1ExtraTree -> fChain -> SetBranchStatus("nCenJets", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("cenJetEt", kTRUE); 
  l1ExtraTree -> fChain -> SetBranchStatus("cenJetBx", kTRUE);

  // TH1F * bxM1JetPt = makeTH1F("bxM1JetPt",250,-0.5,249.5);
  TH1F * h_cenJetPt = makeTH1F("h_cenJetPt",250,-0.5,249.5);
  TH1F * h_fwdJetPt = makeTH1F("h_fwdJetPt",250,-0.5,249.5);
  TH1F * h_leadingCenJetPt = makeTH1F("h_leadingCenJetPt",250,-0.5,249.5);
  TH1F * h_leadingFwdJetPt = makeTH1F("h_leadingFwdJetPt",250,-0.5,249.5);
  TH1F * h_leadingFwdJetPt_BxM1 = makeTH1F("h_leadingFwdJetPt_BxM1",250,-0.5,249.5);
  TH2F * h_leadingFwdJet_Bx0_BxM1 = makeTH2F("h_leadingFwdJet_BxM1_Bx0",100,-0.5,249.5,100,-0.5,249.5);
  TH2F * h_leadingFwdJet_Bx0_BxM1_CenJetPt50 = makeTH2F("h_leadingFwdJet_Bx0_BxM1_CenJetPt50",100,-0.5,249.5,100,-0.5,249.5);

  TH1F * h_fwdJetBx = makeTH1F("h_fwdJetBx",10,-5.5,4.5);

  //int nCenJet;
  //std::vector<double> cenJetEt;
  //std::vector<int> cenJetBx; 

  //int nFwdJet;
  //std::vector<double> fwdJetEt;
  //std::vector<int> fwdJetBx;
  //int bunchNumber;
  //int evt;
  double leadingCenJetPt;
  double leadingFwdJetPt;
  double leadingFwdJetPt_BxM1;

  for (int i = 0; i < n_events; ++i){
    l1Tree -> GetEntry(i);
    l1ExtraTree -> GetEntry(i);
    if ( (i + 1) % 10000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;

    // bool accept = checkHLT(MyTrigger);
    // if (not accept) continue;

    // nCenJet = l1ExtraTree -> nCenJets;
    // cenJetEt = l1ExtraTree -> cenJetEt;
    // cenJetBx = l1ExtraTree -> cenJetBx; 

    // nFwdJet = l1ExtraTree -> nFwdJets;
    // fwdJetEt = l1ExtraTree -> fwdJetEt;
    // fwdJetBx = l1ExtraTree -> fwdJetBx;

    // bunchNumber = l1Tree -> bx ;
    // evt = l1Tree -> event ;

    // if (l1ExtraTree -> cenJetEt.size() != l1ExtraTree -> cenJetBx.size()) continue;
    // if (l1ExtraTree -> fwdJetEt.size() != l1ExtraTree -> fwdJetBx.size()) continue;
    if ((l1ExtraTree -> cenJetEt.size() == 0) && (l1ExtraTree -> fwdJetEt.size() == 0) ) continue;

    leadingCenJetPt = 0.;
    for (int j = 0; j != l1ExtraTree -> cenJetEt.size(); j++){
      h_cenJetPt -> Fill(l1ExtraTree -> cenJetEt[j]);
      if ((leadingCenJetPt < l1ExtraTree -> cenJetEt[j]) && (l1ExtraTree -> cenJetBx[j] == 0) ){
        leadingCenJetPt = l1ExtraTree -> cenJetEt[j];
      };
    };
    h_leadingCenJetPt -> Fill(leadingCenJetPt);

    leadingFwdJetPt = 0.;
    leadingFwdJetPt_BxM1 = 0.;
    for (int j = 0; j != l1ExtraTree -> fwdJetEt.size(); j++){
      h_fwdJetPt -> Fill(l1ExtraTree -> fwdJetEt[j]);
      h_fwdJetBx -> Fill(l1ExtraTree -> fwdJetBx[j]);
      if ((leadingFwdJetPt < l1ExtraTree -> fwdJetEt[j]) && (l1ExtraTree -> fwdJetBx[j] == 0) ){
        leadingFwdJetPt = l1ExtraTree -> fwdJetEt[j];
      };
      if ((leadingFwdJetPt_BxM1 < l1ExtraTree -> fwdJetEt[j]) && (l1ExtraTree -> fwdJetBx[j] == -1) ){
        leadingFwdJetPt_BxM1 = l1ExtraTree -> fwdJetEt[j];
      };
    };
    h_leadingFwdJetPt -> Fill(leadingFwdJetPt);
    h_leadingFwdJetPt_BxM1 -> Fill(leadingFwdJetPt_BxM1);

    h_leadingFwdJet_Bx0_BxM1 -> Fill(leadingFwdJetPt,leadingFwdJetPt_BxM1);
    if (leadingCenJetPt > 50.){
      h_leadingFwdJet_Bx0_BxM1_CenJetPt50 -> Fill(leadingFwdJetPt,leadingFwdJetPt_BxM1);
    };
  };

    h_leadingFwdJet_Bx0_BxM1 -> SetTitle(" ; leading Fwd Jet E_{T} (Bx = 0) GeV ; leading Fwd Jet E_{T} (Bx = -1) GeV ");
    h_leadingFwdJet_Bx0_BxM1_CenJetPt50 -> SetTitle("Leading Cen Jet pT > 50 GeV ; leading Fwd Jet E_{T} (Bx = 0) GeV ; leading Fwd Jet E_{T} (Bx = -1) GeV ");

}
