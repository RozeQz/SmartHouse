// БИБЛИОТЕКИ

#include <TroykaDHT.h>  // библиотека для работы с датчиком температуры и влажности

#include "Station.h"    // модуль работы с датчиками
#include "WifiMagic.h"  // модуль работы с удаленным сервером
#include "config.cpp"   // файл с настройками

// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ

iarduino_RTC time(RTC_DS1302, DS1302_RST, DS1302_CLK, DS1302_DAT);  // для модуля DS1302 - RST, CLK, DAT
DHT dht(DHT_PIN, DHT11); // объект класса DHT - датчик температуры и влажности

Station stn(STATION_ID, STATION_NAME, &dht, PHOTO_PIN, &time); // станция измерения

// КОД

void setup() {
  Serial.begin(9600);
  time.begin();
  Serial.println("Hello!");

  setup_wifi();
}

void loop() {
  static bool doGetData = true;
  if ((millis()/1000%15 == 9) && doGetData) {
    char* str = stn.getParams();

    Serial.println(str);
    send_data(str);

    delete[] str;
    doGetData = false;
  }
  if (millis()/1000%15 <= 8) {
    doGetData = true;
  }
  loop_wifi();
}
