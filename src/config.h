#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>

/** ESP32 pin configuration */
#define transmissionPin 33 // DE & RE
#define rx 16
#define tx 17

/** ESP32 WiFi Setup */
const char *ssid = "REPLACE_WITH_YOUR_SSID";
const char *password = "REPLACE_WITH_YOUR_PASSWORD";

/** ESP32 Data Send Protocols */
#define http_get
// #define mqtt

/** ESP32 Data Send Config */
#ifdef http_get
const char *server_addr = "https://api.thingspeak.com";
const char *server_endpoint = "/update?api_key=";
const char *api_key = "REPLACE_WITH_YOUR_APIKEY";
const int ts_field = 1; // REPLACE_WITH_YOUR_FIELD_NUMBER (default 1)
#else
#endif

/** Wind Speed Sensor Configuration */
const byte ModReadBuffer[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};
const int iteration_aveg = 60;
#define baudWindSensor 4800

#endif