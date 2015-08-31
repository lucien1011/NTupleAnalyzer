//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug 26 10:19:23 2015 by ROOT version 6.02/05
// from TTree L1ExtraTree/L1ExtraTree
// found on file: root://eoscms//eos/cms/store/user/klo/ExpressPhysics_254459/L1Tuple_ExpressPhysics_254459_1.root
//////////////////////////////////////////////////////////

#ifndef L1ExtraTree_h
#define L1ExtraTree_h
using namespace std;

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
// #include "L1TriggerDPG/L1Ntuples/interface/L1AnalysisL1ExtraDataFormat.h"

class L1ExtraTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
 //L1Analysis::L1AnalysisL1ExtraDataFormat *L1Extra;
   UInt_t          nIsoEm;
   vector<double>  isoEmEt;
   vector<double>  isoEmEta;
   vector<double>  isoEmPhi;
   vector<int>     isoEmBx;
   UInt_t          nNonIsoEm;
   vector<double>  nonIsoEmEt;
   vector<double>  nonIsoEmEta;
   vector<double>  nonIsoEmPhi;
   vector<int>     nonIsoEmBx;
   UInt_t          nCenJets;
   vector<double>  cenJetEt;
   vector<double>  cenJetEta;
   vector<double>  cenJetPhi;
   vector<int>     cenJetBx;
   UInt_t          nFwdJets;
   vector<double>  fwdJetEt;
   vector<double>  fwdJetEta;
   vector<double>  fwdJetPhi;
   vector<int>     fwdJetBx;
   UInt_t          nTauJets;
   vector<double>  tauJetEt;
   vector<double>  tauJetEta;
   vector<double>  tauJetPhi;
   vector<int>     tauJetBx;
   UInt_t          nIsoTauJets;
   vector<double>  isoTauJetEt;
   vector<double>  isoTauJetEta;
   vector<double>  isoTauJetPhi;
   vector<int>     isoTauJetBx;
   UInt_t          nMuons;
   vector<double>  muonEt;
   vector<double>  muonEta;
   vector<double>  muonPhi;
   vector<int>     muonChg;
   vector<unsigned int> muonIso;
   vector<unsigned int> muonFwd;
   vector<unsigned int> muonMip;
   vector<unsigned int> muonRPC;
   vector<int>     muonBx;
   vector<int>     muonQuality;
   vector<double>  hfEtSum;
   vector<unsigned int> hfBitCnt;
   vector<int>     hfBx;
   UInt_t          nMet;
   vector<double>  et;
   vector<double>  met;
   vector<double>  metPhi;
   vector<double>  metBx;
   UInt_t          nMht;
   vector<double>  ht;
   vector<double>  mht;
   vector<double>  mhtPhi;
   vector<double>  mhtBx;

   // List of branches
   TBranch        *b_L1Extra_nIsoEm;   //!
   TBranch        *b_L1Extra_isoEmEt;   //!
   TBranch        *b_L1Extra_isoEmEta;   //!
   TBranch        *b_L1Extra_isoEmPhi;   //!
   TBranch        *b_L1Extra_isoEmBx;   //!
   TBranch        *b_L1Extra_nNonIsoEm;   //!
   TBranch        *b_L1Extra_nonIsoEmEt;   //!
   TBranch        *b_L1Extra_nonIsoEmEta;   //!
   TBranch        *b_L1Extra_nonIsoEmPhi;   //!
   TBranch        *b_L1Extra_nonIsoEmBx;   //!
   TBranch        *b_L1Extra_nCenJets;   //!
   TBranch        *b_L1Extra_cenJetEt;   //!
   TBranch        *b_L1Extra_cenJetEta;   //!
   TBranch        *b_L1Extra_cenJetPhi;   //!
   TBranch        *b_L1Extra_cenJetBx;   //!
   TBranch        *b_L1Extra_nFwdJets;   //!
   TBranch        *b_L1Extra_fwdJetEt;   //!
   TBranch        *b_L1Extra_fwdJetEta;   //!
   TBranch        *b_L1Extra_fwdJetPhi;   //!
   TBranch        *b_L1Extra_fwdJetBx;   //!
   TBranch        *b_L1Extra_nTauJets;   //!
   TBranch        *b_L1Extra_tauJetEt;   //!
   TBranch        *b_L1Extra_tauJetEta;   //!
   TBranch        *b_L1Extra_tauJetPhi;   //!
   TBranch        *b_L1Extra_tauJetBx;   //!
   TBranch        *b_L1Extra_nIsoTauJets;   //!
   TBranch        *b_L1Extra_isoTauJetEt;   //!
   TBranch        *b_L1Extra_isoTauJetEta;   //!
   TBranch        *b_L1Extra_isoTauJetPhi;   //!
   TBranch        *b_L1Extra_isoTauJetBx;   //!
   TBranch        *b_L1Extra_nMuons;   //!
   TBranch        *b_L1Extra_muonEt;   //!
   TBranch        *b_L1Extra_muonEta;   //!
   TBranch        *b_L1Extra_muonPhi;   //!
   TBranch        *b_L1Extra_muonChg;   //!
   TBranch        *b_L1Extra_muonIso;   //!
   TBranch        *b_L1Extra_muonFwd;   //!
   TBranch        *b_L1Extra_muonMip;   //!
   TBranch        *b_L1Extra_muonRPC;   //!
   TBranch        *b_L1Extra_muonBx;   //!
   TBranch        *b_L1Extra_muonQuality;   //!
   TBranch        *b_L1Extra_hfEtSum;   //!
   TBranch        *b_L1Extra_hfBitCnt;   //!
   TBranch        *b_L1Extra_hfBx;   //!
   TBranch        *b_L1Extra_nMet;   //!
   TBranch        *b_L1Extra_et;   //!
   TBranch        *b_L1Extra_met;   //!
   TBranch        *b_L1Extra_metPhi;   //!
   TBranch        *b_L1Extra_metBx;   //!
   TBranch        *b_L1Extra_nMht;   //!
   TBranch        *b_L1Extra_ht;   //!
   TBranch        *b_L1Extra_mht;   //!
   TBranch        *b_L1Extra_mhtPhi;   //!
   TBranch        *b_L1Extra_mhtBx;   //!

   L1ExtraTree(TTree *tree=0);
   virtual ~L1ExtraTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef L1ExtraTree_cxx
