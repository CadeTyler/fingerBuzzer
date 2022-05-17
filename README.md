# fingerBuzzer
Project that vibrates individual fingertips with Arduino and vibration motors upon virtual collisions between fingertips and objects in VR

 ________________________________________________________________________________________________________________________

This project requires the following items:

  Unity
  
  Arduino - the original project used an Arduino Nano but most will work as long as the operating voltage is high enough to drive the vibration motors
  
  Oculus Quest (1 or 2)
  
  Glove
  
  5 mini vibration motors (similar to these: https://www.amazon.com/tatoko-Vibration-Button-Type-Vibrating-Appliances/dp/B07Q1ZV4MJ/ref=sr_1_5?crid=10YNB0TU870ZS&keywords=piezo+motors&qid=1652753386&sprefix=piezo+motor%2Caps%2C70&sr=8-5)
  
  Conductive thread (reccomended)
  
 ________________________________________________________________________________________________________________________

Steps to replicate this project are as follows:
1. Create a glove with a vibration motor on each of the fingertips and an Arduino in a comfortable location. Conductive thread can be used to wire the vibration motor to the pins of the arduino. Currently this project only supports wired communication so a battery is not neccesary. For demonstration purposes, LEDs can be wired to the arduino instead of vibration motors.
3. Create a Unity project
4. Set up Unity for development in VR for the Oculus Quest. An example tutorial can be found here: https://www.xrterra.com/developing-for-vr-with-quest-2-unity-for-the-first-time-a-step-by-step-guide/
5. Set up "OVRCameraRig". A tutorial can be found here: https://developer.oculus.com/documentation/unity/unity-add-camera-rig/
6. Within the project, create a cube and add "fingerBuzzer_Unity.cs" to the cube. This script handles collisions and sends the data to Arduino once per frame
7. In fingerBuzzer_Arduino.ino", update line 3 ( const short pins[] = {2,3,6,9,12}; ) " with the correct pins
8. Upload "fingerBuzzer_Arduino.ino" to your Arduino board of choice. 
9. Take note of the serial port in the Arduino IDE and update line 13 ( public SerialPort sp = new SerialPort("COM6",9600); ) in "fingerBuzzer_Unity.cs" with the correct serial port
10. Conect your Quest to your computer using Oculus Link
11. Double check that the computer is plugged in (for performance reasons), Quest is plugged into the computer, and the arduino is plugged into the computer
12. Click "Play" in unity to experience the demonstration
