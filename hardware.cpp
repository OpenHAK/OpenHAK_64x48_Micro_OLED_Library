/******************************************************************************
hardware.cpp
MicroOLED Arduino Library Hardware Interface

Jim Lindblom @ SparkFun Electronics
October 26, 2014
https://github.com/sparkfun/Micro_OLED_Breakout/tree/master/Firmware/Arduino/libraries/SFE_MicroOLED

Modified by:
Emil Varughese @ Edwin Robotics Pvt. Ltd.
July 27, 2015
https://github.com/emil01/SparkFun_Micro_OLED_Arduino_Library/

*
*  >>>>  Modified to work with OpenHAK by Joel Murphy/Biomurph Summer 2017  <<<<
*	 >>>>  https://github.com/OpenHAK/OpenHAK_64x48_Micro_OLED_Library  <<<<
*

This file defines the hardware interface(s) for the Micro OLED Breakout. Those
interfaces include SPI, I2C and a parallel bus.

Development environment specifics:
Arduino 1.0.5
Arduino Pro 3.3V
Micro OLED Breakout v1.0

This code was heavily based around the MicroView library, written by GeekAmmo
(https://github.com/geekammo/MicroView-Arduino-Library), and released under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include "OpenHAK_MicroOLED.h"
#include <Wire.h>

#define I2C_FREQ 400000L	// I2C Frequency is 400kHz (fast as possible)


void MicroOLED::i2cSetup()
{
	// Initialize Wire library (I2C)
	// Using Wire2, because Wire is already being used by OpenHAK
	Wire2.beginOnPins(SCL_PIN, SDA_PIN);
}

/** \brief  Write a byte over I2C

	Write a byte to I2C device _address_. The DC byte determines whether
	the data being sent is a command or display data. Use either I2C_COMMAND
	or I2C_DATA in that parameter. The data byte can be any 8-bit value.
**/
void MicroOLED::i2cWrite(byte address, byte dc, byte data)
{
	Wire2.beginTransmission(address);
	Wire2.write(dc); // If data dc = 0, if command dc = 0x40
	Wire2.write(data);
	Wire2.endTransmission();
}
