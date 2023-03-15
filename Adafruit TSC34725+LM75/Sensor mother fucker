#include <Wire.h>
#include "Adafruit_TCS34725.h"

// Initialize TCS34725 sensor
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  tcs.begin();
}

void loop() {
  uint16_t r, g, b, c;
  float R, G, B;

  // Read color values from TCS34725 sensor
  tcs.getRawData(&r, &g, &b, &c);

  // Convert raw RGB values to real RGB color code
  R = (r * 255.0) / c;
  G = (g * 255.0) / c;
  B = (b * 255.0) / c;

  // Print real RGB color code to Serial Monitor
  Serial.print("Red: ");
  Serial.print(R, 0);
  Serial.print(" Green: ");
  Serial.print(G, 0);
  Serial.print(" Blue: ");
  Serial.print(B, 0);
  Serial.println();

  delay(500);
}
