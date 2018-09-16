#!/usr/bin/python3.6

import unittest
import sys
sys.path.insert(0, '/home/kalexg/Documents/engDevTools/scripts/python')
import readResistor

class TestDictionaryParseMethods(unittest.TestCase):
        
    def testReadFirstBand(self):
        self.assertTrue(False)
    
    def testReadSecondBand(self):
        self.assertTrue(False)

    def testReadThirdBand(self):
        self.assertTrue(False)

    def testReadMultiplier(self):
        self.assertTrue(False)

    def testReadTolerance(self):
        self.assertTrue(False)

    def testNoThirdBand(self):
        self.assertTrue(False)

class TestResistorDerivation(unittest.TestCase):

    def testThreeBand(self):
        self.assertTrue(False)

    def testTwoBand(self):
        self.assertTrue(False)

class TestExceptions(unittest.TestCase):
        
    def testNoFirstBandInputError(self):
        self.assertTrue(False)

    def testNoSecondBandInputError(self):
        self.assertTrue(False)

    def testNoMultiplierError(self):
        self.assertTrue(False)

    def testNoToleranceWarning(self):
        self.assertTrue(False)

    def testMultipleExceptions(self):
        self.assertTrue(False)

if __name__ == "__main__":
    unittest.main()
