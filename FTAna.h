#ifndef FTAna_h
#define FTAna_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH1.h>
#include <TH2.h>
#include <TMath.h>
#include "TLorentzVector.h"

#include <vector>
#include <fstream>
#include <iostream>
// Header file for the classes stored in the TTree if any.
using namespace std;

class FTAna : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   // This is the list of variables available to you.
   Long64_t RunNumber;
   Long64_t EventNumber;
   Long64_t LumiSection;
   Long64_t Bunch;
   Long64_t Orbit;
   Long64_t Time;
   Int_t NVertex;
   Double_t VertexX[100];
   Double_t VertexY[100];
   Double_t VertexZ[100];
   Double_t VertexXError[100];
   Double_t VertexYError[100];
   Double_t VertexZError[100];
   Int_t VertexisValid[100];
   Int_t VertexisFake[100];
   Int_t VertextracksSize[100];
   Double_t VertexnormalizedChi2[100];
   Int_t Vertexndof[100];
   Double_t Vertexrho[100];
   Double_t BeamSpotX0;
   Double_t BeamSpotY0;
   Double_t BeamSpotZ0;
   Double_t BeamSpotX0Error;
   Double_t BeamSpotY0Error;
   Double_t BeamSpotZ0Error;
   Double_t genEventInfo_weight;
   Double_t genEventInfo_qScale;
   Double_t genEventInfo_alphaQCD;
   Double_t genEventInfo_alphaQED;
   Double_t genEventInfo_nMEPartons;
   Double_t genEventInfo_nMEPartonsFiltered;
   Double_t genEventInfo_Q;
   Double_t genEventInfo_id1;
   Double_t genEventInfo_x1;
   Double_t genEventInfo_pdf1;
   Double_t genEventInfo_id2;
   Double_t genEventInfo_x2;
   Double_t genEventInfo_pdf2;
   Int_t NTracks;
   Double_t TrackIso03[500];
   Double_t TrackIso04[500];
   Double_t TrackPx[500];
   Double_t TrackPy[500];
   Double_t TrackPz[500];
   Double_t TrackPt[500]; 
   Double_t TrackPFID[500];
   Double_t TrackPtdiff[500];
   Double_t TrackEta[500];
   Double_t TrackPhi[500];
   Double_t TrackEnergy[500];
   Int_t TrackCharge[500];
   Double_t TrackDxy[500];
   Double_t TrackDz[500]; 
   Int_t TrackFromPV[500];
   Int_t TrackNhits[500];
   Double_t TrackNchi2[500];
   Int_t TrackHighpurity[500];
   Double_t Trackvertexindex[500];
   Double_t TrackPhiAtVtx[500];
   Int_t NMC;
   Double_t MCPx[1000];
   Double_t MCPy[1000];
   Double_t MCPz[1000];
   Double_t MCPt[1000];
   Int_t MCId[1000];
   Double_t MCEta[1000];
   Double_t MCPhi[1000];
   Double_t MCEnergy[1000];
   Double_t MCMass[1000];
   Double_t MCCharge[1000];
   Int_t MCIndex[1000];
   Int_t MCStatus[1000];
   Double_t MCVx[1000];
   Double_t MCVy[1000];
   Double_t MCVz[1000];
   Int_t NMCdaughter[1000];
   Int_t NMCmother[1000];
   Int_t MCMotherIndex[1000];
   Int_t NMuons;
   Double_t MuonIso03[100];
   Double_t MuonIso04[100];
   Int_t MuonIsLooseMatrix[100];
   Int_t MuonIsTightMatrix[100];
   Int_t MuonIsLooseMatrixWoPromptHLT[100];
   Int_t MuonIsTightMatrixWoPromptHLT[100];
   Int_t MuonIsPrompt[100];
   Int_t MuonIsHLT[100];
   Double_t MuonPx[100];
   Double_t MuonPy[100];
   Double_t MuonPz[100];
   Double_t MuonPt[100];
   Double_t MuonEta[100];
   Double_t MuonPhi[100];
   Double_t MuonEnergy[100];
   Double_t MuonTrackIso[100];
   Double_t MuonEcalIso[100];
   Double_t MuonHcalIso[100];
   Double_t MuonCaloIso[100];
   Double_t MuonChargedHadronMiniIso[100];
   Double_t MuonNeutralHadronMiniIso[100];
   Double_t MuonPhotonMiniIso[100];
   Double_t MuonBetaMiniIso[100];
   Double_t MuonMiniIsoCone[100];
   Double_t MuonPtRelv1[100];
   Double_t MuonPtRatiov1[100];
   Double_t MuonPtRel[100];
   Double_t MuonPtRatio[100];
   Int_t MuonHasInnerTrack[100];
   Double_t MuonInnerTrackPt[100];
   Double_t MuonInnerTrackEta[100];
   Double_t MuonInnerTrackPhi[100];
   Double_t MuonInnerTrackCharge[100];
   Double_t MuonOuterTrackPt[100];
   Double_t MuonOuterTrackEta[100];
   Double_t MuonOuterTrackPhi[100];
   Double_t MuonOuterTrackCharge[100];
   Int_t MuonHasOuterTrack[100];
   Double_t MuonDxy[100];
   Double_t MuonDz[100]; 
   Int_t MuonCharge[100];
   Int_t MuonNhits[100]; 
   Double_t MuonNchi2[100]; 
   Int_t MuonNhitsMuon[100];
   Int_t MuonTrackerlayerwithmeasurement[100];
   Int_t MuonPixelhits[100];
   Double_t MuonValidfraction[100];
   Int_t MuonNchambers[100];
   Int_t MuonLMT[100]; 
   Int_t MuonisSH[100];
   Int_t MuonNumberOfMatches[100];
   Int_t MuonNumberOfMatchedStations[100];
   Int_t MuonisGlobal[100];
   Int_t MuonisTracker[100];
   Int_t MuonisStandAloneMuon[100];
   Int_t MuonisCalo[100];
   Int_t MuonisPF[100]; 
   Int_t MuonisRPC[100];
   Double_t MuonpfIsolationR03sumChargedHadronPt[100];
   Double_t MuonpfIsolationR03sumChargedParticlePt[100];
   Double_t MuonpfIsolationR03sumNeutralHadronEt[100];
   Double_t MuonpfIsolationR03sumPhotonEt[100];
   Double_t MuonpfIsolationR03sumPhotonEtHighThreshold[100];
   Double_t MuonpfIsolationR03sumNeutralHadronEtHighThreshold[100];
   Double_t MuonpfIsolationR03sumPUPt[100];
   Double_t MuonpfIsolationR04sumPhotonEtHighThreshold[100];
   Double_t MuonpfIsolationR04sumChargedHadronPt[100];
   Double_t MuonpfIsolationR04sumChargedParticlePt[100];
   Double_t MuonpfIsolationR04sumNeutralHadronEt[100]; 
   Double_t MuonpfIsolationR04sumPhotonEt[100];
   Double_t MuonpfIsolationR04sumNeutralHadronEtHighThreshold[100];
   Double_t MuonpfIsolationR04sumPUPt[100];
   Double_t MuontrkKink[100];
   Double_t Muonchi2LocalPosition[100];
   Double_t MuonsegmentCompatibility[100];
   Double_t MuondbPV3D[100]; 
   Double_t MuonedbPV3D[100];
   Double_t MuonsigPV3D[100];
   Double_t MuondbPV2D[100]; 
   Double_t MuonedbPV2D[100];
   Double_t MuonsigPV2D[100];
   Double_t MuondbBS2D[100];
   Double_t MuonedbBS2D[100];
   Double_t MuonsigBS2D[100];
   Double_t MuondbBS3D[100]; 
   Double_t MuonedbBS3D[100];
   Double_t MuonsigBS3D[100];
   Int_t NEle27;
   Int_t NMu24;
   Double_t IsoMu24ORIsoTkMu24Pt[50];
   Double_t IsoMu24ORIsoTkMu24Eta[50];
   Double_t IsoMu24ORIsoTkMu24Phi[50];
   Double_t Ele27WPLooseGsfPt[50];
   Double_t Ele27WPLooseGsfEta[50];
   Double_t Ele27WPLooseGsfPhi[50];
   Int_t NElectrons;
   Double_t ElectronIso03[100];
   Double_t ElectronIso04[100];
   Int_t ElectronIsCustomHLT[100];
   Int_t ElectronIsLooseMatrix[100];
   Int_t ElectronIsTightMatrix[100];
   Int_t ElectronIsLooseMatrixWoPromptHLT[100];
   Int_t ElectronIsTightMatrixWoPromptHLT[100];
   Int_t ElectronIsPrompt[100];
   Int_t ElectronIsHLT[100];
   Int_t ElectronCutVLMT[100];
   Double_t ElectronPx[100];
   Double_t ElectronPy[100];
   Double_t ElectronPz[100];
   Double_t ElectronPt[100];
   Double_t ElectronEta[100];
   Double_t ElectronPhi[100];
   Double_t ElectronEnergy[100];
   Double_t ElectronTrackIso[100];
   Double_t ElectronEcalIso[100];
   Double_t ElectronHcalIso[100];
   Double_t ElectronCaloIso[100];
   Double_t ElectronChargedHadronMiniIso[100];
   Double_t ElectronNeutralHadronMiniIso[100];
   Double_t ElectronPhotonMiniIso[100];
   Double_t ElectronBetaMiniIso[100];
   Double_t ElectronMiniIsoCone[100];
   Double_t ElectronPtRelv1[100];
   Double_t ElectronPtRatiov1[100];
   Double_t ElectronPtRel[100];
   Double_t ElectronPtRatio[100];
   Double_t ElectronDxy[100];
   Double_t ElectronDz[100];
   Double_t ElectronCharge[100];
   Double_t ElectronsuperClustereta[100];
   Double_t ElectronPFIsolation[100];
   Int_t ElectronpassConversionVeto[100];
   Int_t ElectronnumberOfLostHits[100];
   Double_t ElectronsigmaIetaIeta[100];
   Double_t Electronfull5x5_sigmaIetaIeta[100];
   Int_t ElectronnumberOfHits[100];
   Int_t ElectronisPF[100];
   Double_t ElectronsigmaIetaIphi[100];
   Double_t Electronfull5x5_sigmaIetaIphi[100];
   Double_t Electronip3d[100];
   Double_t ElectrondbPV3D[100];
   Double_t ElectronedbPV3D[100];
   Double_t ElectronsigPV3D[100];
   Double_t ElectrondbPV2D[100];
   Double_t ElectronedbPV2D[100];
   Double_t ElectronsigPV2D[100];
   Double_t ElectrondbBS2D[100];
   Double_t ElectronedbBS2D[100];
   Double_t ElectronsigBS2D[100];
   Double_t ElectrondbBS3D[100];
   Double_t ElectronedbBS3D[100];
   Double_t ElectronsigBS3D[100];
   Double_t ElectronscPixCharge[100];
   Int_t ElectronisGsfCtfScPixChargeConsistent[100];
   Int_t ElectronisGsfScPixChargeConsistent[100];
   Int_t ElectronisGsfCtfChargeConsistent[100];
   Double_t ElectronhcalOverEcal[100];
   Double_t ElectronhadronicOverEm[100];
   Double_t Electronmva_Isolated[100];
   Double_t Electronmva_e_pi[100];
   Double_t ElectronsumChargedHadronPt[100];
   Double_t ElectronsumNeutralHadronEt[100];
   Double_t ElectronsumPhotonEt[100];
   Double_t ElectronsumChargedParticlePt[100];
   Double_t ElectronsumNeutralHadronEtHighThreshold[100];
   Double_t ElectronsumPhotonEtHighThreshold[100];
   Double_t ElectronsumPUPt[100];
   Double_t ElectrondeltaEtaSuperClusterTrackAtVtx[100];
   Double_t ElectrondeltaEtaSeedClusterTrackAtCalo[100];
   Double_t ElectrondeltaEtaEleClusterTrackAtCalo[100];
   Double_t ElectrondeltaPhiSuperClusterTrackAtVtx[100];
   Double_t ElectrondeltaPhiSeedClusterTrackAtCalo[100];
   Double_t ElectrondeltaPhiEleClusterTrackAtCalo[100];
   Int_t ElectroneidLoose[100];
   Int_t ElectroneidRobustLoose[100];
   Int_t ElectroneidTight[100];
   Int_t ElectroneidRobustTight[100];
   Int_t ElectroneidRobustHighEnergy[100];
   Double_t ElectronecalEnergy[100];
   Double_t Electronp_in[100];
   Double_t Electron1oEm1oP[100];
   Double_t Electron1oEm1oPcorrected[100];
   Double_t ElectronEcalPFClusterIso[100];
   Double_t ElectronHcalPFClusterIso[100];
   Bool_t ElectronIsMedium[100];
   Bool_t ElectronIsTrigger[100];
   Double_t ElectronFbrem[100];
   Double_t ElectronEoverP[100];
   Int_t NTaus;
   Double_t TauPx[100];
   Double_t TauPy[100];
   Double_t TauPz[100];
   Double_t TauPt[100];
   Double_t TauEta[100];
   Double_t TauPhi[100];
   Double_t TauEnergy[100];
   Int_t TauDecayMode[100];
   Double_t TauChargedHadronMiniIso[100];
   Double_t TauNeutralHadronMiniIso[100];
   Double_t TauPhotonMiniIso[100];
   Double_t TauBetaMiniIso[100];
   Double_t TauMiniIsoCone[100];
   Double_t TauPtRelv1[100];
   Double_t TauPtRatiov1[100];
   Double_t TauPtRel[100];
   Double_t TauPtRatio[100];
   Double_t TauCharge[100];
   Int_t TauisPF[100];
   Double_t TauDz[100];
   Double_t TauleadChargedHadrCandvx[100];
   Double_t TauleadChargedHadrCandvy[100];
   Double_t TauleadChargedHadrCandvz[100];
   Double_t TauleadChargedHadrCandpt[100];
   Int_t TauagainstElectronMVA6category[100];
   Int_t TaubyCombinedIsolationDeltaBetaCorrRaw3Hits[100];
   Double_t TaudecayModeFindingOldDMs[100];
   Double_t TaudecayModeFindingNewDMs[100];
   Double_t TaubyLooseCombinedIsolationDeltaBetaCorr3Hits[100];
   Double_t TaubyMediumCombinedIsolationDeltaBetaCorr3Hits[100];
   Double_t TaubyTightCombinedIsolationDeltaBetaCorr3Hits[100];
   Double_t TaubyVLooseIsolationMVArun2v1DBoldDMwLT[100];
   Double_t TaubyLooseIsolationMVArun2v1DBoldDMwLT[100];
   Double_t TaubyMediumIsolationMVArun2v1DBoldDMwLT[100];
   Double_t TaubyTightIsolationMVArun2v1DBoldDMwLT[100];
   Double_t TaubyVTightIsolationMVArun2v1DBoldDMwLT[100];
   Double_t TaubyVLooseIsolationMVArun2v1DBnewDMwLT[100];
   Double_t TaubyLooseIsolationMVArun2v1DBnewDMwLT[100];
   Double_t TaubyMediumIsolationMVArun2v1DBnewDMwLT[100];
   Double_t TaubyTightIsolationMVArun2v1DBnewDMwLT[100];
   Double_t TaubyVTightIsolationMVArun2v1DBnewDMwLT[100];
   Double_t TauagainstMuonLoose3[100];
   Double_t TauagainstMuonTight3[100];
   Double_t TauagainstElectronVLooseMVA6[100];
   Double_t TauagainstElectronLooseMVA6[100];
   Double_t TauagainstElectronMediumMVA6[100];
   Double_t TauagainstElectronTightMVA6[100];
   Double_t TauagainstElectronVTightMVA6[100];
   Double_t TaubyVLooseIsolationMVArun2v1DBdR03oldDMwLT[100];
   Double_t TaubyLooseIsolationMVArun2v1DBdR03oldDMwLT[100];
   Double_t TaubyMediumIsolationMVArun2v1DBdR03oldDMwLT[100];
   Double_t TaubyTightIsolationMVArun2v1DBdR03oldDMwLT[100];
   Double_t TaubyVTightIsolationMVArun2v1DBdR03oldDMwLT[100];
   Int_t NPhotons;
   Double_t PhotonPx[100];
   Double_t PhotonPy[100];
   Double_t PhotonPz[100];
   Double_t PhotonPt[100];
   Double_t PhotonEta[100];
   Double_t PhotonPhi[100];
   Double_t PhotonEnergy[100];
   Double_t PhotonTrackIso[100];
   Double_t PhotonEcalIso[100];
   Double_t PhotonHcalIso[100];
   Double_t PhotonCaloIso[100];
   Double_t PhotonParticleIso[100];
   Double_t PhotonChargedHadronIso[100];
   Double_t PhotonNeutralHadronIso[100];
   Double_t PhotonIso[100];
   Double_t PhotonHadronicOverEm[100];
   Double_t PhotonSigmaEtaEta[100];
   Double_t PhotonSigmaIetaIeta[100];
   Double_t PhotonE3x3[100];
   Double_t PhotonE5x5[100];
   Double_t PhotonR9[100];
   Double_t PhotonSuperClustereta[100];
   Int_t PhotonLMT[100];
   Int_t PhotonPassElVeto[100];
   Int_t NJets;
   Double_t JetPx[100];
   Double_t JetPy[100];
   Double_t JetPz[100];
   Double_t JetPt[100];
   Double_t JetEta[100];
   Double_t JetPhi[100];
   Double_t JetEnergy[100];
   Double_t JetEmEnergy[100];
   Double_t JetHadronEnergy[100];
   Double_t JetCSV[100];
   Double_t JetpfCombinedMVAV2BJetTags[100];
   Double_t JetpfJetProbabilityBJetTags[100];
   Double_t JethadronFlavour[100];
   Int_t NGenJets[100];
   Double_t GenJetPx[100];
   Double_t GenJetPy[100];
   Double_t GenJetPz[100];
   Double_t GenJetPt[100];
   Double_t GenJetEta[100];
   Double_t GenJetPhi[100];
   Double_t GenJetEnergy[100];
   Double_t METPt;
   Double_t METPhi;
   Double_t MET2Pt;
   Double_t MET2Phi;
   Int_t HLT_Mu50;
   Int_t HLT_IsoMu20;
   Int_t HLT_IsoTkMu18;
   Int_t HLT_IsoMu22;
   Int_t HLT_IsoTkMu22;
   Int_t HLT_IsoMu24;
   Int_t HLT_IsoTkMu24;
   Int_t HLT_IsoMu27;
   Int_t HLT_IsoTkMu27;
   Int_t HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
   Int_t HLT_IsoMu19_eta2p1_LooseIsoPFTau20;
   Int_t HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
   Int_t HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
   Int_t HLT_TripleMu_12_10_5;
   Int_t HLT_Mu17_Mu8_SameSign_DZ;
   Int_t HLT_Mu20_Mu10_SameSign_DZ;
   Int_t HLT_Photon175;
   Int_t HLT_Photon120;
   Int_t HLT_Photon90;
   Int_t HLT_Photon75;
   Int_t HLT_Photon50;
   Int_t HLT_Photon30;

   Int_t NTowers;
   Double_t TowerEta[5000];
   Double_t TowerPhi[5000];
   Double_t TowerEnergy[5000];
   Double_t TowerEmEnergy[5000];
   //   math::PtEtaPhiMLorentzVector TowerVector[5000];   
   //List of branches
   TBranch *b_RunNumber;
   TBranch *b_EventNumber;
   TBranch *b_LumiSection;
   TBranch *b_Bunch;
   TBranch *b_Orbit;
   TBranch *b_Time;
   TBranch *b_NVertex;
   TBranch *b_VertexX;
   TBranch *b_VertexY;
   TBranch *b_VertexZ;
   TBranch *b_VertexXError;
   TBranch *b_VertexYError;
   TBranch *b_VertexZError;
   TBranch *b_VertexisValid;
   TBranch *b_VertexisFake;
   TBranch *b_VertextracksSize;
   TBranch *b_VertexnormalizedChi2;
   TBranch *b_Vertexndof;
   TBranch *b_Vertexrho;
   TBranch *b_BeamSpotX0;
   TBranch *b_BeamSpotY0;
   TBranch *b_BeamSpotZ0;
   TBranch *b_BeamSpotX0Error;
   TBranch *b_BeamSpotY0Error;
   TBranch *b_BeamSpotZ0Error;
   TBranch *b_genEventInfo_weight;
   TBranch *b_genEventInfo_qScale;
   TBranch *b_genEventInfo_alphaQCD;
   TBranch *b_genEventInfo_alphaQED;
   TBranch *b_genEventInfo_nMEPartons;
   TBranch *b_genEventInfo_nMEPartonsFiltered;
   TBranch *b_genEventInfo_Q;
   TBranch *b_genEventInfo_id1;
   TBranch *b_genEventInfo_x1;
   TBranch *b_genEventInfo_pdf1;
   TBranch *b_genEventInfo_id2;
   TBranch *b_genEventInfo_x2;
   TBranch *b_genEventInfo_pdf2;
   TBranch *b_NTracks;
   TBranch *b_TrackIso03;
   TBranch *b_TrackIso04;
   TBranch *b_TrackPx;
   TBranch *b_TrackPy;
   TBranch *b_TrackPz;
   TBranch *b_TrackPt;
   TBranch *b_TrackPFID;
   TBranch *b_TrackPtdiff;
   TBranch *b_TrackEta;
   TBranch *b_TrackPhi;
   TBranch *b_TrackEnergy;
   TBranch *b_TrackCharge;
   TBranch *b_TrackDxy;
   TBranch *b_TrackDz;
   TBranch *b_TrackFromPV;
   TBranch *b_TrackNhits;
   TBranch *b_TrackNchi2;
   TBranch *b_TrackHighpurity;
   TBranch *b_Trackvertexindex;
   TBranch *b_TrackPhiAtVtx;
   TBranch *b_NMC;
   TBranch *b_MCPx;
   TBranch *b_MCPy;
   TBranch *b_MCPz;
   TBranch *b_MCPt;
   TBranch *b_MCId;
   TBranch *b_MCEta;
   TBranch *b_MCPhi;
   TBranch *b_MCEnergy;
   TBranch *b_MCMass;
   TBranch *b_MCCharge;
   TBranch *b_MCIndex;
   TBranch *b_MCStatus;
   TBranch *b_MCVx;
   TBranch *b_MCVy;
   TBranch *b_MCVz;
   TBranch *b_NMCdaughter;
   TBranch *b_NMCmother;
   TBranch *b_MCMotherIndex;
   TBranch *b_NMuons;
   TBranch *b_MuonIso03;
   TBranch *b_MuonIso04;
   TBranch *b_MuonIsLooseMatrix;
   TBranch *b_MuonIsTightMatrix;
   TBranch *b_MuonIsLooseMatrixWoPromptHLT;
   TBranch *b_MuonIsTightMatrixWoPromptHLT;
   TBranch *b_MuonIsPrompt;
   TBranch *b_MuonIsHLT;
   TBranch *b_MuonPx;
   TBranch *b_MuonPy;
   TBranch *b_MuonPz;
   TBranch *b_MuonPt;
   TBranch *b_MuonEta;
   TBranch *b_MuonPhi;
   TBranch *b_MuonEnergy;
   TBranch *b_MuonTrackIso;
   TBranch *b_MuonEcalIso;
   TBranch *b_MuonHcalIso;
   TBranch *b_MuonCaloIso;
   TBranch *b_MuonChargedHadronMiniIso;
   TBranch *b_MuonNeutralHadronMiniIso;
   TBranch *b_MuonPhotonMiniIso;
   TBranch *b_MuonBetaMiniIso;
   TBranch *b_MuonMiniIsoCone;
   TBranch *b_MuonPtRelv1;
   TBranch *b_MuonPtRatiov1;
   TBranch *b_MuonPtRel;
   TBranch *b_MuonPtRatio;
   TBranch *b_MuonHasInnerTrack;
   TBranch *b_MuonInnerTrackPt;
   TBranch *b_MuonInnerTrackEta;
   TBranch *b_MuonInnerTrackPhi;
   TBranch *b_MuonInnerTrackCharge;
   TBranch *b_MuonOuterTrackPt;
   TBranch *b_MuonOuterTrackEta;
   TBranch *b_MuonOuterTrackPhi;
   TBranch *b_MuonOuterTrackCharge;
   TBranch *b_MuonHasOuterTrack;
   TBranch *b_MuonDxy;
   TBranch *b_MuonDz;
   TBranch *b_MuonCharge;
   TBranch *b_MuonNhits;
   TBranch *b_MuonNchi2;
   TBranch *b_MuonNhitsMuon;
   TBranch *b_MuonTrackerlayerwithmeasurement;
   TBranch *b_MuonPixelhits;
   TBranch *b_MuonValidfraction;
   TBranch *b_MuonNchambers;
   TBranch *b_MuonLMT;
   TBranch *b_MuonisSH;
   TBranch *b_MuonNumberOfMatches;
   TBranch *b_MuonNumberOfMatchedStations;
   TBranch *b_MuonisGlobal;
   TBranch *b_MuonisTracker;
   TBranch *b_MuonisStandAloneMuon;
   TBranch *b_MuonisCalo;
   TBranch *b_MuonisPF;
   TBranch *b_MuonisRPC;
   TBranch *b_MuonpfIsolationR03sumChargedHadronPt;
   TBranch *b_MuonpfIsolationR03sumChargedParticlePt;
   TBranch *b_MuonpfIsolationR03sumNeutralHadronEt;
   TBranch *b_MuonpfIsolationR03sumPhotonEt;
   TBranch *b_MuonpfIsolationR03sumPhotonEtHighThreshold;
   TBranch *b_MuonpfIsolationR03sumNeutralHadronEtHighThreshold;
   TBranch *b_MuonpfIsolationR03sumPUPt;
   TBranch *b_MuonpfIsolationR04sumPhotonEtHighThreshold;
   TBranch *b_MuonpfIsolationR04sumChargedHadronPt;
   TBranch *b_MuonpfIsolationR04sumChargedParticlePt;
   TBranch *b_MuonpfIsolationR04sumNeutralHadronEt;
   TBranch *b_MuonpfIsolationR04sumPhotonEt;
   TBranch *b_MuonpfIsolationR04sumNeutralHadronEtHighThreshold;
   TBranch *b_MuonpfIsolationR04sumPUPt;
   TBranch *b_MuontrkKink;
   TBranch *b_Muonchi2LocalPosition;
   TBranch *b_MuonsegmentCompatibility;
   TBranch *b_MuondbPV3D;
   TBranch *b_MuonedbPV3D;
   TBranch *b_MuonsigPV3D;
   TBranch *b_MuondbPV2D;
   TBranch *b_MuonedbPV2D;
   TBranch *b_MuonsigPV2D;
   TBranch *b_MuondbBS2D;
   TBranch *b_MuonedbBS2D;
   TBranch *b_MuonsigBS2D;
   TBranch *b_MuondbBS3D;
   TBranch *b_MuonedbBS3D;
   TBranch *b_MuonsigBS3D;
   TBranch *b_NEle27;
   TBranch *b_NMu24;
   TBranch *b_IsoMu24ORIsoTkMu24Pt;
   TBranch *b_IsoMu24ORIsoTkMu24Eta;
   TBranch *b_IsoMu24ORIsoTkMu24Phi;
   TBranch *b_Ele27WPLooseGsfPt;
   TBranch *b_Ele27WPLooseGsfEta;
   TBranch *b_Ele27WPLooseGsfPhi;
   TBranch *b_NElectrons;
   TBranch *b_ElectronIso03;
   TBranch *b_ElectronIso04;
   TBranch *b_ElectronIsCustomHLT;
   TBranch *b_ElectronIsLooseMatrix;
   TBranch *b_ElectronIsTightMatrix;
   TBranch *b_ElectronIsLooseMatrixWoPromptHLT;
   TBranch *b_ElectronIsTightMatrixWoPromptHLT;
   TBranch *b_ElectronIsPrompt;
   TBranch *b_ElectronIsHLT;
   TBranch *b_ElectronCutVLMT;
   TBranch *b_ElectronPx;
   TBranch *b_ElectronPy;
   TBranch *b_ElectronPz;
   TBranch *b_ElectronPt;
   TBranch *b_ElectronEta;
   TBranch *b_ElectronPhi;
   TBranch *b_ElectronEnergy;
   TBranch *b_ElectronTrackIso;
   TBranch *b_ElectronEcalIso;
   TBranch *b_ElectronHcalIso;
   TBranch *b_ElectronCaloIso;
   TBranch *b_ElectronChargedHadronMiniIso;
   TBranch *b_ElectronNeutralHadronMiniIso;
   TBranch *b_ElectronPhotonMiniIso;
   TBranch *b_ElectronBetaMiniIso;
   TBranch *b_ElectronMiniIsoCone;
   TBranch *b_ElectronPtRelv1;
   TBranch *b_ElectronPtRatiov1;
   TBranch *b_ElectronPtRel;
   TBranch *b_ElectronPtRatio;
   TBranch *b_ElectronDxy;
   TBranch *b_ElectronDz;
   TBranch *b_ElectronCharge;
   TBranch *b_ElectronsuperClustereta;
   TBranch *b_ElectronpassConversionVeto;
   TBranch *b_ElectronnumberOfLostHits;
   TBranch *b_ElectronsigmaIetaIeta;
   TBranch *b_Electronfull5x5_sigmaIetaIeta;
   TBranch *b_ElectronnumberOfHits;
   TBranch *b_ElectronisPF;
   TBranch *b_ElectronsigmaIetaIphi;
   TBranch *b_Electronfull5x5_sigmaIetaIphi;
   TBranch *b_Electronip3d;
   TBranch *b_ElectrondbPV3D;
   TBranch *b_ElectronedbPV3D;
   TBranch *b_ElectronsigPV3D;
   TBranch *b_ElectrondbPV2D;
   TBranch *b_ElectronedbPV2D;
   TBranch *b_ElectronsigPV2D;
   TBranch *b_ElectrondbBS2D;
   TBranch *b_ElectronedbBS2D;
   TBranch *b_ElectronsigBS2D;
   TBranch *b_ElectrondbBS3D;
   TBranch *b_ElectronedbBS3D;
   TBranch *b_ElectronsigBS3D;
   TBranch *b_ElectronscPixCharge;
   TBranch *b_ElectronisGsfCtfScPixChargeConsistent;
   TBranch *b_ElectronisGsfScPixChargeConsistent;
   TBranch *b_ElectronisGsfCtfChargeConsistent;
   TBranch *b_ElectronhcalOverEcal;
   TBranch *b_ElectronhadronicOverEm;
   TBranch *b_Electronmva_Isolated;
   TBranch *b_Electronmva_e_pi;
   TBranch *b_ElectronsumChargedHadronPt;
   TBranch *b_ElectronsumNeutralHadronEt;
   TBranch *b_ElectronsumPhotonEt;
   TBranch *b_ElectronsumChargedParticlePt;
   TBranch *b_ElectronsumNeutralHadronEtHighThreshold;
   TBranch *b_ElectronsumPhotonEtHighThreshold;
   TBranch *b_ElectronsumPUPt;
   TBranch *b_ElectrondeltaEtaSuperClusterTrackAtVtx;
   TBranch *b_ElectrondeltaEtaSeedClusterTrackAtCalo;
   TBranch *b_ElectrondeltaEtaEleClusterTrackAtCalo;
   TBranch *b_ElectrondeltaPhiSuperClusterTrackAtVtx;
   TBranch *b_ElectrondeltaPhiSeedClusterTrackAtCalo;
   TBranch *b_ElectrondeltaPhiEleClusterTrackAtCalo;
   TBranch *b_ElectroneidLoose;
   TBranch *b_ElectroneidRobustLoose;
   TBranch *b_ElectroneidTight;
   TBranch *b_ElectroneidRobustTight;
   TBranch *b_ElectroneidRobustHighEnergy;
   TBranch *b_ElectronecalEnergy;
   TBranch *b_Electronp_in;
   TBranch *b_Electron1oEm1oP;
   TBranch *b_Electron1oEm1oPcorrected;
   TBranch *b_ElectronEcalPFClusterIso;
   TBranch *b_ElectronHcalPFClusterIso;
   TBranch *b_ElectronIsMedium;
   TBranch *b_ElectronIsTrigger;
   TBranch *b_ElectronPFIsolation;
   TBranch *b_ElectronFbrem;
   TBranch *b_ElectronEoverP;
   TBranch *b_NTaus;
   TBranch *b_TauPx;
   TBranch *b_TauPy;
   TBranch *b_TauPz;
   TBranch *b_TauPt;
   TBranch *b_TauEta;
   TBranch *b_TauPhi;
   TBranch *b_TauEnergy;
   TBranch *b_TauDecayMode;
   TBranch *b_TauChargedHadronMiniIso;
   TBranch *b_TauNeutralHadronMiniIso;
   TBranch *b_TauPhotonMiniIso;
   TBranch *b_TauBetaMiniIso;
   TBranch *b_TauMiniIsoCone;
   TBranch *b_TauPtRelv1;
   TBranch *b_TauPtRatiov1;
   TBranch *b_TauPtRel;
   TBranch *b_TauPtRatio;
   TBranch *b_TauCharge;
   TBranch *b_TauisPF;
   TBranch *b_TauDz;
   TBranch *b_TauleadChargedHadrCandvx;
   TBranch *b_TauleadChargedHadrCandvy;
   TBranch *b_TauleadChargedHadrCandvz;
   TBranch *b_TauleadChargedHadrCandpt;
   TBranch *b_TauagainstElectronMVA6category;
   TBranch *b_TaubyCombinedIsolationDeltaBetaCorrRaw3Hits;
   TBranch *b_TaudecayModeFindingOldDMs;
   TBranch *b_TaudecayModeFindingNewDMs;
   TBranch *b_TaubyLooseCombinedIsolationDeltaBetaCorr3Hits;
   TBranch *b_TaubyMediumCombinedIsolationDeltaBetaCorr3Hits;
   TBranch *b_TaubyTightCombinedIsolationDeltaBetaCorr3Hits;
   TBranch *b_TaubyVLooseIsolationMVArun2v1DBoldDMwLT;
   TBranch *b_TaubyLooseIsolationMVArun2v1DBoldDMwLT;
   TBranch *b_TaubyMediumIsolationMVArun2v1DBoldDMwLT;
   TBranch *b_TaubyTightIsolationMVArun2v1DBoldDMwLT;
   TBranch *b_TaubyVTightIsolationMVArun2v1DBoldDMwLT;
   TBranch *b_TaubyVLooseIsolationMVArun2v1DBnewDMwLT;
   TBranch *b_TaubyLooseIsolationMVArun2v1DBnewDMwLT;
   TBranch *b_TaubyMediumIsolationMVArun2v1DBnewDMwLT;
   TBranch *b_TaubyTightIsolationMVArun2v1DBnewDMwLT;
   TBranch *b_TaubyVTightIsolationMVArun2v1DBnewDMwLT;
   TBranch *b_TauagainstMuonLoose3;
   TBranch *b_TauagainstMuonTight3;
   TBranch *b_TauagainstElectronVLooseMVA6;
   TBranch *b_TauagainstElectronLooseMVA6;
   TBranch *b_TauagainstElectronMediumMVA6;
   TBranch *b_TauagainstElectronTightMVA6;
   TBranch *b_TauagainstElectronVTightMVA6;
   TBranch *b_TaubyVLooseIsolationMVArun2v1DBdR03oldDMwLT;
   TBranch *b_TaubyLooseIsolationMVArun2v1DBdR03oldDMwLT;
   TBranch *b_TaubyMediumIsolationMVArun2v1DBdR03oldDMwLT;
   TBranch *b_TaubyTightIsolationMVArun2v1DBdR03oldDMwLT;
   TBranch *b_TaubyVTightIsolationMVArun2v1DBdR03oldDMwLT;
   TBranch *b_NPhotons;
   TBranch *b_PhotonPx;
   TBranch *b_PhotonPy;
   TBranch *b_PhotonPz;
   TBranch *b_PhotonPt;
   TBranch *b_PhotonEta;
   TBranch *b_PhotonPhi;
   TBranch *b_PhotonEnergy;
   TBranch *b_PhotonTrackIso;
   TBranch *b_PhotonEcalIso;
   TBranch *b_PhotonHcalIso;
   TBranch *b_PhotonCaloIso;
   TBranch *b_PhotonParticleIso;
   TBranch *b_PhotonChargedHadronIso;
   TBranch *b_PhotonNeutralHadronIso;
   TBranch *b_PhotonIso;
   TBranch *b_PhotonHadronicOverEm;
   TBranch *b_PhotonSigmaEtaEta;
   TBranch *b_PhotonSigmaIetaIeta;
   TBranch *b_PhotonE3x3;
   TBranch *b_PhotonE5x5;
   TBranch *b_PhotonR9;
   TBranch *b_PhotonSuperClustereta;
   TBranch *b_PhotonLMT;
   TBranch *b_PhotonPassElVeto;
   TBranch *b_NJets;
   TBranch *b_JetPx;
   TBranch *b_JetPy;
   TBranch *b_JetPz;
   TBranch *b_JetPt;
   TBranch *b_JetEta;
   TBranch *b_JetPhi;
   TBranch *b_JetEnergy;
   TBranch *b_JetEmEnergy;
   TBranch *b_JetHadronEnergy;
   TBranch *b_JetCSV;
   TBranch *b_JetpfCombinedMVAV2BJetTags;
   TBranch *b_JetpfJetProbabilityBJetTags;
   TBranch *b_JethadronFlavour;
   TBranch *b_NGenJets;
   TBranch *b_GenJetPx;
   TBranch *b_GenJetPy;
   TBranch *b_GenJetPz;
   TBranch *b_GenJetPt;
   TBranch *b_GenJetEta;
   TBranch *b_GenJetPhi;
   TBranch *b_GenJetEnergy;
   TBranch *b_METPt;
   TBranch *b_METPhi;
   TBranch *b_MET2Pt;
   TBranch *b_MET2Phi;
   TBranch *b_HLT_Mu50;
   TBranch *b_HLT_IsoMu20;
   TBranch *b_HLT_IsoTkMu18;
   TBranch *b_HLT_IsoMu22;
   TBranch *b_HLT_IsoTkMu22;
   TBranch *b_HLT_IsoMu24;
   TBranch *b_HLT_IsoTkMu24;
   TBranch *b_HLT_IsoMu27;
   TBranch *b_HLT_IsoTkMu27;
   TBranch *b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
   TBranch *b_HLT_IsoMu19_eta2p1_LooseIsoPFTau20;
   TBranch *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
   TBranch *b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
   TBranch *b_HLT_TripleMu_12_10_5;
   TBranch *b_HLT_Mu17_Mu8_SameSign_DZ;
   TBranch *b_HLT_Mu20_Mu10_SameSign_DZ;
   TBranch *b_HLT_Photon175;
   TBranch *b_HLT_Photon120;
   TBranch *b_HLT_Photon90;
   TBranch *b_HLT_Photon75;
   TBranch *b_HLT_Photon50;
   TBranch *b_HLT_Photon30;
   TBranch *b_NTowers;
   TBranch *b_TowerEta;
   TBranch *b_TowerPhi;
   TBranch *b_TowerEnergy;
   TBranch *b_TowerEmEnergy;
   
   FTAna(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~FTAna() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   //User added functions
   //You add functions here
   int ReadLimited(int level, Long64_t entry); //This is an important function.
   void SetHstFileName(const char *HstFileName){ _HstFileName = HstFileName;}
   void SetSumFileName(const char *SumFileName){ _SumFileName = SumFileName;}
   void SetSample(int sample){_sample=sample;}
   void SetVerbose(int verbose){ _verbosity = verbose; }
   void SetData(int data){_data=data;}
   void BookHistograms();
   void Sort(int opt);
   double deltaR(double deltaeta,double deltaphi);
   bool pass_electron_cuts(int level, int i, TLorentzVector v);
   //bool pass_electron_cuts(int level, int i, TLorentzVector v);
   //bool pass_tau_cuts(int level, int i, TLorentzVector v); 
   //bool pass_jet_cuts(int level, int i, TLorentzVector v);
   //bool pass_photon_cuts(int level, int i, TLorentzVector v);
   double delta_phi(float phi1, float phi2);
   int electron_candidate_index(double ef_leading,double ef_subleading);
   bool ElectronIsTight(int index);
   bool ElectronIsLoose(int index);
 public:
   struct Hists {
     //Declare the histograms you want in here.
     TH1F *ngoodele[6],*ptlep[6];
     TH1F *etmiss;
     TH1F *mass;
     TH2F *plots[30001];
     TH1F *deltaR[3],*delta_eta,*delta_phi,*dpt;
     TH1F *bin[3];
     TH1F *ef[4];
     TH1F *cuts[2];
     TH1F *motherid[6];
     TH1F *index[2];
     TH1F *pfiso[12];
     TH2F *iso[4];
     TH1F *eta;
     TH2F *img;
   };
   struct Lepton {
     TLorentzVector v;
     int id;
     int ind;
     float wt;
     int flavor;
     bool plot;
   };   
 protected:
   Hists h;

 private:
   //Global variables go here. Make them global only if necessary.
   TFile *_HstFile;
   const char *_HstFileName;
   const char *_SumFileName;
   int _verbosity;
   int _sample;
   int sampleno;
   float GEV, MEV2GEV;
   int nEvtTotal;
   int count;
   int pass[101];
   int _data;
   vector<Lepton> goodEle,goodJet,goodMu;//,goodEle, goodPho,goodTau,goodJet, goodLep;
   vector<Lepton> Ele;
   int get_match_index(Lepton ele);
   void plot(Lepton ele,int plotno);
   double dr_pion_jet(Lepton pion,int match_index);
   int match_index_jet(Lepton pion);
   ClassDef(FTAna,0);
};

