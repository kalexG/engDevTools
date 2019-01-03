##--------------------------
## Filename: helloWorld.py
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##--------------------------

#!/usr/bin/python3.6

def sayHello():
    myHelloString = "Hello World!"
    return myHelloString

def main():
    helloString = sayHello()
    print(helloString)

if __name__ == "__main__":
    main()
