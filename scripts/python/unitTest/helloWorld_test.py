#!/usr/bin/python3.6
import unittest
import helloWorld

class TestStringMethods(unittest.TestCase):

    def testPrintHello(self):
        self.assertEqual("Hello World!", helloWorld.sayHello())

if __name__ == "__main__":
    unittest.main()

