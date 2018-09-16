#!/usr/bin/python3.6

import sys
import argparse

def parseArguments(args):
    parser = argparse.ArgumentParser(description = "Decode resistor bands")
    group = parser.add_mutually_exclusive_group()
    group.add_argument("-v", "--verbose", action = "store_true", help = "increase output verbosity")
    group.add_argument("-q", "--quiet", action = "store_true", help = "decrease output verbosity")
    parser.add_argument('-b', '--bands', nargs = "+", help = "color of bands (number of bands = 2 or 3)")
    parser.add_argument('-m', '--multiplier', help = "color of multipler")
    parser.add_argument('-t', '--tolerance', help = "color of tolerance")
    return parser.parse_args()

def raiseExceptionsWarnings():
    print("raiseExceptionsWarnings")

def decodeResistance():
    print("decodeResistance")

def main():
    print("readResistor!")
    args = sys.argv[1:]
    print(args)
    parser = parseArguments(args)
    print(parser.bands)
    print(parser.multiplier)
    print(parser.tolerance)

if __name__ == "__main__":
   main()
