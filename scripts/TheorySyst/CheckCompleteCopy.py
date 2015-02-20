def get_copy_list(f_name):
    dsid_list = {}
    with open(f_name) as f:
        for l in f.readlines():
            splits = l.rstrip().split('.')
            dsid = splits[3]
            name = splits[4]

            dsid_list[dsid] = name

    return dsid_list

def get_ref_list(f_name):
    dsid_list = {}
    with open(f_name) as f:
        for l in f.readlines():
            splits = l.rstrip().split('.')
            dsid = splits[0]
            name = splits[1]

            dsid_list[dsid] = name

    return dsid_list

def compare_lists(ref, test):
    missing = 0

    for r in ref.keys():
        if not r in test.keys():
            print 'missing: ', r, ' -- ', ref[r]
            missing += 1

    print 'num missing: ', missing

if __name__ == '__main__':
    copy_list = get_copy_list('copied_list.txt')
    ref_list = get_ref_list('ref_list.txt')

    print 'copied samples: ', len(copy_list)
    print 'ref samples: ', len(ref_list)

    compare_lists(ref=ref_list, test=copy_list)
