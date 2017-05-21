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


