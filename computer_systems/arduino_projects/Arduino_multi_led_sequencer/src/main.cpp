#include <Arduino.h>
#include <DHT.h>

// Define DHT sensor
int led1 = 2;
int led2 = 3;
int button1 = 5;
int button2 = 4;

void setup() {
  // setting the leds 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // setting the buttons
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {
  
  // If the button 1 is pressed, turn it on
  if (digitalRead(button1) == LOW )
  {
    digitalWrite(led1, HIGH);
  } else
  {
    digitalWrite(led1, LOW);
  }

  // if the button 2 is pressed, turn it on
  if (digitalRead(button2) == LOW)
  {
    digitalWrite(led2, HIGH);
  } else
  {
    digitalWrite(led2, LOW);
  }
}

