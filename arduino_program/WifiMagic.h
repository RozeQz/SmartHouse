#ifndef WIFIMAGIC_H
#define WIFIMAGIC_H

void setup_wifi();
void connect_wifi();
void loop_wifi();
void send_data(const char* str);

void wait_for_module();

#endif
