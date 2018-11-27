#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "FTAna.h"

//This is the driver script, which becomes our main program
//Here we set the options which we wish to use, which files
//we want to run over and so on.

//the argument decides what input sample we want to run over.
//we give separate names of output files for each set of
//input files.
void ana(int sample)
{
  const char *hstfilename, *sumfilename;

  TChain *chain = new TChain("demo/RecoTree");
  FTAna m_selec;//declared an instance of our class.

  std::cout<<"Declared chains"<<std::endl;
  
    
  if(sample==1){
    //    chain->Add("realEle.root");
    //can have more chain->Add() lines here.
    //hstfilename = "real_ele.root";//output histogram file
    //sumfilename = "real_ele.txt"; //output text file
    chain->Add("DYMCEle.root");
    hstfilename = "real_ele_mc.root";
    sumfilename = "real_ele.txt";
  }
   if(sample==2){
    chain->Add("/home/dell/TTBar.root");
    hstfilename = "TTbar.root";
    sumfilename = "qcd_ele.txt";
  }
  if(sample==3){
    //    chain->Add("fakeEleWithZ9.root");
    //hstfilename = "fake_ele_withZ_cuts8.root";//output histogram file
    //sumfilename = "fake_ele3_withZ.txt";
    chain->Add("DYMC.root");
    hstfilename = "fake_ele_mc2.root";
    sumfilename = "fake_ele_mc.txt";
  }
  if(sample==4){
    chain->Add("/home/dell/TTBarLeptonic.root");
    hstfilename = "TTbarleptonic.root";
    sumfilename = "qcd_ele.txt";
  }

  std::cout<<"Output files are "<<hstfilename<<" and "<<sumfilename<<std::endl;
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName(sumfilename);
  m_selec.SetVerbose(20000);//set verbosity level for output.
  m_selec.SetData(1);
  m_selec.SetSample(sample);
  //std::cout<<"sample taken"<<endl;
  //this calls the Process function for each event in the chain
  //and runs the m_selec code over it.
  chain->Process(&m_selec);


}

int main(int argc, char *argv[])
{

  if(argc<2){
    std::cout<<" Please give one integer argument "<<std::endl;
    return 0;
  }
  int sample_id = atoi(argv[1]);

  ana(sample_id);
  return 0;
}

