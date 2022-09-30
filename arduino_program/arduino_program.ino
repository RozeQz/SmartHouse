// БИБЛИОТЕКИ

// библиотека для работы с датчиками серии DHT
#include <TroykaDHT.h>  // датчик температуры и влажности

#include "Station.h"    //

// МАКРОСЫ

#define PHOTO_PIN A0    // пин подключения фоторезистора

// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ

DHT dht(7, DHT11); // объект класса DHT - датчик температуры и влажности

Station stn("Lisa's Oleg", &dht, PHOTO_PIN); // станция измерения

// КОД

void setup() {
  // открываем последовательный порт для мониторинга действий в программе
  Serial.begin(9600);
}

void loop() {
  stn.getData();

  char* str = stn.getJSON();
  Serial.println(str);
  delete[] str;

  // ждём две секунды
  delay(2000);
}
