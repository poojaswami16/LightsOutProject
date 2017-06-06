// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

#include <Adafruit_NeoPixel.h>
#include <Wire.h>

int pin = 8;
String myWord;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, pin, NEO_GRB + NEO_KHZ800);

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  strip.begin();
  strip.setBrightness(50);
  strip.show(); 
  Serial.println("setup");
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  myWord = "";
  while (0 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    myWord = myWord + c;
  }
  Serial.println("hello");
  Serial.println(myWord);

if (myWord == "random") {
  strip.setPixelColor(0, 255, 255, 255);
  strip.setPixelColor(1, 0, 0, 255);
  strip.setPixelColor(2, 0, 0, 255);
  strip.setPixelColor(3, 255, 255, 255);
  strip.setPixelColor(4, 0, 0, 255);
}
}

void turnOn(int numButton) {
  if (myWord == "blue") {
    strip.setPixelColor(numButton, 0, 0, 255);
    if (numButton ==0) {
    strip.setPixelColor(numButton, 0, 0, 255);
    strip.setPixelColor(numButton+1,0, 0, 255);
  }
    if (numButton == 4) {
      strip.setPixelColor(numButton-1,0, 0, 255);
      strip.setPixelColor(numButton, 0, 0, 255);
    }
  }
}

void turnOff(int numButton) {
  if (myWord == "white") {
    strip.setPixelColor(numButton, 255, 255, 255);
    if(numButton == 0) {
      strip.setPixelColor(numButton, 255, 255, 255);
      strip.setPixelColor(numButton+1, 255, 255, 255);
    }
    if (numButton == 4) {
      strip.setPixelColor(numButton-1, 255, 255, 255);
      strip.setPixelColor(numButton, 255, 255, 255);
    }
  }
}

void flip() {
  turnOn;
  turnOff;
}
