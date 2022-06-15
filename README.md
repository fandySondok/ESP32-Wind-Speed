# ESP32-Wind-Speed
## Purpose
Proyek ini dibuat untuk memantau kecepetan udara dalam dan luar ruangan menggunakan sensor windspeed VMS-3000-FSJT-NPN tipe rs485.

## Feature
- [x] Mendapatkan Data Kecepatan Angin Rerata
- [x] Mengirimkan Data via HTTP GET (thinkspeak)
- [x] Mengirimkan Data via MQTT (Mosquitto)
- [ ] Mengirimkan Pesan ke Telegram jika Pesan Angin Kencang

## Component
- ESP32 development board (DOIT ESP32 DEVKIT V1)
- Sensor Kecepatan Angin (VMS-3000-FSJT-NPN)
- rs485 to TTL
- Jumper
- breadboard

## Prerequisites
- Internet Connection
- Add [PlattformIO](https://platformio.org/install/ide?install=vscode) extension on VSCode.
- For http GET Method, create a channel in [thingspeak](https://www.mathworks.com/help/thingspeak/collect-data-in-a-new-channel.html) first.
- For MQTT Protocol, create a [mqtt broker](https://randomnerdtutorials.com/how-to-install-mosquitto-broker-on-raspberry-pi/) and topic first.

## Schematic

## Library
- [ESP SoftwareSerial.h](https://www.arduino.cc/reference/en/libraries/espsoftwareserial/).

## Version
Version 0.51.0
