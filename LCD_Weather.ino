/* LCD_Weather */
/* Displays temperature and humidity on an onboard LCD screen. */

/* Circuit:

This circuit requires an Arduino Uno R3 or similar, a DHT11, and a 16x2
LCD display (16-pin) that's compatible with the Hitachi HD44780 driver.

This assumes that you are using the circuit whose diagram is available on 
[URL HERE]. If you're building your own circuit, these are the Arduino pins that
are used:

* DHT Signal to D2
* D7 to LCD RS
* D8 to LCD E
* D9 to LCD D4
* D10 to LCD D5
* D11 to LCD D6
* D12 to LCD D7
* LCD RW to V0
*/

/* LICENSE */
/*
MIT License

Copyright (c) [year] [fullname]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <LiquidCrystal.h>
#include <SimpleDHT.h>

#define DATA_COUNT 10
#define PIN_DHT11 2

/******************************************************************************/
/* Globals */
/******************************************************************************/
// Initialize the LCD with the pins in use
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

SimpleDHT11 dht11;

/* These values are for storing a running average of the data over a ten-second
period. This is to help ensure that the data doesn't fluctuate too much. */

int dataIndex = 0;
int allDataCollected = 0;

byte humidityData[DATA_COUNT];
float tempData[DATA_COUNT];

/******************************************************************************/
/* Arduino Code */
/******************************************************************************/

void setup()
{
	// Start the LCD screen with 2 rows, 16 columns
	lcd.begin(16, 2);
	
	clearLCD();
}

void loop()
{
	byte temperature = 0;
	float tempF = 0;
	byte humidity = 0;
	byte data[40] = {0};
	
	float tempAvg;
	byte humidityAvg;
	
	if (dht11.read(PIN_DHT11, &temperature, &humidity, data))
		return;
	
	tempF = ((float)temperature * 1.8) + 32;
	setData(humidity, tempF);
	
	if (allDataCollected)
	{
		getData(humidity, tempF, &humidityAvg, &tempAvg);
		
		lcd.clear();
		lcd.print("Temp: ");
		lcd.print(tempAvg);
		lcd.print(" F");
		
		lcd.setCursor(0, 1);
		lcd.print("Humidity: ");
		lcd.print(humidityAvg);
		lcd.print("%");
	}
	else
	{
		lcd.setCursor(dataIndex - 1, 1);
		lcd.print(".");
	}
	
	// The sampling rate of DHT11 is 1 HZ.
	delay(1000);
}

/******************************************************************************/
/* Helper functions */
/******************************************************************************/

void clearLCD()
{
  lcd.setCursor(0, 0);
  lcd.print("BOOTING");
  lcd.setCursor(0, 1);
  lcd.print("                "); 
}

/* Gets the current data average */
void getData(byte humidity, float temp, byte* humidityAvg, float* tempAvg)
{
	humidityData[dataIndex] = humidity;
	tempData[dataIndex] = temp;
	
	int humidityTotal = 0;
	float tempTotal = 0;
	
	for (int i = 0; i < DATA_COUNT; i++)
	{
		humidityTotal = humidityTotal + humidityData[i];
		tempTotal = tempTotal + tempData[i];
	}
	
	*humidityAvg = humidityTotal / DATA_COUNT;
	*tempAvg = tempTotal / DATA_COUNT;
}

/* Sets the appropriate data number */
void setData(byte humidity, float temp)
{
	humidityData[dataIndex] = humidity;
	tempData[dataIndex] = temp;
	
	dataIndex++;
	if (dataIndex == DATA_COUNT)
	{
		dataIndex = 0;
		allDataCollected = 1;
	}
}
