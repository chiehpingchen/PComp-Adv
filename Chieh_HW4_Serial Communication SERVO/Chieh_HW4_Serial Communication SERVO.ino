#include <Servo.h>
Servo servo1;

void setup() {
  Serial.begin(9600);
  pinMode(1, OUTPUT);
  servo1.attach(14); //analog pin 0
}

void loop() {
  static int v = 0;

  if ( Serial.available()) {
    char ch = Serial.read();

    switch (ch) {
      case '0'...'9':
        v = v * 10 + ch - '0'; //set degrees
        break;

      case 's': //adding 's' to enter the value
        servo1.write(v);
        v = 0;
        break;
    }

    Serial.print("Enter Angle (ex:180s): ");
    Serial.println(v);
  }
}
