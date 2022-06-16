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
- Sensor Kecepatan Angin (VMS-3000-FSJT-NPN)
- rs485 to TTL
- Jumper
- breadboard

## Prerequisites
- Internet Connection.
- Add [PlattformIO](https://platformio.org/install/ide?install=vscode) extension on VSCode.
- For http GET Method, create a channel in [thingspeak](https://www.mathworks.com/help/thingspeak/collect-data-in-a-new-channel.html) first.
- For MQTT Protocol, create a [mqtt broker](https://randomnerdtutorials.com/how-to-install-mosquitto-broker-on-raspberry-pi/) and topic first.

## Schematic

## Library
- [ESP SoftwareSerial.h](https://www.arduino.cc/reference/en/libraries/espsoftwareserial/)

## Version
Version 0.51.0
