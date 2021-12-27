# arduino-stunt-dog-remote
Arduino IR Remote for the Stunt Dog toy robot

This sketch might be useful to someone who lost the remote control or someone that needs an example of sending raw IR codes using the IRremote Arduino library.

## Requirements:
*Components:*
* 1x 100 ohm resistor
* 1x Infrared Led (you can salvage one from an old remote)

*Software:*
* Arduino IDE
* IRremote library (you can install it from Tools->Manage Libraries ... -> Search for IRremote.)

## Instructions
*Hardware*
* Connect the anode (+ ie. longer lead) of the LED to the 100 ohm resistor
* Connect the other leg of the resistor to Arduino pin 3.
* Connect the cathode (- ie. shorter lead) of the LED to Arduino ground (GND).

*Software*
* Copy the StuntDog directory from this repository to your Arduino sketchbook location (you can find the location in your Arduino IDE  under File->Preferences->Settings)
* Restart the Arduino IDE and you should see StuntDog under your Sketchbook. 
* Upload the sketch and open the serial monitor. Set the baud to 115200.

You should now be presented with the menu.

You can now enter the letter that corresponds with the action you want the robot to perform.


https://user-images.githubusercontent.com/2756871/147489510-5dcbe308-b0f3-4101-8a41-045c02c28494.mp4

