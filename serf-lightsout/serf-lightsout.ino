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
boolean Lights[] = {true, false, false, true, false};

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  strip.begin();
  strip.setBrightness(50);
  strip.show(); 
  Serial.println("setup");
}

void receiveEvent(int howMany) {
  myWord = "";
  while (0 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    myWord = myWord + c;
  }
  Serial.println("hello");
  Serial.println(myWord);
}

void loop(int numButton) {
  if (myWord == "random") {
  strip.setPixelColor(0, 255, 255, 255);
  strip.setPixelColor(1, 0, 0, 255);
  strip.setPixelColor(2, 0, 0, 255);
  strip.setPixelColor(3, 255, 255, 255);
  strip.setPixelColor(4, 0, 0, 255);
}
if (Lights[numButton]) {
    Lights[numButton] == false;
  }
  else {
    Lights[numButton] == true;
  }
  if (Lights[numButton-1]) {
    Lights[numButton-1] == false;
  }
  else {
    Lights[numButton-1] == true;
  }
  if (Lights[numButton+1]) {
    Lights[numButton+1] == false;
  }
  else {
    Lights[numButton+1] == true;
  }
  if (numButton == 0) {
    if (Lights[numButton]) {
      Lights[numButton] == false;
    }
    else {
      Lights[numButton] == true;
    }
    if (Lights[numButton+1]) {
      Lights[numButton+1] == false;
    }
    else {
      Lights[numButton+1] == true;
    }
  }
  if (numButton == 4) {
    if (Lights[numButton]) {
      Lights[numButton] == false;
    }
    else {
      Lights[numButton] == true;
    }
    if (Lights[numButton-1]) {
      Lights[numButton-1] == false;
    }
    else {
    Lights[numButton-1] == true;
    }
  }
}
    
