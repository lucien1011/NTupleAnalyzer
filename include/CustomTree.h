//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug 19 15:15:51 2015 by ROOT version 6.02/05
// from TTree L1Tree/L1Tree
// found on file: ../../CMSSW_7_4_8/src/L1TriggerDPG/L1Menu/test/L1Tree_test.root
//////////////////////////////////////////////////////////

#ifndef CustomTree_h
#define CustomTree_h
using namespace std;

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TMatrixT.h>

// Header file for the classes stored in the TTree if any.
// #include "L1TriggerDPG/L1Ntuples/interface/L1AnalysisEventDataFormat.h"
// #include "L1TriggerDPG/L1Ntuples/interface/L1AnalysisGCTDataFormat.h"
// #include "L1TriggerDPG/L1Ntuples/interface/L1AnalysisGMTDataFormat.h"
// #include "L1TriggerDPG/L1Ntuples/interface/L1AnalysisGTDataFormat.h"
// #include "L1TriggerDPG/L1Ntuples/interface/L1AnalysisRCTDataFormat.h"
// #include "L1TriggerDPG/L1Ntuples/interface/L1AnalysisDTTFDataFormat.h"
// #include "L1TriggerDPG/L1Ntuples/interface/L1AnalysisCSCTFDataFormat.h"
// #include "L1TriggerDPG/L1Ntuples/interface/L1AnalysisCaloTPDataFormat.h"

class CustomTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxmaxRCTREG = 1;

   // Declaration of leaf types
 //L1Analysis::L1AnalysisEventDataFormat *Event;
   Int_t           run;
   Int_t           event;
   Int_t           lumi;
   Int_t           bx;
   ULong64_t       orbit;
   ULong64_t       time;
   vector<TString> hlt;
   Double_t        puWeight;
   Double_t        nPV;
 //L1Analysis::L1AnalysisGCTDataFormat *GCT;
   Int_t           IsoEmSize;
   vector<float>   IsoEmEta;
   vector<float>   IsoEmPhi;
   vector<float>   IsoEmRnk;
   vector<int>     IsoEmBx;
   Int_t           NonIsoEmSize;
   vector<float>   NonIsoEmEta;
   vector<float>   NonIsoEmPhi;
   vector<float>   NonIsoEmRnk;
   vector<int>     NonIsoEmBx;
   Int_t           CJetSize;
   vector<float>   CJetEta;
   vector<float>   CJetPhi;
   vector<float>   CJetRnk;
   vector<int>     CJetBx;
   Int_t           FJetSize;
   vector<float>   FJetEta;
   vector<float>   FJetPhi;
   vector<float>   FJetRnk;
   vector<int>     FJetBx;
   Int_t           TJetSize;
   vector<float>   TJetEta;
   vector<float>   TJetPhi;
   vector<float>   TJetRnk;
   vector<int>     TJetBx;
   Int_t           IsoTJetSize;
   vector<float>   IsoTJetEta;
   vector<float>   IsoTJetPhi;
   vector<float>   IsoTJetRnk;
   vector<int>     IsoTJetBx;
   Int_t           EtMissSize;
   vector<float>   EtMiss;
   vector<float>   EtMissPhi;
   vector<float>   EtMissBX;
   Int_t           HtMissSize;
   vector<float>   HtMiss;
   vector<float>   HtMissPhi;
   vector<float>   HtMissBX;
   Int_t           EtHadSize;
   vector<float>   EtHad;
   vector<float>   EtHadBX;
   Int_t           EtTotSize;
   vector<float>   EtTot;
   vector<float>   EtTotBX;
   Int_t           HFRingEtSumSize;
   vector<float>   HFRingEtSumEta;
   Float_t         HFBitCountsSize;
   vector<float>   HFBitCountsEta;
 //L1Analysis::L1AnalysisGMTDataFormat *GMT;
   Int_t           EvBx;
   Int_t           Ndt;
   vector<int>     Bxdt;
   vector<float>   Ptdt;
   vector<int>     Chadt;
   vector<float>   Etadt;
   vector<int>     FineEtadt;
   vector<float>   Phidt;
   vector<int>     Qualdt;
   vector<int>     Dwdt;
   vector<int>     Chdt;
   Int_t           Ncsc;
   vector<int>     Bxcsc;
   vector<float>   Ptcsc;
   vector<int>     Chacsc;
   vector<float>   Etacsc;
   vector<float>   Phicsc;
   vector<int>     Qualcsc;
   vector<int>     Dwcsc;
   Int_t           Nrpcb;
   vector<int>     Bxrpcb;
   vector<float>   Ptrpcb;
   vector<int>     Charpcb;
   vector<float>   Etarpcb;
   vector<float>   Phirpcb;
   vector<int>     Qualrpcb;
   vector<int>     Dwrpcb;
   Int_t           Nrpcf;
   vector<int>     Bxrpcf;
   vector<float>   Ptrpcf;
   vector<int>     Charpcf;
   vector<float>   Etarpcf;
   vector<float>   Phirpcf;
   vector<int>     Qualrpcf;
   vector<int>     Dwrpcf;
   Int_t           N;
   vector<int>     CandBx;
   vector<float>   Pt;
   vector<int>     Cha;
   vector<float>   Eta;
   vector<float>   Phi;
   vector<int>     Qual;
   vector<int>     Det;
   vector<int>     Rank;
   vector<int>     Isol;
   vector<int>     Mip;
   vector<int>     Dw;
   vector<int>     IdxRPCb;
   vector<int>     IdxRPCf;
   vector<int>     IdxDTBX;
   vector<int>     IdxCSC;
 //L1Analysis::L1AnalysisGTDataFormat *GT;
   vector<ULong64_t> tw1;
   vector<ULong64_t> tw2;
   vector<ULong64_t> tt;
   ULong_t         partrig_tcs;
   ULong_t         gpsTimehi;
   ULong_t         gpsTimelo;
   ULong_t         bstMasterStatus;
   ULong_t         bstturnCountNumber;
   ULong_t         bstlhcFillNumber;
   ULong_t         bstbeamMode;
   ULong_t         bstparticleTypeBeam1;
   ULong_t         bstparticleTypeBeam2;
   ULong_t         bstbeamMomentum;
   ULong_t         bsttotalIntensityBeam1;
   ULong_t         bsttotalIntensityBeam2;
   Int_t           gtfeBx;
   Int_t           Nele;
   vector<int>     Bxel;
   vector<float>   Rankel;
   vector<float>   Phiel;
   vector<float>   Etael;
   vector<bool>    Isoel;
   Int_t           Njet;
   vector<int>     Bxjet;
   vector<float>   Rankjet;
   vector<float>   Phijet;
   vector<float>   Etajet;
   vector<bool>    Taujet;
   vector<bool>    Fwdjet;
   Int_t           RankETT;
   Bool_t          OvETT;
   Int_t           RankHTT;
   Bool_t          OvHTT;
   Int_t           RankETM;
   Int_t           PhiETM;
   Bool_t          OvETM;
   Int_t           RankHTM;
   Int_t           PhiHTM;
   Bool_t          OvHTM;
 //L1Analysis::L1AnalysisRCTDataFormat *RCT;
   Int_t           maxRCTREG_;
   Int_t           RegSize;
   vector<float>   RegEta;
   vector<float>   RegPhi;
   vector<float>   RegGEta;
   vector<float>   RegGPhi;
   vector<float>   RegRnk;
   vector<int>     RegVeto;
   vector<int>     RegBx;
   vector<int>     RegOverFlow;
   vector<int>     RegMip;
   vector<int>     RegFGrain;
   Int_t           EmSize;
   vector<int>     IsIsoEm;
   vector<float>   EmEta;
   vector<float>   EmPhi;
   vector<float>   EmRnk;
   vector<int>     EmBx;
 //L1Analysis::L1AnalysisDTTFDataFormat *DTTF;
   Int_t           phSize;
   vector<int>     phBx;
   vector<int>     phWh;
   vector<int>     phSe;
   vector<int>     phSt;
   vector<float>   phAng;
   vector<double>  phGlobPhi;
   vector<float>   phBandAng;
   vector<int>     phCode;
   vector<float>   phX;
   vector<float>   phY;
   Int_t           thSize;
   vector<int>     thBx;
   vector<int>     thWh;
   vector<int>     thSe;
   vector<int>     thSt;
   vector<float>   thX;
   vector<float>   thY;
   TMatrixT<double> thTheta;
   TMatrixT<double> thCode;
   Int_t           trSize;
   vector<int>     trBx;
   vector<int>     trTag;
   vector<int>     trQual;
   vector<int>     trPtPck;
   vector<float>   trPtVal;
   vector<int>     trPhiPck;
   vector<float>   trPhiVal;
   vector<int>     trEtaPck;
   vector<float>   trEtaVal;
   vector<double>  trPhiGlob;
   vector<int>     trChPck;
   vector<int>     trWh;
   vector<int>     trSc;
   vector<unsigned int> trAddress;
 //L1Analysis::L1AnalysisCSCTFDataFormat *CSCTF;
   //Int_t           trSize;
   vector<int>     trEndcap;
   vector<int>     trSector;
   //vector<int>     trBx;
   vector<int>     trME1ID;
   vector<int>     trME2ID;
   vector<int>     trME3ID;
   vector<int>     trME4ID;
   vector<int>     trMB1ID;
   vector<int>     trME1TBin;
   vector<int>     trME2TBin;
   vector<int>     trME3TBin;
   vector<int>     trME4TBin;
   vector<int>     trMB1TBin;
   vector<int>     trOutputLink;
   vector<int>     trCharge;
   vector<int>     trChargeValid;
   vector<int>     trForR;
   vector<int>     trPhi23;
   vector<int>     trPhi12;
   vector<int>     trPhiSign;
   vector<int>     trEtaBit;
   vector<int>     trPhiBit;
   vector<int>     trPtBit;
   vector<float>   trEta;
   vector<float>   trPhi;
   vector<float>   trPhi_02PI;
   vector<float>   trPt;
   vector<int>     trMode;
   vector<int>     trQuality;
   vector<int>     trNumLCTs;
   TMatrixT<double> trLctEndcap;
   TMatrixT<double> trLctSector;
   TMatrixT<double> trLctSubSector;
   TMatrixT<double> trLctBx;
   TMatrixT<double> trLctBx0;
   TMatrixT<double> trLctStation;
   TMatrixT<double> trLctRing;
   TMatrixT<double> trLctChamber;
   TMatrixT<double> trLctTriggerCSCID;
   TMatrixT<double> trLctFpga;
   TMatrixT<double> trLctlocalPhi;
   TMatrixT<double> trLctCLCT_pattern;
   TMatrixT<double> trLctQuality;
   TMatrixT<double> trLctglobalPhi;
   TMatrixT<double> trLctglobalEta;
   TMatrixT<double> trLctstripNum;
   TMatrixT<double> trLctwireGroup;
   Int_t           lctSize;
   vector<int>     lctEndcap;
   vector<int>     lctSector;
   vector<int>     lctSubSector;
   vector<int>     lctBx;
   vector<int>     lctBx0;
   vector<int>     lctStation;
   vector<int>     lctRing;
   vector<int>     lctChamber;
   vector<int>     lctTriggerCSCID;
   vector<int>     lctFpga;
   vector<int>     lctlocalPhi;
   vector<int>     lctCLCT_pattern;
   vector<int>     lctQuality;
   vector<int>     lctglobalPhi;
   vector<int>     lctglobalEta;
   vector<int>     lctstripNum;
   vector<int>     lctwireGroup;
   Int_t           nsp;
   vector<int>     stSPslot;
   vector<int>     stL1A_BXN;
   vector<unsigned long> stTrkCounter;
   vector<unsigned long> stOrbCounter;
   Int_t           dtSize;
   vector<int>     dtCAL;
   vector<int>     dtFLAG;
   vector<int>     dtBXN;
   vector<int>     dtSector;
   vector<int>     dtSubSector;
   vector<int>     dtBX0;
   vector<int>     dtPhiBend;
   vector<int>     dtQuality;
   vector<int>     dtPhiPacked;
 //L1Analysis::L1AnalysisCaloTPDataFormat *CALO;
   Int_t           nHCALTP;
   vector<int>     hcalTPieta;
   vector<int>     hcalTPiphi;
   vector<int>     hcalTPCaliphi;
   vector<double>  hcalTPet;
   vector<int>     hcalTPcompEt;
   vector<short>   hcalTPfineGrain;
   Int_t           nECALTP;
   vector<int>     ecalTPieta;
   vector<int>     ecalTPiphi;
   vector<int>     ecalTPCaliphi;
   vector<double>  ecalTPet;
   vector<int>     ecalTPcompEt;
   vector<short>   ecalTPfineGrain;

   // List of branches
   TBranch        *b_Event_run;   //!
   TBranch        *b_Event_event;   //!
   TBranch        *b_Event_lumi;   //!
   TBranch        *b_Event_bx;   //!
   TBranch        *b_Event_orbit;   //!
   TBranch        *b_Event_time;   //!
   TBranch        *b_Event_hlt;   //!
   TBranch        *b_Event_puWeight;   //!
   TBranch        *b_Event_nPV;   //!
   TBranch        *b_GCT_IsoEmSize;   //!
   TBranch        *b_GCT_IsoEmEta;   //!
   TBranch        *b_GCT_IsoEmPhi;   //!
   TBranch        *b_GCT_IsoEmRnk;   //!
   TBranch        *b_GCT_IsoEmBx;   //!
   TBranch        *b_GCT_NonIsoEmSize;   //!
   TBranch        *b_GCT_NonIsoEmEta;   //!
   TBranch        *b_GCT_NonIsoEmPhi;   //!
   TBranch        *b_GCT_NonIsoEmRnk;   //!
   TBranch        *b_GCT_NonIsoEmBx;   //!
   TBranch        *b_GCT_CJetSize;   //!
   TBranch        *b_GCT_CJetEta;   //!
   TBranch        *b_GCT_CJetPhi;   //!
   TBranch        *b_GCT_CJetRnk;   //!
   TBranch        *b_GCT_CJetBx;   //!
   TBranch        *b_GCT_FJetSize;   //!
   TBranch        *b_GCT_FJetEta;   //!
   TBranch        *b_GCT_FJetPhi;   //!
   TBranch        *b_GCT_FJetRnk;   //!
   TBranch        *b_GCT_FJetBx;   //!
   TBranch        *b_GCT_TJetSize;   //!
   TBranch        *b_GCT_TJetEta;   //!
   TBranch        *b_GCT_TJetPhi;   //!
   TBranch        *b_GCT_TJetRnk;   //!
   TBranch        *b_GCT_TJetBx;   //!
   TBranch        *b_GCT_IsoTJetSize;   //!
   TBranch        *b_GCT_IsoTJetEta;   //!
   TBranch        *b_GCT_IsoTJetPhi;   //!
   TBranch        *b_GCT_IsoTJetRnk;   //!
   TBranch        *b_GCT_IsoTJetBx;   //!
   TBranch        *b_GCT_EtMissSize;   //!
   TBranch        *b_GCT_EtMiss;   //!
   TBranch        *b_GCT_EtMissPhi;   //!
   TBranch        *b_GCT_EtMissBX;   //!
   TBranch        *b_GCT_HtMissSize;   //!
   TBranch        *b_GCT_HtMiss;   //!
   TBranch        *b_GCT_HtMissPhi;   //!
   TBranch        *b_GCT_HtMissBX;   //!
   TBranch        *b_GCT_EtHadSize;   //!
   TBranch        *b_GCT_EtHad;   //!
   TBranch        *b_GCT_EtHadBX;   //!
   TBranch        *b_GCT_EtTotSize;   //!
   TBranch        *b_GCT_EtTot;   //!
   TBranch        *b_GCT_EtTotBX;   //!
   TBranch        *b_GCT_HFRingEtSumSize;   //!
   TBranch        *b_GCT_HFRingEtSumEta;   //!
   TBranch        *b_GCT_HFBitCountsSize;   //!
   TBranch        *b_GCT_HFBitCountsEta;   //!
   TBranch        *b_GMT_EvBx;   //!
   TBranch        *b_GMT_Ndt;   //!
   TBranch        *b_GMT_Bxdt;   //!
   TBranch        *b_GMT_Ptdt;   //!
   TBranch        *b_GMT_Chadt;   //!
   TBranch        *b_GMT_Etadt;   //!
   TBranch        *b_GMT_FineEtadt;   //!
   TBranch        *b_GMT_Phidt;   //!
   TBranch        *b_GMT_Qualdt;   //!
   TBranch        *b_GMT_Dwdt;   //!
   TBranch        *b_GMT_Chdt;   //!
   TBranch        *b_GMT_Ncsc;   //!
   TBranch        *b_GMT_Bxcsc;   //!
   TBranch        *b_GMT_Ptcsc;   //!
   TBranch        *b_GMT_Chacsc;   //!
   TBranch        *b_GMT_Etacsc;   //!
   TBranch        *b_GMT_Phicsc;   //!
   TBranch        *b_GMT_Qualcsc;   //!
   TBranch        *b_GMT_Dwcsc;   //!
   TBranch        *b_GMT_Nrpcb;   //!
   TBranch        *b_GMT_Bxrpcb;   //!
   TBranch        *b_GMT_Ptrpcb;   //!
   TBranch        *b_GMT_Charpcb;   //!
   TBranch        *b_GMT_Etarpcb;   //!
   TBranch        *b_GMT_Phirpcb;   //!
   TBranch        *b_GMT_Qualrpcb;   //!
   TBranch        *b_GMT_Dwrpcb;   //!
   TBranch        *b_GMT_Nrpcf;   //!
   TBranch        *b_GMT_Bxrpcf;   //!
   TBranch        *b_GMT_Ptrpcf;   //!
   TBranch        *b_GMT_Charpcf;   //!
   TBranch        *b_GMT_Etarpcf;   //!
   TBranch        *b_GMT_Phirpcf;   //!
   TBranch        *b_GMT_Qualrpcf;   //!
   TBranch        *b_GMT_Dwrpcf;   //!
   TBranch        *b_GMT_N;   //!
   TBranch        *b_GMT_CandBx;   //!
   TBranch        *b_GMT_Pt;   //!
   TBranch        *b_GMT_Cha;   //!
   TBranch        *b_GMT_Eta;   //!
   TBranch        *b_GMT_Phi;   //!
   TBranch        *b_GMT_Qual;   //!
   TBranch        *b_GMT_Det;   //!
   TBranch        *b_GMT_Rank;   //!
   TBranch        *b_GMT_Isol;   //!
   TBranch        *b_GMT_Mip;   //!
   TBranch        *b_GMT_Dw;   //!
   TBranch        *b_GMT_IdxRPCb;   //!
   TBranch        *b_GMT_IdxRPCf;   //!
   TBranch        *b_GMT_IdxDTBX;   //!
   TBranch        *b_GMT_IdxCSC;   //!
   TBranch        *b_GT_tw1;   //!
   TBranch        *b_GT_tw2;   //!
   TBranch        *b_GT_tt;   //!
   TBranch        *b_GT_partrig_tcs;   //!
   TBranch        *b_GT_gpsTimehi;   //!
   TBranch        *b_GT_gpsTimelo;   //!
   TBranch        *b_GT_bstMasterStatus;   //!
   TBranch        *b_GT_bstturnCountNumber;   //!
   TBranch        *b_GT_bstlhcFillNumber;   //!
   TBranch        *b_GT_bstbeamMode;   //!
   TBranch        *b_GT_bstparticleTypeBeam1;   //!
   TBranch        *b_GT_bstparticleTypeBeam2;   //!
   TBranch        *b_GT_bstbeamMomentum;   //!
   TBranch        *b_GT_bsttotalIntensityBeam1;   //!
   TBranch        *b_GT_bsttotalIntensityBeam2;   //!
   TBranch        *b_GT_gtfeBx;   //!
   TBranch        *b_GT_Nele;   //!
   TBranch        *b_GT_Bxel;   //!
   TBranch        *b_GT_Rankel;   //!
   TBranch        *b_GT_Phiel;   //!
   TBranch        *b_GT_Etael;   //!
   TBranch        *b_GT_Isoel;   //!
   TBranch        *b_GT_Njet;   //!
   TBranch        *b_GT_Bxjet;   //!
   TBranch        *b_GT_Rankjet;   //!
   TBranch        *b_GT_Phijet;   //!
   TBranch        *b_GT_Etajet;   //!
   TBranch        *b_GT_Taujet;   //!
   TBranch        *b_GT_Fwdjet;   //!
   TBranch        *b_GT_RankETT;   //!
   TBranch        *b_GT_OvETT;   //!
   TBranch        *b_GT_RankHTT;   //!
   TBranch        *b_GT_OvHTT;   //!
   TBranch        *b_GT_RankETM;   //!
   TBranch        *b_GT_PhiETM;   //!
   TBranch        *b_GT_OvETM;   //!
   TBranch        *b_GT_RankHTM;   //!
   TBranch        *b_GT_PhiHTM;   //!
   TBranch        *b_GT_OvHTM;   //!
   TBranch        *b_RCT_maxRCTREG_;   //!
   TBranch        *b_RCT_RegSize;   //!
   TBranch        *b_RCT_RegEta;   //!
   TBranch        *b_RCT_RegPhi;   //!
   TBranch        *b_RCT_RegGEta;   //!
   TBranch        *b_RCT_RegGPhi;   //!
   TBranch        *b_RCT_RegRnk;   //!
   TBranch        *b_RCT_RegVeto;   //!
   TBranch        *b_RCT_RegBx;   //!
   TBranch        *b_RCT_RegOverFlow;   //!
   TBranch        *b_RCT_RegMip;   //!
   TBranch        *b_RCT_RegFGrain;   //!
   TBranch        *b_RCT_EmSize;   //!
   TBranch        *b_RCT_IsIsoEm;   //!
   TBranch        *b_RCT_EmEta;   //!
   TBranch        *b_RCT_EmPhi;   //!
   TBranch        *b_RCT_EmRnk;   //!
   TBranch        *b_RCT_EmBx;   //!
   TBranch        *b_DTTF_phSize;   //!
   TBranch        *b_DTTF_phBx;   //!
   TBranch        *b_DTTF_phWh;   //!
   TBranch        *b_DTTF_phSe;   //!
   TBranch        *b_DTTF_phSt;   //!
   TBranch        *b_DTTF_phAng;   //!
   TBranch        *b_DTTF_phGlobPhi;   //!
   TBranch        *b_DTTF_phBandAng;   //!
   TBranch        *b_DTTF_phCode;   //!
   TBranch        *b_DTTF_phX;   //!
   TBranch        *b_DTTF_phY;   //!
   TBranch        *b_DTTF_thSize;   //!
   TBranch        *b_DTTF_thBx;   //!
   TBranch        *b_DTTF_thWh;   //!
   TBranch        *b_DTTF_thSe;   //!
   TBranch        *b_DTTF_thSt;   //!
   TBranch        *b_DTTF_thX;   //!
   TBranch        *b_DTTF_thY;   //!
   TBranch        *b_DTTF_thTheta;   //!
   TBranch        *b_DTTF_thCode;   //!
   TBranch        *b_DTTF_trSize;   //!
   TBranch        *b_DTTF_trBx;   //!
   TBranch        *b_DTTF_trTag;   //!
   TBranch        *b_DTTF_trQual;   //!
   TBranch        *b_DTTF_trPtPck;   //!
   TBranch        *b_DTTF_trPtVal;   //!
   TBranch        *b_DTTF_trPhiPck;   //!
   TBranch        *b_DTTF_trPhiVal;   //!
   TBranch        *b_DTTF_trEtaPck;   //!
   TBranch        *b_DTTF_trEtaVal;   //!
   TBranch        *b_DTTF_trPhiGlob;   //!
   TBranch        *b_DTTF_trChPck;   //!
   TBranch        *b_DTTF_trWh;   //!
   TBranch        *b_DTTF_trSc;   //!
   TBranch        *b_DTTF_trAddress;   //!
   TBranch        *b_CSCTF_trSize;   //!
   TBranch        *b_CSCTF_trEndcap;   //!
   TBranch        *b_CSCTF_trSector;   //!
   TBranch        *b_CSCTF_trBx;   //!
   TBranch        *b_CSCTF_trME1ID;   //!
   TBranch        *b_CSCTF_trME2ID;   //!
   TBranch        *b_CSCTF_trME3ID;   //!
   TBranch        *b_CSCTF_trME4ID;   //!
   TBranch        *b_CSCTF_trMB1ID;   //!
   TBranch        *b_CSCTF_trME1TBin;   //!
   TBranch        *b_CSCTF_trME2TBin;   //!
   TBranch        *b_CSCTF_trME3TBin;   //!
   TBranch        *b_CSCTF_trME4TBin;   //!
   TBranch        *b_CSCTF_trMB1TBin;   //!
   TBranch        *b_CSCTF_trOutputLink;   //!
   TBranch        *b_CSCTF_trCharge;   //!
   TBranch        *b_CSCTF_trChargeValid;   //!
   TBranch        *b_CSCTF_trForR;   //!
   TBranch        *b_CSCTF_trPhi23;   //!
   TBranch        *b_CSCTF_trPhi12;   //!
   TBranch        *b_CSCTF_trPhiSign;   //!
   TBranch        *b_CSCTF_trEtaBit;   //!
   TBranch        *b_CSCTF_trPhiBit;   //!
   TBranch        *b_CSCTF_trPtBit;   //!
   TBranch        *b_CSCTF_trEta;   //!
   TBranch        *b_CSCTF_trPhi;   //!
   TBranch        *b_CSCTF_trPhi_02PI;   //!
   TBranch        *b_CSCTF_trPt;   //!
   TBranch        *b_CSCTF_trMode;   //!
   TBranch        *b_CSCTF_trQuality;   //!
   TBranch        *b_CSCTF_trNumLCTs;   //!
   TBranch        *b_CSCTF_trLctEndcap;   //!
   TBranch        *b_CSCTF_trLctSector;   //!
   TBranch        *b_CSCTF_trLctSubSector;   //!
   TBranch        *b_CSCTF_trLctBx;   //!
   TBranch        *b_CSCTF_trLctBx0;   //!
   TBranch        *b_CSCTF_trLctStation;   //!
   TBranch        *b_CSCTF_trLctRing;   //!
   TBranch        *b_CSCTF_trLctChamber;   //!
   TBranch        *b_CSCTF_trLctTriggerCSCID;   //!
   TBranch        *b_CSCTF_trLctFpga;   //!
   TBranch        *b_CSCTF_trLctlocalPhi;   //!
   TBranch        *b_CSCTF_trLctCLCT_pattern;   //!
   TBranch        *b_CSCTF_trLctQuality;   //!
   TBranch        *b_CSCTF_trLctglobalPhi;   //!
   TBranch        *b_CSCTF_trLctglobalEta;   //!
   TBranch        *b_CSCTF_trLctstripNum;   //!
   TBranch        *b_CSCTF_trLctwireGroup;   //!
   TBranch        *b_CSCTF_lctSize;   //!
   TBranch        *b_CSCTF_lctEndcap;   //!
   TBranch        *b_CSCTF_lctSector;   //!
   TBranch        *b_CSCTF_lctSubSector;   //!
   TBranch        *b_CSCTF_lctBx;   //!
   TBranch        *b_CSCTF_lctBx0;   //!
   TBranch        *b_CSCTF_lctStation;   //!
   TBranch        *b_CSCTF_lctRing;   //!
   TBranch        *b_CSCTF_lctChamber;   //!
   TBranch        *b_CSCTF_lctTriggerCSCID;   //!
   TBranch        *b_CSCTF_lctFpga;   //!
   TBranch        *b_CSCTF_lctlocalPhi;   //!
   TBranch        *b_CSCTF_lctCLCT_pattern;   //!
   TBranch        *b_CSCTF_lctQuality;   //!
   TBranch        *b_CSCTF_lctglobalPhi;   //!
   TBranch        *b_CSCTF_lctglobalEta;   //!
   TBranch        *b_CSCTF_lctstripNum;   //!
   TBranch        *b_CSCTF_lctwireGroup;   //!
   TBranch        *b_CSCTF_nsp;   //!
   TBranch        *b_CSCTF_stSPslot;   //!
   TBranch        *b_CSCTF_stL1A_BXN;   //!
   TBranch        *b_CSCTF_stTrkCounter;   //!
   TBranch        *b_CSCTF_stOrbCounter;   //!
   TBranch        *b_CSCTF_dtSize;   //!
   TBranch        *b_CSCTF_dtCAL;   //!
   TBranch        *b_CSCTF_dtFLAG;   //!
   TBranch        *b_CSCTF_dtBXN;   //!
   TBranch        *b_CSCTF_dtSector;   //!
   TBranch        *b_CSCTF_dtSubSector;   //!
   TBranch        *b_CSCTF_dtBX0;   //!
   TBranch        *b_CSCTF_dtPhiBend;   //!
   TBranch        *b_CSCTF_dtQuality;   //!
   TBranch        *b_CSCTF_dtPhiPacked;   //!
   TBranch        *b_CALO_nHCALTP;   //!
   TBranch        *b_CALO_hcalTPieta;   //!
   TBranch        *b_CALO_hcalTPiphi;   //!
   TBranch        *b_CALO_hcalTPCaliphi;   //!
   TBranch        *b_CALO_hcalTPet;   //!
   TBranch        *b_CALO_hcalTPcompEt;   //!
   TBranch        *b_CALO_hcalTPfineGrain;   //!
   TBranch        *b_CALO_nECALTP;   //!
   TBranch        *b_CALO_ecalTPieta;   //!
   TBranch        *b_CALO_ecalTPiphi;   //!
   TBranch        *b_CALO_ecalTPCaliphi;   //!
   TBranch        *b_CALO_ecalTPet;   //!
   TBranch        *b_CALO_ecalTPcompEt;   //!
   TBranch        *b_CALO_ecalTPfineGrain;   //!

   CustomTree(TTree *tree=0);
   virtual ~CustomTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CustomTree_cxx
