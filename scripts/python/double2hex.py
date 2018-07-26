#!/usr/bin/python3.6

import sys, struct

print(hex(struct.unpack('<Q', struct.pack('<d', float(sys.argv[1])))[0]))
