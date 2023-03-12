#include <Wire.h>
#include "Adafruit_TCS34725.h"

#include <inttypes.h>
#include <lm75.h>

TempI2C_LM75 termo = TempI2C_LM75(0x48, TempI2C_LM75::nine_bits);

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Initializing TCS34725...");

  if (tcs.begin()) {
    Serial.println("I2C found!");
  } else {
    Serial.println("Could not find I2C sensor, check wiring!");
    while (1)
      ;
  }
}

void loop() {
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);

  Serial.print("Temperature = ");
  Serial.println(termo.getTemp());
  Serial.print("Red: ");
  Serial.print(r);
  Serial.print(" Green: ");
  Serial.print(g);
  Serial.print(" Blue: ");
  Serial.print(b);
  Serial.print(" Clear: ");
  Serial.println(c);
  
  delay(1000);
}
