// This code loops over all images plotted from ElectronTree using FlatTree Analysis, process and saves them
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "THStack.h"
#include "TF1.h"
#include "TString.h"
#include <iostream>
#include <fstream>
#include <math.h>

using std::cout;
using std::endl;

void get(string filename,int plot_begin,int num)
{
  TString file=filename;
  TFile *filen = new TFile(file);
  int plot_no=plot_begin;
  for(int i=plot_no;i<plot_no+num;i++){ // loop over all images
    int b=2959-803;
    int img_no=i+b; // adjust plot number to avoid repetition
    string str1=to_string(i);
    TString plotname=str1;
    str1=to_string(img_no);
    //string s="__";
    //s.append(str1);
    string str2=".jpg";
    string str=str1.append(str2);
    const char* ch1=str.c_str();
    // Edit the image
    gStyle->SetPadTopMargin(0.);
    gStyle->SetPadRightMargin(0.);
    gStyle->SetPadBottomMargin(0.);
    gStyle->SetPadLeftMargin(0.);
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    gStyle->SetOptStat(0);
    c1->cd();
    c1->GetCanvas()->SetGrayscale();
    TH2F *hist=(TH2F*) filen->Get(plotname);
    hist->GetXaxis()->SetLabelOffset(0);
    hist->GetXaxis()->SetLabelSize(0);
    hist->GetXaxis()->SetTickLength(0);
    hist->GetXaxis()->SetAxisColor(0);
    hist->GetYaxis()->SetAxisColor(0);
    hist->GetYaxis()->SetTickLength(0);
    hist->GetYaxis()->SetLabelOffset(0);
    hist->GetYaxis()->SetLabelSize(0);
    hist->GetZaxis()->SetLabelOffset(0);
    hist->GetZaxis()->SetLabelSize(0);
    hist->GetZaxis()->SetTickLength(0);
    hist->GetZaxis()->SetAxisColor(0);
    hist->SetTitle("");
    // hist->GetXaxis()->SetTitle("Relative Eta");
    // hist->GetYaxis()->SetTitle("Relative Phi");
    // hist->GetXaxis()->SetTitleSize(0.05);
    // hist->GetYaxis()->SetTitleSize(0.05);
    hist->Draw("colz");
    c1->SaveAs(ch1);
    c1->Close();
    delete c1;
  }
}
void save(){
  // get("/home/dell/Work/FTAna/real_ele.root",0,101);
  //get("/home/dell/Work/FTAna/real_ele_mc.root",3762,3762);
  //get("/home/dell/Work/FTAna/fake_ele_withZ.root",0,101);
  get("/home/dell/Work/FTAna/qcd_ele7.root",803,803);
}
