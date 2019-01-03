##--------------------------
## Filename: cleanDir.sh
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##--------------------------

#!/bin/bash

echo "Cleaning directory..."
echo "Removing .csv"

# Conditional to determine whether move files or remove them


if [ "$1" = "rm" ]
then
   echo "Removing Stuff"
   edt=($(find ~/* -name "engDevTools"))
   echo ${#edt[@]}
   for i in {0..${#distro[@]}}
   do
      echo "How many times?"
   done

elif [ "$1" = "mv" ]
then
   echo "Moving Stuff"
else 
   echo "Default to removing stuff"
fi
