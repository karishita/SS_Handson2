#
#Name : 19a.sh
#Author : Ishita Kar
#Description:Create a fifo by mknod command
#Date: 20th Sep, 2025.
#_______________________________________________________________________________
#


#!/bin/bash
mknod mypipe p

#_________________________________________________________________________________
#OUTPUT
#Terminal 1:
#echo "Hello" > mypipe

#TYPE 2:
#cat mypipe
#Hello
#_________________________________________________________________________________