L1ExtraTree::L1ExtraTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://eoscms//eos/cms/store/user/klo/ExpressPhysics_254459/L1Tuple_ExpressPhysics_254459_1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://eoscms//eos/cms/store/user/klo/ExpressPhysics_254459/L1Tuple_ExpressPhysics_254459_1.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("root://eoscms//eos/cms/store/user/klo/ExpressPhysics_254459/L1Tuple_ExpressPhysics_254459_1.root:/l1ExtraTreeProducer");
      dir->GetObject("L1ExtraTree",tree);

   }
   Init(tree);
}

L1ExtraTree::~L1ExtraTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t L1ExtraTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t L1ExtraTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void L1ExtraTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nIsoEm", &nIsoEm, &b_L1Extra_nIsoEm);
   fChain->SetBranchAddress("isoEmEt", &isoEmEt, &b_L1Extra_isoEmEt);
   fChain->SetBranchAddress("isoEmEta", &isoEmEta, &b_L1Extra_isoEmEta);
   fChain->SetBranchAddress("isoEmPhi", &isoEmPhi, &b_L1Extra_isoEmPhi);
   fChain->SetBranchAddress("isoEmBx", &isoEmBx, &b_L1Extra_isoEmBx);
   fChain->SetBranchAddress("nNonIsoEm", &nNonIsoEm, &b_L1Extra_nNonIsoEm);
   fChain->SetBranchAddress("nonIsoEmEt", &nonIsoEmEt, &b_L1Extra_nonIsoEmEt);
   fChain->SetBranchAddress("nonIsoEmEta", &nonIsoEmEta, &b_L1Extra_nonIsoEmEta);
   fChain->SetBranchAddress("nonIsoEmPhi", &nonIsoEmPhi, &b_L1Extra_nonIsoEmPhi);
   fChain->SetBranchAddress("nonIsoEmBx", &nonIsoEmBx, &b_L1Extra_nonIsoEmBx);
   fChain->SetBranchAddress("nCenJets", &nCenJets, &b_L1Extra_nCenJets);
   fChain->SetBranchAddress("cenJetEt", &cenJetEt, &b_L1Extra_cenJetEt);
   fChain->SetBranchAddress("cenJetEta", &cenJetEta, &b_L1Extra_cenJetEta);
   fChain->SetBranchAddress("cenJetPhi", &cenJetPhi, &b_L1Extra_cenJetPhi);
   fChain->SetBranchAddress("cenJetBx", &cenJetBx, &b_L1Extra_cenJetBx);
   fChain->SetBranchAddress("nFwdJets", &nFwdJets, &b_L1Extra_nFwdJets);
   fChain->SetBranchAddress("fwdJetEt", &fwdJetEt, &b_L1Extra_fwdJetEt);
   fChain->SetBranchAddress("fwdJetEta", &fwdJetEta, &b_L1Extra_fwdJetEta);
   fChain->SetBranchAddress("fwdJetPhi", &fwdJetPhi, &b_L1Extra_fwdJetPhi);
   fChain->SetBranchAddress("fwdJetBx", &fwdJetBx, &b_L1Extra_fwdJetBx);
   fChain->SetBranchAddress("nTauJets", &nTauJets, &b_L1Extra_nTauJets);
   fChain->SetBranchAddress("tauJetEt", &tauJetEt, &b_L1Extra_tauJetEt);
   fChain->SetBranchAddress("tauJetEta", &tauJetEta, &b_L1Extra_tauJetEta);
   fChain->SetBranchAddress("tauJetPhi", &tauJetPhi, &b_L1Extra_tauJetPhi);
   fChain->SetBranchAddress("tauJetBx", &tauJetBx, &b_L1Extra_tauJetBx);
   fChain->SetBranchAddress("nIsoTauJets", &nIsoTauJets, &b_L1Extra_nIsoTauJets);
   fChain->SetBranchAddress("isoTauJetEt", &isoTauJetEt, &b_L1Extra_isoTauJetEt);
   fChain->SetBranchAddress("isoTauJetEta", &isoTauJetEta, &b_L1Extra_isoTauJetEta);
   fChain->SetBranchAddress("isoTauJetPhi", &isoTauJetPhi, &b_L1Extra_isoTauJetPhi);
   fChain->SetBranchAddress("isoTauJetBx", &isoTauJetBx, &b_L1Extra_isoTauJetBx);
   fChain->SetBranchAddress("nMuons", &nMuons, &b_L1Extra_nMuons);
   fChain->SetBranchAddress("muonEt", &muonEt, &b_L1Extra_muonEt);
   fChain->SetBranchAddress("muonEta", &muonEta, &b_L1Extra_muonEta);
   fChain->SetBranchAddress("muonPhi", &muonPhi, &b_L1Extra_muonPhi);
   fChain->SetBranchAddress("muonChg", &muonChg, &b_L1Extra_muonChg);
   fChain->SetBranchAddress("muonIso", &muonIso, &b_L1Extra_muonIso);
   fChain->SetBranchAddress("muonFwd", &muonFwd, &b_L1Extra_muonFwd);
   fChain->SetBranchAddress("muonMip", &muonMip, &b_L1Extra_muonMip);
   fChain->SetBranchAddress("muonRPC", &muonRPC, &b_L1Extra_muonRPC);
   fChain->SetBranchAddress("muonBx", &muonBx, &b_L1Extra_muonBx);
   fChain->SetBranchAddress("muonQuality", &muonQuality, &b_L1Extra_muonQuality);
   fChain->SetBranchAddress("hfEtSum", &hfEtSum, &b_L1Extra_hfEtSum);
   fChain->SetBranchAddress("hfBitCnt", &hfBitCnt, &b_L1Extra_hfBitCnt);
   fChain->SetBranchAddress("hfBx", &hfBx, &b_L1Extra_hfBx);
   fChain->SetBranchAddress("nMet", &nMet, &b_L1Extra_nMet);
   fChain->SetBranchAddress("et", &et, &b_L1Extra_et);
   fChain->SetBranchAddress("met", &met, &b_L1Extra_met);
   fChain->SetBranchAddress("metPhi", &metPhi, &b_L1Extra_metPhi);
   fChain->SetBranchAddress("metBx", &metBx, &b_L1Extra_metBx);
   fChain->SetBranchAddress("nMht", &nMht, &b_L1Extra_nMht);
   fChain->SetBranchAddress("ht", &ht, &b_L1Extra_ht);
   fChain->SetBranchAddress("mht", &mht, &b_L1Extra_mht);
   fChain->SetBranchAddress("mhtPhi", &mhtPhi, &b_L1Extra_mhtPhi);
   fChain->SetBranchAddress("mhtBx", &mhtBx, &b_L1Extra_mhtBx);
   Notify();
}

Bool_t L1ExtraTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void L1ExtraTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t L1ExtraTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef L1ExtraTree_cxx
