#include "Station.h"

int replacechar(char *str, char orig, char rep) {
    char *ix = str;
    int n = 0;
    while((ix = strchr(ix, orig)) != NULL) {
        *ix++ = rep;
        n++;
    }
    return n;
}

Station::Station(unsigned int id, const char* str, const DHT* dht, int photoPin) : _photoPin(photoPin), _dht(dht), _id(id) { 
  strcpy(_name, str);
  
  pinMode(photoPin, INPUT);
  _dht->begin();
}

int Station::getDHTData(float* temp, int* hum) {
  _dht->read();

  unsigned long stopAttemptsTime = millis() + DHT_CONNECTION_WAITTIME;
  while (_dht->getState() != DHT_OK && millis() < stopAttemptsTime) {
    delay(20);
    _dht->read();
  }
  
  switch (_dht->getState()) {
    case DHT_OK:
      *temp = _dht->getTemperatureC();
      *hum = _dht->getHumidity();
      return 0;
    case DHT_ERROR_CHECKSUM:
    case DHT_ERROR_TIMEOUT:
    case DHT_ERROR_NO_REPLY:
      return _dht->getState();
    default:
      return 255;
  }
}

void Station::getDHTDataJSON(char* buf, int bufSize) {
  float temperature;
  int humidity, error;
  error = getDHTData(&temperature, &humidity);
  sprintf(buf, "{\"brightness\": %d, \"temperature\": ", getBrightness());
  dtostrf(temperature, 4, 2, buf + strlen(buf));
  sprintf(buf + strlen(buf), ", \"humidity\": %d, \"error\": %d}", humidity, error);
}

int Station::getBrightness() {
  return analogRead(_photoPin);
}

char* Station::getJSON() {
  char* result = new char[128]();
  sprintf(result, "{\"stationName\": \"%.16s\", \"data\": ", _name);

  char data[64];
  getDHTDataJSON(data, 64);
  strcat(result, data);
  strcat(result, "}");
  delete[] data;
  return result;
}

char* Station::getParams() {
  char* result = new char[128]();
  char myName[16];
  strcpy(myName, _name);
  replacechar(myName, ' ', '+');
  sprintf(result, "stationName=%.16s&stationID=%u&", myName, _id);
  
  float temperature;
  int humidity, error;
  error = getDHTData(&temperature, &humidity);
  sprintf(result + strlen(result), "humidity=%d&temperature=", humidity);
  dtostrf(temperature, 4, 2, result + strlen(result));
  
  return result;
}
