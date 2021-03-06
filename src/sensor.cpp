#include "sensor.h"
#include <SoftwareSerial.h>
SoftwareSerial mod(rx, tx); // RX=26 , TX =27

byte BufferValue[8];

/** Convert hex data to integer data */
static int hex_to_int(int hexa)
{
  String hxstr = String(hexa, DEC);
  int nUm = hxstr.toInt();
  return nUm;
}

/** Get wind speed data from sensor */
float get_wind_data()
{
  int byte1, byte2;
  byte i;
  float windspeed = 0;
  digitalWrite(transmissionPin, HIGH);
  delay(10);
  if (mod.write(ModReadBuffer, sizeof(ModReadBuffer)) == 8)
  {
    digitalWrite(transmissionPin, LOW);
    for (i = 0; i < 7; i++)
    {
      BufferValue[i] = mod.read();
    }
    if (BufferValue[1] != 255 && BufferValue[2] != 255)
    {
      byte1 = hex_to_int(BufferValue[3]);
      byte2 = hex_to_int(BufferValue[4]);
      windspeed = ((float(byte1) * 256) + float(byte2)) / 10;
      return windspeed;
    }
    return 0;
  }
  return 0;
}

/** Setup serial connection between esp32 and rs-485 to ttl module */
void sensor_setup()
{
  mod.begin(baudWindSensor);
  pinMode(transmissionPin, OUTPUT);
}

/** calculate average of wind speed data */
float average_wind()
{
  float sum_wind_data = 0;
  for (int i = 0; i < iteration_aveg; i++)
  {
    sum_wind_data += get_wind_data();
    delay(10);
  }
  return (sum_wind_data / iteration_aveg);
}
