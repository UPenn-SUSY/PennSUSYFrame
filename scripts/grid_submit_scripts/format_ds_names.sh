#!/bin/bash

# Example bash command to query dq2 for the dataset in question parse the
# containers for the relevant pieces, and print in a format that is acceptable
# for our grid submission scripts.

# MC example
dq2-ls mc12_8TeV.*.Sherpa_CT10_Ttbar*merge.NTUP_SUSY.e1434*p1181/ \
  | sort \
  | sed 's%^\(.*TeV\.\)\(.*\)\(\.merge.*\)$%"\2:\1\2\3"%'

# parse messy sed stuff
sed 's%^\(.*TeV\.\)\(.*\)\(\.merge.*\)$%\"\2:\1\2\3\"%'
#    | ||_________||____||___________|| |___________|
#    | ||          |     |            | |
#    | ||          |     |            | |_ Print in the correct format.
#    | ||          |     |            |    i.e. number.label:full_name
#    | ||          |     |            |
#    | ||          |     |            |_ Anchor to end of line
#    | ||          |     |
#    | ||          |     |_ Capture the rest of the line beginning from
#    | ||          |        ".merge".  Store as \3
#    | ||          |
#    | ||          |_ Capture the DS number and label.  This will lie between
#    | ||             "TeV." and ".merge". Store as \2
#    | ||
#    | ||_ Capture the prefix stuff. Store as \1
#    | |
#    | |_ Anchor to beginning of line
#    |
#    |_ Search


# data example
dq2-ls group.phys-susy.data12_8TeV.*physics_Muons.*NTUP_SUSY*p1182/ \
  | sort \
  | sed 's%^\(.*\.\)\(period.*\)\(\.physics_.*\)$%\"\2:\1\2\3\"%'

# parse messy sed stuff
sed 's%^\(.*\.\)\(period.*\)\(\.physics_.*\)$%\"\2:\1\2\3\"%'
#    | ||______||__________||______________|| |___________|
#    | ||       |           |               | |
#    | ||       |           |               | |_ Print in the correct format.
#    | ||       |           |               |    i.e. number.label:full_name
#    | ||       |           |               |
#    | ||       |           |               |_ Anchor to end of line
#    | ||       |           |
#    | ||       |           |_ Capture the rest of the line beginning from
#    | ||       |              ".merge".  Store as \3
#    | ||       |
#    | ||       |_ Capture the DS number and label.  This is the part that says
#    | ||          period* and ".merge". Store as \2
#    | ||
#    | ||_ Capture the prefix stuff. Store as \1
#    | |
#    | |_ Anchor to beginning of line
#    |
#    |_ Search
