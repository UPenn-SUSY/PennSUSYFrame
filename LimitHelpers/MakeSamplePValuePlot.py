#!/usr/bin/env python

import ROOT
import array
import summary_harvest_tree_description as tree_summary

ROOT.gStyle.SetOptStat(0)

# ------------------------------------------------------------------------------
def readHypoTestResults(input_file_name):
    the_tree = tree_summary.harvesttree(input_file_name)
    results = {}

    for entry in the_tree:
        results[int(entry.mst)] = entry.CLs

    return results

# ------------------------------------------------------------------------------
def getMinMax(val_list, limit_min_to_zero = True):
    min_val = min(val_list)
    max_val = max(val_list)
    delta = max_val - min_val

    min_val -= 0.1*delta
    max_val += 0.1*delta

    if limit_min_to_zero:
        min_val = max(0., min_val)

    return (min_val, max_val)

# ------------------------------------------------------------------------------
def makePValuePlot(input_file_name):
    # get results from hypothesis test
    results = readHypoTestResults(input_file_name)

    # convert results to x and y value lists
    x_vals = sorted(results.keys())
    y_vals = [results[x] for x in x_vals]
    print x_vals
    print y_vals

    # make graph and set style options
    p_value_graph = ROOT.TGraph(len(x_vals), array.array('d', x_vals), array.array('d', y_vals))
    p_value_graph.SetMarkerStyle(20)
    p_value_graph.SetMarkerColor(ROOT.kBlue)
    p_value_graph.SetLineColor(ROOT.kBlue)

    # get min/max for x axis
    x_min, x_max = getMinMax(x_vals)
    y_min, y_max = getMinMax(y_vals)

    print y_vals
    print 'ymin: ', y_min, ' ymax: ', y_max

    # make line to mark p = 0.05
    line = ROOT.TLine(x_min, 0.05, x_max, 0.05)
    line.SetLineColor(ROOT.kRed)
    line.SetLineWidth(4)
    line.SetLineStyle(ROOT.kDashed)

    # Create frame because TGraphs don't have axes
    frame = ROOT.TH1F('f', '', 1, x_min, x_max)
    frame.SetMinimum(y_min)
    frame.SetMaximum(y_max)
    frame.GetXaxis().SetTitle('m_{ #tilde{t}} [GeV]')
    frame.GetYaxis().SetTitle('CL_{s}')

    # Draw p value to plot
    c = ROOT.TCanvas('p_val')
    frame.Draw()
    p_value_graph.Draw('PL')
    line.Draw()

    c.Print('SamplePValue.pdf')

# ------------------------------------------------------------------------------
def main():
    input_file_name = 'SampleExcl_Output_hypotest__1_harvest_list'
    makePValuePlot(input_file_name)

# ==============================================================================
if __name__ == "__main__":
    main()
