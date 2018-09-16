#!/usr/bin/python3.6
import unittest
import sys
sys.path.insert(0, '/home/kalexg/Documents/engDevTools/scripts/python')
import double2hex

class TestConvsersionMethods(unittest.TestCase):

    def testConversionDoubleToHex(self):
        self.assertEqual("0x4059233333333333", double2hex.doubleToHex(100.55))

if __name__ == "__main__":
    unittest.main()
