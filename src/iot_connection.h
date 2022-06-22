#ifndef IOT_CONNECTION_H
#define IOT_CONNECTION_H
#include "config.h"

bool test_connection();
bool wifi_status();
void wifi_setup();
int send_data(String data);
void connection_setup();
#ifdef mqtt
void client_loop();
#endif

#endif
