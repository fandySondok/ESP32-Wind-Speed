#ifndef SENSOR_H
#define SENSOR_H
#include <Arduino.h>
#include "config.h"
void sensor_setup();
float average_wind();
float get_wind_data();

#endif