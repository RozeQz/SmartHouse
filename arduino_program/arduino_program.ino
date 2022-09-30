// БИБЛИОТЕКИ

// библиотека для работы с датчиками серии DHT
#include <TroykaDHT.h>  // датчик температуры и влажности

#include "Station.h"    //

// МАКРОСЫ

#define PHOTO_PIN A0    // пин подключения фоторезистора

// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ

DHT dht(7, DHT11); // объект класса DHT - датчик температуры и влажности

Station stn("Lisa's Oleg"); // станция измерения

// КОД

void setup() {
  pinMode(PHOTO_PIN, INPUT);
  // открываем последовательный порт для мониторинга действий в программе
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  stn.myData._brightness = analogRead(PHOTO_PIN);
  // считывание данных с датчика
  dht.read();
  // проверяем состояние данных
  switch (dht.getState()) {
    // всё OK
    case DHT_OK:
      stn.myData._temperature = dht.getTemperatureC();
      stn.myData._humidity = dht.getHumidity();
      char* str = stn.getJSON();
      Serial.println(str);
      delete[] str;
      break;
    // ошибка контрольной суммы
    case DHT_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
    // превышение времени ожидания
    case DHT_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;
    // данных нет, датчик не реагирует или отсутствует
    case DHT_ERROR_NO_REPLY:
      Serial.println("Sensor not connected");
      break;
  }

  // ждём две секунды
  delay(2000);
}
