##--------------------------
## Filename: hex2double.py
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##--------------------------

import sys, struct

def hexToDouble(hexString):
    return struct.unpack('<d', struct.pack('<Q', int(hexString,16)))[0]

def main(args):
    doubleString = hexToDouble(args[1])
    print(doubleString)

if __name__ == "__main__":
    main(sys.argv)
