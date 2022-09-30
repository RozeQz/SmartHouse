#include "Station.h"

Station::Station(const char* str, const DHT* dht, int photoPin) : _photoPin(photoPin), _dht(dht) { 
  strcpy(_name, str);
  
  pinMode(photoPin, INPUT);
  _dht->begin();
}

void Station::getData() {
  myData.setBrightness(analogRead(_photoPin));

  _dht->read();

  unsigned long stopAttemptsTime = millis() + DHT_CONNECTION_WAITTIME;
  while (_dht->getState() != DHT_OK && millis() < stopAttemptsTime) {
    delay(20);
    _dht->read();
  }
  
  switch (_dht->getState()) {
    case DHT_OK:
      myData.setTemperature(_dht->getTemperatureC());
      myData.setHumidity(_dht->getHumidity());
      myData.setError(0);
      break;
    case DHT_ERROR_CHECKSUM:
    case DHT_ERROR_TIMEOUT:
    case DHT_ERROR_NO_REPLY:
      myData.setError(_dht->getState());
      break;
    default:
      myData.setError(255);
      break;
  }
}

char* Station::getJSON() {
  char* result = new char[128]();
  sprintf(result, "{\"stationName\": \"%.16s\", \"data\": ", _name);

  char* data = myData.getJSON();
  strcat(result, data);
  strcat(result, "}");
  delete[] data;
  return result;
}
