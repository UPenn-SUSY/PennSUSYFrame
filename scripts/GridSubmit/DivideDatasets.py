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

    def __add__(self, x):
        print '%s plus %s' % (self, x)

        if not isinstance(x, UserData):
            print 'self: %s -- x: %s' % (self, x)
            return x+self.max_size

        print 'adding UserData'
        print 'self: %s -- x: %s' % (self, x)
        return self.max_size + x.max_size

# ------------------------------------------------------------------------------
def getDSList(ds_list_file_name):
    ds_list = []

    f = file(ds_list_file_name)
    for l in f.readlines():
        print l

    return ds_list

# ------------------------------------------------------------------------------
def main():
    user_list = [ UserData('brett'  , 500)
                , UserData('liz'    , 500)
                , UserData('leigh'  , 700)
                , UserData('emma'   , 700)
                , UserData('evelyn' , 800)
                ]
    total_space = reduce( lambda a, b: a+b , [x.max_size for x in user_list] )
    print 'total available space: ' , total_space

    ds_list = getDSList('dataset_sizes.tnt_105.txt')

# ==============================================================================
if __name__ == '__main__':
    main()
