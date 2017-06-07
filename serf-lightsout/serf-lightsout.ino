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

void loop() {
  if (myWord == "random") {
  strip.setPixelColor(0, 255, 255, 255);
  strip.setPixelColor(1, 0, 0, 255);
  strip.setPixelColor(2, 0, 0, 255);
  strip.setPixelColor(3, 255, 255, 255);
  strip.setPixelColor(4, 0, 0, 255);
}

int numButton = myWord.toInt(); 
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
    
