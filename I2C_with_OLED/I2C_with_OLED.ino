/*****************************************************************************
******************************************************************************
******************************************************************************

  Address of I2C device
    LM75 address is 0x48
    OLED address is 0x3C
    RGB detection address is 0x29

  Member of Group 9
    Sapsathit Yangwaeng 643040297-7
    Aukkapol Detchaisri 643040310-1
    Jirapat Srisila     643040289-6

*****************************************************************************
*****************************************************************************
****************************************************************************/

#include <Wire.h>  //Libaries for I2C Interface

//Libaries for OLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Libaries for RGB detector
#include "Adafruit_TCS34725.h"

//Libarie for Temp
#include <inttypes.h>
#include <lm75.h>

#define OLED_WIDTH 128
#define OLED_HEIGHT 32
#define OLED_ADDRESS 0x3C
#define LM75_ADDRESS 0x48

String color;

//Initial setting for I2C Interface
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_ADDRESS);
TempI2C_LM75 termo = TempI2C_LM75(LM75_ADDRESS, TempI2C_LM75::nine_bits);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);


void setup() {

  tcs.begin();

  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {

  tcs.setInterrupt(false);
  delay(60);

  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);

  tcs.setInterrupt(true);

  int lux = (r * 0.136 + g * 1.000 + b * 0.052) / 4 ;

  if (r > g && r > b && lux > 20)
    color = "Color is Red";

  else if (g > r && g > b && lux > 20)
    color = "Color is Green";

  else if (b > r && b > g && lux > 20)
    color = "Color is Blue";

  else
    color = "What is color?";

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("ESE-09 Color sensor");
  display.println("Temperature " + String(termo.getTemp()));  
  display.println(color);
  display.println("We are brekdown.");
  Serial.println("ESE-09 Color sensor");
  Serial.println("Temperature " + String(termo.getTemp()));  
  Serial.println(color);
  Serial.println("We are brekdown.");
  display.display();
  delay(2000);
}