// БИБЛИОТЕКИ

// библиотека для работы с датчиками серии DHT
#include <TroykaDHT.h>  // датчик температуры и влажности

#include "Station.h"    //
#include "WifiMagic.h"  //

// МАКРОСЫ

#define PHOTO_PIN A0    // пин подключения фоторезистора

// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ

iarduino_RTC time(RTC_DS1302,A0,5,6);  // для модуля DS1302 - RST, CLK, DAT
DHT dht(7, DHT11); // объект класса DHT - датчик температуры и влажности

Station stn(808, "Lisa", &dht, PHOTO_PIN, &time); // станция измерения

// КОД

void setup() {
  // открываем последовательный порт для мониторинга действий в программе
  Serial.begin(9600);
  time.begin();
  Serial.println("Hello!");
  
  setup_wifi();
  
}

void loop() {
  //stn.getData();

  static bool doGetData = true;
  if ((millis()/1000%15 == 9) && doGetData) {
    //Serial.println("Start sending data...");
    
    char* str = stn.getParams();
    
    Serial.println(str);

    send_data(str);
    

    delete[] str;
    doGetData = false;
    //Serial.println("End sending data");    
  }
  if (millis()/1000%15 <= 8) {
    doGetData = true;
  }

  loop_wifi();
}
