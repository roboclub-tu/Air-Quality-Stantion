// SDS011 dust sensor
/*PM10 is any particulate matter in the air with a diameter of 10 micrometers or less,
including smoke, dust, soot, salts, acids, and metals.
PM2.5 are tiny particles in the air that reduce visibility and cause the air to appear hazy when levels are elevated.*/

#include <SDS011.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Wire.h>

//SDS011 things
float p10,p25;
int error;

SDS011 my_sds;

//BME280 things
#define I2C_SDA 33
#define I2C_SCL 25
#define RX 27
#define TX 22

#define SEALEVELPRESSURE_HPA (1013.25)

TwoWire I2CBME = TwoWire(0);
Adafruit_BME280 bme; // I2C

unsigned long delayTime;

void setup() {
  Serial.begin(9600);
  my_sds.begin(RX, TX);

  I2CBME.begin(I2C_SDA, I2C_SCL, (uint32_t)400000);

  bool status;
  status = bme.begin(0x76, &I2CBME);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  
  delayTime = 2000;
}

void loop() {
// printSDS011Values();
 error = my_sds.read(&p25,&p10); //Range: 0.0-999.9 μg /m3
  if (! error) {
    Serial.println("P2.5: "+String(p25)); 
    Serial.println("P10: "+String(p10));
  }

 printBME280Values();
  
  delay(delayTime);
}

void printSDS011Values(){
   error = my_sds.read(&p25,&p10); //Range: 0.0-999.9 μg /m3
  if (! error) {
    Serial.println("P2.5: "+String(p25)); 
    Serial.println("P10: "+String(p10));
  }
}

void printBME280Values() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");
  Serial.println();
}
