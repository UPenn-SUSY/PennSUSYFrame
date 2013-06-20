#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
import rootlogon
import metaroot


# f = ROOT.TFile('compare.mm_ss.loose_selection.root')
f = ROOT.TFile('../../Plotting/compare.mm_ss.extended.root')

selections = [ 'mm_sr_ss.it5_leppt15_njet1_jetpt25'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_metrel30'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_metrel30_mt230'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_metrel30_mt230_ptll20'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_metrel30_ptll20'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_metrel50'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_metrel50_mt230'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_metrel50_mt230_ptll20'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_metrel50_ptll20'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_mt230'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_mt230_ptll20'
             , 'mm_sr_ss.it5_leppt15_njet1_jetpt25_ptll20'
             ]

# ------------------------------------------------------------------------------
def printToScreen():
    bar = '-'*235
    print bar
    printed_header = False
    for s in selections:
        table_entry = '| %70s ' % s
        # print 'Selection: %s' % s
        selection_dir = f.Get(s)

        canvas = selection_dir.Get('__entries')
        if not printed_header:
            header_line = '| %70s ' % 'Selection'
            for i, lop in enumerate(canvas.GetListOfPrimitives()):
                bin_label = lop.GetXaxis().GetBinLabel(i+1)
                if '=' in bin_label: bin_label = bin_label.split('=')[1].lstrip()
                header_line += '| %20s ' % bin_label
                # header_line += '| %10s ' % lop.GetXaxis().GetBinLabel(i+1)
            header_line += '|'
            print header_line
            print bar
            printed_header = True

        for i, lop in enumerate(canvas.GetListOfPrimitives()):
            table_entry += '| %20f ' % lop.GetBinContent(i+1)
        table_entry += '|'
        print table_entry
    print bar

# ------------------------------------------------------------------------------
def getExpectedEvents():
    labels = []
    contributions = {}
    for s in selections:
        contributions[s] = []

        selection_dir = f.Get(s)
        canvas = selection_dir.Get('__entries')
        if labels == []:
            for i, lop in enumerate(canvas.GetListOfPrimitives()):
                bin_label = lop.GetXaxis().GetBinLabel(i+1)
                if '=' in bin_label:
                    bin_label = bin_label.split('=')[1].lstrip()
                labels.append(bin_label)

        for i, lop in enumerate(canvas.GetListOfPrimitives()):
            contributions[s].append(lop.GetBinContent(i+1))

    return {'labels':labels, 'contributions':contributions}

# ------------------------------------------------------------------------------
def genFileHeader(out_file):
    out_file.write("""\\documentclass[8pt]{beamer}

\\usepackage{ctable}
\\usepackage{colortbl}

\\begin{document}

\\definecolor{colorData}{rgb}{0.00,0.00,0.00} % black
\\definecolor{colorDiboson}{rgb}{0.47,0.47,0.42} % light green
\\definecolor{colorFake}{rgb}{0.55,0.90,0.67} % gray
\\definecolor{color10}{rgb}{0.00,0.40,0.00} % Dark green
\\definecolor{color39}{rgb}{1.00,0.00,0.80} % Magenta
\\definecolor{color40}{rgb}{0.77,0.25,0.00} % Dark orange
\\definecolor{color55}{rgb}{0.40,0.80,1.00} % Light blue
\\definecolor{color56}{rgb}{0.00,1.00,1.00} % Teal
\\definecolor{color57}{rgb}{0.00,0.00,1.00} % Dark blue

\\newcolumntype{K}{\\columncolor[gray]{0.8}\\raggedright}
""")

# ------------------------------------------------------------------------------
def genFileFooter(out_file):
    out_file.write('\\end{document}\n')

# ------------------------------------------------------------------------------
def genFrameHeader(out_file):
    out_file.write("""
\\frame
{
  \\frametitle{Number expected events}

""")

# ------------------------------------------------------------------------------
def getLabelColor(label):
    if 'Data' in label:
        return "colorData"
    if 'diboson' in label:
        return "colorDiboson"
    if 'Fake' in label:
        return "colorFake"
    if '135' in label:
        return "color55"
    if '185' in label:
        return "color56"
    if '260' in label:
        return "color57"
    if '117' in label:
        return "color39"
    if '142' in label:
        return "color40"
    if '150' in label:
        return "color10"
    return 'black'

# ------------------------------------------------------------------------------
def genTableHeader(out_file, labels):
    out_file.write("""  \\begin{table}[tp]
    \\resizebox{\\textwidth}{!}{
      \\begin{tabular}{lccccccc}
        \\toprule
""")
    for l in labels:
        print l + ' - ' + getLabelColor(l)
        out_file.write('         & \\cellcolor{%s}\\textcolor{white}{%s}\n' % (getLabelColor(l), l))
#         & \\cellcolor{color55}\\textcolor{white}{(135, 115)}
#         & \\cellcolor{color56}\\textcolor{white}{(185, 165)}
#         & \\cellcolor{color57}\\textcolor{white}{(260, 240)}
#         & \\cellcolor{color39}\\textcolor{white}{(117.5, 82.5)}
#         & \\cellcolor{color40}\\textcolor{white}{(142.5, 107.5)}
#         & \\cellcolor{color10}\\textcolor{white}{(150, 50)}
    out_file.write("""        \\\\\\toprule
""")

# ------------------------------------------------------------------------------
def genMidRule(out_file):
    out_file.write("        \\midrule\n\n")

# ------------------------------------------------------------------------------
def genTableFooter(out_file):
    out_file.write("""
        \\bottomrule
      \\end {tabular}
    }
  \\end{table}
""")

# # ------------------------------------------------------------------------------
# def genFrameFooter(out_file):
#     out_file.write("""
#   \\center{
#     \\begin{tabular}{rcl}
#       \\toprule
#       $p_{\\mathrm{T}}^{\\ell}$ & $\\ge$ & $15 \\mathrm{GeV}$ \\\\
#       $p_{\\mathrm{T}}^{\\mathrm{jet}}$    & $\\ge$ & $20 \\mathrm{GeV}$ \\\\
#       $E_{T}^{\\mathrm{miss,rel}}$        & $\\ge$ & $20 \\mathrm{GeV}$ \\\\
#       $\\delta\\phi(\\ell\\ell)/\\pi$         & $\\ge$ & $0.5$ \\\\
#       $m_{\\mathrm{T2}}$                  & $\\le$ & $30 \\mathrm{GeV}$ \\\\
#       $p_{\\mathrm{T}}^{\\ell\\ell}$        & $\\le$ & $20 \\mathrm{GeV}$ \\\\
#       \\bottomrule
#     \\end{tabular}
#   }
# }
# """)

# ------------------------------------------------------------------------------
def genLatexFile(labels, contributions):
    out_file = file('component_contributions.tex', 'w')

    genFileHeader(out_file)
    genTableHeader(out_file, labels)

    genTableFooter(out_file)
    # genFrameFooter(out_file)
    genFileFooter(out_file)

    out_file.close()


# ==============================================================================
if __name__ == '__main__':
    printToScreen()
    expected_events = getExpectedEvents()
    genLatexFile(expected_events['labels'], expected_events['contributions'])
