/******************************************************************************
  MicroOLED_Hello.ino
  OpenHAK_MicroOLED Hello World Demo
  *
  * Originally made by
  *
  Jim Lindblom @ SparkFun Electronics
  Original Creation Date: October 26, 2014

  This sketch lights up a familiar pattern on the MicroOLED
  Breakout. It's a great way to prove you've connected everything
  correctly and that your display is in working order.

  Note: The display on the MicroOLED is a 1.8V-3.3V device only.
  Don't try to connect a 5V Arduino directly to it! Use level
  shifters in between the data signals if you have to resort to
  a 5V board.

  This code is beerware; if you see me (or any other SparkFun
  employee) at the local, and you've found our code helpful,
  please buy us a round!

  Distributed as-is; no warranty is given.
  *
  *  >>>>  Modified to work with OpenHAK by Joel Murphy/Biomurph Summer 2017  <<<<
  *
*******************************************************************************/
#include <Wire.h>  // Include Wire if you're using I2C
#include <OpenHAK_MicroOLED.h>  // Include the OpenHAK_MicroOLED library

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_RESET 4  // Connect RST to pin 9 (req. for SPI and I2C)
#define DC_JUMPER 1
// Also connect pin 13 to SCK and pin 11 to MOSI

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////

MicroOLED oled(PIN_RESET, DC_JUMPER); // Example I2C declaration


void setup()
{
  // These three lines of code are all you need to initialize the
  // OLED and print the splash screen.

  // Before you can start using the OLED, call begin() to init
  // all of the pins and configure the OLED.
  oled.begin();
  // clear(ALL) will clear out the OLED's graphic memory.
  // clear(PAGE) will clear the Arduino's display buffer.
  oled.clear(ALL);  // Clear the display's memory (gets rid of artifacts)
  // To actually draw anything on the display, you must call the
  // display() function.
  oled.display();
}

void loop()
{
}
