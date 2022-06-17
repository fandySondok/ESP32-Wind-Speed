#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>

/** ESP32 pin configuration */
#define transmissionPin 33 // DE & RE
#define rx 16
#define tx 17

/** Wind Speed Sensor Configuration */
const byte ModReadBuffer[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};
const int iteration_aveg = 60;
#define baudWindSensor 4800

#endif