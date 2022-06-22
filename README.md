# ESP32-Wind-Speed

## Purpose

This project was created to monitor indoor and outdoor wind speed using the VMS-3000-FSJT-NPN type rs485 windspeed sensor.

## Feature

- [x] Getting Average Wind Speed Data
- [x] Sending Data via HTTP GET (thinkspeak)
- [x] Sending Data via MQTT (Mosquitto)
- [ ] Sending message to telegram if there is wind speed in the high level

## Component

- ESP32 development board (DOIT ESP32 DEVKIT V1)
- Wind Speed Sensor (VMS-3000-FSJT-NPN)
- rs485 to TTL
- Jumper
- breadboard
- Power Supply 12 VDC
- Step Down 12 to 5 VDC (Optional)

## Prerequisites

- Internet Connection.
- Add [PlattformIO](https://platformio.org/install/ide?install=vscode) extension on VSCode.
- For http GET Method, create a channel in [thingspeak](https://www.mathworks.com/help/thingspeak/collect-data-in-a-new-channel.html) first.
- For MQTT Protocol, create a [mqtt broker](https://randomnerdtutorials.com/how-to-install-mosquitto-broker-on-raspberry-pi/) and topic first.

## Schematic

![Schematic](https://github.com/fandySondok/ESP32-Wind-Speed/blob/master/schematic-esp32-windspeed)

## Library

- [ESP SoftwareSerial](https://www.arduino.cc/reference/en/libraries/espsoftwareserial/)

## Datasheet

- [VMS-3000-FSJT-NPN](https://media.digikey.com/pdf/Data%20Sheets/Seeed%20Technology/Wind_Speed_Transmitter_485Type_V1.0_UG.pdf)

## Version

Version 1.0.1
