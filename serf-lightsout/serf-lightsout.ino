#include <Adafruit_NeoPixel.h>
#include <Wire.h>

int pin = 8;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, pin, NEO_GRB + NEO_KHZ800); 
boolean Lights[] = {true, false, false, true, false};

void setup() {
 // Wire.begin(8);                // join i2c bus with address #8
  //Wire.onReceive(receiveEvent); // register event
  //Serial.begin(9600);           // start serial for output
  strip.begin();
  strip.setBrightness(50);
  strip.setPixelColor(0, 255, 255, 255);
  strip.setPixelColor(1, 0, 0, 255);
  strip.setPixelColor(2, 0, 0, 255);
  strip.setPixelColor(3, 255, 255, 255);
  strip.setPixelColor(4, 0, 0, 255);
  strip.show(); 
 
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
 // Serial.println("setup");

  
}


void loop() {
  int numButton;


if(digitalRead(2))
{
  numButton = 0;
}
if(digitalRead(3))
{
  numButton = 1;
}
if(digitalRead(4))
{
  numButton = 2;
}
if(digitalRead(5))
{
  numButton = 3;
}
if(digitalRead(6))
{
  numButton = 4;
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

  if(Lights[0])
    {
       strip.setPixelColor(0, 255, 255, 255);strip.show();
    }
  else
  {
     strip.setPixelColor(0, 0, 0, 255);strip.show();
  }

  
  if(Lights[1])
    {
       strip.setPixelColor(1, 255, 255, 255);strip.show();
    }
  else
  {
     strip.setPixelColor(1, 0, 0, 255);strip.show();
  }

  
    if(Lights[2])
    {
       strip.setPixelColor(2, 255, 255, 255);strip.show();
    }
  else
  {
     strip.setPixelColor(2, 0, 0, 255);strip.show();
  }

  
    if(Lights[3])
    {
       strip.setPixelColor(3, 255, 255, 255);strip.show();
    }
  else
  {
     strip.setPixelColor(3, 0, 0, 255);strip.show();
  }

  
    if(Lights[4])
    {
       strip.setPixelColor(4, 255, 255, 255);strip.show();
    }
  else
  {
     strip.setPixelColor(4, 0, 0, 255);strip.show();
  }  
  
}
    
