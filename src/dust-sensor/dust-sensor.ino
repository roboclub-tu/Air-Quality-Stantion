// SDS011 dust sensor
/*PM10 is any particulate matter in the air with a diameter of 10 micrometers or less,
including smoke, dust, soot, salts, acids, and metals.
PM2.5 are tiny particles in the air that reduce visibility and cause the air to appear hazy when levels are elevated.*/

#include <SDS011.h>

float p10,p25;
int error;

SDS011 my_sds;

void setup() {
  my_sds.begin(27,22); //RX, TX
  Serial.begin(9600);
}

void loop() {
  error = my_sds.read(&p25,&p10); //Range: 0.0-999.9 μg /m3
  if (! error) {
    Serial.println("P2.5: "+String(p25)); 
    Serial.println("P10:  "+String(p10));
  }
  delay(100);
}
