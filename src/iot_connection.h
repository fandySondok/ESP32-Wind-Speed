#ifndef IOT_CONNECTION_H
#define IOT_CONNECTION_H
#include <Arduino.h>

bool test_connection();
bool wifi_status();
void wifi_setup();
int send_data(String data);

#endif
