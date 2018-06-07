#!/usr/bin/python3.6

import sys, struct

print(struct.unpack('<d', struct.pack('<Q', int(sys.argv[1],16)))[0])
