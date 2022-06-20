#include <WiFi.h>
#include "config.h"
#include <ESP32Ping.h>
#include <HTTPClient.h>

static HTTPClient http;
bool test_connection()
{
  bool resp = Ping.ping("www.google.com", 3);
  if (!resp)
  {
    Serial.println("No Internet Access");
    return resp;
  }
  return resp;
}

bool wifi_status()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    return -1;
  }
  return 0;
}

void wifi_setup()
{
  Serial.println("Setup Wifi");
  Serial.println();
  Serial.print("Connection to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  int _timeout = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    _timeout++;
    if (_timeout > 20)
    {
      ESP.restart();
    }
  }
}

int send_data(String data)
{
#ifdef http_get
  String buffer = "";
  buffer += server_addr;
  buffer += server_endpoint;
  buffer += api_key;
  buffer += "&field";
  buffer += String(ts_field);
  buffer += "=";
  buffer += data;

  http.begin(buffer.c_str());
  int _resp = http.GET();
  if (_resp > 0)
  {
    Serial.print("HTTP Response Code: ");
    Serial.println(_resp);
    String payload = http.getString();
    Serial.println(payload);
  }
  else
  {
    Serial.println("Failed to send data");
    Serial.print("ERROR Code");
    Serial.println(_resp);
  }
  http.end();
  return _resp;
#else
#endif
}
