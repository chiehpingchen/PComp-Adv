const int ledPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    int val = Serial.parseInt();
    if (Serial.read() == '\n') {
      val = constrain(val, 0, 255);
      analogWrite(ledPin, val);
    }
        Serial.print("Enter Value (0-255): ");
    Serial.println(val);
  }
}

