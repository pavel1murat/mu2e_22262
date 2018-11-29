void EpeakvsE92()
{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Nov 22 05:34:07 2018) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",18,60,700,504);
   gStyle->SetOptFit(1);
   c1->Range(20.34079,18.88425,177.6717,173.3032);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetLeftMargin(0.1217765);
   c1->SetRightMargin(0.07736389);
   c1->SetTopMargin(0.0777311);
   c1->SetBottomMargin(0.1218487);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1[22] = {
   50,
   55,
   60,
   65,
   70,
   75,
   80,
   85,
   90,
   95,
   99.79226,
   105,
   110,
   115,
   120,
   125,
   130,
   135,
   140,
   145,
   150,
   155};
   Double_t Graph0_fy1[22] = {
   48,
   52,
   57,
   62,
   67,
   71,
   76,
   81,
   86,
   91,
   96.24051,
   101,
   106,
   110,
   115,
   120,
   126,
   130,
   136,
   140,
   145,
   151};
   TGraph *graph = new TGraph(22,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillStyle(1000);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph11 = new TH1F("Graph_Graph_Graph11","Graph",100,39.5,165.5);
   Graph_Graph_Graph11->SetMinimum(37.7);
   Graph_Graph_Graph11->SetMaximum(161.3);
   Graph_Graph_Graph11->SetDirectory(0);
   Graph_Graph_Graph11->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph11->SetLineColor(ci);
   Graph_Graph_Graph11->GetXaxis()->SetTitle("E [MeV]");
   Graph_Graph_Graph11->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph11->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph11->GetYaxis()->SetTitle("E_{reco} [MeV]");
   Graph_Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph11->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph11->GetYaxis()->SetTitleOffset(0);
   Graph_Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph11->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph11);
   
   
   TPaveStats *ptstats = new TPaveStats(0.1819484,0.7016807,0.5429799,0.8613445,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetLineColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf =  5.40 / 20");
   ptstats_LaTex = ptstats->AddText("p0       = -1.94 #pm  0.37 ");
   ptstats_LaTex = ptstats->AddText("p1       =  0.98 #pm  0.00 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   graph->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(graph->GetListOfFunctions());
   
   TF1 *PrevFitTMP3 = new TF1("PrevFitTMP","pol1",47.06,155.42, TF1::EAddToList::kNo);
   PrevFitTMP3->SetFillColor(19);
   PrevFitTMP3->SetFillStyle(0);
   PrevFitTMP3->SetLineColor(2);
   PrevFitTMP3->SetLineWidth(2);
   PrevFitTMP3->SetChisquare(5.398731);
   PrevFitTMP3->SetNDF(20);
   PrevFitTMP3->GetXaxis()->SetLabelFont(42);
   PrevFitTMP3->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP3->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP3->GetXaxis()->SetTitleFont(42);
   PrevFitTMP3->GetYaxis()->SetLabelFont(42);
   PrevFitTMP3->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP3->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP3->GetYaxis()->SetTitleOffset(0);
   PrevFitTMP3->GetYaxis()->SetTitleFont(42);
   PrevFitTMP3->SetParameter(0,-1.937046);
   PrevFitTMP3->SetParError(0,0.3746323);
   PrevFitTMP3->SetParLimits(0,0,0);
   PrevFitTMP3->SetParameter(1,0.9800706);
   PrevFitTMP3->SetParError(1,0.003491853);
   PrevFitTMP3->SetParLimits(1,0,0);
   PrevFitTMP3->SetParent(graph);
   graph->GetListOfFunctions()->Add(PrevFitTMP3);
   graph->Draw("ap");
   
   TPaveText *pt = new TPaveText(0.4398567,0.9342405,0.5601433,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextColor(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Graph");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
