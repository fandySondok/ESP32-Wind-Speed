#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>

/** ESP32 pin configuration */
#define transmissionPin 33 // DE & RE for transmission control
#define rx 16
#define tx 17

/** ESP32 WiFi Setup */
static const char *ssid = "ssid";         // REPLACE_WITH_YOUR_SSID
static const char *password = "password"; // REPLACE_WITH_YOUR_PASSWORD

/** ESP32 Data Send Protocols (select one) */
#define http_get
// #define mqtt

/** ESP32 Data Send Config */
#ifdef http_get
static const char *server_addr = "https://api.thingspeak.com";
static const char *server_endpoint = "/update?api_key=";
static const char *api_key = "REPLACE_WITH_YOUR_APIKEY";
static const int ts_field = 1; // REPLACE_WITH_YOUR_FIELD_NUMBER (default 1)
#elif defined(mqtt)
static const char *mqtt_server_addr = "192.168.1.100"; // REPLACE_WITH_YOUR_MQTT_BROKER_ADDRES
static const uint16_t mqtt_port = 1883;                // REPLACE_WITH_YOUR_MQTT_BROKER_PORT
static const char *pub_topic = "esp32/windspeed";
#endif

/** Wind Speed Sensor Configuration */
const byte ModReadBuffer[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A}; // sensor address to get data wind speed
const int iteration_aveg = 60;                                                 // how much data wind speed calculated
#define baudWindSensor 4800                                                    // baudrate default wind speed sensor

/** Interval get and send data to the server */
const int interval = 1; // (1 minute)

#endif