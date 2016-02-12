int pushButton = 2;                         // push button only talk to the Arduino 
int motorControl = 11;                      // the transistor base pin is controlled by the PWM pin
int buttonState = LOW; 
int x = 0;                                  // using x to mapping the increating/decreating speed to motor
int y = millis();                           // the y is like a Timer


void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(motorControl, OUTPUT);
}

void loop() {

  buttonState = digitalRead(pushButton);

  if ( buttonState == HIGH) {                 // press button to talk to the controller to start
    y = 0;
    for (y = 0; y < 2000; y += 6.5) {
      x = map(y, 0, 1999, 0, 255);            // mapping increating speed from 0% to 100% in 2 sec
      analogWrite(motorControl, x);
      Serial.println(y);
      //      Serial.println(" //////// ");
      //      Serial.println(x);
      //      Serial.println(" /255");
    }
    for (y = 2000; y < 4000; y += 6.5) {
      x = 255;                                // keep the full speed in 2 sec
      analogWrite(motorControl, x);
      Serial.println(y);
      //      Serial.println(" //////// ");
      //      Serial.println(x);
      //      Serial.println(" /255");

    }
    for (y = 4000; y < 6000; y += 6.5) {
      x = map(y, 4000, 5999, 255, 0);         // mapping decreating speed from 100% to 0% in 2 sec
      analogWrite(motorControl, x);
      Serial.println(y);
      //      Serial.println(" //////// ");
      //      Serial.println(x);
      //      Serial.println(" /255");

      buttonState = LOW;
      if (y >= 6000) {
        x = 0;
        analogWrite(motorControl, x);         // turn off the motor
      }
    }
  }
  Serial.println(y);
  //  Serial.println(" //////// ");
  //  Serial.println(x);
  //  Serial.println(" /255");


  delay(1);        // delay in between reads for stability
}


