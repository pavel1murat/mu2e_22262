///////////////////////////////////////////////////////////////////////////////
// make plots using output of TStepPointMCAnaModule.cc and TMuonStopModuleAna.cc
// compare mu- and e- distributions for 2 simulated geometries
//
// save figures in .eps format
// convert -density 300 -depth 8 -quality 85 dtqual_TrackComp_trk_100_200.eps dtqual_TrackComp_trk_100_200.png
///////////////////////////////////////////////////////////////////////////////
#include "TString.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TH2.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "Stntuple/val/stntuple_val_functions.hh"

#include "murat/scripts/plot_utilities.hh"

const char* HistDir    = "/projects/hist/mu2e/ts_warm_bore";

#include "murat/scripts/init_ts_warm_bore_datasets.hh"

const char* figures_dir =  "/projects/mu2e/app/users/murat/notes/mu2e_20913/figures";

// dataset initialization
using namespace ts_warm_bore;

#include "plot_muons_z_at_s1_end.C"
#include "plot_electron_z_at_s1_end.C"
#include "plot_electron_y_at_s1_end.C"

#include "plot_muon_x_at_s2_end.C"
#include "plot_electron_x_at_s2_end.C"
#include "plot_electron_y_at_s2_end.C"

#include "plot_stopped_muon_x_at_vd9.C"
//-----------------------------------------------------------------------------
// plot_momentum.C interface allows to use only one function
//-----------------------------------------------------------------------------
#include "plot_momentum.C"
//-----------------------------------------------------------------------------
// wget -O aaa http://home.fnal.gov/~murat/cafdfc/detsim/e42s5721/AAA_CATALOG.html >| /dev/null 2>&1 | \
//      cat /tmp/aaa  | grep NGENERATED | awk '{print $4}'
//-----------------------------------------------------------------------------
void plot(int Figure = -1, int Print = 0) {
  dataset_t ds1;

  ts_warm_bore::init_datasets();

  if (Figure ==  1) plot_muons_z_at_s1_end       (&d_711_1000_s1_mubeam  ,&d_711_1001_s1_mubeam  ,Print);
  if (Figure ==  2) plot_muons_x_at_s2_end       (&d_711_1000_s2_mubeam  ,&d_711_1001_s2_mubeam  ,Print);
  if (Figure ==  3) plot_stopped_muons_x_at_vd9  (&d_711_1000_s3_tgtstops,&d_711_1001_s3_tgtstops,Print);

  if (Figure == 11) {
    ds1             = d_711_1000_s1_mubeam;
    ds1.fPlotName   = "muon_mom_at_s1_end";
    ds1.fPlotLabel  = "#mu^- at TS3u, end of Stage1";
    ds1.fXAxisTitle = "momentum, MeV/c";
    plot_momentum(&ds1,&d_711_1001_s1_mubeam,"StepPointMCAna","spmc_3/mom",Print);
  }
  
  if (Figure == 12) {
    ds1             = d_711_1000_s2_mubeam;
    ds1.fPlotName   = "muon_mom_at_s2_end";
    ds1.fPlotLabel  = "#mu^- at TS5, end of Stage2";
    ds1.fXAxisTitle = "momentum, MeV/c";
    plot_momentum (&ds1,&d_711_1001_s2_mubeam,"StepPointMCAna","spmc_3/mom",Print);
  }
  
//-----------------------------------------------------------------------------
// Fig 13: stopped muon momentum in front of the stopping target (at VD9)
//-----------------------------------------------------------------------------
  if (Figure == 13) {
    ds1             = d_711_1000_s3_tgtstops;
    ds1.fPlotName   = "stopped_muon_mom_at_vd9";
    ds1.fPlotLabel  = "#mu^- at VD9, in front of ST";
    ds1.fXAxisTitle = "momentum, MeV/c";
    ds1.fXMin       = 0;
    ds1.fXMax       = 100;
    plot_momentum(&ds1,&d_711_1001_s3_tgtstops,"MuonStopAna","vdet_309/mom",Print);
  }

  if (Figure == 21) plot_electron_z_at_s1_end    (&d_711_1000_s1_mubeam  ,&d_711_1001_s1_mubeam  ,Print);
  if (Figure == 22) plot_electron_x_at_s2_end    (&d_711_1000_s2_mubeam  ,&d_711_1001_s2_mubeam  ,Print);

  if (Figure == 31) plot_electron_y_at_s1_end    (&d_711_1000_s1_mubeam  ,&d_711_1001_s1_mubeam  ,Print);
  if (Figure == 32) plot_electron_y_at_s2_end    (&d_711_1000_s2_mubeam  ,&d_711_1001_s2_mubeam  ,Print);

  if (Figure == 41) {
    ds1             = d_711_1000_s1_mubeam;
    ds1.fPlotName   = "electron_mom_at_s1_end";
    ds1.fPlotLabel  = "e- at TS3u, end of Stage1";
    ds1.fXAxisTitle = "momentum, MeV/c";
    ds1.fYLogScale  = 1;
    plot_momentum(&ds1,&d_711_1001_s1_mubeam,"StepPointMCAna","spmc_1/mom",Print);
  }
  
  if (Figure == 42) { 
    ds1             = d_711_1000_s2_mubeam;
    ds1.fPlotName   = "electron_mom_at_s2_end";
    ds1.fXAxisTitle = "momentum, MeV/c";
    ds1.fPlotLabel  = "e- at TS5, end of Stage2";
    ds1.fYLogScale  = 1;
    plot_momentum(&ds1,&d_711_1001_s2_mubeam,"StepPointMCAna","spmc_1/mom",Print);
  }

  if (Figure == 51) {
    ds1             = d_711_1000_s1_mubeam;
    ds1.fPlotName   = "electron_mom_at_s1_end_p_gt_60";
    ds1.fXAxisTitle = "momentum, MeV/c";
    ds1.fPlotLabel  = "e- with P > 60 MeV/c at TS3u, end of Stage1";
    ds1.fXMin       =  50;
    ds1.fXMax       = 200;
    ds1.fYLogScale  = 1;
    plot_momentum(&ds1,&d_711_1001_s1_mubeam,"StepPointMCAna","spmc_101/mom",Print);
  }
  
  if (Figure == 52) {
    ds1             = d_711_1000_s2_mubeam;
    ds1.fPlotName   = "electron_mom_at_s2_end_p_gt_60";
    ds1.fXAxisTitle = "momentum, MeV/c";
    ds1.fPlotLabel  = "e- with P > 60 MeV/c at TS5, end of Stage2";
    ds1.fXMin       =  50;
    ds1.fXMax       = 200;
    ds1.fYLogScale  = 1;
    plot_momentum(&ds1,&d_711_1001_s2_mubeam,"StepPointMCAna","spmc_101/mom",Print);
  }
}
