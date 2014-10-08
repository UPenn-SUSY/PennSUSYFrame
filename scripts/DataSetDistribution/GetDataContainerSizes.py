#!/usr/bin/env python
# ==============================================================================
# = quick script that takes a file containing a list of container names (with or
# = without wildcards) and gets the complete file size of the included datasets
# ==============================================================================

import subprocess

# ==============================================================================
container_list_file_name = 'ContainerList.TNT_106.txt'
output_container_size_file_name = 'ContainerSizes.TNT_106.txt'

# ------------------------------------------------------------------------------
def getContainerList(in_file_name):
    container_list = []
    in_file = file(in_file_name)
    for lines in in_file.readlines():
        pruned = lines.rstrip('\n')
        container_list.append(pruned)
    return container_list

# ------------------------------------------------------------------------------
def getDataSetListFromContainer(container_name):
    p = subprocess.Popen( ['dq2-list-datasets-container', container_name]
                        , stdout = subprocess.PIPE
                        )
    output_string = p.communicate()
    ds_list = output_string[0].split('\n')
    # print '=='
    for ds in ds_list:
        if len(ds) == 0:
            ds_list.remove(ds)
            continue
    # for ds in ds_list:
    #     print '"%s"' % ds
    # print '--'

    return ds_list

# ------------------------------------------------------------------------------
def getDataSetInfo(ds_name):
    p = subprocess.Popen( ['dq2-ls' , '-l' , ds_name]
                        , stdout = subprocess.PIPE
                        )
    output_string = p.communicate()
    dq2_output = output_string[0].split('\n')[0]
    print '\t%s' % dq2_output
    num_files = int(dq2_output.split()[1])
    ds_size   = int(dq2_output.split()[2])
    return {'num_files':num_files , 'size':ds_size*1.e-9}

# ------------------------------------------------------------------------------
def getContainerInfo(container_name):
    print 'getting container size for ' , container_name
    ds_list = getDataSetListFromContainer(container_name)
    num_files      = 0
    container_size = 0.
    for ds in ds_list:
        ds_info = getDataSetInfo(ds)
        num_files      += ds_info['num_files']
        container_size += ds_info['size'    ]
    return {'num_files':num_files , 'size':container_size}

# ==============================================================================
def main():
    container_list = getContainerList(container_list_file_name)
    out_file = file(output_container_size_file_name, 'w')

    for cl in container_list:
        # container_size = getContainerSize(cl)
        container_info = getContainerInfo(cl)
        print cl , ' -- ' , container_info['num_files'] , ' -- ' , container_info['size']
        print ''
        out_file.write( '%s    %s    %s\n' % ( cl
                                             , container_info['num_files']
                                             , container_info['size']
                                             )
                      )
    out_file.close()

# ==============================================================================
if __name__ == '__main__':
    main()
