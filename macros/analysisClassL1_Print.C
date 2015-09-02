#include "L1Tree.h"
#include "L1ExtraTree.h"
#include "analysisClassL1.h"
#include <algorithm>

void printJetsWithBx(const std::vector<double> jetEt, const std::vector<int> jetBx ,FILE* file){
  // std::cout << "--------------" << std::endl;
  // std::cout << jetBx.size() << std::endl; 
  for (int i=0;i != jetBx.size();i++){
    fprintf(file,"Jet %d Et: %f \n",i,jetEt[i]);
    fprintf(file,"Jet %d Bx: %d \n",i,jetBx[i]);
  };
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

  l1ExtraTree -> fChain -> SetBranchStatus("nCenJets", kTRUE);
  l1ExtraTree -> fChain -> SetBranchStatus("cenJetEt", kTRUE); 
  l1ExtraTree -> fChain -> SetBranchStatus("cenJetBx", kTRUE);

  FILE * f;
  f = fopen("L1Printout.txt","w");

  for (int i = 0; i < n_events; ++i){
   
    l1Tree -> GetEntry(i);
    l1ExtraTree -> GetEntry(i);
    if ( (i + 1) % 1000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;

    hlt = l1Tree -> hlt;
    bool accept = checkHLT(MyTrigger);
    if (not accept) continue;

    int nCenJet = l1ExtraTree -> nCenJets;
    std::vector<double> CenJetEt = l1ExtraTree -> cenJetEt;
    std::vector<int> CenJetBx = l1ExtraTree -> cenJetBx; 

    int nFwdJet = l1ExtraTree -> nFwdJets;
    std::vector<double> FwdJetEt = l1ExtraTree -> fwdJetEt;
    std::vector<int> FwdJetBx = l1ExtraTree -> fwdJetBx;

    int runNumber = l1Tree -> run ;
    int bunchNumber = l1Tree -> bx ;
    int lumiSection = l1Tree -> lumi ;
    int eventNumber = l1Tree -> event ;

    tw1 = l1Tree -> tw1;
    tw2 = l1Tree -> tw2;

    // double leadingFwdJetPt = getMaximum(getJetsWithBx(0,fwdJetEt,fwdJetBx));
    // double leadingCenJetPt = getMaximum(getJetsWithBx(0,cenJetEt,cenJetBx));

    bool Bx2Fired = checkTriggerBit(HFPrefiringBitMap["L1_SingleJet128"],2);
    fprintf(f,"=========================== \n");
    fprintf(f,"Event: %d \n",eventNumber);
    fprintf(f,"nCenJet: %d \n",nCenJet);
    fprintf(f,"nFwdJet: %d \n",nFwdJet);
    // fprintf(f,"L1 SingleJet128 Fired in bx2: %s \n",Bx2Fired);
    // std::cout << Bx2Fired << std::endl;
    if (Bx2Fired){
      fprintf(f,"Bx Fired! \n");
    };
    fprintf(f,"--------------------------- \n");
    fprintf(f,"Fwd Jet: \n");
    fprintf(f,"--------------------------- \n");
    printJetsWithBx(FwdJetEt,FwdJetBx,f);
    fprintf(f,"--------------------------- \n");
    fprintf(f,"Cen Jet: \n");
    fprintf(f,"--------------------------- \n");
    printJetsWithBx(CenJetEt,CenJetBx,f);

  };

  fclose(f);

}
