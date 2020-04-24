#!/usr/bin/python3

import sys

if len(sys.argv) == 2:
    for i in range(int(sys.argv[1])):
        print(i)

elif len(sys.argv) == 3:
    for i in range(int(sys.argv[1]), int(sys.argv[2])):
        print(i)

elif len(sys.argv) == 4:
    for i in range(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])):
        print(i)