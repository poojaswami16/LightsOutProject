#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  saySomething("blue");
  saySomething("white");
  saySomething("random");
  
}


void saySomething(char message[]){
  Wire.beginTransmission(1); // transmit to device #8
  Wire.write(message);        // sends five bytes
  Wire.endTransmission();    // stop transmitting
  delay(500);
}
