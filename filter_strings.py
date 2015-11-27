#!/usr/bin/python
# -*- coding: UTF-8 -*-

import string
import re

log_path = r"D:\userdata\chanhan\Desktop\tmp\2015-11-23\cNG_Capella_20151119\journal_GWN-2.log"
filter_str = r'trace_proxy.bin'

def make_new_file_path(old_path):
    return old_path + "_filter_" + filter_str + '.log'

if __name__ == '__main__':
    new_fp = open(make_new_file_path(log_path), 'w')
    with open(log_path, 'r+') as openfileobject:
        for line in openfileobject:
            if filter_str in line:
                new_fp.write(line)

    new_fp.flush()






