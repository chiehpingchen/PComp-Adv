#include <Bridge.h>                  // To pass information between two processors.
// The Bridge library simplifies communication between the ATmega32U4 and the AR9331.

#include <Process.h>                 // Linux processes

#include <FileIO.h>                  // base class for writing and reading to an SD card

#include <Adafruit_NeoPixel.h>
#define PIN 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(13, PIN, NEO_GRB + NEO_KHZ800);

const int shot3Pin = 3;
int shot3State = 0;
const int shot5Pin = 5;
int shot5State = 0;
const int shot6Pin = 6;
int shot6State = 0;
const int shot9Pin = 9;
int shot9State = 0;
const int shot10Pin = 10;
int shot10State = 0;
const int shot11Pin = 11;
int shot11State = 0;

Process picture;
String filename;
String path = "/mnt/sda1/";

unsigned long previousMillis = 0;    // previous timestamp

void setup() {

  pinMode(shot3Pin, INPUT);
  pinMode(shot5Pin, INPUT);
  pinMode(shot6Pin, INPUT);
  pinMode(shot9Pin, INPUT);
  pinMode(shot10Pin, INPUT);
  pinMode(shot11Pin, INPUT);

  Bridge.begin();
  FileSystem.begin();                 // Initializes the SD card and FileIO class
  Serial.begin(9600);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {

  shot3State = digitalRead(shot3Pin);
  shot5State = digitalRead(shot5Pin);
  shot6State = digitalRead(shot6Pin);
  shot9State = digitalRead(shot9Pin);
  shot10State = digitalRead(shot10Pin);
  shot11State = digitalRead(shot11Pin);

  unsigned long currentMillis = millis();

  if (shot3State == HIGH) {

    // Generate filename with timestamp
    filename = "";
    picture.runShellCommand("date +%s");
    while (picture.running());

    while (picture.available() > 0) {
      char c = picture.read();
      filename += c;
    }
    filename.trim();
    filename += "LIKE.png";

    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();

    // Take picture
    picture.runShellCommand("fswebcam " + path + filename + " -f 30 -q 100 -S 20 -r 640x480");

    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(30);

    while (picture.running());

    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(20);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(50);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(80);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(30);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(90);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();

    // Upload to Dropbox
    picture.runShellCommand("python " + path + "upload_picture.py " + path + filename);
    while (picture.running());

    previousMillis = currentMillis;

  }

  if (shot5State == HIGH) {

    // Generate filename with timestamp
    filename = "";
    picture.runShellCommand("date +%s");
    while (picture.running());

    while (picture.available() > 0) {
      char c = picture.read();
      filename += c;
    }
    filename.trim();
    filename += "LOVE.png";


    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();

    // Take picture
    picture.runShellCommand("fswebcam " + path + filename + " -f 30 -q 100 -S 20 -r 640x480");

    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(30);

    while (picture.running());

    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(20);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(50);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(80);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(30);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(90);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();

    // Upload to Dropbox
    picture.runShellCommand("python " + path + "upload_picture.py " + path + filename);
    while (picture.running());

    previousMillis = currentMillis;

  }

  if (shot6State == HIGH) {

    // Generate filename with timestamp
    filename = "";
    picture.runShellCommand("date +%s");
    while (picture.running());

    while (picture.available() > 0) {
      char c = picture.read();
      filename += c;
    }
    filename.trim();
    filename += "HAHA.png";


    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();

    // Take picture
    picture.runShellCommand("fswebcam " + path + filename + " -f 30 -q 100 -S 20 -r 640x480");

    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(30);

    while (picture.running());

    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(20);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(50);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(80);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(30);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(90);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();

    // Upload to Dropbox
    picture.runShellCommand("python " + path + "upload_picture.py " + path + filename);
    while (picture.running());

    previousMillis = currentMillis;

  }

  if (shot9State == HIGH) {

    // Generate filename with timestamp
    filename = "";
    picture.runShellCommand("date +%s");
    while (picture.running());

    while (picture.available() > 0) {
      char c = picture.read();
      filename += c;
    }
    filename.trim();
    filename += "WOW.png";


    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();

    // Take picture
    picture.runShellCommand("fswebcam " + path + filename + " -f 30 -q 100 -S 20 -r 640x480");

    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(30);

    while (picture.running());

    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(20);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(50);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(80);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(30);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(90);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();

    // Upload to Dropbox
    picture.runShellCommand("python " + path + "upload_picture.py " + path + filename);
    while (picture.running());

    previousMillis = currentMillis;

  }

  if (shot10State == HIGH) {

    // Generate filename with timestamp
    filename = "";
    picture.runShellCommand("date +%s");
    while (picture.running());

    while (picture.available() > 0) {
      char c = picture.read();
      filename += c;
    }
    filename.trim();
    filename += "SAD.png";


    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();

    // Take picture
    picture.runShellCommand("fswebcam " + path + filename + " -f 30 -q 100 -S 20 -r 640x480");

    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(30);

    while (picture.running());

    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(20);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(50);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(80);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(30);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(90);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();

    // Upload to Dropbox
    picture.runShellCommand("python " + path + "upload_picture.py " + path + filename);
    while (picture.running());

    previousMillis = currentMillis;

  }

  if (shot11State == HIGH) {

    // Generate filename with timestamp
    filename = "";
    picture.runShellCommand("date +%s");
    while (picture.running());

    while (picture.available() > 0) {
      char c = picture.read();
      filename += c;
    }
    filename.trim();
    filename += "ANGRY.png";


    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(500);
    strip.setPixelColor(6, 25, 0, 0); //6
    strip.show();

    // Take picture
    picture.runShellCommand("fswebcam " + path + filename + " -f 30 -q 100 -S 20 -r 640x480");

    strip.setPixelColor(6, 0, 0, 0); //6
    strip.show();
    delay(30);

    while (picture.running());

    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(20);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(50);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(80);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();
    delay(30);


    strip.setPixelColor(0, 255, 255, 255); //0
    strip.setPixelColor(1, 255, 255, 255); //1
    strip.setPixelColor(2, 255, 255, 255); //2
    strip.setPixelColor(3, 255, 255, 255); //3
    strip.setPixelColor(4, 255, 255, 255); //4
    strip.setPixelColor(5, 255, 255, 255); //5
    strip.setPixelColor(6, 255, 255, 255); //6
    strip.setPixelColor(7, 255, 255, 255); //7
    strip.setPixelColor(8, 255, 255, 255); //8
    strip.setPixelColor(9, 255, 255, 255); //9
    strip.setPixelColor(10, 255, 255, 255); //10
    strip.setPixelColor(11, 255, 255, 255); //11
    strip.setPixelColor(12, 255, 255, 255); //12

    strip.show();
    delay(90);

    strip.setPixelColor(0, 0, 0, 0); //0
    strip.setPixelColor(1, 0, 0, 0); //1
    strip.setPixelColor(2, 0, 0, 0); //2
    strip.setPixelColor(3, 0, 0, 0); //3
    strip.setPixelColor(4, 0, 0, 0); //4
    strip.setPixelColor(5, 0, 0, 0); //5
    strip.setPixelColor(6, 0, 0, 0); //6
    strip.setPixelColor(7, 0, 0, 0); //7
    strip.setPixelColor(8, 0, 0, 0); //8
    strip.setPixelColor(9, 0, 0, 0); //9
    strip.setPixelColor(10, 0, 0, 0); //10
    strip.setPixelColor(11, 0, 0, 0); //11
    strip.setPixelColor(12, 0, 0, 0); //12

    strip.show();

    // Upload to Dropbox
    picture.runShellCommand("python " + path + "upload_picture.py " + path + filename);
    while (picture.running());

    previousMillis = currentMillis;

  }

}