CustomTree::CustomTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../../CMSSW_7_4_8/src/L1TriggerDPG/L1Menu/test/L1Tree_test.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../../CMSSW_7_4_8/src/L1TriggerDPG/L1Menu/test/L1Tree_test.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("../../CMSSW_7_4_8/src/L1TriggerDPG/L1Menu/test/L1Tree_test.root:/l1NtupleProducer");
      dir->GetObject("L1Tree",tree);

   }
   Init(tree);
}

CustomTree::~CustomTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CustomTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CustomTree::LoadTree(Long64_t entry)
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

void CustomTree::Init(TTree *tree)
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

   fChain->SetBranchAddress("run", &run, &b_Event_run);
   fChain->SetBranchAddress("event", &event, &b_Event_event);
   fChain->SetBranchAddress("lumi", &lumi, &b_Event_lumi);
   fChain->SetBranchAddress("bx", &bx, &b_Event_bx);
   fChain->SetBranchAddress("orbit", &orbit, &b_Event_orbit);
   fChain->SetBranchAddress("time", &time, &b_Event_time);
   fChain->SetBranchAddress("hlt", &hlt, &b_Event_hlt);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_Event_puWeight);
   fChain->SetBranchAddress("nPV", &nPV, &b_Event_nPV);
   fChain->SetBranchAddress("IsoEmSize", &IsoEmSize, &b_GCT_IsoEmSize);
   fChain->SetBranchAddress("IsoEmEta", &IsoEmEta, &b_GCT_IsoEmEta);
   fChain->SetBranchAddress("IsoEmPhi", &IsoEmPhi, &b_GCT_IsoEmPhi);
   fChain->SetBranchAddress("IsoEmRnk", &IsoEmRnk, &b_GCT_IsoEmRnk);
   fChain->SetBranchAddress("IsoEmBx", &IsoEmBx, &b_GCT_IsoEmBx);
   fChain->SetBranchAddress("NonIsoEmSize", &NonIsoEmSize, &b_GCT_NonIsoEmSize);
   fChain->SetBranchAddress("NonIsoEmEta", &NonIsoEmEta, &b_GCT_NonIsoEmEta);
   fChain->SetBranchAddress("NonIsoEmPhi", &NonIsoEmPhi, &b_GCT_NonIsoEmPhi);
   fChain->SetBranchAddress("NonIsoEmRnk", &NonIsoEmRnk, &b_GCT_NonIsoEmRnk);
   fChain->SetBranchAddress("NonIsoEmBx", &NonIsoEmBx, &b_GCT_NonIsoEmBx);
   fChain->SetBranchAddress("CJetSize", &CJetSize, &b_GCT_CJetSize);
   fChain->SetBranchAddress("CJetEta", &CJetEta, &b_GCT_CJetEta);
   fChain->SetBranchAddress("CJetPhi", &CJetPhi, &b_GCT_CJetPhi);
   fChain->SetBranchAddress("CJetRnk", &CJetRnk, &b_GCT_CJetRnk);
   fChain->SetBranchAddress("CJetBx", &CJetBx, &b_GCT_CJetBx);
   fChain->SetBranchAddress("FJetSize", &FJetSize, &b_GCT_FJetSize);
   fChain->SetBranchAddress("FJetEta", &FJetEta, &b_GCT_FJetEta);
   fChain->SetBranchAddress("FJetPhi", &FJetPhi, &b_GCT_FJetPhi);
   fChain->SetBranchAddress("FJetRnk", &FJetRnk, &b_GCT_FJetRnk);
   fChain->SetBranchAddress("FJetBx", &FJetBx, &b_GCT_FJetBx);
   fChain->SetBranchAddress("TJetSize", &TJetSize, &b_GCT_TJetSize);
   fChain->SetBranchAddress("TJetEta", &TJetEta, &b_GCT_TJetEta);
   fChain->SetBranchAddress("TJetPhi", &TJetPhi, &b_GCT_TJetPhi);
   fChain->SetBranchAddress("TJetRnk", &TJetRnk, &b_GCT_TJetRnk);
   fChain->SetBranchAddress("TJetBx", &TJetBx, &b_GCT_TJetBx);
   fChain->SetBranchAddress("IsoTJetSize", &IsoTJetSize, &b_GCT_IsoTJetSize);
   fChain->SetBranchAddress("IsoTJetEta", &IsoTJetEta, &b_GCT_IsoTJetEta);
   fChain->SetBranchAddress("IsoTJetPhi", &IsoTJetPhi, &b_GCT_IsoTJetPhi);
   fChain->SetBranchAddress("IsoTJetRnk", &IsoTJetRnk, &b_GCT_IsoTJetRnk);
   fChain->SetBranchAddress("IsoTJetBx", &IsoTJetBx, &b_GCT_IsoTJetBx);
   fChain->SetBranchAddress("EtMissSize", &EtMissSize, &b_GCT_EtMissSize);
   fChain->SetBranchAddress("EtMiss", &EtMiss, &b_GCT_EtMiss);
   fChain->SetBranchAddress("EtMissPhi", &EtMissPhi, &b_GCT_EtMissPhi);
   fChain->SetBranchAddress("EtMissBX", &EtMissBX, &b_GCT_EtMissBX);
   fChain->SetBranchAddress("HtMissSize", &HtMissSize, &b_GCT_HtMissSize);
   fChain->SetBranchAddress("HtMiss", &HtMiss, &b_GCT_HtMiss);
   fChain->SetBranchAddress("HtMissPhi", &HtMissPhi, &b_GCT_HtMissPhi);
   fChain->SetBranchAddress("HtMissBX", &HtMissBX, &b_GCT_HtMissBX);
   fChain->SetBranchAddress("EtHadSize", &EtHadSize, &b_GCT_EtHadSize);
   fChain->SetBranchAddress("EtHad", &EtHad, &b_GCT_EtHad);
   fChain->SetBranchAddress("EtHadBX", &EtHadBX, &b_GCT_EtHadBX);
   fChain->SetBranchAddress("EtTotSize", &EtTotSize, &b_GCT_EtTotSize);
   fChain->SetBranchAddress("EtTot", &EtTot, &b_GCT_EtTot);
   fChain->SetBranchAddress("EtTotBX", &EtTotBX, &b_GCT_EtTotBX);
   fChain->SetBranchAddress("HFRingEtSumSize", &HFRingEtSumSize, &b_GCT_HFRingEtSumSize);
   fChain->SetBranchAddress("HFRingEtSumEta", &HFRingEtSumEta, &b_GCT_HFRingEtSumEta);
   fChain->SetBranchAddress("HFBitCountsSize", &HFBitCountsSize, &b_GCT_HFBitCountsSize);
   fChain->SetBranchAddress("HFBitCountsEta", &HFBitCountsEta, &b_GCT_HFBitCountsEta);
   fChain->SetBranchAddress("EvBx", &EvBx, &b_GMT_EvBx);
   fChain->SetBranchAddress("Ndt", &Ndt, &b_GMT_Ndt);
   fChain->SetBranchAddress("Bxdt", &Bxdt, &b_GMT_Bxdt);
   fChain->SetBranchAddress("Ptdt", &Ptdt, &b_GMT_Ptdt);
   fChain->SetBranchAddress("Chadt", &Chadt, &b_GMT_Chadt);
   fChain->SetBranchAddress("Etadt", &Etadt, &b_GMT_Etadt);
   fChain->SetBranchAddress("FineEtadt", &FineEtadt, &b_GMT_FineEtadt);
   fChain->SetBranchAddress("Phidt", &Phidt, &b_GMT_Phidt);
   fChain->SetBranchAddress("Qualdt", &Qualdt, &b_GMT_Qualdt);
   fChain->SetBranchAddress("Dwdt", &Dwdt, &b_GMT_Dwdt);
   fChain->SetBranchAddress("Chdt", &Chdt, &b_GMT_Chdt);
   fChain->SetBranchAddress("Ncsc", &Ncsc, &b_GMT_Ncsc);
   fChain->SetBranchAddress("Bxcsc", &Bxcsc, &b_GMT_Bxcsc);
   fChain->SetBranchAddress("Ptcsc", &Ptcsc, &b_GMT_Ptcsc);
   fChain->SetBranchAddress("Chacsc", &Chacsc, &b_GMT_Chacsc);
   fChain->SetBranchAddress("Etacsc", &Etacsc, &b_GMT_Etacsc);
   fChain->SetBranchAddress("Phicsc", &Phicsc, &b_GMT_Phicsc);
   fChain->SetBranchAddress("Qualcsc", &Qualcsc, &b_GMT_Qualcsc);
   fChain->SetBranchAddress("Dwcsc", &Dwcsc, &b_GMT_Dwcsc);
   fChain->SetBranchAddress("Nrpcb", &Nrpcb, &b_GMT_Nrpcb);
   fChain->SetBranchAddress("Bxrpcb", &Bxrpcb, &b_GMT_Bxrpcb);
   fChain->SetBranchAddress("Ptrpcb", &Ptrpcb, &b_GMT_Ptrpcb);
   fChain->SetBranchAddress("Charpcb", &Charpcb, &b_GMT_Charpcb);
   fChain->SetBranchAddress("Etarpcb", &Etarpcb, &b_GMT_Etarpcb);
   fChain->SetBranchAddress("Phirpcb", &Phirpcb, &b_GMT_Phirpcb);
   fChain->SetBranchAddress("Qualrpcb", &Qualrpcb, &b_GMT_Qualrpcb);
   fChain->SetBranchAddress("Dwrpcb", &Dwrpcb, &b_GMT_Dwrpcb);
   fChain->SetBranchAddress("Nrpcf", &Nrpcf, &b_GMT_Nrpcf);
   fChain->SetBranchAddress("Bxrpcf", &Bxrpcf, &b_GMT_Bxrpcf);
   fChain->SetBranchAddress("Ptrpcf", &Ptrpcf, &b_GMT_Ptrpcf);
   fChain->SetBranchAddress("Charpcf", &Charpcf, &b_GMT_Charpcf);
   fChain->SetBranchAddress("Etarpcf", &Etarpcf, &b_GMT_Etarpcf);
   fChain->SetBranchAddress("Phirpcf", &Phirpcf, &b_GMT_Phirpcf);
   fChain->SetBranchAddress("Qualrpcf", &Qualrpcf, &b_GMT_Qualrpcf);
   fChain->SetBranchAddress("Dwrpcf", &Dwrpcf, &b_GMT_Dwrpcf);
   fChain->SetBranchAddress("N", &N, &b_GMT_N);
   fChain->SetBranchAddress("CandBx", &CandBx, &b_GMT_CandBx);
   fChain->SetBranchAddress("Pt", &Pt, &b_GMT_Pt);
   fChain->SetBranchAddress("Cha", &Cha, &b_GMT_Cha);
   fChain->SetBranchAddress("Eta", &Eta, &b_GMT_Eta);
   fChain->SetBranchAddress("Phi", &Phi, &b_GMT_Phi);
   fChain->SetBranchAddress("Qual", &Qual, &b_GMT_Qual);
   fChain->SetBranchAddress("Det", &Det, &b_GMT_Det);
   fChain->SetBranchAddress("Rank", &Rank, &b_GMT_Rank);
   fChain->SetBranchAddress("Isol", &Isol, &b_GMT_Isol);
   fChain->SetBranchAddress("Mip", &Mip, &b_GMT_Mip);
   fChain->SetBranchAddress("Dw", &Dw, &b_GMT_Dw);
   fChain->SetBranchAddress("IdxRPCb", &IdxRPCb, &b_GMT_IdxRPCb);
   fChain->SetBranchAddress("IdxRPCf", &IdxRPCf, &b_GMT_IdxRPCf);
   fChain->SetBranchAddress("IdxDTBX", &IdxDTBX, &b_GMT_IdxDTBX);
   fChain->SetBranchAddress("IdxCSC", &IdxCSC, &b_GMT_IdxCSC);
   fChain->SetBranchAddress("tw1", &tw1, &b_GT_tw1);
   fChain->SetBranchAddress("tw2", &tw2, &b_GT_tw2);
   fChain->SetBranchAddress("tt", &tt, &b_GT_tt);
   fChain->SetBranchAddress("partrig_tcs", &partrig_tcs, &b_GT_partrig_tcs);
   fChain->SetBranchAddress("gpsTimehi", &gpsTimehi, &b_GT_gpsTimehi);
   fChain->SetBranchAddress("gpsTimelo", &gpsTimelo, &b_GT_gpsTimelo);
   fChain->SetBranchAddress("bstMasterStatus", &bstMasterStatus, &b_GT_bstMasterStatus);
   fChain->SetBranchAddress("bstturnCountNumber", &bstturnCountNumber, &b_GT_bstturnCountNumber);
   fChain->SetBranchAddress("bstlhcFillNumber", &bstlhcFillNumber, &b_GT_bstlhcFillNumber);
   fChain->SetBranchAddress("bstbeamMode", &bstbeamMode, &b_GT_bstbeamMode);
   fChain->SetBranchAddress("bstparticleTypeBeam1", &bstparticleTypeBeam1, &b_GT_bstparticleTypeBeam1);
   fChain->SetBranchAddress("bstparticleTypeBeam2", &bstparticleTypeBeam2, &b_GT_bstparticleTypeBeam2);
   fChain->SetBranchAddress("bstbeamMomentum", &bstbeamMomentum, &b_GT_bstbeamMomentum);
   fChain->SetBranchAddress("bsttotalIntensityBeam1", &bsttotalIntensityBeam1, &b_GT_bsttotalIntensityBeam1);
   fChain->SetBranchAddress("bsttotalIntensityBeam2", &bsttotalIntensityBeam2, &b_GT_bsttotalIntensityBeam2);
   fChain->SetBranchAddress("gtfeBx", &gtfeBx, &b_GT_gtfeBx);
   fChain->SetBranchAddress("Nele", &Nele, &b_GT_Nele);
   fChain->SetBranchAddress("Bxel", &Bxel, &b_GT_Bxel);
   fChain->SetBranchAddress("Rankel", &Rankel, &b_GT_Rankel);
   fChain->SetBranchAddress("Phiel", &Phiel, &b_GT_Phiel);
   fChain->SetBranchAddress("Etael", &Etael, &b_GT_Etael);
   fChain->SetBranchAddress("Isoel", &Isoel, &b_GT_Isoel);
   fChain->SetBranchAddress("Njet", &Njet, &b_GT_Njet);
   fChain->SetBranchAddress("Bxjet", &Bxjet, &b_GT_Bxjet);
   fChain->SetBranchAddress("Rankjet", &Rankjet, &b_GT_Rankjet);
   fChain->SetBranchAddress("Phijet", &Phijet, &b_GT_Phijet);
   fChain->SetBranchAddress("Etajet", &Etajet, &b_GT_Etajet);
   fChain->SetBranchAddress("Taujet", &Taujet, &b_GT_Taujet);
   fChain->SetBranchAddress("Fwdjet", &Fwdjet, &b_GT_Fwdjet);
   fChain->SetBranchAddress("RankETT", &RankETT, &b_GT_RankETT);
   fChain->SetBranchAddress("OvETT", &OvETT, &b_GT_OvETT);
   fChain->SetBranchAddress("RankHTT", &RankHTT, &b_GT_RankHTT);
   fChain->SetBranchAddress("OvHTT", &OvHTT, &b_GT_OvHTT);
   fChain->SetBranchAddress("RankETM", &RankETM, &b_GT_RankETM);
   fChain->SetBranchAddress("PhiETM", &PhiETM, &b_GT_PhiETM);
   fChain->SetBranchAddress("OvETM", &OvETM, &b_GT_OvETM);
   fChain->SetBranchAddress("RankHTM", &RankHTM, &b_GT_RankHTM);
   fChain->SetBranchAddress("PhiHTM", &PhiHTM, &b_GT_PhiHTM);
   fChain->SetBranchAddress("OvHTM", &OvHTM, &b_GT_OvHTM);
   fChain->SetBranchAddress("maxRCTREG_", &maxRCTREG_, &b_RCT_maxRCTREG_);
   fChain->SetBranchAddress("RegSize", &RegSize, &b_RCT_RegSize);
   fChain->SetBranchAddress("RegEta", &RegEta, &b_RCT_RegEta);
   fChain->SetBranchAddress("RegPhi", &RegPhi, &b_RCT_RegPhi);
   fChain->SetBranchAddress("RegGEta", &RegGEta, &b_RCT_RegGEta);
   fChain->SetBranchAddress("RegGPhi", &RegGPhi, &b_RCT_RegGPhi);
   fChain->SetBranchAddress("RegRnk", &RegRnk, &b_RCT_RegRnk);
   fChain->SetBranchAddress("RegVeto", &RegVeto, &b_RCT_RegVeto);
   fChain->SetBranchAddress("RegBx", &RegBx, &b_RCT_RegBx);
   fChain->SetBranchAddress("RegOverFlow", &RegOverFlow, &b_RCT_RegOverFlow);
   fChain->SetBranchAddress("RegMip", &RegMip, &b_RCT_RegMip);
   fChain->SetBranchAddress("RegFGrain", &RegFGrain, &b_RCT_RegFGrain);
   fChain->SetBranchAddress("EmSize", &EmSize, &b_RCT_EmSize);
   fChain->SetBranchAddress("IsIsoEm", &IsIsoEm, &b_RCT_IsIsoEm);
   fChain->SetBranchAddress("EmEta", &EmEta, &b_RCT_EmEta);
   fChain->SetBranchAddress("EmPhi", &EmPhi, &b_RCT_EmPhi);
   fChain->SetBranchAddress("EmRnk", &EmRnk, &b_RCT_EmRnk);
   fChain->SetBranchAddress("EmBx", &EmBx, &b_RCT_EmBx);
   fChain->SetBranchAddress("phSize", &phSize, &b_DTTF_phSize);
   fChain->SetBranchAddress("phBx", &phBx, &b_DTTF_phBx);
   fChain->SetBranchAddress("phWh", &phWh, &b_DTTF_phWh);
   fChain->SetBranchAddress("phSe", &phSe, &b_DTTF_phSe);
   fChain->SetBranchAddress("phSt", &phSt, &b_DTTF_phSt);
   fChain->SetBranchAddress("phAng", &phAng, &b_DTTF_phAng);
   fChain->SetBranchAddress("phGlobPhi", &phGlobPhi, &b_DTTF_phGlobPhi);
   fChain->SetBranchAddress("phBandAng", &phBandAng, &b_DTTF_phBandAng);
   fChain->SetBranchAddress("phCode", &phCode, &b_DTTF_phCode);
   fChain->SetBranchAddress("phX", &phX, &b_DTTF_phX);
   fChain->SetBranchAddress("phY", &phY, &b_DTTF_phY);
   fChain->SetBranchAddress("thSize", &thSize, &b_DTTF_thSize);
   fChain->SetBranchAddress("thBx", &thBx, &b_DTTF_thBx);
   fChain->SetBranchAddress("thWh", &thWh, &b_DTTF_thWh);
   fChain->SetBranchAddress("thSe", &thSe, &b_DTTF_thSe);
   fChain->SetBranchAddress("thSt", &thSt, &b_DTTF_thSt);
   fChain->SetBranchAddress("thX", &thX, &b_DTTF_thX);
   fChain->SetBranchAddress("thY", &thY, &b_DTTF_thY);
   fChain->SetBranchAddress("thTheta", &thTheta, &b_DTTF_thTheta);
   fChain->SetBranchAddress("thCode", &thCode, &b_DTTF_thCode);
   fChain->SetBranchAddress("trSize", &trSize, &b_DTTF_trSize);
   fChain->SetBranchAddress("trBx", &trBx, &b_DTTF_trBx);
   fChain->SetBranchAddress("trTag", &trTag, &b_DTTF_trTag);
   fChain->SetBranchAddress("trQual", &trQual, &b_DTTF_trQual);
   fChain->SetBranchAddress("trPtPck", &trPtPck, &b_DTTF_trPtPck);
   fChain->SetBranchAddress("trPtVal", &trPtVal, &b_DTTF_trPtVal);
   fChain->SetBranchAddress("trPhiPck", &trPhiPck, &b_DTTF_trPhiPck);
   fChain->SetBranchAddress("trPhiVal", &trPhiVal, &b_DTTF_trPhiVal);
   fChain->SetBranchAddress("trEtaPck", &trEtaPck, &b_DTTF_trEtaPck);
   fChain->SetBranchAddress("trEtaVal", &trEtaVal, &b_DTTF_trEtaVal);
   fChain->SetBranchAddress("trPhiGlob", &trPhiGlob, &b_DTTF_trPhiGlob);
   fChain->SetBranchAddress("trChPck", &trChPck, &b_DTTF_trChPck);
   fChain->SetBranchAddress("trWh", &trWh, &b_DTTF_trWh);
   fChain->SetBranchAddress("trSc", &trSc, &b_DTTF_trSc);
   fChain->SetBranchAddress("trAddress", &trAddress, &b_DTTF_trAddress);
