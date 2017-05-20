/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x32 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution

Modified by Joel Murphy/Biomurph for OpenHAK Fitness Tracker Summer, 2017
*********************************************************************/


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <OpenHAK_SSD1306.h>

#define OLED_RESET 4
OpenHAK_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2



#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix OpenHAK_SSD1306.h!");
#endif

void setup()   {
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

 
  // text display tests
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("08:45");
  display.setTextSize(1);
  display.print("text from Joel");
  display.setCursor(96,0);
  display.print("STEPS");
  display.setCursor(96,8);
  display.println("740\n ");
  display.setCursor(96,16);
  display.println("BPM");
  display.setCursor(96,24);
  display.print("72");
  display.display();
  delay(2000);
  display.clearDisplay();

  
}


void loop() {

}



