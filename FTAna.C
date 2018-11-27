#define FTAna_cxx

#include "FTAna.h"
#include <TH2.h>
#include <TStyle.h>


void FTAna::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.<<
  // The tree argument is deprecated (on PROOF 0 is passed).
  TString option = GetOption();
}
void FTAna::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).
  TString option = GetOption();
  //Initialize global variables here.
  GEV = 1000.;    MEV2GEV = .001;
  nEvtTotal = 0; count=0;for(int i=0;i<101;i++) pass[i]=0;
  //sampleno=_sample;
  
  //Create the histogram file
  _HstFile = new TFile(_HstFileName,"recreate");
 
  //Call the function to book the histograms we declared in Hists.
  BookHistograms();
  //cout<<"Began"<<endl;
}
void FTAna::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.
  //Write histograms and close histogram file
  _HstFile->Write();
  _HstFile->Close();
  //Output to screen.
  cout<<"Total events = "<<nEvtTotal<<endl;
  cout<<"Total histograms ="<<count<<endl;
  //  cout<<"Total pass ="<<pass<<endl;
  //Open the text output file
  ofstream fout(_SumFileName);
  //Put text output in the summary file.
  fout<<"Total events  = "<<nEvtTotal<<endl;
  fout<<"Signal passing the cut = [";
  for(int i=0;i<100;i++) fout<<pass[i]<<",";
  fout<<pass[100]<<"]"<<endl;
}
void FTAna::Terminate()
{
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.
}
Bool_t FTAna::Process(Long64_t entry)
{
  //
  // This function should contain the "body" of the analysis. It can contain
  // simple or elaborate selection criteria, run algorithms on the data
  // of the event and typically fill histograms.
  //
  // The return value is currently not used.

  // Decide to read in whole event or just some branches.
    int readevent = ReadLimited(1,entry);
    if(readevent==0){ cout<<"Did not read in any branches.. quitting."<<endl; return kTRUE;}
    //Increment counter of number of events read in.
    nEvtTotal++;
    //Output processing information to screen based on verbosity level.
    if(_verbosity>1000 && nEvtTotal%10000==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;      
    else if(_verbosity>0 && nEvtTotal%50000==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;
  
    //Your CODE starts here
    /* At the moment the code does the following.
       It loops over all electron candidates (NElectrons). 
       It creates a Lepton object from information about the electron
       candidates. It checks if the electron candidate passes some quality 
       criteria (pass_electron_cuts). If the electron candidate does pass then,
       then it is stored in an array of good Electrons (goodEle).

       Histograms are filled with different properties of interested objects.
       Eta phi images of electrons are plotted. 

    */
    Ele.clear(); //clear array from previous event
    if(_sample==1){
      goodEle.clear(); //clear array from previous event
      h.ngoodele[0]->Fill(NElectrons); //fill a histogram with total number of electron candidates
      for(int i=0; i<NElectrons; i++){ //Loop over electrons
	//Declared a temporary instance of a Lepton
	//and set its properties for this candidate.
	Lepton temp; temp.v.SetPtEtaPhiM(ElectronPt[i],ElectronEta[i],ElectronPhi[i],0.0005); 
	//ID = PDGId*Charge. The PDGId of a electron is 11.
	//See here for all PDGIds (http://pdg.lbl.gov/2007/reviews/montecarlorpp.pdf)
	temp.id = -11*ElectronCharge[i]; temp.ind = i;temp.plot=false; 
	h.ptlep[0]->Fill(temp.v.Pt()); //fill a histogram with pT of this electron candidate
	if(pass_electron_cuts(10,i,temp.v)){//check if this candidate passes selections.
	  if(ElectronIsLoose(i)){//check if this candidate passes selections.
	    goodEle.push_back(temp); //store it in the goodEle array.
	    h.ptlep[1]->Fill(temp.v.Pt());//fill a histogram of with pT of this candidate.
	  }
	}
      }
      Sort(1);//sort the goodEle array descending by pT.
      h.ngoodele[1]->Fill((int)goodEle.size());//fill a histogram with number of electrons.
      if((int)goodEle.size()>0)//check if at least one electron passed
	if((int)goodEle.size()>1){
	  double mass=(goodEle.at(0).v+goodEle.at(1).v).M();
	  h.mass->Fill(mass);
	  if(mass>81 && mass<101) Ele.push_back(goodEle.at(0)); // Collect the Leading Electron from a Z boson decay
	}
      for(int i=0;i<NTowers;i++){ // Loop over all calorimeter towers to collect the calorimeter tower information
	h.bin[0]->Fill(TowerEta[i]);
	h.bin[1]->Fill(TowerPhi[i]);
	h.bin[2]->Fill(TowerEnergy[i]);
      }
    }
    if(_sample==2){
      goodEle.clear();
      goodJet.clear();
      h.ngoodele[0]->Fill(NElectrons); //fill a histogram with total number of electron candidates
      for(int i=0; i<NElectrons; i++){ //Loop over electrons
	//Declared a temporary instance of a Lepton
	//and set its properties for this candidate.
	Lepton temp; temp.v.SetPtEtaPhiM(ElectronPt[i],ElectronEta[i],ElectronPhi[i],0.0005); 
	//ID = PDGId*Charge. The PDGId of a electron is 11.
	//See here for all PDGIds (http://pdg.lbl.gov/2007/reviews/montecarlorpp.pdf)
	temp.id = -11*ElectronCharge[i]; temp.ind = i;temp.plot=false;
	h.ptlep[0]->Fill(temp.v.Pt()); //fill a histogram with pT of this electron candidate
	if(pass_electron_cuts(10,i,temp.v) && ElectronIsMedium[i]){
	  if(ElectronIsTight(i)){
	    Ele.push_back(temp);
	    h.ptlep[1]->Fill(temp.v.Pt());
	  }
	}
      }
      h.ngoodele[1]->Fill((int)Ele.size());
      h.ngoodjet[0]->Fill(NJets);
      int b_count=0;
      for(int i=0;i<NJets;i++){
	Lepton temp; temp.v.SetPxPyPzE(JetPx[i],JetPy[i],JetPz[i],JetEnergy[i]);
	temp.ind=i;temp.b_tag=b_tag(temp);
	goodJet.push_back(temp);
	h.ptlep[2]->Fill(temp.v.Pt());
	if(temp.b_tag) b_count++;
      }
      h.ngoodjet[1]->Fill(b_count);
      if(_data==1){
	int b_count_gen=0;
	int b_meson_count_gen=0;
	for(int i=0;i<NMC;i++){
	  if(fabs(MCId[i])==5){
	    b_count_gen++;
	    h.ptlep[4]->Fill(MCPt[i]);
	    h.motherid[1]->Fill(MCId[MCMotherIndex[i]]);
	    int jet= match_index_jet_mc(i);
	    h.ptlep[6]->Fill(MCPt[i]/JetPt[jet]);
	  }
	  if(fabs(MCId[i])>500 && fabs(MCId[i])<600 && b_meson_mother(i)){
	    b_meson_count_gen++;
	    h.ptlep[5]->Fill(MCPt[i]);
	    h.motherid[2]->Fill(MCId[MCMotherIndex[i]]);
	    int jet= match_index_jet_mc(i);
	    h.ptlep[7]->Fill(MCPt[i]/JetPt[jet]);
	  }
	}
	h.ngoodele[2]->Fill(b_count_gen);
	h.ngoodele[3]->Fill(b_meson_count_gen);
      }
    }
    if(_sample==4){
      h.ngoodele[0]->Fill(NElectrons); //fill a histogram with total number of electron candidates
      for(int i=0; i<NElectrons; i++){ //Loop over electrons
	//Declared a temporary instance of a Lepton
	//and set its properties for this candidate.
	Lepton temp; temp.v.SetPtEtaPhiM(ElectronPt[i],ElectronEta[i],ElectronPhi[i],0.0005); 
	//ID = PDGId*Charge. The PDGId of a electron is 11.
	//See here for all PDGIds (http://pdg.lbl.gov/2007/reviews/montecarlorpp.pdf)
	temp.id = -11*ElectronCharge[i]; temp.ind = i;temp.plot=false;
	h.ptlep[0]->Fill(temp.v.Pt()); //fill a histogram with pT of this electron candidate
	if(pass_electron_cuts(10,i,temp.v) && ElectronIsMedium[i]){
	  if(ElectronIsTight(i)){
	    Ele.push_back(temp);
	    h.ptlep[1]->Fill(temp.v.Pt());
	  }
	}
      }
      h.ngoodele[1]->Fill((int)Ele.size());
    }
    for(int i=0;i<(int)Ele.size();i++){ //Loop over all electron of interest
      if(_data==1){ // If the tree comes from simulation
	int match_index=get_match_index(Ele.at(i));
	if(match_index!=-1){
	  // int mother_index=MCMotherIndex[match_index];
	  // int mother_id=MCId[mother_index]; //Find the mother of matching truth particle
	  int match_jet=match_index_jet(Ele.at(i));
	  if(match_jet != -1 && goodJet.at(match_jet).b_tag && goodJet.at(match_jet).ind==match_jet){
	    if(Ele.at(i).v.Pt()>10 && Ele.at(i).v.Pt()<30) {
	      Ele.at(i).plot=true; // If the mother is not a Z or W boson and pT falls in the desired range, eta phi image of eletron is made
	    }
	  }
	  //h.motherid[0]->Fill(mother_id);
	  h.index[0]->Fill(MCId[match_index]); //Plot the matching truth particle index
	}
      }
      if(Ele.at(i).plot){
	h.eta->Fill(Ele.at(i).v.Eta());
	float riso=ElectronPFIsolation[Ele.at(i).ind]/Ele.at(i).v.Pt();
	float trkiso=ElectronTrackIso[Ele.at(i).ind];
	float caliso=ElectronEcalIso[Ele.at(i).ind]+ElectronHcalIso[Ele.at(i).ind];
	float rel_trkiso=trkiso/Ele.at(i).v.Pt();
	float rel_caliso=caliso/Ele.at(i).v.Pt();
      
	h.pfiso[0]->Fill(riso);
	h.pfiso[1]->Fill(ElectronPFIsolation[Ele.at(i).ind]);
	h.pfiso[4]->Fill(rel_trkiso);
	h.pfiso[6]->Fill(rel_caliso);
	h.pfiso[8]->Fill(trkiso);
	h.pfiso[10]->Fill(caliso);
	h.iso[0]->Fill(caliso,trkiso);
	h.iso[1]->Fill(rel_caliso,rel_trkiso); //plot isolation of electrons
     
	if(riso<0.01){
	  h.pfiso[5]->Fill(rel_trkiso);
	  h.pfiso[7]->Fill(rel_caliso);
	  h.pfiso[9]->Fill(trkiso);
	  h.pfiso[11]->Fill(caliso);
	  h.iso[2]->Fill(caliso,trkiso);
	  h.iso[3]->Fill(rel_caliso,rel_trkiso);
	}
	if(count<3612){
	  for(int j=0;j<101;j++){
	    float cp=(float)j*0.01;
	    if(riso>=cp) pass[j]++;
	  }
	}
	plot(Ele.at(i),count); // make the image
	count++;
      
      
      }
    }
  
    //h.etmiss->Fill(METPt);//fill a histogram with the missing Et of the event.

  
    return kTRUE;
}
void FTAna::plot(Lepton ele,int plotno){
  for(int j=0;j<NTowers;j++){
    double deltaphi=delta_phi(ele.v.Phi(),TowerPhi[j]);
    double deltaeta=ele.v.Eta()-TowerEta[j];
    double delta_phi=ele.v.Phi()-TowerPhi[j];
    double deltar=deltaR(deltaeta,deltaphi);
    h.deltaR[0]->Fill(deltar);
    // h.delta_eta->Fill(deltaeta);
    // h.delta_phi->Fill(delta_phi);
    if(deltar<0.3){
      if(plotno<30001) h.plots[plotno]->Fill(deltaeta,delta_phi,TowerEnergy[j]);
      //if(plotno==0) h.img->Fill(TowerEta[j],TowerPhi[j],TowerEnergy[j]);
    }
  }
}

bool FTAna::pass_electron_cuts(int level, int i, TLorentzVector v)
{
  //Apply selections based on the chosen level.
  bool result = false;
  if(level==10){
    result = v.Pt()>10 && fabs(v.Eta())<2.4;
    //result = result && ElectronisGlobal[i]>0;
  }
  if(level==11){
    result = v.Pt()>10 && fabs(v.Eta())<2.4;
    //result = result && ElectronisGlobal[i]>0;
    //result = result && ElectronTrackIso[i]/v.Pt()<0.25;
  }

  return result;
}
void FTAna::Sort(int opt)
{
  //Sort selected objects by pT (always descending).
  //option 1 sorts the gooEle array
  if(opt==1){
    for(int i=0; i<(int)goodEle.size()-1; i++){
      for(int j=i+1; j<(int)goodEle.size(); j++){
	if( goodEle[i].v.Pt() < goodEle[j].v.Pt() ) swap(goodEle.at(i),goodEle.at(j)); }}
  }
  if(opt==2){
    for(int i=0; i<(int)goodJet.size()-1; i++){
      for(int j=i+1; j<(int)goodJet.size(); j++){
	if( goodJet[i].v.Pt() < goodJet[j].v.Pt() ) swap(goodJet.at(i),goodJet.at(j)); }}
  }
  if(opt==3){
    for(int i=0; i<(int)goodMu.size()-1; i++){
      for(int j=i+1; j<(int)goodMu.size(); j++){
	if( goodMu[i].v.Pt() < goodMu[j].v.Pt() ) swap(goodMu.at(i),goodMu.at(j)); }}
  }
  //Once you have other arrays (goodEle, goodPho), write code here to sort them.
}

double FTAna::delta_phi(float phi1, float phi2)
{
  //Calculate the correct deltaPhi=phi1-phi2
  phi1 = TVector2::Phi_0_2pi(phi1);
  phi2 = TVector2::Phi_0_2pi(phi2);
  double dphi = fabs(phi1 - phi2);
  if(dphi>TMath::Pi()) dphi = 2*TMath::Pi() - dphi;
  return dphi;
}
double FTAna::deltaR(double deltaeta,double deltaphi){
  //double deltaeta=ele.Eta()-towereta;
  double deltar=sqrt(pow(deltaeta,2)+pow(deltaphi,2));
  return deltar;
}
int FTAna::electron_candidate_index(double ef_leading, double ef_subleading){//ef_leading=Em/Had
  if(ef_leading<0.4){
    h.ef[2]->Fill(ef_subleading);
    double ef=1/ef_subleading;
    if(ef<0.356) return 1;
    else return -1;
  }
  else if(ef_subleading<0.4){
    h.ef[2]->Fill(ef_leading);
    double ef=1/ef_leading;
    if(ef<0.356) return 0;
    else return -1;
  }
  else return -1;
}
int FTAna::get_match_index(Lepton ele){
  int index=-1;
  double minDR=0.1;
  double minDpt=3;
  double eta=ele.v.Eta();
  double phi=ele.v.Phi();
  for(int i=0;i<NMC;i++){
    double deltaeta=eta-MCEta[i];
    double deltaphi=delta_phi(phi,MCPhi[i]);
    double dr=(deltaR(deltaeta,deltaphi));
    h.deltaR[1]->Fill(dr);
    if(dr<minDR){
      double dpt=fabs(ele.v.Pt()-MCPt[i]);
      //h.dpt->Fill(dpt);
      index=i;
      minDR=dr;
    }
  }
  return index;
}
int FTAna::match_index_jet(Lepton pion){
  double mindr=0.5;
  int index=-1;
  for(int i=0;i<NJets;i++){
    double deltaeta=pion.v.Eta()-JetEta[i];
    double deltaphi=delta_phi(pion.v.Phi(),JetPhi[i]);
    double dr=deltaR(deltaeta,deltaphi);
    if(dr<mindr){
      mindr=dr;
      index=i;
    }
  }
  return index;
}
int FTAna::match_index_jet_mc(int MCIndex){
  double mindr=0.5;
  int index=-1;
  for(int i=0;i<NJets;i++){
    double deltaeta=MCEta[MCIndex]-JetEta[i];
    double deltaphi=delta_phi(MCPhi[MCIndex],JetPhi[i]);
    double dr=deltaR(deltaeta,deltaphi);
    if(dr<mindr){
      mindr=dr;
      index=i;
    }
  }
  return index;
}
// double FTAna::dr_pion_jet(Lepton pion, int match_index){
//   if(match_index!=-1){
//   double deltaeta=pion.v.Eta()-JetEta[match_index];
//   double deltaphi=delta_phi(pion.v.Phi(),JetPhi[match_index]);
//   double dr=deltaR(deltaeta,deltaphi);
//   return dr;
//   }
//   else return 100;
// }

FTAna::Match FTAna::b_match(Lepton jet){
  double mindr=100;
  int index=-1;
  Match m;
  for(int i=0;i<NMC;i++){
    int id = fabs(MCId[i]);
    if(id>500 && id < 600){
      double deltaeta=MCEta[i]-jet.v.Eta();
      double deltaphi=delta_phi(MCPhi[i],jet.v.Phi());
      double dr=deltaR(deltaeta,deltaphi);
      if(dr<mindr){ mindr=dr;
	index=i;
      }
    } 
  }
  m.mindr=mindr;
  m.index=index;
  return m;
}
bool FTAna::b_tag(Lepton jet){
  Match m=b_match(jet);
  h.deltaR[2]->Fill(m.mindr);
  if(m.mindr<0.5){
    double ptratio=MCPt[m.index]/jet.v.Pt();
    if(ptratio>0.2) return true;
  }
  return false;
}
bool FTAna::b_meson_mother(int MCIndex){
  int mcid=MCId[MCIndex];
  int mother_index=MCMotherIndex[MCIndex];
  int mother_id=MCId[mother_index];
  if(fabs(mother_id)>500 && fabs(mother_id)<600) return false;
  else return true;
}
bool FTAna::ElectronIsTight(int index){
  bool isTightBarrel = ( fabs(ElectronsuperClustereta[index]) <=1.479 &&
			 fabs(ElectrondeltaPhiSuperClusterTrackAtVtx[index]) < 0.03 &&
			 ElectronnumberOfLostHits[index] <=0);
  bool isTightEndcap = ( fabs(ElectronsuperClustereta[index]) >1.479 &&
			 fabs(ElectronsuperClustereta[index]) < 2.500 &&
			 fabs(ElectrondeltaEtaSuperClusterTrackAtVtx[index]) <0.005 &&
			 fabs(ElectrondeltaPhiSuperClusterTrackAtVtx[index]) < 0.02 &&
			 ElectronnumberOfLostHits[index] <=0);
  return isTightBarrel || isTightEndcap;
			 
}
bool FTAna::ElectronIsLoose(int index){
  bool isLooseBarrel = ( fabs(ElectronsuperClustereta[index]) <= 1.479 &&
			 fabs(ElectrondeltaEtaSuperClusterTrackAtVtx[index]) <0.007 &&
			 fabs(ElectrondeltaPhiSuperClusterTrackAtVtx[index]) < 0.15 &&
			 ElectronsigmaIetaIeta[index] < 0.01 &&
			 ElectronhadronicOverEm[index] < 0.12 &&
			 fabs(ElectronDxy[index]) <0.02 &&
			 fabs(ElectronDz[index]) < 0.2 &&
			 fabs(1.0/ElectronecalEnergy[index] - 1.0/Electronp_in[index]) < 0.05 &&
			 ElectronnumberOfLostHits[index] <=1);
  bool isLooseEndcap = ( fabs(ElectronsuperClustereta[index]) > 1.479 &&
			 fabs(ElectronsuperClustereta[index]) < 2.500 &&
			 fabs(ElectrondeltaEtaSuperClusterTrackAtVtx[index]) <0.009 &&
			 fabs(ElectrondeltaPhiSuperClusterTrackAtVtx[index]) < 0.10 &&
			 ElectronsigmaIetaIeta[index] < 0.03 &&
			 ElectronhadronicOverEm[index] < 0.10 &&
			 fabs(ElectronDxy[index]) <0.02 &&
			 fabs(ElectronDz[index]) < 0.2 &&
			 fabs(1.0/ElectronecalEnergy[index] - 1.0/Electronp_in[index]) < 0.05 &&
			 ElectronnumberOfLostHits[index] <=1);
  return isLooseBarrel || isLooseEndcap;
}
void FTAna::BookHistograms()
{
  // Booking syntax for histogram pointers (that we declared in struct Hists in header)
  // obj = new CLASS("localname","Histogram title",NumberOfBins,LowerEdge,HigherEdge)
  if(_sample==1){
    h.ngoodele[0] = new TH1F("ngoodele0","Number of Electron Candidates",10,0,10);
    h.ngoodele[1] = new TH1F("ngoodele1","Number of Electron Candidates",10,0,10);
    //h.ngoodele[2] = new TH1F("ngoodele2","Number of Electron Candidates",10,0,10);
    //h.ngoodele[3] = new TH1F("ngoodele3","Number of Electron Candidates",10,0,10);
    //h.ngoodele[4] = new TH1F("ngoodele4","Number of Electron Candidates",10,0,10);
    //h.ngoodele[5] = new TH1F("ngoodele5","Number of Electron Candidates",10,0,10);
    for(int i=0; i<2; i++) h.ngoodele[i]->Sumw2();
    h.ptlep[0] = new TH1F("ptele0","Electron candidate p_{T}",200,0,100);
    h.ptlep[1] = new TH1F("ptele1","Electron p_{T}",200,0,200);
    h.ptlep[2] = new TH1F("ptele2","Leading Electron p_{T}",200,0,200);
    for(int i=0; i<3; i++) h.ptlep[i]->Sumw2();
    h.mass = new TH1F("mass","Invariant Mass",200,0,200); h.mass->Sumw2();
    h.deltaR[0] = new TH1F("deltaR","deltaR",1000,0,10); h.deltaR[0]->Sumw2();
    h.deltaR[1] = new TH1F("deltaR_mc","deltaR_mc",1000,-10,10); h.deltaR[1]->Sumw2();
    h.dpt = new TH1F("dpt","dpt",1000,-10,10);h.dpt->Sumw2();
    h.motherid[0] = new TH1F("motherid","motherid",200,-100,100);h.motherid[0]->Sumw2();
    h.delta_eta = new TH1F("deltaEta","deltaEta",100,-1,1); h.delta_eta->Sumw2();
    h.delta_phi = new TH1F("deltaPhi","deltaPhi",100,-1,1); h.delta_phi->Sumw2();
    h.bin[0] = new TH1F("towereta","towereta",80000,-0.4,0.4);
    h.bin[1] = new TH1F("towerphi","towerphi",160000,-0.8,0.8);
    h.bin[2] = new TH1F("toweenergy","towerenergy",10000,0,10);
    //h.etmiss = new TH1F("etmiss","Missing E_{T}",500,0,500); h.etmiss->Sumw2();
    h.index[0] = new TH1F("match_id","Match Id",200,-100,100);
    h.index[1] = new TH1F("check","Mother id = particle id",10,0,10);
    h.pfiso[0] = new TH1F("rpfiso","Isolation/pT",1000,0,10);
    h.pfiso[1] = new TH1F("pfiso","Isolation",10000,0,100);
    h.pfiso[2] = new TH1F("rpfiso_pion","Isolation of pion",1000,0,10);
    h.pfiso[3] = new TH1F("rpfiso_notpion","Isolation of electrons not matched to pion",1000,0,10);
    h.pfiso[4] = new TH1F("rel_trackiso","Relative Track Isolation of electrons",1000,0,10);
    h.pfiso[5] = new TH1F("rel_trackiso_iso","Relative Track Isolation of isolated electrons",1000,0,10);
    h.pfiso[6] = new TH1F("rel_caliso","Relative Calorimeter Isolation of electrons",1000,0,10);
    h.pfiso[7] = new TH1F("rel_caliso_iso","Relative Calorimeter Isolation of isolated electrons",1000,0,10);
    h.pfiso[8] = new TH1F("trackiso","Track Isolation of electrons",1000,0,100);
    h.pfiso[9] = new TH1F("trackiso_iso","Track Isolation of isolated electrons",1000,0,100);
    h.pfiso[10] = new TH1F("caliso","Calorimeter Isolation of electrons",1000,0,100);
    h.pfiso[11] = new TH1F("caliso_iso","Calorimeter Isolation of isolated electrons",1000,0,100);
    h.iso[0] = new TH2F("trackiso_caliso","Track Isolation versus calorimeter isolation of electron",1000,0,100,1000,0,100);
    h.iso[1] = new TH2F("rel_trackiso_rel_caliso","Relative track tsolation versus relative calorimeter isolation of electron",1000,0,10,1000,0,10);
    h.iso[2] = new TH2F("trackiso_iso_caliso_iso","Track Isolation versus calorimeter isolation of isolated electron",1000,0,100,1000,0,100);
    h.iso[3] = new TH2F("rel_trackiso_iso_rel_caliso_iso","Relative track tsolation versus relative calorimeter isolation of isolatedelectron",1000,0,10,1000,0,10);
    h.eta = new TH1F("eta","eta",80,-4,4);
    h.img = new TH2F("img","img",400,-3.48,3.48,400,-3.48,3.48);
    h.img->GetXaxis()->SetTitle("Eta");
    h.img->GetYaxis()->SetTitle("Phi");
    for(int i=0;i<30001;i++){
      string str=to_string(i);
      const char* ch=str.c_str();
      h.plots[i] = new TH2F(ch,"Image",40,-0.348,0.348,40,-0.348,0.348);
      h.plots[i]->GetXaxis()->SetTitle("Eta");
      h.plots[i]->GetYaxis()->SetTitle("Phi");
      //cout<<"booked histograms"<<endl;
    }
  }
  if(_sample==2){
    h.ngoodele[0] = new TH1F("ngoodele0","Number of Electron Candidates",10,0,10);
    h.ngoodele[1] = new TH1F("ngoodele1","Number of Electron Candidates",10,0,10);
    h.ngoodele[2] = new TH1F("nb","Number of b",10,0,10);
    h.ngoodele[3] = new TH1F("nbmeson","Number of b meson",10,0,10);
    for(int i=0; i<4; i++) h.ngoodele[i]->Sumw2();
    h.ngoodjet[0] = new TH1F("ngoodjet","Number of Jet candidates",20,0,20);
    h.ngoodjet[1] = new TH1F("bjet","Number of b jet",20,0,20);
    for(int i=0; i<2; i++) h.ngoodjet[i]->Sumw2();
    h.ptlep[0] = new TH1F("ptele0","Electron candidate p_{T}",200,0,100);
    h.ptlep[1] = new TH1F("ptele1","Electron p_{T}",200,0,200);
    h.ptlep[2] = new TH1F("ptjet","Jet pT",200,0,200);
    h.ptlep[3] = new TH1F("ptratio","Ratio of pT of b to pT of jet",1000,0,10);
    h.ptlep[4] = new TH1F("ptb","b pT",200,0,200);
    h.ptlep[5] = new TH1F("ptbmeson","pT of b meson",200,0,200);
    h.ptlep[6] = new TH1F("ptratio_b","Ratio of pT of all b to the pT of matching jet",1000,0,10);
    h.ptlep[7] = new TH1F("ptratio_b_meson","Ratio of pT of all b meson to the pT of matching jet",1000,0,10);
    for(int i=0; i<8; i++) h.ptlep[i]->Sumw2();
    h.deltaR[0] = new TH1F("deltaR","deltaR",1000,0,10); h.deltaR[0]->Sumw2();
    h.deltaR[1] = new TH1F("deltaR_mc","deltaR_mc",1000,0,10); h.deltaR[1]->Sumw2();
    h.deltaR[2] = new TH1F("deltaR_jet_b","deltaR between jet and closest b meson",1000,0,10); h.deltaR[2]->Sumw2();
    h.dpt = new TH1F("dpt","dpt",10000,-500,500);h.dpt->Sumw2();
    h.motherid[0] = new TH1F("motherid","motherid",1200,-600,600);
    h.motherid[1] = new TH1F("motherid_b","Mother of b",1200,-600,600);
    h.motherid[2] = new TH1F("motherid_bmeson","Mother of b meson",1200,-600,600);
    for(int i=0;i<3;i++) h.motherid[i]->Sumw2();
    h.index[0] = new TH1F("match_id","Match Id",1200,-600,600);
    h.pfiso[0] = new TH1F("rpfiso","Isolation",1000,0,10);
    h.pfiso[1] = new TH1F("pfiso","Isolation",10000,0,100);
    h.pfiso[2] = new TH1F("rpfiso_pion","Isolation of pion",1000,0,10);
    h.pfiso[3] = new TH1F("rpfiso_notpion","Isolation of electrons not matched to pion",1000,0,10);
    h.pfiso[4] = new TH1F("rel_trackiso","Relative Track Isolation of electrons",1000,0,10);
    h.pfiso[5] = new TH1F("rel_trackiso_iso","Relative Track Isolation of isolated electrons",1000,0,10);
    h.pfiso[6] = new TH1F("rel_caliso","Relative Calorimeter Isolation of electrons",1000,0,10);
    h.pfiso[7] = new TH1F("rel_caliso_iso","Relative Calorimeter Isolation of isolated electrons",1000,0,10);
    h.pfiso[8] = new TH1F("trackiso","Track Isolation of electrons",1000,0,100);
    h.pfiso[9] = new TH1F("trackiso_iso","Track Isolation of isolated electrons",1000,0,100);
    h.pfiso[10] = new TH1F("caliso","Calorimeter Isolation of electrons",1000,0,100);
    h.pfiso[11] = new TH1F("caliso_iso","Calorimeter Isolation of isolated electrons",1000,0,100);
    h.iso[0] = new TH2F("trackiso_caliso","Track Isolation versus calorimeter isolation of electron",1000,0,100,1000,0,100);
    h.iso[1] = new TH2F("rel_trackiso_rel_caliso","Relative track tsolation versus relative calorimeter isolation of electron",1000,0,10,1000,0,10);
    h.iso[2] = new TH2F("trackiso_iso_caliso_iso","Track Isolation versus calorimeter isolation of isolated electron",1000,0,100,1000,0,100);
    h.iso[3] = new TH2F("rel_trackiso_iso_rel_caliso_iso","Relative track tsolation versus relative calorimeter isolation of isolatedelectron",1000,0,10,1000,0,10);
    h.eta = new TH1F("eta","eta",80,-4,4);
    for(int i=0;i<30001;i++){
      string str=to_string(i);
      const char* ch=str.c_str();
      h.plots[i] = new TH2F(ch,"Image",40,-0.348,0.348,40,-0.348,0.348);
      h.plots[i]->GetXaxis()->SetTitle("Eta");
      h.plots[i]->GetYaxis()->SetTitle("Phi");
      //
    }
  }
  if(_sample==4){
    h.ngoodele[0] = new TH1F("ngoodele0","Number of Electron Candidates",10,0,10);
    h.ngoodele[1] = new TH1F("ngoodele1","Number of Electron Candidates",10,0,10);
    for(int i=0; i<2; i++) h.ngoodele[i]->Sumw2();
    h.ptlep[0] = new TH1F("ptele0","Electron candidate p_{T}",200,0,100);
    h.ptlep[1] = new TH1F("ptele1","Electron p_{T}",200,0,200);
    h.ptlep[2] = new TH1F("ptjet","Jet pT",200,0,200);
    h.ptlep[3] = new TH1F("ptratio","Ratio of pT of pion to pT of jet",1000,0,10);
    h.ptlep[4] = new TH1F("ptjetiso","Jet pT",200,0,200);
    h.ptlep[5] = new TH1F("ptratioiso","Ration of pT of lep to pT of jet",1000,0,10);
    for(int i=0; i<6; i++) h.ptlep[i]->Sumw2();
    h.deltaR[0] = new TH1F("deltaR","deltaR",1000,0,10); h.deltaR[0]->Sumw2();
    h.deltaR[1] = new TH1F("deltaR_mc","deltaR_mc",1000,0,10); h.deltaR[1]->Sumw2();
    h.deltaR[2] = new TH1F("deltaR_pion_jet","deltaR between pion and closest jet",1000,0,10); h.deltaR[2]->Sumw2();
    h.dpt = new TH1F("dpt","dpt",10000,-500,500);h.dpt->Sumw2();
    h.motherid[0] = new TH1F("motherid","motherid",1200,-600,600);h.motherid[0]->Sumw2();
    h.index[0] = new TH1F("match_id","Match Id",1200,-600,600);
    h.pfiso[0] = new TH1F("rpfiso","Isolation",1000,0,10);
    h.pfiso[1] = new TH1F("pfiso","Isolation",10000,0,100);
    h.pfiso[2] = new TH1F("rpfiso_pion","Isolation of pion",1000,0,10);
    h.pfiso[3] = new TH1F("rpfiso_notpion","Isolation of electrons not matched to pion",1000,0,10);
    h.pfiso[4] = new TH1F("rel_trackiso","Relative Track Isolation of electrons",1000,0,10);
    h.pfiso[5] = new TH1F("rel_trackiso_iso","Relative Track Isolation of isolated electrons",1000,0,10);
    h.pfiso[6] = new TH1F("rel_caliso","Relative Calorimeter Isolation of electrons",1000,0,10);
    h.pfiso[7] = new TH1F("rel_caliso_iso","Relative Calorimeter Isolation of isolated electrons",1000,0,10);
    h.pfiso[8] = new TH1F("trackiso","Track Isolation of electrons",1000,0,100);
    h.pfiso[9] = new TH1F("trackiso_iso","Track Isolation of isolated electrons",1000,0,100);
    h.pfiso[10] = new TH1F("caliso","Calorimeter Isolation of electrons",1000,0,100);
    h.pfiso[11] = new TH1F("caliso_iso","Calorimeter Isolation of isolated electrons",1000,0,100);
    h.iso[0] = new TH2F("trackiso_caliso","Track Isolation versus calorimeter isolation of electron",1000,0,100,1000,0,100);
    h.iso[1] = new TH2F("rel_trackiso_rel_caliso","Relative track tsolation versus relative calorimeter isolation of electron",1000,0,10,1000,0,10);
    h.iso[2] = new TH2F("trackiso_iso_caliso_iso","Track Isolation versus calorimeter isolation of isolated electron",1000,0,100,1000,0,100);
    h.iso[3] = new TH2F("rel_trackiso_iso_rel_caliso_iso","Relative track tsolation versus relative calorimeter isolation of isolatedelectron",1000,0,10,1000,0,10);
    h.eta = new TH1F("eta","eta",80,-4,4);
    for(int i=0;i<30001;i++){
      string str=to_string(i);
      const char* ch=str.c_str();
      h.plots[i] = new TH2F(ch,"Image",40,-0.348,0.348,40,-0.348,0.348);
      h.plots[i]->GetXaxis()->SetTitle("Eta");
      h.plots[i]->GetYaxis()->SetTitle("Phi");
      //
    }
    
  }
  //cout<<"booked histograms"<<endl;
  

  // Note the calling of Sumw2() for each histogram we declare.
  // This is needed so that if scale the histograms later, the
  // errors on the points are still correct after scaling.
  // This is relevant.. so ask someone if you don't understand.
  
}