#endif

#ifdef FTAna_cxx
void FTAna::Init(TTree *tree)
{
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

/* fChain->SetBranchAddress("RunNumber",&RunNumber, &b_RunNumber); */
/* fChain->SetBranchAddress("EventNumber",&EventNumber, &b_EventNumber); */
/* fChain->SetBranchAddress("LumiSection",&LumiSection, &b_LumiSection); */
/* fChain->SetBranchAddress("Bunch",&Bunch, &b_Bunch); */
/* fChain->SetBranchAddress("Orbit",&Orbit, &b_Orbit); */
/* fChain->SetBranchAddress("Time",&Time, &b_Time); */
/* fChain->SetBranchAddress("NVertex",&NVertex, &b_NVertex); */
/* fChain->SetBranchAddress("VertexX",VertexX, &b_VertexX); */
/* fChain->SetBranchAddress("VertexY",VertexY, &b_VertexY); */
/* fChain->SetBranchAddress("VertexZ",VertexZ, &b_VertexZ); */
/* fChain->SetBranchAddress("VertexXError",VertexXError, &b_VertexXError); */
/* fChain->SetBranchAddress("VertexYError",VertexYError, &b_VertexYError); */
/* fChain->SetBranchAddress("VertexZError",VertexZError, &b_VertexZError); */
/* fChain->SetBranchAddress("VertexisValid",VertexisValid, &b_VertexisValid); */
/* fChain->SetBranchAddress("VertexisFake",VertexisFake, &b_VertexisFake); */
/* fChain->SetBranchAddress("VertextracksSize",VertextracksSize, &b_VertextracksSize); */
/* fChain->SetBranchAddress("VertexnormalizedChi2",VertexnormalizedChi2, &b_VertexnormalizedChi2); */
/* fChain->SetBranchAddress("Vertexndof",Vertexndof, &b_Vertexndof); */
/* fChain->SetBranchAddress("Vertexrho",Vertexrho, &b_Vertexrho); */
/* fChain->SetBranchAddress("VBeamSpotX0",&BeamSpotX0, &b_BeamSpotX0); */
/* fChain->SetBranchAddress("VBeamSpotY0",&BeamSpotY0, &b_BeamSpotY0); */
/* fChain->SetBranchAddress("VBeamSpotZ0",&BeamSpotZ0, &b_BeamSpotZ0); */
/* fChain->SetBranchAddress("VBeamSpotX0Error",&BeamSpotX0Error, &b_BeamSpotX0Error); */
/* fChain->SetBranchAddress("VBeamSpotY0Error",&BeamSpotY0Error, &b_BeamSpotY0Error); */
/* fChain->SetBranchAddress("VBeamSpotZ0Error",&BeamSpotZ0Error, &b_BeamSpotZ0Error); */
/* fChain->SetBranchAddress("genEventInfo_weight",&genEventInfo_weight, &b_genEventInfo_weight); */
/* fChain->SetBranchAddress("genEventInfo_qScale",&genEventInfo_qScale, &b_genEventInfo_qScale); */
/* fChain->SetBranchAddress("genEventInfo_alphaQCD",&genEventInfo_alphaQCD, &b_genEventInfo_alphaQCD); */
/* fChain->SetBranchAddress("genEventInfo_alphaQED",&genEventInfo_alphaQED, &b_genEventInfo_alphaQED); */
/* fChain->SetBranchAddress("genEventInfo_nMEPartons",&genEventInfo_nMEPartons, &b_genEventInfo_nMEPartons); */
/* fChain->SetBranchAddress("genEventInfo_nMEPartonsFiltered",&genEventInfo_nMEPartonsFiltered, &b_genEventInfo_nMEPartonsFiltered); */
/* fChain->SetBranchAddress("genEventInfo_Q",&genEventInfo_Q, &b_genEventInfo_Q); */
/* fChain->SetBranchAddress("genEventInfo_id1",&genEventInfo_id1, &b_genEventInfo_id1); */
/* fChain->SetBranchAddress("genEventInfo_x1",&genEventInfo_x1, &b_genEventInfo_x1); */
/* fChain->SetBranchAddress("genEventInfo_pdf1",&genEventInfo_pdf1, &b_genEventInfo_pdf1); */
/* fChain->SetBranchAddress("genEventInfo_id2",&genEventInfo_id2, &b_genEventInfo_id2); */
/* fChain->SetBranchAddress("genEventInfo_x2",&genEventInfo_x2, &b_genEventInfo_x2); */
/* fChain->SetBranchAddress("genEventInfo_pdf2",&genEventInfo_pdf2, &b_genEventInfo_pdf2); */
/* fChain->SetBranchAddress("NTracks",&NTracks, &b_NTracks); */
/* fChain->SetBranchAddress("TrackIso03",TrackIso03, &b_TrackIso03); */
/* fChain->SetBranchAddress("TrackIso04",TrackIso04, &b_TrackIso04); */
/* fChain->SetBranchAddress("TrackPx",TrackPx, &b_TrackPx); */
/* fChain->SetBranchAddress("TrackPy",TrackPy, &b_TrackPy); */
/* fChain->SetBranchAddress("TrackPz",TrackPz, &b_TrackPz); */
/* fChain->SetBranchAddress("TrackPt",TrackPt, &b_TrackPt); */
/* fChain->SetBranchAddress("TrackPFID",TrackPFID, &b_TrackPFID); */
/* fChain->SetBranchAddress("TrackPtdiff",TrackPtdiff, &b_TrackPtdiff); */
/* fChain->SetBranchAddress("TrackEta",TrackEta, &b_TrackEta); */
/* fChain->SetBranchAddress("TrackPhi",TrackPhi, &b_TrackPhi); */
/* fChain->SetBranchAddress("TrackEnergy",TrackEnergy, &b_TrackEnergy); */
/* fChain->SetBranchAddress("TrackCharge",TrackCharge, &b_TrackCharge); */
/* fChain->SetBranchAddress("TrackDxy",TrackDxy, &b_TrackDxy); */
/* fChain->SetBranchAddress("TrackDz",TrackDz, &b_TrackDz); */
/* fChain->SetBranchAddress("TrackFromPV",TrackFromPV, &b_TrackFromPV); */
/* fChain->SetBranchAddress("TrackNhits",TrackNhits, &b_TrackNhits); */
/* fChain->SetBranchAddress("TrackNchi2",TrackNchi2, &b_TrackNchi2); */
/* fChain->SetBranchAddress("TrackHighpurity",TrackHighpurity, &b_TrackHighpurity); */
/* fChain->SetBranchAddress("Trackvertexindex",Trackvertexindex, &b_Trackvertexindex); */
/* fChain->SetBranchAddress("TrackPhiAtVtx",TrackPhiAtVtx, &b_TrackPhiAtVtx); */
   if(_data==1){
fChain->SetBranchAddress("NMC",&NMC, &b_NMC);
/* fChain->SetBranchAddress("MCPx",MCPx, &b_MCPx); */
/* fChain->SetBranchAddress("MCPy",MCPy, &b_MCPy); */
/* fChain->SetBranchAddress("MCPz",MCPz, &b_MCPz); */
fChain->SetBranchAddress("MCPt",MCPt, &b_MCPt);
fChain->SetBranchAddress("MCId",MCId, &b_MCId);
fChain->SetBranchAddress("MCEta",MCEta, &b_MCEta);
fChain->SetBranchAddress("MCPhi",MCPhi, &b_MCPhi);
fChain->SetBranchAddress("MCEnergy",MCEnergy, &b_MCEnergy);
fChain->SetBranchAddress("MCMass",MCMass, &b_MCMass);
fChain->SetBranchAddress("MCCharge",MCCharge, &b_MCCharge);
fChain->SetBranchAddress("MCIndex",MCIndex, &b_MCIndex);
fChain->SetBranchAddress("MCStatus",MCStatus, &b_MCStatus);
/* fChain->SetBranchAddress("MCVx",MCVx, &b_MCVx); */
/* fChain->SetBranchAddress("MCVy",MCVy, &b_MCVy); */
/* fChain->SetBranchAddress("MCVz",MCVz, &b_MCVz); */
/* fChain->SetBranchAddress("NMCdaughter",NMCdaughter, &b_NMCdaughter); */
fChain->SetBranchAddress("NMCmother",NMCmother, &b_NMCmother);
fChain->SetBranchAddress("MCMotherIndex",MCMotherIndex, &b_MCMotherIndex);
   }
   if(_sample==3){
     fChain->SetBranchAddress("NMuons",&NMuons, &b_NMuons);
     fChain->SetBranchAddress("MuonPt",MuonPt, &b_MuonPt);
     fChain->SetBranchAddress("MuonEta",MuonEta, &b_MuonEta);
     fChain->SetBranchAddress("MuonPhi",MuonPhi, &b_MuonPhi);
     fChain->SetBranchAddress("MuonEnergy",MuonEnergy, &b_MuonEnergy);
     fChain->SetBranchAddress("METPt",&METPt, &b_METPt);
     fChain->SetBranchAddress("METPhi",&METPhi, &b_METPhi);
   }
/* fChain->SetBranchAddress("MuonIso03",MuonIso03, &b_MuonIso03); */
/* fChain->SetBranchAddress("MuonIso04",MuonIso04, &b_MuonIso04); */
/* fChain->SetBranchAddress("MuonIsLooseMatrix",MuonIsLooseMatrix, &b_MuonIsLooseMatrix); */
/* fChain->SetBranchAddress("MuonIsTightMatrix",MuonIsTightMatrix, &b_MuonIsTightMatrix); */
/* fChain->SetBranchAddress("MuonIsLooseMatrixWoPromptHLT",MuonIsLooseMatrixWoPromptHLT, &b_MuonIsLooseMatrixWoPromptHLT); */
/* fChain->SetBranchAddress("MuonIsTightMatrixWoPromptHLT",MuonIsTightMatrixWoPromptHLT, &b_MuonIsTightMatrixWoPromptHLT); */
/* fChain->SetBranchAddress("MuonIsPrompt",MuonIsPrompt, &b_MuonIsPrompt); */
/* fChain->SetBranchAddress("MuonIsHLT",MuonIsHLT, &b_MuonIsHLT); */
/* fChain->SetBranchAddress("MuonPx",MuonPx, &b_MuonPx); */
/* fChain->SetBranchAddress("MuonPy",MuonPy, &b_MuonPy); */
/* fChain->SetBranchAddress("MuonPz",MuonPz, &b_MuonPz); */
/* fChain->SetBranchAddress("MuonTrackIso",MuonTrackIso, &b_MuonTrackIso); */
/* fChain->SetBranchAddress("MuonEcalIso",MuonEcalIso, &b_MuonEcalIso); */
/* fChain->SetBranchAddress("MuonHcalIso",MuonHcalIso, &b_MuonHcalIso); */
/* fChain->SetBranchAddress("MuonCaloIso",MuonCaloIso, &b_MuonCaloIso); */
/* fChain->SetBranchAddress("MuonChargedHadronMiniIso",MuonChargedHadronMiniIso, &b_MuonChargedHadronMiniIso); */
/* fChain->SetBranchAddress("MuonNeutralHadronMiniIso",MuonNeutralHadronMiniIso, &b_MuonNeutralHadronMiniIso); */
/* fChain->SetBranchAddress("MuonPhotonMiniIso",MuonPhotonMiniIso, &b_MuonPhotonMiniIso); */
/* fChain->SetBranchAddress("MuonBetaMiniIso",MuonBetaMiniIso, &b_MuonBetaMiniIso); */
/* fChain->SetBranchAddress("MuonMiniIsoCone",MuonMiniIsoCone, &b_MuonMiniIsoCone); */
/* fChain->SetBranchAddress("MuonPtRelv1",MuonPtRelv1, &b_MuonPtRelv1); */
/* fChain->SetBranchAddress("MuonPtRatiov1",MuonPtRatiov1, &b_MuonPtRatiov1); */
/* fChain->SetBranchAddress("MuonPtRel",MuonPtRel, &b_MuonPtRel); */
/* fChain->SetBranchAddress("MuonPtRatio",MuonPtRatio, &b_MuonPtRatio); */
/* fChain->SetBranchAddress("MuonHasInnerTrack",MuonHasInnerTrack, &b_MuonHasInnerTrack); */
/* fChain->SetBranchAddress("MuonInnerTrackPt",MuonInnerTrackPt, &b_MuonInnerTrackPt); */
/* fChain->SetBranchAddress("MuonInnerTrackEta",MuonInnerTrackEta, &b_MuonInnerTrackEta); */
/* fChain->SetBranchAddress("MuonInnerTrackPhi",MuonInnerTrackPhi, &b_MuonInnerTrackPhi); */
/* fChain->SetBranchAddress("MuonInnerTrackCharge",MuonInnerTrackCharge, &b_MuonInnerTrackCharge); */
/* fChain->SetBranchAddress("MuonOuterTrackPt",MuonOuterTrackPt, &b_MuonOuterTrackPt); */
/* fChain->SetBranchAddress("MuonOuterTrackEta",MuonOuterTrackEta, &b_MuonOuterTrackEta); */
/* fChain->SetBranchAddress("MuonOuterTrackPhi",MuonOuterTrackPhi, &b_MuonOuterTrackPhi); */
/* fChain->SetBranchAddress("MuonOuterTrackCharge",MuonOuterTrackCharge, &b_MuonOuterTrackCharge); */
/* fChain->SetBranchAddress("MuonHasOuterTrack",MuonHasOuterTrack, &b_MuonHasOuterTrack); */
/* fChain->SetBranchAddress("MuonDxy",MuonDxy, &b_MuonDxy); */
/* fChain->SetBranchAddress("MuonDz",MuonDz, &b_MuonDz); */
/* fChain->SetBranchAddress("MuonCharge",MuonCharge, &b_MuonCharge); */
/* fChain->SetBranchAddress("MuonNhits",MuonNhits, &b_MuonNhits); */
/* fChain->SetBranchAddress("MuonNchi2",MuonNchi2, &b_MuonNchi2); */
/* fChain->SetBranchAddress("MuonNhitsMuon",MuonNhitsMuon, &b_MuonNhitsMuon); */
/* fChain->SetBranchAddress("MuonTrackerlayerwithmeasurement",MuonTrackerlayerwithmeasurement, &b_MuonTrackerlayerwithmeasurement); */
/* fChain->SetBranchAddress("MuonPixelhits",MuonPixelhits, &b_MuonPixelhits); */
/* fChain->SetBranchAddress("MuonValidfraction",MuonValidfraction, &b_MuonValidfraction); */
/* fChain->SetBranchAddress("MuonNchambers",MuonNchambers, &b_MuonNchambers); */
/* fChain->SetBranchAddress("MuonLMT",MuonLMT, &b_MuonLMT); */
/* fChain->SetBranchAddress("MuonisSH",MuonisSH, &b_MuonisSH); */
/* fChain->SetBranchAddress("MuonNumberOfMatches",MuonNumberOfMatches, &b_MuonNumberOfMatches); */
/* fChain->SetBranchAddress("MuonNumberOfMatchedStations",MuonNumberOfMatchedStations, &b_MuonNumberOfMatchedStations); */
/* fChain->SetBranchAddress("MuonisGlobal",MuonisGlobal, &b_MuonisGlobal); */
/* fChain->SetBranchAddress("MuonisTracker",MuonisTracker, &b_MuonisTracker); */
/* fChain->SetBranchAddress("MuonisStandAloneMuon",MuonisStandAloneMuon, &b_MuonisStandAloneMuon); */
/* fChain->SetBranchAddress("MuonisCalo",MuonisCalo, &b_MuonisCalo); */
/* fChain->SetBranchAddress("MuonisPF",MuonisPF, &b_MuonisPF); */
/* fChain->SetBranchAddress("MuonisRPC",MuonisRPC, &b_MuonisRPC); */
/* fChain->SetBranchAddress("MuonpfIsolationR03sumChargedHadronPt",MuonpfIsolationR03sumChargedHadronPt, &b_MuonpfIsolationR03sumChargedHadronPt); */
/* fChain->SetBranchAddress("MuonpfIsolationR03sumChargedParticlePt",MuonpfIsolationR03sumChargedParticlePt, &b_MuonpfIsolationR03sumChargedParticlePt); */
/* fChain->SetBranchAddress("MuonpfIsolationR03sumNeutralHadronEt",MuonpfIsolationR03sumNeutralHadronEt, &b_MuonpfIsolationR03sumNeutralHadronEt); */
/* fChain->SetBranchAddress("MuonpfIsolationR03sumPhotonEt",MuonpfIsolationR03sumPhotonEt, &b_MuonpfIsolationR03sumPhotonEt); */
/* fChain->SetBranchAddress("MuonpfIsolationR03sumPhotonEtHighThreshold",MuonpfIsolationR03sumPhotonEtHighThreshold, &b_MuonpfIsolationR03sumPhotonEtHighThreshold); */
/* fChain->SetBranchAddress("MuonpfIsolationR03sumNeutralHadronEtHighThreshold",MuonpfIsolationR03sumNeutralHadronEtHighThreshold, &b_MuonpfIsolationR03sumNeutralHadronEtHighThreshold); */
/* fChain->SetBranchAddress("MuonpfIsolationR03sumPUPt",MuonpfIsolationR03sumPUPt, &b_MuonpfIsolationR03sumPUPt); */
/* fChain->SetBranchAddress("MuonpfIsolationR04sumPhotonEtHighThreshold",MuonpfIsolationR04sumPhotonEtHighThreshold, &b_MuonpfIsolationR04sumPhotonEtHighThreshold); */
/* fChain->SetBranchAddress("MuonpfIsolationR04sumChargedHadronPt",MuonpfIsolationR04sumChargedHadronPt, &b_MuonpfIsolationR04sumChargedHadronPt); */
/* fChain->SetBranchAddress("MuonpfIsolationR04sumChargedParticlePt",MuonpfIsolationR04sumChargedParticlePt, &b_MuonpfIsolationR04sumChargedParticlePt); */
/* fChain->SetBranchAddress("MuonpfIsolationR04sumNeutralHadronEt",MuonpfIsolationR04sumNeutralHadronEt, &b_MuonpfIsolationR04sumNeutralHadronEt); */
/* fChain->SetBranchAddress("MuonpfIsolationR04sumPhotonEt",MuonpfIsolationR04sumPhotonEt, &b_MuonpfIsolationR04sumPhotonEt); */
/* fChain->SetBranchAddress("MuonpfIsolationR04sumNeutralHadronEtHighThreshold",MuonpfIsolationR04sumNeutralHadronEtHighThreshold, &b_MuonpfIsolationR04sumNeutralHadronEtHighThreshold); */
/* fChain->SetBranchAddress("MuonpfIsolationR04sumPUPt",MuonpfIsolationR04sumPUPt, &b_MuonpfIsolationR04sumPUPt); */
/* fChain->SetBranchAddress("MuontrkKink",MuontrkKink, &b_MuontrkKink); */
/* fChain->SetBranchAddress("Muonchi2LocalPosition",Muonchi2LocalPosition, &b_Muonchi2LocalPosition); */
/* fChain->SetBranchAddress("MuonsegmentCompatibility",MuonsegmentCompatibility, &b_MuonsegmentCompatibility); */
/* fChain->SetBranchAddress("MuondbPV3D",MuondbPV3D, &b_MuondbPV3D); */
/* fChain->SetBranchAddress("MuonedbPV3D",MuonedbPV3D, &b_MuonedbPV3D); */
/* fChain->SetBranchAddress("MuonsigPV3D",MuonsigPV3D, &b_MuonsigPV3D); */
/* fChain->SetBranchAddress("MuondbPV2D",MuondbPV2D, &b_MuondbPV2D); */
/* fChain->SetBranchAddress("MuonedbPV2D",MuonedbPV2D, &b_MuonedbPV2D); */
/* fChain->SetBranchAddress("MuonsigPV2D",MuonsigPV2D, &b_MuonsigPV2D); */
/* fChain->SetBranchAddress("MuondbBS2D",MuondbBS2D, &b_MuondbBS2D); */
/* fChain->SetBranchAddress("MuonedbBS2D",MuonedbBS2D, &b_MuonedbBS2D); */
/* fChain->SetBranchAddress("MuonsigBS2D",MuonsigBS2D, &b_MuonsigBS2D); */
/* fChain->SetBranchAddress("MuondbBS3D",MuondbBS3D, &b_MuondbBS3D); */
/* fChain->SetBranchAddress("MuonedbBS3D",MuonedbBS3D, &b_MuonedbBS3D); */
/* fChain->SetBranchAddress("MuonsigBS3D",MuonsigBS3D, &b_MuonsigBS3D); */
/* fChain->SetBranchAddress("NEle27",&NEle27, &b_NEle27); */
/* fChain->SetBranchAddress("NMu24",&NMu24, &b_NMu24); */
/*  fChain->SetBranchAddress("IsoMu24ORIsoTkMu24Pt",IsoMu24ORIsoTkMu24Pt, &b_IsoMu24ORIsoTkMu24Pt); */
/*  fChain->SetBranchAddress("IsoMu24ORIsoTkMu24Eta",IsoMu24ORIsoTkMu24Eta, &b_IsoMu24ORIsoTkMu24Eta); */
/*  fChain->SetBranchAddress("IsoMu24ORIsoTkMu24Phi",IsoMu24ORIsoTkMu24Phi, &b_IsoMu24ORIsoTkMu24Phi); */
/*  fChain->SetBranchAddress("Ele27WPLooseGsfPt",Ele27WPLooseGsfPt, &b_Ele27WPLooseGsfPt); */
/*  fChain->SetBranchAddress("Ele27WPLooseGsfEta",Ele27WPLooseGsfEta, &b_Ele27WPLooseGsfEta); */
/*  fChain->SetBranchAddress("Ele27WPLooseGsfPhi",Ele27WPLooseGsfPhi, &b_Ele27WPooseGsfPhi); */
fChain->SetBranchAddress("NElectrons",&NElectrons, &b_NElectrons); 
/* fChain->SetBranchAddress("ElectronIso03",ElectronIso03, &b_ElectronIso03); */
/* fChain->SetBranchAddress("ElectronIso04",ElectronIso04, &b_ElectronIso04); */
/* fChain->SetBranchAddress("ElectronIsCustomHLT",ElectronIsCustomHLT, &b_ElectronIsCustomHLT); */
/* fChain->SetBranchAddress("ElectronIsLooseMatrix",ElectronIsLooseMatrix, &b_ElectronIsLooseMatrix); */
/* fChain->SetBranchAddress("ElectronIsTightMatrix",ElectronIsTightMatrix, &b_ElectronIsTightMatrix); */
/* fChain->SetBranchAddress("ElectronIsLooseMatrixWoPromptHLT",ElectronIsLooseMatrixWoPromptHLT, &b_ElectronIsLooseMatrixWoPromptHLT); */
/* fChain->SetBranchAddress("ElectronIsTightMatrixWoPromptHLT",ElectronIsTightMatrixWoPromptHLT, &b_ElectronIsTightMatrixWoPromptHLT); */
/* fChain->SetBranchAddress("ElectronIsPrompt",ElectronIsPrompt, &b_ElectronIsPrompt); */
/* fChain->SetBranchAddress("ElectronIsHLT",ElectronIsHLT, &b_ElectronIsHLT); */
/* fChain->SetBranchAddress("ElectronCutVLMT",ElectronCutVLMT, &b_ElectronCutVLMT); */
/* fChain->SetBranchAddress("ElectronPx",ElectronPx, &b_ElectronPx); */
/* fChain->SetBranchAddress("ElectronPy",ElectronPy, &b_ElectronPy); */
/* fChain->SetBranchAddress("ElectronPz",ElectronPz, &b_ElectronPz); */
fChain->SetBranchAddress("ElectronPt",ElectronPt, &b_ElectronPt);
fChain->SetBranchAddress("ElectronEta",ElectronEta, &b_ElectronEta);
fChain->SetBranchAddress("ElectronPhi",ElectronPhi, &b_ElectronPhi);
 fChain->SetBranchAddress("ElectronIsMedium",ElectronIsMedium,&b_ElectronIsMedium);
 fChain->SetBranchAddress("ElectronIsTrigger",ElectronIsTrigger,&b_ElectronIsTrigger);
 fChain->SetBranchAddress("ElectronPFIsolation",ElectronPFIsolation,&b_ElectronPFIsolation);
 fChain->SetBranchAddress("NTowers",&NTowers,&b_NTowers);
 fChain->SetBranchAddress("TowerEta",TowerEta,&b_TowerEta);
 fChain->SetBranchAddress("TowerPhi",TowerPhi,&b_TowerPhi);
 fChain->SetBranchAddress("TowerEnergy",TowerEnergy,&b_TowerEnergy);
 fChain->SetBranchAddress("TowerEmEnergy",TowerEmEnergy,&b_TowerEmEnergy);
 
//fChain->SetBranchAddress("ElectronEnergy",ElectronEnergy, &b_ElectronEnergy);
fChain->SetBranchAddress("ElectronTrackIso",ElectronTrackIso, &b_ElectronTrackIso);
fChain->SetBranchAddress("ElectronEcalIso",ElectronEcalIso, &b_ElectronEcalIso);
fChain->SetBranchAddress("ElectronHcalIso",ElectronHcalIso, &b_ElectronHcalIso);
/* fChain->SetBranchAddress("ElectronCaloIso",ElectronCaloIso, &b_ElectronCaloIso); */
/* fChain->SetBranchAddress("ElectronChargedHadronMiniIso",ElectronChargedHadronMiniIso, &b_ElectronChargedHadronMiniIso); */
/* fChain->SetBranchAddress("ElectronNeutralHadronMiniIso",ElectronNeutralHadronMiniIso, &b_ElectronNeutralHadronMiniIso); */
/* fChain->SetBranchAddress("ElectronPhotonMiniIso",ElectronPhotonMiniIso, &b_ElectronPhotonMiniIso); */
/* fChain->SetBranchAddress("ElectronBetaMiniIso",ElectronBetaMiniIso, &b_ElectronBetaMiniIso); */
/* fChain->SetBranchAddress("ElectronMiniIsoCone",ElectronMiniIsoCone, &b_ElectronMiniIsoCone); */
/* fChain->SetBranchAddress("ElectronPtRelv1",ElectronPtRelv1, &b_ElectronPtRelv1); */
/* fChain->SetBranchAddress("ElectronPtRatiov1",ElectronPtRatiov1, &b_ElectronPtRatiov1); */
/* fChain->SetBranchAddress("ElectronPtRel",ElectronPtRel, &b_ElectronPtRel); */
/* fChain->SetBranchAddress("ElectronPtRatio",ElectronPtRatio, &b_ElectronPtRatio); */
fChain->SetBranchAddress("ElectronDxy",ElectronDxy, &b_ElectronDxy);
fChain->SetBranchAddress("ElectronDz",ElectronDz, &b_ElectronDz);
/* fChain->SetBranchAddress("ElectronCharge",ElectronCharge, &b_ElectronCharge); */
 fChain->SetBranchAddress("ElectronsuperClustereta",ElectronsuperClustereta, &b_ElectronsuperClustereta);
/* fChain->SetBranchAddress("ElectronpassConversionVeto",ElectronpassConversionVeto, &b_ElectronpassConversionVeto); */
fChain->SetBranchAddress("ElectronnumberOfLostHits",ElectronnumberOfLostHits, &b_ElectronnumberOfLostHits);
fChain->SetBranchAddress("ElectronsigmaIetaIeta",ElectronsigmaIetaIeta, &b_ElectronsigmaIetaIeta);
/* fChain->SetBranchAddress("Electronfull5x5_sigmaIetaIeta",Electronfull5x5_sigmaIetaIeta, &b_Electronfull5x5_sigmaIetaIeta); */
/* fChain->SetBranchAddress("ElectronnumberOfHits",ElectronnumberOfHits, &b_ElectronnumberOfHits); */
/* fChain->SetBranchAddress("ElectronisPF",ElectronisPF, &b_ElectronisPF); */
/* fChain->SetBranchAddress("ElectronsigmaIetaIphi",ElectronsigmaIetaIphi, &b_ElectronsigmaIetaIphi); */
/* fChain->SetBranchAddress("Electronfull5x5_sigmaIetaIphi",Electronfull5x5_sigmaIetaIphi, &b_Electronfull5x5_sigmaIetaIphi); */
/* fChain->SetBranchAddress("Electronip3d",Electronip3d, &b_Electronip3d); */
/* fChain->SetBranchAddress("ElectrondbPV3D",ElectrondbPV3D, &b_ElectrondbPV3D); */
/* fChain->SetBranchAddress("ElectronedbPV3D",ElectronedbPV3D, &b_ElectronedbPV3D); */
/* fChain->SetBranchAddress("ElectronsigPV3D",ElectronsigPV3D, &b_ElectronsigPV3D); */
/* fChain->SetBranchAddress("ElectrondbPV2D",ElectrondbPV2D, &b_ElectrondbPV2D); */
/* fChain->SetBranchAddress("ElectronedbPV2D",ElectronedbPV2D, &b_ElectronedbPV2D); */
/* fChain->SetBranchAddress("ElectronsigPV2D",ElectronsigPV2D, &b_ElectronsigPV2D); */
/* fChain->SetBranchAddress("ElectrondbBS2D",ElectrondbBS2D, &b_ElectrondbBS2D); */
/* fChain->SetBranchAddress("ElectronedbBS2D",ElectronedbBS2D, &b_ElectronedbBS2D); */
/* fChain->SetBranchAddress("ElectronsigBS2D",ElectronsigBS2D, &b_ElectronsigBS2D); */
/* fChain->SetBranchAddress("ElectrondbBS3D",ElectrondbBS3D, &b_ElectrondbBS3D); */
/* fChain->SetBranchAddress("ElectronedbBS3D",ElectronedbBS3D, &b_ElectronedbBS3D); */
/* fChain->SetBranchAddress("ElectronsigBS3D",ElectronsigBS3D, &b_ElectronsigBS3D); */
/* fChain->SetBranchAddress("ElectronscPixCharge",ElectronscPixCharge, &b_ElectronscPixCharge); */
/* fChain->SetBranchAddress("ElectronisGsfCtfScPixChargeConsistent",ElectronisGsfCtfScPixChargeConsistent, &b_ElectronisGsfCtfScPixChargeConsistent); */
/* fChain->SetBranchAddress("ElectronisGsfScPixChargeConsistent",ElectronisGsfScPixChargeConsistent, &b_ElectronisGsfScPixChargeConsistent); */
/* fChain->SetBranchAddress("ElectronisGsfCtfChargeConsistent",ElectronisGsfCtfChargeConsistent, &b_ElectronisGsfCtfChargeConsistent); */
/* fChain->SetBranchAddress("ElectronhcalOverEcal",ElectronhcalOverEcal, &b_ElectronhcalOverEcal); */
fChain->SetBranchAddress("ElectronhadronicOverEm",ElectronhadronicOverEm, &b_ElectronhadronicOverEm);
/* fChain->SetBranchAddress("Electronmva_Isolated",Electronmva_Isolated, &b_Electronmva_Isolated); */
/* fChain->SetBranchAddress("Electronmva_e_pi",Electronmva_e_pi, &b_Electronmva_e_pi); */
/* fChain->SetBranchAddress("ElectronsumChargedHadronPt",ElectronsumChargedHadronPt, &b_ElectronsumChargedHadronPt); */
/* fChain->SetBranchAddress("ElectronsumNeutralHadronEt",ElectronsumNeutralHadronEt, &b_ElectronsumNeutralHadronEt); */
/* fChain->SetBranchAddress("ElectronsumPhotonEt",ElectronsumPhotonEt, &b_ElectronsumPhotonEt); */
/* fChain->SetBranchAddress("ElectronsumChargedParticlePt",ElectronsumChargedParticlePt, &b_ElectronsumChargedParticlePt); */
/* fChain->SetBranchAddress("ElectronsumNeutralHadronEtHighThreshold",ElectronsumNeutralHadronEtHighThreshold, &b_ElectronsumNeutralHadronEtHighThreshold); */
/* fChain->SetBranchAddress("ElectronsumPhotonEtHighThreshold",ElectronsumPhotonEtHighThreshold, &b_ElectronsumPhotonEtHighThreshold); */
/* fChain->SetBranchAddress("ElectronsumPUPt",ElectronsumPUPt, &b_ElectronsumPUPt); */
fChain->SetBranchAddress("ElectrondeltaEtaSuperClusterTrackAtVtx",ElectrondeltaEtaSuperClusterTrackAtVtx, &b_ElectrondeltaEtaSuperClusterTrackAtVtx);
/* fChain->SetBranchAddress("ElectrondeltaEtaSeedClusterTrackAtCalo",ElectrondeltaEtaSeedClusterTrackAtCalo, &b_ElectrondeltaEtaSeedClusterTrackAtCalo); */
/* fChain->SetBranchAddress("ElectrondeltaEtaEleClusterTrackAtCalo",ElectrondeltaEtaEleClusterTrackAtCalo, &b_ElectrondeltaEtaEleClusterTrackAtCalo); */
fChain->SetBranchAddress("ElectrondeltaPhiSuperClusterTrackAtVtx",ElectrondeltaPhiSuperClusterTrackAtVtx, &b_ElectrondeltaPhiSuperClusterTrackAtVtx);
/* fChain->SetBranchAddress("ElectrondeltaPhiSeedClusterTrackAtCalo",ElectrondeltaPhiSeedClusterTrackAtCalo, &b_ElectrondeltaPhiSeedClusterTrackAtCalo); */
/* fChain->SetBranchAddress("ElectrondeltaPhiEleClusterTrackAtCalo",ElectrondeltaPhiEleClusterTrackAtCalo, &b_ElectrondeltaPhiEleClusterTrackAtCalo); */
/* fChain->SetBranchAddress("ElectroneidLoose",ElectroneidLoose, &b_ElectroneidLoose); */
/* fChain->SetBranchAddress("ElectroneidRobustLoose",ElectroneidRobustLoose, &b_ElectroneidRobustLoose); */
/* fChain->SetBranchAddress("ElectroneidTight",ElectroneidTight, &b_ElectroneidTight); */
/* fChain->SetBranchAddress("ElectroneidRobustTight",ElectroneidRobustTight, &b_ElectroneidRobustTight); */
/* fChain->SetBranchAddress("ElectroneidRobustHighEnergy",ElectroneidRobustHighEnergy, &b_ElectroneidRobustHighEnergy); */
fChain->SetBranchAddress("ElectronecalEnergy",ElectronecalEnergy, &b_ElectronecalEnergy);
 fChain->SetBranchAddress("Electronp_in",Electronp_in, &b_Electronp_in); 
/* fChain->SetBranchAddress("Electron1oEm1oP",Electron1oEm1oP, &b_Electron1oEm1oP); */
/* fChain->SetBranchAddress("Electron1oEm1oPcorrected",Electron1oEm1oPcorrected, &b_Electron1oEm1oPcorrected); */
/* fChain->SetBranchAddress("ElectronEcalPFClusterIso",ElectronEcalPFClusterIso, &b_ElectronEcalPFClusterIso); */
/* fChain->SetBranchAddress("ElectronHcalPFClusterIso",ElectronHcalPFClusterIso, &b_ElectronHcalPFClusterIso); */
 fChain->SetBranchAddress("ElectronFbrem",ElectronFbrem,&b_ElectronFbrem);
 fChain->SetBranchAddress("ElectronEoverP",ElectronEoverP,&b_ElectronEoverP);
/* fChain->SetBranchAddress("NTaus",&NTaus, &b_NTaus); */
/* fChain->SetBranchAddress("TauPx",TauPx, &b_TauPx); */
/* fChain->SetBranchAddress("TauPy",TauPy, &b_TauPy); */
/* fChain->SetBranchAddress("TauPz",TauPz, &b_TauPz); */
/* fChain->SetBranchAddress("TauPt",TauPt, &b_TauPt); */
/* fChain->SetBranchAddress("TauEta",TauEta, &b_TauEta); */
/* fChain->SetBranchAddress("TauPhi",TauPhi, &b_TauPhi); */
/* fChain->SetBranchAddress("TauEnergy",TauEnergy, &b_TauEnergy); */
/* fChain->SetBranchAddress("TauDecayMode",TauDecayMode, &b_TauDecayMode); */
/* fChain->SetBranchAddress("TauChargedHadronMiniIso",TauChargedHadronMiniIso, &b_TauChargedHadronMiniIso); */
/* fChain->SetBranchAddress("TauNeutralHadronMiniIso",TauNeutralHadronMiniIso, &b_TauNeutralHadronMiniIso); */
/* fChain->SetBranchAddress("TauPhotonMiniIso",TauPhotonMiniIso, &b_TauPhotonMiniIso); */
/* fChain->SetBranchAddress("TauBetaMiniIso",TauBetaMiniIso, &b_TauBetaMiniIso); */
/* fChain->SetBranchAddress("TauMiniIsoCone",TauMiniIsoCone, &b_TauMiniIsoCone); */
/* fChain->SetBranchAddress("TauPtRelv1",TauPtRelv1, &b_TauPtRelv1); */
/* fChain->SetBranchAddress("TauPtRatiov1",TauPtRatiov1, &b_TauPtRatiov1); */
/* fChain->SetBranchAddress("TauPtRel",TauPtRel, &b_TauPtRel); */
/* fChain->SetBranchAddress("TauPtRatio",TauPtRatio, &b_TauPtRatio); */
/* fChain->SetBranchAddress("TauCharge",TauCharge, &b_TauCharge); */
/* fChain->SetBranchAddress("TauisPF",TauisPF, &b_TauisPF); */
/* fChain->SetBranchAddress("TauDz",TauDz, &b_TauDz); */
/* fChain->SetBranchAddress("TauleadChargedHadrCandvx",TauleadChargedHadrCandvx, &b_TauleadChargedHadrCandvx); */
/* fChain->SetBranchAddress("TauleadChargedHadrCandvy",TauleadChargedHadrCandvy, &b_TauleadChargedHadrCandvy); */
/* fChain->SetBranchAddress("TauleadChargedHadrCandvz",TauleadChargedHadrCandvz, &b_TauleadChargedHadrCandvz); */
/* fChain->SetBranchAddress("TauleadChargedHadrCandpt",TauleadChargedHadrCandpt, &b_TauleadChargedHadrCandpt); */
/* fChain->SetBranchAddress("TauagainstElectronMVA6category",TauagainstElectronMVA6category, &b_TauagainstElectronMVA6category); */
/* fChain->SetBranchAddress("TaubyCombinedIsolationDeltaBetaCorrRaw3Hits",TaubyCombinedIsolationDeltaBetaCorrRaw3Hits, &b_TaubyCombinedIsolationDeltaBetaCorrRaw3Hits); */
/* fChain->SetBranchAddress("TaudecayModeFindingOldDMs",TaudecayModeFindingOldDMs, &b_TaudecayModeFindingOldDMs); */
/* fChain->SetBranchAddress("TaudecayModeFindingNewDMs",TaudecayModeFindingNewDMs, &b_TaudecayModeFindingNewDMs); */
/* fChain->SetBranchAddress("TaubyLooseCombinedIsolationDeltaBetaCorr3Hits",TaubyLooseCombinedIsolationDeltaBetaCorr3Hits, &b_TaubyLooseCombinedIsolationDeltaBetaCorr3Hits); */
/* fChain->SetBranchAddress("TaubyMediumCombinedIsolationDeltaBetaCorr3Hits",TaubyMediumCombinedIsolationDeltaBetaCorr3Hits, &b_TaubyMediumCombinedIsolationDeltaBetaCorr3Hits); */
/* fChain->SetBranchAddress("TaubyTightCombinedIsolationDeltaBetaCorr3Hits",TaubyTightCombinedIsolationDeltaBetaCorr3Hits, &b_TaubyTightCombinedIsolationDeltaBetaCorr3Hits); */
/* fChain->SetBranchAddress("TaubyVLooseIsolationMVArun2v1DBoldDMwLT",TaubyVLooseIsolationMVArun2v1DBoldDMwLT, &b_TaubyVLooseIsolationMVArun2v1DBoldDMwLT); */
/* fChain->SetBranchAddress("TaubyLooseIsolationMVArun2v1DBoldDMwLT",TaubyLooseIsolationMVArun2v1DBoldDMwLT, &b_TaubyLooseIsolationMVArun2v1DBoldDMwLT); */
/* fChain->SetBranchAddress("TaubyMediumIsolationMVArun2v1DBoldDMwLT",TaubyMediumIsolationMVArun2v1DBoldDMwLT, &b_TaubyMediumIsolationMVArun2v1DBoldDMwLT); */
/* fChain->SetBranchAddress("TaubyTightIsolationMVArun2v1DBoldDMwLT",TaubyTightIsolationMVArun2v1DBoldDMwLT, &b_TaubyTightIsolationMVArun2v1DBoldDMwLT); */
/* fChain->SetBranchAddress("TaubyVTightIsolationMVArun2v1DBoldDMwLT",TaubyVTightIsolationMVArun2v1DBoldDMwLT, &b_TaubyVTightIsolationMVArun2v1DBoldDMwLT); */
/* fChain->SetBranchAddress("TaubyVLooseIsolationMVArun2v1DBnewDMwLT",TaubyVLooseIsolationMVArun2v1DBnewDMwLT, &b_TaubyVLooseIsolationMVArun2v1DBnewDMwLT); */
/* fChain->SetBranchAddress("TaubyLooseIsolationMVArun2v1DBnewDMwLT",TaubyLooseIsolationMVArun2v1DBnewDMwLT, &b_TaubyLooseIsolationMVArun2v1DBnewDMwLT); */
/* fChain->SetBranchAddress("TaubyMediumIsolationMVArun2v1DBnewDMwLT",TaubyMediumIsolationMVArun2v1DBnewDMwLT, &b_TaubyMediumIsolationMVArun2v1DBnewDMwLT); */
/* fChain->SetBranchAddress("TaubyTightIsolationMVArun2v1DBnewDMwLT",TaubyTightIsolationMVArun2v1DBnewDMwLT, &b_TaubyTightIsolationMVArun2v1DBnewDMwLT); */
/* fChain->SetBranchAddress("TaubyVTightIsolationMVArun2v1DBnewDMwLT",TaubyVTightIsolationMVArun2v1DBnewDMwLT, &b_TaubyVTightIsolationMVArun2v1DBnewDMwLT); */
/* fChain->SetBranchAddress("TauagainstMuonLoose3",TauagainstMuonLoose3, &b_TauagainstMuonLoose3); */
/* fChain->SetBranchAddress("TauagainstMuonTight3",TauagainstMuonTight3, &b_TauagainstMuonTight3); */
/* fChain->SetBranchAddress("TauagainstElectronVLooseMVA6",TauagainstElectronVLooseMVA6, &b_TauagainstElectronVLooseMVA6); */
/* fChain->SetBranchAddress("TauagainstElectronLooseMVA6",TauagainstElectronLooseMVA6, &b_TauagainstElectronLooseMVA6); */
/* fChain->SetBranchAddress("TauagainstElectronMediumMVA6",TauagainstElectronMediumMVA6, &b_TauagainstElectronMediumMVA6); */
/* fChain->SetBranchAddress("TauagainstElectronTightMVA6",TauagainstElectronTightMVA6, &b_TauagainstElectronTightMVA6); */
/* fChain->SetBranchAddress("TauagainstElectronVTightMVA6",TauagainstElectronVTightMVA6, &b_TauagainstElectronVTightMVA6); */
/* fChain->SetBranchAddress("TaubyVLooseIsolationMVArun2v1DBdR03oldDMwLT",TaubyVLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_TaubyVLooseIsolationMVArun2v1DBdR03oldDMwLT); */
/* fChain->SetBranchAddress("TaubyLooseIsolationMVArun2v1DBdR03oldDMwLT",TaubyLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_TaubyLooseIsolationMVArun2v1DBdR03oldDMwLT); */
/* fChain->SetBranchAddress("TaubyMediumIsolationMVArun2v1DBdR03oldDMwLT",TaubyMediumIsolationMVArun2v1DBdR03oldDMwLT, &b_TaubyMediumIsolationMVArun2v1DBdR03oldDMwLT); */
/* fChain->SetBranchAddress("TaubyTightIsolationMVArun2v1DBdR03oldDMwLT",TaubyTightIsolationMVArun2v1DBdR03oldDMwLT, &b_TaubyTightIsolationMVArun2v1DBdR03oldDMwLT); */
/* fChain->SetBranchAddress("TaubyVTightIsolationMVArun2v1DBdR03oldDMwLT",TaubyVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_TaubyVTightIsolationMVArun2v1DBdR03oldDMwLT); */
/* fChain->SetBranchAddress("NPhotons",&NPhotons, &b_NPhotons); */
/* fChain->SetBranchAddress("PhotonPx",PhotonPx, &b_PhotonPx); */
/* fChain->SetBranchAddress("PhotonPy",PhotonPy, &b_PhotonPy); */
/* fChain->SetBranchAddress("PhotonPz",PhotonPz, &b_PhotonPz); */
/* fChain->SetBranchAddress("PhotonPt",PhotonPt, &b_PhotonPt); */
/* fChain->SetBranchAddress("PhotonEta",PhotonEta, &b_PhotonEta); */
/* fChain->SetBranchAddress("PhotonPhi",PhotonPhi, &b_PhotonPhi); */
/* fChain->SetBranchAddress("PhotonEnergy",PhotonEnergy, &b_PhotonEnergy); */
/* fChain->SetBranchAddress("PhotonTrackIso",PhotonTrackIso, &b_PhotonTrackIso); */
/* fChain->SetBranchAddress("PhotonEcalIso",PhotonEcalIso, &b_PhotonEcalIso); */
/* fChain->SetBranchAddress("PhotonHcalIso",PhotonHcalIso, &b_PhotonHcalIso); */
/* fChain->SetBranchAddress("PhotonCaloIso",PhotonCaloIso, &b_PhotonCaloIso); */
/* fChain->SetBranchAddress("PhotonParticleIso",PhotonParticleIso, &b_PhotonParticleIso); */
/* fChain->SetBranchAddress("PhotonChargedHadronIso",PhotonChargedHadronIso, &b_PhotonChargedHadronIso); */
/* fChain->SetBranchAddress("PhotonNeutralHadronIso",PhotonNeutralHadronIso, &b_PhotonNeutralHadronIso); */
/* fChain->SetBranchAddress("PhotonIso",PhotonIso, &b_PhotonIso); */
/* fChain->SetBranchAddress("PhotonHadronicOverEm",PhotonHadronicOverEm, &b_PhotonHadronicOverEm); */
/* fChain->SetBranchAddress("PhotonSigmaEtaEta",PhotonSigmaEtaEta, &b_PhotonSigmaEtaEta); */
/* fChain->SetBranchAddress("PhotonSigmaIetaIeta",PhotonSigmaIetaIeta, &b_PhotonSigmaIetaIeta); */
/* fChain->SetBranchAddress("PhotonE3x3",PhotonE3x3, &b_PhotonE3x3); */
/* fChain->SetBranchAddress("PhotonE5x5",PhotonE5x5, &b_PhotonE5x5); */
/* fChain->SetBranchAddress("PhotonR9",PhotonR9, &b_PhotonR9); */
/* fChain->SetBranchAddress("PhotonSuperClustereta",PhotonSuperClustereta, &b_PhotonSuperClustereta); */
/* fChain->SetBranchAddress("PhotonLMT",PhotonLMT, &b_PhotonLMT); */
/* fChain->SetBranchAddress("PhotonPassElVeto",PhotonPassElVeto, &b_PhotonPassElVeto); */
   fChain->SetBranchAddress("NJets",&NJets, &b_NJets); 
   fChain->SetBranchAddress("JetPx",JetPx, &b_JetPx); 
   fChain->SetBranchAddress("JetPy",JetPy, &b_JetPy); 
   fChain->SetBranchAddress("JetPz",JetPz, &b_JetPz); 
   fChain->SetBranchAddress("JetPt",JetPt, &b_JetPt); 
   fChain->SetBranchAddress("JetEta",JetEta, &b_JetEta); 
   fChain->SetBranchAddress("JetPhi",JetPhi, &b_JetPhi); 
   fChain->SetBranchAddress("JetEnergy",JetEnergy, &b_JetEnergy);
   fChain->SetBranchAddress("JetEmEnergy",JetEmEnergy, &b_JetEmEnergy);
   fChain->SetBranchAddress("JetHadronEnergy",JetHadronEnergy, &b_JetHadronEnergy);
/* fChain->SetBranchAddress("JetCSV",JetCSV, &b_JetCSV); */
/* fChain->SetBranchAddress("JetpfCombinedMVAV2BJetTags",JetpfCombinedMVAV2BJetTags, &b_JetpfCombinedMVAV2BJetTags); */
/* fChain->SetBranchAddress("JetpfJetProbabilityBJetTags",JetpfJetProbabilityBJetTags, &b_JetpfJetProbabilityBJetTags); */
/* fChain->SetBranchAddress("JethadronFlavour",JethadronFlavour, &b_JethadronFlavour); */
/* fChain->SetBranchAddress("NGenJets",&NGenJets, &b_NGenJets); */
/* fChain->SetBranchAddress("GenJetPx",GenJetPx, &b_GenJetPx); */
/* fChain->SetBranchAddress("GenJetPy",GenJetPy, &b_GenJetPy); */
/* fChain->SetBranchAddress("GenJetPz",GenJetPz, &b_GenJetPz); */
/* fChain->SetBranchAddress("GenJetPt",GenJetPt, &b_GenJetPt); */
/* fChain->SetBranchAddress("GenJetEta",GenJetEta, &b_GenJetEta); */
/* fChain->SetBranchAddress("GenJetPhi",GenJetPhi, &b_GenJetPhi); */
/* fChain->SetBranchAddress("GenJetEnergy",GenJetEnergy, &b_GenJetEnergy); */

/* fChain->SetBranchAddress("MET2Pt",&MET2Pt, &b_MET2Pt); */
/* fChain->SetBranchAddress("MET2Phi",&MET2Phi, &b_MET2Phi); */
/* fChain->SetBranchAddress("HLT_Mu50",&HLT_Mu50, &b_HLT_Mu50); */
/* fChain->SetBranchAddress("HLT_IsoMu20",&HLT_IsoMu20, &b_HLT_IsoMu20); */
/* fChain->SetBranchAddress("HLT_IsoTkMu18",&HLT_IsoTkMu18, &b_HLT_IsoTkMu18); */
/* fChain->SetBranchAddress("HLT_IsoMu22",&HLT_IsoMu22, &b_HLT_IsoMu22); */
/* fChain->SetBranchAddress("HLT_IsoTkMu22",&HLT_IsoTkMu22, &b_HLT_IsoTkMu22); */
/* fChain->SetBranchAddress("HLT_IsoMu24",&HLT_IsoMu24, &b_HLT_IsoMu24); */
/* fChain->SetBranchAddress("HLT_IsoTkMu24",&HLT_IsoTkMu24, &b_HLT_IsoTkMu24); */
/* fChain->SetBranchAddress("HLT_IsoMu27",&HLT_IsoMu27, &b_HLT_IsoMu27); */
/* fChain->SetBranchAddress("HLT_IsoTkMu27",&HLT_IsoTkMu27, &b_HLT_IsoTkMu27); */
/* fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_LooseIsoPFTau20",&HLT_IsoMu17_eta2p1_LooseIsoPFTau20, &b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20); */
/* fChain->SetBranchAddress("HLT_IsoMu19_eta2p1_LooseIsoPFTau20",&HLT_IsoMu19_eta2p1_LooseIsoPFTau20, &b_HLT_IsoMu19_eta2p1_LooseIsoPFTau20); */
/* fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ",&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ); */
/* fChain->SetBranchAddress("HLT_DiMu9_Ele9_CaloIdL_TrackIdL",&HLT_DiMu9_Ele9_CaloIdL_TrackIdL, &b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL); */
/* fChain->SetBranchAddress("HLT_TripleMu_12_10_5",&HLT_TripleMu_12_10_5, &b_HLT_TripleMu_12_10_5); */
/* fChain->SetBranchAddress("HLT_Mu17_Mu8_SameSign_DZ",&HLT_Mu17_Mu8_SameSign_DZ, &b_HLT_Mu17_Mu8_SameSign_DZ); */
/* fChain->SetBranchAddress("HLT_Mu20_Mu10_SameSign_DZ",&HLT_Mu20_Mu10_SameSign_DZ, &b_HLT_Mu20_Mu10_SameSign_DZ); */
/* fChain->SetBranchAddress("HLT_Photon175",&HLT_Photon175, &b_HLT_Photon175); */
/* fChain->SetBranchAddress("HLT_Photon120",&HLT_Photon120, &b_HLT_Photon120); */
/* fChain->SetBranchAddress("HLT_Photon90",&HLT_Photon90, &b_HLT_Photon90); */
/* fChain->SetBranchAddress("HLT_Photon75",&HLT_Photon75, &b_HLT_Photon75); */
/* fChain->SetBranchAddress("HLT_Photon50",&HLT_Photon50, &b_HLT_Photon50); */
/* fChain->SetBranchAddress("HLT_Photon30",&HLT_Photon30, &b_HLT_Photon30); */
 }

