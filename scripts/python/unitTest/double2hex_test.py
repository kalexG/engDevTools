##-----------------------------
## Filename: double2hex_test.py
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##-----------------------------

import sys
sys.path.append("scripts/python")
import unittest
import double2hex

class TestConvsersionMethods(unittest.TestCase):

    def testConversionDoubleToHex(self):
        self.assertEqual("0x4059233333333333", double2hex.doubleToHex(100.55))

if __name__ == "__main__":
    unittest.main()
