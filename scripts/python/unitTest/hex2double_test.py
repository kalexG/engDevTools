##-----------------------------
## Filename: hex2double_test.py
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##-----------------------------

#!/usr/bin/python3.6

import unittest
import hex2double

class TestConvsersionMethods(unittest.TestCase):

    def testConversionHexToDouble(self):
        self.assertEqual(100.55, hex2double.hexToDouble("0x4059233333333333"))

if __name__ == "__main__":
    unittest.main()
