##--------------------------
## Filename: readResistor.py
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##--------------------------

#!/usr/bin/python3.6

import sys
import argparse
import warnings

def parseArguments(args):
    """
    Parses command line arguments and stores into argparse object.

    Parameters
    ----------
    args : list
        List of command line arguments

    Returns
    -------
    parsedArgs : object
        Argparse object containing parsed command line arguments

    """
    parser = argparse.ArgumentParser(description = "Decode resistor bands")
    group = parser.add_mutually_exclusive_group()
    group.add_argument("-v", "--verbose", action="store_true", help="increase output verbosity")
    group.add_argument("-q", "--quiet", action="store_true", help="decrease output verbosity")
    required = parser.add_argument_group("required arguments")
    required.add_argument('-d', '--digits', nargs= '+', action=argumentRange(2,3), required=True,  help="color of digit bands (number of digit bands = 2 or 3)")
    required.add_argument('-m', '--multiplier', nargs=1, required=True,  help="color of multipler band")
    parser.add_argument('-t', '--tolerance', nargs=1, help="color of tolerance band")
    parsedArgs = parser.parse_args(args)
    return parsedArgs

def argumentRange(minA, maxA):
    """
    Raises exception if a command line input exceeds specified boundaries for provided arguments.

    Parameters
    ----------
    minA : int
        Minumum number of arguments for command line input
    maxA : int
        Maximum number of arguments for command line input

    Returns
    -------
    argumentRangeError : argparse.Action


    """
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
    if tol is None:
        listBands = dig + mul
    else:
        listBands = dig + mul + tol
    digitsStr = ""
    if all(elem in list(colorDict.keys()) for elem in listBands):
        for band in dig:
            if colorDict[band][0] != "none":
                digitsStr = digitsStr + str(colorDict[band][0])
            else:
                raise ValueError('Invalid digit color entered: {}'.format(band))
        resistance = int(digitsStr)
        if colorDict[mul[0]][1] != "none":
            resistance *= colorDict[mul[0]][1]
        else:
            raise ValueError('Invalid multipler color entered: {}'.format(mul))
        if tol is None:
            tolerance = None
        else:
            if colorDict[tol[0]][2] != "none":
                tolerance = colorDict[tol[0]][2]
            else:
                raise ValueError('Invalid tolerance color entered: {}'.format(tol))
    else:
        badBand = []
        for band in listBands:
            if band not in colorDict.keys():
                badBand.append(band)
        raise ValueError('Invalid color entered: {}'.format(badBand))
    return [resistance, tolerance]

def main():
    print("readResistor!")
    args = sys.argv[1:]
    # Parse arguments
    parser = parseArguments(args)
    # Issue warnings
    warningMultiplerTolerance(parser.multiplier,parser.tolerance)
    # Execute main function
    decodedResistance = decodeResistance(parser.digits, parser.multiplier, parser.tolerance)
    #  Handle results
    print(decodedResistance)

if __name__ == "__main__":
   main()
