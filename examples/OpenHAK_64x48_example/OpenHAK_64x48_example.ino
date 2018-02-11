/******************************************************************************
 * OpenHAK_64x48_example.ino
 *
 * Made by Joel Murphy for OpenHAK, Spring 2017
 * Targets the Simblee radio module on the OpenHAK fitness tracker.
 *
 * This code is beerware; if you see me (or any other OpehHAK contributor) at the
 * local, and you've found our code helpful, please buy us a round!
 *
 * Distributed as-is; no warranty is given.
 *
 *
 ******************************************************************************/
#include <Wire.h>  // Include Wire 'cause we're using I2C
#include <OpenHAK_MicroOLED.h>  // Include the OpenHAK_MicroOLED library


#define PIN_RESET 4  // Connect RST to pin 9
#define DC_JUMPER 1  // DC Jumper connected to 3V sets the I2C address

MicroOLED oled(PIN_RESET, DC_JUMPER);    // reset pin, I2C address

void setup()
{
  Serial.begin(250000);
  Serial.println("OpenHAK microOLED example");
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
  oled.flipVertical(true);
  oled.flipHorizontal(true);
  oled.display();
}


void loop()
{

}
