# magic
Code for magic tricks

This repository is for code I used to create technology-enabled illusions for a seminar I took at the MIT Media Lab called MAS.S66 Magic as Interface, Technology, and Tradition.  The subdirectory titled "Fire" contains code to be run one an Arduino Nano microcontroller.  This Arduino should be connected  to an [HC-05 bluetooth module](http://www.amazon.com/Bluetooth-converter-serial-communication-master/dp/B008AVPE6Q) on pins 8 and 9 and a potentiometer with the varying pin connected to A0.  

The magic trick is to be performed in the following way.  Power on your Arduino (and correspondingly, your bluetooth module).  Pair your Bluetooth module with your computer.  On a Mac this is done from System Preferences -> Bluetooth.  The default 4-digit pin code is 1234.  Once paired, navigate via command line to the directory containing `fire.sh` run the following commands:
  
    export PATH="$PATH:~/path/to/this/directory"
    chmod u+x fire.sh
  
You should now be able to run the command `fire.sh` and see the terminal printing output.  One of these lines of output will be a number, corresponding to the voltage readings from the potentiometer analog input pin.  This number will be between 0 and 1023, which maps linearly to 0-5V.  In performance, the electronics and potentiometer should be placed up your sleeve or in some discreet location on your person.  When you turn the potentiometer all the way to one extreme and lower the voltage on the analog input pin to below .5 volts, the screen of your laptop will "catch on fire".  That is, it will spontaneously open your default web browser and display [this webpage](http://mcdonnell.mit.edu/human/magicfire.html), containing a page-wide video of a roaring fire, implemented with [bigvideo.js](http://dfcb.github.io/BigVideo.js/)
  
