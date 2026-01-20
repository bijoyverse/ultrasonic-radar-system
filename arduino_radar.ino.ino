#include <Servo.h>

const int TRIG = 9;
const int ECHO = 8;
const int SERVO_PIN = 3;

float duration_us, distance_cm;
Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  myServo.attach(SERVO_PIN);
}

void loop() {
  // Sweep forward
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(15);
    distance_cm = getDistance();
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance_cm);
  }
  
  // Sweep backward
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(15);
    distance_cm = getDistance();
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance_cm);
  }
}

float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration_us = pulseIn(ECHO, HIGH);
  return (0.017 * duration_us); // cm
}
