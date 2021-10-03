##-----------------------------
## Filename: helloWorld_test.py
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##-----------------------------

import sys
sys.path.append("scripts/python")
import unittest
import helloWorld

class TestStringMethods(unittest.TestCase):

    def testPrintHello(self):
        self.assertEqual("Hello World!", helloWorld.sayHello())

if __name__ == "__main__":
    unittest.main()