#!/usr/bin/python3

import subprocess
import re
import os
import sys

def compProgOut(message, args):
    print(message +": ", end="")
    argArr = re.split(" ", args)
    pyProgOut = subprocess.Popen(["./range.py"] + argArr, stdout=subprocess.PIPE).communicate()[0].decode('ASCII')
    cppProgOut = subprocess.Popen(["./a.out"] + argArr, stdout=subprocess.PIPE).communicate()[0].decode('ASCII')
    

    if pyProgOut == cppProgOut:
        print ('\033[92m' + "test passed" + '\033[0m')
    else:
        print ('\033[91m'+"test failed"+'\033[0m')



compProgOut("testing with only last", "5")
compProgOut("testing with 0 as only arg", "0")
compProgOut("testing with single negative arg", "-5")
compProgOut("testing with first < last", "1 5")
compProgOut("testing with first = last", "5 5")
compProgOut("testing with first > last", "15 5")
compProgOut("testing with first < last, step = 1", "1 10 1")
compProgOut("testing with first < last, step = 3", "1 30 3")
compProgOut("testing with first > last, step < 0", "15 5 -2")
compProgOut("testing with first < last, step < 0", "5 15 -2")