#!/usr/bin/python3.6

# Import unittest
import unittest

# Import test modules
import helloWorld_ut
import double2hex_ut
import hex2double_ut
import readResistor_ut

# Initialize test suite
loader = unittest.TestLoader()
suite  = unittest.TestSuite()

# Add desired tests to test suite
suite.addTests(loader.loadTestsFromModule(helloWorld_ut))
suite.addTests(loader.loadTestsFromModule(double2hex_ut))
suite.addTests(loader.loadTestsFromModule(hex2double_ut))
suite.addTests(loader.loadTestsFromModule(readResistor_ut))

# Run all unit tests
runner = unittest.TextTestRunner(verbosity=3)
result = runner.run(suite)
