#include "WifiMagic.h"
#include <Arduino.h>

#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(8, 9);

#define WIFI_SERIAL    mySerial

void setup_wifi() {
  while (!Serial) {}
  Serial.print("Serial init OK\r\n");
  WIFI_SERIAL.begin(9600);
}

void connect_wifi() {
  WIFI_SERIAL.print("AT+CWMODE_DEF=3\r\n");
  wait_for_module();
  WIFI_SERIAL.print("AT+CWJAP=\"wifi\",\"pass\"\r\n");
  wait_for_module();
}

void wait_for_module() {
  while (!WIFI_SERIAL.available()) {
    //Serial.print(".");
    delay(5);
  }
  Serial.print("\r\n");
  while (WIFI_SERIAL.available()) {
    Serial.write(WIFI_SERIAL.read());
  }
}

void send_data(const char* str) {
  WIFI_SERIAL.print("AT+CIPSTART=\"TCP\",\"192.168.1.10\",3000\r\n");
  delay(500);
  WIFI_SERIAL.print("AT+CIPSEND=");
  WIFI_SERIAL.print(strlen(str)+96+String(strlen(str)).length());
  WIFI_SERIAL.print("\r\n");
  delay(500);
  WIFI_SERIAL.print("POST /stations HTTP/1.0\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: ");
  delay(20);
  WIFI_SERIAL.print(strlen(str));
  WIFI_SERIAL.print("\r\n\r\n");
  delay(20);
  WIFI_SERIAL.print(str);
  WIFI_SERIAL.print("\r\n");
  delay(500);
  //WIFI_SERIAL.print("AT+CIPCLOSE");
  //wait_for_module();
}
 
void loop_wifi() {
  // если приходят данные из Wi-Fi модуля - отправим их в порт компьютера
  if (WIFI_SERIAL.available()) {
    Serial.write(WIFI_SERIAL.read());
  }
  // если приходят данные из компьютера - отправим их в Wi-Fi модуль
  if (Serial.available()) {
    WIFI_SERIAL.write(Serial.read());
  }
}
