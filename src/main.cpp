#include <Arduino.h>
#include "config.h"
#include "sensor.h"
#include "iot_connection.h"

unsigned long previous_millis = 0;
long _interval = 60 * 1000 * interval;

void setup()
{
  Serial.begin(115200);
  sensor_setup();
  connection_setup();
}

void loop()
{
  if ((unsigned long)(millis() - previous_millis) >= _interval)
  {
    previous_millis = millis();
    if (wifi_status())
    {
      wifi_setup();
    }
    float wind_data = average_wind();
    send_data(String(wind_data));
  }
#ifdef mqtt
  client_loop();
#endif
}
