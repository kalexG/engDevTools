#!/usr/bin/python3.6

import sys, struct

def doubleToHex(doubleString):
    return hex(struct.unpack('<Q', struct.pack('<d', float(doubleString)))[0])

def main(args):
    hexString = doubleToHex(args[1])
    print(hexString)

if __name__ == "__main__":
    main(sys.argv)
