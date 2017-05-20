/******************************************************************************
 * MicroOLED_Demo.ino
 * SFE_MicroOLED Library Demo
 * Jim Lindblom @ SparkFun Electronics
 * Original Creation Date: October 27, 2014
 *
 * This sketch uses the MicroOLED library to draw a 3-D projected
 * cube, and rotate it along all three axes.
 *
 * Development environment specifics:
 *  Arduino 1.0.5
 *  Arduino Pro 3.3V
 *  Micro OLED Breakout v1.0
 *
 * This code is beerware; if you see me (or any other SparkFun employee) at the
 * local, and you've found our code helpful, please buy us a round!
 *
 * Distributed as-is; no warranty is given.
 *
 *  >>>>  Modified to work with OpenHAK by Joel Murphy/Biomurph Summer 2017  <<<<
 *
 ******************************************************************************/
#include <Wire.h>  // Include Wire if you're using I2C
#include <OpenHAK_MicroOLED.h>  // Include the OpenHAK_MicroOLED library

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_RESET 4  // Connect RST to pin 9
#define DC_JUMPER 1  // DC Jumper connected to 3V sets the I2C address

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
MicroOLED oled(PIN_RESET, DC_JUMPER);    // reset pin, I2C address

void setup()
{
  Serial.begin(250000);
  Serial.println("microOLED test");
  delay(100);
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.clear(PAGE); // Clear the buffer.
  oled.setFontType(2);
  oled.setCursor(0,0);
  oled.print("09:30");
  oled.setCursor(0,24);
  oled.setFontType(0);
  oled.println("text from");
  oled.print("Joel");
  oled.display();
}


void loop()
{
