#include <Adafruit_NeoPixel.h>

const int sensor = 23;    
const int ledPin =  32; 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(10, ledPin, NEO_GRB + NEO_KHZ800);
void setup() {
  Serial.begin(9600);
   pinMode(sensor, INPUT);
pinMode(ledPin, OUTPUT);
}

void loop() {
 int sensorState = digitalRead(sensor);

  Serial.println(sensorState);
  if (sensorState == HIGH) {
    // turn LED on:
     pixels.setPixelColor(1, pixels.Color(0,255,0));
     pixels.show(); 
  } else {
    // turn LED off:
    pixels.setPixelColor(1, pixels.Color(0,0,0));
    pixels.show(); 
  }

  delay(50);
}
