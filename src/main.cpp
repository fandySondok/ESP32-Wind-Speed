#include <Arduino.h>
#include "config.h"
#include "sensor.h"

void setup()
{
  Serial.begin(115200);
  void sensor_setup();
}

void loop()
{
  get_wind_data();
  delay(1000);
}
