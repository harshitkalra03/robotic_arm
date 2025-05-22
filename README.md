# Robotic Arm - 6 DoF
## Project Description
A basic programmable arm, introducing concepts of **automation and control**. It is a 6 degree of freedom robotic arm, with gripper as **End-Effector**. A 6 DOF robotic arm is designed to mimic the movement capabilities of a human arm, providing six independent axes of motion. The six degree of freedom, include 3 rotational (roll, pitch and yaw) and three translational - enabling end-effector to point at any point in the space. 

The robotic arm has 6 links:
* Base
* Shoulder
* Forearm
* Wrist Roll
* Wrist Pitch
* Gripper

It is a prototype model, can be manually-controlled by 3-PS2 joystick modules, each handling 2 degree of freedom, integrated in an handmade controller.
The prototype robotic arm uses two types of servo motors — SG90 and MG995, with three of each. While these servos are not high-torque models, they are well-suited for handling lightweight tasks, making them ideal for early-stage testing and demonstrations.
An Arduino UNO R3 serves as the brain of the system, programmed to control the servos using a polling algorithm. This algorithm smoothly maps the input from a joystick to corresponding joint movements, enabling intuitive control. To enhance stability and prevent unintended motion, a deadzone is implemented — ensuring the arm doesn't react to minor joystick nudges or abrupt releases from extreme positions.

## Components Used
### Hardware
1. 3D Printed Parts for Links
2. Pointed Edge Screws
3. M4 Nut & Bolts
### Electronics
1. [SG90 Servo Motors - 180 Degree Rotation](https://robu.in/product/towerpro-sg90-9gm-1-2kg-180-degree-rotation-servo-motor-good-quality/?msclkid=99c201b78bc9186811516999583f0516&utm_source=bing&utm_medium=cpc&utm_campaign=PMax-Motors,%20Drivers,%20Pumps%20%26%20Actuators%20-%20Jan%202025&utm_term=2328559470122370&utm_content=RC%20Servo%20Motors)
2. [MG995 Servo Motors - 180 Degree Rotation](https://robu.in/product/towerpro-mg995-metal-gear-servo-motor/?msclkid=6700b32559a511bfc62cdb0b8deb839b&utm_source=bing&utm_medium=cpc&utm_campaign=PMax-Motors,%20Drivers,%20Pumps%20%26%20Actuators%20-%20Jan%202025&utm_term=2328559470122370&utm_content=RC%20Servo%20Motors)
3. [Arduino UNO R3](https://robu.in/product/arduino-uno-r3/)
4. [Lipo Battery - 2200mAh](https://robu.in/product/orange-2200mah-3s-30c60c-lithium-polymer-battery-pack-lipo/)
5. [Buck Module - 5V Step Down](https://robu.in/product/lm2596-hv-dc-dc-buck-converter-4-5-50v-to-3-35v/)
6. [Joystick Module](https://robu.in/product/joystick-module-ps2-breakout-sensor/)
7. Jumper Wires

## Libraries Used
+ Servo.h
+ Arduino.h
  
## Circuit Diagram

## Applications - Robotic Arm
1. <ins>***Industrial Automation***</ins>
   1. Assembly lines in automotive and electronics industries
   2. Welding, painting, and packaging
2. <ins>***Medical Field***</ins>
   1. Surgical robots for minimally invasive procedures
   2. Rehabilitation and physical therapy support
   3. Pharmaceutical handling and lab automation
3. <ins>***Warehouse & Logistics***</ins>
   1. Sorting, picking, and placing items
   2. Loading/unloading packages
   3. Integration with automated storage systems

## Contributors
1. @shlok165
2. Kian Sparrow
