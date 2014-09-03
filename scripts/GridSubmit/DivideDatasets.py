#!/usr/bin/env python
# ==============================================================================
# = quick script that takes a file full of dataset containers paired with
# = dataset sizes and breaks up the datasets to be divided amongst out eos
# = spaces.
# ==============================================================================

# ==============================================================================
class UserData(object):
    def __init__(self, user_name = 'user', max_size = 1000):
        self.user_name = user_name
        self.max_size = max_size
        self.current_size = 0
        self.ds_list = []

    def addSample(self, ds):
        self.ds_list.append(ds)
        self.current_size += ds.size

    def printUserInfo(self):
        print 'user name: ' , self.user_name
        print '  max size: ' , self.max_size
        print '  allocated size: ' , self.current_size
        print '  number samples: ' , len(self.ds_list)

    def printUserDataSets(self):
        self.printUserInfo()
        print '  DS list:'
        for ds in self.ds_list:
            print '    %s' % ds.name
        print ''

    def printUserDataSetsToFile(self, out_file_name):
        out_file = file(out_file_name, 'w')
        out_file.write('user name: %s\n'         % self.user_name)
        out_file.write('  max size: %s\n'        % self.max_size)
        out_file.write('  allocated size: %s \n' % self.current_size)
        out_file.write('  number samples: %s \n' % len(self.ds_list))
        out_file.write('\n')
        for ds in self.ds_list:
            out_file.write('    %s\n' % ds.name)
        out_file.close()

# ==============================================================================
class DataSet(object):
    def __init__(self, ds_name, num_files, ds_size):
        self.name      = ds_name
        self.num_files = num_files
        self.size      = ds_size

# ------------------------------------------------------------------------------
def getDSList(ds_list_file_name):
    ds_list = []

    f = file(ds_list_file_name)
    for l in f.readlines():
        splits = l.split()
        ds_list.append( DataSet( splits[0]
                               , int(splits[1])
                               , float(splits[2])
                               )
                      )
    return ds_list

# ------------------------------------------------------------------------------
def fillUserLists(user_list, ds_list):
    # loop over data-sets
    for ds in ds_list:
        ds_allocated = False

        # look at user list. assign this ds to the first user who can hold it
        for user in user_list:
            if user.current_size + ds.size < user.max_size:
                print 'Adding sample %s to user %s' % (ds.name, user.user_name)
                user.addSample(ds)
                ds_allocated = True
                break
        if not ds_allocated:
            print "ERROR: We don't have space for sample " , ds.name
            for user in user_list:
                user.printUserInfo()
                print ''

# ------------------------------------------------------------------------------
def main():
    user_list = [
                  UserData('evelyn'       , 800)
                , UserData('brett_part1'  , 200)
                , UserData('liz_part1'    , 200)
                , UserData('leigh_part1'  , 200)
                , UserData('emma_part1'   , 200)
                , UserData('brett_part2'  , 0  )
                , UserData('liz_part2'    , 500)
                , UserData('leigh_part2'  , 500)
                , UserData('emma_part2'   , 500)
                ]
    total_space = reduce( lambda a, b: a+b , [x.max_size for x in user_list] )
    print 'total available space: ' , total_space

    ds_list = getDSList('ContainerSizes.TNT_106.txt')

    fillUserLists(user_list, ds_list)

    for user in user_list:
        user.printUserDataSets()
        user.printUserDataSetsToFile('files.%s.txt' % user.user_name)

# ==============================================================================
if __name__ == '__main__':
    main()