//    fChain->SetBranchAddress("trSize", &trSize, &b_CSCTF_trSize);
   fChain->SetBranchAddress("trEndcap", &trEndcap, &b_CSCTF_trEndcap);
   fChain->SetBranchAddress("trSector", &trSector, &b_CSCTF_trSector);
//    fChain->SetBranchAddress("trBx", &trBx, &b_CSCTF_trBx);
   fChain->SetBranchAddress("trME1ID", &trME1ID, &b_CSCTF_trME1ID);
   fChain->SetBranchAddress("trME2ID", &trME2ID, &b_CSCTF_trME2ID);
   fChain->SetBranchAddress("trME3ID", &trME3ID, &b_CSCTF_trME3ID);
   fChain->SetBranchAddress("trME4ID", &trME4ID, &b_CSCTF_trME4ID);
   fChain->SetBranchAddress("trMB1ID", &trMB1ID, &b_CSCTF_trMB1ID);
   fChain->SetBranchAddress("trME1TBin", &trME1TBin, &b_CSCTF_trME1TBin);
   fChain->SetBranchAddress("trME2TBin", &trME2TBin, &b_CSCTF_trME2TBin);
   fChain->SetBranchAddress("trME3TBin", &trME3TBin, &b_CSCTF_trME3TBin);
   fChain->SetBranchAddress("trME4TBin", &trME4TBin, &b_CSCTF_trME4TBin);
   fChain->SetBranchAddress("trMB1TBin", &trMB1TBin, &b_CSCTF_trMB1TBin);
   fChain->SetBranchAddress("trOutputLink", &trOutputLink, &b_CSCTF_trOutputLink);
   fChain->SetBranchAddress("trCharge", &trCharge, &b_CSCTF_trCharge);
   fChain->SetBranchAddress("trChargeValid", &trChargeValid, &b_CSCTF_trChargeValid);
   fChain->SetBranchAddress("trForR", &trForR, &b_CSCTF_trForR);
   fChain->SetBranchAddress("trPhi23", &trPhi23, &b_CSCTF_trPhi23);
   fChain->SetBranchAddress("trPhi12", &trPhi12, &b_CSCTF_trPhi12);
   fChain->SetBranchAddress("trPhiSign", &trPhiSign, &b_CSCTF_trPhiSign);
   fChain->SetBranchAddress("trEtaBit", &trEtaBit, &b_CSCTF_trEtaBit);
   fChain->SetBranchAddress("trPhiBit", &trPhiBit, &b_CSCTF_trPhiBit);
   fChain->SetBranchAddress("trPtBit", &trPtBit, &b_CSCTF_trPtBit);
   fChain->SetBranchAddress("trEta", &trEta, &b_CSCTF_trEta);
   fChain->SetBranchAddress("trPhi", &trPhi, &b_CSCTF_trPhi);
   fChain->SetBranchAddress("trPhi_02PI", &trPhi_02PI, &b_CSCTF_trPhi_02PI);
   fChain->SetBranchAddress("trPt", &trPt, &b_CSCTF_trPt);
   fChain->SetBranchAddress("trMode", &trMode, &b_CSCTF_trMode);
   fChain->SetBranchAddress("trQuality", &trQuality, &b_CSCTF_trQuality);
   fChain->SetBranchAddress("trNumLCTs", &trNumLCTs, &b_CSCTF_trNumLCTs);
   fChain->SetBranchAddress("trLctEndcap", &trLctEndcap, &b_CSCTF_trLctEndcap);
   fChain->SetBranchAddress("trLctSector", &trLctSector, &b_CSCTF_trLctSector);
   fChain->SetBranchAddress("trLctSubSector", &trLctSubSector, &b_CSCTF_trLctSubSector);
   fChain->SetBranchAddress("trLctBx", &trLctBx, &b_CSCTF_trLctBx);
   fChain->SetBranchAddress("trLctBx0", &trLctBx0, &b_CSCTF_trLctBx0);
   fChain->SetBranchAddress("trLctStation", &trLctStation, &b_CSCTF_trLctStation);
   fChain->SetBranchAddress("trLctRing", &trLctRing, &b_CSCTF_trLctRing);
   fChain->SetBranchAddress("trLctChamber", &trLctChamber, &b_CSCTF_trLctChamber);
   fChain->SetBranchAddress("trLctTriggerCSCID", &trLctTriggerCSCID, &b_CSCTF_trLctTriggerCSCID);
   fChain->SetBranchAddress("trLctFpga", &trLctFpga, &b_CSCTF_trLctFpga);
   fChain->SetBranchAddress("trLctlocalPhi", &trLctlocalPhi, &b_CSCTF_trLctlocalPhi);
   fChain->SetBranchAddress("trLctCLCT_pattern", &trLctCLCT_pattern, &b_CSCTF_trLctCLCT_pattern);
   fChain->SetBranchAddress("trLctQuality", &trLctQuality, &b_CSCTF_trLctQuality);
   fChain->SetBranchAddress("trLctglobalPhi", &trLctglobalPhi, &b_CSCTF_trLctglobalPhi);
   fChain->SetBranchAddress("trLctglobalEta", &trLctglobalEta, &b_CSCTF_trLctglobalEta);
   fChain->SetBranchAddress("trLctstripNum", &trLctstripNum, &b_CSCTF_trLctstripNum);
   fChain->SetBranchAddress("trLctwireGroup", &trLctwireGroup, &b_CSCTF_trLctwireGroup);
   fChain->SetBranchAddress("lctSize", &lctSize, &b_CSCTF_lctSize);
   fChain->SetBranchAddress("lctEndcap", &lctEndcap, &b_CSCTF_lctEndcap);
   fChain->SetBranchAddress("lctSector", &lctSector, &b_CSCTF_lctSector);
   fChain->SetBranchAddress("lctSubSector", &lctSubSector, &b_CSCTF_lctSubSector);
   fChain->SetBranchAddress("lctBx", &lctBx, &b_CSCTF_lctBx);
   fChain->SetBranchAddress("lctBx0", &lctBx0, &b_CSCTF_lctBx0);
   fChain->SetBranchAddress("lctStation", &lctStation, &b_CSCTF_lctStation);
   fChain->SetBranchAddress("lctRing", &lctRing, &b_CSCTF_lctRing);
   fChain->SetBranchAddress("lctChamber", &lctChamber, &b_CSCTF_lctChamber);
   fChain->SetBranchAddress("lctTriggerCSCID", &lctTriggerCSCID, &b_CSCTF_lctTriggerCSCID);
   fChain->SetBranchAddress("lctFpga", &lctFpga, &b_CSCTF_lctFpga);
   fChain->SetBranchAddress("lctlocalPhi", &lctlocalPhi, &b_CSCTF_lctlocalPhi);
   fChain->SetBranchAddress("lctCLCT_pattern", &lctCLCT_pattern, &b_CSCTF_lctCLCT_pattern);
   fChain->SetBranchAddress("lctQuality", &lctQuality, &b_CSCTF_lctQuality);
   fChain->SetBranchAddress("lctglobalPhi", &lctglobalPhi, &b_CSCTF_lctglobalPhi);
   fChain->SetBranchAddress("lctglobalEta", &lctglobalEta, &b_CSCTF_lctglobalEta);
   fChain->SetBranchAddress("lctstripNum", &lctstripNum, &b_CSCTF_lctstripNum);
   fChain->SetBranchAddress("lctwireGroup", &lctwireGroup, &b_CSCTF_lctwireGroup);
   fChain->SetBranchAddress("nsp", &nsp, &b_CSCTF_nsp);
   fChain->SetBranchAddress("stSPslot", &stSPslot, &b_CSCTF_stSPslot);
   fChain->SetBranchAddress("stL1A_BXN", &stL1A_BXN, &b_CSCTF_stL1A_BXN);
   fChain->SetBranchAddress("stTrkCounter", &stTrkCounter, &b_CSCTF_stTrkCounter);
   fChain->SetBranchAddress("stOrbCounter", &stOrbCounter, &b_CSCTF_stOrbCounter);
   fChain->SetBranchAddress("dtSize", &dtSize, &b_CSCTF_dtSize);
   fChain->SetBranchAddress("dtCAL", &dtCAL, &b_CSCTF_dtCAL);
   fChain->SetBranchAddress("dtFLAG", &dtFLAG, &b_CSCTF_dtFLAG);
   fChain->SetBranchAddress("dtBXN", &dtBXN, &b_CSCTF_dtBXN);
   fChain->SetBranchAddress("dtSector", &dtSector, &b_CSCTF_dtSector);
   fChain->SetBranchAddress("dtSubSector", &dtSubSector, &b_CSCTF_dtSubSector);
   fChain->SetBranchAddress("dtBX0", &dtBX0, &b_CSCTF_dtBX0);
   fChain->SetBranchAddress("dtPhiBend", &dtPhiBend, &b_CSCTF_dtPhiBend);
   fChain->SetBranchAddress("dtQuality", &dtQuality, &b_CSCTF_dtQuality);
   fChain->SetBranchAddress("dtPhiPacked", &dtPhiPacked, &b_CSCTF_dtPhiPacked);
   fChain->SetBranchAddress("nHCALTP", &nHCALTP, &b_CALO_nHCALTP);
   fChain->SetBranchAddress("hcalTPieta", &hcalTPieta, &b_CALO_hcalTPieta);
   fChain->SetBranchAddress("hcalTPiphi", &hcalTPiphi, &b_CALO_hcalTPiphi);
   fChain->SetBranchAddress("hcalTPCaliphi", &hcalTPCaliphi, &b_CALO_hcalTPCaliphi);
   fChain->SetBranchAddress("hcalTPet", &hcalTPet, &b_CALO_hcalTPet);
   fChain->SetBranchAddress("hcalTPcompEt", &hcalTPcompEt, &b_CALO_hcalTPcompEt);
   fChain->SetBranchAddress("hcalTPfineGrain", &hcalTPfineGrain, &b_CALO_hcalTPfineGrain);
   fChain->SetBranchAddress("nECALTP", &nECALTP, &b_CALO_nECALTP);
   fChain->SetBranchAddress("ecalTPieta", &ecalTPieta, &b_CALO_ecalTPieta);
   fChain->SetBranchAddress("ecalTPiphi", &ecalTPiphi, &b_CALO_ecalTPiphi);
   fChain->SetBranchAddress("ecalTPCaliphi", &ecalTPCaliphi, &b_CALO_ecalTPCaliphi);
   fChain->SetBranchAddress("ecalTPet", &ecalTPet, &b_CALO_ecalTPet);
   fChain->SetBranchAddress("ecalTPcompEt", &ecalTPcompEt, &b_CALO_ecalTPcompEt);
   fChain->SetBranchAddress("ecalTPfineGrain", &ecalTPfineGrain, &b_CALO_ecalTPfineGrain);
   Notify();
}

Bool_t CustomTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CustomTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CustomTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CustomTree_cxx
