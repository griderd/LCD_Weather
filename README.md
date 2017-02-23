# LCD_Weather
Arduino UNO project that displays the temperature and humidity on an onboard LCD display.

## License
This software is licensed under the [MIT License](https://github.com/griderd/LCD_Weather/blob/master/license.md).

## Hardware
This project utilizes the following parts:
* Integrated Circuits, Boards, Active Components
  * Arduino UNO R3 (or similar)
  * `LCD1`: 16x2 character LCD screen, 16-pin HD44780 interface.
* Electromechanical Components and Sensors
  * `S1`: Switch (I'm using an ON-ON SPDT)
  * `U1`: Potentiometer. (This is used as a variable voltage divider, so almost anything works. However, I'm using a single-turn 1/2 watt 1K ohm pot. It's available here: https://www.jameco.com/webapp/wcs/stores/servlet/ProductDisplay?langId=-1&storeId=10001&catalogId=10001&productId=2118803)
  * `RHT1`: DHT11 Digital Temperature and Humidity Sensor (I'm using a sensor module from a kit where the `RHT1` sensor, `R1` resistor, and associated wiring that's on `Breadboard2` is all attached to the sensor, similar to this: http://www.jameco.com/z/HUMI-01-OSEPP-DHT11-Humidity-and-Temperature-Sensor_2237116.html. If your sensor is an independent 4-pin sensor, the one on `Breadboard2` is set up the way you need.)
* Passive Components
  * `R1`: 5 ohm resistor. See `RHT1`.
  * `R2`: 10 ohm resistor.
  * `VCC1`: 9V battery and snap connector.
  
### Circuit Diagrams
![Breadboard view](https://github.com/griderd/LCD_Weather/blob/master/Temp%20and%20Humidity%20Monitor_bb.png)
![Schematic diagram](https://github.com/griderd/LCD_Weather/blob/master/Temp%20and%20Humidity%20Monitor_schem.png)
  
## Software
The software is fairly straightforward.

### Prerequisite Libraries
* [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal), included with Arduino, to run the LCD display.
* [SimpleDHT](https://github.com/winlinvip/SimpleDHT) to run the DHT sensor.

### The Code
The code is broken into four sections.
* **Intro Comments** describe the purpose of the code and lists the pin arrangement.
* **Globals** contains the global variables and objects used by the code.
* **Arduino Code** contains the `setup()` and `loop()` functions that Arduino uses to run.
* **Helper Functions** contains helper functions that are called by the `setup()` and `loop()` functions.
