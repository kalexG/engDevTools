#!/usr/bin/python3.6

import unittest
import sys
sys.path.insert(0, '/home/kalexg/Documents/engDevTools/scripts/python')
import readResistor

class TestArgumentParseMethods(unittest.TestCase):
        
    def testStoreTwoDigitBands(self):
        parser = readResistor.parseArguments(['-d', 'red', 'blue'])
        self.assertEqual(parser.digits, ['red', 'blue'])
        parser = readResistor.parseArguments(['--digits', 'blue', 'yellow'])
        self.assertEqual(parser.digits, ['blue', 'yellow'])
    
    def testStoreThreeDigitBands(self):
        parser = readResistor.parseArguments(['-d', 'red', 'blue', 'green'])
        self.assertEqual(['red', 'blue', 'green'], parser.digits)
        parser = readResistor.parseArguments(['--digits', 'blue', 'green', 'yellow'])
        self.assertEqual(['blue', 'green', 'yellow'], parser.digits)

    def testStoreMultiplerBand(self):
        parser = readResistor.parseArguments(['-m', '10'])
        self.assertEqual(parser.multiplier, ['10'])
        parser = readResistor.parseArguments(['--multiplier', '11'])
        self.assertEqual(parser.multiplier, ['11'])

    def testStoreCombination(self):
        parser = readResistor.parseArguments(['-d', '1', '2', '3', '-m', '4', '-t', '5', '-q' ])
        self.assertEqual(parser.digits, ['1', '2', '3'])
        self.assertEqual(parser.multiplier, ['4'])
        self.assertEqual(parser.tolerance, ['5'])
        self.assertEqual(parser.quiet, True)
        self.assertEqual(parser.verbose, False)
        parser = readResistor.parseArguments(['--digits', '2', '3', '4', '--multiplier', '5', '--tolerance', '6', '--verbose' ])
        self.assertEqual(parser.digits, ['2', '3', '4'])
        self.assertEqual(parser.multiplier, ['5'])
        self.assertEqual(parser.tolerance, ['6'])
        self.assertEqual(parser.quiet, False)
        self.assertEqual(parser.verbose, True)

    def testStoreToleranceBand(self):
        parser = readResistor.parseArguments(['-t', '5'])
        self.assertEqual(parser.tolerance, ['5'])
        parser = readResistor.parseArguments(['--tolerance', '6'])
        self.assertEqual(parser.tolerance, ['6'])

    def testVerbose(self):
        parser = readResistor.parseArguments(['-v'])
        self.assertTrue(parser.verbose)
        parser = readResistor.parseArguments(['--verbose'])
        self.assertTrue(parser.verbose)

    def testQuiet(self):
        parser = readResistor.parseArguments(['-q'])
        self.assertTrue(parser.quiet)
        parser = readResistor.parseArguments(['--quiet'])
        self.assertTrue(parser.quiet)

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
