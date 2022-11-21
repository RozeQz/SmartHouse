#include "WifiMagic.h"
#include <Arduino.h>

#include <SoftwareSerial.h>

SoftwareSerial mySerial(ESP_RX, ESP_TX);

#define WIFI_SERIAL    mySerial

void setup_wifi() {
  while (!Serial) {}
  Serial.print("Serial init OK\r\n");
  WIFI_SERIAL.begin(4800);
}

void connect_wifi() {
  WIFI_SERIAL.print(F("AT+CWMODE_DEF=3\r\n"));
  wait_for_module();
  WIFI_SERIAL.print(F("AT+CWJAP=\""));
  WIFI_SERIAL.print(SSID);
  WIFI_SERIAL.print("\",\"");
  WIFI_SERIAL.print(PASSWORD);
  WIFI_SERIAL.print("\"\r\n");
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
  WIFI_SERIAL.print(F("AT+CIPSTART=\"TCP\",\""));
  WIFI_SERIAL.print(SERVER_IP);
  WIFI_SERIAL.print(F("\",3000\r\n"));
  delay(500);
  WIFI_SERIAL.print(F("AT+CIPSEND="));
  WIFI_SERIAL.print(strlen(str)+96+String(strlen(str)).length());
  WIFI_SERIAL.print("\r\n");
  delay(500);
  WIFI_SERIAL.print(F("POST /stations HTTP/1.0\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: "));
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
  if (WIFI_SERIAL.available()) {
    Serial.write(WIFI_SERIAL.read());
  }

}
