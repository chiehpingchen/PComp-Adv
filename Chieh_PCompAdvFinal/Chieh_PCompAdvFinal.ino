#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


#define PINspr A1
#define PINsum A2
#define PINfal A4
#define PINwin A5

const int motor1Pin = 6;
const int motor2Pin = 7;
const int motor3Pin = 8;
const int motor4Pin = 9;
const int motor5Pin = 10;
const int motor6Pin = 11;

Adafruit_NeoPixel stripSpr = Adafruit_NeoPixel(5, PINspr, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripSum = Adafruit_NeoPixel(5, PINsum, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripFal = Adafruit_NeoPixel(5, PINfal, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripWin = Adafruit_NeoPixel(5, PINwin, NEO_GRB + NEO_KHZ800);

void setup() {

#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  Serial.begin(9600);

  stripSpr.begin();
  stripSpr.show(); // Initialize all pixels to 'off'

  stripSum.begin();
  stripSum.show();

  stripFal.begin();
  stripFal.show();

  stripWin.begin();
  stripWin.show();

  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);
  pinMode(motor5Pin, OUTPUT);
  pinMode(motor6Pin, OUTPUT);
}

void loop() {

  rainbowSpr(1);
  rainbowSum(1);
  rainbowFal(1);
  rainbowWin(1);


}

void rainbowSpr(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 1; j++) { // 1 cycles for LED strip
    digitalWrite(motor1Pin, LOW);
    delay(25);
    digitalWrite(motor1Pin, HIGH);
    delay(8);
    digitalWrite(motor1Pin, LOW);
    delay(30);
    
    digitalWrite(motor2Pin, LOW);
    delay(30);
    digitalWrite(motor2Pin, HIGH);
    delay(8);
    digitalWrite(motor2Pin, LOW);
    delay(28);
    
    digitalWrite(motor3Pin, LOW);
    delay(28);
    digitalWrite(motor3Pin, HIGH);
    delay(8);
    digitalWrite(motor3Pin, LOW);
    delay(25);

    for (i = 0; i < stripSpr.numPixels(); i++) {
      stripSpr.setPixelColor(i, Wheel(((i * 256 / stripSpr.numPixels()) + j) & 255), 0, Wheel(((i * 256 / stripSpr.numPixels()) + j) & 255));

    }
    stripSpr.show();
    delay(wait);
  }
}

void rainbowSum(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 1; j++) { // 1 cycles for LED strip
    digitalWrite(motor1Pin, HIGH);
    delay(8);
    digitalWrite(motor1Pin, LOW);
    delay(2);
    
    digitalWrite(motor2Pin, LOW);
    delay(2);
    digitalWrite(motor2Pin, HIGH);
    delay(8);
    digitalWrite(motor2Pin, LOW);
    delay(3);
    
    digitalWrite(motor3Pin, LOW);
    delay(3);
    digitalWrite(motor3Pin, HIGH);
    delay(8);
    digitalWrite(motor3Pin, LOW);
    delay(4);
    
    digitalWrite(motor4Pin, LOW);
    delay(4);
    digitalWrite(motor4Pin, HIGH);
    delay(8);
    digitalWrite(motor4Pin, LOW);
    delay(5);
    
    digitalWrite(motor5Pin, HIGH);
    delay(8);
    digitalWrite(motor5Pin, LOW);
    delay(6);
    
    digitalWrite(motor6Pin, HIGH);
    delay(8);
    digitalWrite(motor6Pin, LOW);
    delay(8);

    for (i = 0; i < stripSum.numPixels(); i++) {
      stripSum.setPixelColor(i, 0, Wheel(((i * 256 / stripSum.numPixels()) + j) & 255), 0);

    }
    stripSum.show();
    delay(wait);
  }
}

void rainbowFal(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 1; j++) { // 1 cycles for LED strip
    digitalWrite(motor1Pin, HIGH);
    delay(12);
    digitalWrite(motor1Pin, LOW);
    delay(20);
    
    digitalWrite(motor2Pin, HIGH);
    delay(12);
    digitalWrite(motor2Pin, LOW);
    delay(25);
    
    digitalWrite(motor3Pin, HIGH);
    delay(12);
    digitalWrite(motor3Pin, LOW);
    delay(23);
    
    digitalWrite(motor4Pin, HIGH);
    delay(12);
    digitalWrite(motor4Pin, LOW);
    delay(24);
    
    digitalWrite(motor5Pin, HIGH);
    delay(12);
    digitalWrite(motor5Pin, LOW);
    delay(18);
    
    digitalWrite(motor6Pin, HIGH);
    delay(12);
    digitalWrite(motor6Pin, LOW);
    delay(22);

    for (i = 0; i < stripFal.numPixels(); i++) {
      stripFal.setPixelColor(i, Wheel(((i * 256 / stripFal.numPixels()) + j) & 255), Wheel(((i * 256 / stripFal.numPixels()) + j) & 255), 0);
    }

    stripFal.show();
    delay(wait);
  }
}

void rainbowWin(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 1; j++) { // 1 cycles for LED strip
    digitalWrite(motor1Pin, HIGH);
    delay(5);
    digitalWrite(motor1Pin, LOW);
    delay(800);

    digitalWrite(motor3Pin, LOW);
    delay(25);
    digitalWrite(motor3Pin, HIGH);
    delay(5);
    digitalWrite(motor3Pin, LOW);
    delay(460);
  
    digitalWrite(motor5Pin, LOW);
    delay(24);
    digitalWrite(motor5Pin, HIGH);
    delay(5);
    digitalWrite(motor5Pin, LOW);
    delay(360);
  
    for (i = 0; i < stripWin.numPixels(); i++) {
      stripWin.setPixelColor(i, 0, 0, Wheel(((i * 256 / stripWin.numPixels()) + j) & 255));
    }

    stripWin.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 150) {
    return stripSpr.Color(8, 3, 3);
    return stripSum.Color(3, 8, 3);
    return stripFal.Color(5, 5, 0);
    return stripWin.Color(3, 3, 8);
  }

}


