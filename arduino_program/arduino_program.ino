// библиотека для работы с датчиками серии DHT
#include <TroykaDHT.h>
#include <string.h>
// пин подключения фоторезистора
#define PHOTO_PIN A0

class Data {
  public:
    int brightness;
    float temperature;
    float humidity;
    char* getJSON();
};

class Station {
  private:
    char name[16];
  public:
    Data myData;
    Station(const char* str) { strcpy(name, str); };
    char* getJSON();
};

char* Data::getJSON() {
  char* result = new char[64]();
  strcat(result, "{ \"brightness\": ");
  strcat(result, String(brightness).c_str());
  strcat(result, ", \"temperature\": ");
  strcat(result, String(temperature).c_str());
  strcat(result, ", \"humidity\": ");
  strcat(result, String(humidity).c_str());
  strcat(result, "}");
  return result;
}

char* Station::getJSON() {
  char* result = new char[128]();
  strcat(result, "{\"stationName\":\"");
  strcat(result, name);
  strcat(result, "\", \"data\":");
  char* data = myData.getJSON();
  strcat(result, data);
  strcat(result, "}");
  delete[] data;
  return result;
}

// создаём объект класса DHT
// передаём номер пина к которому подключён датчик и тип датчика
// типы сенсоров: DHT11, DHT21, DHT22
DHT dht(7, DHT11);

Station stn("Lisa's Oleg");

void setup() {
  pinMode(PHOTO_PIN, INPUT);
  // открываем последовательный порт для мониторинга действий в программе
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  stn.myData.brightness = analogRead(PHOTO_PIN);
  // считывание данных с датчика
  dht.read();
  // проверяем состояние данных
  switch (dht.getState()) {
    // всё OK
    case DHT_OK:
      stn.myData.temperature = dht.getTemperatureC();
      stn.myData.humidity = dht.getHumidity();
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