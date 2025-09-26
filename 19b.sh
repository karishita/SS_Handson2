#
#Name : 19b.sh
#Author : Ishita Kar
#Description:Create A FIFO by mkfifo command
#Date: 20th Sep, 2025.
#_______________________________________________________________________________

#!/bin/bash

mkfifo mypipe1

#________________________________________________________________________________
#Terminal 1:
#echo "Hello.." > mypipe1

#Terminal 2:
#Hello..
#_________________________________________________________________________________
