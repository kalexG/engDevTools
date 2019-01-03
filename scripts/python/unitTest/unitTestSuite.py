##---------------------------
## Filename: unitTestSuite.py
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##---------------------------

#!/usr/bin/python3.6

# Import unittest
import unittest

# Import test modules
import helloWorld_test
import double2hex_test
import hex2double_test
import readResistor_test

# Initialize test suite
loader = unittest.TestLoader()
suite  = unittest.TestSuite()

# Add desired tests to test suite
suite.addTests(loader.loadTestsFromModule(helloWorld_test))
suite.addTests(loader.loadTestsFromModule(double2hex_test))
suite.addTests(loader.loadTestsFromModule(hex2double_test))
suite.addTests(loader.loadTestsFromModule(readResistor_test))

# Run all unit tests
runner = unittest.TextTestRunner(verbosity=3)
result = runner.run(suite)
