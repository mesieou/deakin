#include <Arduino.h>  // 
#include <Servo.h>

// Create a new servo object:
Servo myservo;

// Define the servo pin:
#define servoPin 9

void setup() {
  myservo.attach(servoPin);
}

void loop() {
  myservo.write(45);
  delay(1000);

  // Task 1: Sweep to other angles
  myservo.write(90);
  delay(1000);
  myservo.write(135);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(1000);

  // Task 2: Smooth sweep from 0 to 180 and back
  for (int angle = 0; angle <= 180; angle++) {
    myservo.write(angle);
    delay(10);
  }
  for (int angle = 180; angle >= 0; angle--) {
    myservo.write(angle);
    delay(10);
  }
}
