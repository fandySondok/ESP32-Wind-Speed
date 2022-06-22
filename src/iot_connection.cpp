#include <WiFi.h>
#include "iot_connection.h"
#include <ESP32Ping.h>

#ifdef http_get
#include <HTTPClient.h>
static HTTPClient http;
#elif defined(mqtt)
#include <PubSubClient.h>
WiFiClient espClient;
PubSubClient client(espClient);
static void callback(char *topic, byte *message, unsigned int length);
static void reconnect();
static void mqtt_setup();
#endif

/** Testing internet access from access point */
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

/** return status connection between esp32 and access point */
bool wifi_status()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    return -1;
  }
  return 0;
}

/** Connect to access point */
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

/** Send data to server */
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
#elif defined(mqtt)
  if (!client.connected())
  {
    reconnect();
  }
  client.publish(pub_topic, data.c_str());
  return 1;
#endif
}

#ifdef mqtt

/** Callback when received data from sub topic */
static void callback(char *topic, byte *message, unsigned int length)
{
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++)
  {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();
}

/** Attempt to reconnect */
static void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client"))
    {
      Serial.println("connected");
      // Subscribe
      // client.subscribe("esp32/sub");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

/** Prepare ESP32 to use mqtt protocol */
static void mqtt_setup()
{
  client.setServer(mqtt_server_addr, mqtt_port);
  client.setCallback(callback);
}

/** Make sure client get data from sub topic in real-time */
void client_loop()
{
  client.loop();
}
#endif

/** Setup ESP32 to send data */
void connection_setup()
{
  wifi_setup();
#ifdef mqtt
  mqtt_setup();
#endif
}