Bool_t FTAna::Notify()
{
   return kTRUE;
}
int FTAna::ReadLimited(int level, Long64_t entry)
{
  // This function is meant to speed up your run-time.
  // It does this by not reading in all branches for an event,
  // but only those that we tell it to.
  // With level=0, the whole event is read-in. This is default behavior.
  // With level=1, you turn on only needed variables.

  if(level==0){ GetEntry(entry); return 1; }
  if(level==1){
    //Turn on only those branches that we need
   
    
    b_NElectrons->GetEntry(entry);
    b_ElectronPt->GetEntry(entry);
    b_ElectronEta->GetEntry(entry);
    b_ElectronPhi->GetEntry(entry);
    b_ElectronIsMedium->GetEntry(entry);
    b_ElectronIsTrigger->GetEntry(entry);
    b_ElectronPFIsolation->GetEntry(entry);
    b_ElectronTrackIso->GetEntry(entry);
    b_ElectronEcalIso->GetEntry(entry);
    b_ElectronHcalIso->GetEntry(entry);
    b_ElectrondeltaEtaSuperClusterTrackAtVtx->GetEntry(entry);
    b_ElectrondeltaPhiSuperClusterTrackAtVtx->GetEntry(entry);
    b_ElectronsigmaIetaIeta->GetEntry(entry);
    b_ElectronhadronicOverEm->GetEntry(entry);
    b_ElectronFbrem->GetEntry(entry);
    b_ElectronEoverP->GetEntry(entry);
    b_ElectronecalEnergy->GetEntry(entry);
    b_Electronp_in->GetEntry(entry);
    b_ElectronDxy->GetEntry(entry);
    b_ElectronDz->GetEntry(entry);
    b_ElectronnumberOfLostHits->GetEntry(entry);
    b_ElectronsuperClustereta->GetEntry(entry);
    b_NTowers->GetEntry(entry);
    b_TowerEta->GetEntry(entry);
    b_TowerPhi->GetEntry(entry);
    b_TowerEnergy->GetEntry(entry);
    b_TowerEmEnergy->GetEntry(entry);
    b_NJets->GetEntry(entry);
    b_JetEta->GetEntry(entry);
    b_JetPx->GetEntry(entry);
    b_JetPy->GetEntry(entry);
    b_JetPz->GetEntry(entry);
    b_JetPt->GetEntry(entry);
    b_JetPhi->GetEntry(entry);
    b_JetEnergy->GetEntry(entry);
    b_JetEmEnergy->GetEntry(entry);
    b_JetHadronEnergy->GetEntry(entry);
    if(_data==1){
      b_NMC->GetEntry(entry);
      b_MCPt->GetEntry(entry);
      b_MCEta->GetEntry(entry);
      b_MCPhi->GetEntry(entry);
      b_MCId->GetEntry(entry);
      b_MCEnergy->GetEntry(entry);
      b_MCStatus->GetEntry(entry);
      b_MCIndex->GetEntry(entry);
      b_MCCharge->GetEntry(entry);
      b_MCMass->GetEntry(entry);
      b_NMCmother->GetEntry(entry);
      b_MCMotherIndex->GetEntry(entry);
    }
    //    b_ElectronEnergy->GetEntry(entry);

    return 1;
  }
  
  return 0;
}
#endif // #ifdef FTAna_cxx

