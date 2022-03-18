#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Wire.h>

#define I2C_SDA 33
#define I2C_SCL 25

#define SEALEVELPRESSURE_HPA (1013.25)

TwoWire I2CBME = TwoWire(0);
Adafruit_BME280 bme; // I2C

unsigned long delayTime;

void setup() {
  Serial.begin(9600);
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
  printValues();
  delay(delayTime);
}

void printValues() {
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
