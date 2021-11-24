# ObjectSenserWithArduino

This project is based on the development of an accident prevention and detection device in personal mobility vehicles with a low-cost microcontroller. The device will approach in case any danger is approaching the device, in which case the LED bulbs that the device will have incorporated will be turned on, which will be turned on in 3 phases according to the level of proximity of the possible danger:

  - Level 1: It is located at a distance X. 

  - Level 2: It is located at a distance Y, being Y less than X.

  - Level 3: It is located at a distance Z, with Z being less than Y. 

In case of reaching level 1, the first 2 LED bulbs will be turned on but there will be no audible warning. From level 2, apart from keeping the 2 LED bulbs of level 1 on, another 2 bulbs will be turned on and an audible warning will be made every 2 seconds. And finally, at level 3, apart from maintaining level 2, the remaining bulbs will be turned on and the frequency will be increased from 2 to 1 second.

Here the step-by-step development of everything that has been done will be shown, along with all the elements used, whose data and link to acquire them have also been added.
