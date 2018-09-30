#!/usr/bin/python3.6

import sys
import argparse
import warnings

def parseArguments(args):
    parser = argparse.ArgumentParser(description = "Decode resistor bands")
    group = parser.add_mutually_exclusive_group()
    group.add_argument("-v", "--verbose", action="store_true", help="increase output verbosity")
    group.add_argument("-q", "--quiet", action="store_true", help="decrease output verbosity")
    parser.add_argument('-d', '--digits', nargs= '+', action=argumentRange(2,3),  help="color of digit bands (number of digit bands = 2 or 3)")
    parser.add_argument('-m', '--multiplier', nargs=1,  help="color of multipler band")
    parser.add_argument('-t', '--tolerance', nargs=1, help="color of tolerance band")
    parsedArgs = parser.parse_args(args)
    return parsedArgs

def argumentRange(minA, maxA):
    class argumentRangeError(argparse.Action):
        def __call__(self, parser, args, values, option_string=None):
            if not minA<=len(values)<=maxA:
                msg='argument "{}" requires between {} and {} arguments'.format(self.dest,minA,maxA)
                raise argparse.ArgumentTypeError(msg)
            setattr(args, self.dest, values)
    return argumentRangeError

def warningMultiplerTolerance(mul, tol):
    if mul == None:
        warnings.warn("You didn't provide a multipler as an input.", UserWarning)
    if tol == None:
        warnings.warn("You didn't provide a tolerance as an input.", UserWarning)

def exceptionNonIntegerArguments():
    print("exceptionNonIntegerArguments")

def decodeResistance(dig, mul, tol):
    colorDict = { 
        "black"  : [ 0,      1,         "none"  ],
        "brown"  : [ 1,      10,        "1%"    ],
        "red"    : [ 2,      100,       "2%"    ],
        "orange" : [ 3,      1000,      "none"  ],
        "yellow" : [ 4,      10000,     "none"  ],
        "green"  : [ 5,      100000,    "0.5%"  ],
        "blue"   : [ 6,      1000000,   "0.25%" ],
        "violet" : [ 7,      10000000,  "0.1%"  ],
        "grey"   : [ 8,      "none",    "0.05%" ],
        "white"  : [ 9,      "none",    "none"  ],
        "gold"   : [ "none", 0.1,       "5%"    ],
        "silver" : [ "none", 0.01,      "10%"   ]
    }
    listBands = dig + mul + tol
    digitsStr = ""
    if all(elem in list(colorDict.keys()) for elem in listBands):
        for band in dig:
            if colorDict[band][0] != "none":
                digitsStr = digitsStr + str(colorDict[band][0])
            else:
                print("EXCEPTION: digits invalid")
                return
        resistance = int(digitsStr)
        if colorDict[mul[0]][1] != "none":
            resistance *= colorDict[mul[0]][1]
        else:
            print("EXCEPTION: multiplier invalid")
            return
        if colorDict[tol[0]][2] != "none":
            tolerance = colorDict[tol[0]][2]
        else:
            print("EXCEPTION: tolerance invalid")
            return
    else:
        print("EXCEPTION: colors invalid")
        return
    return [resistance, tolerance]

def main():
    print("readResistor!")
    args = sys.argv[1:]
    parser = parseArguments(args)
    warningMultiplerTolerance(parser.multiplier,parser.tolerance)
    decodedResistance = decodeResistance(parser.digits, parser.multiplier, parser.tolerance)
    print(decodedResistance)
if __name__ == "__main__":
   main()
