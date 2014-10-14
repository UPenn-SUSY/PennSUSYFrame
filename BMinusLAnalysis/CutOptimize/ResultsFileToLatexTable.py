#!/usr/bin/env python

import glob
import re

# get list of variables
def getListOfVariables(sample_file_name):
    sample_file = file(sample_file_name)
    list_of_variables = []
    for l in sample_file.readlines():
        splits = l.rstrip().split(':')

        # if this is a blank line, skip
        if len(splits) == 0: continue

        # if this is a horizontal bar, all the variables are done. we can stop
        if re.search('---------------', splits[0]): break

        # this is a variable! store it to the list!
        if re.search('var_', splits[0]):
            list_of_variables.append(splits[1])

    # we are done with this file for now. close it
    sample_file.close()

    return list_of_variables

# get cut strings
def getSampleInfo(sample_file_name):
    sample_file = file(sample_file_name)

    num_sig = 0
    num_bkg = 0
    eff_sig = 0
    eff_bkg = 0
    significance = 0
    cut_strings = []

    found_start = False
    for l in sample_file.readlines():
        splits = l.strip().rstrip().split(':')

        # if this is a blank line, skip
        if len(splits) == 0: continue

        # All the info we want is below the horizontal bar. If this is the horizontal bar, we can start!
        if re.search('---------------', splits[0]):
            print 'found start!!!'
            found_start = True
            continue
        # if we haven't found the horizontal bar, we can skip this line
        if not found_start: continue

        # singal efficiency info
        if splits[0] == 'sig eff':
            eff_sig = float(splits[1].split()[0])
            num_sig = float(splits[2])

        # background efficiency info
        if splits[0] == 'bkg eff':
            eff_bkg = float(splits[1].split()[0])
            num_bkg = float(splits[2])

        # significance
        if splits[0] == 'significance':
            significance = float(splits[1])

        # cut strings
        if re.search('var_', splits[0]):
            cut_info_splits = splits[0].split('<')
            print cut_info_splits
            lower_is_inf = re.search('inf', cut_info_splits[0])
            upper_is_inf = re.search('inf', cut_info_splits[2])

            if not lower_is_inf and upper_is_inf:
                cut_strings.append('\\ge %0.2f' % float(cut_info_splits[0]))
            elif lower_is_inf and not upper_is_inf:
                cut_strings.append('\\le %0.2f' % float(cut_info_splits[2]))
            elif not lower_is_inf and not upper_is_inf:
                cut_strings.append('%0.2f \\le x \\le %0.2f' % (float(cut_info_splits[0]), float(cut_info_splits[2])))
            else:
                cut_strings.append('--')

    return { 'num_sig':num_sig
           , 'num_bkg':num_bkg
           , 'eff_sig':eff_sig
           , 'eff_bkg':eff_bkg
           , 'significance':significance
           , 'cut_strings':cut_strings
           }

# print to table
def printToTable(out_file_name, cut_vars, sample_info):
    out_file = file(out_file_name, 'w')

    file_header = '\\documentclass[14pt]{article}\n\\usepackage{ctable}\n\n\\begin{document}\n\n'
    out_file.write(file_header)

    for i, cv in enumerate(cut_vars):
        clean_name = cv.replace('_', '\_').replace('^', '\^')
        out_file.write('var %d: %s\n\n' % (i, clean_name))
    out_file.write('\n')

    # header line
    table_header_line = '\\begin{tabular}{c|'
    for i in xrange(len(cut_vars)):
        table_header_line += 'c'
    table_header_line += '|cc|c}\n'
    out_file.write(table_header_line)

    # title line for table
    title_line = '\\toprule\nSample & '
    for i, cv in enumerate(cut_vars):
        # title_line += cv
        title_line += 'var %d' % i
        title_line += ' & '
    title_line += ' num sig & num bkg & Significance \\\\\n\\midrule\n'
    out_file.write(title_line)

    for i, si in enumerate(sample_info):
        this_line = '%d & ' % i
        for cut_itr, cv in enumerate(cut_vars):
            this_line += '$%s$' % si['cut_strings'][cut_itr]
            this_line += ' & '
        this_line += '%0.2f' % si['num_sig']
        this_line += ' & '
        this_line += '%0.2f' % si['num_bkg']
        this_line += ' & '
        this_line += '%0.2f' % si['significance']
        this_line += ' \\\\\n'

        out_file.write(this_line)

    out_file.write('\\bottomrule\n\\end{tabular}\n\n\\end{document}\n')

def main():
    # get list of files:
    list_of_files = glob.glob('results_*.txt')
    print list_of_files

    list_of_cut_vars = getListOfVariables(list_of_files[0])
    print list_of_cut_vars

    print ''

    sample_info = []
    for lof in list_of_files:
        sample_info.append(getSampleInfo(lof))

    printToTable('results_table.tex', list_of_cut_vars, sample_info)

if __name__ == '__main__':
    main()
