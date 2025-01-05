#include <Servo.h>      

//restricted motion of servo
const int MIN = 20;      
const int MAX = 160;     

//intialised speed to zeroi
int speed = 0;

//initialised initial position of arm.
int posn_base = 90;
int posn_shoulder = 90;
int posn_elbow = 90;
int posn_wrist = 90;
int posn_gripper_ud = 90;
int posn_gripper = 90;

//setting position of links on joystick.
const int analog_pin_base = A0; // joystick1 x
const int analog_pin_shoulder = A1; // joystick1 y
const int analog_pin_elbow = A2;  // joystick2 x
const int analog_pin_wrist = A3;   //joystick2 y
const int analog_pin_gripper_ud = A4;  //joystick3 y
const int analog_pin_gripper = A5;  //joystick3 x


const int digital_pin_base = 3;
const int digital_pin_shoulder = 5;
const int digital_pin_elbow = 6;
const int digital_pin_wrist = 9;
const int digital_pin_gripper_ud = 10;
const int digital_pin_gripper = 11;

//Declaring links.
Servo base_servo;
Servo shoulder_servo;
Servo elbow_servo;
Servo wrist_servo;
Servo gripper_ud_servo;
Servo gripper_servo;

//storing last updated time of links movement.
unsigned long last_update_base = 0;
unsigned long last_update_shoulder = 0;
unsigned long last_update_elbow = 0;
unsigned long last_update_wrist = 0;
unsigned long last_update_gripper_ud = 0;
unsigned long last_update_gripper = 0;

//setting interval for calling objects(functions).
const unsigned long update_interval = 20; // Update interval in milliseconds

void setup() {
  //beginning communication with serial monitor through serial port for debugging.
  Serial.begin(9600);

  //declaring analog pins for joysticks.
  pinMode(analog_pin_base, INPUT);
  pinMode(analog_pin_shoulder, INPUT);
  pinMode(analog_pin_elbow, INPUT);
  pinMode(analog_pin_wrist, INPUT);
  pinMode(analog_pin_gripper_ud, INPUT);
  pinMode(analog_pin_gripper, INPUT);

  //intialising servo objects.
  base_servo.attach(digital_pin_base);
  shoulder_servo.attach(digital_pin_shoulder);
  elbow_servo.attach(digital_pin_elbow);
  wrist_servo.attach(digital_pin_wrist);
  gripper_ud_servo.attach(digital_pin_gripper_ud);
  gripper_servo.attach(digital_pin_gripper);

  // initialization
  base_servo.write(posn_base);
  shoulder_servo.write(posn_shoulder);
  elbow_servo.write(posn_elbow);
  wrist_servo.write(posn_wrist);
  gripper_ud_servo.write(posn_gripper_ud);
  gripper_servo.write(posn_gripper);
}

void arm(int &posn, int analog_pin_link, Servo &link_servo, unsigned long &last_update) {
  unsigned long current_time = millis();  // recording current time.
  
  //reading joystick value only after a threshold time interval.
  if (current_time - last_update >= update_interval) {    
    int js_read = analogRead(analog_pin_link);
    speed = map(js_read, 0, 1023, -3, 3);   //adjusting speed according joystick movement.

    //setting a dead zone for joystick.
    if (js_read <= 450 || js_read >= 550) {  
      posn += speed;
      posn = constrain(posn, MIN, MAX);   //restricting extreme values of position.
      link_servo.write(posn);
    }
    last_update = current_time;
  }
}

void loop() {
  //calling arm methods.
  arm(posn_base, analog_pin_base, base_servo, last_update_base);
  arm(posn_shoulder, analog_pin_shoulder, shoulder_servo, last_update_shoulder);
  arm(posn_elbow, analog_pin_elbow, elbow_servo, last_update_elbow);
  arm(posn_wrist, analog_pin_wrist, wrist_servo, last_update_wrist);
  arm(posn_gripper_ud, analog_pin_gripper_ud, gripper_ud_servo, last_update_gripper_ud);
  arm(posn_gripper, analog_pin_gripper, gripper_servo, last_update_gripper);
}   
