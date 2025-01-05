#include <Servo.h>

const int MIN = 20;
const int MAX = 160;

int speed = 0;

int posn_base = 90;
int posn_shoulder = 90;
int posn_elbow = 90;
int posn_wrist = 90;
int posn_gripper_ud = 90;
int posn_gripper = 90;

const int analog_pin_base = A0; // js1 x
const int analog_pin_shoulder = A1; // js1 y
const int analog_pin_elbow = A2;
const int analog_pin_wrist = A3;
const int analog_pin_gripper_ud = A4;
const int analog_pin_gripper = A5;

const int digital_pin_base = 3;
const int digital_pin_shoulder = 5;
const int digital_pin_elbow = 6;
const int digital_pin_wrist = 9;
const int digital_pin_gripper_ud = 10;
const int digital_pin_gripper = 11;

Servo base_servo;
Servo shoulder_servo;
Servo elbow_servo;
Servo wrist_servo;
Servo gripper_ud_servo;
Servo gripper_servo;

unsigned long last_update_base = 0;
unsigned long last_update_shoulder = 0;
unsigned long last_update_elbow = 0;
unsigned long last_update_wrist = 0;
unsigned long last_update_gripper_ud = 0;
unsigned long last_update_gripper = 0;

const unsigned long update_interval = 20; // Update interval in milliseconds

void setup() {
  Serial.begin(9600);

  pinMode(analog_pin_base, INPUT);
  pinMode(analog_pin_shoulder, INPUT);
  pinMode(analog_pin_elbow, INPUT);
  pinMode(analog_pin_wrist, INPUT);
  pinMode(analog_pin_gripper_ud, INPUT);
  pinMode(analog_pin_gripper, INPUT);

  base_servo.attach(digital_pin_base);
  shoulder_servo.attach(digital_pin_shoulder);
  elbow_servo.attach(digital_pin_elbow);
  wrist_servo.attach(digital_pin_wrist);
  gripper_ud_servo.attach(digital_pin_gripper_ud);
  gripper_servo.attach(digital_pin_gripper);

  // Initialization
  base_servo.write(posn_base);
  shoulder_servo.write(posn_shoulder);
  elbow_servo.write(posn_elbow);
  wrist_servo.write(posn_wrist);
  gripper_ud_servo.write(posn_gripper_ud);
  gripper_servo.write(posn_gripper);
}

void arm(int &posn, int analog_pin_link, Servo &link_servo, unsigned long &last_update) {
  unsigned long current_time = millis();
  if (current_time - last_update >= update_interval) {
    int js_read = analogRead(analog_pin_link);
    speed = map(js_read, 0, 1023, -3, 3);

    if (js_read <= 450 || js_read >= 550) {
      posn += speed;
      posn = constrain(posn, MIN, MAX);
      link_servo.write(posn);
    }
    last_update = current_time;
  }
}

void loop() {
  arm(posn_base, analog_pin_base, base_servo, last_update_base);
  arm(posn_shoulder, analog_pin_shoulder, shoulder_servo, last_update_shoulder);
  arm(posn_elbow, analog_pin_elbow, elbow_servo, last_update_elbow);
  arm(posn_wrist, analog_pin_wrist, wrist_servo, last_update_wrist);
  arm(posn_gripper_ud, analog_pin_gripper_ud, gripper_ud_servo, last_update_gripper_ud);
  arm(posn_gripper, analog_pin_gripper, gripper_servo, last_update_gripper);
}   