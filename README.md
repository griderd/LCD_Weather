# LCD_Weather
Arduino UNO project that displays the temperature and humidity on an onboard LCD display.

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
  
## Circuit Diagrams

  
## Software

