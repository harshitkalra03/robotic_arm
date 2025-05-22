# 🤖 Robotic Arm – 6 DoF
## 📌 Project Description
This project features a 6 Degrees of Freedom (DoF) programmable robotic arm designed to introduce foundational concepts in **automation and control**. Inspired by the _**biomechanics of a human arm**_, this robotic arm provides six independent axes of motion—three rotational (**roll, pitch, yaw**) and **three translational**—allowing the gripper end-effector to **orient and position** itself at any point in 3D space.

The six key segments of the robotic arm include:
* **Base**
* **Shoulder**
* **Forearm**
* **Wrist Roll**
* **Wrist Pitch**
* **Gripper**

This prototype model is manually controlled using **three PS2 joystick modules**, each responsible for two degrees of freedom, embedded in a **handcrafted control unit**.<br>
The arm employs two types of servo motors—**SG90** and **MG995** (three each). While not high-torque, these motors are well-suited for lightweight manipulation tasks, making the setup ideal for testing, learning, and proof-of-concept applications.<br>
At its core, the system uses an **Arduino UNO R3** to process control signals via a **polling algorithm**. The algorithm maps joystick input linearly to joint movement and incorporates a **deadzone** to filter out accidental or sudden joystick releases, ensuring smoother and more stable operation.

## 🔩 Components Used
### 🛠 Hardware
1. 3D Printed Parts for Links
2. Pointed Edge Screws
3. M4 Nut & Bolts
### 🔌 Electronics
1. [SG90 Servo Motors - 180 Degree Rotation](https://robu.in/product/towerpro-sg90-9gm-1-2kg-180-degree-rotation-servo-motor-good-quality/?msclkid=99c201b78bc9186811516999583f0516&utm_source=bing&utm_medium=cpc&utm_campaign=PMax-Motors,%20Drivers,%20Pumps%20%26%20Actuators%20-%20Jan%202025&utm_term=2328559470122370&utm_content=RC%20Servo%20Motors)
2. [MG995 Servo Motors - 180 Degree Rotation](https://robu.in/product/towerpro-mg995-metal-gear-servo-motor/?msclkid=6700b32559a511bfc62cdb0b8deb839b&utm_source=bing&utm_medium=cpc&utm_campaign=PMax-Motors,%20Drivers,%20Pumps%20%26%20Actuators%20-%20Jan%202025&utm_term=2328559470122370&utm_content=RC%20Servo%20Motors)
3. [Arduino UNO R3](https://robu.in/product/arduino-uno-r3/)
4. [Lipo Battery - 2200mAh](https://robu.in/product/orange-2200mah-3s-30c60c-lithium-polymer-battery-pack-lipo/)
5. [Buck Module - 5V Step Down](https://robu.in/product/lm2596-hv-dc-dc-buck-converter-4-5-50v-to-3-35v/)
6. [Joystick Module](https://robu.in/product/joystick-module-ps2-breakout-sensor/)
7. Jumper Wires

## 📚 Libraries Used
+ [Servo.h](https://github.com/arduino-libraries/Servo)
+ Arduino.h
  
## ⚡ Circuit Diagram
> (To be added as Schematic-Image)

## 🛠 Applications of Robotic Arm
1. 🏭 <ins>***Industrial Automation***</ins>
   1. Assembly lines in automotive and electronics industries
   2. Welding, painting, and packaging
2. 🏥 <ins>***Medical Field***</ins>
   1. Surgical robots for minimally invasive procedures
   2. Rehabilitation and physical therapy support
   3. Pharmaceutical handling and lab automation
3. 📦 <ins>***Warehouse & Logistics***</ins>
   1. Sorting, picking, and placing items
   2. Loading/unloading packages
   3. Integration with automated storage systems

## 👥 Contributors
+ [**Robotics Club**](https://www.linkedin.com/company/robotics-club-iitrpr/), IIT Ropar
  **Role:** Mentorship, Logistics Help, Guidance
+ [**Shlok Narayan Vaidya**](https://www.linkedin.com/in/shlok-vaidya-138803326/), B.Tech Artificial Intelligence & Data Science, IIT Ropar
  **Role:** Embedded Programming, Control System Design
+ [**Kian Sparrow**](https://www.linkedin.com/in/kian-sparrow-4a6361320/), B.Tech Engineering Physics, IIT Ropar
  **Role:** Fabrication, Control System Design, Embedded Programming
+ [**Harshit Kalra**](https://www.linkedin.com/in/harshit-kalra-84309a317/), B.Tech Electrical Engineering, IIT Ropar
  **Role:** Electronics, Embedded Programming, Fabrication
  
