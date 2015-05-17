#Set permisions
sudo chmod o+rwx /dev/tty.AlphaMoney-DevB


#!/bin/bash

# Port setting
stty -f /dev/tty.AlphaMoney-DevB 9600 cs8 cread clocal

# Loop
while [ 1 ]; 
do
    #echo 'LOADING...'
    READ=`dd if=/dev/tty.AlphaMoney-DevB count=2 | sed 's/ //g'`
    echo $READ
    if [ "$READ" -lt 100 ];
    then 
    	python -mwebbrowser http://mcdonnell.mit.edu/human/magicfire.html
    fi
    #echo '[PRESS Ctrl + C TO EXIT]'
done