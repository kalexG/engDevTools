##-------------------------------
## Filename: readResistor_test.py
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##-------------------------------

#!/usr/bin/python3.6

import unittest
import readResistor
import argparse

class TestArgumentParseMethods(unittest.TestCase):

    def testStoreTwoDigitBands(self):
        parser = readResistor.parseArguments(['-d', 'red', 'blue', '-m', 'red'])
        self.assertEqual(parser.digits, ['red', 'blue'])
    
    def testStoreThreeDigitBands(self):
        parser = readResistor.parseArguments(['-d', 'red', 'blue', 'green', '-m', 'red'])
        self.assertEqual(['red', 'blue', 'green'], parser.digits)

    def testStoreMultiplerBand(self):
        parser = readResistor.parseArguments(['-d', 'red', 'red', '-m', 'red'])
        self.assertEqual(parser.multiplier, ['red'])

    def testMultiplierRequired(self):
        with self.assertRaises(SystemExit) as context:
            readResistor.parseArguments(['-d', 'red', 'red'])

    def testStoreCombination(self):
        parser = readResistor.parseArguments(['-d', '1', '2', '3', '-m', '4', '-t', '5', '-q' ])
        self.assertEqual(parser.digits, ['1', '2', '3'])
        self.assertEqual(parser.multiplier, ['4'])
        self.assertEqual(parser.tolerance, ['5'])
        self.assertEqual(parser.quiet, True)
        self.assertEqual(parser.verbose, False)

    def testStoreToleranceBand(self):
        parser = readResistor.parseArguments(['-d', 'red', 'red', '-m', 'red', '-t', 'red'])
        self.assertEqual(parser.tolerance, ['red'])

    def testVerbose(self):
        parser = readResistor.parseArguments(['-d', 'red', 'red', '-m', 'red', '-v'])
        self.assertTrue(parser.verbose)

    def testQuiet(self):
        parser = readResistor.parseArguments(['-d', 'red', 'red', '-m', 'red', '-q'])
        self.assertTrue(parser.quiet)

    def testExceptionLowerBoundDigitBand(self):
        with self.assertRaises(argparse.ArgumentTypeError) as context:
            readResistor.parseArguments(['-d', 'red', '-m', 'red'])
        self.assertTrue('argument "digits" requires between 2 and 3 arguments' in str(context.exception))

    def testExceptionUpperBoundDigitBand(self):
        with self.assertRaises(argparse.ArgumentTypeError) as context:
            readResistor.parseArguments(['-d', 'red', 'red', 'red', 'red', '-m', 'red'])
        self.assertTrue('argument "digits" requires between 2 and 3 arguments' in str(context.exception))

    def testMutuallyExclusiveVerbosity(self):
        with self.assertRaises(SystemExit) as context:
            readResistor.parseArguments(['-d', 'red', 'red', '-m', 'red', '-v', '-q'])

    def testDigitsRequired(self):
        with self.assertRaises(SystemExit) as context:
            readResistor.parseArguments(['-m', 'red'])

    def testMultipleMultiplerBands(self):
        with self.assertRaises(SystemExit) as context:
            readResistor.parseArguments(['-d', 'red', 'red', '-m', 'red', 'red'])

    def testMultipleToleranceBands(self):
        with self.assertRaises(SystemExit) as context:
            readResistor.parseArguments(['-d', 'red', 'red', '-m', 'red', '-t', 'red', 'red'])

#class TestResistorDerivation(unittest.TestCase):

#    def testThreeBand(self):
#        self.assertTrue(False)

#    def testTwoBand(self):
#        self.assertTrue(False)

#class TestExceptions(unittest.TestCase):
        
#    def testNoFirstBandInputError(self):
#        self.assertTrue(False)

#    def testNoSecondBandInputError(self):
#        self.assertTrue(False)

#    def testNoMultiplierError(self):
#        self.assertTrue(False)

#    def testNoToleranceWarning(self):
#        self.assertTrue(False)

#    def testMultipleExceptions(self):
#        self.assertTrue(False)

if __name__ == "__main__":
    unittest.main()
