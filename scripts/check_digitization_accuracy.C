///////////////////////////////////////////////////////////////////////////////
// digitized here are the data from Armstrong'1992 Ca40 spectrum
// the data are are the triplets: (x,y), (x,y+sigma), (x,y-sigma)
// the purpose of this digitization is to check by how much
// the error bars on the plot are different from purely statistical ones.
///////////////////////////////////////////////////////////////////////////////

#include "TH1.h"
#include "TH2.h"

#include "TString.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TH2.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "Stntuple/val/stntuple_val_functions.hh"

#include "murat/scripts/plot_utilities.hh"
#include "string.h"

char figures_dir[1000];

char* f1 = strcpy((char*) figures_dir,(const char*) gSystem->Getenv("MU2E_NOTES_DIR"));
char* f2 = strcat((char*) figures_dir,"/mu2e_22262/figures");

  double data[] = {
    83.5314,21.4876, 83.5811,26.2699, 83.4817,16.7053,
    84.4568,14.5184, 84.4044,17.9054, 84.5092,10.9321,
    85.5314,21.4976, 85.5812,26.0807, 85.5330,16.7155,
    86.5077,15.5249, 86.5577,19.3109, 86.5603,11.5401,
    87.5364,6.36434, 87.4843,8.75512, 87.5372,3.97331,
    88.5597,13.5425, 88.5072,17.1288, 88.6121,9.95625,
    89.5351,10.3594, 89.5853,13.5477, 89.4334,7.56931,
    90.6648,5.58291, 90.5103,7.57467, 90.6656,3.19188,
    91.5370,4.59099, 91.5363,6.58352, 91.5376,2.59846,
    92.6659,2.40483, 92.5115,3.99808, 92.6152,0.61129,
    -1
  };

//-----------------------------------------------------------------------------
// in X we should see the half-bin
//-----------------------------------------------------------------------------
void check_digitization_accuracy_dx(int Print = 0) {

  TH1F* h_dx = new TH1F("h_delta_e","h_dx",20,-0.5,0.5);

  TCanvas* c = new TCanvas("c_digitization_accuracy_dx","digitization_accuracy_dx",1200,800);

  int np=0;

  for (; data[6*np] > 0; np++) {
    float dx1 = data[6*np+2]-data[6*np];
    float dx2 = data[6*np+4]-data[6*np];

    h_dx->Fill(dx1);
    h_dx->Fill(dx2);
  }

  h_dx->SetTitle("");
  h_dx->GetXaxis()->SetTitle("#Delta E, MeV");
  h_dx->Draw();

  draw_label_ndc("accuracy of digitizing the energy bin center",0.15,0.86,0.03,52);
  
  if (Print == 1) c->Print(Form("%s/eps/%s.eps",figures_dir,"digitization_accuracy_de")) ;
}

//-----------------------------------------------------------------------------
// check that the erro bar is sqrt(N)
//-----------------------------------------------------------------------------
void check_digitization_error_bars(int Print = 0) {

  TCanvas* c = new TCanvas("c_error_bars","error_bars",1500,700);
  c->Divide(2,1);

  c->cd(1);

  TH2F* h_dy = new TH2F("h_error_bars","h_error_bars",100,0 ,10,50,-2.5,2.5);


  int np=0;

  for (; data[6*np] > 0; np++) {
    float dy1 = (data[6*np+3]-data[6*np+5])/2;
    float dy2 = sqrt(data[6*np+1]);

    h_dy->Fill(dy2,dy1-dy2);
  }

  h_dy->SetMarkerStyle(20);
  h_dy->SetMarkerSize(1);
  h_dy->SetTitle("");
  h_dy->GetXaxis()->SetTitle("#sigma_{Y}");
  h_dy->GetYaxis()->SetTitle("#sigma_{Y} - #sqrt{Y}");
  h_dy->GetYaxis()->SetTitleOffset(1.2);
  h_dy->Draw();

  draw_label_ndc("cross check of the error bars",0.15,0.86,0.03,52);

  c->cd(2);

  TH1D* h_py = h_dy->ProjectionY();
  
  h_py->GetXaxis()->SetTitleOffset(1.2);
  h_py->SetTitle("");

  draw_label_ndc("cross check of the error bars",0.15,0.86,0.03,52);
  h_py->Draw();
  
  if (Print == 1) c->Print(Form("%s/eps/%s.eps",figures_dir,"digitization_error_bars")) ;
}


//-----------------------------------------------------------------------------
// 2018-10-31 - redigitize several spectra, recheck accuracy
//-----------------------------------------------------------------------------
double data_Al_1992 [] = {
  57.4888,55.2209, 58.4915,59.1703, 59.4603,82.1449, 60.4843,74.2118, 61.4942,74.1558,
  62.4803,72.1636, 63.4921,71.1063, 64.4965,74.1211, 65.5044,75.2000, 66.5249,69.2028,
  67.4997,58.2651, 68.4810,74.2304, 69.4863,46.2034, 70.5583,57.2297, 71.5001,34.2087,
  72.5014,54.2464, 73.5107,39.2369, 74.5296,34.1743, 75.5246,27.1755, 76.5052,28.2541,
  77.5259,22.1902, 79.5109,26.2835, 78.5194,16.0592, 80.5535,7.93659, 81.5325,9.94974,
  82.5220,6.02168, 83.5300,7.03379, 84.5689,6.04354, 85.5824,3.98491, 86.4902,-0.0107858,
  87.5201,4.00561, 88.5063,1.94669, 89.4632,1.02232, 90.5497,3.97121, 91.4574,0.0422686,
  92.4946,-0.0134094, 93.5317,-0.00233206, 94.4869,0.00787071, 95.5514,-0.0475158, 96.5319,1.09782,
  97.5145,1.04156, 99.5070,0.996082,
  -1 };

void check_digitization_accuracy_Al_dx() {

  TH1F* h_dx = new TH1F("h_dx_Al","h_dx_Al",100,-1,1);
  h_dx->GetXaxis()->SetTitle("#Delta E, MeV");


  int np=0;

  for (; data_Al_1992[2*np] > 0; np++) {
    double x = data_Al_1992[2*np];
    float dx  = x - int(x) -0.5;
    h_dx->Fill(dx);
  }

  h_dx->Draw();
}

//-----------------------------------------------------------------------------
void check_digitization_accuracy_Al_1992_dy(int Print = 0) {

  TCanvas* c = new TCanvas("c_digitization_accuracy_dy","digitization_accuracy_dy",1200,800);
  
  TH1F* h_dy = new TH1F("h_dy_Al_1992","h_dy_Al_1992",100,-1,1);

  int np=0;
  double dy;
  
  for (; data_Al_1992[2*np] > 0; np++) {
    double y = data_Al_1992[2*np+1];
    double dy1  = y - floor(y);
    double dy2  = y - floor(y+1);

    if (fabs(dy1) < fabs(dy2)) dy = dy1;
    else                       dy = dy2;

    printf(" y = %12.5f  dy = %10.5f\n",y,dy);
    h_dy->Fill(dy);
  }

  h_dy->SetTitle("");
  h_dy->GetXaxis()->SetTitle("Y- closest integer");
  h_dy->Draw();

  draw_label_ndc("digitization accuracy bin contents",0.15,0.86,0.03,52);
  
  if (Print == 1) c->Print(Form("%s/eps/%s.eps",figures_dir,"digitization_accuracy_Al_1992_dy")) ;
}

